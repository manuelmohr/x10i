#ifndef OCTOPOS_X10_SIGNAL_POSIX_H
#define OCTOPOS_X10_SIGNAL_POSIX_H

#include <pthread.h>

#include "types.h"
#include "x10_signal.h"

struct X10_TYPE("x10.util.concurrent.Signal") x10_signal {
	x10_object      base;
	pthread_cond_t  x10_signal_cond;
	pthread_mutex_t x10_signal_mutex;
};

#endif
