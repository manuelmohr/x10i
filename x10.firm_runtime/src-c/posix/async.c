#include <pthread.h>
#include <stdio.h>

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

static void panic(const char * msg) {
	printf("%s\n", msg);
	abort();
}

typedef struct finish_state finish_state;

struct finish_state {
	/* a mutex for parallel activity creation */
	pthread_mutex_t     mutex;
	/* a list of all child activities */
	pthread_t           children[MAX_ACTIVITIES_PER_FINISH];
	/* enclosing finish (maybe NULL for root) */
	finish_state        *parent;
};

static void finish_state_init(finish_state *fs, finish_state *parent) {
	if (pthread_mutex_init(& fs->mutex, NULL))
		panic("Could not init mutex");
	memset(fs->children, 0, sizeof(pthread_t)*MAX_ACTIVITIES_PER_FINISH);
	fs->parent = parent;
}

static void finish_state_free(finish_state *fs) {
	if (pthread_mutex_destroy(& fs->mutex))
		panic("Could not destroy mutex");
	free(fs);
}

/**
 * When an activity is spawned, it must inherit some information from its parent activity.
 * Specifically, the finish state must be known to register further activity spawns.
 * Of course, the closure/function pointer for the new activity to execute must be known, too.
 */

typedef struct async_closure {
	/* x10 closure pointer */
	void           *body;
	/* enclosing finish state */
	finish_state   *enclosing;
} async_closure;

static pthread_key_t enclosing_finish_state;

static finish_state* finish_state_get_current(void) {
	return pthread_getspecific(enclosing_finish_state);
}

static void register_at_finish_state(pthread_t child, finish_state *fs) {
	if (pthread_mutex_lock(& fs->mutex))
		panic("Could not lock mutex");
	for (int i=0; i<MAX_ACTIVITIES_PER_FINISH; i++) {
		// FIXME a zero pthread_t might be valid
		if (fs->children[i] == 0) {
			fs->children[i] = child;
			goto success;
		}
	}
	panic("Too many activities for this finish state");
success:
	if (pthread_mutex_unlock(& fs->mutex))
		panic("Could not unlock mutex");
}

/* X10 function to execute ()=>void closures */
extern void* _ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(void *body);

/** Top-level thread function, initializes activity and cleans up afterwards */
static void *execute(void *ptr) {
	async_closure *ac = (async_closure *) ptr;
	finish_state *fs = ac->enclosing;
	void *body = ac->body;
	free(ac);
	/* store enclosing finish state in thread-local data */
	if (pthread_setspecific(enclosing_finish_state, fs))
		panic("Could not set thread-local key");
	/* run the closure */
	_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(body);
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
void _ZN3x104lang7Runtime16finishBlockBeginEv(void) {
	finish_state *enclosing = finish_state_get_current();
	finish_state *nested = malloc(sizeof(finish_state));
	if (nested == NULL) panic("malloc returned NULL");
	finish_state_init(nested, enclosing);
	if (pthread_setspecific(enclosing_finish_state, nested))
		panic("Could not set thread-local key");
}

static void __attribute__((constructor)) init_finish_state(void) {
	/* initialize main thread's finish state */
	if (pthread_key_create(&enclosing_finish_state, NULL))
		panic("Could not create thread-local key");
	if (pthread_setspecific(enclosing_finish_state, NULL))
		panic("Could not set thread-local key");

	/* begin main thread's finish block */
	_ZN3x104lang7Runtime16finishBlockBeginEv();
}

/* x10.lang.Runtime.executeParallel(body:()=>void) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0E(void *body) {
	// TODO ensure not in atomic
	finish_state *enclosing = finish_state_get_current();
	async_closure *ac = malloc(sizeof(async_closure));
	if (ac == NULL) panic("malloc returned NULL");
	ac->body = body;
	ac->enclosing = enclosing;
	pthread_t child;
	if (pthread_create(&child, NULL, execute, ac))
		panic("Could not create thread");
	register_at_finish_state(child, enclosing);
}

/* x10.lang.Runtime.finishBlockEnd() */
void _ZN3x104lang7Runtime14finishBlockEndEv(void) {
	/* wait for all child threads */
	finish_state *enclosing = finish_state_get_current();
	for (int i=0; i<MAX_ACTIVITIES_PER_FINISH; i++) {
		// FIXME a zero pthread_t might be valid
		if (enclosing->children[i] != 0) {
			if (pthread_join(enclosing->children[i], NULL))
				panic("Could not join thread");
		}
	}
	/* clear the finish state */
	finish_state *parent = enclosing->parent;
	finish_state_free(enclosing);
	/* restore enclosing finish state */
	if (pthread_setspecific(enclosing_finish_state, parent))
		panic("Could not set thread-local key");
}

static void __attribute__((destructor)) exit_finish_state(void) {
	/* end main thread's finish block */
	_ZN3x104lang7Runtime14finishBlockEndEv();
}
