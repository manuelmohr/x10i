#include <x10/compiler/NativeCPPCompilationUnit.h>


#include "x10/compiler/NativeCPPCompilationUnit.inc"


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeCPPCompilationUnit.x10": x10.ast.PropertyDecl_c
void x10::compiler::NativeCPPCompilationUnit::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::NativeCPPCompilationUnit");
    
}

x10aux::RuntimeType x10::compiler::NativeCPPCompilationUnit::rtt;
void x10::compiler::NativeCPPCompilationUnit::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.NativeCPPCompilationUnit", 2, parents, 0, NULL, NULL);
}
