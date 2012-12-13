#include <pthread.h>
#include <errno.h>

#include "x10_lock.h"
#include "util.h"
#include "init.h"
#include "posix_types.h"

void _ZN3x104util10concurrent4LockC1Ev(x10_lock *self)
{
    // create lock attributes object
    // ??check the return code for ENOMEM and throw OutOfMemoryError??
    (void)pthread_mutexattr_init(&(self->__lock_attr));

    // set lock type to reentrant
    int type = PTHREAD_MUTEX_RECURSIVE;
    pthread_mutexattr_settype(&(self->__lock_attr), type);

    // whether this lock is shared by threads across places
    // if so, set this to PTHREAD_PROCESS_SHARED
    int pshared = PTHREAD_PROCESS_PRIVATE;
    pthread_mutexattr_setpshared(&(self->__lock_attr), pshared);

#ifdef PTHREAD_PRIO_NONE
    // we are not currently implementing any fairness policy
    int protocol = PTHREAD_PRIO_NONE;
    pthread_mutexattr_setprotocol(&(self->__lock_attr), protocol);
#endif

    // create lock object
    // ??check the return code for ENOMEM and throw OutOfMemoryError??
    (void)pthread_mutex_init(&(self->__lock), &(self->__lock_attr));
}

void _ZN3x104util10concurrent4Lock4lockEv(x10_lock *self)
{
    // blocks until the lock becomes available
    pthread_mutex_lock(&(self->__lock));
}

x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(x10_lock *self)
{
    // acquire the lock only if it is not held by another thread
    if (pthread_mutex_trylock(&(self->__lock)) == 0) {
        return X10_TRUE;
    }
    return X10_FALSE;
}

void _ZN3x104util10concurrent4Lock6unlockEv(x10_lock *self)
{
    // calling thread doesn't own the lock
    if (pthread_mutex_unlock(&(self->__lock)) == EPERM) {
        x10_throw_exception(X10_ILLEGAL_MONITOR_STATE_EXCEPTION, T_(""));
    }
}

x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(x10_lock *self)
{
    // hack, until we find someway to do this reliably
    #ifdef _AIX
    #ifdef __64BIT__
        /**
         * typdef struct { long __mt_word[8]; } pthread_mutext_t;
         * 3rd element [index 2] contains basic lock status
         * 8th element [index 7] contains multiple of (UINT_MAX+1)
         * times number of additional recursive locks
         */
        if (self->__lock.__mt_word[2]) {
            long multiple = UINT_MAX;
            multiple += 1;
            int rlocks = (self->__lock.__mt_word[7])/multiple;
            return (rlocks + 1);
        }
        return 0;
    #else /* !__64BIT__ */
        /**
         * typedef struct { int __mt_word[13]; } pthread_mutex_t;
         * 5th element [index 4] contains basic lock status
         * 9th element [index 8] contains additional recursive locks
         */
        if (self->__lock.__mt_word[4]) {
            return (self->__lock.__mt_word[8] + 1);
        }
        return 0;
    #endif /* __64BIT__ */
    #else /* !_AIX */
    X10_UNUSED(self);
        return -1;
    #endif /* _AIX */
}

pthread_mutex_t x10_op_lock;

void init_locks(void)
{
	pthread_mutex_init(&x10_op_lock, NULL);
}

void destroy_locks(void)
{
	pthread_mutex_destroy(&x10_op_lock);
}
