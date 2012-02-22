#include <stdio.h>
#include "platform.h"

void x10_write_block(const void *data, size_t size)
{
	const char *buf = (const char*)data;
	for (size_t i = 0; i < size; ++i) {
		putchar(buf[i]);
	}
}
