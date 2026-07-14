// middleware.hc — batteries-included middleware for the hica router
//
// A middleware is a function `(req, next) -> route_response`:
//   - call `next(req)` to continue the chain (and optionally transform the result)
//   - return a response without calling `next` to short-circuit
//
// Use with serve_routes_mw (from router.hc):
//
//   import "../src/middleware"
//
//   fun main() {
//     serve_routes_mw(8080, [
//       get("/", (req) => json_response("\{\"ok\": true\}"))
//     ], [
//       logger(),
//       cors("*"),
//       require_bearer("secret123")
//     ])
//   }

extern import "router_impl"
pub import "./router"

// ---------------------------------------------------------------------------
// Response builders for middleware short-circuits (produce route_response)
// ---------------------------------------------------------------------------

pub fun respond_json(body) {
  make_route_response(200, "Content-Type: application/json", body)
}

pub fun respond_text(body) {
  make_route_response(200, "Content-Type: text/plain", body)
}

pub fun respond_status(code, body) {
  make_route_response(code, "Content-Type: text/plain", body)
}

// Append a header to a route_response, preserving existing headers.
pub fun route_with_header(resp, name, value) {
  route_add_header(resp, name, value)
}

// ---------------------------------------------------------------------------
// Built-in middleware
// ---------------------------------------------------------------------------

// Log "METHOD /path" for every request, then continue.
pub fun logger() {
  (req, next) => {
    println(req_method(req) + " " + req_path(req))
    next(req)
  }
}

// Add CORS headers to every response and answer OPTIONS preflight with 204.
// origin is the value for Access-Control-Allow-Origin (e.g. "*" or a domain).
pub fun cors(origin) {
  // Build the preflight header block once, outside the closure, so it is not
  // rebuilt on every OPTIONS request.
  let preflight = "Access-Control-Allow-Origin: " + origin + "\n"
                + "Access-Control-Allow-Methods: GET, POST, PUT, DELETE, PATCH, OPTIONS\n"
                + "Access-Control-Allow-Headers: Content-Type, Authorization"
  (req, next) => {
    if req_method(req) == "OPTIONS" {
      make_route_response(204, preflight, "")
    } else {
      route_add_header(next(req), "Access-Control-Allow-Origin", origin)
    }
  }
}

// Require a matching Bearer token. 401 if the header is absent, 403 if the
// token does not match, otherwise continue.
pub fun require_bearer(token) {
  (req, next) => {
    match bearer_token(req) {
      None => respond_status(401, "Unauthorized"),
      Some(t) => if t == token { next(req) } else { respond_status(403, "Forbidden") }
    }
  }
}
