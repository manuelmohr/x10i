#include <x10/compiler/NativeClass.h>


#include "x10/compiler/NativeClass.inc"


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeClass.x10": x10.ast.PropertyDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeClass.x10": x10.ast.PropertyDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/NativeClass.x10": x10.ast.PropertyDecl_c
void x10::compiler::NativeClass::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::NativeClass");
    
}

x10aux::RuntimeType x10::compiler::NativeClass::rtt;
void x10::compiler::NativeClass::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.NativeClass", 2, parents, 0, NULL, NULL);
}
