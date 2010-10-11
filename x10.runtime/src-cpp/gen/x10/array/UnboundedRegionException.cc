#include <x10/array/UnboundedRegionException.h>


#include "x10/array/UnboundedRegionException.inc"

void x10::array::UnboundedRegionException::_instance_init() {
    _I_("Doing initialisation for class: x10::array::UnboundedRegionException");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/array/UnboundedRegionException.x10": x10.ast.X10ConstructorDecl_c
void x10::array::UnboundedRegionException::_constructor(x10aux::ref<x10::lang::String> msg)
{
    this->x10::lang::RuntimeException::_constructor(
      msg);
    
}
x10aux::ref<x10::array::UnboundedRegionException> x10::array::UnboundedRegionException::_make(
  x10aux::ref<x10::lang::String> msg)
{
    x10aux::ref<x10::array::UnboundedRegionException> this_ = new (memset(x10aux::alloc<x10::array::UnboundedRegionException>(), 0, sizeof(x10::array::UnboundedRegionException))) x10::array::UnboundedRegionException();
    this_->_constructor(msg);
    return this_;
}


const x10aux::serialization_id_t x10::array::UnboundedRegionException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::UnboundedRegionException::_deserializer<x10::lang::Object>);

void x10::array::UnboundedRegionException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::RuntimeException::_serialize_body(buf);
    
}

void x10::array::UnboundedRegionException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::RuntimeException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::array::UnboundedRegionException::rtt;
void x10::array::UnboundedRegionException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::RuntimeException>()};
    rtt.initStageTwo("x10.array.UnboundedRegionException", 1, parents, 0, NULL, NULL);
}
