#include "x10_string.h"
#include "util.h"

#define X10_ALLOC_STRING(len) (x10_string *)x10_malloc(sizeof(x10_string) + (((len) + 1) * sizeof(x10_char)))

#define X10_STRING_INIT(str, len) \
	X10_INIT_OBJECT(str, T_STRING); \
	X10_STRING_LEN(str) = len;

// check string bounds; return IndexOutOfRangeException 
#define X10_CHECK_STRING_BOUNDS(self, idx) \
	if (idx < 0 || (x10_uint)idx > X10_STRING_LEN(self)) { \
		x10_throw_exception(X10IndexOutOfBoundsException);	\
	}

static x10_string *x10_string_from_wide_buf(const size_t len, const x10_char *wchars) {
	// TODO memory management/garbage collection
	x10_string *str = X10_ALLOC_STRING(len);
	assert(str != NULL); // TODO out of memory exception?!
	
	X10_STRING_INIT(str, len);

	memcpy((void *)X10_STRING_BUF(str), (const void *)wchars, len * sizeof(x10_char));
	X10_STRING_BUF(str)[len] = T_('\0');

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

// String methods

x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE(x10_string *self, x10_any *other)
{
	if(other == X10_NULL) return X10_FALSE;
	if(!X10_INSTANCE_OF(other, T_STRING)) return X10_FALSE; 
	const x10_string *oth = X10_OBJECT_CAST(x10_string, other);
	if(X10_STRING_LEN(self) != X10_STRING_LEN(oth)) return X10_FALSE;
	if(wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(oth), X10_STRING_LEN(self)))
		return X10_FALSE;
	return X10_TRUE; 
}

x10_int _ZN3x104lang6String6lengthEv(x10_string *self)
{
	return X10_STRING_LEN(self);
}

x10_string *_ZN3x104lang6String8toStringEv(x10_string *self)
{
	return self;
}

x10_char _ZN3x104lang6String6charAtEi(x10_string *self, x10_int idx)
{
	X10_CHECK_STRING_BOUNDS(self, idx);
	return X10_STRING_CHAR(self, idx); 
}

x10_int _ZN3x104lang6String7indexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if(idx < 0) idx = 0;
	if((size_t)idx >= X10_STRING_LEN(self)) return -1;


	const x10_char *pos = wcschr(&X10_STRING_CHAR(self, idx), c);

	if(pos == NULL) return -1;

	return (pos - X10_STRING_BUF(self)); 
}

x10_int _ZN3x104lang6String7indexOfEDi(x10_string *self, x10_char c)
{
	return _ZN3x104lang6String7indexOfEDii(self, c, 0); 
}

static const x10_char *wstrnrstrn(const x10_char *haystack, size_t haystack_sz,
                             const x10_char *needle, size_t needle_sz)
{
	if(haystack_sz < needle_sz)
		return X10_NULL;

	for(size_t i = haystack_sz-needle_sz; i > 0; --i) {
		if (!wcsncmp(&haystack[i], needle, needle_sz)) {
	    		return &haystack[i];
		}
	}

	if (!wcsncmp(haystack, needle, needle_sz))
		return haystack;

	return X10_NULL;
}


x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(x10_string *self, x10_string *other, x10_int idx)
{
	x10_null_check(other); 
	if(idx < 0) idx = 0;
	if(((size_t)idx) >= X10_STRING_LEN(self)) return -1;

	const x10_char *haystack = &X10_STRING_CHAR(self, idx);
	const size_t haystack_sz = X10_STRING_LEN(self) - idx;
	const x10_char *needle = X10_STRING_BUF(other);
	const size_t needle_sz = X10_STRING_LEN(other); 
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
	return _ZN3x104lang6String11lastIndexOfEDii(self, c, X10_STRING_LEN(self) - 1); 
}

x10_int _ZN3x104lang6String11lastIndexOfEDii(x10_string *self, x10_char c, x10_int idx)
{
	if(idx < 0) idx = 0;
	if((size_t)idx >= X10_STRING_LEN(self)) return -1;

	const x10_char *pos = wcsrchr(&X10_STRING_CHAR(self, idx), c);

	if(pos == NULL) return -1;

	return (pos - X10_STRING_BUF(self)); 
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(x10_string *self, x10_string * other)
{
	return _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(self, other, X10_STRING_LEN(self) - 1); 
}

x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(x10_string *self, x10_string *other, x10_int idx)
{
	x10_null_check(other); 
	if(idx < 0) idx = 0;
	if(((size_t)idx) >= X10_STRING_LEN(self)) return -1;

	const x10_char *needle = X10_STRING_BUF(other);
	const size_t needle_sz = X10_STRING_LEN(other); 
	const x10_char *haystack = X10_STRING_BUF(self); 
	const size_t haystack_sz = idx + 1;

	const x10_char *pos = wstrnrstrn(haystack, haystack_sz, needle, needle_sz);
	if(pos == X10_NULL)
		return -1;
	return (x10_int)(pos - haystack); 
}


x10_string *_ZN3x104lang6String9substringEi(x10_string *self, x10_int start_idx)
{
	X10_CHECK_STRING_BOUNDS(self, start_idx); 
	const size_t len = X10_STRING_LEN(self) - start_idx;
	return x10_string_from_wide_buf(len, &X10_STRING_CHAR(self, start_idx)); 
}

x10_string *_ZN3x104lang6String9substringEii(x10_string *self, x10_int start_idx, x10_int to_idx)
{
	X10_CHECK_STRING_BOUNDS(self, start_idx);
	X10_CHECK_STRING_BOUNDS(self, to_idx);
	if(start_idx > to_idx) {
		x10_throw_exception(X10IndexOutOfBoundsException);
	}

	const size_t len = to_idx - start_idx;
	return x10_string_from_wide_buf(len, &X10_STRING_CHAR(self, start_idx)); 
}

x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if(other == X10_NULL) return X10_FALSE;
	const size_t len_self  = X10_STRING_LEN(self);
	const size_t len_other = X10_STRING_LEN(other); 

	if(len_other > len_self) return X10_FALSE;
	const size_t diff = len_self - len_other;

	return wcsncmp(&X10_STRING_CHAR(self, diff), X10_STRING_BUF(other), len_other) == 0 ? X10_TRUE : X10_FALSE; 
}

