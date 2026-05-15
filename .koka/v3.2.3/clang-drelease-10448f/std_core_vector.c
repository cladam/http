// Koka generated module: std/core/vector, koka version: 3.2.3, platform: 64-bit
#include "std_core_vector.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_std_core_types__list kk_vector_to_list(kk_vector_t v, kk_std_core_types__list tail, kk_context_t* ctx) {
  // todo: avoid boxed_dup if v is unique
  kk_ssize_t n;
  kk_box_t* p = kk_vector_buf_borrow(v, &n, ctx);
  if (n <= 0) {
    kk_vector_drop(v,ctx);
    return tail;
  }
  kk_std_core_types__list nil  = kk_std_core_types__new_Nil(ctx);
  struct kk_std_core_types_Cons* cons = NULL;
  kk_std_core_types__list list = kk_std_core_types__new_Nil(ctx);
  for( kk_ssize_t i = 0; i < n; i++ ) {
    kk_std_core_types__list hd = kk_std_core_types__new_Cons(kk_reuse_null,0,kk_box_dup(p[i],ctx), nil, ctx);
    if (cons==NULL) {
      list = hd;
    }
    else {
      cons->tail = hd;
    }
    cons = kk_std_core_types__as_Cons(hd,ctx);
  }
  if (cons == NULL) { list = tail; }
               else { cons->tail = tail; }
  kk_vector_drop(v,ctx);
  return list;
}

kk_vector_t kk_list_to_vector(kk_std_core_types__list xs, kk_context_t* ctx) {
  // todo: avoid boxed_dup if xs is unique
  // find the length
  kk_ssize_t len = 0;
  kk_std_core_types__list ys = xs;
  while (kk_std_core_types__is_Cons(ys,ctx)) {
    struct kk_std_core_types_Cons* cons = kk_std_core_types__as_Cons(ys,ctx);
    len++;
    ys = cons->tail;
  }
  // alloc the vector and copy
  kk_box_t* p;
  kk_vector_t v = kk_vector_alloc_uninit(len, &p, ctx);
  ys = xs;
  for( kk_ssize_t i = 0; i < len; i++) {
    struct kk_std_core_types_Cons* cons = kk_std_core_types__as_Cons(ys,ctx);
    ys = cons->tail;
    p[i] = kk_box_dup(cons->head,ctx);
  }
  kk_std_core_types__list_drop(xs,ctx);  // todo: drop while visiting?
  return v;
}


kk_vector_t kk_vector_init_total( kk_ssize_t n, kk_function_t init, kk_context_t* ctx) {
  kk_vector_t v = kk_vector_alloc(n, kk_box_null(), ctx);
  kk_box_t* p = kk_vector_buf_borrow(v, NULL, ctx);
  for(kk_ssize_t i = 0; i < n; i++) {
    kk_function_dup(init,ctx);
    p[i] = kk_function_call(kk_box_t,(kk_function_t,kk_ssize_t,kk_context_t*),init,(init,i,ctx),ctx);
  }
  kk_function_drop(init,ctx);
  return v;
}


kk_vector_t kk_std_core_vector__unsafe_vector(kk_ssize_t n, kk_context_t* _ctx) { /* forall<a> (n : ssize_t) -> vector<a> */ 
  return kk_vector_alloc(n,kk_box_null(),kk_context());
}
 
// Create a new vector of length `n`  with initial elements `init`` .

kk_vector_t kk_std_core_vector_vector_alloc(kk_ssize_t n, kk_box_t init, kk_context_t* _ctx) { /* forall<a,e> (n : ssize_t, init : a) -> e vector<a> */ 
  return kk_vector_alloc(n,init,kk_context());
}
 
// Create a new vector of length `n`  with initial elements given by a total function `f` .

kk_vector_t kk_std_core_vector_vector_alloc_total(kk_ssize_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a> (n : ssize_t, f : (ssize_t) -> a) -> vector<a> */ 
  return kk_vector_init_total(n,f,kk_context());
}
 
// Return the element at position `index`  in vector `v`.
// Raise an out of bounds exception if `index < 0`  or `index >= v.length`.

kk_box_t kk_std_core_vector__index(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, index : int) -> exn a */ 
  kk_ssize_t idx;
  kk_integer_t _x_x72 = kk_integer_dup(index, _ctx); /*int*/
  idx = kk_std_core_int_ssize__t(_x_x72, _ctx); /*ssize_t*/
  bool _match_x68;
  kk_ssize_t _x_x73 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _match_x68 = (idx < _x_x73); /*bool*/
  if (_match_x68) {
    return kk_vector_at_borrow(v,idx,kk_context());
  }
  {
    kk_std_core_hnd__ev ev_10262 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x74 = kk_std_core_hnd__as_Ev(ev_10262, _ctx);
      kk_box_t _box_x0 = _con_x74->hnd;
      int32_t m = _con_x74->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x0, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x69;
      kk_std_core_hnd__clause1 _brw_x70 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x69 = _brw_x70; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x4 = _match_x69.clause;
        kk_box_t _x_x75;
        kk_std_core_exn__exception _x_x76;
        kk_string_t _x_x77;
        kk_define_string_literal(static, _s_x78, 19, "index out of bounds", _ctx)
        _x_x77 = kk_string_dup(_s_x78, _ctx); /*string*/
        _x_x76 = kk_std_core_exn__new_Exception(_x_x77, kk_std_core_exn__new_ExnRange(_ctx), _ctx); /*exception*/
        _x_x75 = kk_std_core_exn__exception_box(_x_x76, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4, (_fun_unbox_x4, m, ev_10262, _x_x75, _ctx), _ctx);
      }
    }
  }
}
 
