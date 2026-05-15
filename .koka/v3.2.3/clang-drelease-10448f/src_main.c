// Koka generated module: src/main, koka version: 3.2.3, platform: 64-bit
#include "src_main.h"

kk_unit_t kk_src_main_hc_assert(bool b, kk_context_t* _ctx) { /* (b : bool) -> exn () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<exn>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (b) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_core_hnd__ev ev_10109 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x13;
    {
      struct kk_std_core_hnd_Ev* _con_x14 = kk_std_core_hnd__as_Ev(ev_10109, _ctx);
      kk_box_t _box_x0 = _con_x14->hnd;
      int32_t m = _con_x14->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x0, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x9;
      kk_std_core_hnd__clause1 _brw_x11 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,10000,exn,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x9 = _brw_x11; /*hnd/clause1<exception,10000,exn,10001,10002>*/
      {
        kk_function_t _fun_unbox_x4 = _match_x9.clause;
        kk_box_t _x_x15;
        kk_std_core_exn__exception _x_x16;
        kk_string_t _x_x17;
        kk_define_string_literal(static, _s_x18, 16, "assertion failed", _ctx)
        _x_x17 = kk_string_dup(_s_x18, _ctx); /*string*/
        kk_std_core_exn__exception_info _x_x19;
        kk_std_core_types__optional _match_x10 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x10, _ctx)) {
          kk_box_t _box_x8 = _match_x10._cons._Optional.value;
          kk_std_core_exn__exception_info _uniq_info_400 = kk_std_core_exn__exception_info_unbox(_box_x8, KK_BORROWED, _ctx);
          kk_std_core_exn__exception_info_dup(_uniq_info_400, _ctx);
          kk_std_core_types__optional_drop(_match_x10, _ctx);
          _x_x19 = _uniq_info_400; /*exception-info*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x10, _ctx);
          _x_x19 = kk_std_core_exn__new_ExnError(_ctx); /*exception-info*/
        }
        _x_x16 = kk_std_core_exn__new_Exception(_x_x17, _x_x19, _ctx); /*exception*/
        _x_x15 = kk_std_core_exn__exception_box(_x_x16, _ctx); /*10009*/
        _x_x13 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x4, (_fun_unbox_x4, m, ev_10109, _x_x15, _ctx), _ctx); /*10010*/
      }
    }
    kk_unit_unbox(_x_x13); return kk_Unit;
  }
}

// initialization
void kk_src_main__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_std_core__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_src_main__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
