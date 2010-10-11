#ifndef __X10_UTIL_VALHASHMAP__KEYSET_H
#define __X10_UTIL_VALHASHMAP__KEYSET_H

#include <x10rt.h>


#define X10_UTIL_ABSTRACTCOLLECTION_H_NODEPS
#include <x10/util/AbstractCollection.h>
#undef X10_UTIL_ABSTRACTCOLLECTION_H_NODEPS
#define X10_UTIL_SET_H_NODEPS
#include <x10/util/Set.h>
#undef X10_UTIL_SET_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class ValHashMap;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(S), class FMGL(T)> class MapIterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class UnsupportedOperationException;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class Collection;
} } 
namespace x10 { namespace util { 

template<class FMGL(Key), class FMGL(Value)> class ValHashMap__KeySet;
template <> class ValHashMap__KeySet<void, void>;
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__KeySet : public x10::util::AbstractCollection<FMGL(Key)>
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[6];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::Container<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _itable_1;
    
    static typename x10::lang::Iterable<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _itable_2;
    
    static typename x10::util::Collection<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _itable_3;
    
    static typename x10::util::Set<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _itable_4;
    
    void _instance_init();
    
    x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > FMGL(map);
    
    void _constructor(x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map);
    
    static x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > _make(
             x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map);
    
    virtual x10aux::ref<x10::lang::Iterator<FMGL(Key)> > iterator(
      );
    virtual x10_boolean contains(FMGL(Key) k);
    virtual x10_boolean add(FMGL(Key) k);
    virtual x10_boolean remove(FMGL(Key) k);
    virtual x10aux::ref<x10::util::Container<FMGL(Key)> >
      clone(
      );
    virtual x10_int size();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ValHashMap__KeySet<void, void> : public x10::util::AbstractCollection<void>
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_VALHASHMAP__KEYSET_H

namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)>
class ValHashMap__KeySet;
} } 

#ifndef X10_UTIL_VALHASHMAP__KEYSET_H_NODEPS
#define X10_UTIL_VALHASHMAP__KEYSET_H_NODEPS
#include <x10/util/AbstractCollection.h>
#include <x10/util/Set.h>
#include <x10/util/ValHashMap.h>
#include <x10/lang/Iterator.h>
#include <x10/util/MapIterator.h>
#include <x10/util/ValHashMap__HashEntry.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/UnsupportedOperationException.h>
#include <x10/lang/Int.h>
#include <x10/util/Collection.h>
#ifndef X10_UTIL_VALHASHMAP__KEYSET__CLOSURE__0_CLOSURE
#define X10_UTIL_VALHASHMAP__KEYSET__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(Key), class FMGL(Value)> class x10_util_ValHashMap__KeySet__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)>::template itable <x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(Key) apply(x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > e) {
        
        //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(e)->FMGL(key);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) > > this_ = new (x10aux::alloc<x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) > >()) x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_util_ValHashMap__KeySet__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10:166";
    }

};

template<class FMGL(Key), class FMGL(Value)> typename x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)>::template itable <x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) > >x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::_itable(&x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::toString, &x10::lang::Closure::typeName);template<class FMGL(Key), class FMGL(Value)>
x10aux::itable_entry x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> >, &x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(Key), class FMGL(Value)>
const x10aux::serialization_id_t x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) >::template _deserialize<x10::lang::Object>);

#endif // X10_UTIL_VALHASHMAP__KEYSET__CLOSURE__0_CLOSURE
#ifndef X10_UTIL_VALHASHMAP__KEYSET_H_GENERICS
#define X10_UTIL_VALHASHMAP__KEYSET_H_GENERICS
template<class FMGL(Key), class FMGL(Value)> template<class __T> x10aux::ref<__T> x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > this_ = new (x10aux::alloc_remote<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >()) x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_VALHASHMAP__KEYSET_H_GENERICS
#ifndef X10_UTIL_VALHASHMAP__KEYSET_H_IMPLEMENTATION
#define X10_UTIL_VALHASHMAP__KEYSET_H_IMPLEMENTATION
#include <x10/util/ValHashMap__KeySet.h>


