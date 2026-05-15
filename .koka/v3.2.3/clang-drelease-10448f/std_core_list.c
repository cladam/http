// Koka generated module: std/core/list, koka version: 3.2.3, platform: 64-bit
#include "std_core_list.h"
 
// Return the head of list if the list is not empty.

kk_std_core_types__maybe kk_std_core_list_maybe_fs_head(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1472 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1472->head;
    kk_std_core_types__list _pat_0 = _con_x1472->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return kk_std_core_types__new_Just(x, _ctx);
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the head of list with a default value in case the list is empty.

kk_box_t kk_std_core_list_head(kk_std_core_types__list xs, kk_box_t kkloc_default, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, default : a) -> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1473 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1473->head;
    kk_std_core_types__list _pat_0 = _con_x1473->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__list_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_drop(kkloc_default, _ctx);
    return x;
  }
  {
    return kkloc_default;
  }
}
 
// Return the tail of list. Returns the empty list if `xs` is empty.

kk_std_core_types__list kk_std_core_list_tail(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1474 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_0 = _con_x1474->head;
    kk_std_core_types__list xx = _con_x1474->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    return xx;
  }
  {
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: length, len

kk_integer_t kk_std_core_list__unroll_lift_length_6003_10000(kk_std_core_types__list ys, kk_integer_t acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, acc : int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1475 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _pat_0 = _con_x1475->head;
    kk_std_core_types__list yy = _con_x1475->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(ys, _ctx);
    }
    else {
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x1476 = kk_integer_add_small_const(acc, 1, _ctx); /*int*/
      ys = yy;
      acc = _x_x1476;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// monadic lift

bool kk_std_core_list__lp__at_mlift_unroll_x_10001_10683_eq__eq__rp_(kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_std_core_types__list xx, kk_std_core_types__list yy, bool _y_x10422, kk_context_t* _ctx) { /* forall<a,e> (?(==) : (a, a) -> e bool, xx : list<a>, yy : list<a>, bool) -> e bool */ 
  if (_y_x10422) {
    return kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(xx, yy, _implicit_fs__lp__eq__eq__rp_, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// Element-wise list equality


// lift anonymous function
struct kk_std_core_list__lp__at_unroll_x_10001_fun1481__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__lp__at_unroll_x_10001_fun1481_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__lp__at_new_unroll_x_10001_fun1481_eq__eq__rp_(kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lp__at_unroll_x_10001_fun1481__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_list__lp__at_unroll_x_10001_fun1481__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lp__at_unroll_x_10001_fun1481_eq__eq__rp_, kk_context());
  _self->_implicit_fs__lp__at_x_0_eq__eq__rp_ = _implicit_fs__lp__at_x_0_eq__eq__rp_;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lp__at_unroll_x_10001_fun1481_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  struct kk_std_core_list__lp__at_unroll_x_10001_fun1481__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_list__lp__at_unroll_x_10001_fun1481__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_ = _self->_implicit_fs__lp__at_x_0_eq__eq__rp_; /* (813, 813) -> 814 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<813> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<813> */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10422_0_3 = kk_bool_unbox(_b_x1); /*bool*/;
  bool _x_x1482 = kk_std_core_list__lp__at_mlift_unroll_x_10001_10683_eq__eq__rp_(_implicit_fs__lp__at_x_0_eq__eq__rp_, xx_0, yy_0, _y_x10422_0_3, _ctx); /*bool*/
  return kk_bool_box(_x_x1482);
}

bool kk_std_core_list__lp__at_unroll_x_10001_eq__eq__rp_(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs__lp__at_x_0_eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ys : list<a>, ?(==) : (a, a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1477 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1477->head;
    kk_std_core_types__list xx_0 = _con_x1477->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
      return false;
    }
    {
      struct kk_std_core_types_Cons* _con_x1478 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1478->head;
      kk_std_core_types__list yy_0 = _con_x1478->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      bool x_0_10719;
      kk_function_t _x_x1479 = kk_function_dup(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx); /*(813, 813) -> 814 bool*/
      x_0_10719 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1479, (_x_x1479, x, y, _ctx), _ctx); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1480 = kk_std_core_hnd_yield_extend(kk_std_core_list__lp__at_new_unroll_x_10001_fun1481_eq__eq__rp_(_implicit_fs__lp__at_x_0_eq__eq__rp_, xx_0, yy_0, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x1480);
      }
      if (x_0_10719) { // tailcall
                       xs = xx_0;
                       ys = yy_0;
                       goto kk__tailcall;
      }
      {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs__lp__at_x_0_eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return true;
    }
    {
      struct kk_std_core_types_Cons* _con_x1483 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_7 = _con_x1483->head;
      kk_std_core_types__list _pat_8 = _con_x1483->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_8, _ctx);
        kk_box_drop(_pat_7, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return false;
    }
  }
}
 
// monadic lift

kk_std_core_types__order kk_std_core_list__mlift_unroll_cmp_10002_10684(kk_function_t _implicit_fs_cmp, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_std_core_types__order _y_x10429, kk_context_t* _ctx) { /* forall<a,e> (?cmp : (a, a) -> e order, xx : list<a>, yy : list<a>, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10429, _ctx)) {
    return kk_std_core_list__unroll_cmp_10002(xx, yy, _implicit_fs_cmp, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(_implicit_fs_cmp, _ctx);
    return _y_x10429;
  }
}
 
// Order on lists


// lift anonymous function
struct kk_std_core_list__unroll_cmp_10002_fun1489__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_cmp_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_cmp_10002_fun1489(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_cmp_10002_fun1489(kk_function_t _implicit_fs_cmp_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_cmp_10002_fun1489__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_cmp_10002_fun1489__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_cmp_10002_fun1489, kk_context());
  _self->_implicit_fs_cmp_0 = _implicit_fs_cmp_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_cmp_10002_fun1489(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_cmp_10002_fun1489__t* _self = kk_function_as(struct kk_std_core_list__unroll_cmp_10002_fun1489__t*, _fself, _ctx);
  kk_function_t _implicit_fs_cmp_0 = _self->_implicit_fs_cmp_0; /* (909, 909) -> 910 order */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<909> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<909> */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_cmp_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10429_0_7 = kk_std_core_types__order_unbox(_b_x5, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1490 = kk_std_core_list__mlift_unroll_cmp_10002_10684(_implicit_fs_cmp_0, xx_0, yy_0, _y_x10429_0_7, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1490, _ctx);
}

kk_std_core_types__order kk_std_core_list__unroll_cmp_10002(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_cmp_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ys : list<a>, ?cmp : (a, a) -> e order) -> e order */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1485 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1485->head;
    kk_std_core_types__list xx_0 = _con_x1485->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs_cmp_0, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1486 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1486->head;
      kk_std_core_types__list yy_0 = _con_x1486->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__order x_0_10722;
      kk_function_t _x_x1487 = kk_function_dup(_implicit_fs_cmp_0, _ctx); /*(909, 909) -> 910 order*/
      x_0_10722 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1487, (_x_x1487, x, y, _ctx), _ctx); /*order*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1488 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_cmp_10002_fun1489(_implicit_fs_cmp_0, xx_0, yy_0, _ctx), _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x1488, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_0_10722, _ctx)) { // tailcall
                                                       xs = xx_0;
                                                       ys = yy_0;
                                                       goto kk__tailcall;
      }
      {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_function_drop(_implicit_fs_cmp_0, _ctx);
        return x_0_10722;
      }
    }
  }
  {
    kk_function_drop(_implicit_fs_cmp_0, _ctx);
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1491 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t _pat_6 = _con_x1491->head;
      kk_std_core_types__list _pat_7 = _con_x1491->tail;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        kk_std_core_types__list_drop(_pat_7, _ctx);
        kk_box_drop(_pat_6, _ctx);
        kk_datatype_ptr_free(ys, _ctx);
      }
      else {
        kk_datatype_ptr_decref(ys, _ctx);
      }
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list__trmc_take(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1493 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t x = _con_x1493->head;
      kk_std_core_types__list xx = _con_x1493->tail;
      kk_reuse_t _ru_x1394 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1394 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10361 = kk_datatype_null(); /*list<971>*/;
      kk_std_core_types__list _trmc_x10362 = kk_std_core_types__new_Cons(_ru_x1394, 0, x, _trmc_x10361, _ctx); /*list<971>*/;
      kk_field_addr_t _b_x13_18 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10362, _ctx)->tail, _ctx); /*@field-addr<list<971>>*/;
      { // tailcall
        kk_integer_t _x_x1494 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1495 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10362, _ctx)),_b_x13_18,kk_context()); /*ctx<0>*/
        xs = xx;
        n = _x_x1494;
        _acc = _x_x1495;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1496 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1496, KK_OWNED, _ctx);
  }
}
 
// Take the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_take(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1497 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_take(xs_0, n_0, _x_x1497, _ctx);
}
 
// Drop the first `n` elements of a list (or fewer if the list is shorter than `n`)

kk_std_core_types__list kk_std_core_list_drop(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1498 = kk_std_core_types__as_Cons(xs, _ctx);
    if (kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context())) {
      kk_box_t _pat_0 = _con_x1498->head;
      kk_std_core_types__list xx = _con_x1498->tail;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_box_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      { // tailcall
        kk_integer_t _x_x1499 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x1499;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return xs;
  }
}

kk_std_core_types__list kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__list acc, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (acc : list<a>, ys : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1500 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t x = _con_x1500->head;
    kk_std_core_types__list xx = _con_x1500->tail;
    kk_reuse_t _ru_x1396 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1396 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x1501 = kk_std_core_types__new_Cons(_ru_x1396, 0, x, acc, _ctx); /*list<79>*/
      acc = _x_x1501;
      ys = xx;
      goto kk__tailcall;
    }
  }
  {
    return acc;
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__trmc_unroll_append_10004(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1502 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1502->head;
    kk_std_core_types__list xx = _con_x1502->tail;
    kk_reuse_t _ru_x1397 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1397 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10363 = kk_datatype_null(); /*list<1132>*/;
    kk_std_core_types__list _trmc_x10364 = kk_std_core_types__new_Cons(_ru_x1397, 0, x, _trmc_x10363, _ctx); /*list<1132>*/;
    kk_field_addr_t _b_x29_34 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10364, _ctx)->tail, _ctx); /*@field-addr<list<1132>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1503 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10364, _ctx)),_b_x29_34,kk_context()); /*ctx<0>*/
      xs = xx;
      _acc = _x_x1503;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1504 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(ys, _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1504, KK_OWNED, _ctx);
  }
}
 
// Append two lists.

kk_std_core_types__list kk_std_core_list__unroll_append_10004(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1505 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_append_10004(xs_0, ys_0, _x_x1505, _ctx);
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_unroll_foldl_10005_10685(kk_function_t f, kk_std_core_types__list xx, kk_box_t _y_x10436, kk_context_t* _ctx) { /* forall<a,b,e> (f : (b, a) -> e b, xx : list<a>, b) -> e b */ 
  return kk_std_core_list__unroll_foldl_10005(xx, _y_x10436, f, _ctx);
}
 
// Fold a list from the left, i.e. `foldl([1,2],0,(+)) == (0+1)+2`
// Since `foldl` is tail recursive, it is preferred over `foldr` when using an associative function `f`


// lift anonymous function
struct kk_std_core_list__unroll_foldl_10005_fun1510__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1510(kk_function_t _fself, kk_box_t _y_x10436_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foldl_10005_fun1510(kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1510__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foldl_10005_fun1510__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foldl_10005_fun1510, kk_context());
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foldl_10005_fun1510(kk_function_t _fself, kk_box_t _y_x10436_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foldl_10005_fun1510__t* _self = kk_function_as(struct kk_std_core_list__unroll_foldl_10005_fun1510__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1203, 1202) -> 1204 1203 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1202> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_unroll_foldl_10005_10685(f_0, xx_0, _y_x10436_0, _ctx);
}

kk_box_t kk_std_core_list__unroll_foldl_10005(kk_std_core_types__list xs, kk_box_t z, kk_function_t f_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, z : b, f : (b, a) -> e b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1508 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1508->head;
    kk_std_core_types__list xx_0 = _con_x1508->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10729;
    kk_function_t _x_x1509 = kk_function_dup(f_0, _ctx); /*(1203, 1202) -> 1204 1203*/
    x_0_10729 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1509, (_x_x1509, z, x, _ctx), _ctx); /*1203*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10729, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foldl_10005_fun1510(f_0, xx_0, _ctx), _ctx);
    }
    { // tailcall
      xs = xx_0;
      z = x_0_10729;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return z;
  }
}
 
// monadic lift

kk_box_t kk_std_core_list__mlift_lift_foldr_10345_10686(kk_std_core_types__list _uniq_xx_10270, kk_function_t f, kk_box_t _uniq_z_10266_0_10355, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, f : (a, b) -> e b, b) -> e b */ 
  return kk_std_core_list__lift_foldr_10345(f, _uniq_xx_10270, _uniq_z_10266_0_10355, _ctx);
}
 
// lifted local: foldr, @spec-x10272
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10267, using:
// @uniq-f@10267 = fn<(e :: E)>(x: 1256, y: 1255){
//   f(y, x);
// }


// lift anonymous function
struct kk_std_core_list__lift_foldr_10345_fun1513__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10270_0;
  kk_function_t f_0;
};
static kk_box_t kk_std_core_list__lift_foldr_10345_fun1513(kk_function_t _fself, kk_box_t _uniq_z_10266_0_10355_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foldr_10345_fun1513(kk_std_core_types__list _uniq_xx_10270_0, kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10345_fun1513__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foldr_10345_fun1513__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foldr_10345_fun1513, kk_context());
  _self->_uniq_xx_10270_0 = _uniq_xx_10270_0;
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foldr_10345_fun1513(kk_function_t _fself, kk_box_t _uniq_z_10266_0_10355_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foldr_10345_fun1513__t* _self = kk_function_as(struct kk_std_core_list__lift_foldr_10345_fun1513__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10270_0 = _self->_uniq_xx_10270_0; /* list<1255> */
  kk_function_t f_0 = _self->f_0; /* (1255, 1256) -> 1257 1256 */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10270_0, _ctx);kk_function_dup(f_0, _ctx);}, {}, _ctx)
  return kk_std_core_list__mlift_lift_foldr_10345_10686(_uniq_xx_10270_0, f_0, _uniq_z_10266_0_10355_0, _ctx);
}

kk_box_t kk_std_core_list__lift_foldr_10345(kk_function_t f_0, kk_std_core_types__list _uniq_xs_10265, kk_box_t _uniq_z_10266, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a, b) -> e b, list<a>, b) -> e b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10265, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1511 = kk_std_core_types__as_Cons(_uniq_xs_10265, _ctx);
    kk_box_t _uniq_x_10269 = _con_x1511->head;
    kk_std_core_types__list _uniq_xx_10270_0 = _con_x1511->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10265, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10265, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10269, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10270_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10265, _ctx);
    }
    kk_box_t x_10732;
    kk_function_t _x_x1512 = kk_function_dup(f_0, _ctx); /*(1255, 1256) -> 1257 1256*/
    x_10732 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1512, (_x_x1512, _uniq_x_10269, _uniq_z_10266, _ctx), _ctx); /*1256*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10732, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foldr_10345_fun1513(_uniq_xx_10270_0, f_0, _ctx), _ctx);
    }
    { // tailcall
      _uniq_xs_10265 = _uniq_xx_10270_0;
      _uniq_z_10266 = x_10732;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    return _uniq_z_10266;
  }
}


// lift anonymous function
struct kk_std_core_list_foldl1_fun1522__t {
  struct kk_function_s _base;
  kk_ssize_t i_10735;
};
static kk_box_t kk_std_core_list_foldl1_fun1522(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldl1_fun1522(kk_ssize_t i_10735, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl1_fun1522__t* _self = kk_function_alloc_as(struct kk_std_core_list_foldl1_fun1522__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foldl1_fun1522, kk_context());
  _self->i_10735 = i_10735;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foldl1_fun1522(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_list_foldl1_fun1522__t* _self = kk_function_as(struct kk_std_core_list_foldl1_fun1522__t*, _fself, _ctx);
  kk_ssize_t i_10735 = _self->i_10735; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10735, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10735, cont, res, _ctx);
}

kk_box_t kk_std_core_list_foldl1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1514 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1514->head;
    kk_std_core_types__list xx = _con_x1514->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t i_10735;
    kk_std_core_hnd__htag _x_x1515 = kk_std_core_hnd__htag_dup(kk_std_core_exn_exn_fs__tag, _ctx); /*hnd/htag<exn>*/
    i_10735 = kk_std_core_hnd__evv_index(_x_x1515, _ctx); /*hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_10735,kk_context()); /*hnd/evv<<exn|1314>>*/;
    kk_std_core_hnd__ev ev_10739 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t y;
    {
      struct kk_std_core_hnd_Ev* _con_x1516 = kk_std_core_hnd__as_Ev(ev_10739, _ctx);
      kk_box_t _box_x40 = _con_x1516->hnd;
      int32_t m = _con_x1516->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x40, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1375;
      kk_std_core_hnd__clause1 _brw_x1377 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x1375 = _brw_x1377; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x44 = _match_x1375.clause;
        kk_box_t _x_x1517;
        kk_std_core_exn__exception _x_x1518;
        kk_string_t _x_x1519;
        kk_define_string_literal(static, _s_x1520, 33, "unexpected Nil in std/core/foldl1", _ctx)
        _x_x1519 = kk_string_dup(_s_x1520, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x1521;
        kk_std_core_types__optional _match_x1376 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1376, _ctx)) {
          kk_box_t _box_x48 = _match_x1376._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x48, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x1376, _ctx);
          _x_x1521 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1376, _ctx);
          _x_x1521 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x1518 = kk_std_core_exn__new_Exception(_x_x1519, _x_x1521, _ctx); /*exception*/
        _x_x1517 = kk_std_core_exn__exception_box(_x_x1518, _ctx); /*45*/
        y = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x44, (_fun_unbox_x44, m, ev_10739, _x_x1517, _ctx), _ctx); /*1313*/
      }
    }
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_list_new_foldl1_fun1522(i_10735, _ctx), _ctx);
    }
    {
      return y;
    }
  }
}


// lift anonymous function
struct kk_std_core_list_foldr1_fun1531__t {
  struct kk_function_s _base;
  kk_ssize_t i_10744;
};
static kk_box_t kk_std_core_list_foldr1_fun1531(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_foldr1_fun1531(kk_ssize_t i_10744, kk_context_t* _ctx) {
  struct kk_std_core_list_foldr1_fun1531__t* _self = kk_function_alloc_as(struct kk_std_core_list_foldr1_fun1531__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_foldr1_fun1531, kk_context());
  _self->i_10744 = i_10744;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_foldr1_fun1531(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_core_list_foldr1_fun1531__t* _self = kk_function_as(struct kk_std_core_list_foldr1_fun1531__t*, _fself, _ctx);
  kk_ssize_t i_10744 = _self->i_10744; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10744, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10744, cont, res, _ctx);
}

kk_box_t kk_std_core_list_foldr1(kk_std_core_types__list xs, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, f : (a, a) -> <exn|e> a) -> <exn|e> a */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn|1350>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    x = kk_std_core_types__new_Nil(_ctx); /*list<1349>*/
  }
  else {
    x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<1349>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_std_core_types__is_Cons(x, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1523 = kk_std_core_types__as_Cons(x, _ctx);
    kk_box_t x_0 = _con_x1523->head;
    kk_std_core_types__list xx = _con_x1523->tail;
    if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
      kk_datatype_ptr_free(x, _ctx);
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(x, _ctx);
    }
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_function_drop(f, _ctx);
      return x_0;
    }
    {
      return kk_std_core_list__unroll_foldl_10005(xx, x_0, f, _ctx);
    }
  }
  {
    kk_function_drop(f, _ctx);
    kk_ssize_t i_10744;
    kk_std_core_hnd__htag _x_x1524 = kk_std_core_hnd__htag_dup(kk_std_core_exn_exn_fs__tag, _ctx); /*hnd/htag<exn>*/
    i_10744 = kk_std_core_hnd__evv_index(_x_x1524, _ctx); /*hnd/ev-index*/
    kk_evv_t w_0 = kk_evv_swap_create1(i_10744,kk_context()); /*hnd/evv<<exn|1350>>*/;
    kk_std_core_hnd__ev ev_10748 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t y;
    {
      struct kk_std_core_hnd_Ev* _con_x1525 = kk_std_core_hnd__as_Ev(ev_10748, _ctx);
      kk_box_t _box_x49 = _con_x1525->hnd;
      int32_t m = _con_x1525->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x49, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x1371;
      kk_std_core_hnd__clause1 _brw_x1373 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x1371 = _brw_x1373; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x53 = _match_x1371.clause;
        kk_box_t _x_x1526;
        kk_std_core_exn__exception _x_x1527;
        kk_string_t _x_x1528;
        kk_define_string_literal(static, _s_x1529, 33, "unexpected Nil in std/core/foldl1", _ctx)
        _x_x1528 = kk_string_dup(_s_x1529, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x1530;
        kk_std_core_types__optional _match_x1372 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x1372, _ctx)) {
          kk_box_t _box_x57 = _match_x1372._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x57, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x1372, _ctx);
          _x_x1530 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x1372, _ctx);
          _x_x1530 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x1527 = kk_std_core_exn__new_Exception(_x_x1528, _x_x1530, _ctx); /*exception*/
        _x_x1526 = kk_std_core_exn__exception_box(_x_x1527, _ctx); /*45*/
        y = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x53, (_fun_unbox_x53, m, ev_10748, _x_x1526, _ctx), _ctx); /*1349*/
      }
    }
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_core_list_new_foldr1_fun1531(i_10744, _ctx), _ctx);
    }
    {
      return y;
    }
  }
}
 
// split a list at position `n`

