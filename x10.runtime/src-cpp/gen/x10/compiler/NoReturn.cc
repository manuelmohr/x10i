#include <x10/compiler/NoReturn.h>


#include "x10/compiler/NoReturn.inc"

x10aux::RuntimeType x10::compiler::NoReturn::rtt;
void x10::compiler::NoReturn::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>()};
    rtt.initStageTwo("x10.compiler.NoReturn", 2, parents, 0, NULL, NULL);
}
