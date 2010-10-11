#ifndef __X10_LANG_FUTURE_H
#define __X10_LANG_FUTURE_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_0_H_NODEPS
#include <x10/lang/Fun_0_0.h>
#undef X10_LANG_FUN_0_0_H_NODEPS
namespace x10 { namespace lang { 
class Runtime__Latch;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Error;
} } 
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Future;
template <> class Future<void>;
template<class FMGL(T)> class Future : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Fun_0_0<FMGL(T)>::template itable<x10::lang::Future<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Future<FMGL(T)> > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Runtime__Latch> FMGL(latch);
    
    x10aux::ref<x10::util::GrowableRail<x10aux::ref<x10::lang::Throwable> > >
      FMGL(exception);
    
    x10aux::ref<x10::util::GrowableRail<FMGL(T) > > FMGL(result);
    
    x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > FMGL(eval);
    
    void _constructor(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval);
    
    static x10aux::ref<x10::lang::Future<FMGL(T)> > _make(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval);
    
    x10aux::ref<x10::util::GrowableRail<FMGL(T) > > result();
    virtual x10_boolean forced();
    virtual FMGL(T) apply();
    virtual FMGL(T) force();
    virtual void run();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Future<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_FUTURE_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class Future;
} } 

#ifndef X10_LANG_FUTURE_H_NODEPS
#define X10_LANG_FUTURE_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Runtime__Latch.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Throwable.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Int.h>
#include <x10/lang/Error.h>
#include <x10/lang/RuntimeException.h>
#ifndef X10_LANG_FUTURE__CLOSURE__1_CLOSURE
#define X10_LANG_FUTURE__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_lang_Future__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_lang_Future__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply() {
        
        //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this->FMGL(latch))->await();
        
        //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10If_c
        if ((((saved_this->FMGL(exception))->length()) > (((x10_int)0))))
        {
            
            //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> e =
              (saved_this->
                 FMGL(exception))->apply(((x10_int)0));
            
            //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10If_c
            if (x10aux::instanceof<x10aux::ref<x10::lang::Error> >(e))
            {
                
                //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::Error> >(e)));
            }
            
            //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10If_c
            if (x10aux::instanceof<x10aux::ref<x10::lang::RuntimeException> >(e))
            {
                
                //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::RuntimeException> >(e)));
            }
            
            //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Assert_c
            #ifndef NO_ASSERTIONS
            if (x10aux::x10__assertions_enabled)
                x10aux::x10__assert(false);
            #endif//NO_ASSERTIONS
            
        }
        
        //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
        return (saved_this->result())->apply(((x10_int)0));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Future<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Future<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Future<FMGL(T)> > >();
        x10aux::ref<x10_lang_Future__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Future__closure__1<FMGL(T) > >()) x10_lang_Future__closure__1<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Future__closure__1(x10aux::ref<x10::lang::Future<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10:56-67";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_lang_Future__closure__1<FMGL(T) > >x10_lang_Future__closure__1<FMGL(T) >::_itable(&x10_lang_Future__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Future__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Future__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >, &x10_lang_Future__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Future__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Future__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_FUTURE__CLOSURE__1_CLOSURE
#ifndef X10_LANG_FUTURE__CLOSURE__0_CLOSURE
#define X10_LANG_FUTURE__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_lang_Future__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<x10_boolean>::template itable <x10_lang_Future__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_boolean apply() {
        
        //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
        return x10aux::placeCheck(saved_this->FMGL(latch))->apply();
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Future<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Future<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Future<FMGL(T)> > >();
        x10aux::ref<x10_lang_Future__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Future__closure__0<FMGL(T) > >()) x10_lang_Future__closure__0<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Future__closure__0(x10aux::ref<x10::lang::Future<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10:48";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<x10_boolean>::template itable <x10_lang_Future__closure__0<FMGL(T) > >x10_lang_Future__closure__0<FMGL(T) >::_itable(&x10_lang_Future__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Future__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Future__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >, &x10_lang_Future__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Future__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Future__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_FUTURE__CLOSURE__0_CLOSURE
#ifndef X10_LANG_FUTURE_H_GENERICS
#define X10_LANG_FUTURE_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Future<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Future<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Future<FMGL(T)> >()) x10::lang::Future<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_FUTURE_H_GENERICS
#ifndef X10_LANG_FUTURE_H_IMPLEMENTATION
#define X10_LANG_FUTURE_H_IMPLEMENTATION
#include <x10/lang/Future.h>


#include "x10/lang/Future.inc"

template<class FMGL(T)> typename x10::lang::Fun_0_0<FMGL(T)>::template itable<x10::lang::Future<FMGL(T)> >  x10::lang::Future<FMGL(T)>::_itable_0(&x10::lang::Future<FMGL(T)>::apply, &x10::lang::Future<FMGL(T)>::at, &x10::lang::Future<FMGL(T)>::at, &x10::lang::Future<FMGL(T)>::equals, &x10::lang::Future<FMGL(T)>::hashCode, &x10::lang::Future<FMGL(T)>::home, &x10::lang::Future<FMGL(T)>::toString, &x10::lang::Future<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::lang::Future<FMGL(T)> >  x10::lang::Future<FMGL(T)>::_itable_1(&x10::lang::Future<FMGL(T)>::at, &x10::lang::Future<FMGL(T)>::at, &x10::lang::Future<FMGL(T)>::equals, &x10::lang::Future<FMGL(T)>::hashCode, &x10::lang::Future<FMGL(T)>::home, &x10::lang::Future<FMGL(T)>::toString, &x10::lang::Future<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::lang::Future<FMGL(T)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Future<FMGL(T)> >())};
template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Future<FMGL(T)>");
    
}


