#ifndef OCTOPOS_AGENT_H_
#define OCTOPOS_AGENT_H_

#include <octopos.h>

#ifdef USE_AGENTSYSTEM
agentclaim_t agentclaim_get_current(void);
void agentclaim_set_current(agentclaim_t ac);
#endif

#endif
