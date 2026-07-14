// examples/server_errors.hc — custom error handling (Ktor StatusPages-style)
//
// By default an exception raised inside a handler becomes a plain
// "500 Internal Server Error". serve_routes_with_errors lets you decide the
// response yourself: the on_error callback receives the exception message and
// returns a ServerResponse, so you can render a JSON error body (or map
// specific messages to other status codes).
//
// Run (from the http library root):
//   hica run examples/server_errors.hc
// Then:
//   curl -i localhost:8080/                -> 200
//   curl -i localhost:8080/boom            -> 500 with a JSON error body
//   curl -i localhost:8080/missing         -> 404 (unmatched routes still 404)

import "../src/router"

fun handle_root(req) : ServerResponse {
  json_response("\{\"hello\": \"world\"\}")
}

// This handler raises an exception (division by zero). Without a custom error
// handler it would be a bare 500; here on_error turns it into a JSON body
// carrying the exception message.
fun handle_boom(req) {
  let n = 1 / 0
  json_response("ok " + show(n))
}

// Map the caught exception message onto a JSON 500 body.
fun on_error(msg: string) : ServerResponse {
  json_status(500, "\{\"error\": \"internal\"\}")
}

fun main() {
  println("Server on http://localhost:8080 (GET /, GET /boom)")
  serve_routes_with_errors(8080, [
    get("/",     handle_root),
    get("/boom", handle_boom)
  ], on_error)
}
