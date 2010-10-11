#include <x10/compiler/CUDA.h>


#include "x10/compiler/CUDA.inc"

x10aux::RuntimeType x10::compiler::CUDA::rtt;
void x10::compiler::CUDA::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.compiler.CUDA", 1, parents, 0, NULL, NULL);
}
