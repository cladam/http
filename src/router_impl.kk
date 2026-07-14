/*
 * router_impl.kk — Route types, path matching, param extraction, and dispatch
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module router_impl

import http_server_impl

// ---------------------------------------------------------------------------
// Types
// ---------------------------------------------------------------------------

// Enhanced request handed to every route handler.
// path_params holds segments extracted from the route pattern (e.g. {id}).
// query_params holds key/value pairs parsed from the query string.
pub struct request
  method       : string
  path         : string
  path_params  : list<(string, string)>
  query_params : list<(string, string)>
  headers      : string     // raw "Name: Value\n..." string
  body         : string

// The response type returned by route handlers.
pub struct route_response
  status  : int
  headers : string
  body    : string

// A route definition.
pub struct route
  method  : string
  pattern : string
  handler_fn : (request) -> io route_response

// ---------------------------------------------------------------------------
// Constructors (called from Hica, which cannot call Koka constructors directly)
// ---------------------------------------------------------------------------

pub fun make_route(method: string, pattern: string, handler_fn: (request) -> io route_response) : route
  Route(method, pattern, handler_fn)

// `noinline` so the Route_response allocation is never fused (via Perceus reuse)
// with a caller's drop of an unrelated value — that fusion corrupts the heap when
// a short-circuiting middleware drops its `next` closure in the same branch.
pub noinline fun make_route_response(status: int, headers: string, body: string) : route_response
  Route_response(status, headers, body)

// Typed accessors for route_response — used where the value's type is inferred
// (e.g. middleware plumbing), avoiding ambiguity with the other structs that
// also have status/headers/body fields.
pub fun route_response_status(r: route_response) : int
  r.status

pub fun route_response_headers(r: route_response) : string
  r.headers

pub fun route_response_body(r: route_response) : string
  r.body

// Append a header to a route_response in a single destructure.  Doing this in
// one match (rather than three separate consuming accessor calls) avoids a
// Perceus refcount corruption seen when chained in a short-circuiting branch.
pub fun route_add_header(resp: route_response, name: string, value: string) : route_response
  match resp
    Route_response(st, hs, bd) ->
      val sep = if hs == "" then "" else "\n"
      Route_response(st, hs ++ sep ++ name ++ ": " ++ value, bd)

// Build a request value from raw strings, running path matching and query
// parsing the same way the dispatcher does.  Useful for tests and manual
// dispatch.  If the path does not match the pattern, path params are empty.
pub fun build_request(method: string, pattern: string, path: string, query: string, headers: string, body: string) : request
  val pp = match match_path(pattern, path)
             Just(p) -> p
             Nothing -> []
  val qp = parse_query_params(query)
  Request(method, path, pp, qp, headers, body)

// Build a request from a raw server_request for pre-routing inspection
// (middleware).  Path params are empty because no route has matched yet;
// query params are parsed so middleware can read them.
pub fun build_base_request(sreq: server_request) : request
  val qp = parse_query_params(sreq.query)
  Request(sreq.method, sreq.path, [], qp, sreq.headers, sreq.body)

// ---------------------------------------------------------------------------
// Path pattern matching
//
// match_path("/items/{id}/tags/{tag}", "/items/42/tags/koka")
//   => Just([("id","42"), ("tag","koka")])
//
// Patterns must match exactly in segment count; {name} captures any segment.
// Trailing slashes are normalised before matching.
// ---------------------------------------------------------------------------

pub fun match_path(pattern: string, path: string) : maybe<list<(string, string)>>
  val pat = normalize(pattern)
  val pth = normalize(path)
  match_parts(split(pat, "/"), split(pth, "/"), [])

// Substring [start, endx) using supported sslice ops. Koka has no s[a:b] syntax.
fun str_slice(s : string, start : int, endx : int) : string
  // Build a fresh string from the char list.  Avoids sslice views that share
  // the source buffer (which dangle/double-free when the slice outlives the
  // source, e.g. a token returned from bearer_token into user code).
  s.list.drop(start).take(endx - start).string

fun normalize(s: string) : string
  if s != "/" && s.ends-with("/").bool then str_slice(s, 0, s.count - 1) else s

// Match a path against a pattern and return the captured value for `key`.
// Returns Nothing if the path does not match, or if the pattern has no such
// parameter.  Convenient for tests and manual routing.
pub fun match_param(pattern: string, path: string, key: string) : maybe<string>
  match match_path(pattern, path)
    Nothing      -> Nothing
    Just(params) -> lookup_kv(params, key)

// Structural recursion on `pat` (its tail `ps` is strictly smaller) keeps this
// total — no `div` effect, so it never leaks divergence into user handlers.
// A pattern segment of "*" is a trailing wildcard: it captures the entire
// remaining path (joined with "/") under the key "*", so "/static/*" matches
// "/static/css/app.css" with "*" -> "css/app.css".
fun match_parts(pat: list<string>, path: list<string>, acc: list<(string, string)>) : maybe<list<(string, string)>>
  match pat
    [] -> match path
      [] -> Just(reverse(acc))
      _  -> Nothing
    Cons(p, ps) ->
      if p == "*"
        then Just(reverse([("*", join(path, "/"))] ++ acc))
        else match path
          [] -> Nothing
          Cons(v, vs) ->
            if p.starts-with("{").bool && p.ends-with("}").bool
              then
                val name = str_slice(p, 1, p.count - 1)
                match_parts(ps, vs, [(name, v)] ++ acc)
              else if p == v
                then match_parts(ps, vs, acc)
                else Nothing

// ---------------------------------------------------------------------------
// Query string parsing: "k=v&k2=v2" -> [("k","v"),("k2","v2")]
// ---------------------------------------------------------------------------

pub fun parse_query_params(query: string) : list<(string, string)>
  if query == "" then []
  else map(split(query, "&"), parse_kv)

fun parse_kv(pair: string) : (string, string)
  val parts = split(pair, "=")
  match parts
    []          -> (pair, "")
    [k]         -> (k, "")
    Cons(k, rest) -> (k, join(rest, "="))

// ---------------------------------------------------------------------------
// Param lookups
// ---------------------------------------------------------------------------

fun lookup_kv(kvs: list<(string, string)>, key: string) : maybe<string>
  match kvs
    []               -> Nothing
    Cons((k, v), rest) -> if k == key then Just(v) else lookup_kv(rest, key)

// Path parameter as string ("" if not present).
pub fun path_str(req: request, key: string) : string
  match lookup_kv(req.path_params, key)
    Nothing -> ""
    Just(v) -> v

// Path parameter as int (0 if absent or not parseable).
pub fun path_int(req: request, key: string) : int
  parse_int_str(path_str(req, key))

// Path parameter as maybe<string>. Nothing if the parameter is absent.
// Use this (rather than path_str) when you need to distinguish a missing
// parameter from an empty capture and return, say, a 400.
pub fun path_str_opt(req: request, key: string) : maybe<string>
  lookup_kv(req.path_params, key)

// Path parameter as maybe<int>. Nothing if the parameter is absent or does
// not parse as an integer — so you can tell a genuine 0 from bad/missing input.
pub fun path_int_opt(req: request, key: string) : maybe<int>
  match lookup_kv(req.path_params, key)
    Nothing -> Nothing
    Just(v) -> parse_int_str_maybe(v)

// Query parameter as maybe<string>.
pub fun query_str(req: request, key: string) : maybe<string>
  lookup_kv(req.query_params, key)

// Query parameter as maybe<int>.
pub fun query_int(req: request, key: string) : maybe<int>
  match lookup_kv(req.query_params, key)
    Nothing -> Nothing
    Just(v) -> parse_int_str_maybe(v)

// Query parameter as maybe<bool>. Accepts "true"/"1" and "false"/"0".
pub fun query_bool(req: request, key: string) : maybe<bool>
  match lookup_kv(req.query_params, key)
    Nothing       -> Nothing
    Just("true")  -> Just(True)
    Just("1")     -> Just(True)
    Just("false") -> Just(False)
    Just("0")     -> Just(False)
    _             -> Nothing

// ---------------------------------------------------------------------------
// Form fields (application/x-www-form-urlencoded request bodies)
//
// The body has the same shape as a query string ("a=1&b=2"), so it is parsed
// with the same code.
// ---------------------------------------------------------------------------

// Form field as maybe<string>, parsed from the urlencoded request body.
pub fun form_str(req: request, key: string) : maybe<string>
  lookup_kv(parse_query_params(req.body), key)

// Form field as maybe<int>.
pub fun form_int(req: request, key: string) : maybe<int>
  match form_str(req, key)
    Nothing -> Nothing
    Just(v) -> parse_int_str_maybe(v)

// ---------------------------------------------------------------------------
// Header lookup (case-insensitive search in the raw header string)
// ---------------------------------------------------------------------------

// Find a request header by name. Returns maybe<string>.
pub fun req_header(req: request, key: string) : maybe<string>
  find_in_headers(split(req.headers, "\n"), to-lower(key))

// ---------------------------------------------------------------------------
// Cookies (parsed from the Cookie request header: "a=1; b=2")
// ---------------------------------------------------------------------------

fun parse_cookie_pair(pair: string) : (string, string)
  val t = trim(pair)
  match split(t, "=")
    []            -> (t, "")
    Cons(k, rest) -> (trim(k), trim(join(rest, "=")))

fun parse_cookies(header: string) : list<(string, string)>
  if header == "" then []
  else map(split(header, ";"), parse_cookie_pair)

// Cookie value by name from the Cookie request header.
pub fun cookie(req: request, key: string) : maybe<string>
  match req_header(req, "cookie")
    Nothing -> Nothing
    Just(h) -> lookup_kv(parse_cookies(h), key)

// ---------------------------------------------------------------------------
// Raw field accessors — Hica callers cannot read fields off an extern Koka
// struct directly (req.body generates an unknown accessor), so expose these.
// Named req_* to match req_header and to avoid colliding with
// http_server_impl's request_* accessors (router.hc imports both modules).
// ---------------------------------------------------------------------------

pub fun req_method(req: request) : string
  req.method

pub fun req_path(req: request) : string
  req.path

pub fun req_body(req: request) : string
  req.body

fun find_in_headers(lines: list<string>, lkey: string) : maybe<string>
  match lines
    [] -> Nothing
    Cons(line, rest) ->
      val parts = split(trim(line), ":")
      match parts
        Cons(n, vs) ->
          if to-lower(trim(n)) == lkey
            then Just(trim(join(vs, ":")))
            else find_in_headers(rest, lkey)
        _ -> find_in_headers(rest, lkey)

// Extract the Bearer token from the Authorization header, if present.
pub fun bearer_token(req: request) : maybe<string>
  match req_header(req, "authorization")
    Nothing -> Nothing
    Just(v) ->
      if v.starts-with("Bearer ").bool
        then Just(str_slice(v, 7, v.count))
        else Nothing

// ---------------------------------------------------------------------------
// Dispatch: match a raw server_request against a list of routes
// ---------------------------------------------------------------------------

pub fun dispatch_routes(sreq: server_request, routes: list<route>) : io route_response
  val qparams = parse_query_params(sreq.query)
  dispatch_loop(sreq, qparams, routes)

fun dispatch_loop(sreq: server_request, qparams: list<(string, string)>, routes: list<route>) : io route_response
  match routes
    [] ->
      Route_response(404, "Content-Type: text/plain", "Not Found")
    Cons(r, rest) ->
      val method_ok = r.method == "*" || to-lower(r.method) == to-lower(sreq.method)
      if !method_ok then dispatch_loop(sreq, qparams, rest)
      else
        match match_path(r.pattern, sreq.path)
          Nothing ->
            dispatch_loop(sreq, qparams, rest)
          Just(params) ->
            val req = Request(sreq.method, sreq.path, params, qparams, sreq.headers, sreq.body)
            (r.handler_fn)(req)

// Dispatch an already-built request against the routes.  Used by the
// middleware pipeline so the raw server_request (which holds a C pointer) is
// never captured in closures — only pure request data flows through the chain.
pub fun dispatch_request(base: request, routes: list<route>) : io route_response
  dispatch_req_loop(base, routes)

fun dispatch_req_loop(base: request, routes: list<route>) : io route_response
  match routes
    [] ->
      Route_response(404, "Content-Type: text/plain", "Not Found")
    Cons(r, rest) ->
      val method_ok = r.method == "*" || to-lower(r.method) == to-lower(base.method)
      if !method_ok then dispatch_req_loop(base, rest)
      else
        match match_path(r.pattern, base.path)
          Nothing ->
            dispatch_req_loop(base, rest)
          Just(params) ->
            val req = Request(base.method, base.path, params, base.query_params, base.headers, base.body)
            (r.handler_fn)(req)

// ---------------------------------------------------------------------------
// Exception guard
//
// A handler may raise an exception (bad list index, unwrap of an Err, division
// by zero, an explicit throw, ...).  Left unhandled, the exception aborts the
// request inside libmicrohttpd's callback and poisons the event loop so every
// later request fails too.  These wrappers catch any exception and return a
// 500 response instead, keeping the server healthy.
// ---------------------------------------------------------------------------

fun internal_error() : route_response
  Route_response(500, "Content-Type: text/plain", "Internal Server Error")

// Dispatch a raw server_request, converting any handler exception into a 500.
pub fun dispatch_routes_safe(sreq: server_request, routes: list<route>) : io route_response
  match try({ dispatch_routes(sreq, routes) })
    Ok(r)      -> r
    Error(_ex) -> internal_error()

// Run a composed middleware pipeline, converting any exception into a 500.
// The pipeline is the last parameter so hica's extern-signature parser reads
// the function type cleanly (mirroring make_route).
pub fun run_pipeline_safe(base: request, pipeline: (request) -> io route_response) : io route_response
  match try({ pipeline(base) })
    Ok(r)      -> r
    Error(_ex) -> internal_error()

// ---------------------------------------------------------------------------
// Integer parsing (hand-rolled to avoid stdlib version uncertainty)
// ---------------------------------------------------------------------------

fun parse_int_str(s: string) : int
  match parse_int_str_maybe(s)
    Nothing -> 0
    Just(n) -> n

fun parse_int_str_maybe(s: string) : maybe<int>
  if s == "" then Nothing
  else if str_slice(s, 0, 1) == "-"
    then match parse_digits(s.list.drop(1), 0)
           Nothing -> Nothing
           Just(n) -> Just(0 - n)
    else parse_digits(s.list, 0)

// Structural recursion over the char list keeps this total (no `div`).
fun parse_digits(chars: list<char>, acc: int) : maybe<int>
  match chars
    Nil -> Just(acc)
    Cons(c, rest) ->
      val d = c.int - '0'.int
      if d >= 0 && d <= 9 then parse_digits(rest, acc * 10 + d)
      else Nothing
