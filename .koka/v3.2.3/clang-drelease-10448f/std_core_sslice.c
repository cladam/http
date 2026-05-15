// Koka generated module: std/core/sslice, koka version: 3.2.3, platform: 64-bit
#include "std_core_sslice.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2024, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static inline void kk_sslice_start_end_borrowx( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, const uint8_t** sstart, const uint8_t** send, kk_context_t* ctx) {
  kk_ssize_t strlen;
  const uint8_t* s = kk_string_buf_borrow(sslice.str,&strlen,ctx);
  kk_ssize_t slstart = kk_integer_clamp_ssize_t_borrow(sslice.start,ctx);
  kk_ssize_t sllen   = kk_integer_clamp_ssize_t_borrow(sslice.len,ctx);
  *start = s + slstart;
  *end = s + slstart + sllen;
  if (sstart != NULL) *sstart = s;
  if (send != NULL) *send = s + strlen;
  kk_assert_internal(*start >= s && *start <= *end);
  kk_assert_internal(*end >= *start && *end <= s + strlen);
}

static inline void kk_sslice_start_end_borrow( kk_std_core_sslice__sslice sslice, const uint8_t** start, const uint8_t** end, kk_context_t* ctx) {
  kk_sslice_start_end_borrowx(sslice,start,end,NULL,NULL,ctx);
}

kk_integer_t kk_slice_count( kk_std_core_sslice__sslice sslice, kk_context_t* ctx ) {
  // TODO: optimize this by extending kk_string_count
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  kk_ssize_t count = 0;
  while( start < end && *start != 0 ) {
    const uint8_t* next = kk_utf8_next(start);
    count++;
    start = next;
  }
  kk_std_core_sslice__sslice_drop(sslice,ctx);
  return kk_integer_from_ssize_t(count,ctx);
}

kk_string_t kk_slice_to_string( kk_std_core_sslice__sslice  sslice, kk_context_t* ctx ) {
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(sslice, &start, &end, ctx);
  // is it the full string?
  if (kk_integer_is_zero_borrow(sslice.start) &&
      kk_integer_eq_borrow(sslice.len,kk_integer_from_ssize_t(kk_string_len_borrow(sslice.str,ctx),ctx),ctx)) {
    // TODO: drop sslice and dup sslice.str?
    return sslice.str;
  }
  else {
    // if not, we copy len bytes
    kk_string_t s = kk_string_alloc_dupn_valid_utf8(kk_integer_clamp_ssize_t_borrow(sslice.len,ctx), start, ctx);
    kk_std_core_sslice__sslice_drop(sslice,ctx);
    return s;
  }
}

kk_std_core_sslice__sslice kk_slice_first( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* next = (slen > 0 ? kk_utf8_next(s) : s);
  return kk_std_core_sslice__new_Sslice(str, kk_integer_zero, kk_integer_from_ptrdiff_t(next - s,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_last( kk_string_t str, kk_context_t* ctx ) {
  kk_ssize_t slen;
  const uint8_t* s = kk_string_buf_borrow(str,&slen,ctx);
  const uint8_t* end = s + slen;
  const uint8_t* prev = (s==end ? s : kk_utf8_prev(end));
  return kk_std_core_sslice__new_Sslice(str, kk_integer_from_ptrdiff_t(prev - s,ctx), kk_integer_from_ptrdiff_t(end - prev,ctx), ctx);
}

kk_std_core_sslice__sslice kk_slice_between( struct kk_std_core_sslice_Sslice slice1, struct kk_std_core_sslice_Sslice slice2, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow( slice1.str, NULL, ctx );
  const uint8_t* s2 = kk_string_buf_borrow( slice2.str, NULL, ctx );
  if (s1 != s2) {
    kk_info_message("between: not equal slices: %p vs. %p\n", s1, s2);
    return kk_std_core_sslice__new_Sslice(kk_string_empty(), kk_integer_zero, kk_integer_min_one, ctx); // invalid slice
  }

  kk_integer_t start;
  kk_integer_t len;
  if (kk_integer_lte_borrow(slice1.start,slice2.start,ctx)) {
    start = kk_integer_dup(slice1.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice2.start,ctx),kk_integer_dup(slice1.start,ctx),ctx);
  }
  else  {
    start = kk_integer_dup(slice2.start,ctx);
    len   = kk_integer_sub(kk_integer_dup(slice1.start,ctx),kk_integer_dup(slice2.start,ctx),ctx);
  }
  return kk_std_core_sslice__new_Sslice(slice1.str, start, len, ctx);
}

kk_std_core_types__maybe kk_slice_next( struct kk_std_core_sslice_Sslice slice, kk_context_t* ctx ) {
  if (!kk_integer_is_pos_borrow(slice.len,ctx)) {
    kk_std_core_sslice__sslice_drop(slice,ctx);
    return kk_std_core_types__new_Nothing(ctx);
  }
  const uint8_t* start;
  const uint8_t* end;
  kk_sslice_start_end_borrow(slice, &start, &end, ctx);
  kk_ssize_t clen;
  const kk_char_t c = kk_utf8_read(start,&clen);
  kk_assert_internal(clen > 0 && clen <= kk_integer_clamp_ssize_t_borrow(slice.len,ctx));
  kk_integer_t iclen = kk_integer_min(kk_integer_from_ssize_t(clen,ctx),kk_integer_dup(slice.len,ctx),ctx);
  // TODO: specialize type to avoid boxing
  // note: don't drop slice as we take over all fields
  kk_integer_t istart = kk_integer_add(slice.start,kk_integer_dup(iclen,ctx),ctx);
  kk_integer_t ilen   = kk_integer_sub(slice.len,iclen,ctx);
  kk_std_core_sslice__sslice snext = kk_std_core_sslice__new_Sslice(slice.str, istart, ilen, ctx);
  kk_std_core_types__tuple2 res = kk_std_core_types__new_Tuple2( kk_char_box(c,ctx), kk_std_core_sslice__sslice_box(snext,ctx), ctx);
  return kk_std_core_types__new_Just( kk_std_core_types__tuple2_box(res,ctx), ctx );
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_extend_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  kk_ssize_t cnt = kk_integer_clamp_ssize_t_borrow(count,ctx);
  if (cnt==0 || (!kk_integer_is_pos_borrow(slice.len,ctx) && cnt<0)) return slice;
  const uint8_t* s0;
  const uint8_t* s1;
  kk_sslice_start_end_borrow(slice,&s0,&s1,ctx);
  const uint8_t* t  = s1;
  if (cnt >= 0) { // Positive
    while (cnt > 0 && *t != 0) { // Don't extend if already at the end of the c string
      t = kk_utf8_next(t);
      cnt--;
    }
  }
  else {  // cnt < 0
    const uint8_t* sstart = s0 - kk_integer_clamp_ssize_t_borrow(slice.start,ctx);
    do {
      t = kk_utf8_prev(t);
      cnt++;
    } while (cnt < 0 && t > sstart);
  }
  if (t == s1) return slice;  // length is unchanged
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, slice.start, kk_integer_from_ptrdiff_t(t < s0 ? 0 : (t - s0),ctx), ctx);
}

/* Borrow count */
struct kk_std_core_sslice_Sslice kk_slice_advance_borrow( struct kk_std_core_sslice_Sslice slice, kk_integer_t count, kk_context_t* ctx ) {
  const kk_ssize_t cnt0 = kk_integer_clamp_ssize_t_borrow(count,ctx);
  kk_ssize_t cnt = cnt0;
  if (cnt==0) return slice;
  const uint8_t* sstart;
  const uint8_t* s0;
  const uint8_t* s1;
  const uint8_t* send;
  kk_sslice_start_end_borrowx(slice,&s0,&s1,&sstart,&send,ctx);
  // advance the start
  const uint8_t* t0  = s0;
  if (cnt >= 0) {
    while (cnt > 0 && t0 < send) {
      t0 = kk_utf8_next(t0);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t0 > sstart) {
      t0 = kk_utf8_prev(t0);
      cnt++;
    }
  }
  if (t0 == s0 && cnt0 > 0) return slice;  // start is unchanged
  // "t0" points to the new start, now advance the end by the same amount of codepoints
  const uint8_t* t1 = s1;
  cnt = cnt0;
  if (cnt >= 0) {
    while (cnt > 0 && t1 < send) {
      t1 = kk_utf8_next(t1);
      cnt--;
    }
  }
  else {  // cnt < 0
    while (cnt < 0 && t1 > sstart) {
      t1 = kk_utf8_prev(t1);
      cnt++;
    }
  }
  // t1 points to the new end
  kk_assert_internal(t1 >= t0);
  const kk_ssize_t in_len = kk_integer_clamp_ssize_t_borrow(slice.len, ctx);
  kk_ssize_t new_len = (t1-t0);
  // kk_info_message("Here %d %d %d t: %d %d s: %d %d, st: %d %d\n", in_len, cnt0, new_len, t1, t0, s1, s0, sstart, send);
  kk_assert_internal(t1 <= send && t0 >= sstart);
  kk_integer_drop(slice.start,ctx);
  kk_integer_drop(slice.len,ctx);
  return kk_std_core_sslice__new_Sslice(slice.str, kk_integer_from_ptrdiff_t(t0 - sstart,ctx),
                                          kk_integer_from_ptrdiff_t(new_len, ctx), ctx);
}

/* Borrow iupto */
struct kk_std_core_sslice_Sslice kk_slice_common_prefix_borrow( kk_string_t str1, kk_string_t str2, kk_integer_t iupto, kk_context_t* ctx ) {
  const uint8_t* s1 = kk_string_buf_borrow(str1,NULL,ctx);
  const uint8_t* s2 = kk_string_buf_borrow(str2,NULL,ctx);
  kk_ssize_t upto = kk_integer_clamp_ssize_t_borrow(iupto,ctx);
  kk_ssize_t count;
  for(count = 0; count < upto && *s1 != 0 && *s2 != 0; count++, s1++, s2++ ) {
    if (*s1 != *s2) break;
  }
  kk_string_drop(str2,ctx);
  return kk_std_core_sslice__new_Sslice(str1, kk_integer_zero, kk_integer_from_ssize_t(count,ctx), ctx);
}


kk_std_core_sslice__sslice kk_std_core_sslice_sslice_fs__copy(kk_std_core_sslice__sslice _this, kk_std_core_types__optional str, kk_std_core_types__optional start, kk_std_core_types__optional len, kk_context_t* _ctx) { /* (sslice, str : ? string, start : ? int, len : ? int) -> sslice */ 
  kk_string_t _x_x202;
  if (kk_std_core_types__is_Optional(str, _ctx)) {
    kk_box_t _box_x0 = str._cons._Optional.value;
    kk_string_t _uniq_str_139 = kk_string_unbox(_box_x0);
    kk_string_dup(_uniq_str_139, _ctx);
    kk_std_core_types__optional_drop(str, _ctx);
    _x_x202 = _uniq_str_139; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(str, _ctx);
    {
      kk_string_t _x = _this.str;
      kk_string_dup(_x, _ctx);
      _x_x202 = _x; /*string*/
    }
  }
  kk_integer_t _x_x203;
  if (kk_std_core_types__is_Optional(start, _ctx)) {
    kk_box_t _box_x1 = start._cons._Optional.value;
    kk_integer_t _uniq_start_147 = kk_integer_unbox(_box_x1, _ctx);
    kk_integer_dup(_uniq_start_147, _ctx);
    kk_std_core_types__optional_drop(start, _ctx);
    _x_x203 = _uniq_start_147; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(start, _ctx);
    {
      kk_integer_t _x_0 = _this.start;
      kk_integer_dup(_x_0, _ctx);
      _x_x203 = _x_0; /*int*/
    }
  }
  kk_integer_t _x_x204;
  if (kk_std_core_types__is_Optional(len, _ctx)) {
    kk_box_t _box_x2 = len._cons._Optional.value;
    kk_integer_t _uniq_len_155 = kk_integer_unbox(_box_x2, _ctx);
    kk_integer_dup(_uniq_len_155, _ctx);
    kk_std_core_types__optional_drop(len, _ctx);
    kk_std_core_sslice__sslice_drop(_this, _ctx);
    _x_x204 = _uniq_len_155; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(len, _ctx);
    {
      kk_integer_t _x_1 = _this.len;
      kk_integer_dup(_x_1, _ctx);
      kk_std_core_sslice__sslice_drop(_this, _ctx);
      _x_x204 = _x_1; /*int*/
    }
  }
  return kk_std_core_sslice__new_Sslice(_x_x202, _x_x203, _x_x204, _ctx);
}
 
// O(n). Copy the `slice` argument into a fresh string.
// Takes O(1) time if the slice covers the entire string.

kk_string_t kk_std_core_sslice_string(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> string */ 
  return kk_slice_to_string(slice_0,kk_context());
}
 
// Equality based on contents of the slice
// O(`n`+`m`) where `n` and `m` are the lengths of the two strings

bool kk_std_core_sslice__lp__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    kk_integer_dup(len1, _ctx);
    kk_integer_dup(len2, _ctx);
    kk_string_dup(s1, _ctx);
    kk_string_dup(s2, _ctx);
    kk_integer_dup(start1, _ctx);
    kk_integer_dup(start2, _ctx);
    bool _match_x197 = kk_box_eq((kk_string_box(s1)),(kk_string_box(s2))); /*bool*/;
    if (_match_x197) {
      bool _match_x198;
      bool _brw_x201 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(start2, _ctx);
      _match_x198 = _brw_x201; /*bool*/
      if (_match_x198) {
        bool _match_x199;
        bool _brw_x200 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
        kk_integer_drop(len1, _ctx);
        kk_integer_drop(len2, _ctx);
        _match_x199 = _brw_x200; /*bool*/
        if (_match_x199) {
          kk_std_core_sslice__sslice_drop(slice2, _ctx);
          kk_std_core_sslice__sslice_drop(slice1, _ctx);
          return true;
        }
        {
          kk_string_t _x_x205 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
          kk_string_t _x_x206 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
          return kk_string_is_eq(_x_x205,_x_x206,kk_context());
        }
      }
      {
        kk_integer_drop(len2, _ctx);
        kk_integer_drop(len1, _ctx);
        kk_string_t _x_x207 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
        kk_string_t _x_x208 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
        return kk_string_is_eq(_x_x207,_x_x208,kk_context());
      }
    }
    {
      kk_integer_drop(start2, _ctx);
      kk_integer_drop(start1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      kk_string_t _x_x209 = kk_std_core_sslice_string(slice1, _ctx); /*string*/
      kk_string_t _x_x210 = kk_std_core_sslice_string(slice2, _ctx); /*string*/
      return kk_string_is_eq(_x_x209,_x_x210,kk_context());
    }
  }
}
 
