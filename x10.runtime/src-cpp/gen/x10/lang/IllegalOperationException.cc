#include <x10/lang/IllegalOperationException.h>


#include "x10/lang/IllegalOperationException.inc"

void x10::lang::IllegalOperationException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::IllegalOperationException");
    
}


//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalOperationException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalOperationException::_constructor() {
    this->x10::lang::RuntimeException::_constructor(x10::lang::String::Lit("illegal operation exception"));
    
}
x10aux::ref<x10::lang::IllegalOperationException> x10::lang::IllegalOperationException::_make(
  ) {
    x10aux::ref<x10::lang::IllegalOperationException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalOperationException>(), 0, sizeof(x10::lang::IllegalOperationException))) x10::lang::IllegalOperationException();
    this_->_constructor();
    return this_;
}



//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalOperationException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalOperationException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::lang::IllegalOperationException> x10::lang::IllegalOperationException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::IllegalOperationException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalOperationException>(), 0, sizeof(x10::lang::IllegalOperationException))) x10::lang::IllegalOperationException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::lang::IllegalOperationException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::IllegalOperationException::_deserializer<x10::lang::Object>);

void x10::lang::IllegalOperationException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::lang::IllegalOperationException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::IllegalOperationException::rtt;
void x10::lang::IllegalOperationException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.lang.IllegalOperationException", 1, parents, 0, NULL, NULL);
}
