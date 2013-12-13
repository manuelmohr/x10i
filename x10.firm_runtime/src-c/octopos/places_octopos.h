/* platform specific place abstraction */
#ifndef PLACES_OCTOPOS_H
#define PLACES_OCTOPOS_H

#include <octopos.h>

void distribute_places(dispatch_claim_t *new_places, unsigned new_n_places);

x10_int x10_get_here_placeid(void);

#endif
