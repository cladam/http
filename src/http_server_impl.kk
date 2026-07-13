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

extern http_server_start_raw( port : int ) : io int
  c "kk_http_server_start"

extern http_server_accept_raw( srv : int ) : io int
  c "kk_http_server_accept"

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

extern http_server_respond_raw(
  srv     : int,
  req     : int,
  status  : int,
  headers : string,
  body    : string
) : io ()
  c "kk_http_server_respond"

extern http_server_stop_raw( srv : int ) : io ()
  c "kk_http_server_stop"

// ---------------------------------------------------------------------------
// Public API
// ---------------------------------------------------------------------------

// Start an HTTP server listening on the given port.
// Returns a server handle to pass to http_server_accept / http_server_stop.
pub fun http_server_start( port : int ) : io http_server
  http_server_start_raw(port)

// Block until the next HTTP request arrives, then return it.
// Multiple simultaneous connections are held by libmicrohttpd; this returns
// one at a time for sequential processing.
pub fun http_server_accept( srv : http_server ) : io server_request
  val rid  = http_server_accept_raw(srv)
  val meth = http_req_method_raw(rid)
  val pth  = http_req_path_raw(rid)
  val qry  = http_req_query_raw(rid)
  val hdrs = http_req_headers_raw(rid)
  val bdy  = http_req_body_raw(rid)
  Server_request(meth, pth, qry, hdrs, bdy, rid)

// Send an HTTP response for a pending request.
// headers is a newline-separated "Name: Value" string.
// The request handle is consumed — do not call this twice for the same req.
pub fun http_server_respond(
  srv     : http_server,
  req     : server_request,
  status  : int,
  headers : string,
  body    : string
) : io ()
  http_server_respond_raw(srv, req.req_id, status, headers, body)

// Stop the server and release all resources.
pub fun http_server_stop( srv : http_server ) : io ()
  http_server_stop_raw(srv)

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
