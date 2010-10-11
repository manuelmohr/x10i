#ifndef __X10_UTIL_MAPITERATOR_H
#define __X10_UTIL_MAPITERATOR_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 

template<class FMGL(S), class FMGL(T)> class MapIterator;
template <> class MapIterator<void, void>;
template<class FMGL(S), class FMGL(T)> class MapIterator : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Iterator<FMGL(T)>::template itable<x10::util::MapIterator<FMGL(S), FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::MapIterator<FMGL(S), FMGL(T)> > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Iterator<FMGL(S)> > FMGL(i);
    
    x10aux::ref<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> > FMGL(f);
    
    void _constructor(x10aux::ref<x10::lang::Iterator<FMGL(S)> > i,
                      x10aux::ref<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> > f);
    
    static x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> > _make(
             x10aux::ref<x10::lang::Iterator<FMGL(S)> > i,
             x10aux::ref<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> > f);
    
    virtual x10_boolean hasNext();
    virtual FMGL(T) next();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class MapIterator<void, void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_MAPITERATOR_H

namespace x10 { namespace util { 
template<class FMGL(S), class FMGL(T)>
class MapIterator;
} } 

#ifndef X10_UTIL_MAPITERATOR_H_NODEPS
#define X10_UTIL_MAPITERATOR_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Boolean.h>
#ifndef X10_UTIL_MAPITERATOR_H_GENERICS
#define X10_UTIL_MAPITERATOR_H_GENERICS
template<class FMGL(S), class FMGL(T)> template<class __T> x10aux::ref<__T> x10::util::MapIterator<FMGL(S), FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::util::MapIterator<FMGL(S), FMGL(T)> >()) x10::util::MapIterator<FMGL(S), FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_MAPITERATOR_H_GENERICS
#ifndef X10_UTIL_MAPITERATOR_H_IMPLEMENTATION
#define X10_UTIL_MAPITERATOR_H_IMPLEMENTATION
#include <x10/util/MapIterator.h>


#include "x10/util/MapIterator.inc"

template<class FMGL(S), class FMGL(T)> typename x10::lang::Iterator<FMGL(T)>::template itable<x10::util::MapIterator<FMGL(S), FMGL(T)> >  x10::util::MapIterator<FMGL(S), FMGL(T)>::_itable_0(&x10::util::MapIterator<FMGL(S), FMGL(T)>::at, &x10::util::MapIterator<FMGL(S), FMGL(T)>::at, &x10::util::MapIterator<FMGL(S), FMGL(T)>::equals, &x10::util::MapIterator<FMGL(S), FMGL(T)>::hasNext, &x10::util::MapIterator<FMGL(S), FMGL(T)>::hashCode, &x10::util::MapIterator<FMGL(S), FMGL(T)>::home, &x10::util::MapIterator<FMGL(S), FMGL(T)>::next, &x10::util::MapIterator<FMGL(S), FMGL(T)>::toString, &x10::util::MapIterator<FMGL(S), FMGL(T)>::typeName);
template<class FMGL(S), class FMGL(T)> x10::lang::Any::itable<x10::util::MapIterator<FMGL(S), FMGL(T)> >  x10::util::MapIterator<FMGL(S), FMGL(T)>::_itable_1(&x10::util::MapIterator<FMGL(S), FMGL(T)>::at, &x10::util::MapIterator<FMGL(S), FMGL(T)>::at, &x10::util::MapIterator<FMGL(S), FMGL(T)>::equals, &x10::util::MapIterator<FMGL(S), FMGL(T)>::hashCode, &x10::util::MapIterator<FMGL(S), FMGL(T)>::home, &x10::util::MapIterator<FMGL(S), FMGL(T)>::toString, &x10::util::MapIterator<FMGL(S), FMGL(T)>::typeName);
template<class FMGL(S), class FMGL(T)> x10aux::itable_entry x10::util::MapIterator<FMGL(S), FMGL(T)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::MapIterator<FMGL(S), FMGL(T)> >())};
template<class FMGL(S), class FMGL(T)> void x10::util::MapIterator<FMGL(S), FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::MapIterator<FMGL(S), FMGL(T)>");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10FieldDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10FieldDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(S), class FMGL(T)> void x10::util::MapIterator<FMGL(S), FMGL(T)>::_constructor(
                                         x10aux::ref<x10::lang::Iterator<FMGL(S)> > i,
                                         x10aux::ref<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> > f)
{
    this->x10::lang::Object::_constructor();
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> >)this))->
      FMGL(i) =
      i;
    
    //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> >)this))->
      FMGL(f) =
      f;
    
}
template<class FMGL(S), class FMGL(T)>
x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> > x10::util::MapIterator<FMGL(S), FMGL(T)>::_make(
  x10aux::ref<x10::lang::Iterator<FMGL(S)> > i,
  x10aux::ref<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> > f)
{
    x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::util::MapIterator<FMGL(S), FMGL(T)> >(), 0, sizeof(x10::util::MapIterator<FMGL(S), FMGL(T)>))) x10::util::MapIterator<FMGL(S), FMGL(T)>();
    this_->_constructor(i,
    f);
    return this_;
}



//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S), class FMGL(T)> x10_boolean
  x10::util::MapIterator<FMGL(S), FMGL(T)>::hasNext(
  ) {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10Return_c
    return (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> >)this)->
                                                                                       FMGL(i));
           (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(S)> >(_->_getITables())->hasNext))(); }));
    
}

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S), class FMGL(T)> FMGL(T)
  x10::util::MapIterator<FMGL(S), FMGL(T)>::next(
  ) {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/MapIterator.x10": x10.ast.X10Return_c
    return (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::placeCheck(x10aux::nullCheck(((x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> >)this)->
                                                                                                          FMGL(f)));
    (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<FMGL(S), FMGL(T)> >(_->_getITables())->apply))(
      (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::util::MapIterator<FMGL(S), FMGL(T)> >)this)->
                                                                                  FMGL(i));
      (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(S)> >(_->_getITables())->next))(); }))); }));
    
}
template<class FMGL(S), class FMGL(T)> const x10aux::serialization_id_t x10::util::MapIterator<FMGL(S), FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::MapIterator<FMGL(S), FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(S), class FMGL(T)> void x10::util::MapIterator<FMGL(S), FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(S), class FMGL(T)> void x10::util::MapIterator<FMGL(S), FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(S), class FMGL(T)> x10aux::RuntimeType x10::util::MapIterator<FMGL(S), FMGL(T)>::rtt;
template<class FMGL(S), class FMGL(T)> void x10::util::MapIterator<FMGL(S), FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::MapIterator<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<FMGL(T)> >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(S)>(), x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::contravariant, x10aux::RuntimeType::covariant};
    const char *baseName = "x10.util.MapIterator";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
#endif // X10_UTIL_MAPITERATOR_H_IMPLEMENTATION
#endif // __X10_UTIL_MAPITERATOR_H_NODEPS
