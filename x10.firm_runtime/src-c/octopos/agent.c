#include <octopos.h>
#include <stdio.h>

#include "ilocal_data.h"
#include "agent.h"

agentclaim_t agentclaim_get_current(void)
{
#ifdef USE_AGENTSYSTEM
	ilocal_data_t *ilocal = get_ilocal_data();
	return ilocal->agent_claim;
#else
	return NULL;
#endif
}

void agentclaim_set_current(agentclaim_t ac)
{
#ifdef USE_AGENTSYSTEM
	ilocal_data_t *ilocal = get_ilocal_data();
	ilocal->agent_claim = ac;
#else
	return NULL;
#endif
}
