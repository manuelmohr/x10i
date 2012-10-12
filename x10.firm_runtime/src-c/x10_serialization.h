#ifndef X10_SERIALIZATION_H_
#define X10_SERIALIZATION_H_

#include "x10.h"
#include "x10_object.h"
#include "obst.h"

typedef struct obstack obstack;
struct serialization_buffer_t {
	obstack      obst;
	size_t       bytes_written;
	x10_object **serialized_objects;
};
typedef struct serialization_buffer_t serialization_buffer_t;

struct deserialization_buffer_t {
	char        *data;
	size_t       cursor;
	size_t       length;
	x10_object **deserialized_objects;
};
typedef struct deserialization_buffer_t deserialization_buffer_t;

serialization_buffer_t *x10_serialization_init();
void x10_serialization_write_primitive(serialization_buffer_t *buf, void *data, size_t nbytes);
void x10_serialization_write_object(serialization_buffer_t *buf, x10_object *objPtr);
char *x10_serialization_finish(serialization_buffer_t *buf);

deserialization_buffer_t *x10_deserialization_init(char *data, size_t length);
void x10_deserialization_restore_primitive(deserialization_buffer_t *buf, void *addr, size_t nbytes);
void x10_deserialization_restore_object(deserialization_buffer_t *buf, x10_object **addr);
void x10_deserialization_finish(deserialization_buffer_t *buf);

#endif
