// Koka generated module: std/core/int, koka version: 3.2.3, platform: 64-bit
#include "std_core_int.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

// static inline kk_std_core_types__order kk_int_as_order(int i,kk_context_t* ctx) {
//   return (i==0 ? kk_std_core_types__new_Eq(ctx) : (i > 0 ? kk_std_core_types__new_Gt(ctx) : kk_std_core_types__new_Lt(ctx)));
// }

static inline kk_std_core_types__maybe kk_integer_xparse( kk_string_t s, bool hex, kk_context_t* ctx ) {
  kk_integer_t i;
  bool ok = (hex ? kk_integer_hex_parse(kk_string_cbuf_borrow(s,NULL,ctx),&i,ctx) : kk_integer_parse(kk_string_cbuf_borrow(s,NULL,ctx),&i,ctx) );
  kk_string_drop(s,ctx);
  return (ok ? kk_std_core_types__new_Just(kk_integer_box(i,ctx),ctx) : kk_std_core_types__new_Nothing(ctx));
}

static inline kk_std_core_types__tuple2 kk_integer_div_mod_tuple(kk_integer_t x, kk_integer_t y, kk_context_t* ctx) {
  kk_integer_t mod;
  kk_integer_t div = kk_integer_div_mod(x,y,&mod,ctx);
  return kk_std_core_types__new_Tuple2(kk_integer_box(div,ctx),kk_integer_box(mod,ctx),ctx);
}


kk_std_core_types__order kk_std_core_int_order(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> order */ 
  bool _match_x46 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x46) {
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Lt(_ctx);
  }
  {
    bool _match_x47;
    bool _brw_x48 = kk_integer_gt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(i, _ctx);
    _match_x47 = _brw_x48; /*bool*/
    if (_match_x47) {
      return kk_std_core_types__new_Gt(_ctx);
    }
    {
      return kk_std_core_types__new_Eq(_ctx);
    }
  }
}
 
// /* Euclidean-0 division & modulus.
// Euclidean division is defined as: For any `D`  and `d`  where ``d!=0`` , we have:
// 
// 1. ``D == d*(D/d) + (D%d)``
// 2. ``D%d``  is always positive where ``0 <= D%d < abs(d)``
// 
// Moreover, Euclidean-0 is a total function, for the case where `d==0`  we have
// that ``D%0 == D``  and ``D/0 == 0`` . So property (1) still holds, but not property (2).
// 
// Useful laws that hold for Euclidean-0 division:
// 
// * ``D/(-d) == -(D/d)``
// * ``D%(-d) == D%d``
// * ``D/(2^n) == sar(D,n)         ``  (where ``2^n`` means ``2`` to the power of ``n``)
// * ``D%(2^n) == D & ((2^n) - 1)  ``
// 
// See also _Division and modulus for computer scientists, Daan Leijen, 2001_ for further information
// (available at: <https://www.microsoft.com/en-us/research/wp-content/uploads/2016/02/divmodnote-letter.pdf>).
// */

kk_std_core_types__tuple2 kk_std_core_int_divmod(kk_integer_t x, kk_integer_t y, kk_context_t* _ctx) { /* (x : int, y : int) -> (int, int) */ 
  return kk_integer_div_mod_tuple(x,y,kk_context());
}
 
// Raise an integer `i` to the power of `exp`.

kk_integer_t kk_std_core_int_pow(kk_integer_t i, kk_integer_t exp, kk_context_t* _ctx) { /* (i : int, exp : int) -> int */ 
  return kk_integer_pow(i,exp,kk_context());
}
 
// Return the number of decimal digits of `i`. Return `0` when `i==0`.

kk_integer_t kk_std_core_int_count_digits(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_count_digits(i,kk_context());
}

kk_integer_t kk_std_core_int_mul_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> int */ 
  return kk_integer_mul_pow10(i,n,kk_context());
}
 
// Return the number of ending `0` digits of `i`. Return `0` when `i==0`.

kk_integer_t kk_std_core_int_is_exp10(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int */ 
  return kk_integer_ctz(i,kk_context());
}

kk_integer_t kk_std_core_int_cdiv_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> int */ 
  return kk_integer_cdiv_pow10(i,n,kk_context());
}

