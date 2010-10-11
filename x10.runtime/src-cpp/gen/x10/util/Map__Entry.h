#ifndef __X10_UTIL_MAP__ENTRY_H
#define __X10_UTIL_MAP__ENTRY_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace util { 

template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
template <> class Map__Entry<void, void>;
template<class FMGL(Key), class FMGL(Val)> class Map__Entry   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), FMGL(Key) (I::*getKey) (), FMGL(Val) (I::*getValue) (), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), void (I::*setValue) (FMGL(Val)), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), getKey(getKey), getValue(getValue), hashCode(hashCode), home(home), setValue(setValue), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        FMGL(Key) (I::*getKey) ();
        FMGL(Val) (I::*getValue) ();
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        void (I::*setValue) (FMGL(Val));
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Val)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Map__Entry<void, void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_MAP__ENTRY_H

namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
} } 

#ifndef X10_UTIL_MAP__ENTRY_H_NODEPS
#define X10_UTIL_MAP__ENTRY_H_NODEPS
#include <x10/lang/Any.h>
#ifndef X10_UTIL_MAP__ENTRY_H_GENERICS
#define X10_UTIL_MAP__ENTRY_H_GENERICS
#endif // X10_UTIL_MAP__ENTRY_H_GENERICS
#ifndef X10_UTIL_MAP__ENTRY_H_IMPLEMENTATION
#define X10_UTIL_MAP__ENTRY_H_IMPLEMENTATION
#include <x10/util/Map__Entry.h>


#include "x10/util/Map__Entry.inc"

template<class FMGL(Key), class FMGL(Val)> void x10::util::Map__Entry<FMGL(Key), FMGL(Val)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Map__Entry<FMGL(Key), FMGL(Val)>");
    
}

template<class FMGL(Key), class FMGL(Val)> x10aux::RuntimeType x10::util::Map__Entry<FMGL(Key), FMGL(Val)>::rtt;
template<class FMGL(Key), class FMGL(Val)> void x10::util::Map__Entry<FMGL(Key), FMGL(Val)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::Map__Entry<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(Key)>(), x10aux::getRTT<FMGL(Val)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.Map$Entry";
    rtt.initStageTwo(baseName, 1, parents, 2, params, variances);
}
#endif // X10_UTIL_MAP__ENTRY_H_IMPLEMENTATION
#endif // __X10_UTIL_MAP__ENTRY_H_NODEPS
