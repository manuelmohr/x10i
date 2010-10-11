#ifndef __X10_LANG_RUNTIME__STATEFULREDUCER_H
#define __X10_LANG_RUNTIME__STATEFULREDUCER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Reducible;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Runtime__StatefulReducer;
template <> class Runtime__StatefulReducer<void>;
template<class FMGL(T)> class Runtime__StatefulReducer : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Reducible<FMGL(T)> > FMGL(reducer);
    
    FMGL(T) FMGL(result);
    
    x10_int FMGL(MAX);
    
    x10aux::ref<x10::lang::Rail<FMGL(T) > > FMGL(resultRail);
    
    x10aux::ref<x10::lang::Rail<x10_boolean > > FMGL(workerFlag);
    
    void _constructor(x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    static x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > _make(
             x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    virtual void accept(FMGL(T) t);
    virtual void accept(FMGL(T) t, x10_int id);
    virtual void placeMerge();
    virtual FMGL(T) result();
    virtual void reset();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Runtime__StatefulReducer<void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_RUNTIME__STATEFULREDUCER_H

namespace x10 { namespace lang { 
template<class FMGL(T)>
class Runtime__StatefulReducer;
} } 

#ifndef X10_LANG_RUNTIME__STATEFULREDUCER_H_NODEPS
#define X10_LANG_RUNTIME__STATEFULREDUCER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Reducible.h>
#include <x10/lang/Int.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__1_CLOSURE
#define X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T)> class x10_lang_Runtime__StatefulReducer__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10_int, FMGL(T)>::template itable <x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply(x10_int id__36) {
        
        //#line 374 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10aux::placeCheck(saved_this)->FMGL(result);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > >();
        x10aux::ref<x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) > >()) x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__StatefulReducer__closure__1(x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:374";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_1<x10_int, FMGL(T)>::template itable <x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) > >x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::_itable(&x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, FMGL(T)> >, &x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__1_CLOSURE
#ifndef X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__0_CLOSURE
#define X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T)> class x10_lang_Runtime__StatefulReducer__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10_int, x10_boolean>::template itable <x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_boolean apply(x10_int id__35) {
        
        //#line 370 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) > >()) x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__StatefulReducer__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:370";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_1<x10_int, x10_boolean>::template itable <x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) > >x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::_itable(&x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >, &x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__STATEFULREDUCER__CLOSURE__0_CLOSURE
#ifndef X10_LANG_RUNTIME__STATEFULREDUCER_H_GENERICS
#define X10_LANG_RUNTIME__STATEFULREDUCER_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Runtime__StatefulReducer<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Runtime__StatefulReducer<FMGL(T)> >()) x10::lang::Runtime__StatefulReducer<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__STATEFULREDUCER_H_GENERICS
#ifndef X10_LANG_RUNTIME__STATEFULREDUCER_H_IMPLEMENTATION
#define X10_LANG_RUNTIME__STATEFULREDUCER_H_IMPLEMENTATION
#include <x10/lang/Runtime__StatefulReducer.h>


#include "x10/lang/Runtime__StatefulReducer.inc"

template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__StatefulReducer<FMGL(T)>");
    FMGL(MAX) = ((x10_int)1000);
    
}


//#line 366 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 367 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 368 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 369 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 370 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 371 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    this->_instance_init();
    this->x10::lang::Object::_constructor();
    
    //#line 369 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
      FMGL(resultRail) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Rail<FMGL(T) > > >(x10aux::null);
    
    //#line 370 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
      FMGL(workerFlag) =
      x10::lang::Rail<void>::make<x10_boolean >(x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
                                                  FMGL(MAX), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> >(x10aux::ref<x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_boolean> >(sizeof(x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T)>)))x10_lang_Runtime__StatefulReducer__closure__0<FMGL(T)>()))));
    
    //#line 372 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
      FMGL(reducer) =
      r;
    
    //#line 373 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
      FMGL(result) =
      (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                  FMGL(reducer));
      (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->zero))(); }));
    
    //#line 374 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
      FMGL(resultRail) =
      x10::lang::Rail<void>::make<FMGL(T) >(x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this))->
                                              FMGL(MAX), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, FMGL(T)> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, FMGL(T)> >(x10aux::ref<x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, FMGL(T)> >(sizeof(x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T)>)))x10_lang_Runtime__StatefulReducer__closure__1<FMGL(T)>(this)))));
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > x10::lang::Runtime__StatefulReducer<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Runtime__StatefulReducer<FMGL(T)> >(), 0, sizeof(x10::lang::Runtime__StatefulReducer<FMGL(T)>))) x10::lang::Runtime__StatefulReducer<FMGL(T)>();
    this_->_constructor(r);
    return this_;
}



//#line 376 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::accept(
  FMGL(T) t) {
    
    //#line 377 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
      FMGL(result) = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                                 FMGL(reducer));
                     (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->apply))(
                       ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                         FMGL(result),
                       t); }));
}

//#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::accept(
  FMGL(T) t,
  x10_int id) {
    
    //#line 380 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((((id) >= (((x10_int)0)))) && (((id) < (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                  FMGL(MAX)))))
    {
        
        //#line 381 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
           FMGL(resultRail))->set((__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                                              FMGL(reducer));
                                  (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->apply))(
                                    (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                       FMGL(resultRail))->apply(id),
                                    t); })), id);
        
        //#line 382 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
           FMGL(workerFlag))->set(true, id);
    }
    
}

//#line 385 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::placeMerge(
  ) {
    
    //#line 386 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 386 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                         FMGL(MAX)));
             
             //#line 386 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 387 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                   FMGL(workerFlag))->apply(i))
            {
                
                //#line 388 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                  FMGL(result) =
                  (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                              FMGL(reducer));
                  (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->apply))(
                    ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                      FMGL(result),
                    (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                       FMGL(resultRail))->apply(i)); }));
                
                //#line 389 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                   FMGL(resultRail))->set((__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                                                      FMGL(reducer));
                                          (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->zero))(); })), i);
            }
            
        }
    }
    
}

//#line 394 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Runtime__StatefulReducer<FMGL(T)>::result(
  ) {
    
    //#line 394 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
             FMGL(result);
    
}

//#line 395 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::reset(
  ) {
    
    //#line 396 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
      FMGL(result) = (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> >)this)->
                                                                                                 FMGL(reducer));
                     (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Reducible<FMGL(T)> >(_->_getITables())->zero))(); }));
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Runtime__StatefulReducer<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__StatefulReducer<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(reducer));
    
}

template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(reducer) = buf.read<x10aux::ref<x10::lang::Reducible<FMGL(T)> > >();
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Runtime__StatefulReducer<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Runtime__StatefulReducer<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Runtime__StatefulReducer<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Runtime$StatefulReducer";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_RUNTIME__STATEFULREDUCER_H_IMPLEMENTATION
#endif // __X10_LANG_RUNTIME__STATEFULREDUCER_H_NODEPS
