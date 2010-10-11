#ifndef __X10_UTIL_VALHASHMAP_H
#define __X10_UTIL_VALHASHMAP_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_UTIL_VALMAP_H_NODEPS
#include <x10/util/ValMap.h>
#undef X10_UTIL_VALMAP_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class Map;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterable;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterable;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterable;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__HashEntry;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 
class NoSuchElementException;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__KeySet;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class ValMap__Entry;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__EntrySet;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__EntriesIterator;
} } 
namespace x10 { namespace util { 

template<class FMGL(K), class FMGL(V)> class ValHashMap;
template <> class ValHashMap<void, void>;
template<class FMGL(K), class FMGL(V)> class ValHashMap : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::ValMap<FMGL(K), FMGL(V)>::template itable<x10::util::ValHashMap<FMGL(K), FMGL(V)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ValHashMap<FMGL(K), FMGL(V)> > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >
      FMGL(table);
    
    void _constructor(x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > map);
    
    static x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> > _make(
             x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > map);
    
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > apply(FMGL(K) k);
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > get(FMGL(K) k);
    virtual FMGL(V) getOrElse(FMGL(K) k, FMGL(V) orelse);
    virtual FMGL(K) findMax(FMGL(K) index, FMGL(V) max, x10aux::ref<x10::lang::Fun_0_2<FMGL(V), FMGL(V), x10_boolean> > cmp);
    virtual FMGL(V) getOrThrow(FMGL(K) k);
    virtual x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> >
      getEntry(
      FMGL(K) k);
    virtual x10_boolean containsKey(FMGL(K) k);
    virtual x10aux::ref<x10::util::Set<FMGL(K)> > keySet(
      );
    virtual x10aux::ref<x10::util::Set<x10aux::ref<x10::util::ValMap__Entry<FMGL(K), FMGL(V)> > > >
      entries(
      );
    virtual x10_int size();
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >
      entriesIterator(
      );
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ValHashMap<void, void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    template<class FMGL(Key), class FMGL(Value)>
    static x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> >
      make(
      x10aux::ref<x10::util::Map<FMGL(Key), FMGL(Value)> > map);
    
    template<class FMGL(Key), class FMGL(Value)>
    static x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> >
      make(
      x10aux::ref<x10::util::HashMap<FMGL(Key), FMGL(Value)> > map);
    
    template<class FMGL(T)>
    static x10_int
      hash(
      FMGL(T) k);
    
    
};

} } 
#endif // X10_UTIL_VALHASHMAP_H

namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)>
class ValHashMap;
} } 

#ifndef X10_UTIL_VALHASHMAP_H_NODEPS
#define X10_UTIL_VALHASHMAP_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/ValMap.h>
#include <x10/util/Map.h>
#include <x10/util/HashMap.h>
#include <x10/lang/Iterable.h>
#include <x10/util/Map__Entry.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterable.h>
#include <x10/lang/Iterable.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Iterator.h>
#include <x10/util/Map__Entry.h>
#include <x10/util/HashMap.h>
#include <x10/lang/ValRail.h>
#include <x10/util/ValHashMap__HashEntry.h>
#include <x10/util/HashMap.h>
#include <x10/lang/Rail.h>
#include <x10/util/HashMap__HashEntry.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Int.h>
#include <x10/util/Box.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Iterator.h>
#include <x10/util/NoSuchElementException.h>
#include <x10/util/ValHashMap__HashEntry.h>
#include <x10/util/Set.h>
#include <x10/util/ValHashMap__KeySet.h>
#include <x10/util/Set.h>
#include <x10/util/ValMap__Entry.h>
#include <x10/util/ValHashMap__EntrySet.h>
#include <x10/lang/Iterator.h>
#include <x10/util/ValHashMap__EntriesIterator.h>
#ifndef X10_UTIL_VALHASHMAP__CLOSURE__0_CLOSURE
#define X10_UTIL_VALHASHMAP__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(K), class FMGL(V)> class x10_util_ValHashMap__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >::template itable <x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > apply(x10_int index) {
        
        //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > entry =
          (t)->apply(index);
        
        //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > res =
          x10aux::class_cast_unchecked<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
        
        //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(entry, x10aux::null))) {
            
            //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
            res = x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)>::_make(x10aux::placeCheck(x10aux::nullCheck(entry))->getKey(),
                                                                            x10aux::placeCheck(x10aux::nullCheck(entry))->getValue());
        }
        
        //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return res;
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > t;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->t);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > that_t = buf.read<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > >();
        x10aux::ref<x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) > > this_ = new (x10aux::alloc<x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) > >()) x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >(that_t);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_util_ValHashMap__closure__0(x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > t) : t(t) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10:47-52";
    }

};

