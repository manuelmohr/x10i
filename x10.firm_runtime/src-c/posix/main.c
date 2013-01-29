#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>
#include "main.h"
#include "init.h"
#include "places.h"
#include "xmalloc.h"

long master_pid;
/* maximum of 4 places by default */
unsigned n_places = 4;
/* current place */
unsigned place_id;

static void init_places(void)
{
	char *nplaces = getenv("X10_NPLACES");
	if (nplaces != NULL) {
		int nplaces_int = atoi(nplaces);
		if (nplaces_int > 0)
			n_places = (unsigned)nplaces_int;
	}
}

int main(int argc, char **argv)
{
	init_places();
	create_ipc_shared_memory();

	master_pid = (long) getpid();
	/* let's fork until we have a process for each place */
	for (unsigned i = 1; i < n_places; ++i) {
		pid_t new_pid = fork();
		if (new_pid == 0) {
			/* child process */
			place_id = i;
			break;
		}
	}

	init_ipc();
	atexit(shutdown_ipc);

	init_mutex();
	init_locks();
	init_finish_state();

	x10_static_initializer();

	/* start main activity on the root place */
	if (place_id == 0) {
		/* construct args array */
		x10_string *arg_pointers[argc-1];
		for (int i = 1; i < argc; ++i) {
			arg_pointers[i-1] = x10_string_from_cstring(argv[i]);
		}
		x10_object *array = _ZN3x105array5Array15makeStringArrayEPvi((x10_pointer)&arg_pointers, argc-1);
		x10_main(array);
	} else {
		/* idle around until we get an exit signal... */
		x10_idle();
	}

	exit_finish_state();
	destroy_locks();

	return exit_code;
}
