// Unit tests for the router: path matching, param extraction, headers.
// Pure logic only — no network / server needed.
import "../src/router"

// ============================================================
// Path pattern matching
// ============================================================

test "match_param captures a single path parameter" {
  match match_param("/items/\{id\}", "/items/42", "id") {
    Some(v) => assert(v == "42"),
    None    => assert(false)
  }
}

test "match_param captures multiple path parameters" {
  let tag = match_param("/items/\{id\}/tags/\{tag\}", "/items/7/tags/koka", "tag")
  match tag {
    Some(v) => assert(v == "koka"),
    None    => assert(false)
  }
}

test "match_param on a static route with unknown key is None" {
  match match_param("/health", "/health", "id") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "match_path succeeds on an exact static match" {
  let r = is_some(match_path("/a/b/c", "/a/b/c"))
  assert(r)
}

test "match_path fails when a static segment differs" {
  let r = is_none(match_path("/a/b/c", "/a/x/c"))
  assert(r)
}

test "match_path fails on segment count mismatch" {
  let r = is_none(match_path("/items/\{id\}", "/items/42/extra"))
  assert(r)
}

test "match_path ignores a trailing slash" {
  let r = is_some(match_path("/items", "/items/"))
  assert(r)
}

test "match_path matches the root path" {
  let r = is_some(match_path("/", "/"))
  assert(r)
}

// ============================================================
// Path parameter extraction
// ============================================================

test "path_str returns the captured value" {
  let req = build_request("GET", "/items/\{id\}", "/items/42", "", "", "")
  assert(path_str(req, "id") == "42")
}

test "path_str returns empty string when absent" {
  let req = build_request("GET", "/items", "/items", "", "", "")
  assert(path_str(req, "id") == "")
}

test "path_int parses the captured value" {
  let req = build_request("GET", "/items/\{id\}", "/items/99", "", "", "")
  assert(path_int(req, "id") == 99)
}

test "path_int returns 0 when absent" {
  let req = build_request("GET", "/items", "/items", "", "", "")
  assert(path_int(req, "id") == 0)
}

test "path_int parses a negative value" {
  let req = build_request("GET", "/t/\{n\}", "/t/-5", "", "", "")
  assert(path_int(req, "n") == -5)
}

test "path_int returns 0 for non-numeric input" {
  let req = build_request("GET", "/t/\{n\}", "/t/abc", "", "", "")
  assert(path_int(req, "n") == 0)
}

// ============================================================
// Query parameter extraction
// ============================================================

test "query_str finds a present parameter" {
  let req = build_request("GET", "/items", "/items", "q=koka", "", "")
  match query_str(req, "q") {
    Some(v) => assert(v == "koka"),
    None    => assert(false)
  }
}

test "query_str returns None when absent" {
  let req = build_request("GET", "/items", "/items", "", "", "")
  match query_str(req, "q") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "query_int parses a numeric parameter" {
  let req = build_request("GET", "/items", "/items", "page=3", "", "")
  match query_int(req, "page") {
    Some(v) => assert(v == 3),
    None    => assert(false)
  }
}

test "query_int returns None for non-numeric input" {
  let req = build_request("GET", "/items", "/items", "page=x", "", "")
  match query_int(req, "page") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "query_bool accepts true and 1" {
  let req = build_request("GET", "/x", "/x", "a=true&b=1", "", "")
  let a = query_bool(req, "a")
  let b = query_bool(req, "b")
  match a {
    Some(va) => match b {
      Some(vb) => assert(va == true && vb == true),
      None     => assert(false)
    },
    None => assert(false)
  }
}

test "query_bool accepts false and 0" {
  let req = build_request("GET", "/x", "/x", "a=false&b=0", "", "")
  let a = query_bool(req, "a")
  match a {
    Some(va) => assert(va == false),
    None     => assert(false)
  }
}

test "query_bool returns None for unrecognised value" {
  let req = build_request("GET", "/x", "/x", "a=maybe", "", "")
  match query_bool(req, "a") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

// ============================================================
// Query string parsing
// ============================================================

test "parse_query_params splits pairs" {
  let ps = parse_query_params("a=1&b=2")
  assert(length(ps) == 2)
}

test "parse_query_params of empty string is empty" {
  assert(length(parse_query_params("")) == 0)
}

// ============================================================
// Header extraction
// ============================================================

test "req_header is case-insensitive" {
  let req = build_request("GET", "/", "/", "", "Content-Type: application/json\n", "")
  match req_header(req, "content-type") {
    Some(v) => assert(v == "application/json"),
    None    => assert(false)
  }
}

test "req_header returns None when absent" {
  let req = build_request("GET", "/", "/", "", "Server: nginx\n", "")
  match req_header(req, "X-Missing") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "bearer_token extracts a Bearer token" {
  let req = build_request("GET", "/", "/", "", "Authorization: Bearer secret123\n", "")
  match bearer_token(req) {
    Some(v) => assert(v == "secret123"),
    None    => assert(false)
  }
}

test "bearer_token returns None for non-Bearer auth" {
  let req = build_request("GET", "/", "/", "", "Authorization: Basic dXNlcjpwYXNz\n", "")
  match bearer_token(req) {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "bearer_token returns None when header absent" {
  let req = build_request("GET", "/", "/", "", "", "")
  match bearer_token(req) {
    Some(_) => assert(false),
    None    => assert(true)
  }
}
