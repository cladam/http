// Koka generated module: std/core/order, koka version: 3.2.3, platform: 64-bit
#include "std_core_order.h"

bool kk_std_core_order__lp__eq__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x26;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x26 = kk_integer_from_small(-1); /*int*/
    goto _match_x28;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x26 = kk_integer_from_small(0); /*int*/
    goto _match_x28;
  }
  {
    _brw_x26 = kk_integer_from_small(1); /*int*/
  }
  _match_x28: ;
  kk_integer_t _brw_x25;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x25 = kk_integer_from_small(-1); /*int*/
    goto _match_x29;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x25 = kk_integer_from_small(0); /*int*/
    goto _match_x29;
  }
  {
    _brw_x25 = kk_integer_from_small(1); /*int*/
  }
  _match_x29: ;
  bool _brw_x27 = kk_integer_eq_borrow(_brw_x26,_brw_x25,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x26, _ctx);
  kk_integer_drop(_brw_x25, _ctx);
  return _brw_x27;
}

bool kk_std_core_order__lp__excl__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x23;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x23 = kk_integer_from_small(-1); /*int*/
    goto _match_x30;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x23 = kk_integer_from_small(0); /*int*/
    goto _match_x30;
  }
  {
    _brw_x23 = kk_integer_from_small(1); /*int*/
  }
  _match_x30: ;
  kk_integer_t _brw_x22;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x22 = kk_integer_from_small(-1); /*int*/
    goto _match_x31;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x22 = kk_integer_from_small(0); /*int*/
    goto _match_x31;
  }
  {
    _brw_x22 = kk_integer_from_small(1); /*int*/
  }
  _match_x31: ;
  bool _brw_x24 = kk_integer_neq_borrow(_brw_x23,_brw_x22,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x23, _ctx);
  kk_integer_drop(_brw_x22, _ctx);
  return _brw_x24;
}

bool kk_std_core_order__lp__gt__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x20;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x20 = kk_integer_from_small(-1); /*int*/
    goto _match_x32;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x20 = kk_integer_from_small(0); /*int*/
    goto _match_x32;
  }
  {
    _brw_x20 = kk_integer_from_small(1); /*int*/
  }
  _match_x32: ;
  kk_integer_t _brw_x19;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x19 = kk_integer_from_small(-1); /*int*/
    goto _match_x33;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x19 = kk_integer_from_small(0); /*int*/
    goto _match_x33;
  }
  {
    _brw_x19 = kk_integer_from_small(1); /*int*/
  }
  _match_x33: ;
  bool _brw_x21 = kk_integer_gte_borrow(_brw_x20,_brw_x19,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x20, _ctx);
  kk_integer_drop(_brw_x19, _ctx);
  return _brw_x21;
}

bool kk_std_core_order__lp__lt__eq__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x17;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x17 = kk_integer_from_small(-1); /*int*/
    goto _match_x34;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x17 = kk_integer_from_small(0); /*int*/
    goto _match_x34;
  }
  {
    _brw_x17 = kk_integer_from_small(1); /*int*/
  }
  _match_x34: ;
  kk_integer_t _brw_x16;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x16 = kk_integer_from_small(-1); /*int*/
    goto _match_x35;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x16 = kk_integer_from_small(0); /*int*/
    goto _match_x35;
  }
  {
    _brw_x16 = kk_integer_from_small(1); /*int*/
  }
  _match_x35: ;
  bool _brw_x18 = kk_integer_lte_borrow(_brw_x17,_brw_x16,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x17, _ctx);
  kk_integer_drop(_brw_x16, _ctx);
  return _brw_x18;
}

bool kk_std_core_order__lp__gt__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x14;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x14 = kk_integer_from_small(-1); /*int*/
    goto _match_x36;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x14 = kk_integer_from_small(0); /*int*/
    goto _match_x36;
  }
  {
    _brw_x14 = kk_integer_from_small(1); /*int*/
  }
  _match_x36: ;
  kk_integer_t _brw_x13;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x13 = kk_integer_from_small(-1); /*int*/
    goto _match_x37;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x13 = kk_integer_from_small(0); /*int*/
    goto _match_x37;
  }
  {
    _brw_x13 = kk_integer_from_small(1); /*int*/
  }
  _match_x37: ;
  bool _brw_x15 = kk_integer_gt_borrow(_brw_x14,_brw_x13,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x14, _ctx);
  kk_integer_drop(_brw_x13, _ctx);
  return _brw_x15;
}

