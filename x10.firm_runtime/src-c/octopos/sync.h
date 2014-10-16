#define LOCK_T       simple_spinlock
#define LOCK_INIT(x) simple_spinlock_init(x)
#define LOCK_LOCK    simple_spinlock_lock
#define LOCK_UNLOCK  simple_spinlock_unlock
