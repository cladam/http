// Koka generated module: std/core/hnd, koka version: 3.2.3, platform: 64-bit
#include "std_core_hnd.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/
/*
typedef datatype_t kk_std_core_hnd__ev;
struct kk_std_core_hnd_Ev {
  kk_std_core_hnd__htag htag;
  kk_box_t hnd;
  // kk_cfc_t cfc;  // control flow context
  kk_std_core_hnd__evv hevv;
  kk_std_core_hnd__marker marker;
};
*/


// Note. We no longer support cfc for `evv_is_affine` in the C backend since we always use context paths now.
//
// typedef int32_t kk_cfc_t;

// static kk_cfc_t kk_handler_cfc_borrow( kk_box_t h, kk_context_t* ctx ) {
//   kk_box_t b = kk_block_field(kk_ptr_unbox(h,ctx),0);  // first field of the handler is the cfc
//   return kk_integer_clamp32_borrow(kk_integer_unbox(b,ctx),ctx);
// }


static kk_evv_vector_t kk_evv_vector_alloc(kk_ssize_t length, kk_context_t* ctx) {
  kk_assert_internal(length>=0);
  kk_evv_vector_t v = (kk_evv_vector_t)kk_block_alloc(kk_ssizeof(struct kk_evv_vector_s) + (length-1)*kk_ssizeof(kk_std_core_hnd__ev_t), length, KK_TAG_EVV_VECTOR, ctx);
  // v->cfc = kk_integer_from_int32(cfc,ctx);
  return v;
}

static kk_std_core_hnd__ev* kk_evv_vector_buf(kk_evv_vector_t vec, kk_ssize_t* len) {
  if (len != NULL) { *len = kk_block_scan_fsize(&vec->_block); }
  return &vec->vec[0];
}

static kk_std_core_hnd__ev* kk_evv_as_vec(kk_evv_t evv, kk_ssize_t* len, kk_std_core_hnd__ev* single, kk_context_t* ctx) {
  if (kk_evv_is_vector(evv,ctx)) {
    kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
    *len = kk_block_scan_fsize(&vec->_block);
    return &vec->vec[0];
  }
  else {
    // single evidence
    *single = kk_evv_as_ev(evv,ctx);
    *len = 1;
    return single;
  }
}

// kk_std_core_hnd__ev kk_ev_none(kk_context_t* ctx) {
//   static kk_std_core_hnd__ev ev_none_singleton = { kk_datatype_null_init };
//   if (kk_datatype_is_null(ev_none_singleton)) {
//     ev_none_singleton = kk_std_core_hnd__new_Ev(
//       kk_reuse_null,
//       0, // cpath
//       kk_std_core_hnd__new_Htag(kk_string_empty(),ctx), // tag ""
//       0,                                                // marker 0
//       kk_box_null(),                                    // no handler
//       // -1,                                               // bot
//       kk_evv_empty(ctx),
//       ctx
//     );
//   }
//   return kk_std_core_hnd__ev_dup(ev_none_singleton,ctx);
// }


kk_ssize_t kk_evv_index( struct kk_std_core_hnd_Htag htag, kk_context_t* ctx ) {
  // todo: drop htag?
  kk_ssize_t len;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
    if (kk_string_cmp_borrow(htag.tagname,ev->htag.tagname,ctx) <= 0) return i; // break on insertion point
  }
  //string_t evvs = kk_evv_show(dup_datatype_as(kk_evv_t,ctx->evv),ctx);
  //fatal_error(EFAULT,"cannot find tag '%s' in: %s", string_cbuf_borrow(htag.htag), string_cbuf_borrow(evvs));
  //drop_string_t(evvs,ctx);
  return len;
}


// static inline kk_cfc_t kk_cfc_lub(kk_cfc_t cfc1, kk_cfc_t cfc2) {
//   if (cfc1 < 0) return cfc2;
//   else if (cfc1+cfc2 == 1) return 2;
//   else if (cfc1>cfc2) return cfc1;
//   else return cfc2;
// }

// static inline struct kk_std_core_hnd_Ev* kk_evv_as_Ev( kk_evv_t evv, kk_context_t* ctx ) {
//   return kk_std_core_hnd__as_Ev(kk_evv_as_ev(evv,ctx),ctx);
// }


// static kk_cfc_t kk_evv_cfc_of_borrow(kk_evv_t evv, kk_context_t* ctx) {
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_cfc_t cfc = -1;
//     kk_ssize_t len;
//     kk_std_core_hnd__ev single;
//     kk_std_core_hnd__ev* vec = kk_evv_as_vec(ctx->evv,&len,&single,ctx);
//     for(kk_ssize_t i = 0; i < len; i++) {
//       struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(vec[i],ctx);
//       cfc = kk_cfc_lub(cfc, kk_handler_cfc_borrow(ev->hnd,ctx));
//     }
//     return cfc;
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     return kk_handler_cfc_borrow(ev->hnd,ctx);
//   }
// }

bool kk_evv_is_affine(kk_context_t* ctx) {
  return false;
  // return (kk_evv_cfc_of_borrow(ctx->evv,ctx) <= 2);
}


// static void kk_evv_update_cfc_borrow(kk_evv_t evv, kk_cfc_t cfc, kk_context_t* ctx) {
//   kk_assert_internal(!kk_evv_is_empty(evv,ctx)); // should never happen (as named handlers are always in some context)
//   if (kk_evv_is_vector(evv,ctx)) {
//     kk_evv_vector_t vec = kk_evv_as_vector(evv,ctx);
//     vec->cfc = kk_integer_from_int32(kk_cfc_lub(kk_integer_clamp32_borrow(vec->cfc,ctx),cfc), ctx);
//   }
//   else {
//     struct kk_std_core_hnd_Ev* ev = kk_evv_as_Ev(evv,ctx);
//     ev->cfc = kk_cfc_lub(ev->cfc,cfc);
//   }
// }

kk_evv_t kk_evv_insert(kk_evv_t evvd, kk_std_core_hnd__ev evd, kk_context_t* ctx) {
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evd,ctx);
  // update ev with parent evidence vector (either at init, or due to non-scoped resumptions)
  kk_marker_t marker = ev->marker;
  if (marker==0) { kk_std_core_hnd__ev_drop(evd,ctx); return evvd; } // ev-none
  kk_evv_drop(ev->hevv,ctx);
  ev->hevv = kk_evv_dup(evvd,ctx); // fixme: update in-place
  if (marker<0) { // negative marker is used for named evidence; this means this evidence should not be inserted into the evidence vector
    // kk_evv_update_cfc_borrow(evvd,ev->cfc,ctx); // update cfc in-place for named evidence
    kk_std_core_hnd__ev_drop(evd,ctx);
    return evvd;
  }
  // for regular handler evidence, insert ev
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* const evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n == 0) {
    // use ev directly as the evidence vector
    kk_evv_drop(evvd, ctx);
    return kk_ev_as_evv(evd,ctx);
  }
  else {
    // create evidence vector
    // const kk_cfc_t cfc = kk_cfc_lub(kk_evv_cfc_of_borrow(evvd, ctx), ev->cfc);
    // ev->cfc = cfc; // update in place
    kk_evv_vector_t vec2 = kk_evv_vector_alloc(n+1, /* cfc,*/ ctx);
    kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2, NULL);
    kk_ssize_t i;
    for (i = 0; i < n; i++) {
      struct kk_std_core_hnd_Ev* ev1 = kk_std_core_hnd__as_Ev(evv1[i],ctx);
      if (kk_string_cmp_borrow(ev->htag.tagname, ev1->htag.tagname,ctx) <= 0) break;
      evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    evv2[i] = evd;
    for (; i < n; i++) {
      evv2[i+1] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
    }
    kk_evv_drop(evvd, ctx);  // assigned to evidence already
    return kk_datatype_from_base(vec2,ctx);
  }
}

kk_evv_t kk_evv_delete(kk_evv_t evvd, kk_ssize_t index, bool behind, kk_context_t* ctx) {
  kk_ssize_t n;
  kk_std_core_hnd__ev single;
  const kk_std_core_hnd__ev* evv1 = kk_evv_as_vec(evvd, &n, &single, ctx);
  if (n <= 1) {
    kk_evv_drop(evvd,ctx);
    return kk_evv_empty(ctx);
  }
  if (behind) index++;
  kk_assert_internal(index < n);
  // todo: copy without dupping (and later dropping) when possible
  // const kk_cfc_t cfc1 = kk_evv_cfc_of_borrow(evvd,ctx);
  kk_evv_vector_t const vec2 = kk_evv_vector_alloc(n-1,/*cfc1,*/ ctx);
  kk_std_core_hnd__ev* const evv2 = kk_evv_vector_buf(vec2,NULL);
  kk_ssize_t i;
  for(i = 0; i < index; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i],ctx);
  }
  for(; i < n-1; i++) {
    evv2[i] = kk_std_core_hnd__ev_dup(evv1[i+1],ctx);
  }
  struct kk_std_core_hnd_Ev* ev = kk_std_core_hnd__as_Ev(evv1[index],ctx);
  // if (ev->cfc >= cfc1) {
  //   kk_cfc_t cfc = kk_std_core_hnd__as_Ev(evv2[0],ctx)->cfc;
  //   for(i = 1; i < n-1; i++) {
  //     cfc = kk_cfc_lub(cfc,kk_std_core_hnd__as_Ev(evv2[i],ctx)->cfc);
  //   }
  //   vec2->cfc = kk_integer_from_int32(cfc,ctx);
  // }
  kk_evv_drop(evvd,ctx);
  return kk_datatype_from_base(vec2,ctx);
}

kk_evv_t kk_evv_create(kk_evv_t evv1, kk_vector_t indices, kk_context_t* ctx) {
  kk_ssize_t len;
  kk_box_t* elems = kk_vector_buf_borrow(indices,&len,ctx); // borrows
  kk_evv_vector_t evv2 = kk_evv_vector_alloc(len,/* kk_evv_cfc_of_borrow(evv1,ctx),*/ ctx);
  kk_std_core_hnd__ev* buf2 = kk_evv_vector_buf(evv2,NULL);
  kk_assert_internal(kk_evv_is_vector(evv1,ctx));
  kk_ssize_t len1;
  kk_std_core_hnd__ev single;
  kk_std_core_hnd__ev* buf1 = kk_evv_as_vec(evv1,&len1,&single,ctx);
  for(kk_ssize_t i = 0; i < len; i++) {
    kk_ssize_t idx = kk_ssize_unbox(elems[i],KK_BORROWED,ctx);
    kk_assert_internal(idx < len1);
    buf2[i] = kk_std_core_hnd__ev_dup( buf1[idx], ctx );
  }
  kk_vector_drop(indices,ctx);
  kk_evv_drop(evv1,ctx);
  return kk_datatype_from_base(evv2,ctx);
}

kk_evv_t kk_evv_swap_create( kk_vector_t indices, kk_context_t* ctx ) {
  kk_ssize_t len;
  kk_box_t* vec = kk_vector_buf_borrow(indices,&len,ctx);
  if (len==0) {
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create0(ctx);
  }
  if (len==1) {
    kk_ssize_t i = kk_ssize_unbox(vec[0],KK_BORROWED,ctx);
    kk_vector_drop(indices,ctx);
    return kk_evv_swap_create1(i,ctx);
  }
  return kk_evv_swap( kk_evv_create(kk_evv_dup(ctx->evv,ctx),indices,ctx), ctx );
}


kk_string_t kk_evv_show(kk_evv_t evv, kk_context_t* ctx) {
  return kk_string_alloc_dup_valid_utf8("(not yet implemented: kk_evv_show)",ctx);
}


/*-----------------------------------------------------------------------
  Compose continuations
-----------------------------------------------------------------------*/

struct kcompose_fun_s {
  struct kk_function_s _base;
  kk_box_t      count;
  kk_function_t conts[1];
};

// kleisli composition of continuations
static kk_box_t kcompose( kk_function_t fself, kk_box_t x, kk_context_t* ctx) {
  struct kcompose_fun_s* self = kk_function_as(struct kcompose_fun_s*,fself,ctx);
  kk_intx_t count = kk_intf_unbox(self->count);
  kk_function_t* conts = &self->conts[0];
  // call each continuation in order
  for(kk_intx_t i = 0; i < count; i++) {
    // todo: take uniqueness of fself into account to avoid dup_function
    kk_function_t f = kk_function_dup(conts[i],ctx);
    x = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, ctx), ctx);
    if (kk_yielding(ctx)) {
      // if yielding, `yield_next` all continuations that still need to be done
      while(++i < count) {
        // todo: if fself is unique, we could copy without dup?
        kk_yield_extend(kk_function_dup(conts[i],ctx),ctx);
      }
      kk_function_drop(fself,ctx);
      kk_box_drop(x,ctx);     // still drop even though we yield as it may release a boxed value type?
      return kk_box_any(ctx); // return yielding
    }
  }
  kk_function_drop(fself,ctx);
  return x;
}

static kk_function_t new_kcompose( kk_function_t* conts, kk_intf_t count, kk_context_t* ctx ) {
  if (count==0) return kk_function_id(ctx);
  if (count==1) return conts[0];
  struct kcompose_fun_s* f = kk_block_as(struct kcompose_fun_s*,
                               kk_block_alloc(kk_ssizeof(struct kcompose_fun_s) - kk_ssizeof(kk_function_t) + (count*kk_ssizeof(kk_function_t)),
                                 2 + count /* scan size */, KK_TAG_FUNCTION, ctx));
  f->_base.fun = kk_kkfun_ptr_box(&kcompose,ctx);
  f->count = kk_intf_box(count);
  kk_memcpy(f->conts, conts, count * kk_ssizeof(kk_function_t));
  return kk_datatype_from_base(&f->_base,ctx);
}

/*-----------------------------------------------------------------------
  Yield extension
-----------------------------------------------------------------------*/

