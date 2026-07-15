// Tests for multipart/form-data helpers. Pure — no server needed.
// The MHD post-processor callbacks are integration-tested via curl in the
// examples; here we test the pure Hica logic.
import "../src/multipart"

// ============================================================
// Part construction helpers
// ============================================================

fun make_text_part(name: string, content: string) : Part {
  Part { name: name, filename: "", content_type: "text/plain", bytes: content }
}

fun make_file_part(name: string, fname: string, ct: string, data: string) : Part {
  Part { name: name, filename: fname, content_type: ct, bytes: data }
}

// ============================================================
// find_part
// ============================================================

test "find_part returns Some when the part exists" {
  let parts = [
    make_text_part("metadata", "\{\"name\":\"json\"\}"),
    make_file_part("tarball", "json-0.1.0.tar.gz", "application/gzip", "FAKEGZ")
  ]
  match find_part(parts, "metadata") {
    Some(p) => assert(p.bytes == "\{\"name\":\"json\"\}"),
    None    => assert(false)
  }
}

test "find_part returns the file part by name" {
  let parts = [
    make_text_part("metadata", "\{\}"),
    make_file_part("tarball", "pkg.tar.gz", "application/gzip", "GZ")
  ]
  match find_part(parts, "tarball") {
    Some(p) => assert(p.filename == "pkg.tar.gz"),
    None    => assert(false)
  }
}

test "find_part returns None when the part is absent" {
  let parts = [make_text_part("metadata", "\{\}")]
  match find_part(parts, "tarball") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

test "find_part returns None on an empty list" {
  match find_part([], "anything") {
    Some(_) => assert(false),
    None    => assert(true)
  }
}

// ============================================================
// filter_files
// ============================================================

test "filter_files returns only parts with a filename" {
  let parts = [
    make_text_part("description", "A library"),
    make_file_part("tarball", "lib.tar.gz", "application/gzip", "GZ"),
    make_text_part("license", "MIT"),
    make_file_part("readme", "README.md", "text/plain", "# Hello")
  ]
  let files = filter_files(parts, [])
  assert(length(files) == 2)
}

test "filter_files returns empty when no file parts exist" {
  let parts = [
    make_text_part("name", "json"),
    make_text_part("version", "0.1.0")
  ]
  let files = filter_files(parts, [])
  assert(length(files) == 0)
}

test "filter_files preserves order" {
  let parts = [
    make_file_part("first", "a.tar.gz", "application/gzip", "A"),
    make_text_part("meta", "\{\}"),
    make_file_part("second", "b.tar.gz", "application/gzip", "B")
  ]
  let files = filter_files(parts, [])
  match files {
    [f1, f2] => {
      assert(f1.filename == "a.tar.gz")
      assert(f2.filename == "b.tar.gz")
    },
    _ => assert(false)
  }
}

// ============================================================
// Part struct field access
// ============================================================

test "Part fields are accessible" {
  let p = make_file_part("tarball", "pkg-1.0.0.tar.gz", "application/gzip", "data")
  assert(p.name == "tarball")
  assert(p.filename == "pkg-1.0.0.tar.gz")
  assert(p.content_type == "application/gzip")
  assert(p.bytes == "data")
}

test "text part has empty filename" {
  let p = make_text_part("metadata", "\{\}")
  assert(p.filename == "")
}