template<class FMGL(K), class FMGL(V)> typename x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >::template itable <x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) > >x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::_itable(&x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::toString, &x10::lang::Closure::typeName);template<class FMGL(K), class FMGL(V)>
x10aux::itable_entry x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >, &x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(K), class FMGL(V)>
const x10aux::serialization_id_t x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) >::template _deserialize<x10::lang::Object>);

#endif // X10_UTIL_VALHASHMAP__CLOSURE__0_CLOSURE
#ifndef X10_UTIL_VALHASHMAP_H_GENERICS
#define X10_UTIL_VALHASHMAP_H_GENERICS
template<class FMGL(K), class FMGL(V)> template<class __T> x10aux::ref<__T> x10::util::ValHashMap<FMGL(K), FMGL(V)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> > this_ = new (x10aux::alloc_remote<x10::util::ValHashMap<FMGL(K), FMGL(V)> >()) x10::util::ValHashMap<FMGL(K), FMGL(V)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_VALHASHMAP_H_GENERICS
#ifndef X10_UTIL_VALHASHMAP_H_IMPLEMENTATION
#define X10_UTIL_VALHASHMAP_H_IMPLEMENTATION
#include <x10/util/ValHashMap.h>


#include "x10/util/ValHashMap.inc"

template<class FMGL(K), class FMGL(V)> typename x10::util::ValMap<FMGL(K), FMGL(V)>::template itable<x10::util::ValHashMap<FMGL(K), FMGL(V)> >  x10::util::ValHashMap<FMGL(K), FMGL(V)>::_itable_0(&x10::util::ValHashMap<FMGL(K), FMGL(V)>::at, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::at, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::containsKey, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::entries, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::equals, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::get, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::getOrElse, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::getOrThrow, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::hashCode, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::home, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::keySet, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::toString, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::typeName);
template<class FMGL(K), class FMGL(V)> x10::lang::Any::itable<x10::util::ValHashMap<FMGL(K), FMGL(V)> >  x10::util::ValHashMap<FMGL(K), FMGL(V)>::_itable_1(&x10::util::ValHashMap<FMGL(K), FMGL(V)>::at, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::at, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::equals, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::hashCode, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::home, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::toString, &x10::util::ValHashMap<FMGL(K), FMGL(V)>::typeName);
template<class FMGL(K), class FMGL(V)> x10aux::itable_entry x10::util::ValHashMap<FMGL(K), FMGL(V)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::ValMap<FMGL(K), FMGL(V)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ValHashMap<FMGL(K), FMGL(V)> >())};
template<class FMGL(K), class FMGL(V)> void x10::util::ValHashMap<FMGL(K), FMGL(V)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ValHashMap<FMGL(K), FMGL(V)>");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(K), class FMGL(V)> void x10::util::ValHashMap<FMGL(K), FMGL(V)>::_constructor(
                                         x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > map)
{
    this->x10::lang::Object::_constructor();
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > t =
      x10aux::placeCheck(x10aux::nullCheck(map))->
        FMGL(table);
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(table) =
      x10::lang::ValRail<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >::make(x10aux::nullCheck(t)->
                                                                                                    FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >(x10aux::ref<x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >(sizeof(x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V)>)))x10_util_ValHashMap__closure__0<FMGL(K),FMGL(V)>(t)))));
    
}
template<class FMGL(K), class FMGL(V)>
x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> > x10::util::ValHashMap<FMGL(K), FMGL(V)>::_make(
  x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > map)
{
    x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> > this_ = new (memset(x10aux::alloc<x10::util::ValHashMap<FMGL(K), FMGL(V)> >(), 0, sizeof(x10::util::ValHashMap<FMGL(K), FMGL(V)>))) x10::util::ValHashMap<FMGL(K), FMGL(V)>();
    this_->_constructor(map);
    return this_;
}



