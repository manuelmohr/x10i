#include <x10/compiler/ByRef.h>


#include "x10/compiler/ByRef.inc"

x10aux::RuntimeType x10::compiler::ByRef::rtt;
void x10::compiler::ByRef::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ClassAnnotation>()};
    rtt.initStageTwo("x10.compiler.ByRef", 2, parents, 0, NULL, NULL);
}
