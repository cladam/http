/*
 * http_server_inline.c — libmicrohttpd bindings for Koka
 * Part of the hica http library
 * Copyright (C) 2026 Claes Adamsson <claes.adamsson@gmail.com>
 * MIT License
 *
 * Threading model (single-threaded external polling):
 *   MHD runs in EXTERNAL polling mode — it has NO internal thread.  The Koka
 *   thread itself drives libmicrohttpd: kk_http_server_accept runs a
 *   select()+MHD_run() loop, so MHD's access_handler executes on the very same
 *   thread as the Koka runtime.  access_handler suspends the connection and
 *   pushes the completed request onto a queue; accept then dequeues it.
 *
 *   kk_http_server_respond queues the response, resumes the connection, and
 *   kicks MHD_run so the bytes go out; any remaining flush happens on the next
 *   accept poll.
 *
 *   Because everything — MHD callbacks, the request queue, and all Koka work —
 *   happens on a single thread, there is NO cross-thread handoff and no lock is
 *   needed.  A Koka context/heap is thread-local, so this is also the only
 *   memory-safe way to share Koka values with libmicrohttpd callbacks.  For
 *   multi-core scaling, run several of these servers as prefork processes
 *   sharing the listen socket via SO_REUSEPORT.
 */

#include <microhttpd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>

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
/* Multipart parts                                                      */
/* ------------------------------------------------------------------ */

/* Maximum size of a single multipart part (64 MiB). */
#define HCSRV_PART_MAX_BYTES ((size_t)(64 * 1024 * 1024))

typedef struct {
  char*  name;          /* form-field name (always present) */
  char*  filename;      /* original filename; NULL for non-file fields */
  char*  content_type;  /* MIME type; NULL if not specified */
  char*  bytes;         /* raw bytes (binary-safe; NOT NUL-terminated) */
  size_t bytes_len;
} hcsrv_part_t;

static void hcsrv_part_free(hcsrv_part_t* p) {
  if (!p) return;
  free(p->name);
  free(p->filename);
  free(p->content_type);
  free(p->bytes);
}

/* ------------------------------------------------------------------ */
/* Per-connection upload accumulator (lives on MHD thread)             */
/* ------------------------------------------------------------------ */

typedef struct {
  /* Raw body (non-multipart requests). */
  char*  body;
  size_t body_size;

  /* Multipart state (NULL when not a multipart/form-data request). */
  struct MHD_PostProcessor* post_processor;
  hcsrv_part_t* parts;
  size_t        parts_count;
  size_t        parts_cap;
} hcsrv_upload_t;

/* ------------------------------------------------------------------ */
/* A request node: request data in, staged response out.  Lives only   */
/* for the duration of a single hcsrv_access_handler invocation.       */
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
  /* Multipart parts (empty for non-multipart requests). */
  hcsrv_part_t* parts;
  size_t        parts_count;
  /* Response staged by the Koka handler via kk_http_set_response. */
  int    resp_status;
  char*  resp_headers;   /* "Name: Value\n..." (may be NULL) */
  char*  resp_body;      /* may be NULL */
  size_t resp_body_len;
  int    resp_set;
};

/* ------------------------------------------------------------------ */
/* Server state                                                         */
/* ------------------------------------------------------------------ */

