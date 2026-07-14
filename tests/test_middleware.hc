// Unit tests for middleware: response builders, header append, and the
// batteries' short-circuit / pass-through behaviour.  Pure logic — the
// middleware closures are invoked directly with a stub `next`, no server.
import "../src/middleware"

// A stub `next` that returns a fixed 200 response (stands in for the router).
fun stub_next(req) {
  make_route_response(200, "Content-Type: text/plain", "handler-ran")
}

// ============================================================
// Response builders
// ============================================================

test "respond_status sets the status code and body" {
  let r = respond_status(404, "nope")
  assert(route_response_status(r) == 404)
}

test "respond_json sets a JSON content type" {
  let r = respond_json("\{\}")
  assert(route_response_headers(r) == "Content-Type: application/json")
}

test "respond_text carries the body" {
  let r = respond_text("hello")
  assert(route_response_body(r) == "hello")
}

// ============================================================
// route_add_header
// ============================================================

test "route_add_header appends to existing headers" {
  let base = respond_text("x")
  let r = route_add_header(base, "X-Trace", "abc")
  assert(route_response_headers(r) == "Content-Type: text/plain\nX-Trace: abc")
}

test "route_add_header on empty headers omits the separator" {
  let base = make_route_response(200, "", "x")
  let r = route_add_header(base, "X-A", "1")
  assert(route_response_headers(r) == "X-A: 1")
}

// ============================================================
// cors
// ============================================================

test "cors answers OPTIONS preflight with 204 without calling next" {
  let mw = cors("*")
  let req = build_request("OPTIONS", "/", "/", "", "", "")
  let r = mw(req, stub_next)
  assert(route_response_status(r) == 204)
}

test "cors passes non-OPTIONS through to next" {
  let mw = cors("*")
  let req = build_request("GET", "/", "/", "", "", "")
  let r = mw(req, stub_next)
  assert(route_response_body(r) == "handler-ran")
}

test "cors adds Allow-Origin on a passed-through response" {
  let mw = cors("https://app.example")
  let req = build_request("GET", "/", "/", "", "", "")
  let r = mw(req, stub_next)
  assert(contains(route_response_headers(r), "Access-Control-Allow-Origin: https://app.example"))
}

// ============================================================
// require_bearer
// ============================================================

test "require_bearer returns 401 when the token is absent" {
  let mw = require_bearer("secret")
  let req = build_request("GET", "/", "/", "", "", "")
  let r = mw(req, stub_next)
  assert(route_response_status(r) == 401)
}

test "require_bearer returns 403 on a wrong token" {
  let mw = require_bearer("secret")
  let req = build_request("GET", "/", "/", "", "Authorization: Bearer nope\n", "")
  let r = mw(req, stub_next)
  assert(route_response_status(r) == 403)
}

test "require_bearer passes through on the correct token" {
  let mw = require_bearer("secret")
  let req = build_request("GET", "/", "/", "", "Authorization: Bearer secret\n", "")
  let r = mw(req, stub_next)
  assert(route_response_body(r) == "handler-ran")
}
