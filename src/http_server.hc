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

// --- Redirects ---

// 302 Found — a temporary redirect to `url`.
pub fun redirect(url: string) : ServerResponse {
  ServerResponse { status: 302, headers: "Location: " + url, body: "" }
}

// 301 Moved Permanently — a permanent redirect to `url`.
pub fun redirect_permanent(url: string) : ServerResponse {
  ServerResponse { status: 301, headers: "Location: " + url, body: "" }
}

// --- Common status responses ---

// 202 Accepted with a plain-text body.
pub fun accepted(body: string) : ServerResponse {
  ServerResponse { status: 202, headers: "Content-Type: text/plain", body: body }
}

// 204 No Content — an empty successful response.
pub fun no_content() : ServerResponse {
  ServerResponse { status: 204, headers: "", body: "" }
}

// 400 Bad Request with a plain-text message.
pub fun bad_request(msg: string) : ServerResponse {
  ServerResponse { status: 400, headers: "Content-Type: text/plain", body: msg }
}

// 401 Unauthorized with a plain-text message.
pub fun unauthorized(msg: string) : ServerResponse {
  ServerResponse { status: 401, headers: "Content-Type: text/plain", body: msg }
}

// 403 Forbidden with a plain-text message.
pub fun forbidden(msg: string) : ServerResponse {
  ServerResponse { status: 403, headers: "Content-Type: text/plain", body: msg }
}

// 406 Not Acceptable — the client's Accept header matched none of the offered
// representations (used by content negotiation).
pub fun not_acceptable() : ServerResponse {
  ServerResponse { status: 406, headers: "Content-Type: text/plain", body: "Not Acceptable" }
}

// Custom status with application/json body
pub fun json_status(status: int, body: string) : ServerResponse {
  ServerResponse { status: status, headers: "Content-Type: application/json", body: body }
}

// Custom status with an explicit Content-Type.
pub fun content_response(status: int, content_type: string, body: string) : ServerResponse {
  ServerResponse { status: status, headers: "Content-Type: " + content_type, body: body }
}

// Append a header to a response, preserving existing headers.
pub fun with_header(resp: ServerResponse, name: string, value: string) : ServerResponse {
  let hdrs = response_headers(resp)
  let sep = if hdrs == "" { "" } else { "\n" }
  ServerResponse { status: response_status(resp), headers: hdrs + sep + name + ": " + value, body: response_body(resp) }
}

// Set a cookie on a response (Path=/ so it applies site-wide).
pub fun set_cookie(resp: ServerResponse, name: string, value: string) : ServerResponse {
  with_header(resp, "Set-Cookie", name + "=" + value + "; Path=/")
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
// Runs a single-threaded event loop; libmicrohttpd interleaves concurrent
// connections and calls `handler` synchronously per completed request.
// Never returns.
pub fun serve(port: int, handler) {
  http_server_run(port, (node) => {
    let req = request_from_id(node)
    let resp = handler(req)
    http_set_response(node, response_status(resp), response_headers(resp), response_body(resp))
  })
}

// Initialize the HTTP server on `port` non-blockingly, returning a handle.
// Does not enter the blocking serve loop. Drive with `server_poll`.
pub fun server_init(port: int, handler) {
  http_server_init(port, (node) => {
    let req = request_from_id(node)
    let resp = handler(req)
    http_set_response(node, response_status(resp), response_headers(resp), response_body(resp))
  })
}

// Poll the HTTP server once. Returns 1 if active, 0 on stop/error.
pub fun server_poll(srv: int) {
  http_server_poll(srv)
}

// Stop the HTTP server and clean up resources.
pub fun server_stop(srv: int) {
  http_server_stop(srv)
}
