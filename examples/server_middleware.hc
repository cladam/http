// examples/server_middleware.hc — router + middleware (Layer 2)
//
// Demonstrates the Starlette-style middleware chain wrapped around the router,
// using the batteries-included middleware from src/middleware.hc:
//   - logger()          logs "METHOD /path" for every request
//   - cors("*")         adds CORS headers + answers OPTIONS preflight with 204
//   - require_bearer(t) gates every route behind a Bearer token
//
// Middlewares run in list order: the first is outermost (runs first). A
// middleware may short-circuit by returning a response without calling next
// (require_bearer returns 401/403; cors answers OPTIONS preflight directly).
//
// Run (from the http library root):
//   hica run examples/server_middleware.hc
// Then:
//   curl http://localhost:8080/                       -> 401 Unauthorized
//   curl http://localhost:8080/ -H "Authorization: Bearer secret123"
//   curl http://localhost:8080/me -H "Authorization: Bearer secret123"
//   curl -X OPTIONS http://localhost:8080/ -i          -> 204 + CORS headers

import "../src/middleware"

fun handle_root(req) : ServerResponse {
  json_response("\{\"hello\": \"world\"\}")
}

fun handle_me(req) : ServerResponse {
  // require_bearer already validated the token; echo it back.
  match bearer_token(req) {
    Some(t) => json_response("\{\"token\": \"" + t + "\"\}"),
    None    => status_response(401, "Unauthorized")
  }
}

fun main() {
  println("Server starting on http://localhost:8080")
  serve_routes_mw(8080, [
    get("/",   handle_root),
    get("/me", handle_me)
  ], [
    logger(),
    cors("*"),
    require_bearer("secret123")
  ])
}
