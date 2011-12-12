#include "x10.h"

#ifdef __bgp__
#ifndef DISABLE_CLOCK_GETTIME
#define DISABLE_CLOCK_GETTIME // seems to be broken on bgp
#endif
#endif

#ifndef DISABLE_CLOCK_GETTIME
#  if !defined(_POSIX_TIMERS) || _POSIX_TIMERS <= 0
#    define DISABLE_CLOCK_GETTIME
#  endif
#endif
#ifndef DISABLE_CLOCK_GETTIME
#  include <time.h>  // for clock_gettime (optional POSIX)
#  if defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0
#    define CLOCK_X10 CLOCK_MONOTONIC
#  else
#    define CLOCK_X10 CLOCK_REALTIME
#  endif
#else
#  include <sys/time.h>  // for gettimeofday (POSIX)
#endif

x10_long _ZN3x104util5Timer8nanoTimeEv()
{
#ifdef DISABLE_CLOCK_GETTIME
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (x10_long)(tv.tv_sec * 1000000000LL + tv.tv_usec * 1000LL);
#else
    struct timespec ts;
    clock_gettime(CLOCK_X10, &ts);
    return (x10_long)(ts.tv_sec * 1000000000LL + ts.tv_nsec);
#endif
}

x10_long _ZN3x104util5Timer9milliTimeEv()
{
#ifdef DISABLE_CLOCK_GETTIME
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (x10_long)(tv.tv_sec * 1000LL + tv.tv_usec / 1000);
#else
    struct timespec ts;
    clock_gettime(CLOCK_X10, &ts);
    return (x10_long)(ts.tv_sec * 1000LL + ts.tv_nsec / 1000000);
#endif
}