#include "x10/util/ValHashMap__KeySet.inc"

template<class FMGL(Key), class FMGL(Value)> typename x10::util::Container<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itable_0(&x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clone, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::contains, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::containsAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::isEmpty, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::iterator, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::size, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toValRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10::lang::Any::itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itable_1(&x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> typename x10::lang::Iterable<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itable_2(&x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::iterator, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> typename x10::util::Collection<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itable_3(&x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::add, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::addAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::addAllWhere, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clear, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clone, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::contains, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::containsAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::isEmpty, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::iterator, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::remove, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::removeAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::removeAllWhere, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::retainAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::size, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toValRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> typename x10::util::Set<FMGL(Key)>::template itable<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itable_4(&x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::add, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::addAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::addAllWhere, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clear, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clone, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::contains, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::containsAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::isEmpty, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::iterator, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::remove, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::removeAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::removeAllWhere, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::retainAll, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::size, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::toValRail, &x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10aux::itable_entry x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_itables[6] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Container<FMGL(Key)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<FMGL(Key)> >, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::util::Collection<FMGL(Key)> >, &_itable_3), x10aux::itable_entry(&x10aux::getRTT<x10::util::Set<FMGL(Key)> >, &_itable_4), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >())};
template<class FMGL(Key), class FMGL(Value)> void x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>");
    
}


//#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(Key), class FMGL(Value)> void x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_constructor(
                                               x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map)
{
    this->x10::util::AbstractCollection<FMGL(Key)>::_constructor();
    
    //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >)this))->
      FMGL(map) =
      map;
    
}
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_make(
  x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map)
{
    x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> > this_ = new (memset(x10aux::alloc<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >(), 0, sizeof(x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>))) x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>();
    this_->_constructor(map);
    return this_;
}



//#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::lang::Iterator<FMGL(Key)> >
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::iterator(
  ) {
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<FMGL(Key)> > >(x10::util::MapIterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)>::_make(x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >)this)->
                                                                                                                                                                                                                            FMGL(map))->entriesIterator(),
                                                                                                                                                                                                        x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> > >(x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> >(x10aux::ref<x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >, FMGL(Key)> >(sizeof(x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value)>)))x10_util_ValHashMap__KeySet__closure__0<FMGL(Key),FMGL(Value)>())))));
    
}

//#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10_boolean
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::contains(
  FMGL(Key) k) {
    
    //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >)this)->
                               FMGL(map))->containsKey(
             k);
    
}

//#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10_boolean
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::add(
  FMGL(Key) k) {
    
    //#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make()));
}

//#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10_boolean
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::remove(
  FMGL(Key) k) {
    
    //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make()));
}

//#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::Container<FMGL(Key)> >
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::clone(
  ) {
    
    //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make()));
}

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10_int
  x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::size(
  ) {
    
    //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)> >)this)->
                               FMGL(map))->size();
    
}
template<class FMGL(Key), class FMGL(Value)>
const x10aux::serialization_id_t x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::template _deserializer<x10::lang::Object>);

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::util::AbstractCollection<FMGL(Key)>::_serialize_body(buf);
    
}

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::util::AbstractCollection<FMGL(Key)>::_deserialize_body(buf);
    
}

template<class FMGL(Key), class FMGL(Value)>
x10aux::RuntimeType x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::rtt;
template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__KeySet<FMGL(Key), FMGL(Value)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ValHashMap__KeySet<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::util::AbstractCollection<FMGL(Key)> >(), x10aux::getRTT<x10::util::Set<FMGL(Key)> >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(Key)>(), x10aux::getRTT<FMGL(Value)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ValHashMap$KeySet";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
#endif // X10_UTIL_VALHASHMAP__KEYSET_H_IMPLEMENTATION
#endif // __X10_UTIL_VALHASHMAP__KEYSET_H_NODEPS
