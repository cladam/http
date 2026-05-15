// Koka generated module: std/core/tuple, koka version: 3.2.3, platform: 64-bit
#include "std_core_tuple.h"
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789__t {
  struct kk_function_s _base;
  kk_box_t _y_x10100;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_map_10254_fun789(kk_box_t _y_x10100, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789, kk_context());
  _self->_y_x10100 = _y_x10100;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789(kk_function_t _fself, kk_box_t _b_x1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_map_10254_fun789__t*, _fself, _ctx);
  kk_box_t _y_x10100 = _self->_y_x10100; /* 537 */
  kk_drop_match(_self, {kk_box_dup(_y_x10100, _ctx);}, {}, _ctx)
  kk_box_t _y_x10101_3 = _b_x1; /*537*/;
  kk_std_core_types__tuple2 _x_x790 = kk_std_core_types__new_Tuple2(_y_x10100, _y_x10101_3, _ctx); /*(134, 135)*/
  return kk_std_core_types__tuple2_box(_x_x790, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs__mlift_map_10254(kk_function_t f, kk_std_core_types__tuple2 t, kk_box_t _y_x10100, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a), b) -> e (b, b) */ 
  kk_box_t x_10315;
  kk_box_t _x_x787;
  {
    kk_box_t _x_0 = t.snd;
    kk_box_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(t, _ctx);
    _x_x787 = _x_0; /*536*/
  }
  x_10315 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x787, _ctx), _ctx); /*537*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10315, _ctx);
    kk_box_t _x_x788 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__new_mlift_map_10254_fun789(_y_x10100, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x788, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple2(_y_x10100, x_10315, _ctx);
  }
}
 
// Map a function over a tuple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_map_fun794__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple2 t;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun794(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_map_fun794(kk_function_t f, kk_std_core_types__tuple2 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun794__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_map_fun794__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_map_fun794, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun794(kk_function_t _fself, kk_box_t _b_x5, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun794__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_map_fun794__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (536) -> 538 537 */
  kk_std_core_types__tuple2 t = _self->t; /* (536, 536) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple2_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10100_10 = _b_x5; /*537*/;
  kk_std_core_types__tuple2 _x_x795 = kk_std_core_tuple_tuple2_fs__mlift_map_10254(f, t, _y_x10100_10, _ctx); /*(537, 537)*/
  return kk_std_core_types__tuple2_box(_x_x795, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_map_fun798__t {
  struct kk_function_s _base;
  kk_box_t x_10319;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun798(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_map_fun798(kk_box_t x_10319, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun798__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_map_fun798__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_map_fun798, kk_context());
  _self->x_10319 = x_10319;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_map_fun798(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_map_fun798__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_map_fun798__t*, _fself, _ctx);
  kk_box_t x_10319 = _self->x_10319; /* 537 */
  kk_drop_match(_self, {kk_box_dup(x_10319, _ctx);}, {}, _ctx)
  kk_box_t _y_x10101_11 = _b_x7; /*537*/;
  kk_std_core_types__tuple2 _x_x799 = kk_std_core_types__new_Tuple2(x_10319, _y_x10101_11, _ctx); /*(134, 135)*/
  return kk_std_core_types__tuple2_box(_x_x799, _ctx);
}

kk_std_core_types__tuple2 kk_std_core_tuple_tuple2_fs_map(kk_std_core_types__tuple2 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a), f : (a) -> e b) -> e (b, b) */ 
  kk_box_t x_10319;
  kk_function_t _x_x792 = kk_function_dup(f, _ctx); /*(536) -> 538 537*/
  kk_box_t _x_x791;
  {
    kk_box_t _x = t.fst;
    kk_box_dup(_x, _ctx);
    _x_x791 = _x; /*536*/
  }
  x_10319 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x792, (_x_x792, _x_x791, _ctx), _ctx); /*537*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10319, _ctx);
    kk_box_t _x_x793 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_map_fun794(f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple2_unbox(_x_x793, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10322;
    kk_box_t _x_x796;
    {
      kk_box_t _x_0 = t.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(t, _ctx);
      _x_x796 = _x_0; /*536*/
    }
    x_0_10322 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x796, _ctx), _ctx); /*537*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10322, _ctx);
      kk_box_t _x_x797 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_map_fun798(x_10319, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple2_unbox(_x_x797, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Tuple2(x_10319, x_0_10322, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802__t {
  struct kk_function_s _base;
  kk_box_t _y_x10102;
  kk_box_t _y_x10103;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_map_10256_fun802(kk_box_t _y_x10102, kk_box_t _y_x10103, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802, kk_context());
  _self->_y_x10102 = _y_x10102;
  _self->_y_x10103 = _y_x10103;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802(kk_function_t _fself, kk_box_t _b_x13, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10256_fun802__t*, _fself, _ctx);
  kk_box_t _y_x10102 = _self->_y_x10102; /* 697 */
  kk_box_t _y_x10103 = _self->_y_x10103; /* 697 */
  kk_drop_match(_self, {kk_box_dup(_y_x10102, _ctx);kk_box_dup(_y_x10103, _ctx);}, {}, _ctx)
  kk_box_t _y_x10104_15 = _b_x13; /*697*/;
  kk_std_core_types__tuple3 _x_x803 = kk_std_core_types__new_Tuple3(_y_x10102, _y_x10103, _y_x10104_15, _ctx); /*(141, 142, 143)*/
  return kk_std_core_types__tuple3_box(_x_x803, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10256(kk_box_t _y_x10102, kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10103, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_10327;
  kk_box_t _x_x800;
  {
    kk_box_t _x_1 = t.thd;
    kk_box_dup(_x_1, _ctx);
    kk_std_core_types__tuple3_drop(t, _ctx);
    _x_x800 = _x_1; /*696*/
  }
  x_10327 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x800, _ctx), _ctx); /*697*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10327, _ctx);
    kk_box_t _x_x801 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_map_10256_fun802(_y_x10102, _y_x10103, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple3_unbox(_x_x801, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple3(_y_x10102, _y_x10103, x_10327, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807__t {
  struct kk_function_s _base;
  kk_box_t _y_x10102;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_map_10257_fun807(kk_box_t _y_x10102, kk_function_t f, kk_std_core_types__tuple3 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807, kk_context());
  _self->_y_x10102 = _y_x10102;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807(kk_function_t _fself, kk_box_t _b_x17, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_map_10257_fun807__t*, _fself, _ctx);
  kk_box_t _y_x10102 = _self->_y_x10102; /* 697 */
  kk_function_t f = _self->f; /* (696) -> 698 697 */
  kk_std_core_types__tuple3 t = _self->t; /* (696, 696, 696) */
  kk_drop_match(_self, {kk_box_dup(_y_x10102, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10103_19 = _b_x17; /*697*/;
  kk_std_core_types__tuple3 _x_x808 = kk_std_core_tuple_tuple3_fs__mlift_map_10256(_y_x10102, f, t, _y_x10103_19, _ctx); /*(697, 697, 697)*/
  return kk_std_core_types__tuple3_box(_x_x808, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs__mlift_map_10257(kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t _y_x10102, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a), b) -> e (b, b, b) */ 
  kk_box_t x_10332;
  kk_function_t _x_x805 = kk_function_dup(f, _ctx); /*(696) -> 698 697*/
  kk_box_t _x_x804;
  {
    kk_box_t _x_0 = t.snd;
    kk_box_dup(_x_0, _ctx);
    _x_x804 = _x_0; /*696*/
  }
  x_10332 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x805, (_x_x805, _x_x804, _ctx), _ctx); /*697*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10332, _ctx);
    kk_box_t _x_x806 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_map_10257_fun807(_y_x10102, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple3_unbox(_x_x806, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_map_10256(_y_x10102, f, t, x_10332, _ctx);
  }
}
 
// Map a function over a triple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun812__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun812(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun812(kk_function_t f, kk_std_core_types__tuple3 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun812__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun812__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun812, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun812(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun812__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun812__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (696) -> 698 697 */
  kk_std_core_types__tuple3 t = _self->t; /* (696, 696, 696) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10102_29 = _b_x21; /*697*/;
  kk_std_core_types__tuple3 _x_x813 = kk_std_core_tuple_tuple3_fs__mlift_map_10257(f, t, _y_x10102_29, _ctx); /*(697, 697, 697)*/
  return kk_std_core_types__tuple3_box(_x_x813, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun817__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple3 t;
  kk_box_t x_10334;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun817(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun817(kk_function_t f, kk_std_core_types__tuple3 t, kk_box_t x_10334, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun817__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun817__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun817, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_10334 = x_10334;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun817(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun817__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun817__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (696) -> 698 697 */
  kk_std_core_types__tuple3 t = _self->t; /* (696, 696, 696) */
  kk_box_t x_10334 = _self->x_10334; /* 697 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple3_dup(t, _ctx);kk_box_dup(x_10334, _ctx);}, {}, _ctx)
  kk_box_t _y_x10103_30 = _b_x23; /*697*/;
  kk_std_core_types__tuple3 _x_x818 = kk_std_core_tuple_tuple3_fs__mlift_map_10256(x_10334, f, t, _y_x10103_30, _ctx); /*(697, 697, 697)*/
  return kk_std_core_types__tuple3_box(_x_x818, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_map_fun821__t {
  struct kk_function_s _base;
  kk_box_t x_0_10337;
  kk_box_t x_10334;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun821(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_map_fun821(kk_box_t x_0_10337, kk_box_t x_10334, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun821__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_map_fun821__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_map_fun821, kk_context());
  _self->x_0_10337 = x_0_10337;
  _self->x_10334 = x_10334;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_map_fun821(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_map_fun821__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_map_fun821__t*, _fself, _ctx);
  kk_box_t x_0_10337 = _self->x_0_10337; /* 697 */
  kk_box_t x_10334 = _self->x_10334; /* 697 */
  kk_drop_match(_self, {kk_box_dup(x_0_10337, _ctx);kk_box_dup(x_10334, _ctx);}, {}, _ctx)
  kk_box_t _y_x10104_31 = _b_x25; /*697*/;
  kk_std_core_types__tuple3 _x_x822 = kk_std_core_types__new_Tuple3(x_10334, x_0_10337, _y_x10104_31, _ctx); /*(141, 142, 143)*/
  return kk_std_core_types__tuple3_box(_x_x822, _ctx);
}

kk_std_core_types__tuple3 kk_std_core_tuple_tuple3_fs_map(kk_std_core_types__tuple3 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a), f : (a) -> e b) -> e (b, b, b) */ 
  kk_box_t x_10334;
  kk_function_t _x_x810 = kk_function_dup(f, _ctx); /*(696) -> 698 697*/
  kk_box_t _x_x809;
  {
    kk_box_t _x = t.fst;
    kk_box_dup(_x, _ctx);
    _x_x809 = _x; /*696*/
  }
  x_10334 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x810, (_x_x810, _x_x809, _ctx), _ctx); /*697*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10334, _ctx);
    kk_box_t _x_x811 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun812(f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple3_unbox(_x_x811, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10337;
    kk_function_t _x_x815 = kk_function_dup(f, _ctx); /*(696) -> 698 697*/
    kk_box_t _x_x814;
    {
      kk_box_t _x_0 = t.snd;
      kk_box_dup(_x_0, _ctx);
      _x_x814 = _x_0; /*696*/
    }
    x_0_10337 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x815, (_x_x815, _x_x814, _ctx), _ctx); /*697*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10337, _ctx);
      kk_box_t _x_x816 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun817(f, t, x_10334, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple3_unbox(_x_x816, KK_OWNED, _ctx);
    }
    {
      kk_box_t x_1_10340;
      kk_box_t _x_x819;
      {
        kk_box_t _x_1 = t.thd;
        kk_box_dup(_x_1, _ctx);
        kk_std_core_types__tuple3_drop(t, _ctx);
        _x_x819 = _x_1; /*696*/
      }
      x_1_10340 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x819, _ctx), _ctx); /*697*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x_1_10340, _ctx);
        kk_box_t _x_x820 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_map_fun821(x_0_10337, x_10334, _ctx), _ctx); /*2419*/
        return kk_std_core_types__tuple3_unbox(_x_x820, KK_OWNED, _ctx);
      }
      {
        return kk_std_core_types__new_Tuple3(x_10334, x_0_10337, x_1_10340, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_box_t _y_x10106;
  kk_box_t _y_x10107;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10259_fun826(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_box_t _y_x10107, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->_y_x10106 = _y_x10106;
  _self->_y_x10107 = _y_x10107;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10259_fun826__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 903 */
  kk_box_t _y_x10106 = _self->_y_x10106; /* 903 */
  kk_box_t _y_x10107 = _self->_y_x10107; /* 903 */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_box_dup(_y_x10106, _ctx);kk_box_dup(_y_x10107, _ctx);}, {}, _ctx)
  kk_box_t _y_x10108_35 = _b_x33; /*903*/;
  kk_std_core_types__tuple4 _x_x827 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _y_x10105, _y_x10106, _y_x10107, _y_x10108_35, _ctx); /*(150, 151, 152, 153)*/
  return kk_std_core_types__tuple4_box(_x_x827, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10259(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10107, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10346;
  kk_box_t _x_x823;
  {
    struct kk_std_core_types_Tuple4* _con_x824 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _pat_0_2 = _con_x824->fst;
    kk_box_t _pat_1_2 = _con_x824->snd;
    kk_box_t _pat_2_2 = _con_x824->thd;
    kk_box_t _x_2 = _con_x824->field4;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_box_drop(_pat_2_2, _ctx);
      kk_box_drop(_pat_1_2, _ctx);
      kk_box_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_box_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x823 = _x_2; /*902*/
  }
  x_10346 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x823, _ctx), _ctx); /*903*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10346, _ctx);
    kk_box_t _x_x825 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10259_fun826(_y_x10105, _y_x10106, _y_x10107, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple4_unbox(_x_x825, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _y_x10105, _y_x10106, _y_x10107, x_10346, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_box_t _y_x10106;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10260_fun832(kk_box_t _y_x10105, kk_box_t _y_x10106, kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->_y_x10106 = _y_x10106;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10260_fun832__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 903 */
  kk_box_t _y_x10106 = _self->_y_x10106; /* 903 */
  kk_function_t f = _self->f; /* (902) -> 904 903 */
  kk_std_core_types__tuple4 t = _self->t; /* (902, 902, 902, 902) */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_box_dup(_y_x10106, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10107_39 = _b_x37; /*903*/;
  kk_std_core_types__tuple4 _x_x833 = kk_std_core_tuple_tuple4_fs__mlift_map_10259(_y_x10105, _y_x10106, f, t, _y_x10107_39, _ctx); /*(903, 903, 903, 903)*/
  return kk_std_core_types__tuple4_box(_x_x833, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10260(kk_box_t _y_x10105, kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10106, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10352;
  kk_function_t _x_x830 = kk_function_dup(f, _ctx); /*(902) -> 904 903*/
  kk_box_t _x_x828;
  {
    struct kk_std_core_types_Tuple4* _con_x829 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x_1 = _con_x829->thd;
    kk_box_dup(_x_1, _ctx);
    _x_x828 = _x_1; /*902*/
  }
  x_10352 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x830, (_x_x830, _x_x828, _ctx), _ctx); /*903*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10352, _ctx);
    kk_box_t _x_x831 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10260_fun832(_y_x10105, _y_x10106, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple4_unbox(_x_x831, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_map_10259(_y_x10105, _y_x10106, f, t, x_10352, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838__t {
  struct kk_function_s _base;
  kk_box_t _y_x10105;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_map_10261_fun838(kk_box_t _y_x10105, kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838, kk_context());
  _self->_y_x10105 = _y_x10105;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_map_10261_fun838__t*, _fself, _ctx);
  kk_box_t _y_x10105 = _self->_y_x10105; /* 903 */
  kk_function_t f = _self->f; /* (902) -> 904 903 */
  kk_std_core_types__tuple4 t = _self->t; /* (902, 902, 902, 902) */
  kk_drop_match(_self, {kk_box_dup(_y_x10105, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10106_43 = _b_x41; /*903*/;
  kk_std_core_types__tuple4 _x_x839 = kk_std_core_tuple_tuple4_fs__mlift_map_10260(_y_x10105, f, t, _y_x10106_43, _ctx); /*(903, 903, 903, 903)*/
  return kk_std_core_types__tuple4_box(_x_x839, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs__mlift_map_10261(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t _y_x10105, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a), b) -> e (b, b, b, b) */ 
  kk_box_t x_10354;
  kk_function_t _x_x836 = kk_function_dup(f, _ctx); /*(902) -> 904 903*/
  kk_box_t _x_x834;
  {
    struct kk_std_core_types_Tuple4* _con_x835 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x_0 = _con_x835->snd;
    kk_box_dup(_x_0, _ctx);
    _x_x834 = _x_0; /*902*/
  }
  x_10354 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x836, (_x_x836, _x_x834, _ctx), _ctx); /*903*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10354, _ctx);
    kk_box_t _x_x837 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_map_10261_fun838(_y_x10105, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple4_unbox(_x_x837, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_map_10260(_y_x10105, f, t, x_10354, _ctx);
  }
}
 
// Map a function over a quadruple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun844__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun844(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun844(kk_function_t f, kk_std_core_types__tuple4 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun844__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun844__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun844, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun844(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun844__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun844__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (902) -> 904 903 */
  kk_std_core_types__tuple4 t = _self->t; /* (902, 902, 902, 902) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10105_56 = _b_x45; /*903*/;
  kk_std_core_types__tuple4 _x_x845 = kk_std_core_tuple_tuple4_fs__mlift_map_10261(f, t, _y_x10105_56, _ctx); /*(903, 903, 903, 903)*/
  return kk_std_core_types__tuple4_box(_x_x845, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun850__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
  kk_box_t x_10356;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun850(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun850(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t x_10356, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun850__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun850__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun850, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_10356 = x_10356;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun850(kk_function_t _fself, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun850__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun850__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (902) -> 904 903 */
  kk_std_core_types__tuple4 t = _self->t; /* (902, 902, 902, 902) */
  kk_box_t x_10356 = _self->x_10356; /* 903 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);kk_box_dup(x_10356, _ctx);}, {}, _ctx)
  kk_box_t _y_x10106_57 = _b_x47; /*903*/;
  kk_std_core_types__tuple4 _x_x851 = kk_std_core_tuple_tuple4_fs__mlift_map_10260(x_10356, f, t, _y_x10106_57, _ctx); /*(903, 903, 903, 903)*/
  return kk_std_core_types__tuple4_box(_x_x851, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun856__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple4 t;
  kk_box_t x_0_10359;
  kk_box_t x_10356;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun856(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun856(kk_function_t f, kk_std_core_types__tuple4 t, kk_box_t x_0_10359, kk_box_t x_10356, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun856__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun856__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun856, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_0_10359 = x_0_10359;
  _self->x_10356 = x_10356;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun856(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun856__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun856__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (902) -> 904 903 */
  kk_std_core_types__tuple4 t = _self->t; /* (902, 902, 902, 902) */
  kk_box_t x_0_10359 = _self->x_0_10359; /* 903 */
  kk_box_t x_10356 = _self->x_10356; /* 903 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple4_dup(t, _ctx);kk_box_dup(x_0_10359, _ctx);kk_box_dup(x_10356, _ctx);}, {}, _ctx)
  kk_box_t _y_x10107_58 = _b_x49; /*903*/;
  kk_std_core_types__tuple4 _x_x857 = kk_std_core_tuple_tuple4_fs__mlift_map_10259(x_10356, x_0_10359, f, t, _y_x10107_58, _ctx); /*(903, 903, 903, 903)*/
  return kk_std_core_types__tuple4_box(_x_x857, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_map_fun861__t {
  struct kk_function_s _base;
  kk_box_t x_0_10359;
  kk_box_t x_10356;
  kk_box_t x_1_10362;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun861(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_map_fun861(kk_box_t x_0_10359, kk_box_t x_10356, kk_box_t x_1_10362, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun861__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_map_fun861__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_map_fun861, kk_context());
  _self->x_0_10359 = x_0_10359;
  _self->x_10356 = x_10356;
  _self->x_1_10362 = x_1_10362;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_map_fun861(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_map_fun861__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_map_fun861__t*, _fself, _ctx);
  kk_box_t x_0_10359 = _self->x_0_10359; /* 903 */
  kk_box_t x_10356 = _self->x_10356; /* 903 */
  kk_box_t x_1_10362 = _self->x_1_10362; /* 903 */
  kk_drop_match(_self, {kk_box_dup(x_0_10359, _ctx);kk_box_dup(x_10356, _ctx);kk_box_dup(x_1_10362, _ctx);}, {}, _ctx)
  kk_box_t _y_x10108_59 = _b_x51; /*903*/;
  kk_std_core_types__tuple4 _x_x862 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x_10356, x_0_10359, x_1_10362, _y_x10108_59, _ctx); /*(150, 151, 152, 153)*/
  return kk_std_core_types__tuple4_box(_x_x862, _ctx);
}

kk_std_core_types__tuple4 kk_std_core_tuple_tuple4_fs_map(kk_std_core_types__tuple4 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a, a), f : (a) -> e b) -> e (b, b, b, b) */ 
  kk_box_t x_10356;
  kk_function_t _x_x842 = kk_function_dup(f, _ctx); /*(902) -> 904 903*/
  kk_box_t _x_x840;
  {
    struct kk_std_core_types_Tuple4* _con_x841 = kk_std_core_types__as_Tuple4(t, _ctx);
    kk_box_t _x = _con_x841->fst;
    kk_box_dup(_x, _ctx);
    _x_x840 = _x; /*902*/
  }
  x_10356 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x842, (_x_x842, _x_x840, _ctx), _ctx); /*903*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10356, _ctx);
    kk_box_t _x_x843 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun844(f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple4_unbox(_x_x843, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10359;
    kk_function_t _x_x848 = kk_function_dup(f, _ctx); /*(902) -> 904 903*/
    kk_box_t _x_x846;
    {
      struct kk_std_core_types_Tuple4* _con_x847 = kk_std_core_types__as_Tuple4(t, _ctx);
      kk_box_t _x_0 = _con_x847->snd;
      kk_box_dup(_x_0, _ctx);
      _x_x846 = _x_0; /*902*/
    }
    x_0_10359 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x848, (_x_x848, _x_x846, _ctx), _ctx); /*903*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10359, _ctx);
      kk_box_t _x_x849 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun850(f, t, x_10356, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple4_unbox(_x_x849, KK_OWNED, _ctx);
    }
    {
      kk_box_t x_1_10362;
      kk_function_t _x_x854 = kk_function_dup(f, _ctx); /*(902) -> 904 903*/
      kk_box_t _x_x852;
      {
        struct kk_std_core_types_Tuple4* _con_x853 = kk_std_core_types__as_Tuple4(t, _ctx);
        kk_box_t _x_1 = _con_x853->thd;
        kk_box_dup(_x_1, _ctx);
        _x_x852 = _x_1; /*902*/
      }
      x_1_10362 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x854, (_x_x854, _x_x852, _ctx), _ctx); /*903*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x_1_10362, _ctx);
        kk_box_t _x_x855 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun856(f, t, x_0_10359, x_10356, _ctx), _ctx); /*2419*/
        return kk_std_core_types__tuple4_unbox(_x_x855, KK_OWNED, _ctx);
      }
      {
        kk_box_t x_2_10365;
        kk_box_t _x_x858;
        {
          struct kk_std_core_types_Tuple4* _con_x859 = kk_std_core_types__as_Tuple4(t, _ctx);
          kk_box_t _pat_0_2_0 = _con_x859->fst;
          kk_box_t _pat_1_2 = _con_x859->snd;
          kk_box_t _pat_2_2 = _con_x859->thd;
          kk_box_t _x_2 = _con_x859->field4;
          if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
            kk_box_drop(_pat_2_2, _ctx);
            kk_box_drop(_pat_1_2, _ctx);
            kk_box_drop(_pat_0_2_0, _ctx);
            kk_datatype_ptr_free(t, _ctx);
          }
          else {
            kk_box_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(t, _ctx);
          }
          _x_x858 = _x_2; /*902*/
        }
        x_2_10365 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x858, _ctx), _ctx); /*903*/
        if (kk_yielding(kk_context())) {
          kk_box_drop(x_2_10365, _ctx);
          kk_box_t _x_x860 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_map_fun861(x_0_10359, x_10356, x_1_10362, _ctx), _ctx); /*2419*/
          return kk_std_core_types__tuple4_unbox(_x_x860, KK_OWNED, _ctx);
        }
        {
          return kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x_10356, x_0_10359, x_1_10362, x_2_10365, _ctx);
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866__t {
  struct kk_function_s _base;
  kk_box_t _y_x10109;
  kk_box_t _y_x10110;
  kk_box_t _y_x10111;
  kk_box_t _y_x10112;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_map_10263_fun866(kk_box_t _y_x10109, kk_box_t _y_x10110, kk_box_t _y_x10111, kk_box_t _y_x10112, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866, kk_context());
  _self->_y_x10109 = _y_x10109;
  _self->_y_x10110 = _y_x10110;
  _self->_y_x10111 = _y_x10111;
  _self->_y_x10112 = _y_x10112;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866(kk_function_t _fself, kk_box_t _b_x61, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10263_fun866__t*, _fself, _ctx);
  kk_box_t _y_x10109 = _self->_y_x10109; /* 1138 */
  kk_box_t _y_x10110 = _self->_y_x10110; /* 1138 */
  kk_box_t _y_x10111 = _self->_y_x10111; /* 1138 */
  kk_box_t _y_x10112 = _self->_y_x10112; /* 1138 */
  kk_drop_match(_self, {kk_box_dup(_y_x10109, _ctx);kk_box_dup(_y_x10110, _ctx);kk_box_dup(_y_x10111, _ctx);kk_box_dup(_y_x10112, _ctx);}, {}, _ctx)
  kk_box_t _y_x10113_63 = _b_x61; /*1138*/;
  kk_std_core_types__tuple5 _x_x867 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _y_x10109, _y_x10110, _y_x10111, _y_x10112, _y_x10113_63, _ctx); /*(161, 162, 163, 164, 165)*/
  return kk_std_core_types__tuple5_box(_x_x867, _ctx);
}

kk_std_core_types__tuple5 kk_std_core_tuple_tuple5_fs__mlift_map_10263(kk_box_t _y_x10109, kk_box_t _y_x10110, kk_box_t _y_x10111, kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t _y_x10112, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, b, f : (a) -> e b, t : (a, a, a, a, a), b) -> e (b, b, b, b, b) */ 
  kk_box_t x_10372;
  kk_box_t _x_x863;
  {
    struct kk_std_core_types_Tuple5* _con_x864 = kk_std_core_types__as_Tuple5(t, _ctx);
    kk_box_t _pat_0_3 = _con_x864->fst;
    kk_box_t _pat_1_3 = _con_x864->snd;
    kk_box_t _pat_2_3 = _con_x864->thd;
    kk_box_t _pat_3_3 = _con_x864->field4;
    kk_box_t _x_3 = _con_x864->field5;
    if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
      kk_box_drop(_pat_3_3, _ctx);
      kk_box_drop(_pat_2_3, _ctx);
      kk_box_drop(_pat_1_3, _ctx);
      kk_box_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(t, _ctx);
    }
    else {
      kk_box_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(t, _ctx);
    }
    _x_x863 = _x_3; /*1137*/
  }
  x_10372 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x863, _ctx), _ctx); /*1138*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10372, _ctx);
    kk_box_t _x_x865 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_map_10263_fun866(_y_x10109, _y_x10110, _y_x10111, _y_x10112, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple5_unbox(_x_x865, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _y_x10109, _y_x10110, _y_x10111, _y_x10112, x_10372, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872__t {
  struct kk_function_s _base;
  kk_box_t _y_x10109;
  kk_box_t _y_x10110;
  kk_box_t _y_x10111;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_map_10264_fun872(kk_box_t _y_x10109, kk_box_t _y_x10110, kk_box_t _y_x10111, kk_function_t f, kk_std_core_types__tuple5 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872, kk_context());
  _self->_y_x10109 = _y_x10109;
  _self->_y_x10110 = _y_x10110;
  _self->_y_x10111 = _y_x10111;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10264_fun872__t*, _fself, _ctx);
  kk_box_t _y_x10109 = _self->_y_x10109; /* 1138 */
  kk_box_t _y_x10110 = _self->_y_x10110; /* 1138 */
  kk_box_t _y_x10111 = _self->_y_x10111; /* 1138 */
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_drop_match(_self, {kk_box_dup(_y_x10109, _ctx);kk_box_dup(_y_x10110, _ctx);kk_box_dup(_y_x10111, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10112_67 = _b_x65; /*1138*/;
  kk_std_core_types__tuple5 _x_x873 = kk_std_core_tuple_tuple5_fs__mlift_map_10263(_y_x10109, _y_x10110, _y_x10111, f, t, _y_x10112_67, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x873, _ctx);
}

kk_std_core_types__tuple5 kk_std_core_tuple_tuple5_fs__mlift_map_10264(kk_box_t _y_x10109, kk_box_t _y_x10110, kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t _y_x10111, kk_context_t* _ctx) { /* forall<a,b,e> (b, b, f : (a) -> e b, t : (a, a, a, a, a), b) -> e (b, b, b, b, b) */ 
  kk_box_t x_10379;
  kk_function_t _x_x870 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
  kk_box_t _x_x868;
  {
    struct kk_std_core_types_Tuple5* _con_x869 = kk_std_core_types__as_Tuple5(t, _ctx);
    kk_box_t _x_2 = _con_x869->field4;
    kk_box_dup(_x_2, _ctx);
    _x_x868 = _x_2; /*1137*/
  }
  x_10379 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x870, (_x_x870, _x_x868, _ctx), _ctx); /*1138*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10379, _ctx);
    kk_box_t _x_x871 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_map_10264_fun872(_y_x10109, _y_x10110, _y_x10111, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple5_unbox(_x_x871, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_map_10263(_y_x10109, _y_x10110, _y_x10111, f, t, x_10379, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878__t {
  struct kk_function_s _base;
  kk_box_t _y_x10109;
  kk_box_t _y_x10110;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_map_10265_fun878(kk_box_t _y_x10109, kk_box_t _y_x10110, kk_function_t f, kk_std_core_types__tuple5 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878, kk_context());
  _self->_y_x10109 = _y_x10109;
  _self->_y_x10110 = _y_x10110;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10265_fun878__t*, _fself, _ctx);
  kk_box_t _y_x10109 = _self->_y_x10109; /* 1138 */
  kk_box_t _y_x10110 = _self->_y_x10110; /* 1138 */
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_drop_match(_self, {kk_box_dup(_y_x10109, _ctx);kk_box_dup(_y_x10110, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10111_71 = _b_x69; /*1138*/;
  kk_std_core_types__tuple5 _x_x879 = kk_std_core_tuple_tuple5_fs__mlift_map_10264(_y_x10109, _y_x10110, f, t, _y_x10111_71, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x879, _ctx);
}

kk_std_core_types__tuple5 kk_std_core_tuple_tuple5_fs__mlift_map_10265(kk_box_t _y_x10109, kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t _y_x10110, kk_context_t* _ctx) { /* forall<a,b,e> (b, f : (a) -> e b, t : (a, a, a, a, a), b) -> e (b, b, b, b, b) */ 
  kk_box_t x_10381;
  kk_function_t _x_x876 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
  kk_box_t _x_x874;
  {
    struct kk_std_core_types_Tuple5* _con_x875 = kk_std_core_types__as_Tuple5(t, _ctx);
    kk_box_t _x_1 = _con_x875->thd;
    kk_box_dup(_x_1, _ctx);
    _x_x874 = _x_1; /*1137*/
  }
  x_10381 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x876, (_x_x876, _x_x874, _ctx), _ctx); /*1138*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10381, _ctx);
    kk_box_t _x_x877 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_map_10265_fun878(_y_x10109, _y_x10110, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple5_unbox(_x_x877, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_map_10264(_y_x10109, _y_x10110, f, t, x_10381, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884__t {
  struct kk_function_s _base;
  kk_box_t _y_x10109;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_map_10266_fun884(kk_box_t _y_x10109, kk_function_t f, kk_std_core_types__tuple5 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884, kk_context());
  _self->_y_x10109 = _y_x10109;
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884(kk_function_t _fself, kk_box_t _b_x73, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_map_10266_fun884__t*, _fself, _ctx);
  kk_box_t _y_x10109 = _self->_y_x10109; /* 1138 */
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_drop_match(_self, {kk_box_dup(_y_x10109, _ctx);kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10110_75 = _b_x73; /*1138*/;
  kk_std_core_types__tuple5 _x_x885 = kk_std_core_tuple_tuple5_fs__mlift_map_10265(_y_x10109, f, t, _y_x10110_75, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x885, _ctx);
}

kk_std_core_types__tuple5 kk_std_core_tuple_tuple5_fs__mlift_map_10266(kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t _y_x10109, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, t : (a, a, a, a, a), b) -> e (b, b, b, b, b) */ 
  kk_box_t x_10383;
  kk_function_t _x_x882 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
  kk_box_t _x_x880;
  {
    struct kk_std_core_types_Tuple5* _con_x881 = kk_std_core_types__as_Tuple5(t, _ctx);
    kk_box_t _x_0 = _con_x881->snd;
    kk_box_dup(_x_0, _ctx);
    _x_x880 = _x_0; /*1137*/
  }
  x_10383 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x882, (_x_x882, _x_x880, _ctx), _ctx); /*1138*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10383, _ctx);
    kk_box_t _x_x883 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_map_10266_fun884(_y_x10109, f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple5_unbox(_x_x883, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_map_10265(_y_x10109, f, t, x_10383, _ctx);
  }
}
 
// Map a function over a quintuple of elements of the same type.


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_map_fun890__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun890(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_map_fun890(kk_function_t f, kk_std_core_types__tuple5 t, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun890__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_map_fun890__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_map_fun890, kk_context());
  _self->f = f;
  _self->t = t;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun890(kk_function_t _fself, kk_box_t _b_x77, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun890__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_map_fun890__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);}, {}, _ctx)
  kk_box_t _y_x10109_91 = _b_x77; /*1138*/;
  kk_std_core_types__tuple5 _x_x891 = kk_std_core_tuple_tuple5_fs__mlift_map_10266(f, t, _y_x10109_91, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x891, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_map_fun896__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
  kk_box_t x_10385;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun896(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_map_fun896(kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t x_10385, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun896__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_map_fun896__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_map_fun896, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_10385 = x_10385;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun896(kk_function_t _fself, kk_box_t _b_x79, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun896__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_map_fun896__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_box_t x_10385 = _self->x_10385; /* 1138 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);kk_box_dup(x_10385, _ctx);}, {}, _ctx)
  kk_box_t _y_x10110_92 = _b_x79; /*1138*/;
  kk_std_core_types__tuple5 _x_x897 = kk_std_core_tuple_tuple5_fs__mlift_map_10265(x_10385, f, t, _y_x10110_92, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x897, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_map_fun902__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
  kk_box_t x_0_10388;
  kk_box_t x_10385;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun902(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_map_fun902(kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t x_0_10388, kk_box_t x_10385, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun902__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_map_fun902__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_map_fun902, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_0_10388 = x_0_10388;
  _self->x_10385 = x_10385;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun902(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun902__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_map_fun902__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_box_t x_0_10388 = _self->x_0_10388; /* 1138 */
  kk_box_t x_10385 = _self->x_10385; /* 1138 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);kk_box_dup(x_0_10388, _ctx);kk_box_dup(x_10385, _ctx);}, {}, _ctx)
  kk_box_t _y_x10111_93 = _b_x81; /*1138*/;
  kk_std_core_types__tuple5 _x_x903 = kk_std_core_tuple_tuple5_fs__mlift_map_10264(x_10385, x_0_10388, f, t, _y_x10111_93, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x903, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_map_fun908__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__tuple5 t;
  kk_box_t x_0_10388;
  kk_box_t x_10385;
  kk_box_t x_1_10391;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun908(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_map_fun908(kk_function_t f, kk_std_core_types__tuple5 t, kk_box_t x_0_10388, kk_box_t x_10385, kk_box_t x_1_10391, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun908__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_map_fun908__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_map_fun908, kk_context());
  _self->f = f;
  _self->t = t;
  _self->x_0_10388 = x_0_10388;
  _self->x_10385 = x_10385;
  _self->x_1_10391 = x_1_10391;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun908(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun908__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_map_fun908__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1137) -> 1139 1138 */
  kk_std_core_types__tuple5 t = _self->t; /* (1137, 1137, 1137, 1137, 1137) */
  kk_box_t x_0_10388 = _self->x_0_10388; /* 1138 */
  kk_box_t x_10385 = _self->x_10385; /* 1138 */
  kk_box_t x_1_10391 = _self->x_1_10391; /* 1138 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__tuple5_dup(t, _ctx);kk_box_dup(x_0_10388, _ctx);kk_box_dup(x_10385, _ctx);kk_box_dup(x_1_10391, _ctx);}, {}, _ctx)
  kk_box_t _y_x10112_94 = _b_x83; /*1138*/;
  kk_std_core_types__tuple5 _x_x909 = kk_std_core_tuple_tuple5_fs__mlift_map_10263(x_10385, x_0_10388, x_1_10391, f, t, _y_x10112_94, _ctx); /*(1138, 1138, 1138, 1138, 1138)*/
  return kk_std_core_types__tuple5_box(_x_x909, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_map_fun913__t {
  struct kk_function_s _base;
  kk_box_t x_0_10388;
  kk_box_t x_10385;
  kk_box_t x_1_10391;
  kk_box_t x_2_10394;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun913(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_map_fun913(kk_box_t x_0_10388, kk_box_t x_10385, kk_box_t x_1_10391, kk_box_t x_2_10394, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun913__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_map_fun913__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_map_fun913, kk_context());
  _self->x_0_10388 = x_0_10388;
  _self->x_10385 = x_10385;
  _self->x_1_10391 = x_1_10391;
  _self->x_2_10394 = x_2_10394;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_map_fun913(kk_function_t _fself, kk_box_t _b_x85, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_map_fun913__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_map_fun913__t*, _fself, _ctx);
  kk_box_t x_0_10388 = _self->x_0_10388; /* 1138 */
  kk_box_t x_10385 = _self->x_10385; /* 1138 */
  kk_box_t x_1_10391 = _self->x_1_10391; /* 1138 */
  kk_box_t x_2_10394 = _self->x_2_10394; /* 1138 */
  kk_drop_match(_self, {kk_box_dup(x_0_10388, _ctx);kk_box_dup(x_10385, _ctx);kk_box_dup(x_1_10391, _ctx);kk_box_dup(x_2_10394, _ctx);}, {}, _ctx)
  kk_box_t _y_x10113_95 = _b_x85; /*1138*/;
  kk_std_core_types__tuple5 _x_x914 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, x_10385, x_0_10388, x_1_10391, x_2_10394, _y_x10113_95, _ctx); /*(161, 162, 163, 164, 165)*/
  return kk_std_core_types__tuple5_box(_x_x914, _ctx);
}

kk_std_core_types__tuple5 kk_std_core_tuple_tuple5_fs_map(kk_std_core_types__tuple5 t, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (t : (a, a, a, a, a), f : (a) -> e b) -> e (b, b, b, b, b) */ 
  kk_box_t x_10385;
  kk_function_t _x_x888 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
  kk_box_t _x_x886;
  {
    struct kk_std_core_types_Tuple5* _con_x887 = kk_std_core_types__as_Tuple5(t, _ctx);
    kk_box_t _x = _con_x887->fst;
    kk_box_dup(_x, _ctx);
    _x_x886 = _x; /*1137*/
  }
  x_10385 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x888, (_x_x888, _x_x886, _ctx), _ctx); /*1138*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10385, _ctx);
    kk_box_t _x_x889 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_map_fun890(f, t, _ctx), _ctx); /*2419*/
    return kk_std_core_types__tuple5_unbox(_x_x889, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10388;
    kk_function_t _x_x894 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
    kk_box_t _x_x892;
    {
      struct kk_std_core_types_Tuple5* _con_x893 = kk_std_core_types__as_Tuple5(t, _ctx);
      kk_box_t _x_0 = _con_x893->snd;
      kk_box_dup(_x_0, _ctx);
      _x_x892 = _x_0; /*1137*/
    }
    x_0_10388 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x894, (_x_x894, _x_x892, _ctx), _ctx); /*1138*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10388, _ctx);
      kk_box_t _x_x895 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_map_fun896(f, t, x_10385, _ctx), _ctx); /*2419*/
      return kk_std_core_types__tuple5_unbox(_x_x895, KK_OWNED, _ctx);
    }
    {
      kk_box_t x_1_10391;
      kk_function_t _x_x900 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
      kk_box_t _x_x898;
      {
        struct kk_std_core_types_Tuple5* _con_x899 = kk_std_core_types__as_Tuple5(t, _ctx);
        kk_box_t _x_1 = _con_x899->thd;
        kk_box_dup(_x_1, _ctx);
        _x_x898 = _x_1; /*1137*/
      }
      x_1_10391 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x900, (_x_x900, _x_x898, _ctx), _ctx); /*1138*/
      if (kk_yielding(kk_context())) {
        kk_box_drop(x_1_10391, _ctx);
        kk_box_t _x_x901 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_map_fun902(f, t, x_0_10388, x_10385, _ctx), _ctx); /*2419*/
        return kk_std_core_types__tuple5_unbox(_x_x901, KK_OWNED, _ctx);
      }
      {
        kk_box_t x_2_10394;
        kk_function_t _x_x906 = kk_function_dup(f, _ctx); /*(1137) -> 1139 1138*/
        kk_box_t _x_x904;
        {
          struct kk_std_core_types_Tuple5* _con_x905 = kk_std_core_types__as_Tuple5(t, _ctx);
          kk_box_t _x_2 = _con_x905->field4;
          kk_box_dup(_x_2, _ctx);
          _x_x904 = _x_2; /*1137*/
        }
        x_2_10394 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x906, (_x_x906, _x_x904, _ctx), _ctx); /*1138*/
        if (kk_yielding(kk_context())) {
          kk_box_drop(x_2_10394, _ctx);
          kk_box_t _x_x907 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_map_fun908(f, t, x_0_10388, x_10385, x_1_10391, _ctx), _ctx); /*2419*/
          return kk_std_core_types__tuple5_unbox(_x_x907, KK_OWNED, _ctx);
        }
        {
          kk_box_t x_3_10397;
          kk_box_t _x_x910;
          {
            struct kk_std_core_types_Tuple5* _con_x911 = kk_std_core_types__as_Tuple5(t, _ctx);
            kk_box_t _pat_0_3_0 = _con_x911->fst;
            kk_box_t _pat_1_3 = _con_x911->snd;
            kk_box_t _pat_2_3 = _con_x911->thd;
            kk_box_t _pat_3_3 = _con_x911->field4;
            kk_box_t _x_3 = _con_x911->field5;
            if kk_likely(kk_datatype_ptr_is_unique(t, _ctx)) {
              kk_box_drop(_pat_3_3, _ctx);
              kk_box_drop(_pat_2_3, _ctx);
              kk_box_drop(_pat_1_3, _ctx);
              kk_box_drop(_pat_0_3_0, _ctx);
              kk_datatype_ptr_free(t, _ctx);
            }
            else {
              kk_box_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(t, _ctx);
            }
            _x_x910 = _x_3; /*1137*/
          }
          x_3_10397 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, _x_x910, _ctx), _ctx); /*1138*/
          if (kk_yielding(kk_context())) {
            kk_box_drop(x_3_10397, _ctx);
            kk_box_t _x_x912 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_map_fun913(x_0_10388, x_10385, x_1_10391, x_2_10394, _ctx), _ctx); /*2419*/
            return kk_std_core_types__tuple5_unbox(_x_x912, KK_OWNED, _ctx);
          }
          {
            return kk_std_core_types__new_Tuple5(kk_reuse_null, 0, x_10385, x_0_10388, x_1_10391, x_2_10394, x_3_10397, _ctx);
          }
        }
      }
    }
  }
}
 
// Element-wise tuple equality


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__lp__at_x_fun916__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_;
  kk_box_t y1;
  kk_box_t y2;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__lp__at_x_fun916_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__lp__at_new_x_fun916_eq__eq__rp_(kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_box_t y1, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__lp__at_x_fun916__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__lp__at_x_fun916__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__lp__at_x_fun916_eq__eq__rp_, kk_context());
  _self->_implicit_fs_snd_fs__lp__eq__eq__rp_ = _implicit_fs_snd_fs__lp__eq__eq__rp_;
  _self->y1 = y1;
  _self->y2 = y2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__lp__at_x_fun916_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__lp__at_x_fun916__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__lp__at_x_fun916__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_snd_fs__lp__eq__eq__rp_; /* (1276, 1276) -> 1277 bool */
  kk_box_t y1 = _self->y1; /* 1276 */
  kk_box_t y2 = _self->y2; /* 1276 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);}, {}, _ctx)
  bool _y_x10114_99 = kk_bool_unbox(_b_x97); /*bool*/;
  bool _x_x917;
  if (_y_x10114_99) {
    _x_x917 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    _x_x917 = false; /*bool*/
  }
  return kk_bool_box(_x_x917);
}

bool kk_std_core_tuple_tuple2_fs__lp__eq__eq__rp_(kk_std_core_types__tuple2 _pat_x36__22, kk_std_core_types__tuple2 _pat_x36__39, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), (a, b), ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool) -> e bool */ 
  {
    kk_box_t x1 = _pat_x36__22.fst;
    kk_box_t y1 = _pat_x36__22.snd;
    {
      kk_box_t x2 = _pat_x36__39.fst;
      kk_box_t y2 = _pat_x36__39.snd;
      bool x_10405 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x915 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__lp__at_new_x_fun916_eq__eq__rp_(_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x915);
      }
      if (x_10405) {
        return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx);
      }
      {
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__lp__at_new_mlift_x_10269_fun919_eq__eq__rp_(kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919_eq__eq__rp_, kk_context());
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_fun919__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1458, 1458) -> 1459 bool */
  kk_box_t z1 = _self->z1; /* 1458 */
  kk_box_t z2 = _self->z2; /* 1458 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _x_x920;
  bool _y_x10120_103 = kk_bool_unbox(_b_x101); /*bool*/;
  if (_y_x10120_103) {
    _x_x920 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    _x_x920 = false; /*bool*/
  }
  return kk_bool_box(_x_x920);
}

bool kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_eq__eq__rp_(kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, bool _y_x10119, kk_context_t* _ctx) { /* forall<a,b,e> (?snd/(==) : (a, a) -> e bool, ?thd/(==) : (b, b) -> e bool, y1 : a, y2 : a, z1 : b, z2 : b, bool) -> e bool */ 
  if (_y_x10119) {
    bool x_10412 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x918 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__lp__at_new_mlift_x_10269_fun919_eq__eq__rp_(_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x918);
    }
    if (x_10412) {
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx);
    }
    {
      kk_box_drop(z2, _ctx);
      kk_box_drop(z1, _ctx);
      kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// Element-wise triple equality


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun922__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_x_fun922_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__lp__at_new_x_fun922_eq__eq__rp_(kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun922__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun922__t_eq__eq__rp_, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__lp__at_x_fun922_eq__eq__rp_, kk_context());
  _self->_implicit_fs_snd_fs__lp__eq__eq__rp_ = _implicit_fs_snd_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_x_fun922_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun922__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun922__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_snd_fs__lp__eq__eq__rp_; /* (1457, 1457) -> 1459 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1458, 1458) -> 1459 bool */
  kk_box_t y1 = _self->y1; /* 1457 */
  kk_box_t y2 = _self->y2; /* 1457 */
  kk_box_t z1 = _self->z1; /* 1458 */
  kk_box_t z2 = _self->z2; /* 1458 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10119_111 = kk_bool_unbox(_b_x106); /*bool*/;
  bool _x_x923 = kk_std_core_tuple_tuple3_fs__lp__at_mlift_x_10269_eq__eq__rp_(_implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, y1, y2, z1, z2, _y_x10119_111, _ctx); /*bool*/
  return kk_bool_box(_x_x923);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun925__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_x_fun925_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__lp__at_new_x_fun925_eq__eq__rp_(kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun925__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun925__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__lp__at_x_fun925_eq__eq__rp_, kk_context());
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__lp__at_x_fun925_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun925__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__lp__at_x_fun925__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1458, 1458) -> 1459 bool */
  kk_box_t z1 = _self->z1; /* 1458 */
  kk_box_t z2 = _self->z2; /* 1458 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10120_112 = kk_bool_unbox(_b_x108); /*bool*/;
  bool _x_x926;
  if (_y_x10120_112) {
    _x_x926 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    _x_x926 = false; /*bool*/
  }
  return kk_bool_box(_x_x926);
}

bool kk_std_core_tuple_tuple3_fs__lp__eq__eq__rp_(kk_std_core_types__tuple3 _pat_x40__22, kk_std_core_types__tuple3 _pat_x40__44, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,c,e> ((a, b, c), (a, b, c), ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool, ?thd/(==) : (c, c) -> e bool) -> e bool */ 
  {
    kk_box_t x1 = _pat_x40__22.fst;
    kk_box_t y1 = _pat_x40__22.snd;
    kk_box_t z1 = _pat_x40__22.thd;
    {
      kk_box_t x2 = _pat_x40__44.fst;
      kk_box_t y2 = _pat_x40__44.snd;
      kk_box_t z2 = _pat_x40__44.thd;
      bool x_10418 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x921 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__lp__at_new_x_fun922_eq__eq__rp_(_implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, y1, y2, z1, z2, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x921);
      }
      if (x_10418) {
        bool x_0_10421 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x924 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__lp__at_new_x_fun925_eq__eq__rp_(_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*2419*/
          return kk_bool_unbox(_x_x924);
        }
        if (x_0_10421) {
          return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx);
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
          return false;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__lp__at_new_mlift_x_10271_fun928_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_fun928__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1697, 1697) -> 1698 bool */
  kk_box_t w1 = _self->w1; /* 1697 */
  kk_box_t w2 = _self->w2; /* 1697 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  bool _x_x929;
  bool _y_x10128_116 = kk_bool_unbox(_b_x114); /*bool*/;
  if (_y_x10128_116) {
    _x_x929 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    _x_x929 = false; /*bool*/
  }
  return kk_bool_box(_x_x929);
}

bool kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, bool _y_x10127, kk_context_t* _ctx) { /* forall<a,b,e> (?field4/(==) : (b, b) -> e bool, ?thd/(==) : (a, a) -> e bool, w1 : b, w2 : b, z1 : a, z2 : a, bool) -> e bool */ 
  if (_y_x10127) {
    bool x_10428 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x927 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__lp__at_new_mlift_x_10271_fun928_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x927);
    }
    if (x_10428) {
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx);
    }
    {
      kk_box_drop(w2, _ctx);
      kk_box_drop(w1, _ctx);
      kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__lp__at_new_mlift_x_10272_fun931_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931__t_eq__eq__rp_, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_fun931__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1697, 1697) -> 1698 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1696, 1696) -> 1698 bool */
  kk_box_t w1 = _self->w1; /* 1697 */
  kk_box_t w2 = _self->w2; /* 1697 */
  kk_box_t z1 = _self->z1; /* 1696 */
  kk_box_t z2 = _self->z2; /* 1696 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10127_121 = kk_bool_unbox(_b_x119); /*bool*/;
  bool _x_x932 = kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, z1, z2, _y_x10127_121, _ctx); /*bool*/
  return kk_bool_box(_x_x932);
}

