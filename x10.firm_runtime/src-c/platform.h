/* platform-specific abstraction interface */
#ifndef PLATFORM_H
#define PLATFORM_H

#include <stddef.h>

void oplock_lock(void);
void oplock_unlock(void);

#endif
