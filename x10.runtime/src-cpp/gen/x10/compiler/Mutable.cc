#include <x10/compiler/Mutable.h>


#include "x10/compiler/Mutable.inc"

x10aux::RuntimeType x10::compiler::Mutable::rtt;
void x10::compiler::Mutable::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.Mutable", 2, parents, 0, NULL, NULL);
}
