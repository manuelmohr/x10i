#include <x10/compiler/InlineOnly.h>


#include "x10/compiler/InlineOnly.inc"

x10aux::RuntimeType x10::compiler::InlineOnly::rtt;
void x10::compiler::InlineOnly::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::compiler::Inline>()};
    rtt.initStageTwo("x10.compiler.InlineOnly", 2, parents, 0, NULL, NULL);
}
