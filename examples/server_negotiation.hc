// examples/server_negotiation.hc — content negotiation (the Accept header)
//
// One resource, two representations. The client's Accept header decides which
// one it gets: a browser is served HTML, an API client (or curl's default
// */*) is served JSON. A request that accepts neither gets 406.
//
// Run (from the http library root):
//   hica run examples/server_negotiation.hc
// Then:
//   curl localhost:8080/item                                  -> JSON  (*/*)
//   curl localhost:8080/item -H 'Accept: text/html'           -> HTML
//   curl localhost:8080/item -H 'Accept: application/json'    -> JSON
//   curl -i localhost:8080/item -H 'Accept: application/xml'  -> 406
//   # browser-style header prefers HTML even though JSON is offered first:
//   curl localhost:8080/item -H 'Accept: text/html,*/*;q=0.8' -> HTML

import "../src/negotiation"
import "../src/router"

fun handle_item(req) : ServerResponse {
  negotiate(req, [
    ("application/json",         "\{\"name\": \"Widget\", \"price\": 9.99\}"),
    ("text/html; charset=utf-8", "<h1>Widget</h1><p>Price: 9.99</p>")
  ])
}

fun main() {
  println("Server on http://localhost:8080 (GET /item)")
  serve_routes(8080, [
    get("/item", handle_item)
  ])
}
