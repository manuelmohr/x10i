#include <stdio.h>

#include "x10.h"
#include "x10_thread.h"
#include "x10_lock.h"

int main(int argc, char *argv[])
{
	FILE *file = fopen("firmNativeTypes.conf", "w"); 
	if(!file) {
		fprintf(stderr, "File firmNativeTypes.conf could not be opened for writing"); 
		return -1; 
	}

#define DEF_FIRM_NATIVE_TYPE(pack, name, type)	\
	fprintf(file, "%s %s %i\n", pack, name, sizeof(type))
	
	DEF_FIRM_NATIVE_TYPE("x10.lang", "Thread", x10_thread);
	DEF_FIRM_NATIVE_TYPE("x10.util.concurrent", "Lock", x10_lock); 
	
	fclose(file); 
	return 0; 
}

