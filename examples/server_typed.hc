// examples/server_typed.hc — typed request bodies (Layer 3)
//
// Decodes JSON request bodies into a struct with validation, returning
// 422 Unprocessable Entity (FastAPI-style) on malformed or invalid input.
//
// Run (from the http library root):
//   hica run examples/server_typed.hc
// Then:
//   curl -X POST localhost:8080/items -d '{"name":"Widget","price":9.99}'
//   curl -X POST localhost:8080/items -d '{"name":"Widget"}'        -> 422 (missing price)
//   curl -X POST localhost:8080/items -d '{"name":42,"price":1}'    -> 422 (name not a string)
//   curl -X POST localhost:8080/items -d 'not json'                 -> 422 (invalid JSON)

import "../src/body"

struct Item { name: string, price: float, in_stock: bool }

// Decode a JSON object into an Item. `in_stock` is optional (defaults to true).
fun decode_item(doc: Json) : result<Item, string> {
  match field_str(doc, "name") {
    Err(e) => Err(e),
    Ok(name) => match field_num(doc, "price") {
      Err(e) => Err(e),
      Ok(price) => match opt_bool(doc, "in_stock") {
        Err(e) => Err(e),
        Ok(stock) => Ok(Item { name: name, price: price, in_stock: unwrap_maybe_or(stock, true) })
      }
    }
  }
}

// Encode an Item to a JSON value using the terse constructors (Layer 4).
fun encode_item(it: Item) : Json =>
  jobj([
    ("name",     jstr(it.name)),
    ("price",    jnum(it.price)),
    ("in_stock", jbool(it.in_stock))
  ])

fun handle_create(req) : ServerResponse {
  match decode_body(req, decode_item) {
    Ok(item) => created_json(encode_item(item)),   // 201 Created
    Err(msg) => unprocessable(msg)                  // 422 with {"detail": ...}
  }
}

// Return a collection: encode each item and wrap in a JSON array.
fun handle_list(req) : ServerResponse {
  let items = [
    Item { name: "Widget", price: 9.99, in_stock: true },
    Item { name: "Gadget", price: 5.0,  in_stock: false }
  ]
  ok_json(jarr(map(items, encode_item)))
}

fun main() {
  println("Server starting on http://localhost:8080")
  serve_routes(8080, [
    get("/items",  handle_list),
    post("/items", handle_create)
  ])
}