//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10FieldDecl_c
/**
     * Latch for signaling and wait
     */
                                               //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10FieldDecl_c
                                               /**
     * Set if the activity terminated with an exception.
     * Can only be of type Error or RuntimeException
     */
                                                                                                                                                                        //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                        
                                                                                                                                                                        //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                        

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::_constructor(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval)
{
    this->x10::lang::Object::_constructor();
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
      FMGL(latch) =
      x10::lang::Runtime__Latch::_make();
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
      FMGL(exception) =
      x10::util::GrowableRail<x10aux::ref<x10::lang::Throwable> >::_make();
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
      FMGL(eval) =
      eval;
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
      FMGL(result) =
      x10::util::GrowableRail<FMGL(T) >::_make();
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Future<FMGL(T)> > x10::lang::Future<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval)
{
    x10aux::ref<x10::lang::Future<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Future<FMGL(T)> >(), 0, sizeof(x10::lang::Future<FMGL(T)>))) x10::lang::Future<FMGL(T)>();
    this_->_constructor(eval);
    return this_;
}



//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::GrowableRail<FMGL(T) > >
  x10::lang::Future<FMGL(T)>::result(
  ) {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::util::GrowableRail<FMGL(T) > > __desugarer__var__40__ =
          ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
            FMGL(result);
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::GrowableRail<FMGL(T) > > __var761__;
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Labeled_c
        goto __ret1976; __ret1976: 
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__40__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__40__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.util.GrowableRail[T]{self.home==here}"))));
            }
            
            //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
            __var761__ =
              __desugarer__var__40__;
            
            //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Branch_c
            goto __ret1976_end_;
        }
        goto __ret1976_next_; __ret1976_next_: ;
        }
        while (false);
        goto __ret1976_end_; __ret1976_end_: ;
        __var761__;
    }))
    ;
    
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::Future<FMGL(T)>::forced(
  ) {
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::template evalAt<x10_boolean >(
             x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
                                                                    FMGL(latch))),
             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10_boolean> > >(x10aux::ref<x10::lang::Fun_0_0<x10_boolean> >(x10aux::ref<x10_lang_Future__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<x10_boolean> >(sizeof(x10_lang_Future__closure__0<FMGL(T)>)))x10_lang_Future__closure__0<FMGL(T)>(this)))));
    
}

//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Future<FMGL(T)>::apply(
  ) {
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->force();
    
}

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Future<FMGL(T)>::force(
  ) {
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::template evalAt<FMGL(T) >(
             x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
                                                                    FMGL(latch))),
             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> >(x10aux::ref<x10_lang_Future__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<FMGL(T)> >(sizeof(x10_lang_Future__closure__1<FMGL(T)>)))x10_lang_Future__closure__1<FMGL(T)>(this)))));
    
}

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::run(
  ) {
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Try_c
    try {
        
        //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Try_c
        try {
        try {
            
            //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::startFinish();
            {
                
                //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->result())->add((__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::placeCheck(x10aux::nullCheck(((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
                                                                                                                                                                                 FMGL(eval)));
                (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Fun_0_0<FMGL(T)> >(_->_getITables())->apply))(); })));
            }
        }
        catch (x10aux::__ref& __ref__766) {
            x10aux::ref<x10::lang::Throwable>& __exc__ref__766 = (x10aux::ref<x10::lang::Throwable>&)__ref__766;
            if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__766)) {
                x10aux::ref<x10::lang::Throwable> __desugarer__var__41__ =
                  static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__766);
                {
                    
                    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::pushException(
                      __desugarer__var__41__);
                }
            } else
            throw;
        }
        } catch (...) {
            {
                
                //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::stopFinish();
            }
            throw;
        }
        {
            
            //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::stopFinish();
        }
        
        //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
          FMGL(latch)->release();
    }
    catch (x10aux::__ref& __ref__767) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__767 = (x10aux::ref<x10::lang::Throwable>&)__ref__767;
        if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__767)) {
            x10aux::ref<x10::lang::Throwable> t =
              static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__767);
            {
                
                //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
                   FMGL(exception))->add(t);
                
                //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Future.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Future<FMGL(T)> >)this)->
                  FMGL(latch)->release();
            }
        } else
        throw;
    }
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Future<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Future<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(latch));
    buf.write(this->FMGL(exception));
    buf.write(this->FMGL(result));
    buf.write(this->FMGL(eval));
    
}

template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(latch) = buf.read<x10aux::ref<x10::lang::Runtime__Latch> >();
    FMGL(exception) = buf.read<x10aux::ref<x10::util::GrowableRail<x10aux::ref<x10::lang::Throwable> > > >();
    FMGL(result) = buf.read<x10aux::ref<x10::util::GrowableRail<FMGL(T) > > >();
    FMGL(eval) = buf.read<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >();
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Future<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Future<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Future<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.lang.Future";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_LANG_FUTURE_H_IMPLEMENTATION
#endif // __X10_LANG_FUTURE_H_NODEPS
