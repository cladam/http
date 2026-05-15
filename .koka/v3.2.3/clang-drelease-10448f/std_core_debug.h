#pragma once
#ifndef kk_std_core_debug_H
#define kk_std_core_debug_H
// Koka generated module: std/core/debug, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_int.h"
#include "std_core_unsafe.h"
#include "std_core_hnd.h"
#include "std_core_string.h"
#include "std_core_console.h"

// type declarations

// value declarations
 
// Compilation constant that is replaced with the current file's module name

extern kk_string_t kk_std_core_debug_file_fs_kk_module;
 
// Compilation constant that is replaced with the current line number

extern kk_integer_t kk_std_core_debug_file_fs_kk_line;
 
// Compilation constant that is replaced with the current file name

extern kk_string_t kk_std_core_debug_file_fs_kk_file;

static inline kk_string_t kk_std_core_debug_file_fs_kk_file_line(kk_string_t _implicit_fs_kk_file, kk_integer_t _implicit_fs_kk_line, kk_context_t* _ctx) { /* (?kk-file : string, ?kk-line : int) -> string */ 
  kk_string_t _x_x39;
  kk_string_t _x_x40;
  kk_define_string_literal(static, _s_x41, 1, "(", _ctx)
  _x_x40 = kk_string_dup(_s_x41, _ctx); /*string*/
  kk_string_t _x_x42;
  kk_string_t _x_x43 = kk_std_core_int_show(_implicit_fs_kk_line, _ctx); /*string*/
  kk_string_t _x_x44;
  kk_define_string_literal(static, _s_x45, 1, ")", _ctx)
  _x_x44 = kk_string_dup(_s_x45, _ctx); /*string*/
  _x_x42 = kk_std_core_types__lp__plus__plus__rp_(_x_x43, _x_x44, _ctx); /*string*/
  _x_x39 = kk_std_core_types__lp__plus__plus__rp_(_x_x40, _x_x42, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_implicit_fs_kk_file, _x_x39, _ctx);
}

kk_unit_t kk_std_core_debug_xtrace(kk_string_t message, kk_context_t* _ctx); /* (message : string) -> () */ 

kk_unit_t kk_std_core_debug_xtrace_any(kk_string_t message, kk_box_t x, kk_context_t* _ctx); /* forall<a> (message : string, x : a) -> () */ 

extern kk_ref_t kk_std_core_debug_trace_enabled;

kk_unit_t kk_std_core_debug_trace(kk_string_t message, kk_context_t* _ctx); /* (message : string) -> () */ 

kk_unit_t kk_std_core_debug_trace_info(kk_string_t message, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx); /* (message : string, ?kk-file-line : string) -> () */ 

kk_unit_t kk_std_core_debug__mlift_trace_show_10115(kk_string_t _implicit_fs_kk_file_line, kk_string_t _y_x10111, kk_context_t* _ctx); /* forall<_e,e1> (?kk-file-line : string, string) -> e1 () */ 

kk_unit_t kk_std_core_debug_trace_show(kk_box_t x, kk_function_t _implicit_fs_show, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx); /* forall<a,e> (x : a, ?show : (a) -> e string, ?kk-file-line : string) -> e () */ 

kk_unit_t kk_std_core_debug_trace_any(kk_string_t message, kk_box_t x, kk_context_t* _ctx); /* forall<a> (message : string, x : a) -> () */ 

kk_unit_t kk_std_core_debug_notrace(kk_context_t* _ctx); /* () -> (st<global>) () */ 

kk_box_t kk_std_core_debug_unsafe_abort(kk_string_t msg, kk_context_t* _ctx); /* forall<a> (msg : string) -> a */ 

kk_box_t kk_std_core_debug_impossible(kk_std_core_types__optional message, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx); /* forall<a> (message : ? string, ?kk-file-line : string) -> a */ 

kk_unit_t kk_std_core_debug_assert(kk_string_t message, bool condition, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx); /* (message : string, condition : bool, ?kk-file-line : string) -> () */ 

kk_unit_t kk_std_core_debug_breakpoint(kk_context_t* _ctx); /* () -> ndet () */ 

void kk_std_core_debug__init(kk_context_t* _ctx);


void kk_std_core_debug__done(kk_context_t* _ctx);

#endif // header
