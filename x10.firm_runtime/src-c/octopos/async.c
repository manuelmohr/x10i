#include <octopos.h>
#include <stdio.h>
#include <gc.h>

#include "async.h"
#include "remote_exec.h"
#include "ilocal_data.h"
#include "agent.h"
#include "x10_runtime.h"
#include "xmalloc.h"
#include "memory.h"

uintptr_t finish_state_idx;
uintptr_t atomic_depth_idx;
#ifdef USE_AGENTSYSTEM
uintptr_t agent_claim_idx;
#endif

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
	/* a signal for parallel activity creation */
	simple_signal   signal;
	/* enclosing finish (maybe NULL for root) */
	finish_state_t *parent;
};

void finish_state_init_root(finish_state_t *fs)
{
	simple_signal_init(&fs->signal, 0);
	fs->parent = NULL;
}

void finish_state_init(finish_state_t *fs, finish_state_t *parent)
{
	simple_signal_init(&fs->signal, 0);
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
	/* owning agent claim */
	agentclaim_t   agent_claim;
} async_closure;

finish_state_t* finish_state_get_current(void)
{
	return fls_get(finish_state_idx);
}

void finish_state_set_current(finish_state_t *fs)
{
	fls_set(finish_state_idx, fs);
}

void register_at_finish_state(finish_state_t *fs)
{
	simple_signal_add_signalers(&fs->signal, 1);
}

void unregister_from_finish_state_and_exit(finish_state_t *fs)
{
	simple_signal_signal_and_exit(&fs->signal);
}

void unregister_from_finish_state(finish_state_t *fs)
{
	simple_signal_signal(&fs->signal);
}

void activity_inc_atomic_depth(void)
{
	uintptr_t depth = (uintptr_t)fls_get(atomic_depth_idx);
	fls_set(atomic_depth_idx, (void *)(depth + 1));
}

void activity_dec_atomic_depth(void)
{
	uintptr_t depth = (uintptr_t)fls_get(atomic_depth_idx);
	fls_set(atomic_depth_idx, (void *)(depth - 1));
}

unsigned activity_get_atomic_depth(void)
{
	return (uintptr_t)fls_get(atomic_depth_idx);
}

void activity_set_atomic_depth(unsigned depth)
{
	fls_set(atomic_depth_idx, (void*)(uintptr_t)depth);
}

static uintptr_t allocate_fls_slot(void)
{
	intptr_t idx = fls_allocate(NULL);
	if (idx == -1) {
		panic("Could not allocate slot in fiber-local storage");
	}
	return idx;
}

static void init_ilet_local_data(void)
{
	static int fls_initialized = 0;
	static simple_spinlock lock;

	/* allocate slots in fiber-local storage */
	if (!fls_initialized) {
		simple_spinlock_lock(&lock);
		if (!fls_initialized) {
			finish_state_idx = allocate_fls_slot();
			atomic_depth_idx = allocate_fls_slot();
#ifdef USE_AGENTSYSTEM
			agent_claim_idx = allocate_fls_slot();
#endif
			fls_initialized = 1;
		}
		simple_spinlock_unlock(&lock);
	}

	/* the data should already be zero-initialized */
	assert(fls_get(finish_state_idx) == NULL);
	assert(fls_get(atomic_depth_idx) == NULL);
#ifdef USE_AGENTSYSTEM
	assert(fls_get(agent_claim_idx) == NULL);
#endif
}

/**
 * Initializes ilet local data structures for an ilet that will execute
 * X10 code.
 */
static void init_x10_activity(finish_state_t *fs)
{
	init_ilet_local_data();
	finish_state_set_current(fs);
	activity_set_atomic_depth(0);
}

#ifdef USE_AGENTSYSTEM
/** Top-level i-let function, initializes activity and cleans up afterwards */
static void execute(void *ptr)
{
	async_closure  *ac          = (async_closure *)ptr;
	x10_object     *body        = ac->body;
	finish_state_t *fs          = ac->enclosing;
	agentclaim_t    agent_claim = ac->agent_claim;
	mem_free_tlm(ac);

	init_x10_activity(fs);

	/* initialize agent claim */
	agentclaim_set_current(agent_claim);

	/* run the closure */
	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(body);

	if (fs != NULL) {
		/* send signal to finish state if counted async */
		unregister_from_finish_state_and_exit(fs);
	}
}
#else
static void execute(void *data1, void *data2)
{
	x10_object      *body    = data1;
	finish_state_t  *fs      = data2;

	octo_gc_unpin(body);
	init_x10_activity(fs);

	/* run the closure */
	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(body);

	if (fs != NULL) {
		/* send signal to finish state if counted async */
		unregister_from_finish_state_and_exit(fs);
	}
}
#endif

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
	finish_state_t *nested    = mem_allocate_tlm(sizeof(finish_state_t));
	finish_state_init(nested, enclosing);
	finish_state_set_current(nested);
}

/* x10.lang.Runtime.executeParallel(body:()=>void, uncounted:Boolean) */
void _ZN3x104lang7Runtime15executeParallelEPN3x104lang12$VoidFun_0_0Eb(x10_object *body, x10_boolean uncounted)
{
	finish_state_t *enclosing = uncounted ? NULL : finish_state_get_current();
	simple_ilet child;

#ifdef USE_AGENTSYSTEM
	async_closure *ac = mem_allocate_tlm(sizeof(async_closure));
	ac->body        = body;
	ac->enclosing   = enclosing;
	ac->agent_claim = agentclaim_get_current();
	simple_ilet_init(&child, execute, ac);
#else
	octo_gc_pin(body);
	dual_ilet_init(&child, execute, body, enclosing);
#endif
	if (!uncounted) {
		register_at_finish_state(enclosing);
	}
	infect_self_single(&child);
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
	mem_free_tlm(enclosing);
	/* restore enclosing finish state */
	finish_state_set_current(parent);
}
