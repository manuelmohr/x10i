#include <x10/lang/RuntimeException.h>


#include "x10/lang/RuntimeException.inc"

void x10::lang::RuntimeException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::RuntimeException");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/RuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::RuntimeException::_constructor() {
    this->x10::lang::Exception::_constructor();
    
}
x10aux::ref<x10::lang::RuntimeException> x10::lang::RuntimeException::_make(
  ) {
    x10aux::ref<x10::lang::RuntimeException> this_ = new (memset(x10aux::alloc<x10::lang::RuntimeException>(), 0, sizeof(x10::lang::RuntimeException))) x10::lang::RuntimeException();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/RuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::RuntimeException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::Exception::_constructor(
      message);
    
}
x10aux::ref<x10::lang::RuntimeException> x10::lang::RuntimeException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::lang::RuntimeException> this_ = new (memset(x10aux::alloc<x10::lang::RuntimeException>(), 0, sizeof(x10::lang::RuntimeException))) x10::lang::RuntimeException();
    this_->_constructor(message);
    return this_;
}



//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/RuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::RuntimeException::_constructor(x10aux::ref<x10::lang::String> message,
                                               x10aux::ref<x10::lang::Throwable> cause)
{
    this->x10::lang::Exception::_constructor(
      message,
      cause);
    
}
x10aux::ref<x10::lang::RuntimeException> x10::lang::RuntimeException::_make(
  x10aux::ref<x10::lang::String> message,
  x10aux::ref<x10::lang::Throwable> cause)
{
    x10aux::ref<x10::lang::RuntimeException> this_ = new (memset(x10aux::alloc<x10::lang::RuntimeException>(), 0, sizeof(x10::lang::RuntimeException))) x10::lang::RuntimeException();
    this_->_constructor(message,
    cause);
    return this_;
}



//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/RuntimeException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::RuntimeException::_constructor(x10aux::ref<x10::lang::Throwable> cause)
{
    this->x10::lang::Exception::_constructor(
      cause);
    
}
x10aux::ref<x10::lang::RuntimeException> x10::lang::RuntimeException::_make(
  x10aux::ref<x10::lang::Throwable> cause)
{
    x10aux::ref<x10::lang::RuntimeException> this_ = new (memset(x10aux::alloc<x10::lang::RuntimeException>(), 0, sizeof(x10::lang::RuntimeException))) x10::lang::RuntimeException();
    this_->_constructor(cause);
    return this_;
}


const x10aux::serialization_id_t x10::lang::RuntimeException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::RuntimeException::_deserializer<x10::lang::Object>);

void x10::lang::RuntimeException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Exception::_serialize_body(buf);
    
}

void x10::lang::RuntimeException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Exception::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::RuntimeException::rtt;
void x10::lang::RuntimeException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Exception>()};
    rtt.initStageTwo("x10.lang.RuntimeException", 1, parents, 0, NULL, NULL);
}
