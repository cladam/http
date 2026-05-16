/*
 * http_headers.kk — HTTP header parsing utilities
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */
module http_headers

// A parsed HTTP header with name and value.
pub struct header
  hname  : string
  hvalue : string

// Rejoin a list of strings with a separator.
fun rejoin( parts : list<string>, sep : string ) : string
  match parts
    Nil -> ""
    Cons(h, Nil) -> h
    Cons(h, rest) -> h ++ sep ++ rejoin(rest, sep)

// Parse a single header line "Name: value" into a Header.
// Handles values that contain ":" by splitting on the first colon only.
fun parse-header-line( line : string ) : header
  val parts = line.trim.split(":")
  match parts
    Cons(name, rest) -> Header(name.trim, rejoin(rest, ":").trim)
    _ -> Header("", "")

// Parse a raw HTTP header string into a list of headers.
pub fun parse-headers( s : string ) : list<header>
  s.split("\n").filter(fn(l){ l.trim != "" && l.trim.contains(":") }).map(parse-header-line)

// Look up a header value by name (case-insensitive).
// Returns "" if not found.
pub fun get-header( hdrs : list<header>, name : string ) : string
  match hdrs
    Nil -> ""
    Cons(h, rest) ->
      if h.hname.to-lower == name.to-lower then h.hvalue
      else get-header(rest, name)

// Check if a header exists by name (case-insensitive).
pub fun has-header( hdrs : list<header>, name : string ) : bool
  get-header(hdrs, name) != ""

// Get a header value directly from a raw header string.
pub fun find-header( s : string, name : string ) : string
  get-header(s.parse-headers, name)

// Show a header as "Name: Value".
pub fun show( h : header ) : string
  h.hname ++ ": " ++ h.hvalue
