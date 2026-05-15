// Koka generated module: std/core/maybe, koka version: 3.2.3, platform: 64-bit
#include "std_core_maybe.h"
 
// Get the value of the `Just` constructor or raise an exception

kk_box_t kk_std_core_maybe_unjust(kk_std_core_types__maybe m, kk_string_t _implicit_fs_kk_file_line, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>, ?kk-file-line : string) -> exn a */ 
  if (kk_std_core_types__is_Just(m, _ctx)) {
    kk_box_t x = m._cons.Just.value;
    kk_string_drop(_implicit_fs_kk_file_line, _ctx);
    return x;
  }
  {
    kk_string_t message_10000;
    kk_string_t _x_x69;
    kk_define_string_literal(static, _s_x70, 22, "unexpected Nothing in ", _ctx)
    _x_x69 = kk_string_dup(_s_x70, _ctx); /*string*/
    message_10000 = kk_std_core_types__lp__plus__plus__rp_(_x_x69, _implicit_fs_kk_file_line, _ctx); /*string*/
    kk_std_core_hnd__ev ev_10126 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x71 = kk_std_core_hnd__as_Ev(ev_10126, _ctx);
      kk_box_t _box_x0 = _con_x71->hnd;
      int32_t m_0 = _con_x71->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x0, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x64;
      kk_std_core_hnd__clause1 _brw_x66 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x64 = _brw_x66; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x4 = _match_x64.clause;
        kk_box_t _x_x72;
        kk_std_core_exn__exception _x_x73;
        kk_std_core_exn__exception_info _x_x74;
        kk_std_core_types__optional _match_x65 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x65, _ctx)) {
          kk_box_t _box_x8 = _match_x65._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x8, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x65, _ctx);
          _x_x74 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x65, _ctx);
          _x_x74 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x73 = kk_std_core_exn__new_Exception(message_10000, _x_x74, _ctx); /*exception*/
        _x_x72 = kk_std_core_exn__exception_box(_x_x73, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4, (_fun_unbox_x4, m_0, ev_10126, _x_x72, _ctx), _ctx);
      }
    }
  }
}
 
// Get the value of the `Just` constructor or raise an exception with `error-msg`

kk_box_t kk_std_core_maybe_expect(kk_std_core_types__maybe m, kk_string_t error_msg, kk_context_t* _ctx) { /* forall<a> (m : maybe<a>, error-msg : string) -> exn a */ 
  if (kk_std_core_types__is_Just(m, _ctx)) {
    kk_box_t x = m._cons.Just.value;
    kk_string_drop(error_msg, _ctx);
    return x;
  }
  {
    kk_std_core_hnd__ev ev_10129 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x75 = kk_std_core_hnd__as_Ev(ev_10129, _ctx);
      kk_box_t _box_x9 = _con_x75->hnd;
      int32_t m_0 = _con_x75->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x9, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x61;
      kk_std_core_hnd__clause1 _brw_x63 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x61 = _brw_x63; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x13 = _match_x61.clause;
        kk_box_t _x_x76;
        kk_std_core_exn__exception _x_x77;
        kk_std_core_exn__exception_info _x_x78;
        kk_std_core_types__optional _match_x62 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x62, _ctx)) {
          kk_box_t _box_x17 = _match_x62._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x17, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x62, _ctx);
          _x_x78 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x62, _ctx);
          _x_x78 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x77 = kk_std_core_exn__new_Exception(error_msg, _x_x78, _ctx); /*exception*/
        _x_x76 = kk_std_core_exn__exception_box(_x_x77, _ctx); /*45*/
        return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x13, (_fun_unbox_x13, m_0, ev_10129, _x_x76, _ctx), _ctx);
      }
    }
  }
}


