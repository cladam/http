// Koka generated module: std/core/either, koka version: 3.2.3, platform: 64-bit
#include "std_core_either.h"
 
// Map over the `Right` component of an `:either` type.


// lift anonymous function
struct kk_std_core_either_map_fun16__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_either_map_fun16(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core_either_new_map_fun16(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_either_map_fun16, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_either_map_fun16(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _y_x10100_3 = _b_x1; /*166*/;
  kk_std_core_types__either _x_x17 = kk_std_core_types__new_Right(_y_x10100_3, _ctx); /*either<47,48>*/
  return kk_std_core_types__either_box(_x_x17, _ctx);
}

kk_std_core_types__either kk_std_core_either_map(kk_std_core_types__either e, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (e : either<a,b>, f : (b) -> e c) -> e either<a,c> */ 
  if (kk_std_core_types__is_Right(e, _ctx)) {
    kk_box_t x = e._cons.Right.right;
    kk_box_t x_0_10113 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*166*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10113, _ctx);
      kk_box_t _x_x15 = kk_std_core_hnd_yield_extend(kk_std_core_either_new_map_fun16(_ctx), _ctx); /*2419*/
      return kk_std_core_types__either_unbox(_x_x15, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Right(x_0_10113, _ctx);
    }
  }
  {
    kk_box_t x_0_0 = e._cons.Left.left;
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Left(x_0_0, _ctx);
  }
}
 
// Equality on `:either` values

bool kk_std_core_either__lp__eq__eq__rp_(kk_std_core_types__either e1, kk_std_core_types__either e2, kk_function_t _implicit_fs_left_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_right_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,e> (e1 : either<a,b>, e2 : either<a,b>, ?left/(==) : (a, a) -> e bool, ?right/(==) : (b, b) -> e bool) -> e bool */ 
  if (kk_std_core_types__is_Left(e1, _ctx)) {
    kk_box_t l1 = e1._cons.Left.left;
    kk_function_drop(_implicit_fs_right_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Left(e2, _ctx)) {
      kk_box_t l2 = e2._cons.Left.left;
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_left_fs__lp__eq__eq__rp_, (_implicit_fs_left_fs__lp__eq__eq__rp_, l1, l2, _ctx), _ctx);
    }
    {
      kk_box_drop(l1, _ctx);
      kk_std_core_types__either_drop(e2, _ctx);
      kk_function_drop(_implicit_fs_left_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_box_t r1 = e1._cons.Right.right;
    kk_function_drop(_implicit_fs_left_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Right(e2, _ctx)) {
      kk_box_t r2 = e2._cons.Right.right;
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_right_fs__lp__eq__eq__rp_, (_implicit_fs_right_fs__lp__eq__eq__rp_, r1, r2, _ctx), _ctx);
    }
    {
      kk_box_drop(r1, _ctx);
      kk_std_core_types__either_drop(e2, _ctx);
      kk_function_drop(_implicit_fs_right_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
}
 
// Show an `:either` type


// lift anonymous function
struct kk_std_core_either_show_fun29__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_either_show_fun29(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_either_new_show_fun29(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_either_show_fun29, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_either_show_fun29(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _y_x10107_10 = kk_string_unbox(_b_x5); /*string*/;
  kk_string_t _x_x30;
  kk_string_t _x_x31;
  kk_define_string_literal(static, _s_x32, 6, "Right(", _ctx)
  _x_x31 = kk_string_dup(_s_x32, _ctx); /*string*/
  kk_string_t _x_x33;
  kk_string_t _x_x34;
  kk_define_string_literal(static, _s_x35, 1, ")", _ctx)
  _x_x34 = kk_string_dup(_s_x35, _ctx); /*string*/
  _x_x33 = kk_std_core_types__lp__plus__plus__rp_(_y_x10107_10, _x_x34, _ctx); /*string*/
  _x_x30 = kk_std_core_types__lp__plus__plus__rp_(_x_x31, _x_x33, _ctx); /*string*/
  return kk_string_box(_x_x30);
}


// lift anonymous function
struct kk_std_core_either_show_fun42__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_either_show_fun42(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_core_either_new_show_fun42(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_either_show_fun42, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_either_show_fun42(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _y_x10108_11 = kk_string_unbox(_b_x7); /*string*/;
  kk_string_t _x_x43;
  kk_string_t _x_x44;
  kk_define_string_literal(static, _s_x45, 5, "Left(", _ctx)
  _x_x44 = kk_string_dup(_s_x45, _ctx); /*string*/
  kk_string_t _x_x46;
  kk_string_t _x_x47;
  kk_define_string_literal(static, _s_x48, 1, ")", _ctx)
  _x_x47 = kk_string_dup(_s_x48, _ctx); /*string*/
  _x_x46 = kk_std_core_types__lp__plus__plus__rp_(_y_x10108_11, _x_x47, _ctx); /*string*/
  _x_x43 = kk_std_core_types__lp__plus__plus__rp_(_x_x44, _x_x46, _ctx); /*string*/
  return kk_string_box(_x_x43);
}

kk_string_t kk_std_core_either_show(kk_std_core_types__either e, kk_function_t _implicit_fs_left_fs_show, kk_function_t _implicit_fs_right_fs_show, kk_context_t* _ctx) { /* forall<a,b,e> (e : either<a,b>, ?left/show : (a) -> e string, ?right/show : (b) -> e string) -> e string */ 
  if (kk_std_core_types__is_Right(e, _ctx)) {
    kk_box_t x = e._cons.Right.right;
    kk_function_drop(_implicit_fs_left_fs_show, _ctx);
    kk_string_t x_0_10117 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_right_fs_show, (_implicit_fs_right_fs_show, x, _ctx), _ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10117, _ctx);
      kk_box_t _x_x28 = kk_std_core_hnd_yield_extend(kk_std_core_either_new_show_fun29(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x28);
    }
    {
      kk_string_t _x_x36;
      kk_define_string_literal(static, _s_x37, 6, "Right(", _ctx)
      _x_x36 = kk_string_dup(_s_x37, _ctx); /*string*/
      kk_string_t _x_x38;
      kk_string_t _x_x39;
      kk_define_string_literal(static, _s_x40, 1, ")", _ctx)
      _x_x39 = kk_string_dup(_s_x40, _ctx); /*string*/
      _x_x38 = kk_std_core_types__lp__plus__plus__rp_(x_0_10117, _x_x39, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x36, _x_x38, _ctx);
    }
  }
  {
    kk_box_t y = e._cons.Left.left;
    kk_function_drop(_implicit_fs_right_fs_show, _ctx);
    kk_string_t x_1_10121 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_left_fs_show, (_implicit_fs_left_fs_show, y, _ctx), _ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10121, _ctx);
      kk_box_t _x_x41 = kk_std_core_hnd_yield_extend(kk_std_core_either_new_show_fun42(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x41);
    }
    {
      kk_string_t _x_x49;
      kk_define_string_literal(static, _s_x50, 5, "Left(", _ctx)
      _x_x49 = kk_string_dup(_s_x50, _ctx); /*string*/
      kk_string_t _x_x51;
      kk_string_t _x_x52;
      kk_define_string_literal(static, _s_x53, 1, ")", _ctx)
      _x_x52 = kk_string_dup(_s_x53, _ctx); /*string*/
      _x_x51 = kk_std_core_types__lp__plus__plus__rp_(x_1_10121, _x_x52, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x49, _x_x51, _ctx);
    }
  }
}

// initialization
void kk_std_core_either__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_either__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
