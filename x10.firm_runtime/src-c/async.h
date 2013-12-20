#ifndef ASYNC_H
#define ASYNC_H

typedef struct finish_state_t finish_state_t;

finish_state_t *finish_state_get_current();
void finish_state_set_current(finish_state_t *finish_state);
void register_at_finish_state(finish_state_t *finish_state);
void unregister_from_finish_state(finish_state_t *finish_state);

void finish_state_init_root(finish_state_t *fs);
void finish_state_init(finish_state_t *finish_state, finish_state_t *parent);

void finish_state_destroy(finish_state_t *finish_state);
void finish_state_wait(finish_state_t *state);

/** Returns the number of active atomic blocks for the current activity. */
unsigned activity_get_atomic_depth(void);
/** Sets the number of active atomic blocks for the current activity.
 * Use only for initialization and use inc/dec anywhere else. */
void activity_set_atomic_depth(unsigned depth);
/** Increment the number of active atomic blocks for the current activity. */
void activity_inc_atomic_depth(void);
/** Decrement the number of active atomic blocks for the current activity. */
void activity_dec_atomic_depth(void);

#endif
