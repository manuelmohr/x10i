#include "platform_atomic_ops.h"
#include "x10_lock_octopos.h"

simple_spinlock x10_op_lock;

static void __attribute__((constructor)) init_locks(void)
{
	simple_spinlock_init(&x10_op_lock);
}

/* x10.util.concurrent.Lock.this(): Lock */
void _ZN3x104util10concurrent4LockC1Ev(x10_lock *self)
{
	simple_spinlock_init(&self->lock);
}

/* Lock.lock() */
void _ZN3x104util10concurrent4Lock4lockEv(x10_lock *self)
{
	simple_spinlock_lock(&self->lock);
}

/* Lock.tryLock(): Boolean */
x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(x10_lock *self)
{
	return simple_spinlock_trylock(&self->lock);
}

/* Lock.unlock() */
void _ZN3x104util10concurrent4Lock6unlockEv(x10_lock *self)
{
	simple_spinlock_unlock(&self->lock);
}

x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(x10_lock *self)
{
	(void)self;
	return -1;
}
