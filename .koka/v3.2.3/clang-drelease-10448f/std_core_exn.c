// Koka generated module: std/core/exn, koka version: 3.2.3, platform: 64-bit
#include "std_core_exn.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_std_core_exn__error kk_error_ok( kk_box_t result, kk_context_t* ctx ) {
  return kk_std_core_exn__new_Ok( result, ctx );
}

kk_std_core_exn__error kk_error_from_errno( int err, kk_context_t* ctx ) {
  kk_string_t msg;
  #if defined(__GLIBC__) && !defined(WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__)
    // GNU version of strerror_r
    char buf[256];
    char* serr = strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( serr, ctx );
  #elif (/* _POSIX_C_SOURCE >= 200112L ||*/ !defined(WIN32) && (_XOPEN_SOURCE >= 600 || defined(__APPLE__) || defined(__FreeBSD__) || defined(__MUSL__)))
    // XSI version of strerror_r
    char buf[256];
    strerror_r(err, buf, 255); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #elif defined(_MSC_VER) || (__STDC_VERSION__ >= 201112L || __cplusplus >= 201103L)
    // MSVC, or C/C++ 11
    char buf[256];
    strerror_s(buf, 255, err); buf[255] = 0;
    msg = kk_string_alloc_from_qutf8( buf, ctx );
  #else
    // Old style
    msg = kk_string_alloc_from_qutf8( strerror(err), ctx );
  #endif
  return kk_std_core_exn__new_Error( kk_std_core_exn__new_Exception( msg, kk_std_core_exn__new_ExnSystem(kk_reuse_null, 0, kk_integer_from_int(err,ctx), ctx), ctx), ctx );
}


 
// runtime tag for the effect `:exn`

kk_std_core_hnd__htag kk_std_core_exn_exn_fs__tag;
 
// handler for the effect `:exn`

kk_box_t kk_std_core_exn_exn_fs__handle(kk_std_core_exn__exn hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : exn<e,b>, ret : (res : a) -> e b, action : () -> <exn|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x99 = kk_std_core_hnd__htag_dup(kk_std_core_exn_exn_fs__tag, _ctx); /*hnd/htag<exn>*/
  return kk_std_core_hnd__hhandle(_x_x99, kk_std_core_exn__exn_box(hnd, _ctx), ret, action, _ctx);
}

kk_std_core_exn__exception kk_std_core_exn_exception_fs__copy(kk_std_core_exn__exception _this, kk_std_core_types__optional message, kk_std_core_types__optional info, kk_context_t* _ctx) { /* (exception, message : ? string, info : ? exception-info) -> exception */ 
  kk_string_t _x_x104;
  if (kk_std_core_types__is_Optional(message, _ctx)) {
    kk_box_t _box_x16 = message._cons._Optional.value;
    kk_string_t _uniq_message_371 = kk_string_unbox(_box_x16);
    kk_string_dup(_uniq_message_371, _ctx);
    kk_std_core_types__optional_drop(message, _ctx);
    _x_x104 = _uniq_message_371; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(message, _ctx);
    {
      kk_string_t _x = _this.message;
      kk_string_dup(_x, _ctx);
      _x_x104 = _x; /*string*/
    }
  }
  kk_std_core_exn__exception_info _x_x105;
  if (kk_std_core_types__is_Optional(info, _ctx)) {
    kk_box_t _box_x17 = info._cons._Optional.value;
    kk_std_core_exn__exception_info _uniq_info_379 = kk_std_core_exn__exception_info_unbox(_box_x17, KK_BORROWED, _ctx);
    kk_std_core_exn__exception_info_dup(_uniq_info_379, _ctx);
    kk_std_core_types__optional_drop(info, _ctx);
    kk_std_core_exn__exception_drop(_this, _ctx);
    _x_x105 = _uniq_info_379; /*exception-info*/
  }
  else {
    kk_std_core_types__optional_drop(info, _ctx);
    {
      kk_std_core_exn__exception_info _x_0 = _this.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(_this, _ctx);
      _x_x105 = _x_0; /*exception-info*/
    }
  }
  return kk_std_core_exn__new_Exception(_x_x104, _x_x105, _ctx);
}
kk_declare_string_literal(, kk_std_core_exn__tag_ExnError, 21, "std/core/exn/ExnError")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnAssert, 22, "std/core/exn/ExnAssert")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnTodo, 20, "std/core/exn/ExnTodo")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnRange, 21, "std/core/exn/ExnRange")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnPattern, 23, "std/core/exn/ExnPattern")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnSystem, 22, "std/core/exn/ExnSystem")
kk_declare_string_literal(, kk_std_core_exn__tag_ExnInternal, 24, "std/core/exn/ExnInternal")
 
