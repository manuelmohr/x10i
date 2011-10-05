#include "x10_thread.h"
#include "util.h"

// internal thread id counter (monotonically increasing only)
static long __thread_cnt;
static pthread_key_t __thread_mapper;
static x10_boolean __thread_mapper_inited;

// this __thread_start_trap gets used by the X10 debugger, to help it differentiate
// an X10 worker thread from other threads in the application (GC, network, etc).
void __thread_start_trap() {}

// method to bind the process to a single processor
static void thread_bind_cpu(x10_thread *self)
{
// TODO: Implement me
	X10_UNUSED(self);
/*
	// open the file specified by X10RT_CPUMAP
	char * filename = getenv("X10RT_CPUMAP");
	if (filename == NULL) return;
#ifdef __linux__
	FILE * fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Unable to read %s, specified by X10RT_CPUMAP.  Continuing without cpu binding...\n", filename);
		return;
	}

	int lineNumber = 0;
	char buffer[32];
	while (lineNumber <= x10aux::here)
	{
		char* s = fgets(buffer, sizeof(buffer), fd);
		if (s == NULL)
		{
			fprintf(stderr, "Unable to bind place %u to a CPU because there %s only %i line%s in the file %s. Continuing without cpu binding...\n", x10aux::here, lineNumber==1?"is":"are", lineNumber, lineNumber==1?"":"s",filename);
			fclose(fd);
			return;
		}

		if (lineNumber < x10aux::here)
		{
			lineNumber++;
			continue;
		}

		int processor = (int) strtol(s, (char **)NULL, 10);
		if (processor==0 && (errno == EINVAL || errno == ERANGE))
			fprintf(stderr, "Unable to bind place %u to CPU \"%s\": %s.  Continuing without cpu binding...\n", x10aux::here, s, strerror(errno));

		cpu_set_t mask;
		CPU_ZERO(&mask); // disable all CPUs (all are enabled by default)
		CPU_SET(processor, &mask); // enable the one CPU specified in the file
		if( sched_setaffinity(0, sizeof(mask), &mask ) == -1 )
			fprintf(stderr, "Unable to bind place %u to CPU %i: %s. Continuing without cpu binding...\n", x10aux::here, processor, strerror(errno));
		break;
	}
	fclose(fd);
#else
	fprintf(stderr, "X10RT_CPUMAP is not supported on this platform.  Continuing without cpu binding....\n");
#endif
*/
}

// permit initialization
static void x10_thread_thread_permit_init(permit_t *perm)
{
	pthread_mutex_init(&(perm->mutex), NULL);
	pthread_cond_init(&(perm->cond), NULL);
	perm->permit = false;
}


// permit finalization
static void x10_thread_thread_permit_destroy(permit_t *perm)
{
	pthread_mutex_destroy(&(perm->mutex));
	pthread_cond_destroy(&(perm->cond));
}

// TODO: Must be called in the thread class destructor.
// permit cleanup
static void x10_thread_thread_permit_cleanup(void *arg)
{
	permit_t *perm = (permit_t *)arg;

	pthread_mutex_unlock(&(perm->mutex));
}

// Dummy interrupt handler.
static void x10_thread_intr_hndlr(int signo)
{
	X10_UNUSED(signo);
	__xrxDPr();
}

// Clean-up routine for sleep method call.
static void x10_thread_thread_sleep_cleanup(void *arg)
{
	cond_mutex_t *cmp = (cond_mutex_t *)arg;

	__xrxDPrStart();
	pthread_mutex_unlock(&(cmp->mutex));
	pthread_mutex_destroy(&(cmp->mutex));
	pthread_cond_destroy(&(cmp->cond));
	x10_sysfree(cmp);
	signal(SIGINT, SIG_DFL);
	__xrxDPrEnd();
}

// Returns the identifier of this thread.
x10_long x10_thread_get_id(x10_thread *self)
{
	return self->__thread_id;
}

// Returns the system thread id.
x10_long x10_thread_get_tid()
{
	return (x10_long)pthread_self();
}

// Waits forever for this thread to die.
void x10_thread_join(x10_thread *self)
{
	__xrxDPrStart();
	pthread_join(self->__xthread, NULL);
	__xrxDPrEnd();
}
// Tests if this thread is alive.
x10_boolean x10_thread_is_alive(x10_thread *self)
{
	__xrxDPrStart();
	if (self->__thread_already_started && self->__thread_running) {
		return true;
	}
	return false;
	__xrxDPrEnd();
}

// Interrupts this thread.
void x10_thread_interrupt(x10_thread *self)
{
	__xrxDPrStart();
	if (x10_thread_is_alive(self)) {
		pthread_kill(self->__xthread, SIGINT);
	}
	__xrxDPrEnd();
}

X10_EXTERN void _ZN3x104lang6Thread18threadStartHook___Ev(x10_thread *);