x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	if(other == X10_NULL) return X10_FALSE;
	const size_t len_self  = X10_STRING_LEN(self);
	const size_t len_other = X10_STRING_LEN(other);
	
	if(len_other > len_self) return X10_FALSE;

	return wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(other), len_other) == 0 ? X10_TRUE : X10_FALSE; 
}

// whitespaces are the same as in java -> Unicocode codepoints <= U0020
#define X10_IS_WS(c) (c <= 0x20) 

x10_string *_ZN3x104lang6String4trimEv(x10_string *self)
{
	x10_int len = X10_STRING_LEN(self);
	if(len == 0) return self;
	const x10_char *buf = X10_STRING_BUF(self);
	while(len > 0 && X10_IS_WS(buf[0])) { len--; buf++; }
	while(len > 0 && X10_IS_WS(buf[len - 1])) { len--; }
	if(len <= 0) return x10_string_from_wide_chars(T_("")); 
	
	return x10_string_from_wide_buf(len, buf); 
}

x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	x10_null_check(other);
    	const x10_int len_diff = X10_STRING_LEN(self) - X10_STRING_LEN(other);
    	const size_t min_len = MIN(X10_STRING_LEN(self), X10_STRING_LEN(other)); 
	const x10_int cmp = wcsncmp(X10_STRING_BUF(self), X10_STRING_BUF(other), min_len);
	if(cmp != 0) 
		return cmp;
	return len_diff; 
}

x10_string *_ZN3x104lang6String8typeNameEv(x10_string *self)
{
	UNUSED(self);
	return x10_string_from_wide_chars(T_("x10.lang.String"));
}

// operator+(String)
x10_string *_ZN3x104lang6StringplIN3x104lang6StringEEEN3x104lang6StringEPN3x104lang6StringEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	// TODO memory management/garbage collection
	const size_t len = X10_STRING_LEN(self) + X10_STRING_LEN(other);
	x10_string *str = X10_ALLOC_STRING(len);
	assert(str != NULL);

	X10_STRING_INIT(str, len);

	memcpy((void *)X10_STRING_BUF(str), (const void *)X10_STRING_BUF(self), X10_STRING_LEN_BYTES(self));
	memcpy((void *)&X10_STRING_CHAR(str, X10_STRING_LEN(self)), (const void *)X10_STRING_BUF(other), X10_STRING_LEN_BYTES(other));
	X10_STRING_BUF(str)[len] = T_('\0');

	return str;
}

// operator+ functions
#define X10_DEF_OPERATOR_PLUS(funcName, type, convFuncName) \
	X10_EXTERN x10_string *convFuncName(type); \
	x10_string *funcName(x10_string *self, type other) \
	{ \
		return _ZN3x104lang6StringplIN3x104lang6StringEEEN3x104lang6StringEPN3x104lang6StringEPN3x104lang6StringE(self, convFuncName(other)); \
	}

X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIxEEN3x104lang6StringEx,  x10_long, _ZN3x104lang4Long8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIyEEN3x104lang6StringEy,  x10_ulong, _ZN3x104lang5ULong8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIiEEN3x104lang6StringEi,  x10_int, _ZN3x104lang3Int8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIjEEN3x104lang6StringEj,  x10_uint, _ZN3x104lang4UInt8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIsEEN3x104lang6StringEs,  x10_short, _ZN3x104lang5Short8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplItEEN3x104lang6StringEt,  x10_ushort, _ZN3x104lang6UShort8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIaEEN3x104lang6StringEa,  x10_byte, _ZN3x104lang4Byte8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIhEEN3x104lang6StringEh,  x10_ubyte, _ZN3x104lang5UByte8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIDiEEN3x104lang6StringEDi, x10_char, _ZN3x104lang4Char8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIfEEN3x104lang6StringEf,  x10_float, _ZN3x104lang5Float8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIdEEN3x104lang6StringEd,  x10_double, _ZN3x104lang6Double8toStringEv)
X10_DEF_OPERATOR_PLUS(_ZN3x104lang6StringplIbEEN3x104lang6StringEb,  x10_boolean, _ZN3x104lang7Boolean8toStringEv)

#undef X10_DEF_OPERATOR_PLUS



