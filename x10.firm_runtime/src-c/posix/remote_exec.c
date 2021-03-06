#include <sys/mman.h>
#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/prctl.h>
#include <fcntl.h>
#include "xmalloc.h"
#include "remote_exec.h"
#include "init.h"
#include "serialization.h"
#include "async.h"

#define SHM_SIZE  (8*1024*1024)

static mqd_t                *queues;
static mqd_t                 my_queue;
static void                **shm_addrs;
static pthread_mutex_t       send_mutex;
static pthread_mutex_t       mq_send_mutex;
static volatile sig_atomic_t idle_running = 1;
static pid_t                 master_pid;
static pthread_attr_t        detached_pthread_attr;
static pthread_t             message_receive_thread;

typedef union message_t message_t;
typedef void (*message_handler)(const message_t *message);

typedef struct message_base_t {
	message_handler handler;
} message_base_t;

typedef struct dma_message_t {
	message_base_t  base;
	const char     *data;
	size_t          data_size;
} dma_message_t;

typedef struct completion_simple_message_t {
	message_base_t   base;
	pthread_cond_t  *return_cond;
	bool            *return_flag;
	pthread_mutex_t *return_lock;
} completion_simple_message_t;

typedef struct completion_finish_message_t {
	message_base_t  base;
	finish_state_t *finish_state;
} completion_finish_message_t;

typedef struct init_complete_message_t {
	message_base_t base;
	unsigned       from_place;
} init_complete_message_t;

union message_t {
	message_base_t              base;
	completion_finish_message_t completion_finish;
	completion_simple_message_t completion_simple;
	dma_message_t               dma;
	message_handler             handler;
	init_complete_message_t     init_complete;
};

typedef struct remote_exec_header_t {
	unsigned          from_place;
	x10_int           msg_type;
	pthread_cond_t   *return_cond;
	bool             *return_flag;
	pthread_mutex_t  *return_lock;
	x10_object      **return_value_pointer;
	finish_state_t   *finish_state;
} remote_exec_header_t;

typedef struct completion_header_t {
	unsigned          from_place;
	pthread_cond_t   *return_cond;
	bool             *return_flag;
	pthread_mutex_t  *return_lock;
	x10_object      **return_value_pointer;
} completion_header_t;

static void sigchld_handler(int signum)
{
	(void)signum;
	fprintf(stderr, "x10 runtime: a child place has quit unexpectedly, aborting master\n");
	abort();
}

static void sighup_handler(int signum)
{
	(void)signum;
	idle_running = 0;
}

static void send_msg(const message_t *const msg, unsigned const place)
{
	mqd_t const queue = queues[place];
again:;
	/* Matze: the mq_send here is protected with a mutex. In theory and
	 * according to the posix spec this should not be necessary, but I've had
	 * several programs where I have seen messages disappearing when multiple
	 * threads used mq_send to the same queue at once.
	 * TODO: investigate if this is really a linux bug: write a simple C
	 * testprogram that reproduces the bug so we can report it. */
	pthread_mutex_lock(&mq_send_mutex);
	int const res = mq_send(queue, (const char*)msg, sizeof(*msg), 0);
	pthread_mutex_unlock(&mq_send_mutex);
	if (res == EINTR) {
		goto again;
	}

	if (res != 0) {
		perror("x10 runtime: failure while sending remote exec message");
		abort();
	}
}

static void *start_message_handler(void *arg)
{
	message_t *message = (message_t*)arg;
	message->base.handler(message);
	gc_free(message);
	return NULL;
}

static void handle_remote_exec(const message_t *message);
static bool can_handle_synchronously(const message_t *message)
{
	if (message->base.handler == handle_remote_exec)
		return false;
	return true;
}

static bool receive_single_message(void)
{
	message_t *message = GC_XMALLOC(message_t);
again:;
	ssize_t sz = mq_receive(my_queue, (char*)message, sizeof(*message), NULL);
	if (sz < 0) {
		if (errno == EINTR) {
			goto again;
		}
		perror("x10 runtime: failure while receiving message");
		abort();
	}
	if (sz != sizeof(*message)) {
		fprintf(stderr,
		        "x10 runtime: %u received message with strange len '%u'\n",
		        place_id, (unsigned)sz);
		abort();
	}

	if (can_handle_synchronously(message)) {
		message->base.handler(message);
		gc_free(message);
	} else {
		pthread_t dummy;
		int res = GC_pthread_create(&dummy, &detached_pthread_attr,
		                         start_message_handler, message);
		if (res != 0) {
			perror("Couldn't create message handling thread");
			abort();
		}
	}
	return true;
}

