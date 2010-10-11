#ifndef __X10_UTIL_CONTAINER_H
#define __X10_UTIL_CONTAINER_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ITERABLE_H_NODEPS
#include <x10/lang/Iterable.h>
#undef X10_LANG_ITERABLE_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class Container;
template <> class Container<void>;
template<class FMGL(T)> class Container   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) (), x10_boolean (I::*contains) (FMGL(T)), x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10_boolean (I::*isEmpty) (), x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) (), x10_int (I::*size) (), x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), clone(clone), contains(contains), containsAll(containsAll), equals(equals), hashCode(hashCode), home(home), isEmpty(isEmpty), iterator(iterator), size(size), toRail(toRail), toString(toString), toValRail(toValRail), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) ();
        x10_boolean (I::*contains) (FMGL(T));
        x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10_boolean (I::*isEmpty) ();
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) ();
        x10_int (I::*size) ();
        x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::Container<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Container<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_CONTAINER_H

namespace x10 { namespace util { 
template<class FMGL(T)> class Container;
} } 

#ifndef X10_UTIL_CONTAINER_H_NODEPS
#define X10_UTIL_CONTAINER_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Iterable.h>
#include <x10/lang/Int.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#ifndef X10_UTIL_CONTAINER_H_GENERICS
#define X10_UTIL_CONTAINER_H_GENERICS
#endif // X10_UTIL_CONTAINER_H_GENERICS
#ifndef X10_UTIL_CONTAINER_H_IMPLEMENTATION
#define X10_UTIL_CONTAINER_H_IMPLEMENTATION
#include <x10/util/Container.h>


#include "x10/util/Container.inc"

template<class FMGL(T)> void x10::util::Container<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Container<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::Container<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::Container<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::Container<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.util.Container";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_UTIL_CONTAINER_H_IMPLEMENTATION
#endif // __X10_UTIL_CONTAINER_H_NODEPS
