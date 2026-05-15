// Koka generated module: std/core/debug, koka version: 3.2.3, platform: 64-bit
#include "std_core_debug.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

kk_unit_t kk_assert_fail( kk_string_t msg, kk_context_t* ctx ) {
  kk_fatal_error(EINVAL, "assertion failed: %s\n", kk_string_cbuf_borrow(msg,NULL,ctx));
  kk_string_drop(msg,ctx);
  return kk_Unit;
}

kk_box_t kk_abort( kk_string_t msg, kk_context_t* ctx ) {
  kk_fatal_error(EINVAL, "%s\n", kk_string_cbuf_borrow(msg,NULL,ctx));
  kk_string_drop(msg,ctx);
  return kk_box_null();
}

kk_define_string_literal_empty(, kk_std_core_debug_file_fs_kk_module)

kk_integer_t kk_std_core_debug_file_fs_kk_line;
kk_define_string_literal_empty(, kk_std_core_debug_file_fs_kk_file)

kk_unit_t kk_std_core_debug_xtrace(kk_string_t message, kk_context_t* _ctx) { /* (message : string) -> () */ 
  kk_trace(message,kk_context()); return kk_Unit;
}

kk_unit_t kk_std_core_debug_xtrace_any(kk_string_t message, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (message : string, x : a) -> () */ 
  kk_trace_any(message,x,kk_context()); return kk_Unit;
}

kk_ref_t kk_std_core_debug_trace_enabled;
 
// Trace a message used for debug purposes.
// The behavior is system dependent. On a browser and node it uses
// `console.log`  by default.
// Disabled if `notrace` is called.

kk_unit_t kk_std_core_debug_trace(kk_string_t message, kk_context_t* _ctx) { /* (message : string) -> () */ 
  bool _match_x38;
  kk_box_t _x_x46;
  kk_ref_t _x_x47 = kk_ref_dup(kk_std_core_debug_trace_enabled, _ctx); /*ref<global,bool>*/
  _x_x46 = kk_ref_get(_x_x47,kk_context()); /*212*/
  _match_x38 = kk_bool_unbox(_x_x46); /*bool*/
  if (_match_x38) {
    kk_std_core_debug_xtrace(message, _ctx); return kk_Unit;
  }
  {
    kk_string_drop(message, _ctx);
    kk_Unit; return kk_Unit;
  }
}