// Thread start routine.
static void *thread_start_routine(void *arg)
{
	__xrxDPrStart();
	// simply call the run method of the invoking thread object
	x10_thread *tp = (x10_thread *)arg;

	// store this object reference in the place wide mapper key
	if (__thread_mapper_inited) {
		pthread_setspecific(__thread_mapper, arg);
	}

	pthread_mutex_lock(&(tp->__thread_start_lock));

	while (tp->__thread_already_started == false) {
		pthread_cond_wait(&(tp->__thread_start_cond), &(tp->__thread_start_lock));
	}

	pthread_mutex_unlock(&(tp->__thread_start_lock));

	thread_bind_cpu(tp);
	// this thread is now running
	tp->__thread_running = true;
	__thread_start_trap();

	// call the thread start hook
	_ZN3x104lang6Thread18threadStartHook___Ev(tp);

	// finished running
	tp->__thread_running = false;

	__xrxDPrEnd();
	pthread_exit(NULL);
	return NULL; // quell compiler warning
}

x10_thread * _ZN3x104lang6ThreadC1EPN3x104lang6StringE(x10_thread *self, x10_string *name)
{
	__xrxDPrStart();
	// increment the overall thread count
	__thread_cnt += 1;

	// set thread's external id
	self->__thread_id = __thread_cnt;

	// clear this thread's run flags
	self->__thread_already_started = false;
	self->__thread_running = false;

	self->__thread_name = name;

	// create start condition object with default attributes
	// ??check the return code for ENOMEM/EAGAIN??
	(void)pthread_cond_init(&self->__thread_start_cond, NULL);

	// create the associated lock object with default attributes
	// ??check the return code for ENOMEM??
	(void)pthread_mutex_init(&self->__thread_start_lock, NULL);

	/**
	 * create place wide pthread to Thread mapping key to
	 * store thread object reference
	 */
	if (!__thread_mapper_inited) {
		pthread_key_create(&__thread_mapper, NULL);
		__thread_mapper_inited = true;
	}

	// create thread attributes object
	// ??check the return code for ENOMEM??
	(void)pthread_attr_init(&self->__xthread_attr);

	// set this thread's attributes
	// guardsize
#ifdef _AIX
	size_t guardsize = PAGESIZE;
#else
	size_t guardsize = getpagesize();
#endif
	pthread_attr_setguardsize(&self->__xthread_attr, guardsize);
	// inheritsched
	int inheritsched = PTHREAD_INHERIT_SCHED;
	pthread_attr_setinheritsched(&self->__xthread_attr, inheritsched);
	// schedpolicy
	int policy = SCHED_OTHER;
	pthread_attr_setschedpolicy(&self->__xthread_attr, policy);
	// detachstate
	int detachstate = PTHREAD_CREATE_JOINABLE;
	//int detachstate = PTHREAD_CREATE_DETACHED;
	pthread_attr_setdetachstate(&self->__xthread_attr, detachstate);
	// contentionscope
	int contentionscope = PTHREAD_SCOPE_PROCESS;
	pthread_attr_setscope(&self->__xthread_attr, contentionscope);

	/*
	 * NOTE: Setting the stacksize to small breaks BDWGC.
	 *		 Just use the default stacksize to avoid confusing the GC!
	 */
	//stacksize
	//size_t stacksize = PTHREAD_STACK_MIN;
	//*pthread_attr_setstacksize(&__xthread_attr, stacksize);

	// suspendstate
	//int suspendstate = PTHREAD_CREATE_SUSPENDED_NP;
	//pthread_attr_setsuspendstate_np(&__xthread_attr, suspendstate);

	// default: create a new execution thread
	int err = pthread_create(&self->__xthread, &self->__xthread_attr, thread_start_routine, (void *)self);
	if (err) {
		fprintf(stderr, "Could not create worker thread: %s\n", strerror(err));
		abort();
	}
	// create this thread's permit object
	x10_thread_thread_permit_init(&self->__thread_permit);

	__xrxDPrEnd();

	return self;
}

x10_thread *_ZN3x104lang6Thread13currentThreadEv()
{
	return (x10_thread *)pthread_getspecific(__thread_mapper);
}

void _ZN3x104lang6Thread5startEv(x10_thread *self)
{
	__xrxDPrStart();
	if(self->__thread_already_started) {
		x10_throw_exception(T_("IllegalThreadStateException"), T_(""));
	}

	pthread_mutex_lock(&self->__thread_start_lock);
	self->__thread_already_started = true;
	pthread_cond_signal(&self->__thread_start_cond);
	pthread_mutex_unlock(&self->__thread_start_lock);
	__xrxDPrEnd();
}

void _ZN3x104lang6Thread5sleepEx(x10_thread *self, x10_long millis)
{
	_ZN3x104lang6Thread5sleepExi(self, millis, 0);
}

