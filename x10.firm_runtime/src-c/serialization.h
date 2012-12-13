#ifndef X10_SERIALIZATION_H_
#define X10_SERIALIZATION_H_

#include "x10.h"
#include "x10_object.h"
#include "obst.h"

/*

Serialization support
=====================

Runtime (here)
--------------
The runtime defines the type "serialization_buffer_t", consisting of an obstack
"obst" that stores "bytes_written" bytes of serialized data and table of
x10_objects "serialized_object" where references to already serialized objects
are remembered (this is needed to break cycles).

A new serialization buffer is acquired by calling "x10_serialization_init".

"x10_serialization_write_primitive(serialization_buffer_t *buf, const void
*data, size_t nbytes)" appends "nbytes" read from "data" to "buf"'s obstack.
Currently, no endianess conversions happen.

"x10_serialization_write_object(serialization_buffer_t *buf, const x10_object
*objPtr)" is used to write class (not struct) instances to the buffer:

If "objPtr" is NULL, the value X10_SERIALIZATION_NULL_TYPE_UID = (uint32_t)0 is
appended to the buffer.
If the object referenced by "objPtr" has already been serialized to "buf", we
lookup its index "idx" in "buf->serialized_objects". Then, we write
X10_SERIALIZATION_KNOWN_OBJECT_TYPE_ID = (uint32_t)-1, followed by "idx" to the
buffer.
In all other cases, the unique type id of the object's class is read from the
runtime type information and appended to the buffer. Then the object's
serialize method is invoked by performing a dynamic dispatch.

After the serializiation is complete, a call to "x10_serialization_finish"
frees the buffer and returns the created byte sequence.

A similar type "deserialization_buffer_t" exists for the deserialization of
objects, consisting of a pointer "data" to a sequence of "length" bytes,
a "cursor" pointing to the byte to be read next, and a table of x10_objects
"deserialized_objects", which is used in the reference-cycle breaking mechanism.

A new deserialization buffer is acquired by calling
"x10_deserialization_init(const char *data, size_t length)".

A call to "x10_deserialization_restore_primitive(deserialization_buffer_t *buf,
void *addr, size_t nbytes)" copies "nbytes" of "buf"'s data to the location
references by "addr" and advances "buf->cursor" accordingly.

"x10_deserialization_restore_object(deserialization_buffer_t *buf, x10_object
**addr)" allocates and initializes a class instance:

The type uid is read first. If the id is X10_SERIALIZATION_NULL_TYPE_UID, NULL
is written to the location pointed to by "addr".
If the id equals X10_SERIALIZATION_KNOWN_OBJECT_TYPE_ID, the object has already
been deserialized from "buf". We read the index from the byte sequence and
lookup the reference from "buf->deserialized_objects". The reference is then
written to "*addr".
In all other cases, the type id is used as an index to the table
"__deserialize_methods" to obtain the class' vtable address (in order to
allocate a new instance) and the appropriate deserialize method (which
initializes the instance from the serialized data). The address of the new
instance is stored in "*addr".

Afterwards, a call to "x10_deserialization_finish" frees the buffer.

Frontend (x10firm.types.SerializationSupport)
---------------------------------------------

The frontend generates two methods
"T::__serialize(serialization_buffer_t *buf, x10_object *objPtr)" and
"T::__deserialize(deserialization_buffer_t *buf, x10_object *objPtr)"
for each Firm classtype T that represents a X10 class or struct. The
corresponding method entities are created by
"SerializationSupport.setupSerialization(X10ClassType astType, firm.ClassType
firmType)" (both parameters represent the same class, but we need the Polyglot
variant for easy name mangling and subtype checks). For X10 classes, the
serialize method has to be bound dynamically. The serialize method for structs
is always called directly, therefore the method is bound statically. The
deserialize method is either called directly, or via a lookup in the table
"__deserialize_methods", thus it is not part of the vtable. The type uid is set
arbitrarily by this (setup) method.

In order to support the user defined serialization via
"x10.io.CustomSerialization", the interfaces itself and the implementing
methods in classes have to be stored by calls to the "setCustomXXX" methods.

After the type is finished and all types are layouted,
"SerializationSupport.generateSerializationMethods" is called, which calls
"generateSerializationMethod(ClassType klass)" and
"generateDeserializationMethod(ClassType klass)".

In both methods, we distinguish 3 variants:
* native classes (e.g. "x10.lang.String"): The appropriate C functions are
known by name and a call to them is generated.
* classes implementing "x10.io.CustomSerialization": we lookup the
user-definied serialize method respectively the deserialize constructor and
generate calls to them.
* all other classes/structs: we iterate over all fields (skipping transient
ones) and handle those that are...
  ... structs by generating a call to the struct's serialize/deserialize method.
  ... object references by generating calls to
  "x10_serialization_write_object"/"x10_deserialization_restore_object".
  ... primitives by generating calls to
  "x10_serialization_write_primitive"/"x10_deserialization_restore_primitive".

As a last step, the table "__deserialize_methods" is generated. It is indexed
by the type uid and contains for each class the function pointer to the type's
deserialize method and the pointer to the type's vtable.

Example
-------
Assume we have

struct Vec2(x:Int, y:Int);                /----------\         /----------\
class ListNode {             myObject --> | i   = 42 | <-\ /-> | i   = 17 |
  var i : Int;                : ListNode  | v.x =  1 |   | |   | v.x = 0  |
  val v : Vec2;                           | v.y =  0 |   | |   | v.y = 1  |
  var prev : ListNode;                    | prev = 0 |   \-+---| prev     |
  var next : ListNode;                    | next     |-----/   | next = 0 |
}                                         \----------/         \----------/

The frontend chooses to assign the type id 3 to ListNode and generates:

ListNode::__serialize(serialization_buffer_t *buf, ListNode *objPtr) {
  x10::lang::Object::__serialize(buf, &objPtr->$super);
  x10_serialization_write_primitive(buf, &objPtr->i, sizeof(Int));
  Vec2::__serialize(buf, &objPtr->v);
  x10_serialization_write_object(buf, objPtr->prev);
  x10_serialization_write_object(buf, objPtr->next);
}
ListNode::__deserialize(deserialization_buffer_t *buf, ListNode *objPtr) {
  x10::lang::Object::__deserialize(buf, &objPtr->$super);
  x10_deserialization_restore_primitive(buf, &objPtr->i, sizeof(Int));
  Vec2::__deserialize(buf, &objPtr->v);
  x10_deserialization_restore_object(buf, &objPtr->prev);
  x10_deserialization_restore_object(buf, &objPtr->next);
}

Vec2::__serialize(serialization_buffer_t *buf, Vec2 *objPtr) {
  x10_serialization_write_primitive(buf, &objPtr->x, sizeof(Int));
  x10_serialization_write_primitive(buf, &objPtr->y, sizeof(Int));
}
Vec2::__deserialize(deserialization_buffer_t *buf, Vec2 *objPtr) {
  x10_deserialization_restore_primitive(buf, &objPtr->x, sizeof(Int));
  x10_deserialization_restore_primitive(buf, &objPtr->y, sizeof(Int));
}

Serializing "myObject" then yields:

  /---------------------------------- myObject begins: type id for ListNode
  |  /------------------------------- myObject->i
  |  |  /---------------------------- myObject->v.x
  |  |  |  /------------------------- myObject->v.y
  |  |  |  |  /---------------------- myObject->prev is NULL
  |  |  |  |  |  /------------------- myObject->next begins: id for ListNode
  |  |  |  |  |  |  /---------------- myObject->next->i
  |  |  |  |  |  |  |  /------------- myObject->next->v.x
  |  |  |  |  |  |  |  |  /---------- myObject->next->v.y
  |  |  |  |  |  |  |  |  |  /------- myObject->next->prev already serialized
  |  |  |  |  |  |  |  |  |  |  /---- index to buf->serialized_objects
  |  |  |  |  |  |  |  |  |  |  |  /- myObject->next->next is NULL
  v  v  v  v  v  v  v  v  v  v  v  v
[03 42 01 00 00 03 17 00 01 -1 00 00] (these are decimal 32 bit values)

Limitations
-----------

- the "toplevel" value to be serialized has to be a class instance, because we
need to perform a dynamic dispatch to find the serializer method, and a runtime
typeinfo is required (which only classes have) to lookup the deserializer
method.
As a general workaround, trigger X10's autoboxing mechanism by using an
argument of type "Any" in your native method. See the implementation of
Runtime.deepCopy[T](o:T):T for an example.

- the serialize method is assumed to be in the first slot of all classes'
vtables.

*/

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
