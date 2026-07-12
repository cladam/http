/*
 * http_server_inline.c — libmicrohttpd bindings for Koka
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 *
 * Threading model:
 *   MHD runs an internal polling thread that handles all socket I/O and
 *   calls access_handler for each complete request.  access_handler suspends
 *   the connection and pushes the request onto a mutex-protected queue, then
 *   signals a condition variable.
 *
 *   Koka (single-threaded) calls kk_http_server_accept which waits on the
 *   condvar, dequeues the request, and returns field-by-field.  Koka calls
 *   kk_http_server_respond to queue a response and resume the connection;
 *   MHD's thread then transmits it.
 *
 *   No Koka runtime functions are ever called from MHD's thread — only
 *   plain C structs cross the thread boundary.
 */

#include <microhttpd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* ------------------------------------------------------------------ */
/* Growing string buffer                                               */
/* ------------------------------------------------------------------ */

typedef struct {
  char*  buf;
  size_t len;
  size_t cap;
} hcsrv_buf_t;

static void hcsrv_buf_init(hcsrv_buf_t* sb) {
  sb->cap = 256;
  sb->len = 0;
  sb->buf = (char*)malloc(sb->cap);
  if (sb->buf) sb->buf[0] = '\0';
  else sb->cap = 0;
}

static void hcsrv_buf_append(hcsrv_buf_t* sb, const char* s) {
  if (!sb->buf || !s) return;
  size_t slen = strlen(s);
  if (sb->len + slen + 1 > sb->cap) {
    sb->cap = (sb->len + slen + 256) * 2;
    char* p = (char*)realloc(sb->buf, sb->cap);
    if (!p) return;
    sb->buf = p;
  }
  memcpy(sb->buf + sb->len, s, slen);
  sb->len += slen;
  sb->buf[sb->len] = '\0';
}

static void hcsrv_buf_free(hcsrv_buf_t* sb) {
  free(sb->buf);
  sb->buf = NULL;
  sb->len = sb->cap = 0;
}

/* ------------------------------------------------------------------ */
/* Per-connection upload accumulator (lives on MHD thread)             */
/* ------------------------------------------------------------------ */

typedef struct {
  char*  body;
  size_t body_size;
} hcsrv_upload_t;

/* ------------------------------------------------------------------ */
/* A completed, suspended request node (lives in the shared queue)     */
/* ------------------------------------------------------------------ */

typedef struct hcsrv_req hcsrv_req_t;
struct hcsrv_req {
  struct MHD_Connection* connection;
  char*  method;
  char*  path;
  char*  query;    /* decoded "key=val&key2=val2" */
  char*  headers;  /* raw "Name: Value\n..." */
  char*  body;
  size_t body_size;
  hcsrv_req_t* next;
};

/* ------------------------------------------------------------------ */
/* Server state                                                         */
/* ------------------------------------------------------------------ */

typedef struct {
  struct MHD_Daemon* daemon;
  pthread_mutex_t    mutex;
  pthread_cond_t     cond;
  hcsrv_req_t*       head;
  hcsrv_req_t*       tail;
  volatile int       stopped;
} hcsrv_t;

/* ------------------------------------------------------------------ */
/* MHD value-collection callbacks                                      */
/* ------------------------------------------------------------------ */

static enum MHD_Result hcsrv_collect_header(void* cls, enum MHD_ValueKind kind,
                                             const char* key, const char* value) {
  hcsrv_buf_t* sb = (hcsrv_buf_t*)cls;
  if (!key) return MHD_YES;
  hcsrv_buf_append(sb, key);
  hcsrv_buf_append(sb, ": ");
  hcsrv_buf_append(sb, value ? value : "");
  hcsrv_buf_append(sb, "\n");
  return MHD_YES;
}

static enum MHD_Result hcsrv_collect_query(void* cls, enum MHD_ValueKind kind,
                                            const char* key, const char* value) {
  hcsrv_buf_t* sb = (hcsrv_buf_t*)cls;
  if (!key) return MHD_YES;
  if (sb->len > 0) hcsrv_buf_append(sb, "&");
  hcsrv_buf_append(sb, key);
  if (value && value[0]) {
    hcsrv_buf_append(sb, "=");
    hcsrv_buf_append(sb, value);
  }
  return MHD_YES;
}

/* ------------------------------------------------------------------ */
/* Free a request node (does NOT touch node->connection)               */
/* ------------------------------------------------------------------ */

static void hcsrv_req_free(hcsrv_req_t* node) {
  if (!node) return;
  free(node->method);
  free(node->path);
  free(node->query);
  free(node->headers);
  free(node->body);
  free(node);
}

/* ------------------------------------------------------------------ */
/* MHD access handler (called on MHD's internal polling thread)        */
/* ------------------------------------------------------------------ */

