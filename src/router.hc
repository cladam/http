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
//   path_str_opt(req, "key")-> maybe<string> (path param, None if absent)
//   path_int_opt(req, "id") -> maybe<int>    (path param, None if absent/bad)
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
pub import "./http_server"

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
  http_server_run(port, (node) => {
    let raw = request_from_id(node)
    let resp = dispatch_routes_safe(raw, routes)
    http_set_response(node, route_response_status(resp), route_response_headers(resp), route_response_body(resp))
  })
}

// --- Middleware ---
//
// A middleware wraps the whole request/response cycle (Starlette-style):
//
//   fun my_mw(req, next) {
//     // ...inspect/short-circuit before...
//     let resp = next(req)   // run the rest of the chain (route_response)
//     // ...transform the response after...
//     resp
//   }
//
// Return a response WITHOUT calling `next` to short-circuit (auth, preflight).
// Middlewares run in list order: the first is outermost (runs first).
// Build responses for short-circuits with the respond_* helpers in
// middleware.hc, or with make_route_response directly.

// Start serving with a middleware chain wrapped around the router.
// Unmatched requests still return 404 automatically.  Never returns.
// The middleware pipeline is composed once and reused for every request.
pub fun serve_routes_mw(port: int, routes, middlewares) {
  let pipeline = apply_mw(middlewares, routes)
  http_server_run(port, (node) => {
    let raw = request_from_id(node)
    let base = build_base_request(raw)
    let resp = run_pipeline_safe(base, pipeline)
    http_set_response(node, route_response_status(resp), route_response_headers(resp), route_response_body(resp))
  })
}

// Compose a middleware list into a single (request) -> route_response function.
// The innermost link runs the router; each middleware wraps the next.
pub fun apply_mw(middlewares, routes) {
  match middlewares {
    [] => (req) => dispatch_request(req, routes),
    [mw, ..rest] => {
      let inner = apply_mw(rest, routes)
      (req) => mw(req, inner)
    }
  }
}