kk_box_t kk_yield_extend( kk_function_t next, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx));  // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    // todo: can we optimize this so `next` is never allocated in the first place?
    kk_function_drop(next,ctx); // ignore extension if never resuming
  }
  else {
    if (kk_unlikely(yield->conts_count >= KK_YIELD_CONT_MAX)) {
      // alloc a function to compose all continuations in the array
      kk_function_t comp = new_kcompose( yield->conts, yield->conts_count, ctx );
      yield->conts[0] = comp;
      yield->conts_count = 1;
    }
    yield->conts[yield->conts_count++] = next;
  }
  return kk_box_any(ctx);
}

// cont_apply: \x -> f(cont,x)
struct cont_apply_fun_s {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t cont;
};

static kk_box_t cont_apply( kk_function_t fself, kk_box_t x, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_as(struct cont_apply_fun_s*, fself, ctx);
  kk_function_t f = self->f;
  kk_function_t cont = self->cont;
  kk_drop_match(self,{kk_function_dup(f,ctx);kk_function_dup(cont,ctx);},{},ctx);
  return kk_function_call( kk_box_t, (kk_function_t, kk_function_t, kk_box_t, kk_context_t* ctx), f, (f, cont, x, ctx), ctx);
}

static kk_function_t kk_new_cont_apply( kk_function_t f, kk_function_t cont, kk_context_t* ctx ) {
  struct cont_apply_fun_s* self = kk_function_alloc_as(struct cont_apply_fun_s, 3, ctx);
  self->_base.fun = kk_kkfun_ptr_box(&cont_apply,ctx);
  self->f = f;
  self->cont = cont;
  return kk_datatype_from_base(&self->_base,ctx);
}

// Unlike `yield_extend`, `yield_cont` gets access to the current continuation. This is used in `yield_prompt`.
kk_box_t kk_yield_cont( kk_function_t f, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(kk_yielding(ctx)); // cannot extend if not yielding
  if (kk_unlikely(kk_yielding_final(ctx))) {
    kk_function_drop(f,ctx); // ignore extension if never resuming
  }
  else {
    kk_function_t cont = new_kcompose(yield->conts, yield->conts_count, ctx);
    yield->conts_count = 1;
    yield->conts[0] = kk_new_cont_apply(f, cont, ctx);
  }
  return kk_box_any(ctx);
}

kk_function_t kk_yield_to( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  kk_assert_internal(!kk_yielding(ctx)); // already yielding
  ctx->yielding = KK_YIELD_NORMAL;
  yield->marker = m;
  yield->clause = clause;
  yield->conts_count = 0;
  return kk_datatype_unbox(kk_box_any(ctx));
}

kk_box_t kk_yield_final( kk_marker_t m, kk_function_t clause, kk_context_t* ctx ) {
  kk_yield_to(m,clause,ctx);
  ctx->yielding = KK_YIELD_FINAL;
  return kk_box_any(ctx);
}

kk_box_t kk_fatal_resume_final(kk_context_t* ctx) {
  kk_fatal_error(EFAULT,"trying to resume a finalized resumption");
  return kk_box_any(ctx);
}

static kk_box_t _fatal_resume_final(kk_function_t self, kk_context_t* ctx) {
  kk_function_drop(self,ctx);
  return kk_fatal_resume_final(ctx);
}
static kk_function_t fun_fatal_resume_final(kk_context_t* ctx) {
  kk_define_static_function(f,_fatal_resume_final,ctx);
  return kk_function_dup(f,ctx);
}


struct kk_std_core_hnd_yld_s kk_yield_prompt( kk_marker_t m, kk_context_t* ctx ) {
  kk_yield_t* yield = &ctx->yield;
  if (ctx->yielding == KK_YIELD_NONE) {
    return kk_std_core_hnd__new_Pure(ctx);
  }
  else if (yield->marker != m) {
    return (ctx->yielding == KK_YIELD_FINAL ? kk_std_core_hnd__new_YieldingFinal(ctx) : kk_std_core_hnd__new_Yielding(ctx));
  }
  else {
    kk_function_t cont = (ctx->yielding == KK_YIELD_FINAL ? fun_fatal_resume_final(ctx) : new_kcompose(yield->conts, yield->conts_count, ctx));
    kk_function_t clause = yield->clause;
    ctx->yielding = KK_YIELD_NONE;
    #ifndef NDEBUG
    kk_memset(yield,0,kk_ssizeof(kk_yield_t));
    #endif
    return kk_std_core_hnd__new_Yield(clause, cont, ctx);
  }
}

kk_unit_t  kk_evv_guard(kk_evv_t evv, kk_context_t* ctx) {
  bool eq = kk_datatype_eq(ctx->evv,evv);
  kk_evv_drop(evv,ctx);
  if (!eq) {
    // todo: improve error message with diagnostics
    kk_fatal_error(EFAULT,"trying to resume outside the (handler) scope of the original handler");
  }
  return kk_Unit;
}

typedef struct yield_info_s {
  struct kk_std_core_hnd__yield_info_s _base;
  kk_function_t clause;
  kk_function_t conts[KK_YIELD_CONT_MAX];
  kk_intf_t     conts_count;
  kk_marker_t   marker;
  int8_t        yielding;
}* yield_info_t;

kk_std_core_hnd__yield_info kk_yield_capture(kk_context_t* ctx) {
  kk_assert_internal(kk_yielding(ctx));
  yield_info_t yld = kk_block_alloc_as(struct yield_info_s, 1 + KK_YIELD_CONT_MAX, (kk_tag_t)1, ctx);
  yld->clause = ctx->yield.clause;
  kk_ssize_t i = 0;
  for( ; i < ctx->yield.conts_count; i++) {
    yld->conts[i] = ctx->yield.conts[i];
  }
  for( ; i < KK_YIELD_CONT_MAX; i++) {
    yld->conts[i] = kk_function_null(ctx);
  }
  yld->conts_count = ctx->yield.conts_count;
  yld->marker = ctx->yield.marker;
  yld->yielding = ctx->yielding;
  ctx->yielding = 0;
  ctx->yield.conts_count = 0;
  return kk_datatype_from_base(&yld->_base,ctx);
}

kk_box_t kk_yield_reyield( kk_std_core_hnd__yield_info yldinfo, kk_context_t* ctx) {
  kk_assert_internal(!kk_yielding(ctx));
  yield_info_t yld = kk_datatype_as_assert(yield_info_t, yldinfo, (kk_tag_t)1, ctx);
  ctx->yield.clause = kk_function_dup(yld->clause,ctx);
  ctx->yield.marker = yld->marker;
  ctx->yield.conts_count = yld->conts_count;
  ctx->yielding = yld->yielding;
  for(kk_ssize_t i = 0; i < yld->conts_count; i++) {
    ctx->yield.conts[i] = kk_function_dup(yld->conts[i],ctx);
  }
  kk_constructor_drop(yld,ctx);
  return kk_box_any(ctx);
}


kk_std_core_hnd__htag kk_std_core_hnd_htag_fs__copy(kk_std_core_hnd__htag _this, kk_std_core_types__optional tagname, kk_context_t* _ctx) { /* forall<a> (htag<a>, tagname : ? string) -> htag<a> */ 
  kk_string_t _x_x309;
  if (kk_std_core_types__is_Optional(tagname, _ctx)) {
    kk_box_t _box_x0 = tagname._cons._Optional.value;
    kk_string_t _uniq_tagname_1886 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_tagname_1886, _ctx);
    kk_std_core_types__optional_drop(tagname, _ctx);
    kk_std_core_hnd__htag_drop(_this, _ctx);
    _x_x309 = _uniq_tagname_1886; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(tagname, _ctx);
    {
      kk_string_t _x = _this.tagname;
      _x_x309 = _x; /*string*/
    }
  }
  return kk_std_core_hnd__new_Htag(_x_x309, _ctx);
}

kk_std_core_hnd__ev kk_std_core_hnd_ev_fs__copy(kk_std_core_hnd__ev _this, kk_std_core_types__optional htag, int32_t marker, kk_box_t hnd, kk_evv_t hevv, kk_context_t* _ctx) { /* forall<a,e,b> (ev<a>, htag : ? (htag<a>), marker : marker<e,b>, hnd : a<e,b>, hevv : evv<e>) -> ev<a> */ 
  kk_std_core_hnd__htag _x_x311;
  if (kk_std_core_types__is_Optional(htag, _ctx)) {
    kk_box_t _box_x1 = htag._cons._Optional.value;
    kk_std_core_hnd__htag _uniq_htag_1987 = kk_std_core_hnd__htag_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_hnd__htag_dup(_uniq_htag_1987, _ctx);
    kk_std_core_types__optional_drop(htag, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(3)), _ctx);
    _x_x311 = _uniq_htag_1987; /*hnd/htag<2019>*/
  }
  else {
    kk_std_core_types__optional_drop(htag, _ctx);
    {
      struct kk_std_core_hnd_Ev* _con_x312 = kk_std_core_hnd__as_Ev(_this, _ctx);
      kk_std_core_hnd__htag _x = _con_x312->htag;
      kk_box_t _pat_1_0 = _con_x312->hnd;
      kk_evv_t _pat_2 = _con_x312->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_evv_drop(_pat_2, _ctx);
        kk_box_drop(_pat_1_0, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core_hnd__htag_dup(_x, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x311 = _x; /*hnd/htag<2019>*/
    }
  }
  return kk_std_core_hnd__new_Ev(kk_reuse_null, 0, _x_x311, marker, hnd, hevv, _ctx);
}
 
// Are two markers equal?

bool kk_std_core_hnd_eq_marker(int32_t x, int32_t y, kk_context_t* _ctx) { /* forall<a,b,e,e1> (x : marker<e,a>, y : marker<e1,b>) -> bool */ 
  return x==y;
}
 
// Evidence equality compares the markers.

bool kk_std_core_hnd_ev_fs__lp__eq__eq__rp_(kk_std_core_hnd__ev _pat_x141__18, kk_std_core_hnd__ev _pat_x141__37, kk_context_t* _ctx) { /* forall<a> (ev<a>, ev<a>) -> bool */ 
  {
    struct kk_std_core_hnd_Ev* _con_x313 = kk_std_core_hnd__as_Ev(_pat_x141__18, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x313->htag;
    int32_t m1 = _con_x313->marker;
    kk_box_t _pat_1 = _con_x313->hnd;
    kk_evv_t _pat_2 = _con_x313->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__18, _ctx)) {
      kk_evv_drop(_pat_2, _ctx);
      kk_box_drop(_pat_1, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(_pat_x141__18, _ctx);
    }
    else {
      kk_datatype_ptr_decref(_pat_x141__18, _ctx);
    }
    {
      struct kk_std_core_hnd_Ev* _con_x314 = kk_std_core_hnd__as_Ev(_pat_x141__37, _ctx);
      kk_std_core_hnd__htag _pat_4 = _con_x314->htag;
      int32_t m2 = _con_x314->marker;
      kk_box_t _pat_5 = _con_x314->hnd;
      kk_evv_t _pat_6 = _con_x314->hevv;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x141__37, _ctx)) {
        kk_evv_drop(_pat_6, _ctx);
        kk_box_drop(_pat_5, _ctx);
        kk_std_core_hnd__htag_drop(_pat_4, _ctx);
        kk_datatype_ptr_free(_pat_x141__37, _ctx);
      }
      else {
        kk_datatype_ptr_decref(_pat_x141__37, _ctx);
      }
      return kk_std_core_hnd_eq_marker(m1, m2, _ctx);
    }
  }
}

int32_t kk_std_core_hnd_fresh_marker(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return kk_marker_unique(kk_context());
}

int32_t kk_std_core_hnd_fresh_marker_named(kk_context_t* _ctx) { /* forall<a,e> () -> marker<e,a> */ 
  return -kk_marker_unique(kk_context());
}
 
// Insert new evidence into the given evidence vector.

kk_evv_t kk_std_core_hnd_evv_insert(kk_evv_t evv, kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<e,e1,a> (evv : evv<e>, ev : ev<a>) -> e evv<e1> */ 
  return kk_evv_insert(evv,ev,kk_context());
}
 
// show evidence for debug purposes

kk_string_t kk_std_core_hnd_evv_show(kk_evv_t evv, kk_context_t* _ctx) { /* forall<e> (evv : evv<e>) -> string */ 
  return kk_evv_show(evv,kk_context());
}
 
// Is an evidence vector unchanged? (i.e. as pointer equality).
// This is used to avoid copying in common cases.

bool kk_std_core_hnd_evv_eq(kk_evv_t evv0, kk_evv_t evv1, kk_context_t* _ctx) { /* forall<e> (evv0 : evv<e>, evv1 : evv<e>) -> bool */ 
  return kk_evv_eq(evv0,evv1,kk_context());
}
 
// (dynamically) find evidence insertion/deletion index in the evidence vector
// The compiler optimizes `@evv-index` to a static index when apparent from the effect type.

kk_ssize_t kk_std_core_hnd__evv_index(kk_std_core_hnd__htag htag, kk_context_t* _ctx) { /* forall<e,a> (htag : htag<a>) -> e ev-index */ 
  return kk_evv_index(htag,kk_context());
}
 
// Get the current evidence vector.

kk_evv_t kk_std_core_hnd_evv_get(kk_context_t* _ctx) { /* forall<e> () -> e evv<e> */ 
  return kk_evv_get(kk_context());
}
 
// Does the current evidence vector consist solely of affine handlers?
// This is called in backends that do not have context paths (like javascript)
// to optimize TRMC (where we can use faster update-in-place TRMC if we know the
// operations are all affine). As such, it is always safe to return `false`.
//
// control flow context:
//                 -1: none: bottom
//                   /
// 0: except: never resumes   1: linear: resumes exactly once
//                   \          /
//           2: affine: resumes never or once
//                        |
//     3: multi: resumes never, once, or multiple times
//

bool kk_std_core_hnd__evv_is_affine(kk_context_t* _ctx) { /* () -> bool */ 
  return kk_evv_is_affine(kk_context());
}
 
// Remove evidence at index `i` of the current evidence vector, and return the old one.
// (used by `mask`)

