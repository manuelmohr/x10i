#ifndef ASYNC_H
#define ASYNC_H

/** Returns the number of active atomic blocks for the current activity. */
unsigned activity_get_atomic_depth(void);
/** Increment the number of active atomic blocks for the current activity. */
void activity_inc_atomic_depth(void);
/** Decrement the number of active atomic blocks for the current activity. */
void activity_dec_atomic_depth(void);

#endif
