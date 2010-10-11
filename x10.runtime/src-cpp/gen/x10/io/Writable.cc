#include <x10/io/Writable.h>


#include "x10/io/Writable.inc"

void x10::io::Writable::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Writable");
    
}

x10aux::RuntimeType x10::io::Writable::rtt;
void x10::io::Writable::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.io.Writable", 1, parents, 0, NULL, NULL);
}
