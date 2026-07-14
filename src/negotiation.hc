// negotiation.hc — server-driven content negotiation (the Accept header)
//
// Offer several representations of the same resource and let the client's
// Accept header choose. Ranges (`type/*`, `*/*`) and quality values (`;q=0.8`)
// are honoured, and a more specific range wins over a less specific one — so a
// browser (Accept: text/html, ..., */*;q=0.8) is served HTML while an API
// client (Accept: application/json, or curl's */*) is served JSON.
//
//   import "../src/negotiation"
//
//   fun handle_item(req) : ServerResponse {
//     negotiate(req, [
//       ("application/json",       "\{\"name\": \"Widget\"\}"),
//       ("text/html; charset=utf-8", "<h1>Widget</h1>")
//     ])
//   }
//
// When the client accepts none of the offered types, negotiate returns
// 406 Not Acceptable. A matched response carries a `Vary: Accept` header so
// caches key on the Accept header.

extern import "router_impl"
pub import "./http_server"

// --- Offer accessors (pattern-match rather than .0/.1 tuple access, which is
//     ambiguous in generated Koka) ---

// The media type of an (content_type, body) offer.
pub fun offer_mime(o: (string, string)) : string {
  match o { (m, _) => m }
}

// Find the body paired with `mime` in a list of (content_type, body) offers.
pub fun find_body(offers: list<(string, string)>, mime: string) : maybe<string> {
  match offers {
    [] => None,
    [o, ..rest] => match o {
      (m, b) => if m == mime { Some(b) } else { find_body(rest, mime) }
    }
  }
}

// --- Negotiation ---

// Choose the best representation for the client from `offers`, a list of
// (content_type, body) pairs. The server's order breaks ties. Returns a 200
// response (with `Vary: Accept`) carrying the chosen content type and body, or
// 406 Not Acceptable when the client accepts none of them.
pub fun negotiate(req, offers: list<(string, string)>) {
  match best_offer(req, map(offers, offer_mime)) {
    None       => not_acceptable(),
    Some(mime) => match find_body(offers, mime) {
      None       => not_acceptable(),
      Some(body) => with_header(content_response(200, mime, body), "Vary", "Accept")
    }
  }
}

// --- Convenience predicates ---

// True when the client accepts JSON.
pub fun accepts_json(req) : bool {
  accepts(req, "application/json")
}

// True when the client accepts HTML.
pub fun accepts_html(req) : bool {
  accepts(req, "text/html")
}
