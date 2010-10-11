#ifndef __X10_UTIL_HASHMAP_H
#define __X10_UTIL_HASHMAP_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_UTIL_MAP_H_NODEPS
#include <x10/util/Map.h>
#undef X10_UTIL_MAP_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__HashEntry;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace util { 
class NoSuchElementException;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__HashEntry;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__HashEntry;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__KeySet;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Val)> class Map__Entry;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__EntrySet;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class HashMap__EntriesIterator;
} } 
namespace x10 { namespace util { 

template<class FMGL(K), class FMGL(V)> class HashMap;
template <> class HashMap<void, void>;
template<class FMGL(K), class FMGL(V)> class HashMap : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::Map<FMGL(K), FMGL(V)>::template itable<x10::util::HashMap<FMGL(K), FMGL(V)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::HashMap<FMGL(K), FMGL(V)> > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > >
      FMGL(table);
    
    x10_int FMGL(size);
    
    x10_int FMGL(occupation);
    
    x10_int FMGL(mask);
    
    x10_int FMGL(modCount);
    
    x10_boolean FMGL(shouldRehash);
    
    void _constructor();
    
    static x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > _make(
             );
    
    void _constructor(x10_int sz);
    
    static x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > _make(
             x10_int sz);
    
    virtual void init(x10_int sz);
    virtual void clear();
    virtual x10_int hash(FMGL(K) k);
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > apply(FMGL(K) k);
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > get(FMGL(K) k);
    virtual FMGL(V) getOrElse(FMGL(K) k, FMGL(V) orelse);
    virtual FMGL(V) getOrThrow(FMGL(K) k);
    virtual x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> >
      getEntry(
      FMGL(K) k);
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > put(FMGL(K) k, FMGL(V) v);
    virtual void rehash();
    virtual x10_boolean containsKey(FMGL(K) k);
    virtual x10aux::ref<x10::util::Box<FMGL(V)> > remove(FMGL(K) k);
    virtual x10aux::ref<x10::util::Set<FMGL(K)> > keySet();
    virtual x10aux::ref<x10::util::Set<x10aux::ref<x10::util::Map__Entry<FMGL(K), FMGL(V)> > > >
      entries(
      );
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > >
      entriesIterator(
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
template <> class HashMap<void, void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    static x10_int
      FMGL(MAX_PROBES);
    
    static x10_int
      FMGL(MIN_SIZE);
    
    static inline x10_int
      FMGL(MAX_PROBES__get)() {
        return x10::util::HashMap<void, void>::FMGL(MAX_PROBES);
    }
    static inline x10_int
      FMGL(MIN_SIZE__get)() {
        return x10::util::HashMap<void, void>::FMGL(MIN_SIZE);
    }
    
};

} } 
#endif // X10_UTIL_HASHMAP_H

namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)>
class HashMap;
} } 

#ifndef X10_UTIL_HASHMAP_H_NODEPS
#define X10_UTIL_HASHMAP_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Map.h>
#include <x10/lang/Rail.h>
#include <x10/util/HashMap__HashEntry.h>
#include <x10/lang/Int.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/util/Box.h>
#include <x10/util/NoSuchElementException.h>
#include <x10/util/HashMap__HashEntry.h>
#include <x10/util/HashMap__HashEntry.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/util/Set.h>
#include <x10/util/HashMap__KeySet.h>
#include <x10/util/Set.h>
#include <x10/util/Map__Entry.h>
#include <x10/util/HashMap__EntrySet.h>
#include <x10/lang/Iterator.h>
#include <x10/util/HashMap__EntriesIterator.h>
#ifndef X10_UTIL_HASHMAP_H_GENERICS
#define X10_UTIL_HASHMAP_H_GENERICS
template<class FMGL(K), class FMGL(V)> template<class __T> x10aux::ref<__T> x10::util::HashMap<FMGL(K), FMGL(V)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > this_ = new (x10aux::alloc_remote<x10::util::HashMap<FMGL(K), FMGL(V)> >()) x10::util::HashMap<FMGL(K), FMGL(V)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_HASHMAP_H_GENERICS
#ifndef X10_UTIL_HASHMAP_H_IMPLEMENTATION
#define X10_UTIL_HASHMAP_H_IMPLEMENTATION
#include <x10/util/HashMap.h>


#include "x10/util/HashMap.inc"

