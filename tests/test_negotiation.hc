// Unit tests for content negotiation (the Accept header).
// Pure logic only — no network / server needed.
import "../src/negotiation"

// Build a GET request carrying a given Accept header.
fun req_with_accept(accept: string) {
  build_request("GET", "/x", "/x", "", "Accept: " + accept, "")
}

// ============================================================
// accepts
// ============================================================

test "accepts matches an exact type" {
  let req = req_with_accept("application/json")
  assert(accepts(req, "application/json"))
}

test "accepts rejects an unlisted type" {
  let req = req_with_accept("text/html")
  assert(!accepts(req, "application/json"))
}

test "accepts honours the */* wildcard" {
  let req = req_with_accept("*/*")
  assert(accepts(req, "application/json"))
  assert(accepts(req, "text/html"))
}

test "accepts honours a type/* range" {
  let req = req_with_accept("text/*")
  assert(accepts(req, "text/html"))
  assert(!accepts(req, "application/json"))
}

test "accepts ignores charset params on the offer" {
  let req = req_with_accept("text/html")
  assert(accepts(req, "text/html; charset=utf-8"))
}

test "accepts_json and accepts_html predicates" {
  let req = req_with_accept("application/json")
  assert(accepts_json(req))
  assert(!accepts_html(req))
}

// ============================================================
// best_offer
// ============================================================

test "best_offer picks the exact match" {
  let req = req_with_accept("text/html")
  match best_offer(req, ["application/json", "text/html"]) {
    Some(m) => assert(m == "text/html"),
    None    => assert(false)
  }
}

test "best_offer honours q-values over server order (browser case)" {
  let req = req_with_accept("text/html,application/xhtml+xml,*/*;q=0.8")
  match best_offer(req, ["application/json", "text/html"]) {
    Some(m) => assert(m == "text/html"),
    None    => assert(false)
  }
}

test "best_offer falls back to server order for */*" {
  let req = req_with_accept("*/*")
  match best_offer(req, ["application/json", "text/html"]) {
    Some(m) => assert(m == "application/json"),
    None    => assert(false)
  }
}

test "best_offer returns None when nothing is acceptable" {
  let req = req_with_accept("application/xml")
  match best_offer(req, ["application/json", "text/html"]) {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "best_offer excludes a q=0 range" {
  let req = req_with_accept("application/json;q=0")
  match best_offer(req, ["application/json"]) {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "a missing Accept header accepts anything (server order)" {
  let req = build_request("GET", "/x", "/x", "", "", "")
  match best_offer(req, ["application/json", "text/html"]) {
    Some(m) => assert(m == "application/json"),
    None    => assert(false)
  }
}

// ============================================================
// negotiate
// ============================================================

test "negotiate returns the chosen representation with Vary" {
  let req = req_with_accept("text/html")
  let resp = negotiate(req, [
    ("application/json",         "\{\"x\": 1\}"),
    ("text/html; charset=utf-8", "<h1>hi</h1>")
  ])
  assert(response_status(resp) == 200)
  assert(response_body(resp) == "<h1>hi</h1>")
}

test "negotiate serves JSON to an API client" {
  let req = req_with_accept("application/json")
  let resp = negotiate(req, [
    ("application/json",         "\{\"x\": 1\}"),
    ("text/html; charset=utf-8", "<h1>hi</h1>")
  ])
  assert(response_status(resp) == 200)
  assert(response_body(resp) == "\{\"x\": 1\}")
}

test "negotiate returns 406 when nothing matches" {
  let req = req_with_accept("application/xml")
  let resp = negotiate(req, [ ("application/json", "\{\}") ])
  assert(response_status(resp) == 406)
}