typedef struct {
  struct MHD_Daemon* daemon;
  kk_function_t      handler;   /* Koka: (int node_id) -> io ()  (owned) */
  kk_context_t*      ctx;       /* Koka context of the serving thread */
  int                stopped;
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
/* Multipart post-data iterator (MHD callback)                         */
/* ------------------------------------------------------------------ */

/* Find the index of a part by name, or -1 if not found. */
static int hcsrv_upload_find_part(hcsrv_upload_t* up, const char* key) {
  for (int i = (int)up->parts_count - 1; i >= 0; i--) {
    if (up->parts[i].name && strcmp(up->parts[i].name, key) == 0)
      return i;
  }
  return -1;
}

/* Append raw bytes to a part, respecting the per-part size cap. */
static int hcsrv_part_append(hcsrv_part_t* p, const char* data, size_t size) {
  if (!data || size == 0) return 1;
  if (p->bytes_len + size > HCSRV_PART_MAX_BYTES) return 0; /* size cap */
  char* np = (char*)realloc(p->bytes, p->bytes_len + size);
  if (!np) return 0;
  memcpy(np + p->bytes_len, data, size);
  p->bytes      = np;
  p->bytes_len += size;
  return 1;
}

static enum MHD_Result hcsrv_post_iter(
  void* cls,
  enum MHD_ValueKind kind,
  const char* key,
  const char* filename,
  const char* content_type,
  const char* transfer_encoding,
  const char* data,
  uint64_t    off,
  size_t      size)
{
  (void)kind; (void)transfer_encoding;
  hcsrv_upload_t* up = (hcsrv_upload_t*)cls;
  if (!key) return MHD_YES;

  /* When off==0 the part is starting fresh — create a new entry unless we
     already have one with this name from a previous chunk sequence (which
     would indicate repeated field names; we create distinct entries). */
  int idx = (off == 0) ? -1 : hcsrv_upload_find_part(up, key);

  if (idx < 0) {
    /* Grow parts array if needed. */
    if (up->parts_count == up->parts_cap) {
      size_t new_cap = up->parts_cap ? up->parts_cap * 2 : 4;
      hcsrv_part_t* np = (hcsrv_part_t*)realloc(up->parts,
                                                  new_cap * sizeof(hcsrv_part_t));
      if (!np) return MHD_NO;
      up->parts     = np;
      up->parts_cap = new_cap;
    }
    hcsrv_part_t* p = &up->parts[up->parts_count++];
    memset(p, 0, sizeof(*p));
    p->name         = strdup(key);
    p->filename     = filename    ? strdup(filename)     : NULL;
    p->content_type = content_type ? strdup(content_type) : NULL;
    idx = (int)(up->parts_count - 1);
  }

  if (!hcsrv_part_append(&up->parts[idx], data, size))
    return MHD_NO;  /* size cap or OOM — abort the post processor */

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
  free(node->resp_headers);
  free(node->resp_body);
  for (size_t i = 0; i < node->parts_count; i++)
    hcsrv_part_free(&node->parts[i]);
  free(node->parts);
  free(node);
}

/* ------------------------------------------------------------------ */
/* MHD access handler (runs on the Koka thread, inside our MHD_run)     */
/* ------------------------------------------------------------------ */

static enum MHD_Result hcsrv_access_handler(
  void* cls, struct MHD_Connection* conn,
  const char* url, const char* method, const char* version,
  const char* upload_data, size_t* upload_data_size, void** con_cls)
{
  hcsrv_t* srv = (hcsrv_t*)cls;

  /* First call: allocate per-connection upload state; detect multipart. */
  if (*con_cls == NULL) {
    hcsrv_upload_t* up = (hcsrv_upload_t*)calloc(1, sizeof(*up));
    if (!up) return MHD_NO;

    /* If this is a multipart/form-data request, create a post processor.
       Use a 64 KiB processing buffer — MHD streams data through it. */
    const char* ct = MHD_lookup_connection_value(conn, MHD_HEADER_KIND, "Content-Type");
    if (ct && strncmp(ct, "multipart/form-data", 19) == 0) {
      up->post_processor = MHD_create_post_processor(
        conn, 65536, hcsrv_post_iter, up);
      /* If creation failed, we fall back to raw body accumulation. */
    }

    *con_cls = up;
    return MHD_YES;
  }

  hcsrv_upload_t* up = (hcsrv_upload_t*)*con_cls;

  /* Accumulate body data */
  if (*upload_data_size > 0) {
    if (up->post_processor) {
      /* Feed data to the multipart post processor. */
      if (MHD_post_process(up->post_processor, upload_data, *upload_data_size) != MHD_YES)
        return MHD_NO;
    } else {
      /* Raw body accumulation (non-multipart). */
      char* p = (char*)realloc(up->body, up->body_size + *upload_data_size + 1);
      if (!p) return MHD_NO;
      up->body = p;
      memcpy(up->body + up->body_size, upload_data, *upload_data_size);
      up->body_size += *upload_data_size;
      up->body[up->body_size] = '\0';
    }
    *upload_data_size = 0;
    return MHD_YES;
  }

  /* All data received — build a request node (on the Koka thread). */
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

  /* Finish multipart processing and transfer parts to the node. */
  if (up->post_processor) {
    MHD_destroy_post_processor(up->post_processor);
    up->post_processor = NULL;
  }
  node->parts       = up->parts;
  node->parts_count = up->parts_count;
  up->parts         = NULL;
  up->parts_count   = 0;
  up->parts_cap     = 0;

  free(up);
  *con_cls = NULL;

  /* Invoke the Koka handler synchronously.  We are already running on the
     Koka thread (inside MHD_run, which we drive ourselves in kk_http_server_run),
     so calling back into Koka is safe.  The handler reads the request through the
     node id and stages its response by calling kk_http_set_response, which fills
     node->resp_*.  No suspend/resume, no queue, no cross-thread handoff. */
  kk_context_t* ctx = srv->ctx;
  kk_integer_t node_id = kk_integer_from_int((kk_intx_t)(uintptr_t)node, ctx);
  kk_function_t h = kk_function_dup(srv->handler, ctx);
  kk_function_call(kk_unit_t,
    (kk_function_t, kk_integer_t, kk_context_t*),
    h, (h, node_id, ctx), ctx);

  /* Build the MHD response from the staged fields (MHD copies the body). */
  int status = node->resp_set ? node->resp_status : 500;
  struct MHD_Response* resp = MHD_create_response_from_buffer(
    node->resp_body_len,
    node->resp_body ? (void*)node->resp_body : (void*)"",
    MHD_RESPMEM_MUST_COPY);

  /* Parse and add response headers (newline-separated "Name: Value"). */
  if (node->resp_headers) {
    char* saveptr = NULL;
    char* line = strtok_r(node->resp_headers, "\n", &saveptr);
    while (line) {
      char* colon = strchr(line, ':');
      if (colon) {
        *colon = '\0';
        const char* name  = line;
        const char* value = colon + 1;
        while (*value == ' ') value++;
        MHD_add_response_header(resp, name, value);
      }
      line = strtok_r(NULL, "\n", &saveptr);
    }
  }

  enum MHD_Result rc = MHD_queue_response(conn, (unsigned int)status, resp);
  MHD_destroy_response(resp);

  hcsrv_req_free(node);
  return rc;
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
    if (up->post_processor) MHD_destroy_post_processor(up->post_processor);
    for (size_t i = 0; i < up->parts_count; i++) hcsrv_part_free(&up->parts[i]);
    free(up->parts);
    free(up->body);
    free(up);
    *con_cls = NULL;
  }
}