// Throw an exception with a specified message.

kk_box_t kk_std_core_exn_throw(kk_string_t message, kk_std_core_types__optional info, kk_context_t* _ctx) { /* forall<a> (message : string, info : ? exception-info) -> exn a */ 
  kk_std_core_hnd__ev ev_10135 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x106 = kk_std_core_hnd__as_Ev(ev_10135, _ctx);
    kk_box_t _box_x18 = _con_x106->hnd;
    int32_t m = _con_x106->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x107 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x107->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x107->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x22 = _brk_throw_exn.clause;
        kk_box_t _x_x108;
        kk_std_core_exn__exception _x_x109;
        kk_std_core_exn__exception_info _x_x110;
        if (kk_std_core_types__is_Optional(info, _ctx)) {
          kk_box_t _box_x26 = info._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x26, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(info, _ctx);
          _x_x110 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(info, _ctx);
          _x_x110 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x109 = kk_std_core_exn__new_Exception(message, _x_x110, _ctx); /*exception*/
        _x_x108 = kk_std_core_exn__exception_box(_x_x109, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22, (_fun_unbox_x22, m, ev_10135, _x_x108, _ctx), _ctx);
      }
    }
  }
}
 
// Raise a pattern match exception. This is function is used internally by the
// compiler to generate error messages on pattern match failures.

kk_box_t kk_std_core_exn_error_pattern(kk_string_t location, kk_string_t definition, kk_context_t* _ctx) { /* forall<a> (location : string, definition : string) -> exn a */ 
  kk_string_t message_10003;
  kk_string_t _x_x111 = kk_string_dup(location, _ctx); /*string*/
  kk_string_t _x_x112;
  kk_string_t _x_x113;
  kk_define_string_literal(static, _s_x114, 2, ": ", _ctx)
  _x_x113 = kk_string_dup(_s_x114, _ctx); /*string*/
  kk_string_t _x_x115;
  kk_string_t _x_x116 = kk_string_dup(definition, _ctx); /*string*/
  kk_string_t _x_x117;
  kk_define_string_literal(static, _s_x118, 23, ": pattern match failure", _ctx)
  _x_x117 = kk_string_dup(_s_x118, _ctx); /*string*/
  _x_x115 = kk_std_core_types__lp__plus__plus__rp_(_x_x116, _x_x117, _ctx); /*string*/
  _x_x112 = kk_std_core_types__lp__plus__plus__rp_(_x_x113, _x_x115, _ctx); /*string*/
  message_10003 = kk_std_core_types__lp__plus__plus__rp_(_x_x111, _x_x112, _ctx); /*string*/
  kk_std_core_hnd__ev ev_10138 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x119 = kk_std_core_hnd__as_Ev(ev_10138, _ctx);
    kk_box_t _box_x27 = _con_x119->hnd;
    int32_t m = _con_x119->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x27, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x120 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x120->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x120->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x31 = _brk_throw_exn.clause;
        kk_box_t _x_x121;
        kk_std_core_exn__exception _x_x122;
        kk_std_core_exn__exception_info _x_x123 = kk_std_core_exn__new_ExnPattern(kk_reuse_null, 0, location, definition, _ctx); /*exception-info*/
        _x_x122 = kk_std_core_exn__new_Exception(message_10003, _x_x123, _ctx); /*exception*/
        _x_x121 = kk_std_core_exn__exception_box(_x_x122, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x31, (_fun_unbox_x31, m, ev_10138, _x_x121, _ctx), _ctx);
      }
    }
  }
}
 
// Catch any exception raised in `action` and handle it.
// Use `on-exit` when appropriate.


