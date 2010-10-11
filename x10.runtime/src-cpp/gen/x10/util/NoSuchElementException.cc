#include <x10/util/NoSuchElementException.h>


#include "x10/util/NoSuchElementException.inc"

void x10::util::NoSuchElementException::_instance_init() {
    _I_("Doing initialisation for class: x10::util::NoSuchElementException");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/NoSuchElementException.x10": x10.ast.X10ConstructorDecl_c
void x10::util::NoSuchElementException::_constructor() {
    this->x10::lang::RuntimeException::_constructor();
    
}
x10aux::ref<x10::util::NoSuchElementException> x10::util::NoSuchElementException::_make(
  ) {
    x10aux::ref<x10::util::NoSuchElementException> this_ = new (memset(x10aux::alloc<x10::util::NoSuchElementException>(), 0, sizeof(x10::util::NoSuchElementException))) x10::util::NoSuchElementException();
    this_->_constructor();
    return this_;
}



//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/NoSuchElementException.x10": x10.ast.X10ConstructorDecl_c
void x10::util::NoSuchElementException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::lang::RuntimeException::_constructor(
      message);
    
}
x10aux::ref<x10::util::NoSuchElementException> x10::util::NoSuchElementException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::util::NoSuchElementException> this_ = new (memset(x10aux::alloc<x10::util::NoSuchElementException>(), 0, sizeof(x10::util::NoSuchElementException))) x10::util::NoSuchElementException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::util::NoSuchElementException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::NoSuchElementException::_deserializer<x10::lang::Object>);

void x10::util::NoSuchElementException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::util::NoSuchElementException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::NoSuchElementException::rtt;
void x10::util::NoSuchElementException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.util.NoSuchElementException", 1, parents, 0, NULL, NULL);
}
