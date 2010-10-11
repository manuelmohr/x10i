#ifndef __X10_UTIL_COLLECTION_H
#define __X10_UTIL_COLLECTION_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_UTIL_CONTAINER_H_NODEPS
#include <x10/util/Container.h>
#undef X10_UTIL_CONTAINER_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class Collection;
template <> class Collection<void>;
template<class FMGL(T)> class Collection   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*add) (FMGL(T)), x10_boolean (I::*addAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*addAllWhere) (x10aux::ref<x10::util::Container<FMGL(T)> >, x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >), x10_boolean (I::*_m3__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m4__at) (x10::lang::Place), void (I::*clear) (), x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) (), x10_boolean (I::*contains) (FMGL(T)), x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10_boolean (I::*isEmpty) (), x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) (), x10_boolean (I::*remove) (FMGL(T)), x10_boolean (I::*removeAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*removeAllWhere) (x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >), x10_boolean (I::*retainAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_int (I::*size) (), x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : add(add), addAll(addAll), addAllWhere(addAllWhere), _m3__at(_m3__at), _m4__at(_m4__at), clear(clear), clone(clone), contains(contains), containsAll(containsAll), equals(equals), hashCode(hashCode), home(home), isEmpty(isEmpty), iterator(iterator), remove(remove), removeAll(removeAll), removeAllWhere(removeAllWhere), retainAll(retainAll), size(size), toRail(toRail), toString(toString), toValRail(toValRail), typeName(typeName) {}
        x10_boolean (I::*add) (FMGL(T));
        x10_boolean (I::*addAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*addAllWhere) (x10aux::ref<x10::util::Container<FMGL(T)> >, x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >);
        x10_boolean (I::*_m3__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m4__at) (x10::lang::Place);
        void (I::*clear) ();
        x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) ();
        x10_boolean (I::*contains) (FMGL(T));
        x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10_boolean (I::*isEmpty) ();
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) ();
        x10_boolean (I::*remove) (FMGL(T));
        x10_boolean (I::*removeAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*removeAllWhere) (x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >);
        x10_boolean (I::*retainAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_int (I::*size) ();
        x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::Collection<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Collection<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_COLLECTION_H

namespace x10 { namespace util { 
template<class FMGL(T)> class Collection;
} } 

#ifndef X10_UTIL_COLLECTION_H_NODEPS
#define X10_UTIL_COLLECTION_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/util/Container.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_UTIL_COLLECTION_H_GENERICS
#define X10_UTIL_COLLECTION_H_GENERICS
#endif // X10_UTIL_COLLECTION_H_GENERICS
#ifndef X10_UTIL_COLLECTION_H_IMPLEMENTATION
#define X10_UTIL_COLLECTION_H_IMPLEMENTATION
#include <x10/util/Collection.h>


#include "x10/util/Collection.inc"

template<class FMGL(T)> void x10::util::Collection<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::Collection<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::Collection<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::Collection<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::Collection<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::util::Container<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.Collection";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_UTIL_COLLECTION_H_IMPLEMENTATION
#endif // __X10_UTIL_COLLECTION_H_NODEPS
