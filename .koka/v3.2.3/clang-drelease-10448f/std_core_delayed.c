// Koka generated module: std/core/delayed, koka version: 3.2.3, platform: 64-bit
#include "std_core_delayed.h"

kk_std_core_delayed__delayed kk_std_core_delayed_delayed_fs__copy(kk_std_core_delayed__delayed _this, kk_std_core_types__optional dref, kk_context_t* _ctx) { /* forall<e,a> (delayed<e,a>, dref : ? (ref<global,computation<e,a>>)) -> delayed<e,a> */ 
  kk_ref_t _x_x44;
  if (kk_std_core_types__is_Optional(dref, _ctx)) {
    kk_box_t _box_x0 = dref._cons._Optional.value;
    kk_ref_t _uniq_dref_232 = kk_ref_unbox(_box_x0, _ctx);
    kk_ref_dup(_uniq_dref_232, _ctx);
    kk_std_core_types__optional_drop(dref, _ctx);
    kk_std_core_delayed__delayed_drop(_this, _ctx);
    _x_x44 = _uniq_dref_232; /*ref<global,delayed/computation<254,255>>*/
  }
  else {
    kk_std_core_types__optional_drop(dref, _ctx);
    {
      kk_ref_t _x = _this.dref;
      _x_x44 = _x; /*ref<global,delayed/computation<254,255>>*/
    }
  }
  return kk_std_core_delayed__new_XDelay(_x_x44, _ctx);
}
 
// monadic lift

kk_box_t kk_std_core_delayed_force_fs__mlift_go_10115(kk_ref_t r, kk_box_t x_0, kk_context_t* _ctx) { /* forall<a,e> (r : ref<global,computation<e,a>>, x@0 : a) -> <st<global>,div|e> a */ 
  kk_unit_t ___0 = kk_Unit;
  kk_unit_t _brw_x39 = kk_Unit;
  kk_box_t _x_x49;
  kk_std_core_delayed__computation _x_x50;
  kk_box_t _x_x51 = kk_box_dup(x_0, _ctx); /*543*/
  _x_x50 = kk_std_core_delayed__new_XDone(kk_reuse_null, 0, _x_x51, _ctx); /*delayed/computation<5,6>*/
  _x_x49 = kk_std_core_delayed__computation_box(_x_x50, _ctx); /*199*/
  kk_ref_set_borrow(r,_x_x49,kk_context());
  kk_ref_drop(r, _ctx);
  _brw_x39;
  return x_0;
}


// lift anonymous function
struct kk_std_core_delayed_force_fs_go_fun56__t {
  struct kk_function_s _base;
  kk_std_core_delayed__delayed delayed;
};
static kk_box_t kk_std_core_delayed_force_fs_go_fun56(kk_function_t _fself, kk_box_t x_0_0, kk_context_t* _ctx);
static kk_function_t kk_std_core_delayed_force_fs_new_go_fun56(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx) {
  struct kk_std_core_delayed_force_fs_go_fun56__t* _self = kk_function_alloc_as(struct kk_std_core_delayed_force_fs_go_fun56__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_delayed_force_fs_go_fun56, kk_context());
  _self->delayed = delayed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_delayed_force_fs_go_fun56(kk_function_t _fself, kk_box_t x_0_0, kk_context_t* _ctx) {
  struct kk_std_core_delayed_force_fs_go_fun56__t* _self = kk_function_as(struct kk_std_core_delayed_force_fs_go_fun56__t*, _fself, _ctx);
  kk_std_core_delayed__delayed delayed = _self->delayed; /* delayed/delayed<544,543> */
  kk_drop_match(_self, {kk_std_core_delayed__delayed_dup(delayed, _ctx);}, {}, _ctx)
  kk_ref_t _x_x57;
  {
    kk_ref_t _x_1 = delayed.dref;
    _x_x57 = _x_1; /*ref<global,delayed/computation<544,543>>*/
  }
  return kk_std_core_delayed_force_fs__mlift_go_10115(_x_x57, x_0_0, _ctx);
}

kk_box_t kk_std_core_delayed_force_fs_go(kk_std_core_delayed__delayed delayed, kk_context_t* _ctx) { /* forall<a,e> (delayed : delayed<e,a>) -> <st<global>,div|e> a */ 
  kk__tailcall: ;
  kk_std_core_delayed__computation _match_x33;
  kk_box_t _x_x52;
  kk_ref_t _x_x53;
  {
    kk_ref_t _x = delayed.dref;
    kk_ref_dup(_x, _ctx);
    _x_x53 = _x; /*ref<global,delayed/computation<544,543>>*/
  }
  _x_x52 = kk_ref_get(_x_x53,kk_context()); /*212*/
  _match_x33 = kk_std_core_delayed__computation_unbox(_x_x52, KK_OWNED, _ctx); /*delayed/computation<544,543>*/
  if (kk_std_core_delayed__is_XDone(_match_x33, _ctx)) {
    struct kk_std_core_delayed_XDone* _con_x54 = kk_std_core_delayed__as_XDone(_match_x33, _ctx);
    kk_box_t x = _con_x54->value;
    kk_std_core_delayed__delayed_drop(delayed, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_match_x33, _ctx)) {
      kk_datatype_ptr_free(_match_x33, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(_match_x33, _ctx);
    }
    return x;
  }
  if (kk_std_core_delayed__is_XBlocking(_match_x33, _ctx)) { // tailcall
                                                             goto kk__tailcall;
  }
  {
    struct kk_std_core_delayed_XComputation* _con_x55 = kk_std_core_delayed__as_XComputation(_match_x33, _ctx);
    kk_function_t action = _con_x55->action;
    kk_reuse_t _ru_x41 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x33, _ctx)) {
      _ru_x41 = (kk_datatype_ptr_reuse(_match_x33, _ctx));
    }
    else {
      kk_function_dup(action, _ctx);
      kk_datatype_ptr_decref(_match_x33, _ctx);
    }
    kk_unit_t __ = kk_Unit;
    kk_ref_t _brw_x37;
    {
      kk_ref_t _x_0 = delayed.dref;
      kk_ref_dup(_x_0, _ctx);
      _brw_x37 = _x_0; /*ref<global,delayed/computation<544,543>>*/
    }
    kk_unit_t _brw_x38 = kk_Unit;
    kk_ref_set_borrow(_brw_x37,(kk_std_core_delayed__computation_box(kk_std_core_delayed__new_XBlocking(_ctx), _ctx)),kk_context());
    kk_ref_drop(_brw_x37, _ctx);
    _brw_x38;
    kk_box_t x_1_10116 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), action, (action, _ctx), _ctx); /*543*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x41,kk_context());
      kk_box_drop(x_1_10116, _ctx);
      return kk_std_core_hnd_yield_extend(kk_std_core_delayed_force_fs_new_go_fun56(delayed, _ctx), _ctx);
    }
    {
      kk_unit_t ___0_0 = kk_Unit;
      kk_ref_t _brw_x35;
      {
        kk_ref_t _x_2 = delayed.dref;
        _brw_x35 = _x_2; /*ref<global,delayed/computation<544,543>>*/
      }
      kk_unit_t _brw_x36 = kk_Unit;
      kk_box_t _x_x58;
      kk_std_core_delayed__computation _x_x59;
      kk_box_t _x_x60 = kk_box_dup(x_1_10116, _ctx); /*543*/
      _x_x59 = kk_std_core_delayed__new_XDone(_ru_x41, 0, _x_x60, _ctx); /*delayed/computation<5,6>*/
      _x_x58 = kk_std_core_delayed__computation_box(_x_x59, _ctx); /*199*/
      kk_ref_set_borrow(_brw_x35,_x_x58,kk_context());
      kk_ref_drop(_brw_x35, _ctx);
      _brw_x36;
      return x_1_10116;
    }
  }
}