bool kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, bool _y_x10126, kk_context_t* _ctx) { /* forall<a,b,c,e> (?field4/(==) : (c, c) -> e bool, ?snd/(==) : (a, a) -> e bool, ?thd/(==) : (b, b) -> e bool, w1 : c, w2 : c, y1 : a, y2 : a, z1 : b, z2 : b, bool) -> e bool */ 
  if (_y_x10126) {
    bool x_10434 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x930 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__lp__at_new_mlift_x_10272_fun931_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x930);
    }
    {
      return kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, z1, z2, x_10434, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// Element-wise quadruple equality


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun936__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun936_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun936_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun936__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun936__t_eq__eq__rp_, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__lp__at_x_fun936_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_snd_fs__lp__eq__eq__rp_ = _implicit_fs_snd_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun936_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun936__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun936__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1697, 1697) -> 1698 bool */
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_snd_fs__lp__eq__eq__rp_; /* (1695, 1695) -> 1698 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1696, 1696) -> 1698 bool */
  kk_box_t w1 = _self->w1; /* 1697 */
  kk_box_t w2 = _self->w2; /* 1697 */
  kk_box_t y1 = _self->y1; /* 1695 */
  kk_box_t y2 = _self->y2; /* 1695 */
  kk_box_t z1 = _self->z1; /* 1696 */
  kk_box_t z2 = _self->z2; /* 1696 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10126_131 = kk_bool_unbox(_b_x123); /*bool*/;
  bool _x_x937 = kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10272_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, y1, y2, z1, z2, _y_x10126_131, _ctx); /*bool*/
  return kk_bool_box(_x_x937);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun939__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun939_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun939_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun939__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun939__t_eq__eq__rp_, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__lp__at_x_fun939_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun939_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun939__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun939__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1697, 1697) -> 1698 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1696, 1696) -> 1698 bool */
  kk_box_t w1 = _self->w1; /* 1697 */
  kk_box_t w2 = _self->w2; /* 1697 */
  kk_box_t z1 = _self->z1; /* 1696 */
  kk_box_t z2 = _self->z2; /* 1696 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10127_132 = kk_bool_unbox(_b_x125); /*bool*/;
  bool _x_x940 = kk_std_core_tuple_tuple4_fs__lp__at_mlift_x_10271_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, z1, z2, _y_x10127_132, _ctx); /*bool*/
  return kk_bool_box(_x_x940);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun942__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun942_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun942_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun942__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun942__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__lp__at_x_fun942_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__lp__at_x_fun942_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun942__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__lp__at_x_fun942__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1697, 1697) -> 1698 bool */
  kk_box_t w1 = _self->w1; /* 1697 */
  kk_box_t w2 = _self->w2; /* 1697 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  bool _y_x10128_133 = kk_bool_unbox(_b_x127); /*bool*/;
  bool _x_x943;
  if (_y_x10128_133) {
    _x_x943 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    _x_x943 = false; /*bool*/
  }
  return kk_bool_box(_x_x943);
}

bool kk_std_core_tuple_tuple4_fs__lp__eq__eq__rp_(kk_std_core_types__tuple4 _pat_x44__22, kk_std_core_types__tuple4 _pat_x44__49, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,c,d,e> ((a, b, c, d), (a, b, c, d), ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool, ?thd/(==) : (c, c) -> e bool, ?field4/(==) : (d, d) -> e bool) -> e bool */ 
  {
    struct kk_std_core_types_Tuple4* _con_x933 = kk_std_core_types__as_Tuple4(_pat_x44__22, _ctx);
    kk_box_t x1 = _con_x933->fst;
    kk_box_t y1 = _con_x933->snd;
    kk_box_t z1 = _con_x933->thd;
    kk_box_t w1 = _con_x933->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x44__22, _ctx)) {
      kk_datatype_ptr_free(_pat_x44__22, _ctx);
    }
    else {
      kk_box_dup(w1, _ctx);
      kk_box_dup(x1, _ctx);
      kk_box_dup(y1, _ctx);
      kk_box_dup(z1, _ctx);
      kk_datatype_ptr_decref(_pat_x44__22, _ctx);
    }
    {
      struct kk_std_core_types_Tuple4* _con_x934 = kk_std_core_types__as_Tuple4(_pat_x44__49, _ctx);
      kk_box_t x2 = _con_x934->fst;
      kk_box_t y2 = _con_x934->snd;
      kk_box_t z2 = _con_x934->thd;
      kk_box_t w2 = _con_x934->field4;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x44__49, _ctx)) {
        kk_datatype_ptr_free(_pat_x44__49, _ctx);
      }
      else {
        kk_box_dup(w2, _ctx);
        kk_box_dup(x2, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(z2, _ctx);
        kk_datatype_ptr_decref(_pat_x44__49, _ctx);
      }
      bool x_10436 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x935 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun936_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, y1, y2, z1, z2, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x935);
      }
      if (x_10436) {
        bool x_0_10439 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x938 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun939_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
          return kk_bool_unbox(_x_x938);
        }
        if (x_0_10439) {
          bool x_1_10442 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x941 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__lp__at_new_x_fun942_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*2419*/
            return kk_bool_unbox(_x_x941);
          }
          if (x_1_10442) {
            return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx);
          }
          {
            kk_box_drop(w2, _ctx);
            kk_box_drop(w1, _ctx);
            kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
            return false;
          }
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          kk_box_drop(w2, _ctx);
          kk_box_drop(w1, _ctx);
          kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
          kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
          return false;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_box_drop(w2, _ctx);
        kk_box_drop(w1, _ctx);
        kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10274_fun945_eq__eq__rp_(kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_fun945__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);}, {}, _ctx)
  bool _x_x946;
  bool _y_x10138_137 = kk_bool_unbox(_b_x135); /*bool*/;
  if (_y_x10138_137) {
    _x_x946 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs__lp__eq__eq__rp_, (_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
    _x_x946 = false; /*bool*/
  }
  return kk_bool_box(_x_x946);
}

bool kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, bool _y_x10137, kk_context_t* _ctx) { /* forall<a,e,b> (?field4/(==) : (a, a) -> e bool, ?field5/(==) : (b, b) -> e bool, v1 : b, v2 : b, w1 : a, w2 : a, bool) -> e bool */ 
  if (_y_x10137) {
    bool x_10449 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x944 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10274_fun945_eq__eq__rp_(_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x944);
    }
    if (x_10449) {
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs__lp__eq__eq__rp_, (_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx);
    }
    {
      kk_box_drop(v2, _ctx);
      kk_box_drop(v1, _ctx);
      kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10275_fun948_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948__t_eq__eq__rp_, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x140, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_fun948__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1992, 1992) -> 1993 bool */
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_box_t w1 = _self->w1; /* 1992 */
  kk_box_t w2 = _self->w2; /* 1992 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  bool _y_x10137_142 = kk_bool_unbox(_b_x140); /*bool*/;
  bool _x_x949 = kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, w1, w2, _y_x10137_142, _ctx); /*bool*/
  return kk_bool_box(_x_x949);
}

bool kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, bool _y_x10136, kk_context_t* _ctx) { /* forall<a,b,e,c> (?field4/(==) : (b, b) -> e bool, ?field5/(==) : (c, c) -> e bool, ?thd/(==) : (a, a) -> e bool, v1 : c, v2 : c, w1 : b, w2 : b, z1 : a, z2 : a, bool) -> e bool */ 
  if (_y_x10136) {
    bool x_10455 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x947 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10275_fun948_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, w1, w2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x947);
    }
    {
      return kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, w1, w2, x_10455, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10276_fun951_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951__t_eq__eq__rp_, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x144, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_fun951__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1992, 1992) -> 1993 bool */
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1991, 1991) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_box_t w1 = _self->w1; /* 1992 */
  kk_box_t w2 = _self->w2; /* 1992 */
  kk_box_t z1 = _self->z1; /* 1991 */
  kk_box_t z2 = _self->z2; /* 1991 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10136_146 = kk_bool_unbox(_b_x144); /*bool*/;
  bool _x_x952 = kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, z1, z2, _y_x10136_146, _ctx); /*bool*/
  return kk_bool_box(_x_x952);
}

bool kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, bool _y_x10135, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (?field4/(==) : (c, c) -> e bool, ?field5/(==) : (d, d) -> e bool, ?snd/(==) : (a, a) -> e bool, ?thd/(==) : (b, b) -> e bool, v1 : d, v2 : d, w1 : c, w2 : c, y1 : a, y2 : a, z1 : b, z2 : b, bool) -> e bool */ 
  if (_y_x10135) {
    bool x_10457 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x950 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_mlift_x_10276_fun951_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x950);
    }
    {
      return kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, z1, z2, x_10457, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
    return false;
  }
}
 
// Element-wise quintuple equality


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun956__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun956_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun956_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun956__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun956__t_eq__eq__rp_, 13, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_x_fun956_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_snd_fs__lp__eq__eq__rp_ = _implicit_fs_snd_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun956_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun956__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun956__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1992, 1992) -> 1993 bool */
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_snd_fs__lp__eq__eq__rp_; /* (1990, 1990) -> 1993 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1991, 1991) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_box_t w1 = _self->w1; /* 1992 */
  kk_box_t w2 = _self->w2; /* 1992 */
  kk_box_t y1 = _self->y1; /* 1990 */
  kk_box_t y2 = _self->y2; /* 1990 */
  kk_box_t z1 = _self->z1; /* 1991 */
  kk_box_t z2 = _self->z2; /* 1991 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10135_159 = kk_bool_unbox(_b_x148); /*bool*/;
  bool _x_x957 = kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10276_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, y1, y2, z1, z2, _y_x10135_159, _ctx); /*bool*/
  return kk_bool_box(_x_x957);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun959__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun959_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun959_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun959__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun959__t_eq__eq__rp_, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_x_fun959_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_thd_fs__lp__eq__eq__rp_ = _implicit_fs_thd_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun959_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x150, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun959__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun959__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1992, 1992) -> 1993 bool */
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_thd_fs__lp__eq__eq__rp_; /* (1991, 1991) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_box_t w1 = _self->w1; /* 1992 */
  kk_box_t w2 = _self->w2; /* 1992 */
  kk_box_t z1 = _self->z1; /* 1991 */
  kk_box_t z2 = _self->z2; /* 1991 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  bool _y_x10136_160 = kk_bool_unbox(_b_x150); /*bool*/;
  bool _x_x960 = kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10275_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, z1, z2, _y_x10136_160, _ctx); /*bool*/
  return kk_bool_box(_x_x960);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun962__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun962_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun962_eq__eq__rp_(kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun962__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun962__t_eq__eq__rp_, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_x_fun962_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field4_fs__lp__eq__eq__rp_ = _implicit_fs_field4_fs__lp__eq__eq__rp_;
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun962_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x152, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun962__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun962__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field4_fs__lp__eq__eq__rp_; /* (1992, 1992) -> 1993 bool */
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_box_t w1 = _self->w1; /* 1992 */
  kk_box_t w2 = _self->w2; /* 1992 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  bool _y_x10137_161 = kk_bool_unbox(_b_x152); /*bool*/;
  bool _x_x963 = kk_std_core_tuple_tuple5_fs__lp__at_mlift_x_10274_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, w1, w2, _y_x10137_161, _ctx); /*bool*/
  return kk_bool_box(_x_x963);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun965__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_;
  kk_box_t v1;
  kk_box_t v2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun965_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun965_eq__eq__rp_(kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_box_t v1, kk_box_t v2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun965__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun965__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__lp__at_x_fun965_eq__eq__rp_, kk_context());
  _self->_implicit_fs_field5_fs__lp__eq__eq__rp_ = _implicit_fs_field5_fs__lp__eq__eq__rp_;
  _self->v1 = v1;
  _self->v2 = v2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__lp__at_x_fun965_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun965__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__lp__at_x_fun965__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_ = _self->_implicit_fs_field5_fs__lp__eq__eq__rp_; /* (1994, 1994) -> 1993 bool */
  kk_box_t v1 = _self->v1; /* 1994 */
  kk_box_t v2 = _self->v2; /* 1994 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);}, {}, _ctx)
  bool _y_x10138_162 = kk_bool_unbox(_b_x154); /*bool*/;
  bool _x_x966;
  if (_y_x10138_162) {
    _x_x966 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs__lp__eq__eq__rp_, (_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
    _x_x966 = false; /*bool*/
  }
  return kk_bool_box(_x_x966);
}

bool kk_std_core_tuple_tuple5_fs__lp__eq__eq__rp_(kk_std_core_types__tuple5 _pat_x50__22, kk_std_core_types__tuple5 _pat_x50__54, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_thd_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field4_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_field5_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> ((a, b, c, d, a1), (a, b, c, d, a1), ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool, ?thd/(==) : (c, c) -> e bool, ?field4/(==) : (d, d) -> e bool, ?field5/(==) : (a1, a1) -> e bool) -> e bool */ 
  {
    struct kk_std_core_types_Tuple5* _con_x953 = kk_std_core_types__as_Tuple5(_pat_x50__22, _ctx);
    kk_box_t x1 = _con_x953->fst;
    kk_box_t y1 = _con_x953->snd;
    kk_box_t z1 = _con_x953->thd;
    kk_box_t w1 = _con_x953->field4;
    kk_box_t v1 = _con_x953->field5;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x50__22, _ctx)) {
      kk_datatype_ptr_free(_pat_x50__22, _ctx);
    }
    else {
      kk_box_dup(v1, _ctx);
      kk_box_dup(w1, _ctx);
      kk_box_dup(x1, _ctx);
      kk_box_dup(y1, _ctx);
      kk_box_dup(z1, _ctx);
      kk_datatype_ptr_decref(_pat_x50__22, _ctx);
    }
    {
      struct kk_std_core_types_Tuple5* _con_x954 = kk_std_core_types__as_Tuple5(_pat_x50__54, _ctx);
      kk_box_t x2 = _con_x954->fst;
      kk_box_t y2 = _con_x954->snd;
      kk_box_t z2 = _con_x954->thd;
      kk_box_t w2 = _con_x954->field4;
      kk_box_t v2 = _con_x954->field5;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x50__54, _ctx)) {
        kk_datatype_ptr_free(_pat_x50__54, _ctx);
      }
      else {
        kk_box_dup(v2, _ctx);
        kk_box_dup(w2, _ctx);
        kk_box_dup(x2, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(z2, _ctx);
        kk_datatype_ptr_decref(_pat_x50__54, _ctx);
      }
      bool x_10459 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x1, x2, _ctx), _ctx); /*bool*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x955 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun956_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_snd_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, y1, y2, z1, z2, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x955);
      }
      if (x_10459) {
        bool x_0_10462 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y1, y2, _ctx), _ctx); /*bool*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x958 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun959_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, _implicit_fs_thd_fs__lp__eq__eq__rp_, v1, v2, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
          return kk_bool_unbox(_x_x958);
        }
        if (x_0_10462) {
          bool x_1_10465 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs__lp__eq__eq__rp_, (_implicit_fs_thd_fs__lp__eq__eq__rp_, z1, z2, _ctx), _ctx); /*bool*/;
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x961 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun962_eq__eq__rp_(_implicit_fs_field4_fs__lp__eq__eq__rp_, _implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, w1, w2, _ctx), _ctx); /*2419*/
            return kk_bool_unbox(_x_x961);
          }
          if (x_1_10465) {
            bool x_2_10468 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs__lp__eq__eq__rp_, (_implicit_fs_field4_fs__lp__eq__eq__rp_, w1, w2, _ctx), _ctx); /*bool*/;
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x964 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__lp__at_new_x_fun965_eq__eq__rp_(_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx); /*2419*/
              return kk_bool_unbox(_x_x964);
            }
            if (x_2_10468) {
              return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs__lp__eq__eq__rp_, (_implicit_fs_field5_fs__lp__eq__eq__rp_, v1, v2, _ctx), _ctx);
            }
            {
              kk_box_drop(v2, _ctx);
              kk_box_drop(v1, _ctx);
              kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
              return false;
            }
          }
          {
            kk_box_drop(w2, _ctx);
            kk_box_drop(w1, _ctx);
            kk_box_drop(v2, _ctx);
            kk_box_drop(v1, _ctx);
            kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
            kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
            return false;
          }
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          kk_box_drop(w2, _ctx);
          kk_box_drop(w1, _ctx);
          kk_box_drop(v2, _ctx);
          kk_box_drop(v1, _ctx);
          kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
          kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
          kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
          return false;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_box_drop(w2, _ctx);
        kk_box_drop(w1, _ctx);
        kk_box_drop(v2, _ctx);
        kk_box_drop(v1, _ctx);
        kk_function_drop(_implicit_fs_thd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_field5_fs__lp__eq__eq__rp_, _ctx);
        kk_function_drop(_implicit_fs_field4_fs__lp__eq__eq__rp_, _ctx);
        return false;
      }
    }
  }
}
 
