#ifndef __X10_UTIL_LISTITERATOR_H
#define __X10_UTIL_LISTITERATOR_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_UTIL_COLLECTIONITERATOR_H_NODEPS
#include <x10/util/CollectionIterator.h>
#undef X10_UTIL_COLLECTIONITERATOR_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 

template<class FMGL(T)> class ListIterator;
template <> class ListIterator<void>;
template<class FMGL(T)> class ListIterator   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(void (I::*add) (FMGL(T)), x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m2__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_boolean (I::*hasNext) (), x10_boolean (I::*hasPrevious) (), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), FMGL(T) (I::*next) (), x10_int (I::*nextIndex) (), FMGL(T) (I::*previous) (), x10_int (I::*previousIndex) (), void (I::*remove) (), void (I::*set) (FMGL(T)), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : add(add), _m1__at(_m1__at), _m2__at(_m2__at), equals(equals), hasNext(hasNext), hasPrevious(hasPrevious), hashCode(hashCode), home(home), next(next), nextIndex(nextIndex), previous(previous), previousIndex(previousIndex), remove(remove), set(set), toString(toString), typeName(typeName) {}
        void (I::*add) (FMGL(T));
        x10_boolean (I::*_m1__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m2__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_boolean (I::*hasNext) ();
        x10_boolean (I::*hasPrevious) ();
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        FMGL(T) (I::*next) ();
        x10_int (I::*nextIndex) ();
        FMGL(T) (I::*previous) ();
        x10_int (I::*previousIndex) ();
        void (I::*remove) ();
        void (I::*set) (FMGL(T));
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::util::ListIterator<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class ListIterator<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_LISTITERATOR_H

namespace x10 { namespace util { 
template<class FMGL(T)> class ListIterator;
} } 

#ifndef X10_UTIL_LISTITERATOR_H_NODEPS
#define X10_UTIL_LISTITERATOR_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/util/CollectionIterator.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Int.h>
#ifndef X10_UTIL_LISTITERATOR_H_GENERICS
#define X10_UTIL_LISTITERATOR_H_GENERICS
#endif // X10_UTIL_LISTITERATOR_H_GENERICS
#ifndef X10_UTIL_LISTITERATOR_H_IMPLEMENTATION
#define X10_UTIL_LISTITERATOR_H_IMPLEMENTATION
#include <x10/util/ListIterator.h>


#include "x10/util/ListIterator.inc"

template<class FMGL(T)> void x10::util::ListIterator<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ListIterator<FMGL(T)>");
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::ListIterator<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::ListIterator<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ListIterator<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::util::CollectionIterator<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.util.ListIterator";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_UTIL_LISTITERATOR_H_IMPLEMENTATION
#endif // __X10_UTIL_LISTITERATOR_H_NODEPS
