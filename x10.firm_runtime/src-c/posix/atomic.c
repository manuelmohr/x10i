#include <pthread.h>
#include <stdio.h>

#include "util.h"
#include "async.h"

static pthread_cond_t      x10_atomic_cond       = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t     x10_atomic_mutex;
static pthread_mutexattr_t x10_atomic_mutex_attr;

void __attribute__((constructor)) init_mutex(void) {
	pthread_mutexattr_init(&x10_atomic_mutex_attr);
	pthread_mutexattr_settype(&x10_atomic_mutex_attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutexattr_setpshared(&x10_atomic_mutex_attr, PTHREAD_PROCESS_PRIVATE);
	pthread_mutex_init(&x10_atomic_mutex, &x10_atomic_mutex_attr);
}

void _ZN3x104lang7Runtime11enterAtomicEv(void) {
	pthread_mutex_lock(&x10_atomic_mutex);
	activity_inc_atomic_depth();
}

void _ZN3x104lang7Runtime10exitAtomicEv(void) {
	activity_dec_atomic_depth();
	pthread_mutex_unlock(&x10_atomic_mutex);
	pthread_cond_broadcast(&x10_atomic_cond);
}

void _ZN3x104lang7Runtime17ensureNotInAtomicEv(void) {
	if (activity_get_atomic_depth() > 0)
		x10_throw_exception(X10_ILLEGAL_OPERATION_EXCEPTION, T_(""));
}

void _ZN3x104lang7Runtime11awaitAtomicEv(void) {
	pthread_cond_wait(&x10_atomic_cond, &x10_atomic_mutex);
}
