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
pub struct http_response
  status  : int       // HTTP status code (200, 404, etc.)
  body    : string    // Response body as a string
  headers : string    // Raw response headers

// ---------------------------------------------------------------------------
// Low-level extern: calls libcurl
// ---------------------------------------------------------------------------

// Raw request function — returns (status, body, headers) tuple.
// All HTTP methods go through this single C function.
extern http_request_raw(
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
// val resp = http_get("https://httpbin.org/get")
// println(resp.body)
// ```
pub fun http_get( url : string, timeout : int = 0 ) : io http_response
  val (status, body, hdrs) = http_request_raw("GET", url, "", "", "", timeout)
  Http_response(status, body, hdrs)

// Perform an HTTP POST request with a body.
//
// ```koka
// val resp = http_post("https://httpbin.org/post", "{\"key\":\"value\"}", content-type="application/json")
// ```
pub fun http_post( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http_response
  val (status, rbody, hdrs) = http_request_raw("POST", url, body, content-type, "", timeout)
  Http_response(status, rbody, hdrs)

// Perform an HTTP PUT request.
pub fun http_put( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http_response
  val (status, rbody, hdrs) = http_request_raw("PUT", url, body, content-type, "", timeout)
  Http_response(status, rbody, hdrs)

// Perform an HTTP DELETE request.
pub fun http_delete( url : string, timeout : int = 0 ) : io http_response
  val (status, body, hdrs) = http_request_raw("DELETE", url, "", "", "", timeout)
  Http_response(status, body, hdrs)

// Perform an HTTP PATCH request.
pub fun http_patch( url : string, body : string = "", content-type : string = "", timeout : int = 0 ) : io http_response
  val (status, rbody, hdrs) = http_request_raw("PATCH", url, body, content-type, "", timeout)
  Http_response(status, rbody, hdrs)

// Perform an HTTP HEAD request (no body returned).
pub fun http_head( url : string, timeout : int = 0 ) : io http_response
  val (status, body, hdrs) = http_request_raw("HEAD", url, "", "", "", timeout)
  Http_response(status, body, hdrs)

// ---------------------------------------------------------------------------
// General request with custom headers
// ---------------------------------------------------------------------------

// Perform an HTTP request with a custom method and headers.
// Headers are passed as a newline-separated string:
//   "Authorization: Bearer token123\nX-Custom: value"
pub fun http_request(
  method        : string,
  url           : string,
  body          : string = "",
  content-type  : string = "",
  headers       : string = "",
  timeout       : int    = 0
) : io http_response
  val (status, rbody, hdrs) = http_request_raw(method, url, body, content-type, headers, timeout)
  Http_response(status, rbody, hdrs)

// ---------------------------------------------------------------------------
// Convenience: check response status
// ---------------------------------------------------------------------------

// True if the response has a 2xx status code.
pub fun is_ok( resp : http_response ) : bool
  resp.status >= 200 && resp.status < 300

// True if the response is a redirect (3xx).
pub fun is_redirect( resp : http_response ) : bool
  resp.status >= 300 && resp.status < 400

// True if the response is a client error (4xx).
pub fun is_client_error( resp : http_response ) : bool
  resp.status >= 400 && resp.status < 500

// True if the response is a server error (5xx).
pub fun is_server_error( resp : http_response ) : bool
  resp.status >= 500 && resp.status < 600

// Show an http_response
pub fun show( resp : http_response ) : string
  "HTTP " ++ resp.status.show ++ " (" ++ resp.body.count.show ++ " bytes)"

// ---------------------------------------------------------------------------
// JSON convenience helpers
// ---------------------------------------------------------------------------

// GET with Accept: application/json header.
pub fun json_get( url : string, timeout : int = 0 ) : io http_response
  http_request("GET", url, headers="Accept: application/json", timeout=timeout)

// POST with Content-Type: application/json.
pub fun json_post( url : string, body : string, timeout : int = 0 ) : io http_response
  http_post(url, body, content-type="application/json", timeout=timeout)

// PUT with Content-Type: application/json.
pub fun json_put( url : string, body : string, timeout : int = 0 ) : io http_response
  http_put(url, body, content-type="application/json", timeout=timeout)

// PATCH with Content-Type: application/json.
pub fun json_patch( url : string, body : string, timeout : int = 0 ) : io http_response
  http_patch(url, body, content-type="application/json", timeout=timeout)

// POST with Content-Type: application/x-www-form-urlencoded.
pub fun form_post( url : string, body : string, timeout : int = 0 ) : io http_response
  http_post(url, body, content-type="application/x-www-form-urlencoded", timeout=timeout)
