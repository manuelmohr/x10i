#ifndef X10_ATOMIC_OPS_H
#define X10_ATOMIC_OPS_H

#include "types.h"

static inline x10_int x10_atomic_ops_compareAndSet_32(volatile x10_int* address,
	x10_int oldValue, x10_int newValue)
{
#if defined(__sparc__) && !defined(NDEBUG)
	if ((void*)address < (void*)0x80000000 || (void*)address > (void*)0x807FFFFF) {
		fprintf(stderr, "CAS on non-TLM address! addr=%p\n", address);
		abort();
	}
#endif
#if defined(__leon__) && !defined(__CPARSER__)
	// in case of sparc-elf-gcc gcc does not produce a cas instruction for a
	// __sync_val_compare_and_swap so we use inline assembly
	__asm__ __volatile__("stbar\n\tcas [%[addr]], %[old], %[new]"
	                    : [new] "+r" (newValue)
	                    : [addr] "r" (address), [old] "r" (oldValue)
	                    : "memory");
	return newValue;
#else
	return __sync_val_compare_and_swap(address, oldValue, newValue);
#endif
}

/**
 * Ensure that all loads before the barrier have loaded their
 * data before any load after the data accesses its data.
 */
void _ZN3x104util10concurrent6Fences15loadLoadBarrierEv(void);

/**
 * Ensure that all loads before the barrier have loaded
 * their data before any data stored by a store after
 * the barrier has been flushed.
 */
void _ZN3x104util10concurrent6Fences16loadStoreBarrierEv(void);

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for loads after the
 * barrier is accessed.
 */
void _ZN3x104util10concurrent6Fences16storeLoadBarrierEv(void);

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for stores after
 * the barrier is flushed.
 */
void _ZN3x104util10concurrent6Fences17storeStoreBarrierEv(void);

#endif
