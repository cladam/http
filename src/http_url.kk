/*
 * http_url.kk — URL and query string utilities
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module http_url

// A URL query parameter.
pub struct param
  key   : string
  value : string

// Encode a single parameter as "key=value".
fun encode-param( p : param ) : string
  p.key ++ "=" ++ p.value

// Build a query string from a list of parameters.
// Returns "" for empty, "k=v" for one, "k1=v1&k2=v2" for many.
pub fun build-query( params : list<param> ) : string
  match params
    Nil -> ""
    Cons(p, Nil) -> encode-param(p)
    Cons(p, rest) -> encode-param(p) ++ "&" ++ build-query(rest)

// Append query parameters to a base URL.
//
// ```koka
// val url = build-url("https://api.example.com/users", [Param("page","1"), Param("limit","10")])
// // => "https://api.example.com/users?page=1&limit=10"
// ```
pub fun build-url( base : string, params : list<param> ) : string
  val qs = build-query(params)
  if qs == "" then base
  else base ++ "?" ++ qs
