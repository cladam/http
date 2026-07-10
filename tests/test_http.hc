// Unit tests for the pure Hica utilities (headers, url, auth).
// No network / libcurl needed — these exercise parse/build logic only.
import "../src/http_client"

// ============================================================
// Header parsing
// ============================================================

test "parse_headers parses name and value" {
  let hdrs = parse_headers("Content-Type: application/json")
  match get_header(hdrs, "Content-Type") {
    Some(v) => assert(v == "application/json"),
    None    => assert(false)
  }
}

test "get_header is case-insensitive" {
  let hdrs = parse_headers("Server: nginx")
  match get_header(hdrs, "server") {
    Some(v) => assert(v == "nginx"),
    None    => assert(false)
  }
}

test "get_header returns None when absent" {
  let hdrs = parse_headers("Server: nginx")
  match get_header(hdrs, "Missing") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "parse_header_line keeps colons inside the value" {
  let hdrs = parse_headers("Date: Mon, 01 Jan 2024 12:00:00 GMT")
  match get_header(hdrs, "Date") {
    Some(v) => assert(v == "Mon, 01 Jan 2024 12:00:00 GMT"),
    None    => assert(false)
  }
}

test "parse_headers skips blank and malformed lines" {
  let hdrs = parse_headers("A: 1\n\nnotacolon\nB: 2\n")
  assert(length(hdrs) == 2)
}

test "has_header reports presence and absence" {
  let hdrs = parse_headers("X-Test: 1")
  assert(has_header(hdrs, "x-test") == true)
  assert(has_header(hdrs, "nope") == false)
}

test "find_header parses and looks up in one call" {
  match find_header("Cache-Control: no-cache\nETag: abc", "etag") {
    Some(v) => assert(v == "abc"),
    None    => assert(false)
  }
}

// ============================================================
// URL / query building
// ============================================================

test "encode_param builds key=value" {
  assert(encode_param(Param { key: "page", value: "1" }) == "page=1")
}

test "build_query joins params with ampersand" {
  let q = build_query([Param { key: "a", value: "1" }, Param { key: "b", value: "2" }])
  assert(q == "a=1&b=2")
}

test "build_query of empty list is empty string" {
  assert(build_query([]) == "")
}

test "build_url appends the query string" {
  let u = build_url("https://x.test/api", [Param { key: "n", value: "5" }])
  assert(u == "https://x.test/api?n=5")
}

test "build_url with no params is unchanged" {
  assert(build_url("https://x.test/api", []) == "https://x.test/api")
}

// ============================================================
// Auth helpers
// ============================================================

test "with_bearer builds an Authorization header" {
  assert(with_bearer("tok") == "Authorization: Bearer tok")
}

test "with_basic_auth builds an Authorization header" {
  assert(with_basic_auth("dXNlcjpwYXNz") == "Authorization: Basic dXNlcjpwYXNz")
}
