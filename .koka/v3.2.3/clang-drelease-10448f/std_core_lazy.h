#pragma once
#ifndef kk_std_core_lazy_H
#define kk_std_core_lazy_H
// Koka generated module: std/core/lazy, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"

// type declarations

// value declarations

kk_unit_t kk_std_core_lazy_memoize_target(kk_box_t target, kk_integer_t size, kk_integer_t scan_size, kk_context_t* _ctx); /* forall<a> (target : a, size : int, scan-size : int) -> () */ 

kk_box_t kk_std_core_lazy_memoize(kk_box_t target, kk_box_t x, kk_context_t* _ctx); /* forall<a> (target : a, x : a) -> a */ 

extern kk_integer_t kk_std_core_lazy_internal;

void kk_std_core_lazy__init(kk_context_t* _ctx);


void kk_std_core_lazy__done(kk_context_t* _ctx);

#endif // header
