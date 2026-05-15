#pragma once
#ifndef kk_std_core_maybe2_H
#define kk_std_core_maybe2_H
// Koka generated module: std/core/maybe2, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"

// type declarations

// value declarations
 
// Match a `:maybe2` value and either return a default value on `Nothing2` or apply a function to the value on `Just2`

static inline kk_box_t kk_std_core_maybe2_maybe2(kk_std_core_types__maybe2 m, kk_box_t onNothing, kk_function_t onJust, kk_context_t* _ctx) { /* forall<a,b,c,e> (m : maybe2<a,b>, onNothing : c, onJust : (a, b) -> e c) -> e c */ 
  if (kk_std_core_types__is_Nothing2(m, _ctx)) {
    kk_function_drop(onJust, _ctx);
    return onNothing;
  }
  {
    kk_box_t x = m._cons.Just2.fst;
    kk_box_t y = m._cons.Just2.snd;
    kk_box_drop(onNothing, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), onJust, (onJust, x, y, _ctx), _ctx);
  }
}
 
// Convert a `:maybe2<a,b>` value to `:(a,b)`, using the `nothing` parameter for `Nothing2`.

static inline kk_std_core_types__tuple2 kk_std_core_maybe2_default(kk_std_core_types__maybe2 m, kk_std_core_types__tuple2 nothing, kk_context_t* _ctx) { /* forall<a,b> (m : maybe2<a,b>, nothing : (a, b)) -> (a, b) */ 
  if (kk_std_core_types__is_Nothing2(m, _ctx)) {
    return nothing;
  }
  {
    kk_box_t x = m._cons.Just2.fst;
    kk_box_t y = m._cons.Just2.snd;
    kk_std_core_types__tuple2_drop(nothing, _ctx);
    return kk_std_core_types__new_Tuple2(x, y, _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_maybe2_unjust(kk_std_core_types__maybe2 m, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx); /* forall<a,b> (m : maybe2<a,b>, ?kk-file-line : string) -> exn (a, b) */ 

kk_std_core_types__tuple2 kk_std_core_maybe2_expect(kk_std_core_types__maybe2 m, kk_string_t error_msg, kk_context_t* _ctx); /* forall<a,b> (m : maybe2<a,b>, error-msg : string) -> exn (a, b) */ 
 
// monadic lift

static inline kk_std_core_types__maybe2 kk_std_core_maybe2__mlift_map_10125(kk_std_core_types__tuple2 _y_x10110, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b)) -> e maybe2<a,b> */ 
  {
    kk_box_t fx = _y_x10110.fst;
    kk_box_t fy = _y_x10110.snd;
    return kk_std_core_types__new_Just2(fx, fy, _ctx);
  }
}

kk_std_core_types__maybe2 kk_std_core_maybe2_map(kk_std_core_types__maybe2 m, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,c,d,e> (m : maybe2<a,b>, f : (a, b) -> e (c, d)) -> e maybe2<c,d> */ 

static inline kk_std_core_types__maybe2 kk_std_core_maybe2__lp__bar__bar__rp_(kk_std_core_types__maybe2 m1, kk_std_core_types__maybe2 m2, kk_context_t* _ctx) { /* forall<a,b> (m1 : maybe2<a,b>, m2 : maybe2<a,b>) -> maybe2<a,b> */ 
  if (kk_std_core_types__is_Nothing2(m1, _ctx)) {
    return m2;
  }
  {
    kk_std_core_types__maybe2_drop(m2, _ctx);
    return m1;
  }
}
 
// monadic lift

static inline bool kk_std_core_maybe2__lp__at_mlift_x_10126_eq__eq__rp_(kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_box_t b, kk_box_t y, bool _y_x10112, kk_context_t* _ctx) { /* forall<a,e> (?snd/(==) : (a, a) -> e bool, b : a, y : a, bool) -> e bool */ 
  if (_y_x10112) {
    return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y, b, _ctx), _ctx);
  }
  {
    kk_box_drop(y, _ctx);
    kk_box_drop(b, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}

bool kk_std_core_maybe2__lp__eq__eq__rp_(kk_std_core_types__maybe2 mb1, kk_std_core_types__maybe2 mb2, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_context_t* _ctx); /* forall<a,b,e> (mb1 : maybe2<a,b>, mb2 : maybe2<a,b>, ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool) -> e bool */ 
 
// monadic lift

static inline kk_std_core_types__order kk_std_core_maybe2__mlift_cmp_10127(kk_box_t b, kk_function_t _implicit_fs_snd_fs_cmp, kk_box_t y, kk_std_core_types__order _y_x10117, kk_context_t* _ctx) { /* forall<a,e> (b : a, ?snd/cmp : (a, a) -> e order, y : a, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10117, _ctx)) {
    return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y, b, _ctx), _ctx);
  }
  {
    kk_box_drop(y, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    kk_box_drop(b, _ctx);
    return _y_x10117;
  }
}

kk_std_core_types__order kk_std_core_maybe2_cmp(kk_std_core_types__maybe2 mb1, kk_std_core_types__maybe2 mb2, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_context_t* _ctx); /* forall<a,b,e> (mb1 : maybe2<a,b>, mb2 : maybe2<a,b>, ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order) -> e order */ 
 
// monadic lift

static inline kk_string_t kk_std_core_maybe2__mlift_show_10128(kk_string_t _y_x10122, kk_string_t _y_x10123, kk_context_t* _ctx) { /* forall<e> (string, string) -> e string */ 
  kk_string_t _x_x76;
  kk_define_string_literal(static, _s_x77, 6, "Just2(", _ctx)
  _x_x76 = kk_string_dup(_s_x77, _ctx); /*string*/
  kk_string_t _x_x78;
  kk_string_t _x_x79;
  kk_string_t _x_x80;
  kk_define_string_literal(static, _s_x81, 1, ",", _ctx)
  _x_x80 = kk_string_dup(_s_x81, _ctx); /*string*/
  kk_string_t _x_x82;
  kk_string_t _x_x83;
  kk_define_string_literal(static, _s_x84, 1, ")", _ctx)
  _x_x83 = kk_string_dup(_s_x84, _ctx); /*string*/
  _x_x82 = kk_std_core_types__lp__plus__plus__rp_(_y_x10123, _x_x83, _ctx); /*string*/
  _x_x79 = kk_std_core_types__lp__plus__plus__rp_(_x_x80, _x_x82, _ctx); /*string*/
  _x_x78 = kk_std_core_types__lp__plus__plus__rp_(_y_x10122, _x_x79, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x76, _x_x78, _ctx);
}

kk_string_t kk_std_core_maybe2__mlift_show_10129(kk_function_t _implicit_fs_snd_fs_show, kk_box_t y, kk_string_t _y_x10122, kk_context_t* _ctx); /* forall<a,e> (?snd/show : (a) -> e string, y : a, string) -> e string */ 

kk_string_t kk_std_core_maybe2_show(kk_std_core_types__maybe2 mb, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx); /* forall<a,b,e> (mb : maybe2<a,b>, ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */ 
 
// Convert a `:maybe2` type to a boolean, equivalent to `is-just2`.

static inline bool kk_std_core_maybe2_bool(kk_std_core_types__maybe2 mb, kk_context_t* _ctx) { /* forall<a,b> (mb : maybe2<a,b>) -> bool */ 
  if (kk_std_core_types__is_Just2(mb, _ctx)) {
    kk_std_core_types__maybe2_drop(mb, _ctx);
    return true;
  }
  {
    return false;
  }
}

void kk_std_core_maybe2__init(kk_context_t* _ctx);


void kk_std_core_maybe2__done(kk_context_t* _ctx);

#endif // header
