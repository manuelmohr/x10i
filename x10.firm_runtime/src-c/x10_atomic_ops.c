/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */
#include "x10_atomic_ops.h"
#include "x10_object.h"

/**
 * Ensure that all loads before the barrier have loaded their
 * data before any load after the data accesses its data.
 */
void _ZN3x104util10concurrent6Fences15loadLoadBarrierEv() {
}

/**
 * Ensure that all loads before the barrier have loaded
 * their data before any data stored by a store after
 * the barrier has been flushed.
 */
void _ZN3x104util10concurrent6Fences16loadStoreBarrierEv() {
}

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for loads after the
 * barrier is accessed.
 */
void _ZN3x104util10concurrent6Fences16storeLoadBarrierEv() {
}

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for stores after
 * the barrier is flushed.
 */
void _ZN3x104util10concurrent6Fences17storeStoreBarrierEv() {
}

/* We need to access the field of an AtomicReference object
 * for a CAS operation, hence replicate the object layout. */
typedef struct {
	x10_object header;
	x10_pointer reference;
} x10_atomic_reference;

/**
 * Perform a CAS operation for an AtomicReference object
 * @param aref  this pointer of AtomicReference
 * @param old   old reference to compare with
 * @param new   new reference to set if comparison is true
 * @returns     comparison result
 */
x10_boolean x10_compare_and_set(x10_atomic_reference *aref, x10_pointer old, x10_pointer new) {
	x10_pointer *ptr = &(aref->reference);
#ifdef __x86_64__
	x10_pointer prev = (x10_pointer)x10_atomic_ops_compareAndSet_64((volatile x10_ulong*)ptr, (x10_ulong)old, (x10_ulong)new);
#else
	x10_pointer prev = (x10_pointer)x10_atomic_ops_compareAndSet_32((volatile x10_int*)ptr, (x10_int)old, (x10_int)new);
#endif
	return prev == old;
}
