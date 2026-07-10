extern import "http"
import "../src/http_client"

fun main() {
  let resp = http_get("https://httpbin.org/get", 10)
  println("Status: " + show(resp.status))
  println("OK? " + show(resp.status >= 200))

  let hdrs = parse_headers(resp.headers)
  println("Content-Type: " + unwrap_maybe_or(get_header(hdrs, "Content-Type"), "(none)"))

  let post_resp = json_post("https://httpbin.org/post", "\{\"hello\":\"world\"\}", 10)
  println("Post status: " + show(post_resp.status))

  let target = build_url("https://httpbin.org/get", [Param { key: "page", value: "1" }, Param { key: "limit", value: "10" }])
  println("URL: " + target)
}