template<class FMGL(K), class FMGL(V)> typename x10::util::Map<FMGL(K), FMGL(V)>::template itable<x10::util::HashMap<FMGL(K), FMGL(V)> >  x10::util::HashMap<FMGL(K), FMGL(V)>::_itable_0(&x10::util::HashMap<FMGL(K), FMGL(V)>::at, &x10::util::HashMap<FMGL(K), FMGL(V)>::at, &x10::util::HashMap<FMGL(K), FMGL(V)>::clear, &x10::util::HashMap<FMGL(K), FMGL(V)>::containsKey, &x10::util::HashMap<FMGL(K), FMGL(V)>::entries, &x10::util::HashMap<FMGL(K), FMGL(V)>::equals, &x10::util::HashMap<FMGL(K), FMGL(V)>::get, &x10::util::HashMap<FMGL(K), FMGL(V)>::getOrElse, &x10::util::HashMap<FMGL(K), FMGL(V)>::getOrThrow, &x10::util::HashMap<FMGL(K), FMGL(V)>::hashCode, &x10::util::HashMap<FMGL(K), FMGL(V)>::home, &x10::util::HashMap<FMGL(K), FMGL(V)>::keySet, &x10::util::HashMap<FMGL(K), FMGL(V)>::put, &x10::util::HashMap<FMGL(K), FMGL(V)>::remove, &x10::util::HashMap<FMGL(K), FMGL(V)>::toString, &x10::util::HashMap<FMGL(K), FMGL(V)>::typeName);
template<class FMGL(K), class FMGL(V)> x10::lang::Any::itable<x10::util::HashMap<FMGL(K), FMGL(V)> >  x10::util::HashMap<FMGL(K), FMGL(V)>::_itable_1(&x10::util::HashMap<FMGL(K), FMGL(V)>::at, &x10::util::HashMap<FMGL(K), FMGL(V)>::at, &x10::util::HashMap<FMGL(K), FMGL(V)>::equals, &x10::util::HashMap<FMGL(K), FMGL(V)>::hashCode, &x10::util::HashMap<FMGL(K), FMGL(V)>::home, &x10::util::HashMap<FMGL(K), FMGL(V)>::toString, &x10::util::HashMap<FMGL(K), FMGL(V)>::typeName);
template<class FMGL(K), class FMGL(V)> x10aux::itable_entry x10::util::HashMap<FMGL(K), FMGL(V)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Map<FMGL(K), FMGL(V)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::HashMap<FMGL(K), FMGL(V)> >())};
template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::HashMap<FMGL(K), FMGL(V)>");
    
}


//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
/** The actual table, must be of size 2**n */
                                             //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                             /** Number of non-null, non-removed entries in the table. */
                                                                                                         //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                         /** Number of non-null entries in the table. */
                                                                                                                                                        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                        /** table.length - 1 */
                                                                                                                                                                               //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                               
                                                                                                                                                                               //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                               
                                                                                                                                                                               //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                               
                                                                                                                                                                               //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                               

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_constructor(
                                         ) {
    this->x10::lang::Object::_constructor();
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(table) = x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > >(x10aux::null);
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(size) = ((x10_int)0);
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(occupation) = ((x10_int)0);
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(mask) = ((x10_int)0);
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(modCount) = ((x10_int)0);
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(shouldRehash) = false;
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->init(
      x10::util::HashMap<void, void>::
        FMGL(MIN_SIZE__get)());
    
}
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x10::util::HashMap<FMGL(K), FMGL(V)>::_make(
                                         )
{
    x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > this_ = new (memset(x10aux::alloc<x10::util::HashMap<FMGL(K), FMGL(V)> >(), 0, sizeof(x10::util::HashMap<FMGL(K), FMGL(V)>))) x10::util::HashMap<FMGL(K), FMGL(V)>();
    this_->_constructor();
    return this_;
}



