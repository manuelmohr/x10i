#include <x10/io/EOFException.h>


#include "x10/io/EOFException.inc"

void x10::io::EOFException::_instance_init() {
    _I_("Doing initialisation for class: x10::io::EOFException");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/EOFException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::EOFException::_constructor() {
    this->x10::io::IOException::_constructor();
    
}
x10aux::ref<x10::io::EOFException> x10::io::EOFException::_make() {
    x10aux::ref<x10::io::EOFException> this_ = new (memset(x10aux::alloc<x10::io::EOFException>(), 0, sizeof(x10::io::EOFException))) x10::io::EOFException();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/EOFException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::EOFException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::io::IOException::_constructor(
      message);
    
}
x10aux::ref<x10::io::EOFException> x10::io::EOFException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::io::EOFException> this_ = new (memset(x10aux::alloc<x10::io::EOFException>(), 0, sizeof(x10::io::EOFException))) x10::io::EOFException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::io::EOFException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::EOFException::_deserializer<x10::lang::Object>);

void x10::io::EOFException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::IOException::_serialize_body(buf);
    
}

void x10::io::EOFException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::IOException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::EOFException::rtt;
void x10::io::EOFException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::IOException>()};
    rtt.initStageTwo("x10.io.EOFException", 1, parents, 0, NULL, NULL);
}
