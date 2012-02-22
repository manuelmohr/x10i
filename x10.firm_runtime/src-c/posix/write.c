#include <stdio.h>
#include "platform.h"

void x10_write_block(const void *data, size_t size)
{
	fwrite(data, size, 1, stdout);
}
