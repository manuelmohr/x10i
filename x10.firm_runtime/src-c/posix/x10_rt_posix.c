
#include <pthread.h>
#include "x10_rt.h"

typedef struct {
	x10_int here;
} x10_rt_state;

pthread_key_t rt_state_key;

void x10_rt_init()
{
	printf("X10 runtime [posix]: Hello.\n");

	assert (! pthread_key_create(&rt_state_key, NULL));

	x10_rt_set_here_id(0);
}

x10_int x10_rt_get_here_id()
{
	x10_rt_state *state = pthread_getspecific(rt_state_key);
	if (state == NULL)
		panic("No rt state found.");
	return state->here;
}

void x10_rt_set_here_id(x10_int id)
{
	x10_rt_state *state = pthread_getspecific(rt_state_key);
	if (state == NULL) {
		state = calloc(1, sizeof(x10_rt_state));
		if (pthread_setspecific(rt_state_key, state))
			panic("Cannot set rt state.");
	}
	state->here = id;
}

void x10_rt_dma(void *dest, const void *src, size_t len)
{
	memcpy(dest, src, len);
}

static void *posix_place_execute(void *arg)
{
	x10_rt_place_execute(arg);
	pthread_exit(NULL);
}

void x10_rt_spawn(x10_int place_id, void *arg, size_t arg_len)
{
	(void) place_id;
	(void) arg_len;

	pthread_t worker;
	pthread_create(&worker, NULL, posix_place_execute, arg);
	pthread_join(worker, NULL);
}
