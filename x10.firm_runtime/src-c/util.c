#include "util.h"

void panic(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	abort();
}
