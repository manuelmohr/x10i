#include "x10_string.h"
#include "util.h"
#include "x10.h"

static inline void x10_init_string(x10_string *str)
{
	X10_INIT_OBJECT(str, &STRING_VTABLE);
	str->len = 0;
}

static x10_string* x10_allocate_string(x10_int len)
{
	return x10_malloc(sizeof(x10_string) + (((len) + 1) * sizeof(x10_char)));
}

static inline void check_string_bounds(x10_string *str, x10_int idx)
{
	if (idx < 0 || (x10_uint)idx > (str->len)) {
		x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("Within string bounds check"));
	}
}

static void x10_set_string(x10_string *str, const x10_char *wchars,
		size_t len)
{
	str->len = len;
	wcpncpy(x10_string_buf(str), wchars, len);
}

static x10_string *x10_string_from_wide_buf(size_t len, const x10_char *wchars)
{
	x10_string *str = x10_allocate_string(len);

	x10_init_string(str);
	x10_set_string(str, wchars, len);

	return str;
}

x10_string *x10_string_from_wide_chars(const x10_char *wchars)
{
	assert(wchars != NULL);
	return x10_string_from_wide_buf(wcslen(wchars), wchars);
}

x10_string *x10_string_literal(size_t len, x10_char *wchars)
{
	return x10_string_from_wide_buf(len, wchars);
}

// constructors
// this()
x10_string *_ZN3x104lang6StringC1Ev()
{
	return x10_string_from_wide_buf(0, T_(""));
}

// this(String)
x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(x10_string *str)
{
	return x10_string_from_wide_buf(x10_string_len(str), x10_string_buf(str));
}

// String methods

x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE(x10_string *self,
		x10_any *other)
{
	if (other == X10_NULL)
		return X10_FALSE;
	if (!x10_instance_of(other, &STRING_CLASSINFO))
		return X10_FALSE;

	x10_string *oth = X10_OBJECT_CAST(x10_string, other);
	if (x10_string_len(self) != x10_string_len(oth))
		return X10_FALSE;
	if (wcsncmp(x10_string_buf(self), x10_string_buf(oth), x10_string_len(self)))
		return X10_FALSE;

	return X10_TRUE;
}

x10_boolean _ZN3x104lang6String16equalsIgnoreCaseEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if(other == X10_NULL)
		return X10_FALSE;
	
	x10_int self_len  = x10_string_len(self);
	x10_int other_len = x10_string_len(other);
	if(self_len != other_len)
		return X10_FALSE;
	
	const x10_char *self_buf  = (const x10_char *)x10_string_buf(self);
	const x10_char *other_buf = (const x10_char *)x10_string_buf(other);
	
	return wcscasecmp(self_buf, other_buf) == 0;
}

x10_int _ZN3x104lang6String8hashCodeEv(x10_string *self)
{
    x10_int hc = 0;
    x10_int l = x10_string_len(self);
    const x10_char * k = (const x10_char*)x10_string_buf(self);
    for (; l > 0; k++, l--) {
        hc *= 31;
        hc += (x10_int) *k;
    }
    return hc;
}

x10_int _ZN3x104lang6String6lengthEv(x10_string *self)
{
	return x10_string_len(self);
}

x10_string *_ZN3x104lang6String8toStringEv(x10_string *self)
{
	return self;
}

x10_char _ZN3x104lang6String6charAtEi(x10_string *self, x10_int idx)
{
	check_string_bounds(self, idx);
	return x10_string_buf(self)[idx];
}

x10_char _ZN3x104lang6StringapplyEi(x10_string *self, x10_int idx)
{
	return _ZN3x104lang6String6charAtEi(self, idx);
}

x10_int _ZN3x104lang6String7indexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if (idx < 0)
		idx = 0;
	if (idx >= x10_string_len(self))
		return -1;

	const x10_char *pos = wcschr(x10_string_buf(self) + idx, c);
	if (pos == NULL)
		return -1;

	return (pos - x10_string_buf(self));
}

