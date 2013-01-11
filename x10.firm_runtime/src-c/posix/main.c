#include <stdlib.h>
#include "main.h"
#include "init.h"
#include "places.h"

/* maximum of 4 places by default */
unsigned max_tile_id = 3;

int main(int argc, char **argv)
{
	char *nplaces = getenv("X10_NPLACES");
	if (nplaces != NULL) {
		int nplaces_int = atoi(nplaces);
		if (nplaces_int > 0)
			max_tile_id = ((unsigned)nplaces_int)-1;
	}

	init_mutex();
	init_locks();
	init_finish_state();

	x10_rt_init();

	x10_static_initializer();

	/* construct args array */
	x10_string *arg_pointers[argc-1];
	for (int i = 1; i < argc; ++i) {
		arg_pointers[i-1] = x10_string_from_cstring(argv[i]);
	}
	x10_object *array = _ZN3x105array5Array15makeStringArrayEPvi((x10_pointer)&arg_pointers, argc-1);
	x10_main(array);

	exit_finish_state();
	destroy_locks();

	return exit_code;
}
