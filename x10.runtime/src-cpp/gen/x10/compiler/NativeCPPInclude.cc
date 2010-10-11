#include <x10/compiler/NativeCPPInclude.h>


#include "x10/compiler/NativeCPPInclude.inc"


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeCPPInclude.x10": x10.ast.PropertyDecl_c
void x10::compiler::NativeCPPInclude::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::NativeCPPInclude");
    
}

x10aux::RuntimeType x10::compiler::NativeCPPInclude::rtt;
void x10::compiler::NativeCPPInclude::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.NativeCPPInclude", 2, parents, 0, NULL, NULL);
}
