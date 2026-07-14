// body.hc — typed request-body decoding (FastAPI-style) for the hica router
//
// Parse a JSON request body and decode it into your own struct with clear
// validation errors. On failure, return 422 Unprocessable Entity (as FastAPI
// does) with a message describing the problem.
//
// Opt-in module: importing it pulls in the json library. Import it only when
// you want typed request bodies.
//
//   import "../src/body"
//
//   struct Item { name: string, price: float }
//
//   fun decode_item(doc: Json) : result<Item, string> {
//     match field_str(doc, "name") {
//       Err(e) => Err(e),
//       Ok(name) => match field_num(doc, "price") {
//         Err(e) => Err(e),
//         Ok(price) => Ok(Item { name: name, price: price })
//       }
//     }
//   }
//
//   post("/items", (req) => {
//     match decode_body(req, decode_item) {
//       Ok(item) => json_response("\{\"name\": \"" + item.name + "\"\}"),
//       Err(msg) => unprocessable(msg)
//     }
//   })

pub import "json"
extern import "router_impl"
pub import "./router"

// ---------------------------------------------------------------------------
// Field decoders: Json -> result<T, string>
//
// Each returns Ok(value) when the field is present and the right type,
// Err(message) when it is missing or has the wrong type.
// ---------------------------------------------------------------------------

// Required string field.
pub fun field_str(doc: Json, key: string) : result<string, string> => match json_get(doc, key) {
  Some(JString(v)) => Ok(v),
  Some(_)          => Err("field '" + key + "' must be a string"),
  None             => Err("missing required field '" + key + "'")
}

// Required integer field. JSON has no separate integer type, so we accept a
// number only when it has no fractional part (1 or 1.0, but not 1.5) — matching
// FastAPI/Pydantic, which reject non-integral values rather than rounding them.
pub fun field_int(doc: Json, key: string) : result<int, string> => match json_get(doc, key) {
  Some(JNumber(v)) => if to_float(round(v)) == v { Ok(round(v)) }
                      else { Err("field '" + key + "' must be an integer") },
  Some(_)          => Err("field '" + key + "' must be an integer"),
  None             => Err("missing required field '" + key + "'")
}

// Required floating-point field.
pub fun field_num(doc: Json, key: string) : result<float, string> => match json_get(doc, key) {
  Some(JNumber(v)) => Ok(v),
  Some(_)          => Err("field '" + key + "' must be a number"),
  None             => Err("missing required field '" + key + "'")
}

// Required boolean field.
pub fun field_bool(doc: Json, key: string) : result<bool, string> => match json_get(doc, key) {
  Some(JBool(v)) => Ok(v),
  Some(_)        => Err("field '" + key + "' must be a boolean"),
  None           => Err("missing required field '" + key + "'")
}

// ---------------------------------------------------------------------------
// Optional field decoders: Json -> result<maybe<T>, string>
//
// Ok(None) when the field is absent, Ok(Some(v)) when present and correct,
// Err(message) when present but the wrong type.
// ---------------------------------------------------------------------------

pub fun opt_str(doc: Json, key: string) : result<maybe<string>, string> => match json_get(doc, key) {
  None             => Ok(None),
  Some(JString(v)) => Ok(Some(v)),
  Some(_)          => Err("field '" + key + "' must be a string")
}

pub fun opt_int(doc: Json, key: string) : result<maybe<int>, string> => match json_get(doc, key) {
  None             => Ok(None),
  Some(JNumber(v)) => if to_float(round(v)) == v { Ok(Some(round(v))) }
                      else { Err("field '" + key + "' must be an integer") },
  Some(_)          => Err("field '" + key + "' must be an integer")
}

pub fun opt_bool(doc: Json, key: string) : result<maybe<bool>, string> => match json_get(doc, key) {
  None           => Ok(None),
  Some(JBool(v)) => Ok(Some(v)),
  Some(_)        => Err("field '" + key + "' must be a boolean")
}

// ---------------------------------------------------------------------------
// Body parsing
// ---------------------------------------------------------------------------

// Parse the request body as JSON and run a decoder over it.
// Returns Err with a clear message on malformed JSON or a decode failure.
pub fun decode_body(req, decoder) {
  match parse_json(req_body(req)) {
    Err(e)  => Err("invalid JSON: " + e),
    Ok(doc) => decoder(doc)
  }
}

// ---------------------------------------------------------------------------
// Result combinators
//
// Optional helpers for chaining field decoders without the nested-match
// pyramid. Both thread the error through untouched, so the first failing
// field wins. Because hica pipes the left operand in as the first argument,
// they compose cleanly with `|>`:
//
//   fun decode_item(doc: Json) : result<Item, string> =>
//     field_str(doc, "name") |> res_and_then((name) =>
//     field_num(doc, "price") |> res_map((price) =>
//       Item { name: name, price: price }))
//
// The nested-match form is still the recommended default for readability; reach
// for these when a struct has many fields.
// ---------------------------------------------------------------------------

// Run `f` on the Ok value (itself returning a result), short-circuit on Err.
pub fun res_and_then(r, f) => match r {
  Ok(v)  => f(v),
  Err(e) => Err(e)
}

// Map the Ok value, leaving Err untouched.
pub fun res_map(r, f) => match r {
  Ok(v)  => Ok(f(v)),
  Err(e) => Err(e)
}

// ---------------------------------------------------------------------------
// Responses
// ---------------------------------------------------------------------------

// 422 Unprocessable Entity — the FastAPI status for body validation errors.
// Emits a JSON body `\{"detail": "..."\}` so JSON clients get a machine-readable
// error rather than plain text.
pub fun unprocessable(msg: string) : ServerResponse {
  json_status(422, json_emit(JObject([("detail", JString(msg))])))
}