// Equality of slices at the same offset and length on an equal string
// (The strings do not have to be referentially identical though)

bool kk_std_core_sslice__lp__eq__eq__eq__rp_(kk_std_core_sslice__sslice slice1, kk_std_core_sslice__sslice slice2, kk_context_t* _ctx) { /* (slice1 : sslice, slice2 : sslice) -> bool */ 
  {
    kk_string_t s1 = slice1.str;
    kk_integer_t start1 = slice1.start;
    kk_integer_t len1 = slice1.len;
    kk_string_t s2 = slice2.str;
    kk_integer_t start2 = slice2.start;
    kk_integer_t len2 = slice2.len;
    bool _match_x193;
    bool _brw_x196 = kk_integer_eq_borrow(start1,start2,kk_context()); /*bool*/;
    kk_integer_drop(start1, _ctx);
    kk_integer_drop(start2, _ctx);
    _match_x193 = _brw_x196; /*bool*/
    if (_match_x193) {
      bool _match_x194;
      bool _brw_x195 = kk_integer_eq_borrow(len1,len2,kk_context()); /*bool*/;
      kk_integer_drop(len1, _ctx);
      kk_integer_drop(len2, _ctx);
      _match_x194 = _brw_x195; /*bool*/
      if (_match_x194) {
        return kk_string_is_eq(s1,s2,kk_context());
      }
      {
        kk_string_drop(s2, _ctx);
        kk_string_drop(s1, _ctx);
        return false;
      }
    }
    {
      kk_string_drop(s2, _ctx);
      kk_string_drop(s1, _ctx);
      kk_integer_drop(len2, _ctx);
      kk_integer_drop(len1, _ctx);
      return false;
    }
  }
}
 
// O(n). Return the number of characters in a string slice

kk_integer_t kk_std_core_sslice_count(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> int */ 
  return kk_slice_count(slice_0,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_first1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_first(s,kk_context());
}

kk_std_core_sslice__sslice kk_std_core_sslice_last1(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> sslice */ 
  return kk_slice_last(s,kk_context());
}
 
// O(`count`). Advance the start position of a string slice by `count` characters
// up to the end of the string.
// A negative `count` advances the start position backwards upto the first position
// in a string.
// Maintains the character count of the original slice upto the end of the string.
// For example:
//
// * `"abc".first.advance(1).string == "b"`,
// * `"abc".first.advance(3).string == ""`,
// * `"abc".last.advance(-1).string == "b"`.
//

kk_std_core_sslice__sslice kk_std_core_sslice_advance(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_advance_borrow(slice_0,count_0,kk_context());
}
 
// O(`count`). Extend a string slice by `count` characters up to the end of the string.
// A negative `count` shrinks the slice up to the empty slice.
// For example:
//
// * `"abc".first.extend(1).string == "ab"`
// * `"abc".last.extend(-1).string == ""`
//

kk_std_core_sslice__sslice kk_std_core_sslice_extend(kk_std_core_sslice__sslice slice_0, kk_integer_t count_0, kk_context_t* _ctx) { /* (slice : sslice, count : int) -> sslice */ 
  return kk_slice_extend_borrow(slice_0,count_0,kk_context());
}
 
// O(`n`). The first `n` (default = `1`) characters in a string.

kk_std_core_sslice__sslice kk_std_core_sslice_first(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  bool _match_x188;
  kk_integer_t _brw_x191;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x7 = n._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x7, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    _brw_x191 = _uniq_n_414; /*int*/
  }
  else {
    _brw_x191 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x192 = kk_integer_eq_borrow(_brw_x191,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x191, _ctx);
  _match_x188 = _brw_x192; /*bool*/
  if (_match_x188) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_integer_t _brw_x189;
    kk_integer_t _x_x211;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x8 = n._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x8, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x211 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x211 = kk_integer_from_small(1); /*int*/
    }
    _brw_x189 = kk_integer_add_small_const(_x_x211, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x190 = kk_std_core_sslice_extend(slice_0, _brw_x189, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x189, _ctx);
    return _brw_x190;
  }
}
 
