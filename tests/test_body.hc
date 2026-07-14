// Unit tests for typed body decoding: field decoders, optional fields,
// decode_body, and the 422 helper. Pure — no server needed.
import "../src/body"

// A tiny model + decoder used by the decode_body tests.
struct Person { name: string }

fun decode_person(doc: Json) : result<Person, string> => match field_str(doc, "name") {
  Ok(v)  => Ok(Person { name: v }),
  Err(e) => Err(e)
}

// ============================================================
// Required field decoders
// ============================================================

test "field_str reads a present string" {
  let doc = unwrap(parse_json("\{\"name\": \"x\"\}"))
  match field_str(doc, "name") {
    Ok(v)  => assert(v == "x"),
    Err(_) => assert(false)
  }
}

test "field_str errors when the field is the wrong type" {
  let doc = unwrap(parse_json("\{\"name\": 42\}"))
  match field_str(doc, "name") {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

test "field_str errors when the field is missing" {
  let doc = unwrap(parse_json("\{\}"))
  match field_str(doc, "name") {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

test "field_int reads an integral number" {
  let doc = unwrap(parse_json("\{\"n\": 7\}"))
  match field_int(doc, "n") {
    Ok(v)  => assert(v == 7),
    Err(_) => assert(false)
  }
}

test "field_int rejects a non-integral number" {
  let doc = unwrap(parse_json("\{\"n\": 7.5\}"))
  match field_int(doc, "n") {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

test "field_num reads a float" {
  let doc = unwrap(parse_json("\{\"p\": 1.5\}"))
  match field_num(doc, "p") {
    Ok(v)  => assert(v == 1.5),
    Err(_) => assert(false)
  }
}

test "field_num accepts an integer literal" {
  let doc = unwrap(parse_json("\{\"p\": 3\}"))
  match field_num(doc, "p") {
    Ok(v)  => assert(v == 3.0),
    Err(_) => assert(false)
  }
}

test "field_bool reads a boolean" {
  let doc = unwrap(parse_json("\{\"b\": true\}"))
  match field_bool(doc, "b") {
    Ok(v)  => assert(v == true),
    Err(_) => assert(false)
  }
}

test "field_bool errors on a non-boolean" {
  let doc = unwrap(parse_json("\{\"b\": \"nope\"\}"))
  match field_bool(doc, "b") {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

// ============================================================
// Optional field decoders
// ============================================================

test "opt_str returns None when absent" {
  let doc = unwrap(parse_json("\{\}"))
  match opt_str(doc, "name") {
    Ok(m)  => assert(is_none(m)),
    Err(_) => assert(false)
  }
}

test "opt_str returns Some when present" {
  let doc = unwrap(parse_json("\{\"name\": \"x\"\}"))
  match opt_str(doc, "name") {
    Ok(m)  => assert(unwrap_maybe_or(m, "") == "x"),
    Err(_) => assert(false)
  }
}

test "opt_bool errors when present but wrong type" {
  let doc = unwrap(parse_json("\{\"b\": 1\}"))
  match opt_bool(doc, "b") {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

// ============================================================
// decode_body
// ============================================================

test "decode_body decodes a valid JSON body" {
  let req = build_request("POST", "/", "/", "", "", "\{\"name\": \"hi\"\}")
  match decode_body(req, decode_person) {
    Ok(p)  => assert(p.name == "hi"),
    Err(_) => assert(false)
  }
}

test "decode_body reports invalid JSON" {
  let req = build_request("POST", "/", "/", "", "", "not json")
  match decode_body(req, decode_person) {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

test "decode_body propagates a decoder error" {
  let req = build_request("POST", "/", "/", "", "", "\{\}")
  match decode_body(req, decode_person) {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

// ============================================================
// with_body (typed round-trip)
// ============================================================

test "with_body hands a valid body to the handler" {
  let req = build_request("POST", "/", "/", "", "", "\{\"name\": \"ada\"\}")
  let resp = with_body(req, decode_person, (p) => ok_json(jobj([("name", jstr(p.name))])))
  assert(response_status(resp) == 200)
  assert(response_body(resp) == "\{\"name\": \"ada\"\}")
}

test "with_body returns 422 on a decode error" {
  let req = build_request("POST", "/", "/", "", "", "\{\}")
  let resp = with_body(req, decode_person, (p) => ok_json(jobj([("name", jstr(p.name))])))
  assert(response_status(resp) == 422)
}

test "with_body returns 422 on invalid JSON" {
  let req = build_request("POST", "/", "/", "", "", "not json")
  let resp = with_body(req, decode_person, (p) => ok_json(jobj([("name", jstr(p.name))])))
  assert(response_status(resp) == 422)
}

test "with_body lets the handler choose the status" {
  let req = build_request("POST", "/", "/", "", "", "\{\"name\": \"ada\"\}")
  let resp = with_body(req, decode_person, (p) => created_json(jobj([("name", jstr(p.name))])))
  assert(response_status(resp) == 201)
}

// ============================================================
// Result combinators
// ============================================================

test "res_and_then chains on Ok" {
  let doc = unwrap(parse_json("\{\"name\": \"x\"\}"))
  let r = field_str(doc, "name") |> res_and_then((v) => Ok(Person { name: v }))
  match r {
    Ok(p)  => assert(p.name == "x"),
    Err(_) => assert(false)
  }
}

test "res_and_then short-circuits on Err" {
  let doc = unwrap(parse_json("\{\}"))
  let r = field_str(doc, "name") |> res_and_then((v) => Ok(Person { name: v }))
  match r {
    Ok(_)  => assert(false),
    Err(_) => assert(true)
  }
}

test "res_map transforms the Ok value into a struct" {
  let doc = unwrap(parse_json("\{\"name\": \"hi\"\}"))
  let r = field_str(doc, "name") |> res_map((v) => Person { name: v })
  match r {
    Ok(p)  => assert(p.name == "hi"),
    Err(_) => assert(false)
  }
}

// ============================================================
// 422 helper
// ============================================================

test "unprocessable returns a 422 response" {
  let r = unprocessable("bad")
  assert(response_status(r) == 422)
}

test "unprocessable emits a JSON detail body" {
  let r = unprocessable("bad")
  assert(response_body(r) == "\{\"detail\": \"bad\"\}")
}

// ============================================================
// JSON value constructors (Layer 4)
// ============================================================

test "jstr builds a JSON string" {
  assert(json_emit(jstr("hi")) == "\"hi\"")
}

test "jint builds a JSON number from an int" {
  assert(json_emit(jint(7)) == "7")
}

test "jnum builds a JSON number from a float" {
  assert(json_emit(jnum(1.5)) == "1.5")
}

test "jbool builds a JSON boolean" {
  assert(json_emit(jbool(true)) == "true")
}

test "jnull builds JSON null" {
  assert(json_emit(jnull()) == "null")
}

test "jobj builds a JSON object" {
  let j = jobj([("a", jint(1)), ("b", jstr("x"))])
  assert(json_emit(j) == "\{\"a\": 1, \"b\": \"x\"\}")
}

test "jarr builds a JSON array" {
  let j = jarr([jint(1), jint(2)])
  assert(json_emit(j) == "[1, 2]")
}

// ============================================================
// Typed JSON responses (Layer 4)
// ============================================================

test "ok_json returns 200 with a JSON content type" {
  let r = ok_json(jobj([("ok", jbool(true))]))
  assert(response_status(r) == 200)
}

test "ok_json emits the encoded body" {
  let r = ok_json(jobj([("ok", jbool(true))]))
  assert(response_body(r) == "\{\"ok\": true\}")
}

test "created_json returns 201" {
  let r = created_json(jobj([("id", jint(1))]))
  assert(response_status(r) == 201)
}

test "json_response_of uses the given status" {
  let r = json_response_of(202, jarr([]))
  assert(response_status(r) == 202)
}

