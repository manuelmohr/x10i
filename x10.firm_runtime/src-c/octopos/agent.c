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
	(void)ac;
#endif
}

/** Wrapper for agent_claim_invade
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade(agent_t parentagent, constraints_t constr)
{
	return agent_claim_invade(parentagent, constr);
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_or_constraints(agent_t parentagent, uint8_t constr_count, constraints_t constr[])
{
	return agent_claim_invade_or_constraints(parentagent, constr_count, constr);
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_parentclaim(agentclaim_t parentclaim, constraints_t constr)
{
	return agent_claim_invade_parentclaim(parentclaim, constr);
}

/** Wrapper for agent_claim_reinvade
 * which does X10 specific stuff */
int x10_agent_claim_reinvade(agentclaim_t claim)
{
	return agent_claim_reinvade(claim);
}

/** Wrapper for agent_claim_reinvade_constraints
 * which does X10 specific stuff */
int x10_agent_claim_reinvade_constraints(agentclaim_t claim, constraints_t constr)
{
	return agent_claim_reinvade_constraints(claim, constr);
}
