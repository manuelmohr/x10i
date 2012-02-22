#include "x10_string.h"
#include "util.h"
#include "x10.h"

static x10_string *x10_allocate_string(x10_int len)
{
	return x10_malloc(sizeof(x10_string) + (len+1)*sizeof(x10_char));
}

/** initializes a new string, returns pointer to writable buffer */
static x10_char *x10_init_string(x10_string *str, x10_uint len)
{
	X10_INIT_OBJECT(str, &STRING_VTABLE);
	str->len = len;
	return (x10_char*)(str+1);
}

static void check_string_bounds(const x10_string *str, x10_int idx)
{
	if (idx < 0 || idx > (str->len)) {
		x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("Within string bounds check"));
	}
}

x10_string *x10_string_literal(x10_int len, const x10_char *chars)
{
	x10_string *str    = x10_allocate_string(len);
	x10_char   *buffer = x10_init_string(str, len);
	memcpy(buffer, chars, len);
	return str;
}

x10_string *x10_string_from_cstring(const char *string)
{
	return x10_string_literal(strlen(string), string);
}

// this()
x10_string *_ZN3x104lang6StringC1Ev()
{
	return x10_string_literal(0, T_(""));
}

// this(String)
x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(x10_string *str)
{
	return str;
}

static inline bool equals(const x10_char *chars0, const x10_char *chars1,
                          const x10_int len)
{
	/* Note: do not use str(n)cmp here because it stops at '\0' chars */
	return memcmp(chars0, chars1, len) == 0;
}

// String.equals(String other)
x10_boolean _ZN3x104lang6String6equalsEPN3x104lang6StringE(
		const x10_string *self, const x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const x10_int len = self->len;
	if (other->len != len)
		return X10_FALSE;

	return equals(self->chars, other->chars, len);
}

// String.equalsIgnoreCase(String other)
x10_boolean _ZN3x104lang6String16equalsIgnoreCaseEPN3x104lang6StringE(
		const x10_string *self, const x10_string *other)
{
	if(other == X10_NULL)
		return X10_FALSE;

	x10_int len = self->len;
	if (other->len != len)
		return X10_FALSE;

	const x10_char *c0 = self->chars;
	const x10_char *c1 = other->chars;
	while (++c0, ++c1, len-- > 0) {
		if (tolower(*c0) != tolower(*c1))
			return X10_FALSE;
	}
	return X10_TRUE;
}

// String.hashCode()
x10_int _ZN3x104lang6String8hashCodeEv(const x10_string *self)
{
	x10_int hash = 0;
	x10_int l    = self->len;
	const x10_char *c = self->chars;
	for (; l > 0; ++c, --l) {
		hash = ((hash << 5) + hash) + (x10_int)*c;
	}
	return hash;
}

// String.length()
x10_int _ZN3x104lang6String6lengthEv(const x10_string *self)
{
	return self->len;
}

// String.charAt(int)
x10_char _ZN3x104lang6String6charAtEi(const x10_string *self, x10_int idx)
{
	check_string_bounds(self, idx);
	return self->chars[idx];
}

// String.operator()
x10_char _ZN3x104lang6StringapplyEi(const x10_string *self, x10_int idx)
{
	return _ZN3x104lang6String6charAtEi(self, idx);
}

// String.indexOf(char, int)
x10_int _ZN3x104lang6String7indexOfEDii(const x10_string *self, x10_char needle, x10_int idx)
{
	if (idx < 0)
		idx = 0;
	const x10_int len = self->len;
	for (const x10_char *c = &self->chars[idx]; idx < len; ++idx, ++c) {
		if (*c == needle)
			return idx;
	}
	return -1;
}

// String.indexOf(char)
x10_int _ZN3x104lang6String7indexOfEDi(const x10_string *self, x10_char c)
{
	return _ZN3x104lang6String7indexOfEDii(self, c, 0);
}

// String.indexOf(String, int)
x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(const x10_string *self, const x10_string *other, x10_int idx)
{
	x10_null_check(other);
	if (idx < 0)
		idx = 0;

	/* TODO: use a less naive implementation */
	const x10_int   len        = self->len;
	const x10_char *needle     = other->chars;
	const x10_int   needle_len = other->len;
	for (const x10_char *haystack = &self->chars[idx]; idx < (len-needle_len+1); ++idx) {
		if (equals(haystack, needle, needle_len))
			return idx;
	}
	return -1;
}

// String.indexOf(String)
x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	return _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(self, other, 0);
}

// String.lastIndexOf(char, int)
x10_int _ZN3x104lang6String11lastIndexOfEDii(const x10_string *self, x10_char needle, x10_int idx)
{
	const x10_int len = self->len;
	if (idx >= len)
		idx = len-1;

	for (const x10_char *c = &self->chars[idx]; idx >= 0; --c, --idx) {
		if (*c == needle)
			return idx;
	}
	return -1;
}

// String.lastIndexOf(char)
x10_int _ZN3x104lang6String11lastIndexOfEDi(const x10_string *self, x10_char c)
{
	return _ZN3x104lang6String11lastIndexOfEDii(self, c, self->len-1);
}

// String.lastIndexOf(String, idx)
x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(const x10_string *self, const x10_string *other, x10_int idx)
{
	x10_null_check(other);
	const x10_int len        = self->len;
	const x10_int needle_len = other->len;
	if (idx >= len-needle_len+1)
		idx = len-needle_len;

	/* TODO: use a less naive implementation */
	idx -= needle_len-1;
	const x10_char *needle = other->chars;
	for (const x10_char *haystack = &self->chars[idx]; idx >= 0; --idx) {
		if (equals(haystack, needle, needle_len))
			return idx;
	}
	return -1;
}