// lift anonymous function
struct kk_std_core_maybe_map_fun80__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe_map_fun80(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe_new_map_fun80(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe_map_fun80, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe_map_fun80(kk_function_t _fself, kk_box_t _b_x19, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _y_x10110_21 = _b_x19; /*267*/;
  kk_std_core_types__maybe _x_x81 = kk_std_core_types__new_Just(_y_x10110_21, _ctx); /*maybe<88>*/
  return kk_std_core_types__maybe_box(_x_x81, _ctx);
}

kk_std_core_types__maybe kk_std_core_maybe_map(kk_std_core_types__maybe m, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (m : maybe<a>, f : (a) -> e b) -> e maybe<b> */ 
  if (kk_std_core_types__is_Nothing(m, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t x = m._cons.Just.value;
    kk_box_t x_0_10132 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f, (f, x, _ctx), _ctx); /*267*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10132, _ctx);
      kk_box_t _x_x79 = kk_std_core_hnd_yield_extend(kk_std_core_maybe_new_map_fun80(_ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x79, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Just(x_0_10132, _ctx);
    }
  }
}
 
// Equality on `:maybe`

bool kk_std_core_maybe__lp__eq__eq__rp_(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs__lp__eq__eq__rp_, kk_context_t* _ctx) { /* forall<a,e> (mb1 : maybe<a>, mb2 : maybe<a>, ?(==) : (a, a) -> e bool) -> e bool */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      return kk_function_call(bool, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs__lp__eq__eq__rp_, (_implicit_fs__lp__eq__eq__rp_, x, y, _ctx), _ctx);
    }
    {
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
      return false;
    }
  }
  {
    kk_function_drop(_implicit_fs__lp__eq__eq__rp_, _ctx);
    if (kk_std_core_types__is_Nothing(mb2, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__maybe_drop(mb2, _ctx);
      return false;
    }
  }
}
 
// Order on `:maybe` values

kk_std_core_types__order kk_std_core_maybe_cmp(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs_cmp, kk_context_t* _ctx) { /* forall<a,e> (mb1 : maybe<a>, mb2 : maybe<a>, ?cmp : (a, a) -> e order) -> e order */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      return kk_function_call(kk_std_core_types__order, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _implicit_fs_cmp, (_implicit_fs_cmp, x, y, _ctx), _ctx);
    }
    {
      kk_box_drop(x, _ctx);
      kk_function_drop(_implicit_fs_cmp, _ctx);
      return kk_std_core_types__new_Gt(_ctx);
    }
  }
  {
    kk_function_drop(_implicit_fs_cmp, _ctx);
    if (kk_std_core_types__is_Nothing(mb2, _ctx)) {
      return kk_std_core_types__new_Eq(_ctx);
    }
    {
      kk_std_core_types__maybe_drop(mb2, _ctx);
      return kk_std_core_types__new_Lt(_ctx);
    }
  }
}
 
// monadic lift

kk_std_core_types__order2 kk_std_core_maybe__mlift_order2_10124(kk_std_core_types__order2 _y_x10118, kk_context_t* _ctx) { /* forall<a,e> (order2<a>) -> e order2<maybe<a>> */ 
  if (kk_std_core_types__is_Eq2(_y_x10118, _ctx)) {
    kk_box_t z = _y_x10118._cons.Eq2.eq;
    kk_box_t _x_x82;
    kk_std_core_types__maybe _x_x83 = kk_std_core_types__new_Just(z, _ctx); /*maybe<88>*/
    _x_x82 = kk_std_core_types__maybe_box(_x_x83, _ctx); /*105*/
    return kk_std_core_types__new_Eq2(_x_x82, _ctx);
  }
  if (kk_std_core_types__is_Lt2(_y_x10118, _ctx)) {
    kk_box_t l = _y_x10118._cons.Lt2.lt;
    kk_box_t g = _y_x10118._cons.Lt2.gt;
    kk_box_t _x_x84;
    kk_std_core_types__maybe _x_x85 = kk_std_core_types__new_Just(l, _ctx); /*maybe<88>*/
    _x_x84 = kk_std_core_types__maybe_box(_x_x85, _ctx); /*105*/
    kk_box_t _x_x86;
    kk_std_core_types__maybe _x_x87 = kk_std_core_types__new_Just(g, _ctx); /*maybe<88>*/
    _x_x86 = kk_std_core_types__maybe_box(_x_x87, _ctx); /*105*/
    return kk_std_core_types__new_Lt2(_x_x84, _x_x86, _ctx);
  }
  {
    kk_box_t l_0 = _y_x10118._cons.Gt2.lt;
    kk_box_t g_0 = _y_x10118._cons.Gt2.gt;
    kk_box_t _x_x88;
    kk_std_core_types__maybe _x_x89 = kk_std_core_types__new_Just(l_0, _ctx); /*maybe<88>*/
    _x_x88 = kk_std_core_types__maybe_box(_x_x89, _ctx); /*105*/
    kk_box_t _x_x90;
    kk_std_core_types__maybe _x_x91 = kk_std_core_types__new_Just(g_0, _ctx); /*maybe<88>*/
    _x_x90 = kk_std_core_types__maybe_box(_x_x91, _ctx); /*105*/
    return kk_std_core_types__new_Gt2(_x_x88, _x_x90, _ctx);
  }
}
 
