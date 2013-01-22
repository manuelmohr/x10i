#include "remote_exec.h"
#include "ilocal_data.h"
#include "async.h"
#include "init.h"

void x10_rt_init()
{
	x10_rt_set_here_id(0);
}

x10_int x10_rt_get_here_id()
{
	ilocal_data_t *ilocal = get_ilocal_data();
	return ilocal->here_id;
}

void x10_rt_set_here_id(x10_int id)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	ilocal->here_id = id;
}

typedef struct {
	simple_signal join_signal;
	void         *other_args;
} octopos_place_execute_args;

static void octopos_place_execute(void *arg)
{
	octopos_place_execute_args *opea = arg;

	x10_rt_place_execute(opea->other_args);

	simple_signal_signal(&opea->join_signal);
}

void x10_rt_spawn(x10_int place_id, void *arg, size_t arg_len)
{
	(void) place_id; /* TODO: associate the place (id) with a claim_t. */
	(void) arg_len;

	octopos_place_execute_args *opea = xmalloc(sizeof(octopos_place_execute_args));
	simple_signal_init(&opea->join_signal, 1);
	opea->other_args = arg;

	simple_ilet *ilet = xmalloc(sizeof(simple_ilet));
	simple_ilet_init(ilet, octopos_place_execute, opea);

	infect(finish_state_get_current()->claim, ilet, 1);
	simple_signal_wait(&opea->join_signal);

	xfree(opea);
	xfree(ilet);
}

void x10_rt_dma(void *dest, const void *src, size_t len)
{
	memcpy(dest, src, len);
}
