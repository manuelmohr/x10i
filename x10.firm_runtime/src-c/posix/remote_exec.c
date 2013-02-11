#include <sys/mman.h>
#include <pthread.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "remote_exec.h"
#include "init.h"
#include "serialization.h"
#include "async.h"

#define SHM_SIZE  (8*1024*1024)

static mqd_t             *queues;
static mqd_t              my_queue;
static void             **shm_addrs;
static pthread_mutex_t    send_mutex;
static pthread_mutex_t    idle_lock;
static pthread_cond_t     idle_cond;
static pthread_mutex_t    start_lock;
static pthread_cond_t     start_cond;
static volatile unsigned  start_count;

static volatile bool wait_for_dma_receive;

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
	message_base_t  base;
	pthread_cond_t *return_cond;
} completion_simple_message_t;

typedef struct completion_finish_message_t {
	message_base_t  base;
	finish_state_t *finish_state;
} completion_finish_message_t;

typedef struct start_message_t {
	message_base_t base;
	unsigned       from_place;
} start_message_t;

union message_t {
	message_base_t              base;
	completion_finish_message_t completion_finish;
	completion_simple_message_t completion_simple;
	dma_message_t               dma;
	message_handler             handler;
	start_message_t             start;
};

typedef struct remote_exec_header_t {
	unsigned        from_place;
	x10_int         msg_type;
	pthread_cond_t *return_cond;
	x10_object    **return_value_pointer;
	finish_state_t *finish_state;
} remote_exec_header_t;

typedef struct completion_header_t {
	unsigned        from_place;
	pthread_cond_t *return_cond;
	x10_object    **return_value_pointer;
} completion_header_t;

static void send_msg(const message_t *const msg, unsigned const place)
{
	mqd_t const queue = queues[place];
again:;
	int const res = mq_send(queue, (const char*)msg, sizeof(*msg), 0);
	if (res == EINTR)
		  goto again;

	if (res != 0) {
		  perror("x10 runtime: failure while sending remote exec message");
		  abort();
	}
}

static void message_received(union sigval val);
static void register_notify_handler(void)
{
	struct sigevent sigev;
	memset(&sigev, 0, sizeof(sigev));
	sigev.sigev_notify            = SIGEV_THREAD;
	sigev.sigev_notify_function   = message_received;
	sigev.sigev_notify_attributes = NULL;
	if (mq_notify(my_queue, &sigev) != 0) {
		perror("x10 runtime: couldn't register message notify event");
		exit(1);
	}
}

static void message_received(union sigval val)
{
	(void)val;

	register_notify_handler();

	message_t message;
again:;
	ssize_t sz = mq_receive(my_queue, (char*)&message, sizeof(message), NULL);
	if (sz < 0) {
		if (errno == EAGAIN)
			return;
		if (errno == EINTR)
			goto again;
		perror("x10 runtime: failure while receiving message");
		abort();
	}
	if (sz != sizeof(message)) {
		fprintf(stderr, "x10 runtime: %u received message with strange len '%u'\n",
		        place_id, (unsigned)sz);
		abort();
	}

	message.base.handler(&message);
	goto again;
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
	dma_message_t message;
	memset(&message, 0, sizeof(message));
	message.base.handler = handler;
	message.data         = dest;
	message.data_size    = data_size;

	/* send a message to the other place to trigger the execution */
	send_msg((const message_t*)&message, place);
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
	pthread_cond_signal(completion->return_cond);
}

static void handle_completion_finish(const message_t *message)
{
	const completion_finish_message_t *const completion
		= &message->completion_finish;
	unregister_from_finish_state(completion->finish_state);
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

	/* notify caller that we don't need the send buffer anymore */
	message_base_t deserialization_complete;
	memset(&deserialization_complete, 0, sizeof(deserialization_complete));
	deserialization_complete.handler = handle_deserialization_complete;
	send_msg((const message_t*)&deserialization_complete, header->from_place);

	/* wake up execute_at */
	pthread_cond_signal(header->return_cond);
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

	message_base_t deserialization_complete;
	memset(&deserialization_complete, 0, sizeof(deserialization_complete));
	deserialization_complete.handler = handle_deserialization_complete;
	send_msg((const message_t*)&deserialization_complete, header.from_place);

	if (header.msg_type == MSG_RUN_AT) {
		_ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(closure);

		/* acknowledge return1 */
		completion_simple_message_t completion;
		memset(&completion, 0, sizeof(completion));
		completion.base.handler = handle_completion_simple;
		completion.return_cond  = header.return_cond;
		send_msg((const message_t*)&completion, header.from_place);
	} else {
		assert(header.msg_type == MSG_EVAL_AT);
		x10_object *retval = _ZN3x104lang7Runtime8evaluateEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);

		struct obstack obst;
		obstack_init(&obst);
		completion_header_t completion_header;
		completion_header.from_place           = place_id;
		completion_header.return_cond          = header.return_cond;
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

	completion_finish_message_t completion;
	memset(&completion, 0, sizeof(completion));
	completion.base.handler = handle_completion_finish;
	completion.finish_state = header.finish_state;
	send_msg((const message_t*)&completion, header.from_place);
}

