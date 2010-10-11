#include <x10/compiler/CUDAUtilities.h>


#include "x10/compiler/CUDAUtilities.inc"

void x10::compiler::CUDAUtilities::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::CUDAUtilities");
    
}


//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/CUDAUtilities.x10": x10.ast.X10MethodDecl_c
x10_uint x10::compiler::CUDAUtilities::autoBlocks() {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/CUDAUtilities.x10": x10.ast.X10Return_c
    return ((x10_uint) (((x10_int)8)));
    
}

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/CUDAUtilities.x10": x10.ast.X10MethodDecl_c
x10_uint x10::compiler::CUDAUtilities::autoThreads() {
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/CUDAUtilities.x10": x10.ast.X10Return_c
    return ((x10_uint) (((x10_int)1)));
    
}

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/CUDAUtilities.x10": x10.ast.X10ConstructorDecl_c
void x10::compiler::CUDAUtilities::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::compiler::CUDAUtilities> x10::compiler::CUDAUtilities::_make(
  ) {
    x10aux::ref<x10::compiler::CUDAUtilities> this_ = new (memset(x10aux::alloc<x10::compiler::CUDAUtilities>(), 0, sizeof(x10::compiler::CUDAUtilities))) x10::compiler::CUDAUtilities();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::compiler::CUDAUtilities::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::compiler::CUDAUtilities::_deserializer<x10::lang::Object>);

void x10::compiler::CUDAUtilities::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::compiler::CUDAUtilities::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::compiler::CUDAUtilities::rtt;
void x10::compiler::CUDAUtilities::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.compiler.CUDAUtilities", 1, parents, 0, NULL, NULL);
}
