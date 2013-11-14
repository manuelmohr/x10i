#include <octopos.h>

#include "places.h"
#include "types.h"

unsigned n_places;
unsigned place_id;

/* x10.lang.Place.getMaxPlaces(): Int */
x10_int _ZN3x104lang5Place12getMaxPlacesEv(void)
{
#ifdef USE_AGENTSYSTEM
	agentclaim_t cur = agentclaim_get_current();
	int tilecount = agent_claim_get_tilecount(cur);
	return tilecount;
#else
	return n_places;
#endif
}

// vim: noet
