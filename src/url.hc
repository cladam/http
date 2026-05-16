// URL query parameter
pub struct Param { key: string, value: string }

// Encode a single parameter as "key=value"
pub fun encode_param(p: Param) : string {
  p.key + "=" + p.value
}

// Recursively build a query string from parameters
pub fun build_query_parts(params: list<Param>) : string => match params {
  []          => "",
  [p]         => encode_param(p),
  [p, ..rest] => encode_param(p) + "&" + build_query_parts(rest)
}

// Build a query string from a list of parameters
// Returns "" for an empty list, "key=val" for one, "k1=v1&k2=v2" for many
pub fun build_query(params: list<Param>) : string {
  build_query_parts(params)
}

// Append query parameters to a base URL
// build_url("https://api.example.com/users", [Param("page", "1"), Param("limit", "10")])
// => "https://api.example.com/users?page=1&limit=10"
pub fun build_url(base: string, params: list<Param>) : string {
  let qs = build_query(params)
  if qs == "" {
    base
  } else {
    base + "?" + qs
  }
}