kk_std_core_types__tuple2 kk_std_core_list_split(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> (list<a>, list<a>) */ 
  kk_std_core_types__list _b_x58_60;
  kk_std_core_types__list _x_x1532 = kk_std_core_types__list_dup(xs, _ctx); /*list<1392>*/
  kk_integer_t _x_x1533 = kk_integer_dup(n, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1534 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  _b_x58_60 = kk_std_core_list__trmc_take(_x_x1532, _x_x1533, _x_x1534, _ctx); /*list<1392>*/
  kk_std_core_types__list _b_x59_61 = kk_std_core_list_drop(xs, n, _ctx); /*list<1392>*/;
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x58_60, _ctx), kk_std_core_types__list_box(_b_x59_61, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_unroll_drop_while_10006_10687(kk_function_t predicate, kk_std_core_types__list xs, kk_std_core_types__list xx, bool _y_x10456, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xs : list<a>, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10456) {
    kk_std_core_types__list_drop(xs, _ctx);
    return kk_std_core_list__unroll_drop_while_10006(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return xs;
  }
}
 
// Drop all initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__unroll_drop_while_10006_fun1538__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xs_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1538(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_drop_while_10006_fun1538(kk_function_t predicate_0, kk_std_core_types__list xs_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1538__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_drop_while_10006_fun1538__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_drop_while_10006_fun1538, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xs_0 = xs_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_drop_while_10006_fun1538(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_drop_while_10006_fun1538__t* _self = kk_function_as(struct kk_std_core_list__unroll_drop_while_10006_fun1538__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (1438) -> 1439 bool */
  kk_std_core_types__list xs_0 = _self->xs_0; /* list<1438> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1438> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xs_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10456_0_65 = kk_bool_unbox(_b_x63); /*bool*/;
  kk_std_core_types__list _x_x1539 = kk_std_core_list__mlift_unroll_drop_while_10006_10687(predicate_0, xs_0, xx_0, _y_x10456_0_65, _ctx); /*list<1438>*/
  return kk_std_core_types__list_box(_x_x1539, _ctx);
}

kk_std_core_types__list kk_std_core_list__unroll_drop_while_10006(kk_std_core_types__list xs_0, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1535 = kk_std_core_types__as_Cons(xs_0, _ctx);
    kk_box_t x = _con_x1535->head;
    kk_std_core_types__list xx_0 = _con_x1535->tail;
    kk_box_dup(x, _ctx);
    kk_std_core_types__list_dup(xx_0, _ctx);
    bool x_0_10753;
    kk_function_t _x_x1536 = kk_function_dup(predicate_0, _ctx); /*(1438) -> 1439 bool*/
    x_0_10753 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1536, (_x_x1536, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1537 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_drop_while_10006_fun1538(predicate_0, xs_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1537, KK_OWNED, _ctx);
    }
    if (x_0_10753) {
      if kk_likely(kk_datatype_ptr_is_unique(xs_0, _ctx)) {
        kk_std_core_types__list_drop(xx_0, _ctx);
        kk_box_drop(x, _ctx);
        kk_datatype_ptr_free(xs_0, _ctx);
      }
      else {
        kk_datatype_ptr_decref(xs_0, _ctx);
      }
      { // tailcall
        xs_0 = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return xs_0;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_10007_10688(kk_std_core_types__cctx _acc, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10462, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10462) {
    kk_std_core_types__list _trmc_x10365 = kk_datatype_null(); /*list<1504>*/;
    kk_std_core_types__list _trmc_x10366 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10365, _ctx); /*list<1504>*/;
    kk_field_addr_t _b_x71_74 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10366, _ctx)->tail, _ctx); /*@field-addr<list<1504>>*/;
    kk_std_core_types__cctx _x_x1540 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10366, _ctx)),_b_x71_74,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _x_x1540, _ctx);
  }
  {
    kk_box_drop(x, _ctx);
    return kk_std_core_list__trmc_unroll_filter_10007(xx, pred, _acc, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_10007_fun1545__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1545(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_10007_fun1545(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1545__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1545__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_10007_fun1545, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_10007_fun1545(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_10007_fun1545__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_10007_fun1545__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1504>> */
  kk_function_t pred_0 = _self->pred_0; /* (1504) -> 1505 bool */
  kk_box_t x_0 = _self->x_0; /* 1504 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1504> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10462_0_97 = kk_bool_unbox(_b_x79); /*bool*/;
  kk_std_core_types__list _x_x1546 = kk_std_core_list__mlift_trmc_unroll_filter_10007_10688(_acc_0, pred_0, x_0, xx_0, _y_x10462_0_97, _ctx); /*list<1504>*/
  return kk_std_core_types__list_box(_x_x1546, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_10007(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1541 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1541->head;
    kk_std_core_types__list xx_0 = _con_x1541->tail;
    kk_reuse_t _ru_x1405 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1405 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10756;
    kk_function_t _x_x1543 = kk_function_dup(pred_0, _ctx); /*(1504) -> 1505 bool*/
    kk_box_t _x_x1542 = kk_box_dup(x_0, _ctx); /*1504*/
    x_1_10756 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1543, (_x_x1543, _x_x1542, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1405,kk_context());
      kk_box_t _x_x1544 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_10007_fun1545(_acc_0, pred_0, x_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1544, KK_OWNED, _ctx);
    }
    if (x_1_10756) {
      kk_std_core_types__list _trmc_x10365_0 = kk_datatype_null(); /*list<1504>*/;
      kk_std_core_types__list _trmc_x10366_0 = kk_std_core_types__new_Cons(_ru_x1405, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10365_0, _ctx); /*list<1504>*/;
      kk_field_addr_t _b_x85_91 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10366_0, _ctx)->tail, _ctx); /*@field-addr<list<1504>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1547 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10366_0, _ctx)),_b_x85_91,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1547;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1405,kk_context());
      kk_box_drop(x_0, _ctx);
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1548 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1548, KK_OWNED, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filter([1,2,3],odd?) == [1,3]`

kk_std_core_types__list kk_std_core_list__unroll_filter_10007(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1549 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_10007(xs_0, pred_1, _x_x1549, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10689(kk_std_core_types__cctx _acc, kk_function_t pred, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10470, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, pred : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10470, _ctx)) {
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _acc, _ctx);
  }
  {
    kk_box_t y = _y_x10470._cons.Just.value;
    kk_std_core_types__list _trmc_x10367 = kk_datatype_null(); /*list<1588>*/;
    kk_std_core_types__list _trmc_x10368 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10367, _ctx); /*list<1588>*/;
    kk_field_addr_t _b_x103_106 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10368, _ctx)->tail, _ctx); /*@field-addr<list<1588>>*/;
    kk_std_core_types__cctx _x_x1551 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10368, _ctx)),_b_x103_106,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_filter_map_10008(xx, pred, _x_x1551, _ctx);
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1556__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1556(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1556(kk_std_core_types__cctx _acc_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1556__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1556__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_filter_map_10008_fun1556, kk_context());
  _self->_acc_0 = _acc_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_filter_map_10008_fun1556(kk_function_t _fself, kk_box_t _b_x113, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1556__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_filter_map_10008_fun1556__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1588>> */
  kk_function_t pred_0 = _self->pred_0; /* (1587) -> 1589 maybe<1588> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1587> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10470_0_129 = kk_std_core_types__maybe_unbox(_b_x113, KK_OWNED, _ctx); /*maybe<1588>*/;
  kk_std_core_types__list _x_x1557 = kk_std_core_list__mlift_trmc_unroll_filter_map_10008_10689(_acc_0, pred_0, xx_0, _y_x10470_0_129, _ctx); /*list<1588>*/
  return kk_std_core_types__list_box(_x_x1557, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_filter_map_10008(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1552 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1552, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1553 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1553->head;
    kk_std_core_types__list xx_0 = _con_x1553->tail;
    kk_reuse_t _ru_x1406 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1406 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10761;
    kk_function_t _x_x1554 = kk_function_dup(pred_0, _ctx); /*(1587) -> 1589 maybe<1588>*/
    x_0_10761 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1554, (_x_x1554, x, _ctx), _ctx); /*maybe<1588>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1406,kk_context());
      kk_std_core_types__maybe_drop(x_0_10761, _ctx);
      kk_box_t _x_x1555 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_filter_map_10008_fun1556(_acc_0, pred_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1555, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10761, _ctx)) {
      kk_reuse_drop(_ru_x1406,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
    {
      kk_box_t y_0 = x_0_10761._cons.Just.value;
      kk_std_core_types__list _trmc_x10367_0 = kk_datatype_null(); /*list<1588>*/;
      kk_std_core_types__list _trmc_x10368_0 = kk_std_core_types__new_Cons(_ru_x1406, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10367_0, _ctx); /*list<1588>*/;
      kk_field_addr_t _b_x119_125 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10368_0, _ctx)->tail, _ctx); /*@field-addr<list<1588>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1558 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10368_0, _ctx)),_b_x119_125,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1558;
        goto kk__tailcall;
      }
    }
  }
}
 
// Retain only those elements of a list that satisfy the given predicate `pred`.
// For example: `filterMap([1,2,3],fn(i) { if i.odd? then Nothing else Just(i*i) }) == [4]`

kk_std_core_types__list kk_std_core_list__unroll_filter_map_10008(kk_std_core_types__list xs_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, pred : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1559 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_filter_map_10008(xs_0, pred_1, _x_x1559, _ctx);
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_unroll_foreach_while_10009_10690(kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10478, kk_context_t* _ctx) { /* forall<a,b,e> (action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(_y_x10478, _ctx)) {
    return kk_std_core_list__unroll_foreach_while_10009(xx, action, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10478;
  }
}
 
// Invoke `action` for each element of a list while `action` return `Nothing`


// lift anonymous function
struct kk_std_core_list__unroll_foreach_while_10009_fun1564__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1564(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_while_10009_fun1564(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1564__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1564__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_while_10009_fun1564, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_while_10009_fun1564(kk_function_t _fself, kk_box_t _b_x131, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_while_10009_fun1564__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_while_10009_fun1564__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (1661) -> 1663 maybe<1662> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<1661> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10478_0_133 = kk_std_core_types__maybe_unbox(_b_x131, KK_OWNED, _ctx); /*maybe<1662>*/;
  kk_std_core_types__maybe _x_x1565 = kk_std_core_list__mlift_unroll_foreach_while_10009_10690(action_0, xx_0, _y_x10478_0_133, _ctx); /*maybe<1662>*/
  return kk_std_core_types__maybe_box(_x_x1565, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__unroll_foreach_while_10009(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1561 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1561->head;
    kk_std_core_types__list xx_0 = _con_x1561->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10766;
    kk_function_t _x_x1562 = kk_function_dup(action_0, _ctx); /*(1661) -> 1663 maybe<1662>*/
    x_0_10766 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1562, (_x_x1562, x, _ctx), _ctx); /*maybe<1662>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10766, _ctx);
      kk_box_t _x_x1563 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_while_10009_fun1564(action_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1563, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_0_10766, _ctx)) { // tailcall
                                                          xs = xx_0;
                                                          goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_0_10766;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_find_10346_10691(kk_box_t _uniq_x_10279, kk_std_core_types__list _uniq_xx_10280, kk_function_t pred, bool _y_x10484, kk_context_t* _ctx) { /* forall<a,e> (a, list<a>, pred : (a) -> e bool, bool) -> e maybe<a> */ 
  if (_y_x10484) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10280, _ctx);
    return kk_std_core_types__new_Just(_uniq_x_10279, _ctx);
  }
  {
    kk_box_drop(_uniq_x_10279, _ctx);
    return kk_std_core_list__lift_find_10346(pred, _uniq_xx_10280, _ctx);
  }
}
 
// lifted local: find, @spec-x10283
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10276, using:
// @uniq-action@10276 = fn<(e :: E)>(x: 1730){
//   match ((pred(x))) {
//     ((std/core/types/True() : bool ) as @pat@1: bool)
//        -> std/core/types/Just<a>(x);
//     ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_find_10346_fun1570__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10279_0;
  kk_std_core_types__list _uniq_xx_10280_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_find_10346_fun1570(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_find_10346_fun1570(kk_box_t _uniq_x_10279_0, kk_std_core_types__list _uniq_xx_10280_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10346_fun1570__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_find_10346_fun1570__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_find_10346_fun1570, kk_context());
  _self->_uniq_x_10279_0 = _uniq_x_10279_0;
  _self->_uniq_xx_10280_0 = _uniq_xx_10280_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_find_10346_fun1570(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_find_10346_fun1570__t* _self = kk_function_as(struct kk_std_core_list__lift_find_10346_fun1570__t*, _fself, _ctx);
  kk_box_t _uniq_x_10279_0 = _self->_uniq_x_10279_0; /* 1730 */
  kk_std_core_types__list _uniq_xx_10280_0 = _self->_uniq_xx_10280_0; /* list<1730> */
  kk_function_t pred_0 = _self->pred_0; /* (1730) -> 1731 bool */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10279_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10280_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10484_0_137 = kk_bool_unbox(_b_x135); /*bool*/;
  kk_std_core_types__maybe _x_x1571 = kk_std_core_list__mlift_lift_find_10346_10691(_uniq_x_10279_0, _uniq_xx_10280_0, pred_0, _y_x10484_0_137, _ctx); /*maybe<1730>*/
  return kk_std_core_types__maybe_box(_x_x1571, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_find_10346(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10275, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10275, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1566 = kk_std_core_types__as_Cons(_uniq_xs_10275, _ctx);
    kk_box_t _uniq_x_10279_0 = _con_x1566->head;
    kk_std_core_types__list _uniq_xx_10280_0 = _con_x1566->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10275, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10275, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10279_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10280_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10275, _ctx);
    }
    bool x_10769;
    kk_function_t _x_x1568 = kk_function_dup(pred_0, _ctx); /*(1730) -> 1731 bool*/
    kk_box_t _x_x1567 = kk_box_dup(_uniq_x_10279_0, _ctx); /*1730*/
    x_10769 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1568, (_x_x1568, _x_x1567, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1569 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_find_10346_fun1570(_uniq_x_10279_0, _uniq_xx_10280_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1569, KK_OWNED, _ctx);
    }
    if (x_10769) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10280_0, _ctx);
      return kk_std_core_types__new_Just(_uniq_x_10279_0, _ctx);
    }
    {
      kk_box_drop(_uniq_x_10279_0, _ctx);
      { // tailcall
        _uniq_xs_10275 = _uniq_xx_10280_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_range_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1364 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1364) {
    kk_std_core_types__list _trmc_x10369 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10370;
    kk_box_t _x_x1572;
    kk_integer_t _x_x1573 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1572 = kk_integer_box(_x_x1573, _ctx); /*79*/
    _trmc_x10370 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1572, _trmc_x10369, _ctx); /*list<int>*/
    kk_field_addr_t _b_x147_152 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10370, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1574 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1575 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10370, _ctx)),_b_x147_152,kk_context()); /*ctx<0>*/
      lo = _x_x1574;
      _acc = _x_x1575;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1576 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1576, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_range_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_context_t* _ctx) { /* (lo : int, hi : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1577 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_range_fs__trmc_list(lo_0, hi_0, _x_x1577, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_10010_10692(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_box_t _trmc_x10371, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e b, xx : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10372 = kk_datatype_null(); /*list<2229>*/;
  kk_std_core_types__list _trmc_x10373 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10371, _trmc_x10372, _ctx); /*list<2229>*/;
  kk_field_addr_t _b_x163_166 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10373, _ctx)->tail, _ctx); /*@field-addr<list<2229>>*/;
  kk_std_core_types__cctx _own_x1362 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10373, _ctx)),_b_x163_166,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1363 = kk_std_core_list__trmc_unroll_map_10010(xx, f, _own_x1362, _ctx); /*list<2229>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1363;
}
 
// Apply a function `f` to each element of the input list in sequence.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_10010_fun1582__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1582(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_10010_fun1582(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1582__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1582__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_10010_fun1582, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_10010_fun1582(kk_function_t _fself, kk_box_t _b_x171, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_10010_fun1582__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_10010_fun1582__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2229>> */
  kk_function_t f_0 = _self->f_0; /* (2228) -> 2230 2229 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2228> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10371_0_189 = _b_x171; /*2229*/;
  kk_std_core_types__list _x_x1583 = kk_std_core_list__mlift_trmc_unroll_map_10010_10692(_acc_0, f_0, xx_0, _trmc_x10371_0_189, _ctx); /*list<2229>*/
  return kk_std_core_types__list_box(_x_x1583, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_10010(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1578 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1578->head;
    kk_std_core_types__list xx_0 = _con_x1578->tail;
    kk_reuse_t _ru_x1409 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1409 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_box_t x_0_10772;
    kk_function_t _x_x1579 = kk_function_dup(f_0, _ctx); /*(2228) -> 2230 2229*/
    x_0_10772 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1579, (_x_x1579, x, _ctx), _ctx); /*2229*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1409,kk_context());
      kk_box_drop(x_0_10772, _ctx);
      kk_box_t _x_x1580;
      kk_function_t _x_x1581;
      kk_function_dup(f_0, _ctx);
      _x_x1581 = kk_std_core_list__new_trmc_unroll_map_10010_fun1582(_acc_0, f_0, xx_0, _ctx); /*(2418) -> 2420 2419*/
      _x_x1580 = kk_std_core_hnd_yield_extend(_x_x1581, _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1580, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10372_0 = kk_datatype_null(); /*list<2229>*/;
      kk_std_core_types__list _trmc_x10373_0 = kk_std_core_types__new_Cons(_ru_x1409, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10772, _trmc_x10372_0, _ctx); /*list<2229>*/;
      kk_field_addr_t _b_x177_183 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10373_0, _ctx)->tail, _ctx); /*@field-addr<list<2229>>*/;
      kk_std_core_types__cctx _own_x1361 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10373_0, _ctx)),_b_x177_183,kk_context()); /*ctx<0>*/;
      { // tailcall
        xs = xx_0;
        _acc_0 = _own_x1361;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x1584 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1584, KK_OWNED, _ctx);
  }
}
 
// Apply a function `f` to each element of the input list in sequence.

kk_std_core_types__list kk_std_core_list__unroll_map_10010(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e b) -> e list<b> */ 
  kk_std_core_types__cctx _own_x1359 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_map_10010(xs_0, f_1, _own_x1359, _ctx);
}
 
// lifted local: char/list, @spec-x10291
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10286, using:
// @uniq-f@10286 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__trmc_lift_list_10347(kk_std_core_types__list _uniq_xs_10285, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<int>, ctx<list<char>>) -> list<char> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10285, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1585 = kk_std_core_types__as_Cons(_uniq_xs_10285, _ctx);
    kk_box_t _box_x190 = _con_x1585->head;
    kk_std_core_types__list _uniq_xx_10289 = _con_x1585->tail;
    kk_integer_t _uniq_x_10288 = kk_integer_unbox(_box_x190, _ctx);
    kk_reuse_t _ru_x1410 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10285, _ctx)) {
      _ru_x1410 = (kk_datatype_ptr_reuse(_uniq_xs_10285, _ctx));
    }
    else {
      kk_integer_dup(_uniq_x_10288, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10289, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10285, _ctx);
    }
    kk_char_t _trmc_x10374 = kk_integer_clamp32(_uniq_x_10288,kk_context()); /*char*/;
    kk_std_core_types__list _trmc_x10375 = kk_datatype_null(); /*list<char>*/;
    kk_std_core_types__list _trmc_x10376 = kk_std_core_types__new_Cons(_ru_x1410, 0, kk_char_box(_trmc_x10374, _ctx), _trmc_x10375, _ctx); /*list<char>*/;
    kk_field_addr_t _b_x200_205 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10376, _ctx)->tail, _ctx); /*@field-addr<list<char>>*/;
    kk_std_core_types__cctx _brw_x1356;
    kk_std_core_types__cctx _x_x1586 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<char>>*/
    _brw_x1356 = kk_cctx_extend_linear(_x_x1586,(kk_std_core_types__list_box(_trmc_x10376, _ctx)),_b_x200_205,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1357 = kk_std_core_list_char_fs__trmc_lift_list_10347(_uniq_xx_10289, _brw_x1356, _ctx); /*list<char>*/;
    kk_std_core_types__cctx_drop(_brw_x1356, _ctx);
    return _brw_x1357;
  }
  {
    kk_box_t _x_x1587;
    kk_std_core_types__cctx _x_x1588 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<char>>*/
    _x_x1587 = kk_cctx_apply_linear(_x_x1588,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1587, KK_OWNED, _ctx);
  }
}
 
// lifted local: char/list, @spec-x10291
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10286, using:
// @uniq-f@10286 = std/core/char/int/char

kk_std_core_types__list kk_std_core_list_char_fs__lift_list_10347(kk_std_core_types__list _uniq_xs_10285_0, kk_context_t* _ctx) { /* (list<int>) -> list<char> */ 
  kk_std_core_types__cctx _brw_x1354 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1355 = kk_std_core_list_char_fs__trmc_lift_list_10347(_uniq_xs_10285_0, _brw_x1354, _ctx); /*list<char>*/;
  kk_std_core_types__cctx_drop(_brw_x1354, _ctx);
  return _brw_x1355;
}
 
// Create a list of characters from `lo`  to `hi`  (including `hi`).

kk_std_core_types__list kk_std_core_list_char_fs_list(kk_char_t lo, kk_char_t hi, kk_context_t* _ctx) { /* (lo : char, hi : char) -> list<char> */ 
  kk_integer_t lo_0_10777 = kk_integer_from_int(lo,kk_context()); /*int*/;
  kk_integer_t hi_0_10778 = kk_integer_from_int(hi,kk_context()); /*int*/;
  kk_std_core_types__list xs_10071;
  kk_std_core_types__cctx _x_x1589 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  xs_10071 = kk_std_core_list_range_fs__trmc_list(lo_0_10777, hi_0_10778, _x_x1589, _ctx); /*list<int>*/
  if (kk_std_core_types__is_Nil(xs_10071, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x1352 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x1353 = kk_std_core_list_char_fs__trmc_lift_list_10347(xs_10071, _brw_x1352, _ctx); /*list<char>*/;
    kk_std_core_types__cctx_drop(_brw_x1352, _ctx);
    return _brw_x1353;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_function_fs__mlift_trmc_list_10693(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_box_t _trmc_x10377, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10378 = kk_datatype_null(); /*list<1938>*/;
  kk_std_core_types__list _trmc_x10379 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10377, _trmc_x10378, _ctx); /*list<1938>*/;
  kk_field_addr_t _b_x216_219 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10379, _ctx)->tail, _ctx); /*@field-addr<list<1938>>*/;
  kk_integer_t _x_x1590 = kk_integer_add_small_const(lo, 1, _ctx); /*int*/
  kk_std_core_types__cctx _x_x1591 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10379, _ctx)),_b_x216_219,kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(_x_x1590, hi, f, _x_x1591, _ctx);
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_function_fs__trmc_list_fun1595__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
};
static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1595(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_function_fs__new_trmc_list_fun1595(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1595__t* _self = kk_function_alloc_as(struct kk_std_core_list_function_fs__trmc_list_fun1595__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_function_fs__trmc_list_fun1595, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_function_fs__trmc_list_fun1595(kk_function_t _fself, kk_box_t _b_x224, kk_context_t* _ctx) {
  struct kk_std_core_list_function_fs__trmc_list_fun1595__t* _self = kk_function_as(struct kk_std_core_list_function_fs__trmc_list_fun1595__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<1938>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 1939 1938 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10377_0_242 = _b_x224; /*1938*/;
  kk_std_core_types__list _x_x1596 = kk_std_core_list_function_fs__mlift_trmc_list_10693(_acc_0, f_0, hi_0, lo_0, _trmc_x10377_0_242, _ctx); /*list<1938>*/
  return kk_std_core_types__list_box(_x_x1596, _ctx);
}

kk_std_core_types__list kk_std_core_list_function_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1350 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1350) {
    kk_box_t x_10780;
    kk_function_t _x_x1593 = kk_function_dup(f_0, _ctx); /*(int) -> 1939 1938*/
    kk_integer_t _x_x1592 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10780 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1593, (_x_x1593, _x_x1592, _ctx), _ctx); /*1938*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10780, _ctx);
      kk_box_t _x_x1594 = kk_std_core_hnd_yield_extend(kk_std_core_list_function_fs__new_trmc_list_fun1595(_acc_0, f_0, hi_0, lo_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1594, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10378_0 = kk_datatype_null(); /*list<1938>*/;
      kk_std_core_types__list _trmc_x10379_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10780, _trmc_x10378_0, _ctx); /*list<1938>*/;
      kk_field_addr_t _b_x230_236 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10379_0, _ctx)->tail, _ctx); /*@field-addr<list<1938>>*/;
      { // tailcall
        kk_integer_t _x_x1597 = kk_integer_add_small_const(lo_0, 1, _ctx); /*int*/
        kk_std_core_types__cctx _x_x1598 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10379_0, _ctx)),_b_x230_236,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1597;
        _acc_0 = _x_x1598;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1599 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1599, KK_OWNED, _ctx);
  }
}
 
// Applies a function `f` to list of increasing elements from `lo`  to `hi`
// (including both `lo`  and `hi` ).
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_function_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1600 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_function_fs__trmc_list(lo_1, hi_1, f_1, _x_x1600, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs__trmc_list(kk_integer_t lo, kk_integer_t hi, kk_integer_t stride, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int, ctx<list<int>>) -> list<int> */ 
  kk__tailcall: ;
  bool _match_x1349 = kk_integer_lte_borrow(lo,hi,kk_context()); /*bool*/;
  if (_match_x1349) {
    kk_std_core_types__list _trmc_x10380 = kk_datatype_null(); /*list<int>*/;
    kk_std_core_types__list _trmc_x10381;
    kk_box_t _x_x1601;
    kk_integer_t _x_x1602 = kk_integer_dup(lo, _ctx); /*int*/
    _x_x1601 = kk_integer_box(_x_x1602, _ctx); /*79*/
    _trmc_x10381 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1601, _trmc_x10380, _ctx); /*list<int>*/
    kk_field_addr_t _b_x252_257 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10381, _ctx)->tail, _ctx); /*@field-addr<list<int>>*/;
    { // tailcall
      kk_integer_t _x_x1603;
      kk_integer_t _x_x1604 = kk_integer_dup(stride, _ctx); /*int*/
      _x_x1603 = kk_integer_add(lo,_x_x1604,kk_context()); /*int*/
      kk_std_core_types__cctx _x_x1605 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10381, _ctx)),_b_x252_257,kk_context()); /*ctx<0>*/
      lo = _x_x1603;
      _acc = _x_x1605;
      goto kk__tailcall;
    }
  }
  {
    kk_integer_drop(stride, _ctx);
    kk_integer_drop(lo, _ctx);
    kk_integer_drop(hi, _ctx);
    kk_box_t _x_x1606 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1606, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stride_fs_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_context_t* _ctx) { /* (lo : int, hi : int, stride : int) -> list<int> */ 
  kk_std_core_types__cctx _x_x1607 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stride_fs__trmc_list(lo_0, hi_0, stride_0, _x_x1607, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list_stridefunction_fs__mlift_trmc_list_10694(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t hi, kk_integer_t lo, kk_integer_t stride, kk_box_t _trmc_x10382, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, f : (int) -> e a, hi : int, lo : int, stride : int, a) -> e list<a> */ 
  kk_std_core_types__list _trmc_x10383 = kk_datatype_null(); /*list<2118>*/;
  kk_std_core_types__list _trmc_x10384 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10382, _trmc_x10383, _ctx); /*list<2118>*/;
  kk_field_addr_t _b_x268_271 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10384, _ctx)->tail, _ctx); /*@field-addr<list<2118>>*/;
  kk_integer_t _x_x1608;
  kk_integer_t _x_x1609 = kk_integer_dup(stride, _ctx); /*int*/
  _x_x1608 = kk_integer_add(lo,_x_x1609,kk_context()); /*int*/
  kk_std_core_types__cctx _x_x1610 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10384, _ctx)),_b_x268_271,kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(_x_x1608, hi, stride, f, _x_x1610, _ctx);
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.


// lift anonymous function
struct kk_std_core_list_stridefunction_fs__trmc_list_fun1614__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t hi_0;
  kk_integer_t lo_0;
  kk_integer_t stride_0;
};
static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1614(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_stridefunction_fs__new_trmc_list_fun1614(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t hi_0, kk_integer_t lo_0, kk_integer_t stride_0, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1614__t* _self = kk_function_alloc_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1614__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_stridefunction_fs__trmc_list_fun1614, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->hi_0 = hi_0;
  _self->lo_0 = lo_0;
  _self->stride_0 = stride_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_stridefunction_fs__trmc_list_fun1614(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_core_list_stridefunction_fs__trmc_list_fun1614__t* _self = kk_function_as(struct kk_std_core_list_stridefunction_fs__trmc_list_fun1614__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2118>> */
  kk_function_t f_0 = _self->f_0; /* (int) -> 2119 2118 */
  kk_integer_t hi_0 = _self->hi_0; /* int */
  kk_integer_t lo_0 = _self->lo_0; /* int */
  kk_integer_t stride_0 = _self->stride_0; /* int */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(hi_0, _ctx);kk_integer_dup(lo_0, _ctx);kk_integer_dup(stride_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10382_0_294 = _b_x276; /*2118*/;
  kk_std_core_types__list _x_x1615 = kk_std_core_list_stridefunction_fs__mlift_trmc_list_10694(_acc_0, f_0, hi_0, lo_0, stride_0, _trmc_x10382_0_294, _ctx); /*list<2118>*/
  return kk_std_core_types__list_box(_x_x1615, _ctx);
}

kk_std_core_types__list kk_std_core_list_stridefunction_fs__trmc_list(kk_integer_t lo_0, kk_integer_t hi_0, kk_integer_t stride_0, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  bool _match_x1347 = kk_integer_lte_borrow(lo_0,hi_0,kk_context()); /*bool*/;
  if (_match_x1347) {
    kk_box_t x_10783;
    kk_function_t _x_x1612 = kk_function_dup(f_0, _ctx); /*(int) -> 2119 2118*/
    kk_integer_t _x_x1611 = kk_integer_dup(lo_0, _ctx); /*int*/
    x_10783 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_context_t*), _x_x1612, (_x_x1612, _x_x1611, _ctx), _ctx); /*2118*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_10783, _ctx);
      kk_box_t _x_x1613 = kk_std_core_hnd_yield_extend(kk_std_core_list_stridefunction_fs__new_trmc_list_fun1614(_acc_0, f_0, hi_0, lo_0, stride_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1613, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10383_0 = kk_datatype_null(); /*list<2118>*/;
      kk_std_core_types__list _trmc_x10384_0 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10783, _trmc_x10383_0, _ctx); /*list<2118>*/;
      kk_field_addr_t _b_x282_288 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10384_0, _ctx)->tail, _ctx); /*@field-addr<list<2118>>*/;
      { // tailcall
        kk_integer_t _x_x1616;
        kk_integer_t _x_x1617 = kk_integer_dup(stride_0, _ctx); /*int*/
        _x_x1616 = kk_integer_add(lo_0,_x_x1617,kk_context()); /*int*/
        kk_std_core_types__cctx _x_x1618 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10384_0, _ctx)),_b_x282_288,kk_context()); /*ctx<0>*/
        lo_0 = _x_x1616;
        _acc_0 = _x_x1618;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(stride_0, _ctx);
    kk_integer_drop(lo_0, _ctx);
    kk_integer_drop(hi_0, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1619 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1619, KK_OWNED, _ctx);
  }
}
 
