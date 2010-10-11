#include <x10/compiler/NativeDef.h>


#include "x10/compiler/NativeDef.inc"


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeDef.x10": x10.ast.PropertyDecl_c
void x10::compiler::NativeDef::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::NativeDef");
    
}

x10aux::RuntimeType x10::compiler::NativeDef::rtt;
void x10::compiler::NativeDef::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>()};
    rtt.initStageTwo("x10.compiler.NativeDef", 2, parents, 0, NULL, NULL);
}
