# http

Hica HTTP client library built on top of libcurl.

## Requirements

- [libcurl](https://curl.se/libcurl/) installed on your system (ships with macOS, `apt install libcurl4-openssl-dev` on Debian/Ubuntu)
- [Koka](https://koka-lang.github.io/) 3.2.3+
- [Hica](https://github.com/cladam/hica) 0.37.0+

## Setup

Add the library as a git submodule in your project:

```sh
mkdir -p lib
git submodule add https://github.com/cladam/hica-http lib/http
```

Then configure your `hica.hml` to include the library source and link libcurl:

```hml
@project {
    name: "my-app"
    version: "0.1.0"
    entry: "main.hc"
}

@koka {
    include: "./lib/http/src"
    flags: "--cclib=curl"
}
```

The `http` module is written in Koka (C FFI), so you import it with `extern import`:

```rust
extern import "http"
import http_client
```

`extern import` passes the Koka module through without compilation.
`import http_client` brings in the Hica utilities (headers, URL building, auth helpers).

## Quick start

```rust
extern import "http"
import http_client

fun main() {
  // Simple GET request
  let resp = http_get("https://httpbin.org/get", timeout=10)
  println("Status: " + show(resp.status))
  println("OK? " + show(is_ok(resp)))

  // Parse response headers
  let hdrs = parse_headers(resp.headers)
  println("Content-Type: " + unwrap_maybe_or(get_header(hdrs, "Content-Type"), "(none)"))

  // JSON POST
  let post_resp = json_post("https://httpbin.org/post", "\{\"hello\":\"world\"\}")
  println("Post status: " + show(post_resp.status))

  // Build URL with query parameters
  let url = build_url("https://httpbin.org/get", [
    Param { key: "page", value: "1" },
    Param { key: "limit", value: "10" }
  ])
  let qresp = http_get(url)
  println("Query status: " + show(qresp.status))
}
```

Build and run:

```sh
hica build main.hc
./main
```

The `@koka` block in `hica.hml` handles include paths and compiler flags automatically.

## API reference

### `http` (Koka — extern import)

Core HTTP functions powered by libcurl:

| Function | Description |
|---|---|
| `http_get(url, timeout=0)` | GET request |
| `http_post(url, body, content_type, timeout)` | POST request |
| `http_put(url, body, content_type, timeout)` | PUT request |
| `http_delete(url, timeout)` | DELETE request |
| `http_patch(url, body, content_type, timeout)` | PATCH request |
| `http_head(url, timeout)` | HEAD request |
| `http_request(method, url, body, content_type, headers, timeout)` | General request with custom headers |
| `is_ok(resp)` | True if status is 2xx |
| `is_redirect(resp)` | True if status is 3xx |
| `is_client_error(resp)` | True if status is 4xx |
| `is_server_error(resp)` | True if status is 5xx |
| `json_get(url, timeout)` | GET with `Accept: application/json` |
| `json_post(url, body, timeout)` | POST with JSON content type |
| `json_put(url, body, timeout)` | PUT with JSON content type |
| `json_patch(url, body, timeout)` | PATCH with JSON content type |
| `form_post(url, body, timeout)` | POST with form-urlencoded content type |

All functions return an `http_response` with fields: `status` (int), `body` (string), `headers` (string).

> **Note (Hica callers):** `is_ok` collides with Hica's built-in `Result` combinator of the same name. In `.hc` code, `is_ok(resp)` resolves to the built-in (compiled to `.is-right`) instead of this function — use `resp.status >= 200 && resp.status < 300` instead. `is_redirect`, `is_client_error`, and `is_server_error` are unaffected, as are all Koka callers.

### `headers` (Hica)

Header parsing and lookup:

| Function | Description |
|---|---|
| `parse_headers(raw)` | Parse raw header string into `list<Header>` |
| `get_header(hdrs, name)` | Look up header by name (case-insensitive), returns `maybe<string>` (`None` if not found) |
| `has_header(hdrs, name)` | Check if a header exists |
| `find_header(raw, name)` | Shortcut — parse + look up in one call, returns `maybe<string>` |

### `url` (Hica)

URL and query string building:

| Function | Description |
|---|---|
| `build_url(base, params)` | Append query parameters to a URL |
| `build_query(params)` | Build a query string from `list<Param>` |
| `encode_param(p)` | Encode a single `Param` as `key=value` |
| `Param { key, value }` | Query parameter constructor |

### `http_client` (Hica barrel)

Re-exports `headers` and `url`, plus auth helpers:

| Function | Description |
|---|---|
| `with_bearer(token)` | Build `Authorization: Bearer <token>` header string |
| `with_basic_auth(credentials)` | Build `Authorization: Basic <credentials>` header string |

Use with `http_request`:

```hica
let resp = http_request("GET", "https://api.example.com/me", headers=with_bearer(my_token))
```

## License

MIT
