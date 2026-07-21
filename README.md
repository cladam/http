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

> **Tip:** `web.hc` is a convenience barrel — `import "web"` re-exports the
> router, middleware, static-file, and content-negotiation modules (and the
> response helpers) so a typical app needs a single import. Add `import "body"`
> too for typed request/response bodies (it is separate because it pulls in the
> json library).

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
| `group(prefix, routes)` | Prefix a list of routes with a shared path |
| `serve_routes(port, routes)` | Start serving; dispatches to routes, auto-404. Never returns |

Patterns support `{name}` path parameters, e.g. `/items/{id}/tags/{tag}`.
Trailing slashes are normalised.

`group` mounts a set of routes under a shared prefix (like Ktor's
`route("/tasks") { ... }`). It returns a plain list, so it composes with `+`
and nests:

```rust
serve_routes(8080,
  group("/tasks", [
    get("/",     list_tasks),    // GET  /tasks
    get("/{id}", get_task),      // GET  /tasks/{id}
    post("/",    create_task)    // POST /tasks
  ]) +
  [ get("/health", health) ])    // GET  /health
```

#### Request helpers

Each handler receives a `request`. Read from it with these helpers (all take
`req` as the first argument):

| Function | Returns | Description |
|---|---|---|
| `path_str(req, key)` | `string` | Path parameter (`""` if absent) |
| `path_int(req, key)` | `int` | Path parameter as int (`0` if absent/non-numeric) |
| `path_str_opt(req, key)` | `maybe<string>` | Path parameter (`None` if absent) |
| `path_int_opt(req, key)` | `maybe<int>` | Path parameter as int (`None` if absent/non-numeric) |
| `query_str(req, key)` | `maybe<string>` | Query parameter |
| `query_int(req, key)` | `maybe<int>` | Query parameter as int |
| `query_bool(req, key)` | `maybe<bool>` | Query parameter (`true`/`1`, `false`/`0`) |
| `req_header(req, name)` | `maybe<string>` | Request header (case-insensitive) |
| `bearer_token(req)` | `maybe<string>` | Token from `Authorization: Bearer ...` |
| `req_method(req)` | `string` | Request method (`GET`, `POST`, ...) |
| `req_path(req)` | `string` | Request path |
| `req_body(req)` | `string` | Raw request body (parse with the json library) |
| `form_str(req, key)` | `maybe<string>` | Field from a urlencoded form body |
| `form_int(req, key)` | `maybe<int>` | Form field as int |
| `cookie(req, key)` | `maybe<string>` | Value from the `Cookie` request header |
| `accepts(req, mime)` | `bool` | Does the client's `Accept` header allow `mime`? |

#### Response constructors

| Function | Description |
|---|---|
| `text_response(body)` | `200` with `text/plain` |
| `json_response(body)` | `200` with `application/json` |
| `html_response(body)` | `200` with `text/html` |
| `not_found_response()` | `404 Not Found` |
| `error_response(msg)` | `500` with the message |
| `status_response(status, body)` | Custom status with a plain-text body |
| `content_response(status, content_type, body)` | Custom status with an explicit `Content-Type` |
| `redirect(url)` | `302 Found` to `url` |
| `redirect_permanent(url)` | `301 Moved Permanently` to `url` |
| `accepted(body)` | `202 Accepted` |
| `no_content()` | `204 No Content` |
| `bad_request(msg)` | `400 Bad Request` |
| `unauthorized(msg)` | `401 Unauthorized` |
| `forbidden(msg)` | `403 Forbidden` |
| `with_header(resp, name, value)` | Append a header to a response |
| `set_cookie(resp, name, value)` | Add a `Set-Cookie` header (`Path=/`) |

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
| `logger()` | Log an access line `"METHOD /path STATUS Nms"` after each request (status + latency), flushed so file-redirected logs stay current |
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

### Error handling

