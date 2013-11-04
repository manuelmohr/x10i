#include <octopos.h>
#include <stdio.h>

#include "ilocal_data.h"

#ifdef USE_AGENTSYSTEM
agentclaim_t agentclaim_get_current(void)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	return ilocal->agent_claim;
}

void agentclaim_set_current(agentclaim_t ac)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	ilocal->agent_claim = ac;
}
#endif
