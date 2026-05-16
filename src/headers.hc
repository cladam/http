// headers — HTTP header parsing utilities

// A parsed HTTP header with name and value
pub struct Header { name: string, value: string }

// Rejoin a list of strings with a separator
pub fun rejoin(parts: list<string>, sep: string) : string => match parts {
  []          => "",
  [h]         => h,
  [h, ..rest] => h + sep + rejoin(rest, sep)
}

// Parse a single header line "Name: value" into a Header
// Handles values that contain ":" by splitting on first colon only
pub fun parse_header_line(line: string) : Header {
  let parts = split(trim(line), ":")
  match parts {
    [name, ..rest] => Header { name: trim(name), value: trim(rejoin(rest, ":")) },
    _ => Header { name: "", value: "" }
  }
}

// Recursively parse a list of header lines
pub fun parse_header_lines(lines: list<string>) : list<Header> => match lines {
  [] => [],
  [line, ..rest] => {
    let trimmed = trim(line)
    if trimmed == "" {
      parse_header_lines(rest)
    } else if contains(trimmed, ":") {
      [parse_header_line(trimmed)] + parse_header_lines(rest)
    } else {
      parse_header_lines(rest)
    }
  }
}

// Parse a raw HTTP header string into a list of Headers
pub fun parse_headers(raw: string) : list<Header> {
  parse_header_lines(split(raw, "\n"))
}

// Look up a header value by name (case-insensitive)
// Returns "" if not found
pub fun get_header(hdrs: list<Header>, name: string) : string => match hdrs {
  [] => "",
  [h, ..rest] => if to_lower(h.name) == to_lower(name) { h.value } else { get_header(rest, name) }
}

// Check if a header exists by name (case-insensitive)
pub fun has_header(hdrs: list<Header>, name: string) : bool {
  get_header(hdrs, name) != ""
}

pub fun show_header(h: Header) : string {
  h.name + ": " + h.value
}