// Order on tuples


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_cmp_fun968__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs_cmp;
  kk_box_t y1;
  kk_box_t y2;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_cmp_fun968(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_cmp_fun968(kk_function_t _implicit_fs_snd_fs_cmp, kk_box_t y1, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_cmp_fun968__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_cmp_fun968__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_cmp_fun968, kk_context());
  _self->_implicit_fs_snd_fs_cmp = _implicit_fs_snd_fs_cmp;
  _self->y1 = y1;
  _self->y2 = y2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_cmp_fun968(kk_function_t _fself, kk_box_t _b_x164, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_cmp_fun968__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_cmp_fun968__t*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs_cmp = _self->_implicit_fs_snd_fs_cmp; /* (2098, 2098) -> 2099 order */
  kk_box_t y1 = _self->y1; /* 2098 */
  kk_box_t y2 = _self->y2; /* 2098 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10146_166 = kk_std_core_types__order_unbox(_b_x164, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x969;
  if (kk_std_core_types__is_Eq(_y_x10146_166, _ctx)) {
    _x_x969 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    _x_x969 = _y_x10146_166; /*order*/
  }
  return kk_std_core_types__order_box(_x_x969, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple2_fs_cmp(kk_std_core_types__tuple2 _pat_x60__21, kk_std_core_types__tuple2 _pat_x60__38, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), (a, b), ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order) -> e order */ 
  {
    kk_box_t x1 = _pat_x60__21.fst;
    kk_box_t y1 = _pat_x60__21.snd;
    {
      kk_box_t x2 = _pat_x60__38.fst;
      kk_box_t y2 = _pat_x60__38.snd;
      kk_std_core_types__order x_10475 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_cmp, (_implicit_fs_fst_fs_cmp, x1, x2, _ctx), _ctx); /*order*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x967 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_cmp_fun968(_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x967, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_10475, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx);
      }
      {
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
        return x_10475;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_cmp_10279_fun971(kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971, kk_context());
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971(kk_function_t _fself, kk_box_t _b_x168, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_cmp_10279_fun971__t*, _fself, _ctx);
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2163, 2163) -> 2164 order */
  kk_box_t z1 = _self->z1; /* 2163 */
  kk_box_t z2 = _self->z2; /* 2163 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x972;
  kk_std_core_types__order _y_x10152_170 = kk_std_core_types__order_unbox(_b_x168, KK_OWNED, _ctx); /*order*/;
  if (kk_std_core_types__is_Eq(_y_x10152_170, _ctx)) {
    _x_x972 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_cmp, (_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    _x_x972 = _y_x10152_170; /*order*/
  }
  return kk_std_core_types__order_box(_x_x972, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple3_fs__mlift_cmp_10279(kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_std_core_types__order _y_x10151, kk_context_t* _ctx) { /* forall<a,b,e> (?snd/cmp : (a, a) -> e order, ?thd/cmp : (b, b) -> e order, y1 : a, y2 : a, z1 : b, z2 : b, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10151, _ctx)) {
    kk_std_core_types__order x_10482 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x970 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_cmp_10279_fun971(_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x970, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__order _y_x10152_171 = x_10482; /*order*/;
      if (kk_std_core_types__is_Eq(_y_x10152_171, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_cmp, (_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx);
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
        return _y_x10152_171;
      }
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    return _y_x10151;
  }
}
 
// Order on triples


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_cmp_fun976__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_cmp_fun976(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_cmp_fun976(kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_cmp_fun976__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_cmp_fun976__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_cmp_fun976, kk_context());
  _self->_implicit_fs_snd_fs_cmp = _implicit_fs_snd_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_cmp_fun976(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_cmp_fun976__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_cmp_fun976__t*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs_cmp = _self->_implicit_fs_snd_fs_cmp; /* (2162, 2162) -> 2164 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2163, 2163) -> 2164 order */
  kk_box_t y1 = _self->y1; /* 2162 */
  kk_box_t y2 = _self->y2; /* 2162 */
  kk_box_t z1 = _self->z1; /* 2163 */
  kk_box_t z2 = _self->z2; /* 2163 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10151_178 = kk_std_core_types__order_unbox(_b_x173, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x977 = kk_std_core_tuple_tuple3_fs__mlift_cmp_10279(_implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, y1, y2, z1, z2, _y_x10151_178, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x977, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_cmp_fun981__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_cmp_fun981(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_cmp_fun981(kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_cmp_fun981__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_cmp_fun981__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_cmp_fun981, kk_context());
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_cmp_fun981(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_cmp_fun981__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_cmp_fun981__t*, _fself, _ctx);
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2163, 2163) -> 2164 order */
  kk_box_t z1 = _self->z1; /* 2163 */
  kk_box_t z2 = _self->z2; /* 2163 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10152_179 = kk_std_core_types__order_unbox(_b_x175, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x982;
  if (kk_std_core_types__is_Eq(_y_x10152_179, _ctx)) {
    _x_x982 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_cmp, (_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    _x_x982 = _y_x10152_179; /*order*/
  }
  return kk_std_core_types__order_box(_x_x982, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple3_fs_cmp(kk_std_core_types__tuple3 _pat_x66__26, kk_std_core_types__tuple3 _pat_x66__48, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,c,e> ((a, b, c), (a, b, c), ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order, ?thd/cmp : (c, c) -> e order) -> e order */ 
  {
    kk_box_t x1 = _pat_x66__26.fst;
    kk_box_t y1 = _pat_x66__26.snd;
    kk_box_t z1 = _pat_x66__26.thd;
    {
      kk_box_t x2 = _pat_x66__48.fst;
      kk_box_t y2 = _pat_x66__48.snd;
      kk_box_t z2 = _pat_x66__48.thd;
      kk_std_core_types__order x_10488;
      kk_function_t _x_x973 = kk_function_dup(_implicit_fs_fst_fs_cmp, _ctx); /*(2161, 2161) -> 2164 order*/
      x_10488 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x973, (_x_x973, x1, x2, _ctx), _ctx); /*order*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x974;
        kk_function_t _x_x975;
        kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
        _x_x975 = kk_std_core_tuple_tuple3_fs_new_cmp_fun976(_implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, y1, y2, z1, z2, _ctx); /*(2418) -> 2420 2419*/
        _x_x974 = kk_std_core_hnd_yield_extend(_x_x975, _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x974, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_10488, _ctx)) {
        kk_std_core_types__order x_0_10491;
        kk_function_t _x_x978 = kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx); /*(2162, 2162) -> 2164 order*/
        x_0_10491 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x978, (_x_x978, y1, y2, _ctx), _ctx); /*order*/
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x979;
          kk_function_t _x_x980;
          kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
          _x_x980 = kk_std_core_tuple_tuple3_fs_new_cmp_fun981(_implicit_fs_thd_fs_cmp, z1, z2, _ctx); /*(2418) -> 2420 2419*/
          _x_x979 = kk_std_core_hnd_yield_extend(_x_x980, _ctx); /*2419*/
          return kk_std_core_types__order_unbox(_x_x979, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq(x_0_10491, _ctx)) {
          kk_function_t _x_x983 = kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx); /*(2163, 2163) -> 2164 order*/
          return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x983, (_x_x983, z1, z2, _ctx), _ctx);
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          return x_0_10491;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        return x_10488;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_cmp_10281_fun985(kk_function_t _implicit_fs_field4_fs_cmp, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10281_fun985__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2246, 2246) -> 2247 order */
  kk_box_t w1 = _self->w1; /* 2246 */
  kk_box_t w2 = _self->w2; /* 2246 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x986;
  kk_std_core_types__order _y_x10160_183 = kk_std_core_types__order_unbox(_b_x181, KK_OWNED, _ctx); /*order*/;
  if (kk_std_core_types__is_Eq(_y_x10160_183, _ctx)) {
    _x_x986 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_cmp, (_implicit_fs_field4_fs_cmp, w1, w2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    _x_x986 = _y_x10160_183; /*order*/
  }
  return kk_std_core_types__order_box(_x_x986, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple4_fs__mlift_cmp_10281(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_std_core_types__order _y_x10159, kk_context_t* _ctx) { /* forall<a,b,e> (?field4/cmp : (b, b) -> e order, ?thd/cmp : (a, a) -> e order, w1 : b, w2 : b, z1 : a, z2 : a, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10159, _ctx)) {
    kk_std_core_types__order x_10498 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_cmp, (_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x984 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_cmp_10281_fun985(_implicit_fs_field4_fs_cmp, w1, w2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x984, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__order _y_x10160_184 = x_10498; /*order*/;
      if (kk_std_core_types__is_Eq(_y_x10160_184, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_cmp, (_implicit_fs_field4_fs_cmp, w1, w2, _ctx), _ctx);
      }
      {
        kk_box_drop(w2, _ctx);
        kk_box_drop(w1, _ctx);
        kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
        return _y_x10160_184;
      }
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    return _y_x10159;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_cmp_10282_fun988(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_cmp_10282_fun988__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2246, 2246) -> 2247 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2245, 2245) -> 2247 order */
  kk_box_t w1 = _self->w1; /* 2246 */
  kk_box_t w2 = _self->w2; /* 2246 */
  kk_box_t z1 = _self->z1; /* 2245 */
  kk_box_t z2 = _self->z2; /* 2245 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10159_188 = kk_std_core_types__order_unbox(_b_x186, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x989 = kk_std_core_tuple_tuple4_fs__mlift_cmp_10281(_implicit_fs_field4_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, z1, z2, _y_x10159_188, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x989, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple4_fs__mlift_cmp_10282(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_std_core_types__order _y_x10158, kk_context_t* _ctx) { /* forall<a,b,c,e> (?field4/cmp : (c, c) -> e order, ?snd/cmp : (a, a) -> e order, ?thd/cmp : (b, b) -> e order, w1 : c, w2 : c, y1 : a, y2 : a, z1 : b, z2 : b, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10158, _ctx)) {
    kk_std_core_types__order x_10504 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x987 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_cmp_10282_fun988(_implicit_fs_field4_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x987, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple4_fs__mlift_cmp_10281(_implicit_fs_field4_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, z1, z2, x_10504, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    return _y_x10158;
  }
}
 
// Order on quadruples


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_cmp_fun995__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_snd_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun995(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_cmp_fun995(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun995__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun995__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_cmp_fun995, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_snd_fs_cmp = _implicit_fs_snd_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun995(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun995__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun995__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2246, 2246) -> 2247 order */
  kk_function_t _implicit_fs_snd_fs_cmp = _self->_implicit_fs_snd_fs_cmp; /* (2244, 2244) -> 2247 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2245, 2245) -> 2247 order */
  kk_box_t w1 = _self->w1; /* 2246 */
  kk_box_t w2 = _self->w2; /* 2246 */
  kk_box_t y1 = _self->y1; /* 2244 */
  kk_box_t y2 = _self->y2; /* 2244 */
  kk_box_t z1 = _self->z1; /* 2245 */
  kk_box_t z2 = _self->z2; /* 2245 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10158_198 = kk_std_core_types__order_unbox(_b_x190, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x996 = kk_std_core_tuple_tuple4_fs__mlift_cmp_10282(_implicit_fs_field4_fs_cmp, _implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, y1, y2, z1, z2, _y_x10158_198, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x996, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_cmp_fun1000__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun1000(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_cmp_fun1000(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun1000__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun1000__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_cmp_fun1000, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun1000(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun1000__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun1000__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2246, 2246) -> 2247 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2245, 2245) -> 2247 order */
  kk_box_t w1 = _self->w1; /* 2246 */
  kk_box_t w2 = _self->w2; /* 2246 */
  kk_box_t z1 = _self->z1; /* 2245 */
  kk_box_t z2 = _self->z2; /* 2245 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10159_199 = kk_std_core_types__order_unbox(_b_x192, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1001 = kk_std_core_tuple_tuple4_fs__mlift_cmp_10281(_implicit_fs_field4_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, z1, z2, _y_x10159_199, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1001, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_cmp_fun1005__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun1005(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_cmp_fun1005(kk_function_t _implicit_fs_field4_fs_cmp, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun1005__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun1005__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_cmp_fun1005, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_cmp_fun1005(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_cmp_fun1005__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_cmp_fun1005__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2246, 2246) -> 2247 order */
  kk_box_t w1 = _self->w1; /* 2246 */
  kk_box_t w2 = _self->w2; /* 2246 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10160_200 = kk_std_core_types__order_unbox(_b_x194, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1006;
  if (kk_std_core_types__is_Eq(_y_x10160_200, _ctx)) {
    _x_x1006 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_cmp, (_implicit_fs_field4_fs_cmp, w1, w2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    _x_x1006 = _y_x10160_200; /*order*/
  }
  return kk_std_core_types__order_box(_x_x1006, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple4_fs_cmp(kk_std_core_types__tuple4 _pat_x74__26, kk_std_core_types__tuple4 _pat_x74__53, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_function_t _implicit_fs_field4_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,c,d,e> ((a, b, c, d), (a, b, c, d), ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order, ?thd/cmp : (c, c) -> e order, ?field4/cmp : (d, d) -> e order) -> e order */ 
  {
    struct kk_std_core_types_Tuple4* _con_x990 = kk_std_core_types__as_Tuple4(_pat_x74__26, _ctx);
    kk_box_t x1 = _con_x990->fst;
    kk_box_t y1 = _con_x990->snd;
    kk_box_t z1 = _con_x990->thd;
    kk_box_t w1 = _con_x990->field4;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x74__26, _ctx)) {
      kk_datatype_ptr_free(_pat_x74__26, _ctx);
    }
    else {
      kk_box_dup(w1, _ctx);
      kk_box_dup(x1, _ctx);
      kk_box_dup(y1, _ctx);
      kk_box_dup(z1, _ctx);
      kk_datatype_ptr_decref(_pat_x74__26, _ctx);
    }
    {
      struct kk_std_core_types_Tuple4* _con_x991 = kk_std_core_types__as_Tuple4(_pat_x74__53, _ctx);
      kk_box_t x2 = _con_x991->fst;
      kk_box_t y2 = _con_x991->snd;
      kk_box_t z2 = _con_x991->thd;
      kk_box_t w2 = _con_x991->field4;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x74__53, _ctx)) {
        kk_datatype_ptr_free(_pat_x74__53, _ctx);
      }
      else {
        kk_box_dup(w2, _ctx);
        kk_box_dup(x2, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(z2, _ctx);
        kk_datatype_ptr_decref(_pat_x74__53, _ctx);
      }
      kk_std_core_types__order x_10506;
      kk_function_t _x_x992 = kk_function_dup(_implicit_fs_fst_fs_cmp, _ctx); /*(2243, 2243) -> 2247 order*/
      x_10506 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x992, (_x_x992, x1, x2, _ctx), _ctx); /*order*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x993;
        kk_function_t _x_x994;
        kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
        _x_x994 = kk_std_core_tuple_tuple4_fs_new_cmp_fun995(_implicit_fs_field4_fs_cmp, _implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, y1, y2, z1, z2, _ctx); /*(2418) -> 2420 2419*/
        _x_x993 = kk_std_core_hnd_yield_extend(_x_x994, _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x993, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_10506, _ctx)) {
        kk_std_core_types__order x_0_10509;
        kk_function_t _x_x997 = kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx); /*(2244, 2244) -> 2247 order*/
        x_0_10509 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x997, (_x_x997, y1, y2, _ctx), _ctx); /*order*/
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x998;
          kk_function_t _x_x999;
          kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
          kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
          _x_x999 = kk_std_core_tuple_tuple4_fs_new_cmp_fun1000(_implicit_fs_field4_fs_cmp, _implicit_fs_thd_fs_cmp, w1, w2, z1, z2, _ctx); /*(2418) -> 2420 2419*/
          _x_x998 = kk_std_core_hnd_yield_extend(_x_x999, _ctx); /*2419*/
          return kk_std_core_types__order_unbox(_x_x998, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq(x_0_10509, _ctx)) {
          kk_std_core_types__order x_1_10512;
          kk_function_t _x_x1002 = kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx); /*(2245, 2245) -> 2247 order*/
          x_1_10512 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1002, (_x_x1002, z1, z2, _ctx), _ctx); /*order*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1003;
            kk_function_t _x_x1004;
            kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
            _x_x1004 = kk_std_core_tuple_tuple4_fs_new_cmp_fun1005(_implicit_fs_field4_fs_cmp, w1, w2, _ctx); /*(2418) -> 2420 2419*/
            _x_x1003 = kk_std_core_hnd_yield_extend(_x_x1004, _ctx); /*2419*/
            return kk_std_core_types__order_unbox(_x_x1003, KK_OWNED, _ctx);
          }
          if (kk_std_core_types__is_Eq(x_1_10512, _ctx)) {
            kk_function_t _x_x1007 = kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx); /*(2246, 2246) -> 2247 order*/
            return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1007, (_x_x1007, w1, w2, _ctx), _ctx);
          }
          {
            kk_box_drop(w2, _ctx);
            kk_box_drop(w1, _ctx);
            return x_1_10512;
          }
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          kk_box_drop(w2, _ctx);
          kk_box_drop(w1, _ctx);
          return x_0_10509;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_box_drop(w2, _ctx);
        kk_box_drop(w1, _ctx);
        return x_10506;
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10284_fun1009(kk_function_t _implicit_fs_field5_fs_cmp, kk_box_t v1, kk_box_t v2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009, kk_context());
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10284_fun1009__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _x_x1010;
  kk_std_core_types__order _y_x10170_204 = kk_std_core_types__order_unbox(_b_x202, KK_OWNED, _ctx); /*order*/;
  if (kk_std_core_types__is_Eq(_y_x10170_204, _ctx)) {
    _x_x1010 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_cmp, (_implicit_fs_field5_fs_cmp, v1, v2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
    _x_x1010 = _y_x10170_204; /*order*/
  }
  return kk_std_core_types__order_box(_x_x1010, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple5_fs__mlift_cmp_10284(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_std_core_types__order _y_x10169, kk_context_t* _ctx) { /* forall<a,e,b> (?field4/cmp : (a, a) -> e order, ?field5/cmp : (b, b) -> e order, v1 : b, v2 : b, w1 : a, w2 : a, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10169, _ctx)) {
    kk_std_core_types__order x_10519 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_cmp, (_implicit_fs_field4_fs_cmp, w1, w2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1008 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10284_fun1009(_implicit_fs_field5_fs_cmp, v1, v2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x1008, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__order _y_x10170_205 = x_10519; /*order*/;
      if (kk_std_core_types__is_Eq(_y_x10170_205, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_cmp, (_implicit_fs_field5_fs_cmp, v1, v2, _ctx), _ctx);
      }
      {
        kk_box_drop(v2, _ctx);
        kk_box_drop(v1, _ctx);
        kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
        return _y_x10170_205;
      }
    }
  }
  {
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    return _y_x10169;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10285_fun1012(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012(kk_function_t _fself, kk_box_t _b_x207, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10285_fun1012__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2346, 2346) -> 2347 order */
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_box_t w1 = _self->w1; /* 2346 */
  kk_box_t w2 = _self->w2; /* 2346 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10169_209 = kk_std_core_types__order_unbox(_b_x207, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1013 = kk_std_core_tuple_tuple5_fs__mlift_cmp_10284(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, v1, v2, w1, w2, _y_x10169_209, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1013, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple5_fs__mlift_cmp_10285(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_std_core_types__order _y_x10168, kk_context_t* _ctx) { /* forall<a,b,e,c> (?field4/cmp : (b, b) -> e order, ?field5/cmp : (c, c) -> e order, ?thd/cmp : (a, a) -> e order, v1 : c, v2 : c, w1 : b, w2 : b, z1 : a, z2 : a, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10168, _ctx)) {
    kk_std_core_types__order x_10525 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_cmp, (_implicit_fs_thd_fs_cmp, z1, z2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1011 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10285_fun1012(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, v1, v2, w1, w2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x1011, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_cmp_10284(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, v1, v2, w1, w2, x_10525, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    return _y_x10168;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10286_fun1015(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015(kk_function_t _fself, kk_box_t _b_x211, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_cmp_10286_fun1015__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2346, 2346) -> 2347 order */
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2345, 2345) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_box_t w1 = _self->w1; /* 2346 */
  kk_box_t w2 = _self->w2; /* 2346 */
  kk_box_t z1 = _self->z1; /* 2345 */
  kk_box_t z2 = _self->z2; /* 2345 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10168_213 = kk_std_core_types__order_unbox(_b_x211, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1016 = kk_std_core_tuple_tuple5_fs__mlift_cmp_10285(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, z1, z2, _y_x10168_213, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1016, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple5_fs__mlift_cmp_10286(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_std_core_types__order _y_x10167, kk_context_t* _ctx) { /* forall<a,b,c,e,d> (?field4/cmp : (c, c) -> e order, ?field5/cmp : (d, d) -> e order, ?snd/cmp : (a, a) -> e order, ?thd/cmp : (b, b) -> e order, v1 : d, v2 : d, w1 : c, w2 : c, y1 : a, y2 : a, z1 : b, z2 : b, order) -> e order */ 
  if (kk_std_core_types__is_Eq(_y_x10167, _ctx)) {
    kk_std_core_types__order x_10527 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y1, y2, _ctx), _ctx); /*order*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1014 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_cmp_10286_fun1015(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order_unbox(_x_x1014, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_cmp_10285(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, z1, z2, x_10527, _ctx);
    }
  }
  {
    kk_box_drop(z2, _ctx);
    kk_box_drop(z1, _ctx);
    kk_box_drop(y2, _ctx);
    kk_box_drop(y1, _ctx);
    kk_box_drop(w2, _ctx);
    kk_box_drop(w1, _ctx);
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_thd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_cmp, _ctx);
    return _y_x10167;
  }
}
 
// Order on quintuples


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_cmp_fun1022__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_function_t _implicit_fs_snd_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t y1;
  kk_box_t y2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1022(kk_function_t _fself, kk_box_t _b_x215, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_cmp_fun1022(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t y1, kk_box_t y2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1022__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1022__t, 13, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_cmp_fun1022, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->_implicit_fs_snd_fs_cmp = _implicit_fs_snd_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->y1 = y1;
  _self->y2 = y2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1022(kk_function_t _fself, kk_box_t _b_x215, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1022__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1022__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2346, 2346) -> 2347 order */
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_function_t _implicit_fs_snd_fs_cmp = _self->_implicit_fs_snd_fs_cmp; /* (2344, 2344) -> 2347 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2345, 2345) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_box_t w1 = _self->w1; /* 2346 */
  kk_box_t w2 = _self->w2; /* 2346 */
  kk_box_t y1 = _self->y1; /* 2344 */
  kk_box_t y2 = _self->y2; /* 2344 */
  kk_box_t z1 = _self->z1; /* 2345 */
  kk_box_t z2 = _self->z2; /* 2345 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(y1, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10167_226 = kk_std_core_types__order_unbox(_b_x215, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1023 = kk_std_core_tuple_tuple5_fs__mlift_cmp_10286(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, y1, y2, z1, z2, _y_x10167_226, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1023, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_cmp_fun1027__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_function_t _implicit_fs_thd_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1027(kk_function_t _fself, kk_box_t _b_x217, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_cmp_fun1027(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1027__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1027__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_cmp_fun1027, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->_implicit_fs_thd_fs_cmp = _implicit_fs_thd_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1027(kk_function_t _fself, kk_box_t _b_x217, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1027__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1027__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2346, 2346) -> 2347 order */
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_function_t _implicit_fs_thd_fs_cmp = _self->_implicit_fs_thd_fs_cmp; /* (2345, 2345) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_box_t w1 = _self->w1; /* 2346 */
  kk_box_t w2 = _self->w2; /* 2346 */
  kk_box_t z1 = _self->z1; /* 2345 */
  kk_box_t z2 = _self->z2; /* 2345 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10168_227 = kk_std_core_types__order_unbox(_b_x217, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1028 = kk_std_core_tuple_tuple5_fs__mlift_cmp_10285(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, z1, z2, _y_x10168_227, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1028, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_cmp_fun1032__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_cmp;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
  kk_box_t w1;
  kk_box_t w2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1032(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_cmp_fun1032(kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_box_t v1, kk_box_t v2, kk_box_t w1, kk_box_t w2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1032__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1032__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_cmp_fun1032, kk_context());
  _self->_implicit_fs_field4_fs_cmp = _implicit_fs_field4_fs_cmp;
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  _self->w1 = w1;
  _self->w2 = w2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1032(kk_function_t _fself, kk_box_t _b_x219, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1032__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1032__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_cmp = _self->_implicit_fs_field4_fs_cmp; /* (2346, 2346) -> 2347 order */
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_box_t w1 = _self->w1; /* 2346 */
  kk_box_t w2 = _self->w2; /* 2346 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);kk_box_dup(w1, _ctx);kk_box_dup(w2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10169_228 = kk_std_core_types__order_unbox(_b_x219, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1033 = kk_std_core_tuple_tuple5_fs__mlift_cmp_10284(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, v1, v2, w1, w2, _y_x10169_228, _ctx); /*order*/
  return kk_std_core_types__order_box(_x_x1033, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_cmp_fun1037__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs_cmp;
  kk_box_t v1;
  kk_box_t v2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1037(kk_function_t _fself, kk_box_t _b_x221, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_cmp_fun1037(kk_function_t _implicit_fs_field5_fs_cmp, kk_box_t v1, kk_box_t v2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1037__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1037__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_cmp_fun1037, kk_context());
  _self->_implicit_fs_field5_fs_cmp = _implicit_fs_field5_fs_cmp;
  _self->v1 = v1;
  _self->v2 = v2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_cmp_fun1037(kk_function_t _fself, kk_box_t _b_x221, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_cmp_fun1037__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_cmp_fun1037__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs_cmp = _self->_implicit_fs_field5_fs_cmp; /* (2348, 2348) -> 2347 order */
  kk_box_t v1 = _self->v1; /* 2348 */
  kk_box_t v2 = _self->v2; /* 2348 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);kk_box_dup(v1, _ctx);kk_box_dup(v2, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10170_229 = kk_std_core_types__order_unbox(_b_x221, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x1038;
  if (kk_std_core_types__is_Eq(_y_x10170_229, _ctx)) {
    _x_x1038 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_cmp, (_implicit_fs_field5_fs_cmp, v1, v2, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(v2, _ctx);
    kk_box_drop(v1, _ctx);
    kk_function_drop(_implicit_fs_field5_fs_cmp, _ctx);
    _x_x1038 = _y_x10170_229; /*order*/
  }
  return kk_std_core_types__order_box(_x_x1038, _ctx);
}

kk_std_core_types__order kk_std_core_tuple_tuple5_fs_cmp(kk_std_core_types__tuple5 _pat_x86__26, kk_std_core_types__tuple5 _pat_x86__58, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_function_t _implicit_fs_thd_fs_cmp, kk_function_t _implicit_fs_field4_fs_cmp, kk_function_t _implicit_fs_field5_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> ((a, b, c, d, a1), (a, b, c, d, a1), ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order, ?thd/cmp : (c, c) -> e order, ?field4/cmp : (d, d) -> e order, ?field5/cmp : (a1, a1) -> e order) -> e order */ 
  {
    struct kk_std_core_types_Tuple5* _con_x1017 = kk_std_core_types__as_Tuple5(_pat_x86__26, _ctx);
    kk_box_t x1 = _con_x1017->fst;
    kk_box_t y1 = _con_x1017->snd;
    kk_box_t z1 = _con_x1017->thd;
    kk_box_t w1 = _con_x1017->field4;
    kk_box_t v1 = _con_x1017->field5;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x86__26, _ctx)) {
      kk_datatype_ptr_free(_pat_x86__26, _ctx);
    }
    else {
      kk_box_dup(v1, _ctx);
      kk_box_dup(w1, _ctx);
      kk_box_dup(x1, _ctx);
      kk_box_dup(y1, _ctx);
      kk_box_dup(z1, _ctx);
      kk_datatype_ptr_decref(_pat_x86__26, _ctx);
    }
    {
      struct kk_std_core_types_Tuple5* _con_x1018 = kk_std_core_types__as_Tuple5(_pat_x86__58, _ctx);
      kk_box_t x2 = _con_x1018->fst;
      kk_box_t y2 = _con_x1018->snd;
      kk_box_t z2 = _con_x1018->thd;
      kk_box_t w2 = _con_x1018->field4;
      kk_box_t v2 = _con_x1018->field5;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x86__58, _ctx)) {
        kk_datatype_ptr_free(_pat_x86__58, _ctx);
      }
      else {
        kk_box_dup(v2, _ctx);
        kk_box_dup(w2, _ctx);
        kk_box_dup(x2, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(z2, _ctx);
        kk_datatype_ptr_decref(_pat_x86__58, _ctx);
      }
      kk_std_core_types__order x_10529;
      kk_function_t _x_x1019 = kk_function_dup(_implicit_fs_fst_fs_cmp, _ctx); /*(2343, 2343) -> 2347 order*/
      x_10529 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1019, (_x_x1019, x1, x2, _ctx), _ctx); /*order*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1020;
        kk_function_t _x_x1021;
        kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);
        kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
        _x_x1021 = kk_std_core_tuple_tuple5_fs_new_cmp_fun1022(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_snd_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, y1, y2, z1, z2, _ctx); /*(2418) -> 2420 2419*/
        _x_x1020 = kk_std_core_hnd_yield_extend(_x_x1021, _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x1020, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_10529, _ctx)) {
        kk_std_core_types__order x_0_10532;
        kk_function_t _x_x1024 = kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx); /*(2344, 2344) -> 2347 order*/
        x_0_10532 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1024, (_x_x1024, y1, y2, _ctx), _ctx); /*order*/
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x1025;
          kk_function_t _x_x1026;
          kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
          kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);
          kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx);
          _x_x1026 = kk_std_core_tuple_tuple5_fs_new_cmp_fun1027(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, _implicit_fs_thd_fs_cmp, v1, v2, w1, w2, z1, z2, _ctx); /*(2418) -> 2420 2419*/
          _x_x1025 = kk_std_core_hnd_yield_extend(_x_x1026, _ctx); /*2419*/
          return kk_std_core_types__order_unbox(_x_x1025, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq(x_0_10532, _ctx)) {
          kk_std_core_types__order x_1_10535;
          kk_function_t _x_x1029 = kk_function_dup(_implicit_fs_thd_fs_cmp, _ctx); /*(2345, 2345) -> 2347 order*/
          x_1_10535 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1029, (_x_x1029, z1, z2, _ctx), _ctx); /*order*/
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x1030;
            kk_function_t _x_x1031;
            kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx);
            kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);
            _x_x1031 = kk_std_core_tuple_tuple5_fs_new_cmp_fun1032(_implicit_fs_field4_fs_cmp, _implicit_fs_field5_fs_cmp, v1, v2, w1, w2, _ctx); /*(2418) -> 2420 2419*/
            _x_x1030 = kk_std_core_hnd_yield_extend(_x_x1031, _ctx); /*2419*/
            return kk_std_core_types__order_unbox(_x_x1030, KK_OWNED, _ctx);
          }
          if (kk_std_core_types__is_Eq(x_1_10535, _ctx)) {
            kk_std_core_types__order x_2_10538;
            kk_function_t _x_x1034 = kk_function_dup(_implicit_fs_field4_fs_cmp, _ctx); /*(2346, 2346) -> 2347 order*/
            x_2_10538 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1034, (_x_x1034, w1, w2, _ctx), _ctx); /*order*/
            if (kk_yielding(kk_context())) {
              kk_box_t _x_x1035;
              kk_function_t _x_x1036;
              kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx);
              _x_x1036 = kk_std_core_tuple_tuple5_fs_new_cmp_fun1037(_implicit_fs_field5_fs_cmp, v1, v2, _ctx); /*(2418) -> 2420 2419*/
              _x_x1035 = kk_std_core_hnd_yield_extend(_x_x1036, _ctx); /*2419*/
              return kk_std_core_types__order_unbox(_x_x1035, KK_OWNED, _ctx);
            }
            if (kk_std_core_types__is_Eq(x_2_10538, _ctx)) {
              kk_function_t _x_x1039 = kk_function_dup(_implicit_fs_field5_fs_cmp, _ctx); /*(2348, 2348) -> 2347 order*/
              return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1039, (_x_x1039, v1, v2, _ctx), _ctx);
            }
            {
              kk_box_drop(v2, _ctx);
              kk_box_drop(v1, _ctx);
              return x_2_10538;
            }
          }
          {
            kk_box_drop(w2, _ctx);
            kk_box_drop(w1, _ctx);
            kk_box_drop(v2, _ctx);
            kk_box_drop(v1, _ctx);
            return x_1_10535;
          }
        }
        {
          kk_box_drop(z2, _ctx);
          kk_box_drop(z1, _ctx);
          kk_box_drop(w2, _ctx);
          kk_box_drop(w1, _ctx);
          kk_box_drop(v2, _ctx);
          kk_box_drop(v1, _ctx);
          return x_0_10532;
        }
      }
      {
        kk_box_drop(z2, _ctx);
        kk_box_drop(z1, _ctx);
        kk_box_drop(y2, _ctx);
        kk_box_drop(y1, _ctx);
        kk_box_drop(w2, _ctx);
        kk_box_drop(w1, _ctx);
        kk_box_drop(v2, _ctx);
        kk_box_drop(v1, _ctx);
        return x_10529;
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_tuple_tuple2_fs__mlift_order2_10287(kk_box_t z1, kk_std_core_types__order2 _y_x10179, kk_context_t* _ctx) { /* forall<a,b,e> (z1 : a, order2<b>) -> e order2<(a, b)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10179, _ctx)) {
    kk_box_t z2 = _y_x10179._cons.Eq2.eq;
    kk_box_t _x_x1040;
    kk_std_core_types__tuple2 _x_x1041 = kk_std_core_types__new_Tuple2(z1, z2, _ctx); /*(134, 135)*/
    _x_x1040 = kk_std_core_types__tuple2_box(_x_x1041, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x1040, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10179, _ctx)) {
    kk_box_t x2_sq_ = _y_x10179._cons.Lt2.lt;
    kk_box_t y2_sq_ = _y_x10179._cons.Lt2.gt;
    kk_box_t _x_x1042;
    kk_std_core_types__tuple2 _x_x1043;
    kk_box_t _x_x1044 = kk_box_dup(z1, _ctx); /*2697*/
    _x_x1043 = kk_std_core_types__new_Tuple2(_x_x1044, x2_sq_, _ctx); /*(134, 135)*/
    _x_x1042 = kk_std_core_types__tuple2_box(_x_x1043, _ctx); /*105*/
    kk_box_t _x_x1045;
    kk_std_core_types__tuple2 _x_x1046 = kk_std_core_types__new_Tuple2(z1, y2_sq_, _ctx); /*(134, 135)*/
    _x_x1045 = kk_std_core_types__tuple2_box(_x_x1046, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1042, _x_x1045, _ctx);
  }
  {
    kk_box_t y2_0_sq_ = _y_x10179._cons.Gt2.lt;
    kk_box_t x2_0_sq_ = _y_x10179._cons.Gt2.gt;
    kk_box_t _x_x1047;
    kk_std_core_types__tuple2 _x_x1048;
    kk_box_t _x_x1049 = kk_box_dup(z1, _ctx); /*2697*/
    _x_x1048 = kk_std_core_types__new_Tuple2(_x_x1049, y2_0_sq_, _ctx); /*(134, 135)*/
    _x_x1047 = kk_std_core_types__tuple2_box(_x_x1048, _ctx); /*105*/
    kk_box_t _x_x1050;
    kk_std_core_types__tuple2 _x_x1051 = kk_std_core_types__new_Tuple2(z1, x2_0_sq_, _ctx); /*(134, 135)*/
    _x_x1050 = kk_std_core_types__tuple2_box(_x_x1051, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1047, _x_x1050, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053__t {
  struct kk_function_s _base;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_order2_10288_fun1053(kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053, kk_context());
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053(kk_function_t _fself, kk_box_t _b_x243, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_order2_10288_fun1053__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 2697 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10179_253 = kk_std_core_types__order2_unbox(_b_x243, KK_OWNED, _ctx); /*order2<2698>*/;
  kk_std_core_types__order2 _x_x1054 = kk_std_core_tuple_tuple2_fs__mlift_order2_10287(z1, _y_x10179_253, _ctx); /*order2<(2697, 2698)>*/
  return kk_std_core_types__order2_box(_x_x1054, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple2_fs__mlift_order2_10288(kk_function_t _implicit_fs_b_fs_order2, kk_box_t x2, kk_box_t y2, kk_std_core_types__order2 _y_x10178, kk_context_t* _ctx) { /* forall<a,b,e> (?b/order2 : (b, b) -> e order2<b>, x2 : b, y2 : b, order2<a>) -> e order2<(a, b)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10178, _ctx)) {
    kk_box_t z1 = _y_x10178._cons.Eq2.eq;
    kk_std_core_types__order2 x_10545 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_b_fs_order2, (_implicit_fs_b_fs_order2, x2, y2, _ctx), _ctx); /*order2<2698>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10545, _ctx);
      kk_box_t _x_x1052 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__new_mlift_order2_10288_fun1053(z1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1052, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple2_fs__mlift_order2_10287(z1, x_10545, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10178, _ctx)) {
    kk_box_t x1_sq_ = _y_x10178._cons.Lt2.lt;
    kk_box_t y1_sq_ = _y_x10178._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1055;
    kk_std_core_types__tuple2 _x_x1056 = kk_std_core_types__new_Tuple2(x1_sq_, x2, _ctx); /*(134, 135)*/
    _x_x1055 = kk_std_core_types__tuple2_box(_x_x1056, _ctx); /*105*/
    kk_box_t _x_x1057;
    kk_std_core_types__tuple2 _x_x1058 = kk_std_core_types__new_Tuple2(y1_sq_, y2, _ctx); /*(134, 135)*/
    _x_x1057 = kk_std_core_types__tuple2_box(_x_x1058, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1055, _x_x1057, _ctx);
  }
  {
    kk_box_t y1_0_sq_ = _y_x10178._cons.Gt2.lt;
    kk_box_t x1_0_sq_ = _y_x10178._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1059;
    kk_std_core_types__tuple2 _x_x1060 = kk_std_core_types__new_Tuple2(y1_0_sq_, y2, _ctx); /*(134, 135)*/
    _x_x1059 = kk_std_core_types__tuple2_box(_x_x1060, _ctx); /*105*/
    kk_box_t _x_x1061;
    kk_std_core_types__tuple2 _x_x1062 = kk_std_core_types__new_Tuple2(x1_0_sq_, x2, _ctx); /*(134, 135)*/
    _x_x1061 = kk_std_core_types__tuple2_box(_x_x1062, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1059, _x_x1061, _ctx);
  }
}
 
// order2 of tuple2 values


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_order2_fun1066__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_b_fs_order2;
  kk_box_t x2;
  kk_box_t y2;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_order2_fun1066(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_order2_fun1066(kk_function_t _implicit_fs_b_fs_order2, kk_box_t x2, kk_box_t y2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_order2_fun1066__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_order2_fun1066__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_order2_fun1066, kk_context());
  _self->_implicit_fs_b_fs_order2 = _implicit_fs_b_fs_order2;
  _self->x2 = x2;
  _self->y2 = y2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_order2_fun1066(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_order2_fun1066__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_order2_fun1066__t*, _fself, _ctx);
  kk_function_t _implicit_fs_b_fs_order2 = _self->_implicit_fs_b_fs_order2; /* (2698, 2698) -> 2699 order2<2698> */
  kk_box_t x2 = _self->x2; /* 2698 */
  kk_box_t y2 = _self->y2; /* 2698 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_b_fs_order2, _ctx);kk_box_dup(x2, _ctx);kk_box_dup(y2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10178_278 = kk_std_core_types__order2_unbox(_b_x255, KK_OWNED, _ctx); /*order2<2697>*/;
  kk_std_core_types__order2 _x_x1067 = kk_std_core_tuple_tuple2_fs__mlift_order2_10288(_implicit_fs_b_fs_order2, x2, y2, _y_x10178_278, _ctx); /*order2<(2697, 2698)>*/
  return kk_std_core_types__order2_box(_x_x1067, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_order2_fun1070__t {
  struct kk_function_s _base;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_order2_fun1070(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_order2_fun1070(kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_order2_fun1070__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_order2_fun1070__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_order2_fun1070, kk_context());
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_order2_fun1070(kk_function_t _fself, kk_box_t _b_x257, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_order2_fun1070__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_order2_fun1070__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 2697 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10179_279 = kk_std_core_types__order2_unbox(_b_x257, KK_OWNED, _ctx); /*order2<2698>*/;
  kk_std_core_types__order2 _x_x1071 = kk_std_core_tuple_tuple2_fs__mlift_order2_10287(z1, _y_x10179_279, _ctx); /*order2<(2697, 2698)>*/
  return kk_std_core_types__order2_box(_x_x1071, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple2_fs_order2(kk_std_core_types__tuple2 _pat_x104__24, kk_std_core_types__tuple2 _pat_x104__42, kk_function_t _implicit_fs_a_fs_order2, kk_function_t _implicit_fs_b_fs_order2, kk_context_t* _ctx) { /* forall<a,b,e> ((a, b), (a, b), ?a/order2 : (a, a) -> e order2<a>, ?b/order2 : (b, b) -> e order2<b>) -> e order2<(a, b)> */ 
  {
    kk_box_t x1 = _pat_x104__24.fst;
    kk_box_t x2 = _pat_x104__24.snd;
    {
      kk_box_t y1 = _pat_x104__42.fst;
      kk_box_t y2 = _pat_x104__42.snd;
      kk_std_core_types__order2 x_10547;
      kk_function_t _x_x1063 = kk_function_dup(_implicit_fs_a_fs_order2, _ctx); /*(2697, 2697) -> 2699 order2<2697>*/
      x_10547 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1063, (_x_x1063, x1, y1, _ctx), _ctx); /*order2<2697>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__order2_drop(x_10547, _ctx);
        kk_box_t _x_x1064;
        kk_function_t _x_x1065;
        kk_function_dup(_implicit_fs_b_fs_order2, _ctx);
        _x_x1065 = kk_std_core_tuple_tuple2_fs_new_order2_fun1066(_implicit_fs_b_fs_order2, x2, y2, _ctx); /*(2418) -> 2420 2419*/
        _x_x1064 = kk_std_core_hnd_yield_extend(_x_x1065, _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x1064, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_10547, _ctx)) {
        kk_box_t z1 = x_10547._cons.Eq2.eq;
        kk_std_core_types__order2 x_0_10550;
        kk_function_t _x_x1068 = kk_function_dup(_implicit_fs_b_fs_order2, _ctx); /*(2698, 2698) -> 2699 order2<2698>*/
        x_0_10550 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1068, (_x_x1068, x2, y2, _ctx), _ctx); /*order2<2698>*/
        if (kk_yielding(kk_context())) {
          kk_std_core_types__order2_drop(x_0_10550, _ctx);
          kk_box_t _x_x1069 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_order2_fun1070(z1, _ctx), _ctx); /*2419*/
          return kk_std_core_types__order2_unbox(_x_x1069, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq2(x_0_10550, _ctx)) {
          kk_box_t z2 = x_0_10550._cons.Eq2.eq;
          kk_box_t _x_x1072;
          kk_std_core_types__tuple2 _x_x1073 = kk_std_core_types__new_Tuple2(z1, z2, _ctx); /*(134, 135)*/
          _x_x1072 = kk_std_core_types__tuple2_box(_x_x1073, _ctx); /*105*/
          return kk_std_core_types__new_Eq2(_x_x1072, _ctx);
        }
        if (kk_std_core_types__is_Lt2(x_0_10550, _ctx)) {
          kk_box_t x2_sq_ = x_0_10550._cons.Lt2.lt;
          kk_box_t y2_sq_ = x_0_10550._cons.Lt2.gt;
          kk_box_t _x_x1074;
          kk_std_core_types__tuple2 _x_x1075;
          kk_box_t _x_x1076 = kk_box_dup(z1, _ctx); /*2697*/
          _x_x1075 = kk_std_core_types__new_Tuple2(_x_x1076, x2_sq_, _ctx); /*(134, 135)*/
          _x_x1074 = kk_std_core_types__tuple2_box(_x_x1075, _ctx); /*105*/
          kk_box_t _x_x1077;
          kk_std_core_types__tuple2 _x_x1078 = kk_std_core_types__new_Tuple2(z1, y2_sq_, _ctx); /*(134, 135)*/
          _x_x1077 = kk_std_core_types__tuple2_box(_x_x1078, _ctx); /*105*/
          return kk_std_core_types__new_Lt2(_x_x1074, _x_x1077, _ctx);
        }
        {
          kk_box_t y2_0_sq_ = x_0_10550._cons.Gt2.lt;
          kk_box_t x2_0_sq_ = x_0_10550._cons.Gt2.gt;
          kk_box_t _x_x1079;
          kk_std_core_types__tuple2 _x_x1080;
          kk_box_t _x_x1081 = kk_box_dup(z1, _ctx); /*2697*/
          _x_x1080 = kk_std_core_types__new_Tuple2(_x_x1081, y2_0_sq_, _ctx); /*(134, 135)*/
          _x_x1079 = kk_std_core_types__tuple2_box(_x_x1080, _ctx); /*105*/
          kk_box_t _x_x1082;
          kk_std_core_types__tuple2 _x_x1083 = kk_std_core_types__new_Tuple2(z1, x2_0_sq_, _ctx); /*(134, 135)*/
          _x_x1082 = kk_std_core_types__tuple2_box(_x_x1083, _ctx); /*105*/
          return kk_std_core_types__new_Gt2(_x_x1079, _x_x1082, _ctx);
        }
      }
      if (kk_std_core_types__is_Lt2(x_10547, _ctx)) {
        kk_box_t x1_sq_ = x_10547._cons.Lt2.lt;
        kk_box_t y1_sq_ = x_10547._cons.Lt2.gt;
        kk_box_t _x_x1084;
        kk_std_core_types__tuple2 _x_x1085 = kk_std_core_types__new_Tuple2(x1_sq_, x2, _ctx); /*(134, 135)*/
        _x_x1084 = kk_std_core_types__tuple2_box(_x_x1085, _ctx); /*105*/
        kk_box_t _x_x1086;
        kk_std_core_types__tuple2 _x_x1087 = kk_std_core_types__new_Tuple2(y1_sq_, y2, _ctx); /*(134, 135)*/
        _x_x1086 = kk_std_core_types__tuple2_box(_x_x1087, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x1084, _x_x1086, _ctx);
      }
      {
        kk_box_t y1_0_sq_ = x_10547._cons.Gt2.lt;
        kk_box_t x1_0_sq_ = x_10547._cons.Gt2.gt;
        kk_box_t _x_x1088;
        kk_std_core_types__tuple2 _x_x1089 = kk_std_core_types__new_Tuple2(y1_0_sq_, y2, _ctx); /*(134, 135)*/
        _x_x1088 = kk_std_core_types__tuple2_box(_x_x1089, _ctx); /*105*/
        kk_box_t _x_x1090;
        kk_std_core_types__tuple2 _x_x1091 = kk_std_core_types__new_Tuple2(x1_0_sq_, x2, _ctx); /*(134, 135)*/
        _x_x1090 = kk_std_core_types__tuple2_box(_x_x1091, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x1088, _x_x1090, _ctx);
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_tuple_tuple3_fs__mlift_order2_10289(kk_box_t z1, kk_box_t z2, kk_std_core_types__order2 _y_x10185, kk_context_t* _ctx) { /* forall<a,b,c,e> (z1 : a, z2 : b, order2<c>) -> e order2<(a, b, c)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10185, _ctx)) {
    kk_box_t z3 = _y_x10185._cons.Eq2.eq;
    kk_box_t _x_x1092;
    kk_std_core_types__tuple3 _x_x1093 = kk_std_core_types__new_Tuple3(z1, z2, z3, _ctx); /*(141, 142, 143)*/
    _x_x1092 = kk_std_core_types__tuple3_box(_x_x1093, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x1092, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10185, _ctx)) {
    kk_box_t x3_sq_ = _y_x10185._cons.Lt2.lt;
    kk_box_t y3_sq_ = _y_x10185._cons.Lt2.gt;
    kk_box_t _x_x1094;
    kk_std_core_types__tuple3 _x_x1095;
    kk_box_t _x_x1096 = kk_box_dup(z1, _ctx); /*3160*/
    kk_box_t _x_x1097 = kk_box_dup(z2, _ctx); /*3161*/
    _x_x1095 = kk_std_core_types__new_Tuple3(_x_x1096, _x_x1097, x3_sq_, _ctx); /*(141, 142, 143)*/
    _x_x1094 = kk_std_core_types__tuple3_box(_x_x1095, _ctx); /*105*/
    kk_box_t _x_x1098;
    kk_std_core_types__tuple3 _x_x1099 = kk_std_core_types__new_Tuple3(z1, z2, y3_sq_, _ctx); /*(141, 142, 143)*/
    _x_x1098 = kk_std_core_types__tuple3_box(_x_x1099, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1094, _x_x1098, _ctx);
  }
  {
    kk_box_t y3_0_sq_ = _y_x10185._cons.Gt2.lt;
    kk_box_t x3_0_sq_ = _y_x10185._cons.Gt2.gt;
    kk_box_t _x_x1100;
    kk_std_core_types__tuple3 _x_x1101;
    kk_box_t _x_x1102 = kk_box_dup(z1, _ctx); /*3160*/
    kk_box_t _x_x1103 = kk_box_dup(z2, _ctx); /*3161*/
    _x_x1101 = kk_std_core_types__new_Tuple3(_x_x1102, _x_x1103, y3_0_sq_, _ctx); /*(141, 142, 143)*/
    _x_x1100 = kk_std_core_types__tuple3_box(_x_x1101, _ctx); /*105*/
    kk_box_t _x_x1104;
    kk_std_core_types__tuple3 _x_x1105 = kk_std_core_types__new_Tuple3(z1, z2, x3_0_sq_, _ctx); /*(141, 142, 143)*/
    _x_x1104 = kk_std_core_types__tuple3_box(_x_x1105, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1100, _x_x1104, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_order2_10290_fun1107(kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107(kk_function_t _fself, kk_box_t _b_x291, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_order2_10290_fun1107__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 3160 */
  kk_box_t z2 = _self->z2; /* 3161 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10185_301 = kk_std_core_types__order2_unbox(_b_x291, KK_OWNED, _ctx); /*order2<3162>*/;
  kk_std_core_types__order2 _x_x1108 = kk_std_core_tuple_tuple3_fs__mlift_order2_10289(z1, z2, _y_x10185_301, _ctx); /*order2<(3160, 3161, 3162)>*/
  return kk_std_core_types__order2_box(_x_x1108, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple3_fs__mlift_order2_10290(kk_function_t _implicit_fs_c_fs_order2, kk_box_t x3, kk_box_t y3, kk_box_t z1, kk_std_core_types__order2 _y_x10184, kk_context_t* _ctx) { /* forall<a,b,c,e> (?c/order2 : (c, c) -> e order2<c>, x3 : c, y3 : c, z1 : a, order2<b>) -> e order2<(a, b, c)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10184, _ctx)) {
    kk_box_t z2 = _y_x10184._cons.Eq2.eq;
    kk_std_core_types__order2 x_10553 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_c_fs_order2, (_implicit_fs_c_fs_order2, x3, y3, _ctx), _ctx); /*order2<3162>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10553, _ctx);
      kk_box_t _x_x1106 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_order2_10290_fun1107(z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1106, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple3_fs__mlift_order2_10289(z1, z2, x_10553, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10184, _ctx)) {
    kk_box_t x2_sq_ = _y_x10184._cons.Lt2.lt;
    kk_box_t y2_sq_ = _y_x10184._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1109;
    kk_std_core_types__tuple3 _x_x1110;
    kk_box_t _x_x1111 = kk_box_dup(z1, _ctx); /*3160*/
    _x_x1110 = kk_std_core_types__new_Tuple3(_x_x1111, x2_sq_, x3, _ctx); /*(141, 142, 143)*/
    _x_x1109 = kk_std_core_types__tuple3_box(_x_x1110, _ctx); /*105*/
    kk_box_t _x_x1112;
    kk_std_core_types__tuple3 _x_x1113 = kk_std_core_types__new_Tuple3(z1, y2_sq_, y3, _ctx); /*(141, 142, 143)*/
    _x_x1112 = kk_std_core_types__tuple3_box(_x_x1113, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1109, _x_x1112, _ctx);
  }
  {
    kk_box_t y2_0_sq_ = _y_x10184._cons.Gt2.lt;
    kk_box_t x2_0_sq_ = _y_x10184._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1114;
    kk_std_core_types__tuple3 _x_x1115;
    kk_box_t _x_x1116 = kk_box_dup(z1, _ctx); /*3160*/
    _x_x1115 = kk_std_core_types__new_Tuple3(_x_x1116, y2_0_sq_, y3, _ctx); /*(141, 142, 143)*/
    _x_x1114 = kk_std_core_types__tuple3_box(_x_x1115, _ctx); /*105*/
    kk_box_t _x_x1117;
    kk_std_core_types__tuple3 _x_x1118 = kk_std_core_types__new_Tuple3(z1, x2_0_sq_, x3, _ctx); /*(141, 142, 143)*/
    _x_x1117 = kk_std_core_types__tuple3_box(_x_x1118, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1114, _x_x1117, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_box_t x3;
  kk_box_t y3;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_order2_10291_fun1120(kk_function_t _implicit_fs_c_fs_order2, kk_box_t x3, kk_box_t y3, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->x3 = x3;
  _self->y3 = y3;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120(kk_function_t _fself, kk_box_t _b_x303, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_order2_10291_fun1120__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3162, 3162) -> 3163 order2<3162> */
  kk_box_t x3 = _self->x3; /* 3162 */
  kk_box_t y3 = _self->y3; /* 3162 */
  kk_box_t z1 = _self->z1; /* 3160 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10184_313 = kk_std_core_types__order2_unbox(_b_x303, KK_OWNED, _ctx); /*order2<3161>*/;
  kk_std_core_types__order2 _x_x1121 = kk_std_core_tuple_tuple3_fs__mlift_order2_10290(_implicit_fs_c_fs_order2, x3, y3, z1, _y_x10184_313, _ctx); /*order2<(3160, 3161, 3162)>*/
  return kk_std_core_types__order2_box(_x_x1121, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple3_fs__mlift_order2_10291(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t y2, kk_box_t y3, kk_std_core_types__order2 _y_x10183, kk_context_t* _ctx) { /* forall<a,b,c,e> (?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>, x2 : b, x3 : c, y2 : b, y3 : c, order2<a>) -> e order2<(a, b, c)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10183, _ctx)) {
    kk_box_t z1 = _y_x10183._cons.Eq2.eq;
    kk_std_core_types__order2 x_10555 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_b_fs_order2, (_implicit_fs_b_fs_order2, x2, y2, _ctx), _ctx); /*order2<3161>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10555, _ctx);
      kk_box_t _x_x1119 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_order2_10291_fun1120(_implicit_fs_c_fs_order2, x3, y3, z1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1119, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple3_fs__mlift_order2_10290(_implicit_fs_c_fs_order2, x3, y3, z1, x_10555, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10183, _ctx)) {
    kk_box_t x1_sq_ = _y_x10183._cons.Lt2.lt;
    kk_box_t y1_sq_ = _y_x10183._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1122;
    kk_std_core_types__tuple3 _x_x1123 = kk_std_core_types__new_Tuple3(x1_sq_, x2, x3, _ctx); /*(141, 142, 143)*/
    _x_x1122 = kk_std_core_types__tuple3_box(_x_x1123, _ctx); /*105*/
    kk_box_t _x_x1124;
    kk_std_core_types__tuple3 _x_x1125 = kk_std_core_types__new_Tuple3(y1_sq_, y2, y3, _ctx); /*(141, 142, 143)*/
    _x_x1124 = kk_std_core_types__tuple3_box(_x_x1125, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1122, _x_x1124, _ctx);
  }
  {
    kk_box_t y1_0_sq_ = _y_x10183._cons.Gt2.lt;
    kk_box_t x1_0_sq_ = _y_x10183._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1126;
    kk_std_core_types__tuple3 _x_x1127 = kk_std_core_types__new_Tuple3(y1_0_sq_, y2, y3, _ctx); /*(141, 142, 143)*/
    _x_x1126 = kk_std_core_types__tuple3_box(_x_x1127, _ctx); /*105*/
    kk_box_t _x_x1128;
    kk_std_core_types__tuple3 _x_x1129 = kk_std_core_types__new_Tuple3(x1_0_sq_, x2, x3, _ctx); /*(141, 142, 143)*/
    _x_x1128 = kk_std_core_types__tuple3_box(_x_x1129, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1126, _x_x1128, _ctx);
  }
}
 
// order2 of tuple3 values


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_order2_fun1133__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_b_fs_order2;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_box_t x2;
  kk_box_t x3;
  kk_box_t y2;
  kk_box_t y3;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1133(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_order2_fun1133(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t y2, kk_box_t y3, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1133__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1133__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_order2_fun1133, kk_context());
  _self->_implicit_fs_b_fs_order2 = _implicit_fs_b_fs_order2;
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->x2 = x2;
  _self->x3 = x3;
  _self->y2 = y2;
  _self->y3 = y3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1133(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1133__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1133__t*, _fself, _ctx);
  kk_function_t _implicit_fs_b_fs_order2 = _self->_implicit_fs_b_fs_order2; /* (3161, 3161) -> 3163 order2<3161> */
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3162, 3162) -> 3163 order2<3162> */
  kk_box_t x2 = _self->x2; /* 3161 */
  kk_box_t x3 = _self->x3; /* 3162 */
  kk_box_t y2 = _self->y2; /* 3161 */
  kk_box_t y3 = _self->y3; /* 3162 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_b_fs_order2, _ctx);kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_box_dup(x2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(y3, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10183_349 = kk_std_core_types__order2_unbox(_b_x315, KK_OWNED, _ctx); /*order2<3160>*/;
  kk_std_core_types__order2 _x_x1134 = kk_std_core_tuple_tuple3_fs__mlift_order2_10291(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, x2, x3, y2, y3, _y_x10183_349, _ctx); /*order2<(3160, 3161, 3162)>*/
  return kk_std_core_types__order2_box(_x_x1134, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_order2_fun1138__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_box_t x3;
  kk_box_t y3;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1138(kk_function_t _fself, kk_box_t _b_x317, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_order2_fun1138(kk_function_t _implicit_fs_c_fs_order2, kk_box_t x3, kk_box_t y3, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1138__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1138__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_order2_fun1138, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->x3 = x3;
  _self->y3 = y3;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1138(kk_function_t _fself, kk_box_t _b_x317, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1138__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1138__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3162, 3162) -> 3163 order2<3162> */
  kk_box_t x3 = _self->x3; /* 3162 */
  kk_box_t y3 = _self->y3; /* 3162 */
  kk_box_t z1 = _self->z1; /* 3160 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10184_350 = kk_std_core_types__order2_unbox(_b_x317, KK_OWNED, _ctx); /*order2<3161>*/;
  kk_std_core_types__order2 _x_x1139 = kk_std_core_tuple_tuple3_fs__mlift_order2_10290(_implicit_fs_c_fs_order2, x3, y3, z1, _y_x10184_350, _ctx); /*order2<(3160, 3161, 3162)>*/
  return kk_std_core_types__order2_box(_x_x1139, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_order2_fun1142__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1142(kk_function_t _fself, kk_box_t _b_x319, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_order2_fun1142(kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1142__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1142__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_order2_fun1142, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_order2_fun1142(kk_function_t _fself, kk_box_t _b_x319, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_order2_fun1142__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_order2_fun1142__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 3160 */
  kk_box_t z2 = _self->z2; /* 3161 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10185_351 = kk_std_core_types__order2_unbox(_b_x319, KK_OWNED, _ctx); /*order2<3162>*/;
  kk_std_core_types__order2 _x_x1143 = kk_std_core_tuple_tuple3_fs__mlift_order2_10289(z1, z2, _y_x10185_351, _ctx); /*order2<(3160, 3161, 3162)>*/
  return kk_std_core_types__order2_box(_x_x1143, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple3_fs_order2(kk_std_core_types__tuple3 _pat_x115__24, kk_std_core_types__tuple3 _pat_x115__49, kk_function_t _implicit_fs_a_fs_order2, kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_context_t* _ctx) { /* forall<a,b,c,e> ((a, b, c), (a, b, c), ?a/order2 : (a, a) -> e order2<a>, ?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>) -> e order2<(a, b, c)> */ 
  {
    kk_box_t x1 = _pat_x115__24.fst;
    kk_box_t x2 = _pat_x115__24.snd;
    kk_box_t x3 = _pat_x115__24.thd;
    {
      kk_box_t y1 = _pat_x115__49.fst;
      kk_box_t y2 = _pat_x115__49.snd;
      kk_box_t y3 = _pat_x115__49.thd;
      kk_std_core_types__order2 x_10557;
      kk_function_t _x_x1130 = kk_function_dup(_implicit_fs_a_fs_order2, _ctx); /*(3160, 3160) -> 3163 order2<3160>*/
      x_10557 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1130, (_x_x1130, x1, y1, _ctx), _ctx); /*order2<3160>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__order2_drop(x_10557, _ctx);
        kk_box_t _x_x1131;
        kk_function_t _x_x1132;
        kk_function_dup(_implicit_fs_b_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
        _x_x1132 = kk_std_core_tuple_tuple3_fs_new_order2_fun1133(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, x2, x3, y2, y3, _ctx); /*(2418) -> 2420 2419*/
        _x_x1131 = kk_std_core_hnd_yield_extend(_x_x1132, _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x1131, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_10557, _ctx)) {
        kk_box_t z1 = x_10557._cons.Eq2.eq;
        kk_std_core_types__order2 x_0_10560;
        kk_function_t _x_x1135 = kk_function_dup(_implicit_fs_b_fs_order2, _ctx); /*(3161, 3161) -> 3163 order2<3161>*/
        x_0_10560 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1135, (_x_x1135, x2, y2, _ctx), _ctx); /*order2<3161>*/
        if (kk_yielding(kk_context())) {
          kk_std_core_types__order2_drop(x_0_10560, _ctx);
          kk_box_t _x_x1136;
          kk_function_t _x_x1137;
          kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
          _x_x1137 = kk_std_core_tuple_tuple3_fs_new_order2_fun1138(_implicit_fs_c_fs_order2, x3, y3, z1, _ctx); /*(2418) -> 2420 2419*/
          _x_x1136 = kk_std_core_hnd_yield_extend(_x_x1137, _ctx); /*2419*/
          return kk_std_core_types__order2_unbox(_x_x1136, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq2(x_0_10560, _ctx)) {
          kk_box_t z2 = x_0_10560._cons.Eq2.eq;
          kk_std_core_types__order2 x_1_10563;
          kk_function_t _x_x1140 = kk_function_dup(_implicit_fs_c_fs_order2, _ctx); /*(3162, 3162) -> 3163 order2<3162>*/
          x_1_10563 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1140, (_x_x1140, x3, y3, _ctx), _ctx); /*order2<3162>*/
          if (kk_yielding(kk_context())) {
            kk_std_core_types__order2_drop(x_1_10563, _ctx);
            kk_box_t _x_x1141 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_order2_fun1142(z1, z2, _ctx), _ctx); /*2419*/
            return kk_std_core_types__order2_unbox(_x_x1141, KK_OWNED, _ctx);
          }
          if (kk_std_core_types__is_Eq2(x_1_10563, _ctx)) {
            kk_box_t z3 = x_1_10563._cons.Eq2.eq;
            kk_box_t _x_x1144;
            kk_std_core_types__tuple3 _x_x1145 = kk_std_core_types__new_Tuple3(z1, z2, z3, _ctx); /*(141, 142, 143)*/
            _x_x1144 = kk_std_core_types__tuple3_box(_x_x1145, _ctx); /*105*/
            return kk_std_core_types__new_Eq2(_x_x1144, _ctx);
          }
          if (kk_std_core_types__is_Lt2(x_1_10563, _ctx)) {
            kk_box_t x3_sq_ = x_1_10563._cons.Lt2.lt;
            kk_box_t y3_sq_ = x_1_10563._cons.Lt2.gt;
            kk_box_t _x_x1146;
            kk_std_core_types__tuple3 _x_x1147;
            kk_box_t _x_x1148 = kk_box_dup(z1, _ctx); /*3160*/
            kk_box_t _x_x1149 = kk_box_dup(z2, _ctx); /*3161*/
            _x_x1147 = kk_std_core_types__new_Tuple3(_x_x1148, _x_x1149, x3_sq_, _ctx); /*(141, 142, 143)*/
            _x_x1146 = kk_std_core_types__tuple3_box(_x_x1147, _ctx); /*105*/
            kk_box_t _x_x1150;
            kk_std_core_types__tuple3 _x_x1151 = kk_std_core_types__new_Tuple3(z1, z2, y3_sq_, _ctx); /*(141, 142, 143)*/
            _x_x1150 = kk_std_core_types__tuple3_box(_x_x1151, _ctx); /*105*/
            return kk_std_core_types__new_Lt2(_x_x1146, _x_x1150, _ctx);
          }
          {
            kk_box_t y3_0_sq_ = x_1_10563._cons.Gt2.lt;
            kk_box_t x3_0_sq_ = x_1_10563._cons.Gt2.gt;
            kk_box_t _x_x1152;
            kk_std_core_types__tuple3 _x_x1153;
            kk_box_t _x_x1154 = kk_box_dup(z1, _ctx); /*3160*/
            kk_box_t _x_x1155 = kk_box_dup(z2, _ctx); /*3161*/
            _x_x1153 = kk_std_core_types__new_Tuple3(_x_x1154, _x_x1155, y3_0_sq_, _ctx); /*(141, 142, 143)*/
            _x_x1152 = kk_std_core_types__tuple3_box(_x_x1153, _ctx); /*105*/
            kk_box_t _x_x1156;
            kk_std_core_types__tuple3 _x_x1157 = kk_std_core_types__new_Tuple3(z1, z2, x3_0_sq_, _ctx); /*(141, 142, 143)*/
            _x_x1156 = kk_std_core_types__tuple3_box(_x_x1157, _ctx); /*105*/
            return kk_std_core_types__new_Gt2(_x_x1152, _x_x1156, _ctx);
          }
        }
        if (kk_std_core_types__is_Lt2(x_0_10560, _ctx)) {
          kk_box_t x2_sq_ = x_0_10560._cons.Lt2.lt;
          kk_box_t y2_sq_ = x_0_10560._cons.Lt2.gt;
          kk_box_t _x_x1158;
          kk_std_core_types__tuple3 _x_x1159;
          kk_box_t _x_x1160 = kk_box_dup(z1, _ctx); /*3160*/
          _x_x1159 = kk_std_core_types__new_Tuple3(_x_x1160, x2_sq_, x3, _ctx); /*(141, 142, 143)*/
          _x_x1158 = kk_std_core_types__tuple3_box(_x_x1159, _ctx); /*105*/
          kk_box_t _x_x1161;
          kk_std_core_types__tuple3 _x_x1162 = kk_std_core_types__new_Tuple3(z1, y2_sq_, y3, _ctx); /*(141, 142, 143)*/
          _x_x1161 = kk_std_core_types__tuple3_box(_x_x1162, _ctx); /*105*/
          return kk_std_core_types__new_Lt2(_x_x1158, _x_x1161, _ctx);
        }
        {
          kk_box_t y2_0_sq_ = x_0_10560._cons.Gt2.lt;
          kk_box_t x2_0_sq_ = x_0_10560._cons.Gt2.gt;
          kk_box_t _x_x1163;
          kk_std_core_types__tuple3 _x_x1164;
          kk_box_t _x_x1165 = kk_box_dup(z1, _ctx); /*3160*/
          _x_x1164 = kk_std_core_types__new_Tuple3(_x_x1165, y2_0_sq_, y3, _ctx); /*(141, 142, 143)*/
          _x_x1163 = kk_std_core_types__tuple3_box(_x_x1164, _ctx); /*105*/
          kk_box_t _x_x1166;
          kk_std_core_types__tuple3 _x_x1167 = kk_std_core_types__new_Tuple3(z1, x2_0_sq_, x3, _ctx); /*(141, 142, 143)*/
          _x_x1166 = kk_std_core_types__tuple3_box(_x_x1167, _ctx); /*105*/
          return kk_std_core_types__new_Gt2(_x_x1163, _x_x1166, _ctx);
        }
      }
      if (kk_std_core_types__is_Lt2(x_10557, _ctx)) {
        kk_box_t x1_sq_ = x_10557._cons.Lt2.lt;
        kk_box_t y1_sq_ = x_10557._cons.Lt2.gt;
        kk_box_t _x_x1168;
        kk_std_core_types__tuple3 _x_x1169 = kk_std_core_types__new_Tuple3(x1_sq_, x2, x3, _ctx); /*(141, 142, 143)*/
        _x_x1168 = kk_std_core_types__tuple3_box(_x_x1169, _ctx); /*105*/
        kk_box_t _x_x1170;
        kk_std_core_types__tuple3 _x_x1171 = kk_std_core_types__new_Tuple3(y1_sq_, y2, y3, _ctx); /*(141, 142, 143)*/
        _x_x1170 = kk_std_core_types__tuple3_box(_x_x1171, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x1168, _x_x1170, _ctx);
      }
      {
        kk_box_t y1_0_sq_ = x_10557._cons.Gt2.lt;
        kk_box_t x1_0_sq_ = x_10557._cons.Gt2.gt;
        kk_box_t _x_x1172;
        kk_std_core_types__tuple3 _x_x1173 = kk_std_core_types__new_Tuple3(y1_0_sq_, y2, y3, _ctx); /*(141, 142, 143)*/
        _x_x1172 = kk_std_core_types__tuple3_box(_x_x1173, _ctx); /*105*/
        kk_box_t _x_x1174;
        kk_std_core_types__tuple3 _x_x1175 = kk_std_core_types__new_Tuple3(x1_0_sq_, x2, x3, _ctx); /*(141, 142, 143)*/
        _x_x1174 = kk_std_core_types__tuple3_box(_x_x1175, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x1172, _x_x1174, _ctx);
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_tuple_tuple4_fs__mlift_order2_10292(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_std_core_types__order2 _y_x10193, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (z1 : a, z2 : b, z3 : c, order2<d>) -> e order2<(a, b, c, d)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10193, _ctx)) {
    kk_box_t z4 = _y_x10193._cons.Eq2.eq;
    kk_box_t _x_x1176;
    kk_std_core_types__tuple4 _x_x1177 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, z2, z3, z4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1176 = kk_std_core_types__tuple4_box(_x_x1177, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x1176, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10193, _ctx)) {
    kk_box_t x4_sq_ = _y_x10193._cons.Lt2.lt;
    kk_box_t y4_sq_ = _y_x10193._cons.Lt2.gt;
    kk_box_t _x_x1178;
    kk_std_core_types__tuple4 _x_x1179;
    kk_box_t _x_x1180 = kk_box_dup(z1, _ctx); /*3833*/
    kk_box_t _x_x1181 = kk_box_dup(z2, _ctx); /*3834*/
    kk_box_t _x_x1182 = kk_box_dup(z3, _ctx); /*3835*/
    _x_x1179 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1180, _x_x1181, _x_x1182, x4_sq_, _ctx); /*(150, 151, 152, 153)*/
    _x_x1178 = kk_std_core_types__tuple4_box(_x_x1179, _ctx); /*105*/
    kk_box_t _x_x1183;
    kk_std_core_types__tuple4 _x_x1184 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, z2, z3, y4_sq_, _ctx); /*(150, 151, 152, 153)*/
    _x_x1183 = kk_std_core_types__tuple4_box(_x_x1184, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1178, _x_x1183, _ctx);
  }
  {
    kk_box_t y4_0_sq_ = _y_x10193._cons.Gt2.lt;
    kk_box_t x4_0_sq_ = _y_x10193._cons.Gt2.gt;
    kk_box_t _x_x1185;
    kk_std_core_types__tuple4 _x_x1186;
    kk_box_t _x_x1187 = kk_box_dup(z1, _ctx); /*3833*/
    kk_box_t _x_x1188 = kk_box_dup(z2, _ctx); /*3834*/
    kk_box_t _x_x1189 = kk_box_dup(z3, _ctx); /*3835*/
    _x_x1186 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1187, _x_x1188, _x_x1189, y4_0_sq_, _ctx); /*(150, 151, 152, 153)*/
    _x_x1185 = kk_std_core_types__tuple4_box(_x_x1186, _ctx); /*105*/
    kk_box_t _x_x1190;
    kk_std_core_types__tuple4 _x_x1191 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, z2, z3, x4_0_sq_, _ctx); /*(150, 151, 152, 153)*/
    _x_x1190 = kk_std_core_types__tuple4_box(_x_x1191, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1185, _x_x1190, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193(kk_function_t _fself, kk_box_t _b_x363, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_order2_10293_fun1193(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193(kk_function_t _fself, kk_box_t _b_x363, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10293_fun1193__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_box_t z2 = _self->z2; /* 3834 */
  kk_box_t z3 = _self->z3; /* 3835 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10193_373 = kk_std_core_types__order2_unbox(_b_x363, KK_OWNED, _ctx); /*order2<3836>*/;
  kk_std_core_types__order2 _x_x1194 = kk_std_core_tuple_tuple4_fs__mlift_order2_10292(z1, z2, z3, _y_x10193_373, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1194, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple4_fs__mlift_order2_10293(kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x4, kk_box_t y4, kk_box_t z1, kk_box_t z2, kk_std_core_types__order2 _y_x10192, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (?field4/order2 : (d, d) -> e order2<d>, x4 : d, y4 : d, z1 : a, z2 : b, order2<c>) -> e order2<(a, b, c, d)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10192, _ctx)) {
    kk_box_t z3 = _y_x10192._cons.Eq2.eq;
    kk_std_core_types__order2 x_10566 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_order2, (_implicit_fs_field4_fs_order2, x4, y4, _ctx), _ctx); /*order2<3836>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10566, _ctx);
      kk_box_t _x_x1192 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_order2_10293_fun1193(z1, z2, z3, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1192, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple4_fs__mlift_order2_10292(z1, z2, z3, x_10566, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10192, _ctx)) {
    kk_box_t x3_sq_ = _y_x10192._cons.Lt2.lt;
    kk_box_t y3_sq_ = _y_x10192._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_box_t _x_x1195;
    kk_std_core_types__tuple4 _x_x1196;
    kk_box_t _x_x1197 = kk_box_dup(z1, _ctx); /*3833*/
    kk_box_t _x_x1198 = kk_box_dup(z2, _ctx); /*3834*/
    _x_x1196 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1197, _x_x1198, x3_sq_, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1195 = kk_std_core_types__tuple4_box(_x_x1196, _ctx); /*105*/
    kk_box_t _x_x1199;
    kk_std_core_types__tuple4 _x_x1200 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, z2, y3_sq_, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1199 = kk_std_core_types__tuple4_box(_x_x1200, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1195, _x_x1199, _ctx);
  }
  {
    kk_box_t y3_0_sq_ = _y_x10192._cons.Gt2.lt;
    kk_box_t x3_0_sq_ = _y_x10192._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_box_t _x_x1201;
    kk_std_core_types__tuple4 _x_x1202;
    kk_box_t _x_x1203 = kk_box_dup(z1, _ctx); /*3833*/
    kk_box_t _x_x1204 = kk_box_dup(z2, _ctx); /*3834*/
    _x_x1202 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1203, _x_x1204, y3_0_sq_, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1201 = kk_std_core_types__tuple4_box(_x_x1202, _ctx); /*105*/
    kk_box_t _x_x1205;
    kk_std_core_types__tuple4 _x_x1206 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, z2, x3_0_sq_, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1205 = kk_std_core_types__tuple4_box(_x_x1206, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1201, _x_x1205, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_box_t x4;
  kk_box_t y4;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_order2_10294_fun1208(kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x4, kk_box_t y4, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208, kk_context());
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->x4 = x4;
  _self->y4 = y4;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10294_fun1208__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (3836, 3836) -> 3837 order2<3836> */
  kk_box_t x4 = _self->x4; /* 3836 */
  kk_box_t y4 = _self->y4; /* 3836 */
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_box_t z2 = _self->z2; /* 3834 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10192_385 = kk_std_core_types__order2_unbox(_b_x375, KK_OWNED, _ctx); /*order2<3835>*/;
  kk_std_core_types__order2 _x_x1209 = kk_std_core_tuple_tuple4_fs__mlift_order2_10293(_implicit_fs_field4_fs_order2, x4, y4, z1, z2, _y_x10192_385, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1209, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple4_fs__mlift_order2_10294(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t y3, kk_box_t y4, kk_box_t z1, kk_std_core_types__order2 _y_x10191, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>, x3 : c, x4 : d, y3 : c, y4 : d, z1 : a, order2<b>) -> e order2<(a, b, c, d)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10191, _ctx)) {
    kk_box_t z2 = _y_x10191._cons.Eq2.eq;
    kk_std_core_types__order2 x_10568 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_c_fs_order2, (_implicit_fs_c_fs_order2, x3, y3, _ctx), _ctx); /*order2<3835>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10568, _ctx);
      kk_box_t _x_x1207 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_order2_10294_fun1208(_implicit_fs_field4_fs_order2, x4, y4, z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1207, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple4_fs__mlift_order2_10293(_implicit_fs_field4_fs_order2, x4, y4, z1, z2, x_10568, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10191, _ctx)) {
    kk_box_t x2_sq_ = _y_x10191._cons.Lt2.lt;
    kk_box_t y2_sq_ = _y_x10191._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1210;
    kk_std_core_types__tuple4 _x_x1211;
    kk_box_t _x_x1212 = kk_box_dup(z1, _ctx); /*3833*/
    _x_x1211 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1212, x2_sq_, x3, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1210 = kk_std_core_types__tuple4_box(_x_x1211, _ctx); /*105*/
    kk_box_t _x_x1213;
    kk_std_core_types__tuple4 _x_x1214 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, y2_sq_, y3, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1213 = kk_std_core_types__tuple4_box(_x_x1214, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1210, _x_x1213, _ctx);
  }
  {
    kk_box_t y2_0_sq_ = _y_x10191._cons.Gt2.lt;
    kk_box_t x2_0_sq_ = _y_x10191._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1215;
    kk_std_core_types__tuple4 _x_x1216;
    kk_box_t _x_x1217 = kk_box_dup(z1, _ctx); /*3833*/
    _x_x1216 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, _x_x1217, y2_0_sq_, y3, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1215 = kk_std_core_types__tuple4_box(_x_x1216, _ctx); /*105*/
    kk_box_t _x_x1218;
    kk_std_core_types__tuple4 _x_x1219 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, z1, x2_0_sq_, x3, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1218 = kk_std_core_types__tuple4_box(_x_x1219, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1215, _x_x1218, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t y3;
  kk_box_t y4;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221(kk_function_t _fself, kk_box_t _b_x387, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_order2_10295_fun1221(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t y3, kk_box_t y4, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->y3 = y3;
  _self->y4 = y4;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221(kk_function_t _fself, kk_box_t _b_x387, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_order2_10295_fun1221__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3835, 3835) -> 3837 order2<3835> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (3836, 3836) -> 3837 order2<3836> */
  kk_box_t x3 = _self->x3; /* 3835 */
  kk_box_t x4 = _self->x4; /* 3836 */
  kk_box_t y3 = _self->y3; /* 3835 */
  kk_box_t y4 = _self->y4; /* 3836 */
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10191_397 = kk_std_core_types__order2_unbox(_b_x387, KK_OWNED, _ctx); /*order2<3834>*/;
  kk_std_core_types__order2 _x_x1222 = kk_std_core_tuple_tuple4_fs__mlift_order2_10294(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x3, x4, y3, y4, z1, _y_x10191_397, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1222, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple4_fs__mlift_order2_10295(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_box_t y2, kk_box_t y3, kk_box_t y4, kk_std_core_types__order2 _y_x10190, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>, x2 : b, x3 : c, x4 : d, y2 : b, y3 : c, y4 : d, order2<a>) -> e order2<(a, b, c, d)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10190, _ctx)) {
    kk_box_t z1 = _y_x10190._cons.Eq2.eq;
    kk_std_core_types__order2 x_10570 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_b_fs_order2, (_implicit_fs_b_fs_order2, x2, y2, _ctx), _ctx); /*order2<3834>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10570, _ctx);
      kk_box_t _x_x1220 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_order2_10295_fun1221(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x3, x4, y3, y4, z1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1220, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple4_fs__mlift_order2_10294(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x3, x4, y3, y4, z1, x_10570, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10190, _ctx)) {
    kk_box_t x1_sq_ = _y_x10190._cons.Lt2.lt;
    kk_box_t y1_sq_ = _y_x10190._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1223;
    kk_std_core_types__tuple4 _x_x1224 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x1_sq_, x2, x3, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1223 = kk_std_core_types__tuple4_box(_x_x1224, _ctx); /*105*/
    kk_box_t _x_x1225;
    kk_std_core_types__tuple4 _x_x1226 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, y1_sq_, y2, y3, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1225 = kk_std_core_types__tuple4_box(_x_x1226, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1223, _x_x1225, _ctx);
  }
  {
    kk_box_t y1_0_sq_ = _y_x10190._cons.Gt2.lt;
    kk_box_t x1_0_sq_ = _y_x10190._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1227;
    kk_std_core_types__tuple4 _x_x1228 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, y1_0_sq_, y2, y3, y4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1227 = kk_std_core_types__tuple4_box(_x_x1228, _ctx); /*105*/
    kk_box_t _x_x1229;
    kk_std_core_types__tuple4 _x_x1230 = kk_std_core_types__new_Tuple4(kk_reuse_null, 0, x1_0_sq_, x2, x3, x4, _ctx); /*(150, 151, 152, 153)*/
    _x_x1229 = kk_std_core_types__tuple4_box(_x_x1230, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1227, _x_x1229, _ctx);
  }
}
 
// order2 of tuple4 values


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_order2_fun1236__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_b_fs_order2;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_box_t x2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t y2;
  kk_box_t y3;
  kk_box_t y4;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1236(kk_function_t _fself, kk_box_t _b_x399, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_order2_fun1236(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_box_t y2, kk_box_t y3, kk_box_t y4, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1236__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1236__t, 10, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_order2_fun1236, kk_context());
  _self->_implicit_fs_b_fs_order2 = _implicit_fs_b_fs_order2;
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->x2 = x2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->y2 = y2;
  _self->y3 = y3;
  _self->y4 = y4;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1236(kk_function_t _fself, kk_box_t _b_x399, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1236__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1236__t*, _fself, _ctx);
  kk_function_t _implicit_fs_b_fs_order2 = _self->_implicit_fs_b_fs_order2; /* (3834, 3834) -> 3837 order2<3834> */
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3835, 3835) -> 3837 order2<3835> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (3836, 3836) -> 3837 order2<3836> */
  kk_box_t x2 = _self->x2; /* 3834 */
  kk_box_t x3 = _self->x3; /* 3835 */
  kk_box_t x4 = _self->x4; /* 3836 */
  kk_box_t y2 = _self->y2; /* 3834 */
  kk_box_t y3 = _self->y3; /* 3835 */
  kk_box_t y4 = _self->y4; /* 3836 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_b_fs_order2, _ctx);kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_box_dup(x2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10190_444 = kk_std_core_types__order2_unbox(_b_x399, KK_OWNED, _ctx); /*order2<3833>*/;
  kk_std_core_types__order2 _x_x1237 = kk_std_core_tuple_tuple4_fs__mlift_order2_10295(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x2, x3, x4, y2, y3, y4, _y_x10190_444, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1237, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_order2_fun1241__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t y3;
  kk_box_t y4;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1241(kk_function_t _fself, kk_box_t _b_x401, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_order2_fun1241(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t y3, kk_box_t y4, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1241__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1241__t, 8, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_order2_fun1241, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->y3 = y3;
  _self->y4 = y4;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1241(kk_function_t _fself, kk_box_t _b_x401, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1241__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1241__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (3835, 3835) -> 3837 order2<3835> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (3836, 3836) -> 3837 order2<3836> */
  kk_box_t x3 = _self->x3; /* 3835 */
  kk_box_t x4 = _self->x4; /* 3836 */
  kk_box_t y3 = _self->y3; /* 3835 */
  kk_box_t y4 = _self->y4; /* 3836 */
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10191_445 = kk_std_core_types__order2_unbox(_b_x401, KK_OWNED, _ctx); /*order2<3834>*/;
  kk_std_core_types__order2 _x_x1242 = kk_std_core_tuple_tuple4_fs__mlift_order2_10294(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x3, x4, y3, y4, z1, _y_x10191_445, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1242, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_order2_fun1246__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_box_t x4;
  kk_box_t y4;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1246(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_order2_fun1246(kk_function_t _implicit_fs_field4_fs_order2, kk_box_t x4, kk_box_t y4, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1246__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1246__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_order2_fun1246, kk_context());
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->x4 = x4;
  _self->y4 = y4;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1246(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1246__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1246__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (3836, 3836) -> 3837 order2<3836> */
  kk_box_t x4 = _self->x4; /* 3836 */
  kk_box_t y4 = _self->y4; /* 3836 */
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_box_t z2 = _self->z2; /* 3834 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10192_446 = kk_std_core_types__order2_unbox(_b_x403, KK_OWNED, _ctx); /*order2<3835>*/;
  kk_std_core_types__order2 _x_x1247 = kk_std_core_tuple_tuple4_fs__mlift_order2_10293(_implicit_fs_field4_fs_order2, x4, y4, z1, z2, _y_x10192_446, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1247, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_order2_fun1250__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1250(kk_function_t _fself, kk_box_t _b_x405, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_order2_fun1250(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1250__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1250__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_order2_fun1250, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_order2_fun1250(kk_function_t _fself, kk_box_t _b_x405, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_order2_fun1250__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_order2_fun1250__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 3833 */
  kk_box_t z2 = _self->z2; /* 3834 */
  kk_box_t z3 = _self->z3; /* 3835 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10193_447 = kk_std_core_types__order2_unbox(_b_x405, KK_OWNED, _ctx); /*order2<3836>*/;
  kk_std_core_types__order2 _x_x1251 = kk_std_core_tuple_tuple4_fs__mlift_order2_10292(z1, z2, z3, _y_x10193_447, _ctx); /*order2<(3833, 3834, 3835, 3836)>*/
  return kk_std_core_types__order2_box(_x_x1251, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple4_fs_order2(kk_std_core_types__tuple4 _pat_x130__24, kk_std_core_types__tuple4 _pat_x130__56, kk_function_t _implicit_fs_a_fs_order2, kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_context_t* _ctx) { /* forall<a,b,c,d,e> ((a, b, c, d), (a, b, c, d), ?a/order2 : (a, a) -> e order2<a>, ?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>) -> e order2<(a, b, c, d)> */ 
  {
    struct kk_std_core_types_Tuple4* _con_x1231 = kk_std_core_types__as_Tuple4(_pat_x130__24, _ctx);
    kk_box_t x1 = _con_x1231->fst;
    kk_box_t x2 = _con_x1231->snd;
    kk_box_t x3 = _con_x1231->thd;
    kk_box_t x4 = _con_x1231->field4;
    kk_reuse_t _ru_x779 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x130__24, _ctx)) {
      _ru_x779 = (kk_datatype_ptr_reuse(_pat_x130__24, _ctx));
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_datatype_ptr_decref(_pat_x130__24, _ctx);
    }
    {
      struct kk_std_core_types_Tuple4* _con_x1232 = kk_std_core_types__as_Tuple4(_pat_x130__56, _ctx);
      kk_box_t y1 = _con_x1232->fst;
      kk_box_t y2 = _con_x1232->snd;
      kk_box_t y3 = _con_x1232->thd;
      kk_box_t y4 = _con_x1232->field4;
      kk_reuse_t _ru_x780 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x130__56, _ctx)) {
        _ru_x780 = (kk_datatype_ptr_reuse(_pat_x130__56, _ctx));
      }
      else {
        kk_box_dup(y1, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(y3, _ctx);
        kk_box_dup(y4, _ctx);
        kk_datatype_ptr_decref(_pat_x130__56, _ctx);
      }
      kk_std_core_types__order2 x_10572;
      kk_function_t _x_x1233 = kk_function_dup(_implicit_fs_a_fs_order2, _ctx); /*(3833, 3833) -> 3837 order2<3833>*/
      x_10572 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1233, (_x_x1233, x1, y1, _ctx), _ctx); /*order2<3833>*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x779,kk_context());
        kk_reuse_drop(_ru_x780,kk_context());
        kk_std_core_types__order2_drop(x_10572, _ctx);
        kk_box_t _x_x1234;
        kk_function_t _x_x1235;
        kk_function_dup(_implicit_fs_b_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
        _x_x1235 = kk_std_core_tuple_tuple4_fs_new_order2_fun1236(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x2, x3, x4, y2, y3, y4, _ctx); /*(2418) -> 2420 2419*/
        _x_x1234 = kk_std_core_hnd_yield_extend(_x_x1235, _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x1234, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_10572, _ctx)) {
        kk_box_t z1 = x_10572._cons.Eq2.eq;
        kk_std_core_types__order2 x_0_10575;
        kk_function_t _x_x1238 = kk_function_dup(_implicit_fs_b_fs_order2, _ctx); /*(3834, 3834) -> 3837 order2<3834>*/
        x_0_10575 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1238, (_x_x1238, x2, y2, _ctx), _ctx); /*order2<3834>*/
        if (kk_yielding(kk_context())) {
          kk_reuse_drop(_ru_x779,kk_context());
          kk_reuse_drop(_ru_x780,kk_context());
          kk_std_core_types__order2_drop(x_0_10575, _ctx);
          kk_box_t _x_x1239;
          kk_function_t _x_x1240;
          kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
          kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
          _x_x1240 = kk_std_core_tuple_tuple4_fs_new_order2_fun1241(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, x3, x4, y3, y4, z1, _ctx); /*(2418) -> 2420 2419*/
          _x_x1239 = kk_std_core_hnd_yield_extend(_x_x1240, _ctx); /*2419*/
          return kk_std_core_types__order2_unbox(_x_x1239, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq2(x_0_10575, _ctx)) {
          kk_box_t z2 = x_0_10575._cons.Eq2.eq;
          kk_std_core_types__order2 x_1_10578;
          kk_function_t _x_x1243 = kk_function_dup(_implicit_fs_c_fs_order2, _ctx); /*(3835, 3835) -> 3837 order2<3835>*/
          x_1_10578 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1243, (_x_x1243, x3, y3, _ctx), _ctx); /*order2<3835>*/
          if (kk_yielding(kk_context())) {
            kk_reuse_drop(_ru_x779,kk_context());
            kk_reuse_drop(_ru_x780,kk_context());
            kk_std_core_types__order2_drop(x_1_10578, _ctx);
            kk_box_t _x_x1244;
            kk_function_t _x_x1245;
            kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
            _x_x1245 = kk_std_core_tuple_tuple4_fs_new_order2_fun1246(_implicit_fs_field4_fs_order2, x4, y4, z1, z2, _ctx); /*(2418) -> 2420 2419*/
            _x_x1244 = kk_std_core_hnd_yield_extend(_x_x1245, _ctx); /*2419*/
            return kk_std_core_types__order2_unbox(_x_x1244, KK_OWNED, _ctx);
          }
          if (kk_std_core_types__is_Eq2(x_1_10578, _ctx)) {
            kk_box_t z3 = x_1_10578._cons.Eq2.eq;
            kk_std_core_types__order2 x_2_10581;
            kk_function_t _x_x1248 = kk_function_dup(_implicit_fs_field4_fs_order2, _ctx); /*(3836, 3836) -> 3837 order2<3836>*/
            x_2_10581 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1248, (_x_x1248, x4, y4, _ctx), _ctx); /*order2<3836>*/
            if (kk_yielding(kk_context())) {
              kk_reuse_drop(_ru_x779,kk_context());
              kk_reuse_drop(_ru_x780,kk_context());
              kk_std_core_types__order2_drop(x_2_10581, _ctx);
              kk_box_t _x_x1249 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_order2_fun1250(z1, z2, z3, _ctx), _ctx); /*2419*/
              return kk_std_core_types__order2_unbox(_x_x1249, KK_OWNED, _ctx);
            }
            if (kk_std_core_types__is_Eq2(x_2_10581, _ctx)) {
              kk_box_t z4 = x_2_10581._cons.Eq2.eq;
              kk_reuse_drop(_ru_x779,kk_context());
              kk_box_t _x_x1252;
              kk_std_core_types__tuple4 _x_x1253 = kk_std_core_types__new_Tuple4(_ru_x780, 0, z1, z2, z3, z4, _ctx); /*(150, 151, 152, 153)*/
              _x_x1252 = kk_std_core_types__tuple4_box(_x_x1253, _ctx); /*105*/
              return kk_std_core_types__new_Eq2(_x_x1252, _ctx);
            }
            if (kk_std_core_types__is_Lt2(x_2_10581, _ctx)) {
              kk_box_t x4_sq_ = x_2_10581._cons.Lt2.lt;
              kk_box_t y4_sq_ = x_2_10581._cons.Lt2.gt;
              kk_box_t _x_x1254;
              kk_std_core_types__tuple4 _x_x1255;
              kk_box_t _x_x1256 = kk_box_dup(z1, _ctx); /*3833*/
              kk_box_t _x_x1257 = kk_box_dup(z2, _ctx); /*3834*/
              kk_box_t _x_x1258 = kk_box_dup(z3, _ctx); /*3835*/
              _x_x1255 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1256, _x_x1257, _x_x1258, x4_sq_, _ctx); /*(150, 151, 152, 153)*/
              _x_x1254 = kk_std_core_types__tuple4_box(_x_x1255, _ctx); /*105*/
              kk_box_t _x_x1259;
              kk_std_core_types__tuple4 _x_x1260 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, z2, z3, y4_sq_, _ctx); /*(150, 151, 152, 153)*/
              _x_x1259 = kk_std_core_types__tuple4_box(_x_x1260, _ctx); /*105*/
              return kk_std_core_types__new_Lt2(_x_x1254, _x_x1259, _ctx);
            }
            {
              kk_box_t y4_0_sq_ = x_2_10581._cons.Gt2.lt;
              kk_box_t x4_0_sq_ = x_2_10581._cons.Gt2.gt;
              kk_box_t _x_x1261;
              kk_std_core_types__tuple4 _x_x1262;
              kk_box_t _x_x1263 = kk_box_dup(z1, _ctx); /*3833*/
              kk_box_t _x_x1264 = kk_box_dup(z2, _ctx); /*3834*/
              kk_box_t _x_x1265 = kk_box_dup(z3, _ctx); /*3835*/
              _x_x1262 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1263, _x_x1264, _x_x1265, y4_0_sq_, _ctx); /*(150, 151, 152, 153)*/
              _x_x1261 = kk_std_core_types__tuple4_box(_x_x1262, _ctx); /*105*/
              kk_box_t _x_x1266;
              kk_std_core_types__tuple4 _x_x1267 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, z2, z3, x4_0_sq_, _ctx); /*(150, 151, 152, 153)*/
              _x_x1266 = kk_std_core_types__tuple4_box(_x_x1267, _ctx); /*105*/
              return kk_std_core_types__new_Gt2(_x_x1261, _x_x1266, _ctx);
            }
          }
          if (kk_std_core_types__is_Lt2(x_1_10578, _ctx)) {
            kk_box_t x3_sq_ = x_1_10578._cons.Lt2.lt;
            kk_box_t y3_sq_ = x_1_10578._cons.Lt2.gt;
            kk_box_t _x_x1268;
            kk_std_core_types__tuple4 _x_x1269;
            kk_box_t _x_x1270 = kk_box_dup(z1, _ctx); /*3833*/
            kk_box_t _x_x1271 = kk_box_dup(z2, _ctx); /*3834*/
            _x_x1269 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1270, _x_x1271, x3_sq_, x4, _ctx); /*(150, 151, 152, 153)*/
            _x_x1268 = kk_std_core_types__tuple4_box(_x_x1269, _ctx); /*105*/
            kk_box_t _x_x1272;
            kk_std_core_types__tuple4 _x_x1273 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, z2, y3_sq_, y4, _ctx); /*(150, 151, 152, 153)*/
            _x_x1272 = kk_std_core_types__tuple4_box(_x_x1273, _ctx); /*105*/
            return kk_std_core_types__new_Lt2(_x_x1268, _x_x1272, _ctx);
          }
          {
            kk_box_t y3_0_sq_ = x_1_10578._cons.Gt2.lt;
            kk_box_t x3_0_sq_ = x_1_10578._cons.Gt2.gt;
            kk_box_t _x_x1274;
            kk_std_core_types__tuple4 _x_x1275;
            kk_box_t _x_x1276 = kk_box_dup(z1, _ctx); /*3833*/
            kk_box_t _x_x1277 = kk_box_dup(z2, _ctx); /*3834*/
            _x_x1275 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1276, _x_x1277, y3_0_sq_, y4, _ctx); /*(150, 151, 152, 153)*/
            _x_x1274 = kk_std_core_types__tuple4_box(_x_x1275, _ctx); /*105*/
            kk_box_t _x_x1278;
            kk_std_core_types__tuple4 _x_x1279 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, z2, x3_0_sq_, x4, _ctx); /*(150, 151, 152, 153)*/
            _x_x1278 = kk_std_core_types__tuple4_box(_x_x1279, _ctx); /*105*/
            return kk_std_core_types__new_Gt2(_x_x1274, _x_x1278, _ctx);
          }
        }
        if (kk_std_core_types__is_Lt2(x_0_10575, _ctx)) {
          kk_box_t x2_sq_ = x_0_10575._cons.Lt2.lt;
          kk_box_t y2_sq_ = x_0_10575._cons.Lt2.gt;
          kk_box_t _x_x1280;
          kk_std_core_types__tuple4 _x_x1281;
          kk_box_t _x_x1282 = kk_box_dup(z1, _ctx); /*3833*/
          _x_x1281 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1282, x2_sq_, x3, x4, _ctx); /*(150, 151, 152, 153)*/
          _x_x1280 = kk_std_core_types__tuple4_box(_x_x1281, _ctx); /*105*/
          kk_box_t _x_x1283;
          kk_std_core_types__tuple4 _x_x1284 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, y2_sq_, y3, y4, _ctx); /*(150, 151, 152, 153)*/
          _x_x1283 = kk_std_core_types__tuple4_box(_x_x1284, _ctx); /*105*/
          return kk_std_core_types__new_Lt2(_x_x1280, _x_x1283, _ctx);
        }
        {
          kk_box_t y2_0_sq_ = x_0_10575._cons.Gt2.lt;
          kk_box_t x2_0_sq_ = x_0_10575._cons.Gt2.gt;
          kk_box_t _x_x1285;
          kk_std_core_types__tuple4 _x_x1286;
          kk_box_t _x_x1287 = kk_box_dup(z1, _ctx); /*3833*/
          _x_x1286 = kk_std_core_types__new_Tuple4(_ru_x780, 0, _x_x1287, y2_0_sq_, y3, y4, _ctx); /*(150, 151, 152, 153)*/
          _x_x1285 = kk_std_core_types__tuple4_box(_x_x1286, _ctx); /*105*/
          kk_box_t _x_x1288;
          kk_std_core_types__tuple4 _x_x1289 = kk_std_core_types__new_Tuple4(_ru_x779, 0, z1, x2_0_sq_, x3, x4, _ctx); /*(150, 151, 152, 153)*/
          _x_x1288 = kk_std_core_types__tuple4_box(_x_x1289, _ctx); /*105*/
          return kk_std_core_types__new_Gt2(_x_x1285, _x_x1288, _ctx);
        }
      }
      if (kk_std_core_types__is_Lt2(x_10572, _ctx)) {
        kk_box_t x1_sq_ = x_10572._cons.Lt2.lt;
        kk_box_t y1_sq_ = x_10572._cons.Lt2.gt;
        kk_box_t _x_x1290;
        kk_std_core_types__tuple4 _x_x1291 = kk_std_core_types__new_Tuple4(_ru_x780, 0, x1_sq_, x2, x3, x4, _ctx); /*(150, 151, 152, 153)*/
        _x_x1290 = kk_std_core_types__tuple4_box(_x_x1291, _ctx); /*105*/
        kk_box_t _x_x1292;
        kk_std_core_types__tuple4 _x_x1293 = kk_std_core_types__new_Tuple4(_ru_x779, 0, y1_sq_, y2, y3, y4, _ctx); /*(150, 151, 152, 153)*/
        _x_x1292 = kk_std_core_types__tuple4_box(_x_x1293, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x1290, _x_x1292, _ctx);
      }
      {
        kk_box_t y1_0_sq_ = x_10572._cons.Gt2.lt;
        kk_box_t x1_0_sq_ = x_10572._cons.Gt2.gt;
        kk_box_t _x_x1294;
        kk_std_core_types__tuple4 _x_x1295 = kk_std_core_types__new_Tuple4(_ru_x780, 0, y1_0_sq_, y2, y3, y4, _ctx); /*(150, 151, 152, 153)*/
        _x_x1294 = kk_std_core_types__tuple4_box(_x_x1295, _ctx); /*105*/
        kk_box_t _x_x1296;
        kk_std_core_types__tuple4 _x_x1297 = kk_std_core_types__new_Tuple4(_ru_x779, 0, x1_0_sq_, x2, x3, x4, _ctx); /*(150, 151, 152, 153)*/
        _x_x1296 = kk_std_core_types__tuple4_box(_x_x1297, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x1294, _x_x1296, _ctx);
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs__mlift_order2_10296(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_box_t z4, kk_std_core_types__order2 _y_x10203, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (z1 : a, z2 : b, z3 : c, z4 : d, order2<a1>) -> e order2<(a, b, c, d, a1)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10203, _ctx)) {
    kk_box_t z5 = _y_x10203._cons.Eq2.eq;
    kk_box_t _x_x1298;
    kk_std_core_types__tuple5 _x_x1299 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, z3, z4, z5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1298 = kk_std_core_types__tuple5_box(_x_x1299, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x1298, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10203, _ctx)) {
    kk_box_t x5_sq_ = _y_x10203._cons.Lt2.lt;
    kk_box_t y5_sq_ = _y_x10203._cons.Lt2.gt;
    kk_box_t _x_x1300;
    kk_std_core_types__tuple5 _x_x1301;
    kk_box_t _x_x1302 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1303 = kk_box_dup(z2, _ctx); /*4749*/
    kk_box_t _x_x1304 = kk_box_dup(z3, _ctx); /*4750*/
    kk_box_t _x_x1305 = kk_box_dup(z4, _ctx); /*4751*/
    _x_x1301 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1302, _x_x1303, _x_x1304, _x_x1305, x5_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1300 = kk_std_core_types__tuple5_box(_x_x1301, _ctx); /*105*/
    kk_box_t _x_x1306;
    kk_std_core_types__tuple5 _x_x1307 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, z3, z4, y5_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1306 = kk_std_core_types__tuple5_box(_x_x1307, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1300, _x_x1306, _ctx);
  }
  {
    kk_box_t y5_0_sq_ = _y_x10203._cons.Gt2.lt;
    kk_box_t x5_0_sq_ = _y_x10203._cons.Gt2.gt;
    kk_box_t _x_x1308;
    kk_std_core_types__tuple5 _x_x1309;
    kk_box_t _x_x1310 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1311 = kk_box_dup(z2, _ctx); /*4749*/
    kk_box_t _x_x1312 = kk_box_dup(z3, _ctx); /*4750*/
    kk_box_t _x_x1313 = kk_box_dup(z4, _ctx); /*4751*/
    _x_x1309 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1310, _x_x1311, _x_x1312, _x_x1313, y5_0_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1308 = kk_std_core_types__tuple5_box(_x_x1309, _ctx); /*105*/
    kk_box_t _x_x1314;
    kk_std_core_types__tuple5 _x_x1315 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, z3, z4, x5_0_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1314 = kk_std_core_types__tuple5_box(_x_x1315, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1308, _x_x1314, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
  kk_box_t z4;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317(kk_function_t _fself, kk_box_t _b_x459, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_order2_10297_fun1317(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_box_t z4, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  _self->z4 = z4;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317(kk_function_t _fself, kk_box_t _b_x459, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10297_fun1317__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_box_t z3 = _self->z3; /* 4750 */
  kk_box_t z4 = _self->z4; /* 4751 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);kk_box_dup(z4, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10203_469 = kk_std_core_types__order2_unbox(_b_x459, KK_OWNED, _ctx); /*order2<4753>*/;
  kk_std_core_types__order2 _x_x1318 = kk_std_core_tuple_tuple5_fs__mlift_order2_10296(z1, z2, z3, z4, _y_x10203_469, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1318, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs__mlift_order2_10297(kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x5, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_std_core_types__order2 _y_x10202, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (?field5/order2 : (a1, a1) -> e order2<a1>, x5 : a1, y5 : a1, z1 : a, z2 : b, z3 : c, order2<d>) -> e order2<(a, b, c, d, a1)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10202, _ctx)) {
    kk_box_t z4 = _y_x10202._cons.Eq2.eq;
    kk_std_core_types__order2 x_10584 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_order2, (_implicit_fs_field5_fs_order2, x5, y5, _ctx), _ctx); /*order2<4753>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10584, _ctx);
      kk_box_t _x_x1316 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_order2_10297_fun1317(z1, z2, z3, z4, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1316, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_order2_10296(z1, z2, z3, z4, x_10584, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10202, _ctx)) {
    kk_box_t x4_sq_ = _y_x10202._cons.Lt2.lt;
    kk_box_t y4_sq_ = _y_x10202._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_box_t _x_x1319;
    kk_std_core_types__tuple5 _x_x1320;
    kk_box_t _x_x1321 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1322 = kk_box_dup(z2, _ctx); /*4749*/
    kk_box_t _x_x1323 = kk_box_dup(z3, _ctx); /*4750*/
    _x_x1320 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1321, _x_x1322, _x_x1323, x4_sq_, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1319 = kk_std_core_types__tuple5_box(_x_x1320, _ctx); /*105*/
    kk_box_t _x_x1324;
    kk_std_core_types__tuple5 _x_x1325 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, z3, y4_sq_, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1324 = kk_std_core_types__tuple5_box(_x_x1325, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1319, _x_x1324, _ctx);
  }
  {
    kk_box_t y4_0_sq_ = _y_x10202._cons.Gt2.lt;
    kk_box_t x4_0_sq_ = _y_x10202._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_box_t _x_x1326;
    kk_std_core_types__tuple5 _x_x1327;
    kk_box_t _x_x1328 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1329 = kk_box_dup(z2, _ctx); /*4749*/
    kk_box_t _x_x1330 = kk_box_dup(z3, _ctx); /*4750*/
    _x_x1327 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1328, _x_x1329, _x_x1330, y4_0_sq_, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1326 = kk_std_core_types__tuple5_box(_x_x1327, _ctx); /*105*/
    kk_box_t _x_x1331;
    kk_std_core_types__tuple5 _x_x1332 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, z3, x4_0_sq_, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1331 = kk_std_core_types__tuple5_box(_x_x1332, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1326, _x_x1331, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x5;
  kk_box_t y5;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334(kk_function_t _fself, kk_box_t _b_x471, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_order2_10298_fun1334(kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x5, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334, kk_context());
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x5 = x5;
  _self->y5 = y5;
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334(kk_function_t _fself, kk_box_t _b_x471, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10298_fun1334__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_box_t z3 = _self->z3; /* 4750 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10202_481 = kk_std_core_types__order2_unbox(_b_x471, KK_OWNED, _ctx); /*order2<4751>*/;
  kk_std_core_types__order2 _x_x1335 = kk_std_core_tuple_tuple5_fs__mlift_order2_10297(_implicit_fs_field5_fs_order2, x5, y5, z1, z2, z3, _y_x10202_481, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1335, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs__mlift_order2_10298(kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x4, kk_box_t x5, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_std_core_types__order2 _y_x10201, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (?field4/order2 : (d, d) -> e order2<d>, ?field5/order2 : (a1, a1) -> e order2<a1>, x4 : d, x5 : a1, y4 : d, y5 : a1, z1 : a, z2 : b, order2<c>) -> e order2<(a, b, c, d, a1)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10201, _ctx)) {
    kk_box_t z3 = _y_x10201._cons.Eq2.eq;
    kk_std_core_types__order2 x_10586 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_order2, (_implicit_fs_field4_fs_order2, x4, y4, _ctx), _ctx); /*order2<4751>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10586, _ctx);
      kk_box_t _x_x1333 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_order2_10298_fun1334(_implicit_fs_field5_fs_order2, x5, y5, z1, z2, z3, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1333, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_order2_10297(_implicit_fs_field5_fs_order2, x5, y5, z1, z2, z3, x_10586, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10201, _ctx)) {
    kk_box_t x3_sq_ = _y_x10201._cons.Lt2.lt;
    kk_box_t y3_sq_ = _y_x10201._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_box_t _x_x1336;
    kk_std_core_types__tuple5 _x_x1337;
    kk_box_t _x_x1338 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1339 = kk_box_dup(z2, _ctx); /*4749*/
    _x_x1337 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1338, _x_x1339, x3_sq_, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1336 = kk_std_core_types__tuple5_box(_x_x1337, _ctx); /*105*/
    kk_box_t _x_x1340;
    kk_std_core_types__tuple5 _x_x1341 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, y3_sq_, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1340 = kk_std_core_types__tuple5_box(_x_x1341, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1336, _x_x1340, _ctx);
  }
  {
    kk_box_t y3_0_sq_ = _y_x10201._cons.Gt2.lt;
    kk_box_t x3_0_sq_ = _y_x10201._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_box_t _x_x1342;
    kk_std_core_types__tuple5 _x_x1343;
    kk_box_t _x_x1344 = kk_box_dup(z1, _ctx); /*4748*/
    kk_box_t _x_x1345 = kk_box_dup(z2, _ctx); /*4749*/
    _x_x1343 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1344, _x_x1345, y3_0_sq_, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1342 = kk_std_core_types__tuple5_box(_x_x1343, _ctx); /*105*/
    kk_box_t _x_x1346;
    kk_std_core_types__tuple5 _x_x1347 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, z2, x3_0_sq_, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1346 = kk_std_core_types__tuple5_box(_x_x1347, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1342, _x_x1346, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x4;
  kk_box_t x5;
  kk_box_t y4;
  kk_box_t y5;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349(kk_function_t _fself, kk_box_t _b_x483, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_order2_10299_fun1349(kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x4, kk_box_t x5, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349__t, 9, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349, kk_context());
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x4 = x4;
  _self->x5 = x5;
  _self->y4 = y4;
  _self->y5 = y5;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349(kk_function_t _fself, kk_box_t _b_x483, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10299_fun1349__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (4751, 4751) -> 4752 order2<4751> */
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x4 = _self->x4; /* 4751 */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y4 = _self->y4; /* 4751 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10201_493 = kk_std_core_types__order2_unbox(_b_x483, KK_OWNED, _ctx); /*order2<4750>*/;
  kk_std_core_types__order2 _x_x1350 = kk_std_core_tuple_tuple5_fs__mlift_order2_10298(_implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x4, x5, y4, y5, z1, z2, _y_x10201_493, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1350, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs__mlift_order2_10299(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t x5, kk_box_t y3, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_std_core_types__order2 _y_x10200, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>, ?field5/order2 : (a1, a1) -> e order2<a1>, x3 : c, x4 : d, x5 : a1, y3 : c, y4 : d, y5 : a1, z1 : a, order2<b>) -> e order2<(a, b, c, d, a1)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10200, _ctx)) {
    kk_box_t z2 = _y_x10200._cons.Eq2.eq;
    kk_std_core_types__order2 x_10588 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_c_fs_order2, (_implicit_fs_c_fs_order2, x3, y3, _ctx), _ctx); /*order2<4750>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10588, _ctx);
      kk_box_t _x_x1348 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_order2_10299_fun1349(_implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x4, x5, y4, y5, z1, z2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1348, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_order2_10298(_implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x4, x5, y4, y5, z1, z2, x_10588, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10200, _ctx)) {
    kk_box_t x2_sq_ = _y_x10200._cons.Lt2.lt;
    kk_box_t y2_sq_ = _y_x10200._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1351;
    kk_std_core_types__tuple5 _x_x1352;
    kk_box_t _x_x1353 = kk_box_dup(z1, _ctx); /*4748*/
    _x_x1352 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1353, x2_sq_, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1351 = kk_std_core_types__tuple5_box(_x_x1352, _ctx); /*105*/
    kk_box_t _x_x1354;
    kk_std_core_types__tuple5 _x_x1355 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, y2_sq_, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1354 = kk_std_core_types__tuple5_box(_x_x1355, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1351, _x_x1354, _ctx);
  }
  {
    kk_box_t y2_0_sq_ = _y_x10200._cons.Gt2.lt;
    kk_box_t x2_0_sq_ = _y_x10200._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_box_t _x_x1356;
    kk_std_core_types__tuple5 _x_x1357;
    kk_box_t _x_x1358 = kk_box_dup(z1, _ctx); /*4748*/
    _x_x1357 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, _x_x1358, y2_0_sq_, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1356 = kk_std_core_types__tuple5_box(_x_x1357, _ctx); /*105*/
    kk_box_t _x_x1359;
    kk_std_core_types__tuple5 _x_x1360 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, z1, x2_0_sq_, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1359 = kk_std_core_types__tuple5_box(_x_x1360, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1356, _x_x1359, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t x5;
  kk_box_t y3;
  kk_box_t y4;
  kk_box_t y5;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362(kk_function_t _fself, kk_box_t _b_x495, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_order2_10300_fun1362(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t x5, kk_box_t y3, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->x5 = x5;
  _self->y3 = y3;
  _self->y4 = y4;
  _self->y5 = y5;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362(kk_function_t _fself, kk_box_t _b_x495, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_order2_10300_fun1362__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (4750, 4750) -> 4752 order2<4750> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (4751, 4751) -> 4752 order2<4751> */
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x3 = _self->x3; /* 4750 */
  kk_box_t x4 = _self->x4; /* 4751 */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y3 = _self->y3; /* 4750 */
  kk_box_t y4 = _self->y4; /* 4751 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10200_505 = kk_std_core_types__order2_unbox(_b_x495, KK_OWNED, _ctx); /*order2<4749>*/;
  kk_std_core_types__order2 _x_x1363 = kk_std_core_tuple_tuple5_fs__mlift_order2_10299(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x3, x4, x5, y3, y4, y5, z1, _y_x10200_505, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1363, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs__mlift_order2_10300(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_box_t x5, kk_box_t y2, kk_box_t y3, kk_box_t y4, kk_box_t y5, kk_std_core_types__order2 _y_x10199, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>, ?field5/order2 : (a1, a1) -> e order2<a1>, x2 : b, x3 : c, x4 : d, x5 : a1, y2 : b, y3 : c, y4 : d, y5 : a1, order2<a>) -> e order2<(a, b, c, d, a1)> */ 
  if (kk_std_core_types__is_Eq2(_y_x10199, _ctx)) {
    kk_box_t z1 = _y_x10199._cons.Eq2.eq;
    kk_std_core_types__order2 x_10590 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_b_fs_order2, (_implicit_fs_b_fs_order2, x2, y2, _ctx), _ctx); /*order2<4749>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__order2_drop(x_10590, _ctx);
      kk_box_t _x_x1361 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_order2_10300_fun1362(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x3, x4, x5, y3, y4, y5, z1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__order2_unbox(_x_x1361, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_tuple_tuple5_fs__mlift_order2_10299(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x3, x4, x5, y3, y4, y5, z1, x_10590, _ctx);
    }
  }
  if (kk_std_core_types__is_Lt2(_y_x10199, _ctx)) {
    kk_box_t x1_sq_ = _y_x10199._cons.Lt2.lt;
    kk_box_t y1_sq_ = _y_x10199._cons.Lt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1364;
    kk_std_core_types__tuple5 _x_x1365 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, x1_sq_, x2, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1364 = kk_std_core_types__tuple5_box(_x_x1365, _ctx); /*105*/
    kk_box_t _x_x1366;
    kk_std_core_types__tuple5 _x_x1367 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, y1_sq_, y2, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1366 = kk_std_core_types__tuple5_box(_x_x1367, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x1364, _x_x1366, _ctx);
  }
  {
    kk_box_t y1_0_sq_ = _y_x10199._cons.Gt2.lt;
    kk_box_t x1_0_sq_ = _y_x10199._cons.Gt2.gt;
    kk_function_drop(_implicit_fs_field5_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_field4_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_c_fs_order2, _ctx);
    kk_function_drop(_implicit_fs_b_fs_order2, _ctx);
    kk_box_t _x_x1368;
    kk_std_core_types__tuple5 _x_x1369 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, y1_0_sq_, y2, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1368 = kk_std_core_types__tuple5_box(_x_x1369, _ctx); /*105*/
    kk_box_t _x_x1370;
    kk_std_core_types__tuple5 _x_x1371 = kk_std_core_types__new_Tuple5(kk_reuse_null, 0, x1_0_sq_, x2, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
    _x_x1370 = kk_std_core_types__tuple5_box(_x_x1371, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x1368, _x_x1370, _ctx);
  }
}
 
// order2 of tuple5 values


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_order2_fun1377__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_b_fs_order2;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t x5;
  kk_box_t y2;
  kk_box_t y3;
  kk_box_t y4;
  kk_box_t y5;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1377(kk_function_t _fself, kk_box_t _b_x507, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_order2_fun1377(kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x2, kk_box_t x3, kk_box_t x4, kk_box_t x5, kk_box_t y2, kk_box_t y3, kk_box_t y4, kk_box_t y5, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1377__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1377__t, 13, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_order2_fun1377, kk_context());
  _self->_implicit_fs_b_fs_order2 = _implicit_fs_b_fs_order2;
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x2 = x2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->x5 = x5;
  _self->y2 = y2;
  _self->y3 = y3;
  _self->y4 = y4;
  _self->y5 = y5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1377(kk_function_t _fself, kk_box_t _b_x507, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1377__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1377__t*, _fself, _ctx);
  kk_function_t _implicit_fs_b_fs_order2 = _self->_implicit_fs_b_fs_order2; /* (4749, 4749) -> 4752 order2<4749> */
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (4750, 4750) -> 4752 order2<4750> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (4751, 4751) -> 4752 order2<4751> */
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x2 = _self->x2; /* 4749 */
  kk_box_t x3 = _self->x3; /* 4750 */
  kk_box_t x4 = _self->x4; /* 4751 */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y2 = _self->y2; /* 4749 */
  kk_box_t y3 = _self->y3; /* 4750 */
  kk_box_t y4 = _self->y4; /* 4751 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_b_fs_order2, _ctx);kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y2, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(y5, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10199_563 = kk_std_core_types__order2_unbox(_b_x507, KK_OWNED, _ctx); /*order2<4748>*/;
  kk_std_core_types__order2 _x_x1378 = kk_std_core_tuple_tuple5_fs__mlift_order2_10300(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x2, x3, x4, x5, y2, y3, y4, y5, _y_x10199_563, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1378, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_order2_fun1382__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_c_fs_order2;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x3;
  kk_box_t x4;
  kk_box_t x5;
  kk_box_t y3;
  kk_box_t y4;
  kk_box_t y5;
  kk_box_t z1;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1382(kk_function_t _fself, kk_box_t _b_x509, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_order2_fun1382(kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x3, kk_box_t x4, kk_box_t x5, kk_box_t y3, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1382__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1382__t, 11, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_order2_fun1382, kk_context());
  _self->_implicit_fs_c_fs_order2 = _implicit_fs_c_fs_order2;
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x3 = x3;
  _self->x4 = x4;
  _self->x5 = x5;
  _self->y3 = y3;
  _self->y4 = y4;
  _self->y5 = y5;
  _self->z1 = z1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1382(kk_function_t _fself, kk_box_t _b_x509, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1382__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1382__t*, _fself, _ctx);
  kk_function_t _implicit_fs_c_fs_order2 = _self->_implicit_fs_c_fs_order2; /* (4750, 4750) -> 4752 order2<4750> */
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (4751, 4751) -> 4752 order2<4751> */
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x3 = _self->x3; /* 4750 */
  kk_box_t x4 = _self->x4; /* 4751 */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y3 = _self->y3; /* 4750 */
  kk_box_t y4 = _self->y4; /* 4751 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_c_fs_order2, _ctx);kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x3, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y3, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10200_564 = kk_std_core_types__order2_unbox(_b_x509, KK_OWNED, _ctx); /*order2<4749>*/;
  kk_std_core_types__order2 _x_x1383 = kk_std_core_tuple_tuple5_fs__mlift_order2_10299(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x3, x4, x5, y3, y4, y5, z1, _y_x10200_564, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1383, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_order2_fun1387__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_order2;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x4;
  kk_box_t x5;
  kk_box_t y4;
  kk_box_t y5;
  kk_box_t z1;
  kk_box_t z2;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1387(kk_function_t _fself, kk_box_t _b_x511, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_order2_fun1387(kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x4, kk_box_t x5, kk_box_t y4, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1387__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1387__t, 9, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_order2_fun1387, kk_context());
  _self->_implicit_fs_field4_fs_order2 = _implicit_fs_field4_fs_order2;
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x4 = x4;
  _self->x5 = x5;
  _self->y4 = y4;
  _self->y5 = y5;
  _self->z1 = z1;
  _self->z2 = z2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1387(kk_function_t _fself, kk_box_t _b_x511, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1387__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1387__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_order2 = _self->_implicit_fs_field4_fs_order2; /* (4751, 4751) -> 4752 order2<4751> */
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x4 = _self->x4; /* 4751 */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y4 = _self->y4; /* 4751 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x4, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y4, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10201_565 = kk_std_core_types__order2_unbox(_b_x511, KK_OWNED, _ctx); /*order2<4750>*/;
  kk_std_core_types__order2 _x_x1388 = kk_std_core_tuple_tuple5_fs__mlift_order2_10298(_implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x4, x5, y4, y5, z1, z2, _y_x10201_565, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1388, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_order2_fun1392__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs_order2;
  kk_box_t x5;
  kk_box_t y5;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1392(kk_function_t _fself, kk_box_t _b_x513, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_order2_fun1392(kk_function_t _implicit_fs_field5_fs_order2, kk_box_t x5, kk_box_t y5, kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1392__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1392__t, 7, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_order2_fun1392, kk_context());
  _self->_implicit_fs_field5_fs_order2 = _implicit_fs_field5_fs_order2;
  _self->x5 = x5;
  _self->y5 = y5;
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1392(kk_function_t _fself, kk_box_t _b_x513, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1392__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1392__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs_order2 = _self->_implicit_fs_field5_fs_order2; /* (4753, 4753) -> 4752 order2<4753> */
  kk_box_t x5 = _self->x5; /* 4753 */
  kk_box_t y5 = _self->y5; /* 4753 */
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_box_t z3 = _self->z3; /* 4750 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);kk_box_dup(x5, _ctx);kk_box_dup(y5, _ctx);kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10202_566 = kk_std_core_types__order2_unbox(_b_x513, KK_OWNED, _ctx); /*order2<4751>*/;
  kk_std_core_types__order2 _x_x1393 = kk_std_core_tuple_tuple5_fs__mlift_order2_10297(_implicit_fs_field5_fs_order2, x5, y5, z1, z2, z3, _y_x10202_566, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1393, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_order2_fun1396__t {
  struct kk_function_s _base;
  kk_box_t z1;
  kk_box_t z2;
  kk_box_t z3;
  kk_box_t z4;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1396(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_order2_fun1396(kk_box_t z1, kk_box_t z2, kk_box_t z3, kk_box_t z4, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1396__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1396__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_order2_fun1396, kk_context());
  _self->z1 = z1;
  _self->z2 = z2;
  _self->z3 = z3;
  _self->z4 = z4;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_order2_fun1396(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_order2_fun1396__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_order2_fun1396__t*, _fself, _ctx);
  kk_box_t z1 = _self->z1; /* 4748 */
  kk_box_t z2 = _self->z2; /* 4749 */
  kk_box_t z3 = _self->z3; /* 4750 */
  kk_box_t z4 = _self->z4; /* 4751 */
  kk_drop_match(_self, {kk_box_dup(z1, _ctx);kk_box_dup(z2, _ctx);kk_box_dup(z3, _ctx);kk_box_dup(z4, _ctx);}, {}, _ctx)
  kk_std_core_types__order2 _y_x10203_567 = kk_std_core_types__order2_unbox(_b_x515, KK_OWNED, _ctx); /*order2<4753>*/;
  kk_std_core_types__order2 _x_x1397 = kk_std_core_tuple_tuple5_fs__mlift_order2_10296(z1, z2, z3, z4, _y_x10203_567, _ctx); /*order2<(4748, 4749, 4750, 4751, 4753)>*/
  return kk_std_core_types__order2_box(_x_x1397, _ctx);
}

kk_std_core_types__order2 kk_std_core_tuple_tuple5_fs_order2(kk_std_core_types__tuple5 _pat_x148__24, kk_std_core_types__tuple5 _pat_x148__63, kk_function_t _implicit_fs_a_fs_order2, kk_function_t _implicit_fs_b_fs_order2, kk_function_t _implicit_fs_c_fs_order2, kk_function_t _implicit_fs_field4_fs_order2, kk_function_t _implicit_fs_field5_fs_order2, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> ((a, b, c, d, a1), (a, b, c, d, a1), ?a/order2 : (a, a) -> e order2<a>, ?b/order2 : (b, b) -> e order2<b>, ?c/order2 : (c, c) -> e order2<c>, ?field4/order2 : (d, d) -> e order2<d>, ?field5/order2 : (a1, a1) -> e order2<a1>) -> e order2<(a, b, c, d, a1)> */ 
  {
    struct kk_std_core_types_Tuple5* _con_x1372 = kk_std_core_types__as_Tuple5(_pat_x148__24, _ctx);
    kk_box_t x1 = _con_x1372->fst;
    kk_box_t x2 = _con_x1372->snd;
    kk_box_t x3 = _con_x1372->thd;
    kk_box_t x4 = _con_x1372->field4;
    kk_box_t x5 = _con_x1372->field5;
    kk_reuse_t _ru_x781 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_pat_x148__24, _ctx)) {
      _ru_x781 = (kk_datatype_ptr_reuse(_pat_x148__24, _ctx));
    }
    else {
      kk_box_dup(x1, _ctx);
      kk_box_dup(x2, _ctx);
      kk_box_dup(x3, _ctx);
      kk_box_dup(x4, _ctx);
      kk_box_dup(x5, _ctx);
      kk_datatype_ptr_decref(_pat_x148__24, _ctx);
    }
    {
      struct kk_std_core_types_Tuple5* _con_x1373 = kk_std_core_types__as_Tuple5(_pat_x148__63, _ctx);
      kk_box_t y1 = _con_x1373->fst;
      kk_box_t y2 = _con_x1373->snd;
      kk_box_t y3 = _con_x1373->thd;
      kk_box_t y4 = _con_x1373->field4;
      kk_box_t y5 = _con_x1373->field5;
      kk_reuse_t _ru_x782 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_pat_x148__63, _ctx)) {
        _ru_x782 = (kk_datatype_ptr_reuse(_pat_x148__63, _ctx));
      }
      else {
        kk_box_dup(y1, _ctx);
        kk_box_dup(y2, _ctx);
        kk_box_dup(y3, _ctx);
        kk_box_dup(y4, _ctx);
        kk_box_dup(y5, _ctx);
        kk_datatype_ptr_decref(_pat_x148__63, _ctx);
      }
      kk_std_core_types__order2 x_10592;
      kk_function_t _x_x1374 = kk_function_dup(_implicit_fs_a_fs_order2, _ctx); /*(4748, 4748) -> 4752 order2<4748>*/
      x_10592 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1374, (_x_x1374, x1, y1, _ctx), _ctx); /*order2<4748>*/
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x781,kk_context());
        kk_reuse_drop(_ru_x782,kk_context());
        kk_std_core_types__order2_drop(x_10592, _ctx);
        kk_box_t _x_x1375;
        kk_function_t _x_x1376;
        kk_function_dup(_implicit_fs_b_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
        kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);
        _x_x1376 = kk_std_core_tuple_tuple5_fs_new_order2_fun1377(_implicit_fs_b_fs_order2, _implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x2, x3, x4, x5, y2, y3, y4, y5, _ctx); /*(2418) -> 2420 2419*/
        _x_x1375 = kk_std_core_hnd_yield_extend(_x_x1376, _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x1375, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_10592, _ctx)) {
        kk_box_t z1 = x_10592._cons.Eq2.eq;
        kk_std_core_types__order2 x_0_10595;
        kk_function_t _x_x1379 = kk_function_dup(_implicit_fs_b_fs_order2, _ctx); /*(4749, 4749) -> 4752 order2<4749>*/
        x_0_10595 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1379, (_x_x1379, x2, y2, _ctx), _ctx); /*order2<4749>*/
        if (kk_yielding(kk_context())) {
          kk_reuse_drop(_ru_x781,kk_context());
          kk_reuse_drop(_ru_x782,kk_context());
          kk_std_core_types__order2_drop(x_0_10595, _ctx);
          kk_box_t _x_x1380;
          kk_function_t _x_x1381;
          kk_function_dup(_implicit_fs_c_fs_order2, _ctx);
          kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
          kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);
          _x_x1381 = kk_std_core_tuple_tuple5_fs_new_order2_fun1382(_implicit_fs_c_fs_order2, _implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x3, x4, x5, y3, y4, y5, z1, _ctx); /*(2418) -> 2420 2419*/
          _x_x1380 = kk_std_core_hnd_yield_extend(_x_x1381, _ctx); /*2419*/
          return kk_std_core_types__order2_unbox(_x_x1380, KK_OWNED, _ctx);
        }
        if (kk_std_core_types__is_Eq2(x_0_10595, _ctx)) {
          kk_box_t z2 = x_0_10595._cons.Eq2.eq;
          kk_std_core_types__order2 x_1_10598;
          kk_function_t _x_x1384 = kk_function_dup(_implicit_fs_c_fs_order2, _ctx); /*(4750, 4750) -> 4752 order2<4750>*/
          x_1_10598 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1384, (_x_x1384, x3, y3, _ctx), _ctx); /*order2<4750>*/
          if (kk_yielding(kk_context())) {
            kk_reuse_drop(_ru_x781,kk_context());
            kk_reuse_drop(_ru_x782,kk_context());
            kk_std_core_types__order2_drop(x_1_10598, _ctx);
            kk_box_t _x_x1385;
            kk_function_t _x_x1386;
            kk_function_dup(_implicit_fs_field4_fs_order2, _ctx);
            kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);
            _x_x1386 = kk_std_core_tuple_tuple5_fs_new_order2_fun1387(_implicit_fs_field4_fs_order2, _implicit_fs_field5_fs_order2, x4, x5, y4, y5, z1, z2, _ctx); /*(2418) -> 2420 2419*/
            _x_x1385 = kk_std_core_hnd_yield_extend(_x_x1386, _ctx); /*2419*/
            return kk_std_core_types__order2_unbox(_x_x1385, KK_OWNED, _ctx);
          }
          if (kk_std_core_types__is_Eq2(x_1_10598, _ctx)) {
            kk_box_t z3 = x_1_10598._cons.Eq2.eq;
            kk_std_core_types__order2 x_2_10601;
            kk_function_t _x_x1389 = kk_function_dup(_implicit_fs_field4_fs_order2, _ctx); /*(4751, 4751) -> 4752 order2<4751>*/
            x_2_10601 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1389, (_x_x1389, x4, y4, _ctx), _ctx); /*order2<4751>*/
            if (kk_yielding(kk_context())) {
              kk_reuse_drop(_ru_x781,kk_context());
              kk_reuse_drop(_ru_x782,kk_context());
              kk_std_core_types__order2_drop(x_2_10601, _ctx);
              kk_box_t _x_x1390;
              kk_function_t _x_x1391;
              kk_function_dup(_implicit_fs_field5_fs_order2, _ctx);
              _x_x1391 = kk_std_core_tuple_tuple5_fs_new_order2_fun1392(_implicit_fs_field5_fs_order2, x5, y5, z1, z2, z3, _ctx); /*(2418) -> 2420 2419*/
              _x_x1390 = kk_std_core_hnd_yield_extend(_x_x1391, _ctx); /*2419*/
              return kk_std_core_types__order2_unbox(_x_x1390, KK_OWNED, _ctx);
            }
            if (kk_std_core_types__is_Eq2(x_2_10601, _ctx)) {
              kk_box_t z4 = x_2_10601._cons.Eq2.eq;
              kk_std_core_types__order2 x_3_10604;
              kk_function_t _x_x1394 = kk_function_dup(_implicit_fs_field5_fs_order2, _ctx); /*(4753, 4753) -> 4752 order2<4753>*/
              x_3_10604 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x1394, (_x_x1394, x5, y5, _ctx), _ctx); /*order2<4753>*/
              if (kk_yielding(kk_context())) {
                kk_reuse_drop(_ru_x781,kk_context());
                kk_reuse_drop(_ru_x782,kk_context());
                kk_std_core_types__order2_drop(x_3_10604, _ctx);
                kk_box_t _x_x1395 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_order2_fun1396(z1, z2, z3, z4, _ctx), _ctx); /*2419*/
                return kk_std_core_types__order2_unbox(_x_x1395, KK_OWNED, _ctx);
              }
              if (kk_std_core_types__is_Eq2(x_3_10604, _ctx)) {
                kk_box_t z5 = x_3_10604._cons.Eq2.eq;
                kk_reuse_drop(_ru_x781,kk_context());
                kk_box_t _x_x1398;
                kk_std_core_types__tuple5 _x_x1399 = kk_std_core_types__new_Tuple5(_ru_x782, 0, z1, z2, z3, z4, z5, _ctx); /*(161, 162, 163, 164, 165)*/
                _x_x1398 = kk_std_core_types__tuple5_box(_x_x1399, _ctx); /*105*/
                return kk_std_core_types__new_Eq2(_x_x1398, _ctx);
              }
              if (kk_std_core_types__is_Lt2(x_3_10604, _ctx)) {
                kk_box_t x5_sq_ = x_3_10604._cons.Lt2.lt;
                kk_box_t y5_sq_ = x_3_10604._cons.Lt2.gt;
                kk_box_t _x_x1400;
                kk_std_core_types__tuple5 _x_x1401;
                kk_box_t _x_x1402 = kk_box_dup(z1, _ctx); /*4748*/
                kk_box_t _x_x1403 = kk_box_dup(z2, _ctx); /*4749*/
                kk_box_t _x_x1404 = kk_box_dup(z3, _ctx); /*4750*/
                kk_box_t _x_x1405 = kk_box_dup(z4, _ctx); /*4751*/
                _x_x1401 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1402, _x_x1403, _x_x1404, _x_x1405, x5_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
                _x_x1400 = kk_std_core_types__tuple5_box(_x_x1401, _ctx); /*105*/
                kk_box_t _x_x1406;
                kk_std_core_types__tuple5 _x_x1407 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, z3, z4, y5_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
                _x_x1406 = kk_std_core_types__tuple5_box(_x_x1407, _ctx); /*105*/
                return kk_std_core_types__new_Lt2(_x_x1400, _x_x1406, _ctx);
              }
              {
                kk_box_t y5_0_sq_ = x_3_10604._cons.Gt2.lt;
                kk_box_t x5_0_sq_ = x_3_10604._cons.Gt2.gt;
                kk_box_t _x_x1408;
                kk_std_core_types__tuple5 _x_x1409;
                kk_box_t _x_x1410 = kk_box_dup(z1, _ctx); /*4748*/
                kk_box_t _x_x1411 = kk_box_dup(z2, _ctx); /*4749*/
                kk_box_t _x_x1412 = kk_box_dup(z3, _ctx); /*4750*/
                kk_box_t _x_x1413 = kk_box_dup(z4, _ctx); /*4751*/
                _x_x1409 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1410, _x_x1411, _x_x1412, _x_x1413, y5_0_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
                _x_x1408 = kk_std_core_types__tuple5_box(_x_x1409, _ctx); /*105*/
                kk_box_t _x_x1414;
                kk_std_core_types__tuple5 _x_x1415 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, z3, z4, x5_0_sq_, _ctx); /*(161, 162, 163, 164, 165)*/
                _x_x1414 = kk_std_core_types__tuple5_box(_x_x1415, _ctx); /*105*/
                return kk_std_core_types__new_Gt2(_x_x1408, _x_x1414, _ctx);
              }
            }
            if (kk_std_core_types__is_Lt2(x_2_10601, _ctx)) {
              kk_box_t x4_sq_ = x_2_10601._cons.Lt2.lt;
              kk_box_t y4_sq_ = x_2_10601._cons.Lt2.gt;
              kk_box_t _x_x1416;
              kk_std_core_types__tuple5 _x_x1417;
              kk_box_t _x_x1418 = kk_box_dup(z1, _ctx); /*4748*/
              kk_box_t _x_x1419 = kk_box_dup(z2, _ctx); /*4749*/
              kk_box_t _x_x1420 = kk_box_dup(z3, _ctx); /*4750*/
              _x_x1417 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1418, _x_x1419, _x_x1420, x4_sq_, x5, _ctx); /*(161, 162, 163, 164, 165)*/
              _x_x1416 = kk_std_core_types__tuple5_box(_x_x1417, _ctx); /*105*/
              kk_box_t _x_x1421;
              kk_std_core_types__tuple5 _x_x1422 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, z3, y4_sq_, y5, _ctx); /*(161, 162, 163, 164, 165)*/
              _x_x1421 = kk_std_core_types__tuple5_box(_x_x1422, _ctx); /*105*/
              return kk_std_core_types__new_Lt2(_x_x1416, _x_x1421, _ctx);
            }
            {
              kk_box_t y4_0_sq_ = x_2_10601._cons.Gt2.lt;
              kk_box_t x4_0_sq_ = x_2_10601._cons.Gt2.gt;
              kk_box_t _x_x1423;
              kk_std_core_types__tuple5 _x_x1424;
              kk_box_t _x_x1425 = kk_box_dup(z1, _ctx); /*4748*/
              kk_box_t _x_x1426 = kk_box_dup(z2, _ctx); /*4749*/
              kk_box_t _x_x1427 = kk_box_dup(z3, _ctx); /*4750*/
              _x_x1424 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1425, _x_x1426, _x_x1427, y4_0_sq_, y5, _ctx); /*(161, 162, 163, 164, 165)*/
              _x_x1423 = kk_std_core_types__tuple5_box(_x_x1424, _ctx); /*105*/
              kk_box_t _x_x1428;
              kk_std_core_types__tuple5 _x_x1429 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, z3, x4_0_sq_, x5, _ctx); /*(161, 162, 163, 164, 165)*/
              _x_x1428 = kk_std_core_types__tuple5_box(_x_x1429, _ctx); /*105*/
              return kk_std_core_types__new_Gt2(_x_x1423, _x_x1428, _ctx);
            }
          }
          if (kk_std_core_types__is_Lt2(x_1_10598, _ctx)) {
            kk_box_t x3_sq_ = x_1_10598._cons.Lt2.lt;
            kk_box_t y3_sq_ = x_1_10598._cons.Lt2.gt;
            kk_box_t _x_x1430;
            kk_std_core_types__tuple5 _x_x1431;
            kk_box_t _x_x1432 = kk_box_dup(z1, _ctx); /*4748*/
            kk_box_t _x_x1433 = kk_box_dup(z2, _ctx); /*4749*/
            _x_x1431 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1432, _x_x1433, x3_sq_, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
            _x_x1430 = kk_std_core_types__tuple5_box(_x_x1431, _ctx); /*105*/
            kk_box_t _x_x1434;
            kk_std_core_types__tuple5 _x_x1435 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, y3_sq_, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
            _x_x1434 = kk_std_core_types__tuple5_box(_x_x1435, _ctx); /*105*/
            return kk_std_core_types__new_Lt2(_x_x1430, _x_x1434, _ctx);
          }
          {
            kk_box_t y3_0_sq_ = x_1_10598._cons.Gt2.lt;
            kk_box_t x3_0_sq_ = x_1_10598._cons.Gt2.gt;
            kk_box_t _x_x1436;
            kk_std_core_types__tuple5 _x_x1437;
            kk_box_t _x_x1438 = kk_box_dup(z1, _ctx); /*4748*/
            kk_box_t _x_x1439 = kk_box_dup(z2, _ctx); /*4749*/
            _x_x1437 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1438, _x_x1439, y3_0_sq_, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
            _x_x1436 = kk_std_core_types__tuple5_box(_x_x1437, _ctx); /*105*/
            kk_box_t _x_x1440;
            kk_std_core_types__tuple5 _x_x1441 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, z2, x3_0_sq_, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
            _x_x1440 = kk_std_core_types__tuple5_box(_x_x1441, _ctx); /*105*/
            return kk_std_core_types__new_Gt2(_x_x1436, _x_x1440, _ctx);
          }
        }
        if (kk_std_core_types__is_Lt2(x_0_10595, _ctx)) {
          kk_box_t x2_sq_ = x_0_10595._cons.Lt2.lt;
          kk_box_t y2_sq_ = x_0_10595._cons.Lt2.gt;
          kk_box_t _x_x1442;
          kk_std_core_types__tuple5 _x_x1443;
          kk_box_t _x_x1444 = kk_box_dup(z1, _ctx); /*4748*/
          _x_x1443 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1444, x2_sq_, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
          _x_x1442 = kk_std_core_types__tuple5_box(_x_x1443, _ctx); /*105*/
          kk_box_t _x_x1445;
          kk_std_core_types__tuple5 _x_x1446 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, y2_sq_, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
          _x_x1445 = kk_std_core_types__tuple5_box(_x_x1446, _ctx); /*105*/
          return kk_std_core_types__new_Lt2(_x_x1442, _x_x1445, _ctx);
        }
        {
          kk_box_t y2_0_sq_ = x_0_10595._cons.Gt2.lt;
          kk_box_t x2_0_sq_ = x_0_10595._cons.Gt2.gt;
          kk_box_t _x_x1447;
          kk_std_core_types__tuple5 _x_x1448;
          kk_box_t _x_x1449 = kk_box_dup(z1, _ctx); /*4748*/
          _x_x1448 = kk_std_core_types__new_Tuple5(_ru_x782, 0, _x_x1449, y2_0_sq_, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
          _x_x1447 = kk_std_core_types__tuple5_box(_x_x1448, _ctx); /*105*/
          kk_box_t _x_x1450;
          kk_std_core_types__tuple5 _x_x1451 = kk_std_core_types__new_Tuple5(_ru_x781, 0, z1, x2_0_sq_, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
          _x_x1450 = kk_std_core_types__tuple5_box(_x_x1451, _ctx); /*105*/
          return kk_std_core_types__new_Gt2(_x_x1447, _x_x1450, _ctx);
        }
      }
      if (kk_std_core_types__is_Lt2(x_10592, _ctx)) {
        kk_box_t x1_sq_ = x_10592._cons.Lt2.lt;
        kk_box_t y1_sq_ = x_10592._cons.Lt2.gt;
        kk_box_t _x_x1452;
        kk_std_core_types__tuple5 _x_x1453 = kk_std_core_types__new_Tuple5(_ru_x782, 0, x1_sq_, x2, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
        _x_x1452 = kk_std_core_types__tuple5_box(_x_x1453, _ctx); /*105*/
        kk_box_t _x_x1454;
        kk_std_core_types__tuple5 _x_x1455 = kk_std_core_types__new_Tuple5(_ru_x781, 0, y1_sq_, y2, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
        _x_x1454 = kk_std_core_types__tuple5_box(_x_x1455, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x1452, _x_x1454, _ctx);
      }
      {
        kk_box_t y1_0_sq_ = x_10592._cons.Gt2.lt;
        kk_box_t x1_0_sq_ = x_10592._cons.Gt2.gt;
        kk_box_t _x_x1456;
        kk_std_core_types__tuple5 _x_x1457 = kk_std_core_types__new_Tuple5(_ru_x782, 0, y1_0_sq_, y2, y3, y4, y5, _ctx); /*(161, 162, 163, 164, 165)*/
        _x_x1456 = kk_std_core_types__tuple5_box(_x_x1457, _ctx); /*105*/
        kk_box_t _x_x1458;
        kk_std_core_types__tuple5 _x_x1459 = kk_std_core_types__new_Tuple5(_ru_x781, 0, x1_0_sq_, x2, x3, x4, x5, _ctx); /*(161, 162, 163, 164, 165)*/
        _x_x1458 = kk_std_core_types__tuple5_box(_x_x1459, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x1456, _x_x1458, _ctx);
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471__t {
  struct kk_function_s _base;
  kk_string_t _y_x10210;
};
static kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471(kk_function_t _fself, kk_string_t _y_x10211, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_show_10302_fun1471(kk_string_t _y_x10210, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471, kk_context());
  _self->_y_x10210 = _y_x10210;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471(kk_function_t _fself, kk_string_t _y_x10211, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1471__t*, _fself, _ctx);
  kk_string_t _y_x10210 = _self->_y_x10210; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10210, _ctx);}, {}, _ctx)
  kk_string_t _x_x1472;
  kk_define_string_literal(static, _s_x1473, 1, "(", _ctx)
  _x_x1472 = kk_string_dup(_s_x1473, _ctx); /*string*/
  kk_string_t _x_x1474;
  kk_string_t _x_x1475;
  kk_string_t _x_x1476;
  kk_define_string_literal(static, _s_x1477, 1, ",", _ctx)
  _x_x1476 = kk_string_dup(_s_x1477, _ctx); /*string*/
  kk_string_t _x_x1478;
  kk_string_t _x_x1479;
  kk_define_string_literal(static, _s_x1480, 1, ")", _ctx)
  _x_x1479 = kk_string_dup(_s_x1480, _ctx); /*string*/
  _x_x1478 = kk_std_core_types__lp__plus__plus__rp_(_y_x10211, _x_x1479, _ctx); /*string*/
  _x_x1475 = kk_std_core_types__lp__plus__plus__rp_(_x_x1476, _x_x1478, _ctx); /*string*/
  _x_x1474 = kk_std_core_types__lp__plus__plus__rp_(_y_x10210, _x_x1475, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1472, _x_x1474, _ctx);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482__t {
  struct kk_function_s _base;
  kk_function_t next_10608;
};
static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482(kk_function_t _fself, kk_box_t _b_x569, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs__new_mlift_show_10302_fun1482(kk_function_t next_10608, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482, kk_context());
  _self->next_10608 = next_10608;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482(kk_function_t _fself, kk_box_t _b_x569, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs__mlift_show_10302_fun1482__t*, _fself, _ctx);
  kk_function_t next_10608 = _self->next_10608; /* (string) -> 5015 string */
  kk_drop_match(_self, {kk_function_dup(next_10608, _ctx);}, {}, _ctx)
  kk_string_t _x_x1483;
  kk_string_t _x_x1484 = kk_string_unbox(_b_x569); /*string*/
  _x_x1483 = kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10608, (next_10608, _x_x1484, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1483);
}

kk_string_t kk_std_core_tuple_tuple2_fs__mlift_show_10302(kk_function_t _implicit_fs_snd_fs_show, kk_std_core_types__tuple2 x, kk_string_t _y_x10210, kk_context_t* _ctx) { /* forall<a,b,e> (?snd/show : (b) -> e string, x : (a, b), string) -> e string */ 
  kk_string_t x_0_10607;
  kk_box_t _x_x1470;
  {
    kk_box_t _x_0 = x.snd;
    kk_box_dup(_x_0, _ctx);
    kk_std_core_types__tuple2_drop(x, _ctx);
    _x_x1470 = _x_0; /*5014*/
  }
  x_0_10607 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1470, _ctx), _ctx); /*string*/
  kk_function_t next_10608 = kk_std_core_tuple_tuple2_fs__new_mlift_show_10302_fun1471(_y_x10210, _ctx); /*(string) -> 5015 string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10607, _ctx);
    kk_box_t _x_x1481 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs__new_mlift_show_10302_fun1482(next_10608, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1481);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10608, (next_10608, x_0_10607, _ctx), _ctx);
  }
}
 
// Show a tuple


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_show_fun1487__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_std_core_types__tuple2 x;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun1487(kk_function_t _fself, kk_box_t _b_x572, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_show_fun1487(kk_function_t _implicit_fs_snd_fs_show, kk_std_core_types__tuple2 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun1487__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_show_fun1487__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_show_fun1487, kk_context());
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun1487(kk_function_t _fself, kk_box_t _b_x572, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun1487__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_show_fun1487__t*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (5014) -> 5015 string */
  kk_std_core_types__tuple2 x = _self->x; /* (5013, 5014) */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_std_core_types__tuple2_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10210_577 = kk_string_unbox(_b_x572); /*string*/;
  kk_string_t _x_x1488 = kk_std_core_tuple_tuple2_fs__mlift_show_10302(_implicit_fs_snd_fs_show, x, _y_x10210_577, _ctx); /*string*/
  return kk_string_box(_x_x1488);
}


// lift anonymous function
struct kk_std_core_tuple_tuple2_fs_show_fun1491__t {
  struct kk_function_s _base;
  kk_string_t x_0_10611;
};
static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun1491(kk_function_t _fself, kk_box_t _b_x574, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple2_fs_new_show_fun1491(kk_string_t x_0_10611, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun1491__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple2_fs_show_fun1491__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple2_fs_show_fun1491, kk_context());
  _self->x_0_10611 = x_0_10611;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple2_fs_show_fun1491(kk_function_t _fself, kk_box_t _b_x574, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple2_fs_show_fun1491__t* _self = kk_function_as(struct kk_std_core_tuple_tuple2_fs_show_fun1491__t*, _fself, _ctx);
  kk_string_t x_0_10611 = _self->x_0_10611; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10611, _ctx);}, {}, _ctx)
  kk_string_t _y_x10211_578 = kk_string_unbox(_b_x574); /*string*/;
  kk_string_t _x_x1492;
  kk_string_t _x_x1493;
  kk_define_string_literal(static, _s_x1494, 1, "(", _ctx)
  _x_x1493 = kk_string_dup(_s_x1494, _ctx); /*string*/
  kk_string_t _x_x1495;
  kk_string_t _x_x1496;
  kk_string_t _x_x1497;
  kk_define_string_literal(static, _s_x1498, 1, ",", _ctx)
  _x_x1497 = kk_string_dup(_s_x1498, _ctx); /*string*/
  kk_string_t _x_x1499;
  kk_string_t _x_x1500;
  kk_define_string_literal(static, _s_x1501, 1, ")", _ctx)
  _x_x1500 = kk_string_dup(_s_x1501, _ctx); /*string*/
  _x_x1499 = kk_std_core_types__lp__plus__plus__rp_(_y_x10211_578, _x_x1500, _ctx); /*string*/
  _x_x1496 = kk_std_core_types__lp__plus__plus__rp_(_x_x1497, _x_x1499, _ctx); /*string*/
  _x_x1495 = kk_std_core_types__lp__plus__plus__rp_(x_0_10611, _x_x1496, _ctx); /*string*/
  _x_x1492 = kk_std_core_types__lp__plus__plus__rp_(_x_x1493, _x_x1495, _ctx); /*string*/
  return kk_string_box(_x_x1492);
}

kk_string_t kk_std_core_tuple_tuple2_fs_show(kk_std_core_types__tuple2 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx) { /* forall<a,b,e> (x : (a, b), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */ 
  kk_string_t x_0_10611;
  kk_box_t _x_x1485;
  {
    kk_box_t _x = x.fst;
    kk_box_dup(_x, _ctx);
    _x_x1485 = _x; /*5013*/
  }
  x_0_10611 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x1485, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10611, _ctx);
    kk_box_t _x_x1486 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_show_fun1487(_implicit_fs_snd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1486);
  }
  {
    kk_string_t x_1_10614;
    kk_box_t _x_x1489;
    {
      kk_box_t _x_0 = x.snd;
      kk_box_dup(_x_0, _ctx);
      kk_std_core_types__tuple2_drop(x, _ctx);
      _x_x1489 = _x_0; /*5014*/
    }
    x_1_10614 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1489, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10614, _ctx);
      kk_box_t _x_x1490 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple2_fs_new_show_fun1491(x_0_10611, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1490);
    }
    {
      kk_string_t _x_x1502;
      kk_define_string_literal(static, _s_x1503, 1, "(", _ctx)
      _x_x1502 = kk_string_dup(_s_x1503, _ctx); /*string*/
      kk_string_t _x_x1504;
      kk_string_t _x_x1505;
      kk_string_t _x_x1506;
      kk_define_string_literal(static, _s_x1507, 1, ",", _ctx)
      _x_x1506 = kk_string_dup(_s_x1507, _ctx); /*string*/
      kk_string_t _x_x1508;
      kk_string_t _x_x1509;
      kk_define_string_literal(static, _s_x1510, 1, ")", _ctx)
      _x_x1509 = kk_string_dup(_s_x1510, _ctx); /*string*/
      _x_x1508 = kk_std_core_types__lp__plus__plus__rp_(x_1_10614, _x_x1509, _ctx); /*string*/
      _x_x1505 = kk_std_core_types__lp__plus__plus__rp_(_x_x1506, _x_x1508, _ctx); /*string*/
      _x_x1504 = kk_std_core_types__lp__plus__plus__rp_(x_0_10611, _x_x1505, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x1502, _x_x1504, _ctx);
    }
  }
}
 
// monadic lift

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10303(kk_string_t _y_x10212, kk_string_t _y_x10213, kk_string_t _y_x10214, kk_context_t* _ctx) { /* forall<e> (string, string, string) -> e string */ 
  kk_string_t _x_x1511;
  kk_define_string_literal(static, _s_x1512, 1, "(", _ctx)
  _x_x1511 = kk_string_dup(_s_x1512, _ctx); /*string*/
  kk_string_t _x_x1513;
  kk_string_t _x_x1514;
  kk_string_t _x_x1515;
  kk_define_string_literal(static, _s_x1516, 1, ",", _ctx)
  _x_x1515 = kk_string_dup(_s_x1516, _ctx); /*string*/
  kk_string_t _x_x1517;
  kk_string_t _x_x1518;
  kk_string_t _x_x1519;
  kk_define_string_literal(static, _s_x1520, 1, ",", _ctx)
  _x_x1519 = kk_string_dup(_s_x1520, _ctx); /*string*/
  kk_string_t _x_x1521;
  kk_string_t _x_x1522;
  kk_define_string_literal(static, _s_x1523, 1, ")", _ctx)
  _x_x1522 = kk_string_dup(_s_x1523, _ctx); /*string*/
  _x_x1521 = kk_std_core_types__lp__plus__plus__rp_(_y_x10214, _x_x1522, _ctx); /*string*/
  _x_x1518 = kk_std_core_types__lp__plus__plus__rp_(_x_x1519, _x_x1521, _ctx); /*string*/
  _x_x1517 = kk_std_core_types__lp__plus__plus__rp_(_y_x10213, _x_x1518, _ctx); /*string*/
  _x_x1514 = kk_std_core_types__lp__plus__plus__rp_(_x_x1515, _x_x1517, _ctx); /*string*/
  _x_x1513 = kk_std_core_types__lp__plus__plus__rp_(_y_x10212, _x_x1514, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1511, _x_x1513, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526__t {
  struct kk_function_s _base;
  kk_string_t _y_x10212;
  kk_string_t _y_x10213;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526(kk_function_t _fself, kk_box_t _b_x580, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_show_10304_fun1526(kk_string_t _y_x10212, kk_string_t _y_x10213, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526, kk_context());
  _self->_y_x10212 = _y_x10212;
  _self->_y_x10213 = _y_x10213;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526(kk_function_t _fself, kk_box_t _b_x580, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10304_fun1526__t*, _fself, _ctx);
  kk_string_t _y_x10212 = _self->_y_x10212; /* string */
  kk_string_t _y_x10213 = _self->_y_x10213; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10212, _ctx);kk_string_dup(_y_x10213, _ctx);}, {}, _ctx)
  kk_string_t _y_x10214_582 = kk_string_unbox(_b_x580); /*string*/;
  kk_string_t _x_x1527 = kk_std_core_tuple_tuple3_fs__mlift_show_10303(_y_x10212, _y_x10213, _y_x10214_582, _ctx); /*string*/
  return kk_string_box(_x_x1527);
}

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10304(kk_string_t _y_x10212, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple3 x, kk_string_t _y_x10213, kk_context_t* _ctx) { /* forall<a,b,c,e> (string, ?thd/show : (c) -> e string, x : (a, b, c), string) -> e string */ 
  kk_string_t x_0_10619;
  kk_box_t _x_x1524;
  {
    kk_box_t _x_1 = x.thd;
    kk_box_dup(_x_1, _ctx);
    kk_std_core_types__tuple3_drop(x, _ctx);
    _x_x1524 = _x_1; /*5318*/
  }
  x_0_10619 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1524, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10619, _ctx);
    kk_box_t _x_x1525 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_show_10304_fun1526(_y_x10212, _y_x10213, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1525);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_show_10303(_y_x10212, _y_x10213, x_0_10619, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530__t {
  struct kk_function_s _base;
  kk_string_t _y_x10212;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple3 x;
};
static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530(kk_function_t _fself, kk_box_t _b_x584, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs__new_mlift_show_10305_fun1530(kk_string_t _y_x10212, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple3 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530, kk_context());
  _self->_y_x10212 = _y_x10212;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530(kk_function_t _fself, kk_box_t _b_x584, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs__mlift_show_10305_fun1530__t*, _fself, _ctx);
  kk_string_t _y_x10212 = _self->_y_x10212; /* string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5318) -> 5319 string */
  kk_std_core_types__tuple3 x = _self->x; /* (5316, 5317, 5318) */
  kk_drop_match(_self, {kk_string_dup(_y_x10212, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple3_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10213_586 = kk_string_unbox(_b_x584); /*string*/;
  kk_string_t _x_x1531 = kk_std_core_tuple_tuple3_fs__mlift_show_10304(_y_x10212, _implicit_fs_thd_fs_show, x, _y_x10213_586, _ctx); /*string*/
  return kk_string_box(_x_x1531);
}

kk_string_t kk_std_core_tuple_tuple3_fs__mlift_show_10305(kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple3 x, kk_string_t _y_x10212, kk_context_t* _ctx) { /* forall<a,b,c,e> (?snd/show : (b) -> e string, ?thd/show : (c) -> e string, x : (a, b, c), string) -> e string */ 
  kk_string_t x_0_10621;
  kk_box_t _x_x1528;
  {
    kk_box_t _x_0 = x.snd;
    kk_box_dup(_x_0, _ctx);
    _x_x1528 = _x_0; /*5317*/
  }
  x_0_10621 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1528, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10621, _ctx);
    kk_box_t _x_x1529 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs__new_mlift_show_10305_fun1530(_y_x10212, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1529);
  }
  {
    return kk_std_core_tuple_tuple3_fs__mlift_show_10304(_y_x10212, _implicit_fs_thd_fs_show, x, x_0_10621, _ctx);
  }
}
 
// Show a triple


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun1534__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple3 x;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1534(kk_function_t _fself, kk_box_t _b_x588, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun1534(kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple3 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1534__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun1534__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun1534, kk_context());
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1534(kk_function_t _fself, kk_box_t _b_x588, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1534__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun1534__t*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (5317) -> 5319 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5318) -> 5319 string */
  kk_std_core_types__tuple3 x = _self->x; /* (5316, 5317, 5318) */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple3_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10212_596 = kk_string_unbox(_b_x588); /*string*/;
  kk_string_t _x_x1535 = kk_std_core_tuple_tuple3_fs__mlift_show_10305(_implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _y_x10212_596, _ctx); /*string*/
  return kk_string_box(_x_x1535);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun1538__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple3 x;
  kk_string_t x_0_10623;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1538(kk_function_t _fself, kk_box_t _b_x590, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun1538(kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple3 x, kk_string_t x_0_10623, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1538__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun1538__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun1538, kk_context());
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  _self->x_0_10623 = x_0_10623;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1538(kk_function_t _fself, kk_box_t _b_x590, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1538__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun1538__t*, _fself, _ctx);
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5318) -> 5319 string */
  kk_std_core_types__tuple3 x = _self->x; /* (5316, 5317, 5318) */
  kk_string_t x_0_10623 = _self->x_0_10623; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple3_dup(x, _ctx);kk_string_dup(x_0_10623, _ctx);}, {}, _ctx)
  kk_string_t _y_x10213_597 = kk_string_unbox(_b_x590); /*string*/;
  kk_string_t _x_x1539 = kk_std_core_tuple_tuple3_fs__mlift_show_10304(x_0_10623, _implicit_fs_thd_fs_show, x, _y_x10213_597, _ctx); /*string*/
  return kk_string_box(_x_x1539);
}


// lift anonymous function
struct kk_std_core_tuple_tuple3_fs_show_fun1542__t {
  struct kk_function_s _base;
  kk_string_t x_0_10623;
  kk_string_t x_1_10626;
};
static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1542(kk_function_t _fself, kk_box_t _b_x592, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple3_fs_new_show_fun1542(kk_string_t x_0_10623, kk_string_t x_1_10626, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1542__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple3_fs_show_fun1542__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple3_fs_show_fun1542, kk_context());
  _self->x_0_10623 = x_0_10623;
  _self->x_1_10626 = x_1_10626;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple3_fs_show_fun1542(kk_function_t _fself, kk_box_t _b_x592, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple3_fs_show_fun1542__t* _self = kk_function_as(struct kk_std_core_tuple_tuple3_fs_show_fun1542__t*, _fself, _ctx);
  kk_string_t x_0_10623 = _self->x_0_10623; /* string */
  kk_string_t x_1_10626 = _self->x_1_10626; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10623, _ctx);kk_string_dup(x_1_10626, _ctx);}, {}, _ctx)
  kk_string_t _y_x10214_598 = kk_string_unbox(_b_x592); /*string*/;
  kk_string_t _x_x1543 = kk_std_core_tuple_tuple3_fs__mlift_show_10303(x_0_10623, x_1_10626, _y_x10214_598, _ctx); /*string*/
  return kk_string_box(_x_x1543);
}

kk_string_t kk_std_core_tuple_tuple3_fs_show(kk_std_core_types__tuple3 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_context_t* _ctx) { /* forall<a,b,c,e> (x : (a, b, c), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string) -> e string */ 
  kk_string_t x_0_10623;
  kk_box_t _x_x1532;
  {
    kk_box_t _x = x.fst;
    kk_box_dup(_x, _ctx);
    _x_x1532 = _x; /*5316*/
  }
  x_0_10623 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x1532, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10623, _ctx);
    kk_box_t _x_x1533 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun1534(_implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1533);
  }
  {
    kk_string_t x_1_10626;
    kk_box_t _x_x1536;
    {
      kk_box_t _x_0 = x.snd;
      kk_box_dup(_x_0, _ctx);
      _x_x1536 = _x_0; /*5317*/
    }
    x_1_10626 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1536, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10626, _ctx);
      kk_box_t _x_x1537 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun1538(_implicit_fs_thd_fs_show, x, x_0_10623, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1537);
    }
    {
      kk_string_t x_2_10629;
      kk_box_t _x_x1540;
      {
        kk_box_t _x_1 = x.thd;
        kk_box_dup(_x_1, _ctx);
        kk_std_core_types__tuple3_drop(x, _ctx);
        _x_x1540 = _x_1; /*5318*/
      }
      x_2_10629 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1540, _ctx), _ctx); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10629, _ctx);
        kk_box_t _x_x1541 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple3_fs_new_show_fun1542(x_0_10623, x_1_10626, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x1541);
      }
      {
        kk_string_t _x_x1544;
        kk_define_string_literal(static, _s_x1545, 1, "(", _ctx)
        _x_x1544 = kk_string_dup(_s_x1545, _ctx); /*string*/
        kk_string_t _x_x1546;
        kk_string_t _x_x1547;
        kk_string_t _x_x1548;
        kk_define_string_literal(static, _s_x1549, 1, ",", _ctx)
        _x_x1548 = kk_string_dup(_s_x1549, _ctx); /*string*/
        kk_string_t _x_x1550;
        kk_string_t _x_x1551;
        kk_string_t _x_x1552;
        kk_define_string_literal(static, _s_x1553, 1, ",", _ctx)
        _x_x1552 = kk_string_dup(_s_x1553, _ctx); /*string*/
        kk_string_t _x_x1554;
        kk_string_t _x_x1555;
        kk_define_string_literal(static, _s_x1556, 1, ")", _ctx)
        _x_x1555 = kk_string_dup(_s_x1556, _ctx); /*string*/
        _x_x1554 = kk_std_core_types__lp__plus__plus__rp_(x_2_10629, _x_x1555, _ctx); /*string*/
        _x_x1551 = kk_std_core_types__lp__plus__plus__rp_(_x_x1552, _x_x1554, _ctx); /*string*/
        _x_x1550 = kk_std_core_types__lp__plus__plus__rp_(x_1_10626, _x_x1551, _ctx); /*string*/
        _x_x1547 = kk_std_core_types__lp__plus__plus__rp_(_x_x1548, _x_x1550, _ctx); /*string*/
        _x_x1546 = kk_std_core_types__lp__plus__plus__rp_(x_0_10623, _x_x1547, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x1544, _x_x1546, _ctx);
      }
    }
  }
}
 
// monadic lift

kk_string_t kk_std_core_tuple_tuple4_fs__mlift_show_10306(kk_string_t _y_x10215, kk_string_t _y_x10216, kk_string_t _y_x10217, kk_string_t _y_x10218, kk_context_t* _ctx) { /* forall<e> (string, string, string, string) -> e string */ 
  kk_string_t _x_x1557;
  kk_define_string_literal(static, _s_x1558, 1, "(", _ctx)
  _x_x1557 = kk_string_dup(_s_x1558, _ctx); /*string*/
  kk_string_t _x_x1559;
  kk_string_t _x_x1560;
  kk_string_t _x_x1561;
  kk_define_string_literal(static, _s_x1562, 1, ",", _ctx)
  _x_x1561 = kk_string_dup(_s_x1562, _ctx); /*string*/
  kk_string_t _x_x1563;
  kk_string_t _x_x1564;
  kk_string_t _x_x1565;
  kk_define_string_literal(static, _s_x1566, 1, ",", _ctx)
  _x_x1565 = kk_string_dup(_s_x1566, _ctx); /*string*/
  kk_string_t _x_x1567;
  kk_string_t _x_x1568;
  kk_string_t _x_x1569;
  kk_define_string_literal(static, _s_x1570, 1, ",", _ctx)
  _x_x1569 = kk_string_dup(_s_x1570, _ctx); /*string*/
  kk_string_t _x_x1571;
  kk_string_t _x_x1572;
  kk_define_string_literal(static, _s_x1573, 1, ")", _ctx)
  _x_x1572 = kk_string_dup(_s_x1573, _ctx); /*string*/
  _x_x1571 = kk_std_core_types__lp__plus__plus__rp_(_y_x10218, _x_x1572, _ctx); /*string*/
  _x_x1568 = kk_std_core_types__lp__plus__plus__rp_(_x_x1569, _x_x1571, _ctx); /*string*/
  _x_x1567 = kk_std_core_types__lp__plus__plus__rp_(_y_x10217, _x_x1568, _ctx); /*string*/
  _x_x1564 = kk_std_core_types__lp__plus__plus__rp_(_x_x1565, _x_x1567, _ctx); /*string*/
  _x_x1563 = kk_std_core_types__lp__plus__plus__rp_(_y_x10216, _x_x1564, _ctx); /*string*/
  _x_x1560 = kk_std_core_types__lp__plus__plus__rp_(_x_x1561, _x_x1563, _ctx); /*string*/
  _x_x1559 = kk_std_core_types__lp__plus__plus__rp_(_y_x10215, _x_x1560, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1557, _x_x1559, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577__t {
  struct kk_function_s _base;
  kk_string_t _y_x10215;
  kk_string_t _y_x10216;
  kk_string_t _y_x10217;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577(kk_function_t _fself, kk_box_t _b_x600, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_show_10307_fun1577(kk_string_t _y_x10215, kk_string_t _y_x10216, kk_string_t _y_x10217, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577, kk_context());
  _self->_y_x10215 = _y_x10215;
  _self->_y_x10216 = _y_x10216;
  _self->_y_x10217 = _y_x10217;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577(kk_function_t _fself, kk_box_t _b_x600, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10307_fun1577__t*, _fself, _ctx);
  kk_string_t _y_x10215 = _self->_y_x10215; /* string */
  kk_string_t _y_x10216 = _self->_y_x10216; /* string */
  kk_string_t _y_x10217 = _self->_y_x10217; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10215, _ctx);kk_string_dup(_y_x10216, _ctx);kk_string_dup(_y_x10217, _ctx);}, {}, _ctx)
  kk_string_t _y_x10218_602 = kk_string_unbox(_b_x600); /*string*/;
  kk_string_t _x_x1578 = kk_std_core_tuple_tuple4_fs__mlift_show_10306(_y_x10215, _y_x10216, _y_x10217, _y_x10218_602, _ctx); /*string*/
  return kk_string_box(_x_x1578);
}

kk_string_t kk_std_core_tuple_tuple4_fs__mlift_show_10307(kk_string_t _y_x10215, kk_string_t _y_x10216, kk_function_t _implicit_fs_field4_fs_show, kk_std_core_types__tuple4 x, kk_string_t _y_x10217, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (string, string, ?field4/show : (d) -> e string, x : (a, b, c, d), string) -> e string */ 
  kk_string_t x_0_10632;
  kk_box_t _x_x1574;
  {
    struct kk_std_core_types_Tuple4* _con_x1575 = kk_std_core_types__as_Tuple4(x, _ctx);
    kk_box_t _pat_0_2 = _con_x1575->fst;
    kk_box_t _pat_1_2 = _con_x1575->snd;
    kk_box_t _pat_2_2 = _con_x1575->thd;
    kk_box_t _x_2 = _con_x1575->field4;
    if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
      kk_box_drop(_pat_2_2, _ctx);
      kk_box_drop(_pat_1_2, _ctx);
      kk_box_drop(_pat_0_2, _ctx);
      kk_datatype_ptr_free(x, _ctx);
    }
    else {
      kk_box_dup(_x_2, _ctx);
      kk_datatype_ptr_decref(x, _ctx);
    }
    _x_x1574 = _x_2; /*5720*/
  }
  x_0_10632 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_show, (_implicit_fs_field4_fs_show, _x_x1574, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10632, _ctx);
    kk_box_t _x_x1576 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_show_10307_fun1577(_y_x10215, _y_x10216, _y_x10217, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1576);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_show_10306(_y_x10215, _y_x10216, _y_x10217, x_0_10632, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582__t {
  struct kk_function_s _base;
  kk_string_t _y_x10215;
  kk_string_t _y_x10216;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_std_core_types__tuple4 x;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582(kk_function_t _fself, kk_box_t _b_x604, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_show_10308_fun1582(kk_string_t _y_x10215, kk_string_t _y_x10216, kk_function_t _implicit_fs_field4_fs_show, kk_std_core_types__tuple4 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582, kk_context());
  _self->_y_x10215 = _y_x10215;
  _self->_y_x10216 = _y_x10216;
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582(kk_function_t _fself, kk_box_t _b_x604, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10308_fun1582__t*, _fself, _ctx);
  kk_string_t _y_x10215 = _self->_y_x10215; /* string */
  kk_string_t _y_x10216 = _self->_y_x10216; /* string */
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (5720) -> 5721 string */
  kk_std_core_types__tuple4 x = _self->x; /* (5717, 5718, 5719, 5720) */
  kk_drop_match(_self, {kk_string_dup(_y_x10215, _ctx);kk_string_dup(_y_x10216, _ctx);kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_std_core_types__tuple4_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10217_606 = kk_string_unbox(_b_x604); /*string*/;
  kk_string_t _x_x1583 = kk_std_core_tuple_tuple4_fs__mlift_show_10307(_y_x10215, _y_x10216, _implicit_fs_field4_fs_show, x, _y_x10217_606, _ctx); /*string*/
  return kk_string_box(_x_x1583);
}

kk_string_t kk_std_core_tuple_tuple4_fs__mlift_show_10308(kk_string_t _y_x10215, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple4 x, kk_string_t _y_x10216, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (string, ?field4/show : (d) -> e string, ?thd/show : (c) -> e string, x : (a, b, c, d), string) -> e string */ 
  kk_string_t x_0_10634;
  kk_box_t _x_x1579;
  {
    struct kk_std_core_types_Tuple4* _con_x1580 = kk_std_core_types__as_Tuple4(x, _ctx);
    kk_box_t _x_1 = _con_x1580->thd;
    kk_box_dup(_x_1, _ctx);
    _x_x1579 = _x_1; /*5719*/
  }
  x_0_10634 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1579, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10634, _ctx);
    kk_box_t _x_x1581 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_show_10308_fun1582(_y_x10215, _y_x10216, _implicit_fs_field4_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1581);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_show_10307(_y_x10215, _y_x10216, _implicit_fs_field4_fs_show, x, x_0_10634, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587__t {
  struct kk_function_s _base;
  kk_string_t _y_x10215;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple4 x;
};
static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587(kk_function_t _fself, kk_box_t _b_x608, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs__new_mlift_show_10309_fun1587(kk_string_t _y_x10215, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple4 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587, kk_context());
  _self->_y_x10215 = _y_x10215;
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587(kk_function_t _fself, kk_box_t _b_x608, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs__mlift_show_10309_fun1587__t*, _fself, _ctx);
  kk_string_t _y_x10215 = _self->_y_x10215; /* string */
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (5720) -> 5721 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5719) -> 5721 string */
  kk_std_core_types__tuple4 x = _self->x; /* (5717, 5718, 5719, 5720) */
  kk_drop_match(_self, {kk_string_dup(_y_x10215, _ctx);kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple4_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10216_610 = kk_string_unbox(_b_x608); /*string*/;
  kk_string_t _x_x1588 = kk_std_core_tuple_tuple4_fs__mlift_show_10308(_y_x10215, _implicit_fs_field4_fs_show, _implicit_fs_thd_fs_show, x, _y_x10216_610, _ctx); /*string*/
  return kk_string_box(_x_x1588);
}

kk_string_t kk_std_core_tuple_tuple4_fs__mlift_show_10309(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple4 x, kk_string_t _y_x10215, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (?field4/show : (d) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, x : (a, b, c, d), string) -> e string */ 
  kk_string_t x_0_10636;
  kk_box_t _x_x1584;
  {
    struct kk_std_core_types_Tuple4* _con_x1585 = kk_std_core_types__as_Tuple4(x, _ctx);
    kk_box_t _x_0 = _con_x1585->snd;
    kk_box_dup(_x_0, _ctx);
    _x_x1584 = _x_0; /*5718*/
  }
  x_0_10636 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1584, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10636, _ctx);
    kk_box_t _x_x1586 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs__new_mlift_show_10309_fun1587(_y_x10215, _implicit_fs_field4_fs_show, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1586);
  }
  {
    return kk_std_core_tuple_tuple4_fs__mlift_show_10308(_y_x10215, _implicit_fs_field4_fs_show, _implicit_fs_thd_fs_show, x, x_0_10636, _ctx);
  }
}
 
// Show a quadruple


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_show_fun1592__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple4 x;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1592(kk_function_t _fself, kk_box_t _b_x612, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_show_fun1592(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple4 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1592__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_show_fun1592__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_show_fun1592, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1592(kk_function_t _fself, kk_box_t _b_x612, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1592__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_show_fun1592__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (5720) -> 5721 string */
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (5718) -> 5721 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5719) -> 5721 string */
  kk_std_core_types__tuple4 x = _self->x; /* (5717, 5718, 5719, 5720) */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple4_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10215_623 = kk_string_unbox(_b_x612); /*string*/;
  kk_string_t _x_x1593 = kk_std_core_tuple_tuple4_fs__mlift_show_10309(_implicit_fs_field4_fs_show, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _y_x10215_623, _ctx); /*string*/
  return kk_string_box(_x_x1593);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_show_fun1597__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple4 x;
  kk_string_t x_0_10638;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1597(kk_function_t _fself, kk_box_t _b_x614, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_show_fun1597(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple4 x, kk_string_t x_0_10638, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1597__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_show_fun1597__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_show_fun1597, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  _self->x_0_10638 = x_0_10638;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1597(kk_function_t _fself, kk_box_t _b_x614, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1597__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_show_fun1597__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (5720) -> 5721 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (5719) -> 5721 string */
  kk_std_core_types__tuple4 x = _self->x; /* (5717, 5718, 5719, 5720) */
  kk_string_t x_0_10638 = _self->x_0_10638; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple4_dup(x, _ctx);kk_string_dup(x_0_10638, _ctx);}, {}, _ctx)
  kk_string_t _y_x10216_624 = kk_string_unbox(_b_x614); /*string*/;
  kk_string_t _x_x1598 = kk_std_core_tuple_tuple4_fs__mlift_show_10308(x_0_10638, _implicit_fs_field4_fs_show, _implicit_fs_thd_fs_show, x, _y_x10216_624, _ctx); /*string*/
  return kk_string_box(_x_x1598);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_show_fun1602__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_std_core_types__tuple4 x;
  kk_string_t x_0_10638;
  kk_string_t x_1_10641;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1602(kk_function_t _fself, kk_box_t _b_x616, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_show_fun1602(kk_function_t _implicit_fs_field4_fs_show, kk_std_core_types__tuple4 x, kk_string_t x_0_10638, kk_string_t x_1_10641, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1602__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_show_fun1602__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_show_fun1602, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->x = x;
  _self->x_0_10638 = x_0_10638;
  _self->x_1_10641 = x_1_10641;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1602(kk_function_t _fself, kk_box_t _b_x616, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1602__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_show_fun1602__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (5720) -> 5721 string */
  kk_std_core_types__tuple4 x = _self->x; /* (5717, 5718, 5719, 5720) */
  kk_string_t x_0_10638 = _self->x_0_10638; /* string */
  kk_string_t x_1_10641 = _self->x_1_10641; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_std_core_types__tuple4_dup(x, _ctx);kk_string_dup(x_0_10638, _ctx);kk_string_dup(x_1_10641, _ctx);}, {}, _ctx)
  kk_string_t _y_x10217_625 = kk_string_unbox(_b_x616); /*string*/;
  kk_string_t _x_x1603 = kk_std_core_tuple_tuple4_fs__mlift_show_10307(x_0_10638, x_1_10641, _implicit_fs_field4_fs_show, x, _y_x10217_625, _ctx); /*string*/
  return kk_string_box(_x_x1603);
}


// lift anonymous function
struct kk_std_core_tuple_tuple4_fs_show_fun1607__t {
  struct kk_function_s _base;
  kk_string_t x_0_10638;
  kk_string_t x_1_10641;
  kk_string_t x_2_10644;
};
static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1607(kk_function_t _fself, kk_box_t _b_x618, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple4_fs_new_show_fun1607(kk_string_t x_0_10638, kk_string_t x_1_10641, kk_string_t x_2_10644, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1607__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple4_fs_show_fun1607__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple4_fs_show_fun1607, kk_context());
  _self->x_0_10638 = x_0_10638;
  _self->x_1_10641 = x_1_10641;
  _self->x_2_10644 = x_2_10644;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple4_fs_show_fun1607(kk_function_t _fself, kk_box_t _b_x618, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple4_fs_show_fun1607__t* _self = kk_function_as(struct kk_std_core_tuple_tuple4_fs_show_fun1607__t*, _fself, _ctx);
  kk_string_t x_0_10638 = _self->x_0_10638; /* string */
  kk_string_t x_1_10641 = _self->x_1_10641; /* string */
  kk_string_t x_2_10644 = _self->x_2_10644; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10638, _ctx);kk_string_dup(x_1_10641, _ctx);kk_string_dup(x_2_10644, _ctx);}, {}, _ctx)
  kk_string_t _y_x10218_626 = kk_string_unbox(_b_x618); /*string*/;
  kk_string_t _x_x1608 = kk_std_core_tuple_tuple4_fs__mlift_show_10306(x_0_10638, x_1_10641, x_2_10644, _y_x10218_626, _ctx); /*string*/
  return kk_string_box(_x_x1608);
}

kk_string_t kk_std_core_tuple_tuple4_fs_show(kk_std_core_types__tuple4 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_function_t _implicit_fs_field4_fs_show, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (x : (a, b, c, d), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, ?field4/show : (d) -> e string) -> e string */ 
  kk_string_t x_0_10638;
  kk_box_t _x_x1589;
  {
    struct kk_std_core_types_Tuple4* _con_x1590 = kk_std_core_types__as_Tuple4(x, _ctx);
    kk_box_t _x = _con_x1590->fst;
    kk_box_dup(_x, _ctx);
    _x_x1589 = _x; /*5717*/
  }
  x_0_10638 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x1589, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10638, _ctx);
    kk_box_t _x_x1591 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_show_fun1592(_implicit_fs_field4_fs_show, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1591);
  }
  {
    kk_string_t x_1_10641;
    kk_box_t _x_x1594;
    {
      struct kk_std_core_types_Tuple4* _con_x1595 = kk_std_core_types__as_Tuple4(x, _ctx);
      kk_box_t _x_0 = _con_x1595->snd;
      kk_box_dup(_x_0, _ctx);
      _x_x1594 = _x_0; /*5718*/
    }
    x_1_10641 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1594, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10641, _ctx);
      kk_box_t _x_x1596 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_show_fun1597(_implicit_fs_field4_fs_show, _implicit_fs_thd_fs_show, x, x_0_10638, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1596);
    }
    {
      kk_string_t x_2_10644;
      kk_box_t _x_x1599;
      {
        struct kk_std_core_types_Tuple4* _con_x1600 = kk_std_core_types__as_Tuple4(x, _ctx);
        kk_box_t _x_1 = _con_x1600->thd;
        kk_box_dup(_x_1, _ctx);
        _x_x1599 = _x_1; /*5719*/
      }
      x_2_10644 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1599, _ctx), _ctx); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10644, _ctx);
        kk_box_t _x_x1601 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_show_fun1602(_implicit_fs_field4_fs_show, x, x_0_10638, x_1_10641, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x1601);
      }
      {
        kk_string_t x_3_10647;
        kk_box_t _x_x1604;
        {
          struct kk_std_core_types_Tuple4* _con_x1605 = kk_std_core_types__as_Tuple4(x, _ctx);
          kk_box_t _pat_0_2_0 = _con_x1605->fst;
          kk_box_t _pat_1_2 = _con_x1605->snd;
          kk_box_t _pat_2_2 = _con_x1605->thd;
          kk_box_t _x_2 = _con_x1605->field4;
          if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
            kk_box_drop(_pat_2_2, _ctx);
            kk_box_drop(_pat_1_2, _ctx);
            kk_box_drop(_pat_0_2_0, _ctx);
            kk_datatype_ptr_free(x, _ctx);
          }
          else {
            kk_box_dup(_x_2, _ctx);
            kk_datatype_ptr_decref(x, _ctx);
          }
          _x_x1604 = _x_2; /*5720*/
        }
        x_3_10647 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_show, (_implicit_fs_field4_fs_show, _x_x1604, _ctx), _ctx); /*string*/
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_3_10647, _ctx);
          kk_box_t _x_x1606 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple4_fs_new_show_fun1607(x_0_10638, x_1_10641, x_2_10644, _ctx), _ctx); /*2419*/
          return kk_string_unbox(_x_x1606);
        }
        {
          kk_string_t _x_x1609;
          kk_define_string_literal(static, _s_x1610, 1, "(", _ctx)
          _x_x1609 = kk_string_dup(_s_x1610, _ctx); /*string*/
          kk_string_t _x_x1611;
          kk_string_t _x_x1612;
          kk_string_t _x_x1613;
          kk_define_string_literal(static, _s_x1614, 1, ",", _ctx)
          _x_x1613 = kk_string_dup(_s_x1614, _ctx); /*string*/
          kk_string_t _x_x1615;
          kk_string_t _x_x1616;
          kk_string_t _x_x1617;
          kk_define_string_literal(static, _s_x1618, 1, ",", _ctx)
          _x_x1617 = kk_string_dup(_s_x1618, _ctx); /*string*/
          kk_string_t _x_x1619;
          kk_string_t _x_x1620;
          kk_string_t _x_x1621;
          kk_define_string_literal(static, _s_x1622, 1, ",", _ctx)
          _x_x1621 = kk_string_dup(_s_x1622, _ctx); /*string*/
          kk_string_t _x_x1623;
          kk_string_t _x_x1624;
          kk_define_string_literal(static, _s_x1625, 1, ")", _ctx)
          _x_x1624 = kk_string_dup(_s_x1625, _ctx); /*string*/
          _x_x1623 = kk_std_core_types__lp__plus__plus__rp_(x_3_10647, _x_x1624, _ctx); /*string*/
          _x_x1620 = kk_std_core_types__lp__plus__plus__rp_(_x_x1621, _x_x1623, _ctx); /*string*/
          _x_x1619 = kk_std_core_types__lp__plus__plus__rp_(x_2_10644, _x_x1620, _ctx); /*string*/
          _x_x1616 = kk_std_core_types__lp__plus__plus__rp_(_x_x1617, _x_x1619, _ctx); /*string*/
          _x_x1615 = kk_std_core_types__lp__plus__plus__rp_(x_1_10641, _x_x1616, _ctx); /*string*/
          _x_x1612 = kk_std_core_types__lp__plus__plus__rp_(_x_x1613, _x_x1615, _ctx); /*string*/
          _x_x1611 = kk_std_core_types__lp__plus__plus__rp_(x_0_10638, _x_x1612, _ctx); /*string*/
          return kk_std_core_types__lp__plus__plus__rp_(_x_x1609, _x_x1611, _ctx);
        }
      }
    }
  }
}
 
// monadic lift

kk_string_t kk_std_core_tuple_tuple5_fs__mlift_show_10310(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_string_t _y_x10221, kk_string_t _y_x10222, kk_string_t _y_x10223, kk_context_t* _ctx) { /* forall<e> (string, string, string, string, string) -> e string */ 
  kk_string_t _x_x1626;
  kk_define_string_literal(static, _s_x1627, 1, "(", _ctx)
  _x_x1626 = kk_string_dup(_s_x1627, _ctx); /*string*/
  kk_string_t _x_x1628;
  kk_string_t _x_x1629;
  kk_string_t _x_x1630;
  kk_define_string_literal(static, _s_x1631, 1, ",", _ctx)
  _x_x1630 = kk_string_dup(_s_x1631, _ctx); /*string*/
  kk_string_t _x_x1632;
  kk_string_t _x_x1633;
  kk_string_t _x_x1634;
  kk_define_string_literal(static, _s_x1635, 1, ",", _ctx)
  _x_x1634 = kk_string_dup(_s_x1635, _ctx); /*string*/
  kk_string_t _x_x1636;
  kk_string_t _x_x1637;
  kk_string_t _x_x1638;
  kk_define_string_literal(static, _s_x1639, 1, ",", _ctx)
  _x_x1638 = kk_string_dup(_s_x1639, _ctx); /*string*/
  kk_string_t _x_x1640;
  kk_string_t _x_x1641;
  kk_string_t _x_x1642;
  kk_define_string_literal(static, _s_x1643, 1, ",", _ctx)
  _x_x1642 = kk_string_dup(_s_x1643, _ctx); /*string*/
  kk_string_t _x_x1644;
  kk_string_t _x_x1645;
  kk_define_string_literal(static, _s_x1646, 1, ")", _ctx)
  _x_x1645 = kk_string_dup(_s_x1646, _ctx); /*string*/
  _x_x1644 = kk_std_core_types__lp__plus__plus__rp_(_y_x10223, _x_x1645, _ctx); /*string*/
  _x_x1641 = kk_std_core_types__lp__plus__plus__rp_(_x_x1642, _x_x1644, _ctx); /*string*/
  _x_x1640 = kk_std_core_types__lp__plus__plus__rp_(_y_x10222, _x_x1641, _ctx); /*string*/
  _x_x1637 = kk_std_core_types__lp__plus__plus__rp_(_x_x1638, _x_x1640, _ctx); /*string*/
  _x_x1636 = kk_std_core_types__lp__plus__plus__rp_(_y_x10221, _x_x1637, _ctx); /*string*/
  _x_x1633 = kk_std_core_types__lp__plus__plus__rp_(_x_x1634, _x_x1636, _ctx); /*string*/
  _x_x1632 = kk_std_core_types__lp__plus__plus__rp_(_y_x10220, _x_x1633, _ctx); /*string*/
  _x_x1629 = kk_std_core_types__lp__plus__plus__rp_(_x_x1630, _x_x1632, _ctx); /*string*/
  _x_x1628 = kk_std_core_types__lp__plus__plus__rp_(_y_x10219, _x_x1629, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x1626, _x_x1628, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650__t {
  struct kk_function_s _base;
  kk_string_t _y_x10219;
  kk_string_t _y_x10220;
  kk_string_t _y_x10221;
  kk_string_t _y_x10222;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_show_10311_fun1650(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_string_t _y_x10221, kk_string_t _y_x10222, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650, kk_context());
  _self->_y_x10219 = _y_x10219;
  _self->_y_x10220 = _y_x10220;
  _self->_y_x10221 = _y_x10221;
  _self->_y_x10222 = _y_x10222;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10311_fun1650__t*, _fself, _ctx);
  kk_string_t _y_x10219 = _self->_y_x10219; /* string */
  kk_string_t _y_x10220 = _self->_y_x10220; /* string */
  kk_string_t _y_x10221 = _self->_y_x10221; /* string */
  kk_string_t _y_x10222 = _self->_y_x10222; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10219, _ctx);kk_string_dup(_y_x10220, _ctx);kk_string_dup(_y_x10221, _ctx);kk_string_dup(_y_x10222, _ctx);}, {}, _ctx)
  kk_string_t _y_x10223_630 = kk_string_unbox(_b_x628); /*string*/;
  kk_string_t _x_x1651 = kk_std_core_tuple_tuple5_fs__mlift_show_10310(_y_x10219, _y_x10220, _y_x10221, _y_x10222, _y_x10223_630, _ctx); /*string*/
  return kk_string_box(_x_x1651);
}

kk_string_t kk_std_core_tuple_tuple5_fs__mlift_show_10311(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_string_t _y_x10221, kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_string_t _y_x10222, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (string, string, string, ?field5/show : (a1) -> e string, x : (a, b, c, d, a1), string) -> e string */ 
  kk_string_t x_0_10650;
  kk_box_t _x_x1647;
  {
    struct kk_std_core_types_Tuple5* _con_x1648 = kk_std_core_types__as_Tuple5(x, _ctx);
    kk_box_t _pat_0_3 = _con_x1648->fst;
    kk_box_t _pat_1_3 = _con_x1648->snd;
    kk_box_t _pat_2_3 = _con_x1648->thd;
    kk_box_t _pat_3_3 = _con_x1648->field4;
    kk_box_t _x_3 = _con_x1648->field5;
    if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
      kk_box_drop(_pat_3_3, _ctx);
      kk_box_drop(_pat_2_3, _ctx);
      kk_box_drop(_pat_1_3, _ctx);
      kk_box_drop(_pat_0_3, _ctx);
      kk_datatype_ptr_free(x, _ctx);
    }
    else {
      kk_box_dup(_x_3, _ctx);
      kk_datatype_ptr_decref(x, _ctx);
    }
    _x_x1647 = _x_3; /*6212*/
  }
  x_0_10650 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_show, (_implicit_fs_field5_fs_show, _x_x1647, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10650, _ctx);
    kk_box_t _x_x1649 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_show_10311_fun1650(_y_x10219, _y_x10220, _y_x10221, _y_x10222, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1649);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_show_10310(_y_x10219, _y_x10220, _y_x10221, _y_x10222, x_0_10650, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655__t {
  struct kk_function_s _base;
  kk_string_t _y_x10219;
  kk_string_t _y_x10220;
  kk_string_t _y_x10221;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_std_core_types__tuple5 x;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655(kk_function_t _fself, kk_box_t _b_x632, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_show_10312_fun1655(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_string_t _y_x10221, kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655, kk_context());
  _self->_y_x10219 = _y_x10219;
  _self->_y_x10220 = _y_x10220;
  _self->_y_x10221 = _y_x10221;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655(kk_function_t _fself, kk_box_t _b_x632, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10312_fun1655__t*, _fself, _ctx);
  kk_string_t _y_x10219 = _self->_y_x10219; /* string */
  kk_string_t _y_x10220 = _self->_y_x10220; /* string */
  kk_string_t _y_x10221 = _self->_y_x10221; /* string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_drop_match(_self, {kk_string_dup(_y_x10219, _ctx);kk_string_dup(_y_x10220, _ctx);kk_string_dup(_y_x10221, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10222_634 = kk_string_unbox(_b_x632); /*string*/;
  kk_string_t _x_x1656 = kk_std_core_tuple_tuple5_fs__mlift_show_10311(_y_x10219, _y_x10220, _y_x10221, _implicit_fs_field5_fs_show, x, _y_x10222_634, _ctx); /*string*/
  return kk_string_box(_x_x1656);
}

kk_string_t kk_std_core_tuple_tuple5_fs__mlift_show_10312(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_string_t _y_x10221, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (string, string, ?field4/show : (d) -> e string, ?field5/show : (a1) -> e string, x : (a, b, c, d, a1), string) -> e string */ 
  kk_string_t x_0_10652;
  kk_box_t _x_x1652;
  {
    struct kk_std_core_types_Tuple5* _con_x1653 = kk_std_core_types__as_Tuple5(x, _ctx);
    kk_box_t _x_2 = _con_x1653->field4;
    kk_box_dup(_x_2, _ctx);
    _x_x1652 = _x_2; /*6210*/
  }
  x_0_10652 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_show, (_implicit_fs_field4_fs_show, _x_x1652, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10652, _ctx);
    kk_box_t _x_x1654 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_show_10312_fun1655(_y_x10219, _y_x10220, _y_x10221, _implicit_fs_field5_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1654);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_show_10311(_y_x10219, _y_x10220, _y_x10221, _implicit_fs_field5_fs_show, x, x_0_10652, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660__t {
  struct kk_function_s _base;
  kk_string_t _y_x10219;
  kk_string_t _y_x10220;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_std_core_types__tuple5 x;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660(kk_function_t _fself, kk_box_t _b_x636, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_show_10313_fun1660(kk_string_t _y_x10219, kk_string_t _y_x10220, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660, kk_context());
  _self->_y_x10219 = _y_x10219;
  _self->_y_x10220 = _y_x10220;
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660(kk_function_t _fself, kk_box_t _b_x636, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10313_fun1660__t*, _fself, _ctx);
  kk_string_t _y_x10219 = _self->_y_x10219; /* string */
  kk_string_t _y_x10220 = _self->_y_x10220; /* string */
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (6210) -> 6211 string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_drop_match(_self, {kk_string_dup(_y_x10219, _ctx);kk_string_dup(_y_x10220, _ctx);kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10221_638 = kk_string_unbox(_b_x636); /*string*/;
  kk_string_t _x_x1661 = kk_std_core_tuple_tuple5_fs__mlift_show_10312(_y_x10219, _y_x10220, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, x, _y_x10221_638, _ctx); /*string*/
  return kk_string_box(_x_x1661);
}

kk_string_t kk_std_core_tuple_tuple5_fs__mlift_show_10313(kk_string_t _y_x10219, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple5 x, kk_string_t _y_x10220, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (string, ?field4/show : (d) -> e string, ?field5/show : (a1) -> e string, ?thd/show : (c) -> e string, x : (a, b, c, d, a1), string) -> e string */ 
  kk_string_t x_0_10654;
  kk_box_t _x_x1657;
  {
    struct kk_std_core_types_Tuple5* _con_x1658 = kk_std_core_types__as_Tuple5(x, _ctx);
    kk_box_t _x_1 = _con_x1658->thd;
    kk_box_dup(_x_1, _ctx);
    _x_x1657 = _x_1; /*6209*/
  }
  x_0_10654 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1657, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10654, _ctx);
    kk_box_t _x_x1659 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_show_10313_fun1660(_y_x10219, _y_x10220, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1659);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_show_10312(_y_x10219, _y_x10220, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, x, x_0_10654, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665__t {
  struct kk_function_s _base;
  kk_string_t _y_x10219;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple5 x;
};
static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs__new_mlift_show_10314_fun1665(kk_string_t _y_x10219, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple5 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665, kk_context());
  _self->_y_x10219 = _y_x10219;
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs__mlift_show_10314_fun1665__t*, _fself, _ctx);
  kk_string_t _y_x10219 = _self->_y_x10219; /* string */
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (6210) -> 6211 string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (6209) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_drop_match(_self, {kk_string_dup(_y_x10219, _ctx);kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10220_642 = kk_string_unbox(_b_x640); /*string*/;
  kk_string_t _x_x1666 = kk_std_core_tuple_tuple5_fs__mlift_show_10313(_y_x10219, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_thd_fs_show, x, _y_x10220_642, _ctx); /*string*/
  return kk_string_box(_x_x1666);
}

kk_string_t kk_std_core_tuple_tuple5_fs__mlift_show_10314(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple5 x, kk_string_t _y_x10219, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (?field4/show : (d) -> e string, ?field5/show : (a1) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, x : (a, b, c, d, a1), string) -> e string */ 
  kk_string_t x_0_10656;
  kk_box_t _x_x1662;
  {
    struct kk_std_core_types_Tuple5* _con_x1663 = kk_std_core_types__as_Tuple5(x, _ctx);
    kk_box_t _x_0 = _con_x1663->snd;
    kk_box_dup(_x_0, _ctx);
    _x_x1662 = _x_0; /*6208*/
  }
  x_0_10656 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1662, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10656, _ctx);
    kk_box_t _x_x1664 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs__new_mlift_show_10314_fun1665(_y_x10219, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1664);
  }
  {
    return kk_std_core_tuple_tuple5_fs__mlift_show_10313(_y_x10219, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_thd_fs_show, x, x_0_10656, _ctx);
  }
}
 
// Show a quintuple


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_show_fun1670__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple5 x;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1670(kk_function_t _fself, kk_box_t _b_x644, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_show_fun1670(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple5 x, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1670__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_show_fun1670__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_show_fun1670, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1670(kk_function_t _fself, kk_box_t _b_x644, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1670__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_show_fun1670__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (6210) -> 6211 string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (6208) -> 6211 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (6209) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);}, {}, _ctx)
  kk_string_t _y_x10219_658 = kk_string_unbox(_b_x644); /*string*/;
  kk_string_t _x_x1671 = kk_std_core_tuple_tuple5_fs__mlift_show_10314(_implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _y_x10219_658, _ctx); /*string*/
  return kk_string_box(_x_x1671);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_show_fun1675__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_function_t _implicit_fs_thd_fs_show;
  kk_std_core_types__tuple5 x;
  kk_string_t x_0_10658;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1675(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_show_fun1675(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_std_core_types__tuple5 x, kk_string_t x_0_10658, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1675__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_show_fun1675__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_show_fun1675, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->_implicit_fs_thd_fs_show = _implicit_fs_thd_fs_show;
  _self->x = x;
  _self->x_0_10658 = x_0_10658;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1675(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1675__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_show_fun1675__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (6210) -> 6211 string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_function_t _implicit_fs_thd_fs_show = _self->_implicit_fs_thd_fs_show; /* (6209) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_string_t x_0_10658 = _self->x_0_10658; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_function_dup(_implicit_fs_thd_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);kk_string_dup(x_0_10658, _ctx);}, {}, _ctx)
  kk_string_t _y_x10220_659 = kk_string_unbox(_b_x646); /*string*/;
  kk_string_t _x_x1676 = kk_std_core_tuple_tuple5_fs__mlift_show_10313(x_0_10658, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_thd_fs_show, x, _y_x10220_659, _ctx); /*string*/
  return kk_string_box(_x_x1676);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_show_fun1680__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field4_fs_show;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_std_core_types__tuple5 x;
  kk_string_t x_0_10658;
  kk_string_t x_1_10661;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1680(kk_function_t _fself, kk_box_t _b_x648, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_show_fun1680(kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_string_t x_0_10658, kk_string_t x_1_10661, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1680__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_show_fun1680__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_show_fun1680, kk_context());
  _self->_implicit_fs_field4_fs_show = _implicit_fs_field4_fs_show;
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->x = x;
  _self->x_0_10658 = x_0_10658;
  _self->x_1_10661 = x_1_10661;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1680(kk_function_t _fself, kk_box_t _b_x648, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1680__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_show_fun1680__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field4_fs_show = _self->_implicit_fs_field4_fs_show; /* (6210) -> 6211 string */
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_string_t x_0_10658 = _self->x_0_10658; /* string */
  kk_string_t x_1_10661 = _self->x_1_10661; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field4_fs_show, _ctx);kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);kk_string_dup(x_0_10658, _ctx);kk_string_dup(x_1_10661, _ctx);}, {}, _ctx)
  kk_string_t _y_x10221_660 = kk_string_unbox(_b_x648); /*string*/;
  kk_string_t _x_x1681 = kk_std_core_tuple_tuple5_fs__mlift_show_10312(x_0_10658, x_1_10661, _implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, x, _y_x10221_660, _ctx); /*string*/
  return kk_string_box(_x_x1681);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_show_fun1685__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_field5_fs_show;
  kk_std_core_types__tuple5 x;
  kk_string_t x_0_10658;
  kk_string_t x_1_10661;
  kk_string_t x_2_10664;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1685(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_show_fun1685(kk_function_t _implicit_fs_field5_fs_show, kk_std_core_types__tuple5 x, kk_string_t x_0_10658, kk_string_t x_1_10661, kk_string_t x_2_10664, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1685__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_show_fun1685__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_show_fun1685, kk_context());
  _self->_implicit_fs_field5_fs_show = _implicit_fs_field5_fs_show;
  _self->x = x;
  _self->x_0_10658 = x_0_10658;
  _self->x_1_10661 = x_1_10661;
  _self->x_2_10664 = x_2_10664;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1685(kk_function_t _fself, kk_box_t _b_x650, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1685__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_show_fun1685__t*, _fself, _ctx);
  kk_function_t _implicit_fs_field5_fs_show = _self->_implicit_fs_field5_fs_show; /* (6212) -> 6211 string */
  kk_std_core_types__tuple5 x = _self->x; /* (6207, 6208, 6209, 6210, 6212) */
  kk_string_t x_0_10658 = _self->x_0_10658; /* string */
  kk_string_t x_1_10661 = _self->x_1_10661; /* string */
  kk_string_t x_2_10664 = _self->x_2_10664; /* string */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_field5_fs_show, _ctx);kk_std_core_types__tuple5_dup(x, _ctx);kk_string_dup(x_0_10658, _ctx);kk_string_dup(x_1_10661, _ctx);kk_string_dup(x_2_10664, _ctx);}, {}, _ctx)
  kk_string_t _y_x10222_661 = kk_string_unbox(_b_x650); /*string*/;
  kk_string_t _x_x1686 = kk_std_core_tuple_tuple5_fs__mlift_show_10311(x_0_10658, x_1_10661, x_2_10664, _implicit_fs_field5_fs_show, x, _y_x10222_661, _ctx); /*string*/
  return kk_string_box(_x_x1686);
}


// lift anonymous function
struct kk_std_core_tuple_tuple5_fs_show_fun1690__t {
  struct kk_function_s _base;
  kk_string_t x_0_10658;
  kk_string_t x_1_10661;
  kk_string_t x_2_10664;
  kk_string_t x_3_10667;
};
static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1690(kk_function_t _fself, kk_box_t _b_x652, kk_context_t* _ctx);
static kk_function_t kk_std_core_tuple_tuple5_fs_new_show_fun1690(kk_string_t x_0_10658, kk_string_t x_1_10661, kk_string_t x_2_10664, kk_string_t x_3_10667, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1690__t* _self = kk_function_alloc_as(struct kk_std_core_tuple_tuple5_fs_show_fun1690__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_tuple_tuple5_fs_show_fun1690, kk_context());
  _self->x_0_10658 = x_0_10658;
  _self->x_1_10661 = x_1_10661;
  _self->x_2_10664 = x_2_10664;
  _self->x_3_10667 = x_3_10667;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_tuple_tuple5_fs_show_fun1690(kk_function_t _fself, kk_box_t _b_x652, kk_context_t* _ctx) {
  struct kk_std_core_tuple_tuple5_fs_show_fun1690__t* _self = kk_function_as(struct kk_std_core_tuple_tuple5_fs_show_fun1690__t*, _fself, _ctx);
  kk_string_t x_0_10658 = _self->x_0_10658; /* string */
  kk_string_t x_1_10661 = _self->x_1_10661; /* string */
  kk_string_t x_2_10664 = _self->x_2_10664; /* string */
  kk_string_t x_3_10667 = _self->x_3_10667; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10658, _ctx);kk_string_dup(x_1_10661, _ctx);kk_string_dup(x_2_10664, _ctx);kk_string_dup(x_3_10667, _ctx);}, {}, _ctx)
  kk_string_t _y_x10223_662 = kk_string_unbox(_b_x652); /*string*/;
  kk_string_t _x_x1691 = kk_std_core_tuple_tuple5_fs__mlift_show_10310(x_0_10658, x_1_10661, x_2_10664, x_3_10667, _y_x10223_662, _ctx); /*string*/
  return kk_string_box(_x_x1691);
}

kk_string_t kk_std_core_tuple_tuple5_fs_show(kk_std_core_types__tuple5 x, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_function_t _implicit_fs_thd_fs_show, kk_function_t _implicit_fs_field4_fs_show, kk_function_t _implicit_fs_field5_fs_show, kk_context_t* _ctx) { /* forall<a,b,c,d,e,a1> (x : (a, b, c, d, a1), ?fst/show : (a) -> e string, ?snd/show : (b) -> e string, ?thd/show : (c) -> e string, ?field4/show : (d) -> e string, ?field5/show : (a1) -> e string) -> e string */ 
  kk_string_t x_0_10658;
  kk_box_t _x_x1667;
  {
    struct kk_std_core_types_Tuple5* _con_x1668 = kk_std_core_types__as_Tuple5(x, _ctx);
    kk_box_t _x = _con_x1668->fst;
    kk_box_dup(_x, _ctx);
    _x_x1667 = _x; /*6207*/
  }
  x_0_10658 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, _x_x1667, _ctx), _ctx); /*string*/
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10658, _ctx);
    kk_box_t _x_x1669 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_show_fun1670(_implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_snd_fs_show, _implicit_fs_thd_fs_show, x, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x1669);
  }
  {
    kk_string_t x_1_10661;
    kk_box_t _x_x1672;
    {
      struct kk_std_core_types_Tuple5* _con_x1673 = kk_std_core_types__as_Tuple5(x, _ctx);
      kk_box_t _x_0 = _con_x1673->snd;
      kk_box_dup(_x_0, _ctx);
      _x_x1672 = _x_0; /*6208*/
    }
    x_1_10661 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, _x_x1672, _ctx), _ctx); /*string*/
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_1_10661, _ctx);
      kk_box_t _x_x1674 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_show_fun1675(_implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, _implicit_fs_thd_fs_show, x, x_0_10658, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x1674);
    }
    {
      kk_string_t x_2_10664;
      kk_box_t _x_x1677;
      {
        struct kk_std_core_types_Tuple5* _con_x1678 = kk_std_core_types__as_Tuple5(x, _ctx);
        kk_box_t _x_1 = _con_x1678->thd;
        kk_box_dup(_x_1, _ctx);
        _x_x1677 = _x_1; /*6209*/
      }
      x_2_10664 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_thd_fs_show, (_implicit_fs_thd_fs_show, _x_x1677, _ctx), _ctx); /*string*/
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_2_10664, _ctx);
        kk_box_t _x_x1679 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_show_fun1680(_implicit_fs_field4_fs_show, _implicit_fs_field5_fs_show, x, x_0_10658, x_1_10661, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x1679);
      }
      {
        kk_string_t x_3_10667;
        kk_box_t _x_x1682;
        {
          struct kk_std_core_types_Tuple5* _con_x1683 = kk_std_core_types__as_Tuple5(x, _ctx);
          kk_box_t _x_2 = _con_x1683->field4;
          kk_box_dup(_x_2, _ctx);
          _x_x1682 = _x_2; /*6210*/
        }
        x_3_10667 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field4_fs_show, (_implicit_fs_field4_fs_show, _x_x1682, _ctx), _ctx); /*string*/
        if (kk_yielding(kk_context())) {
          kk_string_drop(x_3_10667, _ctx);
          kk_box_t _x_x1684 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_show_fun1685(_implicit_fs_field5_fs_show, x, x_0_10658, x_1_10661, x_2_10664, _ctx), _ctx); /*2419*/
          return kk_string_unbox(_x_x1684);
        }
        {
          kk_string_t x_4_10670;
          kk_box_t _x_x1687;
          {
            struct kk_std_core_types_Tuple5* _con_x1688 = kk_std_core_types__as_Tuple5(x, _ctx);
            kk_box_t _pat_0_3_0 = _con_x1688->fst;
            kk_box_t _pat_1_3 = _con_x1688->snd;
            kk_box_t _pat_2_3 = _con_x1688->thd;
            kk_box_t _pat_3_3 = _con_x1688->field4;
            kk_box_t _x_3 = _con_x1688->field5;
            if kk_likely(kk_datatype_ptr_is_unique(x, _ctx)) {
              kk_box_drop(_pat_3_3, _ctx);
              kk_box_drop(_pat_2_3, _ctx);
              kk_box_drop(_pat_1_3, _ctx);
              kk_box_drop(_pat_0_3_0, _ctx);
              kk_datatype_ptr_free(x, _ctx);
            }
            else {
              kk_box_dup(_x_3, _ctx);
              kk_datatype_ptr_decref(x, _ctx);
            }
            _x_x1687 = _x_3; /*6212*/
          }
          x_4_10670 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_field5_fs_show, (_implicit_fs_field5_fs_show, _x_x1687, _ctx), _ctx); /*string*/
          if (kk_yielding(kk_context())) {
            kk_string_drop(x_4_10670, _ctx);
            kk_box_t _x_x1689 = kk_std_core_hnd_yield_extend(kk_std_core_tuple_tuple5_fs_new_show_fun1690(x_0_10658, x_1_10661, x_2_10664, x_3_10667, _ctx), _ctx); /*2419*/
            return kk_string_unbox(_x_x1689);
          }
          {
            kk_string_t _x_x1692;
            kk_define_string_literal(static, _s_x1693, 1, "(", _ctx)
            _x_x1692 = kk_string_dup(_s_x1693, _ctx); /*string*/
            kk_string_t _x_x1694;
            kk_string_t _x_x1695;
            kk_string_t _x_x1696;
            kk_define_string_literal(static, _s_x1697, 1, ",", _ctx)
            _x_x1696 = kk_string_dup(_s_x1697, _ctx); /*string*/
            kk_string_t _x_x1698;
            kk_string_t _x_x1699;
            kk_string_t _x_x1700;
            kk_define_string_literal(static, _s_x1701, 1, ",", _ctx)
            _x_x1700 = kk_string_dup(_s_x1701, _ctx); /*string*/
            kk_string_t _x_x1702;
            kk_string_t _x_x1703;
            kk_string_t _x_x1704;
            kk_define_string_literal(static, _s_x1705, 1, ",", _ctx)
            _x_x1704 = kk_string_dup(_s_x1705, _ctx); /*string*/
            kk_string_t _x_x1706;
            kk_string_t _x_x1707;
            kk_string_t _x_x1708;
            kk_define_string_literal(static, _s_x1709, 1, ",", _ctx)
            _x_x1708 = kk_string_dup(_s_x1709, _ctx); /*string*/
            kk_string_t _x_x1710;
            kk_string_t _x_x1711;
            kk_define_string_literal(static, _s_x1712, 1, ")", _ctx)
            _x_x1711 = kk_string_dup(_s_x1712, _ctx); /*string*/
            _x_x1710 = kk_std_core_types__lp__plus__plus__rp_(x_4_10670, _x_x1711, _ctx); /*string*/
            _x_x1707 = kk_std_core_types__lp__plus__plus__rp_(_x_x1708, _x_x1710, _ctx); /*string*/
            _x_x1706 = kk_std_core_types__lp__plus__plus__rp_(x_3_10667, _x_x1707, _ctx); /*string*/
            _x_x1703 = kk_std_core_types__lp__plus__plus__rp_(_x_x1704, _x_x1706, _ctx); /*string*/
            _x_x1702 = kk_std_core_types__lp__plus__plus__rp_(x_2_10664, _x_x1703, _ctx); /*string*/
            _x_x1699 = kk_std_core_types__lp__plus__plus__rp_(_x_x1700, _x_x1702, _ctx); /*string*/
            _x_x1698 = kk_std_core_types__lp__plus__plus__rp_(x_1_10661, _x_x1699, _ctx); /*string*/
            _x_x1695 = kk_std_core_types__lp__plus__plus__rp_(_x_x1696, _x_x1698, _ctx); /*string*/
            _x_x1694 = kk_std_core_types__lp__plus__plus__rp_(x_0_10658, _x_x1695, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x1692, _x_x1694, _ctx);
          }
        }
      }
    }
  }
}

// initialization
void kk_std_core_tuple__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_tuple__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
