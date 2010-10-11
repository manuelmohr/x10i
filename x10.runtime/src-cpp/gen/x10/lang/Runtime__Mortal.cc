#include <x10/lang/Runtime__Mortal.h>


#include "x10/lang/Runtime__Mortal.inc"

x10aux::RuntimeType x10::lang::Runtime__Mortal::rtt;
void x10::lang::Runtime__Mortal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.lang.Runtime$Mortal", 1, parents, 0, NULL, NULL);
}
