#ifndef OCTOPOS_ILOCAL_DATA_H_
#define OCTOPOS_ILOCAL_DATA_H_

#include "async.h"

typedef struct {
	finish_state_t *fs;
	unsigned        atomic_depth;
#ifdef USE_AGENTSYSTEM
	agentclaim_t    agent_claim;
#endif
#ifndef NDEBUG
	unsigned magic;
#endif
} ilocal_data_t;

static inline ilocal_data_t *get_ilet_local_data(void)
{
	ilocal_data_t *result = (ilocal_data_t*)get_ilocal_data();
	assert(result->magic == 0x600DBABEu);
	return result;
}

static inline void init_ilet_local_data(void)
{
#ifndef NDEBUG
	ilocal_data_t *data = (ilocal_data_t*)get_ilocal_data();
	memset(data, 0, sizeof(*data));
	data->magic = 0x600DBABEu;
#endif
}

typedef struct place_local_data {
	dispatch_claim_t *places;
	unsigned n_places;
	unsigned place_id;
} place_local_data;

#endif