// Returns an integer list of increasing elements from `lo`  to `hi` with stride `stride`.
// If `lo > hi`  the function returns the empty list.

kk_std_core_types__list kk_std_core_list_stridefunction_fs_list(kk_integer_t lo_1, kk_integer_t hi_1, kk_integer_t stride_1, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,e> (lo : int, hi : int, stride : int, f : (int) -> e a) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1620 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list_stridefunction_fs__trmc_list(lo_1, hi_1, stride_1, f_1, _x_x1620, _ctx);
}
 
// Apply a function `f` to each character in a string


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1621__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1621(kk_function_t _fself, kk_box_t _b_x298, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1621(kk_function_t f, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1621__t* _self = kk_function_alloc_as(struct kk_std_core_list_string_fs_map_fun1621__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_string_fs_map_fun1621, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1621(kk_function_t _fself, kk_box_t _b_x298, kk_context_t* _ctx) {
  struct kk_std_core_list_string_fs_map_fun1621__t* _self = kk_function_as(struct kk_std_core_list_string_fs_map_fun1621__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (char) -> 2171 char */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  kk_char_t _x_x1622;
  kk_char_t _x_x1623 = kk_char_unbox(_b_x298, KK_OWNED, _ctx); /*char*/
  _x_x1622 = kk_function_call(kk_char_t, (kk_function_t, kk_char_t, kk_context_t*), f, (f, _x_x1623, _ctx), _ctx); /*char*/
  return kk_char_box(_x_x1622, _ctx);
}


// lift anonymous function
struct kk_std_core_list_string_fs_map_fun1625__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_string_fs_map_fun1625(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_string_fs_new_map_fun1625(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_string_fs_map_fun1625, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_string_fs_map_fun1625(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1626;
  kk_std_core_types__list _x_x1627 = kk_std_core_types__list_unbox(_b_x303, KK_OWNED, _ctx); /*list<char>*/
  _x_x1626 = kk_std_core_string_listchar_fs_string(_x_x1627, _ctx); /*string*/
  return kk_string_box(_x_x1626);
}

kk_string_t kk_std_core_list_string_fs_map(kk_string_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<e> (s : string, f : (char) -> e char) -> e string */ 
  kk_std_core_types__list xs_10075 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  kk_std_core_types__list x_10786;
  if (kk_std_core_types__is_Nil(xs_10075, _ctx)) {
    kk_function_drop(f, _ctx);
    x_10786 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
  }
  else {
    kk_std_core_types__cctx _b_x297_301 = kk_cctx_empty(kk_context()); /*ctx<list<char>>*/;
    kk_function_t _brw_x1345 = kk_std_core_list_string_fs_new_map_fun1621(f, _ctx); /*(2228) -> 2230 2229*/;
    kk_std_core_types__list _brw_x1346 = kk_std_core_list__trmc_unroll_map_10010(xs_10075, _brw_x1345, _b_x297_301, _ctx); /*list<2229>*/;
    kk_function_drop(_brw_x1345, _ctx);
    x_10786 = _brw_x1346; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10786, _ctx);
    kk_box_t _x_x1624 = kk_std_core_hnd_yield_extend(kk_std_core_list_string_fs_new_map_fun1625(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1624);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10786, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_list__mlift_unroll_order2_10011_10695(kk_box_t z, kk_std_core_types__order2 _y_x10510, kk_context_t* _ctx) { /* forall<a,e> (z : a, order2<list<a>>) -> e order2<list<a>> */ 
  if (kk_std_core_types__is_Eq2(_y_x10510, _ctx)) {
    kk_box_t _box_x305 = _y_x10510._cons.Eq2.eq;
    kk_std_core_types__list zz = kk_std_core_types__list_unbox(_box_x305, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(zz, _ctx);
    kk_std_core_types__order2_drop(_y_x10510, _ctx);
    kk_box_t _x_x1628;
    kk_std_core_types__list _x_x1629 = kk_std_core_types__new_Cons(kk_reuse_null, 0, z, zz, _ctx); /*list<79>*/
    _x_x1628 = kk_std_core_types__list_box(_x_x1629, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x1628, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10510, _ctx)) {
    kk_box_t _box_x307 = _y_x10510._cons.Lt2.lt;
    kk_box_t _box_x308 = _y_x10510._cons.Lt2.gt;
    kk_std_core_types__list xx_sq_ = kk_std_core_types__list_unbox(_box_x307, KK_BORROWED, _ctx);
    kk_std_core_types__list yy_sq_ = kk_std_core_types__list_unbox(_box_x308, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(xx_sq_, _ctx);
    kk_std_core_types__list_dup(yy_sq_, _ctx);
    kk_std_core_types__order2_drop(_y_x10510, _ctx);
    kk_box_t _x_x1630;
    kk_std_core_types__list _x_x1631;
    kk_box_t _x_x1632 = kk_box_dup(z, _ctx); /*2513*/
    _x_x1631 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1632, xx_sq_, _ctx); /*list<79>*/
    _x_x1630 = kk_std_core_types__list_box(_x_x1631, _ctx); /*105*/
    kk_box_t _x_x1633;
    kk_std_core_types__list _x_x1634 = kk_std_core_types__new_Cons(kk_reuse_null, 0, z, yy_sq_, _ctx); /*list<79>*/
    _x_x1633 = kk_std_core_types__list_box(_x_x1634, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1630, _x_x1633, _ctx);
  }
  {
    kk_box_t _box_x311 = _y_x10510._cons.Gt2.lt;
    kk_box_t _box_x312 = _y_x10510._cons.Gt2.gt;
    kk_std_core_types__list yy_0_sq_ = kk_std_core_types__list_unbox(_box_x311, KK_BORROWED, _ctx);
    kk_std_core_types__list xx_0_sq_ = kk_std_core_types__list_unbox(_box_x312, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(xx_0_sq_, _ctx);
    kk_std_core_types__list_dup(yy_0_sq_, _ctx);
    kk_std_core_types__order2_drop(_y_x10510, _ctx);
    kk_box_t _x_x1635;
    kk_std_core_types__list _x_x1636;
    kk_box_t _x_x1637 = kk_box_dup(z, _ctx); /*2513*/
    _x_x1636 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1637, yy_0_sq_, _ctx); /*list<79>*/
    _x_x1635 = kk_std_core_types__list_box(_x_x1636, _ctx); /*105*/
    kk_box_t _x_x1638;
    kk_std_core_types__list _x_x1639 = kk_std_core_types__new_Cons(kk_reuse_null, 0, z, xx_0_sq_, _ctx); /*list<79>*/
    _x_x1638 = kk_std_core_types__list_box(_x_x1639, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1635, _x_x1638, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641__t {
  struct kk_function_s _base;
  kk_box_t z_0;
};
static kk_box_t kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641(kk_function_t _fself, kk_box_t _b_x321, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_unroll_order2_10011_10696_fun1641(kk_box_t z_0, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641, kk_context());
  _self->z_0 = z_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641(kk_function_t _fself, kk_box_t _b_x321, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641__t* _self = kk_function_as(struct kk_std_core_list__mlift_unroll_order2_10011_10696_fun1641__t*, _fself, _ctx);
  kk_box_t z_0 = _self->z_0; /* 2513 */
  kk_drop_match(_self, {kk_box_dup(z_0, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10510_0_331 = kk_std_core_types__order2_unbox(_b_x321, KK_OWNED, _ctx); /*order2<list<2513>>*/;
  kk_std_core_types__order2 _x_x1642 = kk_std_core_list__mlift_unroll_order2_10011_10695(z_0, _y_x10510_0_331, _ctx); /*order2<list<2513>>*/
  return kk_std_core_types__order2_box(_x_x1642, _ctx);
}

kk_std_core_types__order2 kk_std_core_list__mlift_unroll_order2_10011_10696(kk_function_t _implicit_fs_order2, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_std_core_types__order2 _y_x10509, kk_context_t* _ctx) { /* forall<a,e> (?order2 : (a, a) -> e order2<a>, xx : list<a>, yy : list<a>, order2<a>) -> e order2<list<a>> */ 
  if (kk_std_core_types__is_Eq2(_y_x10509, _ctx)) {
    kk_box_t z_0 = _y_x10509._cons.Eq2.eq;
    kk_std_core_types__order2 x_10790;
    kk_std_core_types__order2 _brw_x1343 = kk_std_core_list__unroll_order2_10011(xx, yy, _implicit_fs_order2, _ctx); /*order2<list<2513>>*/;
    kk_function_drop(_implicit_fs_order2, _ctx);
    x_10790 = _brw_x1343; /*order2<list<2513>>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10790, _ctx);
      kk_box_t _x_x1640 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_unroll_order2_10011_10696_fun1641(z_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1640, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_list__mlift_unroll_order2_10011_10695(z_0, x_10790, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10509, _ctx)) {
    kk_box_t x_sq_ = _y_x10509._cons.Lt2.lt;
    kk_box_t y_sq_ = _y_x10509._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_order2, _ctx);
    kk_box_t _x_x1643;
    kk_std_core_types__list _x_x1644 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_sq_, xx, _ctx); /*list<79>*/
    _x_x1643 = kk_std_core_types__list_box(_x_x1644, _ctx); /*105*/
    kk_box_t _x_x1645;
    kk_std_core_types__list _x_x1646 = kk_std_core_types__new_Cons(kk_reuse_null, 0, y_sq_, yy, _ctx); /*list<79>*/
    _x_x1645 = kk_std_core_types__list_box(_x_x1646, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1643, _x_x1645, _ctx);
  }
  {
    kk_box_t y_0_sq_ = _y_x10509._cons.Gt2.lt;
    kk_box_t x_0_sq_ = _y_x10509._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_order2, _ctx);
    kk_box_t _x_x1647;
    kk_std_core_types__list _x_x1648 = kk_std_core_types__new_Cons(kk_reuse_null, 0, y_0_sq_, yy, _ctx); /*list<79>*/
    _x_x1647 = kk_std_core_types__list_box(_x_x1648, _ctx); /*105*/
    kk_box_t _x_x1649;
    kk_std_core_types__list _x_x1650 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_0_sq_, xx, _ctx); /*list<79>*/
    _x_x1649 = kk_std_core_types__list_box(_x_x1650, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1647, _x_x1649, _ctx);
  }
}
 
// Order2 on lists


// lift anonymous function
struct kk_std_core_list__unroll_order2_10011_fun1658__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_order2_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_order2_10011_fun1658(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_order2_10011_fun1658(kk_function_t _implicit_fs_order2_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_order2_10011_fun1658__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_order2_10011_fun1658__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_order2_10011_fun1658, kk_context());
  _self->_implicit_fs_order2_0 = _implicit_fs_order2_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_order2_10011_fun1658(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_order2_10011_fun1658__t* _self = kk_function_as(struct kk_std_core_list__unroll_order2_10011_fun1658__t*, _fself, _ctx);
  kk_function_t _implicit_fs_order2_0 = _self->_implicit_fs_order2_0; /* (2513, 2513) -> 2514 order2<2513> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2513> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2513> */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_order2_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10509_0_371 = kk_std_core_types__order2_unbox(_b_x338, KK_OWNED, _ctx); /*order2<2513>*/;
  kk_std_core_types__order2 _x_x1659 = kk_std_core_list__mlift_unroll_order2_10011_10696(_implicit_fs_order2_0, xx_0, yy_0, _y_x10509_0_371, _ctx); /*order2<list<2513>>*/
  return kk_std_core_types__order2_box(_x_x1659, _ctx);
}


// lift anonymous function
struct kk_std_core_list__unroll_order2_10011_fun1661__t {
  struct kk_function_s _base;
  kk_box_t z_1;
};
static kk_box_t kk_std_core_list__unroll_order2_10011_fun1661(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_order2_10011_fun1661(kk_box_t z_1, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_order2_10011_fun1661__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_order2_10011_fun1661__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_order2_10011_fun1661, kk_context());
  _self->z_1 = z_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_order2_10011_fun1661(kk_function_t _fself, kk_box_t _b_x340, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_order2_10011_fun1661__t* _self = kk_function_as(struct kk_std_core_list__unroll_order2_10011_fun1661__t*, _fself, _ctx);
  kk_box_t z_1 = _self->z_1; /* 2513 */
  kk_drop_match(_self, {kk_box_dup(z_1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10510_1_372 = kk_std_core_types__order2_unbox(_b_x340, KK_OWNED, _ctx); /*order2<list<2513>>*/;
  kk_std_core_types__order2 _x_x1662 = kk_std_core_list__mlift_unroll_order2_10011_10695(z_1, _y_x10510_1_372, _ctx); /*order2<list<2513>>*/
  return kk_std_core_types__order2_box(_x_x1662, _ctx);
}

kk_std_core_types__order2 kk_std_core_list__unroll_order2_10011(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t _implicit_fs_order2_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ys : list<a>, ?order2 : (a, a) -> e order2<a>) -> e order2<list<a>> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      return kk_std_core_types__new_Eq2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _ctx);
    }
    {
      return kk_std_core_types__new_Lt2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_std_core_types__list_box(ys, _ctx), _ctx);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1651 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1651->head;
    kk_std_core_types__list xx_0 = _con_x1651->tail;
    kk_reuse_t _ru_x1411 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1411 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Nil(ys, _ctx)) {
      kk_box_t _x_x1652;
      kk_std_core_types__list _x_x1653 = kk_std_core_types__new_Cons(_ru_x1411, 0, x_0, xx_0, _ctx); /*list<79>*/
      _x_x1652 = kk_std_core_types__list_box(_x_x1653, _ctx); /*105*/
      return kk_std_core_types__new_Gt2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _x_x1652, _ctx);
    }
    {
      struct kk_std_core_types_Cons* _con_x1654 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1654->head;
      kk_std_core_types__list yy_0 = _con_x1654->tail;
      kk_reuse_t _ru_x1412 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1412 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__order2 x_1_10792;
      kk_function_t _x_x1655 = kk_function_dup(_implicit_fs_order2_0, _ctx); /*(2513, 2513) -> 2514 order2<2513>*/
      x_1_10792 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1655, (_x_x1655, x_0, y, _ctx), _ctx); /*order2<2513>*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1411,kk_context());
        kk_reuse_drop(_ru_x1412,kk_context());
        kk_std_core_types__order2_drop(x_1_10792, _ctx);
        kk_box_t _x_x1656;
        kk_function_t _x_x1657;
        kk_function_dup(_implicit_fs_order2_0, _ctx);
        _x_x1657 = kk_std_core_list__new_unroll_order2_10011_fun1658(_implicit_fs_order2_0, xx_0, yy_0, _ctx); /*(2418) -> 2420 2419*/
        _x_x1656 = kk_std_core_hnd_yield_extend(_x_x1657, _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x1656, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_1_10792, _ctx)) {
        kk_box_t z_1 = x_1_10792._cons.Eq2.eq;
        kk_std_core_types__order2 x_2_10795 = kk_std_core_list__unroll_order2_10011(xx_0, yy_0, _implicit_fs_order2_0, _ctx); /*order2<list<2513>>*/;
        if (kk_yielding(kk_context())) {
          kk_reuse_drop(_ru_x1411,kk_context());
          kk_reuse_drop(_ru_x1412,kk_context());
          kk_std_core_types__order2_drop(x_2_10795, _ctx);
          kk_box_t _x_x1660 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_order2_10011_fun1661(z_1, _ctx), _ctx); /*2419*/
          return kk_std_core_types__order2_unbox(_x_x1660, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq2(x_2_10795, _ctx)) {
          kk_box_t _box_x341 = x_2_10795._cons.Eq2.eq;
          kk_std_core_types__list zz_0 = kk_std_core_types__list_unbox(_box_x341, KK_BORROWED, _ctx);
          kk_reuse_drop(_ru_x1411,kk_context());
          kk_std_core_types__list_dup(zz_0, _ctx);
          kk_std_core_types__order2_drop(x_2_10795, _ctx);
          kk_box_t _x_x1663;
          kk_std_core_types__list _x_x1664 = kk_std_core_types__new_Cons(_ru_x1412, 0, z_1, zz_0, _ctx); /*list<79>*/
          _x_x1663 = kk_std_core_types__list_box(_x_x1664, _ctx); /*105*/
          return kk_std_core_types__new_Eq2(_x_x1663, _ctx);
        }
        if (kk_std_core_types__is_Lt2(x_2_10795, _ctx)) {
          kk_box_t _box_x343 = x_2_10795._cons.Lt2.lt;
          kk_box_t _box_x344 = x_2_10795._cons.Lt2.gt;
          kk_std_core_types__list xx_1_sq_ = kk_std_core_types__list_unbox(_box_x343, KK_BORROWED, _ctx);
          kk_std_core_types__list yy_1_sq_ = kk_std_core_types__list_unbox(_box_x344, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(xx_1_sq_, _ctx);
          kk_std_core_types__list_dup(yy_1_sq_, _ctx);
          kk_std_core_types__order2_drop(x_2_10795, _ctx);
          kk_box_t _x_x1665;
          kk_std_core_types__list _x_x1666;
          kk_box_t _x_x1667 = kk_box_dup(z_1, _ctx); /*2513*/
          _x_x1666 = kk_std_core_types__new_Cons(_ru_x1412, 0, _x_x1667, xx_1_sq_, _ctx); /*list<79>*/
          _x_x1665 = kk_std_core_types__list_box(_x_x1666, _ctx); /*105*/
          kk_box_t _x_x1668;
          kk_std_core_types__list _x_x1669 = kk_std_core_types__new_Cons(_ru_x1411, 0, z_1, yy_1_sq_, _ctx); /*list<79>*/
          _x_x1668 = kk_std_core_types__list_box(_x_x1669, _ctx); /*105*/
          return kk_std_core_types__new_Lt2(_x_x1665, _x_x1668, _ctx);
        }
        {
          kk_box_t _box_x347 = x_2_10795._cons.Gt2.lt;
          kk_box_t _box_x348 = x_2_10795._cons.Gt2.gt;
          kk_std_core_types__list yy_0_0_sq_ = kk_std_core_types__list_unbox(_box_x347, KK_BORROWED, _ctx);
          kk_std_core_types__list xx_0_0_sq_ = kk_std_core_types__list_unbox(_box_x348, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(xx_0_0_sq_, _ctx);
          kk_std_core_types__list_dup(yy_0_0_sq_, _ctx);
          kk_std_core_types__order2_drop(x_2_10795, _ctx);
          kk_box_t _x_x1670;
          kk_std_core_types__list _x_x1671;
          kk_box_t _x_x1672 = kk_box_dup(z_1, _ctx); /*2513*/
          _x_x1671 = kk_std_core_types__new_Cons(_ru_x1412, 0, _x_x1672, yy_0_0_sq_, _ctx); /*list<79>*/
          _x_x1670 = kk_std_core_types__list_box(_x_x1671, _ctx); /*105*/
          kk_box_t _x_x1673;
          kk_std_core_types__list _x_x1674 = kk_std_core_types__new_Cons(_ru_x1411, 0, z_1, xx_0_0_sq_, _ctx); /*list<79>*/
          _x_x1673 = kk_std_core_types__list_box(_x_x1674, _ctx); /*105*/
          return kk_std_core_types__new_Gt2(_x_x1670, _x_x1673, _ctx);
        }
      }
      if (kk_std_core_types__is_Lt2(x_1_10792, _ctx)) {
        kk_box_t x_1_sq_ = x_1_10792._cons.Lt2.lt;
        kk_box_t y_1_sq_ = x_1_10792._cons.Lt2.gt;
        kk_box_t _x_x1675;
        kk_std_core_types__list _x_x1676 = kk_std_core_types__new_Cons(_ru_x1412, 0, x_1_sq_, xx_0, _ctx); /*list<79>*/
        _x_x1675 = kk_std_core_types__list_box(_x_x1676, _ctx); /*105*/
        kk_box_t _x_x1677;
        kk_std_core_types__list _x_x1678 = kk_std_core_types__new_Cons(_ru_x1411, 0, y_1_sq_, yy_0, _ctx); /*list<79>*/
        _x_x1677 = kk_std_core_types__list_box(_x_x1678, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x1675, _x_x1677, _ctx);
      }
      {
        kk_box_t y_0_0_sq_ = x_1_10792._cons.Gt2.lt;
        kk_box_t x_0_0_sq_ = x_1_10792._cons.Gt2.gt;
        kk_box_t _x_x1679;
        kk_std_core_types__list _x_x1680 = kk_std_core_types__new_Cons(_ru_x1412, 0, y_0_0_sq_, yy_0, _ctx); /*list<79>*/
        _x_x1679 = kk_std_core_types__list_box(_x_x1680, _ctx); /*105*/
        kk_box_t _x_x1681;
        kk_std_core_types__list _x_x1682 = kk_std_core_types__new_Cons(_ru_x1411, 0, x_0_0_sq_, xx_0, _ctx); /*list<79>*/
        _x_x1681 = kk_std_core_types__list_box(_x_x1682, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x1679, _x_x1681, _ctx);
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_6004_10012_10697(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10078, kk_std_core_types__list yy, kk_box_t _trmc_x10385, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a) -> e b, i@0@10078 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10386 = kk_datatype_null(); /*list<2589>*/;
  kk_std_core_types__list _trmc_x10387 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10385, _trmc_x10386, _ctx); /*list<2589>*/;
  kk_field_addr_t _b_x384_387 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10387, _ctx)->tail, _ctx); /*@field-addr<list<2589>>*/;
  kk_std_core_types__cctx _x_x1683 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10387, _ctx)),_b_x384_387,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012(f, yy, i_0_10078, _x_x1683, _ctx);
}
 
// lifted local: map-indexed, map-idx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10078_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688(kk_function_t _fself, kk_box_t _b_x392, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_6004_10012_fun1688(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10078_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10078_0 = i_0_10078_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688(kk_function_t _fself, kk_box_t _b_x392, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012_fun1688__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2589>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2588) -> 2590 2589 */
  kk_integer_t i_0_10078_0 = _self->i_0_10078_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2588> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10078_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10385_0_410 = _b_x392; /*2589*/;
  kk_std_core_types__list _x_x1689 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_6004_10012_10697(_acc_0, f_0, i_0_10078_0, yy_0, _trmc_x10385_0_410, _ctx); /*list<2589>*/
  return kk_std_core_types__list_box(_x_x1689, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1684 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1684->head;
    kk_std_core_types__list yy_0 = _con_x1684->tail;
    kk_reuse_t _ru_x1413 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1413 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10078_0;
    kk_integer_t _x_x1685 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10078_0 = kk_integer_add_small_const(_x_x1685, 1, _ctx); /*int*/
    kk_box_t x_10798;
    kk_function_t _x_x1686 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2588) -> 2590 2589*/
    x_10798 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1686, (_x_x1686, i, y, _ctx), _ctx); /*2589*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1413,kk_context());
      kk_box_drop(x_10798, _ctx);
      kk_box_t _x_x1687 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_6004_10012_fun1688(_acc_0, f_0, i_0_10078_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1687, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10386_0 = kk_datatype_null(); /*list<2589>*/;
      kk_std_core_types__list _trmc_x10387_0 = kk_std_core_types__new_Cons(_ru_x1413, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10798, _trmc_x10386_0, _ctx); /*list<2589>*/;
      kk_field_addr_t _b_x398_404 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10387_0, _ctx)->tail, _ctx); /*@field-addr<list<2589>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1690 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10387_0, _ctx)),_b_x398_404,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10078_0;
        _acc_0 = _x_x1690;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1691 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1691, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed, map-idx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_6004_10012(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1692 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_6004_10012(f_1, ys_0, i_0, _x_x1692, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_peek_6005_10013_10698(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list yy, kk_box_t _trmc_x10388, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (value : a, rest : list<a>) -> e b, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10389 = kk_datatype_null(); /*list<2651>*/;
  kk_std_core_types__list _trmc_x10390 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10388, _trmc_x10389, _ctx); /*list<2651>*/;
  kk_field_addr_t _b_x416_419 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10390, _ctx)->tail, _ctx); /*@field-addr<list<2651>>*/;
  kk_std_core_types__cctx _x_x1695 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10390, _ctx)),_b_x416_419,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013(f, yy, _x_x1695, _ctx);
}
 
// lifted local: map-peek, mappeek


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700(kk_function_t _fself, kk_box_t _b_x424, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_peek_6005_10013_fun1700(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700(kk_function_t _fself, kk_box_t _b_x424, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013_fun1700__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2651>> */
  kk_function_t f_0 = _self->f_0; /* (value : 2650, rest : list<2650>) -> 2652 2651 */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2650> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10388_0_442 = _b_x424; /*2651*/;
  kk_std_core_types__list _x_x1701 = kk_std_core_list__mlift_trmc_unroll_lift_map_peek_6005_10013_10698(_acc_0, f_0, yy_0, _trmc_x10388_0_442, _ctx); /*list<2651>*/
  return kk_std_core_types__list_box(_x_x1701, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1696 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1696->head;
    kk_std_core_types__list yy_0 = _con_x1696->tail;
    kk_reuse_t _ru_x1414 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1414 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_box_t x_10807;
    kk_function_t _x_x1698 = kk_function_dup(f_0, _ctx); /*(value : 2650, rest : list<2650>) -> 2652 2651*/
    kk_std_core_types__list _x_x1697 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2650>*/
    x_10807 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1698, (_x_x1698, y, _x_x1697, _ctx), _ctx); /*2651*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1414,kk_context());
      kk_box_drop(x_10807, _ctx);
      kk_box_t _x_x1699 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_peek_6005_10013_fun1700(_acc_0, f_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1699, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10389_0 = kk_datatype_null(); /*list<2651>*/;
      kk_std_core_types__list _trmc_x10390_0 = kk_std_core_types__new_Cons(_ru_x1414, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10807, _trmc_x10389_0, _ctx); /*list<2651>*/;
      kk_field_addr_t _b_x430_436 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10390_0, _ctx)->tail, _ctx); /*@field-addr<list<2651>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1702 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10390_0, _ctx)),_b_x430_436,kk_context()); /*ctx<0>*/
        ys = yy_0;
        _acc_0 = _x_x1702;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1703 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1703, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-peek, mappeek

kk_std_core_types__list kk_std_core_list__unroll_lift_map_peek_6005_10013(kk_function_t f_1, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (value : a, rest : list<a>) -> e b, ys : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1704 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_peek_6005_10013(f_1, ys_0, _x_x1704, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_6006_10014_10699(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i_0_10086, kk_std_core_types__list yy, kk_box_t _trmc_x10391, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (idx : int, value : a, rest : list<a>) -> e b, i@0@10086 : int, yy : list<a>, b) -> e list<b> */ 
  kk_std_core_types__list _trmc_x10392 = kk_datatype_null(); /*list<2722>*/;
  kk_std_core_types__list _trmc_x10393 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10391, _trmc_x10392, _ctx); /*list<2722>*/;
  kk_field_addr_t _b_x448_451 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10393, _ctx)->tail, _ctx); /*@field-addr<list<2722>>*/;
  kk_std_core_types__cctx _x_x1707 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10393, _ctx)),_b_x448_451,kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014(f, yy, i_0_10086, _x_x1707, _ctx);
}
 
