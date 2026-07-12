extern import "http"
import "../src/http_server"

fun main() {
  println("Listening on http://localhost:8080")
  serve(8080, (req) => {
    println(req.method + " " + req.path)
    if req.path == "/health" {
      text_response("ok")
    } else if req.path == "/echo" {
      json_response("\{\"method\": \"" + req.method + "\", \"path\": \"" + req.path + "\", \"body\": \"" + req.body + "\"\}")
    } else {
      not_found_response()
    }
  })
}
