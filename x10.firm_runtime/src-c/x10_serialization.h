#ifndef X10_SERIALIZATION_H_
#define X10_SERIALIZATION_H_

#include "x10.h"
#include "x10_object.h"
#include "obst.h"

typedef struct obstack obstack;
struct serialization_buffer_t {
	obstack            obst;
	size_t             bytes_written;
	const x10_object **serialized_objects;
};
typedef struct serialization_buffer_t serialization_buffer_t;

struct deserialization_buffer_t {
	const char        *data;
	size_t             cursor;
	size_t             length;
	x10_object **deserialized_objects;
};
typedef struct deserialization_buffer_t deserialization_buffer_t;

typedef void (serialize_method)(serialization_buffer_t *buf, const x10_object *objPtr);
typedef void (deserialize_method)(deserialization_buffer_t *buf, x10_object *objPtr);

serialization_buffer_t *x10_serialization_init();
void x10_serialization_write_primitive(serialization_buffer_t *buf, const void *data, size_t nbytes);
void x10_serialization_write_object(serialization_buffer_t *buf, const x10_object *objPtr);
char *x10_serialization_finish(serialization_buffer_t *buf);

deserialization_buffer_t *x10_deserialization_init(const char *data, size_t length);
void x10_deserialization_restore_primitive(deserialization_buffer_t *buf, void *addr, size_t nbytes);
void x10_deserialization_restore_object(deserialization_buffer_t *buf, x10_object **addr);
void x10_deserialization_finish(deserialization_buffer_t *buf);

extern serialize_method    _ZN3x104lang6Object11__serializeEPvPv;
extern deserialize_method  _ZN3x104lang6Object13__deserializeEPvPv;

#endif