kk_function_t kk_std_core_delayed_unsafe_no_state_div_cast(kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (f : () -> <st<global>,div|e> a) -> (() -> e a) */ 
  return f;
}
extern kk_box_t kk_std_core_delayed_force_fun63(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_delayed_force_fun63__t* _self = kk_function_as(struct kk_std_core_delayed_force_fun63__t*, _fself, _ctx);
  kk_std_core_delayed__delayed delayed = _self->delayed; /* delayed/delayed<644,643> */
  kk_drop_match(_self, {kk_std_core_delayed__delayed_dup(delayed, _ctx);}, {}, _ctx)
  return kk_std_core_delayed_force_fs_go(delayed, _ctx);
}
 
// Given a total function to calculate a value `:a`, return
// a total function that only calculates the value once and then
// returns the cached result.


// lift anonymous function
struct kk_std_core_delayed_once_fun64__t {
  struct kk_function_s _base;
  kk_function_t calc;
  kk_ref_t r;
};
static kk_box_t kk_std_core_delayed_once_fun64(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_core_delayed_new_once_fun64(kk_function_t calc, kk_ref_t r, kk_context_t* _ctx) {
  struct kk_std_core_delayed_once_fun64__t* _self = kk_function_alloc_as(struct kk_std_core_delayed_once_fun64__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_delayed_once_fun64, kk_context());
  _self->calc = calc;
  _self->r = r;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_delayed_once_fun64(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_core_delayed_once_fun64__t* _self = kk_function_as(struct kk_std_core_delayed_once_fun64__t*, _fself, _ctx);
  kk_function_t calc = _self->calc; /* () -> 756 */
  kk_ref_t r = _self->r; /* ref<_670,maybe<756>> */
  kk_drop_match(_self, {kk_function_dup(calc, _ctx);kk_ref_dup(r, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x31;
  kk_box_t _x_x65;
  kk_ref_t _x_x66 = kk_ref_dup(r, _ctx); /*ref<_670,maybe<756>>*/
  _x_x65 = kk_ref_get(_x_x66,kk_context()); /*212*/
  _match_x31 = kk_std_core_types__maybe_unbox(_x_x65, KK_OWNED, _ctx); /*maybe<756>*/
  if (kk_std_core_types__is_Just(_match_x31, _ctx)) {
    kk_box_t x = _match_x31._cons.Just.value;
    kk_ref_drop(r, _ctx);
    kk_function_drop(calc, _ctx);
    return x;
  }
  {
    kk_box_t x_0 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), calc, (calc, _ctx), _ctx); /*756*/;
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x32 = kk_Unit;
    kk_box_t _x_x67;
    kk_std_core_types__maybe _x_x68;
    kk_box_t _x_x69 = kk_box_dup(x_0, _ctx); /*756*/
    _x_x68 = kk_std_core_types__new_Just(_x_x69, _ctx); /*maybe<88>*/
    _x_x67 = kk_std_core_types__maybe_box(_x_x68, _ctx); /*199*/
    kk_ref_set_borrow(r,_x_x67,kk_context());
    kk_ref_drop(r, _ctx);
    _brw_x32;
    return x_0;
  }
}

kk_function_t kk_std_core_delayed_once(kk_function_t calc, kk_context_t* _ctx) { /* forall<a> (calc : () -> a) -> (() -> a) */ 
  kk_ref_t r = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<_670,maybe<756>>*/;
  return kk_std_core_delayed_new_once_fun64(calc, r, _ctx);
}

// initialization
void kk_std_core_delayed__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_delayed__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
