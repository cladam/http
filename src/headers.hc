// headers — HTTP header parsing utilities

// A parsed HTTP header with name and value
pub struct Header { name: string, value: string }

// Parse a single header line "Name: value" into a Header
// Handles values that contain ":" by splitting on first colon only
pub fun parse_header_line(line: string) : Header {
  let parts = split(trim(line), ":")
  match parts {
    [n, ..rest] => Header { name: trim(n), value: trim(join(rest, ":")) },
    _ => Header { name: "", value: "" }
  }
}

// Parse a raw HTTP header string into a list of Headers
pub fun parse_headers(raw: string) : list<Header> {
  split(raw, "\n")
    |> map(trim)
    |> filter((l) => l != "" && contains(l, ":"))
    |> map(parse_header_line)
}

// Look up a header value by name (case-insensitive)
// Returns Some(value) if present, None if not found
pub fun get_header(hdrs: list<Header>, key: string) : maybe<string> => match hdrs {
  [] => None,
  [h, ..rest] => if to_lower(h.name) == to_lower(key) { Some(h.value) } else { get_header(rest, key) }
}

// Check if a header exists by name (case-insensitive)
pub fun has_header(hdrs: list<Header>, key: string) : bool {
  is_some(get_header(hdrs, key))
}

// Get a header value directly from a raw header string
pub fun find_header(raw: string, key: string) : maybe<string> {
  get_header(parse_headers(raw), key)
}

pub fun show_header(h: Header) : string {
  h.name + ": " + h.value
}