/* ================================================================== */
/* Koka-callable functions (always invoked from Koka's thread)         */
/* ================================================================== */

/* Drive libmicrohttpd for one poll cycle on the Koka thread: wait (bounded)
   for socket activity, then let MHD process it.  Because every request is
   handled synchronously inside hcsrv_access_handler, there is no queue and no
   suspend/resume — MHD naturally interleaves concurrent connections across
   successive MHD_run calls.  Returns 0 only on a fatal daemon error. */
static int hcsrv_poll(hcsrv_t* srv) {
  fd_set rs, ws, es;
  FD_ZERO(&rs); FD_ZERO(&ws); FD_ZERO(&es);
  MHD_socket maxfd = 0;
  if (MHD_get_fdset(srv->daemon, &rs, &ws, &es, &maxfd) != MHD_YES)
    return 0;

  struct timeval tv;
  MHD_UNSIGNED_LONG_LONG mhd_to;
  if (MHD_get_timeout(srv->daemon, &mhd_to) == MHD_YES) {
    tv.tv_sec  = (time_t)(mhd_to / 1000);
    tv.tv_usec = (long)((mhd_to % 1000) * 1000);
  } else {
    /* No MHD timeout pending: block up to 1s so we periodically re-check stop. */
    tv.tv_sec  = 1;
    tv.tv_usec = 0;
  }

  int sel = select((int)maxfd + 1, &rs, &ws, &es, &tv);
  if (sel < 0 && errno != EINTR)
    return 0;
  MHD_run(srv->daemon);
  return 1;
}

/* Stage the response computed by the Koka handler onto the request node.
   Copies the strings into C memory; the node is consumed by the caller
   (hcsrv_access_handler) immediately after the handler returns. */
static kk_unit_t kk_http_set_response(
  kk_integer_t  node_int,
  kk_integer_t  status_int,
  kk_string_t   headers_str,
  kk_string_t   body_str,
  kk_context_t* ctx)
{
  hcsrv_req_t* node   = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(node_int, ctx);
  int          status = (int)           kk_integer_clamp64(status_int, ctx);
  kk_integer_drop(node_int,   ctx);
  kk_integer_drop(status_int, ctx);

  if (node) {
    kk_ssize_t  blen;
    const char* b = kk_string_cbuf_borrow(body_str, &blen, ctx);
    kk_ssize_t  hlen;
    const char* h = kk_string_cbuf_borrow(headers_str, &hlen, ctx);

    node->resp_status   = status;
    node->resp_body     = NULL;
    node->resp_body_len = 0;
    if (blen > 0) {
      node->resp_body = (char*)malloc((size_t)blen);
      if (node->resp_body) {
        memcpy(node->resp_body, b, (size_t)blen);
        node->resp_body_len = (size_t)blen;
      }
    }
    node->resp_headers = NULL;
    if (hlen > 0) {
      node->resp_headers = (char*)malloc((size_t)hlen + 1);
      if (node->resp_headers) {
        memcpy(node->resp_headers, h, (size_t)hlen);
        node->resp_headers[hlen] = '\0';
      }
    }
    node->resp_set = 1;
  }

  kk_string_drop(headers_str, ctx);
  kk_string_drop(body_str,    ctx);
  return kk_Unit;
}

