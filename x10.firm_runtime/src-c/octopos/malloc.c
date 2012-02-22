/* poor mans allocator */
#include <stddef.h>
#include <string.h>

/* 16MB ought to be enough for anybody */
static char        storage[16*1024*1024];
static const char *storage_end = storage + sizeof(storage);
static char       *used        = storage;

void *malloc(size_t size)
{
	if (used+size >= storage_end)
		return NULL;
	void *result = used;
	used += size;
	return result;
}

void free(void *ptr)
{
	(void)ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t full_size = nmemb * size; /* who cares about overflow */
	void  *result    = malloc(full_size);
	memset(result, 0, full_size);
	return result;
}

void* realloc(void *ptr, size_t size)
{
	void *newmem = malloc(size);
	memcpy(newmem, ptr, size); /* copies too much but shouldn't hurt */
	return newmem;
}
