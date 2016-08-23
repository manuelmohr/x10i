#ifndef OCTOPOS_ETH_DUMMY_H
#define OCTOPOS_ETH_DUMMY_H

#include "cfAttribs.h"
#if cf_hw_sys_iotile_support != 0
	#include <octo_eth.h>
#else
	/* This is a non-IO-tile variant => insert our dummy */
	typedef void* eth_channel_t;
	enum {
		ETH_MODE_WRITE, ETH_MODE_READ,
	};
	static eth_channel_t *eth_open(int fd, int mode)
	{
		(void)fd;
		(void)mode;
		panic("eth_open not available");
	}
	static int eth_receive(eth_channel_t *chan, void *buf, size_t size, simple_ilet *ilet)
	{
		(void)chan;
		(void)buf;
		(void)size;
		(void)ilet;
		panic("eth_receive not available");
	}
	static int eth_close(eth_channel_t *chan)
	{
		(void)chan;
		panic("eth_close not available");
	}
	static int eth_send(eth_channel_t *chan, void *buf, size_t size, simple_ilet *ilet)
	{
		(void)chan;
		(void)buf;
		(void)size;
		(void)ilet;
		panic("eth_send not available");
	}
#endif

#endif
