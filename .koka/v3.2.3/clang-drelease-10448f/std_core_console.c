// Koka generated module: std/core/console, koka version: 3.2.3, platform: 64-bit
#include "std_core_console.h"

kk_ref_t kk_std_core_console_redirect;
 
// Redirect `print` and `println` calls to a specified function.


// lift anonymous function
struct kk_std_core_console_print_redirect_fun45__t {
  struct kk_function_s _base;
  kk_function_t print;
};
static kk_box_t kk_std_core_console_print_redirect_fun45(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_console_new_print_redirect_fun45(kk_function_t print, kk_context_t* _ctx) {
  struct kk_std_core_console_print_redirect_fun45__t* _self = kk_function_alloc_as(struct kk_std_core_console_print_redirect_fun45__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_console_print_redirect_fun45, kk_context());
  _self->print = print;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_console_print_redirect_fun45(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_console_print_redirect_fun45__t* _self = kk_function_as(struct kk_std_core_console_print_redirect_fun45__t*, _fself, _ctx);
  kk_function_t print = _self->print; /* (msg : string) -> console/console () */
  kk_drop_match(_self, {kk_function_dup(print, _ctx);}, {}, _ctx)
  kk_unit_t _x_x46 = kk_Unit;
  kk_string_t _x_x47 = kk_string_unbox(_b_x5); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_context_t*), print, (print, _x_x47, _ctx), _ctx);
  return kk_unit_box(_x_x46);
}

kk_unit_t kk_std_core_console_print_redirect(kk_function_t print, kk_context_t* _ctx) { /* (print : (msg : string) -> console ()) -> <st<global>,console,ndet> () */ 
  kk_box_t _x_x43;
  kk_std_core_types__maybe _x_x44 = kk_std_core_types__new_Just(kk_function_box(kk_std_core_console_new_print_redirect_fun45(print, _ctx), _ctx), _ctx); /*maybe<88>*/
  _x_x43 = kk_std_core_types__maybe_box(_x_x44, _ctx); /*199*/
  kk_ref_set_borrow(kk_std_core_console_redirect,_x_x43,kk_context()); return kk_Unit;
}
 
// Print a string to the console, including a final newline character.

kk_unit_t kk_std_core_console_xprintsln(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_println(s,kk_context()); return kk_Unit;
}
 
// Print a string to the console

kk_unit_t kk_std_core_console_xprints(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_print(s,kk_context()); return kk_Unit;
}

kk_unit_t kk_std_core_console_prints(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_types__maybe _match_x42;
  kk_box_t _x_x48;
  kk_ref_t _x_x49 = kk_ref_dup(kk_std_core_console_redirect, _ctx); /*ref<global,maybe<(string) -> console/console ()>>*/
  _x_x48 = kk_ref_get(_x_x49,kk_context()); /*212*/
  _match_x42 = kk_std_core_types__maybe_unbox(_x_x48, KK_OWNED, _ctx); /*maybe<(string) -> console/console ()>*/
  if (kk_std_core_types__is_Nothing(_match_x42, _ctx)) {
    kk_std_core_console_xprints(s, _ctx); return kk_Unit;
  }
  {
    kk_box_t _fun_unbox_x16 = _match_x42._cons.Just.value;
    kk_box_t _x_x50;
    kk_function_t _x_x51 = kk_function_unbox(_fun_unbox_x16, _ctx); /*(17) -> console/console 18*/
    _x_x50 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x51, (_x_x51, kk_string_box(s), _ctx), _ctx); /*18*/
    kk_unit_unbox(_x_x50); return kk_Unit;
  }
}

kk_unit_t kk_std_core_console_printsln(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> console () */ 
  kk_std_core_types__maybe _match_x41;
  kk_box_t _x_x52;
  kk_ref_t _x_x53 = kk_ref_dup(kk_std_core_console_redirect, _ctx); /*ref<global,maybe<(string) -> console/console ()>>*/
  _x_x52 = kk_ref_get(_x_x53,kk_context()); /*212*/
  _match_x41 = kk_std_core_types__maybe_unbox(_x_x52, KK_OWNED, _ctx); /*maybe<(string) -> console/console ()>*/
  if (kk_std_core_types__is_Nothing(_match_x41, _ctx)) {
    kk_std_core_console_xprintsln(s, _ctx); return kk_Unit;
  }
  {
    kk_box_t _fun_unbox_x27 = _match_x41._cons.Just.value;
    kk_string_t _b_x30;
    kk_string_t _x_x54;
    kk_define_string_literal(static, _s_x55, 1, "\n", _ctx)
    _x_x54 = kk_string_dup(_s_x55, _ctx); /*string*/
    _b_x30 = kk_std_core_types__lp__plus__plus__rp_(s, _x_x54, _ctx); /*string*/
    kk_box_t _x_x56;
    kk_function_t _x_x57 = kk_function_unbox(_fun_unbox_x27, _ctx); /*(28) -> console/console 29*/
    _x_x56 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x57, (_x_x57, kk_string_box(_b_x30), _ctx), _ctx); /*29*/
    kk_unit_unbox(_x_x56); return kk_Unit;
  }
}
 
// Print a value that has a `show` function


// lift anonymous function
struct kk_std_core_console_default_fs_show_fs_print_fun59__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_console_default_fs_show_fs_print_fun59(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_std_core_console_default_fs_show_fs_new_print_fun59(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_console_default_fs_show_fs_print_fun59, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_console_default_fs_show_fs_print_fun59(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x60 = kk_Unit;
  kk_string_t _x_x61 = kk_string_unbox(_b_x34); /*string*/
  kk_std_core_console_prints(_x_x61, _ctx);
  return kk_unit_box(_x_x60);
}

kk_unit_t kk_std_core_console_default_fs_show_fs_print(kk_box_t x, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (x : a, ?show : (a) -> <console|e> string) -> <console|e> () */ 
  kk_string_t x_0_10103 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, x, _ctx), _ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10103, _ctx);
    kk_box_t _x_x58 = kk_std_core_hnd_yield_extend(kk_std_core_console_default_fs_show_fs_new_print_fun59(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x58); return kk_Unit;
  }
  {
    kk_std_core_console_prints(x_0_10103, _ctx); return kk_Unit;
  }
}
 
// Print a value that has a `show` function, including a final newline character.


// lift anonymous function
struct kk_std_core_console_default_fs_show_fs_println_fun63__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_console_default_fs_show_fs_println_fun63(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_console_default_fs_show_fs_new_println_fun63(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_console_default_fs_show_fs_println_fun63, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_console_default_fs_show_fs_println_fun63(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x64 = kk_Unit;
  kk_string_t _x_x65 = kk_string_unbox(_b_x37); /*string*/
  kk_std_core_console_printsln(_x_x65, _ctx);
  return kk_unit_box(_x_x64);
}

kk_unit_t kk_std_core_console_default_fs_show_fs_println(kk_box_t x, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (x : a, ?show : (a) -> <console|e> string) -> <console|e> () */ 
  kk_string_t x_0_10105 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, x, _ctx), _ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10105, _ctx);
    kk_box_t _x_x62 = kk_std_core_hnd_yield_extend(kk_std_core_console_default_fs_show_fs_new_println_fun63(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x62); return kk_Unit;
  }
  {
    kk_std_core_console_printsln(x_0_10105, _ctx); return kk_Unit;
  }
}

// initialization
void kk_std_core_console__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_show__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core_console_redirect = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<global,maybe<(string) -> console/console ()>>*/
  }
}

// termination
void kk_std_core_console__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_ref_drop(kk_std_core_console_redirect, _ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_types__done(_ctx);
}