static void *message_receive_loop(void *arg)
{
	(void)arg;
	while (receive_single_message()) {
	}
	return NULL;
}

/** initiate dma transfer to remote tile and send an dma_message_t.
 * Note: locks the send_mutex, so you have to make sure it is freed later */
static void send_msg_dma(unsigned const place, message_handler const handler,
                         const char *const data, size_t const data_size)
{
	/* fill data into our shared memory segment */
	pthread_mutex_lock(&send_mutex);
	char *dest = shm_addrs[place_id];
	memcpy(dest, data, data_size);

	if (data_size > SHM_SIZE) {
		fprintf(stderr, "x10 runtime: message size too big (maximum allowed is %u)\n", SHM_SIZE);
		abort();
	}
	message_t msg;
	memset(&msg, 0, sizeof(msg));
	dma_message_t *dma   = &msg.dma;
	dma->base.handler    = handler;
	dma->data            = dest;
	dma->data_size       = data_size;

	/* send a message to the other place to trigger the execution */
	send_msg(&msg, place);
}

static void handle_deserialization_complete(const message_t *message)
{
	(void)message;
	pthread_mutex_unlock(&send_mutex);
}

static void handle_completion_simple(const message_t *message)
{
	const completion_simple_message_t *const completion
		= &message->completion_simple;
	pthread_mutex_lock(completion->return_lock);
	*completion->return_flag = true;
	pthread_cond_signal(completion->return_cond);
	pthread_mutex_unlock(completion->return_lock);
}

static void handle_completion_finish(const message_t *message)
{
	const completion_finish_message_t *const completion
		= &message->completion_finish;
	finish_state_t *fs = completion->finish_state;
	/* fs is NULL for uncounted asyncs. */
	if (fs != NULL) {
		unregister_from_finish_state(fs);
	}
}

static void handle_completion(const message_t *message)
{
	const dma_message_t *const dma = &message->dma;
	const completion_header_t *const header
		= (const completion_header_t*)dma->data;
	const char *const data      = dma->data      + sizeof(*header);
	size_t      const data_size = dma->data_size - sizeof(*header);

	x10_object *return_value = x10_deserialize_from(data, data_size);
	*(header->return_value_pointer) = return_value;

	pthread_mutex_t *lock = header->return_lock;
	pthread_cond_t  *cond = header->return_cond;
	bool            *flag = header->return_flag;

	/* notify caller that we don't need the send buffer anymore */
	message_t msg;
	memset(&msg, 0, sizeof(msg));
	message_base_t *deserialization_complete = &msg.base;
	deserialization_complete->handler        = handle_deserialization_complete;
	send_msg(&msg, header->from_place);

	/* wake up execute_at */
	pthread_mutex_lock(lock);
	*flag = true;
	pthread_cond_signal(cond);
	pthread_mutex_unlock(lock);
}

