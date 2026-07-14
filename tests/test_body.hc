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

test "field_int reads and rounds a number" {
  let doc = unwrap(parse_json("\{\"n\": 7\}"))
  match field_int(doc, "n") {
    Ok(v)  => assert(v == 7),
    Err(_) => assert(false)
  }
}

test "field_num reads a float" {
  let doc = unwrap(parse_json("\{\"p\": 1.5\}"))
  match field_num(doc, "p") {
    Ok(v)  => assert(v == 1.5),
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
// 422 helper
// ============================================================

test "unprocessable returns a 422 response" {
  let r = unprocessable("bad")
  assert(response_status(r) == 422)
}
