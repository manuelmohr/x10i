#ifndef __X10_COMPILER_SETOPS_H
#define __X10_COMPILER_SETOPS_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace compiler { 

template<class FMGL(T)> class SetOps;
template <> class SetOps<void>;
template<class FMGL(T)> class SetOps   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(FMGL(T) (I::*__and) (FMGL(T)), FMGL(T) (I::*__minus) (FMGL(T)), FMGL(T) (I::*__not) (), FMGL(T) (I::*__or) (FMGL(T)), x10_boolean (I::*_m4__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m5__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : __and(__and), __minus(__minus), __not(__not), __or(__or), _m4__at(_m4__at), _m5__at(_m5__at), equals(equals), hashCode(hashCode), home(home), toString(toString), typeName(typeName) {}
        FMGL(T) (I::*__and) (FMGL(T));
        FMGL(T) (I::*__minus) (FMGL(T));
        FMGL(T) (I::*__not) ();
        FMGL(T) (I::*__or) (FMGL(T));
        x10_boolean (I::*_m4__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m5__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::compiler::SetOps<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class SetOps<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_COMPILER_SETOPS_H

namespace x10 { namespace compiler { 
template<class FMGL(T)> class SetOps;
} } 

#ifndef X10_COMPILER_SETOPS_H_NODEPS
#define X10_COMPILER_SETOPS_H_NODEPS
#include <x10/lang/Any.h>
#ifndef X10_COMPILER_SETOPS_H_GENERICS
#define X10_COMPILER_SETOPS_H_GENERICS
#endif // X10_COMPILER_SETOPS_H_GENERICS
#ifndef X10_COMPILER_SETOPS_H_IMPLEMENTATION
#define X10_COMPILER_SETOPS_H_IMPLEMENTATION
#include <x10/compiler/SetOps.h>


#include "x10/compiler/SetOps.inc"

template<class FMGL(T)> void x10::compiler::SetOps<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::SetOps<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::compiler::SetOps<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::compiler::SetOps<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::compiler::SetOps<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.compiler.SetOps";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_COMPILER_SETOPS_H_IMPLEMENTATION
#endif // __X10_COMPILER_SETOPS_H_NODEPS
