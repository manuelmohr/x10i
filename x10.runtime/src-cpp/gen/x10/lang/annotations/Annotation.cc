#include <x10/lang/annotations/Annotation.h>


#include "x10/lang/annotations/Annotation.inc"

x10aux::RuntimeType x10::lang::annotations::Annotation::rtt;
void x10::lang::annotations::Annotation::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.lang.annotations.Annotation", 1, parents, 0, NULL, NULL);
}
