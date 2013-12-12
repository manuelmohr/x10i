#include <octopos.h>

#include "places.h"
#include "types.h"

unsigned n_places;
unsigned place_id;

/* x10.lang.Place.getMaxPlaces(): Int */
x10_int _ZN3x104lang5Place12getMaxPlacesEv(void)
{
	return n_places;
}

// vim: noet
