#ifndef ILOCAL_DATA_H_
#define ILOCAL_DATA_H_

#include "async.h"

typedef struct {
	finish_state *fs;
	x10_int       here_id;
	unsigned      atomic_depth;
} ilocal_data_t;

#endif