// lifted local: map-indexed-peek, mapidx


// lift anonymous function
struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0_10086_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713(kk_function_t _fself, kk_box_t _b_x456, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0_10086_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0_10086_0 = i_0_10086_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713(kk_function_t _fself, kk_box_t _b_x456, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2722>> */
  kk_function_t f_0 = _self->f_0; /* (idx : int, value : 2721, rest : list<2721>) -> 2723 2722 */
  kk_integer_t i_0_10086_0 = _self->i_0_10086_0; /* int */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<2721> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0_10086_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10391_0_474 = _b_x456; /*2722*/;
  kk_std_core_types__list _x_x1714 = kk_std_core_list__mlift_trmc_unroll_lift_map_indexed_peek_6006_10014_10699(_acc_0, f_0, i_0_10086_0, yy_0, _trmc_x10391_0_474, _ctx); /*list<2722>*/
  return kk_std_core_types__list_box(_x_x1714, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014(kk_function_t f_0, kk_std_core_types__list ys, kk_integer_t i, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1708 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1708->head;
    kk_std_core_types__list yy_0 = _con_x1708->tail;
    kk_reuse_t _ru_x1415 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1415 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy_0, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_integer_t i_0_10086_0;
    kk_integer_t _x_x1709 = kk_integer_dup(i, _ctx); /*int*/
    i_0_10086_0 = kk_integer_add_small_const(_x_x1709, 1, _ctx); /*int*/
    kk_box_t x_10814;
    kk_function_t _x_x1711 = kk_function_dup(f_0, _ctx); /*(idx : int, value : 2721, rest : list<2721>) -> 2723 2722*/
    kk_std_core_types__list _x_x1710 = kk_std_core_types__list_dup(yy_0, _ctx); /*list<2721>*/
    x_10814 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_std_core_types__list, kk_context_t*), _x_x1711, (_x_x1711, i, y, _x_x1710, _ctx), _ctx); /*2722*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1415,kk_context());
      kk_box_drop(x_10814, _ctx);
      kk_box_t _x_x1712 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_lift_map_indexed_peek_6006_10014_fun1713(_acc_0, f_0, i_0_10086_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1712, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _trmc_x10392_0 = kk_datatype_null(); /*list<2722>*/;
      kk_std_core_types__list _trmc_x10393_0 = kk_std_core_types__new_Cons(_ru_x1415, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_10814, _trmc_x10392_0, _ctx); /*list<2722>*/;
      kk_field_addr_t _b_x462_468 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10393_0, _ctx)->tail, _ctx); /*@field-addr<list<2722>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1715 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10393_0, _ctx)),_b_x462_468,kk_context()); /*ctx<0>*/
        ys = yy_0;
        i = i_0_10086_0;
        _acc_0 = _x_x1715;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_integer_drop(i, _ctx);
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x1716 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1716, KK_OWNED, _ctx);
  }
}
 
// lifted local: map-indexed-peek, mapidx

kk_std_core_types__list kk_std_core_list__unroll_lift_map_indexed_peek_6006_10014(kk_function_t f_1, kk_std_core_types__list ys_0, kk_integer_t i_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (idx : int, value : a, rest : list<a>) -> e b, ys : list<a>, i : int) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1717 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_map_indexed_peek_6006_10014(f_1, ys_0, i_0, _x_x1717, _ctx);
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list__trmc_replicate(kk_box_t x, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (x : a, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x1336 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1336) {
    kk_std_core_types__list _trmc_x10394 = kk_datatype_null(); /*list<2781>*/;
    kk_std_core_types__list _trmc_x10395;
    kk_box_t _x_x1720 = kk_box_dup(x, _ctx); /*2781*/
    _trmc_x10395 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1720, _trmc_x10394, _ctx); /*list<2781>*/
    kk_field_addr_t _b_x480_485 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10395, _ctx)->tail, _ctx); /*@field-addr<list<2781>>*/;
    { // tailcall
      kk_integer_t _x_x1721 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x1722 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10395, _ctx)),_b_x480_485,kk_context()); /*ctx<0>*/
      n = _x_x1721;
      _acc = _x_x1722;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(x, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x1723 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1723, KK_OWNED, _ctx);
  }
}
 
// Create a list of `n` repeated elements `x`

kk_std_core_types__list kk_std_core_list_replicate(kk_box_t x_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (x : a, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x1724 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_replicate(x_0, n_0, _x_x1724, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_remove_10348_10700(kk_std_core_types__cctx _acc, kk_box_t _uniq_x_10295, kk_std_core_types__list _uniq_xx_10296, kk_function_t pred, bool _y_x10540, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, a, list<a>, pred : (a) -> e bool, bool) -> e list<a> */ 
  if (_y_x10540) {
    kk_box_drop(_uniq_x_10295, _ctx);
    return kk_std_core_list__trmc_lift_remove_10348(pred, _uniq_xx_10296, _acc, _ctx);
  }
  {
    kk_std_core_types__list _trmc_x10396 = kk_datatype_null(); /*list<2821>*/;
    kk_std_core_types__list _trmc_x10397 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10295, _trmc_x10396, _ctx); /*list<2821>*/;
    kk_field_addr_t _b_x496_499 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10397, _ctx)->tail, _ctx); /*@field-addr<list<2821>>*/;
    kk_std_core_types__cctx _x_x1725 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10397, _ctx)),_b_x496_499,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_lift_remove_10348(pred, _uniq_xx_10296, _x_x1725, _ctx);
  }
}
 
// lifted local: remove, @spec-x10300
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10293, using:
// @uniq-pred@10293 = fn<(e :: E)>(x: 2821){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }


// lift anonymous function
struct kk_std_core_list__trmc_lift_remove_10348_fun1730__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_box_t _uniq_x_10295_0;
  kk_std_core_types__list _uniq_xx_10296_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__trmc_lift_remove_10348_fun1730(kk_function_t _fself, kk_box_t _b_x504, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_remove_10348_fun1730(kk_std_core_types__cctx _acc_0, kk_box_t _uniq_x_10295_0, kk_std_core_types__list _uniq_xx_10296_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10348_fun1730__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_remove_10348_fun1730__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_remove_10348_fun1730, kk_context());
  _self->_acc_0 = _acc_0;
  _self->_uniq_x_10295_0 = _uniq_x_10295_0;
  _self->_uniq_xx_10296_0 = _uniq_xx_10296_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_remove_10348_fun1730(kk_function_t _fself, kk_box_t _b_x504, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_remove_10348_fun1730__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_remove_10348_fun1730__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<2821>> */
  kk_box_t _uniq_x_10295_0 = _self->_uniq_x_10295_0; /* 2821 */
  kk_std_core_types__list _uniq_xx_10296_0 = _self->_uniq_xx_10296_0; /* list<2821> */
  kk_function_t pred_0 = _self->pred_0; /* (2821) -> 2822 bool */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_box_dup(_uniq_x_10295_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10296_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10540_0_522 = kk_bool_unbox(_b_x504); /*bool*/;
  kk_std_core_types__list _x_x1731 = kk_std_core_list__mlift_trmc_lift_remove_10348_10700(_acc_0, _uniq_x_10295_0, _uniq_xx_10296_0, pred_0, _y_x10540_0_522, _ctx); /*list<2821>*/
  return kk_std_core_types__list_box(_x_x1731, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_remove_10348(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10292, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10292, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1726 = kk_std_core_types__as_Cons(_uniq_xs_10292, _ctx);
    kk_box_t _uniq_x_10295_0 = _con_x1726->head;
    kk_std_core_types__list _uniq_xx_10296_0 = _con_x1726->tail;
    kk_reuse_t _ru_x1416 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10292, _ctx)) {
      _ru_x1416 = (kk_datatype_ptr_reuse(_uniq_xs_10292, _ctx));
    }
    else {
      kk_box_dup(_uniq_x_10295_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10296_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10292, _ctx);
    }
    bool x_10823;
    kk_function_t _x_x1728 = kk_function_dup(pred_0, _ctx); /*(2821) -> 2822 bool*/
    kk_box_t _x_x1727 = kk_box_dup(_uniq_x_10295_0, _ctx); /*2821*/
    x_10823 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1728, (_x_x1728, _x_x1727, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1416,kk_context());
      kk_box_t _x_x1729 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_remove_10348_fun1730(_acc_0, _uniq_x_10295_0, _uniq_xx_10296_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1729, KK_OWNED, _ctx);
    }
    if (x_10823) {
      kk_reuse_drop(_ru_x1416,kk_context());
      kk_box_drop(_uniq_x_10295_0, _ctx);
      { // tailcall
        _uniq_xs_10292 = _uniq_xx_10296_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _trmc_x10396_0 = kk_datatype_null(); /*list<2821>*/;
      kk_std_core_types__list _trmc_x10397_0 = kk_std_core_types__new_Cons(_ru_x1416, kk_field_index_of(struct kk_std_core_types_Cons, tail), _uniq_x_10295_0, _trmc_x10396_0, _ctx); /*list<2821>*/;
      kk_field_addr_t _b_x510_516 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10397_0, _ctx)->tail, _ctx); /*@field-addr<list<2821>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1732 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10397_0, _ctx)),_b_x510_516,kk_context()); /*ctx<0>*/
        _uniq_xs_10292 = _uniq_xx_10296_0;
        _acc_0 = _x_x1732;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x1733 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1733, KK_OWNED, _ctx);
  }
}
 
// lifted local: remove, @spec-x10300
// specialized: std/core/list/@unroll-filter@10007, on parameters @uniq-pred@10293, using:
// @uniq-pred@10293 = fn<(e :: E)>(x: 2821){
//   std/core/types/@open<(total :: E),(e :: E),(b : bool) -> bool,(b : bool) -> (e :: E) bool>((fn(b: bool){
//     (match (b) {
//       ((std/core/types/True() : bool ) as @pat@0: bool)
//          -> std/core/types/False;
//       ((@skip std/core/types/False() : bool ) as @pat@0@0: bool)
//          -> std/core/types/True;
//     });
//   }))((pred(x)));
// }

kk_std_core_types__list kk_std_core_list__lift_remove_10348(kk_function_t pred_1, kk_std_core_types__list _uniq_xs_10292_0, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> e bool, list<a>) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1734 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_remove_10348(pred_1, _uniq_xs_10292_0, _x_x1734, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_partition_acc_10015_10701(kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_function_t pred, kk_box_t x, kk_std_core_types__list xx, bool _y_x10548, kk_context_t* _ctx) { /* forall<a,e> (acc1 : ctx<list<a>>, acc2 : ctx<list<a>>, pred : (a) -> e bool, x : a, xx : list<a>, bool) -> e (list<a>, list<a>) */ 
  if (_y_x10548) {
    kk_std_core_types__list _cctx_x2924;
    kk_std_core_types__list _x_x1736 = kk_datatype_null(); /*list<2984>*/
    _cctx_x2924 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1736, _ctx); /*list<2984>*/
    kk_field_addr_t _cctx_x2925 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2924, _ctx)->tail, _ctx); /*@field-addr<list<2984>>*/;
    kk_std_core_types__list _b_x529_539 = _cctx_x2924; /*list<2984>*/;
    kk_field_addr_t _b_x530_540 = _cctx_x2925; /*@field-addr<list<2984>>*/;
    kk_std_core_types__cctx _own_x1333;
    kk_std_core_types__cctx _x_x1737 = kk_cctx_create((kk_std_core_types__list_box(_b_x529_539, _ctx)),_b_x530_540,kk_context()); /*cctx<0,1>*/
    _own_x1333 = kk_cctx_compose(acc1,_x_x1737,kk_context()); /*cctx<394,396>*/
    kk_std_core_types__tuple2 _brw_x1334 = kk_std_core_list__unroll_partition_acc_10015(xx, pred, _own_x1333, acc2, _ctx); /*(list<2984>, list<2984>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1334;
  }
  {
    kk_std_core_types__list _cctx_x2971;
    kk_std_core_types__list _x_x1738 = kk_datatype_null(); /*list<2984>*/
    _cctx_x2971 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1738, _ctx); /*list<2984>*/
    kk_field_addr_t _cctx_x2972 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2971, _ctx)->tail, _ctx); /*@field-addr<list<2984>>*/;
    kk_std_core_types__list _b_x537_541 = _cctx_x2971; /*list<2984>*/;
    kk_field_addr_t _b_x538_542 = _cctx_x2972; /*@field-addr<list<2984>>*/;
    kk_std_core_types__cctx _own_x1331;
    kk_std_core_types__cctx _x_x1739 = kk_cctx_create((kk_std_core_types__list_box(_b_x537_541, _ctx)),_b_x538_542,kk_context()); /*cctx<0,1>*/
    _own_x1331 = kk_cctx_compose(acc2,_x_x1739,kk_context()); /*cctx<394,396>*/
    kk_std_core_types__tuple2 _brw_x1332 = kk_std_core_list__unroll_partition_acc_10015(xx, pred, acc1, _own_x1331, _ctx); /*(list<2984>, list<2984>)*/;
    kk_function_drop(pred, _ctx);
    return _brw_x1332;
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_partition_acc_10015_fun1747__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc1_0;
  kk_std_core_types__cctx acc2_0;
  kk_function_t pred_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_partition_acc_10015_fun1747(kk_function_t _fself, kk_box_t _b_x550, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_partition_acc_10015_fun1747(kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_function_t pred_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10015_fun1747__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_partition_acc_10015_fun1747__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_partition_acc_10015_fun1747, kk_context());
  _self->acc1_0 = acc1_0;
  _self->acc2_0 = acc2_0;
  _self->pred_0 = pred_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_partition_acc_10015_fun1747(kk_function_t _fself, kk_box_t _b_x550, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_partition_acc_10015_fun1747__t* _self = kk_function_as(struct kk_std_core_list__unroll_partition_acc_10015_fun1747__t*, _fself, _ctx);
  kk_std_core_types__cctx acc1_0 = _self->acc1_0; /* ctx<list<2984>> */
  kk_std_core_types__cctx acc2_0 = _self->acc2_0; /* ctx<list<2984>> */
  kk_function_t pred_0 = _self->pred_0; /* (2984) -> 2985 bool */
  kk_box_t x_0 = _self->x_0; /* 2984 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<2984> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc1_0, _ctx);kk_std_core_types__cctx_dup(acc2_0, _ctx);kk_function_dup(pred_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10548_0_578 = kk_bool_unbox(_b_x550); /*bool*/;
  kk_std_core_types__tuple2 _x_x1748 = kk_std_core_list__mlift_unroll_partition_acc_10015_10701(acc1_0, acc2_0, pred_0, x_0, xx_0, _y_x10548_0_578, _ctx); /*(list<2984>, list<2984>)*/
  return kk_std_core_types__tuple2_box(_x_x1748, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_partition_acc_10015(kk_std_core_types__list xs, kk_function_t pred_0, kk_std_core_types__cctx acc1_0, kk_std_core_types__cctx acc2_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, acc1 : ctx<list<a>>, acc2 : ctx<list<a>>) -> e (list<a>, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x547_567;
    kk_box_t _x_x1740 = kk_cctx_apply(acc1_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x547_567 = kk_std_core_types__list_unbox(_x_x1740, KK_OWNED, _ctx); /*list<2984>*/
    kk_std_core_types__list _b_x548_568;
    kk_box_t _x_x1741 = kk_cctx_apply(acc2_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x548_568 = kk_std_core_types__list_unbox(_x_x1741, KK_OWNED, _ctx); /*list<2984>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x547_567, _ctx), kk_std_core_types__list_box(_b_x548_568, _ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1742 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1742->head;
    kk_std_core_types__list xx_0 = _con_x1742->tail;
    kk_reuse_t _ru_x1417 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1417 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10828;
    kk_function_t _x_x1744 = kk_function_dup(pred_0, _ctx); /*(2984) -> 2985 bool*/
    kk_box_t _x_x1743 = kk_box_dup(x_0, _ctx); /*2984*/
    x_1_10828 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1744, (_x_x1744, _x_x1743, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1417,kk_context());
      kk_box_t _x_x1745;
      kk_function_t _x_x1746;
      kk_function_dup(pred_0, _ctx);
      _x_x1746 = kk_std_core_list__new_unroll_partition_acc_10015_fun1747(acc1_0, acc2_0, pred_0, x_0, xx_0, _ctx); /*(2418) -> 2420 2419*/
      _x_x1745 = kk_std_core_hnd_yield_extend(_x_x1746, _ctx); /*2419*/
      return kk_std_core_types__tuple2_unbox(_x_x1745, KK_OWNED, _ctx);
    }
    if (x_1_10828) {
      kk_std_core_types__list _cctx_x2924_0;
      kk_std_core_types__list _x_x1749 = kk_datatype_null(); /*list<2984>*/
      _cctx_x2924_0 = kk_std_core_types__new_Cons(_ru_x1417, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1749, _ctx); /*list<2984>*/
      kk_field_addr_t _cctx_x2925_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2924_0, _ctx)->tail, _ctx); /*@field-addr<list<2984>>*/;
      kk_std_core_types__list _b_x557_574 = _cctx_x2924_0; /*list<2984>*/;
      kk_field_addr_t _b_x558_575 = _cctx_x2925_0; /*@field-addr<list<2984>>*/;
      kk_std_core_types__cctx _own_x1330;
      kk_std_core_types__cctx _x_x1750 = kk_cctx_create((kk_std_core_types__list_box(_b_x557_574, _ctx)),_b_x558_575,kk_context()); /*cctx<0,1>*/
      _own_x1330 = kk_cctx_compose(acc1_0,_x_x1750,kk_context()); /*cctx<394,396>*/
      { // tailcall
        xs = xx_0;
        acc1_0 = _own_x1330;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list _cctx_x2971_0;
      kk_std_core_types__list _x_x1751 = kk_datatype_null(); /*list<2984>*/
      _cctx_x2971_0 = kk_std_core_types__new_Cons(_ru_x1417, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _x_x1751, _ctx); /*list<2984>*/
      kk_field_addr_t _cctx_x2972_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x2971_0, _ctx)->tail, _ctx); /*@field-addr<list<2984>>*/;
      kk_std_core_types__list _b_x565_576 = _cctx_x2971_0; /*list<2984>*/;
      kk_field_addr_t _b_x566_577 = _cctx_x2972_0; /*@field-addr<list<2984>>*/;
      kk_std_core_types__cctx _own_x1329;
      kk_std_core_types__cctx _x_x1752 = kk_cctx_create((kk_std_core_types__list_box(_b_x565_576, _ctx)),_b_x566_577,kk_context()); /*cctx<0,1>*/
      _own_x1329 = kk_cctx_compose(acc2_0,_x_x1752,kk_context()); /*cctx<394,396>*/
      { // tailcall
        xs = xx_0;
        acc2_0 = _own_x1329;
        goto kk__tailcall;
      }
    }
  }
}
 
// Partition a list in two lists where the first list contains
// those elements that satisfy the given predicate `pred`.
// For example: `partition([1,2,3],odd?) == ([1,3],[2])`

kk_std_core_types__tuple2 kk_std_core_list_partition(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool) -> e (list<a>, list<a>) */ 
  kk_std_core_types__cctx acc1_10095 = kk_cctx_empty(kk_context()); /*ctx<list<3031>>*/;
  kk_std_core_types__cctx acc2_10096 = kk_cctx_empty(kk_context()); /*ctx<list<3031>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x595_597;
    kk_box_t _x_x1755 = kk_cctx_apply(acc1_10095,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x595_597 = kk_std_core_types__list_unbox(_x_x1755, KK_OWNED, _ctx); /*list<3031>*/
    kk_std_core_types__list _b_x596_598;
    kk_box_t _x_x1756 = kk_cctx_apply(acc2_10096,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x596_598 = kk_std_core_types__list_unbox(_x_x1756, KK_OWNED, _ctx); /*list<3031>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x595_597, _ctx), kk_std_core_types__list_box(_b_x596_598, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_partition_acc_10015(xs, pred, acc1_10095, acc2_10096, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_list__mlift_lift_lookup_10349_10702(kk_std_core_types__tuple2 _uniq_x_10306, kk_std_core_types__list _uniq_xx_10307, kk_function_t pred, bool _y_x10557, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), list<(a, b)>, pred : (a) -> e bool, bool) -> e maybe<b> */ 
  if (_y_x10557) {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__list_drop(_uniq_xx_10307, _ctx);
    kk_box_t _x_x1757;
    {
      kk_box_t _x_0 = _uniq_x_10306.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(_uniq_x_10306, _ctx);
      _x_x1757 = _x_0; /*3168*/
    }
    return kk_std_core_types__new_Just(_x_x1757, _ctx);
  }
  {
    kk_std_core_types__tuple2_drop(_uniq_x_10306, _ctx);
    return kk_std_core_list__lift_lookup_10349(pred, _uniq_xx_10307, _ctx);
  }
}
 
// lifted local: lookup, @spec-x10310
// specialized: std/core/list/@unroll-foreach-while@10009, on parameters @uniq-action@10303, using:
// @uniq-action@10303 = fn<(e :: E)>(kv: (3167, 3168)){
//   match ((pred((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> a,(tuple2 : (a, b)) -> (e :: E) a>((fn(tuple2: (3167, 3168)){
//     (match (tuple2) {
//       ((@skip std/core/types/Tuple2((@x: 3167) : a, (@pat@0@0: 3168) : a) : (a, b) ) as @pat@1: (3167, 3168))
//          -> @x;
//     });
//   }))(kv))))) {
//     ((std/core/types/True() : bool ) as @pat@2: bool)
//        -> std/core/types/Just<a>((std/core/types/@open<(total :: E),(e :: E),(tuple2 : (a, b)) -> b,(tuple2 : (a, b)) -> (e :: E) b>((fn(tuple2@0: (3167, 3168)){
//         (match (tuple2@0) {
//           ((@skip std/core/types/Tuple2((@pat@0@1: 3167) : a, (@x@0: 3168) : a) : (a, b) ) as @pat@3: (3167, 3168))
//              -> @x@0;
//         });
//       }))(kv)));
//     ((@skip std/core/types/False() : bool ) as @pat@0@2: bool)
//        -> std/core/types/Nothing<a>;
//   };
// }