// Order two `:maybe` values in ascending order


// lift anonymous function
struct kk_std_core_maybe_order2_fun94__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe_order2_fun94(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe_new_order2_fun94(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe_order2_fun94, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe_order2_fun94(kk_function_t _fself, kk_box_t _b_x33, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__order2 _y_x10118_53 = kk_std_core_types__order2_unbox(_b_x33, KK_OWNED, _ctx); /*order2<580>*/;
  kk_std_core_types__order2 _x_x95 = kk_std_core_maybe__mlift_order2_10124(_y_x10118_53, _ctx); /*order2<maybe<580>>*/
  return kk_std_core_types__order2_box(_x_x95, _ctx);
}

kk_std_core_types__order2 kk_std_core_maybe_order2(kk_std_core_types__maybe mb1, kk_std_core_types__maybe mb2, kk_function_t _implicit_fs_order2, kk_context_t* _ctx) { /* forall<a,e> (mb1 : maybe<a>, mb2 : maybe<a>, ?order2 : (a, a) -> e order2<a>) -> e order2<maybe<a>> */ 
  if (kk_std_core_types__is_Just(mb1, _ctx)) {
    kk_box_t x = mb1._cons.Just.value;
    if (kk_std_core_types__is_Just(mb2, _ctx)) {
      kk_box_t y = mb2._cons.Just.value;
      kk_std_core_types__order2 x_0_10136;
      kk_function_t _x_x92 = kk_function_dup(_implicit_fs_order2, _ctx); /*(580, 580) -> 581 order2<580>*/
      x_0_10136 = kk_function_call(kk_std_core_types__order2, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x92, (_x_x92, x, y, _ctx), _ctx); /*order2<580>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__order2_drop(x_0_10136, _ctx);
        kk_box_t _x_x93 = kk_std_core_hnd_yield_extend(kk_std_core_maybe_new_order2_fun94(_ctx), _ctx); /*2419*/
        return kk_std_core_types__order2_unbox(_x_x93, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Eq2(x_0_10136, _ctx)) {
        kk_box_t z = x_0_10136._cons.Eq2.eq;
        kk_box_t _x_x96;
        kk_std_core_types__maybe _x_x97 = kk_std_core_types__new_Just(z, _ctx); /*maybe<88>*/
        _x_x96 = kk_std_core_types__maybe_box(_x_x97, _ctx); /*105*/
        return kk_std_core_types__new_Eq2(_x_x96, _ctx);
      }
      if (kk_std_core_types__is_Lt2(x_0_10136, _ctx)) {
        kk_box_t l = x_0_10136._cons.Lt2.lt;
        kk_box_t g = x_0_10136._cons.Lt2.gt;
        kk_box_t _x_x98;
        kk_std_core_types__maybe _x_x99 = kk_std_core_types__new_Just(l, _ctx); /*maybe<88>*/
        _x_x98 = kk_std_core_types__maybe_box(_x_x99, _ctx); /*105*/
        kk_box_t _x_x100;
        kk_std_core_types__maybe _x_x101 = kk_std_core_types__new_Just(g, _ctx); /*maybe<88>*/
        _x_x100 = kk_std_core_types__maybe_box(_x_x101, _ctx); /*105*/
        return kk_std_core_types__new_Lt2(_x_x98, _x_x100, _ctx);
      }
      {
        kk_box_t l_0 = x_0_10136._cons.Gt2.lt;
        kk_box_t g_0 = x_0_10136._cons.Gt2.gt;
        kk_box_t _x_x102;
        kk_std_core_types__maybe _x_x103 = kk_std_core_types__new_Just(l_0, _ctx); /*maybe<88>*/
        _x_x102 = kk_std_core_types__maybe_box(_x_x103, _ctx); /*105*/
        kk_box_t _x_x104;
        kk_std_core_types__maybe _x_x105 = kk_std_core_types__new_Just(g_0, _ctx); /*maybe<88>*/
        _x_x104 = kk_std_core_types__maybe_box(_x_x105, _ctx); /*105*/
        return kk_std_core_types__new_Gt2(_x_x102, _x_x104, _ctx);
      }
    }
    {
      kk_box_t _x_x106;
      kk_std_core_types__maybe _x_x107 = kk_std_core_types__new_Just(x, _ctx); /*maybe<88>*/
      _x_x106 = kk_std_core_types__maybe_box(_x_x107, _ctx); /*105*/
      return kk_std_core_types__new_Gt2(kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx), _x_x106, _ctx);
    }
  }
  {
    return kk_std_core_types__new_Lt2(kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx), kk_std_core_types__maybe_box(mb2, _ctx), _ctx);
  }
}
 
