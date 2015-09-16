#include <octopos.h>
#include "async.h"
#include "ilocal_data.h"
#include "places_octopos.h"
#include "remote_exec.h"
#include "agent.h"
#include "serialization.h"
#include "x10_runtime.h"
#include "invasic_host.h"

/**
 * This file provides the runtime support for at statements/expressions.
 *
 * The following terms are use throughout the code:
 * - source denotes the place/tile that initiates the remote execution
 * - destination denotes the remote place/tile
 *
 * The control flow for an at expression looks like this:
 *
 *                          Source                          |                       Destination
 *                                                          |
 * x10_execute_at:                                          |
 * - allocates source-local data                            |
 * - serializes closure                                     |
 * - registers at finish state                              |
 * - waits for local termination                            |
 * |                                                        |
 * +--------------------------------------------------------+-+
 *     message:                                             | |
 *     - address of source-local data                       | |
 *     - size of closure                                    | |
 *                                                          | v
 *                                                          | allocate_destination_memory:
 *                                                          | - allocates destination-local data
 *                                                          | - allocates DMA receive buffer
 *                                                          | |
 * +--------------------------------------------------------+-+ message:
 * |                                                        |   - address of source-local data
 * |                                                        |   - address of receive buffer
 * |                                                        |     (can be used to synthesize destination-local data)
 * v                                                        |
 * transfer_parameters:                                     |
 * - initiates DMA transfer of closure                      |
 * |                                                        |
 * +--------------------------------------------------------+-+
 * |   message:                                             | |
 * |   - address of receive buffer                          | |
 * |     (can be used to synthesize destination-local data) | |
 * |   - source finish state                                | |
 * |                                                        | |
 * | message:                                               | |
 * | - address of send buffer                               | |
 * v                                                        | v
 * free_obstack:                                            | evaluate_at_expression:
 * - frees send buffer                                      | - allocates new top level finish state
 *                                                          | - deserializes closure
 *                                                          | - frees DMA receive buffer
 *                                                          | - evaluates expression
 *                                                          | - serializes result
 *                                                          | |
 * +--------------------------------------------------------+-+ message:
 * |                                                        |   - address of destination-local data
 * |                                                        |   - size of closure
 * v                                                        |
 * allocate_source_memory:                                  |
 * - allocates DMA receive buffer                           |
 * |                                                        |
 * +--------------------------------------------------------+-+
 *     message:                                             | |
 *     - address of destination-local data                  | |
 *     - address of receive buffer                          | |
 *       (can be used to synthesize buffer size)            | |
 *                                                          | v
 *                                                          | transfer_result:
 *                                                          | - initiates DMA transfer of closure
 *                                                          | |
 * +--------------------------------------------------------+-+ message:
 * |                                                        | | - address of receive buffer
 * |                                                        | |   (can be used to synthesize buffer size)
 * |                                                        | | - address of source-local data
 * |                                                        | |
 * |                                                        | | message:
 * |                                                        | | - address of destination-local data
 * v                                                        | v
 * receive_result:                                          | wait_for_global_termination:
 * - deserializes closure                                   | - frees send buffer
 * - frees DMA receive buffer                               | - frees destination-local data
 * - notifies local termination                             | - waits for global termination
 * |                                                        | - frees top level finish state
 * v                                                        | |
 * x10_execute_at:                                          | |
 * - wakes up                                               | |
 * - terminates locally                                     | |
 *                                                          | |
 * +--------------------------------------------------------+-+ message:
 * |                                                        |   - source finish state
 * v                                                        |
 * notify_global_termination:                               |
 * - unregisters from source finish state                   |
 *   (at expression terminates globally)                    |
 */

struct source_local_data {
	simple_signal   *join_signal;
	finish_state_t  *finish_state;
	x10_int          message_type;
	void            *obstack;
	x10_object      *return_value;
	void            *send_buffer;
	buf_size_t       buffer_size;
	dispatch_claim_t dispatch_claim;
};
typedef struct source_local_data source_local_data_t;

/* Data structure that acts as receive buffer. */
struct source_dma_data {
	buf_size_t buffer_size;
	char       _padding[ARCH_DMA_BLOCK_SIZE - sizeof(buf_size_t)];
	char       receive_buffer[];
};
typedef struct source_dma_data source_dma_data_t;

