#include "x10_assert.h"

#include <stdlib.h>

void x10_assert(x10_boolean cond, x10_string* message, x10_string* position)
{
	if (!cond) {
		printf("assert at \"");
		fwrite(position->chars, position->len, 1, stdout);
		printf("\" failed");
		if (message) {
			printf(": ");
			fwrite(message->chars, message->len, 1, stdout);
			putchar('\n');
		}
		abort();
	}
}