static void handle_shutdown(const message_t *message)
{
	(void)message;
	pthread_cond_signal(&idle_cond);
}

static void handle_start(const message_t *message)
{
	(void)message;
	pthread_mutex_lock(&start_lock);
	if (--start_count == 0) {
		pthread_cond_signal(&start_cond);
	}
	pthread_mutex_unlock(&start_lock);
}

static void create_queue_name(char *buf, size_t buf_size, unsigned place)
{
	snprintf(buf, buf_size, "/x10_%ld_%u", master_pid, place);
}

void create_ipc_shared_memory(void)
{
	shm_addrs = XMALLOCN(void*, n_places);
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

void init_ipc(void)
{
	/* create message queues */
	queues = XMALLOCNZ(mqd_t, n_places);

	struct mq_attr attr;
	memset(&attr, 0, sizeof(attr));
	attr.mq_flags   = 0;
	attr.mq_maxmsg  = 10;
	attr.mq_msgsize = sizeof(message_t);
	attr.mq_curmsgs = 0;

	/* open message queues for each place */
	for (unsigned i = 0; i < n_places; ++i) {
		int flags = O_CREAT;
		flags |= i == place_id ? O_RDONLY|O_NONBLOCK : O_WRONLY;
		char buf[64];
		create_queue_name(buf, sizeof(buf), i);
		mqd_t queue = mq_open(buf, flags, 0600, &attr);
		if (queue == (mqd_t)-1) {
			perror("x10 runtime: couldn't setup message queue");
			fprintf(stderr, "Place %u, queueu '%s'\n", place_id, buf);
			exit(1);
		}

		queues[i] = queue;
	}

	/* setup notification */
	my_queue = queues[place_id];

	/* initialize send mutex */
	pthread_mutex_init(&send_mutex, NULL);

	if (place_id != 0) {
		pthread_mutex_init(&idle_lock, NULL);
		pthread_cond_init(&idle_cond, NULL);
		register_notify_handler();

		/* notify place 0 that we are ready */
		start_message_t start;
		start.base.handler = handle_start;
		start.from_place   = place_id;
		send_msg((const message_t*)&start, 0);
	} else {
		pthread_mutex_init(&start_lock, NULL);
		pthread_cond_init(&start_cond, NULL);
		/* wait for other places to become ready */
		start_count = n_places-1;

		pthread_mutex_lock(&start_lock);
		register_notify_handler();
		pthread_cond_wait(&start_cond, &start_lock);

		pthread_mutex_unlock(&start_lock);
	}
}

void shutdown_ipc(void)
{
	if (queues == NULL)
		return;

	/* send shutdown message to other places */
	if (place_id == 0) {
		for (unsigned i = 1; i < n_places; ++i) {
			message_base_t exitmessage;
			exitmessage.handler = handle_shutdown;
			send_msg((const message_t*)&exitmessage, i);
		}
	}

	for (unsigned i = 0; i < n_places; ++i) {
		mqd_t queue = queues[i];
		if (queue != (mqd_t)-1)
			mq_close(queues[i]);
		queues[i] = (mqd_t)-1;
	}
	/* unlink our own queue */
	char buf[64];
	create_queue_name(buf, sizeof(buf), place_id);
	mq_unlink(buf);

	pthread_mutex_destroy(&send_mutex);
}

void x10_idle(void)
{
	pthread_mutex_lock(&idle_lock);
	pthread_cond_wait(&idle_cond, &idle_lock);
	pthread_mutex_unlock(&idle_lock);
	pthread_mutex_destroy(&idle_lock);
	pthread_cond_destroy(&idle_cond);
}

x10_object *x10_execute_at(x10_int remote_place, x10_int msg_type,
                           x10_object *closure)
{
	unsigned remote_id = (unsigned)remote_place;
	assert(remote_id != place_id);

	assert(msg_type == MSG_RUN_AT || msg_type == MSG_EVAL_AT);

	pthread_mutex_t condlock     = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t  return_cond  = PTHREAD_COND_INITIALIZER;
	x10_object     *return_value = NULL;

	finish_state_t *finish_state = finish_state_get_current();
	register_at_finish_state(finish_state);

	/* construct message payload */
	struct obstack obst;
	obstack_init(&obst);
	remote_exec_header_t header;
	header.from_place           = place_id;
	header.msg_type             = msg_type;
	header.return_cond          = &return_cond;
	header.return_value_pointer = &return_value;
	header.finish_state         = finish_state;
	obstack_grow(&obst, &header, sizeof(header));

	x10_serialize_to_obst(&obst, closure);

	size_t data_size = obstack_object_size(&obst);
	char  *data      = obstack_finish(&obst);

	/* send a message to the other place to trigger the execution */
	send_msg_dma(remote_id, handle_remote_exec, data, data_size);
	obstack_free(&obst, NULL);

	pthread_mutex_lock(&condlock);
	pthread_cond_wait(&return_cond, &condlock);

	pthread_mutex_unlock(&condlock);
	pthread_mutex_destroy(&condlock);
	pthread_cond_destroy(&return_cond);

	return return_value;
}
