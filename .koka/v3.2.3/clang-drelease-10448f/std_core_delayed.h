#pragma once
#ifndef kk_std_core_delayed_H
#define kk_std_core_delayed_H
// Koka generated module: std/core/delayed, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_unsafe.h"

// type declarations

// type std/core/delayed/computation
struct kk_std_core_delayed__computation_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_std_core_delayed__computation;
struct kk_std_core_delayed_XComputation {
  struct kk_std_core_delayed__computation_s _base;
  kk_function_t action;
};
struct kk_std_core_delayed_XDone {
  struct kk_std_core_delayed__computation_s _base;
  kk_box_t value;
};
static inline kk_std_core_delayed__computation kk_std_core_delayed__new_XBlocking(kk_context_t* _ctx) {
  return kk_datatype_from_tag((kk_tag_t)(3));
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__base_XComputation(struct kk_std_core_delayed_XComputation* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__new_XComputation(kk_reuse_t _at, int32_t _cpath, kk_function_t action, kk_context_t* _ctx) {
  struct kk_std_core_delayed_XComputation* _con = kk_block_alloc_at_as(struct kk_std_core_delayed_XComputation, _at, 1 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->action = action;
  return kk_std_core_delayed__base_XComputation(_con, _ctx);
}
static inline struct kk_std_core_delayed_XComputation* kk_std_core_delayed__as_XComputation(kk_std_core_delayed__computation x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_core_delayed_XComputation*, x, (kk_tag_t)(1), _ctx);
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__base_XDone(struct kk_std_core_delayed_XDone* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__new_XDone(kk_reuse_t _at, int32_t _cpath, kk_box_t value, kk_context_t* _ctx) {
  struct kk_std_core_delayed_XDone* _con = kk_block_alloc_at_as(struct kk_std_core_delayed_XDone, _at, 1 /* scan count */, _cpath, (kk_tag_t)(2), _ctx);
  _con->value = value;
  return kk_std_core_delayed__base_XDone(_con, _ctx);
}
static inline struct kk_std_core_delayed_XDone* kk_std_core_delayed__as_XDone(kk_std_core_delayed__computation x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_std_core_delayed_XDone*, x, (kk_tag_t)(2), _ctx);
}
static inline bool kk_std_core_delayed__is_XBlocking(kk_std_core_delayed__computation x, kk_context_t* _ctx) {
  return (kk_datatype_has_singleton_tag(x, (kk_tag_t)(3)));
}
static inline bool kk_std_core_delayed__is_XComputation(kk_std_core_delayed__computation x, kk_context_t* _ctx) {
  return (kk_datatype_has_ptr_tag(x, (kk_tag_t)(1), _ctx));
}
static inline bool kk_std_core_delayed__is_XDone(kk_std_core_delayed__computation x, kk_context_t* _ctx) {
  return (kk_datatype_has_ptr_tag(x, (kk_tag_t)(2), _ctx));
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__computation_dup(kk_std_core_delayed__computation _x, kk_context_t* _ctx) {
  return kk_datatype_dup(_x, _ctx);
}
static inline void kk_std_core_delayed__computation_drop(kk_std_core_delayed__computation _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline kk_box_t kk_std_core_delayed__computation_box(kk_std_core_delayed__computation _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_std_core_delayed__computation kk_std_core_delayed__computation_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type std/core/delayed/delayed
struct kk_std_core_delayed_XDelay {
  kk_ref_t dref;
};
typedef struct kk_std_core_delayed_XDelay kk_std_core_delayed__delayed;
static inline kk_std_core_delayed__delayed kk_std_core_delayed__new_XDelay(kk_ref_t dref, kk_context_t* _ctx) {
  kk_std_core_delayed__delayed _con = { dref };
  return _con;
}
static inline bool kk_std_core_delayed__is_XDelay(kk_std_core_delayed__delayed x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_std_core_delayed__delayed kk_std_core_delayed__delayed_dup(kk_std_core_delayed__delayed _x, kk_context_t* _ctx) {
  kk_ref_dup(_x.dref, _ctx);
  return _x;
}
static inline void kk_std_core_delayed__delayed_drop(kk_std_core_delayed__delayed _x, kk_context_t* _ctx) {
  kk_ref_drop(_x.dref, _ctx);
}
static inline kk_box_t kk_std_core_delayed__delayed_box(kk_std_core_delayed__delayed _x, kk_context_t* _ctx) {
  return kk_ref_box(_x.dref, _ctx);
}
static inline kk_std_core_delayed__delayed kk_std_core_delayed__delayed_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_std_core_delayed__new_XDelay(kk_ref_unbox(_x, _ctx), _ctx);
}

// value declarations
 
// Automatically generated. Tests for the `XComputation` constructor of the `:computation` type.

static inline bool kk_std_core_delayed_is_xcomputation(kk_std_core_delayed__computation computation, kk_context_t* _ctx) { /* forall<a,e> (computation : computation<e,a>) -> bool */ 
  if (kk_std_core_delayed__is_XComputation(computation, _ctx)) {
    struct kk_std_core_delayed_XComputation* _con_x42 = kk_std_core_delayed__as_XComputation(computation, _ctx);
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `XDone` constructor of the `:computation` type.

static inline bool kk_std_core_delayed_is_xdone(kk_std_core_delayed__computation computation, kk_context_t* _ctx) { /* forall<a,e> (computation : computation<e,a>) -> bool */ 
  if (kk_std_core_delayed__is_XDone(computation, _ctx)) {
    struct kk_std_core_delayed_XDone* _con_x43 = kk_std_core_delayed__as_XDone(computation, _ctx);
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `XBlocking` constructor of the `:computation` type.

static inline bool kk_std_core_delayed_is_xblocking(kk_std_core_delayed__computation computation, kk_context_t* _ctx) { /* forall<a,e> (computation : computation<e,a>) -> bool */ 
  if (kk_std_core_delayed__is_XBlocking(computation, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `dref` constructor field of the `:delayed` type.

static inline kk_ref_t kk_std_core_delayed_delayed_fs_dref(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx) { /* forall<e,a> (delayed : delayed<e,a>) -> ref<global,computation<e,a>> */ 
  {
    kk_ref_t _x = delayed.dref;
    return kk_ref_dup(_x, _ctx);
  }
}

kk_std_core_delayed__delayed kk_std_core_delayed_delayed_fs__copy(kk_std_core_delayed__delayed _this, kk_std_core_types__optional dref, kk_context_t* _ctx); /* forall<e,a> (delayed<e,a>, dref : ? (ref<global,computation<e,a>>)) -> delayed<e,a> */ 
 
// Create a new `:delayed` value.

static inline kk_std_core_delayed__delayed kk_std_core_delayed_delay(kk_function_t action, kk_context_t* _ctx) { /* forall<a,e> (action : () -> e a) -> delayed<e,a> */ 
  kk_ref_t r;
  kk_box_t _x_x45;
  kk_std_core_delayed__computation _x_x46 = kk_std_core_delayed__new_XComputation(kk_reuse_null, 0, action, _ctx); /*delayed/computation<5,6>*/
  _x_x45 = kk_std_core_delayed__computation_box(_x_x46, _ctx); /*191*/
  r = kk_ref_alloc(_x_x45,kk_context()); /*ref<global,delayed/computation<319,318>>*/
  return kk_std_core_delayed__new_XDelay(r, _ctx);
}
 
// Create a new `:delayed` value.

static inline kk_std_core_delayed__delayed kk_std_core_delayed_memo(kk_box_t value, kk_context_t* _ctx) { /* forall<a,e> (value : a) -> delayed<e,a> */ 
  kk_ref_t r;
  kk_box_t _x_x47;
  kk_std_core_delayed__computation _x_x48 = kk_std_core_delayed__new_XDone(kk_reuse_null, 0, value, _ctx); /*delayed/computation<5,6>*/
  _x_x47 = kk_std_core_delayed__computation_box(_x_x48, _ctx); /*191*/
  r = kk_ref_alloc(_x_x47,kk_context()); /*ref<global,delayed/computation<383,382>>*/
  return kk_std_core_delayed__new_XDelay(r, _ctx);
}

kk_box_t kk_std_core_delayed_force_fs__mlift_go_10115(kk_ref_t r, kk_box_t x_0, kk_context_t* _ctx); /* forall<a,e> (r : ref<global,computation<e,a>>, x@0 : a) -> <st<global>,div|e> a */ 

kk_box_t kk_std_core_delayed_force_fs_go(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx); /* forall<a,e> (delayed : delayed<e,a>) -> <st<global>,div|e> a */ 

kk_function_t kk_std_core_delayed_unsafe_no_state_div_cast(kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (f : () -> <st<global>,div|e> a) -> (() -> e a) */ 

static inline kk_box_t kk_std_core_delayed_unsafe_no_state_div(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (f : () -> <st<global>,div|e> a) -> e a */ 
  kk_function_t _x_x61 = kk_std_core_delayed_unsafe_no_state_div_cast(f, _ctx); /*() -> 575 574*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x61, (_x_x61, _ctx), _ctx);
}
 
// Force a delayed value; the value is computed only on the first
// call to `force` and cached afterwards.


// lift anonymous function
struct kk_std_core_delayed_force_fun63__t {
  struct kk_function_s _base;
  kk_std_core_delayed__delayed delayed;
};
extern kk_box_t kk_std_core_delayed_force_fun63(kk_function_t _fself, kk_context_t* _ctx);
static inline kk_function_t kk_std_core_delayed_new_force_fun63(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx) {
  struct kk_std_core_delayed_force_fun63__t* _self = kk_function_alloc_as(struct kk_std_core_delayed_force_fun63__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_delayed_force_fun63, kk_context());
  _self->delayed = delayed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_box_t kk_std_core_delayed_force(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx) { /* forall<a,e> (delayed : delayed<e,a>) -> e a */ 
  kk_function_t _x_x62 = kk_std_core_delayed_unsafe_no_state_div_cast(kk_std_core_delayed_new_force_fun63(delayed, _ctx), _ctx); /*() -> 575 574*/
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x62, (_x_x62, _ctx), _ctx);
}

kk_function_t kk_std_core_delayed_once(kk_function_t calc, kk_context_t* _ctx); /* forall<a> (calc : () -> a) -> (() -> a) */ 

void kk_std_core_delayed__init(kk_context_t* _ctx);


void kk_std_core_delayed__done(kk_context_t* _ctx);

#endif // header
