#ifndef __X10_UTIL_BUILDER_H
#define __X10_UTIL_BUILDER_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace util { 

template<class FMGL(Element), class FMGL(Collection)> class Builder;
template <> class Builder<void, void>;
template<class FMGL(Element), class FMGL(Collection)> class Builder   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10aux::ref<x10::util::Builder<FMGL(Element), FMGL(Collection)> > (I::*add) (FMGL(Element)), x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m2__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), FMGL(Collection) (I::*result) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : add(add), _m1__at(_m1__at), _m2__at(_m2__at), equals(equals), hashCode(hashCode), home(home), result(result), toString(toString), typeName(typeName) {}
        x10aux::ref<x10::util::Builder<FMGL(Element), FMGL(Collection)> > (I::*add) (FMGL(Element));
        x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m2__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        FMGL(Collection) (I::*result) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::Builder<FMGL(Element), FMGL(Collection)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Builder<void, void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_BUILDER_H

namespace x10 { namespace util { 
template<class FMGL(Element), class FMGL(Collection)> class Builder;
} } 

#ifndef X10_UTIL_BUILDER_H_NODEPS
#define X10_UTIL_BUILDER_H_NODEPS
#include <x10/lang/Any.h>
#ifndef X10_UTIL_BUILDER_H_GENERICS
#define X10_UTIL_BUILDER_H_GENERICS
#endif // X10_UTIL_BUILDER_H_GENERICS
#ifndef X10_UTIL_BUILDER_H_IMPLEMENTATION
#define X10_UTIL_BUILDER_H_IMPLEMENTATION
#include <x10/util/Builder.h>


#include "x10/util/Builder.inc"

template<class FMGL(Element), class FMGL(Collection)> void x10::util::Builder<FMGL(Element), FMGL(Collection)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Builder<FMGL(Element), FMGL(Collection)>");
    
}

template<class FMGL(Element), class FMGL(Collection)> x10aux::RuntimeType x10::util::Builder<FMGL(Element), FMGL(Collection)>::rtt;
template<class FMGL(Element), class FMGL(Collection)> void x10::util::Builder<FMGL(Element), FMGL(Collection)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::Builder<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(Element)>(), x10aux::getRTT<FMGL(Collection)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::covariant};
    const char *baseName = "x10.util.Builder";
    rtt.initStageTwo(baseName, 1, parents, 2, params, variances);
}
#endif // X10_UTIL_BUILDER_H_IMPLEMENTATION
#endif // __X10_UTIL_BUILDER_H_NODEPS