static void handle_remote_exec(const message_t *message)
{
	const dma_message_t *const dma = &message->dma;

	const remote_exec_header_t const header
		= *((const remote_exec_header_t*) dma->data);
	const char *const data      = dma->data      + sizeof(header);
	size_t      const data_size = dma->data_size - sizeof(header);

	/* create a new toplevel finish state */
	finish_state_t state;
	finish_state_init(&state, NULL);
	assert(finish_state_get_current() == NULL);
	finish_state_set_current(&state);

	x10_object *closure = x10_deserialize_from(data, data_size);

	message_t msg;
	memset(&msg, 0, sizeof(msg));
	message_base_t *deserialization_complete = &msg.base;
	deserialization_complete->handler = handle_deserialization_complete;
	send_msg(&msg, header.from_place);

	if (header.msg_type == MSG_RUN_AT) {
		_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(closure);

		/* acknowledge return1 */
		message_t msg;
		memset(&msg, 0, sizeof(msg));
		completion_simple_message_t *completion = &msg.completion_simple;
		completion->base.handler = handle_completion_simple;
		completion->return_cond  = header.return_cond;
		completion->return_flag  = header.return_flag;
		completion->return_lock  = header.return_lock;
		send_msg(&msg, header.from_place);
	} else if (header.msg_type == MSG_RUN_AT_ASYNC) {
		message_t msg;
		memset(&msg, 0, sizeof(msg));
		completion_simple_message_t *completion = &msg.completion_simple;
		completion->base.handler = handle_completion_simple;
		completion->return_cond  = header.return_cond;
		completion->return_flag  = header.return_flag;
		completion->return_lock  = header.return_lock;
		send_msg(&msg, header.from_place);

		_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(closure);
	} else {
		assert(header.msg_type == MSG_EVAL_AT);
		x10_object *retval = _ZN3x104lang7Runtime14callAnyClosureEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

		struct obstack obst;
		obstack_init(&obst);
		completion_header_t completion_header;
		completion_header.from_place           = place_id;
		completion_header.return_cond          = header.return_cond;
		completion_header.return_flag          = header.return_flag;
		completion_header.return_lock          = header.return_lock;
		completion_header.return_value_pointer = header.return_value_pointer;
		obstack_grow(&obst, &completion_header, sizeof(completion_header));

		x10_serialize_to_obst(&obst, retval);

		size_t data_size = obstack_object_size(&obst);
		char  *data      = obstack_finish(&obst);

		send_msg_dma(header.from_place, handle_completion, data, data_size);
		obstack_free(&obst, NULL);
	}

	assert(finish_state_get_current() == &state);
	finish_state_wait(&state);
	finish_state_destroy(&state);
	finish_state_set_current(NULL);

	memset(&msg, 0, sizeof(msg));
	completion_finish_message_t *completion = &msg.completion_finish;
	completion->base.handler    = handle_completion_finish;
	completion->finish_state    = header.finish_state;
	send_msg(&msg, header.from_place);
}

static void handle_init_complete(const message_t *message)
{
	const init_complete_message_t *const init_complete = &message->init_complete;
	(void)init_complete;
}

static void create_queue_name(char *buf, size_t buf_size, unsigned place)
{
	snprintf(buf, buf_size, "/x10_%ld_%u", (long)master_pid, place);
}

static void init_shared_memory(void)
{
	shm_addrs = GC_XMALLOCN(void*, n_places);
	for (unsigned i = 0; i < n_places; ++i) {
		void *addr = mmap(NULL, SHM_SIZE, PROT_READ|PROT_WRITE,
		                  MAP_SHARED|MAP_ANONYMOUS, 0, 0);
		if (addr == MAP_FAILED) {
			perror("x10 runtime: failed to create shared memory");
			exit(1);
		}
		shm_addrs[i] = addr;
	}
}

static mqd_t setup_queue(unsigned place, int flags)
{
	struct mq_attr attr;
	memset(&attr, 0, sizeof(attr));
	attr.mq_flags   = 0;
	attr.mq_maxmsg  = 10;
	attr.mq_msgsize = sizeof(message_t);
	attr.mq_curmsgs = 0;

	char buf[64];
	create_queue_name(buf, sizeof(buf), place);
	mqd_t queue = mq_open(buf, flags, 0600, &attr);
	if (queue == (mqd_t)-1) {
		perror("x10 runtime: couldn't setup message queue");
		fprintf(stderr, "Place %u, queue '%s'\n", place_id, buf);
		exit(1);
	}

	return queue;
}

static void unlink_queues(void)
{
	char buf[64];
	for (unsigned p = 0; p < n_places; ++p) {
		create_queue_name(buf, sizeof(buf), p);
		mq_unlink(buf);
	}
}

static void init_message_queues(void)
{
	queues = GC_XMALLOCNZ(mqd_t, n_places);

	/* open message queues for each place */
	for (unsigned i = 0; i < n_places; ++i) {
		if (place_id == 0 && i == 0) {
			queues[0] = my_queue;
			continue;
		}
		int flags = O_CREAT;
		flags |= i == place_id ? O_RDONLY : O_WRONLY;
		queues[i] = setup_queue(i, flags);
	}

	my_queue = queues[place_id];
	pthread_mutex_init(&send_mutex, NULL);
	pthread_mutex_init(&mq_send_mutex, NULL);

	int res = GC_pthread_create(&message_receive_thread, &detached_pthread_attr,
	                            message_receive_loop, NULL);
	if (res != 0) {
		perror("Couldn't create message handling thread");
		abort();
	}
}

