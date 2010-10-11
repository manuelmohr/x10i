#include <x10/util/Timer.h>


#include "x10/util/Timer.inc"

void x10::util::Timer::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Timer");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Timer.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Timer.x10": x10.ast.X10MethodDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Timer.x10": x10.ast.X10ConstructorDecl_c
void x10::util::Timer::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::util::Timer> x10::util::Timer::_make() {
    x10aux::ref<x10::util::Timer> this_ = new (memset(x10aux::alloc<x10::util::Timer>(), 0, sizeof(x10::util::Timer))) x10::util::Timer();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::util::Timer::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::Timer::_deserializer<x10::lang::Object>);

void x10::util::Timer::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::Timer::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::Timer::rtt;
void x10::util::Timer::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.util.Timer", 1, parents, 0, NULL, NULL);
}
