extern import "http"
import "../src/http_client"

fun main() {
  // Simple GET
  println("--- GET ---")
  let resp = http_get("https://httpbin.org/get")
  println("Status: " + show(resp.status))
  println("OK? " + show(resp.status >= 200))

  // Parse and inspect headers
  let hdrs = parse_headers(resp.headers)
  println("Content-Type: " + unwrap_maybe_or(get_header(hdrs, "Content-Type"), "(none)"))
  println("Has Server header? " + show(has_header(hdrs, "Server")))

  // Shortcut: find header directly from raw string
  println("Server: " + unwrap_maybe_or(find_header(resp.headers, "Server"), "(none)"))

  // JSON POST
  println("")
  println("--- JSON POST ---")
  let post_resp = json_post("https://httpbin.org/post", "\{\"hello\":\"world\"\}")
  println("Status: " + show(post_resp.status))

  // Build URL with query parameters
  println("")
  println("--- URL building ---")
  let target = build_url("https://httpbin.org/get", [Param { key: "page", value: "1" }, Param { key: "limit", value: "10" }])
  println("URL: " + target)
  let qresp = http_get(target)
  println("Status: " + show(qresp.status))

  // Auth header (just show how to build it)
  println("")
  println("--- Auth ---")
  println("Bearer header: " + with_bearer("my-secret-token"))
}
