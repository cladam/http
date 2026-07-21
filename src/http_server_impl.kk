/*
 * http_server_impl.kk — Koka FFI bindings for the hica HTTP server
 * Backed by libmicrohttpd via http_server_inline.c
 *
 * Part of the hica ecosystem
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module http_server_impl

extern import
  c file "http_server_inline.c"

// ---------------------------------------------------------------------------
// Types
// ---------------------------------------------------------------------------

// Opaque server handle (wraps a C hcsrv_t* pointer).
pub alias http_server = int

// A pending HTTP request.  req_id holds the C hcsrv_req_t* pointer and is
// consumed by http_server_respond — do not use it directly.
pub struct server_request
  method  : string
  path    : string
  query   : string   // decoded query string, e.g. "page=1&limit=10"
  headers : string   // raw request headers "Name: Value\n..."
  body    : string
  req_id  : int      // internal: C-side request handle

// ---------------------------------------------------------------------------
// Raw externs — call the C functions in http_server_inline.c
// ---------------------------------------------------------------------------

// A request handler: given a request node id, read the request, compute a
// response, and stage it via http_set_response.
pub alias req_handler = (int) -> io ()

extern http_server_run_raw( port : int, on_request : req_handler ) : io ()
  c "kk_http_server_run"

extern http_server_init_raw( port : int, on_request : req_handler ) : io int
  c "kk_http_server_init"

extern http_server_poll_raw( srv_ptr : int ) : io int
  c "kk_http_server_poll"

extern http_server_stop_raw( srv_ptr : int ) : io ()
  c "kk_http_server_stop"

extern http_set_response_raw( node : int, status : int, headers : string, body : string ) : io ()
  c "kk_http_set_response"

extern http_req_method_raw( req : int ) : io string
  c "kk_http_req_method"

extern http_req_path_raw( req : int ) : io string
  c "kk_http_req_path"

extern http_req_query_raw( req : int ) : io string
  c "kk_http_req_query"

extern http_req_headers_raw( req : int ) : io string
  c "kk_http_req_headers"

extern http_req_body_raw( req : int ) : io string
  c "kk_http_req_body"

extern http_now_millis_raw() : io int
  c "kk_http_now_millis"

extern http_flush_stdout_raw() : io ()
  c "kk_http_flush_stdout"

// Multipart: number of parsed parts (0 for non-multipart requests).
extern http_req_part_count_raw( req : int ) : io int
  c "kk_http_req_part_count"

// Multipart: read a field of part[idx].
// selector: 0=name, 1=filename, 2=content_type, 3=bytes (binary-safe).
extern http_req_part_field_raw( req : int, idx : int, sel : int ) : io string
  c "kk_http_req_part_field"

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

// Run an HTTP server on `port`.  For every request, `handler` is invoked with
// the request's node id; the handler reads the request via `request_from_id`,
// computes a response, and stages it with `http_set_response`.  The request is
// handled synchronously on this thread inside libmicrohttpd's event loop, so
// there is no cross-thread handoff.  Never returns.
pub fun http_server_run( port : int, on_request : req_handler ) : io ()
  http_server_run_raw(port, on_request)

// Initialize the HTTP server on `port` asynchronously/non-blockingly.
// Returns a handle (int) to the server state.
pub fun http_server_init( port : int, on_request : req_handler ) : io int
  http_server_init_raw(port, on_request)

// Poll the HTTP server once. Returns 1 if active, 0 on stop/error.
pub fun http_server_poll( srv_ptr : int ) : io int
  http_server_poll_raw(srv_ptr)

// Stop the HTTP server and free associated memory.
pub fun http_server_stop( srv_ptr : int ) : io ()
  http_server_stop_raw(srv_ptr)

// Stage the response (status + headers + body) for the request node `node`.
// Called from inside a handler; libmicrohttpd sends it once the handler returns.
pub fun http_set_response( node : int, status : int, headers : string, body : string ) : io ()
  http_set_response_raw(node, status, headers, body)

// Monotonic clock in milliseconds (for measuring request latency).
pub fun http_now_millis() : io int
  http_now_millis_raw()

// Flush stdout — Koka block-buffers stdout when it is not a TTY, so the access
// logger calls this after each line to keep file-redirected logs current.
pub fun http_flush_stdout() : io ()
  http_flush_stdout_raw()

// Build a server_request value from a request node id (used inside a handler).
pub fun request_from_id( node : int ) : io server_request
  val meth = http_req_method_raw(node)
  val pth  = http_req_path_raw(node)
  val qry  = http_req_query_raw(node)
  val hdrs = http_req_headers_raw(node)
  val bdy  = http_req_body_raw(node)
  Server_request(meth, pth, qry, hdrs, bdy, node)

// ---------------------------------------------------------------------------
// Field accessors — Hica callers cannot read fields off an extern Koka
// struct directly (req.path generates an unknown accessor), so expose these.
// ---------------------------------------------------------------------------

pub fun request_method( req : server_request ) : string
  req.method

pub fun request_path( req : server_request ) : string
  req.path

pub fun request_query( req : server_request ) : string
  req.query

pub fun request_headers( req : server_request ) : string
  req.headers

pub fun request_body( req : server_request ) : string
  req.body

// ---------------------------------------------------------------------------
// Multipart part access — used by multipart.hc
// ---------------------------------------------------------------------------

// Number of parsed multipart parts (0 for non-multipart requests).
pub fun http_req_part_count( req : server_request ) : io int
  http_req_part_count_raw(req.req_id)

// Name of part at index idx.
pub fun http_req_part_name( req : server_request, idx : int ) : io string
  http_req_part_field_raw(req.req_id, idx, 0)

// Original filename of part at index idx ("" if not a file part).
pub fun http_req_part_filename( req : server_request, idx : int ) : io string
  http_req_part_field_raw(req.req_id, idx, 1)

// Content-Type of part at index idx ("" if not specified).
pub fun http_req_part_content_type( req : server_request, idx : int ) : io string
  http_req_part_field_raw(req.req_id, idx, 2)

// Raw bytes of part at index idx (binary-safe).
pub fun http_req_part_bytes( req : server_request, idx : int ) : io string
  http_req_part_field_raw(req.req_id, idx, 3)

// ---------------------------------------------------------------------------
// Multipart by-id variants — used by multipart.hc which receives the router's
// `request` type (not `server_request`) and passes req_id explicitly.
// ---------------------------------------------------------------------------

pub fun http_part_count_by_id( req_id : int ) : io int
  http_req_part_count_raw(req_id)

pub fun http_part_field_by_id( req_id : int, idx : int, sel : int ) : io string
  http_req_part_field_raw(req_id, idx, sel)