// Show a `:maybe` type


// lift anonymous function
struct kk_std_core_maybe_show_fun114__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_core_maybe_show_fun114(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx);
static kk_function_t kk_std_core_maybe_new_show_fun114(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_maybe_show_fun114, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_core_maybe_show_fun114(kk_function_t _fself, kk_box_t _b_x55, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _y_x10121_57 = kk_string_unbox(_b_x55); /*string*/;
  kk_string_t _x_x115;
  kk_string_t _x_x116;
  kk_define_string_literal(static, _s_x117, 5, "Just(", _ctx)
  _x_x116 = kk_string_dup(_s_x117, _ctx); /*string*/
  kk_string_t _x_x118;
  kk_string_t _x_x119;
  kk_define_string_literal(static, _s_x120, 1, ")", _ctx)
  _x_x119 = kk_string_dup(_s_x120, _ctx); /*string*/
  _x_x118 = kk_std_core_types__lp__plus__plus__rp_(_y_x10121_57, _x_x119, _ctx); /*string*/
  _x_x115 = kk_std_core_types__lp__plus__plus__rp_(_x_x116, _x_x118, _ctx); /*string*/
  return kk_string_box(_x_x115);
}

kk_string_t kk_std_core_maybe_show(kk_std_core_types__maybe mb, kk_function_t _implicit_fs_show, kk_context_t* _ctx) { /* forall<a,e> (mb : maybe<a>, ?show : (a) -> e string) -> e string */ 
  if (kk_std_core_types__is_Just(mb, _ctx)) {
    kk_box_t x = mb._cons.Just.value;
    kk_string_t x_0_10139 = kk_function_call(kk_string_t, (kk_function_t, kk_box_t, kk_context_t*), _implicit_fs_show, (_implicit_fs_show, x, _ctx), _ctx); /*string*/;
    if (kk_yielding(kk_context())) {
      kk_string_drop(x_0_10139, _ctx);
      kk_box_t _x_x113 = kk_std_core_hnd_yield_extend(kk_std_core_maybe_new_show_fun114(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x113);
    }
    {
      kk_string_t _x_x121;
      kk_define_string_literal(static, _s_x122, 5, "Just(", _ctx)
      _x_x121 = kk_string_dup(_s_x122, _ctx); /*string*/
      kk_string_t _x_x123;
      kk_string_t _x_x124;
      kk_define_string_literal(static, _s_x125, 1, ")", _ctx)
      _x_x124 = kk_string_dup(_s_x125, _ctx); /*string*/
      _x_x123 = kk_std_core_types__lp__plus__plus__rp_(x_0_10139, _x_x124, _ctx); /*string*/
      return kk_std_core_types__lp__plus__plus__rp_(_x_x121, _x_x123, _ctx);
    }
  }
  {
    kk_function_drop(_implicit_fs_show, _ctx);
    kk_define_string_literal(static, _s_x126, 7, "Nothing", _ctx)
    return kk_string_dup(_s_x126, _ctx);
  }
}

// initialization
void kk_std_core_maybe__init(kk_context_t* _ctx){
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
void kk_std_core_maybe__done(kk_context_t* _ctx){
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