x10_int _ZN3x104lang6String7indexOfEDi(x10_string *self, x10_char c)
{
	return _ZN3x104lang6String7indexOfEDii(self, c, 0);
}

static const x10_char *wstrnrstrn(const x10_char *haystack, size_t haystack_sz,
                             const x10_char *needle, size_t needle_sz)
{
	if (haystack_sz < needle_sz)
		return X10_NULL;

	for (size_t i = haystack_sz-needle_sz; i > 0; --i)
		if (!wcsncmp(&haystack[i], needle, needle_sz))
			return &haystack[i];

	if (!wcsncmp(haystack, needle, needle_sz))
		return haystack;

	return X10_NULL;
}


x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(x10_string *self, x10_string *other, x10_int idx)
{
	x10_null_check(other);
	if (idx < 0)
		idx = 0;
	if (idx >= x10_string_len(self))
		return -1;

	const x10_char *haystack = x10_string_buf(self) + idx;
	const size_t haystack_sz = x10_string_len(self) - idx;
	const x10_char *needle = x10_string_buf(other);
	const size_t needle_sz = x10_string_len(other);
	const x10_char *pos = wstrnrstrn(haystack, haystack_sz, needle, needle_sz);

	if (pos == X10_NULL)
		return (x10_int) -1;

	return idx + (x10_int) (pos - haystack);
}

x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(self, other, 0);
}

x10_int _ZN3x104lang6String11lastIndexOfEDi(x10_string *self, x10_char c)
{
	return _ZN3x104lang6String11lastIndexOfEDii(self, c, x10_string_len(self) - 1);
}

x10_int _ZN3x104lang6String11lastIndexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if (idx < 0)
		idx = 0;
	if (idx >= x10_string_len(self))
		return -1;

	const x10_char *pos = wcsrchr(x10_string_buf(self) + idx, c);

	if (pos == NULL)
		return -1;

	return (pos - x10_string_buf(self));
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(x10_string *self, x10_string * other)
{
	return _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(self, other, x10_string_len(self) - 1);
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(x10_string *self, x10_string *other, x10_int idx)
{
	x10_null_check(other);
	if (idx < 0)
		idx = 0;
	if (idx >= x10_string_len(self))
		return -1;

	const x10_char *needle = x10_string_buf(other);
	const size_t needle_sz = x10_string_len(other);
	const x10_char *haystack = x10_string_buf(self);
	const size_t haystack_sz = idx + 1;

	const x10_char *pos = wstrnrstrn(haystack, haystack_sz, needle, needle_sz);
	if (pos == X10_NULL)
		return -1;

	return (x10_int)(pos - haystack);
}


x10_string *_ZN3x104lang6String9substringEi(x10_string *self, x10_int start_idx)
{
	check_string_bounds(self, start_idx);
	const size_t len = x10_string_len(self) - start_idx;
	return x10_string_from_wide_buf(len, x10_string_buf(self) + start_idx);
}

x10_string *_ZN3x104lang6String9substringEii(x10_string *self, x10_int start_idx, x10_int to_idx)
{
	check_string_bounds(self, start_idx);
	check_string_bounds(self, to_idx);
	if (start_idx > to_idx)
		x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("In substring"));

	const size_t len = to_idx - start_idx;
	return x10_string_from_wide_buf(len, x10_string_buf(self) + start_idx);
}

x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const size_t len_self  = x10_string_len(self);
	const size_t len_other = x10_string_len(other);

	if (len_other > len_self)
		return X10_FALSE;

	const size_t diff = len_self - len_other;
	return wcsncmp(x10_string_buf(self) + diff, x10_string_buf(other), len_other) == 0 ? X10_TRUE : X10_FALSE;
}

x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const size_t len_self  = x10_string_len(self);
	const size_t len_other = x10_string_len(other);
	if (len_other > len_self)
		return X10_FALSE;

	return wcsncmp(x10_string_buf(self), x10_string_buf(other), len_other) == 0 ? X10_TRUE : X10_FALSE;
}

