#include "x10_string.h"
#include "util.h"

static inline x10_int get_str_len(const x10_string *str) {
	return str->len;
}

#define X10_STRING_INIT(str, len_) \
	X10_INIT_OBJECT(str, T_STRING); \
	str->len = (len_);

static inline x10_string* alloc_string(x10_int len) {
	return (x10_string *)x10_malloc(sizeof(x10_string) + (((len) + 1) * sizeof(x10_char)));
}

static inline void check_string_bounds(x10_string *str, x10_int idx) {
	if (idx < 0 || (x10_uint)idx > (str->len)) {
		x10_throw_exception(new_exception("Index Out of Bounds", "Within string bounds check"));
	}
}

static x10_string *x10_string_from_wide_buf(const size_t len, const x10_char *wchars) {
	x10_string *str = alloc_string(len);

	X10_STRING_INIT(str, len);

	wcpncpy(X10_STRING_BUF(str), wchars, len);

	return str;
}

x10_string *x10_string_from_wide_chars(const x10_char *wchars)
{
	assert(wchars != NULL);
	return x10_string_from_wide_buf(wcslen(wchars), wchars);
}

x10_string *x10_string_literal(size_t len, x10_char *wchars) {
	return x10_string_from_wide_buf(len, wchars);
}

// constructors
// this(String)
x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(x10_string *str)
{
	return x10_string_from_wide_buf(get_str_len(str), X10_STRING_BUF(str));
}

// this()
x10_string *_ZN3x104lang6StringC1Ev()
{
	return x10_string_literal(0, T_(""));
}

// String methods

x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE(x10_string *self, x10_any *other)
{
	if (other == X10_NULL)
		return X10_FALSE;
	if (!X10_INSTANCE_OF(other, T_STRING))
		return X10_FALSE;

	const x10_string *oth = X10_OBJECT_CAST(x10_string, other);
	if (get_str_len(self) != get_str_len(oth))
		return X10_FALSE;
	if (wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(oth), get_str_len(self)))
		return X10_FALSE;

	return X10_TRUE;
}

x10_int _ZN3x104lang6String6lengthEv(x10_string *self)
{
	return get_str_len(self);
}

x10_string *_ZN3x104lang6String8toStringEv(x10_string *self)
{
	return self;
}

x10_char _ZN3x104lang6String6charAtEi(x10_string *self, x10_int idx)
{
	check_string_bounds(self, idx);
	return X10_STRING_CHAR(self, idx);
}

x10_int _ZN3x104lang6String7indexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if (idx < 0)
		idx = 0;
	if (idx >= get_str_len(self))
		return -1;

	const x10_char *pos = wcschr(&X10_STRING_CHAR(self, idx), c);
	if (pos == NULL)
		return -1;

	return (pos - X10_STRING_BUF(self));
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
	if (idx >= get_str_len(self))
		return -1;

	const x10_char *haystack = &X10_STRING_CHAR(self, idx);
	const size_t haystack_sz = get_str_len(self) - idx;
	const x10_char *needle = X10_STRING_BUF(other);
	const size_t needle_sz = get_str_len(other);
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
	return _ZN3x104lang6String11lastIndexOfEDii(self, c, get_str_len(self) - 1);
}

x10_int _ZN3x104lang6String11lastIndexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if (idx < 0)
		idx = 0;
	if (idx >= get_str_len(self))
		return -1;

	const x10_char *pos = wcsrchr(&X10_STRING_CHAR(self, idx), c);

	if (pos == NULL)
		return -1;

	return (pos - X10_STRING_BUF(self));
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(x10_string *self, x10_string * other)
{
	return _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(self, other, get_str_len(self) - 1);
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(x10_string *self, x10_string *other, x10_int idx)
{
	x10_null_check(other);
	if (idx < 0)
		idx = 0;
	if (idx >= get_str_len(self))
		return -1;

	const x10_char *needle = X10_STRING_BUF(other);
	const size_t needle_sz = get_str_len(other);
	const x10_char *haystack = X10_STRING_BUF(self);
	const size_t haystack_sz = idx + 1;

	const x10_char *pos = wstrnrstrn(haystack, haystack_sz, needle, needle_sz);
	if (pos == X10_NULL)
		return -1;

	return (x10_int)(pos - haystack);
}


x10_string *_ZN3x104lang6String9substringEi(x10_string *self, x10_int start_idx)
{
	check_string_bounds(self, start_idx);
	const size_t len = get_str_len(self) - start_idx;
	return x10_string_from_wide_buf(len, &X10_STRING_CHAR(self, start_idx));
}

x10_string *_ZN3x104lang6String9substringEii(x10_string *self, x10_int start_idx, x10_int to_idx)
{
	check_string_bounds(self, start_idx);
	check_string_bounds(self, to_idx);
	if (start_idx > to_idx)
		x10_throw_exception(new_exception("Index Out Of Bounds", "In substring"));

	const size_t len = to_idx - start_idx;
	return x10_string_from_wide_buf(len, &X10_STRING_CHAR(self, start_idx));
}

x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const size_t len_self  = get_str_len(self);
	const size_t len_other = get_str_len(other);

	if (len_other > len_self)
		return X10_FALSE;

	const size_t diff = len_self - len_other;
	return wcsncmp(&X10_STRING_CHAR(self, diff), X10_STRING_BUF(other), len_other) == 0 ? X10_TRUE : X10_FALSE;
}

x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const size_t len_self  = get_str_len(self);
	const size_t len_other = get_str_len(other);
	if (len_other > len_self)
		return X10_FALSE;

	return wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(other), len_other) == 0 ? X10_TRUE : X10_FALSE;
}

// whitespaces are the same as in java -> Unicocode codepoints <= U0020
#define X10_IS_WS(c) (c <= 0x20)

x10_string *_ZN3x104lang6String4trimEv(x10_string *self)
{
	x10_int len = get_str_len(self);
	if (len == 0)
		return self;

	const x10_char *buf = X10_STRING_BUF(self);
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

x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	x10_null_check(other);
	const x10_int len_diff = get_str_len(self) - get_str_len(other);
	const size_t min_len = MIN(get_str_len(self), get_str_len(other));
	const x10_int cmp = wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(other), min_len);
	if (cmp != 0)
		return cmp;

	return len_diff;
}

x10_string *_ZN3x104lang6String8typeNameEv(x10_string *self)
{
	UNUSED(self);
	return x10_string_from_wide_chars(T_("x10.lang.String"));
}

// operator+(String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	return _ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(self, other);
}

// static operator+(String, String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(x10_string *x, x10_string *y)
{
	const size_t len_x = get_str_len(x), len_y = get_str_len(y);
	const size_t len_ret = len_x + len_y;
	x10_string *ret = alloc_string(len_ret);

	X10_STRING_INIT(ret, len_ret);

	wcpncpy(X10_STRING_BUF(ret), X10_STRING_BUF(x), len_x);
	wcpncpy(&X10_STRING_CHAR(ret, len_x), X10_STRING_BUF(y), len_y);

	return ret;
}
