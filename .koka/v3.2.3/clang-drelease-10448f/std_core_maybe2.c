// Koka generated module: std/core/maybe2, koka version: 3.2.3, platform: 64-bit
#include "std_core_maybe2.h"
 
// Get the value of the `Just` constructor or raise an exception

kk_std_core_types__tuple2 kk_std_core_maybe2_unjust(kk_std_core_types__maybe2 m, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* forall<a,b> (m : maybe2<a,b>, ?kk-file-line : string) -> exn (a, b) */ 
  if (kk_std_core_types__is_Just2(m, _ctx)) {
    kk_box_t x = m._cons.Just2.fst;
    kk_box_t y = m._cons.Just2.snd;
    kk_string_drop(_implicit_fs_kk_file_line, _ctx);
    return kk_std_core_types__new_Tuple2(x, y, _ctx);
  }
  {
    kk_string_t message_10000;
    kk_string_t _x_x55;
    kk_define_string_literal(static, _s_x56, 23, "unexpected Nothing2 in ", _ctx)
    _x_x55 = kk_string_dup(_s_x56, _ctx); /*string*/
    message_10000 = kk_std_core_types__lp__plus__plus__rp_(_x_x55, _implicit_fs_kk_file_line, _ctx); /*string*/
    kk_std_core_hnd__ev ev_10130 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x57;
    {
      struct kk_std_core_hnd_Ev* _con_x58 = kk_std_core_hnd__as_Ev(ev_10130, _ctx);
      kk_box_t _box_x0 = _con_x58->hnd;
      int32_t m_0 = _con_x58->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x0, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x50;
      kk_std_core_hnd__clause1 _brw_x52 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x50 = _brw_x52; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x4 = _match_x50.clause;
        kk_box_t _x_x59;
        kk_std_core_exn__exception _x_x60;
        kk_std_core_exn__exception_info _x_x61;
        kk_std_core_types__optional _match_x51 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x51, _ctx)) {
          kk_box_t _box_x8 = _match_x51._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x8, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x51, _ctx);
          _x_x61 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x51, _ctx);
          _x_x61 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x60 = kk_std_core_exn__new_Exception(message_10000, _x_x61, _ctx); /*exception*/
        _x_x59 = kk_std_core_exn__exception_box(_x_x60, _ctx); /*45*/
        _x_x57 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4, (_fun_unbox_x4, m_0, ev_10130, _x_x59, _ctx), _ctx); /*46*/
      }
    }
    return kk_std_core_types__tuple2_unbox(_x_x57, KK_OWNED, _ctx);
  }
}
 
// Get the value of the `Just` constructor or raise an exception

kk_std_core_types__tuple2 kk_std_core_maybe2_expect(kk_std_core_types__maybe2 m, kk_string_t error_msg, kk_context_t* _ctx) { /* forall<a,b> (m : maybe2<a,b>, error-msg : string) -> exn (a, b) */ 
  if (kk_std_core_types__is_Just2(m, _ctx)) {
    kk_box_t x = m._cons.Just2.fst;
    kk_box_t y = m._cons.Just2.snd;
    kk_string_drop(error_msg, _ctx);
    return kk_std_core_types__new_Tuple2(x, y, _ctx);
  }
  {
    kk_std_core_hnd__ev ev_10133 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x62;
    {
      struct kk_std_core_hnd_Ev* _con_x63 = kk_std_core_hnd__as_Ev(ev_10133, _ctx);
      kk_box_t _box_x9 = _con_x63->hnd;
      int32_t m_0 = _con_x63->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x9, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x47;
      kk_std_core_hnd__clause1 _brw_x49 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x47 = _brw_x49; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x13 = _match_x47.clause;
        kk_box_t _x_x64;
        kk_std_core_exn__exception _x_x65;
        kk_std_core_exn__exception_info _x_x66;
        kk_std_core_types__optional _match_x48 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x48, _ctx)) {
          kk_box_t _box_x17 = _match_x48._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x17, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x48, _ctx);
          _x_x66 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x48, _ctx);
          _x_x66 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x65 = kk_std_core_exn__new_Exception(error_msg, _x_x66, _ctx); /*exception*/
        _x_x64 = kk_std_core_exn__exception_box(_x_x65, _ctx); /*45*/
        _x_x62 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x13, (_fun_unbox_x13, m_0, ev_10133, _x_x64, _ctx), _ctx); /*46*/
      }
    }
    return kk_std_core_types__tuple2_unbox(_x_x62, KK_OWNED, _ctx);
  }
}


