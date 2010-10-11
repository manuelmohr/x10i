#ifndef __X10_UTIL_MAP_H
#define __X10_UTIL_MAP_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace util { 
class NoSuchElementException;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
} } 
namespace x10 { namespace util { 

template<class FMGL(K), class FMGL(V)> class Map;
template <> class Map<void, void>;
template<class FMGL(K), class FMGL(V)> class Map   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), void (I::*clear) (), x10_boolean (I::*containsKey) (FMGL(K)), x10aux::ref<x10::util::Set<x10aux::ref<x10::util::Map__Entry<FMGL(K), FMGL(V)> > > > (I::*entries) (), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10aux::ref<x10::util::Box<FMGL(V)> > (I::*get) (FMGL(K)), FMGL(V) (I::*getOrElse) (FMGL(K), FMGL(V)), FMGL(V) (I::*getOrThrow) (FMGL(K)), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::util::Set<FMGL(K)> > (I::*keySet) (), x10aux::ref<x10::util::Box<FMGL(V)> > (I::*put) (FMGL(K), FMGL(V)), x10aux::ref<x10::util::Box<FMGL(V)> > (I::*remove) (FMGL(K)), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), clear(clear), containsKey(containsKey), entries(entries), equals(equals), get(get), getOrElse(getOrElse), getOrThrow(getOrThrow), hashCode(hashCode), home(home), keySet(keySet), put(put), remove(remove), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        void (I::*clear) ();
        x10_boolean (I::*containsKey) (FMGL(K));
        x10aux::ref<x10::util::Set<x10aux::ref<x10::util::Map__Entry<FMGL(K), FMGL(V)> > > > (I::*entries) ();
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10aux::ref<x10::util::Box<FMGL(V)> > (I::*get) (FMGL(K));
        FMGL(V) (I::*getOrElse) (FMGL(K), FMGL(V));
        FMGL(V) (I::*getOrThrow) (FMGL(K));
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::util::Set<FMGL(K)> > (I::*keySet) ();
        x10aux::ref<x10::util::Box<FMGL(V)> > (I::*put) (FMGL(K), FMGL(V));
        x10aux::ref<x10::util::Box<FMGL(V)> > (I::*remove) (FMGL(K));
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::Map<FMGL(K), FMGL(V)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Map<void, void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_MAP_H

namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class Map;
} } 

#ifndef X10_UTIL_MAP_H_NODEPS
#define X10_UTIL_MAP_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Boolean.h>
#include <x10/util/Box.h>
#include <x10/util/NoSuchElementException.h>
#include <x10/util/Set.h>
#include <x10/util/Set.h>
#include <x10/util/Map__Entry.h>
#ifndef X10_UTIL_MAP_H_GENERICS
#define X10_UTIL_MAP_H_GENERICS
#endif // X10_UTIL_MAP_H_GENERICS
#ifndef X10_UTIL_MAP_H_IMPLEMENTATION
#define X10_UTIL_MAP_H_IMPLEMENTATION
#include <x10/util/Map.h>


#include "x10/util/Map.inc"

template<class FMGL(K), class FMGL(V)> void x10::util::Map<FMGL(K), FMGL(V)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Map<FMGL(K), FMGL(V)>");
    
}

template<class FMGL(K), class FMGL(V)> x10aux::RuntimeType x10::util::Map<FMGL(K), FMGL(V)>::rtt;
template<class FMGL(K), class FMGL(V)> void x10::util::Map<FMGL(K), FMGL(V)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::Map<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(K)>(), x10aux::getRTT<FMGL(V)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.Map";
    rtt.initStageTwo(baseName, 1, parents, 2, params, variances);
}
#endif // X10_UTIL_MAP_H_IMPLEMENTATION
#endif // __X10_UTIL_MAP_H_NODEPS