//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_constructor(
                                         x10_int sz)
{
    this->x10::lang::Object::_constructor();
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(table) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > >(x10aux::null);
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(size) =
      ((x10_int)0);
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(occupation) =
      ((x10_int)0);
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(mask) =
      ((x10_int)0);
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(modCount) =
      ((x10_int)0);
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->
      FMGL(shouldRehash) =
      false;
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int pow2 =
      x10::util::HashMap<void, void>::
        FMGL(MIN_SIZE__get)();
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10While_c
    while (((pow2) < (sz)))
    {
        
        //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        pow2 =
          ((x10_int) ((pow2) << (((x10_int)1))));
    }
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this))->init(
      pow2);
    
}
template<class FMGL(K), class FMGL(V)>
x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x10::util::HashMap<FMGL(K), FMGL(V)>::_make(
  x10_int sz)
{
    x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > this_ = new (memset(x10aux::alloc<x10::util::HashMap<FMGL(K), FMGL(V)> >(), 0, sizeof(x10::util::HashMap<FMGL(K), FMGL(V)>))) x10::util::HashMap<FMGL(K), FMGL(V)>();
    this_->_constructor(sz);
    return this_;
}



//#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> void
  x10::util::HashMap<FMGL(K), FMGL(V)>::init(
  x10_int sz) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert((x10aux::struct_equals((((x10_int) ((sz) & (((x10_int) -(sz)))))),
                                                   sz)));
    #endif//NO_ASSERTIONS
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert(((sz) >= (x10::util::HashMap<void, void>::
                                        FMGL(MIN_SIZE__get)())));
    #endif//NO_ASSERTIONS
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(table) = x10::lang::Rail<void>::make<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > >(sz);
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(mask) = ((x10_int) ((sz) - (((x10_int)1))));
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(size) = ((x10_int)0);
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(occupation) = ((x10_int)0);
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(shouldRehash) = false;
}

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> void
  x10::util::HashMap<FMGL(K), FMGL(V)>::clear(
  ) {
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
          ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(modCount) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(modCount)) + (y)));
    }))
    ;
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->init(
      x10::util::HashMap<void, void>::
        FMGL(MIN_SIZE__get)());
}

//#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10_int
  x10::util::HashMap<FMGL(K), FMGL(V)>::hash(
  FMGL(K) k) {
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return ((x10_int) ((x10aux::hash_code(k)) * (((x10_int)17))));
    
}

//#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::apply(
  FMGL(K) k) {
    
    //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->get(
             k);
    
}

//#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::get(
  FMGL(K) k) {
    
    //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)) ||
        x10aux::nullCheck(e)->
          FMGL(removed)) {
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(V)> > >(x10aux::null);
        
    }
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10::util::Box<void>::template __implicit_convert<FMGL(V) >(
             x10aux::nullCheck(e)->
               FMGL(value));
    
}

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> FMGL(V)
  x10::util::HashMap<FMGL(K), FMGL(V)>::getOrElse(
  FMGL(K) k,
  FMGL(V) orelse) {
    
    //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)) ||
        x10aux::nullCheck(e)->
          FMGL(removed)) {
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
        return orelse;
        
    }
    
    //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(e)->FMGL(value);
    
}

//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> FMGL(V)
  x10::util::HashMap<FMGL(K), FMGL(V)>::getOrThrow(
  FMGL(K) k) {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(e, x10aux::null)) ||
        x10aux::nullCheck(e)->
          FMGL(removed)) {
        
        //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::util::NoSuchElementException::_make(x10::lang::String::Lit("Not found"))));
    }
    
    //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(e)->FMGL(value);
    
}

//#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::getEntry(
  FMGL(K) k) {
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                 FMGL(size),
                               ((x10_int)0))))
    {
        
        //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
        
    }
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int h = ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->hash(
                  k);
    
    //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int i = h;
    
    //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
        x10_int j = ((x10_int) ((i) & (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                         FMGL(mask))));
        
        //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        i = ((x10_int) ((i) + (((x10_int)1))));
        
        //#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
          (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
             FMGL(table))->apply(j);
        
        //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(e, x10aux::null)))
        {
            
            //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if (((((x10_int) ((i) - (h)))) > (x10::util::HashMap<void, void>::
                                                FMGL(MAX_PROBES__get)())))
            {
                
                //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                  FMGL(shouldRehash) =
                  true;
            }
            
            //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
            return x10aux::class_cast_unchecked<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
            
        }
        
        //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(e, x10aux::null)))
        {
            
            //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->
                                         FMGL(hash),
                                       h)) &&
                x10aux::equals(k,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(e)->
                                                                                              FMGL(key))))
            {
                
                //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
                if (((((x10_int) ((i) - (h)))) > (x10::util::HashMap<void, void>::
                                                    FMGL(MAX_PROBES__get)())))
                {
                    
                    //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                      FMGL(shouldRehash) =
                      true;
                }
                
                //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
                return e;
                
            }
            
            //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if (((((x10_int) ((i) - (h)))) > (x10aux::nullCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                                                  FMGL(table))->
                                                FMGL(length))))
            {
                
                //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
                if (((((x10_int) ((i) - (h)))) > (x10::util::HashMap<void, void>::
                                                    FMGL(MAX_PROBES__get)())))
                {
                    
                    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                      FMGL(shouldRehash) =
                      true;
                }
                
                //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
                return x10aux::class_cast_unchecked<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > >(x10aux::null);
                
            }
            
        }
        
    }
    
}

