#include <x10/compiler/Uninitialized.h>


#include "x10/compiler/Uninitialized.inc"

x10aux::RuntimeType x10::compiler::Uninitialized::rtt;
void x10::compiler::Uninitialized::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::FieldAnnotation>()};
    rtt.initStageTwo("x10.compiler.Uninitialized", 2, parents, 0, NULL, NULL);
}
