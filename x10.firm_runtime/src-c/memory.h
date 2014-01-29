#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

/**
 * Allocate @p size bytes in tile-local memory (heap on POSIX).
 */
void *mem_allocate_tlm(size_t size);
/**
 * Allocate @p size bytes on the heap.
 */
void *mem_allocate_global(size_t size);

void mem_free_tlm(void *tlm_ptr);

#endif
