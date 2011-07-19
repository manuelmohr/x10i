#include "x10_assert.h"

#include <stdlib.h>

X10_EXTERN void x10_assert(x10_boolean cond, x10_string* message,
		x10_string* position)
{
	if (!cond) {
		if (!message)
			fwprintf(stderr, T_("assert at \"%.*ls\" failed.\n"),
					x10_string_len(position), x10_string_buf(position));
		else
			fwprintf(stderr, T_("assert at \"%.*ls\" failed:\n%.*ls\n"),
					x10_string_len(position), x10_string_buf(position),
					x10_string_len(message),  x10_string_buf(message));

		abort();
	}
}