//#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::put(
  FMGL(K) k,
  FMGL(V) v) {
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                 FMGL(occupation),
                               x10aux::nullCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                                   FMGL(table))->
                                 FMGL(length))) ||
        (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
           FMGL(shouldRehash) &&
         ((((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
             FMGL(occupation)) >= (((x10_int) ((x10aux::nullCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                                                    FMGL(table))->
                                                  FMGL(length)) / (((x10_int)2))))))))
    {
        
        //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->rehash();
    }
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int h = ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->hash(
                  k);
    
    //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int i = h;
    
    //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
        x10_int j = ((x10_int) ((i) & (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                         FMGL(mask))));
        
        //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        i = ((x10_int) ((i) + (((x10_int)1))));
        
        //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
          (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
             FMGL(table))->apply(j);
        
        //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(e, x10aux::null)))
        {
            
            //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if (((((x10_int) ((i) - (h)))) > (x10::util::HashMap<void, void>::
                                                FMGL(MAX_PROBES__get)())))
            {
                
                //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                  FMGL(shouldRehash) =
                  true;
            }
            
            //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
                  ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
                x10_int y =
                  ((x10_int)1);
                x10aux::nullCheck(x)->
                  FMGL(modCount) =
                  ((x10_int) ((x10aux::nullCheck(x)->
                                 FMGL(modCount)) + (y)));
            }))
            ;
            
            //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
               FMGL(table))->set(x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)>::_make(k,
                                                                                        v,
                                                                                        h), j);
            
            //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
                  ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
                x10_int y =
                  ((x10_int)1);
                x10aux::nullCheck(x)->
                  FMGL(size) =
                  ((x10_int) ((x10aux::nullCheck(x)->
                                 FMGL(size)) + (y)));
            }))
            ;
            
            //#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
                  ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
                x10_int y =
                  ((x10_int)1);
                x10aux::nullCheck(x)->
                  FMGL(occupation) =
                  ((x10_int) ((x10aux::nullCheck(x)->
                                 FMGL(occupation)) + (y)));
            }))
            ;
            
            //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
            return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(V)> > >(x10aux::null);
            
        }
        else
        
        //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(x10aux::nullCheck(e)->
                                     FMGL(hash),
                                   h)) &&
            x10aux::equals(k,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(e)->
                                                                                          FMGL(key))))
        {
            
            //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
            FMGL(V) old =
              x10aux::nullCheck(e)->
                FMGL(value);
            
            //#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(e)->
              FMGL(value) =
              v;
            
            //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if (x10aux::nullCheck(e)->
                  FMGL(removed))
            {
                
                //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(e)->
                  FMGL(removed) =
                  false;
                
                //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                (__extension__ ({
                    x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
                      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
                    x10_int y =
                      ((x10_int)1);
                    x10aux::nullCheck(x)->
                      FMGL(size) =
                      ((x10_int) ((x10aux::nullCheck(x)->
                                     FMGL(size)) + (y)));
                }))
                ;
                
                //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
                return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(V)> > >(x10aux::null);
                
            }
            
            //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
            return x10::util::Box<void>::template __implicit_convert<FMGL(V) >(
                     old);
            
        }
        
    }
    
}

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> void
  x10::util::HashMap<FMGL(K), FMGL(V)>::rehash(
  ) {
    
    //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
          ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(modCount) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(modCount)) + (y)));
    }))
    ;
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > t =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
        FMGL(table);
    
    //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10_int oldSize = ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                        FMGL(size);
    
    //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(table) = x10::lang::Rail<void>::make<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > >(((x10_int) ((x10aux::nullCheck(t)->
                                                                                                                               FMGL(length)) * (((x10_int)2)))));
    
    //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(mask) = ((x10_int) ((x10aux::nullCheck(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                                    FMGL(table))->
                                  FMGL(length)) - (((x10_int)1))));
    
    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(size) = ((x10_int)0);
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(occupation) = ((x10_int)0);
    
    //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(shouldRehash) = false;
    
    //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(t)->
                                         FMGL(length)));
             
             //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((t)->apply(i),
                                        x10aux::null)) &&
                (!(x10aux::nullCheck((t)->apply(i))->
                     FMGL(removed))))
            {
                
                //#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->put(
                  x10aux::nullCheck((t)->apply(i))->
                    FMGL(key),
                  x10aux::nullCheck((t)->apply(i))->
                    FMGL(value));
                
                //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                  FMGL(shouldRehash) =
                  false;
            }
            
        }
    }
    
    //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert((x10aux::struct_equals(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
                                                     FMGL(size),
                                                   oldSize)));
    #endif//NO_ASSERTIONS
    
    //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
      FMGL(size) = oldSize;
}