// lift anonymous function
struct kk_std_core_list__lift_lookup_10349_fun1762__t {
  struct kk_function_s _base;
  kk_std_core_types__tuple2 _uniq_x_10306_0;
  kk_std_core_types__list _uniq_xx_10307_0;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_list__lift_lookup_10349_fun1762(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_lookup_10349_fun1762(kk_std_core_types__tuple2 _uniq_x_10306_0, kk_std_core_types__list _uniq_xx_10307_0, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10349_fun1762__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_lookup_10349_fun1762__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_lookup_10349_fun1762, kk_context());
  _self->_uniq_x_10306_0 = _uniq_x_10306_0;
  _self->_uniq_xx_10307_0 = _uniq_xx_10307_0;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_lookup_10349_fun1762(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_lookup_10349_fun1762__t* _self = kk_function_as(struct kk_std_core_list__lift_lookup_10349_fun1762__t*, _fself, _ctx);
  kk_std_core_types__tuple2 _uniq_x_10306_0 = _self->_uniq_x_10306_0; /* (3167, 3168) */
  kk_std_core_types__list _uniq_xx_10307_0 = _self->_uniq_xx_10307_0; /* list<(3167, 3168)> */
  kk_function_t pred_0 = _self->pred_0; /* (3167) -> 3169 bool */
  kk_drop_match(_self, {kk_std_core_types__tuple2_dup(_uniq_x_10306_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10307_0, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  bool _y_x10557_0_607 = kk_bool_unbox(_b_x605); /*bool*/;
  kk_std_core_types__maybe _x_x1763 = kk_std_core_list__mlift_lift_lookup_10349_10702(_uniq_x_10306_0, _uniq_xx_10307_0, pred_0, _y_x10557_0_607, _ctx); /*maybe<3168>*/
  return kk_std_core_types__maybe_box(_x_x1763, _ctx);
}

kk_std_core_types__maybe kk_std_core_list__lift_lookup_10349(kk_function_t pred_0, kk_std_core_types__list _uniq_xs_10302, kk_context_t* _ctx) { /* forall<a,b,e> (pred : (a) -> e bool, list<(a, b)>) -> e maybe<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_xs_10302, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1758 = kk_std_core_types__as_Cons(_uniq_xs_10302, _ctx);
    kk_box_t _box_x603 = _con_x1758->head;
    kk_std_core_types__list _uniq_xx_10307_0 = _con_x1758->tail;
    kk_std_core_types__tuple2 _uniq_x_10306_0 = kk_std_core_types__tuple2_unbox(_box_x603, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10302, _ctx)) {
      kk_std_core_types__tuple2_dup(_uniq_x_10306_0, _ctx);
      kk_box_drop(_box_x603, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10302, _ctx);
    }
    else {
      kk_std_core_types__tuple2_dup(_uniq_x_10306_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10307_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10302, _ctx);
    }
    bool x_10831;
    kk_function_t _x_x1760 = kk_function_dup(pred_0, _ctx); /*(3167) -> 3169 bool*/
    kk_box_t _x_x1759;
    {
      kk_box_t _x = _uniq_x_10306_0.fst;
      kk_box_dup(_x, _ctx);
      _x_x1759 = _x; /*3167*/
    }
    x_10831 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1760, (_x_x1760, _x_x1759, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1761 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_lookup_10349_fun1762(_uniq_x_10306_0, _uniq_xx_10307_0, pred_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x1761, KK_OWNED, _ctx);
    }
    if (x_10831) {
      kk_function_drop(pred_0, _ctx);
      kk_std_core_types__list_drop(_uniq_xx_10307_0, _ctx);
      kk_box_t _x_x1764;
      {
        kk_box_t _x_0_0 = _uniq_x_10306_0.snd;
        kk_box_dup(_x_0_0, _ctx);
        kk_std_core_types__tuple2_drop(_uniq_x_10306_0, _ctx);
        _x_x1764 = _x_0_0; /*3168*/
      }
      return kk_std_core_types__new_Just(_x_x1764, _ctx);
    }
    {
      kk_std_core_types__tuple2_drop(_uniq_x_10306_0, _ctx);
      { // tailcall
        _uniq_xs_10302 = _uniq_xx_10307_0;
        goto kk__tailcall;
      }
    }
  }
}
 
// monadic lift

kk_integer_t kk_std_core_list__mlift_unroll_index_of_acc_10016_10703(kk_integer_t idx, kk_function_t pred, kk_std_core_types__list xx, bool _y_x10564, kk_context_t* _ctx) { /* forall<a,e> (idx : int, pred : (a) -> e bool, xx : list<a>, bool) -> e int */ 
  if (_y_x10564) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(pred, _ctx);
    return idx;
  }
  {
    kk_integer_t _x_x1765 = kk_integer_add_small_const(idx, 1, _ctx); /*int*/
    return kk_std_core_list__unroll_index_of_acc_10016(xx, pred, _x_x1765, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_list__unroll_index_of_acc_10016_fun1769__t {
  struct kk_function_s _base;
  kk_integer_t idx_0;
  kk_function_t pred_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_index_of_acc_10016_fun1769(kk_function_t _fself, kk_box_t _b_x609, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_index_of_acc_10016_fun1769(kk_integer_t idx_0, kk_function_t pred_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10016_fun1769__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_index_of_acc_10016_fun1769__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_index_of_acc_10016_fun1769, kk_context());
  _self->idx_0 = idx_0;
  _self->pred_0 = pred_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_index_of_acc_10016_fun1769(kk_function_t _fself, kk_box_t _b_x609, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_index_of_acc_10016_fun1769__t* _self = kk_function_as(struct kk_std_core_list__unroll_index_of_acc_10016_fun1769__t*, _fself, _ctx);
  kk_integer_t idx_0 = _self->idx_0; /* int */
  kk_function_t pred_0 = _self->pred_0; /* (3224) -> 3225 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3224> */
  kk_drop_match(_self, {kk_integer_dup(idx_0, _ctx);kk_function_dup(pred_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10564_0_611 = kk_bool_unbox(_b_x609); /*bool*/;
  kk_integer_t _x_x1770 = kk_std_core_list__mlift_unroll_index_of_acc_10016_10703(idx_0, pred_0, xx_0, _y_x10564_0_611, _ctx); /*int*/
  return kk_integer_box(_x_x1770, _ctx);
}

kk_integer_t kk_std_core_list__unroll_index_of_acc_10016(kk_std_core_types__list xs, kk_function_t pred_0, kk_integer_t idx_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, pred : (a) -> e bool, idx : int) -> e int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1766 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1766->head;
    kk_std_core_types__list xx_0 = _con_x1766->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10834;
    kk_function_t _x_x1767 = kk_function_dup(pred_0, _ctx); /*(3224) -> 3225 bool*/
    x_0_10834 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1767, (_x_x1767, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1768 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_index_of_acc_10016_fun1769(idx_0, pred_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_integer_unbox(_x_x1768, _ctx);
    }
    if (x_0_10834) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(pred_0, _ctx);
      return idx_0;
    }
    { // tailcall
      kk_integer_t _x_x1771 = kk_integer_add_small_const(idx_0, 1, _ctx); /*int*/
      xs = xx_0;
      idx_0 = _x_x1771;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(pred_0, _ctx);
    kk_integer_drop(idx_0, _ctx);
    return kk_integer_from_small(-1);
  }
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_unroll_foreach_10017_10704(kk_function_t action, kk_std_core_types__list xx, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (action : (a) -> e (), xx : list<a>, wild_ : ()) -> e () */ 
  kk_std_core_list__unroll_foreach_10017(xx, action, _ctx); return kk_Unit;
}
 
// Invoke `action` for each element of a list


// lift anonymous function
struct kk_std_core_list__unroll_foreach_10017_fun1775__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_foreach_10017_fun1775(kk_function_t _fself, kk_box_t _b_x613, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_foreach_10017_fun1775(kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10017_fun1775__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_foreach_10017_fun1775__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_foreach_10017_fun1775, kk_context());
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_foreach_10017_fun1775(kk_function_t _fself, kk_box_t _b_x613, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_foreach_10017_fun1775__t* _self = kk_function_as(struct kk_std_core_list__unroll_foreach_10017_fun1775__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (3304) -> 3305 () */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3304> */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_615 = kk_Unit;
  kk_unit_unbox(_b_x613);
  kk_unit_t _x_x1776 = kk_Unit;
  kk_std_core_list__mlift_unroll_foreach_10017_10704(action_0, xx_0, wild___0_615, _ctx);
  return kk_unit_box(_x_x1776);
}

kk_unit_t kk_std_core_list__unroll_foreach_10017(kk_std_core_types__list xs, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (a) -> e ()) -> e () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1772 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1772->head;
    kk_std_core_types__list xx_0 = _con_x1772->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_unit_t x_0_10837 = kk_Unit;
    kk_function_t _x_x1773 = kk_function_dup(action_0, _ctx); /*(3304) -> 3305 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x1773, (_x_x1773, x, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1774 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_foreach_10017_fun1775(action_0, xx_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x1774); return kk_Unit;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_map_while_10018_10705(kk_std_core_types__cctx _acc, kk_function_t action, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10577, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, action : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10577, _ctx)) {
    kk_box_t y = _y_x10577._cons.Just.value;
    kk_std_core_types__list _trmc_x10398 = kk_datatype_null(); /*list<3382>*/;
    kk_std_core_types__list _trmc_x10399 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10398, _ctx); /*list<3382>*/;
    kk_field_addr_t _b_x621_626 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10399, _ctx)->tail, _ctx); /*@field-addr<list<3382>>*/;
    kk_std_core_types__cctx _x_x1777 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10399, _ctx)),_b_x621_626,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_map_while_10018(xx, action, _x_x1777, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(action, _ctx);
    kk_box_t _x_x1778 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1778, KK_OWNED, _ctx);
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_map_while_10018_fun1783__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t action_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_map_while_10018_fun1783(kk_function_t _fself, kk_box_t _b_x635, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_map_while_10018_fun1783(kk_std_core_types__cctx _acc_0, kk_function_t action_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10018_fun1783__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_map_while_10018_fun1783__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_map_while_10018_fun1783, kk_context());
  _self->_acc_0 = _acc_0;
  _self->action_0 = action_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_map_while_10018_fun1783(kk_function_t _fself, kk_box_t _b_x635, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_map_while_10018_fun1783__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_map_while_10018_fun1783__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<3382>> */
  kk_function_t action_0 = _self->action_0; /* (3381) -> 3383 maybe<3382> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3381> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(action_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10577_0_655 = kk_std_core_types__maybe_unbox(_b_x635, KK_OWNED, _ctx); /*maybe<3382>*/;
  kk_std_core_types__list _x_x1784 = kk_std_core_list__mlift_trmc_unroll_map_while_10018_10705(_acc_0, action_0, xx_0, _y_x10577_0_655, _ctx); /*list<3382>*/
  return kk_std_core_types__list_box(_x_x1784, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_map_while_10018(kk_std_core_types__list xs, kk_function_t action_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action_0, _ctx);
    kk_box_t _x_x1779 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1779, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1780 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1780->head;
    kk_std_core_types__list xx_0 = _con_x1780->tail;
    kk_reuse_t _ru_x1421 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1421 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10840;
    kk_function_t _x_x1781 = kk_function_dup(action_0, _ctx); /*(3381) -> 3383 maybe<3382>*/
    x_0_10840 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x1781, (_x_x1781, x, _ctx), _ctx); /*maybe<3382>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1421,kk_context());
      kk_std_core_types__maybe_drop(x_0_10840, _ctx);
      kk_box_t _x_x1782 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_map_while_10018_fun1783(_acc_0, action_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1782, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10840, _ctx)) {
      kk_box_t y_0 = x_0_10840._cons.Just.value;
      kk_std_core_types__list _trmc_x10398_0 = kk_datatype_null(); /*list<3382>*/;
      kk_std_core_types__list _trmc_x10399_0 = kk_std_core_types__new_Cons(_ru_x1421, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10398_0, _ctx); /*list<3382>*/;
      kk_field_addr_t _b_x641_649 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10399_0, _ctx)->tail, _ctx); /*@field-addr<list<3382>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1785 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10399_0, _ctx)),_b_x641_649,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1785;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1421,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(action_0, _ctx);
      kk_box_t _x_x1786 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1786, KK_OWNED, _ctx);
    }
  }
}
 
// Invoke `action` on each element of a list while `action` returns `Just`

kk_std_core_types__list kk_std_core_list__unroll_map_while_10018(kk_std_core_types__list xs_0, kk_function_t action_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, action : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x1787 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_map_while_10018(xs_0, action_1, _x_x1787, _ctx);
}
 
// monadic lift

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10706(kk_std_core_types__list _uniq_xx_10316, kk_function_t action, kk_ref_t i, kk_unit_t _uniq_x___10317, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, ()) -> <local<h>|e> () */ 
  kk_std_core_list__lift_foreach_indexed_10350(action, i, _uniq_xx_10316, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_0;
  kk_function_t action_0;
  kk_ref_t i_0;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790(kk_function_t _fself, kk_box_t _b_x661, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10707_fun1790(kk_std_core_types__list _uniq_xx_10316_0, kk_function_t action_0, kk_ref_t i_0, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790, kk_context());
  _self->_uniq_xx_10316_0 = _uniq_xx_10316_0;
  _self->action_0 = action_0;
  _self->i_0 = i_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790(kk_function_t _fself, kk_box_t _b_x661, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10707_fun1790__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_0 = _self->_uniq_xx_10316_0; /* list<3520> */
  kk_function_t action_0 = _self->action_0; /* (int, 3520) -> 3521 () */
  kk_ref_t i_0 = _self->i_0; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_0, _ctx);kk_function_dup(action_0, _ctx);kk_ref_dup(i_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10317_0_663 = kk_Unit;
  kk_unit_unbox(_b_x661);
  kk_unit_t _x_x1791 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10706(_uniq_xx_10316_0, action_0, i_0, _uniq_x___10317_0_663, _ctx);
  return kk_unit_box(_x_x1791);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10707(kk_std_core_types__list _uniq_xx_10316_0, kk_function_t action_0, kk_ref_t i_0, kk_integer_t _y_x10587, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_x657_659 = kk_integer_add_small_const(_y_x10587, 1, _ctx); /*int*/;
  kk_unit_t x_10845 = kk_Unit;
  kk_ref_set_borrow(i_0,(kk_integer_box(_b_x657_659, _ctx)),kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1789 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10707_fun1790(_uniq_xx_10316_0, action_0, i_0, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1789); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10350_10706(_uniq_xx_10316_0, action_0, i_0, x_10845, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_1;
  kk_function_t action_1;
  kk_ref_t i_1;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795(kk_function_t _fself, kk_box_t _b_x669, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10708_fun1795(kk_std_core_types__list _uniq_xx_10316_1, kk_function_t action_1, kk_ref_t i_1, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795, kk_context());
  _self->_uniq_xx_10316_1 = _uniq_xx_10316_1;
  _self->action_1 = action_1;
  _self->i_1 = i_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795(kk_function_t _fself, kk_box_t _b_x669, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10708_fun1795__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_1 = _self->_uniq_xx_10316_1; /* list<3520> */
  kk_function_t action_1 = _self->action_1; /* (int, 3520) -> 3521 () */
  kk_ref_t i_1 = _self->i_1; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_1, _ctx);kk_function_dup(action_1, _ctx);kk_ref_dup(i_1, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10587_0_671 = kk_integer_unbox(_b_x669, _ctx); /*int*/;
  kk_unit_t _x_x1796 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10707(_uniq_xx_10316_1, action_1, i_1, _y_x10587_0_671, _ctx);
  return kk_unit_box(_x_x1796);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10708(kk_std_core_types__list _uniq_xx_10316_1, kk_function_t action_1, kk_ref_t i_1, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,a,e> (list<a>, action : (int, a) -> e (), i : local-var<h,int>, wild_ : ()) -> <local<h>|e> () */ 
  kk_integer_t x_0_10847;
  kk_box_t _x_x1792;
  kk_ref_t _x_x1793 = kk_ref_dup(i_1, _ctx); /*local-var<3510,int>*/
  _x_x1792 = kk_ref_get(_x_x1793,kk_context()); /*298*/
  x_0_10847 = kk_integer_unbox(_x_x1792, _ctx); /*int*/
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_0_10847, _ctx);
    kk_box_t _x_x1794 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10708_fun1795(_uniq_xx_10316_1, action_1, i_1, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1794); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10350_10707(_uniq_xx_10316_1, action_1, i_1, x_0_10847, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_2;
  kk_function_t action_2;
  kk_ref_t i_2;
};
static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799(kk_function_t _fself, kk_box_t _b_x673, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10709_fun1799(kk_std_core_types__list _uniq_xx_10316_2, kk_function_t action_2, kk_ref_t i_2, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799__t* _self = kk_function_alloc_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799, kk_context());
  _self->_uniq_xx_10316_2 = _uniq_xx_10316_2;
  _self->action_2 = action_2;
  _self->i_2 = i_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799(kk_function_t _fself, kk_box_t _b_x673, kk_context_t* _ctx) {
  struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799__t* _self = kk_function_as(struct kk_std_core_list__mlift_lift_foreach_indexed_10350_10709_fun1799__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_2 = _self->_uniq_xx_10316_2; /* list<3520> */
  kk_function_t action_2 = _self->action_2; /* (int, 3520) -> 3521 () */
  kk_ref_t i_2 = _self->i_2; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_2, _ctx);kk_function_dup(action_2, _ctx);kk_ref_dup(i_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_675 = kk_Unit;
  kk_unit_unbox(_b_x673);
  kk_unit_t _x_x1800 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10708(_uniq_xx_10316_2, action_2, i_2, wild___0_675, _ctx);
  return kk_unit_box(_x_x1800);
}

kk_unit_t kk_std_core_list__mlift_lift_foreach_indexed_10350_10709(kk_box_t _uniq_x_10315, kk_std_core_types__list _uniq_xx_10316_2, kk_function_t action_2, kk_ref_t i_2, kk_integer_t j, kk_context_t* _ctx) { /* forall<h,a,e> (a, list<a>, action : (int, a) -> e (), i : local-var<h,int>, j : int) -> <local<h>|e> () */ 
  kk_unit_t x_1_10849 = kk_Unit;
  kk_function_t _x_x1797 = kk_function_dup(action_2, _ctx); /*(int, 3520) -> 3521 ()*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1797, (_x_x1797, j, _uniq_x_10315, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1798 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_mlift_lift_foreach_indexed_10350_10709_fun1799(_uniq_xx_10316_2, action_2, i_2, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x1798); return kk_Unit;
  }
  {
    kk_std_core_list__mlift_lift_foreach_indexed_10350_10708(_uniq_xx_10316_2, action_2, i_2, x_1_10849, _ctx); return kk_Unit;
  }
}
 
// lifted local: foreach-indexed, @spec-x10319
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10313, using:
// @uniq-action@10313 = fn<<(local :: H -> X)<(h :: H)>|(e :: E)>>(x: 3520){
//   val j : int;
//   val _ : ();
//   std/core/types/local-set<int,(e :: E),(h :: H)>(i, (std/core/types/@open<(total :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>,(x : int, y : int) -> int,(x : int, y : int) -> <(local :: H -> X)<(h :: H)>|(e :: E)> int>((fn(x@0: int, y: int){
//       (std/core/int/int-add(x@0, y));
//     }))((std/core/types/local-get<int,(h :: H),(e :: E)>(i, (std/core/types/@Hnodiv<(h :: H),int,(e :: E)>))), 1)));
// }


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10350_fun1805__t {
  struct kk_function_s _base;
  kk_box_t _uniq_x_10315_0;
  kk_std_core_types__list _uniq_xx_10316_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1805(kk_function_t _fself, kk_box_t _b_x681, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10350_fun1805(kk_box_t _uniq_x_10315_0, kk_std_core_types__list _uniq_xx_10316_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1805__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1805__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10350_fun1805, kk_context());
  _self->_uniq_x_10315_0 = _uniq_x_10315_0;
  _self->_uniq_xx_10316_3 = _uniq_xx_10316_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1805(kk_function_t _fself, kk_box_t _b_x681, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1805__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1805__t*, _fself, _ctx);
  kk_box_t _uniq_x_10315_0 = _self->_uniq_x_10315_0; /* 3520 */
  kk_std_core_types__list _uniq_xx_10316_3 = _self->_uniq_xx_10316_3; /* list<3520> */
  kk_function_t action_4 = _self->action_4; /* (int, 3520) -> 3521 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_box_dup(_uniq_x_10315_0, _ctx);kk_std_core_types__list_dup(_uniq_xx_10316_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t j_0_700 = kk_integer_unbox(_b_x681, _ctx); /*int*/;
  kk_unit_t _x_x1806 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10709(_uniq_x_10315_0, _uniq_xx_10316_3, action_4, i_3, j_0_700, _ctx);
  return kk_unit_box(_x_x1806);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10350_fun1809__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1809(kk_function_t _fself, kk_box_t _b_x683, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10350_fun1809(kk_std_core_types__list _uniq_xx_10316_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1809__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1809__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10350_fun1809, kk_context());
  _self->_uniq_xx_10316_3 = _uniq_xx_10316_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1809(kk_function_t _fself, kk_box_t _b_x683, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1809__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1809__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_3 = _self->_uniq_xx_10316_3; /* list<3520> */
  kk_function_t action_4 = _self->action_4; /* (int, 3520) -> 3521 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_701 = kk_Unit;
  kk_unit_unbox(_b_x683);
  kk_unit_t _x_x1810 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10708(_uniq_xx_10316_3, action_4, i_3, wild___1_701, _ctx);
  return kk_unit_box(_x_x1810);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10350_fun1814__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1814(kk_function_t _fself, kk_box_t _b_x689, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10350_fun1814(kk_std_core_types__list _uniq_xx_10316_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1814__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1814__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10350_fun1814, kk_context());
  _self->_uniq_xx_10316_3 = _uniq_xx_10316_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1814(kk_function_t _fself, kk_box_t _b_x689, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1814__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1814__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_3 = _self->_uniq_xx_10316_3; /* list<3520> */
  kk_function_t action_4 = _self->action_4; /* (int, 3520) -> 3521 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_integer_t _y_x10587_1_702 = kk_integer_unbox(_b_x689, _ctx); /*int*/;
  kk_unit_t _x_x1815 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10707(_uniq_xx_10316_3, action_4, i_3, _y_x10587_1_702, _ctx);
  return kk_unit_box(_x_x1815);
}


// lift anonymous function
struct kk_std_core_list__lift_foreach_indexed_10350_fun1817__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10316_3;
  kk_function_t action_4;
  kk_ref_t i_3;
};
static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1817(kk_function_t _fself, kk_box_t _b_x695, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_lift_foreach_indexed_10350_fun1817(kk_std_core_types__list _uniq_xx_10316_3, kk_function_t action_4, kk_ref_t i_3, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1817__t* _self = kk_function_alloc_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1817__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__lift_foreach_indexed_10350_fun1817, kk_context());
  _self->_uniq_xx_10316_3 = _uniq_xx_10316_3;
  _self->action_4 = action_4;
  _self->i_3 = i_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__lift_foreach_indexed_10350_fun1817(kk_function_t _fself, kk_box_t _b_x695, kk_context_t* _ctx) {
  struct kk_std_core_list__lift_foreach_indexed_10350_fun1817__t* _self = kk_function_as(struct kk_std_core_list__lift_foreach_indexed_10350_fun1817__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10316_3 = _self->_uniq_xx_10316_3; /* list<3520> */
  kk_function_t action_4 = _self->action_4; /* (int, 3520) -> 3521 () */
  kk_ref_t i_3 = _self->i_3; /* local-var<3510,int> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10316_3, _ctx);kk_function_dup(action_4, _ctx);kk_ref_dup(i_3, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10317_1_703 = kk_Unit;
  kk_unit_unbox(_b_x695);
  kk_unit_t _x_x1818 = kk_Unit;
  kk_std_core_list__mlift_lift_foreach_indexed_10350_10706(_uniq_xx_10316_3, action_4, i_3, _uniq_x___10317_1_703, _ctx);
  return kk_unit_box(_x_x1818);
}

kk_unit_t kk_std_core_list__lift_foreach_indexed_10350(kk_function_t action_4, kk_ref_t i_3, kk_std_core_types__list _uniq_xs_10312, kk_context_t* _ctx) { /* forall<h,a,e> (action : (int, a) -> e (), i : local-var<h,int>, list<a>) -> <local<h>|e> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10312, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1801 = kk_std_core_types__as_Cons(_uniq_xs_10312, _ctx);
    kk_box_t _uniq_x_10315_0 = _con_x1801->head;
    kk_std_core_types__list _uniq_xx_10316_3 = _con_x1801->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10312, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10312, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10315_0, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10316_3, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10312, _ctx);
    }
    kk_integer_t x_2_10852;
    kk_box_t _x_x1802;
    kk_ref_t _x_x1803 = kk_ref_dup(i_3, _ctx); /*local-var<3510,int>*/
    _x_x1802 = kk_ref_get(_x_x1803,kk_context()); /*298*/
    x_2_10852 = kk_integer_unbox(_x_x1802, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_2_10852, _ctx);
      kk_box_t _x_x1804 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10350_fun1805(_uniq_x_10315_0, _uniq_xx_10316_3, action_4, i_3, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x1804); return kk_Unit;
    }
    {
      kk_unit_t x_3_10855 = kk_Unit;
      kk_function_t _x_x1807 = kk_function_dup(action_4, _ctx); /*(int, 3520) -> 3521 ()*/
      kk_function_call(kk_unit_t, (kk_function_t, kk_integer_t, kk_box_t, kk_context_t*), _x_x1807, (_x_x1807, x_2_10852, _uniq_x_10315_0, _ctx), _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1808 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10350_fun1809(_uniq_xx_10316_3, action_4, i_3, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x1808); return kk_Unit;
      }
      {
        kk_integer_t x_4_10859;
        kk_box_t _x_x1811;
        kk_ref_t _x_x1812 = kk_ref_dup(i_3, _ctx); /*local-var<3510,int>*/
        _x_x1811 = kk_ref_get(_x_x1812,kk_context()); /*298*/
        x_4_10859 = kk_integer_unbox(_x_x1811, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_4_10859, _ctx);
          kk_box_t _x_x1813 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10350_fun1814(_uniq_xx_10316_3, action_4, i_3, _ctx), _ctx); /*2419*/
          kk_unit_unbox(_x_x1813); return kk_Unit;
        }
        {
          kk_integer_t _b_x691_693 = kk_integer_add_small_const(x_4_10859, 1, _ctx); /*int*/;
          kk_unit_t x_5_10862 = kk_Unit;
          kk_ref_set_borrow(i_3,(kk_integer_box(_b_x691_693, _ctx)),kk_context());
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1816 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_lift_foreach_indexed_10350_fun1817(_uniq_xx_10316_3, action_4, i_3, _ctx), _ctx); /*2419*/
            kk_unit_unbox(_x_x1816); return kk_Unit;
          }
          { // tailcall
            _uniq_xs_10312 = _uniq_xx_10316_3;
            goto kk__tailcall;
          }
        }
      }
    }
  }
  {
    kk_ref_drop(i_3, _ctx);
    kk_function_drop(action_4, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Invoke `action` for each element of a list, passing also the position of the element.

kk_unit_t kk_std_core_list_foreach_indexed(kk_std_core_types__list xs, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, action : (int, a) -> e ()) -> e () */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<3510,int>*/;
  kk_unit_t res = kk_Unit;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(action, _ctx);
  }
  else {
    kk_ref_t _x_x1819 = kk_ref_dup(loc, _ctx); /*local-var<3510,int>*/
    kk_std_core_list__lift_foreach_indexed_10350(action, _x_x1819, xs, _ctx);
  }
  kk_box_t _x_x1820 = kk_std_core_hnd_prompt_local_var(loc, kk_unit_box(res), _ctx); /*4162*/
  kk_unit_unbox(_x_x1820); return kk_Unit;
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__trmc_unroll_lift_intersperse_6007_10019(kk_box_t sep, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1821 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x1821->head;
    kk_std_core_types__list yy = _con_x1821->tail;
    kk_reuse_t _ru_x1423 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1423 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10400;
    kk_std_core_types__list _x_x1822 = kk_datatype_null(); /*list<3597>*/
    _trmc_x10400 = kk_std_core_types__new_Cons(_ru_x1423, 0, y, _x_x1822, _ctx); /*list<3597>*/
    kk_field_addr_t _b_x715_720 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10400, _ctx)->tail, _ctx); /*@field-addr<list<3597>>*/;
    { // tailcall
      kk_box_t _x_x1823 = kk_box_dup(sep, _ctx); /*3597*/
      kk_std_core_types__cctx _x_x1824;
      kk_box_t _x_x1825;
      kk_std_core_types__list _x_x1826 = kk_std_core_types__new_Cons(kk_reuse_null, 0, sep, _trmc_x10400, _ctx); /*list<79>*/
      _x_x1825 = kk_std_core_types__list_box(_x_x1826, _ctx); /*0*/
      _x_x1824 = kk_cctx_extend_linear(_acc,_x_x1825,_b_x715_720,kk_context()); /*ctx<0>*/
      sep = _x_x1823;
      ys = yy;
      _acc = _x_x1824;
      goto kk__tailcall;
    }
  }
  {
    kk_box_drop(sep, _ctx);
    kk_box_t _x_x1827 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1827, KK_OWNED, _ctx);
  }
}
 
// lifted local: intersperse, before

kk_std_core_types__list kk_std_core_list__unroll_lift_intersperse_6007_10019(kk_box_t sep_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (sep : a, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x1828 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_lift_intersperse_6007_10019(sep_0, ys_0, _x_x1828, _ctx);
}
 
// Insert a separator `sep`  between all elements of a list `xs` .

kk_std_core_types__list kk_std_core_list_intersperse(kk_std_core_types__list xs, kk_box_t sep, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, sep : a) -> list<a> */ 
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1830 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1830->head;
    kk_std_core_types__list xx = _con_x1830->tail;
    kk_reuse_t _ru_x1424 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1424 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _x_x1831;
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      kk_box_drop(sep, _ctx);
      _x_x1831 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
    }
    else {
      kk_std_core_types__cctx _x_x1832 = kk_cctx_empty(kk_context()); /*ctx<0>*/
      _x_x1831 = kk_std_core_list__trmc_unroll_lift_intersperse_6007_10019(sep, xx, _x_x1832, _ctx); /*forall<a> list<a>*/
    }
    return kk_std_core_types__new_Cons(_ru_x1424, 0, x, _x_x1831, _ctx);
  }
  {
    kk_box_drop(sep, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_joinsep(kk_std_core_types__list xs, kk_string_t sep, kk_context_t* _ctx) { /* (xs : list<string>, sep : string) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_string_drop(sep, _ctx);
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1834 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x726 = _con_x1834->head;
    kk_std_core_types__list _pat_1 = _con_x1834->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x726);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_string_drop(sep, _ctx);
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1835 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x727 = _con_x1835->head;
    kk_std_core_types__list _pat_3 = _con_x1835->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1836 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x728 = _con_x1836->head;
      kk_std_core_types__list _pat_4 = _con_x1836->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1837 = kk_string_dup(sep, _ctx); /*string*/
        kk_string_t _x_x1838 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1837,_x_x1838,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x727);
          kk_string_t y = kk_string_unbox(_box_x728);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          kk_string_drop(sep, _ctx);
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x1840 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    return kk_string_join_with(_x_x1840,sep,kk_context());
  }
}
 
// Concatenate all strings in a list

kk_string_t kk_std_core_list_concat_fs_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1842 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x729 = _con_x1842->head;
    kk_std_core_types__list _pat_1 = _con_x1842->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x729);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x1843 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x730 = _con_x1843->head;
    kk_std_core_types__list _pat_3 = _con_x1843->tail;
    struct kk_std_core_types_Cons* _con_x1844 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x731 = _con_x1844->head;
    kk_std_core_types__list _pat_4 = _con_x1844->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x730);
      kk_string_t y = kk_string_unbox(_box_x731);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x1845 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    return kk_string_join(_x_x1845,kk_context());
  }
}
 
// monadic lift

kk_string_t kk_std_core_list__mlift_show_10710(kk_std_core_types__list _c_x10596, kk_context_t* _ctx) { /* (list<string>) -> string */ 
  kk_string_t _x_x1846;
  kk_define_string_literal(static, _s_x1847, 1, "[", _ctx)
  _x_x1846 = kk_string_dup(_s_x1847, _ctx); /*string*/
  kk_string_t _x_x1848;
  kk_string_t _x_x1849;
  if (kk_std_core_types__is_Nil(_c_x10596, _ctx)) {
    _x_x1849 = kk_string_empty(); /*string*/
    goto _match_x1850;
  }
  {
    struct kk_std_core_types_Cons* _con_x1852 = kk_std_core_types__as_Cons(_c_x10596, _ctx);
    kk_box_t _box_x732 = _con_x1852->head;
    kk_std_core_types__list _pat_1 = _con_x1852->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x732);
      if kk_likely(kk_datatype_ptr_is_unique(_c_x10596, _ctx)) {
        kk_datatype_ptr_free(_c_x10596, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(_c_x10596, _ctx);
      }
      _x_x1849 = x; /*string*/
      goto _match_x1850;
    }
  }
  if (kk_std_core_types__is_Cons(_c_x10596, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1853 = kk_std_core_types__as_Cons(_c_x10596, _ctx);
    kk_box_t _box_x733 = _con_x1853->head;
    kk_std_core_types__list _pat_3 = _con_x1853->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1854 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x734 = _con_x1854->head;
      kk_std_core_types__list _pat_4 = _con_x1854->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x1855;
        kk_define_string_literal(static, _s_x1856, 1, ",", _ctx)
        _x_x1855 = kk_string_dup(_s_x1856, _ctx); /*string*/
        kk_string_t _x_x1857 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x1855,_x_x1857,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x733);
          kk_string_t y = kk_string_unbox(_box_x734);
          if kk_likely(kk_datatype_ptr_is_unique(_c_x10596, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(_c_x10596, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(_c_x10596, _ctx);
          }
          _x_x1849 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x1850;
        }
      }
    }
  }
  {
    kk_vector_t _x_x1859 = kk_std_core_vector_unvlist(_c_x10596, _ctx); /*vector<978>*/
    kk_string_t _x_x1860;
    kk_define_string_literal(static, _s_x1861, 1, ",", _ctx)
    _x_x1860 = kk_string_dup(_s_x1861, _ctx); /*string*/
    _x_x1849 = kk_string_join_with(_x_x1859,_x_x1860,kk_context()); /*string*/
  }
  _match_x1850: ;
  kk_string_t _x_x1862;
  kk_define_string_literal(static, _s_x1863, 1, "]", _ctx)
  _x_x1862 = kk_string_dup(_s_x1863, _ctx); /*string*/
  _x_x1848 = kk_std_core_types__lp__plus__plus__rp_(_x_x1849, _x_x1862, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1846, _x_x1848, _ctx);
}
 
// Show a list


// lift anonymous function
struct kk_std_core_list_show_fun1864__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_show;
};
static kk_box_t kk_std_core_list_show_fun1864(kk_function_t _fself, kk_box_t _b_x738, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1864(kk_function_t _implicit_fs_show, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1864__t* _self = kk_function_alloc_as(struct kk_std_core_list_show_fun1864__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list_show_fun1864, kk_context());
  _self->_implicit_fs_show = _implicit_fs_show;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list_show_fun1864(kk_function_t _fself, kk_box_t _b_x738, kk_context_t* _ctx) {
  struct kk_std_core_list_show_fun1864__t* _self = kk_function_as(struct kk_std_core_list_show_fun1864__t*, _fself, _ctx);
  kk_function_t _implicit_fs_show = _self->_implicit_fs_show; /* (3800) -> 3801 string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_show, _ctx);}, {}, _ctx)
  kk_string_t _x_x1865 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, _b_x738, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1865);
}


// lift anonymous function
struct kk_std_core_list_show_fun1867__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_list_show_fun1867(kk_function_t _fself, kk_box_t _b_x743, kk_context_t* _ctx);
static kk_function_t kk_std_core_list_new_show_fun1867(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_list_show_fun1867, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_list_show_fun1867(kk_function_t _fself, kk_box_t _b_x743, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1868;
  kk_std_core_types__list _x_x1869 = kk_std_core_types__list_unbox(_b_x743, KK_OWNED, _ctx); /*list<string>*/
  _x_x1868 = kk_std_core_list__mlift_show_10710(_x_x1869, _ctx); /*string*/
  return kk_string_box(_x_x1868);
}

kk_string_t kk_std_core_list_show(kk_std_core_types__list xs, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, ?show : (a) -> e string) -> e string */ 
  kk_std_core_types__list x_10871;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(_implicit_fs_show, _ctx);
    x_10871 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    kk_std_core_types__cctx _b_x737_741 = kk_cctx_empty(kk_context()); /*ctx<list<string>>*/;
    kk_function_t _brw_x1315 = kk_std_core_list_new_show_fun1864(_implicit_fs_show, _ctx); /*(2228) -> 2230 2229*/;
    kk_std_core_types__list _brw_x1316 = kk_std_core_list__trmc_unroll_map_10010(xs, _brw_x1315, _b_x737_741, _ctx); /*list<2229>*/;
    kk_function_drop(_brw_x1315, _ctx);
    x_10871 = _brw_x1316; /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10871, _ctx);
    kk_box_t _x_x1866 = kk_std_core_hnd_yield_extend(kk_std_core_list_new_show_fun1867(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1866);
  }
  {
    kk_string_t _x_x1870;
    kk_define_string_literal(static, _s_x1871, 1, "[", _ctx)
    _x_x1870 = kk_string_dup(_s_x1871, _ctx); /*string*/
    kk_string_t _x_x1872;
    kk_string_t _x_x1873;
    if (kk_std_core_types__is_Nil(x_10871, _ctx)) {
      _x_x1873 = kk_string_empty(); /*string*/
      goto _match_x1874;
    }
    {
      struct kk_std_core_types_Cons* _con_x1876 = kk_std_core_types__as_Cons(x_10871, _ctx);
      kk_box_t _box_x744 = _con_x1876->head;
      kk_std_core_types__list _pat_1_0 = _con_x1876->tail;
      if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
        kk_string_t x_0 = kk_string_unbox(_box_x744);
        if kk_likely(kk_datatype_ptr_is_unique(x_10871, _ctx)) {
          kk_datatype_ptr_free(x_10871, _ctx);
        }
        else {
          kk_string_dup(x_0, _ctx);
          kk_datatype_ptr_decref(x_10871, _ctx);
        }
        _x_x1873 = x_0; /*string*/
        goto _match_x1874;
      }
    }
    if (kk_std_core_types__is_Cons(x_10871, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1877 = kk_std_core_types__as_Cons(x_10871, _ctx);
      kk_box_t _box_x745 = _con_x1877->head;
      kk_std_core_types__list _pat_3 = _con_x1877->tail;
      if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1878 = kk_std_core_types__as_Cons(_pat_3, _ctx);
        kk_box_t _box_x746 = _con_x1878->head;
        kk_std_core_types__list _pat_4 = _con_x1878->tail;
        if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
          kk_string_t _x_x1879;
          kk_define_string_literal(static, _s_x1880, 1, ",", _ctx)
          _x_x1879 = kk_string_dup(_s_x1880, _ctx); /*string*/
          kk_string_t _x_x1881 = kk_string_empty(); /*string*/
          if (kk_string_is_eq(_x_x1879,_x_x1881,kk_context())) {
            kk_string_t x_0_0 = kk_string_unbox(_box_x745);
            kk_string_t y = kk_string_unbox(_box_x746);
            if kk_likely(kk_datatype_ptr_is_unique(x_10871, _ctx)) {
              if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
                kk_datatype_ptr_free(_pat_3, _ctx);
              }
              else {
                kk_string_dup(y, _ctx);
                kk_datatype_ptr_decref(_pat_3, _ctx);
              }
              kk_datatype_ptr_free(x_10871, _ctx);
            }
            else {
              kk_string_dup(x_0_0, _ctx);
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(x_10871, _ctx);
            }
            _x_x1873 = kk_std_core_types__lp__plus__plus__rp_(x_0_0, y, _ctx); /*string*/
            goto _match_x1874;
          }
        }
      }
    }
    {
      kk_vector_t _x_x1883 = kk_std_core_vector_unvlist(x_10871, _ctx); /*vector<978>*/
      kk_string_t _x_x1884;
      kk_define_string_literal(static, _s_x1885, 1, ",", _ctx)
      _x_x1884 = kk_string_dup(_s_x1885, _ctx); /*string*/
      _x_x1873 = kk_string_join_with(_x_x1883,_x_x1884,kk_context()); /*string*/
    }
    _match_x1874: ;
    kk_string_t _x_x1886;
    kk_define_string_literal(static, _s_x1887, 1, "]", _ctx)
    _x_x1886 = kk_string_dup(_s_x1887, _ctx); /*string*/
    _x_x1872 = kk_std_core_types__lp__plus__plus__rp_(_x_x1873, _x_x1886, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x1870, _x_x1872, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__trmc_unroll_zip_10020(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>, ctx<list<(a, b)>>) -> list<(a, b)> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1888 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1888->head;
    kk_std_core_types__list xx = _con_x1888->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1889 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1889->head;
      kk_std_core_types__list yy = _con_x1889->tail;
      kk_reuse_t _ru_x1438 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1438 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_std_core_types__list _trmc_x10402 = kk_datatype_null(); /*list<(3917, 3918)>*/;
      kk_std_core_types__list _trmc_x10403;
      kk_box_t _x_x1890;
      kk_std_core_types__tuple2 _x_x1891 = kk_std_core_types__new_Tuple2(x, y, _ctx); /*(134, 135)*/
      _x_x1890 = kk_std_core_types__tuple2_box(_x_x1891, _ctx); /*79*/
      _trmc_x10403 = kk_std_core_types__new_Cons(_ru_x1438, 0, _x_x1890, _trmc_x10402, _ctx); /*list<(3917, 3918)>*/
      kk_field_addr_t _b_x757_764 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10403, _ctx)->tail, _ctx); /*@field-addr<list<(3917, 3918)>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1892 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10403, _ctx)),_b_x757_764,kk_context()); /*ctx<0>*/
        xs = xx;
        ys = yy;
        _acc = _x_x1892;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1893 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1893, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1894 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1894, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by pairing the corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zip_10020(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, ys : list<b>) -> list<(a, b)> */ 
  kk_std_core_types__cctx _x_x1895 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_zip_10020(xs_0, ys_0, _x_x1895, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_10021_10711(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10404, kk_context_t* _ctx) { /* forall<a,b,c,e> (ctx<list<c>>, f : (a, b) -> e c, xx : list<a>, yy : list<b>, c) -> e list<c> */ 
  kk_std_core_types__list _trmc_x10405 = kk_datatype_null(); /*list<4000>*/;
  kk_std_core_types__list _trmc_x10406 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10404, _trmc_x10405, _ctx); /*list<4000>*/;
  kk_field_addr_t _b_x777_780 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10406, _ctx)->tail, _ctx); /*@field-addr<list<4000>>*/;
  kk_std_core_types__cctx _own_x1312 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10406, _ctx)),_b_x777_780,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1313 = kk_std_core_list__trmc_unroll_zipwith_10021(xx, yy, f, _own_x1312, _ctx); /*list<4000>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1313;
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_zipwith_10021_fun1902__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10021_fun1902(kk_function_t _fself, kk_box_t _b_x785, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_zipwith_10021_fun1902(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10021_fun1902__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_zipwith_10021_fun1902__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_zipwith_10021_fun1902, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_zipwith_10021_fun1902(kk_function_t _fself, kk_box_t _b_x785, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_10021_fun1902__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_zipwith_10021_fun1902__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4000>> */
  kk_function_t f_0 = _self->f_0; /* (3998, 3999) -> 4001 4000 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<3998> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<3999> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10404_0_807 = _b_x785; /*4000*/;
  kk_std_core_types__list _x_x1903 = kk_std_core_list__mlift_trmc_unroll_zipwith_10021_10711(_acc_0, f_0, xx_0, yy_0, _trmc_x10404_0_807, _ctx); /*list<4000>*/
  return kk_std_core_types__list_box(_x_x1903, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_10021(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1897 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1897->head;
    kk_std_core_types__list xx_0 = _con_x1897->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1898 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1898->head;
      kk_std_core_types__list yy_0 = _con_x1898->tail;
      kk_reuse_t _ru_x1440 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1440 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10878;
      kk_function_t _x_x1899 = kk_function_dup(f_0, _ctx); /*(3998, 3999) -> 4001 4000*/
      x_0_10878 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1899, (_x_x1899, x, y, _ctx), _ctx); /*4000*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1440,kk_context());
        kk_box_drop(x_0_10878, _ctx);
        kk_box_t _x_x1900;
        kk_function_t _x_x1901;
        kk_function_dup(f_0, _ctx);
        _x_x1901 = kk_std_core_list__new_trmc_unroll_zipwith_10021_fun1902(_acc_0, f_0, xx_0, yy_0, _ctx); /*(2418) -> 2420 2419*/
        _x_x1900 = kk_std_core_hnd_yield_extend(_x_x1901, _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x1900, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10405_0 = kk_datatype_null(); /*list<4000>*/;
        kk_std_core_types__list _trmc_x10406_0 = kk_std_core_types__new_Cons(_ru_x1440, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10878, _trmc_x10405_0, _ctx); /*list<4000>*/;
        kk_field_addr_t _b_x791_799 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10406_0, _ctx)->tail, _ctx); /*@field-addr<list<4000>>*/;
        kk_std_core_types__cctx _own_x1311 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10406_0, _ctx)),_b_x791_799,kk_context()); /*ctx<0>*/;
        { // tailcall
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _own_x1311;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_box_t _x_x1904 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1904, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_box_t _x_x1905 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1905, KK_OWNED, _ctx);
  }
}
 
