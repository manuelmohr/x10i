#include "invasic_host_posix.h"
#include "ethernet.h"
#include "init.h"
#include "serialization.h"
#ifdef __x86_64__
	typedef void EthChannel;
	enum {
		ETH_MODE_WRITE, ETH_MODE_READ,
	};
	static EthChannel *ethChannelCreate(const char *name, int fd, int mode)
	{
		(void)name;
		(void)fd;
		(void)mode;
		panic("ethChannelCreate not available on x86_64");
	}
	static int ethChannelReceive(EthChannel *chan, void *buf, size_t size)
	{
		(void)chan;
		(void)buf;
		(void)size;
		panic("ethChannelReceive not available on x86_64");
	}
	static int32_t ethChannelPrepareSend(EthChannel *chan)
	{
		(void)chan;
		panic("ethChannelPrepareSend not available on x86_64");
	}
	static void ethChannelDestroy(EthChannel *chan)
	{
		(void)chan;
		panic("ethChannelDestroy not available on x86_64");
	}
	static int ethChannelSend(EthChannel *chan, void *buf, size_t size)
	{
		(void)chan;
		(void)buf;
		(void)size;
		panic("ethChannelSend not available on x86_64");
	}
#else
	#include <ethchannel.h>
#endif
#include <stdlib.h>

static EthChannel *write_chan = NULL;
static EthChannel *read_chan  = NULL;

static bool open_channels(const char *octo_sys)
{
	write_chan = ethChannelCreate(octo_sys, 0, ETH_MODE_WRITE);
	if (write_chan == NULL) {
		perror("could not create write channel");
		return false;
	}
	read_chan = ethChannelCreate(octo_sys, 1, ETH_MODE_READ);
	if (read_chan == NULL) {
		ethChannelDestroy(write_chan);
		perror("could not create read channel");
		return false;
	}
	return true;
}

static void close_channels(void)
{
	ethChannelDestroy(write_chan);
	ethChannelDestroy(read_chan);
}

static bool receive(void *buffer, size_t size)
{
	return ethChannelReceive(read_chan, buffer, size) != -1;
}

static bool send(void *buffer, size_t size)
{
	assert(size <= ETHERNET_MESSAGE_SIZE);
	int32_t buf_size = ethChannelPrepareSend(write_chan);
	if (buf_size == -1)
		return false;
	assert(buf_size >= ETHERNET_MESSAGE_SIZE);
	return ethChannelSend(write_chan, buffer, size) != -1;
}

void run_as_invasic_host(const char *octo_sys)
{
	if (!open_channels(octo_sys)) {
		exit_code = 1;
		return;
	}

	for (;;) {
		x10i_message_t  result  = ethernet_receive(&receive);
		x10_object     *closure = result.obj;
		if (closure == NULL) {
			exit_code = 1;
			break;
		}

		if (result.info & INVASIC_HOST_EXPECT_ANSWER) {
			x10_object *return_value = _ZN3x104lang7Runtime14callAnyClosureEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(closure);
			x10i_message_t answer = {return_value, 0};

			if (!ethernet_send(&send, answer)) {
				exit_code = 1;
				break;
			}
		} else {
			_ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(closure);
		}
	}

	close_channels();
}
