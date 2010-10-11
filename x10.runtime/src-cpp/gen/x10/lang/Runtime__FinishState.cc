#include <x10/lang/Runtime__FinishState.h>


#include "x10/lang/Runtime__FinishState.inc"

void x10::lang::Runtime__FinishState::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__FinishState");
    
}

x10aux::RuntimeType x10::lang::Runtime__FinishState::rtt;
void x10::lang::Runtime__FinishState::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.lang.Runtime$FinishState", 1, parents, 0, NULL, NULL);
}