//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::apply(
  FMGL(K) k) {
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->get(
             k);
    
}

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::get(
  FMGL(K) k) {
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)))
    {
        
        //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(V)> > >(x10aux::null);
        
    }
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10::util::Box<void>::template __implicit_convert<FMGL(V) >(
             x10aux::nullCheck(e)->
               FMGL(value));
    
}

//#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> FMGL(V)
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::getOrElse(
  FMGL(K) k,
  FMGL(V) orelse) {
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)))
    {
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return orelse;
        
    }
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(e)->FMGL(value);
    
}

//#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> FMGL(K)
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::findMax(
  FMGL(K) index,
  FMGL(V) max,
  x10aux::ref<x10::lang::Fun_0_2<FMGL(V), FMGL(V), x10_boolean> > cmp) {
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<FMGL(K)> > key1924;
        for (
             //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
             key1924 = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->keySet());
                       (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Set<FMGL(K)> >(_->_getITables())->iterator))(); }));
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(key1924))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(K)> >(((x10aux::ref<x10::lang::Reference>)key1924)->_getITables())->hasNext))();
             ) {
            
            //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
            FMGL(K) key = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(key1924))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(K)> >(((x10aux::ref<x10::lang::Reference>)key1924)->_getITables())->next))();
            
            //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
            FMGL(V) count = x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->apply(
                                                key))->x10::util::Box<FMGL(V)>::apply();
            
            //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
            if ((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(cmp))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(V), FMGL(V), x10_boolean> >(((x10aux::ref<x10::lang::Reference>)cmp)->_getITables())->apply))(
                  count,
                  max)) {
                
                //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
                max = count;
                
                //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
                index = key;
            }
            
        }
    }
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return index;
    
}

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> FMGL(V)
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::getOrThrow(
  FMGL(K) k) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)))
    {
        
        //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::util::NoSuchElementException::_make(x10::lang::String::Lit("Not found"))));
    }
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(e)->FMGL(value);
    
}

//#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::getEntry(
  FMGL(K) k) {
    
    //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10_int size = x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->
                                       FMGL(table))->
                     FMGL(length);
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10_int mask = ((x10_int) ((size) - (((x10_int)1))));
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(size, ((x10_int)0))))
    {
        
        //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
        
    }
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10_int h = x10::util::ValHashMap<void, void>::template hash<FMGL(K) >(
                  k);
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10_int i = h;
    
    //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
        x10_int j = ((x10_int) ((i) & (mask)));
        
        //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
        i = ((x10_int) ((i) + (((x10_int)1))));
        
        //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > e =
          (((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->
             FMGL(table))->apply(j);
        
        //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(e, x10aux::null)))
        {
            
            //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
            return x10aux::class_cast_unchecked<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
            
        }
        
        //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(e, x10aux::null)))
        {
            
            //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->
                                         FMGL(hash),
                                       h)) &&
                x10aux::equals(k,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(e)->
                                                                                              FMGL(key))))
            {
                
                //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
                return e;
                
            }
            
            //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
            if (((((x10_int) ((i) - (h)))) > (x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->
                                                                  FMGL(table))->
                                                FMGL(length))))
            {
                
                //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
                return x10aux::class_cast_unchecked<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
                
            }
            
        }
        
    }
    
}

//#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10_boolean
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::containsKey(
  FMGL(K) k) {
    
    //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return (!x10aux::struct_equals(e, x10aux::null));
    
}

//#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Set<FMGL(K)> >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::keySet(
  ) {
    
    //#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Set<FMGL(K)> > >(x10::util::ValHashMap__KeySet<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)));
    
}

//#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Set<x10aux::ref<x10::util::ValMap__Entry<FMGL(K), FMGL(V)> > > >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::entries(
  ) {
    
    //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Set<x10aux::ref<x10::util::ValMap__Entry<FMGL(K), FMGL(V)> > > > >(x10::util::ValHashMap__EntrySet<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)));
    
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10_int
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::size(
  ) {
    
    //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this)->
                               FMGL(table))->
             FMGL(length);
    
}

//#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > >
  x10::util::ValHashMap<FMGL(K), FMGL(V)>::entriesIterator(
  ) {
    
    //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(K), FMGL(V)> > iterator =
      x10::util::ValHashMap__EntriesIterator<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::ValHashMap<FMGL(K), FMGL(V)> >)this));
    
    //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    iterator->advance();
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > > >(iterator);
    
}
template<class FMGL(K), class FMGL(V)> const x10aux::serialization_id_t x10::util::ValHashMap<FMGL(K), FMGL(V)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ValHashMap<FMGL(K), FMGL(V)>::template _deserializer<x10::lang::Object>);

