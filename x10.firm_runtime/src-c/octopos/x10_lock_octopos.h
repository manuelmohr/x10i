#ifndef OCTOPOS_X10_LOCK_OCTOPOS_H
#define OCTOPOS_X10_LOCK_OCTOPOS_H

#include <octopos.h>
#include "types.h"
#include "x10_lock.h"

struct X10_TYPE("x10.util.concurrent.Lock") x10_lock {
	x10_object      base;
	simple_spinlock lock;
};

#endif
