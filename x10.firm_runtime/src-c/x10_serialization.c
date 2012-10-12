
#include <stdio.h>
#include <assert.h>
#include "x10_serialization.h"
#include "array.h"

//#define X10_SERIALIZATION_DEBUG

#define X10_SERIALIZATION_NULL_TYPE_UID 0
#define X10_SERIALIZATION_KNOWN_OBJECT_TYPE_ID ((uint32_t)-1)

typedef void (serialize_method)(serialization_buffer_t *buf, x10_object *objPtr);
typedef void (deserialize_method)(deserialization_buffer_t *buf, void *objPtr);

struct deserialize_methods_entry_t {
	deserialize_method *deserializer;
	x10_vtable         *vtable;
};
typedef struct deserialize_methods_entry_t dm_entry_t;

extern dm_entry_t __deserialize_methods[];

static inline int find_object(x10_object **arr, x10_object *key)
{
	int i;
	for (i = ARR_LEN(arr)-1; i >= 0; i--) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}

serialization_buffer_t *x10_serialization_init(void)
{
	serialization_buffer_t *buf = calloc(1, sizeof(serialization_buffer_t));
	obstack_init(&buf->obst);
	buf->bytes_written = 0;
	buf->serialized_objects = NEW_ARR_F(x10_object *, 0);
	return buf;
}

void x10_serialization_write_primitive(serialization_buffer_t *buf, void *data, size_t nbytes)
{
	assert (nbytes > 0);

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_SERIALIZATION: writing primitive at %x (%d bytes)\n", (unsigned)data, nbytes);
#endif

	obstack_grow(&buf->obst, data, nbytes);
	buf->bytes_written += nbytes;

}

void x10_serialization_write_object(serialization_buffer_t *buf, x10_object *objPtr)
{
	uint32_t uid;

	if (objPtr == NULL) {

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_SERIALIZATION: writing NULL\n");
#endif

		uid = X10_SERIALIZATION_NULL_TYPE_UID;
		obstack_grow(&buf->obst, &uid, sizeof(uint32_t));
		buf->bytes_written += sizeof(uint32_t);
		return;
	}

	int idx = find_object(buf->serialized_objects, objPtr);
	if (idx > -1) {

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_SERIALIZATION: found previously serialized object %x at %d\n", (unsigned) objPtr, idx);
#endif

		uid = X10_SERIALIZATION_KNOWN_OBJECT_TYPE_ID;
		obstack_grow(&buf->obst, &uid, sizeof(uint32_t));
		obstack_grow(&buf->obst, &idx, sizeof(uint32_t));
		buf->bytes_written += (2 * sizeof(uint32_t));
		return;
	}

	ARR_APP1(x10_object *, buf->serialized_objects, objPtr);

	uid = objPtr->vptr->runtime_type_info->uid;

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_SERIALIZATION: writing object of type [%d]%s at %x\n", uid, objPtr->vptr->runtime_type_info->name->data, (unsigned) objPtr);
#endif

	obstack_grow(&buf->obst, &uid, sizeof(uint32_t));
	buf->bytes_written += sizeof(uint32_t);

	serialize_method *serializer = objPtr->vptr->fptrs[0];
	serializer(buf, objPtr);
}

char *x10_serialization_finish(serialization_buffer_t *buf)
{
	char *obst_finished = obstack_finish(&buf->obst);
	char *result = malloc(buf->bytes_written);
	memcpy(result, obst_finished, buf->bytes_written);

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_SERIALIZATION: wrote %d bytes: ", buf->bytes_written);
	char *p = result;
	size_t i;
	for (i = 0; i < buf->bytes_written; i++)
		printf("%02X ", (*p++) & 0xFF);
	puts("\n");
#endif

	obstack_free(&buf->obst, NULL);
	DEL_ARR_F(buf->serialized_objects);

	free(buf);

	return result;
}

static inline uint32_t get_u32(deserialization_buffer_t *buf)
{
	uint8_t b1 = buf->data[buf->cursor++];
	uint8_t b2 = buf->data[buf->cursor++];
	uint8_t b3 = buf->data[buf->cursor++];
	uint8_t b4 = buf->data[buf->cursor++];
	return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}

deserialization_buffer_t *x10_deserialization_init(char *data, size_t length)
{
	deserialization_buffer_t *buf = calloc(1, sizeof(deserialization_buffer_t));
	buf->data = data;
	buf->cursor = 0;
	buf->length = length;
	buf->deserialized_objects = NEW_ARR_F(x10_object *, 0);
	return buf;
}

void x10_deserialization_restore_primitive(deserialization_buffer_t *buf, void *addr, size_t nbytes)
{
	/* TODO: think about endianess conversions */
#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_DESERIALIZATION: restoring %d bytes to %x)\n", nbytes, (unsigned) addr);
#endif

	assert (buf->cursor + nbytes <= buf->length);
	memcpy(addr, &buf->data[buf->cursor], nbytes);
	buf->cursor += nbytes;
}

void x10_deserialization_restore_object(deserialization_buffer_t *buf, x10_object **addr)
{
	uint32_t class_id = get_u32(buf);

	if (class_id == X10_SERIALIZATION_NULL_TYPE_UID) {

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_DESERIALIZATION: restoring NULL\n");
#endif

		*addr = NULL;
		return;
	}

	if (class_id == X10_SERIALIZATION_KNOWN_OBJECT_TYPE_ID) {
		uint32_t object_num = get_u32(buf);
		assert (ARR_LEN(buf->deserialized_objects) > object_num);
		*addr = buf->deserialized_objects[object_num];

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_DESERIALIZATION: restored previously deserialized object %x from slot %d\n", (unsigned) *addr, object_num);
#endif

		return;
	}

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_DESERIALIZATION: restoring object of type %d\n", class_id);
#endif

	dm_entry_t *entry = &__deserialize_methods[class_id];
	x10_object *newObj = calloc(1, entry->vtable->runtime_type_info->size);
	newObj->vptr = entry->vtable;
	*addr = newObj;
	ARR_APP1(x10_object *, buf->deserialized_objects, newObj);

	entry->deserializer(buf, newObj);

	assert (buf->cursor <= buf->length);
}

void x10_deserialization_finish(deserialization_buffer_t *buf)
{
	assert (buf->cursor == buf->length);
	DEL_ARR_F(buf->deserialized_objects);
	free(buf);
}

x10_object* _ZN3x104lang7Runtime11deepCopyAnyEPN3x104lang3AnyE(x10_object *obj)
{
	serialization_buffer_t *buf = x10_serialization_init();
	x10_serialization_write_object(buf, obj);
	char *serialized = x10_serialization_finish(buf);

	deserialization_buffer_t *debuf = x10_deserialization_init(serialized, buf->bytes_written);
	x10_object *result;
	x10_deserialization_restore_object(debuf, &result);
	x10_deserialization_finish(debuf);

	free(serialized);
	return result;
}