kk_std_core_types__tuple2 kk_std_core_int_cdivmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  bool _match_x41 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x41) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Tuple2(kk_integer_box(i, _ctx), kk_integer_box(kk_integer_from_small(0), _ctx), _ctx);
  }
  {
    kk_integer_t cq;
    kk_integer_t _x_x49 = kk_integer_dup(i, _ctx); /*int*/
    kk_integer_t _x_x50 = kk_integer_dup(n, _ctx); /*int*/
    cq = kk_std_core_int_cdiv_exp10(_x_x49, _x_x50, _ctx); /*int*/
    kk_integer_t y_10005;
    kk_integer_t _x_x51 = kk_integer_dup(cq, _ctx); /*int*/
    y_10005 = kk_std_core_int_mul_exp10(_x_x51, n, _ctx); /*int*/
    kk_integer_t cr = kk_integer_sub(i,y_10005,kk_context()); /*int*/;
    return kk_std_core_types__new_Tuple2(kk_integer_box(cq, _ctx), kk_integer_box(cr, _ctx), _ctx);
  }
}

kk_std_core_types__tuple2 kk_std_core_int_divmod_exp10(kk_integer_t i, kk_integer_t n, kk_context_t* _ctx) { /* (i : int, n : int) -> (int, int) */ 
  kk_std_core_types__tuple2 _match_x39;
  kk_integer_t _x_x52 = kk_integer_dup(n, _ctx); /*int*/
  _match_x39 = kk_std_core_int_cdivmod_exp10(i, _x_x52, _ctx); /*(int, int)*/
  {
    kk_box_t _box_x18 = _match_x39.fst;
    kk_box_t _box_x19 = _match_x39.snd;
    kk_integer_t cq = kk_integer_unbox(_box_x18, _ctx);
    kk_integer_t cr = kk_integer_unbox(_box_x19, _ctx);
    kk_integer_dup(cq, _ctx);
    kk_integer_dup(cr, _ctx);
    kk_std_core_types__tuple2_drop(_match_x39, _ctx);
    bool b_10006 = kk_integer_lt_borrow(cr,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (b_10006) {
      kk_integer_t y_0_10012 = kk_std_core_int_mul_exp10(kk_integer_from_small(1), n, _ctx); /*int*/;
      kk_integer_t _b_x20_24 = kk_integer_add_small_const(cq, -1, _ctx); /*int*/;
      kk_integer_t _b_x21_25 = kk_integer_add(cr,y_0_10012,kk_context()); /*int*/;
      return kk_std_core_types__new_Tuple2(kk_integer_box(_b_x20_24, _ctx), kk_integer_box(_b_x21_25, _ctx), _ctx);
    }
    {
      kk_integer_drop(n, _ctx);
      return kk_std_core_types__new_Tuple2(kk_integer_box(cq, _ctx), kk_integer_box(cr, _ctx), _ctx);
    }
  }
}
 
// Convert an `:int` to a string

kk_string_t kk_std_core_int_show(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> string */ 
  return kk_integer_to_string(i,kk_context());
}

kk_std_core_types__maybe kk_std_core_int_xparse(kk_string_t s, bool hex, kk_context_t* _ctx) { /* (s : string, hex : bool) -> maybe<int> */ 
  return kk_integer_xparse(s,hex,kk_context());
}
 
// clamp an `:int` to fit in an `:int8`.

int8_t kk_std_core_int_int8(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int8 */ 
  return kk_integer_clamp_int8(i,kk_context());
}
 
// clamp an `:int` to fit in an `:int8` but interpret the `:int` as an unsigned 8-bit value,
// and clamp between 0 and 255.

int8_t kk_std_core_int_uint8(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int8 */ 
  return kk_integer_clamp_byte(i,kk_context());
}
 
// clamp an `:int` to fit in an `:int16`.

int16_t kk_std_core_int_int16(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> int16 */ 
  return kk_integer_clamp_int16(i,kk_context());
}
 
// clamp an `:int` to fit in an `:intptr_t`.

intptr_t kk_std_core_int_intptr__t(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> intptr_t */ 
  return kk_integer_clamp_intptr_t(i,kk_context());
}
 
// Convert an integer to an `:ssize_t`. The number is _clamped_ to the maximal or minimum `:ssize_t`
// value if it is outside the range of an `:ssize_t`.
// Needed for evidence indices in `module std/core/hnd`

kk_ssize_t kk_std_core_int_ssize__t(kk_integer_t i, kk_context_t* _ctx) { /* (i : int) -> ssize_t */ 
  return kk_integer_clamp_ssize_t(i,kk_context());
}

// initialization
void kk_std_core_int__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_int__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_types__done(_ctx);
}