//#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10_boolean
  x10::util::HashMap<FMGL(K), FMGL(V)>::containsKey(
  FMGL(K) k) {
    
    //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return (!x10aux::struct_equals(e, x10aux::null)) &&
    (!(x10aux::nullCheck(e)->
         FMGL(removed)));
    
}

//#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Box<FMGL(V)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::remove(
  FMGL(K) k) {
    
    //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
          ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(modCount) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(modCount)) + (y)));
    }))
    ;
    
    //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > e =
      ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->getEntry(
        k);
    
    //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(e, x10aux::null)) &&
        (!(x10aux::nullCheck(e)->
             FMGL(removed)))) {
        
        //#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> > x =
              ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this);
            x10_int y =
              ((x10_int)1);
            x10aux::nullCheck(x)->
              FMGL(size) =
              ((x10_int) ((x10aux::nullCheck(x)->
                             FMGL(size)) - (y)));
        }))
        ;
        
        //#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(e)->FMGL(removed) =
          true;
        
        //#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
        return x10::util::Box<void>::template __implicit_convert<FMGL(V) >(
                 x10aux::nullCheck(e)->
                   FMGL(value));
        
    }
    
    //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(V)> > >(x10aux::null);
    
}

//#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Set<FMGL(K)> >
  x10::util::HashMap<FMGL(K), FMGL(V)>::keySet(
  ) {
    
    //#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Set<FMGL(K)> > >(x10::util::HashMap__KeySet<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)));
    
}

//#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::util::Set<x10aux::ref<x10::util::Map__Entry<FMGL(K), FMGL(V)> > > >
  x10::util::HashMap<FMGL(K), FMGL(V)>::entries(
  ) {
    
    //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::Set<x10aux::ref<x10::util::Map__Entry<FMGL(K), FMGL(V)> > > > >(x10::util::HashMap__EntrySet<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)));
    
}

//#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > >
  x10::util::HashMap<FMGL(K), FMGL(V)>::entriesIterator(
  ) {
    
    //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::HashMap__EntriesIterator<FMGL(K), FMGL(V)> > iterator =
      x10::util::HashMap__EntriesIterator<FMGL(K), FMGL(V)>::_make(((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this));
    
    //#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": polyglot.ast.Eval_c
    iterator->advance();
    
    //#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::util::HashMap__HashEntry<FMGL(K), FMGL(V)> > > > >(iterator);
    
}

//#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(K), class FMGL(V)> x10_int
  x10::util::HashMap<FMGL(K), FMGL(V)>::size(
  ) {
    
    //#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashMap.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::HashMap<FMGL(K), FMGL(V)> >)this)->
             FMGL(size);
    
}
template<class FMGL(K), class FMGL(V)> const x10aux::serialization_id_t x10::util::HashMap<FMGL(K), FMGL(V)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::HashMap<FMGL(K), FMGL(V)>::template _deserializer<x10::lang::Object>);

template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(K), class FMGL(V)> x10aux::RuntimeType x10::util::HashMap<FMGL(K), FMGL(V)>::rtt;
template<class FMGL(K), class FMGL(V)> void x10::util::HashMap<FMGL(K), FMGL(V)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::HashMap<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::Map<FMGL(K), FMGL(V)> >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(K)>(), x10aux::getRTT<FMGL(V)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.HashMap";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
#endif // X10_UTIL_HASHMAP_H_IMPLEMENTATION
#endif // __X10_UTIL_HASHMAP_H_NODEPS
