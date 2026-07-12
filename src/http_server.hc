// http_server — high-level HTTP server API for hica
// Backed by libmicrohttpd via http_server_impl.kk
//
// Usage:
//   import "../src/http_server"
//
//   fun main() {
//     println("Listening on :8080")
//     serve(8080, (req) => {
//       if req.path == "/health" {
//         text_response("ok")
//       } else {
//         json_response("\{\"path\": \"" + req.path + "\"\}")
//       }
//     })
//   }

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
