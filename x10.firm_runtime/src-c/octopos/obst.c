#include "obst.h"
#include "memory.h"

void *obstack_chunk_alloc(size_t bytes)
{
	return mem_allocate_tlm(bytes);
}

void obstack_chunk_free(void *ptr)
{
	mem_free_tlm(ptr);
}
