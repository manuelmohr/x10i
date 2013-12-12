/* platform specific place abstraction */
#ifndef PLACES_OCTOPOS_H
#define PLACES_OCTOPOS_H

#include <octopos.h>

extern dispatch_claim_t *places;

void distribute_places(dispatch_claim_t *new_places, unsigned new_n_places);

#endif
