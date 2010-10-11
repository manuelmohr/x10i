#include <x10/compiler/Inline.h>


#include "x10/compiler/Inline.inc"

x10aux::RuntimeType x10::compiler::Inline::rtt;
void x10::compiler::Inline::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>(), x10aux::getRTT<x10::lang::annotations::ExpressionAnnotation>()};
    rtt.initStageTwo("x10.compiler.Inline", 3, parents, 0, NULL, NULL);
}