// O(`n`). The last `n` (default = `1`) characters in a string

kk_std_core_sslice__sslice kk_std_core_sslice_last(kk_string_t s, kk_std_core_types__optional n, kk_context_t* _ctx) { /* (s : string, n : ? int) -> sslice */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_last1(s, _ctx); /*sslice/sslice*/;
  bool _match_x180;
  kk_integer_t _brw_x186;
  if (kk_std_core_types__is_Optional(n, _ctx)) {
    kk_box_t _box_x9 = n._cons._Optional.value;
    kk_integer_t _uniq_n_450 = kk_integer_unbox(_box_x9, _ctx);
    kk_integer_dup(_uniq_n_450, _ctx);
    _brw_x186 = _uniq_n_450; /*int*/
  }
  else {
    _brw_x186 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x187 = kk_integer_eq_borrow(_brw_x186,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x186, _ctx);
  _match_x180 = _brw_x187; /*bool*/
  if (_match_x180) {
    kk_std_core_types__optional_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _own_x182;
    kk_integer_t _brw_x183;
    kk_integer_t _x_x212;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x10 = n._cons._Optional.value;
      kk_integer_t _uniq_n_450_0 = kk_integer_unbox(_box_x10, _ctx);
      kk_integer_dup(_uniq_n_450_0, _ctx);
      _x_x212 = _uniq_n_450_0; /*int*/
    }
    else {
      _x_x212 = kk_integer_from_small(1); /*int*/
    }
    _brw_x183 = kk_integer_sub((kk_integer_from_small(1)),_x_x212,kk_context()); /*int*/
    kk_std_core_sslice__sslice _brw_x184 = kk_std_core_sslice_advance(slice_0, _brw_x183, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x183, _ctx);
    _own_x182 = _brw_x184; /*sslice/sslice*/
    kk_integer_t _brw_x181;
    kk_integer_t _x_x213;
    if (kk_std_core_types__is_Optional(n, _ctx)) {
      kk_box_t _box_x11 = n._cons._Optional.value;
      kk_integer_t _uniq_n_450_1 = kk_integer_unbox(_box_x11, _ctx);
      kk_integer_dup(_uniq_n_450_1, _ctx);
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x213 = _uniq_n_450_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(n, _ctx);
      _x_x213 = kk_integer_from_small(1); /*int*/
    }
    _brw_x181 = kk_integer_add_small_const(_x_x213, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x185 = kk_std_core_sslice_extend(_own_x182, _brw_x181, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x181, _ctx);
    return _brw_x185;
  }
}
 
// O(1). Return the string slice from the end of `slice` argument
// to the end of the string.

kk_std_core_sslice__sslice kk_std_core_sslice_after(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> sslice */ 
  {
    kk_string_t s = slice_0.str;
    kk_integer_t start = slice_0.start;
    kk_integer_t len = slice_0.len;
    kk_integer_t x_0_10013;
    kk_string_t _x_x214 = kk_string_dup(s, _ctx); /*string*/
    x_0_10013 = kk_string_len_int(_x_x214,kk_context()); /*int*/
    kk_integer_t y_0_10014;
    kk_integer_t _x_x215 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x216 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10014 = kk_integer_add(_x_x215,_x_x216,kk_context()); /*int*/
    kk_integer_t _x_x217 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x218 = kk_integer_sub(x_0_10013,y_0_10014,kk_context()); /*int*/
    return kk_std_core_sslice__new_Sslice(s, _x_x217, _x_x218, _ctx);
  }
}
 
// Convert the first character of a string to uppercase.

kk_string_t kk_std_core_sslice_capitalize(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_1;
  kk_string_t _x_x219 = kk_string_dup(s, _ctx); /*string*/
  slice_0_1 = kk_std_core_sslice_first1(_x_x219, _ctx); /*sslice/sslice*/
  kk_std_core_sslice__sslice slice_0_0_10021;
  bool _match_x173;
  kk_integer_t _brw_x178;
  kk_std_core_types__optional _match_x177 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x177, _ctx)) {
    kk_box_t _box_x12 = _match_x177._cons._Optional.value;
    kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x12, _ctx);
    kk_integer_dup(_uniq_n_414_0, _ctx);
    kk_std_core_types__optional_drop(_match_x177, _ctx);
    _brw_x178 = _uniq_n_414_0; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x177, _ctx);
    _brw_x178 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x179 = kk_integer_eq_borrow(_brw_x178,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x178, _ctx);
  _match_x173 = _brw_x179; /*bool*/
  if (_match_x173) {
    slice_0_0_10021 = slice_0_1; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x175;
    kk_integer_t _x_x220;
    kk_std_core_types__optional _match_x174 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x174, _ctx)) {
      kk_box_t _box_x13 = _match_x174._cons._Optional.value;
      kk_integer_t _uniq_n_414_0_0 = kk_integer_unbox(_box_x13, _ctx);
      kk_integer_dup(_uniq_n_414_0_0, _ctx);
      kk_std_core_types__optional_drop(_match_x174, _ctx);
      _x_x220 = _uniq_n_414_0_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x174, _ctx);
      _x_x220 = kk_integer_from_small(1); /*int*/
    }
    _brw_x175 = kk_integer_add_small_const(_x_x220, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x176 = kk_std_core_sslice_extend(slice_0_1, _brw_x175, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x175, _ctx);
    slice_0_0_10021 = _brw_x176; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_string_t _x_x221;
  kk_string_t _x_x222;
  kk_std_core_sslice__sslice _x_x223;
  bool _match_x166;
  kk_integer_t _brw_x171;
  kk_std_core_types__optional _match_x170 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x170, _ctx)) {
    kk_box_t _box_x14 = _match_x170._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x14, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    kk_std_core_types__optional_drop(_match_x170, _ctx);
    _brw_x171 = _uniq_n_414; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x170, _ctx);
    _brw_x171 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x172 = kk_integer_eq_borrow(_brw_x171,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x171, _ctx);
  _match_x166 = _brw_x172; /*bool*/
  if (_match_x166) {
    _x_x223 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x168;
    kk_integer_t _x_x224;
    kk_std_core_types__optional _match_x167 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x167, _ctx)) {
      kk_box_t _box_x15 = _match_x167._cons._Optional.value;
      kk_integer_t _uniq_n_414_1 = kk_integer_unbox(_box_x15, _ctx);
      kk_integer_dup(_uniq_n_414_1, _ctx);
      kk_std_core_types__optional_drop(_match_x167, _ctx);
      _x_x224 = _uniq_n_414_1; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x167, _ctx);
      _x_x224 = kk_integer_from_small(1); /*int*/
    }
    _brw_x168 = kk_integer_add_small_const(_x_x224, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x169 = kk_std_core_sslice_extend(slice_0, _brw_x168, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x168, _ctx);
    _x_x223 = _brw_x169; /*sslice/sslice*/
  }
  _x_x222 = kk_std_core_sslice_string(_x_x223, _ctx); /*string*/
  _x_x221 = kk_std_core_string_to_upper(_x_x222, _ctx); /*string*/
  kk_string_t _x_x225;
  kk_std_core_sslice__sslice _x_x226;
  {
    kk_string_t s_1 = slice_0_0_10021.str;
    kk_integer_t start = slice_0_0_10021.start;
    kk_integer_t len = slice_0_0_10021.len;
    kk_integer_t x_1_10028;
    kk_string_t _x_x227 = kk_string_dup(s_1, _ctx); /*string*/
    x_1_10028 = kk_string_len_int(_x_x227,kk_context()); /*int*/
    kk_integer_t y_1_10029;
    kk_integer_t _x_x228 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x229 = kk_integer_dup(len, _ctx); /*int*/
    y_1_10029 = kk_integer_add(_x_x228,_x_x229,kk_context()); /*int*/
    kk_integer_t _x_x230 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x231 = kk_integer_sub(x_1_10028,y_1_10029,kk_context()); /*int*/
    _x_x226 = kk_std_core_sslice__new_Sslice(s_1, _x_x230, _x_x231, _ctx); /*sslice/sslice*/
  }
  _x_x225 = kk_std_core_sslice_string(_x_x226, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x221, _x_x225, _ctx);
}
 
