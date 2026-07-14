// Tests for the extra response helpers, imported through the web.hc barrel
// (which also confirms the barrel re-exports the router + response helpers).
import "../src/web"

test "redirect is 302" {
  assert(response_status(redirect("/home")) == 302)
}

test "redirect sets a Location header" {
  assert(contains(response_headers(redirect("/home")), "Location: /home"))
}

test "redirect_permanent is 301" {
  assert(response_status(redirect_permanent("/new")) == 301)
}

test "accepted is 202" {
  assert(response_status(accepted("queued")) == 202)
}

test "no_content is 204" {
  assert(response_status(no_content()) == 204)
}

test "no_content has an empty body" {
  assert(response_body(no_content()) == "")
}

test "bad_request is 400" {
  assert(response_status(bad_request("nope")) == 400)
}

test "unauthorized is 401" {
  assert(response_status(unauthorized("no")) == 401)
}

test "forbidden is 403" {
  assert(response_status(forbidden("no")) == 403)
}

// The barrel re-exports the router: constructors and dispatch are usable here.
test "the barrel re-exports router constructors" {
  let routes = [ get("/", (req) => accepted("ok")) ]
  let base = build_request("GET", "/", "/", "", "", "")
  let r = dispatch_request(base, routes)
  assert(route_response_status(r) == 202)
}
