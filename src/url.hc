// URL query parameter
pub type param {
  Param(key: string, val: string)
}

// Encode a single parameter as "key=value"
pub fun encode-param(p: param) : string {
  p.key + "=" + p.val
}

// Recursively build a query string from parameters
pub fun build-query-parts(params: list<param>) : string {
  match params {
    Nil -> ""
    Cons(p, Nil) -> encode-param(p)
    Cons(p, rest) -> encode-param(p) + "&" + build-query-parts(rest)
  }
}

// Build a query string from a list of parameters
// Returns "" for an empty list, "key=val" for one, "k1=v1&k2=v2" for many
pub fun build-query(params: list<param>) : string {
  build-query-parts(params)
}

// Append query parameters to a base URL
// build-url("https://api.example.com/users", [Param("page", "1"), Param("limit", "10")])
// => "https://api.example.com/users?page=1&limit=10"
pub fun build-url(base: string, params: list<param>) : string {
  let qs = build-query(params)
  if qs == "" {
    base
  } else {
    base + "?" + qs
  }
}
