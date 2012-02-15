#ifndef X10_ATOMIC_OPS_H_
#define X10_ATOMIC_OPS_H_

#include "x10.h"

X10_EXTERN x10_int x10_atomic_ops_compareAndSet_32(volatile x10_int* address, x10_int oldValue, x10_int newValue);
X10_EXTERN x10_long x10_atomic_ops_compareAndSet_64(volatile x10_long* address, x10_long oldValue, x10_long newValue);
X10_EXTERN void* x10_atomic_ops_compareAndSet_ptr(volatile void** address, void* oldValue, void* newValue);

/**
 * Ensure that all loads before the barrier have loaded their
 * data before any load after the data accesses its data.
 */
X10_EXTERN void _ZN3x104util10concurrent6Fences15loadLoadBarrierEv(void);

/**
 * Ensure that all loads before the barrier have loaded
 * their data before any data stored by a store after
 * the barrier has been flushed.
 */
X10_EXTERN void _ZN3x104util10concurrent6Fences16loadStoreBarrierEv(void);

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for loads after the
 * barrier is accessed.
 */
X10_EXTERN void _ZN3x104util10concurrent6Fences16storeLoadBarrierEv(void);

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for stores after
 * the barrier is flushed.
 */
X10_EXTERN void _ZN3x104util10concurrent6Fences17storeStoreBarrierEv(void);

#endif
