#include <x10/lang/InterruptedException.h>


#include "x10/lang/InterruptedException.inc"

void x10::lang::InterruptedException::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::InterruptedException");
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/InterruptedException.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::InterruptedException::_constructor() {
    this->x10::lang::Exception::_constructor();
    
}
x10aux::ref<x10::lang::InterruptedException> x10::lang::InterruptedException::_make(
  ) {
    x10aux::ref<x10::lang::InterruptedException> this_ = new (memset(x10aux::alloc<x10::lang::InterruptedException>(), 0, sizeof(x10::lang::InterruptedException))) x10::lang::InterruptedException();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::InterruptedException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::InterruptedException::_deserializer<x10::lang::Object>);

void x10::lang::InterruptedException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Exception::_serialize_body(buf);
    
}

void x10::lang::InterruptedException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Exception::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::InterruptedException::rtt;
void x10::lang::InterruptedException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Exception>()};
    rtt.initStageTwo("x10.lang.InterruptedException", 1, parents, 0, NULL, NULL);
}
