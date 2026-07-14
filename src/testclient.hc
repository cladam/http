// testclient.hc — in-process test client for the router
//
// Dispatch requests straight through your routes (and optionally middleware)
// without opening a socket, so you can unit-test an app with `hica test`:
//
//   import "../src/testclient"
//
//   fun routes() => [
//     get("/items/{id}", (req) => json_response("\{\"id\": " + show(path_int(req, "id")) + "\}")),
//     post("/items",     (req) => created_response(req_body(req)))
//   ]
//
//   test "GET /items/7 returns 200" {
//     let resp = test_get(routes(), "/items/7")
//     assert(route_response_status(resp) == 200)
//   }
//
// Every helper returns a route_response; read it with route_response_status,
// route_response_headers, and route_response_body.

extern import "router_impl"
pub import "./router"

// Split "/path?a=1&b=2" into a (path, query) pair. No "?" yields an empty query.
pub fun split_path_query(path_and_query: string) : (string, string) {
  match split(path_and_query, "?") {
    []          => ("", ""),
    [p]         => (p, ""),
    [p, ..rest] => (p, join(rest, "?"))
  }
}

// Dispatch a request through `routes` in-process and return the route_response.
// `path` may include a query string, e.g. "/items?page=2&limit=10".
// `headers` is a raw "Name: Value\n..." string (use "" for none).
pub fun test_request(routes, method: string, path: string, headers: string, body: string) {
  match split_path_query(path) {
    (p, q) => dispatch_request(build_request(method, p, p, q, headers, body), routes)
  }
}

// Same as test_request but runs the middleware chain around the router,
// mirroring serve_routes_mw.
pub fun test_request_mw(routes, middlewares, method: string, path: string, headers: string, body: string) {
  match split_path_query(path) {
    (p, q) => (apply_mw(middlewares, routes))(build_request(method, p, p, q, headers, body))
  }
}

// --- Method conveniences (no custom headers; use test_request for those) ---

pub fun test_get(routes, path: string) {
  test_request(routes, "GET", path, "", "")
}

pub fun test_post(routes, path: string, body: string) {
  test_request(routes, "POST", path, "", body)
}

pub fun test_put(routes, path: string, body: string) {
  test_request(routes, "PUT", path, "", body)
}

pub fun test_delete(routes, path: string) {
  test_request(routes, "DELETE", path, "", "")
}

pub fun test_patch(routes, path: string, body: string) {
  test_request(routes, "PATCH", path, "", body)
}
