#ifndef POSIX_TYPES_H
#define POSIX_TYPES_H

#include <pthread.h>
#include "x10.h"
#include "x10_string.h"

// execution thread condition & associated lock pair
typedef struct cond_mutex_t {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
} cond_mutex_t;

// thread permit type
typedef struct permit_t {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	x10_boolean permit;
} permit_t;

struct x10_thread {
	x10_object base;
	// thread id
	x10_long __thread_id;
	// thread name
	x10_string *__thread_name;
	// thread's pthread id
	pthread_t __xthread;
	// thread attributes
	pthread_attr_t __xthread_attr;
	// thread run flags
	x10_boolean __thread_already_started;
	x10_boolean __thread_running;
	// thread start condition & associated lock
	pthread_cond_t __thread_start_cond;
	pthread_mutex_t __thread_start_lock;
	// thread specific permit object
	permit_t __thread_permit;
};

struct x10_place {
	x10_int id;
};

typedef struct x10_lock {
	x10_object base;
	// lock id
	pthread_mutex_t __lock;
	// lock attributes
	pthread_mutexattr_t __lock_attr;
} x10_lock;

#endif
