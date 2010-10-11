#ifndef __X10_LANG_BITWISE_H
#define __X10_LANG_BITWISE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 

template<class FMGL(T)> class Bitwise;
template <> class Bitwise<void>;
template<class FMGL(T)> class Bitwise   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), FMGL(T) (I::*__ampersand) (FMGL(T)), FMGL(T) (I::*__left) (x10_int), FMGL(T) (I::*__right) (x10_int), FMGL(T) (I::*__unsigned_right) (x10_int), FMGL(T) (I::*__caret) (FMGL(T)), FMGL(T) (I::*__bar) (FMGL(T)), FMGL(T) (I::*__tilde) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hashCode(hashCode), home(home), __ampersand(__ampersand), __left(__left), __right(__right), __unsigned_right(__unsigned_right), __caret(__caret), __bar(__bar), __tilde(__tilde), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        FMGL(T) (I::*__ampersand) (FMGL(T));
        FMGL(T) (I::*__left) (x10_int);
        FMGL(T) (I::*__right) (x10_int);
        FMGL(T) (I::*__unsigned_right) (x10_int);
        FMGL(T) (I::*__caret) (FMGL(T));
        FMGL(T) (I::*__bar) (FMGL(T));
        FMGL(T) (I::*__tilde) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::lang::Bitwise<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Bitwise<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_BITWISE_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class Bitwise;
} } 

#ifndef X10_LANG_BITWISE_H_NODEPS
#define X10_LANG_BITWISE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Int.h>
#ifndef X10_LANG_BITWISE_H_GENERICS
#define X10_LANG_BITWISE_H_GENERICS
#endif // X10_LANG_BITWISE_H_GENERICS
#ifndef X10_LANG_BITWISE_H_IMPLEMENTATION
#define X10_LANG_BITWISE_H_IMPLEMENTATION
#include <x10/lang/Bitwise.h>


#include "x10/lang/Bitwise.inc"

template<class FMGL(T)> void x10::lang::Bitwise<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Bitwise<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Bitwise<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Bitwise<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Bitwise<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Bitwise";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_BITWISE_H_IMPLEMENTATION
#endif // __X10_LANG_BITWISE_H_NODEPS
