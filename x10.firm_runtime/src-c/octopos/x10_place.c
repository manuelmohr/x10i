#include <octopos.h>

#include "places.h"
#include "types.h"

/* x10.lang.Place.getMaxPlaces(): Int */
x10_int _ZN3x104lang5Place12getMaxPlacesEv(void)
{
	place_local_data *pld = claim_get_local_data();
	return pld->n_places;
}

x10_int x10_get_here_placeid(void)
{
	place_local_data *pld = claim_get_local_data();
	return pld->place_id;
}

// x10.lang.Runtime.getHere() : Int
x10_int _ZN3x104lang7Runtime9getHereIdEv()
{
	return x10_get_here_placeid();
}

// vim: noet
