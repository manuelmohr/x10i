#include <x10/lang/ArithmeticException.h>


#include "x10/lang/ArithmeticException.inc"

void x10::lang::ArithmeticException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::ArithmeticException");
    
}


//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ArithmeticException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::ArithmeticException::_constructor() {
    this->x10::lang::RuntimeException::_constructor();
    
}
x10aux::ref<x10::lang::ArithmeticException> x10::lang::ArithmeticException::_make(
  ) {
    x10aux::ref<x10::lang::ArithmeticException> this_ = new (memset(x10aux::alloc<x10::lang::ArithmeticException>(), 0, sizeof(x10::lang::ArithmeticException))) x10::lang::ArithmeticException();
    this_->_constructor();
    return this_;
}



//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ArithmeticException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::ArithmeticException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::lang::ArithmeticException> x10::lang::ArithmeticException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::ArithmeticException> this_ = new (memset(x10aux::alloc<x10::lang::ArithmeticException>(), 0, sizeof(x10::lang::ArithmeticException))) x10::lang::ArithmeticException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::lang::ArithmeticException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::ArithmeticException::_deserializer<x10::lang::Object>);

void x10::lang::ArithmeticException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::lang::ArithmeticException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::ArithmeticException::rtt;
void x10::lang::ArithmeticException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.lang.ArithmeticException", 1, parents, 0, NULL, NULL);
}
