/*
 * http-inline.c — libcurl bindings for Koka
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 */

#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

/* ------------------------------------------------------------------ */
/* Response buffer: dynamically growing byte buffer for curl callback  */
/* ------------------------------------------------------------------ */

typedef struct {
  char*  data;
  size_t size;
} hc_buf_t;

static size_t hc_write_cb(void* contents, size_t size, size_t nmemb, void* userp) {
  size_t realsize = size * nmemb;
  hc_buf_t* buf = (hc_buf_t*)userp;
  char* ptr = (char*)realloc(buf->data, buf->size + realsize + 1);
  if (!ptr) return 0;  /* out of memory */
  buf->data = ptr;
  memcpy(&(buf->data[buf->size]), contents, realsize);
  buf->size += realsize;
  buf->data[buf->size] = '\0';
  return realsize;
}

/* ------------------------------------------------------------------ */
/* Header buffer: collect response headers into a separate buffer      */
/* ------------------------------------------------------------------ */

static size_t hc_header_cb(void* contents, size_t size, size_t nmemb, void* userp) {
  size_t realsize = size * nmemb;
  hc_buf_t* buf = (hc_buf_t*)userp;
  char* ptr = (char*)realloc(buf->data, buf->size + realsize + 1);
  if (!ptr) return 0;
  buf->data = ptr;
  memcpy(&(buf->data[buf->size]), contents, realsize);
  buf->size += realsize;
  buf->data[buf->size] = '\0';
  return realsize;
}

/* ------------------------------------------------------------------ */
/* hc_buf_init / hc_buf_free                                           */
/* ------------------------------------------------------------------ */

static void hc_buf_init(hc_buf_t* buf) {
  buf->data = (char*)malloc(1);
  buf->data[0] = '\0';
  buf->size = 0;
}

static void hc_buf_free(hc_buf_t* buf) {
  if (buf->data) free(buf->data);
  buf->data = NULL;
  buf->size = 0;
}

/* ------------------------------------------------------------------ */
/* Global init/cleanup (called once per process)                       */
/* ------------------------------------------------------------------ */

static int hc_curl_initialized = 0;

static void hc_ensure_init(void) {
  if (!hc_curl_initialized) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    hc_curl_initialized = 1;
  }
}

/* ------------------------------------------------------------------ */
/* kk_http_request: general-purpose HTTP request                       */
/*                                                                     */
/* Returns a tuple: (status:int, body:string, headers:string)          */
/* Throws on curl errors (network failure, DNS, etc.)                  */
/* ------------------------------------------------------------------ */

