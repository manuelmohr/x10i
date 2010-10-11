#ifndef __X10_LANG_REDUCIBLE_H
#define __X10_LANG_REDUCIBLE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 

template<class FMGL(T)> class Reducible;
template <> class Reducible<void>;
template<class FMGL(T)> class Reducible   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(FMGL(T) (I::*apply) (FMGL(T), FMGL(T)), x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m2__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) (), FMGL(T) (I::*zero) ()) : apply(apply), _m1__at(_m1__at), _m2__at(_m2__at), equals(equals), hashCode(hashCode), home(home), toString(toString), typeName(typeName), zero(zero) {}
        FMGL(T) (I::*apply) (FMGL(T), FMGL(T));
        x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m2__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
        FMGL(T) (I::*zero) ();
    };
    
    static void _serialize(x10aux::ref<x10::lang::Reducible<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Reducible<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_REDUCIBLE_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class Reducible;
} } 

#ifndef X10_LANG_REDUCIBLE_H_NODEPS
#define X10_LANG_REDUCIBLE_H_NODEPS
#include <x10/lang/Any.h>
#ifndef X10_LANG_REDUCIBLE_H_GENERICS
#define X10_LANG_REDUCIBLE_H_GENERICS
#endif // X10_LANG_REDUCIBLE_H_GENERICS
#ifndef X10_LANG_REDUCIBLE_H_IMPLEMENTATION
#define X10_LANG_REDUCIBLE_H_IMPLEMENTATION
#include <x10/lang/Reducible.h>


#include "x10/lang/Reducible.inc"

template<class FMGL(T)> void x10::lang::Reducible<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Reducible<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Reducible<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Reducible<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Reducible<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Reducible";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_REDUCIBLE_H_IMPLEMENTATION
#endif // __X10_LANG_REDUCIBLE_H_NODEPS
