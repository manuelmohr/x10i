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
	assert (false);
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

#ifdef USE_AGENTSYSTEM
static void dispatch_claim_list_from_agentclaim(agentclaim_t ac, dispatch_claim_t** old_places, int* old_n_places)
{
	assert(*old_places == NULL);
	const int new_n_places = agent_claim_get_tilecount(ac);
	assert (new_n_places > 0);
	dispatch_claim_t *const new_places = mem_allocate_tlm(new_n_places * sizeof(*new_places));
	assert(NULL != new_places);
	/* collect proxyclaims and convert to dispatch claims */
	for (int i = 0; i < new_n_places; i++) {
		int tid = agent_claim_get_tileid_iterative(ac, i);
		proxy_claim_t pClaim = agent_claim_get_proxyclaim_tile_type(ac, tid, 0);
		assert (pClaim != NULL);
		dispatch_claim_t dc = proxy_get_dispatch_info(pClaim);
		new_places[i] = dc;
	}
	*old_places = new_places;
	*old_n_places = new_n_places;
}


static void redistribute_places(agentclaim_t ac, dispatch_claim_t* old_places, int old_n_places)
{
	assert (ac != NULL && "invalid claim"); // TODO throw exception?
	dispatch_claim_t *new_places = NULL;
	int new_n_places = 0;
	dispatch_claim_list_from_agentclaim(ac, &new_places, &new_n_places);
	assert(NULL != new_places);
	assert(new_n_places > 0);
	if (0 == new_n_places)
		return; /* nothing to distribute */
	if (old_places != NULL) {
		/* reinvade: reorder, so new places are always added to the back */
		assert (old_n_places <= new_n_places && "only ever add places (sticky!)");
		//printf("reorder %d new according to %d old\n", new_n_places, old_n_places);
		for (int i = 0; i < old_n_places; i++) {
			const tile_id_t oi = dispatch_claim_get_tid(old_places[i]);
			const tile_id_t ni = dispatch_claim_get_tid(new_places[i]);
			//printf("cmp at %d: %d ?= %d\n", i, oi, ni);
			if (oi == ni)
				continue;
			int j = i+1;
			//printf("search from %d to %d\n", j, new_n_places);
			for (; j < new_n_places; j++) {
				const tile_id_t nj = dispatch_claim_get_tid(new_places[j]);
				//printf("nj == %d\n", nj);
				if (oi != nj)
					continue;
				//printf("found %d at %d\n", nj, j);
				dispatch_claim_t tmp = new_places[i];
				new_places[i] = new_places[j];
				new_places[j] = tmp;
				break;
			}
			assert (j < new_n_places && "found something to swap" );
		}
	}
	/* distribute array to all tiles */
	distribute_places(new_places, new_n_places);
}

/** Wrapper for agent_claim_invade
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade(agent_t parentagent, constraints_t constr)
{
	agentclaim_t ac = agent_claim_invade(parentagent, constr);
	if (NULL != ac)
		redistribute_places(ac, NULL, 0);
	return ac;
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_or_constraints(agent_t parentagent, uint8_t constr_count, constraints_t constr[])
{
	agentclaim_t ac = agent_claim_invade_or_constraints(parentagent, constr_count, constr);
	if (NULL != ac)
		redistribute_places(ac, NULL, 0);
	return ac;
}

/** Wrapper for agent_claim_invade_or_constraints
 * which does X10 specific stuff */
agentclaim_t x10_agent_claim_invade_parentclaim(agentclaim_t parentclaim, constraints_t constr)
{
	agentclaim_t ac = agent_claim_invade_parentclaim(parentclaim, constr);
	if (NULL != ac)
		redistribute_places(ac, NULL, 0);
	return ac;
}

/** Wrapper for agent_claim_reinvade
 * which does X10 specific stuff */
int x10_agent_claim_reinvade(agentclaim_t claim)
{
	dispatch_claim_t *old_places = NULL;
	int old_n_places = 0;
	dispatch_claim_list_from_agentclaim(claim, &old_places, &old_n_places);
	int r = agent_claim_reinvade(claim);
	if (r > 0)
		redistribute_places(claim, old_places, old_n_places);
	return r;
}

/** Wrapper for agent_claim_reinvade_constraints
 * which does X10 specific stuff */
int x10_agent_claim_reinvade_constraints(agentclaim_t claim, constraints_t constr)
{
	dispatch_claim_t *old_places = NULL;
	int old_n_places = 0;
	dispatch_claim_list_from_agentclaim(claim, &old_places, &old_n_places);
	int r = agent_claim_reinvade_constraints(claim, constr);
	if (r > 0)
		redistribute_places(claim, old_places, old_n_places);
	return r;
}
#endif