/* Run an HTTP server on `port`, dispatching every request to the Koka
   `handler` (a `(int node_id) -> io ()` closure).  Single-threaded event loop:
   we own the Koka thread and drive MHD_run ourselves, so the handler always
   runs on this same thread with a valid context.  Never returns until stopped. */
static kk_unit_t kk_http_server_run(
  kk_integer_t   port_int,
  kk_function_t  handler,
  kk_context_t*  ctx)
{
  int port = (int)kk_integer_clamp64(port_int, ctx);
  kk_integer_drop(port_int, ctx);

  hcsrv_t* srv = (hcsrv_t*)calloc(1, sizeof(*srv));
  if (!srv) { kk_function_drop(handler, ctx); return kk_Unit; }
  srv->handler = handler;   /* take ownership for the server's lifetime */
  srv->ctx     = ctx;

  /* External polling, no internal thread, no suspend/resume. */
  srv->daemon = MHD_start_daemon(
    MHD_NO_FLAG,
    (uint16_t)port,
    NULL, NULL,
    hcsrv_access_handler, srv,
    MHD_OPTION_CONNECTION_LIMIT,      (unsigned int)4096,
    MHD_OPTION_LISTEN_BACKLOG_SIZE,   (unsigned int)1024,
    MHD_OPTION_NOTIFY_COMPLETED,
      (MHD_RequestCompletedCallback)hcsrv_request_completed, NULL,
    MHD_OPTION_END
  );
  if (!srv->daemon) {
    kk_function_drop(srv->handler, ctx);
    free(srv);
    return kk_Unit;
  }

  while (!srv->stopped) {
    if (!hcsrv_poll(srv)) break;
  }

  MHD_stop_daemon(srv->daemon);
  kk_function_drop(srv->handler, ctx);
  free(srv);
  return kk_Unit;
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

/* Monotonic clock in milliseconds — used for request-latency logging.
   CLOCK_MONOTONIC is unaffected by wall-clock adjustments, so a difference of
   two readings is a robust elapsed time. */
static kk_integer_t kk_http_now_millis(kk_context_t* ctx) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  int64_t ms = (int64_t)ts.tv_sec * 1000 + (int64_t)(ts.tv_nsec / 1000000);
  return kk_integer_from_int((kk_intx_t)ms, ctx);
}

/* Flush stdout — Koka block-buffers stdout when it is not a TTY (e.g. logs
   redirected to a file), so the access logger flushes after each line. */
static kk_unit_t kk_http_flush_stdout(kk_context_t* ctx) {
  fflush(stdout);
  return kk_Unit;
}

/* ------------------------------------------------------------------ */
/* Multipart part accessors (Koka-callable)                             */
/* ------------------------------------------------------------------ */

/* Total number of parsed multipart parts (0 for non-multipart requests). */
static kk_integer_t kk_http_req_part_count(kk_integer_t req_int, kk_context_t* ctx) {
  hcsrv_req_t* n = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  kk_integer_drop(req_int, ctx);
  int count = (n) ? (int)n->parts_count : 0;
  return kk_integer_from_int((kk_intx_t)count, ctx);
}

/* Return a field of part[idx] as a Koka string.
   selector: 0=name, 1=filename, 2=content_type, 3=bytes (binary-safe). */
static kk_string_t kk_http_req_part_field(kk_integer_t req_int, kk_integer_t idx_int,
                                           kk_integer_t sel_int, kk_context_t* ctx) {
  hcsrv_req_t* n   = (hcsrv_req_t*)(uintptr_t)kk_integer_clamp64(req_int, ctx);
  int           idx = (int)kk_integer_clamp64(idx_int, ctx);
  int           sel = (int)kk_integer_clamp64(sel_int, ctx);
  kk_integer_drop(req_int, ctx);
  kk_integer_drop(idx_int, ctx);
  kk_integer_drop(sel_int, ctx);

  if (!n || idx < 0 || (size_t)idx >= n->parts_count) {
    return kk_string_alloc_from_utf8n(0, "", ctx);
  }
  const hcsrv_part_t* p = &n->parts[idx];
  switch (sel) {
    case 0: { /* name */
      const char* s = p->name ? p->name : "";
      return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
    }
    case 1: { /* filename */
      const char* s = p->filename ? p->filename : "";
      return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
    }
    case 2: { /* content_type */
      const char* s = p->content_type ? p->content_type : "";
      return kk_string_alloc_from_utf8n((kk_ssize_t)strlen(s), s, ctx);
    }
    case 3: { /* bytes (binary-safe) */
      if (!p->bytes || p->bytes_len == 0)
        return kk_string_alloc_from_utf8n(0, "", ctx);
      return kk_string_alloc_from_utf8n((kk_ssize_t)p->bytes_len, p->bytes, ctx);
    }
    default:
      return kk_string_alloc_from_utf8n(0, "", ctx);
  }
}