// lift anonymous function
struct kk_std_core_exn_handle_fs_try_fun131__t {
  struct kk_function_s _base;
  kk_function_t hndl;
};
static kk_box_t kk_std_core_exn_handle_fs_try_fun131(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_handle_fs_new_try_fun131(kk_function_t hndl, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun131__t* _self = kk_function_alloc_as(struct kk_std_core_exn_handle_fs_try_fun131__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_handle_fs_try_fun131, kk_context());
  _self->hndl = hndl;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_handle_fs_try_fun132__t {
  struct kk_function_s _base;
  kk_function_t hndl;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core_exn_handle_fs_try_fun132(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_handle_fs_new_try_fun132(kk_function_t hndl, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun132__t* _self = kk_function_alloc_as(struct kk_std_core_exn_handle_fs_try_fun132__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_handle_fs_try_fun132, kk_context());
  _self->hndl = hndl;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_handle_fs_try_fun132(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun132__t* _self = kk_function_as(struct kk_std_core_exn_handle_fs_try_fun132__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 657 656 */
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x654__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_exn__exception, kk_context_t*), hndl, (hndl, x, _ctx), _ctx);
}
static kk_box_t kk_std_core_exn_handle_fs_try_fun131(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun131__t* _self = kk_function_as(struct kk_std_core_exn_handle_fs_try_fun131__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 657 656 */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x654__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_handle_fs_new_try_fun132(hndl, x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_handle_fs_try_fun135__t {
  struct kk_function_s _base;
  kk_function_t _b_x35_39;
};
static kk_box_t kk_std_core_exn_handle_fs_try_fun135(kk_function_t _fself, int32_t _b_x36, kk_std_core_hnd__ev _b_x37, kk_box_t _b_x38, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_handle_fs_new_try_fun135(kk_function_t _b_x35_39, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun135__t* _self = kk_function_alloc_as(struct kk_std_core_exn_handle_fs_try_fun135__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_handle_fs_try_fun135, kk_context());
  _self->_b_x35_39 = _b_x35_39;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_handle_fs_try_fun135(kk_function_t _fself, int32_t _b_x36, kk_std_core_hnd__ev _b_x37, kk_box_t _b_x38, kk_context_t* _ctx) {
  struct kk_std_core_exn_handle_fs_try_fun135__t* _self = kk_function_as(struct kk_std_core_exn_handle_fs_try_fun135__t*, _fself, _ctx);
  kk_function_t _b_x35_39 = _self->_b_x35_39; /* (m : hnd/marker<657,656>, hnd/ev<exn>, x : exception) -> 657 638 */
  kk_drop_match(_self, {kk_function_dup(_b_x35_39, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x136 = kk_std_core_exn__exception_unbox(_b_x38, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x35_39, (_b_x35_39, _b_x36, _b_x37, _x_x136, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_handle_fs_try_fun137__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_handle_fs_try_fun137(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_handle_fs_new_try_fun137(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_handle_fs_try_fun137, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_handle_fs_try_fun137(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_std_core_exn_handle_fs_try(kk_function_t action, kk_function_t hndl, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a, hndl : (exception) -> e a) -> e a */ 
  kk_function_t _b_x35_39 = kk_std_core_exn_handle_fs_new_try_fun131(hndl, _ctx); /*(m : hnd/marker<657,656>, hnd/ev<exn>, x : exception) -> 657 638*/;
  kk_std_core_exn__exn _x_x133;
  kk_std_core_hnd__clause1 _x_x134 = kk_std_core_hnd__new_Clause1(kk_std_core_exn_handle_fs_new_try_fun135(_b_x35_39, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x133 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x134, _ctx); /*exn<14,15>*/
  return kk_std_core_exn_exn_fs__handle(_x_x133, kk_std_core_exn_handle_fs_new_try_fun137(_ctx), action, _ctx);
}
 
// Transform an exception effect to an  `:error` type.


// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun139__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun139(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun139(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_error_fs_try_fun139, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun140__t {
  struct kk_function_s _base;
  kk_std_core_exn__exception x;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun140(kk_function_t _fself, kk_function_t _b_x42, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun140(kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun140__t* _self = kk_function_alloc_as(struct kk_std_core_exn_error_fs_try_fun140__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_error_fs_try_fun140, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun141__t {
  struct kk_function_s _base;
  kk_function_t _b_x42;
};
static kk_std_core_exn__error kk_std_core_exn_error_fs_try_fun141(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x43, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun141(kk_function_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun141__t* _self = kk_function_alloc_as(struct kk_std_core_exn_error_fs_try_fun141__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_error_fs_try_fun141, kk_context());
  _self->_b_x42 = _b_x42;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_exn__error kk_std_core_exn_error_fs_try_fun141(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x43, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun141__t* _self = kk_function_as(struct kk_std_core_exn_error_fs_try_fun141__t*, _fself, _ctx);
  kk_function_t _b_x42 = _self->_b_x42; /* (hnd/resume-result<2716,2719>) -> 2718 2719 */
  kk_drop_match(_self, {kk_function_dup(_b_x42, _ctx);}, {}, _ctx)
  kk_box_t _x_x142 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x42, (_b_x42, _b_x43, _ctx), _ctx); /*2719*/
  return kk_std_core_exn__error_unbox(_x_x142, KK_OWNED, _ctx);
}
static kk_box_t kk_std_core_exn_error_fs_try_fun140(kk_function_t _fself, kk_function_t _b_x42, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun140__t* _self = kk_function_as(struct kk_std_core_exn_error_fs_try_fun140__t*, _fself, _ctx);
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_t ___wildcard_x654__45_61 = kk_std_core_exn_error_fs_new_try_fun141(_b_x42, _ctx); /*(hnd/resume-result<638,error<704>>) -> 705 error<704>*/;
  kk_function_drop(___wildcard_x654__45_61, _ctx);
  kk_std_core_exn__error _x_x143 = kk_std_core_exn__new_Error(x, _ctx); /*error<6>*/
  return kk_std_core_exn__error_box(_x_x143, _ctx);
}
static kk_box_t kk_std_core_exn_error_fs_try_fun139(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x654__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_error_fs_new_try_fun140(x, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun146__t {
  struct kk_function_s _base;
  kk_function_t _b_x44_57;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun146(kk_function_t _fself, int32_t _b_x45, kk_std_core_hnd__ev _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun146(kk_function_t _b_x44_57, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun146__t* _self = kk_function_alloc_as(struct kk_std_core_exn_error_fs_try_fun146__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_error_fs_try_fun146, kk_context());
  _self->_b_x44_57 = _b_x44_57;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_exn_error_fs_try_fun146(kk_function_t _fself, int32_t _b_x45, kk_std_core_hnd__ev _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun146__t* _self = kk_function_as(struct kk_std_core_exn_error_fs_try_fun146__t*, _fself, _ctx);
  kk_function_t _b_x44_57 = _self->_b_x44_57; /* (m : hnd/marker<705,error<704>>, hnd/ev<exn>, x : exception) -> 705 638 */
  kk_drop_match(_self, {kk_function_dup(_b_x44_57, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x147 = kk_std_core_exn__exception_unbox(_b_x47, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x44_57, (_b_x44_57, _b_x45, _b_x46, _x_x147, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun148__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun148(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun148(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_error_fs_try_fun148, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_error_fs_try_fun148(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _res_62 = kk_std_core_exn__error_unbox(_b_x53, KK_OWNED, _ctx); /*error<704>*/;
  return kk_std_core_exn__error_box(_res_62, _ctx);
}


// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun149__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun149(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun149(kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun149__t* _self = kk_function_alloc_as(struct kk_std_core_exn_error_fs_try_fun149__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_exn_error_fs_try_fun149, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_core_exn_error_fs_try_fun152__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_exn_error_fs_try_fun152(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_core_exn_error_fs_new_try_fun152(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_exn_error_fs_try_fun152, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_exn_error_fs_try_fun152(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _y_x10122_63 = _b_x49; /*704*/;
  kk_std_core_exn__error _x_x153 = kk_std_core_exn__new_Ok(_y_x10122_63, _ctx); /*error<6>*/
  return kk_std_core_exn__error_box(_x_x153, _ctx);
}
static kk_box_t kk_std_core_exn_error_fs_try_fun149(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_exn_error_fs_try_fun149__t* _self = kk_function_as(struct kk_std_core_exn_error_fs_try_fun149__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <exn|705> 704 */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_box_t x_0_10143 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*704*/;
  kk_std_core_exn__error _x_x150;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_0_10143, _ctx);
    kk_box_t _x_x151 = kk_std_core_hnd_yield_extend(kk_std_core_exn_error_fs_new_try_fun152(_ctx), _ctx); /*2419*/
    _x_x150 = kk_std_core_exn__error_unbox(_x_x151, KK_OWNED, _ctx); /*error<704>*/
  }
  else {
    _x_x150 = kk_std_core_exn__new_Ok(x_0_10143, _ctx); /*error<704>*/
  }
  return kk_std_core_exn__error_box(_x_x150, _ctx);
}

kk_std_core_exn__error kk_std_core_exn_error_fs_try(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> <exn|e> a) -> e error<a> */ 
  kk_box_t _x_x138;
  kk_function_t _b_x44_57 = kk_std_core_exn_error_fs_new_try_fun139(_ctx); /*(m : hnd/marker<705,error<704>>, hnd/ev<exn>, x : exception) -> 705 638*/;
  kk_std_core_exn__exn _x_x144;
  kk_std_core_hnd__clause1 _x_x145 = kk_std_core_hnd__new_Clause1(kk_std_core_exn_error_fs_new_try_fun146(_b_x44_57, _ctx), _ctx); /*hnd/clause1<45,46,47,48,49>*/
  _x_x144 = kk_std_core_exn__new_Hnd_exn(kk_reuse_null, 0, kk_integer_from_small(0), _x_x145, _ctx); /*exn<14,15>*/
  _x_x138 = kk_std_core_exn_exn_fs__handle(_x_x144, kk_std_core_exn_error_fs_new_try_fun148(_ctx), kk_std_core_exn_error_fs_new_try_fun149(action, _ctx), _ctx); /*198*/
  return kk_std_core_exn__error_unbox(_x_x138, KK_OWNED, _ctx);
}
extern kk_box_t kk_std_core_exn_catch_fun155(kk_function_t _fself, kk_function_t ___wildcard_x654__45, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun155__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun155__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 736 735 */
  kk_std_core_exn__exception x = _self->x; /* exception */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);kk_std_core_exn__exception_dup(x, _ctx);}, {}, _ctx)
  kk_function_drop(___wildcard_x654__45, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_std_core_exn__exception, kk_context_t*), hndl, (hndl, x, _ctx), _ctx);
}
extern kk_box_t kk_std_core_exn_catch_fun154(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x654__16, kk_std_core_exn__exception x, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun154__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun154__t*, _fself, _ctx);
  kk_function_t hndl = _self->hndl; /* (exception) -> 736 735 */
  kk_drop_match(_self, {kk_function_dup(hndl, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(___wildcard_x654__16, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(m, kk_std_core_exn_new_catch_fun155(hndl, x, _ctx), _ctx);
}
extern kk_box_t kk_std_core_exn_catch_fun158(kk_function_t _fself, int32_t _b_x65, kk_std_core_hnd__ev _b_x66, kk_box_t _b_x67, kk_context_t* _ctx) {
  struct kk_std_core_exn_catch_fun158__t* _self = kk_function_as(struct kk_std_core_exn_catch_fun158__t*, _fself, _ctx);
  kk_function_t _b_x64_68 = _self->_b_x64_68; /* (m : hnd/marker<736,735>, hnd/ev<exn>, x : exception) -> 736 638 */
  kk_drop_match(_self, {kk_function_dup(_b_x64_68, _ctx);}, {}, _ctx)
  kk_std_core_exn__exception _x_x159 = kk_std_core_exn__exception_unbox(_b_x67, KK_OWNED, _ctx); /*exception*/
  return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_exn__exception, kk_context_t*), _b_x64_68, (_b_x64_68, _b_x65, _b_x66, _x_x159, _ctx), _ctx);
}
extern kk_box_t kk_std_core_exn_catch_fun160(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}
 
// Transform an `:error` type back to an `exn` effect.

kk_box_t kk_std_core_exn_untry(kk_std_core_exn__error err, kk_context_t* _ctx) { /* forall<a> (err : error<a>) -> exn a */ 
  if (kk_std_core_exn__is_Error(err, _ctx)) {
    kk_std_core_exn__exception exn_0 = err._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn_0, _ctx);
    kk_std_core_exn__error_drop(err, _ctx);
    kk_std_core_hnd__ev ev_10147 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x161 = kk_std_core_hnd__as_Ev(ev_10147, _ctx);
      kk_box_t _box_x69 = _con_x161->hnd;
      int32_t m = _con_x161->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x69, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      {
        struct kk_std_core_exn__Hnd_exn* _con_x162 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x162->_cfc;
        kk_std_core_hnd__clause1 _brk_throw_exn = _con_x162->_brk_throw_exn;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x73 = _brk_throw_exn.clause;
          return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x73, (_fun_unbox_x73, m, ev_10147, kk_std_core_exn__exception_box(exn_0, _ctx), _ctx), _ctx);
        }
      }
    }
  }
  {
    kk_box_t x_0 = err._cons.Ok.result;
    return x_0;
  }
}
 
// Transform an `:error` type to an `:either` value.

kk_std_core_types__either kk_std_core_exn_either(kk_std_core_exn__error t, kk_context_t* _ctx) { /* forall<a> (t : error<a>) -> either<exception,a> */ 
  if (kk_std_core_exn__is_Error(t, _ctx)) {
    kk_std_core_exn__exception exn_0 = t._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn_0, _ctx);
    kk_std_core_exn__error_drop(t, _ctx);
    return kk_std_core_types__new_Left(kk_std_core_exn__exception_box(exn_0, _ctx), _ctx);
  }
  {
    kk_box_t x = t._cons.Ok.result;
    return kk_std_core_types__new_Right(x, _ctx);
  }
}

kk_box_t kk_std_core_exn_exn_error_range(kk_context_t* _ctx) { /* forall<a> () -> exn a */ 
  kk_std_core_hnd__ev ev_10152 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
  {
    struct kk_std_core_hnd_Ev* _con_x164 = kk_std_core_hnd__as_Ev(ev_10152, _ctx);
    kk_box_t _box_x79 = _con_x164->hnd;
    int32_t m = _con_x164->marker;
    kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x79, KK_BORROWED, _ctx);
    kk_std_core_exn__exn_dup(h, _ctx);
    {
      struct kk_std_core_exn__Hnd_exn* _con_x165 = kk_std_core_exn__as_Hnd_exn(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x165->_cfc;
      kk_std_core_hnd__clause1 _brk_throw_exn = _con_x165->_brk_throw_exn;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_brk_throw_exn, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x83 = _brk_throw_exn.clause;
        kk_box_t _x_x166;
        kk_std_core_exn__exception _x_x167;
        kk_string_t _x_x168;
        kk_define_string_literal(static, _s_x169, 18, "index out-of-range", _ctx)
        _x_x168 = kk_string_dup(_s_x169, _ctx); /*string*/
        _x_x167 = kk_std_core_exn__new_Exception(_x_x168, kk_std_core_exn__new_ExnRange(_ctx), _ctx); /*exception*/
        _x_x166 = kk_std_core_exn__exception_box(_x_x167, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x83, (_fun_unbox_x83, m, ev_10152, _x_x166, _ctx), _ctx);
      }
    }
  }
}
 
// Prepend `exn`'s message with `pre`.

kk_std_core_exn__exception kk_std_core_exn_prepend(kk_std_core_exn__exception exn_0, kk_string_t pre, kk_context_t* _ctx) { /* (exn : exception, pre : string) -> exception */ 
  kk_string_t _x_x170;
  kk_string_t _x_x171;
  kk_string_t _x_x172;
  kk_define_string_literal(static, _s_x173, 2, ": ", _ctx)
  _x_x172 = kk_string_dup(_s_x173, _ctx); /*string*/
  kk_string_t _x_x174;
  {
    kk_string_t _x = exn_0.message;
    kk_string_dup(_x, _ctx);
    _x_x174 = _x; /*string*/
  }
  _x_x171 = kk_std_core_types__lp__plus__plus__rp_(_x_x172, _x_x174, _ctx); /*string*/
  _x_x170 = kk_std_core_types__lp__plus__plus__rp_(pre, _x_x171, _ctx); /*string*/
  kk_std_core_exn__exception_info _x_x175;
  {
    kk_std_core_exn__exception_info _x_0 = exn_0.info;
    kk_std_core_exn__exception_info_dup(_x_0, _ctx);
    kk_std_core_exn__exception_drop(exn_0, _ctx);
    _x_x175 = _x_0; /*exception-info*/
  }
  return kk_std_core_exn__new_Exception(_x_x170, _x_x175, _ctx);
}

// initialization
void kk_std_core_exn__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x97;
    kk_define_string_literal(static, _s_x98, 7, "exn@exn", _ctx)
    _x_x97 = kk_string_dup(_s_x98, _ctx); /*string*/
    kk_std_core_exn_exn_fs__tag = kk_std_core_hnd__new_Htag(_x_x97, _ctx); /*hnd/htag<exn>*/
  }
  kk_init_string_literal(kk_std_core_exn__tag_ExnError, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnAssert, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnTodo, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnRange, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnPattern, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnSystem, _ctx)
  kk_init_string_literal(kk_std_core_exn__tag_ExnInternal, _ctx)
}

// termination
void kk_std_core_exn__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_std_core_exn_exn_fs__tag, _ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
