#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"

struct x10_string { 
	x10_char *buf;
	x10_char_int len;
};

X10_EXTERN const x10_string *x10_string_literal(const x10_char_int, const x10_char *);

#endif // X10_STRING_H_
