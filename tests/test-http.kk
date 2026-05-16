/*
 * test-http.kk — smoke test for the http library
 * 
 * Compile and run:
 *   koka -e -ilib/http/src --cclib=-lcurl test-http.kk
 */
module test-http

import http

fun main()
  println("--- HTTP GET ---")
  val resp = http_get("https://httpbin.org/get", timeout=10)
  println("Status: " ++ resp.status.show)
  println("Body length: " ++ resp.body.count.show ++ " bytes")
  println("OK? " ++ resp.is_ok.show)
  println("")

  println("--- HTTP POST (JSON) ---")
  val post-resp = http_post(
    "https://httpbin.org/post",
    body="{\"hello\":\"world\"}",
    content-type="application/json",
    timeout=10
  )
  println("Status: " ++ post-resp.status.show)
  println("Body (first 200 chars):")
  println(post-resp.body.slice.take(200).string)
  println("")

  println("--- HTTP HEAD ---")
  val head-resp = http_head("https://httpbin.org/get", timeout=10)
  println("Status: " ++ head-resp.status.show)
  println("Body length: " ++ head-resp.body.count.show ++ " (should be 0)")
  println("Headers:")
  println(head-resp.headers.slice.take(300).string)