void _ZN3x104lang6Thread5sleepExi(x10_thread *self, x10_long millis, x10_int nanos)
{
	X10_UNUSED(self);
	cond_mutex_t *cmp;
	x10_boolean done = false;
	struct timeval tval;
	struct timespec tout;
	long sleep_usec;
	int rc;

	__xrxDPrStart();
	signal(SIGINT, x10_thread_intr_hndlr);
	cmp = x10_sysalloc(sizeof(cond_mutex_t));
	pthread_mutex_init(&(cmp->mutex), NULL);
	pthread_cond_init(&(cmp->cond), NULL);
	pthread_mutex_lock(&(cmp->mutex));
	pthread_cleanup_push(x10_thread_thread_sleep_cleanup, (void *)cmp);
	gettimeofday(&tval, NULL);
	tout.tv_sec = tval.tv_sec + (millis/1000);
	tout.tv_nsec = ((tval.tv_usec + ((millis%1000) * 1000)) * 1000) + nanos;
	sleep_usec = (tout.tv_sec * 1000 * 1000) + (tout.tv_nsec / 1000);

	while (!done) {
		rc = pthread_cond_timedwait(&(cmp->cond), &(cmp->mutex), &tout);
		if (rc == ETIMEDOUT) {
			// specified timeout has passed
			done = true;
		} else {
			// might be a spurious wakeup
			x10_throw_exception(T_("InterruptedException"), T_(""));
			break;
			/*
			struct timeval cval;
			long cur_usec;
			gettimeofday(&cval, NULL);
			cur_usec = (cval.tv_sec * 1000 * 1000) + cval.tv_usec;
			if (cur_usec < sleep_usec) {
				 throwException<InterruptedException>();
				 done = false;
				 continue;
			}
			*/
		}
	}
	pthread_cleanup_pop(1);
	__xrxDPrEnd();
}


void _ZN3x104lang6Thread4parkEv()
{
	x10_thread *self = _ZN3x104lang6Thread13currentThreadEv();
	permit_t *perm = &(self->__thread_permit);

	pthread_mutex_lock(&(perm->mutex));
	pthread_cleanup_push(x10_thread_thread_permit_cleanup, (void *)perm);
	while (perm->permit == false) {
		pthread_cond_wait(&(perm->cond), &(perm->mutex));
	}
	perm->permit = false;
	pthread_cleanup_pop(1);
}

void _ZN3x104lang6Thread9parkNanosEx(x10_long nanos)
{
	x10_thread *self = _ZN3x104lang6Thread13currentThreadEv();
	permit_t *perm = &(self->__thread_permit);
	struct timeval tval;
	struct timespec tout;
	int rc;
	x10_long nanosPerSecond = 1000000000LL;

	gettimeofday(&tval, NULL);

	/* One must take care to ensure that the final value of tout.tv_nsec is valid (ie, between 0 and 1e9-1). */
	x10_long timeOutNanos = nanos + (tval.tv_usec * 1000);
	x10_long timeOutSeconds = (timeOutNanos/nanosPerSecond);
	timeOutNanos -= (timeOutSeconds*nanosPerSecond);
	assert(timeOutNanos >= 0 && timeOutNanos < nanosPerSecond);

	tout.tv_sec = tval.tv_sec + timeOutSeconds;
	tout.tv_nsec = timeOutNanos;

	pthread_mutex_lock(&(perm->mutex));
	pthread_cleanup_push(x10_thread_thread_permit_cleanup, (void *)perm);
	while (perm->permit == false) {
		rc = pthread_cond_timedwait(&(perm->cond), &(perm->mutex), &tout);
		if (rc == ETIMEDOUT) {
			perm->permit = true;
		}
	}
	perm->permit = false;
	pthread_cleanup_pop(1);
}

void _ZN3x104lang6Thread6unparkEv(x10_thread *self)
{
	permit_t *perm = &(self->__thread_permit);

	pthread_mutex_lock(&(perm->mutex));
	if (!perm->permit) {
		perm->permit = true;
		pthread_cond_signal(&(perm->cond));
	}
	pthread_mutex_unlock(&(perm->mutex));
}

x10_string *_ZN3x104lang6Thread4nameEv(x10_thread *self)
{
	return self->__thread_name;
}

void _ZN3x104lang6Thread4nameEPN3x104lang6StringE(x10_thread *self, x10_string *name)
{
	self->__thread_name = name;
}

void _ZN3x104lang6ThreadapplyEv(x10_thread *self)
{
	X10_UNUSED(self);
	// DO NOTHING -> We will call the Thread "threadStartHook___" hook for dynamic binding of operator()
}

// TODO: Add home struct as return type
x10_any *_ZN3x104lang6Thread4homeEv(x10_thread *self)
{
	X10_UNUSED(self);

	return X10_NULL;
}
