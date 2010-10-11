#include <x10/util/IndexedMemoryChunk__NativeRep.h>


#include "x10/util/IndexedMemoryChunk__NativeRep.inc"

void x10::util::IndexedMemoryChunk__NativeRep::_instance_init() {
    _I_("Doing initialisation for class: x10::util::IndexedMemoryChunk__NativeRep");
    
}


//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10ConstructorDecl_c
void x10::util::IndexedMemoryChunk__NativeRep::_constructor() {
    this->x10::lang::Object::_constructor();
    
}

void x10::util::IndexedMemoryChunk__NativeRep::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::util::IndexedMemoryChunk__NativeRep::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::util::IndexedMemoryChunk__NativeRep::rtt;
void x10::util::IndexedMemoryChunk__NativeRep::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.util.IndexedMemoryChunk__NativeRep", 1, parents, 0, NULL, NULL);
}
