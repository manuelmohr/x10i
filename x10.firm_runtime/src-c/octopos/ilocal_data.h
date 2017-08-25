#ifndef OCTOPOS_ILOCAL_DATA_H_
#define OCTOPOS_ILOCAL_DATA_H_

#include "async.h"

extern uintptr_t finish_state_idx;
extern uintptr_t atomic_depth_idx;
#ifdef USE_AGENTSYSTEM
extern uintptr_t agent_claim_idx;
#endif

typedef struct place_local_data {
	dispatch_claim_t *places;
	unsigned n_places;
	unsigned place_id;
} place_local_data;

#endif
