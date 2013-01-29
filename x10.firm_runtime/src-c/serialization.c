
#include <stdio.h>
#include <assert.h>
#include "serialization.h"
#include "array.h"

//#define X10_SERIALIZATION_DEBUG

#define X10_SERIALIZATION_NULL_TYPE_UID 0
#define X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID ((uint32_t)-1)

struct deserialize_methods_entry_t {
	deserialize_method *deserializer;
	x10_vtable         *vtable;
};
typedef struct deserialize_methods_entry_t dm_entry_t;

extern dm_entry_t __deserialize_methods[];

static inline int find_object(const x10_object **arr, const x10_object *key)
{
	int i;
	for (i = ARR_LEN(arr)-1; i >= 0; i--) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}

void x10_init_serialization_buffer(serialization_buffer_t *buffer,
                                   struct obstack *obst)
{
	memset(buffer, 0, sizeof(*buffer));
	buffer->obst               = obst;
	buffer->serialized_objects = NEW_ARR_F(const x10_object *, 0);
}

void x10_destroy_serialization_buffer(serialization_buffer_t *buffer)
{
	DEL_ARR_F(buffer->serialized_objects);
}

void x10_serialization_write_primitive(serialization_buffer_t *buf, const void *data, size_t nbytes)
{
	assert(nbytes > 0);

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_SERIALIZATION: writing primitive at %x (%d bytes)\n", (unsigned)data, nbytes);
#endif

	obstack_grow(buf->obst, data, nbytes);
}

void x10_serialization_write_object(serialization_buffer_t *buf, const x10_object *objPtr)
{
	if (objPtr == NULL) {

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_SERIALIZATION: writing NULL\n");
#endif

		uint32_t uid = X10_SERIALIZATION_NULL_TYPE_UID;
		obstack_grow(buf->obst, &uid, sizeof(uint32_t));
		return;
	}

	int idx = find_object(buf->serialized_objects, objPtr);
	if (idx >= 0) {

#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_SERIALIZATION: found previously serialized object %x at %d\n", (unsigned) objPtr, idx);
#endif

		uint32_t uid = X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID;
		obstack_grow(buf->obst, &uid, sizeof(uint32_t));
		obstack_grow(buf->obst, &idx, sizeof(uint32_t));
		return;
	}

	ARR_APP1(const x10_object *, buf->serialized_objects, objPtr);

	uint32_t uid = objPtr->vptr->runtime_type_info->uid;

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_SERIALIZATION: writing object of type [%d]%s at %x\n", uid, objPtr->vptr->runtime_type_info->name->data, (unsigned) objPtr);
#endif

	obstack_grow(buf->obst, &uid, sizeof(uint32_t));

	/* frontend assures that T::__serialize is in the first vtable slot */
	serialize_method *serializer = objPtr->vptr->fptrs[0];
	serializer(buf, objPtr);
}

void x10_serialize_to_obst(struct obstack *const obst,
                           const x10_object *const object)
{
	serialization_buffer_t buffer;
	x10_init_serialization_buffer(&buffer, obst);
	x10_serialization_write_object(&buffer, object);
	x10_destroy_serialization_buffer(&buffer);
}


static inline uint32_t get_u32(deserialization_buffer_t *buf)
{
	uint8_t b1 = buf->data[buf->cursor++];
	uint8_t b2 = buf->data[buf->cursor++];
	uint8_t b3 = buf->data[buf->cursor++];
	uint8_t b4 = buf->data[buf->cursor++];
	return (b4 << 24) | (b3 << 16) | (b2 << 8) | b1;
}

void x10_init_deserialization_buffer(deserialization_buffer_t *buffer,
                                     const char *const data, size_t const size)
{
	memset(buffer, 0, sizeof(*buffer));
	buffer->data   = data;
	buffer->cursor = 0;
	buffer->length = size;
	buffer->deserialized_objects = NEW_ARR_F(x10_object *, 0);
}

void x10_destroy_deserialization_buffer(deserialization_buffer_t *buffer)
{
	assert(buffer->cursor == buffer->length);
	DEL_ARR_F(buffer->deserialized_objects);
}

void x10_deserialization_restore_primitive(deserialization_buffer_t *buf, void *addr, size_t nbytes)
{
	/* TODO: think about endianess conversions */
#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_DESERIALIZATION: restoring %d bytes to %x\n", nbytes, (unsigned) addr);
#endif

	assert(buf->cursor + nbytes <= buf->length);
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

	if (class_id == X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID) {
		uint32_t object_num = get_u32(buf);
		assert(ARR_LEN(buf->deserialized_objects) > object_num);

		x10_object *result = buf->deserialized_objects[object_num];
#ifdef X10_SERIALIZATION_DEBUG
		printf("X10_DESERIALIZATION: restored previously deserialized object %p from slot %d\n", result, object_num);
#endif
		*addr = result;
		return;
	}

#ifdef X10_SERIALIZATION_DEBUG
	printf("X10_DESERIALIZATION: restoring object of type %d\n", class_id);
#endif

	dm_entry_t *entry = &__deserialize_methods[class_id];
	x10_object *newObj = calloc(1, entry->vtable->runtime_type_info->size);
	newObj->vptr = entry->vtable;
	ARR_APP1(x10_object *, buf->deserialized_objects, newObj);

	entry->deserializer(buf, newObj);

	assert(buf->cursor <= buf->length);
	*addr = newObj;
}

x10_object *x10_deserialize_from(const char *data, size_t data_size)
{
	deserialization_buffer_t debuf;
	x10_init_deserialization_buffer(&debuf, data, data_size);
	x10_object *result;
	x10_deserialization_restore_object(&debuf, &result);
	x10_destroy_deserialization_buffer(&debuf);
	return result;
}

x10_object* _ZN3x104lang7Runtime11deepCopyAnyEPN3x104lang3AnyE(const x10_object *obj)
{
	struct obstack obst;
	obstack_init(&obst);

	x10_serialize_to_obst(&obst, obj);

	size_t data_size = obstack_object_size(&obst);
	char  *data      = obstack_finish(&obst);

	x10_object *result = x10_deserialize_from(data, data_size);

	obstack_free(&obst, NULL);
	return result;
}
