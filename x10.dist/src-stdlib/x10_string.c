#include "x10_string.h"

#define X10_ALLOC_STRING(len) (x10_string *)X10_MALLOC(sizeof(x10_string) + (((len) + 1) * sizeof(x10_char)))

#define X10_STRING_INIT(str, len) \
	X10_INIT_OBJECT(str, T_OBJECT); \
	X10_STRING_LEN(str) = len;

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
x10_int _ZN3x104lang6String6lengthEv(x10_string *self)
{
	return X10_STRING_LEN(self);
}

x10_string *_ZN3x104lang6String8toStringEv(x10_string *self)
{
	return self;
}

x10_string *_ZN3x104lang6String8typeNameEv(x10_string *self)
{
	UNUSED(self);
	return x10_string_from_wide_chars(L"x10.lang.String");
}

// operator+(String)
x10_string *_ZN3x104lang6StringplIN3x104lang6StringEEEN3x104lang6StringEPN3x104lang6StringEPN3x104lang6StringE(x10_string *self, x10_string *other)
{
	// TODO memory management/garbage collection
	const size_t len = X10_STRING_LEN(self) + X10_STRING_LEN(other);
	x10_string *str = X10_ALLOC_STRING(len);
	assert(str != NULL);

	X10_STRING_INIT(str, len);

	memcpy((void *)X10_STRING_BUF(str), (const void *)X10_STRING_BUF(self), X10_STRING_LEN(self) * sizeof(x10_char));
	memcpy((void *)&X10_STRING_CHAR(str, X10_STRING_LEN(self)), (const void *)X10_STRING_BUF(other), X10_STRING_LEN(other) * sizeof(x10_char));
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



