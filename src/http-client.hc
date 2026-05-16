// http-client — barrel module for the hica HTTP library
// Re-exports the low-level http module plus Hica utilities

pub import http
pub import headers
pub import url

// --- JSON convenience helpers ---

// JSON GET — sets Accept: application/json header
pub fun json-get(target: string, timeout: int = 0) : http-response {
  http-request("GET", target, headers="Accept: application/json", timeout=timeout)
}

// JSON POST — sets Content-Type: application/json
pub fun json-post(target: string, body: string, timeout: int = 0) : http-response {
  http-post(target, body, content-type="application/json", timeout=timeout)
}

// JSON PUT — sets Content-Type: application/json
pub fun json-put(target: string, body: string, timeout: int = 0) : http-response {
  http-put(target, body, content-type="application/json", timeout=timeout)
}

// JSON PATCH — sets Content-Type: application/json
pub fun json-patch(target: string, body: string, timeout: int = 0) : http-response {
  http-patch(target, body, content-type="application/json", timeout=timeout)
}

// --- Auth helpers ---

// Build a Bearer authorization header string
// Use with http-request: http-request("GET", url, headers=with-bearer(token))
pub fun with-bearer(token: string) : string {
  "Authorization: Bearer " + token
}

// Build a Basic authorization header string
// Expects base64-encoded "user:password" credentials
pub fun with-basic-auth(credentials: string) : string {
  "Authorization: Basic " + credentials
}

// --- Form helpers ---

// POST form-encoded data
pub fun form-post(target: string, body: string, timeout: int = 0) : http-response {
  http-post(target, body, content-type="application/x-www-form-urlencoded", timeout=timeout)
}
