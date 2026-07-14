// web.hc — convenience barrel for building web services
//
// Re-exports the router, middleware, and static-file modules (and, through the
// router, the low-level http_server response helpers) so a typical app needs a
// single import:
//
//   import "../src/web"
//
//   fun main() {
//     serve_routes_mw(8080, [
//       get("/",         (req) => json_response("\{\"ok\": true\}")),
//       get("/static/*", assets)
//     ], [ logger(), cors("*") ])
//   }
//
// For typed request/response bodies, add `import "body"` as well — it is kept
// separate because it pulls in the json library.

pub import "./router"
pub import "./middleware"
pub import "./static"
pub import "./negotiation"
