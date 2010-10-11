#include <x10/compiler/Transient.h>


#include "x10/compiler/Transient.inc"

x10aux::RuntimeType x10::compiler::Transient::rtt;
void x10::compiler::Transient::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::StatementAnnotation>()};
    rtt.initStageTwo("x10.compiler.Transient", 2, parents, 0, NULL, NULL);
}