kk_evv_t kk_std_core_hnd_evv_swap_delete(kk_ssize_t i, bool behind, kk_context_t* _ctx) { /* forall<e,e1> (i : ev-index, behind : bool) -> e1 evv<e> */ 
  return kk_evv_swap_delete(i,behind,kk_context());
}
 
// Swap the current evidence vector with a new vector consisting of evidence
// at indices `indices` in the current vector.

kk_evv_t kk_std_core_hnd_evv_swap_create(kk_vector_t indices, kk_context_t* _ctx) { /* forall<e> (indices : vector<ev-index>) -> e evv<e> */ 
  return kk_evv_swap_create(indices,kk_context());
}

kk_box_t kk_std_core_hnd_yield_extend(kk_function_t next, kk_context_t* _ctx) { /* forall<a,b,e> (next : (a) -> e b) -> e b */ 
  return kk_yield_extend(next,kk_context());
}

kk_box_t kk_std_core_hnd_yield_cont(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,b> (f : forall<c> ((c) -> e a, c) -> e b) -> e b */ 
  return kk_yield_cont(f,kk_context());
}

kk_std_core_hnd__yld kk_std_core_hnd_yield_prompt(int32_t m, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>) -> yld<e,a,b> */ 
  return kk_yield_prompt(m,kk_context());
}

kk_function_t kk_std_core_hnd_yield_to_prim(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e (() -> a) */ 
  return kk_yield_to(m,clause,kk_context());
}

