#include <x10/compiler/Unroll.h>


#include "x10/compiler/Unroll.inc"


//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/Unroll.x10": x10.ast.PropertyDecl_c
void x10::compiler::Unroll::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::Unroll");
    
}

x10aux::RuntimeType x10::compiler::Unroll::rtt;
void x10::compiler::Unroll::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::StatementAnnotation>()};
    rtt.initStageTwo("x10.compiler.Unroll", 2, parents, 0, NULL, NULL);
}
