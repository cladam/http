// URL query parameter
pub struct Param { key: string, value: string }

// Encode a single parameter as "key=value"
pub fun encode_param(p: Param) : string {
  p.key + "=" + p.value
}

// Build a query string from a list of parameters
// Returns "" for an empty list, "key=val" for one, "k1=v1&k2=v2" for many
pub fun build_query(params: list<Param>) : string {
  params |> map(encode_param) |> join("&")
}

// Append query parameters to a base URL
// build_url("https://api.example.com/users", [Param { key: "page", value: "1" }, Param { key: "limit", value: "10" }])
// => "https://api.example.com/users?page=1&limit=10"
pub fun build_url(base: string, params: list<Param>) : string {
  let qs = build_query(params)
  if qs == "" {
    base
  } else {
    base + "?" + qs
  }
}
