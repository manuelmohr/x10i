#ifndef __X10_UTIL_LIST_H
#define __X10_UTIL_LIST_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_UTIL_COLLECTION_H_NODEPS
#include <x10/util/Collection.h>
#undef X10_UTIL_COLLECTION_H_NODEPS
#define X10_UTIL_INDEXED_H_NODEPS
#include <x10/util/Indexed.h>
#undef X10_UTIL_INDEXED_H_NODEPS
#define X10_LANG_SETTABLE_H_NODEPS
#include <x10/lang/Settable.h>
#undef X10_LANG_SETTABLE_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class ListIterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Comparable;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class List;
template <> class List<void>;
template<class FMGL(T)> class List   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*add) (FMGL(T)), x10_boolean (I::*addAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*addAllWhere) (x10aux::ref<x10::util::Container<FMGL(T)> >, x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >), void (I::*addBefore) (x10_int, FMGL(T)), FMGL(T) (I::*apply) (x10_int), x10_boolean (I::*_m5__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m6__at) (x10::lang::Place), void (I::*clear) (), x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) (), x10_boolean (I::*contains) (FMGL(T)), x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), FMGL(T) (I::*getFirst) (), FMGL(T) (I::*getLast) (), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10_int (I::*_m16__indexOf) (FMGL(T)), x10_int (I::*_m17__indexOf) (x10_int, FMGL(T)), x10aux::ref<x10::util::List<x10_int> > (I::*indices) (), x10_boolean (I::*isEmpty) (), x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) (), x10aux::ref<x10::util::ListIterator<FMGL(T)> > (I::*iteratorFrom) (x10_int), x10_int (I::*_m22__lastIndexOf) (FMGL(T)), x10_int (I::*_m23__lastIndexOf) (x10_int, FMGL(T)), x10_boolean (I::*remove) (FMGL(T)), x10_boolean (I::*removeAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), x10_boolean (I::*removeAllWhere) (x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >), FMGL(T) (I::*removeAt) (x10_int), FMGL(T) (I::*removeFirst) (), FMGL(T) (I::*removeLast) (), x10_boolean (I::*retainAll) (x10aux::ref<x10::util::Container<FMGL(T)> >), void (I::*reverse) (), FMGL(T) (I::*set) (FMGL(T), x10_int), x10_int (I::*size) (), void (I::*_m34__sort) (), void (I::*_m35__sort) (x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >), x10aux::ref<x10::util::List<FMGL(T)> > (I::*subList) (x10_int, x10_int), x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : add(add), addAll(addAll), addAllWhere(addAllWhere), addBefore(addBefore), apply(apply), _m5__at(_m5__at), _m6__at(_m6__at), clear(clear), clone(clone), contains(contains), containsAll(containsAll), equals(equals), getFirst(getFirst), getLast(getLast), hashCode(hashCode), home(home), _m16__indexOf(_m16__indexOf), _m17__indexOf(_m17__indexOf), indices(indices), isEmpty(isEmpty), iterator(iterator), iteratorFrom(iteratorFrom), _m22__lastIndexOf(_m22__lastIndexOf), _m23__lastIndexOf(_m23__lastIndexOf), remove(remove), removeAll(removeAll), removeAllWhere(removeAllWhere), removeAt(removeAt), removeFirst(removeFirst), removeLast(removeLast), retainAll(retainAll), reverse(reverse), set(set), size(size), _m34__sort(_m34__sort), _m35__sort(_m35__sort), subList(subList), toRail(toRail), toString(toString), toValRail(toValRail), typeName(typeName) {}
        x10_boolean (I::*add) (FMGL(T));
        x10_boolean (I::*addAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*addAllWhere) (x10aux::ref<x10::util::Container<FMGL(T)> >, x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >);
        void (I::*addBefore) (x10_int, FMGL(T));
        FMGL(T) (I::*apply) (x10_int);
        x10_boolean (I::*_m5__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m6__at) (x10::lang::Place);
        void (I::*clear) ();
        x10aux::ref<x10::util::Container<FMGL(T)> > (I::*clone) ();
        x10_boolean (I::*contains) (FMGL(T));
        x10_boolean (I::*containsAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        FMGL(T) (I::*getFirst) ();
        FMGL(T) (I::*getLast) ();
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10_int (I::*_m16__indexOf) (FMGL(T));
        x10_int (I::*_m17__indexOf) (x10_int, FMGL(T));
        x10aux::ref<x10::util::List<x10_int> > (I::*indices) ();
        x10_boolean (I::*isEmpty) ();
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > (I::*iterator) ();
        x10aux::ref<x10::util::ListIterator<FMGL(T)> > (I::*iteratorFrom) (x10_int);
        x10_int (I::*_m22__lastIndexOf) (FMGL(T));
        x10_int (I::*_m23__lastIndexOf) (x10_int, FMGL(T));
        x10_boolean (I::*remove) (FMGL(T));
        x10_boolean (I::*removeAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        x10_boolean (I::*removeAllWhere) (x10aux::ref<x10::lang::Fun_0_1<FMGL(T), x10_boolean> >);
        FMGL(T) (I::*removeAt) (x10_int);
        FMGL(T) (I::*removeFirst) ();
        FMGL(T) (I::*removeLast) ();
        x10_boolean (I::*retainAll) (x10aux::ref<x10::util::Container<FMGL(T)> >);
        void (I::*reverse) ();
        FMGL(T) (I::*set) (FMGL(T), x10_int);
        x10_int (I::*size) ();
        void (I::*_m34__sort) ();
        void (I::*_m35__sort) (x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >);
        x10aux::ref<x10::util::List<FMGL(T)> > (I::*subList) (x10_int, x10_int);
        x10aux::ref<x10::lang::Rail<FMGL(T) > > (I::*toRail) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > (I::*toValRail) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::List<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class List<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_LIST_H

namespace x10 { namespace util { 
template<class FMGL(T)> class List;
} } 

#ifndef X10_UTIL_LIST_H_NODEPS
#define X10_UTIL_LIST_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/util/Collection.h>
#include <x10/util/Indexed.h>
#include <x10/lang/Settable.h>
#include <x10/lang/Int.h>
#include <x10/util/ListIterator.h>
#include <x10/lang/Comparable.h>
#include <x10/lang/Fun_0_2.h>
#ifndef X10_UTIL_LIST_H_GENERICS
#define X10_UTIL_LIST_H_GENERICS
#endif // X10_UTIL_LIST_H_GENERICS
#ifndef X10_UTIL_LIST_H_IMPLEMENTATION
#define X10_UTIL_LIST_H_IMPLEMENTATION
#include <x10/util/List.h>


#include "x10/util/List.inc"

template<class FMGL(T)> void x10::util::List<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::List<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::List<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::List<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::List<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[4] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::util::Collection<FMGL(T)> >(), x10aux::getRTT<x10::util::Indexed<FMGL(T)> >(), x10aux::getRTT<x10::lang::Settable<x10_int, FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.List";
    rtt.initStageTwo(baseName, 4, parents, 1, params, variances);
}
#endif // X10_UTIL_LIST_H_IMPLEMENTATION
#endif // __X10_UTIL_LIST_H_NODEPS