static enum MHD_Result hcsrv_access_handler(
  void* cls, struct MHD_Connection* conn,
  const char* url, const char* method, const char* version,
  const char* upload_data, size_t* upload_data_size, void** con_cls)
{
  hcsrv_t* srv = (hcsrv_t*)cls;

  /* First call: allocate per-connection upload state */
  if (*con_cls == NULL) {
    hcsrv_upload_t* up = (hcsrv_upload_t*)calloc(1, sizeof(*up));
    if (!up) return MHD_NO;
    *con_cls = up;
    return MHD_YES;
  }

  hcsrv_upload_t* up = (hcsrv_upload_t*)*con_cls;

  /* Accumulate body data */
  if (*upload_data_size > 0) {
    char* p = (char*)realloc(up->body, up->body_size + *upload_data_size + 1);
    if (!p) return MHD_NO;
    up->body = p;
    memcpy(up->body + up->body_size, upload_data, *upload_data_size);
    up->body_size += *upload_data_size;
    up->body[up->body_size] = '\0';
    *upload_data_size = 0;
    return MHD_YES;
  }

  /* All data received — build a request node */
  hcsrv_req_t* node = (hcsrv_req_t*)calloc(1, sizeof(*node));
  if (!node) return MHD_NO;

  node->connection = conn;
  node->method = strdup(method ? method : "GET");
  node->path   = strdup(url   ? url    : "/");

  /* Collect request headers */
  hcsrv_buf_t hdr_buf;
  hcsrv_buf_init(&hdr_buf);
  MHD_get_connection_values(conn, MHD_HEADER_KIND, hcsrv_collect_header, &hdr_buf);
  node->headers = hdr_buf.buf; /* transfer ownership */

  /* Collect query parameters */
  hcsrv_buf_t qs_buf;
  hcsrv_buf_init(&qs_buf);
  MHD_get_connection_values(conn, MHD_GET_ARGUMENT_KIND, hcsrv_collect_query, &qs_buf);
  node->query = qs_buf.buf;

  /* Transfer body ownership */
  if (up->body) {
    node->body      = up->body;
    node->body_size = up->body_size;
    up->body = NULL;
  } else {
    node->body      = strdup("");
    node->body_size = 0;
  }

  /* Suspend connection — MHD will not close it until resumed */
  MHD_suspend_connection(conn);

  /* Enqueue the node (signalling the Koka thread) */
  pthread_mutex_lock(&srv->mutex);
  if (srv->tail) {
    srv->tail->next = node;
  } else {
    srv->head = node;
  }
  srv->tail = node;
  pthread_cond_signal(&srv->cond);
  pthread_mutex_unlock(&srv->mutex);

  /* Clean up upload state */
  free(up);
  *con_cls = NULL;

  return MHD_YES;
}

/* ------------------------------------------------------------------ */
/* MHD request-completed callback (cleans up if upload never finished) */
/* ------------------------------------------------------------------ */

static void hcsrv_request_completed(
  void* cls, struct MHD_Connection* conn,
  void** con_cls, enum MHD_RequestTerminationCode toe)
{
  hcsrv_upload_t* up = (hcsrv_upload_t*)*con_cls;
  if (up) {
    free(up->body);
    free(up);
    *con_cls = NULL;
  }
}

/* ================================================================== */
/* Koka-callable functions (always invoked from Koka's thread)         */
/* ================================================================== */

/* Start an HTTP server on the given port.
   Returns an opaque server handle (pointer as int), or 0 on failure. */
static kk_integer_t kk_http_server_start(kk_integer_t port_int, kk_context_t* ctx) {
  int port = (int)kk_integer_clamp64(port_int, ctx);
  kk_integer_drop(port_int, ctx);

  hcsrv_t* srv = (hcsrv_t*)calloc(1, sizeof(*srv));
  if (!srv) return kk_integer_from_int(0, ctx);

  pthread_mutex_init(&srv->mutex, NULL);
  pthread_cond_init(&srv->cond, NULL);

  srv->daemon = MHD_start_daemon(
    MHD_USE_INTERNAL_POLLING_THREAD | MHD_ALLOW_SUSPEND_RESUME,
    (uint16_t)port,
    NULL, NULL,
    hcsrv_access_handler, srv,
    MHD_OPTION_NOTIFY_COMPLETED,
      (MHD_RequestCompletedCallback)hcsrv_request_completed, NULL,
    MHD_OPTION_END
  );

  if (!srv->daemon) {
    pthread_mutex_destroy(&srv->mutex);
    pthread_cond_destroy(&srv->cond);
    free(srv);
    return kk_integer_from_int(0, ctx);
  }

  return kk_integer_from_int((kk_intx_t)(uintptr_t)srv, ctx);
}

/* Block until the next request arrives in the queue.
   Returns an opaque request handle (pointer as int), or 0 if stopped. */
static kk_integer_t kk_http_server_accept(kk_integer_t srv_int, kk_context_t* ctx) {
  hcsrv_t* srv = (hcsrv_t*)(uintptr_t)kk_integer_clamp64(srv_int, ctx);
  kk_integer_drop(srv_int, ctx);
  if (!srv) return kk_integer_from_int(0, ctx);

  pthread_mutex_lock(&srv->mutex);
  while (srv->head == NULL && !srv->stopped)
    pthread_cond_wait(&srv->cond, &srv->mutex);

  hcsrv_req_t* node = srv->head;
  if (node) {
    srv->head = node->next;
    if (!srv->head) srv->tail = NULL;
    node->next = NULL;
  }
  pthread_mutex_unlock(&srv->mutex);

  if (!node) return kk_integer_from_int(0, ctx);
  return kk_integer_from_int((kk_intx_t)(uintptr_t)node, ctx);
}

