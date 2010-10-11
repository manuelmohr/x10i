#include <x10/compiler/NativeRep.h>


#include "x10/compiler/NativeRep.inc"


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeRep.x10": x10.ast.PropertyDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeRep.x10": x10.ast.PropertyDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeRep.x10": x10.ast.PropertyDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeRep.x10": x10.ast.PropertyDecl_c
void x10::compiler::NativeRep::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::NativeRep");
    
}

x10aux::RuntimeType x10::compiler::NativeRep::rtt;
void x10::compiler::NativeRep::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.NativeRep", 2, parents, 0, NULL, NULL);
}
