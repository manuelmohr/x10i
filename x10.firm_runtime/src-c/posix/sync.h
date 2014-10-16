#define LOCK_T       pthread_mutex_t
#define LOCK_INIT(x) pthread_mutex_init(x,NULL)
#define LOCK_LOCK    pthread_mutex_lock
#define LOCK_UNLOCK  pthread_mutex_unlock
