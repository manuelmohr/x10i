#include <octopos.h>
#include "async.h"
#include "ilocal_data.h"
#include "places_octopos.h"
#include "remote_exec.h"
#include "serialization.h"
#include "x10_runtime.h"

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

	simple_signal_signal(&fs->signal);
}

/* Frees obstack that acts as send buffer. */
static void free_obstack(void *obstack)
{
	struct obstack *obst = (struct obstack *)obstack;

	obstack_free(obst, NULL);
	mem_free(obst);
}

/* Runs an at statement. */
static void run_at_statement(void *arg, void *source_finish_state)
{
	/* Deserialize object. */
	char                     *buf                    = get_local_address(arg);
	destination_dma_data_t   *destination_dma_data   = (destination_dma_data_t *)(buf - offsetof(destination_dma_data_t, receive_buffer));
	destination_local_data_t *destination_local_data = destination_dma_data->destination_local_data;
	x10_object               *closure                = x10_deserialize_from(destination_dma_data->receive_buffer, destination_local_data->buffer_size);
	dispatch_claim_t          source_claim           = destination_local_data->source_dispatch_claim;
	void                     *source_local_data      = destination_local_data->source_local_data;

	/* Free destination's data. */
	mem_free(destination_dma_data);
	mem_free(destination_local_data);

	/* Create a new top level finish state on the new tile. */
	finish_state_t fs;
	fs.claim = get_claim();
	simple_signal_init(&fs.signal, 0);
	finish_state_set_current(&fs);
	register_at_finish_state(&fs);
	activity_set_atomic_depth(0);

	_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(closure);

	/* Notify local termination to source tile. */
	simple_ilet notify_local_termination_ilet;
	simple_ilet_init(&notify_local_termination_ilet, notify_local_termination, source_local_data);
	dispatch_claim_infect(source_claim, &notify_local_termination_ilet, 1);

	unregister_from_finish_state(&fs);

	/* Wait for global termination. */
	simple_signal_wait(&fs.signal);

	/* Notify global termination to source tile. */
	simple_ilet notify_global_termination_ilet;
	simple_ilet_init(&notify_global_termination_ilet, notify_global_termination, source_finish_state);
	dispatch_claim_infect(source_claim, &notify_global_termination_ilet, 1);
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
	mem_free(destination_local_data);

	unregister_from_finish_state(finish_state);

	/* Wait for global termination. */
	simple_signal_wait(&finish_state->signal);

	mem_free(finish_state);

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
	mem_free(source_dma_data);

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
	source_dma_data_t *source_dma_data = mem_allocate(MEM_TLM_LOCAL, sizeof(*source_dma_data) + (buf_size_t)buffer_size);
	void              *source_buffer   = &source_dma_data->receive_buffer;
	simple_ilet        dma_ilet;
	source_dma_data->buffer_size = (buf_size_t)buffer_size;

	dual_ilet_init(&dma_ilet, transfer_result, destination_local_data, get_global_address(source_buffer));
	dispatch_claim_send_reply(&dma_ilet);
}

/* Evaluates an at expression. */
static void evaluate_at_expression(void *arg, void *source_finish_state)
{
	/* Deserialize object. */
	char                     *buf                    = get_local_address(arg);
	destination_dma_data_t   *destination_dma_data   = (destination_dma_data_t *)(buf - offsetof(destination_dma_data_t, receive_buffer));
	destination_local_data_t *destination_local_data = destination_dma_data->destination_local_data;
	x10_object               *closure                = x10_deserialize_from(destination_dma_data->receive_buffer, destination_local_data->buffer_size);

	/* Free destination's DMA data. */
	mem_free(destination_dma_data);

	/* Create a new top level finish state on the new tile. */
	finish_state_t *fs = mem_allocate(MEM_TLM_LOCAL, sizeof(*fs));
	fs->claim = get_claim();
	simple_signal_init(&fs->signal, 0);
	finish_state_set_current(fs);
	register_at_finish_state(fs);
	activity_set_atomic_depth(0);

	x10_object *return_value = _ZN3x104lang7Runtime14callAnyClosureEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

	/* Serialize return value. */
	struct obstack *obst = mem_allocate(MEM_TLM_LOCAL, sizeof(*obst));
	obstack_init(obst);
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
	dual_ilet_init(&allocation_ilet, allocate_source_memory, (void*)destination_local_data, (void*)destination_local_data->buffer_size);
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
	} else {
		assert(message_type == MSG_RUN_AT);
		dual_ilet_init(&remote, run_at_statement, destination_buffer, finish_state);
	}
	dispatch_claim_push_dma(dispatch_claim, send_buffer, destination_buffer, buffer_size, &local, &remote);
}

/* Allocates the receive buffer in the destination memory. */
static void allocate_destination_memory(void *source_local_data, void *buffer_size)
{
	destination_local_data_t *destination_local_data = mem_allocate(MEM_TLM_LOCAL, sizeof(*destination_local_data));
	destination_dma_data_t   *destination_dma_data   = mem_allocate(MEM_TLM_LOCAL, sizeof(*destination_dma_data) + (buf_size_t)buffer_size);
	simple_ilet               dma_ilet;

	destination_local_data->buffer_size           = (buf_size_t)buffer_size;
	destination_local_data->source_dispatch_claim = get_parent_dispatch_claim();
	destination_local_data->source_local_data     = source_local_data;
	destination_dma_data->destination_local_data  = destination_local_data;

	void *global_receive_buffer = get_global_address(&destination_dma_data->receive_buffer);
	dual_ilet_init(&dma_ilet, transfer_parameters, source_local_data, global_receive_buffer);
	dispatch_claim_send_reply(&dma_ilet);
}

x10_object *x10_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure)
{
	assert(msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT);

	/* Serialize closure. */
	struct obstack *obst = mem_allocate(MEM_TLM_LOCAL, sizeof(*obst));
	obstack_init(obst);
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

#ifdef USE_AGENTSYSTEM
	agentclaim_t myClaim = agentclaim_get_current();
	proxy_claim_t pClaim = agent_claim_get_proxyclaim_tile_type(myClaim, place_id, 0);
	dispatch_claim_t destination_claim = proxy_get_dispatch_info(pClaim);
#else
	assert(place_id >= 0 && (unsigned)place_id < n_places);
	dispatch_claim_t destination_claim = places[place_id];
#endif

	source_local_data.dispatch_claim = destination_claim;

	/* Create destination i-let for memory allocation. */
	simple_ilet allocation_ilet;
	dual_ilet_init(&allocation_ilet, allocate_destination_memory, (void*)&source_local_data, (void*)source_local_data.buffer_size);
	dispatch_claim_infect(destination_claim, &allocation_ilet, 1);

	/* Register at current finish state to recognize global termination of the at. */
	register_at_finish_state(finish_state);

	/* Wait for local termination. */
	simple_signal_wait(&join_signal);

	return source_local_data.return_value;
}
