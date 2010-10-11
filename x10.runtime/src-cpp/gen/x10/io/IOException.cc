#include <x10/io/IOException.h>


#include "x10/io/IOException.inc"

void x10::io::IOException::_instance_init() {
    _I_("Doing initialisation for class: x10::io::IOException");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/IOException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::IOException::_constructor() {
    this->x10::lang::Exception::_constructor();
    
}
x10aux::ref<x10::io::IOException> x10::io::IOException::_make() {
    x10aux::ref<x10::io::IOException> this_ = new (memset(x10aux::alloc<x10::io::IOException>(), 0, sizeof(x10::io::IOException))) x10::io::IOException();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/IOException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::IOException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::Exception::_constructor(
      message);
    
}
x10aux::ref<x10::io::IOException> x10::io::IOException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::io::IOException> this_ = new (memset(x10aux::alloc<x10::io::IOException>(), 0, sizeof(x10::io::IOException))) x10::io::IOException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::io::IOException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::IOException::_deserializer<x10::lang::Object>);

void x10::io::IOException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Exception::_serialize_body(buf);
    
}

void x10::io::IOException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Exception::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::IOException::rtt;
void x10::io::IOException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Exception>()};
    rtt.initStageTwo("x10.io.IOException", 1, parents, 0, NULL, NULL);
}
