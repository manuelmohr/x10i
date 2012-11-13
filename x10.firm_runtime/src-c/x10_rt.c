
#include <stdio.h>

#include "x10_rt.h"
#include "x10_serialization.h"
#include "async.h"

extern void *_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(x10_object *closure);
extern void *_ZN3x104lang7Runtime8evaluateEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(x10_object *closure);

typedef struct {
	x10_int       place_id;
	x10_int       msg_type;
	finish_state *fs;

	size_t        closure_len;
	void         *closure;

	size_t        result_len;
	char         *result;
} place_execute_args;

void x10_rt_place_execute(void *arg)
{
	place_execute_args *pea = arg;

	/* set up state for the newly create thread. */
	x10_rt_set_here_id(pea->place_id);
	finish_state_set_current(pea->fs);

	char *recv_buf = malloc(pea->closure_len);
	if (! recv_buf)
		panic("Could not allocate receive buffer.");

	x10_rt_dma(recv_buf, pea->closure, pea->closure_len);

	deserialization_buffer_t *deser_buf = x10_deserialization_init(recv_buf, pea->closure_len);
	x10_object *closure;
	x10_deserialization_restore_object(deser_buf, &closure);
	x10_deserialization_finish(deser_buf);
	free(recv_buf);

	if (pea->msg_type == MSG_RUN_AT) {
		_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(closure);
	} else if (pea->msg_type == MSG_EVAL_AT) {
		x10_object *ret = _ZN3x104lang7Runtime8evaluateEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

		serialization_buffer_t *ser_buf = x10_serialization_init();
		x10_serialization_write_object(ser_buf, ret);

		pea->result_len  = ser_buf->bytes_written;
		pea->result      = x10_serialization_finish(ser_buf);
	} else {
		panic("Unhandled message type.");
	}

	unregister_from_finish_state(pea->fs);
}

x10_object *x10_rt_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure)
{
	assert (msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT);

	serialization_buffer_t* ser_buf = x10_serialization_init();
	x10_serialization_write_object(ser_buf, closure);

	place_execute_args *pea = malloc(sizeof(place_execute_args));
	pea->place_id    = place_id;
	pea->msg_type    = msg_type;
	pea->fs          = finish_state_get_current();

	pea->closure_len = ser_buf->bytes_written;
	pea->closure     = x10_serialization_finish(ser_buf);
	pea->result_len  = 0;
	pea->result      = NULL;

	register_at_finish_state(pea->fs);

	x10_rt_spawn(place_id, pea, sizeof(place_execute_args));

	x10_object *retVal = NULL;
	if (msg_type == MSG_EVAL_AT) {
		char *recv_buf = malloc(pea->result_len);
		x10_rt_dma(recv_buf, pea->result, pea->result_len);

		deserialization_buffer_t *deser_buf = x10_deserialization_init(recv_buf, pea->result_len);

		x10_deserialization_restore_object(deser_buf, &retVal);
		x10_deserialization_finish(deser_buf);

		free(recv_buf);
	}

	free(pea->closure);
	if (pea->result)
		free(pea->result);
	free(pea);

	return retVal;
}