// Return the element at position `index` in vector `v`, or `Nothing` if out of bounds

kk_std_core_types__maybe kk_std_core_vector_at(kk_vector_t v, kk_integer_t index, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, index : int) -> maybe<a> */ 
  kk_ssize_t idx;
  kk_integer_t _x_x79 = kk_integer_dup(index, _ctx); /*int*/
  idx = kk_std_core_int_ssize__t(_x_x79, _ctx); /*ssize_t*/
  bool _match_x67;
  kk_ssize_t _x_x80 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _match_x67 = (idx < _x_x80); /*bool*/
  if (_match_x67) {
    kk_box_t _x_x81 = kk_vector_at_borrow(v,idx,kk_context()); /*3*/
    return kk_std_core_types__new_Just(_x_x81, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
extern kk_box_t kk_std_core_vector_vector_init_total_fun87(kk_function_t _fself, kk_ssize_t i, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_total_fun87__t* _self = kk_function_as(struct kk_std_core_vector_vector_init_total_fun87__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (int) -> 476 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_integer_t _x_x88 = kk_integer_from_ssize_t(i,kk_context()); /*int*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), f, (f, _x_x88, _ctx), _ctx);
}

kk_ssize_t kk_std_core_vector_ssize__t_fs_decr(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> ssize_t */ 
  return (i - 1);
}

kk_ssize_t kk_std_core_vector_ssize__t_fs_incr(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> ssize_t */ 
  return (i + 1);
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_forz_1011_10252(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (ssize_t) -> e (), i : ssize_t, n : ssize_t, wild_ : ()) -> e () */ 
  kk_ssize_t i_0_10002 = kk_std_core_vector_ssize__t_fs_incr(i, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_forz_1011(action, n, i_0_10002, _ctx); return kk_Unit;
}
 
// lifted local: forz, rep


// lift anonymous function
struct kk_std_core_vector__lift_forz_1011_fun91__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_ssize_t i_0;
  kk_ssize_t n_0;
};
static kk_box_t kk_std_core_vector__lift_forz_1011_fun91(kk_function_t _fself, kk_box_t _b_x9, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_forz_1011_fun91(kk_function_t action_0, kk_ssize_t i_0, kk_ssize_t n_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_forz_1011_fun91__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_forz_1011_fun91__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_forz_1011_fun91, kk_context());
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_forz_1011_fun91(kk_function_t _fself, kk_box_t _b_x9, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_forz_1011_fun91__t* _self = kk_function_as(struct kk_std_core_vector__lift_forz_1011_fun91__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (ssize_t) -> 539 () */
  kk_ssize_t i_0 = _self->i_0; /* ssize_t */
  kk_ssize_t n_0 = _self->n_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_skip_dup(i_0, _ctx);kk_skip_dup(n_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_11 = kk_Unit;
  kk_unit_unbox(_b_x9);
  kk_unit_t _x_x92 = kk_Unit;
  kk_std_core_vector__mlift_lift_forz_1011_10252(action_0, i_0, n_0, wild___0_11, _ctx);
  return kk_unit_box(_x_x92);
}

kk_unit_t kk_std_core_vector__lift_forz_1011(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx) { /* forall<e> (action : (ssize_t) -> e (), n : ssize_t, i : ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x65 = (i_0 < n_0); /*bool*/;
  if (_match_x65) {
    kk_unit_t x_10265 = kk_Unit;
    kk_function_t _x_x89 = kk_function_dup(action_0, _ctx); /*(ssize_t) -> 539 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_ssize_t, kk_context_t*), _x_x89, (_x_x89, i_0, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x90 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_forz_1011_fun91(action_0, i_0, n_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x90); return kk_Unit;
    }
    {
      kk_ssize_t i_0_10002_0 = kk_std_core_vector_ssize__t_fs_incr(i_0, _ctx); /*ssize_t*/;
      { // tailcall
        i_0 = i_0_10002_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_vector_init_10184_10253(kk_ssize_t _uniq_i_10130, kk_ssize_t _uniq_n_10129, kk_function_t f, kk_vector_t v, kk_box_t _y_x10221, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (int) -> e a, v : vector<a>, a) -> e () */ 
  kk_unit_t _uniq_x___10132 = kk_Unit;
  kk_vector_t _x_x93 = kk_vector_dup(v, _ctx); /*vector<591>*/
  kk_vector_unsafe_assign(_x_x93,_uniq_i_10130,_y_x10221,kk_context());
  kk_ssize_t _uniq_i_0_10002_10133 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10130, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_vector_init_10184(f, v, _uniq_n_10129, _uniq_i_0_10002_10133, _ctx); return kk_Unit;
}
 
// lifted local: vector-init, @spec-x10135
// specialized: std/core/vector/@lift-forz@1011, on parameters @uniq-action@10128, using:
// @uniq-action@10128 = fn<(e :: E)>(i@0: ssize_t){
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(v, i@0, (f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)))));
// }


// lift anonymous function
struct kk_std_core_vector__lift_vector_init_10184_fun97__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10130_0;
  kk_ssize_t _uniq_n_10129_0;
};
static kk_box_t kk_std_core_vector__lift_vector_init_10184_fun97(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_vector_init_10184_fun97(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10130_0, kk_ssize_t _uniq_n_10129_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_vector_init_10184_fun97__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_vector_init_10184_fun97__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_vector_init_10184_fun97, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10130_0 = _uniq_i_10130_0;
  _self->_uniq_n_10129_0 = _uniq_n_10129_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_vector_init_10184_fun97(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_vector_init_10184_fun97__t* _self = kk_function_as(struct kk_std_core_vector__lift_vector_init_10184_fun97__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (int) -> 592 591 */
  kk_vector_t v_0 = _self->v_0; /* vector<591> */
  kk_ssize_t _uniq_i_10130_0 = _self->_uniq_i_10130_0; /* ssize_t */
  kk_ssize_t _uniq_n_10129_0 = _self->_uniq_n_10129_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10130_0, _ctx);kk_skip_dup(_uniq_n_10129_0, _ctx);}, {}, _ctx)
  kk_box_t _y_x10221_0_15 = _b_x13; /*591*/;
  kk_unit_t _x_x98 = kk_Unit;
  kk_std_core_vector__mlift_lift_vector_init_10184_10253(_uniq_i_10130_0, _uniq_n_10129_0, f_0, v_0, _y_x10221_0_15, _ctx);
  return kk_unit_box(_x_x98);
}

kk_unit_t kk_std_core_vector__lift_vector_init_10184(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10129_0, kk_ssize_t _uniq_i_10130_0, kk_context_t* _ctx) { /* forall<a,e> (f : (int) -> e a, v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x63 = (_uniq_i_10130_0 < _uniq_n_10129_0); /*bool*/;
  if (_match_x63) {
    kk_box_t x_10268;
    kk_function_t _x_x95 = kk_function_dup(f_0, _ctx); /*(int) -> 592 591*/
    kk_integer_t _x_x94 = kk_integer_from_ssize_t(_uniq_i_10130_0,kk_context()); /*int*/
    x_10268 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x95, (_x_x95, _x_x94, _ctx), _ctx); /*591*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10268, _ctx);
      kk_box_t _x_x96 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_vector_init_10184_fun97(f_0, v_0, _uniq_i_10130_0, _uniq_n_10129_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x96); return kk_Unit;
    }
    {
      kk_unit_t _uniq_x___10132_0 = kk_Unit;
      kk_vector_t _x_x99 = kk_vector_dup(v_0, _ctx); /*vector<591>*/
      kk_vector_unsafe_assign(_x_x99,_uniq_i_10130_0,x_10268,kk_context());
      kk_ssize_t _uniq_i_0_10002_10133_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10130_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10130_0 = _uniq_i_0_10002_10133_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Create a new vector of length `n`  with initial elements given by function `f` which can have a control effect.


// lift anonymous function
struct kk_std_core_vector_vector_init_fun103__t {
  struct kk_function_s _base;
  kk_vector_t v;
};
static kk_box_t kk_std_core_vector_vector_init_fun103(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector_new_vector_init_fun103(kk_vector_t v, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_fun103__t* _self = kk_function_alloc_as(struct kk_std_core_vector_vector_init_fun103__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector_vector_init_fun103, kk_context());
  _self->v = v;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector_vector_init_fun103(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  struct kk_std_core_vector_vector_init_fun103__t* _self = kk_function_as(struct kk_std_core_vector_vector_init_fun103__t*, _fself, _ctx);
  kk_vector_t v = _self->v; /* vector<591> */
  kk_drop_match(_self, {kk_vector_dup(v, _ctx);}, {}, _ctx)
  kk_unit_t wild___19 = kk_Unit;
  kk_unit_unbox(_b_x17);
  return kk_vector_box(v, _ctx);
}

kk_vector_t kk_std_core_vector_vector_init(kk_integer_t n, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (n : int, f : (int) -> e a) -> e vector<a> */ 
  kk_ssize_t len;
  kk_integer_t _x_x100 = kk_integer_dup(n, _ctx); /*int*/
  len = kk_std_core_int_ssize__t(_x_x100, _ctx); /*ssize_t*/
  kk_vector_t v = kk_vector_alloc(len,kk_box_null(),kk_context()); /*vector<591>*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_unit_t x_10271 = kk_Unit;
  kk_vector_t _x_x101 = kk_vector_dup(v, _ctx); /*vector<591>*/
  kk_std_core_vector__lift_vector_init_10184(f, _x_x101, len, i, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x102 = kk_std_core_hnd_yield_extend(kk_std_core_vector_new_vector_init_fun103(v, _ctx), _ctx); /*2419*/
    return kk_vector_unbox(_x_x102, _ctx);
  }
  {
    return v;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexedz_10185_10255(kk_ssize_t _uniq_i_10139, kk_ssize_t _uniq_n_10138, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10141, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (ssize_t, a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10002_10142 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10139, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexedz_10185(f, v, _uniq_n_10138, _uniq_i_0_10002_10142, _ctx); return kk_Unit;
}
 
// lifted local: foreach-indexedz, @spec-x10144
// specialized: std/core/vector/@lift-forz@1011, on parameters @uniq-action@10137, using:
// @uniq-action@10137 = fn<(e :: E)>(i@0: ssize_t){
//   f(i@0, (std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_indexedz_10185_fun107__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10139_0;
  kk_ssize_t _uniq_n_10138_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_indexedz_10185_fun107(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_indexedz_10185_fun107(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10139_0, kk_ssize_t _uniq_n_10138_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexedz_10185_fun107__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_indexedz_10185_fun107__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_indexedz_10185_fun107, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10139_0 = _uniq_i_10139_0;
  _self->_uniq_n_10138_0 = _uniq_n_10138_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_indexedz_10185_fun107(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexedz_10185_fun107__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_indexedz_10185_fun107__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (ssize_t, 636) -> 637 () */
  kk_vector_t v_0 = _self->v_0; /* vector<636> */
  kk_ssize_t _uniq_i_10139_0 = _self->_uniq_i_10139_0; /* ssize_t */
  kk_ssize_t _uniq_n_10138_0 = _self->_uniq_n_10138_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10139_0, _ctx);kk_skip_dup(_uniq_n_10138_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10141_0_23 = kk_Unit;
  kk_unit_unbox(_b_x21);
  kk_unit_t _x_x108 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_indexedz_10185_10255(_uniq_i_10139_0, _uniq_n_10138_0, f_0, v_0, _uniq_x___10141_0_23, _ctx);
  return kk_unit_box(_x_x108);
}

kk_unit_t kk_std_core_vector__lift_foreach_indexedz_10185(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10138_0, kk_ssize_t _uniq_i_10139_0, kk_context_t* _ctx) { /* forall<a,e> (f : (ssize_t, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x60 = (_uniq_i_10139_0 < _uniq_n_10138_0); /*bool*/;
  if (_match_x60) {
    kk_unit_t x_10276 = kk_Unit;
    kk_function_t _x_x105 = kk_function_dup(f_0, _ctx); /*(ssize_t, 636) -> 637 ()*/
    kk_box_t _x_x104 = kk_vector_at_borrow(v_0,_uniq_i_10139_0,kk_context()); /*3*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_ssize_t, kk_box_t, kk_context_t*), _x_x105, (_x_x105, _uniq_i_10139_0, _x_x104, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x106 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_indexedz_10185_fun107(f_0, v_0, _uniq_i_10139_0, _uniq_n_10138_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x106); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10002_10142_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10139_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10139_0 = _uniq_i_0_10002_10142_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_10186_10256(kk_ssize_t _uniq_i_10148, kk_ssize_t _uniq_n_10147, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10150, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10002_10151 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10148, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_10186(f, v, _uniq_n_10147, _uniq_i_0_10002_10151, _ctx); return kk_Unit;
}
 
// lifted local: foreach, @spec-x10153
// specialized: std/core/vector/@lift-forz@1011, on parameters @uniq-action@10146, using:
// @uniq-action@10146 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10023 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f(x@10023);
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_10186_fun111__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10148_0;
  kk_ssize_t _uniq_n_10147_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_10186_fun111(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_10186_fun111(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10148_0, kk_ssize_t _uniq_n_10147_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_10186_fun111__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_10186_fun111__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_10186_fun111, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10148_0 = _uniq_i_10148_0;
  _self->_uniq_n_10147_0 = _uniq_n_10147_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_10186_fun111(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_10186_fun111__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_10186_fun111__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (668) -> 669 () */
  kk_vector_t v_0 = _self->v_0; /* vector<668> */
  kk_ssize_t _uniq_i_10148_0 = _self->_uniq_i_10148_0; /* ssize_t */
  kk_ssize_t _uniq_n_10147_0 = _self->_uniq_n_10147_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10148_0, _ctx);kk_skip_dup(_uniq_n_10147_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10150_0_27 = kk_Unit;
  kk_unit_unbox(_b_x25);
  kk_unit_t _x_x112 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_10186_10256(_uniq_i_10148_0, _uniq_n_10147_0, f_0, v_0, _uniq_x___10150_0_27, _ctx);
  return kk_unit_box(_x_x112);
}

kk_unit_t kk_std_core_vector__lift_foreach_10186(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10147_0, kk_ssize_t _uniq_i_10148_0, kk_context_t* _ctx) { /* forall<a,e> (f : (a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x58 = (_uniq_i_10148_0 < _uniq_n_10147_0); /*bool*/;
  if (_match_x58) {
    kk_box_t x_10023 = kk_vector_at_borrow(v_0,_uniq_i_10148_0,kk_context()); /*668*/;
    kk_unit_t x_10279 = kk_Unit;
    kk_function_t _x_x109 = kk_function_dup(f_0, _ctx); /*(668) -> 669 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x109, (_x_x109, x_10023, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x110 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_10186_fun111(f_0, v_0, _uniq_i_10148_0, _uniq_n_10147_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x110); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10002_10151_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10148_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10148_0 = _uniq_i_0_10002_10151_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_foreach_indexed_10187_10257(kk_ssize_t _uniq_i_10157, kk_ssize_t _uniq_n_10156, kk_function_t f, kk_vector_t v, kk_unit_t _uniq_x___10159, kk_context_t* _ctx) { /* forall<a,e> (ssize_t, ssize_t, f : (int, a) -> e (), v : vector<a>, ()) -> e () */ 
  kk_ssize_t _uniq_i_0_10002_10160 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10157, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_foreach_indexed_10187(f, v, _uniq_n_10156, _uniq_i_0_10002_10160, _ctx); return kk_Unit;
}
 
// lifted local: foreach-indexed, @spec-x10162
// specialized: std/core/vector/@lift-forz@1011, on parameters @uniq-action@10155, using:
// @uniq-action@10155 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10025 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   f((std/core/types/@open<(total :: E),(e :: E),(i : ssize_t) -> int,(i : ssize_t) -> (e :: E) int>(std/core/int/ssize_t/int)(i@0)), x@10025);
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_indexed_10187_fun116__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10157_0;
  kk_ssize_t _uniq_n_10156_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_indexed_10187_fun116(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_indexed_10187_fun116(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10157_0, kk_ssize_t _uniq_n_10156_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexed_10187_fun116__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_indexed_10187_fun116__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_indexed_10187_fun116, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10157_0 = _uniq_i_10157_0;
  _self->_uniq_n_10156_0 = _uniq_n_10156_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_indexed_10187_fun116(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_indexed_10187_fun116__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_indexed_10187_fun116__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (int, 705) -> 706 () */
  kk_vector_t v_0 = _self->v_0; /* vector<705> */
  kk_ssize_t _uniq_i_10157_0 = _self->_uniq_i_10157_0; /* ssize_t */
  kk_ssize_t _uniq_n_10156_0 = _self->_uniq_n_10156_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10157_0, _ctx);kk_skip_dup(_uniq_n_10156_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10159_0_31 = kk_Unit;
  kk_unit_unbox(_b_x29);
  kk_unit_t _x_x117 = kk_Unit;
  kk_std_core_vector__mlift_lift_foreach_indexed_10187_10257(_uniq_i_10157_0, _uniq_n_10156_0, f_0, v_0, _uniq_x___10159_0_31, _ctx);
  return kk_unit_box(_x_x117);
}

kk_unit_t kk_std_core_vector__lift_foreach_indexed_10187(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10156_0, kk_ssize_t _uniq_i_10157_0, kk_context_t* _ctx) { /* forall<a,e> (f : (int, a) -> e (), v : vector<a>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x56 = (_uniq_i_10157_0 < _uniq_n_10156_0); /*bool*/;
  if (_match_x56) {
    kk_box_t x_10025 = kk_vector_at_borrow(v_0,_uniq_i_10157_0,kk_context()); /*705*/;
    kk_unit_t x_10282 = kk_Unit;
    kk_function_t _x_x114 = kk_function_dup(f_0, _ctx); /*(int, 705) -> 706 ()*/
    kk_integer_t _x_x113 = kk_integer_from_ssize_t(_uniq_i_10157_0,kk_context()); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x114, (_x_x114, _x_x113, x_10025, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x115 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_indexed_10187_fun116(f_0, v_0, _uniq_i_10157_0, _uniq_n_10156_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x115); return kk_Unit;
    }
    {
      kk_ssize_t _uniq_i_0_10002_10160_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10157_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10157_0 = _uniq_i_0_10002_10160_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_for_whilez_1012_10258(kk_function_t action, kk_ssize_t i, kk_ssize_t n, kk_std_core_types__maybe _y_x10237, kk_context_t* _ctx) { /* forall<a,e> (action : (ssize_t) -> e maybe<a>, i : ssize_t, n : ssize_t, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10237, _ctx)) {
    kk_ssize_t i_0_10015 = kk_std_core_vector_ssize__t_fs_incr(i, _ctx); /*ssize_t*/;
    return kk_std_core_vector__lift_for_whilez_1012(action, n, i_0_10015, _ctx);
  }
  {
    kk_box_t x = _y_x10237._cons.Just.value;
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Just(x, _ctx);
  }
}
 
// lifted local: for-whilez, rep


// lift anonymous function
struct kk_std_core_vector__lift_for_whilez_1012_fun120__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_ssize_t i_0;
  kk_ssize_t n_0;
};
static kk_box_t kk_std_core_vector__lift_for_whilez_1012_fun120(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_for_whilez_1012_fun120(kk_function_t action_0, kk_ssize_t i_0, kk_ssize_t n_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_for_whilez_1012_fun120__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_for_whilez_1012_fun120__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_for_whilez_1012_fun120, kk_context());
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_for_whilez_1012_fun120(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_for_whilez_1012_fun120__t* _self = kk_function_as(struct kk_std_core_vector__lift_for_whilez_1012_fun120__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (ssize_t) -> 780 maybe<779> */
  kk_ssize_t i_0 = _self->i_0; /* ssize_t */
  kk_ssize_t n_0 = _self->n_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_skip_dup(i_0, _ctx);kk_skip_dup(n_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10237_0_35 = kk_std_core_types__maybe_unbox(_b_x33, KK_OWNED, _ctx); /*maybe<779>*/;
  kk_std_core_types__maybe _x_x121 = kk_std_core_vector__mlift_lift_for_whilez_1012_10258(action_0, i_0, n_0, _y_x10237_0_35, _ctx); /*maybe<779>*/
  return kk_std_core_types__maybe_box(_x_x121, _ctx);
}

kk_std_core_types__maybe kk_std_core_vector__lift_for_whilez_1012(kk_function_t action_0, kk_ssize_t n_0, kk_ssize_t i_0, kk_context_t* _ctx) { /* forall<a,e> (action : (ssize_t) -> e maybe<a>, n : ssize_t, i : ssize_t) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_x54 = (i_0 < n_0); /*bool*/;
  if (_match_x54) {
    kk_std_core_types__maybe x_0_10285;
    kk_function_t _x_x118 = kk_function_dup(action_0, _ctx); /*(ssize_t) -> 780 maybe<779>*/
    x_0_10285 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_ssize_t, kk_context_t*), _x_x118, (_x_x118, i_0, _ctx), _ctx); /*maybe<779>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10285, _ctx);
      kk_box_t _x_x119 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_for_whilez_1012_fun120(action_0, i_0, n_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x119, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10285, _ctx)) {
      kk_ssize_t i_0_10015_0 = kk_std_core_vector_ssize__t_fs_incr(i_0, _ctx); /*ssize_t*/;
      { // tailcall
        i_0 = i_0_10015_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t x_1 = x_0_10285._cons.Just.value;
      kk_function_drop(action_0, _ctx);
      return kk_std_core_types__new_Just(x_1, _ctx);
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_vector__mlift_lift_foreach_while_10188_10259(kk_ssize_t _uniq_i_10166, kk_ssize_t _uniq_n_10165, kk_function_t f, kk_vector_t v, kk_std_core_types__maybe _y_x10242, kk_context_t* _ctx) { /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e maybe<b>, v : vector<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10242, _ctx)) {
    kk_ssize_t _uniq_i_0_10015_10169 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10166, _ctx); /*ssize_t*/;
    return kk_std_core_vector__lift_foreach_while_10188(f, v, _uniq_n_10165, _uniq_i_0_10015_10169, _ctx);
  }
  {
    kk_box_t _uniq_x_10171 = _y_x10242._cons.Just.value;
    kk_vector_drop(v, _ctx);
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Just(_uniq_x_10171, _ctx);
  }
}
 
// lifted local: foreach-while, @spec-x10173
// specialized: std/core/vector/@lift-for-whilez@1012, on parameters @uniq-action@10164, using:
// @uniq-action@10164 = fn<(e :: E)>(i@0: ssize_t){
//   f((std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_foreach_while_10188_fun125__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_ssize_t _uniq_i_10166_0;
  kk_ssize_t _uniq_n_10165_0;
};
static kk_box_t kk_std_core_vector__lift_foreach_while_10188_fun125(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_foreach_while_10188_fun125(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_i_10166_0, kk_ssize_t _uniq_n_10165_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_while_10188_fun125__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_foreach_while_10188_fun125__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_foreach_while_10188_fun125, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->_uniq_i_10166_0 = _uniq_i_10166_0;
  _self->_uniq_n_10165_0 = _uniq_n_10165_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_foreach_while_10188_fun125(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_foreach_while_10188_fun125__t* _self = kk_function_as(struct kk_std_core_vector__lift_foreach_while_10188_fun125__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (831) -> 833 maybe<832> */
  kk_vector_t v_0 = _self->v_0; /* vector<831> */
  kk_ssize_t _uniq_i_10166_0 = _self->_uniq_i_10166_0; /* ssize_t */
  kk_ssize_t _uniq_n_10165_0 = _self->_uniq_n_10165_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_skip_dup(_uniq_i_10166_0, _ctx);kk_skip_dup(_uniq_n_10165_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10242_0_39 = kk_std_core_types__maybe_unbox(_b_x37, KK_OWNED, _ctx); /*maybe<832>*/;
  kk_std_core_types__maybe _x_x126 = kk_std_core_vector__mlift_lift_foreach_while_10188_10259(_uniq_i_10166_0, _uniq_n_10165_0, f_0, v_0, _y_x10242_0_39, _ctx); /*maybe<832>*/
  return kk_std_core_types__maybe_box(_x_x126, _ctx);
}

kk_std_core_types__maybe kk_std_core_vector__lift_foreach_while_10188(kk_function_t f_0, kk_vector_t v_0, kk_ssize_t _uniq_n_10165_0, kk_ssize_t _uniq_i_10166_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e maybe<b>, v : vector<a>, ssize_t, ssize_t) -> e maybe<b> */ 
  kk__tailcall: ;
  bool _match_x52 = (_uniq_i_10166_0 < _uniq_n_10165_0); /*bool*/;
  if (_match_x52) {
    kk_std_core_types__maybe x_10288;
    kk_function_t _x_x123 = kk_function_dup(f_0, _ctx); /*(831) -> 833 maybe<832>*/
    kk_box_t _x_x122 = kk_vector_at_borrow(v_0,_uniq_i_10166_0,kk_context()); /*3*/
    x_10288 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x123, (_x_x123, _x_x122, _ctx), _ctx); /*maybe<832>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10288, _ctx);
      kk_box_t _x_x124 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_foreach_while_10188_fun125(f_0, v_0, _uniq_i_10166_0, _uniq_n_10165_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x124, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_10288, _ctx)) {
      kk_ssize_t _uniq_i_0_10015_10169_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10166_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10166_0 = _uniq_i_0_10015_10169_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t _uniq_x_10171_0 = x_10288._cons.Just.value;
      kk_vector_drop(v_0, _ctx);
      kk_function_drop(f_0, _ctx);
      return kk_std_core_types__new_Just(_uniq_x_10171_0, _ctx);
    }
  }
  {
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_vector__mlift_lift_map_10189_10260(kk_ssize_t _uniq_i_10177, kk_ssize_t _uniq_n_10176, kk_function_t f, kk_vector_t v, kk_vector_t w, kk_box_t _y_x10247, kk_context_t* _ctx) { /* forall<a,b,e> (ssize_t, ssize_t, f : (a) -> e b, v : vector<a>, w : vector<b>, b) -> e () */ 
  kk_unit_t _uniq_x___10179 = kk_Unit;
  kk_vector_t _x_x127 = kk_vector_dup(w, _ctx); /*vector<902>*/
  kk_vector_unsafe_assign(_x_x127,_uniq_i_10177,_y_x10247,kk_context());
  kk_ssize_t _uniq_i_0_10002_10180 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10177, _ctx); /*ssize_t*/;
  kk_std_core_vector__lift_map_10189(f, v, w, _uniq_n_10176, _uniq_i_0_10002_10180, _ctx); return kk_Unit;
}
 
// lifted local: map, @spec-x10182
// specialized: std/core/vector/@lift-forz@1011, on parameters @uniq-action@10175, using:
// @uniq-action@10175 = fn<(e :: E)>(i@0: ssize_t){
//   val x@10027 : a
//         = std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, index : ssize_t) -> a,(v : (vector :: V -> V)<a>, index : ssize_t) -> (e :: E) a>((std/core/vector/unsafe-idx<a>))(v, i@0);
//   std/core/types/@open<(total :: E),(e :: E),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (),(v : (vector :: V -> V)<a>, i : ssize_t, x : a) -> (e :: E) ()>((std/core/vector/unsafe-assign<a>))(w, i@0, (f(x@10027)));
// }


// lift anonymous function
struct kk_std_core_vector__lift_map_10189_fun130__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_vector_t v_0;
  kk_vector_t w_0;
  kk_ssize_t _uniq_i_10177_0;
  kk_ssize_t _uniq_n_10176_0;
};
static kk_box_t kk_std_core_vector__lift_map_10189_fun130(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector__new_lift_map_10189_fun130(kk_function_t f_0, kk_vector_t v_0, kk_vector_t w_0, kk_ssize_t _uniq_i_10177_0, kk_ssize_t _uniq_n_10176_0, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_map_10189_fun130__t* _self = kk_function_alloc_as(struct kk_std_core_vector__lift_map_10189_fun130__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector__lift_map_10189_fun130, kk_context());
  _self->f_0 = f_0;
  _self->v_0 = v_0;
  _self->w_0 = w_0;
  _self->_uniq_i_10177_0 = _uniq_i_10177_0;
  _self->_uniq_n_10176_0 = _uniq_n_10176_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector__lift_map_10189_fun130(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_vector__lift_map_10189_fun130__t* _self = kk_function_as(struct kk_std_core_vector__lift_map_10189_fun130__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (901) -> 903 902 */
  kk_vector_t v_0 = _self->v_0; /* vector<901> */
  kk_vector_t w_0 = _self->w_0; /* vector<902> */
  kk_ssize_t _uniq_i_10177_0 = _self->_uniq_i_10177_0; /* ssize_t */
  kk_ssize_t _uniq_n_10176_0 = _self->_uniq_n_10176_0; /* ssize_t */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_vector_dup(v_0, _ctx);kk_vector_dup(w_0, _ctx);kk_skip_dup(_uniq_i_10177_0, _ctx);kk_skip_dup(_uniq_n_10176_0, _ctx);}, {}, _ctx)
  kk_box_t _y_x10247_0_43 = _b_x41; /*902*/;
  kk_unit_t _x_x131 = kk_Unit;
  kk_std_core_vector__mlift_lift_map_10189_10260(_uniq_i_10177_0, _uniq_n_10176_0, f_0, v_0, w_0, _y_x10247_0_43, _ctx);
  return kk_unit_box(_x_x131);
}

kk_unit_t kk_std_core_vector__lift_map_10189(kk_function_t f_0, kk_vector_t v_0, kk_vector_t w_0, kk_ssize_t _uniq_n_10176_0, kk_ssize_t _uniq_i_10177_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, v : vector<a>, w : vector<b>, ssize_t, ssize_t) -> e () */ 
  kk__tailcall: ;
  bool _match_x50 = (_uniq_i_10177_0 < _uniq_n_10176_0); /*bool*/;
  if (_match_x50) {
    kk_box_t x_10027 = kk_vector_at_borrow(v_0,_uniq_i_10177_0,kk_context()); /*901*/;
    kk_box_t x_10291;
    kk_function_t _x_x128 = kk_function_dup(f_0, _ctx); /*(901) -> 903 902*/
    x_10291 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x128, (_x_x128, x_10027, _ctx), _ctx); /*902*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10291, _ctx);
      kk_box_t _x_x129 = kk_std_core_hnd_yield_extend(kk_std_core_vector__new_lift_map_10189_fun130(f_0, v_0, w_0, _uniq_i_10177_0, _uniq_n_10176_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x129); return kk_Unit;
    }
    {
      kk_unit_t _uniq_x___10179_0 = kk_Unit;
      kk_vector_t _x_x132 = kk_vector_dup(w_0, _ctx); /*vector<902>*/
      kk_vector_unsafe_assign(_x_x132,_uniq_i_10177_0,x_10291,kk_context());
      kk_ssize_t _uniq_i_0_10002_10180_0 = kk_std_core_vector_ssize__t_fs_incr(_uniq_i_10177_0, _ctx); /*ssize_t*/;
      { // tailcall
        _uniq_i_10177_0 = _uniq_i_0_10002_10180_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_vector_drop(w_0, _ctx);
    kk_vector_drop(v_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Apply a function `f` to each element in a vector `v`


// lift anonymous function
struct kk_std_core_vector_map_fun138__t {
  struct kk_function_s _base;
  kk_vector_t w;
};
static kk_box_t kk_std_core_vector_map_fun138(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_std_core_vector_new_map_fun138(kk_vector_t w, kk_context_t* _ctx) {
  struct kk_std_core_vector_map_fun138__t* _self = kk_function_alloc_as(struct kk_std_core_vector_map_fun138__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_vector_map_fun138, kk_context());
  _self->w = w;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_vector_map_fun138(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_std_core_vector_map_fun138__t* _self = kk_function_as(struct kk_std_core_vector_map_fun138__t*, _fself, _ctx);
  kk_vector_t w = _self->w; /* vector<902> */
  kk_drop_match(_self, {kk_vector_dup(w, _ctx);}, {}, _ctx)
  kk_unit_t wild___47 = kk_Unit;
  kk_unit_unbox(_b_x45);
  return kk_vector_box(w, _ctx);
}

kk_vector_t kk_std_core_vector_map(kk_vector_t v, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (v : vector<a>, f : (a) -> e b) -> e vector<b> */ 
  kk_vector_t w;
  kk_ssize_t _x_x133;
  kk_integer_t _x_x134;
  kk_ssize_t _x_x135 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/
  _x_x134 = kk_integer_from_ssize_t(_x_x135,kk_context()); /*int*/
  _x_x133 = kk_std_core_int_ssize__t(_x_x134, _ctx); /*ssize_t*/
  w = kk_vector_alloc(_x_x133,kk_box_null(),kk_context()); /*vector<902>*/
  kk_ssize_t n_10020 = kk_vector_len_borrow(v,kk_context()); /*ssize_t*/;
  kk_ssize_t i = (KK_IZ(0)); /*ssize_t*/;
  kk_unit_t x_10294 = kk_Unit;
  kk_vector_t _x_x136 = kk_vector_dup(w, _ctx); /*vector<902>*/
  kk_std_core_vector__lift_map_10189(f, v, _x_x136, n_10020, i, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x137 = kk_std_core_hnd_yield_extend(kk_std_core_vector_new_map_fun138(w, _ctx), _ctx); /*2419*/
    return kk_vector_unbox(_x_x137, _ctx);
  }
  {
    return w;
  }
}
 
// Convert a vector to a list with an optional tail.

kk_std_core_types__list kk_std_core_vector_vlist(kk_vector_t v, kk_std_core_types__optional tail, kk_context_t* _ctx) { /* forall<a> (v : vector<a>, tail : ? (list<a>)) -> list<a> */ 
  kk_std_core_types__list _x_x139;
  if (kk_std_core_types__is_Optional(tail, _ctx)) {
    kk_box_t _box_x48 = tail._cons._Optional.value;
    kk_std_core_types__list _uniq_tail_919 = kk_std_core_types__list_unbox(_box_x48, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_tail_919, _ctx);
    kk_std_core_types__optional_drop(tail, _ctx);
    _x_x139 = _uniq_tail_919; /*list<935>*/
  }
  else {
    kk_std_core_types__optional_drop(tail, _ctx);
    _x_x139 = kk_std_core_types__new_Nil(_ctx); /*list<935>*/
  }
  return kk_vector_to_list(v,_x_x139,kk_context());
}

kk_vector_t kk_std_core_vector_unvlist(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> vector<a> */ 
  return kk_list_to_vector(xs,kk_context());
}

bool kk_std_core_vector_ssize__t_fs_is_zero(kk_ssize_t i, kk_context_t* _ctx) { /* (i : ssize_t) -> bool */ 
  return (i == 0);
}

// initialization
void kk_std_core_vector__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_int__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_vector__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_int__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
