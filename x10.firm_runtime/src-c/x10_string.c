#include "x10_string.h"
#include "util.h"
#include "x10.h"
#include "x10_serialization.h"

/* vtable for x10.lang.String */
extern const x10_vtable _ZTVN3x104lang6StringE;

static void check_string_bounds(const x10_string *str, x10_int idx)
{
	if (idx < 0 || idx > (str->len)) {
		x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("Within string bounds check"));
	}
}

static x10_char *allocate_chars(x10_int len)
{
	return malloc(sizeof(x10_char) * len);
}

x10_string *x10_string_from_literal(x10_int len, const x10_char *chars)
{
	x10_string *str = X10_ALLOC_OBJECT(x10_string, &_ZTVN3x104lang6StringE);
	str->len   = len;
	str->chars = chars;
	return str;
}

static x10_string *x10_string_copy_from(x10_int len, const x10_char *chars)
{
	x10_char *new_chars = allocate_chars(len);
	memcpy(new_chars, chars, len * sizeof(new_chars[0]));
	return x10_string_from_literal(len, new_chars);
}

x10_string *x10_string_from_cstring_len(size_t len, const char *string)
{
	assert(sizeof(string[0]) == sizeof(x10_char));
	assert(len == (size_t)(x10_int)len);
	return x10_string_copy_from((x10_int)len, (const x10_char*)string);
}

x10_string *x10_string_from_cstring(const char *string)
{
	return x10_string_from_cstring_len(strlen(string), string);
}

/* String.this(): String */
void x10_string_create_empty(x10_string *str)
{
	str->len   = 0;
	str->chars = NULL;
}

/* String.this(Int,Pointer): String */
void x10_string_create_from_pointer(x10_string *str, x10_int len, const void *data)
{
	str->len   = len;
	str->chars = (const x10_char*)data;
}

/* String.this(String): String */
void x10_string_create_duplicate(x10_string *str, const x10_string *other)
{
	str->len   = other->len;
	str->chars = other->chars;
}

static inline bool equals(const x10_char *chars0, const x10_char *chars1,
                          const x10_int len)
{
	/* Note: do not use str(n)cmp here because it stops at '\0' chars */
	return memcmp(chars0, chars1, len) == 0;
}

// String.equals(String other)
x10_boolean x10_string_equals(
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
x10_boolean x10_string_equals_ignore_case(
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
x10_int x10_string_hash_code(const x10_string *self)
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
x10_int x10_string_length(const x10_string *self)
{
	return self->len;
}

// String.charAt(int)
x10_char x10_string_char_at(const x10_string *self, x10_int idx)
{
	check_string_bounds(self, idx);
	return self->chars[idx];
}

// String.indexOf(char, int)
x10_int x10_string_index_of_char_from(const x10_string *self, x10_char needle, x10_int idx)
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
x10_int x10_string_index_of_char(const x10_string *self, x10_char c)
{
	return x10_string_index_of_char_from(self, c, 0);
}

// String.indexOf(String, int)
x10_int x10_string_index_of_string_from(const x10_string *self, const x10_string *other, x10_int idx)
{
	x10_null_check(other);
	if (idx < 0)
		idx = 0;

	/* TODO: use a less naive implementation */
	const x10_int   len        = self->len;
	const x10_char *needle     = other->chars;
	const x10_int   needle_len = other->len;
	for ( ; idx < (len-needle_len+1); ++idx) {
		const x10_char *haystack = &self->chars[idx];
		if (equals(haystack, needle, needle_len))
			return idx;
	}
	return -1;
}

// String.indexOf(String)
x10_int x10_string_index_of_string(const x10_string *self, const x10_string *other)
{
	return x10_string_index_of_string_from(self, other, 0);
}

// String.lastIndexOf(char, int)
x10_int x10_string_last_index_of_char_from(const x10_string *self, x10_char needle, x10_int idx)
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
x10_int x10_string_last_index_of_char(const x10_string *self, x10_char c)
{
	return x10_string_last_index_of_char_from(self, c, self->len-1);
}

// String.lastIndexOf(String, idx)
x10_int x10_string_last_index_of_string_from(const x10_string *self, const x10_string *other, x10_int idx)
{
x10_null_check(other);
const x10_int len        = self->len;
const x10_int needle_len = other->len;
if (idx >= len-needle_len+1)
	idx = len-needle_len;

/* TODO: use a less naive implementation */
idx -= needle_len-1;
const x10_char *needle = other->chars;
for ( ; idx >= 0; --idx) {
	const x10_char *haystack = &self->chars[idx];
	if (equals(haystack, needle, needle_len))
		return idx;
}
return -1;
}

// String.lastIndexOf(String)
x10_int x10_string_last_index_of_string(const x10_string *self, const x10_string *other)
{
	return x10_string_last_index_of_string_from(self, other, self->len - other->len);
}

// String.substring(String, int): String
x10_string *x10_string_substring_from(const x10_string *self, x10_int start_idx)
{
check_string_bounds(self, start_idx);
const x10_int len = self->len - start_idx;
return x10_string_copy_from(len, &self->chars[start_idx]);
}

// String.substring(String, int, int)
x10_string *x10_string_substring_from_to(const x10_string *self, x10_int start_idx, x10_int to_idx)
{
check_string_bounds(self, start_idx);
check_string_bounds(self, to_idx);
if (start_idx > to_idx)
	x10_throw_exception(X10_INDEX_OUT_OF_BOUNDS_EXCEPTION, T_("In substring"));

const x10_int len = to_idx - start_idx;
return x10_string_copy_from(len, &self->chars[start_idx]);
}

// String.endsWith(String): Boolean
x10_boolean x10_string_ends_with(const x10_string *self, const x10_string *other)
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

// String.startsWith(String): Boolean
x10_boolean x10_string_starts_with(const x10_string *self, const x10_string *other)
{
	if (other == X10_NULL)
		return X10_FALSE;

	const x10_int self_len  = self->len;
	const x10_int other_len = other->len;
	if (other_len > self_len)
		return X10_FALSE;

	return equals(self->chars, other->chars, other_len);
}

// String.trim(): String
x10_string *x10_string_trim(const x10_string *self)
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
		if (!_ZN3x104lang4Char12isWhitespaceEv(chars[end]))
			break;
	}
	return x10_string_copy_from(end-begin+1, &chars[begin]);
}

