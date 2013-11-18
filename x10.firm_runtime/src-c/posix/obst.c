#include "obst.h"
#include "xmalloc.h"

void *obstack_chunk_alloc(size_t bytes)
{
	return gc_xmalloc(bytes);
}

void obstack_chunk_free(void *ptr)
{
	gc_free(ptr);
}
