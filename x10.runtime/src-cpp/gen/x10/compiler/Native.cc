#include <x10/compiler/Native.h>


#include "x10/compiler/Native.inc"


//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/Native.x10": x10.ast.PropertyDecl_c

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/Native.x10": x10.ast.PropertyDecl_c
void x10::compiler::Native::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::Native");
    
}

x10aux::RuntimeType x10::compiler::Native::rtt;
void x10::compiler::Native::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>(), x10aux::getRTT<x10::lang::annotations::FieldAnnotation>()};
    rtt.initStageTwo("x10.compiler.Native", 3, parents, 0, NULL, NULL);
}
