#include "invasic_host_octopos.h"
#include "ethernet.h"
#include "serialization.h"
#include "eth_dummy.h"
#include <octopos.h>
#include <limits.h>

static eth_channel_t read_chan  = NULL;
static eth_channel_t write_chan = NULL;

static void signal_ilet(void *data)
{
	simple_signal *sig = (simple_signal*)data;
	simple_signal_signal(sig);
}

bool octo_receive(void *buffer, size_t size)
{
	simple_signal sig;
	simple_signal_init(&sig, 1);
	simple_ilet ilet;
	simple_ilet_init(&ilet, &signal_ilet, &sig);
	if (eth_receive(read_chan, buffer, size, &ilet) != 0)
		return false;
	simple_signal_wait(&sig);
	return true;
}

bool octo_send(void *buffer, size_t size)
{
	simple_signal sig;
	simple_signal_init(&sig, 1);
	simple_ilet ilet;
	simple_ilet_init(&ilet, &signal_ilet, &sig);
	if (eth_send(write_chan, buffer, size, &ilet) != 0)
		return false;
	simple_signal_wait(&sig);
	return true;
}

static void open_channels(void)
{
	read_chan = eth_open(0, ETH_MODE_READ);
	if (read_chan == NULL)
		panic("could not open read channel");
	write_chan = eth_open(1, ETH_MODE_WRITE);
	if (write_chan == NULL)
		panic("could not open write channel");
}

static void close_channels(void)
{
	if (eth_close(read_chan) != 0)
		panic("could not close read channel");
	if (eth_close(write_chan) != 0)
		panic("could not close write channel");
}

x10_object *exec_on_invasic_host(x10_int msg_type, x10_object *obj)
{
	x10_object *result      = NULL;
	const bool  need_answer = msg_type == MSG_EVAL_AT;
	uint32_t    info        = 0;
	if (need_answer)
		info |= INVASIC_HOST_EXPECT_ANSWER;

	open_channels();
	x10i_message_t message = {obj, info};
	if (!ethernet_send(&octo_send, message))
		panic("ethernet_send failed");

	if (need_answer) {
		x10i_message_t res = ethernet_receive(&octo_receive);
		result = res.obj;
		assert(res.info == 0);
	}
	close_channels();

	return result;
}
