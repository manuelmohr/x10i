#include <x10/array/Region__Scanner.h>


#include "x10/array/Region__Scanner.inc"

void x10::array::Region__Scanner::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Region__Scanner");
    
}

x10aux::RuntimeType x10::array::Region__Scanner::rtt;
void x10::array::Region__Scanner::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.array.Region$Scanner", 1, parents, 0, NULL, NULL);
}
