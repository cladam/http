// http_client — barrel module for the hica HTTP library
// Re-exports Hica utility modules

pub import "./headers"
pub import "./url"

// --- Auth helpers ---

// Build a Bearer authorization header string
// Use with http_request: http_request("GET", url, headers=with_bearer(token))
pub fun with_bearer(token: string) : string {
  "Authorization: Bearer " + token
}

// Build a Basic authorization header string
// Expects base64-encoded "user:password" credentials
pub fun with_basic_auth(credentials: string) : string {
  "Authorization: Basic " + credentials
}
