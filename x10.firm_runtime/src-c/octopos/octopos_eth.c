#include <octo_eth.h>
#include <octo_ilet.h>
#include <octo_signal.h>

#include "async.h"
#include "util.h"

/* TODO: replace panics with proper exceptions as soon as we support them */

static void send_signal(void *data)
{
	simple_signal *signal = (simple_signal*)data;
	simple_signal_signal(signal);
}

x10_opaque_handle _ZN7octopos15EthWriteChannel4openEt(x10_ushort channel)
{
	eth_channel_t result = eth_open(channel, ETH_MODE_WRITE);
	if (result == NULL)
		panic("eth_open(ETH_MODE_WRITE) failed");
	return result;
}

x10_opaque_handle _ZN7octopos14EthReadChannel4openEt(x10_ushort channel)
{
	eth_channel_t result = eth_open(channel, ETH_MODE_READ);
	if (result == NULL)
		panic("eth_open(ETH_MODE_READ) failed");
	return result;
}

void _ZN7octopos15EthWriteChannel10writeAsyncEPvi(x10_opaque_handle handle,
                                                  x10_pointer buffer,
                                                  x10_int size)
{
	finish_state_t *current = finish_state_get_current();
	register_at_finish_state(current);

	simple_ilet ilet;
	simple_ilet_init(&ilet, send_signal, &current->signal);
	int res = eth_send((eth_channel_t)handle, buffer, (buf_size_t)size, &ilet);
	if (res != 0)
		panic("eth_send(...) failed");
}

void _ZN7octopos14EthReadChannel9readAsyncEPvi(x10_opaque_handle handle,
                                               x10_pointer buffer,
                                               x10_int size)
{
	finish_state_t *current = finish_state_get_current();
	register_at_finish_state(current);

	simple_ilet ilet;
	simple_ilet_init(&ilet, send_signal, &current->signal);
	int res = eth_receive((eth_channel_t)handle, buffer, (buf_size_t)size,
	                      &ilet);
	if (res != 0)
		panic("eth_receive(...) failed");
}