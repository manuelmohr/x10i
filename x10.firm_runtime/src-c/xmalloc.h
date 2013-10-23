/*
 * This file is part of libFirm.
 * Copyright (C) 2012 University of Karlsruhe.
 */

/**
 * @file
 * @brief       never failing wrappers for malloc() & friends.
 * @author      Markus Armbruster
 * @note        The functions here never fail because they simply abort your
 *              program in case of an error.
 */
#ifndef FIRM_ADT_XMALLOC_H
#define FIRM_ADT_XMALLOC_H

#include "begin.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#ifdef NO_GARBAGE_COLLECTION
static inline void gc_free(void *ptr)
{
	free(ptr);
}

static inline void gc_init(void)
{
}
#else
#define GC_THREADS
#include <gc.h>
static inline void gc_free(void *ptr)
{
	GC_FREE(ptr);
}

static inline void gc_init(void)
{
	GC_INIT();
}
#endif

/**
 * @ingroup adt
 * @defgroup xmalloc Memory Allocation
 * @{
 */

/**
 * Allocate @p size bytes on the heap.
 * This is a wrapper for malloc/calloc which calls panic() in case of errors,
 * so no error handling is required for code using it. The memory allocated with
 * this function is set to 0.
 */
FIRM_API void *gc_xmalloc(size_t size);
/**
 * Allocate @p size bytes on the heap.
 * This is a variant of gc_xmalloc(), but the resulting memory mustn't contain
 * any pointers (or the garbage collection behaviour is undefined). Furthermore
 * the memory returned is uninitialized and not necessarily set to 0.
 */
FIRM_API void *gc_xmalloc_atomic(size_t size);
/**
 * Change size of a previously allocated memory block to @p size bytes.
 * This is a wrapper for GC_realloc which calls panic() in case of errors, so no
 * error handling is required for code using it.
 */
FIRM_API void *gc_xrealloc(void *ptr, size_t size);
/** like gc_xrealloc() but if the memory was allocated with gc_xmalloc() and
 * not with gc_xmalloc_atomic() then it is ensured that when growing the newly
 * allocated space is zeroed. */
FIRM_API void *gc_xrealloc_zeroed(void *ptr, size_t prev_size, size_t size);
/**
 * Allocates memory and copies string @p str into it.
 * This is a wrapper for strdup which calls panic() in case of errors, so no
 * error handling is required for code using it.
 */
FIRM_API char *gc_xstrdup(const char *str);

/**
 * Allocate n objects of a certain type
 */
#define GC_XMALLOCN(type, n) ((type*)gc_xmalloc(sizeof(type) * (n)))

/**
 * Allocate n objects of a certain type and zero them
 */
#define GC_XMALLOCNZ(type, n) ((type*)memset(gc_xmalloc(sizeof(type) * (n)), 0, sizeof(type) * (n)))

/**
 * Allocate one object of a certain type
 */
#define GC_XMALLOC(type) GC_XMALLOCN(type, 1)

/**
 * Allocate one object of a certain type and zero it
 */
#define GC_XMALLOCZ(type) GC_XMALLOCNZ(type, 1)

/**
 * Reallocate n objects of a certain type
 */
#define GC_XREALLOC(ptr, type, n) ((type*)gc_xrealloc(ptr, sizeof(type) * (n)))

/**
 * Allocate an object with n elements of a flexible array member
 */
#define GC_XMALLOCF(type, member, n) ((type*)gc_xmalloc(offsetof(type, member) + sizeof(*((type*)0)->member) * (n)))

/**
 * Allocate an object with n elements of a flexible array member and zero the
 * whole object
 */
#define GC_XMALLOCFZ(type, member, n) ((type*)memset(XMALLOCF(type, member, (n)), 0, offsetof(type, member) + sizeof(*((type*)0)->member) * (n)))

/**
 * Allocate n objects of a certain type on the given obstack
 */
#define OALLOCN(obst, type, n) ((type*)obstack_alloc((obst), sizeof(type) * (n)))

/**
 * Allocate n objects of a certain type on the given obstack and zero them
 */
#define OALLOCNZ(obst, type, n) ((type*)memset(OALLOCN((obst), type, (n)), 0, sizeof(type) * (n)))

/**
 * Allocate one object of a certain type on the given obstack
 */
#define OALLOC(obst, type) OALLOCN(obst, type, 1)

/**
 * Allocate one object of a certain type on the given obstack and zero it
 */
#define OALLOCZ(obst, type) OALLOCNZ(obst, type, 1)

/**
 * Allocate an object with n elements of a flexible array member on the given
 * obstck
 */
#define OALLOCF(obst, type, member, n) ((type*)obstack_alloc((obst), offsetof(type, member) + sizeof(*((type*)0)->member) * (n)))

/**
 * Allocate an object with n elements of a flexible array member on the given
 * obstack and zero the whole object
 */
#define OALLOCFZ(obst, type, member, n) ((type*)memset(OALLOCF((obst), type, member, (n)), 0, offsetof(type, member) + sizeof(*((type*)0)->member) * (n)))

/** @} */

#endif