// lift anonymous function
struct kk_std_core_maybe2_map_fun68__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe2_map_fun68(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2_new_map_fun68(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe2_map_fun68, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe2_map_fun68(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__tuple2 _y_x10110_21 = kk_std_core_types__tuple2_unbox(_b_x19, KK_OWNED, _ctx); /*(427, 428)*/;
  kk_std_core_types__maybe2 _x_x69;
  {
    kk_box_t fx = _y_x10110_21.fst;
    kk_box_t fy = _y_x10110_21.snd;
    _x_x69 = kk_std_core_types__new_Just2(fx, fy, _ctx); /*maybe2<93,94>*/
  }
  return kk_std_core_types__maybe2_box(_x_x69, _ctx);
}

kk_std_core_types__maybe2 kk_std_core_maybe2_map(kk_std_core_types__maybe2 m, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,d,e> (m : maybe2<a,b>, f : (a, b) -> e (c, d)) -> e maybe2<c,d> */ 
  if (kk_std_core_types__is_Nothing2(m, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nothing2(_ctx);
  }
  {
    kk_box_t x = m._cons.Just2.fst;
    kk_box_t y = m._cons.Just2.snd;
    kk_std_core_types__tuple2 x_0_10136 = kk_function_call(kk_std_core_types__tuple2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), f, (f, x, y, _ctx), _ctx); /*(427, 428)*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__tuple2_drop(x_0_10136, _ctx);
      kk_box_t _x_x67 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2_new_map_fun68(_ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe2_unbox(_x_x67, KK_OWNED, _ctx);
    }
    {
      kk_box_t fx_0 = x_0_10136.fst;
      kk_box_t fy_0 = x_0_10136.snd;
      return kk_std_core_types__new_Just2(fx_0, fy_0, _ctx);
    }
  }
}
 
// Equality on `:maybe`


// lift anonymous function
struct kk_std_core_maybe2__lp__at_x_fun71__t_eq__eq__rp_ {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_;
  kk_box_t b;
  kk_box_t y;
};
static kk_box_t kk_std_core_maybe2__lp__at_x_fun71_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2__lp__at_new_x_fun71_eq__eq__rp_(kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_box_t b, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__lp__at_x_fun71__t_eq__eq__rp_* _self = kk_function_alloc_as(struct kk_std_core_maybe2__lp__at_x_fun71__t_eq__eq__rp_, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2__lp__at_x_fun71_eq__eq__rp_, kk_context());
  _self->_implicit_fs_snd_fs__lp__eq__eq__rp_ = _implicit_fs_snd_fs__lp__eq__eq__rp_;
  _self->b = b;
  _self->y = y;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_maybe2__lp__at_x_fun71_eq__eq__rp_(kk_function_t _fself, kk_box_t _b_x23, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__lp__at_x_fun71__t_eq__eq__rp_* _self = kk_function_as(struct kk_std_core_maybe2__lp__at_x_fun71__t_eq__eq__rp_*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_ = _self->_implicit_fs_snd_fs__lp__eq__eq__rp_; /* (568, 568) -> 569 bool */
  kk_box_t b = _self->b; /* 568 */
  kk_box_t y = _self->y; /* 568 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);kk_box_dup(b, _ctx);kk_box_dup(y, _ctx);}, {}, _ctx)
  bool _y_x10112_25 = kk_bool_unbox(_b_x23); /*bool*/;
  bool _x_x72;
  if (_y_x10112_25) {
    _x_x72 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y, b, _ctx), _ctx); /*bool*/
  }
  else {
    kk_box_drop(y, _ctx);
    kk_box_drop(b, _ctx);
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    _x_x72 = false; /*bool*/
  }
  return kk_bool_box(_x_x72);
}

bool kk_std_core_maybe2__lp__eq__eq__rp_(kk_std_core_types__maybe2 mb1, kk_std_core_types__maybe2 mb2, kk_function_t _implicit_fs_fst_fs__lp__eq__eq__rp_, kk_function_t _implicit_fs_snd_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,b,e> (mb1 : maybe2<a,b>, mb2 : maybe2<a,b>, ?fst/(==) : (a, a) -> e bool, ?snd/(==) : (b, b) -> e bool) -> e bool */ 
  if (kk_std_core_types__is_Just2(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just2.fst;
    kk_box_t y = mb1._cons.Just2.snd;
    if (kk_std_core_types__is_Just2(mb2, _ctx)) {
      kk_box_t a = mb2._cons.Just2.fst;
      kk_box_t b = mb2._cons.Just2.snd;
      bool x_0_10140 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs__lp__eq__eq__rp_, (_implicit_fs_fst_fs__lp__eq__eq__rp_, x, a, _ctx), _ctx); /*bool*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x70 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2__lp__at_new_x_fun71_eq__eq__rp_(_implicit_fs_snd_fs__lp__eq__eq__rp_, b, y, _ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x70);
      }
      if (x_0_10140) {
        return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs__lp__eq__eq__rp_, (_implicit_fs_snd_fs__lp__eq__eq__rp_, y, b, _ctx), _ctx);
      }
      {
        kk_box_drop(y, _ctx);
        kk_box_drop(b, _ctx);
        kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
        return false;
      }
    }
    {
      kk_box_drop(y, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
      kk_function_drop(_implicit_fs_fst_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(_implicit_fs_snd_fs__lp__eq__eq__rp_, _ctx);
    kk_function_drop(_implicit_fs_fst_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nothing2(mb2, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__maybe2_drop(mb2, _ctx);
      return false;
    }
  }
}
 
// Order on `:maybe` values


// lift anonymous function
struct kk_std_core_maybe2_cmp_fun74__t {
  struct kk_function_s _base;
  kk_box_t b;
  kk_function_t _implicit_fs_snd_fs_cmp;
  kk_box_t y;
};
static kk_box_t kk_std_core_maybe2_cmp_fun74(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2_new_cmp_fun74(kk_box_t b, kk_function_t _implicit_fs_snd_fs_cmp, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_cmp_fun74__t* _self = kk_function_alloc_as(struct kk_std_core_maybe2_cmp_fun74__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2_cmp_fun74, kk_context());
  _self->b = b;
  _self->_implicit_fs_snd_fs_cmp = _implicit_fs_snd_fs_cmp;
  _self->y = y;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_maybe2_cmp_fun74(kk_function_t _fself, kk_box_t _b_x27, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_cmp_fun74__t* _self = kk_function_as(struct kk_std_core_maybe2_cmp_fun74__t*, _fself, _ctx);
  kk_box_t b = _self->b; /* 656 */
  kk_function_t _implicit_fs_snd_fs_cmp = _self->_implicit_fs_snd_fs_cmp; /* (656, 656) -> 657 order */
  kk_box_t y = _self->y; /* 656 */
  kk_drop_match(_self, {kk_box_dup(b, _ctx);kk_function_dup(_implicit_fs_snd_fs_cmp, _ctx);kk_box_dup(y, _ctx);}, {}, _ctx)
  kk_std_core_types__order _y_x10117_29 = kk_std_core_types__order_unbox(_b_x27, KK_OWNED, _ctx); /*order*/;
  kk_std_core_types__order _x_x75;
  if (kk_std_core_types__is_Eq(_y_x10117_29, _ctx)) {
    _x_x75 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y, b, _ctx), _ctx); /*order*/
  }
  else {
    kk_box_drop(y, _ctx);
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    kk_box_drop(b, _ctx);
    _x_x75 = _y_x10117_29; /*order*/
  }
  return kk_std_core_types__order_box(_x_x75, _ctx);
}

kk_std_core_types__order kk_std_core_maybe2_cmp(kk_std_core_types__maybe2 mb1, kk_std_core_types__maybe2 mb2, kk_function_t _implicit_fs_fst_fs_cmp, kk_function_t _implicit_fs_snd_fs_cmp, kk_context_t* _ctx) { /* forall<a,b,e> (mb1 : maybe2<a,b>, mb2 : maybe2<a,b>, ?fst/cmp : (a, a) -> e order, ?snd/cmp : (b, b) -> e order) -> e order */ 
  if (kk_std_core_types__is_Just2(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just2.fst;
    kk_box_t y = mb1._cons.Just2.snd;
    if (kk_std_core_types__is_Just2(mb2, _ctx)) {
      kk_box_t a = mb2._cons.Just2.fst;
      kk_box_t b = mb2._cons.Just2.snd;
      kk_std_core_types__order x_0_10147 = kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_cmp, (_implicit_fs_fst_fs_cmp, x, a, _ctx), _ctx); /*order*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x73 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2_new_cmp_fun74(b, _implicit_fs_snd_fs_cmp, y, _ctx), _ctx); /*2419*/
        return kk_std_core_types__order_unbox(_x_x73, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq(x_0_10147, _ctx)) {
        return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_cmp, (_implicit_fs_snd_fs_cmp, y, b, _ctx), _ctx);
      }
      {
        kk_box_drop(y, _ctx);
        kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
        kk_box_drop(b, _ctx);
        return x_0_10147;
      }
    }
    {
      kk_box_drop(y, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
      kk_function_drop(_implicit_fs_fst_fs_cmp, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
  }
  {
    kk_function_drop(_implicit_fs_snd_fs_cmp, _ctx);
    kk_function_drop(_implicit_fs_fst_fs_cmp, _ctx);
    if (kk_std_core_types__is_Nothing2(mb2, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      kk_std_core_types__maybe2_drop(mb2, _ctx);
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_maybe2__mlift_show_10129_fun85__t {
  struct kk_function_s _base;
  kk_string_t _y_x10122;
};
static kk_string_t kk_std_core_maybe2__mlift_show_10129_fun85(kk_function_t _fself, kk_string_t _y_x10123, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2__new_mlift_show_10129_fun85(kk_string_t _y_x10122, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__mlift_show_10129_fun85__t* _self = kk_function_alloc_as(struct kk_std_core_maybe2__mlift_show_10129_fun85__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2__mlift_show_10129_fun85, kk_context());
  _self->_y_x10122 = _y_x10122;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_string_t kk_std_core_maybe2__mlift_show_10129_fun85(kk_function_t _fself, kk_string_t _y_x10123, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__mlift_show_10129_fun85__t* _self = kk_function_as(struct kk_std_core_maybe2__mlift_show_10129_fun85__t*, _fself, _ctx);
  kk_string_t _y_x10122 = _self->_y_x10122; /* string */
  kk_drop_match(_self, {kk_string_dup(_y_x10122, _ctx);}, {}, _ctx)
  kk_string_t _x_x86;
  kk_define_string_literal(static, _s_x87, 6, "Just2(", _ctx)
  _x_x86 = kk_string_dup(_s_x87, _ctx); /*string*/
  kk_string_t _x_x88;
  kk_string_t _x_x89;
  kk_string_t _x_x90;
  kk_define_string_literal(static, _s_x91, 1, ",", _ctx)
  _x_x90 = kk_string_dup(_s_x91, _ctx); /*string*/
  kk_string_t _x_x92;
  kk_string_t _x_x93;
  kk_define_string_literal(static, _s_x94, 1, ")", _ctx)
  _x_x93 = kk_string_dup(_s_x94, _ctx); /*string*/
  _x_x92 = kk_std_core_types__lp__plus__plus__rp_(_y_x10123, _x_x93, _ctx); /*string*/
  _x_x89 = kk_std_core_types__lp__plus__plus__rp_(_x_x90, _x_x92, _ctx); /*string*/
  _x_x88 = kk_std_core_types__lp__plus__plus__rp_(_y_x10122, _x_x89, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x86, _x_x88, _ctx);
}


// lift anonymous function
struct kk_std_core_maybe2__mlift_show_10129_fun96__t {
  struct kk_function_s _base;
  kk_function_t next_10155;
};
static kk_box_t kk_std_core_maybe2__mlift_show_10129_fun96(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2__new_mlift_show_10129_fun96(kk_function_t next_10155, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__mlift_show_10129_fun96__t* _self = kk_function_alloc_as(struct kk_std_core_maybe2__mlift_show_10129_fun96__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2__mlift_show_10129_fun96, kk_context());
  _self->next_10155 = next_10155;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_maybe2__mlift_show_10129_fun96(kk_function_t _fself, kk_box_t _b_x31, kk_context_t* _ctx) {
  struct kk_std_core_maybe2__mlift_show_10129_fun96__t* _self = kk_function_as(struct kk_std_core_maybe2__mlift_show_10129_fun96__t*, _fself, _ctx);
  kk_function_t next_10155 = _self->next_10155; /* (string) -> 754 string */
  kk_drop_match(_self, {kk_function_dup(next_10155, _ctx);}, {}, _ctx)
  kk_string_t _x_x97;
  kk_string_t _x_x98 = kk_string_unbox(_b_x31); /*string*/
  _x_x97 = kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10155, (next_10155, _x_x98, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x97);
}

kk_string_t kk_std_core_maybe2__mlift_show_10129(kk_function_t _implicit_fs_snd_fs_show, kk_box_t y, kk_string_t _y_x10122, kk_context_t* _ctx) { /* forall<a,e> (?snd/show : (a) -> e string, y : a, string) -> e string */ 
  kk_string_t x_10154 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, y, _ctx), _ctx); /*string*/;
  kk_function_t next_10155 = kk_std_core_maybe2__new_mlift_show_10129_fun85(_y_x10122, _ctx); /*(string) -> 754 string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10154, _ctx);
    kk_box_t _x_x95 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2__new_mlift_show_10129_fun96(next_10155, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x95);
  }
  {
    return kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), next_10155, (next_10155, x_10154, _ctx), _ctx);
  }
}
 
// Show a `:maybe2` type


// lift anonymous function
struct kk_std_core_maybe2_show_fun100__t {
  struct kk_function_s _base;
  kk_function_t _implicit_fs_snd_fs_show;
  kk_box_t y;
};
static kk_box_t kk_std_core_maybe2_show_fun100(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2_new_show_fun100(kk_function_t _implicit_fs_snd_fs_show, kk_box_t y, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_show_fun100__t* _self = kk_function_alloc_as(struct kk_std_core_maybe2_show_fun100__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2_show_fun100, kk_context());
  _self->_implicit_fs_snd_fs_show = _implicit_fs_snd_fs_show;
  _self->y = y;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_maybe2_show_fun100(kk_function_t _fself, kk_box_t _b_x34, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_show_fun100__t* _self = kk_function_as(struct kk_std_core_maybe2_show_fun100__t*, _fself, _ctx);
  kk_function_t _implicit_fs_snd_fs_show = _self->_implicit_fs_snd_fs_show; /* (753) -> 754 string */
  kk_box_t y = _self->y; /* 753 */
  kk_drop_match(_self, {kk_function_dup(_implicit_fs_snd_fs_show, _ctx);kk_box_dup(y, _ctx);}, {}, _ctx)
  kk_string_t _y_x10122_39 = kk_string_unbox(_b_x34); /*string*/;
  kk_string_t _x_x101 = kk_std_core_maybe2__mlift_show_10129(_implicit_fs_snd_fs_show, y, _y_x10122_39, _ctx); /*string*/
  return kk_string_box(_x_x101);
}


// lift anonymous function
struct kk_std_core_maybe2_show_fun103__t {
  struct kk_function_s _base;
  kk_string_t x_0_10158;
};
static kk_box_t kk_std_core_maybe2_show_fun103(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe2_new_show_fun103(kk_string_t x_0_10158, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_show_fun103__t* _self = kk_function_alloc_as(struct kk_std_core_maybe2_show_fun103__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_maybe2_show_fun103, kk_context());
  _self->x_0_10158 = x_0_10158;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_maybe2_show_fun103(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx) {
  struct kk_std_core_maybe2_show_fun103__t* _self = kk_function_as(struct kk_std_core_maybe2_show_fun103__t*, _fself, _ctx);
  kk_string_t x_0_10158 = _self->x_0_10158; /* string */
  kk_drop_match(_self, {kk_string_dup(x_0_10158, _ctx);}, {}, _ctx)
  kk_string_t _y_x10123_40 = kk_string_unbox(_b_x36); /*string*/;
  kk_string_t _x_x104;
  kk_string_t _x_x105;
  kk_define_string_literal(static, _s_x106, 6, "Just2(", _ctx)
  _x_x105 = kk_string_dup(_s_x106, _ctx); /*string*/
  kk_string_t _x_x107;
  kk_string_t _x_x108;
  kk_string_t _x_x109;
  kk_define_string_literal(static, _s_x110, 1, ",", _ctx)
  _x_x109 = kk_string_dup(_s_x110, _ctx); /*string*/
  kk_string_t _x_x111;
  kk_string_t _x_x112;
  kk_define_string_literal(static, _s_x113, 1, ")", _ctx)
  _x_x112 = kk_string_dup(_s_x113, _ctx); /*string*/
  _x_x111 = kk_std_core_types__lp__plus__plus__rp_(_y_x10123_40, _x_x112, _ctx); /*string*/
  _x_x108 = kk_std_core_types__lp__plus__plus__rp_(_x_x109, _x_x111, _ctx); /*string*/
  _x_x107 = kk_std_core_types__lp__plus__plus__rp_(x_0_10158, _x_x108, _ctx); /*string*/
  _x_x104 = kk_std_core_types__lp__plus__plus__rp_(_x_x105, _x_x107, _ctx); /*string*/
  return kk_string_box(_x_x104);
}

kk_string_t kk_std_core_maybe2_show(kk_std_core_types__maybe2 mb, kk_function_t _implicit_fs_fst_fs_show, kk_function_t _implicit_fs_snd_fs_show, kk_context_t* _ctx) { /* forall<a,b,e> (mb : maybe2<a,b>, ?fst/show : (a) -> e string, ?snd/show : (b) -> e string) -> e string */ 
  if (kk_std_core_types__is_Just2(mb, _ctx)) {
    kk_box_t x = mb._cons.Just2.fst;
    kk_box_t y = mb._cons.Just2.snd;
    kk_string_t x_0_10158 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_fst_fs_show, (_implicit_fs_fst_fs_show, x, _ctx), _ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10158, _ctx);
      kk_box_t _x_x99 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2_new_show_fun100(_implicit_fs_snd_fs_show, y, _ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x99);
    }
    {
      kk_string_t x_1_10161 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_snd_fs_show, (_implicit_fs_snd_fs_show, y, _ctx), _ctx); /*string*/;
      if (kk_yielding(kk_context())) {
        kk_string_drop(x_1_10161, _ctx);
        kk_box_t _x_x102 = kk_std_core_hnd_yield_extend(kk_std_core_maybe2_new_show_fun103(x_0_10158, _ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x102);
      }
      {
        kk_string_t _x_x114;
        kk_define_string_literal(static, _s_x115, 6, "Just2(", _ctx)
        _x_x114 = kk_string_dup(_s_x115, _ctx); /*string*/
        kk_string_t _x_x116;
        kk_string_t _x_x117;
        kk_string_t _x_x118;
        kk_define_string_literal(static, _s_x119, 1, ",", _ctx)
        _x_x118 = kk_string_dup(_s_x119, _ctx); /*string*/
        kk_string_t _x_x120;
        kk_string_t _x_x121;
        kk_define_string_literal(static, _s_x122, 1, ")", _ctx)
        _x_x121 = kk_string_dup(_s_x122, _ctx); /*string*/
        _x_x120 = kk_std_core_types__lp__plus__plus__rp_(x_1_10161, _x_x121, _ctx); /*string*/
        _x_x117 = kk_std_core_types__lp__plus__plus__rp_(_x_x118, _x_x120, _ctx); /*string*/
        _x_x116 = kk_std_core_types__lp__plus__plus__rp_(x_0_10158, _x_x117, _ctx); /*string*/
        return kk_std_core_types__lp__plus__plus__rp_(_x_x114, _x_x116, _ctx);
      }
    }
  }
  {
    kk_function_drop(_implicit_fs_snd_fs_show, _ctx);
    kk_function_drop(_implicit_fs_fst_fs_show, _ctx);
    kk_define_string_literal(static, _s_x123, 8, "Nothing2", _ctx)
    return kk_string_dup(_s_x123, _ctx);
  }
}

// initialization
void kk_std_core_maybe2__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_maybe2__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
