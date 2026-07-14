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

// Required integer field. Accepts a JSON integer (`JInt`) directly, or a
// number without a fractional part (1.0 but not 1.5) — matching FastAPI/Pydantic,
// which reject non-integral values rather than rounding them.
pub fun field_int(doc: Json, key: string) : result<int, string> => match json_get(doc, key) {
  Some(JInt(n))    => Ok(n),
  Some(JNumber(v)) => if to_float(round(v)) == v { Ok(round(v)) }
                      else { Err("field '" + key + "' must be an integer") },
  Some(_)          => Err("field '" + key + "' must be an integer"),
  None             => Err("missing required field '" + key + "'")
}

// Required floating-point field. Accepts a JSON float or integer.
pub fun field_num(doc: Json, key: string) : result<float, string> => match json_get(doc, key) {
  Some(JNumber(v)) => Ok(v),
  Some(JInt(n))    => Ok(to_float(n)),
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
  Some(JInt(n))    => Ok(Some(n)),
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

// ---------------------------------------------------------------------------
// Typed round-trip
//
// with_body ties the decode and respond sides together, the way Ktor's
// call.receive<T>() + call.respond(obj) do: it parses and decodes the request
// body, and on success hands the typed value to your handler. A malformed body
// or a decode error becomes a 422 automatically, so the handler only ever sees
// a valid value.
//
//   post("/items", (req) => with_body(req, decode_item, (item) =>
//     created_json(encode_item(item))))
//
// The handler returns a ServerResponse, so it stays in full control of the
// status and body (200/201, a Location header, a negotiated representation …).
// ---------------------------------------------------------------------------

// Decode the request body with `decoder`; on success call `handler` with the
// typed value, otherwise return 422 with the decode error.
pub fun with_body(req, decoder, handler) {
  match decode_body(req, decoder) {
    Ok(value) => handler(value),
    Err(msg)  => unprocessable(msg)
  }
}

// ---------------------------------------------------------------------------
// JSON value constructors (terse aliases for building response bodies)
//
// These wrap the json library's Json constructors with short names so an
// encoder reads cleanly:
//
//   fun encode_item(it: Item) : Json =>
//     jobj([
//       ("name",     jstr(it.name)),
//       ("price",    jnum(it.price)),
//       ("in_stock", jbool(it.in_stock))
//     ])
// ---------------------------------------------------------------------------

pub fun jstr(s: string) : Json => JString(s)
pub fun jint(n: int) : Json => JInt(n)
pub fun jnum(x: float) : Json => JNumber(x)
pub fun jbool(b: bool) : Json => JBool(b)
pub fun jnull() : Json => JNull

// Build a JSON object from a list of (key, Json) pairs.
pub fun jobj(fields: list<(string, Json)>) : Json => JObject(fields)

// Build a JSON array from a list of Json values.
pub fun jarr(items: list<Json>) : Json => JArray(items)

// ---------------------------------------------------------------------------
// Typed JSON responses (encode a Json value into a ServerResponse)
//
// The mirror of decode_body: build a Json value with an encoder, then send it.
//
//   Ok(item)  => ok_json(encode_item(item))          // 200
//   Ok(item)  => created_json(encode_item(item))     // 201
//   ...       => json_response_of(202, encode(x))     // custom status
//
// For a collection, encode each element and wrap in an array:
//   ok_json(jarr(map(items, encode_item)))
// ---------------------------------------------------------------------------

// 200 OK with a JSON body.
pub fun ok_json(j: Json) : ServerResponse => json_status(200, json_emit(j))

// 201 Created with a JSON body.
pub fun created_json(j: Json) : ServerResponse => json_status(201, json_emit(j))

// Custom status with a JSON body.
pub fun json_response_of(status: int, j: Json) : ServerResponse => json_status(status, json_emit(j))