struct destination_local_data {
	buf_size_t        buffer_size;
	finish_state_t   *finish_state;
	void             *obstack;
	void             *send_buffer;
	dispatch_claim_t  source_dispatch_claim;
	void             *source_local_data;
	void             *source_finish_state;
};
typedef struct destination_local_data destination_local_data_t;

/* Data structure that acts as receive buffer. */
struct destination_dma_data {
	destination_local_data_t *destination_local_data;
	char                      _padding[ARCH_DMA_BLOCK_SIZE - sizeof(destination_local_data_t*)];
	char                      receive_buffer[];
};
typedef struct destination_dma_data destination_dma_data_t;

/* Notifies local termination of the at statement/expression. */
static void notify_local_termination(void *arg)
{
	source_local_data_t *source_local_data = (source_local_data_t *)arg;

	simple_signal_signal(source_local_data->join_signal);
}

/* Notifies global termination of the at statement/expression. */
static void notify_global_termination(void *arg)
{
	finish_state_t *fs = (finish_state_t *)arg;

	unregister_from_finish_state(fs);
}

/* Frees obstack that acts as send buffer. */
static void free_obstack(void *obstack)
{
	struct obstack *obst = (struct obstack *)obstack;

	obstack_free(obst, NULL);
	mem_free_tlm(obst);
}

static void do_run_at_statement(void *arg, void *source_finish_state, bool notify_local)
{
	/* Create a new top level finish state on the new tile. */
	finish_state_t fs;
	finish_state_init_root(&fs);
	init_x10_activity(&fs);

	/* Deserialize object. */
	char                     *buf                    = get_local_address(arg);
	destination_dma_data_t   *destination_dma_data   = (destination_dma_data_t *)(buf - offsetof(destination_dma_data_t, receive_buffer));
	destination_local_data_t *destination_local_data = destination_dma_data->destination_local_data;
	x10_object               *closure                = x10_deserialize_from(destination_dma_data->receive_buffer, destination_local_data->buffer_size);
	dispatch_claim_t          source_claim           = destination_local_data->source_dispatch_claim;
	void                     *source_local_data      = destination_local_data->source_local_data;

	/* Free destination's data. */
	mem_free_tlm(destination_dma_data);
	mem_free_tlm(destination_local_data);

	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(closure);

	if (notify_local) {
		/* Notify local termination to source tile. */
		simple_ilet notify_local_termination_ilet;
		simple_ilet_init(&notify_local_termination_ilet, notify_local_termination, source_local_data);
		dispatch_claim_infect(source_claim, &notify_local_termination_ilet, 1);
	}

	/* Wait for global termination. */
	finish_state_wait(&fs);
	finish_state_destroy(&fs);

	/* Notify global termination to source tile. */
	simple_ilet notify_global_termination_ilet;
	simple_ilet_init(&notify_global_termination_ilet, notify_global_termination, source_finish_state);
	dispatch_claim_infect(source_claim, &notify_global_termination_ilet, 1);
}

/* Runs an at async statement. */
static void run_at_async_statement(void *arg, void *source_finish_state)
{
	do_run_at_statement(arg, source_finish_state, false);
}

/* Runs an at statement. */
static void run_at_statement(void *arg, void *source_finish_state)
{
	do_run_at_statement(arg, source_finish_state, true);
}

static inline void write_uid(char *buf, uint32_t val)
{
	buf[0] = (uint8_t)(val >>  0);
	buf[1] = (uint8_t)(val >>  8);
	buf[2] = (uint8_t)(val >> 16);
	buf[3] = (uint8_t)(val >> 24);
}

/* Runs an at async statement with a small closure. */
static void run_at_async_statement_small(void *arg, void *source_finish_state)
{
	/* Create a new top level finish state on the new tile. */
	finish_state_t fs;
	finish_state_init_root(&fs);
	init_x10_activity(&fs);

	/* Deserialize object. */
	x10_object closure;
	x10_deserialization_restore_stateless_object(&closure, (uint32_t)(uintptr_t)arg);

	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(&closure);

	/* Wait for global termination. */
	finish_state_wait(&fs);
	finish_state_destroy(&fs);

	/* Notify global termination to source tile. */
	simple_ilet notify_global_termination_ilet;
	simple_ilet_init(&notify_global_termination_ilet, notify_global_termination, source_finish_state);
	dispatch_claim_send_reply(&notify_global_termination_ilet);
}

