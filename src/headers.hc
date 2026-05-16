import http

// A parsed HTTP header with name and value
pub type header {
  Header(name: string, value: string)
}

// Rejoin a list of strings with a separator
pub fun rejoin(parts: list<string>, sep: string) : string {
  match parts {
    Nil -> ""
    Cons(h, Nil) -> h
    Cons(h, rest) -> h + sep + rejoin(rest, sep)
  }
}

// Parse a single header line "Name: value" into a Header
// Handles values that contain ":" by splitting on first colon only
pub fun parse-header-line(line: string) : header {
  let parts = split(trim(line), ":")
  match parts {
    Cons(name, rest) -> Header(trim(name), trim(rejoin(rest, ":")))
    _ -> Header("", "")
  }
}

// Recursively parse a list of header lines
pub fun parse-header-lines(lines: list<string>) : list<header> {
  match lines {
    Nil -> []
    Cons(line, rest) -> {
      let trimmed = trim(line)
      if trimmed == "" {
        parse-header-lines(rest)
      } else if contains(trimmed, ":") {
        Cons(parse-header-line(trimmed), parse-header-lines(rest))
      } else {
        parse-header-lines(rest)
      }
    }
  }
}

// Parse a raw HTTP header string into a list of Headers
pub fun parse-headers(raw: string) : list<header> {
  parse-header-lines(split(raw, "\n"))
}

// Look up a header value by name (case-insensitive)
// Returns "" if not found
pub fun get-header(hdrs: list<header>, name: string) : string {
  match hdrs {
    Nil -> ""
    Cons(h, rest) -> {
      if to-lower(h.name) == to-lower(name) {
        h.value
      } else {
        get-header(rest, name)
      }
    }
  }
}

// Check if a header exists by name (case-insensitive)
pub fun has-header(hdrs: list<header>, name: string) : bool {
  get-header(hdrs, name) != ""
}

// Get a header value directly from an http-response
pub fun response-header(resp: http-response, name: string) : string {
  get-header(parse-headers(resp.headers), name)
}

// Get the Content-Type from an http-response
pub fun response-content-type(resp: http-response) : string {
  response-header(resp, "Content-Type")
}

// Show a header as "Name: Value"
pub fun show-header(h: header) : string {
  h.name + ": " + h.value
}
