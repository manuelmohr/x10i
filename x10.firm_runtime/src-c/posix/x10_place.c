#include "places.h"
#include "types.h"

unsigned n_places;
unsigned place_id;

/* x10.lang.Place.getMaxPlaces(): Int */
x10_int _ZN3x104lang5Place12getMaxPlacesEv(void)
{
	return n_places;
}

// x10.lang.Runtime.getHere() : Int
x10_int _ZN3x104lang7Runtime9getHereIdEv()
{
	return (x10_int)place_id;
}

// vim: noet