/* Cleans up and waits until at expression terminates globally. */
static void wait_for_global_termination(void *destination_data)
{
	destination_local_data_t *destination_local_data = (destination_local_data_t *)destination_data;
	void                     *obstack                = destination_local_data->obstack;

	free_obstack(obstack);

	finish_state_t   *finish_state        = destination_local_data->finish_state;
	dispatch_claim_t  source_claim        = destination_local_data->source_dispatch_claim;
	void             *source_finish_state = destination_local_data->source_finish_state;

	/* Free destination's local data. */
	mem_free_tlm(destination_local_data);

	/* Wait for global termination. */
	finish_state_wait(finish_state);
	finish_state_destroy(finish_state);
	mem_free_tlm(finish_state);

	/* Notify global termination to source tile. */
	simple_ilet notify_global_termination_ilet;
	simple_ilet_init(&notify_global_termination_ilet, notify_global_termination, source_finish_state);
	dispatch_claim_infect(source_claim, &notify_global_termination_ilet, 1);
}

/* Receives the result of the at expression. */
static void receive_result(void *source_buffer, void *source_data)
{
	char                *buf               = get_local_address(source_buffer);
	source_dma_data_t   *source_dma_data   = (source_dma_data_t *)(buf - offsetof(source_dma_data_t, receive_buffer));
	buf_size_t           buffer_size       = source_dma_data->buffer_size;
	source_local_data_t *source_local_data = (source_local_data_t *)source_data;

	source_local_data->return_value = x10_deserialize_from(buf, buffer_size);

	/* Free source's DMA data. */
	mem_free_tlm(source_dma_data);

	notify_local_termination(source_local_data);
}

/* Transfers the closure of the result of the at expression. */
static void transfer_result(void *destination_data, void *source_buffer)
{
	destination_local_data_t *destination_local_data = (destination_local_data_t *)destination_data;
	void                     *send_buffer            = destination_local_data->send_buffer;
	dispatch_claim_t          source_claim           = destination_local_data->source_dispatch_claim;
	void                     *source_local_data      = destination_local_data->source_local_data;
	buf_size_t                buffer_size            = destination_local_data->buffer_size;

	assert(buffer_size > 0);

	/* Perform DMA transfer. */
	simple_ilet local;
	simple_ilet remote;
	simple_ilet_init(&local, wait_for_global_termination, destination_local_data);
	dual_ilet_init(&remote, receive_result, source_buffer, source_local_data);
	dispatch_claim_push_dma(source_claim, send_buffer, source_buffer, buffer_size, &local, &remote);
}

/* Allocates the receive buffer in the source memory. */
static void allocate_source_memory(void *destination_local_data, void *buffer_size)
{
	source_dma_data_t *source_dma_data = mem_allocate_tlm(sizeof(*source_dma_data) + (buf_size_t)(uintptr_t)buffer_size);
	void              *source_buffer   = &source_dma_data->receive_buffer;
	simple_ilet        dma_ilet;
	source_dma_data->buffer_size = (buf_size_t)(uintptr_t)buffer_size;

	dual_ilet_init(&dma_ilet, transfer_result, destination_local_data, get_global_address(source_buffer));
	dispatch_claim_send_reply(&dma_ilet);
}

