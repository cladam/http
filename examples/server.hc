extern import "http"
import "../src/http_server"

fun main() {
  println("Listening on http://localhost:8080")
  serve(8080, (req) => {
    println(request_method(req) + " " + request_path(req))
    if request_path(req) == "/health" {
      text_response("ok")
    } else if request_path(req) == "/echo" {
      json_response("\{\"method\": \"" + request_method(req) + "\", \"path\": \"" + request_path(req) + "\", \"body\": \"" + request_body(req) + "\"\}")
    } else {
      not_found_response()
    }
  })
}