// Zip two lists together by apply a function `f` to all corresponding elements.
// The returned list is only as long as the smallest input list.

kk_std_core_types__list kk_std_core_list__unroll_zipwith_10021(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (xs : list<a>, ys : list<b>, f : (a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _own_x1309 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_zipwith_10021(xs_0, ys_0, f_1, _own_x1309, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_zipwith_iter_10022_10712(kk_std_core_types__cctx _acc, kk_function_t f, kk_integer_t i, kk_std_core_types__list xx, kk_std_core_types__list yy, kk_box_t _trmc_x10407, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (ctx<list<a>>, f : (int, b, c) -> e d, i : int, xx : list<b>, yy : list<c>, d) -> e list<d> */ 
  kk_std_core_types__list _trmc_x10408 = kk_datatype_null(); /*list<4086>*/;
  kk_std_core_types__list _trmc_x10409 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), _trmc_x10407, _trmc_x10408, _ctx); /*list<4086>*/;
  kk_field_addr_t _b_x813_816 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10409, _ctx)->tail, _ctx); /*@field-addr<list<4086>>*/;
  kk_integer_t _own_x1306 = kk_integer_add_small_const(i, 1, _ctx); /*int*/;
  kk_std_core_types__cctx _own_x1305 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10409, _ctx)),_b_x813_816,kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1307 = kk_std_core_list__trmc_unroll_zipwith_iter_10022(_own_x1306, xx, yy, f, _own_x1305, _ctx); /*list<4082>*/;
  kk_function_drop(f, _ctx);
  return _brw_x1307;
}


// lift anonymous function
struct kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_integer_t i_0;
  kk_std_core_types__list xx_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_zipwith_iter_10022_fun1912(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_integer_t i_0, kk_std_core_types__list xx_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->i_0 = i_0;
  _self->xx_0 = xx_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_zipwith_iter_10022_fun1912__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<4082>> */
  kk_function_t f_0 = _self->f_0; /* (int, 4084, 4085) -> 4087 4086 */
  kk_integer_t i_0 = _self->i_0; /* int */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<4084> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<4085> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_integer_dup(i_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  kk_box_t _trmc_x10407_0_843 = _b_x821; /*4086*/;
  kk_std_core_types__list _x_x1913 = kk_std_core_list__mlift_trmc_unroll_zipwith_iter_10022_10712(_acc_0, f_0, i_0, xx_0, yy_0, _trmc_x10407_0_843, _ctx); /*list<4086>*/
  return kk_std_core_types__list_box(_x_x1913, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_zipwith_iter_10022(kk_integer_t i_0, kk_std_core_types__list xs, kk_std_core_types__list ys, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,c,e> (i : int, xs : list<a>, ys : list<b>, f : (int, a, b) -> e c, ctx<list<c>>) -> e list<c> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1906 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x1906->head;
    kk_std_core_types__list xx_0 = _con_x1906->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Cons(ys, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1907 = kk_std_core_types__as_Cons(ys, _ctx);
      kk_box_t y = _con_x1907->head;
      kk_std_core_types__list yy_0 = _con_x1907->tail;
      kk_reuse_t _ru_x1442 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
        _ru_x1442 = (kk_datatype_ptr_reuse(ys, _ctx));
      }
      else {
        kk_box_dup(y, _ctx);
        kk_std_core_types__list_dup(yy_0, _ctx);
        kk_datatype_ptr_decref(ys, _ctx);
      }
      kk_box_t x_0_10884;
      kk_function_t _x_x1909 = kk_function_dup(f_0, _ctx); /*(int, 4084, 4085) -> 4087 4086*/
      kk_integer_t _x_x1908 = kk_integer_dup(i_0, _ctx); /*int*/
      x_0_10884 = kk_function_call(kk_box_t, (kk_function_t, kk_integer_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1909, (_x_x1909, _x_x1908, x, y, _ctx), _ctx); /*4086*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x1442,kk_context());
        kk_box_drop(x_0_10884, _ctx);
        kk_box_t _x_x1910;
        kk_function_t _x_x1911;
        kk_function_dup(f_0, _ctx);
        _x_x1911 = kk_std_core_list__new_trmc_unroll_zipwith_iter_10022_fun1912(_acc_0, f_0, i_0, xx_0, yy_0, _ctx); /*(2418) -> 2420 2419*/
        _x_x1910 = kk_std_core_hnd_yield_extend(_x_x1911, _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x1910, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list _trmc_x10408_0 = kk_datatype_null(); /*list<4086>*/;
        kk_std_core_types__list _trmc_x10409_0 = kk_std_core_types__new_Cons(_ru_x1442, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0_10884, _trmc_x10408_0, _ctx); /*list<4086>*/;
        kk_field_addr_t _b_x827_835 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10409_0, _ctx)->tail, _ctx); /*@field-addr<list<4086>>*/;
        kk_integer_t _own_x1304 = kk_integer_add_small_const(i_0, 1, _ctx); /*int*/;
        kk_std_core_types__cctx _own_x1303 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10409_0, _ctx)),_b_x827_835,kk_context()); /*ctx<0>*/;
        { // tailcall
          i_0 = _own_x1304;
          xs = xx_0;
          ys = yy_0;
          _acc_0 = _own_x1303;
          goto kk__tailcall;
        }
      }
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x, _ctx);
      kk_integer_drop(i_0, _ctx);
      kk_box_t _x_x1914 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1914, KK_OWNED, _ctx);
    }
  }
  {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_integer_drop(i_0, _ctx);
    kk_box_t _x_x1915 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1915, KK_OWNED, _ctx);
  }
}

kk_std_core_types__list kk_std_core_list__unroll_zipwith_iter_10022(kk_integer_t i_1, kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,c,e> (i : int, xs : list<a>, ys : list<b>, f : (int, a, b) -> e c) -> e list<c> */ 
  kk_std_core_types__cctx _own_x1301 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  return kk_std_core_list__trmc_unroll_zipwith_iter_10022(i_1, xs_0, ys_0, f_1, _own_x1301, _ctx);
}
 
// lifted local: unzip, iter

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_unzip_6008_10023(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_context_t* _ctx) { /* forall<a,b,c,d> (ys : list<(a, b)>, acc1 : cctx<c,list<a>>, acc2 : cctx<d,list<b>>) -> (c, d) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1916 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x844 = _con_x1916->head;
    kk_std_core_types__tuple2 _pat_0 = kk_std_core_types__tuple2_unbox(_box_x844, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1916->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_reuse_t _ru_x1443 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_drop(_box_x844, _ctx);
      _ru_x1443 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x4190;
    kk_std_core_types__list _x_x1917 = kk_datatype_null(); /*list<4297>*/
    _cctx_x4190 = kk_std_core_types__new_Cons(_ru_x1443, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1917, _ctx); /*list<4297>*/
    kk_field_addr_t _cctx_x4191 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4190, _ctx)->tail, _ctx); /*@field-addr<list<4297>>*/;
    kk_std_core_types__list _cctx_x4233;
    kk_std_core_types__list _x_x1918 = kk_datatype_null(); /*list<4298>*/
    _cctx_x4233 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1918, _ctx); /*list<4298>*/
    kk_field_addr_t _cctx_x4234 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4233, _ctx)->tail, _ctx); /*@field-addr<list<4298>>*/;
    kk_std_core_types__list _b_x857_865 = _cctx_x4190; /*list<4297>*/;
    kk_field_addr_t _b_x858_866 = _cctx_x4191; /*@field-addr<list<4297>>*/;
    kk_std_core_types__list _b_x859_867 = _cctx_x4233; /*list<4298>*/;
    kk_field_addr_t _b_x860_868 = _cctx_x4234; /*@field-addr<list<4298>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1919;
      kk_std_core_types__cctx _x_x1920 = kk_cctx_create((kk_std_core_types__list_box(_b_x857_865, _ctx)),_b_x858_866,kk_context()); /*cctx<0,1>*/
      _x_x1919 = kk_cctx_compose(acc1,_x_x1920,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1921;
      kk_std_core_types__cctx _x_x1922 = kk_cctx_create((kk_std_core_types__list_box(_b_x859_867, _ctx)),_b_x860_868,kk_context()); /*cctx<0,1>*/
      _x_x1921 = kk_cctx_compose(acc2,_x_x1922,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1919;
      acc2 = _x_x1921;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1923 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1924 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple2(_x_x1923, _x_x1924, _ctx);
  }
}
 
// Unzip a list of pairs into two lists

