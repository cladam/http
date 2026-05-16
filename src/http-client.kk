/*
 * http-client.kk — Barrel module for the hica HTTP library
 * Import this single module to get everything.
 *
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module http-client

pub import http
pub import http-headers
pub import http-url

// ---------------------------------------------------------------------------
// Auth helpers
// ---------------------------------------------------------------------------

// Build a Bearer authorization header string.
// Use with http-request: `http-request("GET", url, headers=with-bearer(token))`
pub fun with-bearer( token : string ) : string
  "Authorization: Bearer " ++ token

// Build a Basic authorization header string.
// Expects base64-encoded "user:password" credentials.
pub fun with-basic-auth( credentials : string ) : string
  "Authorization: Basic " ++ credentials
