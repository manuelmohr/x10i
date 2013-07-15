
#include <stdio.h>
#include <assert.h>
#include "serialization.h"
#include "adt/array.h"

#define X10_SERIALIZATION_NULL_TYPE_UID 0
#define X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID ((uint32_t)-1)

struct deserialize_methods_entry_t {
	deserialize_method *deserializer;
	x10_vtable         *vtable;
};
typedef struct deserialize_methods_entry_t dm_entry_t;

extern dm_entry_t __deserialize_methods[];
extern serialize_method *__serialize_methods[];

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

void x10_serialization_write_long(serialization_buffer_t *buf,
                                  const x10_long *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_ulong(serialization_buffer_t *buf,
                                   const x10_ulong *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_int(serialization_buffer_t *buf,
                                 const x10_int *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_uint(serialization_buffer_t *buf,
                                  const x10_uint *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_short(serialization_buffer_t *buf,
                                   const x10_short *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_ushort(serialization_buffer_t *buf,
                                    const x10_ushort *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_byte(serialization_buffer_t *buf,
                                  const x10_byte *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_ubyte(serialization_buffer_t *buf,
                                   const x10_ubyte *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_boolean(serialization_buffer_t *buf,
                                     const x10_boolean *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_char(serialization_buffer_t *buf,
                                  const x10_char *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_float(serialization_buffer_t *buf,
                                   const x10_float *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_double(serialization_buffer_t *buf,
                                    const x10_double *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

void x10_serialization_write_pointer(serialization_buffer_t *buf,
                                     const x10_pointer *value_ptr)
{
	obstack_grow(buf->obst, value_ptr, sizeof(*value_ptr));
}

static inline void put_u32(serialization_buffer_t *buf, uint32_t val)
{
	obstack_make_room(buf->obst, 4);
	obstack_1grow_fast(buf->obst, (uint8_t)(val >>  0));
	obstack_1grow_fast(buf->obst, (uint8_t)(val >>  8));
	obstack_1grow_fast(buf->obst, (uint8_t)(val >> 16));
	obstack_1grow_fast(buf->obst, (uint8_t)(val >> 24));
}

void x10_serialization_write_object(serialization_buffer_t *const buf,
                                    const x10_object *const objPtr)
{
	if (objPtr == NULL) {
		put_u32(buf, X10_SERIALIZATION_NULL_TYPE_UID);
		return;
	}

	int idx = find_object(buf->serialized_objects, objPtr);
	if (idx >= 0) {
		put_u32(buf, X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID);
		put_u32(buf, idx);
		return;
	}

	ARR_APP1(const x10_object *, buf->serialized_objects, objPtr);

	uint32_t uid = objPtr->vptr->runtime_type_info->uid;
	put_u32(buf, uid);

	serialize_method *serializer = __serialize_methods[uid];
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

void x10_deserialization_restore_long(deserialization_buffer_t *buf,
                                      x10_long *addr)
{
	*addr = * ((x10_long*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_ulong(deserialization_buffer_t *buf,
                                       x10_ulong *addr)
{
	*addr = * ((x10_ulong*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_int(deserialization_buffer_t *buf,
                                     x10_int *addr)
{
	*addr = * ((x10_int*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_uint(deserialization_buffer_t *buf,
                                      x10_uint *addr)
{
	*addr = * ((x10_uint*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_short(deserialization_buffer_t *buf,
                                       x10_short *addr)
{
	*addr = * ((x10_short*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_ushort(deserialization_buffer_t *buf,
                                        x10_ushort *addr)
{
	*addr = * ((x10_ushort*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_byte(deserialization_buffer_t *buf,
                                      x10_byte *addr)
{
	*addr = * ((x10_byte*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_ubyte(deserialization_buffer_t *buf,
                                       x10_ubyte *addr)
{
	*addr = * ((x10_ubyte*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_char(deserialization_buffer_t *buf,
                                      x10_char *addr)
{
	*addr = * ((x10_char*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_boolean(deserialization_buffer_t *buf,
                                         x10_boolean *addr)
{
	*addr = * ((x10_boolean*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_float(deserialization_buffer_t *buf,
                                       x10_float *addr)
{
	*addr = * ((x10_float*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_double(deserialization_buffer_t *buf,
                                        x10_double *addr)
{
	*addr = * ((x10_double*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_pointer(deserialization_buffer_t *buf,
                                         x10_pointer *addr)
{
	*addr = * ((x10_pointer*)&buf->data[buf->cursor]);
	buf->cursor += sizeof(*addr);
}

void x10_deserialization_restore_object(deserialization_buffer_t *buf, x10_object **addr)
{
	uint32_t class_id = get_u32(buf);

	if (class_id == X10_SERIALIZATION_NULL_TYPE_UID) {
		*addr = NULL;
		return;
	}

	if (class_id == X10_SERIALIZATION_KNOWN_OBJECT_TYPE_UID) {
		uint32_t object_num = get_u32(buf);
		assert(ARR_LEN(buf->deserialized_objects) > object_num);

		x10_object *result = buf->deserialized_objects[object_num];
		*addr = result;
		return;
	}

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
