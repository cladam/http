/*
 * http.kk — HTTP client library for Koka / Hica
 * Uses libcurl via C FFI for HTTP/HTTPS requests.
 * 
 * Part of the hica ecosystem
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module http

extern import
  c file "http-inline.c"

// ---------------------------------------------------------------------------
// Response type
// ---------------------------------------------------------------------------

// An HTTP response with status code, body, and raw headers.
pub struct http-response
  status  : int       // HTTP status code (200, 404, etc.)
  body    : string    // Response body as a string
  headers : string    // Raw response headers

// ---------------------------------------------------------------------------
// Low-level extern: calls libcurl
// ---------------------------------------------------------------------------

// Raw request function — returns (status, body, headers) tuple.
// All HTTP methods go through this single C function.
extern http-request-raw(
  method       : string,
  url          : string,
  body         : string,
  content-type : string,
  extra-headers: string,
  timeout      : int
) : io (int, string, string)
  c "kk_http_request"

// ---------------------------------------------------------------------------
// Public API: simple HTTP methods
// ---------------------------------------------------------------------------

// Perform an HTTP GET request.
//
// ```koka
// val resp = http-get("https://httpbin.org/get")
// println(resp.body)
// ```
pub fun http-get( url : string, timeout : int = 0 ) : io http-response
  val (status, body, hdrs) = http-request-raw("GET", url, "", "", "", timeout)
  Http-response(status, body, hdrs)

// Perform an HTTP POST request with a body.
//
// ```koka
// val resp = http-post("https://httpbin.org/post", "{\"key\":\"value\"}", content-type="application/json")
// ```
pub fun http-post( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http-response
  val (status, rbody, hdrs) = http-request-raw("POST", url, body, content-type, "", timeout)
  Http-response(status, rbody, hdrs)

// Perform an HTTP PUT request.
pub fun http-put( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http-response
  val (status, rbody, hdrs) = http-request-raw("PUT", url, body, content-type, "", timeout)
  Http-response(status, rbody, hdrs)

// Perform an HTTP DELETE request.
pub fun http-delete( url : string, timeout : int = 0 ) : io http-response
  val (status, body, hdrs) = http-request-raw("DELETE", url, "", "", "", timeout)
  Http-response(status, body, hdrs)

// Perform an HTTP PATCH request.
pub fun http-patch( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http-response
  val (status, rbody, hdrs) = http-request-raw("PATCH", url, body, content-type, "", timeout)
  Http-response(status, rbody, hdrs)

// Perform an HTTP HEAD request (no body returned).
pub fun http-head( url : string, timeout : int = 0 ) : io http-response
  val (status, body, hdrs) = http-request-raw("HEAD", url, "", "", "", timeout)
  Http-response(status, body, hdrs)

// ---------------------------------------------------------------------------
// General request with custom headers
// ---------------------------------------------------------------------------

// Perform an HTTP request with a custom method and headers.
// Headers are passed as a newline-separated string:
//   "Authorization: Bearer token123\nX-Custom: value"
pub fun http-request(
  method        : string,
  url           : string,
  body          : string = "",
  content-type  : string = "",
  headers       : string = "",
  timeout       : int    = 0
) : io http-response
  val (status, rbody, hdrs) = http-request-raw(method, url, body, content-type, headers, timeout)
  Http-response(status, rbody, hdrs)

// ---------------------------------------------------------------------------
// Convenience: check response status
// ---------------------------------------------------------------------------

// True if the response has a 2xx status code.
pub fun is-ok( resp : http-response ) : bool
  resp.status >= 200 && resp.status < 300

// True if the response is a redirect (3xx).
pub fun is-redirect( resp : http-response ) : bool
  resp.status >= 300 && resp.status < 400

// True if the response is a client error (4xx).
pub fun is-client-error( resp : http-response ) : bool
  resp.status >= 400 && resp.status < 500

// True if the response is a server error (5xx).
pub fun is-server-error( resp : http-response ) : bool
  resp.status >= 500 && resp.status < 600

// Show an http-response
pub fun show( resp : http-response ) : string
  "HTTP " ++ resp.status.show ++ " (" ++ resp.body.count.show ++ " bytes)"

// ---------------------------------------------------------------------------
// JSON convenience helpers
// ---------------------------------------------------------------------------

// GET with Accept: application/json header.
pub fun json-get( url : string, timeout : int = 0 ) : io http-response
  http-request("GET", url, headers="Accept: application/json", timeout=timeout)

// POST with Content-Type: application/json.
pub fun json-post( url : string, body : string, timeout : int = 0 ) : io http-response
  http-post(url, body, content-type="application/json", timeout=timeout)

// PUT with Content-Type: application/json.
pub fun json-put( url : string, body : string, timeout : int = 0 ) : io http-response
  http-put(url, body, content-type="application/json", timeout=timeout)

// PATCH with Content-Type: application/json.
pub fun json-patch( url : string, body : string, timeout : int = 0 ) : io http-response
  http-patch(url, body, content-type="application/json", timeout=timeout)

// POST with Content-Type: application/x-www-form-urlencoded.
pub fun form-post( url : string, body : string, timeout : int = 0 ) : io http-response
  http-post(url, body, content-type="application/x-www-form-urlencoded", timeout=timeout)
