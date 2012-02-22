#include "x10_assert.h"

#include <stdlib.h>

void x10_assert(x10_boolean cond, x10_string* message, x10_string* position)
{
	if (!cond) {
		puts("assert at \"");
		x10_write_block(position->chars, position->len);
		puts("\" failed");
		if (message) {
			puts(":\n");
			x10_write_block(message->chars, message->len);
			putchar('\n');
		}
		abort();
	}
}
