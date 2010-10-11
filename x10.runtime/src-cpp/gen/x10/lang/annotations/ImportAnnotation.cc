#include <x10/lang/annotations/ImportAnnotation.h>


#include "x10/lang/annotations/ImportAnnotation.inc"

x10aux::RuntimeType x10::lang::annotations::ImportAnnotation::rtt;
void x10::lang::annotations::ImportAnnotation::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::Annotation>()};
    rtt.initStageTwo("x10.lang.annotations.ImportAnnotation", 2, parents, 0, NULL, NULL);
}
