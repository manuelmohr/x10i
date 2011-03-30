#include "x10_string.h"

const x10_string *_Z18x10_string_literalEJPN6StringEP6JArrayIjE(const x10_char_int length, const x10_char *wchars) {
	// TODO memory management/garbage collection
	// FIXME assumes that buf is const
	x10_string *str = (x10_string *)XMALLOC(x10_string);

	assert (str != NULL); // TODO out of memory exception?!
	str->len = length;
	str->buf = wchars;
	return str;
}

void _ZN7Printer7printlnEJvPN3AnyE(x10_string *self, x10_any any) {
	// FIXME Any is not String in general!
	x10_string *str = (x10_string *)any;
	x10_char_int i;

	(void)self;

	for(i = 0; i < str->len; i++) {
	   putchar(str->buf[i]);
	}
	
	putchar('\n');
}
