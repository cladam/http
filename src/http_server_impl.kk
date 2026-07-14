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

// Stage the response (status + headers + body) for the request node `node`.
// Called from inside a handler; libmicrohttpd sends it once the handler returns.
pub fun http_set_response( node : int, status : int, headers : string, body : string ) : io ()
  http_set_response_raw(node, status, headers, body)

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
