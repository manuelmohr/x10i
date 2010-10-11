#include <x10/lang/ValRail__NativeRep.h>


#include "x10/lang/ValRail__NativeRep.inc"

void x10::lang::ValRail__NativeRep::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::ValRail__NativeRep");
    
}


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::ValRail__NativeRep::isCPP() {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::ValRail__NativeRep::isJava() {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::ValRail__NativeRep::useNativeFor(x10::lang::Place x) {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10Return_c
    return true && (!x10aux::struct_equals(x, x10::lang::Place_methods::_make(x10aux::here)));
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10MethodDecl_c

//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::ValRail__NativeRep::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::lang::ValRail__NativeRep> x10::lang::ValRail__NativeRep::_make(
  ) {
    x10aux::ref<x10::lang::ValRail__NativeRep> this_ = new (memset(x10aux::alloc<x10::lang::ValRail__NativeRep>(), 0, sizeof(x10::lang::ValRail__NativeRep))) x10::lang::ValRail__NativeRep();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::ValRail__NativeRep::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::ValRail__NativeRep::_deserializer<x10::lang::Object>);

void x10::lang::ValRail__NativeRep::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::ValRail__NativeRep::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::ValRail__NativeRep::rtt;
void x10::lang::ValRail__NativeRep::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.ValRail__NativeRep", 1, parents, 0, NULL, NULL);
}
