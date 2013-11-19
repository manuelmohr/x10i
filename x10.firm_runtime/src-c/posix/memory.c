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

#include "xmalloc.h"
#include "memory.h"

void *mem_allocate_tlm(size_t size)
{
	/* Will call GC_MALLOC/malloc depending on NO_GARBAGE_COLLECTION */
	return gc_xmalloc(size);
}

void *mem_allocate_global(size_t size)
{
#ifdef NO_GARBAGE_COLLECTION
	return malloc(size);
#else
	(void)size;
	panic("All heap allocations should go through the garbage collector");
#endif
}

void mem_free_tlm(void *tlm_ptr)
{
	/* Will call GC_FREE/free depending on NO_GARBAGE_COLLECTION */
	gc_free(tlm_ptr);
}

void *mem_get_global_address(void *tlm_local_ptr)
{
	return tlm_local_ptr;
}

void *mem_get_local_address(void *tlm_global_ptr)
{
	return tlm_global_ptr;
}
