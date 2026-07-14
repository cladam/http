// static.hc — serve files from a directory (Starlette StaticFiles-style)
//
// Mount a directory on a route using a trailing "*" wildcard, which captures
// the rest of the path:
//
//   import "../src/static"
//
//   serve_routes(8080, [
//     get("/",         (req) => html_response("<h1>Home</h1>")),
//     get("/static/*", serve_dir("./public"))
//   ])
//
// A request for /static/css/app.css reads ./public/css/app.css. The Content-Type
// is chosen from the file extension; a missing file is a 404, and any attempt to
// escape the directory (a ".." segment or an absolute path) is a 403.
//
// Note: files are read as text (UTF-8). Binary assets such as images are not
// yet supported — that needs a binary-safe file read and response body.

extern import "router_impl"
pub import "./router"

// Pick a Content-Type from a file's extension.
pub fun content_type_for(path: string) : string {
  if ends_with(path, ".html") { "text/html; charset=utf-8" }
  else if ends_with(path, ".htm")  { "text/html; charset=utf-8" }
  else if ends_with(path, ".css")  { "text/css; charset=utf-8" }
  else if ends_with(path, ".js")   { "application/javascript; charset=utf-8" }
  else if ends_with(path, ".mjs")  { "application/javascript; charset=utf-8" }
  else if ends_with(path, ".json") { "application/json" }
  else if ends_with(path, ".svg")  { "image/svg+xml" }
  else if ends_with(path, ".xml")  { "application/xml" }
  else if ends_with(path, ".txt")  { "text/plain; charset=utf-8" }
  else if ends_with(path, ".csv")  { "text/csv; charset=utf-8" }
  else if ends_with(path, ".md")   { "text/markdown; charset=utf-8" }
  else { "text/plain; charset=utf-8" }
}

// A relative path is safe only if it does not try to climb out of the mounted
// directory (no ".." segment) and is not absolute.
pub fun is_safe_rel(rel: string) : bool {
  !contains(rel, "..") && !starts_with(rel, "/")
}

// Serve a single file for `req` from under `dir`, using the captured "*"
// wildcard as the relative path. An empty capture serves "index.html".
// Returns 403 on an unsafe path and 404 when the file is missing.
pub fun serve_file_from(req, dir: string) {
  let rel = path_str(req, "*")
  let target = if rel == "" { "index.html" } else { rel }
  if !is_safe_rel(target) {
    status_response(403, "Forbidden")
  } else {
    match read_file(dir + "/" + target) {
      Ok(content) => content_response(200, content_type_for(target), content),
      Err(_)      => not_found_response()
    }
  }
}

// Return a handler closure that serves files from `dir` under a "*" route.
// Mount it directly on a wildcard route:
//
//   serve_routes(8080, [
//     get("/static/*", serve_dir("./public"))
//   ])
//
// A request for /static/css/app.css reads ./public/css/app.css.
pub fun serve_dir(dir: string) {
  (req) => {
    let rel = path_str(req, "*")
    let target = if rel == "" { "index.html" } else { rel }
    if !is_safe_rel(target) {
      status_response(403, "Forbidden")
    } else {
      match read_file(dir + "/" + target) {
        Ok(content) => content_response(200, content_type_for(target), content),
        Err(_)      => not_found_response()
      }
    }
  }
}
