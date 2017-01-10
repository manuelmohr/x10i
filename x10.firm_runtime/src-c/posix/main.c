#include <stdlib.h>
#include <limits.h>
#include <sched.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>
#include "main.h"
#include "init.h"
#include "places.h"
#include "serialization.h"
#include "xmalloc.h"

void *_ZN3x108compiler14InitDispatcher17get_staticMonitorEv(void);

int main(int argc, char **argv)
{
	gc_init();

	if (argc == 3 && strcmp(argv[1], "--invasicSystem") == 0) {
		/* Special mode as invasic host system. */
		place_id = (unsigned)INVASIC_HOST_PLACE_ID;
	} else {
		/* Normal startup. */
		init_ipc();
		atexit(shutdown_ipc);
	}

	x10_serialization_init();
	init_finish_state();

	x10_static_initializer();
	/* Make sure that InitDispatcher's static monitor is initialized. */
	(void)_ZN3x108compiler14InitDispatcher17get_staticMonitorEv();

	/* start main activity on the root place */
	if (place_id == 0) {
		/* construct args array */
		x10_string *arg_pointers[argc-1];
		for (int i = 1; i < argc; ++i) {
			arg_pointers[i-1] = x10_string_from_cstring(argv[i]);
		}
		x10_object *array = _ZN3x105array5Array15makeStringArrayEPvi((x10_pointer)&arg_pointers, argc-1);
		x10_main(array);
	} else if (place_id == (unsigned)INVASIC_HOST_PLACE_ID) {
		const char *octo_sys = argv[2];
		run_as_invasic_host(octo_sys);
	} else {
		/* idle around until we get an exit signal... */
		x10_idle();
	}

	exit_finish_state();

	return exit_code;
}
