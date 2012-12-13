#include "main.h"
#include "init.h"

int main(int argc, char **argv)
{
	init_mutex();
	init_locks();
	init_finish_state();

	x10_rt_init();

	(void)argc;
	(void)argv;
	x10_main(NULL);

	exit_finish_state();
	destroy_locks();

	return 0;
}
