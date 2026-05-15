// Koka generated module: std/core/lazy, koka version: 3.2.3, platform: 64-bit
#include "std_core_lazy.h"
 
// internal: marker for lazy values that will be memoized (used to for correct reuse and reference counting)

kk_unit_t kk_std_core_lazy_memoize_target(kk_box_t target, kk_integer_t size, kk_integer_t scan_size, kk_context_t* _ctx) { /* forall<a> (target : a, size : int, scan-size : int) -> () */ 
  /**/; return kk_Unit;
}
 
// internal: explicitly force update-in-place for lazy values

kk_box_t kk_std_core_lazy_memoize(kk_box_t target, kk_box_t x, kk_context_t* _ctx) { /* forall<a> (target : a, x : a) -> a */ 
  return target;
}

kk_integer_t kk_std_core_lazy_internal;

// initialization
void kk_std_core_lazy__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_std_core_lazy_internal = kk_integer_from_small(42); /*int*/
  }
}

// termination
void kk_std_core_lazy__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_integer_drop(kk_std_core_lazy_internal, _ctx);
  kk_std_core_types__done(_ctx);
}
