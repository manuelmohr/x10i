#include <x10/lang/NumberFormatException.h>


#include "x10/lang/NumberFormatException.inc"

void x10::lang::NumberFormatException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::NumberFormatException");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/NumberFormatException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::NumberFormatException::_constructor() {
    this->x10::lang::IllegalArgumentException::_constructor();
    
}
x10aux::ref<x10::lang::NumberFormatException> x10::lang::NumberFormatException::_make(
  ) {
    x10aux::ref<x10::lang::NumberFormatException> this_ = new (memset(x10aux::alloc<x10::lang::NumberFormatException>(), 0, sizeof(x10::lang::NumberFormatException))) x10::lang::NumberFormatException();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/NumberFormatException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::NumberFormatException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::IllegalArgumentException::_constructor(
      message);
    
}
x10aux::ref<x10::lang::NumberFormatException> x10::lang::NumberFormatException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::NumberFormatException> this_ = new (memset(x10aux::alloc<x10::lang::NumberFormatException>(), 0, sizeof(x10::lang::NumberFormatException))) x10::lang::NumberFormatException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::lang::NumberFormatException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::NumberFormatException::_deserializer<x10::lang::Object>);

void x10::lang::NumberFormatException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::IllegalArgumentException::_serialize_body(buf);
    
}

void x10::lang::NumberFormatException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::IllegalArgumentException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::NumberFormatException::rtt;
void x10::lang::NumberFormatException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::IllegalArgumentException>()};
    rtt.initStageTwo("x10.lang.NumberFormatException", 1, parents, 0, NULL, NULL);
}
