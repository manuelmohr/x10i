#include <octopos.h>
#include <stdio.h>

#include "async.h"
#include "x10_rt.h"
#include "ilocal_data.h"

/**
 * A finish_state holds all information for a finish statement.
 * All its child activities are tracked. Also, their children must register
 * as well, which means finish state must be thread-safe.
 * Finish statements are nested, so whenever one finishes, the outer state
 * must be reinstantiated.
 *
 * We should not carry the current finish state through all function calls.
 * However, at any point we might spawn a new activity and must register it
 * at the current finish state. Hence, we use i-let-local data to store the
 * current finish state.
 */

static void panic(const char * msg) {
	printf("%s\n", msg);
	abort();
}

struct finish_state {
	/* the common claim of all activities */
	claim_t        claim;
	/* a signal for parallel activity creation */
	simple_signal  signal;
	/* enclosing finish (maybe NULL for root) */
	finish_state  *parent;
};

static void finish_state_init(finish_state *fs, finish_state *parent) {
	simple_signal_init(&fs->signal, 0);
	fs->claim  = parent->claim;
	fs->parent = parent;
}

static void finish_state_free(finish_state *fs) {
	free(fs);
}

/**
 * When an activity is spawned, it must inherit some information from its parent activity.
 * Specifically, the finish state must be known to register further activity spawns.
 * Of course, the closure/function pointer for the new activity to execute must be known, too.
 */

typedef struct async_closure {
	/* x10 closure pointer */
	void         *body;
	/* enclosing finish state */
	finish_state *enclosing;
	/* executing ilet */
	simple_ilet  *ilet;
	x10_int       here_id;
} async_closure;

finish_state* finish_state_get_current(void)
{
	void *ilocal_data = get_ilocal_data();
	ilocal_data_t *ilocal = *(ilocal_data_t**)ilocal_data;
	return ilocal->fs;
}

void finish_state_set_current(finish_state *fs)
{
	void *ilocal_data = get_ilocal_data();
	ilocal_data_t *ilocal = *(ilocal_data_t**)ilocal_data;
	ilocal->fs = fs;
}

void register_at_finish_state(finish_state *fs) {
	simple_signal_add_signalers(&fs->signal, 1);
}

void unregister_from_finish_state(finish_state *fs) {
	simple_signal_signal(&fs->signal);
}

/* X10 function to execute ()=>void closures */
extern void* _ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(x10_object *body);

/** Top-level i-let function, initializes activity and cleans up afterwards */
static void execute(void *ptr) {
	async_closure *ac      = (async_closure *)ptr;
	void          *body    = ac->body;
	finish_state  *fs      = ac->enclosing;
	simple_ilet   *ilet    = ac->ilet;
	x10_int        here_id = ac->here_id;
	free(ac);

	void **ilocal = get_ilocal_data();
	*ilocal = malloc(sizeof(ilocal_data_t));

	/* store enclosing finish state in i-let-local data */
	finish_state_set_current(fs);
	x10_rt_set_here_id(here_id);

	/* run the closure */
	_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(body);

	/* send signal to finish state */
	unregister_from_finish_state(fs);

	free(*ilocal);
	free(ilet);
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
	finish_state_set_current(nested);
}

/* x10.lang.Runtime.executeParallel(body:()=>void) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0E(void *body) {
	// TODO ensure not in atomic
	finish_state  *enclosing = finish_state_get_current();
	async_closure *ac        = malloc(sizeof(async_closure));
	simple_ilet   *child     = malloc(sizeof(simple_ilet));
	if (ac == NULL) panic("malloc returned NULL");
	ac->body      = body;
	ac->enclosing = enclosing;
	ac->ilet      = child;
	ac->here_id   = x10_rt_get_here_id();
	simple_ilet_init(child, execute, ac);
	if (infect(enclosing->claim, child, 1)) panic("infect failed");
	register_at_finish_state(enclosing);
}

/* x10.lang.Runtime.finishBlockEnd() */
void _ZN3x104lang7Runtime14finishBlockEndEv(void) {
	/* wait for all child i-lets */
	finish_state *enclosing = finish_state_get_current();

	/* wait for spawned activities */
	simple_signal_wait(&enclosing->signal);

	/* clear the finish state */
	finish_state *parent = enclosing->parent;
	finish_state_free(enclosing);
	/* restore enclosing finish state */
	finish_state_set_current(parent);
}
