#include "x10_string.h"

#define X10_ALLOC_STRING(len) (x10_string *)XMALLOC(sizeof(x10_string) + (((len) + 1) * sizeof(x10_char)))

static x10_string *x10_string_from_wide_buf(const size_t len, const x10_char *wchars) {
	// TODO memory management/garbage collection
	x10_string *str = X10_ALLOC_STRING(len);
	assert(str != NULL); // TODO out of memory exception?!

	X10_INIT_OBJECT(str, T_STRING);
	
	X10_STRING_LEN(str) = len;
	memcpy((void *)X10_STRING_BUF(str), (const void *)wchars, len * sizeof(x10_char));
	X10_STRING_BUF(str)[len] = L'\0';

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
X10_EXTERN x10_int _ZN3x104lang6String6lengthEv(x10_string *self)
{
	return X10_STRING_LEN(self);
}

