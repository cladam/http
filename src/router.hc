// router.hc — FastAPI-style routing for the hica HTTP server
//
// Usage:
//
//   import "../src/router"
//
//   fun main() {
//     println("Listening on :8080")
//     serve_routes(8080, [
//       get("/", (req) =>
//         json_response("\{\"hello\": \"world\"\}")),
//
//       get("/items/{id}", (req) => {
//         let id = path_int(req, "id")
//         let q  = query_str(req, "q")
//         json_response("\{\"id\": " + show(id) + "\}")
//       }),
//
//       post("/items", (req) =>
//         json_response(req.body))
//     ])
//   }
//
// Available request helpers (all take `req` as first arg):
//   path_str(req, "key")    -> string        (path param, "" if absent)
//   path_int(req, "id")     -> int           (path param, 0 if absent)
//   query_str(req, "q")     -> maybe<string>
//   query_int(req, "page")  -> maybe<int>
//   query_bool(req, "flag") -> maybe<bool>
//   req_header(req, "Authorization") -> maybe<string>
//   bearer_token(req)       -> maybe<string>
//
// Response helpers (from http_server):
//   text_response(body)     -> ServerResponse (200 text/plain)
//   json_response(body)     -> ServerResponse (200 application/json)
//   html_response(body)     -> ServerResponse (200 text/html)
//   not_found_response()    -> ServerResponse (404)
//   error_response(msg)     -> ServerResponse (500)
//   status_response(n, body)-> ServerResponse (n text/plain)

extern import "http_server_impl"
extern import "router_impl"
import "./http_server"

// --- Internal helper ---
// Wraps a user handler (ServerResponse-returning) into the route_response
// tuple the router dispatcher expects.
// Must be pub — Hica requires all library functions to be pub.
pub fun wrap_handler(method, pattern, handler) {
  make_route(method, pattern, (req) => {
    let resp = handler(req)
    make_route_response(response_status(resp), response_headers(resp), response_body(resp))
  })
}

// --- Route constructors ---

pub fun get(pattern, handler) {
  wrap_handler("GET", pattern, handler)
}

pub fun post(pattern, handler) {
  wrap_handler("POST", pattern, handler)
}

pub fun put(pattern, handler) {
  wrap_handler("PUT", pattern, handler)
}

pub fun delete(pattern, handler) {
  wrap_handler("DELETE", pattern, handler)
}

pub fun patch(pattern, handler) {
  wrap_handler("PATCH", pattern, handler)
}

// Match any HTTP method — useful for catch-all handlers.
pub fun any(pattern, handler) {
  wrap_handler("*", pattern, handler)
}

// --- Server entry point ---

// Start serving on port.  Each incoming request is matched against routes in
// order; the first match wins.  Unmatched requests return 404 automatically.
// Never returns.
pub fun serve_routes(port: int, routes) {
  let srv = http_server_start(port)
  routes_loop(srv, routes)
}

pub fun routes_loop(srv, routes) {
  let raw = http_server_accept(srv)
  let resp = dispatch_routes(raw, routes)
  http_server_respond(srv, raw, resp.status, resp.headers, resp.body)
  routes_loop(srv, routes)
}