kk_unit_t kk_std_core_debug_trace_info(kk_string_t message, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* (message : string, ?kk-file-line : string) -> () */ 
  kk_string_t message_0_10002;
  kk_string_t _x_x48;
  kk_string_t _x_x49;
  kk_define_string_literal(static, _s_x50, 2, ": ", _ctx)
  _x_x49 = kk_string_dup(_s_x50, _ctx); /*string*/
  _x_x48 = kk_std_core_types__lp__plus__plus__rp_(_x_x49, message, _ctx); /*string*/
  message_0_10002 = kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file_line, _x_x48, _ctx); /*string*/
  bool _match_x37;
  kk_box_t _x_x51;
  kk_ref_t _x_x52 = kk_ref_dup(kk_std_core_debug_trace_enabled, _ctx); /*ref<global,bool>*/
  _x_x51 = kk_ref_get(_x_x52,kk_context()); /*212*/
  _match_x37 = kk_bool_unbox(_x_x51); /*bool*/
  if (_match_x37) {
    kk_std_core_debug_xtrace(message_0_10002, _ctx); return kk_Unit;
  }
  {
    kk_string_drop(message_0_10002, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_core_debug__mlift_trace_show_10115(kk_string_t _implicit_fs_kk_file_line, kk_string_t _y_x10111, kk_context_t* _ctx) { /* forall<_e,e1> (?kk-file-line : string, string) -> e1 () */ 
  kk_string_t message_0_10004;
  kk_string_t _x_x53;
  kk_string_t _x_x54;
  kk_define_string_literal(static, _s_x55, 2, ": ", _ctx)
  _x_x54 = kk_string_dup(_s_x55, _ctx); /*string*/
  _x_x53 = kk_std_core_types__lp__plus__plus__rp_(_x_x54, _y_x10111, _ctx); /*string*/
  message_0_10004 = kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file_line, _x_x53, _ctx); /*string*/
  bool _match_x36;
  kk_box_t _x_x56;
  kk_ref_t _x_x57 = kk_ref_dup(kk_std_core_debug_trace_enabled, _ctx); /*ref<global,bool>*/
  _x_x56 = kk_ref_get(_x_x57,kk_context()); /*212*/
  _match_x36 = kk_bool_unbox(_x_x56); /*bool*/
  if (_match_x36) {
    kk_std_core_debug_xtrace(message_0_10004, _ctx); return kk_Unit;
  }
  {
    kk_string_drop(message_0_10004, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_std_core_debug_trace_show_fun59__t {
  struct kk_function_s _base;
  kk_string_t _implicit_fs_kk_file_line;
};
static kk_box_t kk_std_core_debug_trace_show_fun59(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx);
static kk_function_t kk_std_core_debug_new_trace_show_fun59(kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) {
  struct kk_std_core_debug_trace_show_fun59__t* _self = kk_function_alloc_as(struct kk_std_core_debug_trace_show_fun59__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_debug_trace_show_fun59, kk_context());
  _self->_implicit_fs_kk_file_line = _implicit_fs_kk_file_line;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_debug_trace_show_fun59(kk_function_t _fself, kk_box_t _b_x15, kk_context_t* _ctx) {
  struct kk_std_core_debug_trace_show_fun59__t* _self = kk_function_as(struct kk_std_core_debug_trace_show_fun59__t*, _fself, _ctx);
  kk_string_t _implicit_fs_kk_file_line = _self->_implicit_fs_kk_file_line; /* string */
  kk_drop_match(_self, {kk_string_dup(_implicit_fs_kk_file_line, _ctx);}, {}, _ctx)
  kk_string_t _y_x10111_21 = kk_string_unbox(_b_x15); /*string*/;
  kk_unit_t _x_x60 = kk_Unit;
  kk_std_core_debug__mlift_trace_show_10115(_implicit_fs_kk_file_line, _y_x10111_21, _ctx);
  return kk_unit_box(_x_x60);
}

kk_unit_t kk_std_core_debug_trace_show(kk_box_t x, kk_function_t _implicit_fs_show, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* forall<a,e> (x : a, ?show : (a) -> e string, ?kk-file-line : string) -> e () */ 
  kk_string_t x_0_10116 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, x, _ctx), _ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10116, _ctx);
    kk_box_t _x_x58 = kk_std_core_hnd_yield_extend(kk_std_core_debug_new_trace_show_fun59(_implicit_fs_kk_file_line, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x58); return kk_Unit;
  }
  {
    kk_string_t message_0_10004;
    kk_string_t _x_x61;
    kk_string_t _x_x62;
    kk_define_string_literal(static, _s_x63, 2, ": ", _ctx)
    _x_x62 = kk_string_dup(_s_x63, _ctx); /*string*/
    _x_x61 = kk_std_core_types__lp__plus__plus__rp_(_x_x62, x_0_10116, _ctx); /*string*/
    message_0_10004 = kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file_line, _x_x61, _ctx); /*string*/
    bool _match_x35;
    kk_box_t _x_x64;
    kk_ref_t _x_x65 = kk_ref_dup(kk_std_core_debug_trace_enabled, _ctx); /*ref<global,bool>*/
    _x_x64 = kk_ref_get(_x_x65,kk_context()); /*212*/
    _match_x35 = kk_bool_unbox(_x_x64); /*bool*/
    if (_match_x35) {
      kk_std_core_debug_xtrace(message_0_10004, _ctx); return kk_Unit;
    }
    {
      kk_string_drop(message_0_10004, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

kk_unit_t kk_std_core_debug_trace_any(kk_string_t message, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (message : string, x : a) -> () */ 
  bool _match_x33;
  kk_box_t _x_x66;
  kk_ref_t _x_x67 = kk_ref_dup(kk_std_core_debug_trace_enabled, _ctx); /*ref<global,bool>*/
  _x_x66 = kk_ref_get(_x_x67,kk_context()); /*212*/
  _match_x33 = kk_bool_unbox(_x_x66); /*bool*/
  if (_match_x33) {
    kk_std_core_debug_xtrace_any(message, x, _ctx); return kk_Unit;
  }
  {
    kk_box_drop(x, _ctx);
    kk_string_drop(message, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Disable tracing completely.

kk_unit_t kk_std_core_debug_notrace(kk_context_t* _ctx) { /* () -> (st<global>) () */ 
  kk_ref_set_borrow(kk_std_core_debug_trace_enabled,(kk_bool_box(false)),kk_context()); return kk_Unit;
}

kk_box_t kk_std_core_debug_unsafe_abort(kk_string_t msg, kk_context_t* _ctx) { /* forall<a> (msg : string) -> a */ 
  return kk_abort(msg,kk_context());
}

kk_box_t kk_std_core_debug_impossible(kk_std_core_types__optional message, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* forall<a> (message : ? string, ?kk-file-line : string) -> a */ 
  kk_string_t _x_x68;
  kk_string_t _x_x69;
  kk_string_t _x_x70;
  kk_define_string_literal(static, _s_x71, 13, ": impossible:", _ctx)
  _x_x70 = kk_string_dup(_s_x71, _ctx); /*string*/
  kk_string_t _x_x72;
  if (kk_std_core_types__is_Optional(message, _ctx)) {
    kk_box_t _box_x30 = message._cons._Optional.value;
    kk_string_t _uniq_message_327 = kk_string_unbox(_box_x30);
    kk_string_dup(_uniq_message_327, _ctx);
    kk_std_core_types__optional_drop(message, _ctx);
    _x_x72 = _uniq_message_327; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(message, _ctx);
    kk_define_string_literal(static, _s_x73, 1, "\?", _ctx)
    _x_x72 = kk_string_dup(_s_x73, _ctx); /*string*/
  }
  _x_x69 = kk_std_core_types__lp__plus__plus__rp_(_x_x70, _x_x72, _ctx); /*string*/
  _x_x68 = kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file_line, _x_x69, _ctx); /*string*/
  return kk_std_core_debug_unsafe_abort(_x_x68, _ctx);
}

kk_unit_t kk_std_core_debug_assert(kk_string_t message, bool condition, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* (message : string, condition : bool, ?kk-file-line : string) -> () */ 
  if (condition) {
    kk_string_drop(message, _ctx);
    kk_string_drop(_implicit_fs_kk_file_line, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_string_t _b_x31_32;
    kk_string_t _x_x74;
    kk_string_t _x_x75;
    kk_define_string_literal(static, _s_x76, 20, ": assertion failed: ", _ctx)
    _x_x75 = kk_string_dup(_s_x76, _ctx); /*string*/
    _x_x74 = kk_std_core_types__lp__plus__plus__rp_(_x_x75, message, _ctx); /*string*/
    _b_x31_32 = kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file_line, _x_x74, _ctx); /*string*/
    kk_box_t _x_x77 = kk_std_core_debug_unsafe_abort(_b_x31_32, _ctx); /*318*/
    kk_unit_unbox(_x_x77); return kk_Unit;
  }
}
 
// Explicitly trigger a breakpoint

kk_unit_t kk_std_core_debug_breakpoint(kk_context_t* _ctx) { /* () -> ndet () */ 
  kk_debugger_break(kk_context()); return kk_Unit;
}

// initialization
void kk_std_core_debug__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_console__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core_debug_file_fs_kk_line = kk_integer_from_small(0); /*int*/
  }
  {
    kk_std_core_debug_trace_enabled = kk_ref_alloc((kk_bool_box(true)),kk_context()); /*ref<global,bool>*/
  }
}

// termination
void kk_std_core_debug__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_ref_drop(kk_std_core_debug_trace_enabled, _ctx);
  kk_integer_drop(kk_std_core_debug_file_fs_kk_line, _ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_types__done(_ctx);
}
