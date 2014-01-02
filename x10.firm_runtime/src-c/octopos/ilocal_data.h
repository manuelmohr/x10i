#ifndef OCTOPOS_ILOCAL_DATA_H_
#define OCTOPOS_ILOCAL_DATA_H_

#include "async.h"

typedef struct {
	finish_state_t *fs;
	unsigned        atomic_depth;
#ifdef USE_AGENTSYSTEM
	agentclaim_t    agent_claim;
#endif
	unsigned magic;
} ilocal_data_t;

#endif

/* Initialize magic_number to recognize stack overflows. */
void initialize_magic_number(void);

/* Returns 1 if magic number is correct, 0 otherwise. */
int check_magic_number(void);
