#include <octopos.h>

#include "places.h"
#include "types.h"

/* x10.lang.Place.getMaxPlaces(): Int */
x10_int _ZN3x104lang5Place12getMaxPlacesEv(void)
{
	place_local_data *pld = claim_get_local_data(get_claim());
	return pld->n_places;
}

x10_int x10_get_here_placeid(void)
{
	place_local_data *pld = claim_get_local_data(get_claim());
	return pld->place_id;
}

// vim: noet
