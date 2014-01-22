#include <octopos.h>
#include <stdio.h>

#include "ilocal_data.h"
#include "agent.h"
#include "places_octopos.h"
#include "memory.h"

agentclaim_t agentclaim_get_current(void)
{
#ifdef USE_AGENTSYSTEM
	return get_ilet_local_data()->agent_claim;
#else
	return NULL;
#endif
}

void agentclaim_set_current(agentclaim_t ac)
{
#ifdef USE_AGENTSYSTEM
	get_ilet_local_data()->agent_claim = ac;
#else
	(void)ac;
#endif
}

static void redistribute_places(agentclaim_t ac)
{
	assert (ac != NULL && "invalid claim"); // TODO throw exception?
	unsigned new_n_places = agent_claim_get_tilecount(ac);
	if (0 == new_n_places)
		return; /* nothing to distribute */
	dispatch_claim_t *new_places = mem_allocate_tlm(new_n_places * sizeof(*new_places));
	assert(NULL != new_places);
	for (unsigned pid = 0; pid < new_n_places; ++pid) {
		proxy_claim_t pClaim = agent_claim_get_proxyclaim_tile_type(ac, pid, 0);
		dispatch_claim_t dc = proxy_get_dispatch_info(pClaim);
		new_places[pid] = dc;
	}
	distribute_places(new_places, new_n_places);
}

/** Wrapper for agent_claim_invade
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade(agent_t parentagent, constraints_t constr)
{
	agentclaim_t ac = agent_claim_invade(parentagent, constr);
	redistribute_places(ac);
	return ac;
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_or_constraints(agent_t parentagent, uint8_t constr_count, constraints_t constr[])
{
	agentclaim_t ac = agent_claim_invade_or_constraints(parentagent, constr_count, constr);
	redistribute_places(ac);
	return ac;
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_parentclaim(agentclaim_t parentclaim, constraints_t constr)
{
	agentclaim_t ac = agent_claim_invade_parentclaim(parentclaim, constr);
	redistribute_places(ac);
	return ac;
}

/** Wrapper for agent_claim_reinvade
 * which does X10 specific stuff */
int x10_agent_claim_reinvade(agentclaim_t claim)
{
	int r = agent_claim_reinvade(claim);
	if (r > 0)
		redistribute_places(claim);
	return r;
}

/** Wrapper for agent_claim_reinvade_constraints
 * which does X10 specific stuff */
int x10_agent_claim_reinvade_constraints(agentclaim_t claim, constraints_t constr)
{
	int r = agent_claim_reinvade_constraints(claim, constr);
	if (r > 0)
		redistribute_places(claim);
	return r;
}
