#include "remote_exec.h"
#include "ilocal_data.h"
#include "async.h"
#include "init.h"
#include "serialization.h"

static x10_int x10_get_here_id()
{
	ilocal_data_t *ilocal = get_ilocal_data();
	return ilocal->here_id;
}

static void x10_set_here_id(x10_int id)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	ilocal->here_id = id;
}

void x10_rt_init(void)
{
	x10_set_here_id(0);
}

typedef struct {
	simple_signal join_signal;
	void         *other_args;
} octopos_place_execute_args;

static void x10_place_execute(void *arg);
static void octopos_place_execute(void *arg)
{
	octopos_place_execute_args *opea = arg;

	x10_place_execute(opea->other_args);

	simple_signal_signal(&opea->join_signal);
}

static void x10_spawn(x10_int place_id, void *arg, size_t arg_len)
{
	(void) place_id; /* TODO: associate the place (id) with a claim_t. */
	(void) arg_len;

	octopos_place_execute_args *opea = XMALLOC(octopos_place_execute_args);
	simple_signal_init(&opea->join_signal, 1);
	opea->other_args = arg;

	simple_ilet *ilet = XMALLOC(simple_ilet);
	simple_ilet_init(ilet, octopos_place_execute, opea);

	infect(finish_state_get_current()->claim, ilet, 1);
	simple_signal_wait(&opea->join_signal);

	free(opea);
	free(ilet);
}

static void x10_dma(void *dest, const void *src, size_t len)
{
	memcpy(dest, src, len);
}

typedef struct {
	x10_int         place_id;
	x10_int         msg_type;
	finish_state_t *fs;

	size_t          closure_len;
	void           *closure;

	size_t          result_len;
	char           *result;
} place_execute_args;

static void x10_place_execute(void *arg)
{
	place_execute_args *pea = arg;

	/* set up state for the newly create thread. */
	x10_set_here_id(pea->place_id);
	finish_state_set_current(pea->fs);

	char *recv_buf = malloc(pea->closure_len);
	if (! recv_buf)
		panic("Could not allocate receive buffer.");

	x10_dma(recv_buf, pea->closure, pea->closure_len);

	x10_object *closure = x10_deserialize_from(recv_buf, pea->closure_len);
	free(recv_buf);

	if (pea->msg_type == MSG_RUN_AT) {
		_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(closure);
	} else if (pea->msg_type == MSG_EVAL_AT) {
		x10_object *ret = _ZN3x104lang7Runtime8evaluateEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

		struct obstack obst;
		obstack_init(&obst);
		x10_serialize_to_obst(&obst, ret);

		pea->result_len  = obstack_object_size(&obst);
		pea->result      = obstack_finish(&obst);
	} else {
		panic("Unhandled message type.");
	}

	unregister_from_finish_state(pea->fs);
}

x10_object *x10_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure)
{
	assert(msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT);

	struct obstack obst;
	obstack_init(&obst);
	x10_serialize_to_obst(&obst, closure);

	place_execute_args *pea = malloc(sizeof(place_execute_args));
	pea->place_id    = place_id;
	pea->msg_type    = msg_type;
	pea->fs          = finish_state_get_current();

	pea->closure_len = obstack_object_size(&obst);
	pea->closure     = obstack_finish(&obst);
	pea->result_len  = 0;
	pea->result      = NULL;

	register_at_finish_state(pea->fs);

	x10_spawn(place_id, pea, sizeof(place_execute_args));

	x10_object *retVal = NULL;
	if (msg_type == MSG_EVAL_AT) {
		char *recv_buf = malloc(pea->result_len);
		x10_dma(recv_buf, pea->result, pea->result_len);

		retVal = x10_deserialize_from(recv_buf, pea->result_len);
		free(recv_buf);
	}

	free(pea->closure);
	if (pea->result)
		free(pea->result);
	free(pea);

	return retVal;
}
