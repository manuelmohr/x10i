#include <octopos.h>
#include <stdio.h>

#include "async.h"
#include "remote_exec.h"
#include "ilocal_data.h"
#include "agent.h"
#include "x10_runtime.h"
#include "xmalloc.h"

/**
 * A finish_state_t holds all information for a finish statement.
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
struct finish_state_t {
	/* the common claim of all activities */
	claim_t         claim;
	/* a signal for parallel activity creation */
	simple_signal   signal;
	/* enclosing finish (maybe NULL for root) */
	finish_state_t *parent;
};

void finish_state_init_root(finish_state_t *fs)
{
	simple_signal_init(&fs->signal, 0);
	fs->claim  = get_claim();
	fs->parent = NULL;
}

void finish_state_init(finish_state_t *fs, finish_state_t *parent)
{
	simple_signal_init(&fs->signal, 0);
	fs->claim  = parent->claim;
	fs->parent = parent;
}

void finish_state_wait(finish_state_t *state)
{
	simple_signal_wait(&state->signal);
}

void finish_state_destroy(finish_state_t *fs)
{
	(void)fs;
	assert(simple_signal_get_counter(&fs->signal) == 0);
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
	/* executing ilet */
	simple_ilet    *ilet;
	/* owning agent claim */
	agentclaim_t   agent_claim;
} async_closure;

finish_state_t* finish_state_get_current(void)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	return ilocal->fs;
}

void finish_state_set_current(finish_state_t *fs)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	ilocal->fs = fs;
}

void register_at_finish_state(finish_state_t *fs)
{
	simple_signal_add_signalers(&fs->signal, 1);
}

void unregister_from_finish_state(finish_state_t *fs)
{
	simple_signal_signal(&fs->signal);
}

void activity_inc_atomic_depth(void)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	++ilocal->atomic_depth;
}

void activity_dec_atomic_depth(void)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	--ilocal->atomic_depth;
}

unsigned activity_get_atomic_depth(void)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	return ilocal->atomic_depth;
}

void activity_set_atomic_depth(unsigned depth)
{
	ilocal_data_t *ilocal = get_ilet_local_data();
	ilocal->atomic_depth = depth;
}

/** Top-level i-let function, initializes activity and cleans up afterwards */
static void execute(void *ptr)
{
	async_closure  *ac          = (async_closure *)ptr;
	x10_object     *body        = ac->body;
	finish_state_t *fs          = ac->enclosing;
	simple_ilet    *ilet        = ac->ilet;
#ifdef USE_AGENTSYSTEM
	agentclaim_t    agent_claim = ac->agent_claim;
#endif
	mem_free(ac);

	/* Initialize magic number to recognize stack overflows. */
	init_ilet_local_data();

	/* store enclosing finish state in i-let-local data */
	finish_state_set_current(fs);
	/* initialize atomic depth */
	activity_set_atomic_depth(0);
#ifdef USE_AGENTSYSTEM
	/* initialize agent claim */
	agentclaim_set_current(agent_claim);
#endif

	/* run the closure */
	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(body);

	/* send signal to finish state */
	unregister_from_finish_state(fs);

	mem_free(ilet);
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
	finish_state_t *nested    = mem_allocate(MEM_TLM_LOCAL, sizeof(finish_state_t));
	finish_state_init(nested, enclosing);
	finish_state_set_current(nested);
}

/* x10.lang.Runtime.executeParallel(body:()=>void) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0E(x10_object *body)
{
	finish_state_t *enclosing = finish_state_get_current();
	async_closure  *ac        = mem_allocate(MEM_TLM_LOCAL, sizeof(async_closure));
	simple_ilet    *child     = mem_allocate(MEM_TLM_LOCAL, sizeof(simple_ilet));
	ac->body      = body;
	ac->enclosing = enclosing;
	ac->ilet      = child;
#ifdef USE_AGENTSYSTEM
	ac->agent_claim = agentclaim_get_current();
#else
	ac->agent_claim = 0;
#endif
	simple_ilet_init(child, execute, ac);
	register_at_finish_state(enclosing);
	if (infect(enclosing->claim, child, 1)) {
		unregister_from_finish_state(enclosing);
		panic("infect failed");
	}
}

/* x10.lang.Runtime.finishBlockEnd() */
void _ZN3x104lang7Runtime14finishBlockEndEv(void)
{
	/* wait for all child i-lets */
	finish_state_t *enclosing = finish_state_get_current();

	/* wait for spawned activities */
	finish_state_wait(enclosing);

	/* clear the finish state */
	finish_state_t *parent = enclosing->parent;
	finish_state_destroy(enclosing);
	mem_free(enclosing);
	/* restore enclosing finish state */
	finish_state_set_current(parent);
}
