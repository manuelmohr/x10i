#ifndef __X10_LANG_VALRAIL__RAILITERATOR_H
#define __X10_LANG_VALRAIL__RAILITERATOR_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 

template<class FMGL(S)> class ValRail__RailIterator;
template <> class ValRail__RailIterator<void>;
template<class FMGL(S)> class ValRail__RailIterator : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Iterator<FMGL(S)>::template itable<x10::lang::ValRail__RailIterator<FMGL(S)> > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::ValRail__RailIterator<FMGL(S)> > _itable_1;
    
    void _instance_init();
    
    x10_int FMGL(curIndex);
    
    x10aux::ref<x10::lang::ValRail<FMGL(S) > > FMGL(rail);
    
    void _constructor(x10aux::ref<x10::lang::ValRail<FMGL(S) > > r);
    
    static x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> > _make(
             x10aux::ref<x10::lang::ValRail<FMGL(S) > > r);
    
    virtual x10_boolean hasNext();
    virtual FMGL(S) next();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ValRail__RailIterator<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_VALRAIL__RAILITERATOR_H

namespace x10 { namespace lang { 
template<class FMGL(S)> class ValRail__RailIterator;
} } 

#ifndef X10_LANG_VALRAIL__RAILITERATOR_H_NODEPS
#define X10_LANG_VALRAIL__RAILITERATOR_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Int.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_2.h>
#ifndef X10_LANG_VALRAIL__RAILITERATOR_H_GENERICS
#define X10_LANG_VALRAIL__RAILITERATOR_H_GENERICS
template<class FMGL(S)> template<class __T> x10aux::ref<__T> x10::lang::ValRail__RailIterator<FMGL(S)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> > this_ = new (x10aux::alloc_remote<x10::lang::ValRail__RailIterator<FMGL(S)> >()) x10::lang::ValRail__RailIterator<FMGL(S)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_VALRAIL__RAILITERATOR_H_GENERICS
#ifndef X10_LANG_VALRAIL__RAILITERATOR_H_IMPLEMENTATION
#define X10_LANG_VALRAIL__RAILITERATOR_H_IMPLEMENTATION
#include <x10/lang/ValRail__RailIterator.h>


#include "x10/lang/ValRail__RailIterator.inc"

template<class FMGL(S)> typename x10::lang::Iterator<FMGL(S)>::template itable<x10::lang::ValRail__RailIterator<FMGL(S)> >  x10::lang::ValRail__RailIterator<FMGL(S)>::_itable_0(&x10::lang::ValRail__RailIterator<FMGL(S)>::at, &x10::lang::ValRail__RailIterator<FMGL(S)>::at, &x10::lang::ValRail__RailIterator<FMGL(S)>::equals, &x10::lang::ValRail__RailIterator<FMGL(S)>::hasNext, &x10::lang::ValRail__RailIterator<FMGL(S)>::hashCode, &x10::lang::ValRail__RailIterator<FMGL(S)>::home, &x10::lang::ValRail__RailIterator<FMGL(S)>::next, &x10::lang::ValRail__RailIterator<FMGL(S)>::toString, &x10::lang::ValRail__RailIterator<FMGL(S)>::typeName);
template<class FMGL(S)> x10::lang::Any::itable<x10::lang::ValRail__RailIterator<FMGL(S)> >  x10::lang::ValRail__RailIterator<FMGL(S)>::_itable_1(&x10::lang::ValRail__RailIterator<FMGL(S)>::at, &x10::lang::ValRail__RailIterator<FMGL(S)>::at, &x10::lang::ValRail__RailIterator<FMGL(S)>::equals, &x10::lang::ValRail__RailIterator<FMGL(S)>::hashCode, &x10::lang::ValRail__RailIterator<FMGL(S)>::home, &x10::lang::ValRail__RailIterator<FMGL(S)>::toString, &x10::lang::ValRail__RailIterator<FMGL(S)>::typeName);
template<class FMGL(S)> x10aux::itable_entry x10::lang::ValRail__RailIterator<FMGL(S)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<FMGL(S)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::ValRail__RailIterator<FMGL(S)> >())};
template<class FMGL(S)> void x10::lang::ValRail__RailIterator<FMGL(S)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::ValRail__RailIterator<FMGL(S)>");
    
}


//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10FieldDecl_c

//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10FieldDecl_c

//#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(S)> void x10::lang::ValRail__RailIterator<FMGL(S)>::_constructor(
                          x10aux::ref<x10::lang::ValRail<FMGL(S) > > r)
{
    this->x10::lang::Object::_constructor();
    
    //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this))->
      FMGL(curIndex) =
      ((x10_int)0);
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this))->
      FMGL(rail) =
      r;
    
}
template<class FMGL(S)>
x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> > x10::lang::ValRail__RailIterator<FMGL(S)>::_make(
  x10aux::ref<x10::lang::ValRail<FMGL(S) > > r)
{
    x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> > this_ = new (memset(x10aux::alloc<x10::lang::ValRail__RailIterator<FMGL(S)> >(), 0, sizeof(x10::lang::ValRail__RailIterator<FMGL(S)>))) x10::lang::ValRail__RailIterator<FMGL(S)>();
    this_->_constructor(r);
    return this_;
}



//#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> x10_boolean x10::lang::ValRail__RailIterator<FMGL(S)>::hasNext(
  ) {
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10Return_c
    return ((((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this)->
               FMGL(curIndex)) < (x10aux::nullCheck(((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this)->
                                                      FMGL(rail))->
                                    FMGL(length)));
    
}

//#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> FMGL(S) x10::lang::ValRail__RailIterator<FMGL(S)>::next(
  ) {
    
    //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this)->
              FMGL(rail))->apply(((x10_int) (((__extension__ ({
        x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> > x =
          ((x10aux::ref<x10::lang::ValRail__RailIterator<FMGL(S)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(curIndex) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(curIndex)) + (y)));
    }))
    ) - (((x10_int)1)))));
    
}
template<class FMGL(S)> const x10aux::serialization_id_t x10::lang::ValRail__RailIterator<FMGL(S)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::ValRail__RailIterator<FMGL(S)>::template _deserializer<x10::lang::Object>);

template<class FMGL(S)> void x10::lang::ValRail__RailIterator<FMGL(S)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(S)> void x10::lang::ValRail__RailIterator<FMGL(S)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(S)> x10aux::RuntimeType x10::lang::ValRail__RailIterator<FMGL(S)>::rtt;
template<class FMGL(S)> void x10::lang::ValRail__RailIterator<FMGL(S)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::ValRail__RailIterator<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<FMGL(S)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(S)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.ValRail$RailIterator";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_LANG_VALRAIL__RAILITERATOR_H_IMPLEMENTATION
#endif // __X10_LANG_VALRAIL__RAILITERATOR_H_NODEPS