// An empty slice

kk_std_core_sslice__sslice kk_std_core_sslice_empty;
 
// An invalid slice

kk_std_core_sslice__sslice kk_std_core_sslice_invalid;
 
// Return the first character of a string as a string (or the empty string)

kk_string_t kk_std_core_sslice_head(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x238;
  bool _match_x153;
  kk_integer_t _brw_x158;
  kk_std_core_types__optional _match_x157 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x157, _ctx)) {
    kk_box_t _box_x16 = _match_x157._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x16, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    kk_std_core_types__optional_drop(_match_x157, _ctx);
    _brw_x158 = _uniq_n_414; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x157, _ctx);
    _brw_x158 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x159 = kk_integer_eq_borrow(_brw_x158,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x158, _ctx);
  _match_x153 = _brw_x159; /*bool*/
  if (_match_x153) {
    _x_x238 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x155;
    kk_integer_t _x_x239;
    kk_std_core_types__optional _match_x154 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x154, _ctx)) {
      kk_box_t _box_x17 = _match_x154._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x17, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(_match_x154, _ctx);
      _x_x239 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x154, _ctx);
      _x_x239 = kk_integer_from_small(1); /*int*/
    }
    _brw_x155 = kk_integer_add_small_const(_x_x239, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x156 = kk_std_core_sslice_extend(slice_0, _brw_x155, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x155, _ctx);
    _x_x238 = _brw_x156; /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x238, _ctx);
}
 
// Return the tail of a string (or the empty string)

kk_string_t kk_std_core_sslice_tail(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> string */ 
  kk_std_core_sslice__sslice slice_0_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice slice_0_10042;
  bool _match_x146;
  kk_integer_t _brw_x151;
  kk_std_core_types__optional _match_x150 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x150, _ctx)) {
    kk_box_t _box_x18 = _match_x150._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x18, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    kk_std_core_types__optional_drop(_match_x150, _ctx);
    _brw_x151 = _uniq_n_414; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x150, _ctx);
    _brw_x151 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x152 = kk_integer_eq_borrow(_brw_x151,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x151, _ctx);
  _match_x146 = _brw_x152; /*bool*/
  if (_match_x146) {
    slice_0_10042 = slice_0_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x148;
    kk_integer_t _x_x240;
    kk_std_core_types__optional _match_x147 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x147, _ctx)) {
      kk_box_t _box_x19 = _match_x147._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x19, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(_match_x147, _ctx);
      _x_x240 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x147, _ctx);
      _x_x240 = kk_integer_from_small(1); /*int*/
    }
    _brw_x148 = kk_integer_add_small_const(_x_x240, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x149 = kk_std_core_sslice_extend(slice_0_0, _brw_x148, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x148, _ctx);
    slice_0_10042 = _brw_x149; /*sslice/sslice*/
  }
  kk_std_core_sslice__sslice _x_x241;
  {
    kk_string_t s_0 = slice_0_10042.str;
    kk_integer_t start = slice_0_10042.start;
    kk_integer_t len = slice_0_10042.len;
    kk_integer_t x_0_10049;
    kk_string_t _x_x242 = kk_string_dup(s_0, _ctx); /*string*/
    x_0_10049 = kk_string_len_int(_x_x242,kk_context()); /*int*/
    kk_integer_t y_0_10050;
    kk_integer_t _x_x243 = kk_integer_dup(start, _ctx); /*int*/
    kk_integer_t _x_x244 = kk_integer_dup(len, _ctx); /*int*/
    y_0_10050 = kk_integer_add(_x_x243,_x_x244,kk_context()); /*int*/
    kk_integer_t _x_x245 = kk_integer_add(start,len,kk_context()); /*int*/
    kk_integer_t _x_x246 = kk_integer_sub(x_0_10049,y_0_10050,kk_context()); /*int*/
    _x_x241 = kk_std_core_sslice__new_Sslice(s_0, _x_x245, _x_x246, _ctx); /*sslice/sslice*/
  }
  return kk_std_core_sslice_string(_x_x241, _ctx);
}
 
// Return the common prefix of two strings (upto `upto` characters (default is minimum length of the two strings))

kk_std_core_sslice__sslice kk_std_core_sslice_common_prefix(kk_string_t s, kk_string_t t, kk_std_core_types__optional upto, kk_context_t* _ctx) { /* (s : string, t : string, upto : ? int) -> sslice */ 
  kk_integer_t _brw_x144;
  if (kk_std_core_types__is_Optional(upto, _ctx)) {
    kk_box_t _box_x20 = upto._cons._Optional.value;
    kk_integer_t _uniq_upto_696 = kk_integer_unbox(_box_x20, _ctx);
    _brw_x144 = kk_integer_dup(_uniq_upto_696, _ctx); /*int*/
  }
  else {
    _brw_x144 = kk_integer_from_small(-1); /*int*/
  }
  kk_std_core_sslice__sslice _brw_x145 = kk_slice_common_prefix_borrow(s,t,_brw_x144,kk_context()); /*sslice/sslice*/;
  kk_integer_drop(_brw_x144, _ctx);
  return _brw_x145;
}
 
// If the slice is not empty,
// return the first character, and a new slice that is advanced by 1.

kk_std_core_types__maybe kk_std_core_sslice_next(kk_std_core_sslice__sslice slice_0, kk_context_t* _ctx) { /* (slice : sslice) -> maybe<(char, sslice)> */ 
  return kk_slice_next(slice_0,kk_context());
}
 
// monadic lift

kk_unit_t kk_std_core_sslice_slice_fs__mlift_foreach_10228(kk_function_t action, kk_std_core_sslice__sslice rest, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (action : (c : char) -> e (), rest : sslice, wild_ : ()) -> e () */ 
  kk_std_core_sslice_slice_fs_foreach(rest, action, _ctx); return kk_Unit;
}
 
// Apply a function for each character in a string slice.