/* Field accessors — read from the C req node, create Koka strings.
   Each call borrows req_int (Koka handles refcounting of the boxed int). */

static kk_string_t kk_http_req_method(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  const char* s = (n && n->method) ? n->method : "";
  return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
}

static kk_string_t kk_http_req_path(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  const char* s = (n && n->path) ? n->path : "/";
  return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
}

static kk_string_t kk_http_req_query(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  const char* s = (n && n->query) ? n->query : "";
  return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
}

static kk_string_t kk_http_req_headers(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  const char* s = (n && n->headers) ? n->headers : "";
  return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
}

static kk_string_t kk_http_req_body(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  if (!n || !n->body) return kk_string_alloc_from_utf8n(0, "", ctx);
  return kk_string_alloc_from_utf8n((kk_ssize_t)n->body_size, n->body, ctx);
}

/* Send a response for a suspended request.
   headers is a newline-separated "Name: Value\n..." string.
   Frees the request node. Queues response then resumes the connection. */
static kk_unit_t kk_http_server_respond(
  kk_integer_t srv_int,
  kk_integer_t req_int,
  kk_integer_t status_int,
  kk_string_t  headers_str,
  kk_string_t  body_str,
  kk_context_t* ctx)
{
  hcsrv_t*     srv    = (hcsrv_t*)    (uintptr_t)kk_integer_clamp64(srv_int,    ctx);
  hcsrv_req_t* node   = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int,    ctx);
  int          status = (int)           kk_integer_clamp64(status_int, ctx);

  kk_integer_drop(srv_int,    ctx);
  kk_integer_drop(req_int,    ctx);
  kk_integer_drop(status_int, ctx);

  if (!node) {
    kk_string_drop(headers_str, ctx);
    kk_string_drop(body_str,    ctx);
    return kk_Unit;
  }

  kk_ssize_t  body_len;
  const char* c_body = kk_string_cbuf_borrow(body_str, &body_len, ctx);
  kk_ssize_t  hdr_len;
  const char* c_hdrs = kk_string_cbuf_borrow(headers_str, &hdr_len, ctx);

  /* Copy body: MHD takes ownership via MHD_RESPMEM_MUST_FREE */
  void* body_copy = NULL;
  if (body_len > 0) {
    body_copy = malloc((size_t)body_len);
    if (body_copy) memcpy(body_copy, c_body, (size_t)body_len);
  }

  struct MHD_Response* resp = MHD_create_response_from_buffer(
    (size_t)body_len,
    body_copy ? body_copy : (void*)"",
    body_copy ? MHD_RESPMEM_MUST_FREE : MHD_RESPMEM_PERSISTENT);

  /* Parse and add response headers (newline-separated "Name: Value") */
  if (hdr_len > 0) {
    char* h_copy = (char*)malloc((size_t)hdr_len + 1);
    if (h_copy) {
      memcpy(h_copy, c_hdrs, (size_t)hdr_len);
      h_copy[hdr_len] = '\0';
      char* line = strtok(h_copy, "\n");
      while (line) {
        char* colon = strchr(line, ':');
        if (colon) {
          *colon = '\0';
          const char* name  = line;
          const char* value = colon + 1;
          while (*value == ' ') value++;
          MHD_add_response_header(resp, name, value);
        }
        line = strtok(NULL, "\n");
      }
      free(h_copy);
    }
  }

  /* Save connection pointer before freeing the node */
  struct MHD_Connection* conn = node->connection;
  hcsrv_req_free(node);

  /* Queue response, then signal MHD to send it */
  MHD_queue_response(conn, (unsigned int)status, resp);
  MHD_destroy_response(resp);
  MHD_resume_connection(conn);

  kk_string_drop(headers_str, ctx);
  kk_string_drop(body_str,    ctx);

  return kk_Unit;
}

/* Stop the server, drain the queue, free all resources. */
static kk_unit_t kk_http_server_stop(kk_integer_t srv_int, kk_context_t* ctx) {
  hcsrv_t* srv = (hcsrv_t*)(uintptr_t)kk_integer_clamp64(srv_int, ctx);
  kk_integer_drop(srv_int, ctx);
  if (!srv) return kk_Unit;

  pthread_mutex_lock(&srv->mutex);
  srv->stopped = 1;
  pthread_cond_broadcast(&srv->cond);
  pthread_mutex_unlock(&srv->mutex);

  MHD_stop_daemon(srv->daemon);

  /* Drain any queued requests that were never responded to */
  hcsrv_req_t* node = srv->head;
  while (node) {
    hcsrv_req_t* next = node->next;
    hcsrv_req_free(node);
    node = next;
  }

  pthread_mutex_destroy(&srv->mutex);
  pthread_cond_destroy(&srv->cond);
  free(srv);

  return kk_Unit;
}