kk_box_t kk_std_core_hnd_yield_to_final(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,e1,b> (m : marker<e1,b>, clause : ((resume-result<a,b>) -> e1 b) -> e1 b) -> e a */ 
  return kk_yield_final(m,clause,kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_yield_to_fun315__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_yield_to_fun315(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_yield_to_fun315(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_yield_to_fun315, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_yield_to_fun315(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t _x_x316 = kk_function_unbox(_b_x3, _ctx); /*() -> 2786 4*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x316, (_x_x316, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_yield_to(int32_t m, kk_function_t clause, kk_context_t* _ctx) { /* forall<a,e,b> (m : marker<e,b>, clause : ((resume-result<a,b>) -> e b) -> e b) -> e a */ 
  kk_function_t g = kk_std_core_hnd_yield_to_prim(m, clause, _ctx); /*() -> 2785*/;
  kk_function_drop(g, _ctx);
  return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_yield_to_fun315(_ctx), _ctx);
}

kk_std_core_hnd__yield_info kk_std_core_hnd_yield_capture(kk_context_t* _ctx) { /* forall<e> () -> e yield-info */ 
  return kk_yield_capture(kk_context());
}

kk_box_t kk_std_core_hnd_unsafe_reyield(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) { /* forall<a,e> (yld : yield-info) -> e a */ 
  return kk_yield_reyield(yld,kk_context());
}

kk_unit_t kk_std_core_hnd_guard(kk_evv_t w, kk_context_t* _ctx) { /* forall<e> (w : evv<e>) -> e () */ 
  kk_evv_guard(w,kk_context()); return kk_Unit;
}

kk_box_t kk_std_core_hnd_resume_final(kk_context_t* _ctx) { /* forall<a> () -> a */ 
  return kk_fatal_resume_final(kk_context());
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun319__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun319(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun319(kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun319__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun319__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun319, kk_context());
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun319(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun319__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun319__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3484> */
  kk_function_t ret = _self->ret; /* (3482) -> 3483 3485 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3483> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3483> */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  kk_evv_t w0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
  kk_evv_t w1_sq_;
  bool _match_x265;
  kk_evv_t _x_x320 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3483>*/
  _match_x265 = kk_std_core_hnd_evv_eq(w0, _x_x320, _ctx); /*bool*/
  if (_match_x265) {
    w1_sq_ = w1; /*hnd/evv<3483>*/
  }
  else {
    kk_evv_drop(w1, _ctx);
    kk_evv_t _x_x321 = kk_evv_dup(w0_sq_, _ctx); /*hnd/evv<3483>*/
    kk_std_core_hnd__ev _x_x322 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
    w1_sq_ = kk_std_core_hnd_evv_insert(_x_x321, _x_x322, _ctx); /*hnd/evv<3483>*/
  }
  kk_unit_t ___1 = kk_Unit;
  kk_evv_t _x_x323 = kk_evv_dup(w1_sq_, _ctx); /*hnd/evv<3483>*/
  kk_evv_set(_x_x323,kk_context());
  kk_box_t _x_x324 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*3482*/
  return kk_std_core_hnd_prompt(w0_sq_, w1_sq_, ev, m, ret, _x_x324, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun325__t {
  struct kk_function_s _base;
  kk_function_t cont_0;
  kk_std_core_hnd__ev ev;
  kk_function_t ret;
  kk_evv_t w0;
  kk_evv_t w1;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun325(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun325(kk_function_t cont_0, kk_std_core_hnd__ev ev, kk_function_t ret, kk_evv_t w0, kk_evv_t w1, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun325__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun325__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun325, kk_context());
  _self->cont_0 = cont_0;
  _self->ev = ev;
  _self->ret = ret;
  _self->w0 = w0;
  _self->w1 = w1;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun331__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_prompt_fun331(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun331(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun331__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun331__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun331, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun331(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun331__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun331__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 3463 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  return x;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun332__t {
  struct kk_function_s _base;
  kk_box_t x_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun332(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun332(kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun332__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun332__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun332, kk_context());
  _self->x_0 = x_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun332(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun332__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun332__t*, _fself, _ctx);
  kk_box_t x_0 = _self->x_0; /* 3463 */
  kk_drop_match(_self, {kk_box_dup(x_0, _ctx);}, {}, _ctx)
  return x_0;
}


// lift anonymous function
struct kk_std_core_hnd_prompt_fun338__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
  int32_t m;
};
static kk_box_t kk_std_core_hnd_prompt_fun338(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun338(kk_box_t x_1_0, int32_t m, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun338__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun338__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun338, kk_context());
  _self->x_1_0 = x_1_0;
  _self->m = m;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_prompt_fun339__t {
  struct kk_function_s _base;
  kk_box_t x_1_0;
};
static kk_box_t kk_std_core_hnd_prompt_fun339(kk_function_t _fself, kk_function_t ___wildcard_x409__85, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_fun339(kk_box_t x_1_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun339__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_fun339__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_fun339, kk_context());
  _self->x_1_0 = x_1_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_fun339(kk_function_t _fself, kk_function_t ___wildcard_x409__85, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun339__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun339__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3485 */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x409__85, _ctx);
  return x_1_0;
}
static kk_box_t kk_std_core_hnd_prompt_fun338(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun338__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun338__t*, _fself, _ctx);
  kk_box_t x_1_0 = _self->x_1_0; /* 3485 */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_box_dup(x_1_0, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_prompt_fun339(x_1_0, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_prompt_fun325(kk_function_t _fself, kk_std_core_hnd__resume_result r, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_fun325__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_fun325__t*, _fself, _ctx);
  kk_function_t cont_0 = _self->cont_0; /* (() -> 3463) -> 3483 3482 */
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<3484> */
  kk_function_t ret = _self->ret; /* (3482) -> 3483 3485 */
  kk_evv_t w0 = _self->w0; /* hnd/evv<3483> */
  kk_evv_t w1 = _self->w1; /* hnd/evv<3483> */
  int32_t m = _self->m; /* hnd/marker<3483,3485> */
  kk_drop_match(_self, {kk_function_dup(cont_0, _ctx);kk_std_core_hnd__ev_dup(ev, _ctx);kk_function_dup(ret, _ctx);kk_evv_dup(w0, _ctx);kk_evv_dup(w1, _ctx);kk_skip_dup(m, _ctx);}, {}, _ctx)
  if (kk_std_core_hnd__is_Deep(r, _ctx)) {
    kk_box_t x = r._cons.Deep.result;
    kk_evv_t w0_0_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
    kk_evv_t w1_0_sq_;
    bool _match_x264;
    kk_evv_t _x_x326 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3483>*/
    _match_x264 = kk_std_core_hnd_evv_eq(w0, _x_x326, _ctx); /*bool*/
    if (_match_x264) {
      w1_0_sq_ = w1; /*hnd/evv<3483>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x327 = kk_evv_dup(w0_0_sq_, _ctx); /*hnd/evv<3483>*/
      kk_std_core_hnd__ev _x_x328 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
      w1_0_sq_ = kk_std_core_hnd_evv_insert(_x_x327, _x_x328, _ctx); /*hnd/evv<3483>*/
    }
    kk_unit_t ___2 = kk_Unit;
    kk_evv_t _x_x329 = kk_evv_dup(w1_0_sq_, _ctx); /*hnd/evv<3483>*/
    kk_evv_set(_x_x329,kk_context());
    kk_box_t _x_x330 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun331(x, _ctx), _ctx), _ctx); /*3482*/
    return kk_std_core_hnd_prompt(w0_0_sq_, w1_0_sq_, ev, m, ret, _x_x330, _ctx);
  }
  if (kk_std_core_hnd__is_Shallow(r, _ctx)) {
    kk_box_t x_0 = r._cons.Shallow.result;
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_box_t x_1_10002 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun332(x_0, _ctx), _ctx), _ctx); /*3482*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_1_10002, _ctx);
      return kk_std_core_hnd_yield_extend(ret, _ctx);
    }
    {
      return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, x_1_10002, _ctx), _ctx);
    }
  }
  {
    kk_box_t x_1_0 = r._cons.Finalize.result;
    kk_evv_t w0_1_sq_ = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3483>*/;
    kk_evv_t w1_1_sq_;
    bool _match_x262;
    kk_evv_t _x_x333 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3483>*/
    _match_x262 = kk_std_core_hnd_evv_eq(w0, _x_x333, _ctx); /*bool*/
    if (_match_x262) {
      w1_1_sq_ = w1; /*hnd/evv<3483>*/
    }
    else {
      kk_evv_drop(w1, _ctx);
      kk_evv_t _x_x334 = kk_evv_dup(w0_1_sq_, _ctx); /*hnd/evv<3483>*/
      kk_std_core_hnd__ev _x_x335 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3484>*/
      w1_1_sq_ = kk_std_core_hnd_evv_insert(_x_x334, _x_x335, _ctx); /*hnd/evv<3483>*/
    }
    kk_unit_t ___3 = kk_Unit;
    kk_evv_t _x_x336 = kk_evv_dup(w1_1_sq_, _ctx); /*hnd/evv<3483>*/
    kk_evv_set(_x_x336,kk_context());
    kk_box_t _x_x337 = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), cont_0, (cont_0, kk_std_core_hnd_new_prompt_fun338(x_1_0, m, _ctx), _ctx), _ctx); /*3482*/
    return kk_std_core_hnd_prompt(w0_1_sq_, w1_1_sq_, ev, m, ret, _x_x337, _ctx);
  }
}

kk_box_t kk_std_core_hnd_prompt(kk_evv_t w0, kk_evv_t w1, kk_std_core_hnd__ev ev, int32_t m, kk_function_t ret, kk_box_t result, kk_context_t* _ctx) { /* forall<a,e,b,c> (w0 : evv<e>, w1 : evv<e>, ev : ev<b>, m : marker<e,c>, ret : (a) -> e c, result : a) -> e c */ 
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x317 = kk_evv_dup(w1, _ctx); /*hnd/evv<3483>*/
  kk_std_core_hnd_guard(_x_x317, _ctx);
  kk_unit_t ___0 = kk_Unit;
  kk_evv_t _x_x318 = kk_evv_dup(w0, _ctx); /*hnd/evv<3483>*/
  kk_evv_set(_x_x318,kk_context());
  kk_std_core_hnd__yld _match_x261 = kk_std_core_hnd_yield_prompt(m, _ctx); /*hnd/yld<2611,2610,2612>*/;
  if (kk_std_core_hnd__is_Pure(_match_x261, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), ret, (ret, result, _ctx), _ctx);
  }
  if (kk_std_core_hnd__is_YieldingFinal(_match_x261, _ctx)) {
    kk_evv_drop(w1, _ctx);
    kk_evv_drop(w0, _ctx);
    kk_function_drop(ret, _ctx);
    kk_box_drop(result, _ctx);
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return kk_box_any(kk_context());
  }
  if (kk_std_core_hnd__is_Yielding(_match_x261, _ctx)) {
    kk_box_drop(result, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_fun319(ev, ret, w0, w1, m, _ctx), _ctx);
  }
  {
    kk_function_t clause = _match_x261._cons.Yield.clause;
    kk_function_t cont_0 = _match_x261._cons.Yield.cont;
    kk_box_drop(result, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), clause, (clause, kk_std_core_hnd_new_prompt_fun325(cont_0, ev, ret, w0, w1, m, _ctx), _ctx), _ctx);
  }
}

kk_box_t kk_std_core_hnd__hhandle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : () -> e1 a) -> e c */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3613>*/;
  int32_t m = kk_std_core_hnd_fresh_marker(_ctx); /*hnd/marker<3613,3616>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x340 = kk_evv_dup(w0, _ctx); /*hnd/evv<3613>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x340, _ctx); /*hnd/ev<3615>*/
  kk_evv_t w1;
  kk_evv_t _x_x341 = kk_evv_dup(w0, _ctx); /*hnd/evv<3613>*/
  kk_std_core_hnd__ev _x_x342 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3615>*/
  w1 = kk_std_core_hnd_evv_insert(_x_x341, _x_x342, _ctx); /*hnd/evv<3613>*/
  kk_unit_t __ = kk_Unit;
  kk_evv_t _x_x343 = kk_evv_dup(w1, _ctx); /*hnd/evv<3613>*/
  kk_evv_set(_x_x343,kk_context());
  kk_box_t _x_x344 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*3612*/
  return kk_std_core_hnd_prompt(w0, w1, ev, m, ret, _x_x344, _ctx);
}

kk_box_t kk_std_core_hnd__named_handle(kk_std_core_hnd__htag tag, kk_box_t h, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (tag : htag<b>, h : b<e,c>, ret : (a) -> e c, action : (ev<b>) -> e1 a) -> e c */ 
  int32_t m = kk_std_core_hnd_fresh_marker_named(_ctx); /*hnd/marker<3729,3732>*/;
  kk_evv_t w0 = kk_std_core_hnd_evv_get(_ctx); /*hnd/evv<3729>*/;
  kk_std_core_hnd__ev ev;
  kk_evv_t _x_x345 = kk_evv_dup(w0, _ctx); /*hnd/evv<3729>*/
  ev = kk_std_core_hnd__new_Ev(kk_reuse_null, 0, tag, m, h, _x_x345, _ctx); /*hnd/ev<3731>*/
  kk_evv_t _x_x346 = kk_evv_dup(w0, _ctx); /*hnd/evv<3729>*/
  kk_std_core_hnd__ev _x_x347 = kk_std_core_hnd__ev_dup(ev, _ctx); /*hnd/ev<3731>*/
  kk_box_t _x_x348 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__ev, kk_context_t*), action, (action, ev, _ctx), _ctx); /*3728*/
  return kk_std_core_hnd_prompt(_x_x346, w0, _x_x347, m, ret, _x_x348, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_mask_at1_fun349__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd_mask_at1_fun349(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_mask_at1_fun349(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun349__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_mask_at1_fun349__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_mask_at1_fun349, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_mask_at1_fun349(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_mask_at1_fun349__t* _self = kk_function_as(struct kk_std_core_hnd_mask_at1_fun349__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_mask_at1(kk_ssize_t i, bool behind, kk_function_t action, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, behind : bool, action : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_3757>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), action, (action, x, _ctx), _ctx); /*3862*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_mask_at1_fun349(i, behind, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__mask_at_fun350__t {
  struct kk_function_s _base;
  kk_ssize_t i;
  bool behind;
};
static kk_box_t kk_std_core_hnd__mask_at_fun350(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_mask_at_fun350(kk_ssize_t i, bool behind, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun350__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__mask_at_fun350__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__mask_at_fun350, kk_context());
  _self->i = i;
  _self->behind = behind;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__mask_at_fun350(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__mask_at_fun350__t* _self = kk_function_as(struct kk_std_core_hnd__mask_at_fun350__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  bool behind = _self->behind; /* bool */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);kk_skip_dup(behind, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_mask_at1(i, behind, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__mask_at(kk_ssize_t i, bool behind, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, behind : bool, action : () -> e a) -> e1 a */ 
  kk_evv_t w0 = kk_std_core_hnd_evv_swap_delete(i, behind, _ctx); /*hnd/evv<_3885>*/;
  kk_box_t x = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*3974*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(x, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_mask_at_fun350(i, behind, _ctx), _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_core_hnd_prompt_local_var_fun352__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_box_t v;
};
static kk_box_t kk_std_core_hnd_prompt_local_var_fun352(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_prompt_local_var_fun352(kk_ref_t loc, kk_box_t v, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun352__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_prompt_local_var_fun352__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_prompt_local_var_fun352, kk_context());
  _self->loc = loc;
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_prompt_local_var_fun352(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_prompt_local_var_fun352__t* _self = kk_function_as(struct kk_std_core_hnd_prompt_local_var_fun352__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<4163,4161> */
  kk_box_t v = _self->v; /* 4161 */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_unit_t ___0 = kk_Unit;
  kk_ref_set_borrow(loc,v,kk_context());
  kk_box_t _x_x353 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4162*/
  return kk_std_core_hnd_prompt_local_var(loc, _x_x353, _ctx);
}

kk_box_t kk_std_core_hnd_prompt_local_var(kk_ref_t loc, kk_box_t res, kk_context_t* _ctx) { /* forall<a,b,h> (loc : local-var<h,a>, res : b) -> <div,local<h>> b */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_box_t v;
    kk_ref_t _x_x351 = kk_ref_dup(loc, _ctx); /*local-var<4163,4161>*/
    v = kk_ref_get(_x_x351,kk_context()); /*4161*/
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_prompt_local_var_fun352(loc, v, _ctx), _ctx);
  }
  {
    kk_ref_drop(loc, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun355__t {
  struct kk_function_s _base;
  kk_function_t fin;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun355(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun355(kk_function_t fin, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun355__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun355__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun355, kk_context());
  _self->fin = fin;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun355(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun355__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun355__t*, _fself, _ctx);
  kk_function_t fin = _self->fin; /* () -> 4415 () */
  kk_drop_match(_self, {kk_function_dup(fin, _ctx);}, {}, _ctx)
  kk_box_t _x_x356 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4414*/
  return kk_std_core_hnd_finally_prompt(fin, _x_x356, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun357__t {
  struct kk_function_s _base;
  kk_std_core_hnd__yield_info yld;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun357(kk_function_t _fself, kk_box_t ___wildcard_x490__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun357(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun357__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun357__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun357, kk_context());
  _self->yld = yld;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun357(kk_function_t _fself, kk_box_t ___wildcard_x490__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun357__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun357__t*, _fself, _ctx);
  kk_std_core_hnd__yield_info yld = _self->yld; /* hnd/yield-info */
  kk_drop_match(_self, {kk_std_core_hnd__yield_info_dup(yld, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x490__43, _ctx);
  return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_finally_prompt_fun358__t {
  struct kk_function_s _base;
  kk_box_t res;
};
static kk_box_t kk_std_core_hnd_finally_prompt_fun358(kk_function_t _fself, kk_box_t ___wildcard_x483__40, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_finally_prompt_fun358(kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun358__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_finally_prompt_fun358__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_finally_prompt_fun358, kk_context());
  _self->res = res;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_finally_prompt_fun358(kk_function_t _fself, kk_box_t ___wildcard_x483__40, kk_context_t* _ctx) {
  struct kk_std_core_hnd_finally_prompt_fun358__t* _self = kk_function_as(struct kk_std_core_hnd_finally_prompt_fun358__t*, _fself, _ctx);
  kk_box_t res = _self->res; /* 4414 */
  kk_drop_match(_self, {kk_box_dup(res, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x483__40, _ctx);
  return res;
}

kk_box_t kk_std_core_hnd_finally_prompt(kk_function_t fin, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (fin : () -> e (), res : a) -> e a */ 
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    bool _match_x257 = kk_yielding_non_final(kk_context()); /*bool*/;
    if (_match_x257) {
      return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_finally_prompt_fun355(fin, _ctx), _ctx);
    }
    {
      kk_std_core_hnd__yield_info yld = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
      kk_unit_t ___0 = kk_Unit;
      kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_finally_prompt_fun357(yld, _ctx), _ctx);
      }
      {
        return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
      }
    }
  }
  {
    kk_unit_t __ = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), fin, (fin, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_finally_prompt_fun358(res, _ctx), _ctx);
    }
    {
      return res;
    }
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun360__t {
  struct kk_function_s _base;
  kk_ref_t count;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun360(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun360(kk_ref_t count, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun360__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun360__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun360, kk_context());
  _self->count = count;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_initially_prompt_fun366__t {
  struct kk_function_s _base;
  kk_function_t cont;
  kk_function_t init;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_initially_prompt_fun366(kk_function_t _fself, kk_box_t ___wildcard_x531__35, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_prompt_fun366(kk_function_t cont, kk_function_t init, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun366__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_prompt_fun366__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_prompt_fun366, kk_context());
  _self->cont = cont;
  _self->init = init;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_prompt_fun366(kk_function_t _fself, kk_box_t ___wildcard_x531__35, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun366__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun366__t*, _fself, _ctx);
  kk_function_t cont = _self->cont; /* (4636) -> 4650 4649 */
  kk_function_t init = _self->init; /* (int) -> 4650 () */
  kk_box_t x = _self->x; /* 4636 */
  kk_drop_match(_self, {kk_function_dup(cont, _ctx);kk_function_dup(init, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x531__35, _ctx);
  kk_box_t _x_x367 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4649*/
  return kk_std_core_hnd_initially_prompt(init, _x_x367, _ctx);
}
static kk_box_t kk_std_core_hnd_initially_prompt_fun360(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_prompt_fun360__t* _self = kk_function_as(struct kk_std_core_hnd_initially_prompt_fun360__t*, _fself, _ctx);
  kk_ref_t count = _self->count; /* ref<global,int> */
  kk_function_t init = _self->init; /* (int) -> 4650 () */
  kk_drop_match(_self, {kk_ref_dup(count, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_integer_t cnt;
  kk_box_t _x_x361;
  kk_ref_t _x_x362 = kk_ref_dup(count, _ctx); /*ref<global,int>*/
  _x_x361 = kk_ref_get(_x_x362,kk_context()); /*212*/
  cnt = kk_integer_unbox(_x_x361, _ctx); /*int*/
  kk_integer_t _b_x14_16;
  kk_integer_t _x_x363 = kk_integer_dup(cnt, _ctx); /*int*/
  _b_x14_16 = kk_integer_add(_x_x363,(kk_integer_from_small(1)),kk_context()); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x255 = kk_Unit;
  kk_ref_set_borrow(count,(kk_integer_box(_b_x14_16, _ctx)),kk_context());
  kk_ref_drop(count, _ctx);
  _brw_x255;
  kk_unit_t ___1 = kk_Unit;
  bool _match_x253 = kk_integer_eq_borrow(cnt,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x253) {
    kk_integer_drop(cnt, _ctx);
  }
  else {
    kk_unit_t r = kk_Unit;
    kk_function_t _x_x364 = kk_function_dup(init, _ctx); /*(int) -> 4650 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x364, (_x_x364, cnt, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t ___0;
      kk_function_t _x_x365;
      kk_function_dup(cont, _ctx);
      kk_function_dup(init, _ctx);
      kk_box_dup(x, _ctx);
      _x_x365 = kk_std_core_hnd_new_initially_prompt_fun366(cont, init, x, _ctx); /*(_4583) -> 4650 4649*/
      ___0 = kk_std_core_hnd_yield_extend(_x_x365, _ctx); /*4649*/
      kk_box_drop(___0, _ctx);
    }
    else {
      
    }
  }
  kk_box_t _x_x368 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*4649*/
  return kk_std_core_hnd_initially_prompt(init, _x_x368, _ctx);
}

kk_box_t kk_std_core_hnd_initially_prompt(kk_function_t init, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), res : a) -> e a */ 
  bool _match_x252 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x252) {
    kk_box_drop(res, _ctx);
    kk_ref_t count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*ref<global,int>*/;
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_initially_prompt_fun360(count, init, _ctx), _ctx);
  }
  {
    kk_function_drop(init, _ctx);
    return res;
  }
}


// lift anonymous function
struct kk_std_core_hnd_initially_fun370__t {
  struct kk_function_s _base;
  kk_function_t action;
  kk_function_t init;
};
static kk_box_t kk_std_core_hnd_initially_fun370(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_initially_fun370(kk_function_t action, kk_function_t init, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun370__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_initially_fun370__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_initially_fun370, kk_context());
  _self->action = action;
  _self->init = init;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_initially_fun370(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_std_core_hnd_initially_fun370__t* _self = kk_function_as(struct kk_std_core_hnd_initially_fun370__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> 4715 4714 */
  kk_function_t init = _self->init; /* (int) -> 4715 () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);kk_function_dup(init, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x18, _ctx);
  kk_box_t _x_x371 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4714*/
  return kk_std_core_hnd_initially_prompt(init, _x_x371, _ctx);
}

kk_box_t kk_std_core_hnd_initially(kk_function_t init, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (init : (int) -> e (), action : () -> e a) -> e a */ 
  kk_unit_t __ = kk_Unit;
  kk_function_t _x_x369 = kk_function_dup(init, _ctx); /*(int) -> 4715 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x369, (_x_x369, kk_integer_from_small(0), _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_initially_fun370(action, init, _ctx), _ctx);
  }
  {
    kk_box_t _x_x372 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*4714*/
    return kk_std_core_hnd_initially_prompt(init, _x_x372, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_resume_context_fs__copy_fun374__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x24;
};
static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun374(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_resume_context_fs__new_copy_fun374(kk_box_t _fun_unbox_x24, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun374__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_resume_context_fs__copy_fun374__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_resume_context_fs__copy_fun374, kk_context());
  _self->_fun_unbox_x24 = _fun_unbox_x24;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_resume_context_fs__copy_fun374(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x27, kk_context_t* _ctx) {
  struct kk_std_core_hnd_resume_context_fs__copy_fun374__t* _self = kk_function_as(struct kk_std_core_hnd_resume_context_fs__copy_fun374__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x24 = _self->_fun_unbox_x24; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x24, _ctx);}, {}, _ctx)
  kk_function_t _x_x375 = kk_function_unbox(_fun_unbox_x24, _ctx); /*(25) -> 4834 26*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x375, (_x_x375, kk_std_core_hnd__resume_result_box(_b_x27, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__resume_context kk_std_core_hnd_resume_context_fs__copy(kk_std_core_hnd__resume_context _this, kk_std_core_types__optional k, kk_context_t* _ctx) { /* forall<a,e,e1,b> (resume-context<a,e,e1,b>, k : ? ((resume-result<a,b>) -> e b)) -> resume-context<a,e,e1,b> */ 
  kk_function_t _x_x373;
  if (kk_std_core_types__is_Optional(k, _ctx)) {
    kk_box_t _fun_unbox_x24 = k._cons._Optional.value;
    kk_box_dup(_fun_unbox_x24, _ctx);
    kk_std_core_types__optional_drop(k, _ctx);
    kk_std_core_hnd__resume_context_drop(_this, _ctx);
    _x_x373 = kk_std_core_hnd_resume_context_fs__new_copy_fun374(_fun_unbox_x24, _ctx); /*(hnd/resume-result<4833,4836>) -> 4834 26*/
  }
  else {
    kk_std_core_types__optional_drop(k, _ctx);
    {
      kk_function_t _x = _this.k;
      _x_x373 = _x; /*(hnd/resume-result<4833,4836>) -> 4834 26*/
    }
  }
  return kk_std_core_hnd__new_Resume_context(_x_x373, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause1_fs__copy_fun380__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x35;
};
static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun380(kk_function_t _fself, int32_t _b_x40, kk_std_core_hnd__ev _b_x41, kk_box_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause1_fs__new_copy_fun380(kk_box_t _fun_unbox_x35, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun380__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause1_fs__copy_fun380__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause1_fs__copy_fun380, kk_context());
  _self->_fun_unbox_x35 = _fun_unbox_x35;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause1_fs__copy_fun380(kk_function_t _fself, int32_t _b_x40, kk_std_core_hnd__ev _b_x41, kk_box_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause1_fs__copy_fun380__t* _self = kk_function_as(struct kk_std_core_hnd_clause1_fs__copy_fun380__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x35 = _self->_fun_unbox_x35; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x35, _ctx);}, {}, _ctx)
  kk_function_t _x_x381 = kk_function_unbox(_fun_unbox_x35, _ctx); /*(36, 37, 38) -> 5200 39*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x381, (_x_x381, kk_int32_box(_b_x40, _ctx), kk_std_core_hnd__ev_box(_b_x41, _ctx), _b_x42, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause1_fs__copy(kk_std_core_hnd__clause1 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (clause1<a,b,c,e,d>, clause : ? ((marker<e,d>, ev<c>, a) -> e b)) -> clause1<a,b,c,e,d> */ 
  kk_function_t _x_x379;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x35 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x35, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause1_drop(_this, _ctx);
    _x_x379 = kk_std_core_hnd_clause1_fs__new_copy_fun380(_fun_unbox_x35, _ctx); /*(hnd/marker<5200,5201>, hnd/ev<5199>, 5197) -> 5200 39*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x379 = _x; /*(hnd/marker<5200,5201>, hnd/ev<5199>, 5197) -> 5200 39*/
    }
  }
  return kk_std_core_hnd__new_Clause1(_x_x379, _ctx);
}

kk_evv_t kk_std_core_hnd_evv_swap_with(kk_std_core_hnd__ev ev, kk_context_t* _ctx) { /* forall<a,e> (ev : ev<a>) -> evv<e> */ 
  kk_evv_t _x_x383;
  {
    struct kk_std_core_hnd_Ev* _con_x384 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_std_core_hnd__htag _pat_0 = _con_x384->htag;
    kk_box_t _pat_2 = _con_x384->hnd;
    kk_evv_t w = _con_x384->hevv;
    if kk_likely(kk_datatype_ptr_is_unique(ev, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_std_core_hnd__htag_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ev, _ctx);
    }
    else {
      kk_evv_dup(w, _ctx);
      kk_datatype_ptr_decref(ev, _ctx);
    }
    _x_x383 = w; /*hnd/evv<5350>*/
  }
  return kk_evv_swap(_x_x383,kk_context());
}
 
// extra under1x to make under1 inlineable


// lift anonymous function
struct kk_std_core_hnd_under1x_fun387__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under1x_fun387(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under1x_fun387(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun387__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under1x_fun387__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under1x_fun387, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under1x_fun387(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1x_fun387__t* _self = kk_function_as(struct kk_std_core_hnd_under1x_fun387__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5473> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_under1x(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,c> (ev : ev<c>, op : (a) -> e b, x : a) -> e b */ 
  kk_evv_t w0;
  kk_evv_t _x_x385;
  {
    struct kk_std_core_hnd_Ev* _con_x386 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x386->hevv;
    kk_evv_dup(w, _ctx);
    _x_x385 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x385,kk_context()); /*hnd/evv<_5384>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*5471*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under1x_fun387(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}
extern kk_box_t kk_std_core_hnd_under1_fun390(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under1_fun390__t* _self = kk_function_as(struct kk_std_core_hnd_under1_fun390__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<5586> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun391__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun391(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x598__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun391(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun391__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun391__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun391, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw1_fun392__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun392(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw1_fun392(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun392__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw1_fun392__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw1_fun392, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw1_fun392(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun392__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun392__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5684, r : hnd/resume-context<5685,5686,5687,5689>) -> 5686 5689 */
  kk_box_t x = _self->x; /* 5684 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x393 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x, _x_x393, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw1_fun391(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x598__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw1_fun391__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw1_fun391__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x : 5684, r : hnd/resume-context<5685,5686,5687,5689>) -> 5686 5689 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x598__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw1_fun392(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,e1,c,d> (op : (x : a, r : resume-context<b,e,e1,d>) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw1_fun391(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect_prompt_fun396__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_prompt_fun396(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_prompt_fun396(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun396__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_prompt_fun396__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_prompt_fun396, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_prompt_fun396(kk_function_t _fself, kk_function_t cont, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun396__t* _self = kk_function_as(struct kk_std_core_hnd_protect_prompt_fun396__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<5936,5938>) -> 5937 5938 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_box_t _x_x397 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, x, _ctx), _ctx); /*5938*/
  return kk_std_core_hnd_protect_prompt(resumed, k, _x_x397, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_protect_prompt_fun399__t {
  struct kk_function_s _base;
  kk_std_core_hnd__yield_info yld;
};
static kk_box_t kk_std_core_hnd_protect_prompt_fun399(kk_function_t _fself, kk_box_t ___wildcard_x621__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_prompt_fun399(kk_std_core_hnd__yield_info yld, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun399__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_prompt_fun399__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_prompt_fun399, kk_context());
  _self->yld = yld;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_prompt_fun399(kk_function_t _fself, kk_box_t ___wildcard_x621__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_prompt_fun399__t* _self = kk_function_as(struct kk_std_core_hnd_protect_prompt_fun399__t*, _fself, _ctx);
  kk_std_core_hnd__yield_info yld = _self->yld; /* hnd/yield-info */
  kk_drop_match(_self, {kk_std_core_hnd__yield_info_dup(yld, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x621__43, _ctx);
  return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
}

kk_box_t kk_std_core_hnd_protect_prompt(kk_ref_t resumed, kk_function_t k, kk_box_t res, kk_context_t* _ctx) { /* forall<a,e,b> (resumed : ref<global,bool>, k : (resume-result<a,b>) -> e b, res : b) -> e b */ 
  bool did_resume;
  kk_box_t _x_x394;
  kk_ref_t _x_x395 = kk_ref_dup(resumed, _ctx); /*ref<global,bool>*/
  _x_x394 = kk_ref_get(_x_x395,kk_context()); /*212*/
  did_resume = kk_bool_unbox(_x_x394); /*bool*/
  if (did_resume) {
    kk_ref_drop(resumed, _ctx);
    kk_function_drop(k, _ctx);
    return res;
  }
  if (kk_yielding(kk_context())) {
    bool _match_x246 = kk_yielding_non_final(kk_context()); /*bool*/;
    if (_match_x246) {
      kk_box_drop(res, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_protect_prompt_fun396(k, resumed, _ctx), _ctx);
    }
    {
      kk_ref_drop(resumed, _ctx);
      kk_std_core_hnd__yield_info yld = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
      kk_box_t __;
      kk_std_core_hnd__resume_result _x_x398 = kk_std_core_hnd__new_Finalize(res, _ctx); /*hnd/resume-result<74,75>*/
      __ = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x398, _ctx), _ctx); /*5938*/
      kk_box_drop(__, _ctx);
      if (kk_yielding(kk_context())) {
        return kk_std_core_hnd_yield_extend(kk_std_core_hnd_new_protect_prompt_fun399(yld, _ctx), _ctx);
      }
      {
        return kk_std_core_hnd_unsafe_reyield(yld, _ctx);
      }
    }
  }
  {
    kk_ref_drop(resumed, _ctx);
    kk_std_core_hnd__resume_result _x_x400 = kk_std_core_hnd__new_Finalize(res, _ctx); /*hnd/resume-result<74,75>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x400, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect_fun402__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect_fun402(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect_fun402(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun402__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect_fun402__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect_fun402, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect_fun402(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect_fun402__t* _self = kk_function_as(struct kk_std_core_hnd_protect_fun402__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6056,6058>) -> 6057 6058 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x245 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x245;
  kk_std_core_hnd__resume_result _x_x403 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x403, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_protect(kk_box_t x, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,e,c> (x : a, clause : (x : a, k : (b) -> e c) -> e c, k : (resume-result<b,c>) -> e c) -> e c */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x401;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x401 = kk_std_core_hnd_new_protect_fun402(k, resumed, _ctx); /*(ret : 6056) -> 6057 6058*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x, _x_x401, _ctx), _ctx); /*6058*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun405(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun405__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun405__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 6148, k : (6149) -> 6150 6152) -> 6150 6152 */
  kk_box_t x = _self->x; /* 6148 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect(x, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control1_fun404(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x639__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control1_fun404__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control1_fun404__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x : 6148, k : (6149) -> 6150 6152) -> 6150 6152 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x639__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control1_fun405(clause, x, _ctx), _ctx);
}
 
// tail-resumptive clause: resumes exactly once at the end
// (these can be executed 'in-place' without capturing a resumption)


// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun406__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun406(kk_function_t _fself, int32_t ___wildcard_x644__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun406(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun406__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun406__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun406, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail1_fun409__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail1_fun409(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail1_fun409(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun409__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail1_fun409__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail1_fun409, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail1_fun409(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun409__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun409__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6235> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail1_fun406(kk_function_t _fself, int32_t ___wildcard_x644__14, kk_std_core_hnd__ev ev, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail1_fun406__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail1_fun406__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6236) -> 6233 6237 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x407;
  {
    struct kk_std_core_hnd_Ev* _con_x408 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x408->hevv;
    kk_evv_dup(w, _ctx);
    _x_x407 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x407,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx); /*6237*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail1_fun409(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail1(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d> (op : (c) -> e d) -> clause1<c,d,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail1_fun406(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop1_fun410(kk_function_t _fself, int32_t ___wildcard_x649__14, kk_std_core_hnd__ev ___wildcard_x649__17, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop1_fun410__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop1_fun410__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6307) -> 6304 6308 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x649__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
 
// clause that never resumes (e.g. an exception handler)
// (these do not need to capture a resumption and execute finally clauses upfront)


// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun411__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun411(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun411(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun411__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun411__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun411, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never1_fun412__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x;
};
static kk_box_t kk_std_core_hnd_clause_never1_fun412(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never1_fun412(kk_function_t op, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun412__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never1_fun412__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never1_fun412, kk_context());
  _self->op = op;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never1_fun412(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun412__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun412__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6391) -> 6393 6395 */
  kk_box_t x = _self->x; /* 6391 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x654__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), op, (op, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never1_fun411(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never1_fun411__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never1_fun411__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (6391) -> 6393 6395 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x654__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never1_fun412(op, x, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never1(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,e,c,d> (op : (a) -> e d) -> clause1<a,b,c,e,d> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never1_fun411(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause0_fs__copy_fun414__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x58;
};
static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun414(kk_function_t _fself, int32_t _b_x62, kk_std_core_hnd__ev _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause0_fs__new_copy_fun414(kk_box_t _fun_unbox_x58, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun414__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause0_fs__copy_fun414__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause0_fs__copy_fun414, kk_context());
  _self->_fun_unbox_x58 = _fun_unbox_x58;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause0_fs__copy_fun414(kk_function_t _fself, int32_t _b_x62, kk_std_core_hnd__ev _b_x63, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause0_fs__copy_fun414__t* _self = kk_function_as(struct kk_std_core_hnd_clause0_fs__copy_fun414__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x58 = _self->_fun_unbox_x58; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x58, _ctx);}, {}, _ctx)
  kk_function_t _x_x415 = kk_function_unbox(_fun_unbox_x58, _ctx); /*(59, 60) -> 6525 61*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x415, (_x_x415, kk_int32_box(_b_x62, _ctx), kk_std_core_hnd__ev_box(_b_x63, _ctx), _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause0_fs__copy(kk_std_core_hnd__clause0 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,e,c> (clause0<a,b,e,c>, clause : ? ((marker<e,c>, ev<b>) -> e a)) -> clause0<a,b,e,c> */ 
  kk_function_t _x_x413;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x58 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x58, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause0_drop(_this, _ctx);
    _x_x413 = kk_std_core_hnd_clause0_fs__new_copy_fun414(_fun_unbox_x58, _ctx); /*(hnd/marker<6525,6526>, hnd/ev<6524>) -> 6525 61*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x413 = _x; /*(hnd/marker<6525,6526>, hnd/ev<6524>) -> 6525 61*/
    }
  }
  return kk_std_core_hnd__new_Clause0(_x_x413, _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun422(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun422__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun422__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6717> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
extern kk_box_t kk_std_core_hnd_under0_fun419(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under0_fun419__t* _self = kk_function_as(struct kk_std_core_hnd_under0_fun419__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6717> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x420;
  {
    struct kk_std_core_hnd_Ev* _con_x421 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x421->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x420 = w_0; /*hnd/evv<5350>*/
  }
  w0_0 = kk_evv_swap(_x_x420,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6715*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under0_fun422(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun423__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun423(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x680__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun423(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun423__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun423__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun423, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw0_fun424__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun424(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw0_fun424(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun424__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw0_fun424__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw0_fun424, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw0_fun424(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun424__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun424__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6803,6804,6805,6807>) -> 6804 6807 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x425 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, _x_x425, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw0_fun423(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x680__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw0_fun423__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw0_fun423__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (hnd/resume-context<6803,6804,6805,6807>) -> 6804 6807 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x680__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw0_fun424(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control_raw0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,e1,b,c> (op : (resume-context<a,e,e1,c>) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control_raw0_fun423(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun426__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun426(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x688__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun426(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun426__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun426__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun426, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun427__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun427(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun427(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun427__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun427__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun427, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control0_fun429__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control0_fun429(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control0_fun429(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun429__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control0_fun429__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control0_fun429, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control0_fun429(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun429__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun429__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<6896,6899>) -> 6897 6899 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x240 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x240;
  kk_std_core_hnd__resume_result _x_x430 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x430, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control0_fun427(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun427__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun427__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6896) -> 6897 6899) -> 6897 6899 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x428;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x428 = kk_std_core_hnd_new_clause_control0_fun429(k, resumed, _ctx); /*(ret : 6896) -> 6897 6899*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_function_t, kk_context_t*), op, (op, _x_x428, _ctx), _ctx); /*6899*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control0_fun426(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x688__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control0_fun426__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control0_fun426__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* ((6896) -> 6897 6899) -> 6897 6899 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x688__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control0_fun427(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_control0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : ((a) -> e c) -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_control0_fun426(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun431__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun431(kk_function_t _fself, int32_t ___wildcard_x692__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun431(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun431__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun431__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun431, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun434__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun434(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun434(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun434__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun434__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun434, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail0_fun437__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_clause_tail0_fun437(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail0_fun437(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun437__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail0_fun437__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail0_fun437, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail0_fun437(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun437__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun437__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6967> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun434(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun434__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun434__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<6967> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x435;
  {
    struct kk_std_core_hnd_Ev* _con_x436 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x436->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x435 = w_0; /*hnd/evv<5350>*/
  }
  w0_0 = kk_evv_swap(_x_x435,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y_0 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*6968*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y_0, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun437(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y_0;
  }
}
static kk_box_t kk_std_core_hnd_clause_tail0_fun431(kk_function_t _fself, int32_t ___wildcard_x692__14, kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail0_fun431__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail0_fun431__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 6965 6968 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x432;
  {
    struct kk_std_core_hnd_Ev* _con_x433 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x433->hevv;
    kk_evv_dup(w, _ctx);
    _x_x432 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x432,kk_context()); /*hnd/evv<_6641>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx); /*6968*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail0_fun434(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return y;
  }
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_tail0(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c> (op : () -> e c) -> clause0<c,b,e,a> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_tail0_fun431(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop0_fun438(kk_function_t _fself, int32_t ___wildcard_x695__14, kk_std_core_hnd__ev ___wildcard_x695__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop0_fun438__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop0_fun438__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7023 7026 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x695__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_value_fun439(kk_function_t _fself, int32_t ___wildcard_x698__14, kk_std_core_hnd__ev ___wildcard_x698__17, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_value_fun439__t* _self = kk_function_as(struct kk_std_core_hnd_clause_value_fun439__t*, _fself, _ctx);
  kk_box_t v = _self->v; /* 7080 */
  kk_drop_match(_self, {kk_box_dup(v, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x698__17, (KK_I32(3)), _ctx);
  return v;
}


// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun440__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun440(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x701__16, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun440(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun440__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun440__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun440, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never0_fun441__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never0_fun441(kk_function_t _fself, kk_function_t ___wildcard_x701__43, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never0_fun441(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun441__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never0_fun441__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never0_fun441, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never0_fun441(kk_function_t _fself, kk_function_t ___wildcard_x701__43, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun441__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun441__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7155 7157 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x701__43, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), op, (op, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never0_fun440(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x701__16, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never0_fun440__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never0_fun440__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* () -> 7155 7157 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x701__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never0_fun441(op, _ctx), _ctx);
}

kk_std_core_hnd__clause0 kk_std_core_hnd_clause_never0(kk_function_t op, kk_context_t* _ctx) { /* forall<a,e,b,c> (op : () -> e c) -> clause0<a,b,e,c> */ 
  return kk_std_core_hnd__new_Clause0(kk_std_core_hnd_new_clause_never0_fun440(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause2_fs__copy_fun443__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x79;
};
static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun443(kk_function_t _fself, int32_t _b_x85, kk_std_core_hnd__ev _b_x86, kk_box_t _b_x87, kk_box_t _b_x88, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_clause2_fs__new_copy_fun443(kk_box_t _fun_unbox_x79, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun443__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause2_fs__copy_fun443__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause2_fs__copy_fun443, kk_context());
  _self->_fun_unbox_x79 = _fun_unbox_x79;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause2_fs__copy_fun443(kk_function_t _fself, int32_t _b_x85, kk_std_core_hnd__ev _b_x86, kk_box_t _b_x87, kk_box_t _b_x88, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause2_fs__copy_fun443__t* _self = kk_function_as(struct kk_std_core_hnd_clause2_fs__copy_fun443__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x79 = _self->_fun_unbox_x79; /* 7 */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x79, _ctx);}, {}, _ctx)
  kk_function_t _x_x444 = kk_function_unbox(_fun_unbox_x79, _ctx); /*(80, 81, 82, 83) -> 7330 84*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), _x_x444, (_x_x444, kk_int32_box(_b_x85, _ctx), kk_std_core_hnd__ev_box(_b_x86, _ctx), _b_x87, _b_x88, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause2_fs__copy(kk_std_core_hnd__clause2 _this, kk_std_core_types__optional clause, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (clause2<a,b,c,d,e,a1>, clause : ? ((marker<e,a1>, ev<d>, a, b) -> e c)) -> clause2<a,b,c,d,e,a1> */ 
  kk_function_t _x_x442;
  if (kk_std_core_types__is_Optional(clause, _ctx)) {
    kk_box_t _fun_unbox_x79 = clause._cons._Optional.value;
    kk_box_dup(_fun_unbox_x79, _ctx);
    kk_std_core_types__optional_drop(clause, _ctx);
    kk_std_core_hnd__clause2_drop(_this, _ctx);
    _x_x442 = kk_std_core_hnd_clause2_fs__new_copy_fun443(_fun_unbox_x79, _ctx); /*(hnd/marker<7330,7331>, hnd/ev<7329>, 7326, 7327) -> 7330 84*/
  }
  else {
    kk_std_core_types__optional_drop(clause, _ctx);
    {
      kk_function_t _x = _this.clause;
      _x_x442 = _x; /*(hnd/marker<7330,7331>, hnd/ev<7329>, 7326, 7327) -> 7330 84*/
    }
  }
  return kk_std_core_hnd__new_Clause2(_x_x442, _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under2_fun447__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun447(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun447(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun447__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun447__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun447, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under2_fun450__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under2_fun450(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under2_fun450(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun450__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under2_fun450__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under2_fun450, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under2_fun450(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun450__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun450__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7451> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under2_fun447(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under2_fun447__t* _self = kk_function_as(struct kk_std_core_hnd_under2_fun447__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<7451> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x448;
  {
    struct kk_std_core_hnd_Ev* _con_x449 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x449->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x448 = w_0; /*hnd/evv<5350>*/
  }
  w0_0 = kk_evv_swap(_x_x448,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*7449*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun450(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under2(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (ev : ev<d>, op : (a, b) -> e c, x1 : a, x2 : b) -> e c */ 
  kk_evv_t w0;
  kk_evv_t _x_x445;
  {
    struct kk_std_core_hnd_Ev* _con_x446 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x446->hevv;
    kk_evv_dup(w, _ctx);
    _x_x445 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x445,kk_context()); /*hnd/evv<_7363>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx); /*7449*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under2_fun447(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_protect2_fun452__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_protect2_fun452(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_protect2_fun452(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun452__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_protect2_fun452__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_protect2_fun452, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_protect2_fun452(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_protect2_fun452__t* _self = kk_function_as(struct kk_std_core_hnd_protect2_fun452__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<7582,7584>) -> 7583 7584 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x235 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x235;
  kk_std_core_hnd__resume_result _x_x453 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x453, _ctx), _ctx);
}

kk_box_t kk_std_core_hnd_protect2(kk_box_t x1, kk_box_t x2, kk_function_t clause, kk_function_t k, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (x1 : a, x2 : b, clause : (x : a, x : b, k : (c) -> e d) -> e d, k : (resume-result<c,d>) -> e d) -> e d */ 
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_function_t _x_x451;
  kk_function_dup(k, _ctx);
  kk_ref_dup(resumed, _ctx);
  _x_x451 = kk_std_core_hnd_new_protect2_fun452(k, resumed, _ctx); /*(ret : 7582) -> 7583 7584*/
  res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), clause, (clause, x1, x2, _x_x451, _ctx), _ctx); /*7584*/
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun455(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun455__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun455__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 7689, x2 : 7690, k : (7691) -> 7692 7694) -> 7692 7694 */
  kk_box_t x1 = _self->x1; /* 7689 */
  kk_box_t x2 = _self->x2; /* 7690 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_protect2(x1, x2, clause, k, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_control2_fun454(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x726__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control2_fun454__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control2_fun454__t*, _fself, _ctx);
  kk_function_t clause = _self->clause; /* (x1 : 7689, x2 : 7690, k : (7691) -> 7692 7694) -> 7692 7694 */
  kk_drop_match(_self, {kk_function_dup(clause, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x726__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control2_fun455(clause, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun456__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun456(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x730__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun456(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun456__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun456__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun456, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw2_fun457__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun457(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw2_fun457(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun457__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw2_fun457__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw2_fun457, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw2_fun457(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun457__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun457__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7808, x2 : 7809, r : hnd/resume-context<7810,7811,7812,7814>) -> 7811 7814 */
  kk_box_t x1 = _self->x1; /* 7808 */
  kk_box_t x2 = _self->x2; /* 7809 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_std_core_hnd__resume_context _x_x458 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, _x_x458, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control_raw2_fun456(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x730__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw2_fun456__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw2_fun456__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 7808, x2 : 7809, r : hnd/resume-context<7810,7811,7812,7814>) -> 7811 7814 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x730__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(m, kk_std_core_hnd_new_clause_control_raw2_fun457(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_control_raw2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,e1,d,a1> (op : (x1 : a, x2 : b, r : resume-context<c,e,e1,a1>) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_control_raw2_fun456(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail2_fun459(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail2_fun459__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail2_fun459__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (7916, 7917) -> 7913 7918 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under2(ev, op, x1, x2, _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop2_fun460(kk_function_t _fself, int32_t ___wildcard_x736__14, kk_std_core_hnd__ev ___wildcard_x736__17, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop2_fun460__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop2_fun460__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8000, 8001) -> 7997 8002 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x736__17, (KK_I32(3)), _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun462__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun462(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x744__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun462(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun462__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun462__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun462, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never2_fun463__t {
  struct kk_function_s _base;
  kk_function_t op;
  kk_box_t x1;
  kk_box_t x2;
};
static kk_box_t kk_std_core_hnd_clause_never2_fun463(kk_function_t _fself, kk_function_t ___wildcard_x744__49, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never2_fun463(kk_function_t op, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun463__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never2_fun463__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never2_fun463, kk_context());
  _self->op = op;
  _self->x1 = x1;
  _self->x2 = x2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never2_fun463(kk_function_t _fself, kk_function_t ___wildcard_x744__49, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun463__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun463__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8218, 8219) -> 8221 8223 */
  kk_box_t x1 = _self->x1; /* 8218 */
  kk_box_t x2 = _self->x2; /* 8219 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);kk_box_dup(x1, _ctx);kk_box_dup(x2, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x744__49, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_never2_fun462(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x744__16, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never2_fun462__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never2_fun462__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8218, 8219) -> 8221 8223 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x744__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_hnd_new_clause_never2_fun463(op, x1, x2, _ctx), _ctx);
}

kk_std_core_hnd__clause2 kk_std_core_hnd_clause_never2(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,e,d,a1> (op : (a, b) -> e a1) -> clause2<a,b,c,d,e,a1> */ 
  return kk_std_core_hnd__new_Clause2(kk_std_core_hnd_new_clause_never2_fun462(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun465__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun465(kk_function_t _fself, int32_t _b_x96, kk_std_core_hnd__ev _b_x97, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun465(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun465__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun465__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun465, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control_raw3_fun466__t {
  struct kk_function_s _base;
  kk_box_t _b_x98;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun466(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control_raw3_fun466(kk_box_t _b_x98, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun466__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control_raw3_fun466__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control_raw3_fun466, kk_context());
  _self->_b_x98 = _b_x98;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control_raw3_fun466(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun466__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun466__t*, _fself, _ctx);
  kk_box_t _b_x98 = _self->_b_x98; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 8430, x2 : 8431, x3 : 8432, r : hnd/resume-context<8433,8434,8435,8437>) -> 8434 8437 */
  kk_drop_match(_self, {kk_box_dup(_b_x98, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple3 _match_x232 = kk_std_core_types__tuple3_unbox(_b_x98, KK_OWNED, _ctx); /*(8430, 8431, 8432)*/;
  {
    kk_box_t x1 = _match_x232.fst;
    kk_box_t x2 = _match_x232.snd;
    kk_box_t x3 = _match_x232.thd;
    kk_std_core_hnd__resume_context _x_x467 = kk_std_core_hnd__new_Resume_context(k, _ctx); /*hnd/resume-context<83,84,85,86>*/
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_std_core_hnd__resume_context, kk_context_t*), op, (op, x1, x2, x3, _x_x467, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_control_raw3_fun465(kk_function_t _fself, int32_t _b_x96, kk_std_core_hnd__ev _b_x97, kk_box_t _b_x98, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control_raw3_fun465__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control_raw3_fun465__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 8430, x2 : 8431, x3 : 8432, r : hnd/resume-context<8433,8434,8435,8437>) -> 8434 8437 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x97, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x96, kk_std_core_hnd_new_clause_control_raw3_fun466(_b_x98, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control_raw3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1,a1,b1> (op : (x1 : a, x2 : b, x3 : c, r : resume-context<d,e,e1,b1>) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control_raw3_fun465(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun468__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun468(kk_function_t _fself, int32_t _b_x110, kk_std_core_hnd__ev _b_x111, kk_box_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun468(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun468__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun468__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun468, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun469__t {
  struct kk_function_s _base;
  kk_box_t _b_x112;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun469(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun469(kk_box_t _b_x112, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun469__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun469__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun469, kk_context());
  _self->_b_x112 = _b_x112;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control3_fun471__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control3_fun471(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control3_fun471(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun471__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control3_fun471__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control3_fun471, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control3_fun471(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun471__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun471__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<8539,8542>) -> 8540 8542 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x231 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x231;
  kk_std_core_hnd__resume_result _x_x472 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x472, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control3_fun469(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun469__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun469__t*, _fself, _ctx);
  kk_box_t _b_x112 = _self->_b_x112; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 8536, x2 : 8537, x3 : 8538, k : (8539) -> 8540 8542) -> 8540 8542 */
  kk_drop_match(_self, {kk_box_dup(_b_x112, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple3 _match_x230 = kk_std_core_types__tuple3_unbox(_b_x112, KK_OWNED, _ctx); /*(8536, 8537, 8538)*/;
  {
    kk_box_t x1 = _match_x230.fst;
    kk_box_t x2 = _match_x230.snd;
    kk_box_t x3 = _match_x230.thd;
    kk_function_t _x_x470;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x470 = kk_std_core_hnd_new_clause_control3_fun471(k, resumed, _ctx); /*(ret : 8539) -> 8540 8542*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, _x_x470, _ctx), _ctx); /*8542*/
  }
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control3_fun468(kk_function_t _fself, int32_t _b_x110, kk_std_core_hnd__ev _b_x111, kk_box_t _b_x112, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control3_fun468__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control3_fun468__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 8536, x2 : 8537, x3 : 8538, k : (8539) -> 8540 8542) -> 8540 8542 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x111, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x110, kk_std_core_hnd_new_clause_control3_fun469(_b_x112, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (x1 : a, x2 : b, x3 : c, k : (d) -> e b1) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control3_fun468(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun473__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun473(kk_function_t _fself, int32_t _b_x118, kk_std_core_hnd__ev _b_x119, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun473(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun473__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun473__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun473, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail3_fun476__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x119;
};
static kk_box_t kk_std_core_hnd_clause_tail3_fun476(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail3_fun476(kk_std_core_hnd__ev _b_x119, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun476__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail3_fun476__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail3_fun476, kk_context());
  _self->_b_x119 = _b_x119;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail3_fun476(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun476__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun476__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x119 = _self->_b_x119; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x119, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x119, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail3_fun473(kk_function_t _fself, int32_t _b_x118, kk_std_core_hnd__ev _b_x119, kk_box_t _b_x120, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail3_fun473__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail3_fun473__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8640, 8641, 8642) -> 8637 8643 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x474;
  {
    struct kk_std_core_hnd_Ev* _con_x475 = kk_std_core_hnd__as_Ev(_b_x119, _ctx);
    kk_evv_t w = _con_x475->hevv;
    kk_evv_dup(w, _ctx);
    _x_x474 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x474,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y;
  kk_std_core_types__tuple3 _match_x229 = kk_std_core_types__tuple3_unbox(_b_x120, KK_OWNED, _ctx); /*(8640, 8641, 8642)*/;
  {
    kk_box_t x1 = _match_x229.fst;
    kk_box_t x2 = _match_x229.snd;
    kk_box_t x3 = _match_x229.thd;
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*8643*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail3_fun476(_b_x119, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x119, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail3(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1> (op : (c, d, a1) -> e b1) -> clause1<(c, d, a1),b1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail3_fun473(op, _ctx), _ctx);
}
extern kk_box_t kk_std_core_hnd_clause_tail_noop3_fun477(kk_function_t _fself, int32_t _b_x126, kk_std_core_hnd__ev _b_x127, kk_box_t _b_x128, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop3_fun477__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop3_fun477__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8741, 8742, 8743) -> 8738 8744 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x127, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple3 _match_x227 = kk_std_core_types__tuple3_unbox(_b_x128, KK_OWNED, _ctx); /*(8741, 8742, 8743)*/;
  {
    kk_box_t x1 = _match_x227.fst;
    kk_box_t x2 = _match_x227.snd;
    kk_box_t x3 = _match_x227.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun478__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun478(kk_function_t _fself, int32_t _b_x134, kk_std_core_hnd__ev _b_x135, kk_box_t _b_x136, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun478(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun478__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun478__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun478, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never3_fun479__t {
  struct kk_function_s _base;
  kk_box_t _b_x136;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never3_fun479(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never3_fun479(kk_box_t _b_x136, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun479__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never3_fun479__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never3_fun479, kk_context());
  _self->_b_x136 = _b_x136;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never3_fun479(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun479__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun479__t*, _fself, _ctx);
  kk_box_t _b_x136 = _self->_b_x136; /* 45 */
  kk_function_t op = _self->op; /* (8839, 8840, 8841) -> 8843 8845 */
  kk_drop_match(_self, {kk_box_dup(_b_x136, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x654__45, _ctx);
  kk_std_core_types__tuple3 _match_x226 = kk_std_core_types__tuple3_unbox(_b_x136, KK_OWNED, _ctx); /*(8839, 8840, 8841)*/;
  {
    kk_box_t x1 = _match_x226.fst;
    kk_box_t x2 = _match_x226.snd;
    kk_box_t x3 = _match_x226.thd;
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never3_fun478(kk_function_t _fself, int32_t _b_x134, kk_std_core_hnd__ev _b_x135, kk_box_t _b_x136, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never3_fun478__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never3_fun478__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (8839, 8840, 8841) -> 8843 8845 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x135, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x134, kk_std_core_hnd_new_clause_never3_fun479(_b_x136, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never3(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1,b1> (op : (a, b, c) -> e b1) -> clause1<(a, b, c),d,a1,e,b1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never3_fun478(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under3_fun485__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun485(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun485(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun485__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun485__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun485, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under3_fun488__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under3_fun488(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under3_fun488(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun488__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under3_fun488__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under3_fun488, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under3_fun488(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun488__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun488__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9082> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under3_fun485(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under3_fun485__t* _self = kk_function_as(struct kk_std_core_hnd_under3_fun485__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9082> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x486;
  {
    struct kk_std_core_hnd_Ev* _con_x487 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x487->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x486 = w_0; /*hnd/evv<5350>*/
  }
  w0_0 = kk_evv_swap(_x_x486,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*9080*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun488(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under3(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (ev : ev<a1>, op : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e d */ 
  kk_evv_t w0;
  kk_evv_t _x_x483;
  {
    struct kk_std_core_hnd_Ev* _con_x484 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x484->hevv;
    kk_evv_dup(w, _ctx);
    _x_x483 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x483,kk_context()); /*hnd/evv<_8988>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, _ctx), _ctx); /*9080*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under3_fun485(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun489__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun489(kk_function_t _fself, int32_t _b_x155, kk_std_core_hnd__ev _b_x156, kk_box_t _b_x157, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun489(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun489__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun489__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun489, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun490__t {
  struct kk_function_s _base;
  kk_box_t _b_x157;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun490(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun490(kk_box_t _b_x157, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun490__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun490__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun490, kk_context());
  _self->_b_x157 = _b_x157;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_control4_fun493__t {
  struct kk_function_s _base;
  kk_function_t k;
  kk_ref_t resumed;
};
static kk_box_t kk_std_core_hnd_clause_control4_fun493(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_control4_fun493(kk_function_t k, kk_ref_t resumed, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun493__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_control4_fun493__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_control4_fun493, kk_context());
  _self->k = k;
  _self->resumed = resumed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_control4_fun493(kk_function_t _fself, kk_box_t ret, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun493__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun493__t*, _fself, _ctx);
  kk_function_t k = _self->k; /* (hnd/resume-result<9186,9189>) -> 9187 9189 */
  kk_ref_t resumed = _self->resumed; /* ref<global,bool> */
  kk_drop_match(_self, {kk_function_dup(k, _ctx);kk_ref_dup(resumed, _ctx);}, {}, _ctx)
  kk_unit_t __ = kk_Unit;
  kk_unit_t _brw_x222 = kk_Unit;
  kk_ref_set_borrow(resumed,(kk_bool_box(true)),kk_context());
  kk_ref_drop(resumed, _ctx);
  _brw_x222;
  kk_std_core_hnd__resume_result _x_x494 = kk_std_core_hnd__new_Deep(ret, _ctx); /*hnd/resume-result<74,75>*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), k, (k, _x_x494, _ctx), _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control4_fun490(kk_function_t _fself, kk_function_t k, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun490__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun490__t*, _fself, _ctx);
  kk_box_t _b_x157 = _self->_b_x157; /* 45 */
  kk_function_t op = _self->op; /* (x1 : 9182, x2 : 9183, x3 : 9184, x4 : 9185, k : (9186) -> 9187 9189) -> 9187 9189 */
  kk_drop_match(_self, {kk_box_dup(_b_x157, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_ref_t resumed = kk_ref_alloc((kk_bool_box(false)),kk_context()); /*ref<global,bool>*/;
  kk_box_t res;
  kk_std_core_types__tuple4 _match_x221 = kk_std_core_types__tuple4_unbox(_b_x157, KK_OWNED, _ctx); /*(9182, 9183, 9184, 9185)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x491 = kk_std_core_types__as_Tuple4(_match_x221, _ctx);
    kk_box_t x1 = _con_x491->fst;
    kk_box_t x2 = _con_x491->snd;
    kk_box_t x3 = _con_x491->thd;
    kk_box_t x4 = _con_x491->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x221, _ctx)) {
      kk_datatype_ptr_free(_match_x221, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x221, _ctx);
    }
    kk_function_t _x_x492;
    kk_function_dup(k, _ctx);
    kk_ref_dup(resumed, _ctx);
    _x_x492 = kk_std_core_hnd_new_clause_control4_fun493(k, resumed, _ctx); /*(ret : 9186) -> 9187 9189*/
    res = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_function_t, kk_context_t*), op, (op, x1, x2, x3, x4, _x_x492, _ctx), _ctx); /*9189*/
  }
  return kk_std_core_hnd_protect_prompt(resumed, k, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_control4_fun489(kk_function_t _fself, int32_t _b_x155, kk_std_core_hnd__ev _b_x156, kk_box_t _b_x157, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_control4_fun489__t* _self = kk_function_as(struct kk_std_core_hnd_clause_control4_fun489__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (x1 : 9182, x2 : 9183, x3 : 9184, x4 : 9185, k : (9186) -> 9187 9189) -> 9187 9189 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x156, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to(_b_x155, kk_std_core_hnd_new_clause_control4_fun490(_b_x157, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_control4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (x1 : a, x2 : b, x3 : c, x4 : d, k : (a1) -> e c1) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_control4_fun489(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun495__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun495(kk_function_t _fself, int32_t _b_x163, kk_std_core_hnd__ev _b_x164, kk_box_t _b_x165, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun495(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun495__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun495__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun495, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_tail4_fun499__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev _b_x164;
};
static kk_box_t kk_std_core_hnd_clause_tail4_fun499(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail4_fun499(kk_std_core_hnd__ev _b_x164, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun499__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail4_fun499__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail4_fun499, kk_context());
  _self->_b_x164 = _b_x164;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail4_fun499(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun499__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun499__t*, _fself, _ctx);
  kk_std_core_hnd__ev _b_x164 = _self->_b_x164; /* hnd/ev<47> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(_b_x164, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(_b_x164, cont, res, _ctx);
}
static kk_box_t kk_std_core_hnd_clause_tail4_fun495(kk_function_t _fself, int32_t _b_x163, kk_std_core_hnd__ev _b_x164, kk_box_t _b_x165, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail4_fun495__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail4_fun495__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9298, 9299, 9300, 9301) -> 9295 9302 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_evv_t w0;
  kk_evv_t _x_x496;
  {
    struct kk_std_core_hnd_Ev* _con_x497 = kk_std_core_hnd__as_Ev(_b_x164, _ctx);
    kk_evv_t w = _con_x497->hevv;
    kk_evv_dup(w, _ctx);
    _x_x496 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x496,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y;
  kk_std_core_types__tuple4 _match_x220 = kk_std_core_types__tuple4_unbox(_b_x165, KK_OWNED, _ctx); /*(9298, 9299, 9300, 9301)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x498 = kk_std_core_types__as_Tuple4(_match_x220, _ctx);
    kk_box_t x1 = _con_x498->fst;
    kk_box_t x2 = _con_x498->snd;
    kk_box_t x3 = _con_x498->thd;
    kk_box_t x4 = _con_x498->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x220, _ctx)) {
      kk_datatype_ptr_free(_match_x220, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x220, _ctx);
    }
    y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*9302*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_clause_tail4_fun499(_b_x164, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(_b_x164, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0,kk_context());
    return y;
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail4_fun495(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_tail_noop4_fun500__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun500(kk_function_t _fself, int32_t _b_x171, kk_std_core_hnd__ev _b_x172, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_tail_noop4_fun500(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun500__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_tail_noop4_fun500__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_tail_noop4_fun500, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_tail_noop4_fun500(kk_function_t _fself, int32_t _b_x171, kk_std_core_hnd__ev _b_x172, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_tail_noop4_fun500__t* _self = kk_function_as(struct kk_std_core_hnd_clause_tail_noop4_fun500__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9411, 9412, 9413, 9414) -> 9408 9415 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x172, (KK_I32(3)), _ctx);
  kk_std_core_types__tuple4 _match_x218 = kk_std_core_types__tuple4_unbox(_b_x173, KK_OWNED, _ctx); /*(9411, 9412, 9413, 9414)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x501 = kk_std_core_types__as_Tuple4(_match_x218, _ctx);
    kk_box_t x1 = _con_x501->fst;
    kk_box_t x2 = _con_x501->snd;
    kk_box_t x3 = _con_x501->thd;
    kk_box_t x4 = _con_x501->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x218, _ctx)) {
      kk_datatype_ptr_free(_match_x218, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x218, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_tail_noop4(kk_function_t op, kk_context_t* _ctx) { /* forall<e,a,b,c,d,a1,b1,c1> (op : (c, d, a1, b1) -> e c1) -> clause1<(c, d, a1, b1),c1,b,e,a> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_tail_noop4_fun500(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun502__t {
  struct kk_function_s _base;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun502(kk_function_t _fself, int32_t _b_x179, kk_std_core_hnd__ev _b_x180, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun502(kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun502__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun502__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun502, kk_context());
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_clause_never4_fun503__t {
  struct kk_function_s _base;
  kk_box_t _b_x181;
  kk_function_t op;
};
static kk_box_t kk_std_core_hnd_clause_never4_fun503(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_clause_never4_fun503(kk_box_t _b_x181, kk_function_t op, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun503__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_clause_never4_fun503__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_clause_never4_fun503, kk_context());
  _self->_b_x181 = _b_x181;
  _self->op = op;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_clause_never4_fun503(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun503__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun503__t*, _fself, _ctx);
  kk_box_t _b_x181 = _self->_b_x181; /* 45 */
  kk_function_t op = _self->op; /* (9521, 9522, 9523, 9524) -> 9526 9528 */
  kk_drop_match(_self, {kk_box_dup(_b_x181, _ctx);kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x654__45, _ctx);
  kk_std_core_types__tuple4 _match_x217 = kk_std_core_types__tuple4_unbox(_b_x181, KK_OWNED, _ctx); /*(9521, 9522, 9523, 9524)*/;
  {
    struct kk_std_core_types_Tuple4* _con_x504 = kk_std_core_types__as_Tuple4(_match_x217, _ctx);
    kk_box_t x1 = _con_x504->fst;
    kk_box_t x2 = _con_x504->snd;
    kk_box_t x3 = _con_x504->thd;
    kk_box_t x4 = _con_x504->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x217, _ctx)) {
      kk_datatype_ptr_free(_match_x217, _ctx);
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_match_x217, _ctx);
    }
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx);
  }
}
static kk_box_t kk_std_core_hnd_clause_never4_fun502(kk_function_t _fself, int32_t _b_x179, kk_std_core_hnd__ev _b_x180, kk_box_t _b_x181, kk_context_t* _ctx) {
  struct kk_std_core_hnd_clause_never4_fun502__t* _self = kk_function_as(struct kk_std_core_hnd_clause_never4_fun502__t*, _fself, _ctx);
  kk_function_t op = _self->op; /* (9521, 9522, 9523, 9524) -> 9526 9528 */
  kk_drop_match(_self, {kk_function_dup(op, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x180, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x179, kk_std_core_hnd_new_clause_never4_fun503(_b_x181, op, _ctx), _ctx);
}

kk_std_core_hnd__clause1 kk_std_core_hnd_clause_never4(kk_function_t op, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1,c1> (op : (a, b, c, d) -> e c1) -> clause1<(a, b, c, d),a1,b1,e,c1> */ 
  return kk_std_core_hnd__new_Clause1(kk_std_core_hnd_new_clause_never4_fun502(op, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_hnd_under4_fun510__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun510(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun510(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun510__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun510__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun510, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_hnd_under4_fun513__t {
  struct kk_function_s _base;
  kk_std_core_hnd__ev ev;
};
static kk_box_t kk_std_core_hnd_under4_fun513(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_under4_fun513(kk_std_core_hnd__ev ev, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun513__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_under4_fun513__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_under4_fun513, kk_context());
  _self->ev = ev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_under4_fun513(kk_function_t _fself, kk_function_t cont_0, kk_box_t res_0, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun513__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun513__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9788> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_under1x(ev, cont_0, res_0, _ctx);
}
static kk_box_t kk_std_core_hnd_under4_fun510(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_under4_fun510__t* _self = kk_function_as(struct kk_std_core_hnd_under4_fun510__t*, _fself, _ctx);
  kk_std_core_hnd__ev ev = _self->ev; /* hnd/ev<9788> */
  kk_drop_match(_self, {kk_std_core_hnd__ev_dup(ev, _ctx);}, {}, _ctx)
  kk_evv_t w0_0;
  kk_evv_t _x_x511;
  {
    struct kk_std_core_hnd_Ev* _con_x512 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w_0 = _con_x512->hevv;
    kk_evv_dup(w_0, _ctx);
    _x_x511 = w_0; /*hnd/evv<5350>*/
  }
  w0_0 = kk_evv_swap(_x_x511,kk_context()); /*hnd/evv<_5497>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont, (cont, res, _ctx), _ctx); /*9786*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    kk_evv_drop(w0_0, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun513(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w0_0,kk_context());
    return y;
  }
}

kk_box_t kk_std_core_hnd_under4(kk_std_core_hnd__ev ev, kk_function_t op, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,b1> (ev : ev<b1>, op : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e a1 */ 
  kk_evv_t w0;
  kk_evv_t _x_x508;
  {
    struct kk_std_core_hnd_Ev* _con_x509 = kk_std_core_hnd__as_Ev(ev, _ctx);
    kk_evv_t w = _con_x509->hevv;
    kk_evv_dup(w, _ctx);
    _x_x508 = w; /*hnd/evv<5350>*/
  }
  w0 = kk_evv_swap(_x_x508,kk_context()); /*hnd/evv<_9688>*/
  kk_box_t z = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), op, (op, x1, x2, x3, x4, _ctx), _ctx); /*9786*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(z, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_under4_fun510(ev, _ctx), _ctx);
  }
  {
    kk_datatype_ptr_dropn(ev, (KK_I32(3)), _ctx);
    return z;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open_at1_fun514__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd_open_at1_fun514(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open_at1_fun514(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun514__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open_at1_fun514__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open_at1_fun514, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open_at1_fun514(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open_at1_fun514__t* _self = kk_function_as(struct kk_std_core_hnd_open_at1_fun514__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10341>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*10339*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open_at1_fun514(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at0_fun515__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at0_fun515(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at0_fun515(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun515__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at0_fun515__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at0_fun515, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at0_fun515(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at0_fun515__t* _self = kk_function_as(struct kk_std_core_hnd__open_at0_fun515__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at0(kk_ssize_t i, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (i : ev-index, f : () -> e a) -> e1 a */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10448>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*10446*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at0_fun515(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at1_fun516__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at1_fun516(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at1_fun516(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun516__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at1_fun516__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at1_fun516, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at1_fun516(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at1_fun516__t* _self = kk_function_as(struct kk_std_core_hnd__open_at1_fun516__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at1(kk_ssize_t i, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (i : ev-index, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10562>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*10560*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at1_fun516(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at2_fun517__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at2_fun517(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at2_fun517(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun517__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at2_fun517__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at2_fun517, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at2_fun517(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at2_fun517__t* _self = kk_function_as(struct kk_std_core_hnd__open_at2_fun517__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at2(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (i : ev-index, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10689>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*10687*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at2_fun517(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at3_fun518__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at3_fun518(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at3_fun518(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun518__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at3_fun518__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at3_fun518, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at3_fun518(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at3_fun518__t* _self = kk_function_as(struct kk_std_core_hnd__open_at3_fun518__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at3(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (i : ev-index, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10829>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*10827*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at3_fun518(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open_at4_fun519__t {
  struct kk_function_s _base;
  kk_ssize_t i;
};
static kk_box_t kk_std_core_hnd__open_at4_fun519(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open_at4_fun519(kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun519__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open_at4_fun519__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open_at4_fun519, kk_context());
  _self->i = i;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open_at4_fun519(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open_at4_fun519__t* _self = kk_function_as(struct kk_std_core_hnd__open_at4_fun519__t*, _fself, _ctx);
  kk_ssize_t i = _self->i; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open_at4(kk_ssize_t i, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (i : ev-index, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w = kk_evv_swap_create1(i,kk_context()); /*hnd/evv<10982>*/;
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*10980*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open_at4_fun519(i, _ctx), _ctx);
  }
  {
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_open1_fun521__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd_open1_fun521(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_open1_fun521(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun521__t* _self = kk_function_alloc_as(struct kk_std_core_hnd_open1_fun521__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd_open1_fun521, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd_open1_fun521(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd_open1_fun521__t* _self = kk_function_as(struct kk_std_core_hnd_open1_fun521__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd_open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x520 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x520, _ctx); /*hnd/evv<11115>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*11113*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_open1_fun521(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open0_fun523__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open0_fun523(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open0_fun523(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun523__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open0_fun523__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open0_fun523, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open0_fun523(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open0_fun523__t* _self = kk_function_as(struct kk_std_core_hnd__open0_fun523__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open0(kk_vector_t indices, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e,e1> (indices : vector<ev-index>, f : () -> e a) -> e1 a */ 
  kk_evv_t w;
  kk_vector_t _x_x522 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x522, _ctx); /*hnd/evv<11222>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), f, (f, _ctx), _ctx); /*11220*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open0_fun523(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open1_fun525__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open1_fun525(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open1_fun525(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun525__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open1_fun525__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open1_fun525, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open1_fun525(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open1_fun525__t* _self = kk_function_as(struct kk_std_core_hnd__open1_fun525__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open1(kk_vector_t indices, kk_function_t f, kk_box_t x, kk_context_t* _ctx) { /* forall<a,b,e,e1> (indices : vector<ev-index>, f : (a) -> e b, x : a) -> e1 b */ 
  kk_evv_t w;
  kk_vector_t _x_x524 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x524, _ctx); /*hnd/evv<11336>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*11334*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open1_fun525(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open2_fun527__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open2_fun527(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open2_fun527(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun527__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open2_fun527__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open2_fun527, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open2_fun527(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open2_fun527__t* _self = kk_function_as(struct kk_std_core_hnd__open2_fun527__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open2(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_context_t* _ctx) { /* forall<a,b,c,e,e1> (indices : vector<ev-index>, f : (a, b) -> e c, x1 : a, x2 : b) -> e1 c */ 
  kk_evv_t w;
  kk_vector_t _x_x526 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x526, _ctx); /*hnd/evv<11463>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, _ctx), _ctx); /*11461*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open2_fun527(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open3_fun529__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open3_fun529(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open3_fun529(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun529__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open3_fun529__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open3_fun529, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open3_fun529(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open3_fun529__t* _self = kk_function_as(struct kk_std_core_hnd__open3_fun529__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open3(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_context_t* _ctx) { /* forall<a,b,c,d,e,e1> (indices : vector<ev-index>, f : (a, b, c) -> e d, x1 : a, x2 : b, x3 : c) -> e1 d */ 
  kk_evv_t w;
  kk_vector_t _x_x528 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x528, _ctx); /*hnd/evv<11603>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, _ctx), _ctx); /*11601*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open3_fun529(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd__open4_fun531__t {
  struct kk_function_s _base;
  kk_vector_t indices;
};
static kk_box_t kk_std_core_hnd__open4_fun531(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd__new_open4_fun531(kk_vector_t indices, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun531__t* _self = kk_function_alloc_as(struct kk_std_core_hnd__open4_fun531__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_hnd__open4_fun531, kk_context());
  _self->indices = indices;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_hnd__open4_fun531(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_hnd__open4_fun531__t* _self = kk_function_as(struct kk_std_core_hnd__open4_fun531__t*, _fself, _ctx);
  kk_vector_t indices = _self->indices; /* vector<hnd/ev-index> */
  kk_drop_match(_self, {kk_vector_dup(indices, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open1(indices, cont, res, _ctx);
}

kk_box_t kk_std_core_hnd__open4(kk_vector_t indices, kk_function_t f, kk_box_t x1, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,e,e1> (indices : vector<ev-index>, f : (a, b, c, d) -> e a1, x1 : a, x2 : b, x3 : c, x4 : d) -> e1 a1 */ 
  kk_evv_t w;
  kk_vector_t _x_x530 = kk_vector_dup(indices, _ctx); /*vector<hnd/ev-index>*/
  w = kk_std_core_hnd_evv_swap_create(_x_x530, _ctx); /*hnd/evv<11756>*/
  kk_box_t y = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x1, x2, x3, x4, _ctx), _ctx); /*11754*/;
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_drop(y, _ctx);
    return kk_std_core_hnd_yield_cont(kk_std_core_hnd__new_open4_fun531(indices, _ctx), _ctx);
  }
  {
    kk_vector_drop(indices, _ctx);
    return y;
  }
}


// lift anonymous function
struct kk_std_core_hnd_try_finalize_prompt_fun533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun533(kk_function_t _fself, kk_function_t _b_x194, kk_box_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_std_core_hnd_new_try_finalize_prompt_fun533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_hnd_try_finalize_prompt_fun533, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_hnd_try_finalize_prompt_fun533(kk_function_t _fself, kk_function_t _b_x194, kk_box_t _b_x195, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_function_t cont_199 = _b_x194; /*(11821) -> 11881 11880*/;
  kk_box_t x_200 = _b_x195; /*11821*/;
  kk_std_core_types__either _x_x534;
  kk_box_t _x_x535 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), cont_199, (cont_199, x_200, _ctx), _ctx); /*11880*/
  _x_x534 = kk_std_core_hnd_try_finalize_prompt(_x_x535, _ctx); /*either<hnd/yield-info,11880>*/
  return kk_std_core_types__either_box(_x_x534, _ctx);
}

kk_std_core_types__either kk_std_core_hnd_try_finalize_prompt(kk_box_t res, kk_context_t* _ctx) { /* forall<a,e> (res : a) -> e either<yield-info,a> */ 
  bool _match_x201 = kk_yielding_non_final(kk_context()); /*bool*/;
  if (_match_x201) {
    kk_box_drop(res, _ctx);
    kk_box_t _x_x532 = kk_std_core_hnd_yield_cont(kk_std_core_hnd_new_try_finalize_prompt_fun533(_ctx), _ctx); /*2568*/
    return kk_std_core_types__either_unbox(_x_x532, KK_OWNED, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_box_drop(res, _ctx);
    kk_std_core_hnd__yield_info _b_x196_198 = kk_std_core_hnd_yield_capture(_ctx); /*hnd/yield-info*/;
    return kk_std_core_types__new_Left(kk_std_core_hnd__yield_info_box(_b_x196_198, _ctx), _ctx);
  }
  {
    return kk_std_core_types__new_Right(res, _ctx);
  }
}

// initialization
void kk_std_core_hnd__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_hnd__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
