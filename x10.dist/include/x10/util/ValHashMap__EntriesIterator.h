#ifndef __X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H
#define __X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry;
} } 
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class ValHashMap;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace util { 

template<class FMGL(Key), class FMGL(Value)> class ValHashMap__EntriesIterator;
template <> class ValHashMap__EntriesIterator<void, void>;
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__EntriesIterator : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > >::template itable<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > FMGL(map);
    
    x10_int FMGL(i);
    
    void _constructor(x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map);
    
    static x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > _make(
             x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map);
    
    virtual void advance();
    virtual x10_boolean hasNext();
    virtual x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >
      next(
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
template <> class ValHashMap__EntriesIterator<void, void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H

namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)>
class ValHashMap__EntriesIterator;
} } 

#ifndef X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_NODEPS
#define X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/util/ValHashMap__HashEntry.h>
#include <x10/util/ValHashMap.h>
#include <x10/lang/Int.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_2.h>
#ifndef X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_GENERICS
#define X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_GENERICS
template<class FMGL(Key), class FMGL(Value)> template<class __T> x10aux::ref<__T> x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > this_ = new (x10aux::alloc_remote<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >()) x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_GENERICS
#ifndef X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_IMPLEMENTATION
#define X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_IMPLEMENTATION
#include <x10/util/ValHashMap__EntriesIterator.h>


#include "x10/util/ValHashMap__EntriesIterator.inc"

template<class FMGL(Key), class FMGL(Value)> typename x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > >::template itable<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_itable_0(&x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::hasNext, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::next, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10::lang::Any::itable<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_itable_1(&x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10aux::itable_entry x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >())};
template<class FMGL(Key), class FMGL(Value)> void x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>");
    
}


//#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(Key), class FMGL(Value)> void x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_constructor(
                                               x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map)
{
    this->x10::lang::Object::_constructor();
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this))->
      FMGL(i) =
      ((x10_int)0);
    
    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this))->
      FMGL(map) =
      map;
    
    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this))->
      FMGL(i) =
      ((x10_int)0);
    
}
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_make(
  x10aux::ref<x10::util::ValHashMap<FMGL(Key), FMGL(Value)> > map)
{
    x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > this_ = new (memset(x10aux::alloc<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >(), 0, sizeof(x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>))) x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>();
    this_->_constructor(map);
    return this_;
}



//#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
void
  x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::advance(
  ) {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10While_c
    while (((((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
               FMGL(i)) < (x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                                                                 FMGL(map))->
                                               FMGL(table))->
                             FMGL(length))))
    {
        
        //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals((x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                                                         FMGL(map))->
                                       FMGL(table))->apply(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                                                             FMGL(i)),
                                    x10aux::null)))
        {
            
            //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
            return;
        }
        
        //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > x =
              ((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this);
            x10_int y =
              ((x10_int)1);
            x10aux::nullCheck(x)->
              FMGL(i) =
              ((x10_int) ((x10aux::nullCheck(x)->
                             FMGL(i)) + (y)));
        }))
        ;
    }
    
}

//#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10_boolean
  x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::hasNext(
  ) {
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10If_c
    if (((((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
            FMGL(i)) < (x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                                                              FMGL(map))->
                                            FMGL(table))->
                          FMGL(length))))
    {
        
        //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
        return true;
        
    }
    
    //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >
  x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::next(
  ) {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10LocalDecl_c
    x10_int j = ((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                  FMGL(i);
    
    //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> > x =
          ((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(i) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(i)) + (y)));
    }))
    ;
    
    //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->advance();
    
    //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return (x10aux::nullCheck(((x10aux::ref<x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)> >)this)->
                                FMGL(map))->
              FMGL(table))->apply(j);
    
}
template<class FMGL(Key), class FMGL(Value)>
const x10aux::serialization_id_t x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::template _deserializer<x10::lang::Object>);

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(Key), class FMGL(Value)>
x10aux::RuntimeType x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::rtt;
template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__EntriesIterator<FMGL(Key), FMGL(Value)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ValHashMap__EntriesIterator<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > > >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(Key)>(), x10aux::getRTT<FMGL(Value)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ValHashMap$EntriesIterator";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
#endif // X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_IMPLEMENTATION
#endif // __X10_UTIL_VALHASHMAP__ENTRIESITERATOR_H_NODEPS