// whitespaces are the same as in java -> Unicocode codepoints <= U0020
#define X10_IS_WS(c) (c <= 0x20)

x10_string *_ZN3x104lang6String4trimEv(x10_string *self)
{
	x10_int len = x10_string_len(self);
	if (len == 0)
		return self;

	const x10_char *buf = x10_string_buf(self);
	while (len > 0 && X10_IS_WS(buf[0])) {
		len--;
		buf++;
	}

	while (len > 0 && X10_IS_WS(buf[len - 1]))
		len--;

	if (len <= 0)
		return x10_string_from_wide_chars(T_(""));

	return x10_string_from_wide_buf(len, buf);
}

x10_string *_ZN3x104lang6String11toLowerCaseEv(x10_string *self)
{
	x10_int len = x10_string_len(self);
	x10_char *self_buf = x10_string_buf(self); 
	x10_string *ret = x10_allocate_string(len);
	x10_char *ret_buf = x10_string_buf(ret);
	x10_int i;
	for(i = 0; i < len; i++) 
		ret_buf[i] = towlower(self_buf[i]);
	return ret;
}

x10_string *_ZN3x104lang6String11toUpperCaseEv(x10_string *self)
{
	x10_int len = x10_string_len(self);
	x10_char *self_buf = x10_string_buf(self); 
	x10_string *ret = x10_allocate_string(len);
	x10_char *ret_buf = x10_string_buf(ret);
	x10_int i;
	for(i = 0; i < len; i++) 
		ret_buf[i] = towupper(self_buf[i]);
	return ret;
}

x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	x10_null_check(other);
	const x10_int self_len = x10_string_len(self), other_len = x10_string_len(other);
	
	const x10_int len_diff = self_len - other_len;
	const size_t min_len = MIN(self_len, other_len);
	const x10_int cmp = wcsncmp(x10_string_buf(self), x10_string_buf(other), min_len);
	if (cmp != 0)
		return cmp;

	return len_diff;
}

x10_int _ZN3x104lang6String19compareToIgnoreCaseEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	x10_null_check(other);
	const x10_int self_len = x10_string_len(self), other_len = x10_string_len(other);
	
	const x10_int len_diff = self_len - other_len;
	const size_t min_len = MIN(self_len, other_len);
	const x10_int cmp = wcsncasecmp(x10_string_buf(self), x10_string_buf(other), min_len);
	if (cmp != 0)
		return cmp;

	return len_diff;
}

x10_string *_ZN3x104lang6String8typeNameEv(x10_string *self)
{
	X10_UNUSED(self);
	return x10_string_from_wide_chars(T_("x10.lang.String"));
}

// operator <(String)
x10_boolean _ZN3x104lang6StringltEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6String9compareToEPN3x104lang6StringE(self, other) < 0;
}

// operator <=(String)
x10_boolean _ZN3x104lang6StringleEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6String9compareToEPN3x104lang6StringE(self, other) <= 0;
}

// operator >(String)
x10_boolean _ZN3x104lang6StringgtEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6String9compareToEPN3x104lang6StringE(self, other) > 0;
}

// operator >=(String)
x10_boolean _ZN3x104lang6StringgeEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6String9compareToEPN3x104lang6StringE(self, other) >= 0;
}

// operator+(String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(self, other);
}

// static operator+(String, String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(x10_string *x, x10_string *y)
{
	const size_t len_x = x10_string_len(x), len_y = x10_string_len(y);
	const size_t len_ret = len_x + len_y;
	x10_string *ret = x10_allocate_string(len_ret);
	x10_init_string(ret);
	ret->len = len_ret;

	wcpncpy(x10_string_buf(ret), x10_string_buf(x), len_x);
	wcpncpy(x10_string_buf(ret) + len_x, x10_string_buf(y), len_y);

	return ret;
}
