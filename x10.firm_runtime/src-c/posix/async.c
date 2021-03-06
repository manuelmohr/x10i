#include <pthread.h>
#include <stdio.h>

#include "async.h"
#include "init.h"
#include "remote_exec.h"
#include "x10_runtime.h"
#include "xmalloc.h"

#define MAX_ACTIVITIES_PER_FINISH 64

static pthread_attr_t async_pthread_attr;

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
		panic("Could not lock mutex (register_at)");

	fs->number_of_activities++;

	if (pthread_mutex_unlock(& fs->mutex))
		panic("Could not unlock mutex");
}

void unregister_from_finish_state(finish_state_t *fs)
{
	if (pthread_mutex_lock(& fs->mutex))
		panic("Could not lock mutex (unregister at)");

	fs->number_of_activities--;
	pthread_cond_signal(& fs->condition);

	if (pthread_mutex_unlock(& fs->mutex))
		panic("Could not unlock mutex");
}

void unregister_from_finish_state_and_exit(finish_state_t *fs)
{
	unregister_from_finish_state(fs);
	pthread_exit(NULL);
}

unsigned activity_get_atomic_depth(void)
{
	return (unsigned)(uintptr_t)pthread_getspecific(activity_atomic_depth);
}

void activity_set_atomic_depth(unsigned depth)
{
	pthread_setspecific(activity_atomic_depth, (void*)(uintptr_t)depth);
}

void activity_inc_atomic_depth(void)
{
	const unsigned new_depth = activity_get_atomic_depth() + 1;
	pthread_setspecific(activity_atomic_depth, (void*)(uintptr_t)new_depth);
}

void activity_dec_atomic_depth(void)
{
	const unsigned new_depth = activity_get_atomic_depth() - 1;
	pthread_setspecific(activity_atomic_depth, (void*)(uintptr_t)new_depth);
}

/** Top-level thread function, initializes activity and cleans up afterwards */
static void *execute(void *ptr)
{
	async_closure  *ac   = (async_closure *) ptr;
	finish_state_t *fs   = ac->enclosing;
	x10_object     *body = ac->body;
	gc_free(ac);
	if (fs != NULL) {
		/* store enclosing finish state in thread-local data for counted asyncs */
		finish_state_set_current(fs);
	}
	/* Initialize atomic depth. */
	if (pthread_setspecific(activity_atomic_depth, NULL))
		panic("Could not set thread-local key");
	/* run the closure */
	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(body);

	if (fs != NULL) {
		unregister_from_finish_state_and_exit(fs);
	} else {
		pthread_exit(NULL);
	}
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
	/* finish_state_t is put into TLS data, so mark is at uncollectable because
	 * the current version of the boehm GC does not scan thread local storage */
	finish_state_t *nested    = (finish_state_t*)GC_MALLOC_UNCOLLECTABLE(sizeof(finish_state_t));
	finish_state_init(nested, enclosing);
	finish_state_set_current(nested);
}

void init_finish_state(void)
{
	pthread_attr_init(&async_pthread_attr);
	pthread_attr_setdetachstate(&async_pthread_attr, PTHREAD_CREATE_DETACHED);

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

/* x10.lang.Runtime.executeParallel(body:()=>void, uncounted:Boolean) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0Eb(x10_object *body, x10_boolean uncounted)
{
	finish_state_t *enclosing = uncounted ? NULL : finish_state_get_current();
	async_closure  *ac        = GC_XMALLOC(async_closure);
	ac->body = body;
	ac->enclosing = enclosing;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	if (!uncounted) {
		register_at_finish_state(enclosing);
	}
	pthread_t dummy;
	if (GC_pthread_create(&dummy, &async_pthread_attr, execute, ac))
		panic("Could not create thread");
}

void finish_state_wait(finish_state_t *state)
{
	/* wait for all child threads */
	if (pthread_mutex_lock(&state->mutex))
		panic("Could not lock mutex (wait)");

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
	gc_free(enclosing);
	/* restore enclosing finish state */
	finish_state_set_current(parent);
}

void exit_finish_state(void)
{
	/* end main thread's finish block */
	_ZN3x104lang7Runtime14finishBlockEndEv();

	pthread_attr_destroy(&async_pthread_attr);
}
