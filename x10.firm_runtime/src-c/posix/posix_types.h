#ifndef POSIX_TYPES_H
#define POSIX_TYPES_H

#include <pthread.h>
#include "types.h"
#include "x10_string.h"

struct x10_place {
	x10_int id;
};

struct X10_TYPE("x10.util.concurrent.Lock") x10_lock {
	x10_object base;
	// lock id
	pthread_mutex_t __lock;
	// lock attributes
	pthread_mutexattr_t __lock_attr;
};

#endif
