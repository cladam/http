# http

Hica HTTP **client and server** library. The client is built on
[libcurl](https://curl.se/libcurl/); the server on
[libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/), with a
FastAPI-style typed router on top.

## Requirements

- [libcurl](https://curl.se/libcurl/) — for the client (ships with macOS, `apt install libcurl4-openssl-dev` on Debian/Ubuntu)
- [libmicrohttpd](https://www.gnu.org/software/libmicrohttpd/) — for the server (`brew install libmicrohttpd` on macOS, `apt install libmicrohttpd-dev` on Debian/Ubuntu)
- [Koka](https://koka-lang.github.io/) 3.2.3+
- [Hica](https://github.com/cladam/hica) 0.41.6+

## Installation

### 1. Add the package

```sh
hica add http
hica fetch
```

This records the dependency in `hica.hml` and downloads the package.

### 2. Configure `hica.hml`

Add the linker and include flags to your project's `hica.hml`. The client only
needs `--cclib=curl`; the server additionally needs libmicrohttpd:

```hml
@project {
    name: "my-app"
    version: "0.1.0"
    entry: "main.hc"
}

@koka {
    include: "./lib/http/src"
    flags: "--cclib=curl --cclib=microhttpd --ccincdir=/opt/homebrew/include --cclinkopts=-L/opt/homebrew/lib"
}
```

> **Portability note:** the `/opt/homebrew` paths locate libmicrohttpd's headers
> and library on Apple Silicon macOS. On Intel macOS use `/usr/local`; on Linux
> libmicrohttpd installs to default search paths, so the extra `--ccincdir` /
> `--cclinkopts` entries are harmless no-ops and can be omitted. If you only use
> the client, drop `--cclib=microhttpd` and the two path flags entirely.

### 3. Import

The `http` module is written in Koka (C FFI), so you import it with `extern import`:

```rust
extern import "http"
import "http_client"
```

`extern import` passes the Koka module through without compilation.
`import http_client` brings in the Hica utilities (headers, URL building, auth helpers).

## Quick start

```rust
extern import "http"
import "http_client"

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

## Server

The server is built on libmicrohttpd. libmicrohttpd's internal thread handles
all socket I/O and holds concurrent connections open; requests are handed to
your handler **one at a time** for sequential processing (the Koka runtime is
single-threaded). This is well suited to I/O-bound services and tooling.

### Router (recommended)

`router.hc` provides a FastAPI-style typed router: declare routes with
`get`/`post`/`put`/`delete`/`patch`, and the first matching route wins.
Unmatched requests return `404` automatically. If a handler raises an exception
(a bad index, `unwrap` of an `Err`, an explicit throw, …), it is caught and
turned into a `500 Internal Server Error` — the server stays healthy and keeps
serving other requests.

```rust
import "router"

fun handle_get_item(req) : ServerResponse {
  let id = path_int(req, "id")             // path param /items/{id}
  let verbose = query_bool(req, "verbose") // ?verbose=true -> maybe<bool>
  json_response("\{\"id\": " + show(id) + "\}")
}

fun handle_create(req) : ServerResponse {
  // req body is available as a string; parse it with the json library
  json_response(req_body(req))
}

fun main() {
  println("Listening on :8080")
  serve_routes(8080, [
    get("/",              (req) => json_response("\{\"hello\": \"world\"\}")),
    get("/items/{id}",    handle_get_item),
    post("/items",        handle_create),
    delete("/items/{id}", (req) => status_response(204, ""))
  ])
}
```

#### Route constructors

| Function | Description |
|---|---|
| `get(pattern, handler)` | Register a `GET` route |
| `post(pattern, handler)` | Register a `POST` route |
| `put(pattern, handler)` | Register a `PUT` route |
| `delete(pattern, handler)` | Register a `DELETE` route |
| `patch(pattern, handler)` | Register a `PATCH` route |
| `any(pattern, handler)` | Match any HTTP method (catch-all) |
| `serve_routes(port, routes)` | Start serving; dispatches to routes, auto-404. Never returns |

Patterns support `{name}` path parameters, e.g. `/items/{id}/tags/{tag}`.
Trailing slashes are normalised.

#### Request helpers

Each handler receives a `request`. Read from it with these helpers (all take
`req` as the first argument):

| Function | Returns | Description |
|---|---|---|
| `path_str(req, key)` | `string` | Path parameter (`""` if absent) |
| `path_int(req, key)` | `int` | Path parameter as int (`0` if absent/non-numeric) |
| `query_str(req, key)` | `maybe<string>` | Query parameter |
| `query_int(req, key)` | `maybe<int>` | Query parameter as int |
| `query_bool(req, key)` | `maybe<bool>` | Query parameter (`true`/`1`, `false`/`0`) |
| `req_header(req, name)` | `maybe<string>` | Request header (case-insensitive) |
| `bearer_token(req)` | `maybe<string>` | Token from `Authorization: Bearer ...` |
| `req_method(req)` | `string` | Request method (`GET`, `POST`, ...) |
| `req_path(req)` | `string` | Request path |
| `req_body(req)` | `string` | Raw request body (parse with the json library) |

#### Response constructors

| Function | Description |
|---|---|
| `text_response(body)` | `200` with `text/plain` |
| `json_response(body)` | `200` with `application/json` |
| `html_response(body)` | `200` with `text/html` |
| `not_found_response()` | `404 Not Found` |
| `error_response(msg)` | `500` with the message |
| `status_response(status, body)` | Custom status with a plain-text body |

### Middleware

`middleware.hc` adds a Starlette-style middleware chain around the router. A
middleware is a function `(req, next) -> route_response`:

- call `next(req)` to continue the chain (and optionally transform the result)
- return a response **without** calling `next` to short-circuit

Middlewares run in list order — the first is outermost (runs first). Use
`serve_routes_mw` instead of `serve_routes`:

```rust
import "middleware"

fun main() {
  serve_routes_mw(8080, [
    get("/",   (req) => json_response("\{\"hello\": \"world\"\}")),
    get("/me", (req) => json_response("\{\"ok\": true\}"))
  ], [
    logger(),                    // logs "METHOD /path"
    cors("*"),                   // CORS headers + OPTIONS preflight
    require_bearer("secret123")  // 401/403 unless a matching Bearer token
  ])
}
```

#### Built-in middleware

| Function | Description |
|---|---|
| `logger()` | Log `"METHOD /path"` for each request, then continue |
| `cors(origin)` | Add `Access-Control-Allow-Origin` to responses; answer `OPTIONS` preflight with `204` |
| `require_bearer(token)` | `401` if the `Authorization` header is absent, `403` if the token mismatches, else continue |

#### Writing your own

A middleware is just a two-argument function returning a `route_response`. Build
short-circuit responses with the `respond_*` helpers, or transform a downstream
response with `route_add_header`:

```rust
fun request_timer() {
  (req, next) => {
    let resp = next(req)
    route_add_header(resp, "X-Handled-By", "hica")
  }
}
```

| Function | Description |
|---|---|
| `serve_routes_mw(port, routes, middlewares)` | Serve with a middleware chain wrapped around the router. Never returns |
| `respond_json(body)` | `200` `application/json` `route_response` |
| `respond_text(body)` | `200` `text/plain` `route_response` |
| `respond_status(code, body)` | Custom-status `text/plain` `route_response` |
| `route_add_header(resp, name, value)` | Append a header to a `route_response` |

### Typed request bodies

`body.hc` decodes a JSON request body into your own struct with validation,
returning **422 Unprocessable Entity** (as FastAPI does) on malformed or invalid
input. It is an opt-in module — importing it pulls in the [json](https://github.com/cladam/json)
library, and re-exports the `Json` type and `json_emit` so you can build responses too.

```rust
import "body"

struct Item { name: string, price: float, in_stock: bool }

// A decoder is `(Json) -> result<Item, string>`: chain field decoders and
// build your struct, or return an error message.
fun decode_item(doc: Json) : result<Item, string> {
  match field_str(doc, "name") {
    Err(e) => Err(e),
    Ok(name) => match field_num(doc, "price") {
      Err(e) => Err(e),
      Ok(price) => match opt_bool(doc, "in_stock") {
        Err(e) => Err(e),
        Ok(stock) => Ok(Item { name: name, price: price, in_stock: unwrap_maybe_or(stock, true) })
      }
    }
  }
}

// Encode a struct to a JSON value with the terse constructors.
fun encode_item(it: Item) : Json =>
  jobj([
    ("name",     jstr(it.name)),
    ("price",    jnum(it.price)),
    ("in_stock", jbool(it.in_stock))
  ])

fun handle_create(req) : ServerResponse {
  match decode_body(req, decode_item) {
    Ok(item) => created_json(encode_item(item)),   // 201 Created
    Err(msg) => unprocessable(msg)                  // 422 with {"detail": ...}
  }
}
```

#### Field decoders

Each returns `Ok(value)` when the field is present and the right type,
`Err(message)` when it is missing or the wrong type.

| Function | Returns | Description |
|---|---|---|
| `field_str(doc, key)` | `result<string, string>` | Required string field |
| `field_int(doc, key)` | `result<int, string>` | Required integer (rejects non-integral numbers) |
| `field_num(doc, key)` | `result<float, string>` | Required number (integer or float) |
| `field_bool(doc, key)` | `result<bool, string>` | Required boolean field |

Optional variants return `Ok(None)` when absent, `Ok(Some(v))` when present and
correct, and `Err` when present but the wrong type:

| Function | Returns |
|---|---|
| `opt_str(doc, key)` | `result<maybe<string>, string>` |
| `opt_int(doc, key)` | `result<maybe<int>, string>` |
| `opt_bool(doc, key)` | `result<maybe<bool>, string>` |

#### Body + response helpers

| Function | Description |
|---|---|
| `decode_body(req, decoder)` | Parse the request body as JSON, then run `decoder`. `Err` on malformed JSON or a decode failure |
| `unprocessable(msg)` | `422 Unprocessable Entity` with a `{"detail": msg}` JSON body |

#### Typed responses

The mirror of decoding: build a `Json` value with terse constructors, then send
it. Encode a collection by mapping the encoder over a list and wrapping in an
array — `ok_json(jarr(map(items, encode_item)))`.

| Function | Returns | Description |
|---|---|---|
| `jstr(s)` / `jnum(x)` / `jint(n)` / `jbool(b)` / `jnull()` | `Json` | Scalar JSON values |
| `jobj(fields)` | `Json` | Object from a `list<(string, Json)>` |
| `jarr(items)` | `Json` | Array from a `list<Json>` |
| `ok_json(j)` | `ServerResponse` | `200 OK` with the encoded JSON body |
| `created_json(j)` | `ServerResponse` | `201 Created` with the encoded JSON body |
| `json_response_of(status, j)` | `ServerResponse` | Custom status with the encoded JSON body |

### Low-level server (`http_server`)

For full control, use `serve` directly without the router. Your handler
receives a raw `server_request`; read its fields with the accessor helpers.

```rust
import "http_server"

fun main() {
  serve(8080, (req) => {
    if request_path(req) == "/health" {
      text_response("ok")
    } else {
      not_found_response()
    }
  })
}
```

| Function | Description |
|---|---|
| `serve(port, handler)` | Start serving; every request goes to `handler`. Never returns |
| `request_method(req)` | Request method as `string` |
| `request_path(req)` | Request path as `string` |
| `request_query(req)` | Raw query string (`"k=v&k2=v2"`) |
| `request_headers(req)` | Raw request headers (`"Name: Value\n..."`) |
| `request_body(req)` | Request body as `string` |

Build and run a server:

```sh
hica build examples/server.hc -o server
./server
```

See [`examples/server.hc`](examples/server.hc) for the low-level API and
[`examples/server_router.hc`](examples/server_router.hc) for the router with
JSON request/response handling.

## Testing your app

`testclient.hc` dispatches requests straight through your routes without opening
a socket, so you can unit-test an app with `hica test` — no running server, no
ports. Every helper returns a `route_response`; read it with
`route_response_status`, `route_response_headers`, and `route_response_body`.

```rust
import "../src/testclient"

fun app() => [
  get("/items/\{id\}", (req) => json_response("\{\"id\": " + show(path_int(req, "id")) + "\}")),
  post("/items",       (req) => status_response(201, req_body(req)))
]

test "GET /items/7 returns 200" {
  let r = test_get(app(), "/items/7")
  assert(route_response_status(r) == 200)
}

test "a missing route is a 404" {
  let r = test_get(app(), "/nope")
  assert(route_response_status(r) == 404)
}
```

| Function | Description |
|---|---|
| `test_get(routes, path)` | Dispatch a `GET`. `path` may include a query string (`/items?page=2`) |
| `test_post(routes, path, body)` | Dispatch a `POST` with a body |
| `test_put(routes, path, body)` | Dispatch a `PUT` with a body |
| `test_patch(routes, path, body)` | Dispatch a `PATCH` with a body |
| `test_delete(routes, path)` | Dispatch a `DELETE` |
| `test_request(routes, method, path, headers, body)` | Full control, including raw request headers |
| `test_request_mw(routes, middlewares, method, path, headers, body)` | Dispatch through the middleware chain too |

## License

MIT
