// server_multipart.hc — multipart/form-data upload example
//
// Shows the publish-endpoint pattern from the hica registry RFC:
// a PUT that accepts either:
//   (a) multipart/form-data with a "metadata" JSON part and a "tarball" binary part, or
//   (b) application/json with a base64-encoded tarball_b64 field (interim fallback).
//
// Run:
//   hica build examples/server_multipart.hc -o /tmp/server_multipart && /tmp/server_multipart
//
// Test with curl:
//   curl -X PUT http://localhost:8081/api/v1/packages/json/0.1.0 \
//        -F metadata='{"name":"json","version":"0.1.0","checksum":"sha256:abc"}' \
//        -F tarball=@/path/to/json-0.1.0.tar.gz
//
import "../src/web"
import "../src/multipart"

fun handle_publish(req) {
  match req_part(req, "metadata") {
    None => status_response(400, "missing 'metadata' part"),
    Some(meta) => {
      match req_part(req, "tarball") {
        None => status_response(400, "missing 'tarball' part"),
        Some(tar) => {
          let name = path_str(req, "name")
          let ver  = path_str(req, "version")
          let meta_len = show(length(meta.bytes))
          let tar_len  = show(length(tar.bytes))
          let fname    = tar.filename
          json_response(
            "\{\"ok\": true, \"package\": \"" + name + "\", " +
            "\"version\": \"" + ver + "\", " +
            "\"metadata_bytes\": " + meta_len + ", " +
            "\"tarball_bytes\": " + tar_len + ", " +
            "\"filename\": \"" + fname + "\"\}"
          )
        }
      }
    }
  }
}

fun handle_list_parts(req) {
  let parts = req_parts(req)
  let files = req_files(req)
  let count     = show(length(parts))
  let filecount = show(length(files))
  json_response(
    "\{\"parts\": " + count + ", \"files\": " + filecount + "\}"
  )
}

fun main() {
  println("Listening on :8081")
  serve_routes(8081, [
    put("/api/v1/packages/\{name\}/\{version\}", (req) => handle_publish(req)),
    post("/debug/parts",                         (req) => handle_list_parts(req))
  ])
}
