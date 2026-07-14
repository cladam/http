// examples/server_static.hc — serve static files from a directory
//
// Run (from the http library root):
//   hica run examples/server_static.hc
// Then:
//   curl localhost:8080/                       -> the home page (dynamic)
//   curl localhost:8080/static/                -> public/index.html
//   curl localhost:8080/static/style.css       -> public/style.css (text/css)
//   curl localhost:8080/static/nope.txt        -> 404
//   curl localhost:8080/static/../secret       -> 403 (traversal blocked)

import "../src/static"

// A named handler that serves files from ./examples/public via the "*" capture.
fun assets(req) => serve_file_from(req, "./examples/public")

fun main() {
  println("Server on http://localhost:8080 (static files under /static/*)")
  serve_routes(8080, [
    get("/",         (req) => html_response("<h1>Home</h1><p>See <a href=\"/static/\">/static/</a></p>")),
    get("/static/*", assets)
  ])
}