// lift anonymous function
struct kk_std_core_sslice_slice_fs_foreach_fun251__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_sslice__sslice rest_0;
};
static kk_box_t kk_std_core_sslice_slice_fs_foreach_fun251(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_slice_fs_new_foreach_fun251(kk_function_t action_0, kk_std_core_sslice__sslice rest_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_slice_fs_foreach_fun251__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_slice_fs_foreach_fun251__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_slice_fs_foreach_fun251, kk_context());
  _self->action_0 = action_0;
  _self->rest_0 = rest_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_slice_fs_foreach_fun251(kk_function_t _fself, kk_box_t _b_x25, kk_context_t* _ctx) {
  struct kk_std_core_sslice_slice_fs_foreach_fun251__t* _self = kk_function_as(struct kk_std_core_sslice_slice_fs_foreach_fun251__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 780 () */
  kk_std_core_sslice__sslice rest_0 = _self->rest_0; /* sslice/sslice */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_sslice__sslice_dup(rest_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_27 = kk_Unit;
  kk_unit_unbox(_b_x25);
  kk_unit_t _x_x252 = kk_Unit;
  kk_std_core_sslice_slice_fs__mlift_foreach_10228(action_0, rest_0, wild___0_27, _ctx);
  return kk_unit_box(_x_x252);
}

kk_unit_t kk_std_core_sslice_slice_fs_foreach(kk_std_core_sslice__sslice slice_0, kk_function_t action_0, kk_context_t* _ctx) { /* forall<e> (slice : sslice, action : (c : char) -> e ()) -> e () */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x142 = kk_std_core_sslice_next(slice_0, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x142, _ctx)) {
    kk_function_drop(action_0, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_box_t _box_x21 = _match_x142._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x21, KK_BORROWED, _ctx);
    kk_box_t _box_x22 = _pat_1.fst;
    kk_box_t _box_x23 = _pat_1.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x23, KK_BORROWED, _ctx);
    kk_char_t c = kk_char_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x142, _ctx);
    kk_unit_t x_10234 = kk_Unit;
    kk_function_t _x_x249 = kk_function_dup(action_0, _ctx); /*(c : char) -> 780 ()*/
    kk_function_call(kk_unit_t, (kk_function_t, kk_char_t, kk_context_t*), _x_x249, (_x_x249, c, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x250 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_slice_fs_new_foreach_fun251(action_0, rest_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x250); return kk_Unit;
    }
    { // tailcall
      slice_0 = rest_0;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_unit_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10229(kk_ref_t cnt, kk_integer_t _y_x10209, kk_context_t* _ctx) { /* forall<h,e> (cnt : local-var<h,int>, int) -> <local<h>|e> () */ 
  kk_integer_t _b_x29_31 = kk_integer_add_small_const(_y_x10209, 1, _ctx); /*int*/;
  kk_unit_t _brw_x141 = kk_Unit;
  kk_ref_set_borrow(cnt,(kk_integer_box(_b_x29_31, _ctx)),kk_context());
  kk_ref_drop(cnt, _ctx);
  _brw_x141; return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10230(kk_std_core_sslice__sslice _uniq_rest_10193, kk_ref_t cnt_0, kk_function_t pred, kk_unit_t _c_x10211, kk_context_t* _ctx) { /* forall<h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, ()) -> () */ 
  kk_std_core_sslice_pred_fs__lift_count_10200(cnt_0, pred, _uniq_rest_10193, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260__t {
  struct kk_function_s _base;
  kk_ref_t cnt_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_lift_count_10200_10231_fun260(kk_ref_t cnt_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260, kk_context());
  _self->cnt_1 = cnt_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun260__t*, _fself, _ctx);
  kk_ref_t cnt_1 = _self->cnt_1; /* local-var<920,int> */
  kk_drop_match(_self, {kk_ref_dup(cnt_1, _ctx);}, {}, _ctx)
  kk_unit_t _x_x261 = kk_Unit;
  kk_integer_t _x_x262 = kk_integer_unbox(_b_x37, _ctx); /*int*/
  kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10229(cnt_1, _x_x262, _ctx);
  return kk_unit_box(_x_x261);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10193_0;
  kk_ref_t cnt_1;
  kk_function_t pred_0;
};
static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_mlift_lift_count_10200_10231_fun265(kk_std_core_sslice__sslice _uniq_rest_10193_0, kk_ref_t cnt_1, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265, kk_context());
  _self->_uniq_rest_10193_0 = _uniq_rest_10193_0;
  _self->cnt_1 = cnt_1;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265(kk_function_t _fself, kk_box_t _b_x41, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231_fun265__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10193_0 = _self->_uniq_rest_10193_0; /* sslice/sslice */
  kk_ref_t cnt_1 = _self->cnt_1; /* local-var<920,int> */
  kk_function_t pred_0 = _self->pred_0; /* (char) -> 926 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10193_0, _ctx);kk_ref_dup(cnt_1, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10211_0_43 = kk_Unit;
  kk_unit_unbox(_b_x41);
  kk_unit_t _x_x266 = kk_Unit;
  kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10230(_uniq_rest_10193_0, cnt_1, pred_0, _c_x10211_0_43, _ctx);
  return kk_unit_box(_x_x266);
}

kk_unit_t kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231(kk_std_core_sslice__sslice _uniq_rest_10193_0, kk_ref_t cnt_1, kk_function_t pred_0, bool _y_x10208, kk_context_t* _ctx) { /* forall<h,e> (sslice, cnt : local-var<h,int>, pred : (char) -> e bool, bool) -> <local<h>|e> () */ 
  kk_unit_t x_10237 = kk_Unit;
  if (_y_x10208) {
    kk_integer_t x_0_10239;
    kk_box_t _x_x256;
    kk_ref_t _x_x257 = kk_ref_dup(cnt_1, _ctx); /*local-var<920,int>*/
    _x_x256 = kk_ref_get(_x_x257,kk_context()); /*298*/
    x_0_10239 = kk_integer_unbox(_x_x256, _ctx); /*int*/
    if (kk_yielding(kk_context())) {
      kk_integer_drop(x_0_10239, _ctx);
      kk_box_t _x_x258;
      kk_function_t _x_x259;
      kk_ref_dup(cnt_1, _ctx);
      _x_x259 = kk_std_core_sslice_pred_fs__new_mlift_lift_count_10200_10231_fun260(cnt_1, _ctx); /*(2418) -> 2420 2419*/
      _x_x258 = kk_std_core_hnd_yield_extend(_x_x259, _ctx); /*2419*/
      kk_unit_unbox(_x_x258);
    }
    else {
      kk_ref_t _x_x263 = kk_ref_dup(cnt_1, _ctx); /*local-var<920,int>*/
      kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10229(_x_x263, x_0_10239, _ctx);
    }
  }
  else {
    
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x264 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_mlift_lift_count_10200_10231_fun265(_uniq_rest_10193_0, cnt_1, pred_0, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x264); return kk_Unit;
  }
  {
    kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10230(_uniq_rest_10193_0, cnt_1, pred_0, x_10237, _ctx); return kk_Unit;
  }
}
 
// lifted local: pred/count, @spec-x10198
// specialized: std/core/sslice/#slice/foreach, on parameters @uniq-action@10188, using:
// @uniq-action@10188 = fn<<(local :: H -> X)<(h :: H)>|(e :: E)>>(c: char){
//   match ((std/core/hnd/@mask-builtin<bool,(e :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>>((fn<(e :: E)>(){
//     (pred(c));
//   })))) {
//     ((std/core/types/True() : bool ) as @pat: bool)
//        -> std/core/types/local-set<int,(e :: E),(h :: H)>(cnt, (std/core/types/@open<(total :: E),<(local :: H -> X)<(h :: H)>|(e :: E)>,(x : int, y : int) -> int,(x : int, y : int) -> <(local :: H -> X)<(h :: H)>|(e :: E)> int>((fn(x: int, y: int){
//           (std/core/int/int-add(x, y));
//         }))((std/core/types/local-get<int,(h :: H),(e :: E)>(cnt, (std/core/types/@Hnodiv<(h :: H),int,(e :: E)>))), 1)));
//     ((@skip std/core/types/False() : bool ) as @pat@0: bool)
//        -> std/core/types/Unit;
//   };
// }


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10200_fun269__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10193_1;
  kk_ref_t cnt_2;
  kk_function_t pred_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun269(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10200_fun269(kk_std_core_sslice__sslice _uniq_rest_10193_1, kk_ref_t cnt_2, kk_function_t pred_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun269__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun269__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10200_fun269, kk_context());
  _self->_uniq_rest_10193_1 = _uniq_rest_10193_1;
  _self->cnt_2 = cnt_2;
  _self->pred_1 = pred_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun269(kk_function_t _fself, kk_box_t _b_x48, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun269__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun269__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10193_1 = _self->_uniq_rest_10193_1; /* sslice/sslice */
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<920,int> */
  kk_function_t pred_1 = _self->pred_1; /* (char) -> 926 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10193_1, _ctx);kk_ref_dup(cnt_2, _ctx);kk_function_dup(pred_1, _ctx);}, {}, _ctx)
  bool _y_x10208_0_61 = kk_bool_unbox(_b_x48); /*bool*/;
  kk_unit_t _x_x270 = kk_Unit;
  kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10231(_uniq_rest_10193_1, cnt_2, pred_1, _y_x10208_0_61, _ctx);
  return kk_unit_box(_x_x270);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10200_fun275__t {
  struct kk_function_s _base;
  kk_ref_t cnt_2;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun275(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10200_fun275(kk_ref_t cnt_2, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun275__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun275__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10200_fun275, kk_context());
  _self->cnt_2 = cnt_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun275(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun275__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun275__t*, _fself, _ctx);
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<920,int> */
  kk_drop_match(_self, {kk_ref_dup(cnt_2, _ctx);}, {}, _ctx)
  kk_unit_t _x_x276 = kk_Unit;
  kk_integer_t _x_x277 = kk_integer_unbox(_b_x54, _ctx); /*int*/
  kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10229(cnt_2, _x_x277, _ctx);
  return kk_unit_box(_x_x276);
}


// lift anonymous function
struct kk_std_core_sslice_pred_fs__lift_count_10200_fun280__t {
  struct kk_function_s _base;
  kk_std_core_sslice__sslice _uniq_rest_10193_1;
  kk_ref_t cnt_2;
  kk_function_t pred_1;
};
static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun280(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs__new_lift_count_10200_fun280(kk_std_core_sslice__sslice _uniq_rest_10193_1, kk_ref_t cnt_2, kk_function_t pred_1, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun280__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun280__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs__lift_count_10200_fun280, kk_context());
  _self->_uniq_rest_10193_1 = _uniq_rest_10193_1;
  _self->cnt_2 = cnt_2;
  _self->pred_1 = pred_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs__lift_count_10200_fun280(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs__lift_count_10200_fun280__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs__lift_count_10200_fun280__t*, _fself, _ctx);
  kk_std_core_sslice__sslice _uniq_rest_10193_1 = _self->_uniq_rest_10193_1; /* sslice/sslice */
  kk_ref_t cnt_2 = _self->cnt_2; /* local-var<920,int> */
  kk_function_t pred_1 = _self->pred_1; /* (char) -> 926 bool */
  kk_drop_match(_self, {kk_std_core_sslice__sslice_dup(_uniq_rest_10193_1, _ctx);kk_ref_dup(cnt_2, _ctx);kk_function_dup(pred_1, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10211_1_62 = kk_Unit;
  kk_unit_unbox(_b_x58);
  kk_unit_t _x_x281 = kk_Unit;
  kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10230(_uniq_rest_10193_1, cnt_2, pred_1, _c_x10211_1_62, _ctx);
  return kk_unit_box(_x_x281);
}

kk_unit_t kk_std_core_sslice_pred_fs__lift_count_10200(kk_ref_t cnt_2, kk_function_t pred_1, kk_std_core_sslice__sslice _uniq_slice_0_10187, kk_context_t* _ctx) { /* forall<h,e> (cnt : local-var<h,int>, pred : (char) -> e bool, sslice) -> <local<h>|e> () */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x135 = kk_std_core_sslice_next(_uniq_slice_0_10187, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x135, _ctx)) {
    kk_function_drop(pred_1, _ctx);
    kk_ref_drop(cnt_2, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_box_t _box_x44 = _match_x135._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_1_10191 = kk_std_core_types__tuple2_unbox(_box_x44, KK_BORROWED, _ctx);
    kk_box_t _box_x45 = _uniq_pat_1_10191.fst;
    kk_box_t _box_x46 = _uniq_pat_1_10191.snd;
    kk_std_core_sslice__sslice _uniq_rest_10193_1 = kk_std_core_sslice__sslice_unbox(_box_x46, KK_BORROWED, _ctx);
    kk_char_t _uniq_c_10192 = kk_char_unbox(_box_x45, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(_uniq_rest_10193_1, _ctx);
    kk_std_core_types__maybe_drop(_match_x135, _ctx);
    bool x_1_10241;
    kk_function_t _x_x267 = kk_function_dup(pred_1, _ctx); /*(char) -> 926 bool*/
    x_1_10241 = kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x_x267, (_x_x267, _uniq_c_10192, _ctx), _ctx); /*bool*/
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x268 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_lift_count_10200_fun269(_uniq_rest_10193_1, cnt_2, pred_1, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x268); return kk_Unit;
    }
    {
      kk_unit_t x_2_10245 = kk_Unit;
      if (x_1_10241) {
        kk_integer_t x_3_10248;
        kk_box_t _x_x271;
        kk_ref_t _x_x272 = kk_ref_dup(cnt_2, _ctx); /*local-var<920,int>*/
        _x_x271 = kk_ref_get(_x_x272,kk_context()); /*298*/
        x_3_10248 = kk_integer_unbox(_x_x271, _ctx); /*int*/
        if (kk_yielding(kk_context())) {
          kk_integer_drop(x_3_10248, _ctx);
          kk_box_t _x_x273;
          kk_function_t _x_x274;
          kk_ref_dup(cnt_2, _ctx);
          _x_x274 = kk_std_core_sslice_pred_fs__new_lift_count_10200_fun275(cnt_2, _ctx); /*(2418) -> 2420 2419*/
          _x_x273 = kk_std_core_hnd_yield_extend(_x_x274, _ctx); /*2419*/
          kk_unit_unbox(_x_x273);
        }
        else {
          kk_ref_t _x_x278 = kk_ref_dup(cnt_2, _ctx); /*local-var<920,int>*/
          kk_std_core_sslice_pred_fs__mlift_lift_count_10200_10229(_x_x278, x_3_10248, _ctx);
        }
      }
      else {
        
      }
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x279 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_pred_fs__new_lift_count_10200_fun280(_uniq_rest_10193_1, cnt_2, pred_1, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x279); return kk_Unit;
      }
      { // tailcall
        _uniq_slice_0_10187 = _uniq_rest_10193_1;
        goto kk__tailcall;
      }
    }
  }
}
 
// Count the number of times a predicate is true for each character in a string


// lift anonymous function
struct kk_std_core_sslice_pred_fs_count_fun288__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_core_sslice_pred_fs_count_fun288(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_pred_fs_new_count_fun288(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun288__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_pred_fs_count_fun288__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_pred_fs_count_fun288, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_pred_fs_count_fun288(kk_function_t _fself, kk_box_t _b_x72, kk_context_t* _ctx) {
  struct kk_std_core_sslice_pred_fs_count_fun288__t* _self = kk_function_as(struct kk_std_core_sslice_pred_fs_count_fun288__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<920,int> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x72, _ctx);
  return kk_ref_get(loc,kk_context());
}

kk_integer_t kk_std_core_sslice_pred_fs_count(kk_string_t s, kk_function_t pred, kk_context_t* _ctx) { /* forall<e> (s : string, pred : (char) -> e bool) -> e int */ 
  kk_ref_t loc = kk_ref_alloc((kk_integer_box(kk_integer_from_small(0), _ctx)),kk_context()); /*local-var<920,int>*/;
  kk_std_core_sslice__sslice _uniq_slice_0_10187_10202;
  kk_string_t _x_x283 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x284 = kk_string_len_int(s,kk_context()); /*int*/
  _uniq_slice_0_10187_10202 = kk_std_core_sslice__new_Sslice(_x_x283, kk_integer_from_small(0), _x_x284, _ctx); /*sslice/sslice*/
  kk_unit_t x_10252 = kk_Unit;
  kk_ref_t _x_x285 = kk_ref_dup(loc, _ctx); /*local-var<920,int>*/
  kk_std_core_sslice_pred_fs__lift_count_10200(_x_x285, pred, _uniq_slice_0_10187_10202, _ctx);
  kk_integer_t res;
  kk_box_t _x_x286;
  if (kk_yielding(kk_context())) {
    kk_function_t _x_x287;
    kk_ref_dup(loc, _ctx);
    _x_x287 = kk_std_core_sslice_pred_fs_new_count_fun288(loc, _ctx); /*(2418) -> 2420 298*/
    _x_x286 = kk_std_core_hnd_yield_extend(_x_x287, _ctx); /*2419*/
  }
  else {
    kk_ref_t _x_x289 = kk_ref_dup(loc, _ctx); /*local-var<920,int>*/
    _x_x286 = kk_ref_get(_x_x289,kk_context()); /*2419*/
  }
  res = kk_integer_unbox(_x_x286, _ctx); /*int*/
  kk_box_t _x_x290 = kk_std_core_hnd_prompt_local_var(loc, kk_integer_box(res, _ctx), _ctx); /*4162*/
  return kk_integer_unbox(_x_x290, _ctx);
}
 
// Truncate a string to `count` characters.

kk_string_t kk_std_core_sslice_string_fs_truncate(kk_string_t s, kk_integer_t count_0, kk_context_t* _ctx) { /* (s : string, count : int) -> string */ 
  kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice_first1(s, _ctx); /*sslice/sslice*/;
  kk_std_core_sslice__sslice _x_x291;
  kk_std_core_sslice__sslice _own_x125;
  bool _match_x126;
  kk_integer_t _brw_x131;
  kk_std_core_types__optional _match_x130 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x130, _ctx)) {
    kk_box_t _box_x85 = _match_x130._cons._Optional.value;
    kk_integer_t _uniq_n_414 = kk_integer_unbox(_box_x85, _ctx);
    kk_integer_dup(_uniq_n_414, _ctx);
    kk_std_core_types__optional_drop(_match_x130, _ctx);
    _brw_x131 = _uniq_n_414; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x130, _ctx);
    _brw_x131 = kk_integer_from_small(1); /*int*/
  }
  bool _brw_x132 = kk_integer_eq_borrow(_brw_x131,(kk_integer_from_small(1)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x131, _ctx);
  _match_x126 = _brw_x132; /*bool*/
  if (_match_x126) {
    _own_x125 = slice_0; /*sslice/sslice*/
  }
  else {
    kk_integer_t _brw_x128;
    kk_integer_t _x_x292;
    kk_std_core_types__optional _match_x127 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x127, _ctx)) {
      kk_box_t _box_x86 = _match_x127._cons._Optional.value;
      kk_integer_t _uniq_n_414_0 = kk_integer_unbox(_box_x86, _ctx);
      kk_integer_dup(_uniq_n_414_0, _ctx);
      kk_std_core_types__optional_drop(_match_x127, _ctx);
      _x_x292 = _uniq_n_414_0; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x127, _ctx);
      _x_x292 = kk_integer_from_small(1); /*int*/
    }
    _brw_x128 = kk_integer_add_small_const(_x_x292, -1, _ctx); /*int*/
    kk_std_core_sslice__sslice _brw_x129 = kk_std_core_sslice_extend(slice_0, _brw_x128, _ctx); /*sslice/sslice*/;
    kk_integer_drop(_brw_x128, _ctx);
    _own_x125 = _brw_x129; /*sslice/sslice*/
  }
  kk_integer_t _brw_x124 = kk_integer_add_small_const(count_0, -1, _ctx); /*int*/;
  kk_std_core_sslice__sslice _brw_x133 = kk_std_core_sslice_extend(_own_x125, _brw_x124, _ctx); /*sslice/sslice*/;
  kk_integer_drop(_brw_x124, _ctx);
  _x_x291 = _brw_x133; /*sslice/sslice*/
  return kk_std_core_sslice_string(_x_x291, _ctx);
}
 
// Gets up to (`end`-`start`) characters from the slice beginning from `start`.
// If either start or end is negative, returns the original slice

kk_std_core_sslice__sslice kk_std_core_sslice_subslice(kk_std_core_sslice__sslice slice_0, kk_integer_t start, kk_integer_t end, kk_context_t* _ctx) { /* (slice : sslice, start : int, end : int) -> sslice */ 
  bool _match_x120 = kk_integer_lt_borrow(start,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x120) {
    kk_integer_drop(start, _ctx);
    kk_integer_drop(end, _ctx);
    return slice_0;
  }
  {
    bool _match_x121 = kk_integer_lt_borrow(end,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    if (_match_x121) {
      kk_integer_drop(start, _ctx);
      kk_integer_drop(end, _ctx);
      return slice_0;
    }
    {
      kk_std_core_sslice__sslice slice_0_0_10064 = kk_std_core_sslice_advance(slice_0, start, _ctx); /*sslice/sslice*/;
      kk_integer_t _brw_x122 = kk_integer_sub(end,start,kk_context()); /*int*/;
      kk_std_core_sslice__sslice _brw_x123;
      kk_std_core_sslice__sslice _x_x293;
      kk_string_t _x_x294;
      {
        kk_string_t _x = slice_0_0_10064.str;
        kk_string_dup(_x, _ctx);
        _x_x294 = _x; /*string*/
      }
      kk_integer_t _x_x295;
      {
        kk_integer_t _x_0 = slice_0_0_10064.start;
        kk_integer_dup(_x_0, _ctx);
        kk_std_core_sslice__sslice_drop(slice_0_0_10064, _ctx);
        _x_x295 = _x_0; /*int*/
      }
      _x_x293 = kk_std_core_sslice__new_Sslice(_x_x294, _x_x295, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
      _brw_x123 = kk_std_core_sslice_extend(_x_x293, _brw_x122, _ctx); /*sslice/sslice*/
      kk_integer_drop(_brw_x122, _ctx);
      return _brw_x123;
    }
  }
}
 
// Gets a slice that only includes up to n characters from the start of the slice.

kk_std_core_sslice__sslice kk_std_core_sslice_take(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x118 = kk_integer_lt_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x118) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice _brw_x119;
    kk_std_core_sslice__sslice _x_x296;
    kk_string_t _x_x297;
    {
      kk_string_t _x = slice_0.str;
      kk_string_dup(_x, _ctx);
      _x_x297 = _x; /*string*/
    }
    kk_integer_t _x_x298;
    {
      kk_integer_t _x_0 = slice_0.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0, _ctx);
      _x_x298 = _x_0; /*int*/
    }
    _x_x296 = kk_std_core_sslice__new_Sslice(_x_x297, _x_x298, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x119 = kk_std_core_sslice_extend(_x_x296, n, _ctx); /*sslice/sslice*/
    kk_integer_drop(n, _ctx);
    return _brw_x119;
  }
}
 
// Gets a slice that drops the first n characters, shrinking the length of the slice by n accordingly.
// If the slice does not have n characters, then the slice is shrunk to an empty slice.
//
// If maintaining the length of the slice is important, use `advance` instead.

kk_std_core_sslice__sslice kk_std_core_sslice_drop(kk_std_core_sslice__sslice slice_0, kk_integer_t n, kk_context_t* _ctx) { /* (slice : sslice, n : int) -> sslice */ 
  bool _match_x115 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x115) {
    kk_integer_drop(n, _ctx);
    return slice_0;
  }
  {
    kk_std_core_sslice__sslice slice_0_0_10072;
    kk_std_core_sslice__sslice _x_x299 = kk_std_core_sslice__sslice_dup(slice_0, _ctx); /*sslice/sslice*/
    slice_0_0_10072 = kk_std_core_sslice_advance(_x_x299, n, _ctx); /*sslice/sslice*/
    kk_integer_t x_10075 = kk_std_core_sslice_count(slice_0, _ctx); /*int*/;
    kk_integer_t _brw_x116 = kk_integer_sub(x_10075,n,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _brw_x117;
    kk_std_core_sslice__sslice _x_x300;
    kk_string_t _x_x301;
    {
      kk_string_t _x = slice_0_0_10072.str;
      kk_string_dup(_x, _ctx);
      _x_x301 = _x; /*string*/
    }
    kk_integer_t _x_x302;
    {
      kk_integer_t _x_0 = slice_0_0_10072.start;
      kk_integer_dup(_x_0, _ctx);
      kk_std_core_sslice__sslice_drop(slice_0_0_10072, _ctx);
      _x_x302 = _x_0; /*int*/
    }
    _x_x300 = kk_std_core_sslice__new_Sslice(_x_x301, _x_x302, kk_integer_from_small(0), _ctx); /*sslice/sslice*/
    _brw_x117 = kk_std_core_sslice_extend(_x_x300, _brw_x116, _ctx); /*sslice/sslice*/
    kk_integer_drop(_brw_x116, _ctx);
    return _brw_x117;
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_std_core_sslice_slice_fs__mlift_foreach_while_10233(kk_function_t action, kk_std_core_sslice__sslice rest, kk_std_core_types__maybe _y_x10218, kk_context_t* _ctx) { /* forall<a,e> (action : (c : char) -> e maybe<a>, rest : sslice, maybe<a>) -> e maybe<a> */ 
  if (kk_std_core_types__is_Nothing(_y_x10218, _ctx)) {
    return kk_std_core_sslice_slice_fs_foreach_while(rest, action, _ctx);
  }
  {
    kk_std_core_sslice__sslice_drop(rest, _ctx);
    kk_function_drop(action, _ctx);
    return _y_x10218;
  }
}
 
// Apply a function for each character in a string slice.
// If `action` returns `Just`, the function returns immediately with that result.


// lift anonymous function
struct kk_std_core_sslice_slice_fs_foreach_while_fun305__t {
  struct kk_function_s _base;
  kk_function_t action_0;
  kk_std_core_sslice__sslice rest_0;
};
static kk_box_t kk_std_core_sslice_slice_fs_foreach_while_fun305(kk_function_t _fself, kk_box_t _b_x91, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_slice_fs_new_foreach_while_fun305(kk_function_t action_0, kk_std_core_sslice__sslice rest_0, kk_context_t* _ctx) {
  struct kk_std_core_sslice_slice_fs_foreach_while_fun305__t* _self = kk_function_alloc_as(struct kk_std_core_sslice_slice_fs_foreach_while_fun305__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_core_sslice_slice_fs_foreach_while_fun305, kk_context());
  _self->action_0 = action_0;
  _self->rest_0 = rest_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_core_sslice_slice_fs_foreach_while_fun305(kk_function_t _fself, kk_box_t _b_x91, kk_context_t* _ctx) {
  struct kk_std_core_sslice_slice_fs_foreach_while_fun305__t* _self = kk_function_as(struct kk_std_core_sslice_slice_fs_foreach_while_fun305__t*, _fself, _ctx);
  kk_function_t action_0 = _self->action_0; /* (c : char) -> 1133 maybe<1132> */
  kk_std_core_sslice__sslice rest_0 = _self->rest_0; /* sslice/sslice */
  kk_drop_match(_self, {kk_function_dup(action_0, _ctx);kk_std_core_sslice__sslice_dup(rest_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10218_0_93 = kk_std_core_types__maybe_unbox(_b_x91, KK_OWNED, _ctx); /*maybe<1132>*/;
  kk_std_core_types__maybe _x_x306 = kk_std_core_sslice_slice_fs__mlift_foreach_while_10233(action_0, rest_0, _y_x10218_0_93, _ctx); /*maybe<1132>*/
  return kk_std_core_types__maybe_box(_x_x306, _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_slice_fs_foreach_while(kk_std_core_sslice__sslice slice_0, kk_function_t action_0, kk_context_t* _ctx) { /* forall<a,e> (slice : sslice, action : (c : char) -> e maybe<a>) -> e maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x113 = kk_std_core_sslice_next(slice_0, _ctx); /*maybe<(char, sslice/sslice)>*/;
  if (kk_std_core_types__is_Nothing(_match_x113, _ctx)) {
    kk_function_drop(action_0, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_box_t _box_x87 = _match_x113._cons.Just.value;
    kk_std_core_types__tuple2 _pat_1 = kk_std_core_types__tuple2_unbox(_box_x87, KK_BORROWED, _ctx);
    kk_box_t _box_x88 = _pat_1.fst;
    kk_box_t _box_x89 = _pat_1.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x89, KK_BORROWED, _ctx);
    kk_char_t c = kk_char_unbox(_box_x88, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__maybe_drop(_match_x113, _ctx);
    kk_std_core_types__maybe x_10256;
    kk_function_t _x_x303 = kk_function_dup(action_0, _ctx); /*(c : char) -> 1133 maybe<1132>*/
    x_10256 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_char_t, kk_context_t*), _x_x303, (_x_x303, c, _ctx), _ctx); /*maybe<1132>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10256, _ctx);
      kk_box_t _x_x304 = kk_std_core_hnd_yield_extend(kk_std_core_sslice_slice_fs_new_foreach_while_fun305(action_0, rest_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x304, KK_OWNED, _ctx);
    }
    if (kk_std_core_types__is_Nothing(x_10256, _ctx)) { // tailcall
                                                        slice_0 = rest_0;
                                                        goto kk__tailcall;
    }
    {
      kk_std_core_sslice__sslice_drop(rest_0, _ctx);
      kk_function_drop(action_0, _ctx);
      return x_10256;
    }
  }
}
 
// Return the first character of a string (or `Nothing` for the empty string).


// lift anonymous function
struct kk_std_core_sslice_head_char_fun313__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun313(kk_function_t _fself, kk_char_t _b_x94, kk_context_t* _ctx);
static kk_function_t kk_std_core_sslice_new_head_char_fun313(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_core_sslice_head_char_fun313, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_core_sslice_head_char_fun313(kk_function_t _fself, kk_char_t _b_x94, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_core_types__new_Just(kk_char_box(_b_x94, _ctx), _ctx);
}

kk_std_core_types__maybe kk_std_core_sslice_head_char(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> maybe<char> */ 
  kk_std_core_sslice__sslice _x_x310;
  kk_string_t _x_x311 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x312 = kk_string_len_int(s,kk_context()); /*int*/
  _x_x310 = kk_std_core_sslice__new_Sslice(_x_x311, kk_integer_from_small(0), _x_x312, _ctx); /*sslice/sslice*/
  return kk_std_core_sslice_slice_fs_foreach_while(_x_x310, kk_std_core_sslice_new_head_char_fun313(_ctx), _ctx);
}
 
// O(n). If it occurs, return the position of substring `sub` in `s`, tupled with
// the position just following the substring `sub`.

kk_std_core_types__maybe kk_std_core_sslice_find(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x314;
  kk_string_t _x_x315 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x316 = kk_string_dup(sub, _ctx); /*string*/
  _x_x314 = kk_string_index_of1(_x_x315,_x_x316,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x314,kk_context()); /*int*/
  bool _match_x112 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x112) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x95_96;
    kk_integer_t _x_x317 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x318 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x95_96 = kk_std_core_sslice__new_Sslice(s, _x_x317, _x_x318, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x95_96, _ctx), _ctx);
  }
}
 
// Return the last index of substring `sub` in `s` if it occurs.

kk_std_core_types__maybe kk_std_core_sslice_find_last(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> maybe<sslice> */ 
  kk_integer_t i;
  kk_ssize_t _x_x319;
  kk_string_t _x_x320 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x321 = kk_string_dup(sub, _ctx); /*string*/
  _x_x319 = kk_string_last_index_of1(_x_x320,_x_x321,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x319,kk_context()); /*int*/
  bool _match_x111 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x111) {
    kk_string_drop(sub, _ctx);
    kk_string_drop(s, _ctx);
    kk_integer_drop(i, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_std_core_sslice__sslice _b_x97_98;
    kk_integer_t _x_x322 = kk_integer_add_small_const(i, -1, _ctx); /*int*/
    kk_integer_t _x_x323 = kk_string_len_int(sub,kk_context()); /*int*/
    _b_x97_98 = kk_std_core_sslice__new_Sslice(s, _x_x322, _x_x323, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x97_98, _ctx), _ctx);
  }
}
 
// Is `pre`  a prefix of `s`? If so, returns a slice
// of `s` following `pre` up to the end of `s`.

kk_std_core_types__maybe kk_std_core_sslice_starts_with(kk_string_t s, kk_string_t pre, kk_context_t* _ctx) { /* (s : string, pre : string) -> maybe<sslice> */ 
  bool _match_x110;
  kk_string_t _x_x324 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x325 = kk_string_dup(pre, _ctx); /*string*/
  _match_x110 = kk_string_starts_with(_x_x324,_x_x325,kk_context()); /*bool*/
  if (_match_x110) {
    kk_integer_t x_10081;
    kk_string_t _x_x326 = kk_string_dup(s, _ctx); /*string*/
    x_10081 = kk_string_len_int(_x_x326,kk_context()); /*int*/
    kk_integer_t y_10082;
    kk_string_t _x_x327 = kk_string_dup(pre, _ctx); /*string*/
    y_10082 = kk_string_len_int(_x_x327,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x99_100;
    kk_integer_t _x_x328 = kk_string_len_int(pre,kk_context()); /*int*/
    kk_integer_t _x_x329 = kk_integer_sub(x_10081,y_10082,kk_context()); /*int*/
    _b_x99_100 = kk_std_core_sslice__new_Sslice(s, _x_x328, _x_x329, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x99_100, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(pre, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}

bool kk_std_core_sslice_xends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> bool */ 
  return kk_string_ends_with(s,post,kk_context());
}
 
// Does string `s`  end with `post`?
// If so, returns a slice of `s` from the start up to the `post` string at the end.

kk_std_core_types__maybe kk_std_core_sslice_ends_with(kk_string_t s, kk_string_t post, kk_context_t* _ctx) { /* (s : string, post : string) -> maybe<sslice> */ 
  bool _match_x109;
  kk_string_t _x_x330 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x331 = kk_string_dup(post, _ctx); /*string*/
  _match_x109 = kk_std_core_sslice_xends_with(_x_x330, _x_x331, _ctx); /*bool*/
  if (_match_x109) {
    kk_integer_t x_10083;
    kk_string_t _x_x332 = kk_string_dup(s, _ctx); /*string*/
    x_10083 = kk_string_len_int(_x_x332,kk_context()); /*int*/
    kk_integer_t y_10084 = kk_string_len_int(post,kk_context()); /*int*/;
    kk_std_core_sslice__sslice _b_x101_102;
    kk_integer_t _x_x333 = kk_integer_sub(x_10083,y_10084,kk_context()); /*int*/
    _b_x101_102 = kk_std_core_sslice__new_Sslice(s, kk_integer_from_small(0), _x_x333, _ctx); /*sslice/sslice*/
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x101_102, _ctx), _ctx);
  }
  {
    kk_string_drop(s, _ctx);
    kk_string_drop(post, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Trim off a substring `sub` while `s` starts with that string.

kk_string_t kk_std_core_sslice_trim_left(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x107;
  kk_string_t _x_x334 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x335 = kk_string_empty(); /*string*/
  _match_x107 = kk_string_is_eq(_x_x334,_x_x335,kk_context()); /*bool*/
  if (_match_x107) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x108;
    kk_string_t _x_x337 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x338 = kk_string_dup(sub, _ctx); /*string*/
    _match_x108 = kk_std_core_sslice_starts_with(_x_x337, _x_x338, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x108, _ctx)) {
      kk_box_t _box_x103 = _match_x108._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x103, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x108, _ctx);
      { // tailcall
        kk_string_t _x_x339 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x339;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}
 
// Trim off a substring `sub` while `s` ends with that string.

kk_string_t kk_std_core_sslice_trim_right(kk_string_t s, kk_string_t sub, kk_context_t* _ctx) { /* (s : string, sub : string) -> string */ 
  kk__tailcall: ;
  bool _match_x105;
  kk_string_t _x_x340 = kk_string_dup(sub, _ctx); /*string*/
  kk_string_t _x_x341 = kk_string_empty(); /*string*/
  _match_x105 = kk_string_is_eq(_x_x340,_x_x341,kk_context()); /*bool*/
  if (_match_x105) {
    kk_string_drop(sub, _ctx);
    return s;
  }
  {
    kk_std_core_types__maybe _match_x106;
    kk_string_t _x_x343 = kk_string_dup(s, _ctx); /*string*/
    kk_string_t _x_x344 = kk_string_dup(sub, _ctx); /*string*/
    _match_x106 = kk_std_core_sslice_ends_with(_x_x343, _x_x344, _ctx); /*maybe<sslice/sslice>*/
    if (kk_std_core_types__is_Just(_match_x106, _ctx)) {
      kk_box_t _box_x104 = _match_x106._cons.Just.value;
      kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__sslice_unbox(_box_x104, KK_BORROWED, _ctx);
      kk_string_drop(s, _ctx);
      kk_std_core_sslice__sslice_dup(slice_0, _ctx);
      kk_std_core_types__maybe_drop(_match_x106, _ctx);
      { // tailcall
        kk_string_t _x_x345 = kk_std_core_sslice_string(slice_0, _ctx); /*string*/
        s = _x_x345;
        goto kk__tailcall;
      }
    }
    {
      kk_string_drop(sub, _ctx);
      return s;
    }
  }
}

// initialization
void kk_std_core_sslice__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_undiv__init(_ctx);
  kk_std_core_unsafe__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_string__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x234 = kk_string_empty(); /*string*/
    kk_std_core_sslice_empty = kk_std_core_sslice__new_Sslice(_x_x234, kk_integer_from_small(0), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
  {
    kk_string_t _x_x236 = kk_string_empty(); /*string*/
    kk_std_core_sslice_invalid = kk_std_core_sslice__new_Sslice(_x_x236, kk_integer_from_small(-1), kk_integer_from_small(0), _ctx); /*sslice/sslice*/
  }
}

// termination
void kk_std_core_sslice__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_invalid, _ctx);
  kk_std_core_sslice__sslice_drop(kk_std_core_sslice_empty, _ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_unsafe__done(_ctx);
  kk_std_core_undiv__done(_ctx);
  kk_std_core_types__done(_ctx);
}
