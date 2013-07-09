#include "x10_assert.h"

#include <stdlib.h>

void x10_assert(x10_boolean cond, x10_string* message, x10_string* position)
{
	if (!cond) {
		puts("assert at \"");
		fwrite(position->chars, position->len, 1, stdout);
		puts("\" failed");
		if (message) {
			puts(":\n");
			fwrite(message->chars, message->len, 1, stdout);
			putchar('\n');
		}
		abort();
	}
}
