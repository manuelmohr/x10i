#include <x10/compiler/CUDADirectParams.h>


#include "x10/compiler/CUDADirectParams.inc"

x10aux::RuntimeType x10::compiler::CUDADirectParams::rtt;
void x10::compiler::CUDADirectParams::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.compiler.CUDADirectParams", 1, parents, 0, NULL, NULL);
}