// String.lastIndexOf(String)
x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	return _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(self, other, self->len - other->len);
}

// String.substring(String, int)
x10_string *_ZN3x104lang6String9substringEi(const x10_string *self, x10_int start_idx)
{
	check_string_bounds(self, start_idx);
	const x10_int len = self->len - start_idx;
	return x10_string_literal(len, &self->chars[start_idx]);
}

// String.substring(String, int, int)
x10_string *_ZN3x104lang6String9substringEii(const x10_string *self, x10_int start_idx, x10_int to_idx)
{
	check_string_bounds(self, start_idx);
	check_string_bounds(self, to_idx);
	if (start_idx > to_idx)
		x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("In substring"));

	const x10_int len = to_idx - start_idx;
	return x10_string_literal(len, &self->chars[start_idx]);
}

// String.endsWith
x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const x10_int other_len = other->len;
	const x10_int self_len  = self->len;
	const x10_int start     = self_len - other_len;
	if (start < 0)
		return X10_FALSE;
	const x10_char *haystack = &self->chars[start];
	return equals(haystack, other->chars, other_len);
}

// String.startsWith(String)
x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const x10_int self_len  = self->len;
	const x10_int other_len = other->len;
	if (other_len > self_len)
		return X10_FALSE;

	return equals(self->chars, other->chars, other_len);
}

// String.trim()
x10_string *_ZN3x104lang6String4trimEv(const x10_string *self)
{
	const x10_int   len   = self->len;
	const x10_char *chars = self->chars;

	x10_int begin;
	for (begin = 0; begin < len; ++begin) {
		if (!_ZN3x104lang4Char12isWhitespaceEv(chars[begin]))
			break;
	}
	x10_int end;
	for (end = len; end-- > 0;) {
		if (!_ZN3x104lang4Char12isWhitespaceEv(chars[begin]))
			break;
	}
	return x10_string_literal(end-begin, &chars[begin]);
}

// String.toLowerCase()
x10_string *_ZN3x104lang6String11toLowerCaseEv(const x10_string *self)
{
	const x10_int   self_len     = self->len;
	const x10_char *self_chars   = self->chars;
	x10_string     *result       = x10_allocate_string(self_len);
	x10_char       *result_chars = x10_init_string(result, self_len);
	x10_int         i;
	for(i = 0; i < self_len; i++) {
		result_chars[i] = _ZN3x104lang4Char11toLowerCaseEv(self_chars[i]);
	}
	return result;
}

// String.toUpperCase()
x10_string *_ZN3x104lang6String11toUpperCaseEv(const x10_string *self)
{
	const x10_int   self_len     = self->len;
	const x10_char *self_chars   = self->chars;
	x10_string     *result       = x10_allocate_string(self_len);
	x10_char       *result_chars = x10_init_string(result, self_len);
	x10_int         i;
	for(i = 0; i < self_len; i++) {
		result_chars[i] = _ZN3x104lang4Char11toUpperCaseEv(self_chars[i]);
	}
	return result;
}

// String.compareTo(String)
x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	x10_null_check(other);
	const x10_int   self_len    = self->len;
	const x10_int   other_len   = other->len;
	const x10_int   min_len     = MIN(self_len, other_len);
	const x10_char *self_chars  = self->chars;
	const x10_char *other_chars = other->chars;

	for (x10_int i = 0; i < min_len; ++i) {
		if (self_chars[i] != other_chars[i]) {
			return (x10_int)self_chars[i] - (x10_int)other_chars[i];
		}
	}
	return self_len - other_len;
}

// String.compareToIgnoreCase(String)
x10_int _ZN3x104lang6String19compareToIgnoreCaseEPN3x104lang6StringE(
		const x10_string *self, const x10_string *other)
{
	x10_null_check(other);
	const x10_int   self_len    = self->len;
	const x10_int   other_len   = other->len;
	const x10_int   min_len     = MIN(self_len, other_len);
	const x10_char *self_chars  = self->chars;
	const x10_char *other_chars = other->chars;

	for (x10_int i = 0; i < min_len; ++i) {
		x10_char u1 = _ZN3x104lang4Char11toUpperCaseEv(self_chars[i]);
		x10_char u2 = _ZN3x104lang4Char11toUpperCaseEv(other_chars[i]);
		if (self_chars[i] != other_chars[i]) {
			return (x10_int)u1 - (x10_int)u2;
		}
	}
	return self_len - other_len;
}

x10_string *_ZN3x104lang6String8typeNameEv(const x10_string *self)
{
	X10_UNUSED(self);
	return x10_string_literal(sizeof("x10.lang.String")-1, "x10.lang.String");
}

// static operator+(String, String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(const x10_string *x, const x10_string *y)
{
	const x10_int x_len  = x->len;
	const x10_int y_len  = y->len;
	const x10_int len    = x_len + y_len;
	x10_string   *result = x10_allocate_string(len);
	x10_char     *buffer = x10_init_string(result, len);

	memcpy(buffer, x->chars, x_len*sizeof(buffer[0]));
	memcpy(&buffer[x_len], y->chars, y_len*sizeof(buffer[0]));
	return result;
}

// operator+(String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(const x10_string *self, const x10_string *other)
{
	return _ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(self, other);
}
