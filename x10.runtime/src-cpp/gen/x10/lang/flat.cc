#include <x10/lang/flat.h>


#include "x10/lang/flat.inc"

x10aux::RuntimeType x10::lang::flat::rtt;
void x10::lang::flat::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[4] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::annotations::ExpressionAnnotation>(), x10aux::getRTT<x10::lang::annotations::StatementAnnotation>(), x10aux::getRTT<x10::lang::annotations::MethodAnnotation>()};
    rtt.initStageTwo("x10.lang.flat", 4, parents, 0, NULL, NULL);
}