static void init_master(void)
{
	/* wait for all childs to send their start message */
	for (unsigned c = 1; c < n_places; ++c) {
		receive_single_message();
	}

	init_message_queues();
	unlink_queues();
}

static void init_child(void)
{
	/* use linux extension so all our childs get a SIGHUP delivered if the
	 * master dies unexpectedly */
	prctl(PR_SET_PDEATHSIG, SIGHUP);

	/* close the message queue we inherited from master */
	mq_close(my_queue);
	init_message_queues();

	/* notify place 0 that we are ready */
	message_t msg;
	memset(&msg, 0, sizeof(msg));
	init_complete_message_t *init_complete = &msg.init_complete;
	init_complete->base.handler    = handle_init_complete;
	init_complete->from_place      = place_id;
	send_msg(&msg, 0);

	/* fixup for possible race */
	if (getppid() == 1)
		kill(getpid(), SIGHUP);
}

void init_ipc(void)
{
	master_pid = getpid();

	/* maximum of 4 places by default */
	n_places = 4;
	char *nplaces = getenv("X10_NPLACES");
	if (nplaces != NULL) {
		int nplaces_int = atoi(nplaces);
		if (nplaces_int > 0)
			n_places = (unsigned)nplaces_int;
	}

	init_shared_memory();

	/* initialize receive queue for master it has to be there before the fork
	 * to avoid race conditions */
	my_queue = setup_queue(0, O_CREAT | O_RDONLY);

	signal(SIGCHLD, sigchld_handler);
	signal(SIGHUP, sighup_handler);

	/* let's fork until we have a process for each place */
	for (unsigned i = 1; i < n_places; ++i) {
		pid_t new_pid = fork();
		if (new_pid == 0) {
			/* child process */
			place_id = i;
			init_child();
			break;
		}
	}

	if (place_id == 0) {
		init_master();
	}

	pthread_attr_init(&detached_pthread_attr);
	pthread_attr_setdetachstate(&detached_pthread_attr,
	                            PTHREAD_CREATE_DETACHED);
}

/* Will be called for master and children. */
void shutdown_ipc(void)
{
	if (queues == NULL)
		return;

	pthread_cancel(message_receive_thread);
	signal(SIGCHLD, SIG_DFL);

	for (unsigned i = 0; i < n_places; ++i) {
		mqd_t queue = queues[i];
		if (queue != (mqd_t)-1)
			mq_close(queues[i]);
		queues[i] = (mqd_t)-1;
	}
	pthread_mutex_destroy(&send_mutex);
	pthread_mutex_destroy(&mq_send_mutex);
	pthread_attr_destroy(&detached_pthread_attr);
}

void x10_idle(void)
{
	while (idle_running != 0) {
		pause();
	}
}

x10_object *x10_execute_at(x10_int remote_place, x10_int msg_type,
                           x10_object *closure, x10_boolean uncounted)
{
	unsigned remote_id = (unsigned)remote_place;
	assert(remote_id != place_id);

	assert(msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT || msg_type == MSG_RUN_AT_ASYNC);

	pthread_mutex_t return_lock  = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  return_cond  = PTHREAD_COND_INITIALIZER;
	bool            return_flag  = false;
	x10_object     *return_value = NULL;

	finish_state_t *finish_state = uncounted ? NULL : finish_state_get_current();
	if (!uncounted) {
		register_at_finish_state(finish_state);
	}

	/* construct message payload */
	struct obstack obst;
	obstack_init(&obst);
	remote_exec_header_t header;
	header.from_place           = place_id;
	header.msg_type             = msg_type;
	header.return_cond          = &return_cond;
	header.return_flag          = &return_flag;
	header.return_lock          = &return_lock;
	header.return_value_pointer = &return_value;
	header.finish_state         = finish_state;
	obstack_grow(&obst, &header, sizeof(header));

	x10_serialize_to_obst(&obst, closure);

	size_t data_size = obstack_object_size(&obst);
	char  *data      = obstack_finish(&obst);

	pthread_mutex_lock(&return_lock);
	/* send a message to the other place to trigger the execution */
	send_msg_dma(remote_id, handle_remote_exec, data, data_size);
	obstack_free(&obst, NULL);

	while (!return_flag) {
		pthread_cond_wait(&return_cond, &return_lock);
	}
	pthread_mutex_unlock(&return_lock);

	pthread_mutex_destroy(&return_lock);
	pthread_cond_destroy(&return_cond);

	return return_value;
}
