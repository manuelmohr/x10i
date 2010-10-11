#include <x10/lang/annotations/MethodAnnotation.h>


#include "x10/lang/annotations/MethodAnnotation.inc"

x10aux::RuntimeType x10::lang::annotations::MethodAnnotation::rtt;
void x10::lang::annotations::MethodAnnotation::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::Annotation>()};
    rtt.initStageTwo("x10.lang.annotations.MethodAnnotation", 2, parents, 0, NULL, NULL);
}
