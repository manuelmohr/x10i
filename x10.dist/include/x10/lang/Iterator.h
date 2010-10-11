#ifndef __X10_LANG_ITERATOR_H
#define __X10_LANG_ITERATOR_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace compiler { 
class NativeRep;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Iterator;
template <> class Iterator<void>;
template<class FMGL(T)> class Iterator   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_boolean (I::*hasNext) (), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), FMGL(T) (I::*next) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hasNext(hasNext), hashCode(hashCode), home(home), next(next), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_boolean (I::*hasNext) ();
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        FMGL(T) (I::*next) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::lang::Iterator<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Iterator<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_ITERATOR_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 

#ifndef X10_LANG_ITERATOR_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Boolean.h>
#include <x10/compiler/Native.h>
#include <x10/compiler/NativeRep.h>
#ifndef X10_LANG_ITERATOR_H_GENERICS
#define X10_LANG_ITERATOR_H_GENERICS
#endif // X10_LANG_ITERATOR_H_GENERICS
#ifndef X10_LANG_ITERATOR_H_IMPLEMENTATION
#define X10_LANG_ITERATOR_H_IMPLEMENTATION
#include <x10/lang/Iterator.h>


#include "x10/lang/Iterator.inc"

template<class FMGL(T)> void x10::lang::Iterator<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Iterator<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Iterator<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Iterator<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Iterator<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.lang.Iterator";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_ITERATOR_H_IMPLEMENTATION
#endif // __X10_LANG_ITERATOR_H_NODEPS
