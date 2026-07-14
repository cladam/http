// Tests for form-field and cookie extraction, and the Set-Cookie response
// helper. Pure — no server needed.
import "../src/router"

// ============================================================
// Form fields (urlencoded request bodies)
// ============================================================

test "form_str reads a urlencoded field" {
  let req = build_request("POST", "/", "/", "", "", "name=alice&age=30")
  match form_str(req, "name") {
    Some(v) => assert(v == "alice"),
    None    => assert(false)
  }
}

test "form_str returns None for a missing field" {
  let req = build_request("POST", "/", "/", "", "", "name=alice")
  match form_str(req, "nope") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "form_int parses a numeric field" {
  let req = build_request("POST", "/", "/", "", "", "name=alice&age=30")
  match form_int(req, "age") {
    Some(v) => assert(v == 30),
    None    => assert(false)
  }
}

test "form_int returns None for a non-numeric field" {
  let req = build_request("POST", "/", "/", "", "", "age=old")
  match form_int(req, "age") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

// ============================================================
// Cookies (Cookie request header)
// ============================================================

test "cookie reads a value from the Cookie header" {
  let req = build_request("GET", "/", "/", "", "Cookie: session=abc; theme=dark\n", "")
  match cookie(req, "session") {
    Some(v) => assert(v == "abc"),
    None    => assert(false)
  }
}

test "cookie reads a later value in the header" {
  let req = build_request("GET", "/", "/", "", "Cookie: session=abc; theme=dark\n", "")
  match cookie(req, "theme") {
    Some(v) => assert(v == "dark"),
    None    => assert(false)
  }
}

test "cookie returns None for a missing name" {
  let req = build_request("GET", "/", "/", "", "Cookie: session=abc\n", "")
  match cookie(req, "nope") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "cookie returns None when there is no Cookie header" {
  let req = build_request("GET", "/", "/", "", "", "")
  match cookie(req, "session") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

// ============================================================
// Response helpers
// ============================================================

test "with_header appends a header to a response" {
  let r = with_header(text_response("x"), "X-Custom", "1")
  assert(contains(response_headers(r), "X-Custom: 1"))
}

test "set_cookie adds a Set-Cookie header" {
  let r = set_cookie(json_response("\{\}"), "session", "abc")
  assert(contains(response_headers(r), "Set-Cookie: session=abc; Path=/"))
}
