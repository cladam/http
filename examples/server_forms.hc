// examples/server_forms.hc — form data and cookies
//
// POST /login reads an application/x-www-form-urlencoded body and sets a
// session cookie; GET /me reads that cookie back.
//
// Run (from the http library root):
//   hica run examples/server_forms.hc
// Then:
//   curl -i -X POST localhost:8080/login -d 'username=alice'   # sets Set-Cookie
//   curl localhost:8080/me -H 'Cookie: session=alice'          # reads the cookie
//   curl localhost:8080/me                                     # 401, no cookie

import "../src/router"

fun handle_login(req) : ServerResponse {
  let user = unwrap_maybe_or(form_str(req, "username"), "")
  if user == "" {
    status_response(400, "username required")
  } else {
    set_cookie(text_response("welcome " + user), "session", user)
  }
}

fun handle_me(req) : ServerResponse {
  match cookie(req, "session") {
    Some(user) => json_response("\{\"user\": \"" + user + "\"\}"),
    None       => status_response(401, "not logged in")
  }
}

fun main() {
  println("Server on http://localhost:8080 (POST /login, GET /me)")
  serve_routes(8080, [
    post("/login", handle_login),
    get("/me",     handle_me)
  ])
}
