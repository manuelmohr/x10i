#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"

struct x10_string {
	X10_OBJECT_HEADER
	size_t len;
	x10_char buf[1];
};

#define T_(x) L##x

#define X10_STRING_LEN(s) ((s)->len)
#define X10_STRING_BUF(s) ((s)->buf)

X10_EXTERN x10_string *x10_string_from_wide_chars(const x10_char *);

X10_EXTERN x10_string *x10_string_literal(size_t, x10_char *);

// String methods
X10_EXTERN x10_int _ZN3x104lang6String6lengthEv(x10_string *);

#endif // X10_STRING_H_
