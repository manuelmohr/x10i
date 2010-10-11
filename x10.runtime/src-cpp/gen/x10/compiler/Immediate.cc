#include <x10/compiler/Immediate.h>


#include "x10/compiler/Immediate.inc"

x10aux::RuntimeType x10::compiler::Immediate::rtt;
void x10::compiler::Immediate::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[4] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ExpressionAnnotation>(), x10aux::getRTT<x10::lang::annotations::StatementAnnotation>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>()};
    rtt.initStageTwo("x10.compiler.Immediate", 4, parents, 0, NULL, NULL);
}
