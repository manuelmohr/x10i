/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 *
 * This file is part of libFirm.
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

/**
 * @file
 * @brief       implementation of xmalloc & friends
 * @author      Markus Armbruster
 */

/* @@@ ToDo: replace this file with the one from liberty.
   [reimplement xstrdup, ... ] */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "xmalloc.h"
#include "memory.h"

static void __attribute__((noreturn)) xnomem(void)
{
	/* Do not use panic() here, because it might try to allocate memory! */
	fputs("out of memory\n", stderr);
	abort();
}

#ifdef NO_GARBAGE_COLLECTION
void *gc_xmalloc(size_t size)
{
	void *res = mem_allocate_global(size);
	if (res == NULL && size != 0)
		xnomem();
	memset(res, 0, size);
	return res;
}

void *gc_xmalloc_atomic(size_t size)
{
	void *res = mem_allocate_global(size);
	if (res == NULL && size != 0)
		xnomem();
	return res;
}

void *gc_xrealloc(void *ptr, size_t size)
{
	void *result = realloc(ptr, size);
	if (result == NULL && size != 0)
		xnomem();
	return result;
}

void *gc_xrealloc_zeroed(void *ptr, size_t prev_size, size_t size)
{
	void *result = gc_xrealloc(ptr, size);
	if (size > prev_size) {
		char *p = ((char*)result) + prev_size;
		memset(p, 0, size - prev_size);
	}
	return result;
}
#else
void *gc_xmalloc(size_t size)
{
	void *res = GC_MALLOC(size);

	if (res == NULL && size != 0)
		xnomem();
	return res;
}

void *gc_xmalloc_atomic(size_t size)
{
	void *res = GC_MALLOC_ATOMIC(size);
	if (res == NULL && size != 0)
		xnomem();
	return res;
}

void *gc_xrealloc(void *ptr, size_t size)
{
	void *result = GC_REALLOC(ptr, size);
	if (result == NULL && size != 0)
		xnomem();
	return result;
}

void *gc_xrealloc_zeroed(void *ptr, size_t prev_size, size_t size)
{
	(void)prev_size;
	return gc_xrealloc(ptr, size);
}
#endif

char *xstrdup(const char *str)
{
	size_t len = strlen (str) + 1;
	return (char*) memcpy(gc_xmalloc(len), str, len);
}
