// http_server — high-level HTTP server API for hica
// Backed by libmicrohttpd via http_server_impl.kk
//
// Usage:
//   import "../src/http_server"
//
//   fun main() {
//     println("Listening on :8080")
//     serve(8080, (req) => {
//       if request_path(req) == "/health" {
//         text_response("ok")
//       } else {
//         json_response("\{\"path\": \"" + request_path(req) + "\"\}")
//       }
//     })
//   }
//
// Read request fields with the accessor helpers (from http_server_impl):
//   request_method(req)  -> string
//   request_path(req)    -> string
//   request_query(req)   -> string  (raw "k=v&k2=v2")
//   request_headers(req) -> string  (raw "Name: Value\n...")
//   request_body(req)    -> string
//
// For path/query parameter extraction and routing, use router.hc instead.

extern import "http_server_impl"

// --- Response type ---

pub struct ServerResponse {
  status: int,
  headers: string,
  body: string
}

// --- Response constructors ---

// 200 text/plain response
pub fun text_response(body: string) : ServerResponse {
  ServerResponse { status: 200, headers: "Content-Type: text/plain; charset=utf-8", body: body }
}

// 200 application/json response
pub fun json_response(body: string) : ServerResponse {
  ServerResponse { status: 200, headers: "Content-Type: application/json", body: body }
}

// 200 text/html response
pub fun html_response(body: string) : ServerResponse {
  ServerResponse { status: 200, headers: "Content-Type: text/html; charset=utf-8", body: body }
}

// 404 Not Found
pub fun not_found_response() : ServerResponse {
  ServerResponse { status: 404, headers: "Content-Type: text/plain", body: "Not Found" }
}

// 500 Internal Server Error
pub fun error_response(msg: string) : ServerResponse {
  ServerResponse { status: 500, headers: "Content-Type: text/plain", body: msg }
}

// Custom status with plain-text body
pub fun status_response(status: int, body: string) : ServerResponse {
  ServerResponse { status: status, headers: "Content-Type: text/plain", body: body }
}

// --- Response field accessors ---
// Typed accessors so callers in other modules (e.g. router) can read fields
// off a ServerResponse without the field name colliding with other record
// types that share `status`/`headers`/`body` (e.g. router_impl/route_response).
pub fun response_status(r: ServerResponse) : int { r.status }
pub fun response_headers(r: ServerResponse) : string { r.headers }
pub fun response_body(r: ServerResponse) : string { r.body }

// --- Server loop ---

// Start serving on port, calling handler for each request.
// Requests are processed sequentially; libmicrohttpd holds concurrent
// connections open until their turn arrives.  Never returns.
pub fun serve(port: int, handler) {
  let srv = http_server_start(port)
  serve_loop(srv, handler)
}

// Internal recursive loop — exported because all functions in a library
// module must be pub to be reachable from the generated Koka module.
pub fun serve_loop(srv, handler) {
  let req = http_server_accept(srv)
  let resp = handler(req)
  http_server_respond(srv, req, resp.status, resp.headers, resp.body)
  serve_loop(srv, handler)
}
