// Koka generated module: std/core/show, koka version: 3.2.3, platform: 64-bit
#include "std_core_show.h"
 
// Generic show: shows the internal representation of an object as a string
// Note: this breaks parametricity so it should not be public

kk_string_t kk_std_core_show_gshow(kk_box_t _arg_x1, kk_context_t* _ctx) { /* forall<a> (a) -> string */ 
  return kk_show_any(_arg_x1,kk_context());
}

kk_string_t kk_std_core_show_int_show_hex(kk_integer_t i, bool use_capitals, kk_context_t* _ctx) { /* (i : int, use-capitals : bool) -> string */ 
  return kk_integer_to_hex_string(i,use_capitals,kk_context());
}
 
// Show an `:int` as a hexadecimal value.
// The `width`  parameter specifies how wide the hex value is where `"0"`  is used to align.
// The `use-capitals` parameter (= `True`) determines if capital letters should be used to display the hexadecimal digits.
// The `pre` (=`"0x"`) is an optional prefix for the number (goes between the sign and the number).

kk_string_t kk_std_core_show_show_hex(kk_integer_t i, kk_std_core_types__optional width, kk_std_core_types__optional use_capitals, kk_std_core_types__optional pre, kk_context_t* _ctx) { /* (i : int, width : ? int, use-capitals : ? bool, pre : ? string) -> string */ 
  kk_string_t s_10000;
  kk_integer_t _x_x97;
  kk_integer_t _x_x98 = kk_integer_dup(i, _ctx); /*int*/
  _x_x97 = kk_integer_abs(_x_x98,kk_context()); /*int*/
  bool _x_x99;
  if (kk_std_core_types__is_Optional(use_capitals, _ctx)) {
    kk_box_t _box_x0 = use_capitals._cons._Optional.value;
    bool _uniq_use_capitals_66 = kk_bool_unbox(_box_x0);
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x99 = _uniq_use_capitals_66; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(use_capitals, _ctx);
    _x_x99 = true; /*bool*/
  }
  s_10000 = kk_std_core_show_int_show_hex(_x_x97, _x_x99, _ctx); /*string*/
  kk_integer_t n;
  kk_string_t _x_x100 = kk_string_dup(s_10000, _ctx); /*string*/
  n = kk_std_core_string_chars_fs_count(_x_x100, _ctx); /*int*/
  kk_string_t _x_x101;
  bool _match_x91;
  bool _brw_x92 = kk_integer_lt_borrow(i,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(i, _ctx);
  _match_x91 = _brw_x92; /*bool*/
  if (_match_x91) {
    kk_define_string_literal(static, _s_x102, 1, "-", _ctx)
    _x_x101 = kk_string_dup(_s_x102, _ctx); /*string*/
  }
  else {
    _x_x101 = kk_string_empty(); /*string*/
  }
  kk_string_t _x_x104;
  kk_string_t _x_x105;
  if (kk_std_core_types__is_Optional(pre, _ctx)) {
    kk_box_t _box_x1 = pre._cons._Optional.value;
    kk_string_t _uniq_pre_70 = kk_string_unbox(_box_x1);
    kk_string_dup(_uniq_pre_70, _ctx);
    kk_std_core_types__optional_drop(pre, _ctx);
    _x_x105 = _uniq_pre_70; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(pre, _ctx);
    kk_define_string_literal(static, _s_x106, 2, "0x", _ctx)
    _x_x105 = kk_string_dup(_s_x106, _ctx); /*string*/
  }
  kk_string_t _x_x107;
  bool _match_x88;
  kk_integer_t _brw_x89;
  if (kk_std_core_types__is_Optional(width, _ctx)) {
    kk_box_t _box_x2 = width._cons._Optional.value;
    kk_integer_t _uniq_width_62 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_width_62, _ctx);
    _brw_x89 = _uniq_width_62; /*int*/
  }
  else {
    _brw_x89 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x90 = kk_integer_lte_borrow(_brw_x89,n,kk_context()); /*bool*/;
  kk_integer_drop(_brw_x89, _ctx);
  _match_x88 = _brw_x90; /*bool*/
  if (_match_x88) {
    kk_std_core_types__optional_drop(width, _ctx);
    kk_integer_drop(n, _ctx);
    _x_x107 = s_10000; /*string*/
  }
  else {
    kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
    kk_integer_t n_0_10012;
    kk_integer_t _x_x108;
    if (kk_std_core_types__is_Optional(width, _ctx)) {
      kk_box_t _box_x3 = width._cons._Optional.value;
      kk_integer_t _uniq_width_62_0 = kk_integer_unbox(_box_x3, _ctx);
      kk_integer_dup(_uniq_width_62_0, _ctx);
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x108 = _uniq_width_62_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(width, _ctx);
      _x_x108 = kk_integer_from_small(1); /*int*/
    }
    n_0_10012 = kk_integer_sub(_x_x108,n,kk_context()); /*int*/
    kk_string_t _x_x109 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
    _x_x107 = kk_std_core_types__lp__plus__plus__rp_(_x_x109, s_10000, _ctx); /*string*/
  }
  _x_x104 = kk_std_core_types__lp__plus__plus__rp_(_x_x105, _x_x107, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x101, _x_x104, _ctx);
}
 
// Show a character as a string

kk_string_t kk_std_core_show_show_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> string */ 
  bool _match_x39 = (c < (' ')); /*bool*/;
  if (_match_x39) {
    bool _match_x66 = (c == 0x000A); /*bool*/;
    if (_match_x66) {
      kk_define_string_literal(static, _s_x110, 2, "\\n", _ctx)
      return kk_string_dup(_s_x110, _ctx);
    }
    {
      bool _match_x67 = (c == 0x000D); /*bool*/;
      if (_match_x67) {
        kk_define_string_literal(static, _s_x111, 2, "\\r", _ctx)
        return kk_string_dup(_s_x111, _ctx);
      }
      {
        bool _match_x68 = (c == 0x0009); /*bool*/;
        if (_match_x68) {
          kk_define_string_literal(static, _s_x112, 2, "\\t", _ctx)
          return kk_string_dup(_s_x112, _ctx);
        }
        {
          bool _match_x69;
          kk_integer_t _brw_x86 = kk_integer_from_int(c,kk_context()); /*int*/;
          bool _brw_x87 = kk_integer_lte_borrow(_brw_x86,(kk_integer_from_small(255)),kk_context()); /*bool*/;
          kk_integer_drop(_brw_x86, _ctx);
          _match_x69 = _brw_x87; /*bool*/
          if (_match_x69) {
            kk_integer_t _arg_x247 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_string_t s_10007;
            kk_integer_t _x_x113;
            kk_integer_t _x_x114 = kk_integer_dup(_arg_x247, _ctx); /*int*/
            _x_x113 = kk_integer_abs(_x_x114,kk_context()); /*int*/
            bool _x_x115;
            kk_std_core_types__optional _match_x85 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
            if (kk_std_core_types__is_Optional(_match_x85, _ctx)) {
              kk_box_t _box_x4 = _match_x85._cons._Optional.value;
              bool _uniq_use_capitals_66 = kk_bool_unbox(_box_x4);
              kk_std_core_types__optional_drop(_match_x85, _ctx);
              _x_x115 = _uniq_use_capitals_66; /*bool*/
            }
            else {
              kk_std_core_types__optional_drop(_match_x85, _ctx);
              _x_x115 = true; /*bool*/
            }
            s_10007 = kk_std_core_show_int_show_hex(_x_x113, _x_x115, _ctx); /*string*/
            kk_integer_t n;
            kk_string_t _x_x116 = kk_string_dup(s_10007, _ctx); /*string*/
            n = kk_std_core_string_chars_fs_count(_x_x116, _ctx); /*int*/
            kk_string_t _x_x117;
            kk_define_string_literal(static, _s_x118, 2, "\\x", _ctx)
            _x_x117 = kk_string_dup(_s_x118, _ctx); /*string*/
            kk_string_t _x_x119;
            kk_string_t _x_x120;
            bool _match_x83;
            bool _brw_x84 = kk_integer_lt_borrow(_arg_x247,(kk_integer_from_small(0)),kk_context()); /*bool*/;
            kk_integer_drop(_arg_x247, _ctx);
            _match_x83 = _brw_x84; /*bool*/
            if (_match_x83) {
              kk_define_string_literal(static, _s_x121, 1, "-", _ctx)
              _x_x120 = kk_string_dup(_s_x121, _ctx); /*string*/
            }
            else {
              _x_x120 = kk_string_empty(); /*string*/
            }
            kk_string_t _x_x123;
            kk_string_t _x_x124 = kk_string_empty(); /*string*/
            kk_string_t _x_x126;
            bool _match_x82 = kk_integer_lte_borrow((kk_integer_from_small(2)),n,kk_context()); /*bool*/;
            if (_match_x82) {
              kk_integer_drop(n, _ctx);
              _x_x126 = s_10007; /*string*/
            }
            else {
              kk_string_t s_0_10011 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
              kk_integer_t n_0_10012 = kk_integer_sub((kk_integer_from_small(2)),n,kk_context()); /*int*/;
              kk_string_t _x_x127 = kk_std_core_string_repeatz(s_0_10011, kk_std_core_int_ssize__t(n_0_10012, _ctx), _ctx); /*string*/
              _x_x126 = kk_std_core_types__lp__plus__plus__rp_(_x_x127, s_10007, _ctx); /*string*/
            }
            _x_x123 = kk_std_core_types__lp__plus__plus__rp_(_x_x124, _x_x126, _ctx); /*string*/
            _x_x119 = kk_std_core_types__lp__plus__plus__rp_(_x_x120, _x_x123, _ctx); /*string*/
            return kk_std_core_types__lp__plus__plus__rp_(_x_x117, _x_x119, _ctx);
          }
          {
            bool _match_x70;
            kk_integer_t _brw_x80 = kk_integer_from_int(c,kk_context()); /*int*/;
            kk_integer_t _brw_x79 = kk_integer_from_int(65535, _ctx); /*int*/;
            bool _brw_x81 = kk_integer_lte_borrow(_brw_x80,_brw_x79,kk_context()); /*bool*/;
            kk_integer_drop(_brw_x80, _ctx);
            kk_integer_drop(_brw_x79, _ctx);
            _match_x70 = _brw_x81; /*bool*/
            if (_match_x70) {
              kk_integer_t _arg_x302 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_0_10014;
              kk_integer_t _x_x128;
              kk_integer_t _x_x129 = kk_integer_dup(_arg_x302, _ctx); /*int*/
              _x_x128 = kk_integer_abs(_x_x129,kk_context()); /*int*/
              bool _x_x130;
              kk_std_core_types__optional _match_x78 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x78, _ctx)) {
                kk_box_t _box_x5 = _match_x78._cons._Optional.value;
                bool _uniq_use_capitals_66_0 = kk_bool_unbox(_box_x5);
                kk_std_core_types__optional_drop(_match_x78, _ctx);
                _x_x130 = _uniq_use_capitals_66_0; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x78, _ctx);
                _x_x130 = true; /*bool*/
              }
              s_0_10014 = kk_std_core_show_int_show_hex(_x_x128, _x_x130, _ctx); /*string*/
              kk_integer_t n_0;
              kk_string_t _x_x131 = kk_string_dup(s_0_10014, _ctx); /*string*/
              n_0 = kk_std_core_string_chars_fs_count(_x_x131, _ctx); /*int*/
              kk_string_t _x_x132;
              kk_define_string_literal(static, _s_x133, 2, "\\u", _ctx)
              _x_x132 = kk_string_dup(_s_x133, _ctx); /*string*/
              kk_string_t _x_x134;
              kk_string_t _x_x135;
              bool _match_x76;
              bool _brw_x77 = kk_integer_lt_borrow(_arg_x302,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x302, _ctx);
              _match_x76 = _brw_x77; /*bool*/
              if (_match_x76) {
                kk_define_string_literal(static, _s_x136, 1, "-", _ctx)
                _x_x135 = kk_string_dup(_s_x136, _ctx); /*string*/
              }
              else {
                _x_x135 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x138;
              kk_string_t _x_x139 = kk_string_empty(); /*string*/
              kk_string_t _x_x141;
              bool _match_x75 = kk_integer_lte_borrow((kk_integer_from_small(4)),n_0,kk_context()); /*bool*/;
              if (_match_x75) {
                kk_integer_drop(n_0, _ctx);
                _x_x141 = s_0_10014; /*string*/
              }
              else {
                kk_string_t s_0_10011_0 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_0 = kk_integer_sub((kk_integer_from_small(4)),n_0,kk_context()); /*int*/;
                kk_string_t _x_x142 = kk_std_core_string_repeatz(s_0_10011_0, kk_std_core_int_ssize__t(n_0_10012_0, _ctx), _ctx); /*string*/
                _x_x141 = kk_std_core_types__lp__plus__plus__rp_(_x_x142, s_0_10014, _ctx); /*string*/
              }
              _x_x138 = kk_std_core_types__lp__plus__plus__rp_(_x_x139, _x_x141, _ctx); /*string*/
              _x_x134 = kk_std_core_types__lp__plus__plus__rp_(_x_x135, _x_x138, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x132, _x_x134, _ctx);
            }
            {
              kk_integer_t _arg_x345 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_1_10021;
              kk_integer_t _x_x143;
              kk_integer_t _x_x144 = kk_integer_dup(_arg_x345, _ctx); /*int*/
              _x_x143 = kk_integer_abs(_x_x144,kk_context()); /*int*/
              bool _x_x145;
              kk_std_core_types__optional _match_x74 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x74, _ctx)) {
                kk_box_t _box_x6 = _match_x74._cons._Optional.value;
                bool _uniq_use_capitals_66_1 = kk_bool_unbox(_box_x6);
                kk_std_core_types__optional_drop(_match_x74, _ctx);
                _x_x145 = _uniq_use_capitals_66_1; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x74, _ctx);
                _x_x145 = true; /*bool*/
              }
              s_1_10021 = kk_std_core_show_int_show_hex(_x_x143, _x_x145, _ctx); /*string*/
              kk_integer_t n_1;
              kk_string_t _x_x146 = kk_string_dup(s_1_10021, _ctx); /*string*/
              n_1 = kk_std_core_string_chars_fs_count(_x_x146, _ctx); /*int*/
              kk_string_t _x_x147;
              kk_define_string_literal(static, _s_x148, 2, "\\U", _ctx)
              _x_x147 = kk_string_dup(_s_x148, _ctx); /*string*/
              kk_string_t _x_x149;
              kk_string_t _x_x150;
              bool _match_x72;
              bool _brw_x73 = kk_integer_lt_borrow(_arg_x345,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x345, _ctx);
              _match_x72 = _brw_x73; /*bool*/
              if (_match_x72) {
                kk_define_string_literal(static, _s_x151, 1, "-", _ctx)
                _x_x150 = kk_string_dup(_s_x151, _ctx); /*string*/
              }
              else {
                _x_x150 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x153;
              kk_string_t _x_x154 = kk_string_empty(); /*string*/
              kk_string_t _x_x156;
              bool _match_x71 = kk_integer_lte_borrow((kk_integer_from_small(6)),n_1,kk_context()); /*bool*/;
              if (_match_x71) {
                kk_integer_drop(n_1, _ctx);
                _x_x156 = s_1_10021; /*string*/
              }
              else {
                kk_string_t s_0_10011_1 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_1 = kk_integer_sub((kk_integer_from_small(6)),n_1,kk_context()); /*int*/;
                kk_string_t _x_x157 = kk_std_core_string_repeatz(s_0_10011_1, kk_std_core_int_ssize__t(n_0_10012_1, _ctx), _ctx); /*string*/
                _x_x156 = kk_std_core_types__lp__plus__plus__rp_(_x_x157, s_1_10021, _ctx); /*string*/
              }
              _x_x153 = kk_std_core_types__lp__plus__plus__rp_(_x_x154, _x_x156, _ctx); /*string*/
              _x_x149 = kk_std_core_types__lp__plus__plus__rp_(_x_x150, _x_x153, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x147, _x_x149, _ctx);
            }
          }
        }
      }
    }
  }
  {
    bool _match_x40 = (c > ('~')); /*bool*/;
    if (_match_x40) {
      bool _match_x44 = (c == 0x000A); /*bool*/;
      if (_match_x44) {
        kk_define_string_literal(static, _s_x158, 2, "\\n", _ctx)
        return kk_string_dup(_s_x158, _ctx);
      }
      {
        bool _match_x45 = (c == 0x000D); /*bool*/;
        if (_match_x45) {
          kk_define_string_literal(static, _s_x159, 2, "\\r", _ctx)
          return kk_string_dup(_s_x159, _ctx);
        }
        {
          bool _match_x46 = (c == 0x0009); /*bool*/;
          if (_match_x46) {
            kk_define_string_literal(static, _s_x160, 2, "\\t", _ctx)
            return kk_string_dup(_s_x160, _ctx);
          }
          {
            bool _match_x47;
            kk_integer_t _brw_x64 = kk_integer_from_int(c,kk_context()); /*int*/;
            bool _brw_x65 = kk_integer_lte_borrow(_brw_x64,(kk_integer_from_small(255)),kk_context()); /*bool*/;
            kk_integer_drop(_brw_x64, _ctx);
            _match_x47 = _brw_x65; /*bool*/
            if (_match_x47) {
              kk_integer_t _arg_x247_0 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_string_t s_2_10028;
              kk_integer_t _x_x161;
              kk_integer_t _x_x162 = kk_integer_dup(_arg_x247_0, _ctx); /*int*/
              _x_x161 = kk_integer_abs(_x_x162,kk_context()); /*int*/
              bool _x_x163;
              kk_std_core_types__optional _match_x63 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
              if (kk_std_core_types__is_Optional(_match_x63, _ctx)) {
                kk_box_t _box_x7 = _match_x63._cons._Optional.value;
                bool _uniq_use_capitals_66_2 = kk_bool_unbox(_box_x7);
                kk_std_core_types__optional_drop(_match_x63, _ctx);
                _x_x163 = _uniq_use_capitals_66_2; /*bool*/
              }
              else {
                kk_std_core_types__optional_drop(_match_x63, _ctx);
                _x_x163 = true; /*bool*/
              }
              s_2_10028 = kk_std_core_show_int_show_hex(_x_x161, _x_x163, _ctx); /*string*/
              kk_integer_t n_2;
              kk_string_t _x_x164 = kk_string_dup(s_2_10028, _ctx); /*string*/
              n_2 = kk_std_core_string_chars_fs_count(_x_x164, _ctx); /*int*/
              kk_string_t _x_x165;
              kk_define_string_literal(static, _s_x166, 2, "\\x", _ctx)
              _x_x165 = kk_string_dup(_s_x166, _ctx); /*string*/
              kk_string_t _x_x167;
              kk_string_t _x_x168;
              bool _match_x61;
              bool _brw_x62 = kk_integer_lt_borrow(_arg_x247_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
              kk_integer_drop(_arg_x247_0, _ctx);
              _match_x61 = _brw_x62; /*bool*/
              if (_match_x61) {
                kk_define_string_literal(static, _s_x169, 1, "-", _ctx)
                _x_x168 = kk_string_dup(_s_x169, _ctx); /*string*/
              }
              else {
                _x_x168 = kk_string_empty(); /*string*/
              }
              kk_string_t _x_x171;
              kk_string_t _x_x172 = kk_string_empty(); /*string*/
              kk_string_t _x_x174;
              bool _match_x60 = kk_integer_lte_borrow((kk_integer_from_small(2)),n_2,kk_context()); /*bool*/;
              if (_match_x60) {
                kk_integer_drop(n_2, _ctx);
                _x_x174 = s_2_10028; /*string*/
              }
              else {
                kk_string_t s_0_10011_2 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                kk_integer_t n_0_10012_2 = kk_integer_sub((kk_integer_from_small(2)),n_2,kk_context()); /*int*/;
                kk_string_t _x_x175 = kk_std_core_string_repeatz(s_0_10011_2, kk_std_core_int_ssize__t(n_0_10012_2, _ctx), _ctx); /*string*/
                _x_x174 = kk_std_core_types__lp__plus__plus__rp_(_x_x175, s_2_10028, _ctx); /*string*/
              }
              _x_x171 = kk_std_core_types__lp__plus__plus__rp_(_x_x172, _x_x174, _ctx); /*string*/
              _x_x167 = kk_std_core_types__lp__plus__plus__rp_(_x_x168, _x_x171, _ctx); /*string*/
              return kk_std_core_types__lp__plus__plus__rp_(_x_x165, _x_x167, _ctx);
            }
            {
              bool _match_x48;
              kk_integer_t _brw_x58 = kk_integer_from_int(c,kk_context()); /*int*/;
              kk_integer_t _brw_x57 = kk_integer_from_int(65535, _ctx); /*int*/;
              bool _brw_x59 = kk_integer_lte_borrow(_brw_x58,_brw_x57,kk_context()); /*bool*/;
              kk_integer_drop(_brw_x58, _ctx);
              kk_integer_drop(_brw_x57, _ctx);
              _match_x48 = _brw_x59; /*bool*/
              if (_match_x48) {
                kk_integer_t _arg_x302_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_string_t s_3_10035;
                kk_integer_t _x_x176;
                kk_integer_t _x_x177 = kk_integer_dup(_arg_x302_0, _ctx); /*int*/
                _x_x176 = kk_integer_abs(_x_x177,kk_context()); /*int*/
                bool _x_x178;
                kk_std_core_types__optional _match_x56 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                if (kk_std_core_types__is_Optional(_match_x56, _ctx)) {
                  kk_box_t _box_x8 = _match_x56._cons._Optional.value;
                  bool _uniq_use_capitals_66_3 = kk_bool_unbox(_box_x8);
                  kk_std_core_types__optional_drop(_match_x56, _ctx);
                  _x_x178 = _uniq_use_capitals_66_3; /*bool*/
                }
                else {
                  kk_std_core_types__optional_drop(_match_x56, _ctx);
                  _x_x178 = true; /*bool*/
                }
                s_3_10035 = kk_std_core_show_int_show_hex(_x_x176, _x_x178, _ctx); /*string*/
                kk_integer_t n_3;
                kk_string_t _x_x179 = kk_string_dup(s_3_10035, _ctx); /*string*/
                n_3 = kk_std_core_string_chars_fs_count(_x_x179, _ctx); /*int*/
                kk_string_t _x_x180;
                kk_define_string_literal(static, _s_x181, 2, "\\u", _ctx)
                _x_x180 = kk_string_dup(_s_x181, _ctx); /*string*/
                kk_string_t _x_x182;
                kk_string_t _x_x183;
                bool _match_x54;
                bool _brw_x55 = kk_integer_lt_borrow(_arg_x302_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(_arg_x302_0, _ctx);
                _match_x54 = _brw_x55; /*bool*/
                if (_match_x54) {
                  kk_define_string_literal(static, _s_x184, 1, "-", _ctx)
                  _x_x183 = kk_string_dup(_s_x184, _ctx); /*string*/
                }
                else {
                  _x_x183 = kk_string_empty(); /*string*/
                }
                kk_string_t _x_x186;
                kk_string_t _x_x187 = kk_string_empty(); /*string*/
                kk_string_t _x_x189;
                bool _match_x53 = kk_integer_lte_borrow((kk_integer_from_small(4)),n_3,kk_context()); /*bool*/;
                if (_match_x53) {
                  kk_integer_drop(n_3, _ctx);
                  _x_x189 = s_3_10035; /*string*/
                }
                else {
                  kk_string_t s_0_10011_3 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                  kk_integer_t n_0_10012_3 = kk_integer_sub((kk_integer_from_small(4)),n_3,kk_context()); /*int*/;
                  kk_string_t _x_x190 = kk_std_core_string_repeatz(s_0_10011_3, kk_std_core_int_ssize__t(n_0_10012_3, _ctx), _ctx); /*string*/
                  _x_x189 = kk_std_core_types__lp__plus__plus__rp_(_x_x190, s_3_10035, _ctx); /*string*/
                }
                _x_x186 = kk_std_core_types__lp__plus__plus__rp_(_x_x187, _x_x189, _ctx); /*string*/
                _x_x182 = kk_std_core_types__lp__plus__plus__rp_(_x_x183, _x_x186, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x180, _x_x182, _ctx);
              }
              {
                kk_integer_t _arg_x345_0 = kk_integer_from_int(c,kk_context()); /*int*/;
                kk_string_t s_4_10042;
                kk_integer_t _x_x191;
                kk_integer_t _x_x192 = kk_integer_dup(_arg_x345_0, _ctx); /*int*/
                _x_x191 = kk_integer_abs(_x_x192,kk_context()); /*int*/
                bool _x_x193;
                kk_std_core_types__optional _match_x52 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
                if (kk_std_core_types__is_Optional(_match_x52, _ctx)) {
                  kk_box_t _box_x9 = _match_x52._cons._Optional.value;
                  bool _uniq_use_capitals_66_4 = kk_bool_unbox(_box_x9);
                  kk_std_core_types__optional_drop(_match_x52, _ctx);
                  _x_x193 = _uniq_use_capitals_66_4; /*bool*/
                }
                else {
                  kk_std_core_types__optional_drop(_match_x52, _ctx);
                  _x_x193 = true; /*bool*/
                }
                s_4_10042 = kk_std_core_show_int_show_hex(_x_x191, _x_x193, _ctx); /*string*/
                kk_integer_t n_4;
                kk_string_t _x_x194 = kk_string_dup(s_4_10042, _ctx); /*string*/
                n_4 = kk_std_core_string_chars_fs_count(_x_x194, _ctx); /*int*/
                kk_string_t _x_x195;
                kk_define_string_literal(static, _s_x196, 2, "\\U", _ctx)
                _x_x195 = kk_string_dup(_s_x196, _ctx); /*string*/
                kk_string_t _x_x197;
                kk_string_t _x_x198;
                bool _match_x50;
                bool _brw_x51 = kk_integer_lt_borrow(_arg_x345_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
                kk_integer_drop(_arg_x345_0, _ctx);
                _match_x50 = _brw_x51; /*bool*/
                if (_match_x50) {
                  kk_define_string_literal(static, _s_x199, 1, "-", _ctx)
                  _x_x198 = kk_string_dup(_s_x199, _ctx); /*string*/
                }
                else {
                  _x_x198 = kk_string_empty(); /*string*/
                }
                kk_string_t _x_x201;
                kk_string_t _x_x202 = kk_string_empty(); /*string*/
                kk_string_t _x_x204;
                bool _match_x49 = kk_integer_lte_borrow((kk_integer_from_small(6)),n_4,kk_context()); /*bool*/;
                if (_match_x49) {
                  kk_integer_drop(n_4, _ctx);
                  _x_x204 = s_4_10042; /*string*/
                }
                else {
                  kk_string_t s_0_10011_4 = kk_std_core_string_char_fs_string('0', _ctx); /*string*/;
                  kk_integer_t n_0_10012_4 = kk_integer_sub((kk_integer_from_small(6)),n_4,kk_context()); /*int*/;
                  kk_string_t _x_x205 = kk_std_core_string_repeatz(s_0_10011_4, kk_std_core_int_ssize__t(n_0_10012_4, _ctx), _ctx); /*string*/
                  _x_x204 = kk_std_core_types__lp__plus__plus__rp_(_x_x205, s_4_10042, _ctx); /*string*/
                }
                _x_x201 = kk_std_core_types__lp__plus__plus__rp_(_x_x202, _x_x204, _ctx); /*string*/
                _x_x197 = kk_std_core_types__lp__plus__plus__rp_(_x_x198, _x_x201, _ctx); /*string*/
                return kk_std_core_types__lp__plus__plus__rp_(_x_x195, _x_x197, _ctx);
              }
            }
          }
        }
      }
    }
    {
      bool _match_x41 = (c == ('\'')); /*bool*/;
      if (_match_x41) {
        kk_define_string_literal(static, _s_x206, 2, "\\\'", _ctx)
        return kk_string_dup(_s_x206, _ctx);
      }
      {
        bool _match_x42 = (c == ('"')); /*bool*/;
        if (_match_x42) {
          kk_define_string_literal(static, _s_x207, 2, "\\\"", _ctx)
          return kk_string_dup(_s_x207, _ctx);
        }
        {
          bool _match_x43 = (c == ('\\')); /*bool*/;
          if (_match_x43) {
            kk_define_string_literal(static, _s_x208, 2, "\\\\", _ctx)
            return kk_string_dup(_s_x208, _ctx);
          }
          {
            return kk_std_core_string_char_fs_string(c, _ctx);
          }
        }
      }
    }
  }
}
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__trmc_lift_show_10159(kk_std_core_types__list _uniq_xs_10151, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<char>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10151, _ctx)) {
    struct kk_std_core_types_Cons* _con_x215 = kk_std_core_types__as_Cons(_uniq_xs_10151, _ctx);
    kk_box_t _box_x10 = _con_x215->head;
    kk_std_core_types__list _uniq_xx_10155 = _con_x215->tail;
    kk_char_t _uniq_x_10154 = kk_char_unbox(_box_x10, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x93 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10151, _ctx)) {
      _ru_x93 = (kk_datatype_ptr_reuse(_uniq_xs_10151, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_xx_10155, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10151, _ctx);
    }
    kk_string_t _trmc_x10160 = kk_std_core_show_show_char(_uniq_x_10154, _ctx); /*string*/;
    kk_std_core_types__list _trmc_x10161 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10162 = kk_std_core_types__new_Cons(_ru_x93, 0, kk_string_box(_trmc_x10160), _trmc_x10161, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x20_25 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10162, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x37;
    kk_std_core_types__cctx _x_x216 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x37 = kk_cctx_extend_linear(_x_x216,(kk_std_core_types__list_box(_trmc_x10162, _ctx)),_b_x20_25,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x38 = kk_std_core_show_string_fs__trmc_lift_show_10159(_uniq_xx_10155, _brw_x37, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x37, _ctx);
    return _brw_x38;
  }
  {
    kk_box_t _x_x217;
    kk_std_core_types__cctx _x_x218 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x217 = kk_cctx_apply_linear(_x_x218,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x217, KK_OWNED, _ctx);
  }
}
 
// lifted local: string/@lift-show@10158, string/show, @spec-x10157
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10152, using:
// @uniq-f@10152 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10159(kk_std_core_types__list _uniq_xs_10151_0, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x35 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x36 = kk_std_core_show_string_fs__trmc_lift_show_10159(_uniq_xs_10151_0, _brw_x35, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x35, _ctx);
  return _brw_x36;
}
 
// lifted local: string/show, @spec-x10150
// specialized: std/core/list/map, on parameters @uniq-f@10147, using:
// @uniq-f@10147 = std/core/show/show-char

kk_std_core_types__list kk_std_core_show_string_fs__lift_show_10158(kk_std_core_types__list _uniq_xs_10146, kk_context_t* _ctx) { /* (list<char>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10146, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_show_string_fs__lift_show_10159(_uniq_xs_10146, _ctx);
  }
}
 
// Show a string as a string literal

kk_string_t kk_std_core_show_string_fs_show(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_types__list xs_10045;
  kk_std_core_types__list _own_x34 = kk_std_core_string_list(s, _ctx); /*list<char>*/;
  xs_10045 = kk_std_core_show_string_fs__lift_show_10158(_own_x34, _ctx); /*list<string>*/
  kk_string_t _x_x219;
  kk_define_string_literal(static, _s_x220, 1, "\"", _ctx)
  _x_x219 = kk_string_dup(_s_x220, _ctx); /*string*/
  kk_string_t _x_x221;
  kk_string_t _x_x222;
  if (kk_std_core_types__is_Nil(xs_10045, _ctx)) {
    _x_x222 = kk_string_empty(); /*string*/
    goto _match_x223;
  }
  {
    struct kk_std_core_types_Cons* _con_x225 = kk_std_core_types__as_Cons(xs_10045, _ctx);
    kk_box_t _box_x31 = _con_x225->head;
    kk_std_core_types__list _pat_1 = _con_x225->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x31);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10045, _ctx)) {
        kk_datatype_ptr_free(xs_10045, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10045, _ctx);
      }
      _x_x222 = x; /*string*/
      goto _match_x223;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x226 = kk_std_core_types__as_Cons(xs_10045, _ctx);
    kk_box_t _box_x32 = _con_x226->head;
    kk_std_core_types__list _pat_3 = _con_x226->tail;
    struct kk_std_core_types_Cons* _con_x227 = kk_std_core_types__as_Cons(_pat_3, _ctx);
    kk_box_t _box_x33 = _con_x227->head;
    kk_std_core_types__list _pat_4 = _con_x227->tail;
    if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
      kk_string_t x_0 = kk_string_unbox(_box_x32);
      kk_string_t y = kk_string_unbox(_box_x33);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10045, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_string_dup(y, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        kk_datatype_ptr_free(xs_10045, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_string_dup(y, _ctx);
        kk_datatype_ptr_decref(xs_10045, _ctx);
      }
      _x_x222 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
      goto _match_x223;
    }
  }
  {
    kk_vector_t _x_x228 = kk_std_core_vector_unvlist(xs_10045, _ctx); /*vector<978>*/
    _x_x222 = kk_string_join(_x_x228,kk_context()); /*string*/
  }
  _match_x223: ;
  kk_string_t _x_x229;
  kk_define_string_literal(static, _s_x230, 1, "\"", _ctx)
  _x_x229 = kk_string_dup(_s_x230, _ctx); /*string*/
  _x_x221 = kk_std_core_types__lp__plus__plus__rp_(_x_x222, _x_x229, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x219, _x_x221, _ctx);
}

// initialization
void kk_std_core_show__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_vector__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_core_show__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_vector__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