/* Evaluates an at expression. */
static void evaluate_at_expression(void *arg, void *source_finish_state)
{
	/* Create a new top level finish state on the new tile. */
	finish_state_t *fs = mem_allocate_tlm(sizeof(*fs));
	finish_state_init_root(fs);
	init_x10_activity(fs);

	/* Deserialize object. */
	char                     *buf                    = get_local_address(arg);
	destination_dma_data_t   *destination_dma_data   = (destination_dma_data_t *)(buf - offsetof(destination_dma_data_t, receive_buffer));
	destination_local_data_t *destination_local_data = destination_dma_data->destination_local_data;
	x10_object               *closure                = x10_deserialize_from(destination_dma_data->receive_buffer, destination_local_data->buffer_size);

	/* Free destination's DMA data. */
	mem_free_tlm(destination_dma_data);

	x10_object *return_value = _ZN3x104lang7Runtime14callAnyClosureEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

	/* Serialize return value. */
	struct obstack *obst = mem_allocate_tlm(sizeof(*obst));
	_obstack_begin(obst, 0, ARCH_DMA_BLOCK_SIZE, (void *(*) (PTR_INT_TYPE))obstack_chunk_alloc, (void (*) (void *))obstack_chunk_free);
	x10_serialize_to_obst(obst, return_value);

	/* Set destination-local data. */
	destination_local_data->buffer_size         = obstack_object_size(obst);
	destination_local_data->finish_state        = fs;
	destination_local_data->obstack             = obst;
	destination_local_data->send_buffer         = obstack_finish(obst);
	destination_local_data->source_finish_state = source_finish_state;

	/* Create source i-let for memory allocation. */
	simple_ilet      allocation_ilet;
	dispatch_claim_t source_claim    = destination_local_data->source_dispatch_claim;
	dual_ilet_init(&allocation_ilet, allocate_source_memory, (void*)destination_local_data, (void*)(uintptr_t)destination_local_data->buffer_size);
	dispatch_claim_infect(source_claim, &allocation_ilet, 1);
}

/* Transfers the closure needed to execute the at statement/expression. */
static void transfer_parameters(void *source_data, void *destination_buffer)
{
	source_local_data_t *source_local_data = (source_local_data_t *)source_data;
	finish_state_t      *finish_state      = source_local_data->finish_state;
	x10_int              message_type      = source_local_data->message_type;
	void                *obstack           = source_local_data->obstack;
	void                *send_buffer       = source_local_data->send_buffer;
	buf_size_t           buffer_size       = source_local_data->buffer_size;
	dispatch_claim_t     dispatch_claim    = source_local_data->dispatch_claim;

	assert(buffer_size > 0);

	/* Perform DMA transfer. */
	simple_ilet local;
	simple_ilet remote;
	simple_ilet_init(&local, free_obstack, obstack);
	if (message_type == MSG_EVAL_AT) {
		dual_ilet_init(&remote, evaluate_at_expression, destination_buffer, finish_state);
	} else if (message_type == MSG_RUN_AT) {
		dual_ilet_init(&remote, run_at_statement, destination_buffer, finish_state);
	} else {
		assert(message_type == MSG_RUN_AT_ASYNC);
		dual_ilet_init(&remote, run_at_async_statement, destination_buffer, finish_state);
	}
	dispatch_claim_push_dma(dispatch_claim, send_buffer, destination_buffer, buffer_size, &local, &remote);

	if (message_type == MSG_RUN_AT_ASYNC) {
		simple_signal_signal(source_local_data->join_signal);
	}
}

/* Allocates the receive buffer in the destination memory. */
static void allocate_destination_memory(void *source_local_data, void *buffer_size)
{
	destination_local_data_t *destination_local_data = mem_allocate_tlm(sizeof(*destination_local_data));
	destination_dma_data_t   *destination_dma_data   = mem_allocate_tlm(sizeof(*destination_dma_data) + (buf_size_t)(uintptr_t)buffer_size);
	simple_ilet               dma_ilet;

	destination_local_data->buffer_size           = (buf_size_t)(uintptr_t)buffer_size;
	destination_local_data->source_dispatch_claim = get_parent_dispatch_claim();
	destination_local_data->source_local_data     = source_local_data;
	destination_dma_data->destination_local_data  = destination_local_data;

	void *global_receive_buffer = get_global_address(&destination_dma_data->receive_buffer);
	dual_ilet_init(&dma_ilet, transfer_parameters, source_local_data, global_receive_buffer);
	dispatch_claim_send_reply(&dma_ilet);
}

