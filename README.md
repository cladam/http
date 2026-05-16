# http

Hica HTTP client library built on top of libcurl.

## Requirements

- [libcurl](https://curl.se/libcurl/) installed on your system
- [Koka](https://koka-lang.github.io/) 3.2.3+
- [Hica](https://github.com/niclas-claes/hica) 0.13.0+

## Usage

Import the barrel module to get everything:

```hica
import http_client
```

Or import individual modules:

```hica
import http       // low-level: http_get, http_post, http_request, ...
import headers    // header parsing: parse-headers, get-header, ...
import url        // URL building: build-url, build-query, Param, ...
```

### Quick example

```hica
import http_client

fun main() {
  let resp = http_get("https://httpbin.org/get", timeout=10)
  println("Status: " + show(resp.status))
  println("Content-Type: " + response-content-type(resp))

  // JSON POST
  let post-resp = json-post("https://api.example.com/data", body="\{\"key\":\"value\"\}")
  println("OK? " + show(post-resp.is-ok))

  // URL with query parameters
  let target = build-url("https://api.example.com/search", [Param("q", "hica"), Param("limit", "10")])
  let qresp = http_get(target)
}
```

### Compiling

```sh
# Compile with hica, then build with Koka (requires --cclib=-lcurl)
hica src/http_client.hc
koka -isrc --cclib=-lcurl your-app.kk
```

## Modules

### `http` (Koka)

Low-level libcurl bindings. All HTTP methods:

| Function | Description |
|---|---|
| `http_get(url, timeout=0)` | GET request |
| `http_post(url, body, content-type, timeout)` | POST request |
| `http_put(url, body, content-type, timeout)` | PUT request |
| `http_delete(url, timeout)` | DELETE request |
| `http_patch(url, body, content-type, timeout)` | PATCH request |
| `http_head(url, timeout)` | HEAD request |
| `http_request(method, url, body, content-type, headers, timeout)` | General request |
| `is-ok(resp)` / `is-redirect(resp)` / `is-client-error(resp)` / `is-server-error(resp)` | Status checks |

### `headers` (Hica)

Header parsing and lookup:

| Function | Description |
|---|---|
| `parse-headers(raw)` | Parse raw header string into `list<header>` |
| `get-header(hdrs, name)` | Look up header by name (case-insensitive) |
| `has-header(hdrs, name)` | Check if header exists |
| `response-header(resp, name)` | Get header value directly from response |
| `response-content-type(resp)` | Get Content-Type from response |

### `url` (Hica)

URL and query string building:

| Function | Description |
|---|---|
| `build-url(base, params)` | Append query parameters to a URL |
| `build-query(params)` | Build a query string from `list<param>` |
| `Param(key, val)` | Query parameter constructor |

### `http_client` (Hica barrel)

Re-exports all modules plus convenience helpers:

| Function | Description |
|---|---|
| `json-get(url, timeout)` | GET with `Accept: application/json` |
| `json-post(url, body, timeout)` | POST with JSON content-type |
| `json-put(url, body, timeout)` | PUT with JSON content-type |
| `json-patch(url, body, timeout)` | PATCH with JSON content-type |
| `form-post(url, body, timeout)` | POST with form-encoded content-type |
| `with-bearer(token)` | Build Bearer auth header string |
| `with-basic-auth(credentials)` | Build Basic auth header string |

## License

MIT

