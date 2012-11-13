#ifndef ASYNC_H
#define ASYNC_H

typedef struct finish_state finish_state;

struct finish_state {
	/* a mutex for parallel activity creation */
	pthread_mutex_t     mutex;
	/* Condition variable to wait at the end of finish statements */
	pthread_cond_t      condition;
	/* Number of spawned activities */
	int                 number_of_activities;
	/* enclosing finish (maybe NULL for root) */
	finish_state        *parent;
};

finish_state *finish_state_get_current();
int finish_state_set_current(finish_state *fs);
void register_at_finish_state(finish_state *fs);
void unregister_from_finish_state(finish_state *fs);

/** Returns the number of active atomic blocks for the current activity. */
unsigned activity_get_atomic_depth(void);
/** Increment the number of active atomic blocks for the current activity. */
void activity_inc_atomic_depth(void);
/** Decrement the number of active atomic blocks for the current activity. */
void activity_dec_atomic_depth(void);

#endif
