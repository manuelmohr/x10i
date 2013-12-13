#include "ethernet.h"
#include "serialization.h"
#include "obstack.h"
#include "util.h"
#include "xmalloc.h"
#include "memory.h"
#include <stdint.h>

#define ETHERNET_HEADER_MAGIC 0xbadc0ded

#if 0
#include <stdio.h>
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

struct ethernet_header_t {
	uint32_t magic;
	uint32_t length;
	uint32_t total_length;
	uint32_t info;
	uint32_t checksum; /* Checksum for the payload data */
} __attribute__((packed));
typedef struct ethernet_header_t ethernet_header_t;

struct ethernet_message_t {
	ethernet_header_t header;
	char              data[];
} __attribute__((packed));
typedef struct ethernet_message_t ethernet_message_t;

uint32_t compute_checksum(const char *data, size_t size)
{
	uint32_t checksum = 0;
	for (size_t i = 0; i < size; ++i)
		checksum += (uint32_t)data[i];
	return checksum;
}

#if defined(BIG_ENDIAN_SERIALIZATION) && !defined(__sparc__)
#include "byteswap.h"
static void byteswap_header(ethernet_header_t *header)
{
	header->magic        = byteswap_32(header->magic);
	header->length       = byteswap_32(header->length);
	header->total_length = byteswap_32(header->total_length);
	header->info         = byteswap_32(header->info);
	header->checksum     = byteswap_32(header->checksum);
}
#else
static void byteswap_header(ethernet_header_t *header)
{
	(void)header;
}
#endif

x10i_message_t ethernet_receive(receive_func_t recv)
{
	char     *buffer          = mem_allocate_tlm(ETHERNET_MESSAGE_SIZE);
	char     *received_data   = NULL;
	uint32_t  received_length = 0;
	uint32_t  total_length    = 0;
	uint32_t  info            = 0;

	do {
		if (!recv(buffer, ETHERNET_MESSAGE_SIZE))
			panic("could not receive");

		ethernet_message_t *msg = (ethernet_message_t*)buffer;
		byteswap_header(&msg->header);
		const uint32_t magic  = msg->header.magic;
		const uint32_t length = msg->header.length;
		DEBUG_PRINT("Received message with header: length=%u total_length=%u info=%u checksum=%x\n", msg->header.length, msg->header.total_length, msg->header.info, msg->header.checksum);

		if (magic != ETHERNET_HEADER_MAGIC)
			panic("invalid header");
		if (total_length == 0) {
			total_length = msg->header.total_length;
		} else if (total_length != msg->header.total_length) {
			panic("invalid length information in header");
		}
		assert(length <= total_length);
		const uint32_t checksum = compute_checksum(msg->data, length);
		if (checksum != msg->header.checksum)
			panic("invalid checksum, corrupted data?");

		info |= msg->header.info;

		if (length == total_length) {
			/* Data fits in one message, should be the common case. */
			if (received_data == NULL) {
				received_data   = (char*)msg->data;
				received_length = total_length;
			}
		} else {
			if (received_data == NULL) {
				received_data = gc_xmalloc(total_length);
			}
			memcpy(received_data + received_length, msg->data, length);
			received_length += length;
		}
	} while (received_length < total_length);

	DEBUG_PRINT("Received %u bytes and info = %u\n", received_length, info);
	DEBUG_PRINT("Total checksum = %x\n", compute_checksum(received_data, received_length));

	x10_object *obj = x10_deserialize_from(received_data, received_length);
	if (received_data != buffer + sizeof(ethernet_header_t)) {
		gc_free(received_data);
	}
	mem_free_tlm(buffer);
	return (x10i_message_t){obj, info};
}

bool ethernet_send(send_func_t send, const x10i_message_t message)
{
	bool okay = true;

	struct obstack obst;
	obstack_init(&obst);
	serialization_buffer_t ser_buffer;
	x10_init_serialization_buffer(&ser_buffer, &obst);
	x10_serialization_write_object(&ser_buffer, message.obj);
	x10_destroy_serialization_buffer(&ser_buffer);

	const size_t  total_bytes = obstack_object_size(&obst);
	const char   *total_data  = obstack_finish(&obst);
	size_t        sent_bytes  = 0;
	char         *buffer      = mem_allocate_tlm(ETHERNET_MESSAGE_SIZE);

	DEBUG_PRINT("Preparing to send %u bytes with info = %u\n", total_bytes, message.info);
	DEBUG_PRINT("Total checksum = %x\n", compute_checksum(total_data, total_bytes));

	do {
		const size_t remaining_bytes = total_bytes - sent_bytes;
		const size_t max_payload     = ETHERNET_MESSAGE_SIZE - sizeof(ethernet_header_t);
		const size_t to_send_bytes   = MIN(remaining_bytes, max_payload);

		ethernet_message_t *msg = (ethernet_message_t*)buffer;

		/* Setup message. */
		msg->header.magic        = ETHERNET_HEADER_MAGIC;
		msg->header.length       = to_send_bytes;
		msg->header.total_length = total_bytes;
		msg->header.info         = message.info;
		memcpy(msg->data, total_data + sent_bytes, to_send_bytes);
		msg->header.checksum     = compute_checksum(msg->data, to_send_bytes);

		DEBUG_PRINT("Sending message with header: length=%u total_length=%u info=%u checksum=%x\n", msg->header.length, msg->header.total_length, msg->header.info, msg->header.checksum);

		byteswap_header(&msg->header);
		if (!send(buffer, to_send_bytes + sizeof(ethernet_header_t))) {
			okay = false;
			goto out;
		}

		sent_bytes += to_send_bytes;
	} while (sent_bytes < total_bytes);

out:
	mem_free_tlm(buffer);
	obstack_free(&obst, NULL);
	return okay;
}