static x10_object *x10_execute_at_dispatch_claim(dispatch_claim_t destination_claim, x10_int msg_type, x10_object *closure)
{
	assert(msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT || msg_type == MSG_RUN_AT_ASYNC);

	/* Switch to fast path for at async with small closures. */
	const class_info_t *closure_info = closure->vptr->runtime_type_info;
	const bool          is_small     = closure_info->size <= sizeof(void*);
	if (is_small && msg_type == MSG_RUN_AT_ASYNC) {
		const uint32_t  uid          = closure_info->uid;
		finish_state_t *finish_state = finish_state_get_current();

		/* Register at current finish state to recognize global termination of the at. */
		register_at_finish_state(finish_state);

		simple_ilet remote_ilet;
		dual_ilet_init(&remote_ilet, run_at_async_statement_small, (void*)(uintptr_t)uid, finish_state);
		dispatch_claim_infect(destination_claim, &remote_ilet, 1);
		return NULL;
	}

	/* Serialize closure. */
	struct obstack *obst = mem_allocate_tlm(sizeof(*obst));
	_obstack_begin(obst, 0, ARCH_DMA_BLOCK_SIZE, (void *(*) (PTR_INT_TYPE))obstack_chunk_alloc, (void (*) (void *))obstack_chunk_free);
	x10_serialize_to_obst(obst, closure);

	/* Initialize source-local data. */
	simple_signal        join_signal;
	source_local_data_t  source_local_data;
	finish_state_t      *finish_state      = finish_state_get_current();
	source_local_data.join_signal  = &join_signal;
	source_local_data.finish_state = finish_state;
	source_local_data.message_type = msg_type;
	source_local_data.buffer_size  = obstack_object_size(obst);
	source_local_data.obstack      = obst;
	source_local_data.return_value = NULL;
	source_local_data.send_buffer  = obstack_finish(obst);

	simple_signal_init(&join_signal, 1);

	source_local_data.dispatch_claim = destination_claim;

	/* Register at current finish state to recognize global termination of the at. */
	register_at_finish_state(finish_state);

	/* Create destination i-let for memory allocation. */
	simple_ilet allocation_ilet;
	dual_ilet_init(&allocation_ilet, allocate_destination_memory, (void*)&source_local_data, (void*)(uintptr_t)source_local_data.buffer_size);
	dispatch_claim_infect(destination_claim, &allocation_ilet, 1);

	/* Wait for local termination. */
	simple_signal_wait(&join_signal);

	return source_local_data.return_value;
}

x10_object *x10_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure)
{
	if (place_id == INVASIC_HOST_PLACE_ID) {
		/* Special host place. */
		return exec_on_invasic_host(msg_type, closure);
	}

	place_local_data *pld = claim_get_local_data(get_claim());
	assert(place_id >= 0);
	assert((unsigned)place_id < pld->n_places);
	dispatch_claim_t dc = pld->places[place_id];

	return x10_execute_at_dispatch_claim(dc, msg_type, closure);
}

#ifdef USE_AGENTSYSTEM
static dispatch_claim_t get_dispatch_claim(x10_int pid, agentclaim_t ac)
{
	int tid = agent_claim_get_tileid_iterative(ac, pid);
	proxy_claim_t pc = agent_claim_get_proxyclaim_tile_type(ac, tid, 0);
	dispatch_claim_t dc = proxy_get_dispatch_info(pc);
	return dc;
}

x10_object *x10_eval_at_agent(x10_int pid, void *agentclaim, x10_object *closure)
{
	dispatch_claim_t dc = get_dispatch_claim(pid, (agentclaim_t)agentclaim);
	return x10_execute_at_dispatch_claim(dc, MSG_EVAL_AT, closure);
}

void x10_exec_at_agent(x10_int pid, void *agentclaim, x10_object *closure)
{
	dispatch_claim_t dc = get_dispatch_claim(pid, (agentclaim_t)agentclaim);
	x10_execute_at_dispatch_claim(dc, MSG_RUN_AT, closure);
}

void x10_exec_atasync_agent(x10_int pid, void *agentclaim, x10_object *closure)
{
	dispatch_claim_t dc = get_dispatch_claim(pid, (agentclaim_t)agentclaim);
	x10_execute_at_dispatch_claim(dc, MSG_RUN_AT_ASYNC, closure);
}
#endif
