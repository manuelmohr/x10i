#ifndef OCTOPOS_ILOCAL_DATA_H_
#define OCTOPOS_ILOCAL_DATA_H_

#include "async.h"

typedef struct {
	finish_state_t *fs;
	unsigned        atomic_depth;
#ifdef USE_AGENTSYSTEM
	agentclaim_t    agent_claim;
#endif
} ilocal_data_t;

#endif
