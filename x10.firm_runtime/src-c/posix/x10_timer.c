#include "x10.h"

#include <sys/time.h>

x10_long _ZN3x104util5Timer8nanoTimeEv()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (x10_long)(tv.tv_sec * 1000000000LL + tv.tv_usec * 1000LL);
}

x10_long _ZN3x104util5Timer9milliTimeEv()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (x10_long)(tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}
