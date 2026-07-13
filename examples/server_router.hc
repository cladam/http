// examples/server_router.hc — FastAPI-style HTTP server with routing + JSON
//
// Demonstrates:
//   - Typed route declarations (get, post, delete)
//   - Path parameters:   GET /items/{id}
//   - Query parameters:  GET /items?page=1&limit=10
//   - JSON request body: POST /items
//   - Bearer token auth: GET /protected
//   - Automatic 404 for unmatched routes
//
// Run with hica (from the http library root):
//   hica run examples/server_router.hc
// Then test with curl:
//   curl http://localhost:8080/
//   curl http://localhost:8080/items?page=2
//   curl http://localhost:8080/items/42
//   curl -X POST http://localhost:8080/items -H "Content-Type: application/json" \
//        -d '{"name":"Widget","price":9.99}'
//   curl http://localhost:8080/protected -H "Authorization: Bearer secret123"

import "json"
import "../src/router"

// ---------------------------------------------------------------------------
// In-memory "database" — a simple list baked into the example
// ---------------------------------------------------------------------------

fun find_item(id: int) : maybe<string> {
  if id == 1 { Some("Widget") }
  else if id == 2 { Some("Gadget") }
  else if id == 3 { Some("Doohickey") }
  else { None }
}

// ---------------------------------------------------------------------------
// JSON helpers
// ---------------------------------------------------------------------------

// Build a simple item JSON object as a string (avoids int->float conversion).
fun item_json(id: int, name: string) : string {
  "\{\"id\": " + show(id) + ", \"name\": \"" + name + "\"\}"
}

// Build a paginated list response.
fun items_list_json(page: int, limit: int) : string {
  let items = "[" +
    "\{\"id\": 1, \"name\": \"Widget\"\}," +
    "\{\"id\": 2, \"name\": \"Gadget\"\}," +
    "\{\"id\": 3, \"name\": \"Doohickey\"\}" +
  "]"
  "\{\"page\": " + show(page) + ", \"limit\": " + show(limit) + ", \"items\": " + items + "\}"
}

// ---------------------------------------------------------------------------
// Route handlers
// ---------------------------------------------------------------------------

fun handle_root(req) : ServerResponse {
  json_response("\{\"hello\": \"world\", \"version\": \"1.0\"\}")
}

fun handle_list_items(req) : ServerResponse {
  let page  = unwrap_maybe_or(query_int(req, "page"), 1)
  let limit = unwrap_maybe_or(query_int(req, "limit"), 10)
  json_response(items_list_json(page, limit))
}

fun handle_get_item(req) : ServerResponse {
  let id = path_int(req, "id")
  match find_item(id) {
    None    => not_found_response(),
    Some(name) => json_response(item_json(id, name))
  }
}

fun handle_create_item(req) : ServerResponse {
  match parse_json(req_body(req)) {
    Err(e) => status_response(422, "Invalid JSON: " + e),
    Ok(doc) => {
      // Note: extract the name with an explicit match rather than
      // unwrap_maybe_or — this module already uses unwrap_maybe_or with
      // maybe<int> (query_int), and mixing it with maybe<string> here trips
      // a monomorphisation limitation in the current hica compiler.
      match Some(doc) |> at("name") |> as_str {
        None => status_response(422, "Missing required field: name"),
        Some(name) =>
          if name == "" {
            status_response(422, "Missing required field: name")
          } else {
            json_response("\{\"created\": true, \"name\": \"" + name + "\"\}")
          }
      }
    }
  }
}

fun handle_delete_item(req) : ServerResponse {
  let id = path_int(req, "id")
  match find_item(id) {
    None    => not_found_response(),
    Some(_) => status_response(204, "")
  }
}

fun handle_protected(req) : ServerResponse {
  match bearer_token(req) {
    None       => status_response(401, "Unauthorized"),
    Some(token) => {
      if token == "secret123" {
        json_response(json_emit(JObject([("data", JString("top secret!"))])))
      } else {
        status_response(403, "Forbidden")
      }
    }
  }
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

fun main() {
  println("Server starting on http://localhost:8080")
  serve_routes(8080, [
    get("/",                handle_root),
    get("/items",           handle_list_items),
    get("/items/\{id\}",      handle_get_item),
    post("/items",          handle_create_item),
    delete("/items/\{id\}",   handle_delete_item),
    get("/protected",       handle_protected)
  ])
}
