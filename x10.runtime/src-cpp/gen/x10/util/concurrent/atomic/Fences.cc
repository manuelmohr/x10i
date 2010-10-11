#include <x10/util/concurrent/atomic/Fences.h>


#include "x10/util/concurrent/atomic/Fences.inc"

void x10::util::concurrent::atomic::Fences::_instance_init() {
    _I_("Doing initialisation for class: x10::util::concurrent::atomic::Fences");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/concurrent/atomic/Fences.x10": x10.ast.X10MethodDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/util/concurrent/atomic/Fences.x10": x10.ast.X10MethodDecl_c

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/concurrent/atomic/Fences.x10": x10.ast.X10MethodDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/concurrent/atomic/Fences.x10": x10.ast.X10MethodDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/concurrent/atomic/Fences.x10": x10.ast.X10ConstructorDecl_c
void x10::util::concurrent::atomic::Fences::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::util::concurrent::atomic::Fences> x10::util::concurrent::atomic::Fences::_make(
  ) {
    x10aux::ref<x10::util::concurrent::atomic::Fences> this_ = new (memset(x10aux::alloc<x10::util::concurrent::atomic::Fences>(), 0, sizeof(x10::util::concurrent::atomic::Fences))) x10::util::concurrent::atomic::Fences();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::util::concurrent::atomic::Fences::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::concurrent::atomic::Fences::_deserializer<x10::lang::Object>);

void x10::util::concurrent::atomic::Fences::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::concurrent::atomic::Fences::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::concurrent::atomic::Fences::rtt;
void x10::util::concurrent::atomic::Fences::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.util.concurrent.atomic.Fences", 1, parents, 0, NULL, NULL);
}
