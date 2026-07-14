// Tests for static file serving: content-type mapping, path safety, and the
// router's "*" trailing wildcard. (serve_file_from itself reads the filesystem,
// which isn't available under `hica test`, so it is exercised by the
// server_static example instead.)
import "../src/static"

// ============================================================
// content_type_for
// ============================================================

test "content_type_for maps .html" {
  assert(content_type_for("index.html") == "text/html; charset=utf-8")
}

test "content_type_for maps .css" {
  assert(content_type_for("style.css") == "text/css; charset=utf-8")
}

test "content_type_for maps .js" {
  assert(content_type_for("app.js") == "application/javascript; charset=utf-8")
}

test "content_type_for maps .json" {
  assert(content_type_for("data.json") == "application/json")
}

test "content_type_for maps .svg" {
  assert(content_type_for("logo.svg") == "image/svg+xml")
}

test "content_type_for defaults to text/plain" {
  assert(content_type_for("archive.xyz") == "text/plain; charset=utf-8")
}

// ============================================================
// is_safe_rel — directory-traversal protection
// ============================================================

test "is_safe_rel accepts a normal nested path" {
  assert(is_safe_rel("css/app.css"))
}

test "is_safe_rel rejects a parent traversal" {
  assert(!is_safe_rel("../secret"))
}

test "is_safe_rel rejects a nested traversal" {
  assert(!is_safe_rel("a/b/../../../etc/passwd"))
}

test "is_safe_rel rejects an absolute path" {
  assert(!is_safe_rel("/etc/passwd"))
}

// ============================================================
// "*" trailing wildcard routing
// ============================================================

test "wildcard captures a multi-segment remainder" {
  match match_param("/static/*", "/static/css/app.css", "*") {
    Some(v) => assert(v == "css/app.css"),
    None    => assert(false)
  }
}

test "wildcard captures a single segment" {
  match match_param("/static/*", "/static/app.css", "*") {
    Some(v) => assert(v == "app.css"),
    None    => assert(false)
  }
}

test "wildcard matches an empty remainder" {
  let r = is_some(match_path("/static/*", "/static"))
  assert(r)
}

test "a non-wildcard route still needs an exact segment count" {
  let r = is_none(match_path("/static/\{f\}", "/static/a/b"))
  assert(r)
}
