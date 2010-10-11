#include <x10/io/Readable.h>


#include "x10/io/Readable.inc"

void x10::io::Readable::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Readable");
    
}

x10aux::RuntimeType x10::io::Readable::rtt;
void x10::io::Readable::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.io.Readable", 1, parents, 0, NULL, NULL);
}