template<class FMGL(K), class FMGL(V)> void x10::util::ValHashMap<FMGL(K), FMGL(V)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(table));
    
}

template<class FMGL(K), class FMGL(V)> void x10::util::ValHashMap<FMGL(K), FMGL(V)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(table) = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(K), FMGL(V)> > > > >();
}

template<class FMGL(K), class FMGL(V)> x10aux::RuntimeType x10::util::ValHashMap<FMGL(K), FMGL(V)>::rtt;
template<class FMGL(K), class FMGL(V)> void x10::util::ValHashMap<FMGL(K), FMGL(V)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ValHashMap<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::ValMap<FMGL(K), FMGL(V)> >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(K)>(), x10aux::getRTT<FMGL(V)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ValHashMap";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> >
  x10::util::ValHashMap<void, void>::make(x10aux::ref<x10::util::Map<FMGL(Key), FMGL(Value)> > map)
{
    
    //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap<FMGL(Key), FMGL(Value)> > hashMap =
      x10::util::HashMap<FMGL(Key), FMGL(Value)>::_make();
    
    //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Iterable<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > > entries =
      (__extension__ ({
        x10aux::ref<x10::lang::Iterable<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > > __desugarer__var__82__ =
          x10aux::class_cast<x10aux::ref<x10::lang::Iterable<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > > >((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(map)).operator->()))->*(x10aux::findITable<x10::util::Map<FMGL(Key), FMGL(Value)> >(((x10aux::ref<x10::lang::Reference>)map)->_getITables())->entries))());
        
        //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Iterable<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > > __var1279__;
        
        //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Labeled_c
        goto __ret2011; __ret2011: 
        //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
            if (!((x10aux::struct_equals(x10::lang::Place_methods::place(x10aux::get_location(__desugarer__var__82__)),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Iterable[x10.util.Map$Entry[Key, Value]{self.home==_place11088}]{self.home==_place11088}"))));
            }
            
            //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
            __var1279__ =
              __desugarer__var__82__;
            
            //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Branch_c
            goto __ret2011_end_;
        }
        goto __ret2011_next_; __ret2011_next_: ;
        }
        while (false);
        goto __ret2011_end_; __ret2011_end_: ;
        __var1279__;
    }))
    ;
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > > entry1923;
        for (
             //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
             entry1923 =
               (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(entries)).operator->()))->*(x10aux::findITable<x10::lang::Iterable<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > >(((x10aux::ref<x10::lang::Reference>)entries)->_getITables())->iterator))();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(entry1923))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > >(((x10aux::ref<x10::lang::Reference>)entry1923)->_getITables())->hasNext))();
             )
        {
            
            //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > entry =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(entry1923))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> > > >(((x10aux::ref<x10::lang::Reference>)entry1923)->_getITables())->next))();
            
            //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(entry,
                                        x10aux::null)))
            {
                
                //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(hashMap)->put(
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(entry)).operator->()))->*(x10aux::findITable<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> >(((x10aux::ref<x10::lang::Reference>)entry)->_getITables())->getKey))(),
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(entry)).operator->()))->*(x10aux::findITable<x10::util::Map__Entry<FMGL(Key), FMGL(Value)> >(((x10aux::ref<x10::lang::Reference>)entry)->_getITables())->getValue))());
            }
            
        }
    }
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10::util::ValHashMap<void, void>::template make<FMGL(Key),
           FMGL(Value) >(
             hashMap);
    
}
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> >
  x10::util::ValHashMap<void, void>::make(x10aux::ref<x10::util::HashMap<FMGL(Key), FMGL(Value)> > map)
{
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return x10::util::ValHashMap<FMGL(Key), FMGL(Value)>::_make(map);
    
}
template<class FMGL(T)>
x10_int
  x10::util::ValHashMap<void, void>::hash(FMGL(T) k)
{
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return ((x10_int) ((x10aux::hash_code(k)) * (((x10_int)17))));
    
}
#endif // X10_UTIL_VALHASHMAP_H_IMPLEMENTATION
#endif // __X10_UTIL_VALHASHMAP_H_NODEPS
