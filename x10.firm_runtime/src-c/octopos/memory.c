/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 * Copyright (C) 2013-2013 Karlsruhe Institute of Technology.  All right reserved.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.
 *
 * Licensees holding valid libFirm Professional Edition licenses may use
 * this file in accordance with the libFirm Commercial License.
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

#include "octo_memory.h"
#include "xmalloc.h"

void *mem_allocate_tlm(size_t size)
{
#ifdef __x86_64__
	// use the normal GC allocator on amd64, because TLM == SHM
	// gc_xmalloc already does error checking
	return gc_xmalloc(size);
#else
	void *result = mem_allocate(MEM_TLM_LOCAL, size);
	if (result == NULL && size != 0) {
		fputs("out of tile local memory\n", stderr);
		abort();
	}
	return result;
#endif
}

void *mem_allocate_global(size_t size)
{
#ifdef NO_GARBAGE_COLLECTION
#	ifdef __x86_64__
		return mem_allocate(MEM_TLM_LOCAL, size);
#	else
		return mem_allocate(MEM_SHM, size);
#	endif
#else
	(void)size;
	panic("All heap allocations should go through the garbage collector");
#endif
}

void mem_free_tlm(void *tlm_ptr)
{
#ifdef __x86_64__
	// on amd64 the normal GC allocator is used for TLM allocations
	(void)tlm_ptr;
#else
	mem_free(tlm_ptr);
#endif
}

x10_pointer _ZN7octopos6Memory11allocateTLMEi(x10_int size)
{
	return mem_allocate_tlm(size);
}
