#include <x10/io/IORuntimeException.h>


#include "x10/io/IORuntimeException.inc"

void x10::io::IORuntimeException::_instance_init() {
    _I_("Doing initialisation for class: x10::io::IORuntimeException");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/IORuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::IORuntimeException::_constructor() {
    this->x10::lang::RuntimeException::_constructor();
    
}
x10aux::ref<x10::io::IORuntimeException> x10::io::IORuntimeException::_make(
  ) {
    x10aux::ref<x10::io::IORuntimeException> this_ = new (memset(x10aux::alloc<x10::io::IORuntimeException>(), 0, sizeof(x10::io::IORuntimeException))) x10::io::IORuntimeException();
    this_->_constructor();
    return this_;
}



//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/IORuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::IORuntimeException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::io::IORuntimeException> x10::io::IORuntimeException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::io::IORuntimeException> this_ = new (memset(x10aux::alloc<x10::io::IORuntimeException>(), 0, sizeof(x10::io::IORuntimeException))) x10::io::IORuntimeException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::io::IORuntimeException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::IORuntimeException::_deserializer<x10::lang::Object>);

void x10::io::IORuntimeException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::io::IORuntimeException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::IORuntimeException::rtt;
void x10::io::IORuntimeException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.io.IORuntimeException", 1, parents, 0, NULL, NULL);
}
