#include "x10_lock_octopos.h"

/* x10.util.concurrent.Lock.this(): Lock */
void _ZN3x104util10concurrent4LockC1Ev(x10_lock *self)
{
	recursive_spinlock_init(&self->lock);
}

/* Lock.lock() */
void _ZN3x104util10concurrent4Lock4lockEv(x10_lock *self)
{
	recursive_spinlock_lock(&self->lock);
}

/* Lock.tryLock(): Boolean */
x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(x10_lock *self)
{
	return recursive_spinlock_trylock(&self->lock) == 1;
}

/* Lock.unlock() */
void _ZN3x104util10concurrent4Lock6unlockEv(x10_lock *self)
{
	recursive_spinlock_unlock(&self->lock);
}

x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(x10_lock *self)
{
	(void)self;
	return -1;
}