If a handler raises an exception (a bad list index, an `unwrap` of an `Err`, a
division by zero, an explicit `throw`, ...) the server catches it and returns a
plain `500 Internal Server Error`, keeping the event loop healthy. To decide the
response yourself (like Ktor's `StatusPages` `exception<T> { ... }`) use the
`_with_errors` variants and pass an `on_error` callback. It receives the caught
exception message and returns a `ServerResponse`:

```rust
fun on_error(msg: string) : ServerResponse {
  json_status(500, "\{\"error\": \"internal\"\}")
}

fun main() {
  serve_routes_with_errors(8080, [
    get("/",     (req) => json_response("\{\"ok\": true\}")),
    get("/boom", (req) => json_response("ok " + show(1 / 0)))  // raises
  ], on_error)
}
```

Unmatched routes still return `404`. See [`examples/server_errors.hc`](examples/server_errors.hc).

| Function | Description |
|---|---|
| `serve_routes_with_errors(port, routes, on_error)` | Like `serve_routes`, but a caught exception's message is passed to `on_error`, which returns the response. Never returns |
| `serve_routes_mw_with_errors(port, routes, middlewares, on_error)` | `serve_routes_mw` with a custom error handler. Never returns |

### Content negotiation

`negotiation.hc` offers several representations of a resource and lets the
client's `Accept` header choose — like Ktor's `ContentNegotiation` /
`call.respond(obj)`. Ranges (`type/*`, `*/*`) and quality values (`;q=0.8`) are
honoured, and a more specific range wins over a less specific one, so a browser
is served HTML while an API client (or curl's default `*/*`) is served JSON —
even when JSON is offered first:

```rust
import "negotiation"

fun handle_item(req) : ServerResponse {
  negotiate(req, [
    ("application/json",         "\{\"name\": \"Widget\"\}"),
    ("text/html; charset=utf-8", "<h1>Widget</h1>")
  ])
}
```

`negotiate` returns a `200` with the chosen `Content-Type` and a `Vary: Accept`
header, or `406 Not Acceptable` when the client accepts none of the offers. See
[`examples/server_negotiation.hc`](examples/server_negotiation.hc).

| Function | Description |
|---|---|
| `negotiate(req, offers)` | Pick a representation from `[(content_type, body), ...]` by the `Accept` header; `406` if none match |
| `accepts(req, mime)` | `true` if the client's `Accept` header allows `mime` |
| `accepts_json(req)` | Shorthand for `accepts(req, "application/json")` |
| `accepts_html(req)` | Shorthand for `accepts(req, "text/html")` |
| `not_acceptable()` | `406 Not Acceptable` response |

### Typed request bodies

`body.hc` decodes a JSON request body into your own struct with validation,
returning **422 Unprocessable Entity** (as FastAPI does) on malformed or invalid
input. It is an opt-in module, importing it pulls in the [json](https://github.com/cladam/json)
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

fun handle_create(req) {
  // with_body decodes-or-422s, then hands you the typed value — the round
  // trip of Ktor's call.receive<T>() + call.respond(obj).
  with_body(req, decode_item, (item) =>
    created_json(encode_item(item)))   // 201 on success, 422 on a bad body
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
| `with_body(req, decoder, handler)` | Decode the body; call `handler` with the typed value, or return `422` on a bad body. The typed round-trip |
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

### Multipart / file uploads

`multipart.hc` (included in the `web` barrel) parses `multipart/form-data`
request bodies into a list of `Part` values. The parsing is done in the C layer
by libmicrohttpd's `MHD_PostProcessor`, so each part's bytes arrive
incrementally and are fully accumulated before your handler is called.

Each part is binary-safe: `Part.bytes` is a raw byte string and can hold
arbitrary data including NUL bytes. Individual parts are capped at **64 MiB** by
the C layer; uploads beyond that are rejected by MHD before the handler is
invoked.

```rust
import "web"     // re-exports multipart

// Publish endpoint: accepts a JSON metadata part and a binary tarball part.
fun handle_publish(req) {
  match req_part(req, "metadata") {
    None       => bad_request("missing 'metadata' part"),
    Some(meta) => match req_part(req, "tarball") {
      None      => bad_request("missing 'tarball' part"),
      Some(tar) => {
        let name = path_str(req, "name")
        let ver  = path_str(req, "version")
        // tar.bytes contains the raw tarball bytes; tar.filename is the
        // original filename sent by the client.
        // Verify sha256(tar.bytes) against meta, write to store, etc.
        json_response("\{\"ok\": true, \"package\": \"" + name + "\"\}")
      }
    }
  }
}

fun main() {
  serve_routes(8080, [
    put("/api/v1/packages/{name}/{version}", (req) => handle_publish(req))
  ])
}
```

Test with curl:

```sh
curl -X PUT http://localhost:8080/api/v1/packages/json/0.1.0 \
     -F metadata='{"name":"json","version":"0.1.0","checksum":"sha256:abc"}' \
     -F tarball=@json-0.1.0.tar.gz
```

#### `Part` struct

```
Part {
  name         : string   // form-field name (always present)
  filename     : string   // original filename; "" for non-file fields
  content_type : string   // MIME type from the part header; "" if absent
  bytes        : string   // raw bytes (binary-safe)
}
```

#### Multipart helpers

| Function | Description |
|---|---|
| `req_part(req, name)` | Get a named part; `None` if absent or the request is not multipart |
| `req_parts(req)` | All parts as a list (empty for non-multipart requests) |
| `req_files(req)` | Only parts that carry a filename (file upload parts) |
| `is_multipart(req)` | `true` if the request is multipart and at least one part was parsed |
| `part_str(req, name)` | Convenience — bytes of a named text part as `maybe<string>` |

Non-file form fields (sent without a `filename` attribute) appear as parts with
`filename == ""`. Use `req_part` to read them by name, or iterate `req_parts`
to process all parts. Text fields are available immediately as `Part.bytes`; no
URL-decoding is needed (MHD handles that).

See [`examples/server_multipart.hc`](examples/server_multipart.hc) for a
runnable publish-endpoint example.

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

### Cooperative Concurrency

Because the HTTP server is single-threaded, a blocking call inside a handler (like a heavy computation or database query) blocks the entire server.

To solve this, Hica supports cooperative concurrency and interleaves request processing with background actors. Rather than blocking the main thread, the handler immediately returns `202 Accepted` after enqueuing the payload, and a single-threaded cooperative event loop drives both server polling and background actors together.

#### Non-blocking loop primitives

For cooperative concurrency, use the non-blocking polling APIs:

| Function | Description |
|---|---|
| `server_init(port, handler)` | Initialize the server on a port without starting the blocking serve loop |
| `server_poll(srv)` | Process a single-step non-blocking HTTP event loop cycle. Returns `1` if active |
| `server_stop(srv)` | Stop the server and clean up resources |

#### Example: Non-blocking Background Worker (Webhook Processor)

An incoming webhook is instantly queued, and the main cooperative loop schedules tasks to a background `WebhookWorker` actor:

```rust
import "http_server"
import "std/actor"

type WorkerMsg {
  ProcessPayload(data: string)
}

actor WebhookWorker {
  var processed_count = 0

  receive(msg) => match msg {
    ProcessPayload(data) => {
      processed_count = processed_count + 1
      println("  [Worker] Processed webhook #" + show(processed_count) + " data: " + data)
    }
  }
}

pub fun main() {
  println("Initializing cooperative HTTP server on port 8080...")
  var worker_state = WebhookWorkerState { processed_count: 0 }
  var pending_payloads = []

  // Non-blocking server initialization
  let srv = server_init(8080, (req) => {
    let payload = request_body(req)
    pending_payloads = pending_payloads + [payload]
    accepted("\{\"status\": \"queued\"\}")
  })

  // Start the cooperative polling loop
  run_loop(srv, worker_state, pending_payloads)
  server_stop(srv)
}

pub fun run_loop(srv: int, worker: WebhookWorkerState, payloads: list<string>) : () {
  // Process one HTTP server poll cycle
  let _ = server_poll(srv)

  // Dispatch pending tasks to the actor cooperatively
  var next_worker = worker
  var next_payloads = payloads

  match payloads {
    [] => ()
    [payload, ..rest] => {
      next_worker = webhookworker_receive(worker, ProcessPayload(payload))
      next_payloads = rest
    }
  }

  // Recurse to keep the single-threaded event loop alive
  run_loop(srv, next_worker, next_payloads)
}
```

See [`examples/server_cooperative_worker.hc`](examples/server_cooperative_worker.hc) for a complete, runnable simulation.

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

## Serving static files

`static.hc` serves files from a directory. Mount it on a route with a trailing
`*` wildcard, which captures the rest of the path:

```rust
import "../src/static"

// A named handler that serves files from ./public via the "*" capture.
fun assets(req) => serve_file_from(req, "./public")

fun main() {
  serve_routes(8080, [
    get("/",         (req) => html_response("<h1>Home</h1>")),
    get("/static/*", assets)
  ])
}
```

A request for `/static/css/app.css` reads `./public/css/app.css`. The
`Content-Type` is chosen from the file extension; an empty capture serves
`index.html`; a missing file is a `404`; and any attempt to escape the directory
(a `..` segment or an absolute path) is a `403`.

| Function | Description |
|---|---|
| `serve_file_from(req, dir)` | Serve the `*`-captured path from under `dir` (403 unsafe / 404 missing) |
| `content_type_for(path)` | Content-Type for a file extension |
| `is_safe_rel(rel)` | False if `rel` escapes the directory (`..` or absolute) |

The `*` wildcard is a general router feature — a `"/prefix/*"` pattern matches
any remaining path and captures it under `path_str(req, "*")`.

> **Notes:** `serve_file_from` must be wrapped in a **named** handler (a returned
> closure that reads the filesystem does not currently type-check in hica). Files
> are read as UTF-8 text, so binary assets like images are not yet supported.

## License

MIT
