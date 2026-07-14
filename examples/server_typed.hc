// examples/server_typed.hc — typed request & response bodies (Layers 3 & 4)
//
// Decodes JSON request bodies into a struct with validation (422 on bad input),
// and encodes struct responses back to JSON with terse constructors.
//
// Run (from the http library root):
//   hica run examples/server_typed.hc
// Then:
//   curl localhost:8080/items                                                -> JSON array
//   curl -X POST localhost:8080/items -d '{"quantity":7,"name":"Widget","price":9.99}'
//   curl -X POST localhost:8080/items -d '{"quantity":7,"name":"Widget"}'  -> 422 (missing price)
//   curl -X POST localhost:8080/items -d '{"quantity":1,"name":42,"price":1}'  -> 422 (name not a string)
//   curl -X POST localhost:8080/items -d 'not json'                  -> 422 (invalid JSON)

import "../src/body"

struct Item { quantity: int, name: string, price: float, in_stock: bool }

// Decode a JSON object into an Item. `in_stock` is optional (defaults to true).
fun decode_item(doc: Json) : result<Item, string> {
  match field_int(doc, "quantity") {
    Err(e) => Err(e),
    Ok(quantity) => match field_str(doc, "name") {
      Err(e) => Err(e),
      Ok(name) => match field_num(doc, "price") {
        Err(e) => Err(e),
        Ok(price) => match opt_bool(doc, "in_stock") {
          Err(e) => Err(e),
          Ok(stock) => Ok(Item { quantity: quantity, name: name, price: price, in_stock: unwrap_maybe_or(stock, true) })
        }
      }
    }
  }
}

// Encode an Item to a JSON value using the terse constructors (Layer 4).
// jint renders a clean integer (quantity: 7, not 7.0); jnum renders a float.
fun encode_item(it: Item) : Json =>
  jobj([
    ("quantity", jint(it.quantity)),
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
    Item { quantity: 3, name: "Widget", price: 9.99, in_stock: true },
    Item { quantity: 7, name: "Gadget", price: 5.0,  in_stock: false }
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
