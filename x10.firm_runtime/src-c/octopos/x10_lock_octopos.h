#ifndef X10_LOCK_OCTOPOS_H
#define X10_LOCK_OCTOPOS_H

#include <octopos.h>
#include "x10.h"
#include "x10_lock.h"

struct x10_lock {
	x10_object      base;
	simple_spinlock lock;
};

#endif
