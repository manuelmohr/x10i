#include <x10/lang/ClassCastException.h>


#include "x10/lang/ClassCastException.inc"

void x10::lang::ClassCastException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::ClassCastException");
    
}


//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ClassCastException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::ClassCastException::_constructor() {
    this->x10::lang::RuntimeException::_constructor();
    
}
x10aux::ref<x10::lang::ClassCastException> x10::lang::ClassCastException::_make(
  ) {
    x10aux::ref<x10::lang::ClassCastException> this_ = new (memset(x10aux::alloc<x10::lang::ClassCastException>(), 0, sizeof(x10::lang::ClassCastException))) x10::lang::ClassCastException();
    this_->_constructor();
    return this_;
}



//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ClassCastException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::ClassCastException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::lang::ClassCastException> x10::lang::ClassCastException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::ClassCastException> this_ = new (memset(x10aux::alloc<x10::lang::ClassCastException>(), 0, sizeof(x10::lang::ClassCastException))) x10::lang::ClassCastException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::lang::ClassCastException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::ClassCastException::_deserializer<x10::lang::Object>);

void x10::lang::ClassCastException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::lang::ClassCastException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::ClassCastException::rtt;
void x10::lang::ClassCastException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.lang.ClassCastException", 1, parents, 0, NULL, NULL);
}
