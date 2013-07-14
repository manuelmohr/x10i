#ifndef ETHERNET_H
#define ETHERNET_H

#define ETHERNET_MESSAGE_SIZE (1<<14)

typedef bool (*receive_func_t)(void *buffer, size_t buffer_size);
typedef bool (*send_func_t)(void *buffer, size_t buffer_size);

typedef struct x10i_message_t {
	x10_object *obj;   /** An X10 object, will be serialized. */
	uint32_t    info;  /** Additional, arbitrary information. */
} x10i_message_t;

x10i_message_t ethernet_receive(receive_func_t recv);
bool ethernet_send(send_func_t send, const x10i_message_t message);

#endif