x10_string *x10_string_format(const x10_string *format, const void *args)
{
	X10_UNUSED(format);
	X10_UNUSED(args);
	X10_UNIMPLEMENTED();
}

// String.toLowerCase(): String
x10_string *x10_string_to_lowercase(const x10_string *self)
{
	const x10_int   self_len   = self->len;
	const x10_char *self_chars = self->chars;
	x10_char       *new_chars  = allocate_chars(self_len);
	for(x10_int i = 0; i < self_len; i++) {
		new_chars[i] = _ZN3x104lang4Char11toLowerCaseEv(self_chars[i]);
	}
	return x10_string_from_literal(self_len, new_chars);
}

// String.toUpperCase(): String
x10_string *x10_string_to_uppercase(const x10_string *self)
{
	const x10_int   self_len   = self->len;
	const x10_char *self_chars = self->chars;
	x10_char       *new_chars  = allocate_chars(self_len);
	for(x10_int i = 0; i < self_len; i++) {
		new_chars[i] = _ZN3x104lang4Char11toUpperCaseEv(self_chars[i]);
	}
	return x10_string_from_literal(self_len, new_chars);
}

// String.compareTo(String): Int
x10_int x10_string_compare(const x10_string *self, const x10_string *other)
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

// String.compareToIgnoreCase(String): Int
x10_int x10_string_compare_ignoring_case(
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

// String.typeName(): String
x10_string *x10_string_type_name(const x10_string *self)
{
	X10_UNUSED(self);
	return X10_STRING_FROM_CLITERAL("x10.lang.String");
}

// operator+(String): String
x10_string *x10_string_concat(const x10_string *self, const x10_string *x)
{
	const x10_int self_len  = self->len;
	const x10_int x_len     = x->len;
	const x10_int len       = self_len + x_len;
	x10_char     *new_chars = allocate_chars(len);
	memcpy(new_chars, self->chars, self_len*sizeof(new_chars[0]));
	memcpy(&new_chars[self_len], x->chars, x_len*sizeof(new_chars[0]));
	return x10_string_from_literal(len, new_chars);
}

// String.getPointer(): Pointer
x10_pointer x10_string_get_pointer(const x10_string *self)
{
	return (x10_pointer)self->chars;
}

void x10_string_serialize(serialization_buffer_t *buf, const x10_string *self)
{
	_ZN3x104lang6Object11__serializeEPvPv(buf, &self->base);
	x10_serialization_write_primitive(buf, &self->len, sizeof(x10_int));
	x10_serialization_write_primitive(buf, self->chars, self->len * sizeof(x10_char));
}

void x10_string_deserialize(deserialization_buffer_t *buf, x10_string *self)
{
	_ZN3x104lang6Object13__deserializeEPvPv(buf, &self->base);
	x10_deserialization_restore_primitive(buf, &self->len, sizeof(x10_int));
	self->chars = allocate_chars(self->len);
	x10_deserialization_restore_primitive(buf, (void *)self->chars, self->len * sizeof(x10_char));
}
