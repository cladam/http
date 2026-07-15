// multipart.hc — multipart/form-data support for the hica HTTP server
//
// Parses `multipart/form-data` request bodies (e.g. for file uploads or
// the hica publish endpoint) and exposes each part as a `Part` value.
//
// The C layer (http_server_inline.c) uses libmicrohttpd's MHD_PostProcessor
// to parse incoming parts incrementally.  This module provides the
// high-level Hica API on top of the raw index-based accessors.
//
// Usage:
//
//   import "../src/multipart"
//
//   put("/publish/{name}/{version}", (req) => {
//     match req_part(req, "metadata") {
//       None       => bad_request("missing metadata part"),
//       Some(meta) => match req_part(req, "tarball") {
//         None      => bad_request("missing tarball part"),
//         Some(tar) => handle_publish(meta.bytes, tar.bytes)
//       }
//     }
//   })
//
// `Part.bytes` is a raw byte string (binary-safe).  Non-file form fields
// appear as parts with an empty filename; use `req_part` to retrieve them
// by name, or `req_files` to get only parts that carry a filename.
//
// Size limits: each individual part is capped at 64 MiB by the C layer;
// large uploads beyond that are rejected with a 400 from MHD itself.

extern import "http_server_impl"
extern import "router_impl"
pub import "./http_server"

// A single part from a multipart/form-data request.
pub struct Part {
  name: string,         // form-field name (always present)
  filename: string,     // original filename; "" for non-file fields
  content_type: string, // MIME type declared by the client; "" if absent
  bytes: string         // raw part bytes (binary-safe)
}

// Number of parsed multipart parts.  0 for non-multipart requests.
pub fun req_part_count(req) {
  http_part_count_by_id(request_req_id(req))
}

// True when the request has a multipart/form-data Content-Type and at
// least one part was parsed successfully.
pub fun is_multipart(req) {
  req_part_count(req) > 0
}

// Build a `Part` value from the raw part at position `idx`.
pub fun req_part_at(req, idx: int) {
  let rid = request_req_id(req)
  Part {
    name:         http_part_field_by_id(rid, idx, 0),
    filename:     http_part_field_by_id(rid, idx, 1),
    content_type: http_part_field_by_id(rid, idx, 2),
    bytes:        http_part_field_by_id(rid, idx, 3)
  }
}

// All parts from a multipart request as a list.
// Returns an empty list for non-multipart requests.
pub fun req_parts(req) {
  let count = req_part_count(req)
  req_parts_helper(req, 0, count, [])
}

pub fun req_parts_helper(req, idx: int, count: int, acc: list<Part>) {
  if idx >= count {
    reverse(acc)
  } else {
    req_parts_helper(req, idx + 1, count, [req_part_at(req, idx)] + acc)
  }
}

// Get a named part from a multipart request.
// Returns `None` if the part is absent or the request is not multipart.
pub fun req_part(req, part_name: string) {
  find_part(req_parts(req), part_name)
}

pub fun find_part(parts: list<Part>, part_name: string) : maybe<Part> {
  match parts {
    []          => None,
    [p, ..rest] => if p.name == part_name { Some(p) }
                   else { find_part(rest, part_name) }
  }
}

// All parts that carry a filename (i.e. file upload parts).
pub fun req_files(req) {
  filter_files(req_parts(req), [])
}

pub fun filter_files(parts: list<Part>, acc: list<Part>) : list<Part> {
  match parts {
    []          => reverse(acc),
    [p, ..rest] => if p.filename != "" { filter_files(rest, [p] + acc) }
                   else { filter_files(rest, acc) }
  }
}

// Convenience: get the string value of a named text/plain part.
// Useful for simple form fields embedded alongside a file upload.
pub fun part_str(req, part_name: string) {
  match req_part(req, part_name) {
    None    => None,
    Some(p) => Some(p.bytes)
  }
}
