// Koka generated module: std/core, koka version: 3.2.3, platform: 64-bit
#include "std_core.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_box_t kk_main_console( kk_function_t action, kk_context_t* ctx ) {
  return kk_function_call(kk_box_t,(kk_function_t,kk_unit_t,kk_context_t*),action,(action,kk_Unit,ctx),ctx);
}


 
// Compose two functions `f` and `g`.


// lift anonymous function
struct kk_std_core_o_fun122__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t g;
};
static kk_box_t kk_std_core_o_fun122(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_o_fun122(kk_function_t f, kk_function_t g, kk_context_t* _ctx) {
  struct kk_std_core_o_fun122__t* _self = kk_function_alloc_as(struct kk_std_core_o_fun122__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_o_fun122, kk_context());
  _self->f = f;
  _self->g = g;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_o_fun122(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_core_o_fun122__t* _self = kk_function_as(struct kk_std_core_o_fun122__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (241) -> 244 242 */
  kk_function_t g = _self->g; /* (243) -> 244 241 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_function_dup(g, _ctx);}, {}, _ctx)
  kk_box_t x_0_10209 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), g, (g, x, _ctx), _ctx); /*241*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_0_10209, _ctx);
    return kk_std_core_hnd_yield_extend(f, _ctx);
  }
  {
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x_0_10209, _ctx), _ctx);
  }
}

kk_function_t kk_std_core_o(kk_function_t f, kk_function_t g, kk_context_t* _ctx) { /* forall<a,b,c,e> (f : (a) -> e b, g : (c) -> e a) -> ((x : c) -> e b) */ 
  return kk_std_core_new_o_fun122(f, g, _ctx);
}
extern kk_box_t kk_std_core_const_fun123(kk_function_t _fself, kk_box_t ___wildcard_x105__6, kk_context_t* _ctx) {
  struct kk_std_core_const_fun123__t* _self = kk_function_as(struct kk_std_core_const_fun123__t*, _fself, _ctx);
  kk_box_t kkloc_default = _self->kkloc_default; /* 286 */
  kk_drop_match(_self, {kk_box_dup(kkloc_default, _ctx);}, {}, _ctx)
  kk_box_drop(___wildcard_x105__6, _ctx);
  return kkloc_default;
}
 
// monadic lift

kk_unit_t kk_std_core__mlift_while_10196(kk_function_t action, kk_function_t predicate, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, wild_ : ()) -> <div|e> () */ 
  kk_std_core_while(predicate, action, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core__mlift_while_10197_fun126__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_function_t predicate_0;
};
static kk_box_t kk_std_core__mlift_while_10197_fun126(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_mlift_while_10197_fun126(kk_function_t action_0, kk_function_t predicate_0, kk_context_t* _ctx) {
  struct kk_std_core__mlift_while_10197_fun126__t* _self = kk_function_alloc_as(struct kk_std_core__mlift_while_10197_fun126__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__mlift_while_10197_fun126, kk_context());
  _self->action_0 = action_0;
  _self->predicate_0 = predicate_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__mlift_while_10197_fun126(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  struct kk_std_core__mlift_while_10197_fun126__t* _self = kk_function_as(struct kk_std_core__mlift_while_10197_fun126__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* () -> <div|335> () */
  kk_function_t predicate_0 = _self->predicate_0; /* () -> <div|335> bool */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_function_dup(predicate_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_3 = kk_Unit;
  kk_unit_unbox(_b_x1);
  kk_unit_t _x_x127 = kk_Unit;
  kk_std_core__mlift_while_10196(action_0, predicate_0, wild___0_3, _ctx);
  return kk_unit_box(_x_x127);
}

kk_unit_t kk_std_core__mlift_while_10197(kk_function_t action_0, kk_function_t predicate_0, bool _y_x10137, kk_context_t* _ctx) { /* forall<e> (action : () -> <div|e> (), predicate : () -> <div|e> bool, bool) -> <div|e> () */ 
  if (_y_x10137) {
    kk_unit_t x_10211 = kk_Unit;
    kk_function_t _x_x124 = kk_function_dup(action_0, _ctx); /*() -> <div|335> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x_x124, (_x_x124, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x125 = kk_std_core_hnd_yield_extend(kk_std_core__new_mlift_while_10197_fun126(action_0, predicate_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x125); return kk_Unit;
    }
    {
      kk_std_core__mlift_while_10196(action_0, predicate_0, x_10211, _ctx); return kk_Unit;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// The `while` fun executes `action`  as long as `pred`  is `true`.


// lift anonymous function
struct kk_std_core_while_fun130__t {
  struct kk_function_s _base;
  kk_function_t action_1;
  kk_function_t predicate_1;
};
static kk_box_t kk_std_core_while_fun130(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun130(kk_function_t action_1, kk_function_t predicate_1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun130__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun130__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_while_fun130, kk_context());
  _self->action_1 = action_1;
  _self->predicate_1 = predicate_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_while_fun130(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_while_fun130__t* _self = kk_function_as(struct kk_std_core_while_fun130__t*, _fself, _ctx);
  kk_function_t action_1 = _self->action_1; /* () -> <div|335> () */
  kk_function_t predicate_1 = _self->predicate_1; /* () -> <div|335> bool */
  kk_drop_match(_self, {kk_function_dup(action_1, _ctx);kk_function_dup(predicate_1, _ctx);}, {}, _ctx)
  bool _y_x10137_0_10 = kk_bool_unbox(_b_x5); /*bool*/;
  kk_unit_t _x_x131 = kk_Unit;
  kk_std_core__mlift_while_10197(action_1, predicate_1, _y_x10137_0_10, _ctx);
  return kk_unit_box(_x_x131);
}


// lift anonymous function
struct kk_std_core_while_fun134__t {
  struct kk_function_s _base;
  kk_function_t action_1;
  kk_function_t predicate_1;
};
static kk_box_t kk_std_core_while_fun134(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_core_new_while_fun134(kk_function_t action_1, kk_function_t predicate_1, kk_context_t* _ctx) {
  struct kk_std_core_while_fun134__t* _self = kk_function_alloc_as(struct kk_std_core_while_fun134__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_while_fun134, kk_context());
  _self->action_1 = action_1;
  _self->predicate_1 = predicate_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_while_fun134(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_std_core_while_fun134__t* _self = kk_function_as(struct kk_std_core_while_fun134__t*, _fself, _ctx);
  kk_function_t action_1 = _self->action_1; /* () -> <div|335> () */
  kk_function_t predicate_1 = _self->predicate_1; /* () -> <div|335> bool */
  kk_drop_match(_self, {kk_function_dup(action_1, _ctx);kk_function_dup(predicate_1, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_11 = kk_Unit;
  kk_unit_unbox(_b_x7);
  kk_unit_t _x_x135 = kk_Unit;
  kk_std_core__mlift_while_10196(action_1, predicate_1, wild___1_11, _ctx);
  return kk_unit_box(_x_x135);
}

kk_unit_t kk_std_core_while(kk_function_t predicate_1, kk_function_t action_1, kk_context_t* _ctx) { /* forall<e> (predicate : () -> <div|e> bool, action : () -> <div|e> ()) -> <div|e> () */ 
  kk__tailcall: ;
  bool x_0_10213;
  kk_function_t _x_x128 = kk_function_dup(predicate_1, _ctx); /*() -> <div|335> bool*/
  x_0_10213 = kk_function_call(bool, (kk_function_t, kk_context_t*), _x_x128, (_x_x128, _ctx), _ctx); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x129 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun130(action_1, predicate_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x129); return kk_Unit;
  }
  if (x_0_10213) {
    kk_unit_t x_1_10216 = kk_Unit;
    kk_function_t _x_x132 = kk_function_dup(action_1, _ctx); /*() -> <div|335> ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x_x132, (_x_x132, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x133 = kk_std_core_hnd_yield_extend(kk_std_core_new_while_fun134(action_1, predicate_1, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x133); return kk_Unit;
    }
    { // tailcall
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_1, _ctx);
    kk_function_drop(action_1, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Generic equality if `cmp` exists


// lift anonymous function
struct kk_std_core_default_fs_cmp_fs__lp__at_x_fun137__t_eq__eq__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun137_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun137_eq__eq__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs_cmp_fs__lp__at_x_fun137_eq__eq__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun137_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__order _y_x10141_15 = kk_std_core_types__order_unbox(_b_x13, KK_OWNED, _ctx); /*order*/;
  bool _x_x138;
  if (kk_std_core_types__is_Eq(_y_x10141_15, _ctx)) {
    _x_x138 = true; /*bool*/
  }
  else {
    _x_x138 = false; /*bool*/
  }
  return kk_bool_box(_x_x138);
}

bool kk_std_core_default_fs_cmp_fs__lp__eq__eq__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e bool */ 
  kk_std_core_types__order x_0_10219 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_cmp, (_implicit_fs_cmp, x, y, _ctx), _ctx); /*order*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x136 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun137_eq__eq__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x136);
  }
  if (kk_std_core_types__is_Eq(x_0_10219, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Generic inequality


// lift anonymous function
struct kk_std_core_default_fs__lp__at_x_fun140__t_excl__eq__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs__lp__at_x_fun140_excl__eq__rp_(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs__lp__at_new_x_fun140_excl__eq__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs__lp__at_x_fun140_excl__eq__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs__lp__at_x_fun140_excl__eq__rp_(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _y_x10142_19 = kk_bool_unbox(_b_x17); /*bool*/;
  bool _x_x141;
  if (_y_x10142_19) {
    _x_x141 = false; /*bool*/
  }
  else {
    _x_x141 = true; /*bool*/
  }
  return kk_bool_box(_x_x141);
}

bool kk_std_core_default_fs__lp__excl__eq__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?(==) : (a, a) -> e bool) -> e bool */ 
  bool x_0_10223 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs__lp__eq__eq__rp_, (_implicit_fs__lp__eq__eq__rp_, x, y, _ctx), _ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x139 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs__lp__at_new_x_fun140_excl__eq__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x139);
  }
  if (x_0_10223) {
    return false;
  }
  {
    return true;
  }
}
 
// Generic greater than


// lift anonymous function
struct kk_std_core_default_fs_cmp_fs__lp__at_x_fun144__t_gt__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun144_gt__rp_(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun144_gt__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs_cmp_fs__lp__at_x_fun144_gt__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun144_gt__rp_(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__order _y_x10143_23 = kk_std_core_types__order_unbox(_b_x21, KK_OWNED, _ctx); /*order*/;
  bool _x_x145;
  kk_integer_t _brw_x109;
  if (kk_std_core_types__is_Lt(_y_x10143_23, _ctx)) {
    _brw_x109 = kk_integer_from_small(-1); /*int*/
    goto _match_x146;
  }
  if (kk_std_core_types__is_Eq(_y_x10143_23, _ctx)) {
    _brw_x109 = kk_integer_from_small(0); /*int*/
    goto _match_x146;
  }
  {
    _brw_x109 = kk_integer_from_small(1); /*int*/
  }
  _match_x146: ;
  bool _brw_x110 = kk_integer_eq_borrow(_brw_x109,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x109, _ctx);
  _x_x145 = _brw_x110; /*bool*/
  return kk_bool_box(_x_x145);
}

bool kk_std_core_default_fs_cmp_fs__lp__gt__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e bool */ 
  kk_std_core_types__order x_0_10227 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_cmp, (_implicit_fs_cmp, x, y, _ctx), _ctx); /*order*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x143 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun144_gt__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x143);
  }
  {
    kk_integer_t _brw_x107;
    if (kk_std_core_types__is_Lt(x_0_10227, _ctx)) {
      _brw_x107 = kk_integer_from_small(-1); /*int*/
      goto _match_x147;
    }
    if (kk_std_core_types__is_Eq(x_0_10227, _ctx)) {
      _brw_x107 = kk_integer_from_small(0); /*int*/
      goto _match_x147;
    }
    {
      _brw_x107 = kk_integer_from_small(1); /*int*/
    }
    _match_x147: ;
    bool _brw_x108 = kk_integer_eq_borrow(_brw_x107,(kk_integer_from_small(1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x107, _ctx);
    return _brw_x108;
  }
}
 
// monadic lift

kk_box_t kk_std_core_range_fs__mlift_fold_10201(kk_integer_t end, kk_function_t f, kk_integer_t start, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (end : int, f : (int, a) -> e a, start : int, x : a) -> e a */ 
  kk_integer_t _x_x148 = kk_integer_add_small_const(start, 1, _ctx); /*int*/
  return kk_std_core_range_fs_fold(_x_x148, end, x, f, _ctx);
}
 
// Fold over the integers between [`start`,`end`] (including `end`).


// lift anonymous function
struct kk_std_core_range_fs_fold_fun151__t {
  struct kk_function_s _base;
  kk_integer_t end_0;
  kk_function_t f_0;
  kk_integer_t start_0;
};
static kk_box_t kk_std_core_range_fs_fold_fun151(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs_new_fold_fun151(kk_integer_t end_0, kk_function_t f_0, kk_integer_t start_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_fun151__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs_fold_fun151__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs_fold_fun151, kk_context());
  _self->end_0 = end_0;
  _self->f_0 = f_0;
  _self->start_0 = start_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs_fold_fun151(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_fun151__t* _self = kk_function_as(struct kk_std_core_range_fs_fold_fun151__t*, _fself, _ctx);
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_function_t f_0 = _self->f_0; /* (int, 811) -> 812 811 */
  kk_integer_t start_0 = _self->start_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(end_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(start_0, _ctx);}, {}, _ctx)
  return kk_std_core_range_fs__mlift_fold_10201(end_0, f_0, start_0, x_1, _ctx);
}

kk_box_t kk_std_core_range_fs_fold(kk_integer_t start_0, kk_integer_t end_0, kk_box_t init, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,e> (start : int, end : int, init : a, f : (int, a) -> e a) -> e a */ 
  kk__tailcall: ;
  bool _match_x104 = kk_integer_gt_borrow(start_0,end_0,kk_context()); /*bool*/;
  if (_match_x104) {
    kk_integer_drop(start_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    return init;
  }
  {
    kk_box_t x_0_10231;
    kk_function_t _x_x150 = kk_function_dup(f_0, _ctx); /*(int, 811) -> 812 811*/
    kk_integer_t _x_x149 = kk_integer_dup(start_0, _ctx); /*int*/
    x_0_10231 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x150, (_x_x150, _x_x149, init, _ctx), _ctx); /*811*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10231, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_range_fs_new_fold_fun151(end_0, f_0, start_0, _ctx), _ctx);
    }
    { // tailcall
      kk_integer_t _x_x152 = kk_integer_add_small_const(start_0, 1, _ctx); /*int*/
      start_0 = _x_x152;
      init = x_0_10231;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_box_t kk_std_core_range_fs__mlift_fold_while_10202(kk_integer_t end, kk_function_t f, kk_box_t init, kk_integer_t start, kk_std_core_types__maybe _y_x10148, kk_context_t* _ctx) { /* forall<a,e> (end : int, f : (int, a) -> e maybe<a>, init : a, start : int, maybe<a>) -> e a */ 
  if (kk_std_core_types__is_Just(_y_x10148, _ctx)) {
    kk_box_t x = _y_x10148._cons.Just.value;
    kk_box_drop(init, _ctx);
    kk_integer_t _x_x154 = kk_integer_add_small_const(start, 1, _ctx); /*int*/
    return kk_std_core_range_fs_fold_while(_x_x154, end, x, f, _ctx);
  }
  {
    kk_integer_drop(start, _ctx);
    kk_function_drop(f, _ctx);
    kk_integer_drop(end, _ctx);
    return init;
  }
}
 
// Fold over the integers between [`start`,`end`] (including `end`) or until `f` returns `Nothing`


// lift anonymous function
struct kk_std_core_range_fs_fold_while_fun158__t {
  struct kk_function_s _base;
  kk_integer_t end_0;
  kk_function_t f_0;
  kk_box_t init_0;
  kk_integer_t start_0;
};
static kk_box_t kk_std_core_range_fs_fold_while_fun158(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs_new_fold_while_fun158(kk_integer_t end_0, kk_function_t f_0, kk_box_t init_0, kk_integer_t start_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_while_fun158__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs_fold_while_fun158__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs_fold_while_fun158, kk_context());
  _self->end_0 = end_0;
  _self->f_0 = f_0;
  _self->init_0 = init_0;
  _self->start_0 = start_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs_fold_while_fun158(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx) {
  struct kk_std_core_range_fs_fold_while_fun158__t* _self = kk_function_as(struct kk_std_core_range_fs_fold_while_fun158__t*, _fself, _ctx);
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_function_t f_0 = _self->f_0; /* (int, 948) -> 949 maybe<948> */
  kk_box_t init_0 = _self->init_0; /* 948 */
  kk_integer_t start_0 = _self->start_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(end_0, _ctx);kk_function_dup(f_0, _ctx);kk_box_dup(init_0, _ctx);kk_integer_dup(start_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x159 = kk_std_core_types__maybe_unbox(_b_x25, KK_OWNED, _ctx); /*maybe<948>*/
  return kk_std_core_range_fs__mlift_fold_while_10202(end_0, f_0, init_0, start_0, _x_x159, _ctx);
}

kk_box_t kk_std_core_range_fs_fold_while(kk_integer_t start_0, kk_integer_t end_0, kk_box_t init_0, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,e> (start : int, end : int, init : a, f : (int, a) -> e maybe<a>) -> e a */ 
  kk__tailcall: ;
  bool _match_x102 = kk_integer_gt_borrow(start_0,end_0,kk_context()); /*bool*/;
  if (_match_x102) {
    kk_integer_drop(start_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    return init_0;
  }
  {
    kk_std_core_types__maybe x_0_10234;
    kk_function_t _x_x157 = kk_function_dup(f_0, _ctx); /*(int, 948) -> 949 maybe<948>*/
    kk_integer_t _x_x155 = kk_integer_dup(start_0, _ctx); /*int*/
    kk_box_t _x_x156 = kk_box_dup(init_0, _ctx); /*948*/
    x_0_10234 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x157, (_x_x157, _x_x155, _x_x156, _ctx), _ctx); /*maybe<948>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10234, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_range_fs_new_fold_while_fun158(end_0, f_0, init_0, start_0, _ctx), _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10234, _ctx)) {
      kk_box_t x_1 = x_0_10234._cons.Just.value;
      kk_box_drop(init_0, _ctx);
      { // tailcall
        kk_integer_t _x_x160 = kk_integer_add_small_const(start_0, 1, _ctx); /*int*/
        start_0 = _x_x160;
        init_0 = x_1;
        goto kk__tailcall;
      }
    }
    {
      kk_integer_drop(start_0, _ctx);
      kk_function_drop(f_0, _ctx);
      kk_integer_drop(end_0, _ctx);
      return init_0;
    }
  }
}
 
// Generic lower than


// lift anonymous function
struct kk_std_core_default_fs_cmp_fs__lp__at_x_fun164__t_lt__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun164_lt__rp_(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun164_lt__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs_cmp_fs__lp__at_x_fun164_lt__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun164_lt__rp_(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__order _y_x10153_31 = kk_std_core_types__order_unbox(_b_x29, KK_OWNED, _ctx); /*order*/;
  bool _x_x165;
  kk_integer_t _brw_x98;
  if (kk_std_core_types__is_Lt(_y_x10153_31, _ctx)) {
    _brw_x98 = kk_integer_from_small(-1); /*int*/
    goto _match_x166;
  }
  if (kk_std_core_types__is_Eq(_y_x10153_31, _ctx)) {
    _brw_x98 = kk_integer_from_small(0); /*int*/
    goto _match_x166;
  }
  {
    _brw_x98 = kk_integer_from_small(1); /*int*/
  }
  _match_x166: ;
  bool _brw_x99 = kk_integer_eq_borrow(_brw_x98,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x98, _ctx);
  _x_x165 = _brw_x99; /*bool*/
  return kk_bool_box(_x_x165);
}

bool kk_std_core_default_fs_cmp_fs__lp__lt__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e bool */ 
  kk_std_core_types__order x_0_10237 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_cmp, (_implicit_fs_cmp, x, y, _ctx), _ctx); /*order*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x163 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun164_lt__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x163);
  }
  {
    kk_integer_t _brw_x96;
    if (kk_std_core_types__is_Lt(x_0_10237, _ctx)) {
      _brw_x96 = kk_integer_from_small(-1); /*int*/
      goto _match_x167;
    }
    if (kk_std_core_types__is_Eq(x_0_10237, _ctx)) {
      _brw_x96 = kk_integer_from_small(0); /*int*/
      goto _match_x167;
    }
    {
      _brw_x96 = kk_integer_from_small(1); /*int*/
    }
    _match_x167: ;
    bool _brw_x97 = kk_integer_eq_borrow(_brw_x96,(kk_integer_from_small(-1)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x96, _ctx);
    return _brw_x97;
  }
}
 
// Generic greater than or equal


// lift anonymous function
struct kk_std_core_default_fs_cmp_fs__lp__at_x_fun169__t_gt__eq__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun169_gt__eq__rp_(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun169_gt__eq__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs_cmp_fs__lp__at_x_fun169_gt__eq__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun169_gt__eq__rp_(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _y_x10154_35 = kk_bool_unbox(_b_x33); /*bool*/;
  bool _x_x170;
  if (_y_x10154_35) {
    _x_x170 = false; /*bool*/
  }
  else {
    _x_x170 = true; /*bool*/
  }
  return kk_bool_box(_x_x170);
}

bool kk_std_core_default_fs_cmp_fs__lp__gt__eq__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e bool */ 
  bool x_0_10241 = kk_std_core_default_fs_cmp_fs__lp__lt__rp_(x, y, _implicit_fs_cmp, _ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x168 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun169_gt__eq__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x168);
  }
  if (x_0_10241) {
    return false;
  }
  {
    return true;
  }
}
 
// Generic lower than or equal


// lift anonymous function
struct kk_std_core_default_fs_cmp_fs__lp__at_x_fun172__t_lt__eq__rp_ {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun172_lt__eq__rp_(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun172_lt__eq__rp_(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_default_fs_cmp_fs__lp__at_x_fun172_lt__eq__rp_, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_default_fs_cmp_fs__lp__at_x_fun172_lt__eq__rp_(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _y_x10155_39 = kk_bool_unbox(_b_x37); /*bool*/;
  bool _x_x173;
  if (_y_x10155_39) {
    _x_x173 = false; /*bool*/
  }
  else {
    _x_x173 = true; /*bool*/
  }
  return kk_bool_box(_x_x173);
}

bool kk_std_core_default_fs_cmp_fs__lp__lt__eq__rp_(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e bool */ 
  bool x_0_10245 = kk_std_core_default_fs_cmp_fs__lp__gt__rp_(x, y, _implicit_fs_cmp, _ctx); /*bool*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x171 = kk_std_core_hnd_yield_extend(kk_std_core_default_fs_cmp_fs__lp__at_new_x_fun172_lt__eq__rp_(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x171);
  }
  if (x_0_10245) {
    return false;
  }
  {
    return true;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_range_fs__mlift_lift_for_1901_10206(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int, wild_ : ()) -> e () */ 
  kk_integer_t i_0_10000 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
  kk_std_core_range_fs__lift_for_1901(action, end, i_0_10000, _ctx); return kk_Unit;
}
 
// lifted local: range/for, rep


// lift anonymous function
struct kk_std_core_range_fs__lift_for_1901_fun177__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_integer_t end_0;
  kk_integer_t i_0;
};
static kk_box_t kk_std_core_range_fs__lift_for_1901_fun177(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs__new_lift_for_1901_fun177(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_1901_fun177__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs__lift_for_1901_fun177__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs__lift_for_1901_fun177, kk_context());
  _self->action_0 = action_0;
  _self->end_0 = end_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs__lift_for_1901_fun177(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_1901_fun177__t* _self = kk_function_as(struct kk_std_core_range_fs__lift_for_1901_fun177__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (int) -> 1326 () */
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_integer_dup(end_0, _ctx);kk_integer_dup(i_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_43 = kk_Unit;
  kk_unit_unbox(_b_x41);
  kk_unit_t _x_x178 = kk_Unit;
  kk_std_core_range_fs__mlift_lift_for_1901_10206(action_0, end_0, i_0, wild___0_43, _ctx);
  return kk_unit_box(_x_x178);
}

kk_unit_t kk_std_core_range_fs__lift_for_1901(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<e> (action : (int) -> e (), end : int, i : int) -> e () */ 
  kk__tailcall: ;
  bool _match_x91 = kk_integer_lte_borrow(i_0,end_0,kk_context()); /*bool*/;
  if (_match_x91) {
    kk_unit_t x_10249 = kk_Unit;
    kk_function_t _x_x175 = kk_function_dup(action_0, _ctx); /*(int) -> 1326 ()*/
    kk_integer_t _x_x174 = kk_integer_dup(i_0, _ctx); /*int*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x175, (_x_x175, _x_x174, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x176 = kk_std_core_hnd_yield_extend(kk_std_core_range_fs__new_lift_for_1901_fun177(action_0, end_0, i_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x176); return kk_Unit;
    }
    {
      kk_integer_t i_0_10000_0 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
      { // tailcall
        i_0 = i_0_10000_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core__mlift_lift_repeat_10129_10207(kk_integer_t _uniq_end_10120, kk_integer_t _uniq_i_10121, kk_function_t action, kk_unit_t _uniq_x___10123, kk_context_t* _ctx) { /* forall<e> (int, int, action : () -> e (), ()) -> e () */ 
  kk_integer_t _uniq_i_0_10000_10125 = kk_integer_add_small_const(_uniq_i_10121, 1, _ctx); /*int*/;
  kk_std_core__lift_repeat_10129(action, _uniq_end_10120, _uniq_i_0_10000_10125, _ctx); return kk_Unit;
}
 
// lifted local: repeat, @spec-x10127
// specialized: std/core/#range/@lift-for@1901, on parameters @uniq-action@10119, using:
// @uniq-action@10119 = fn<(e :: E)>(i@0: int){
//   action();
// }


// lift anonymous function
struct kk_std_core__lift_repeat_10129_fun183__t {
  struct kk_function_s _base;
  kk_integer_t _uniq_end_10120_0;
  kk_integer_t _uniq_i_10121_0;
  kk_function_t action_0;
};
static kk_box_t kk_std_core__lift_repeat_10129_fun183(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_lift_repeat_10129_fun183(kk_integer_t _uniq_end_10120_0, kk_integer_t _uniq_i_10121_0, kk_function_t action_0, kk_context_t* _ctx) {
  struct kk_std_core__lift_repeat_10129_fun183__t* _self = kk_function_alloc_as(struct kk_std_core__lift_repeat_10129_fun183__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__lift_repeat_10129_fun183, kk_context());
  _self->_uniq_end_10120_0 = _uniq_end_10120_0;
  _self->_uniq_i_10121_0 = _uniq_i_10121_0;
  _self->action_0 = action_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__lift_repeat_10129_fun183(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_std_core__lift_repeat_10129_fun183__t* _self = kk_function_as(struct kk_std_core__lift_repeat_10129_fun183__t*, _fself, _ctx);
  kk_integer_t _uniq_end_10120_0 = _self->_uniq_end_10120_0; /* int */
  kk_integer_t _uniq_i_10121_0 = _self->_uniq_i_10121_0; /* int */
  kk_function_t action_0 = _self->action_0; /* () -> 1371 () */
  kk_drop_match(_self, {kk_integer_dup(_uniq_end_10120_0, _ctx);kk_integer_dup(_uniq_i_10121_0, _ctx);kk_function_dup(action_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10123_0_47 = kk_Unit;
  kk_unit_unbox(_b_x45);
  kk_unit_t _x_x184 = kk_Unit;
  kk_std_core__mlift_lift_repeat_10129_10207(_uniq_end_10120_0, _uniq_i_10121_0, action_0, _uniq_x___10123_0_47, _ctx);
  return kk_unit_box(_x_x184);
}

kk_unit_t kk_std_core__lift_repeat_10129(kk_function_t action_0, kk_integer_t _uniq_end_10120_0, kk_integer_t _uniq_i_10121_0, kk_context_t* _ctx) { /* forall<e> (action : () -> e (), int, int) -> e () */ 
  kk__tailcall: ;
  bool _match_x89 = kk_integer_lte_borrow(_uniq_i_10121_0,_uniq_end_10120_0,kk_context()); /*bool*/;
  if (_match_x89) {
    kk_unit_t x_10252 = kk_Unit;
    kk_function_t _x_x181 = kk_function_dup(action_0, _ctx); /*() -> 1371 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), _x_x181, (_x_x181, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x182 = kk_std_core_hnd_yield_extend(kk_std_core__new_lift_repeat_10129_fun183(_uniq_end_10120_0, _uniq_i_10121_0, action_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x182); return kk_Unit;
    }
    {
      kk_integer_t _uniq_i_0_10000_10125_0 = kk_integer_add_small_const(_uniq_i_10121_0, 1, _ctx); /*int*/;
      { // tailcall
        _uniq_i_10121_0 = _uniq_i_0_10000_10125_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_integer_drop(_uniq_i_10121_0, _ctx);
    kk_integer_drop(_uniq_end_10120_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_range_fs__mlift_lift_for_while_1902_10208(kk_function_t action, kk_integer_t end, kk_integer_t i, kk_std_core_types__maybe _y_x10165, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10165, _ctx)) {
    kk_integer_t i_0_10009 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
    return kk_std_core_range_fs__lift_for_while_1902(action, end, i_0_10009, _ctx);
  }
  {
    kk_box_t x = _y_x10165._cons.Just.value;
    kk_integer_drop(i, _ctx);
    kk_integer_drop(end, _ctx);
    kk_function_drop(action, _ctx);
    return kk_std_core_types__new_Just(x, _ctx);
  }
}
 
// lifted local: range/for-while, rep


// lift anonymous function
struct kk_std_core_range_fs__lift_for_while_1902_fun189__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_integer_t end_0;
  kk_integer_t i_0;
};
static kk_box_t kk_std_core_range_fs__lift_for_while_1902_fun189(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_core_range_fs__new_lift_for_while_1902_fun189(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_while_1902_fun189__t* _self = kk_function_alloc_as(struct kk_std_core_range_fs__lift_for_while_1902_fun189__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_range_fs__lift_for_while_1902_fun189, kk_context());
  _self->action_0 = action_0;
  _self->end_0 = end_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_range_fs__lift_for_while_1902_fun189(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  struct kk_std_core_range_fs__lift_for_while_1902_fun189__t* _self = kk_function_as(struct kk_std_core_range_fs__lift_for_while_1902_fun189__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (int) -> 1469 maybe<1468> */
  kk_integer_t end_0 = _self->end_0; /* int */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_integer_dup(end_0, _ctx);kk_integer_dup(i_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10165_0_51 = kk_std_core_types__maybe_unbox(_b_x49, KK_OWNED, _ctx); /*maybe<1468>*/;
  kk_std_core_types__maybe _x_x190 = kk_std_core_range_fs__mlift_lift_for_while_1902_10208(action_0, end_0, i_0, _y_x10165_0_51, _ctx); /*maybe<1468>*/
  return kk_std_core_types__maybe_box(_x_x190, _ctx);
}

kk_std_core_types__maybe kk_std_core_range_fs__lift_for_while_1902(kk_function_t action_0, kk_integer_t end_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,e> (action : (int) -> e maybe<a>, end : int, i : int) -> e maybe<a> */ 
  kk__tailcall: ;
  bool _match_x87 = kk_integer_lte_borrow(i_0,end_0,kk_context()); /*bool*/;
  if (_match_x87) {
    kk_std_core_types__maybe x_0_10255;
    kk_function_t _x_x187 = kk_function_dup(action_0, _ctx); /*(int) -> 1469 maybe<1468>*/
    kk_integer_t _x_x186 = kk_integer_dup(i_0, _ctx); /*int*/
    x_0_10255 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_integer_t, kk_context_t*), _x_x187, (_x_x187, _x_x186, _ctx), _ctx); /*maybe<1468>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10255, _ctx);
      kk_box_t _x_x188 = kk_std_core_hnd_yield_extend(kk_std_core_range_fs__new_lift_for_while_1902_fun189(action_0, end_0, i_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x188, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10255, _ctx)) {
      kk_integer_t i_0_10009_0 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
      { // tailcall
        i_0 = i_0_10009_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t x_1 = x_0_10255._cons.Just.value;
      kk_integer_drop(i_0, _ctx);
      kk_integer_drop(end_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return kk_std_core_types__new_Just(x_1, _ctx);
    }
  }
  {
    kk_integer_drop(i_0, _ctx);
    kk_integer_drop(end_0, _ctx);
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Used by the compiler to wrap main console applications

kk_box_t kk_std_core_main_console(kk_function_t main, kk_context_t* _ctx) { /* forall<a,e> (main : () -> e a) -> e a */ 
  return kk_main_console(main,kk_context());
}
 
// Return the host environment: `dotnet`, `browser`, `webworker`, `node`, or `libc`.

kk_string_t kk_std_core_host(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_get_host(kk_context());
}
 
// The default exception handler


// lift anonymous function
struct kk_std_core__default_exn_fun192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun192(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_core__default_exn_fun193__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core__default_exn_fun193(kk_function_t _fself, kk_function_t _b_x56, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun193(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun193__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun193__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun193, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core__default_exn_fun194__t {
  struct kk_function_s _base;
  kk_function_t _b_x56;
};
static kk_unit_t kk_std_core__default_exn_fun194(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x57, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun194(kk_function_t _b_x56, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun194__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun194__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun194, kk_context());
  _self->_b_x56 = _b_x56;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_std_core__default_exn_fun194(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x57, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun194__t* _self = kk_function_as(struct kk_std_core__default_exn_fun194__t*, _fself, _ctx);
  kk_function_t _b_x56 = _self->_b_x56; /* (hnd/resume-result<2716,2719>) -> 2718 2719 */
  kk_drop_match(_self, {kk_function_dup(_b_x56, _ctx);}, {}, _ctx)
  kk_box_t _x_x195 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x56, (_b_x56, _b_x57, _ctx), _ctx); /*2719*/
  kk_unit_unbox(_x_x195); return kk_Unit;
}


// lift anonymous function
struct kk_std_core__default_exn_fun200__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun200(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun200(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun200, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core__default_exn_fun200(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x201 = kk_Unit;
  kk_string_t _x_x202 = kk_string_unbox(_b_x53); /*string*/
  kk_std_core_console_printsln(_x_x202, _ctx);
  return kk_unit_box(_x_x201);
}
static kk_box_t kk_std_core__default_exn_fun193(kk_function_t _fself, kk_function_t _b_x56, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun193__t* _self = kk_function_as(struct kk_std_core__default_exn_fun193__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x654__45_73 = kk_std_core__new_default_exn_fun194(_b_x56, _ctx); /*(hnd/resume-result<1724,()>) -> <console/console|1738> ()*/;
  kk_function_drop(___wildcard_x654__45_73, _ctx);
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x196;
  kk_define_string_literal(static, _s_x197, 20, "uncaught exception: ", _ctx)
  _x_x196 = kk_string_dup(_s_x197, _ctx); /*string*/
  kk_std_core_console_prints(_x_x196, _ctx);
  kk_string_t x_0_10259 = kk_std_core_exn_show(x, _ctx); /*string*/;
  kk_unit_t _x_x198 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10259, _ctx);
    kk_box_t _x_x199 = kk_std_core_hnd_yield_extend(kk_std_core__new_default_exn_fun200(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x199);
  }
  else {
    kk_std_core_console_printsln(x_0_10259, _ctx);
  }
  return kk_unit_box(_x_x198);
}
static kk_box_t kk_std_core__default_exn_fun192(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x654__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core__new_default_exn_fun193(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun205__t {
  struct kk_function_s _base;
  kk_function_t _b_x58_69;
};
static kk_box_t kk_std_core__default_exn_fun205(kk_function_t _fself, int32_t _b_x59, kk_std_core_hnd__ev _b_x60, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun205(kk_function_t _b_x58_69, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun205__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun205__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun205, kk_context());
  _self->_b_x58_69 = _b_x58_69;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__default_exn_fun205(kk_function_t _fself, int32_t _b_x59, kk_std_core_hnd__ev _b_x60, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun205__t* _self = kk_function_as(struct kk_std_core__default_exn_fun205__t*, _fself, _ctx);
  kk_function_t _b_x58_69 = _self->_b_x58_69; /* (m : hnd/marker<<console/console|1738>,()>, hnd/ev<exn>, x : exception) -> <console/console|1738> 1724 */
  kk_drop_match(_self, {kk_function_dup(_b_x58_69, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x206 = kk_std_core_exn__exception_unbox(_b_x61, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x58_69, (_b_x58_69, _b_x59, _b_x60, _x_x206, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core__default_exn_fun207__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core__default_exn_fun207(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun207(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core__default_exn_fun207, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core__default_exn_fun207(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _res_74 = kk_Unit;
  kk_unit_unbox(_b_x65);
  return kk_unit_box(_res_74);
}


// lift anonymous function
struct kk_std_core__default_exn_fun208__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core__default_exn_fun208(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core__new_default_exn_fun208(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun208__t* _self = kk_function_alloc_as(struct kk_std_core__default_exn_fun208__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core__default_exn_fun208, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core__default_exn_fun208(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core__default_exn_fun208__t* _self = kk_function_as(struct kk_std_core__default_exn_fun208__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <exn,console/console|1738> () */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_unit_t _x_x209 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx);
  return kk_unit_box(_x_x209);
}

kk_unit_t kk_std_core__default_exn(kk_function_t action, kk_context_t* _ctx) { /* forall<e> (action : () -> <exn,console/console|e> ()) -> <console/console|e> () */ 
  kk_box_t _x_x191;
  kk_function_t _b_x58_69 = kk_std_core__new_default_exn_fun192(_ctx); /*(m : hnd/marker<<console/console|1738>,()>, hnd/ev<exn>, x : exception) -> <console/console|1738> 1724*/;
  kk_std_core_exn__exn _x_x203;
  kk_std_core_hnd__clause1 _x_x204 = kk_std_core_hnd__new_Clause1(kk_std_core__new_default_exn_fun205(_b_x58_69, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x203 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x204, _ctx); /*exn<14,15>*/
  _x_x191 = kk_std_core_exn_exn_fs__handle(_x_x203, kk_std_core__new_default_exn_fun207(_ctx), kk_std_core__new_default_exn_fun208(action, _ctx), _ctx); /*198*/
  kk_unit_unbox(_x_x191); return kk_Unit;
}

kk_ref_t kk_std_core_unique_count;
 
// Returns a unique integer (modulo 32-bits).

kk_integer_t kk_std_core_unique(kk_context_t* _ctx) { /* () -> ndet int */ 
  kk_integer_t u;
  kk_box_t _x_x210;
  kk_ref_t _x_x211 = kk_ref_dup(kk_std_core_unique_count, _ctx); /*ref<global,int>*/
  _x_x210 = kk_ref_get(_x_x211,kk_context()); /*212*/
  u = kk_integer_unbox(_x_x210, _ctx); /*int*/
  kk_integer_t _b_x82_84;
  kk_integer_t _x_x212 = kk_integer_dup(u, _ctx); /*int*/
  _b_x82_84 = kk_integer_add_small_const(_x_x212, 1, _ctx); /*int*/
  kk_unit_t __ = kk_Unit;
  kk_ref_set_borrow(kk_std_core_unique_count,(kk_integer_box(_b_x82_84, _ctx)),kk_context());
  return u;
}

kk_std_core__stream kk_std_core_stream_fs__copy(kk_std_core__stream _this, kk_std_core_types__optional head, kk_std_core_types__optional tail, kk_context_t* _ctx) { /* forall<a> (stream<a>, head : ? a, tail : ? (stream<a>)) -> stream<a> */ 
  kk_box_t _x_x215;
  if (kk_std_core_types__is_Optional(head, _ctx)) {
    kk_box_t _uniq_head_1868 = head._cons._Optional.value;
    kk_box_dup(_uniq_head_1868, _ctx);
    kk_std_core_types__optional_drop(head, _ctx);
    _x_x215 = _uniq_head_1868; /*1895*/
  }
  else {
    kk_std_core_types__optional_drop(head, _ctx);
    {
      struct kk_std_core_Next* _con_x216 = kk_std_core__as_Next(_this, _ctx);
      kk_box_t _x = _con_x216->head;
      kk_box_dup(_x, _ctx);
      _x_x215 = _x; /*1895*/
    }
  }
  kk_std_core__stream _x_x217;
  if (kk_std_core_types__is_Optional(tail, _ctx)) {
    kk_box_t _box_x85 = tail._cons._Optional.value;
    kk_std_core__stream _uniq_tail_1879 = kk_std_core__stream_unbox(_box_x85, KK_BORROWED, _ctx);
    kk_std_core__stream_dup(_uniq_tail_1879, _ctx);
    kk_std_core_types__optional_drop(tail, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x217 = _uniq_tail_1879; /*stream<1895>*/
  }
  else {
    kk_std_core_types__optional_drop(tail, _ctx);
    {
      struct kk_std_core_Next* _con_x218 = kk_std_core__as_Next(_this, _ctx);
      kk_box_t _pat_0_1 = _con_x218->head;
      kk_std_core__stream _x_0 = _con_x218->tail;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_box_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_std_core__stream_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x217 = _x_0; /*stream<1895>*/
    }
  }
  return kk_std_core__new_Next(kk_reuse_null, 0, _x_x215, _x_x217, _ctx);
}

// initialization
void kk_std_core__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core_unique_count = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*ref<global,int>*/
  }
}

// termination
void kk_std_core__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_ref_drop(kk_std_core_unique_count, _ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