kk_std_core_types__tuple2 kk_std_core_list_unzip(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b> (xs : list<(a, b)>) -> (list<a>, list<b>) */ 
  kk_std_core_types__cctx acc1_10152 = kk_cctx_empty(kk_context()); /*ctx<list<4346>>*/;
  kk_std_core_types__cctx acc2_10153 = kk_cctx_empty(kk_context()); /*ctx<list<4347>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x885_887;
    kk_box_t _x_x1927 = kk_cctx_apply(acc1_10152,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x885_887 = kk_std_core_types__list_unbox(_x_x1927, KK_OWNED, _ctx); /*list<4346>*/
    kk_std_core_types__list _b_x886_888;
    kk_box_t _x_x1928 = kk_cctx_apply(acc2_10153,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x886_888 = kk_std_core_types__list_unbox(_x_x1928, KK_OWNED, _ctx); /*list<4347>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x885_887, _ctx), kk_std_core_types__list_box(_b_x886_888, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip_6008_10023(xs, acc1_10152, acc2_10153, _ctx);
  }
}
 
// lifted local: unzip3, iter

kk_std_core_types__tuple3 kk_std_core_list__unroll_lift_unzip3_6009_10024(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1> (ys : list<(a, b, c)>, acc1 : cctx<d,list<a>>, acc2 : cctx<a1,list<b>>, acc3 : cctx<b1,list<c>>) -> (d, a1, b1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1929 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x893 = _con_x1929->head;
    kk_std_core_types__tuple3 _pat_0 = kk_std_core_types__tuple3_unbox(_box_x893, KK_BORROWED, _ctx);
    kk_std_core_types__list xx = _con_x1929->tail;
    kk_box_t x = _pat_0.fst;
    kk_box_t y = _pat_0.snd;
    kk_box_t z = _pat_0.thd;
    kk_reuse_t _ru_x1444 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      kk_box_dup(x, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_box_drop(_box_x893, _ctx);
      _ru_x1444 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x4406;
    kk_std_core_types__list _x_x1930 = kk_datatype_null(); /*list<4575>*/
    _cctx_x4406 = kk_std_core_types__new_Cons(_ru_x1444, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1930, _ctx); /*list<4575>*/
    kk_field_addr_t _cctx_x4407 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4406, _ctx)->tail, _ctx); /*@field-addr<list<4575>>*/;
    kk_std_core_types__list _cctx_x4449;
    kk_std_core_types__list _x_x1931 = kk_datatype_null(); /*list<4576>*/
    _cctx_x4449 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1931, _ctx); /*list<4576>*/
    kk_field_addr_t _cctx_x4450 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4449, _ctx)->tail, _ctx); /*@field-addr<list<4576>>*/;
    kk_std_core_types__list _cctx_x4492;
    kk_std_core_types__list _x_x1932 = kk_datatype_null(); /*list<4577>*/
    _cctx_x4492 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1932, _ctx); /*list<4577>*/
    kk_field_addr_t _cctx_x4493 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4492, _ctx)->tail, _ctx); /*@field-addr<list<4577>>*/;
    kk_std_core_types__list _b_x912_924 = _cctx_x4406; /*list<4575>*/;
    kk_field_addr_t _b_x913_925 = _cctx_x4407; /*@field-addr<list<4575>>*/;
    kk_std_core_types__list _b_x914_926 = _cctx_x4449; /*list<4576>*/;
    kk_field_addr_t _b_x915_927 = _cctx_x4450; /*@field-addr<list<4576>>*/;
    kk_std_core_types__list _b_x916_928 = _cctx_x4492; /*list<4577>*/;
    kk_field_addr_t _b_x917_929 = _cctx_x4493; /*@field-addr<list<4577>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1933;
      kk_std_core_types__cctx _x_x1934 = kk_cctx_create((kk_std_core_types__list_box(_b_x912_924, _ctx)),_b_x913_925,kk_context()); /*cctx<0,1>*/
      _x_x1933 = kk_cctx_compose(acc1,_x_x1934,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1935;
      kk_std_core_types__cctx _x_x1936 = kk_cctx_create((kk_std_core_types__list_box(_b_x914_926, _ctx)),_b_x915_927,kk_context()); /*cctx<0,1>*/
      _x_x1935 = kk_cctx_compose(acc2,_x_x1936,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1937;
      kk_std_core_types__cctx _x_x1938 = kk_cctx_create((kk_std_core_types__list_box(_b_x916_928, _ctx)),_b_x917_929,kk_context()); /*cctx<0,1>*/
      _x_x1937 = kk_cctx_compose(acc3,_x_x1938,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1933;
      acc2 = _x_x1935;
      acc3 = _x_x1937;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1939 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1940 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1941 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple3(_x_x1939, _x_x1940, _x_x1941, _ctx);
  }
}
 
// Unzip a list of triples into three lists

kk_std_core_types__tuple3 kk_std_core_list_unzip3(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c> (xs : list<(a, b, c)>) -> (list<a>, list<b>, list<c>) */ 
  kk_std_core_types__cctx acc1_10155 = kk_cctx_empty(kk_context()); /*ctx<list<4645>>*/;
  kk_std_core_types__cctx acc2_10156 = kk_cctx_empty(kk_context()); /*ctx<list<4646>>*/;
  kk_std_core_types__cctx acc3_10157 = kk_cctx_empty(kk_context()); /*ctx<list<4647>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x954_957;
    kk_box_t _x_x1945 = kk_cctx_apply(acc1_10155,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x954_957 = kk_std_core_types__list_unbox(_x_x1945, KK_OWNED, _ctx); /*list<4645>*/
    kk_std_core_types__list _b_x955_958;
    kk_box_t _x_x1946 = kk_cctx_apply(acc2_10156,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x955_958 = kk_std_core_types__list_unbox(_x_x1946, KK_OWNED, _ctx); /*list<4646>*/
    kk_std_core_types__list _b_x956_959;
    kk_box_t _x_x1947 = kk_cctx_apply(acc3_10157,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x956_959 = kk_std_core_types__list_unbox(_x_x1947, KK_OWNED, _ctx); /*list<4647>*/
    return kk_std_core_types__new_Tuple3(kk_std_core_types__list_box(_b_x954_957, _ctx), kk_std_core_types__list_box(_b_x955_958, _ctx), kk_std_core_types__list_box(_b_x956_959, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip3_6009_10024(xs, acc1_10155, acc2_10156, acc3_10157, _ctx);
  }
}
 
// lifted local: unzip4, iter

kk_std_core_types__tuple4 kk_std_core_list__unroll_lift_unzip4_6010_10025(kk_std_core_types__list ys, kk_std_core_types__cctx acc1, kk_std_core_types__cctx acc2, kk_std_core_types__cctx acc3, kk_std_core_types__cctx acc4, kk_context_t* _ctx) { /* forall<a,b,c,d,a1,b1,c1,d1> (ys : list<(a, b, c, d)>, acc1 : cctx<a1,list<a>>, acc2 : cctx<b1,list<b>>, acc3 : cctx<c1,list<c>>, acc4 : cctx<d1,list<d>>) -> (a1, b1, c1, d1) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1948 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t _box_x966 = _con_x1948->head;
    kk_std_core_types__tuple4 _pat_0 = kk_std_core_types__tuple4_unbox(_box_x966, KK_BORROWED, _ctx);
    struct kk_std_core_types_Tuple4* _con_x1949 = kk_std_core_types__as_Tuple4(_pat_0, _ctx);
    kk_std_core_types__list xx = _con_x1948->tail;
    kk_box_t x = _con_x1949->fst;
    kk_box_t y = _con_x1949->snd;
    kk_box_t z = _con_x1949->thd;
    kk_box_t w = _con_x1949->field4;
    kk_reuse_t _ru_x1446 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_0, _ctx)) {
        kk_datatype_ptr_free(_pat_0, _ctx);
      }
      else {
        kk_box_dup(w, _ctx);
        kk_box_dup(x, _ctx);
        kk_box_dup(y, _ctx);
        kk_box_dup(z, _ctx);
        kk_datatype_ptr_decref(_pat_0, _ctx);
      }
      _ru_x1446 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(w, _ctx);
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_box_dup(y, _ctx);
      kk_box_dup(z, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _cctx_x4713;
    kk_std_core_types__list _x_x1950 = kk_datatype_null(); /*list<4944>*/
    _cctx_x4713 = kk_std_core_types__new_Cons(_ru_x1446, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _x_x1950, _ctx); /*list<4944>*/
    kk_field_addr_t _cctx_x4714 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4713, _ctx)->tail, _ctx); /*@field-addr<list<4944>>*/;
    kk_std_core_types__list _cctx_x4756;
    kk_std_core_types__list _x_x1951 = kk_datatype_null(); /*list<4945>*/
    _cctx_x4756 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1951, _ctx); /*list<4945>*/
    kk_field_addr_t _cctx_x4757 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4756, _ctx)->tail, _ctx); /*@field-addr<list<4945>>*/;
    kk_std_core_types__list _cctx_x4799;
    kk_std_core_types__list _x_x1952 = kk_datatype_null(); /*list<4946>*/
    _cctx_x4799 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), z, _x_x1952, _ctx); /*list<4946>*/
    kk_field_addr_t _cctx_x4800 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4799, _ctx)->tail, _ctx); /*@field-addr<list<4946>>*/;
    kk_std_core_types__list _cctx_x4842;
    kk_std_core_types__list _x_x1953 = kk_datatype_null(); /*list<4947>*/
    _cctx_x4842 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), w, _x_x1953, _ctx); /*list<4947>*/
    kk_field_addr_t _cctx_x4843 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x4842, _ctx)->tail, _ctx); /*@field-addr<list<4947>>*/;
    kk_std_core_types__list _b_x991_1007 = _cctx_x4713; /*list<4944>*/;
    kk_field_addr_t _b_x992_1008 = _cctx_x4714; /*@field-addr<list<4944>>*/;
    kk_std_core_types__list _b_x993_1009 = _cctx_x4756; /*list<4945>*/;
    kk_field_addr_t _b_x994_1010 = _cctx_x4757; /*@field-addr<list<4945>>*/;
    kk_std_core_types__list _b_x995_1011 = _cctx_x4799; /*list<4946>*/;
    kk_field_addr_t _b_x996_1012 = _cctx_x4800; /*@field-addr<list<4946>>*/;
    kk_std_core_types__list _b_x997_1013 = _cctx_x4842; /*list<4947>*/;
    kk_field_addr_t _b_x998_1014 = _cctx_x4843; /*@field-addr<list<4947>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1954;
      kk_std_core_types__cctx _x_x1955 = kk_cctx_create((kk_std_core_types__list_box(_b_x991_1007, _ctx)),_b_x992_1008,kk_context()); /*cctx<0,1>*/
      _x_x1954 = kk_cctx_compose(acc1,_x_x1955,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1956;
      kk_std_core_types__cctx _x_x1957 = kk_cctx_create((kk_std_core_types__list_box(_b_x993_1009, _ctx)),_b_x994_1010,kk_context()); /*cctx<0,1>*/
      _x_x1956 = kk_cctx_compose(acc2,_x_x1957,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1958;
      kk_std_core_types__cctx _x_x1959 = kk_cctx_create((kk_std_core_types__list_box(_b_x995_1011, _ctx)),_b_x996_1012,kk_context()); /*cctx<0,1>*/
      _x_x1958 = kk_cctx_compose(acc3,_x_x1959,kk_context()); /*cctx<394,396>*/
      kk_std_core_types__cctx _x_x1960;
      kk_std_core_types__cctx _x_x1961 = kk_cctx_create((kk_std_core_types__list_box(_b_x997_1013, _ctx)),_b_x998_1014,kk_context()); /*cctx<0,1>*/
      _x_x1960 = kk_cctx_compose(acc4,_x_x1961,kk_context()); /*cctx<394,396>*/
      ys = xx;
      acc1 = _x_x1954;
      acc2 = _x_x1956;
      acc3 = _x_x1958;
      acc4 = _x_x1960;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x1962 = kk_cctx_apply(acc1,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1963 = kk_cctx_apply(acc2,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1964 = kk_cctx_apply(acc3,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    kk_box_t _x_x1965 = kk_cctx_apply(acc4,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1962, _x_x1963, _x_x1964, _x_x1965, _ctx);
  }
}
 
// Unzip a list of quadruples into four lists

kk_std_core_types__tuple4 kk_std_core_list_unzip4(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,b,c,d> (xs : list<(a, b, c, d)>) -> (list<a>, list<b>, list<c>, list<d>) */ 
  kk_std_core_types__cctx acc1_10159 = kk_cctx_empty(kk_context()); /*ctx<list<5035>>*/;
  kk_std_core_types__cctx acc2_10160 = kk_cctx_empty(kk_context()); /*ctx<list<5036>>*/;
  kk_std_core_types__cctx acc3_10161 = kk_cctx_empty(kk_context()); /*ctx<list<5037>>*/;
  kk_std_core_types__cctx acc4_10162 = kk_cctx_empty(kk_context()); /*ctx<list<5038>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_std_core_types__list _b_x1047_1051;
    kk_box_t _x_x1970 = kk_cctx_apply(acc1_10159,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1047_1051 = kk_std_core_types__list_unbox(_x_x1970, KK_OWNED, _ctx); /*list<5035>*/
    kk_std_core_types__list _b_x1048_1052;
    kk_box_t _x_x1971 = kk_cctx_apply(acc2_10160,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1048_1052 = kk_std_core_types__list_unbox(_x_x1971, KK_OWNED, _ctx); /*list<5036>*/
    kk_std_core_types__list _b_x1049_1053;
    kk_box_t _x_x1972 = kk_cctx_apply(acc3_10161,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1049_1053 = kk_std_core_types__list_unbox(_x_x1972, KK_OWNED, _ctx); /*list<5037>*/
    kk_std_core_types__list _b_x1050_1054;
    kk_box_t _x_x1973 = kk_cctx_apply(acc4_10162,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1050_1054 = kk_std_core_types__list_unbox(_x_x1973, KK_OWNED, _ctx); /*list<5038>*/
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x1047_1051, _ctx), kk_std_core_types__list_box(_b_x1048_1052, _ctx), kk_std_core_types__list_box(_b_x1049_1053, _ctx), kk_std_core_types__list_box(_b_x1050_1054, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_unzip4_6010_10025(xs, acc1_10159, acc2_10160, acc3_10161, acc4_10162, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_std_core_list__mlift_unroll_lift_span_6011_10026_10713(kk_std_core_types__cctx acc, kk_function_t predicate, kk_box_t y, kk_std_core_types__list ys, kk_std_core_types__list yy, bool _y_x10614, kk_context_t* _ctx) { /* forall<a,b,e> (acc : cctx<a,list<b>>, predicate : (b) -> e bool, y : b, ys : list<b>, yy : list<b>, bool) -> e (a, list<b>) */ 
  if (_y_x10614) {
    kk_std_core_types__list_drop(ys, _ctx);
    kk_std_core_types__list _cctx_x5097;
    kk_std_core_types__list _x_x1974 = kk_datatype_null(); /*list<5194>*/
    _cctx_x5097 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _x_x1974, _ctx); /*list<5194>*/
    kk_field_addr_t _cctx_x5098 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x5097, _ctx)->tail, _ctx); /*@field-addr<list<5194>>*/;
    kk_std_core_types__cctx acc_0_10119;
    kk_std_core_types__cctx _x_x1975 = kk_cctx_create((kk_std_core_types__list_box(_cctx_x5097, _ctx)),_cctx_x5098,kk_context()); /*cctx<0,1>*/
    acc_0_10119 = kk_cctx_compose(acc,_x_x1975,kk_context()); /*cctx<5169,list<5194>>*/
    return kk_std_core_list__unroll_lift_span_6011_10026(predicate, yy, acc_0_10119, _ctx);
  }
  {
    kk_std_core_types__list_drop(yy, _ctx);
    kk_box_drop(y, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _b_x1075_1077 = kk_cctx_apply(acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*5169*/;
    return kk_std_core_types__new_Tuple2(_b_x1075_1077, kk_std_core_types__list_box(ys, _ctx), _ctx);
  }
}
 
// lifted local: span, span-acc


// lift anonymous function
struct kk_std_core_list__unroll_lift_span_6011_10026_fun1980__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx acc_0;
  kk_function_t predicate_0;
  kk_box_t y_0;
  kk_std_core_types__list ys_0;
  kk_std_core_types__list yy_0;
};
static kk_box_t kk_std_core_list__unroll_lift_span_6011_10026_fun1980(kk_function_t _fself, kk_box_t _b_x1082, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_lift_span_6011_10026_fun1980(kk_std_core_types__cctx acc_0, kk_function_t predicate_0, kk_box_t y_0, kk_std_core_types__list ys_0, kk_std_core_types__list yy_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_6011_10026_fun1980__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_lift_span_6011_10026_fun1980__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_lift_span_6011_10026_fun1980, kk_context());
  _self->acc_0 = acc_0;
  _self->predicate_0 = predicate_0;
  _self->y_0 = y_0;
  _self->ys_0 = ys_0;
  _self->yy_0 = yy_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_lift_span_6011_10026_fun1980(kk_function_t _fself, kk_box_t _b_x1082, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_lift_span_6011_10026_fun1980__t* _self = kk_function_as(struct kk_std_core_list__unroll_lift_span_6011_10026_fun1980__t*, _fself, _ctx);
  kk_std_core_types__cctx acc_0 = _self->acc_0; /* cctx<5169,list<5194>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (5194) -> 5195 bool */
  kk_box_t y_0 = _self->y_0; /* 5194 */
  kk_std_core_types__list ys_0 = _self->ys_0; /* list<5194> */
  kk_std_core_types__list yy_0 = _self->yy_0; /* list<5194> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(y_0, _ctx);kk_std_core_types__list_dup(ys_0, _ctx);kk_std_core_types__list_dup(yy_0, _ctx);}, {}, _ctx)
  bool _y_x10614_0_1110 = kk_bool_unbox(_b_x1082); /*bool*/;
  kk_std_core_types__tuple2 _x_x1981 = kk_std_core_list__mlift_unroll_lift_span_6011_10026_10713(acc_0, predicate_0, y_0, ys_0, yy_0, _y_x10614_0_1110, _ctx); /*(5169, list<5194>)*/
  return kk_std_core_types__tuple2_box(_x_x1981, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_list__unroll_lift_span_6011_10026(kk_function_t predicate_0, kk_std_core_types__list ys_0, kk_std_core_types__cctx acc_0, kk_context_t* _ctx) { /* forall<a,e,b> (predicate : (a) -> e bool, ys : list<a>, acc : cctx<b,list<a>>) -> e (b, list<a>) */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys_0, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1976 = kk_std_core_types__as_Cons(ys_0, _ctx);
    kk_box_t y_0 = _con_x1976->head;
    kk_std_core_types__list yy_0 = _con_x1976->tail;
    kk_box_dup(y_0, _ctx);
    kk_std_core_types__list_dup(yy_0, _ctx);
    bool x_10895;
    kk_function_t _x_x1978 = kk_function_dup(predicate_0, _ctx); /*(5194) -> 5195 bool*/
    kk_box_t _x_x1977 = kk_box_dup(y_0, _ctx); /*5194*/
    x_10895 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1978, (_x_x1978, _x_x1977, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1979 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_lift_span_6011_10026_fun1980(acc_0, predicate_0, y_0, ys_0, yy_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple2_unbox(_x_x1979, KK_OWNED, _ctx);
    }
    if (x_10895) {
      kk_reuse_t _ru_x1447 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(ys_0, _ctx)) {
        kk_std_core_types__list_drop(yy_0, _ctx);
        kk_box_drop(y_0, _ctx);
        _ru_x1447 = (kk_datatype_ptr_reuse(ys_0, _ctx));
      }
      else {
        kk_datatype_ptr_decref(ys_0, _ctx);
      }
      kk_std_core_types__list _cctx_x5097_0;
      kk_std_core_types__list _x_x1982 = kk_datatype_null(); /*list<5194>*/
      _cctx_x5097_0 = kk_std_core_types__new_Cons(_ru_x1447, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _x_x1982, _ctx); /*list<5194>*/
      kk_field_addr_t _cctx_x5098_0 = kk_field_addr_create(&kk_std_core_types__as_Cons(_cctx_x5097_0, _ctx)->tail, _ctx); /*@field-addr<list<5194>>*/;
      kk_std_core_types__cctx acc_0_10119_0;
      kk_std_core_types__cctx _x_x1983 = kk_cctx_create((kk_std_core_types__list_box(_cctx_x5097_0, _ctx)),_cctx_x5098_0,kk_context()); /*cctx<0,1>*/
      acc_0_10119_0 = kk_cctx_compose(acc_0,_x_x1983,kk_context()); /*cctx<5169,list<5194>>*/
      { // tailcall
        ys_0 = yy_0;
        acc_0 = acc_0_10119_0;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(yy_0, _ctx);
      kk_box_drop(y_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _b_x1095_1102 = kk_cctx_apply(acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*5169*/;
      return kk_std_core_types__new_Tuple2(_b_x1095_1102, kk_std_core_types__list_box(ys_0, _ctx), _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _b_x1099_1106 = kk_cctx_apply(acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*5169*/;
    return kk_std_core_types__new_Tuple2(_b_x1099_1106, kk_std_core_types__list_box(ys_0, _ctx), _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_list_span(kk_std_core_types__list xs, kk_function_t predicate, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e (list<a>, list<a>) */ 
  kk_std_core_types__cctx acc = kk_cctx_empty(kk_context()); /*ctx<list<5194>>*/;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(predicate, _ctx);
    kk_std_core_types__list _b_x1121_1123;
    kk_box_t _x_x1984 = kk_cctx_apply(acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x1121_1123 = kk_std_core_types__list_unbox(_x_x1984, KK_OWNED, _ctx); /*list<5194>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1121_1123, _ctx), kk_std_core_types__list_box(xs, _ctx), _ctx);
  }
  {
    return kk_std_core_list__unroll_lift_span_6011_10026(predicate, xs, acc, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_take_while_10027_10714(kk_std_core_types__cctx _acc, kk_function_t predicate, kk_box_t x, kk_std_core_types__list xx, bool _y_x10622, kk_context_t* _ctx) { /* forall<a,e> (ctx<list<a>>, predicate : (a) -> e bool, x : a, xx : list<a>, bool) -> e list<a> */ 
  if (_y_x10622) {
    kk_std_core_types__list _trmc_x10410 = kk_datatype_null(); /*list<5253>*/;
    kk_std_core_types__list _trmc_x10411 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), x, _trmc_x10410, _ctx); /*list<5253>*/;
    kk_field_addr_t _b_x1132_1137 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10411, _ctx)->tail, _ctx); /*@field-addr<list<5253>>*/;
    kk_std_core_types__cctx _x_x1985 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10411, _ctx)),_b_x1132_1137,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_take_while_10027(xx, predicate, _x_x1985, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_box_drop(x, _ctx);
    kk_function_drop(predicate, _ctx);
    kk_box_t _x_x1986 = kk_cctx_apply(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1986, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`


// lift anonymous function
struct kk_std_core_list__trmc_unroll_take_while_10027_fun1991__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t predicate_0;
  kk_box_t x_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_take_while_10027_fun1991(kk_function_t _fself, kk_box_t _b_x1144, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_take_while_10027_fun1991(kk_std_core_types__cctx _acc_0, kk_function_t predicate_0, kk_box_t x_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10027_fun1991__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_take_while_10027_fun1991__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_take_while_10027_fun1991, kk_context());
  _self->_acc_0 = _acc_0;
  _self->predicate_0 = predicate_0;
  _self->x_0 = x_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_take_while_10027_fun1991(kk_function_t _fself, kk_box_t _b_x1144, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_take_while_10027_fun1991__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_take_while_10027_fun1991__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<5253>> */
  kk_function_t predicate_0 = _self->predicate_0; /* (5253) -> 5254 bool */
  kk_box_t x_0 = _self->x_0; /* 5253 */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5253> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(predicate_0, _ctx);kk_box_dup(x_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10622_0_1166 = kk_bool_unbox(_b_x1144); /*bool*/;
  kk_std_core_types__list _x_x1992 = kk_std_core_list__mlift_trmc_unroll_take_while_10027_10714(_acc_0, predicate_0, x_0, xx_0, _y_x10622_0_1166, _ctx); /*list<5253>*/
  return kk_std_core_types__list_box(_x_x1992, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_take_while_10027(kk_std_core_types__list xs, kk_function_t predicate_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool, ctx<list<a>>) -> e list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1987 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x_0 = _con_x1987->head;
    kk_std_core_types__list xx_0 = _con_x1987->tail;
    kk_reuse_t _ru_x1448 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1448 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_1_10898;
    kk_function_t _x_x1989 = kk_function_dup(predicate_0, _ctx); /*(5253) -> 5254 bool*/
    kk_box_t _x_x1988 = kk_box_dup(x_0, _ctx); /*5253*/
    x_1_10898 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x1989, (_x_x1989, _x_x1988, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1448,kk_context());
      kk_box_t _x_x1990 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_take_while_10027_fun1991(_acc_0, predicate_0, x_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x1990, KK_OWNED, _ctx);
    }
    if (x_1_10898) {
      kk_std_core_types__list _trmc_x10410_0 = kk_datatype_null(); /*list<5253>*/;
      kk_std_core_types__list _trmc_x10411_0 = kk_std_core_types__new_Cons(_ru_x1448, kk_field_index_of(struct kk_std_core_types_Cons, tail), x_0, _trmc_x10410_0, _ctx); /*list<5253>*/;
      kk_field_addr_t _b_x1150_1158 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10411_0, _ctx)->tail, _ctx); /*@field-addr<list<5253>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x1993 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10411_0, _ctx)),_b_x1150_1158,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x1993;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1448,kk_context());
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_box_drop(x_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      kk_box_t _x_x1994 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x1994, KK_OWNED, _ctx);
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    kk_box_t _x_x1995 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1995, KK_OWNED, _ctx);
  }
}
 
// Keep only those initial elements that satisfy `predicate`

kk_std_core_types__list kk_std_core_list__unroll_take_while_10027(kk_std_core_types__list xs_0, kk_function_t predicate_1, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e list<a> */ 
  kk_std_core_types__cctx _x_x1996 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_take_while_10027(xs_0, predicate_1, _x_x1996, _ctx);
}
 
// Concatenate all strings in a list in reverse order

kk_string_t kk_std_core_list_reverse_join(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  kk_std_core_types__list xs_0_10123;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    xs_0_10123 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  else {
    xs_0_10123 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), xs, _ctx); /*list<string>*/
  }
  if (kk_std_core_types__is_Nil(xs_0_10123, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x1999 = kk_std_core_types__as_Cons(xs_0_10123, _ctx);
    kk_box_t _box_x1167 = _con_x1999->head;
    kk_std_core_types__list _pat_1 = _con_x1999->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1167);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10123, _ctx)) {
        kk_datatype_ptr_free(xs_0_10123, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_0_10123, _ctx);
      }
      return x;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2000 = kk_std_core_types__as_Cons(xs_0_10123, _ctx);
    kk_box_t _box_x1168 = _con_x2000->head;
    kk_std_core_types__list _pat_3 = _con_x2000->tail;
    struct kk_std_core_types_Cons* _con_x2001 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x1169 = _con_x2001->head;
    kk_std_core_types__list _pat_4 = _con_x2001->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x1168);
      kk_string_t y = kk_string_unbox(_box_x1169);
      if kk_likely(kk_datatype_ptr_is_unique(xs_0_10123, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_0_10123, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_0_10123, _ctx);
      }
      return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
    }
  }
  {
    kk_vector_t _x_x2002 = kk_std_core_vector_unvlist(xs_0_10123, _ctx); /*vector<978>*/
    return kk_string_join(_x_x2002,kk_context());
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__trmc_lift_concat_6012(kk_std_core_types__list ys, kk_std_core_types__list zss, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2006 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x2006->head;
    kk_std_core_types__list yy = _con_x2006->tail;
    kk_reuse_t _ru_x1452 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1452 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10412 = kk_datatype_null(); /*list<5363>*/;
    kk_std_core_types__list _trmc_x10413 = kk_std_core_types__new_Cons(_ru_x1452, 0, y, _trmc_x10412, _ctx); /*list<5363>*/;
    kk_field_addr_t _b_x1175_1181 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10413, _ctx)->tail, _ctx); /*@field-addr<list<5363>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x2007 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10413, _ctx)),_b_x1175_1181,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc = _x_x2007;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zss, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2008 = kk_std_core_types__as_Cons(zss, _ctx);
    kk_box_t _box_x1176 = _con_x2008->head;
    kk_std_core_types__list zzs = _con_x2008->tail;
    kk_std_core_types__list zs = kk_std_core_types__list_unbox(_box_x1176, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(zss, _ctx)) {
      kk_datatype_ptr_free(zss, _ctx);
    }
    else {
      kk_std_core_types__list_dup(zs, _ctx);
      kk_std_core_types__list_dup(zzs, _ctx);
      kk_datatype_ptr_decref(zss, _ctx);
    }
    { // tailcall
      ys = zs;
      zss = zzs;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x2009 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2009, KK_OWNED, _ctx);
  }
}
 
// lifted local: concat, concat-pre

kk_std_core_types__list kk_std_core_list__lift_concat_6012(kk_std_core_types__list ys_0, kk_std_core_types__list zss_0, kk_context_t* _ctx) { /* forall<a> (ys : list<a>, zss : list<list<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x2010 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_concat_6012(ys_0, zss_0, _x_x2010, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_lift_flatmap_6013_10715(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list zz, kk_std_core_types__list ys_1_10132, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e list<b>, zz : list<a>, ys@1@10132 : list<b>) -> e list<b> */ 
  return kk_std_core_list__trmc_lift_flatmap_6013(f, ys_1_10132, zz, _acc, _ctx);
}
 
// lifted local: flatmap, flatmap-pre


// lift anonymous function
struct kk_std_core_list__trmc_lift_flatmap_6013_fun2017__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list zz_0;
};
static kk_box_t kk_std_core_list__trmc_lift_flatmap_6013_fun2017(kk_function_t _fself, kk_box_t _b_x1194, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_lift_flatmap_6013_fun2017(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list zz_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_6013_fun2017__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_lift_flatmap_6013_fun2017__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_lift_flatmap_6013_fun2017, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->zz_0 = zz_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_lift_flatmap_6013_fun2017(kk_function_t _fself, kk_box_t _b_x1194, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_lift_flatmap_6013_fun2017__t* _self = kk_function_as(struct kk_std_core_list__trmc_lift_flatmap_6013_fun2017__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<5455>> */
  kk_function_t f_0 = _self->f_0; /* (5454) -> 5456 list<5455> */
  kk_std_core_types__list zz_0 = _self->zz_0; /* list<5454> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(zz_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list ys_1_10132_0_1206 = kk_std_core_types__list_unbox(_b_x1194, KK_OWNED, _ctx); /*list<5455>*/;
  kk_std_core_types__list _x_x2018 = kk_std_core_list__mlift_trmc_lift_flatmap_6013_10715(_acc_0, f_0, zz_0, ys_1_10132_0_1206, _ctx); /*list<5455>*/
  return kk_std_core_types__list_box(_x_x2018, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_lift_flatmap_6013(kk_function_t f_0, kk_std_core_types__list ys, kk_std_core_types__list zs, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ys, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2012 = kk_std_core_types__as_Cons(ys, _ctx);
    kk_box_t y = _con_x2012->head;
    kk_std_core_types__list yy = _con_x2012->tail;
    kk_reuse_t _ru_x1454 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ys, _ctx)) {
      _ru_x1454 = (kk_datatype_ptr_reuse(ys, _ctx));
    }
    else {
      kk_box_dup(y, _ctx);
      kk_std_core_types__list_dup(yy, _ctx);
      kk_datatype_ptr_decref(ys, _ctx);
    }
    kk_std_core_types__list _trmc_x10414 = kk_datatype_null(); /*list<5455>*/;
    kk_std_core_types__list _trmc_x10415 = kk_std_core_types__new_Cons(_ru_x1454, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10414, _ctx); /*list<5455>*/;
    kk_field_addr_t _b_x1192_1199 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10415, _ctx)->tail, _ctx); /*@field-addr<list<5455>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x2013 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10415, _ctx)),_b_x1192_1199,kk_context()); /*ctx<0>*/
      ys = yy;
      _acc_0 = _x_x2013;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(zs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2014 = kk_std_core_types__as_Cons(zs, _ctx);
    kk_box_t z = _con_x2014->head;
    kk_std_core_types__list zz_0 = _con_x2014->tail;
    if kk_likely(kk_datatype_ptr_is_unique(zs, _ctx)) {
      kk_datatype_ptr_free(zs, _ctx);
    }
    else {
      kk_box_dup(z, _ctx);
      kk_std_core_types__list_dup(zz_0, _ctx);
      kk_datatype_ptr_decref(zs, _ctx);
    }
    kk_std_core_types__list x_10905;
    kk_function_t _x_x2015 = kk_function_dup(f_0, _ctx); /*(5454) -> 5456 list<5455>*/
    x_10905 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _x_x2015, (_x_x2015, z, _ctx), _ctx); /*list<5455>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_10905, _ctx);
      kk_box_t _x_x2016 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_lift_flatmap_6013_fun2017(_acc_0, f_0, zz_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2016, KK_OWNED, _ctx);
    }
    { // tailcall
      ys = x_10905;
      zs = zz_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x2019 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2019, KK_OWNED, _ctx);
  }
}
 
// lifted local: flatmap, flatmap-pre

kk_std_core_types__list kk_std_core_list__lift_flatmap_6013(kk_function_t f_1, kk_std_core_types__list ys_0, kk_std_core_types__list zs_0, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e list<b>, ys : list<b>, zs : list<a>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x2020 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_lift_flatmap_6013(f_1, ys_0, zs_0, _x_x2020, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10028_10716(kk_std_core_types__cctx _acc, kk_function_t f, kk_std_core_types__list xx, kk_std_core_types__maybe _y_x10636, kk_context_t* _ctx) { /* forall<a,b,e> (ctx<list<b>>, f : (a) -> e maybe<b>, xx : list<a>, maybe<b>) -> e list<b> */ 
  if (kk_std_core_types__is_Just(_y_x10636, _ctx)) {
    kk_box_t y = _y_x10636._cons.Just.value;
    kk_std_core_types__list _trmc_x10416 = kk_datatype_null(); /*list<5542>*/;
    kk_std_core_types__list _trmc_x10417 = kk_std_core_types__new_Cons(kk_reuse_null, kk_field_index_of(struct kk_std_core_types_Cons, tail), y, _trmc_x10416, _ctx); /*list<5542>*/;
    kk_field_addr_t _b_x1212_1215 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10417, _ctx)->tail, _ctx); /*@field-addr<list<5542>>*/;
    kk_std_core_types__cctx _x_x2022 = kk_cctx_extend(_acc,(kk_std_core_types__list_box(_trmc_x10417, _ctx)),_b_x1212_1215,kk_context()); /*ctx<0>*/
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10028(xx, f, _x_x2022, _ctx);
  }
  {
    return kk_std_core_list__trmc_unroll_flatmap_maybe_10028(xx, f, _acc, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.


// lift anonymous function
struct kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_function_t f_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026(kk_function_t _fself, kk_box_t _b_x1220, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_trmc_unroll_flatmap_maybe_10028_fun2026(kk_std_core_types__cctx _acc_0, kk_function_t f_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026__t* _self = kk_function_alloc_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026, kk_context());
  _self->_acc_0 = _acc_0;
  _self->f_0 = f_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026(kk_function_t _fself, kk_box_t _b_x1220, kk_context_t* _ctx) {
  struct kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026__t* _self = kk_function_as(struct kk_std_core_list__trmc_unroll_flatmap_maybe_10028_fun2026__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<5542>> */
  kk_function_t f_0 = _self->f_0; /* (5541) -> 5543 maybe<5542> */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5541> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10636_0_1238 = kk_std_core_types__maybe_unbox(_b_x1220, KK_OWNED, _ctx); /*maybe<5542>*/;
  kk_std_core_types__list _x_x2027 = kk_std_core_list__mlift_trmc_unroll_flatmap_maybe_10028_10716(_acc_0, f_0, xx_0, _y_x10636_0_1238, _ctx); /*list<5542>*/
  return kk_std_core_types__list_box(_x_x2027, _ctx);
}

kk_std_core_types__list kk_std_core_list__trmc_unroll_flatmap_maybe_10028(kk_std_core_types__list xs, kk_function_t f_0, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>, ctx<list<b>>) -> e list<b> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2023 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x2023->head;
    kk_std_core_types__list xx_0 = _con_x2023->tail;
    kk_reuse_t _ru_x1456 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x1456 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe x_0_10911;
    kk_function_t _x_x2024 = kk_function_dup(f_0, _ctx); /*(5541) -> 5543 maybe<5542>*/
    x_0_10911 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_box_t, kk_context_t*), _x_x2024, (_x_x2024, x, _ctx), _ctx); /*maybe<5542>*/
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x1456,kk_context());
      kk_std_core_types__maybe_drop(x_0_10911, _ctx);
      kk_box_t _x_x2025 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_trmc_unroll_flatmap_maybe_10028_fun2026(_acc_0, f_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2025, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Just(x_0_10911, _ctx)) {
      kk_box_t y_0 = x_0_10911._cons.Just.value;
      kk_std_core_types__list _trmc_x10416_0 = kk_datatype_null(); /*list<5542>*/;
      kk_std_core_types__list _trmc_x10417_0 = kk_std_core_types__new_Cons(_ru_x1456, kk_field_index_of(struct kk_std_core_types_Cons, tail), y_0, _trmc_x10416_0, _ctx); /*list<5542>*/;
      kk_field_addr_t _b_x1226_1232 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10417_0, _ctx)->tail, _ctx); /*@field-addr<list<5542>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2028 = kk_cctx_extend(_acc_0,(kk_std_core_types__list_box(_trmc_x10417_0, _ctx)),_b_x1226_1232,kk_context()); /*ctx<0>*/
        xs = xx_0;
        _acc_0 = _x_x2028;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1456,kk_context());
      { // tailcall
        xs = xx_0;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x2029 = kk_cctx_apply(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2029, KK_OWNED, _ctx);
  }
}
 
// Concatenate the `Just` result elements from applying a function to all elements.

kk_std_core_types__list kk_std_core_list__unroll_flatmap_maybe_10028(kk_std_core_types__list xs_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (xs : list<a>, f : (a) -> e maybe<b>) -> e list<b> */ 
  kk_std_core_types__cctx _x_x2030 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_flatmap_maybe_10028(xs_0, f_1, _x_x2030, _ctx);
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__trmc_unroll_concat_maybe_10029(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2032 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1239 = _con_x2032->head;
    kk_std_core_types__list xx = _con_x2032->tail;
    kk_std_core_types__maybe x = kk_std_core_types__maybe_unbox(_box_x1239, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1457 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_box_drop(_box_x1239, _ctx);
      _ru_x1457 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_std_core_types__maybe_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    if (kk_std_core_types__is_Just(x, _ctx)) {
      kk_box_t y = x._cons.Just.value;
      kk_std_core_types__list _trmc_x10418 = kk_datatype_null(); /*list<5607>*/;
      kk_std_core_types__list _trmc_x10419 = kk_std_core_types__new_Cons(_ru_x1457, 0, y, _trmc_x10418, _ctx); /*list<5607>*/;
      kk_field_addr_t _b_x1245_1250 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10419, _ctx)->tail, _ctx); /*@field-addr<list<5607>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2033 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10419, _ctx)),_b_x1245_1250,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x2033;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x1457,kk_context());
      { // tailcall
        xs = xx;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_box_t _x_x2034 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2034, KK_OWNED, _ctx);
  }
}
 
// Concatenate a list of `:maybe` values

kk_std_core_types__list kk_std_core_list__unroll_concat_maybe_10029(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<maybe<a>>) -> list<a> */ 
  kk_std_core_types__cctx _x_x2035 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_unroll_concat_maybe_10029(xs_0, _x_x2035, _ctx);
}
 
// Return the last element of a list (or `Nothing` for the empty list)

kk_std_core_types__maybe kk_std_core_list_last(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2037 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list _pat_0 = _con_x2037->tail;
    if (kk_std_core_types__is_Nil(_pat_0, _ctx)) {
      kk_box_t x = _con_x2037->head;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_box_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2038 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_2 = _con_x2038->head;
    kk_std_core_types__list xx = _con_x2038->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_2, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      xs = xx;
      goto kk__tailcall;
    }
  }
  {
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list__trmc_init(kk_std_core_types__list xs, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2039 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_std_core_types__list xx = _con_x2039->tail;
    if (kk_std_core_types__is_Cons(xx, _ctx)) {
      struct kk_std_core_types_Cons* _con_x2040 = kk_std_core_types__as_Cons(xx, _ctx);
      kk_box_t x = _con_x2039->head;
      kk_reuse_t _ru_x1460 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        _ru_x1460 = (kk_datatype_ptr_reuse(xs, _ctx));
      }
      else {
        kk_box_dup(x, _ctx);
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      kk_std_core_types__list _trmc_x10420 = kk_datatype_null(); /*list<5698>*/;
      kk_std_core_types__list _trmc_x10421 = kk_std_core_types__new_Cons(_ru_x1460, 0, x, _trmc_x10420, _ctx); /*list<5698>*/;
      kk_field_addr_t _b_x1261_1266 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10421, _ctx)->tail, _ctx); /*@field-addr<list<5698>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x2041 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10421, _ctx)),_b_x1261_1266,kk_context()); /*ctx<0>*/
        xs = xx;
        _acc = _x_x2041;
        goto kk__tailcall;
      }
    }
  }
  {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_box_t _x_x2042 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x2042, KK_OWNED, _ctx);
  }
}
 
// Return the list without its last element.
// Return an empty list for an empty list.

kk_std_core_types__list kk_std_core_list_init(kk_std_core_types__list xs_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x2043 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_core_list__trmc_init(xs_0, _x_x2043, _ctx);
}
 
// Get (zero-based) element `n`  of a list. Return a `:maybe` type.

kk_std_core_types__maybe kk_std_core_list__unroll_index_10030(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2044 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x2044->head;
    kk_std_core_types__list xx = _con_x2044->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool _match_x1292 = kk_integer_gt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x1292) {
      kk_box_drop(x, _ctx);
      { // tailcall
        kk_integer_t _x_x2045 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
        xs = xx;
        n = _x_x2045;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xx, _ctx);
      bool _match_x1293;
      bool _brw_x1294 = kk_integer_eq_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
      kk_integer_drop(n, _ctx);
      _match_x1293 = _brw_x1294; /*bool*/
      if (_match_x1293) {
        return kk_std_core_types__new_Just(x, _ctx);
      }
      {
        kk_box_drop(x, _ctx);
        return kk_std_core_types__new_Nothing(_ctx);
      }
    }
  }
  {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_all_10031_10717(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10644, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10644) {
    return kk_std_core_list__unroll_all_10031(xx, predicate, _ctx);
  }
  {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return false;
  }
}
 
// Do all elements satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_all_10031_fun2049__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_all_10031_fun2049(kk_function_t _fself, kk_box_t _b_x1273, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_all_10031_fun2049(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10031_fun2049__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_all_10031_fun2049__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_all_10031_fun2049, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_all_10031_fun2049(kk_function_t _fself, kk_box_t _b_x1273, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_all_10031_fun2049__t* _self = kk_function_as(struct kk_std_core_list__unroll_all_10031_fun2049__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (5835) -> 5836 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5835> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10644_0_1275 = kk_bool_unbox(_b_x1273); /*bool*/;
  bool _x_x2050 = kk_std_core_list__mlift_unroll_all_10031_10717(predicate_0, xx_0, _y_x10644_0_1275, _ctx); /*bool*/
  return kk_bool_box(_x_x2050);
}

bool kk_std_core_list__unroll_all_10031(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2046 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x2046->head;
    kk_std_core_types__list xx_0 = _con_x2046->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10917;
    kk_function_t _x_x2047 = kk_function_dup(predicate_0, _ctx); /*(5835) -> 5836 bool*/
    x_0_10917 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x2047, (_x_x2047, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2048 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_all_10031_fun2049(predicate_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x2048);
    }
    if (x_0_10917) { // tailcall
                     xs = xx_0;
                     goto kk__tailcall;
    }
    {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return true;
  }
}
 
// monadic lift

bool kk_std_core_list__mlift_unroll_any_10032_10718(kk_function_t predicate, kk_std_core_types__list xx, bool _y_x10650, kk_context_t* _ctx) { /* forall<a,e> (predicate : (a) -> e bool, xx : list<a>, bool) -> e bool */ 
  if (_y_x10650) {
    kk_std_core_types__list_drop(xx, _ctx);
    kk_function_drop(predicate, _ctx);
    return true;
  }
  {
    return kk_std_core_list__unroll_any_10032(xx, predicate, _ctx);
  }
}
 
// Are there any elements in a list that satisfy a predicate ?


// lift anonymous function
struct kk_std_core_list__unroll_any_10032_fun2054__t {
  struct kk_function_s _base;
  kk_function_t predicate_0;
  kk_std_core_types__list xx_0;
};
static kk_box_t kk_std_core_list__unroll_any_10032_fun2054(kk_function_t _fself, kk_box_t _b_x1277, kk_context_t* _ctx);
static kk_function_t kk_std_core_list__new_unroll_any_10032_fun2054(kk_function_t predicate_0, kk_std_core_types__list xx_0, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10032_fun2054__t* _self = kk_function_alloc_as(struct kk_std_core_list__unroll_any_10032_fun2054__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_list__unroll_any_10032_fun2054, kk_context());
  _self->predicate_0 = predicate_0;
  _self->xx_0 = xx_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_list__unroll_any_10032_fun2054(kk_function_t _fself, kk_box_t _b_x1277, kk_context_t* _ctx) {
  struct kk_std_core_list__unroll_any_10032_fun2054__t* _self = kk_function_as(struct kk_std_core_list__unroll_any_10032_fun2054__t*, _fself, _ctx);
  kk_function_t predicate_0 = _self->predicate_0; /* (5882) -> 5883 bool */
  kk_std_core_types__list xx_0 = _self->xx_0; /* list<5882> */
  kk_drop_match(_self, {kk_function_dup(predicate_0, _ctx);kk_std_core_types__list_dup(xx_0, _ctx);}, {}, _ctx)
  bool _y_x10650_0_1279 = kk_bool_unbox(_b_x1277); /*bool*/;
  bool _x_x2055 = kk_std_core_list__mlift_unroll_any_10032_10718(predicate_0, xx_0, _y_x10650_0_1279, _ctx); /*bool*/
  return kk_bool_box(_x_x2055);
}

bool kk_std_core_list__unroll_any_10032(kk_std_core_types__list xs, kk_function_t predicate_0, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>, predicate : (a) -> e bool) -> e bool */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2051 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x2051->head;
    kk_std_core_types__list xx_0 = _con_x2051->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xx_0, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool x_0_10920;
    kk_function_t _x_x2052 = kk_function_dup(predicate_0, _ctx); /*(5882) -> 5883 bool*/
    x_0_10920 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x2052, (_x_x2052, x, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2053 = kk_std_core_hnd_yield_extend(kk_std_core_list__new_unroll_any_10032_fun2054(predicate_0, xx_0, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x2053);
    }
    if (x_0_10920) {
      kk_std_core_types__list_drop(xx_0, _ctx);
      kk_function_drop(predicate_0, _ctx);
      return true;
    }
    { // tailcall
      xs = xx_0;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(predicate_0, _ctx);
    return false;
  }
}
 
// lifted local: sum, @spec-x10328
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10323, using:
// @uniq-f@10323 = std/core/int/(+)

kk_integer_t kk_std_core_list__lift_sum_10351(kk_std_core_types__list _uniq_xs_10321, kk_integer_t _uniq_z_10322, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10321, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2056 = kk_std_core_types__as_Cons(_uniq_xs_10321, _ctx);
    kk_box_t _box_x1280 = _con_x2056->head;
    kk_std_core_types__list _uniq_xx_10326 = _con_x2056->tail;
    kk_integer_t _uniq_x_10325 = kk_integer_unbox(_box_x1280, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10321, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10321, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10325, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10326, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10321, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2057 = kk_std_core_int__lp__plus__rp_(_uniq_z_10322, _uniq_x_10325, _ctx); /*int*/
      _uniq_xs_10321 = _uniq_xx_10326;
      _uniq_z_10322 = _x_x2057;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10322;
  }
}
 
// lifted local: minimum, @spec-x10336
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10331, using:
// @uniq-f@10331 = std/core/int/min

kk_integer_t kk_std_core_list__lift_minimum_10352(kk_std_core_types__list _uniq_xs_10329, kk_integer_t _uniq_z_10330, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10329, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2058 = kk_std_core_types__as_Cons(_uniq_xs_10329, _ctx);
    kk_box_t _box_x1281 = _con_x2058->head;
    kk_std_core_types__list _uniq_xx_10334 = _con_x2058->tail;
    kk_integer_t _uniq_x_10333 = kk_integer_unbox(_box_x1281, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10329, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10329, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10333, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10334, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10329, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2059 = kk_std_core_int_min(_uniq_z_10330, _uniq_x_10333, _ctx); /*int*/
      _uniq_xs_10329 = _uniq_xx_10334;
      _uniq_z_10330 = _x_x2059;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10330;
  }
}
 
// Returns the smallest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_minimum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1282 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_5916 = kk_integer_unbox(_box_x1282, _ctx);
      kk_integer_dup(_uniq_default_5916, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_5916;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2060 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1283 = _con_x2060->head;
    kk_std_core_types__list xx = _con_x2060->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1283, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_minimum_10352(xx, x, _ctx);
    }
  }
}
 
// lifted local: maximum, @spec-x10344
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10339, using:
// @uniq-f@10339 = std/core/int/max

kk_integer_t kk_std_core_list__lift_maximum_10353(kk_std_core_types__list _uniq_xs_10337, kk_integer_t _uniq_z_10338, kk_context_t* _ctx) { /* (list<int>, int) -> int */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10337, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2061 = kk_std_core_types__as_Cons(_uniq_xs_10337, _ctx);
    kk_box_t _box_x1284 = _con_x2061->head;
    kk_std_core_types__list _uniq_xx_10342 = _con_x2061->tail;
    kk_integer_t _uniq_x_10341 = kk_integer_unbox(_box_x1284, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10337, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10337, _ctx);
    }
    else {
      kk_integer_dup(_uniq_x_10341, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10342, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10337, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2062 = kk_std_core_int_max(_uniq_z_10338, _uniq_x_10341, _ctx); /*int*/
      _uniq_xs_10337 = _uniq_xx_10342;
      _uniq_z_10338 = _x_x2062;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10338;
  }
}
 
// Returns the largest element of a list of integers (or `default` (=`0`) for the empty list)

kk_integer_t kk_std_core_list_maximum(kk_std_core_types__list xs, kk_std_core_types__optional kkloc_default, kk_context_t* _ctx) { /* (xs : list<int>, default : ? int) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    if (kk_std_core_types__is_Optional(kkloc_default, _ctx)) {
      kk_box_t _box_x1285 = kkloc_default._cons._Optional.value;
      kk_integer_t _uniq_default_5950 = kk_integer_unbox(_box_x1285, _ctx);
      kk_integer_dup(_uniq_default_5950, _ctx);
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return _uniq_default_5950;
    }
    {
      kk_std_core_types__optional_drop(kkloc_default, _ctx);
      return kk_integer_from_small(0);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2063 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1286 = _con_x2063->head;
    kk_std_core_types__list xx = _con_x2063->tail;
    kk_integer_t x = kk_integer_unbox(_box_x1286, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_integer_dup(x, _ctx);
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__optional_drop(kkloc_default, _ctx);
    if (kk_std_core_types__is_Nil(xx, _ctx)) {
      return x;
    }
    {
      return kk_std_core_list__lift_maximum_10353(xx, x, _ctx);
    }
  }
}
 
// Join a list of strings with newlines

kk_string_t kk_std_core_list_unlines(kk_std_core_types__list xs, kk_context_t* _ctx) { /* (xs : list<string>) -> string */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_string_empty();
  }
  {
    struct kk_std_core_types_Cons* _con_x2067 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1287 = _con_x2067->head;
    kk_std_core_types__list _pat_1 = _con_x2067->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x1287);
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs, _ctx);
      }
      return x;
    }
  }
  if (kk_std_core_types__is_Cons(xs, _ctx)) {
    struct kk_std_core_types_Cons* _con_x2068 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _box_x1288 = _con_x2068->head;
    kk_std_core_types__list _pat_3 = _con_x2068->tail;
    if (kk_std_core_types__is_Cons(_pat_3, _ctx)) {
      struct kk_std_core_types_Cons* _con_x2069 = kk_std_core_types__as_Cons(_pat_3, _ctx);
      kk_box_t _box_x1289 = _con_x2069->head;
      kk_std_core_types__list _pat_4 = _con_x2069->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x2070;
        kk_define_string_literal(static, _s_x2071, 1, "\n", _ctx)
        _x_x2070 = kk_string_dup(_s_x2071, _ctx); /*string*/
        kk_string_t _x_x2072 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x2070,_x_x2072,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x1288);
          kk_string_t y = kk_string_unbox(_box_x1289);
          if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
              kk_datatype_ptr_free(_pat_3, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3, _ctx);
            }
            kk_datatype_ptr_free(xs, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs, _ctx);
          }
          return kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx);
        }
      }
    }
  }
  {
    kk_vector_t _x_x2074 = kk_std_core_vector_unvlist(xs, _ctx); /*vector<978>*/
    kk_string_t _x_x2075;
    kk_define_string_literal(static, _s_x2076, 1, "\n", _ctx)
    _x_x2075 = kk_string_dup(_s_x2076, _ctx); /*string*/
    return kk_string_join_with(_x_x2074,_x_x2075,kk_context());
  }
}

// initialization
void kk_std_core_list__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_list__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
