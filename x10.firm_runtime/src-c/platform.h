/* platform-specific abstraction interface */
#ifndef PLATFORM_H
#define PLATFORM_H

#include <stddef.h>

void x10_write_block(const void *data, size_t size);

void oplock_lock(void);
void oplock_unlock(void);

#endif