bool kk_std_core_order__lp__lt__rp_(kk_std_core_types__order x, kk_std_core_types__order y, kk_context_t* _ctx) { /* (x : order, y : order) -> bool */ 
  kk_integer_t _brw_x11;
  if (kk_std_core_types__is_Lt(x, _ctx)) {
    _brw_x11 = kk_integer_from_small(-1); /*int*/
    goto _match_x38;
  }
  if (kk_std_core_types__is_Eq(x, _ctx)) {
    _brw_x11 = kk_integer_from_small(0); /*int*/
    goto _match_x38;
  }
  {
    _brw_x11 = kk_integer_from_small(1); /*int*/
  }
  _match_x38: ;
  kk_integer_t _brw_x10;
  if (kk_std_core_types__is_Lt(y, _ctx)) {
    _brw_x10 = kk_integer_from_small(-1); /*int*/
    goto _match_x39;
  }
  if (kk_std_core_types__is_Eq(y, _ctx)) {
    _brw_x10 = kk_integer_from_small(0); /*int*/
    goto _match_x39;
  }
  {
    _brw_x10 = kk_integer_from_small(1); /*int*/
  }
  _match_x39: ;
  bool _brw_x12 = kk_integer_lt_borrow(_brw_x11,_brw_x10,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x11, _ctx);
  kk_integer_drop(_brw_x10, _ctx);
  return _brw_x12;
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_order_default_fs__mlift_order2_10113(kk_box_t x, kk_box_t y, kk_std_core_types__order _y_x10112, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, order) -> e order2<a> */ 
  if (kk_std_core_types__is_Eq(_y_x10112, _ctx)) {
    kk_box_drop(y, _ctx);
    return kk_std_core_types__new_Eq2(x, _ctx);
  }
  if (kk_std_core_types__is_Lt(_y_x10112, _ctx)) {
    return kk_std_core_types__new_Lt2(x, y, _ctx);
  }
  {
    return kk_std_core_types__new_Gt2(y, x, _ctx);
  }
}
 
// Given a comparison function, we can order 2 elements.


// lift anonymous function
struct kk_std_core_order_default_fs_order2_fun45__t {
  struct kk_function_s _base;
  kk_box_t x;
  kk_box_t y;
};
static kk_box_t kk_std_core_order_default_fs_order2_fun45(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx);
static kk_function_t kk_std_core_order_default_fs_new_order2_fun45(kk_box_t x, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_order_default_fs_order2_fun45__t* _self = kk_function_alloc_as(struct kk_std_core_order_default_fs_order2_fun45__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_order_default_fs_order2_fun45, kk_context());
  _self->x = x;
  _self->y = y;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_order_default_fs_order2_fun45(kk_function_t _fself, kk_box_t _b_x3, kk_context_t* _ctx) {
  struct kk_std_core_order_default_fs_order2_fun45__t* _self = kk_function_as(struct kk_std_core_order_default_fs_order2_fun45__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 258 */
  kk_box_t y = _self->y; /* 258 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);kk_box_dup(y, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10112_8 = kk_std_core_types__order_unbox(_b_x3, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order2 _x_x46 = kk_std_core_order_default_fs__mlift_order2_10113(x, y, _y_x10112_8, _ctx); /*order2<258>*/
  return kk_std_core_types__order2_box(_x_x46, _ctx);
}


// lift anonymous function
struct kk_std_core_order_default_fs_order2_fun47__t {
  struct kk_function_s _base;
  kk_box_t x;
  kk_box_t y;
};
static kk_box_t kk_std_core_order_default_fs_order2_fun47(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx);
static kk_function_t kk_std_core_order_default_fs_new_order2_fun47(kk_box_t x, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_order_default_fs_order2_fun47__t* _self = kk_function_alloc_as(struct kk_std_core_order_default_fs_order2_fun47__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_order_default_fs_order2_fun47, kk_context());
  _self->x = x;
  _self->y = y;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_order_default_fs_order2_fun47(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx) {
  struct kk_std_core_order_default_fs_order2_fun47__t* _self = kk_function_as(struct kk_std_core_order_default_fs_order2_fun47__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 258 */
  kk_box_t y = _self->y; /* 258 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);kk_box_dup(y, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10112_0_9 = kk_std_core_types__order_unbox(_b_x4, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order2 _x_x48;
  if (kk_std_core_types__is_Eq(_y_x10112_0_9, _ctx)) {
    kk_box_drop(y, _ctx);
    _x_x48 = kk_std_core_types__new_Eq2(x, _ctx); /*order2<105>*/
    goto _match_x49;
  }
  if (kk_std_core_types__is_Lt(_y_x10112_0_9, _ctx)) {
    _x_x48 = kk_std_core_types__new_Lt2(x, y, _ctx); /*order2<105>*/
    goto _match_x49;
  }
  {
    _x_x48 = kk_std_core_types__new_Gt2(y, x, _ctx); /*order2<105>*/
  }
  _match_x49: ;
  return kk_std_core_types__order2_box(_x_x48, _ctx);
}

kk_std_core_types__order2 kk_std_core_order_default_fs_order2(kk_box_t x, kk_box_t y, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (x : a, y : a, ?cmp : (a, a) -> e order) -> e order2<a> */ 
  kk_std_core_types__order _b_x0_5;
  kk_function_t _x_x42 = kk_function_dup(_implicit_fs_cmp, _ctx); /*(258, 258) -> 259 order*/
  kk_box_t _x_x40 = kk_box_dup(x, _ctx); /*258*/
  kk_box_t _x_x41 = kk_box_dup(y, _ctx); /*258*/
  _b_x0_5 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x42, (_x_x42, _x_x40, _x_x41, _ctx), _ctx); /*order*/
  kk_box_t _x_x43;
  kk_function_t _x_x44;
  kk_box_dup(x, _ctx);
  kk_box_dup(y, _ctx);
  _x_x44 = kk_std_core_order_default_fs_new_order2_fun45(x, y, _ctx); /*(0) -> 2 1*/
  _x_x43 = kk_std_core_hnd_yield_bind2(kk_std_core_types__order_box(_b_x0_5, _ctx), _x_x44, kk_std_core_order_default_fs_new_order2_fun47(x, y, _ctx), _ctx); /*1*/
  return kk_std_core_types__order2_unbox(_x_x43, KK_OWNED, _ctx);
}

// initialization
void kk_std_core_order__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_order__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_types__done(_ctx);
}
