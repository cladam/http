import http-client

fun main() {
  // Simple GET
  println("--- GET ---")
  let resp = http-get("https://httpbin.org/get", timeout=10)
  println("Status: " + show(resp.status))
  println("OK? " + show(resp.is-ok))

  // Parse and inspect headers
  let hdrs = parse-headers(resp.headers)
  println("Content-Type: " + response-content-type(resp))
  println("Has Server header? " + show(has-header(hdrs, "Server")))

  // JSON POST
  println("")
  println("--- JSON POST ---")
  let post-resp = json-post("https://httpbin.org/post", body="\{\"hello\":\"world\"\}")
  println("Status: " + show(post-resp.status))

  // Build URL with query parameters
  println("")
  println("--- URL building ---")
  let target = build-url("https://httpbin.org/get", [Param("page", "1"), Param("limit", "10")])
  println("URL: " + target)
  let qresp = http-get(target, timeout=10)
  println("Status: " + show(qresp.status))

  // Auth header (just show how to build it)
  println("")
  println("--- Auth ---")
  println("Bearer header: " + with-bearer("my-secret-token"))
}
