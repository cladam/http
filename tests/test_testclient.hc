// Tests for the in-process test client — and a demonstration of how to use it
// to unit-test an app's routes without starting a server.
import "../src/testclient"

// A small app under test. Defined as a function so each test gets its own copy.
fun app() => [
  get("/",           (req) => json_response("\{\"ok\": true\}")),
  get("/items/\{id\}", (req) => json_response("\{\"id\": " + show(path_int(req, "id")) + "\}")),
  get("/search",     (req) => text_response(unwrap_maybe_or(query_str(req, "q"), "none"))),
  post("/items",     (req) => status_response(201, req_body(req))),
  delete("/items/\{id\}", (req) => status_response(204, ""))
]

// ============================================================
// Basic dispatch
// ============================================================

test "GET / returns 200" {
  let r = test_get(app(), "/")
  assert(route_response_status(r) == 200)
}

test "GET / returns the handler body" {
  let r = test_get(app(), "/")
  assert(route_response_body(r) == "\{\"ok\": true\}")
}

test "an unmatched route returns 404" {
  let r = test_get(app(), "/nope")
  assert(route_response_status(r) == 404)
}

test "a method mismatch falls through to 404" {
  let r = test_post(app(), "/", "x")
  assert(route_response_status(r) == 404)
}

// ============================================================
// Params
// ============================================================

test "a path parameter reaches the handler" {
  let r = test_get(app(), "/items/42")
  assert(route_response_body(r) == "\{\"id\": 42\}")
}

test "a query string in the path is parsed" {
  let r = test_get(app(), "/search?q=hello")
  assert(route_response_body(r) == "hello")
}

test "an absent query parameter uses the default" {
  let r = test_get(app(), "/search")
  assert(route_response_body(r) == "none")
}

// ============================================================
// Bodies and methods
// ============================================================

test "POST returns the handler status" {
  let r = test_post(app(), "/items", "payload")
  assert(route_response_status(r) == 201)
}

test "the request body reaches the handler" {
  let r = test_post(app(), "/items", "payload")
  assert(route_response_body(r) == "payload")
}

test "DELETE with a path param returns 204" {
  let r = test_delete(app(), "/items/9")
  assert(route_response_status(r) == 204)
}

// ============================================================
// Custom headers
// ============================================================

test "custom headers reach the handler" {
  let routes = [ get("/h", (req) => text_response(unwrap_maybe_or(req_header(req, "X-Test"), "none"))) ]
  let r = test_request(routes, "GET", "/h", "X-Test: yes\n", "")
  assert(route_response_body(r) == "yes")
}

// ============================================================
// Middleware
// ============================================================

test "test_request_mw runs a pass-through middleware" {
  let routes = [ get("/", (req) => text_response("ok")) ]
  let pass = (req, next) => next(req)
  let r = test_request_mw(routes, [pass], "GET", "/", "", "")
  assert(route_response_body(r) == "ok")
}

test "test_request_mw honours a short-circuiting middleware" {
  let routes = [ get("/", (req) => text_response("ok")) ]
  let block = (req, next) => make_route_response(403, "Content-Type: text/plain", "blocked")
  let r = test_request_mw(routes, [block], "GET", "/", "", "")
  assert(route_response_status(r) == 403)
}
