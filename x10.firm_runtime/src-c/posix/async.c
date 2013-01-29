#include <pthread.h>
#include <stdio.h>

#include "async.h"
#include "init.h"
#include "remote_exec.h"
#include "x10_runtime.h"

#define MAX_ACTIVITIES_PER_FINISH 64

/**
 * A finish_state holds all information for a finish statement.
 * All its child activities are tracked. Also, their children must register
 * as well, which means finish state must be thread-safe.
 * Finish statements are nested, so whenever one finishes, the outer state
 * must be reinstantiated.
 *
 * We should not carry the current finish state through all function calls.
 * However, at any point we might spawn a new activity and must register it
 * at the current finish state. Hence, we use thread-local data to store the
 * current finish state.
 */
struct finish_state_t {
	/* a mutex for parallel activity creation */
	pthread_mutex_t mutex;
	/* Condition variable to wait at the end of finish statements */
	pthread_cond_t  condition;
	/* Number of spawned activities */
	int             number_of_activities;
	/* enclosing finish (maybe NULL for root) */
	finish_state_t *parent;
};

static void panic(const char * msg)
{
	fprintf(stderr, "%s\n", msg);
	abort();
}

void finish_state_init(finish_state_t *fs, finish_state_t *parent)
{
	if (pthread_mutex_init(& fs->mutex, NULL))
		panic("Could not init mutex");
	if (pthread_cond_init(& fs->condition, NULL))
		panic("Could not init condition variable");
	fs->number_of_activities = 0;
	fs->parent               = parent;
}

void finish_state_destroy(finish_state_t *fs)
{
	if (pthread_mutex_destroy(& fs->mutex))
		panic("Could not destroy mutex");
	if (pthread_cond_destroy(& fs->condition))
		panic("Could not destroy condition variable");
}

/**
 * When an activity is spawned, it must inherit some information from its parent activity.
 * Specifically, the finish state must be known to register further activity spawns.
 * Of course, the closure/function pointer for the new activity to execute must be known, too.
 */

typedef struct async_closure {
	/* x10 closure pointer */
	x10_object     *body;
	/* enclosing finish state */
	finish_state_t *enclosing;
} async_closure;

static pthread_key_t enclosing_finish_state;
static pthread_key_t activity_atomic_depth;

finish_state_t* finish_state_get_current(void)
{
	return pthread_getspecific(enclosing_finish_state);
}

void finish_state_set_current(finish_state_t *fs)
{
	if (pthread_setspecific(enclosing_finish_state, fs))
		panic("Could not set current finish state.");
}

void register_at_finish_state(finish_state_t *fs)
{
	if (pthread_mutex_lock(& fs->mutex))
		panic("Could not lock mutex");

	fs->number_of_activities++;

	if (pthread_mutex_unlock(& fs->mutex))
		panic("Could not unlock mutex");
}

void unregister_from_finish_state(finish_state_t *fs)
{
	if (pthread_mutex_lock(& fs->mutex))
		panic("Could not lock mutex");

	fs->number_of_activities--;
	pthread_cond_signal(& fs->condition);

	if (pthread_mutex_unlock(& fs->mutex))
		panic("Could not unlock mutex");
}

unsigned activity_get_atomic_depth(void)
{
	return (unsigned) pthread_getspecific(activity_atomic_depth);
}

void activity_inc_atomic_depth(void)
{
	const unsigned new_depth = activity_get_atomic_depth() + 1;
	pthread_setspecific(activity_atomic_depth, (void*) new_depth);
}

void activity_dec_atomic_depth(void)
{
	const unsigned new_depth = activity_get_atomic_depth() - 1;
	pthread_setspecific(activity_atomic_depth, (void*) new_depth);
}

/** Top-level thread function, initializes activity and cleans up afterwards */
static void *execute(void *ptr)
{
	async_closure  *ac   = (async_closure *) ptr;
	finish_state_t *fs   = ac->enclosing;
	x10_object     *body = ac->body;
	free(ac);
	/* store enclosing finish state in thread-local data */
	finish_state_set_current(fs);
	/* Initialize atomic depth. */
	if (pthread_setspecific(activity_atomic_depth, NULL))
		panic("Could not set thread-local key");
	/* run the closure */
	_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(body);

	unregister_from_finish_state(fs);
	pthread_exit(NULL);
}

/**
 * Native API of X10 runtime. Basically
 *
 *   finish {
 *     async S1;
 *     async S2;
 *   }
 *
 * is syntactic sugar for
 *
 *   x10.lang.Runtime.finishBlockBegin();
 *   x10.lang.Runtime.executeParallel(()=>{S1});
 *   x10.lang.Runtime.executeParallel(()=>{S2});
 *   x10.lang.Runtime.finishBlockEnd();
 *
 */

/* x10.lang.Runtime.finishBlockBegin() */
void _ZN3x104lang7Runtime16finishBlockBeginEv(void)
{
	finish_state_t *enclosing = finish_state_get_current();
	finish_state_t *nested    = XMALLOC(finish_state_t);
	finish_state_init(nested, enclosing);
	finish_state_set_current(nested);
}

void init_finish_state(void)
{
	/* initialize main thread's finish state */
	if (pthread_key_create(&enclosing_finish_state, NULL))
		panic("Could not create thread-local key");
	finish_state_set_current(NULL);
	/* initialize main thread's atomic depth */
	if (pthread_key_create(&activity_atomic_depth, NULL))
		panic("Could not create thread-local key");
	if (pthread_setspecific(activity_atomic_depth, NULL))
		panic("Could not set thread-local key");

	/* begin main thread's finish block */
	_ZN3x104lang7Runtime16finishBlockBeginEv();
}

/* x10.lang.Runtime.executeParallel(body:()=>void) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0E(x10_object *body)
{
	finish_state_t *enclosing = finish_state_get_current();
	async_closure  *ac        = XMALLOC(async_closure);
	ac->body = body;
	ac->enclosing = enclosing;
	pthread_t child;
	if (pthread_create(&child, NULL, execute, ac))
		panic("Could not create thread");
	register_at_finish_state(enclosing);
}

void finish_state_wait(finish_state_t *state)
{
	/* wait for all child threads */
	if (pthread_mutex_lock(&state->mutex))
		panic("Could not lock mutex");

	while (state->number_of_activities > 0) {
		if (pthread_cond_wait(&state->condition, & state->mutex))
			panic("Could not wait on condition variable");
	}

	if (pthread_mutex_unlock(&state->mutex))
		panic("Could not unlock mutex");
}

/* x10.lang.Runtime.finishBlockEnd() */
void _ZN3x104lang7Runtime14finishBlockEndEv(void)
{
	/* wait for all child threads */
	finish_state_t *enclosing = finish_state_get_current();
	finish_state_wait(enclosing);
	/* clear the finish state */
	finish_state_t *parent = enclosing->parent;
	finish_state_destroy(enclosing);
	free(enclosing);
	/* restore enclosing finish state */
	finish_state_set_current(parent);
}

void exit_finish_state(void)
{
	/* end main thread's finish block */
	_ZN3x104lang7Runtime14finishBlockEndEv();
}