static kk_std_core_types__tuple3 kk_http_request(
  kk_string_t  method,
  kk_string_t  url,
  kk_string_t  body,
  kk_string_t  content_type,
  kk_string_t  extra_headers,
  kk_integer_t timeout_int,
  kk_context_t* ctx
) {
  int64_t timeout_secs = kk_integer_clamp64(timeout_int, ctx);
  kk_integer_drop(timeout_int, ctx);
  hc_ensure_init();

  CURL* curl = curl_easy_init();
  if (!curl) {
    kk_string_drop(method, ctx);
    kk_string_drop(url, ctx);
    kk_string_drop(body, ctx);
    kk_string_drop(content_type, ctx);
    kk_string_drop(extra_headers, ctx);
    kk_info_message("http: failed to initialize curl\n", ctx);
    return kk_std_core_types__new_Tuple3(
      kk_integer_box(kk_integer_from_int(0, ctx), ctx),
      kk_string_box(kk_string_empty()),
      kk_string_box(kk_string_empty()),
      ctx
    );
  }

  hc_buf_t resp_body;
  hc_buf_t resp_headers;
  hc_buf_init(&resp_body);
  hc_buf_init(&resp_headers);

  /* Borrow C strings from Koka */
  kk_ssize_t url_len;
  const char* c_url = kk_string_cbuf_borrow(url, &url_len, ctx);
  kk_ssize_t method_len;
  const char* c_method = kk_string_cbuf_borrow(method, &method_len, ctx);
  kk_ssize_t body_len;
  const char* c_body = kk_string_cbuf_borrow(body, &body_len, ctx);
  kk_ssize_t ct_len;
  const char* c_ct = kk_string_cbuf_borrow(content_type, &ct_len, ctx);
  kk_ssize_t eh_len;
  const char* c_eh = kk_string_cbuf_borrow(extra_headers, &eh_len, ctx);

  /* Set URL and common options */
  curl_easy_setopt(curl, CURLOPT_URL, c_url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, hc_write_cb);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&resp_body);
  curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, hc_header_cb);
  curl_easy_setopt(curl, CURLOPT_HEADERDATA, (void*)&resp_headers);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
  curl_easy_setopt(curl, CURLOPT_USERAGENT, "hica-http/1.0");

  if (timeout_secs > 0) {
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, (long)timeout_secs);
  }

  /* Custom request method */
  struct curl_slist* header_list = NULL;

  if (strcmp(c_method, "POST") == 0) {
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, c_body);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)body_len);
  } else if (strcmp(c_method, "PUT") == 0) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, c_body);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)body_len);
  } else if (strcmp(c_method, "DELETE") == 0) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
  } else if (strcmp(c_method, "PATCH") == 0) {
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PATCH");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, c_body);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)body_len);
  } else if (strcmp(c_method, "HEAD") == 0) {
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
  }
  /* else: GET is the default */

  /* Content-Type header */
  if (ct_len > 0) {
    char ct_header[256];
    snprintf(ct_header, sizeof(ct_header), "Content-Type: %s", c_ct);
    header_list = curl_slist_append(header_list, ct_header);
  }

  /* Extra headers (newline-separated) */
  if (eh_len > 0) {
    /* Parse newline-separated headers */
    char* eh_copy = strdup(c_eh);
    char* line = strtok(eh_copy, "\n");
    while (line != NULL) {
      if (strlen(line) > 0 && line[0] != '\r') {
        header_list = curl_slist_append(header_list, line);
      }
      line = strtok(NULL, "\n");
    }
    free(eh_copy);
  }

  if (header_list != NULL) {
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);
  }

  /* Perform the request */
  CURLcode res = curl_easy_perform(curl);

  long http_status = 0;
  if (res == CURLE_OK) {
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_status);
  }

  /* Build Koka result */
  kk_string_t kk_body = kk_string_alloc_from_utf8n((kk_ssize_t)resp_body.size, resp_body.data, ctx);
  kk_string_t kk_headers = kk_string_alloc_from_utf8n((kk_ssize_t)resp_headers.size, resp_headers.data, ctx);

  /* Cleanup */
  hc_buf_free(&resp_body);
  hc_buf_free(&resp_headers);
  if (header_list) curl_slist_free_all(header_list);
  curl_easy_cleanup(curl);

  kk_string_drop(method, ctx);
  kk_string_drop(url, ctx);
  kk_string_drop(body, ctx);
  kk_string_drop(content_type, ctx);
  kk_string_drop(extra_headers, ctx);

  if (res != CURLE_OK) {
    kk_string_drop(kk_body, ctx);
    kk_string_drop(kk_headers, ctx);
    kk_info_message(curl_easy_strerror(res), ctx);
    return kk_std_core_types__new_Tuple3(
      kk_integer_box(kk_integer_from_int(0, ctx), ctx),
      kk_string_box(kk_string_empty()),
      kk_string_box(kk_string_empty()),
      ctx
    );
  }

  return kk_std_core_types__new_Tuple3(
    kk_integer_box(kk_integer_from_int((int64_t)http_status, ctx), ctx),
    kk_string_box(kk_body),
    kk_string_box(kk_headers),
    ctx
  );
}
