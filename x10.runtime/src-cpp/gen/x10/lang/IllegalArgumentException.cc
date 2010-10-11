#include <x10/lang/IllegalArgumentException.h>


#include "x10/lang/IllegalArgumentException.inc"

void x10::lang::IllegalArgumentException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::IllegalArgumentException");
    
}


//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalArgumentException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalArgumentException::_constructor() {
    this->x10::lang::RuntimeException::_constructor();
    
}
x10aux::ref<x10::lang::IllegalArgumentException> x10::lang::IllegalArgumentException::_make(
  ) {
    x10aux::ref<x10::lang::IllegalArgumentException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalArgumentException>(), 0, sizeof(x10::lang::IllegalArgumentException))) x10::lang::IllegalArgumentException();
    this_->_constructor();
    return this_;
}



//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalArgumentException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalArgumentException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::lang::IllegalArgumentException> x10::lang::IllegalArgumentException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::IllegalArgumentException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalArgumentException>(), 0, sizeof(x10::lang::IllegalArgumentException))) x10::lang::IllegalArgumentException();
    this_->_constructor(message);
    return this_;
}



//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalArgumentException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalArgumentException::_constructor(
  x10aux::ref<x10::lang::String> message,
  x10aux::ref<x10::lang::Throwable> cause) {
    this->x10::lang::RuntimeException::_constructor(
      message,
      cause);
    
}
x10aux::ref<x10::lang::IllegalArgumentException> x10::lang::IllegalArgumentException::_make(
  x10aux::ref<x10::lang::String> message,
  x10aux::ref<x10::lang::Throwable> cause)
{
    x10aux::ref<x10::lang::IllegalArgumentException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalArgumentException>(), 0, sizeof(x10::lang::IllegalArgumentException))) x10::lang::IllegalArgumentException();
    this_->_constructor(message,
    cause);
    return this_;
}



//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/IllegalArgumentException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::IllegalArgumentException::_constructor(
  x10aux::ref<x10::lang::Throwable> cause)
{
    this->x10::lang::RuntimeException::_constructor(
      cause);
    
}
x10aux::ref<x10::lang::IllegalArgumentException> x10::lang::IllegalArgumentException::_make(
  x10aux::ref<x10::lang::Throwable> cause)
{
    x10aux::ref<x10::lang::IllegalArgumentException> this_ = new (memset(x10aux::alloc<x10::lang::IllegalArgumentException>(), 0, sizeof(x10::lang::IllegalArgumentException))) x10::lang::IllegalArgumentException();
    this_->_constructor(cause);
    return this_;
}


const x10aux::serialization_id_t x10::lang::IllegalArgumentException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::IllegalArgumentException::_deserializer<x10::lang::Object>);

void x10::lang::IllegalArgumentException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::lang::IllegalArgumentException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::IllegalArgumentException::rtt;
void x10::lang::IllegalArgumentException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.lang.IllegalArgumentException", 1, parents, 0, NULL, NULL);
}
