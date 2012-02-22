/* platform-specific abstraction interface */
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stddef.h>

void x10_write_block(const void *data, size_t size);

void oplock_lock(void);
void oplock_unlock(void);

#endif
