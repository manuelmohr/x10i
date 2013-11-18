#include "obst.h"
#include <octopos.h>

void *obstack_chunk_alloc(size_t bytes)
{
	return mem_allocate(MEM_TLM_LOCAL, bytes);
}

void obstack_chunk_free(void *ptr)
{
	mem_free(ptr);
}
