#ifndef __X10_LANG_CELL_H
#define __X10_LANG_CELL_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class UnsupportedOperationException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Cell;
template <> class Cell<void>;
template<class FMGL(T)> class Cell : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    FMGL(T) FMGL(value);
    
    void _constructor(FMGL(T) x);
    
    static x10aux::ref<x10::lang::Cell<FMGL(T)> > _make(FMGL(T) x);
    
    virtual x10aux::ref<x10::lang::String> toString();
    virtual FMGL(T) apply();
    virtual void apply(FMGL(T) x);
    virtual FMGL(T) set(FMGL(T) x);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::lang::Cell<FMGL(T)> > this_,
                                   x10aux::serialization_buffer& buf);
    
    public: x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Cell<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    template<class FMGL(T)> static x10aux::ref<x10::lang::Cell<FMGL(T)> >
      make(
      FMGL(T) x);
    
    template<class FMGL(T)> static FMGL(T) __implicit_convert(x10aux::ref<x10::lang::Cell<FMGL(T)> > x);
    
    template<class FMGL(T)> static x10aux::ref<x10::lang::Cell<FMGL(T)> >
      __implicit_convert(
      FMGL(T) x);
    
    
};

} } 
#endif // X10_LANG_CELL_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class Cell;
} } 

#ifndef X10_LANG_CELL_H_NODEPS
#define X10_LANG_CELL_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/String.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/UnsupportedOperationException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/VoidFun_0_0.h>
#ifndef X10_LANG_CELL__CLOSURE__2_CLOSURE
#define X10_LANG_CELL__CLOSURE__2_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Cell__closure__2 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Cell__closure__2<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this)->FMGL(value) = x;
    }
    
    // captured environment
    x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this;
    FMGL(T) x;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->x);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Cell<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Cell<FMGL(T)> > >();
        FMGL(T) that_x = buf.read<FMGL(T)>();
        x10aux::ref<x10_lang_Cell__closure__2<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Cell__closure__2<FMGL(T) > >()) x10_lang_Cell__closure__2<FMGL(T) >(that_saved_this, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Cell__closure__2(x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this, FMGL(T) x) : saved_this(saved_this), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10:71";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Cell__closure__2<FMGL(T) > >x10_lang_Cell__closure__2<FMGL(T) >::_itable(&x10_lang_Cell__closure__2<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Cell__closure__2<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Cell__closure__2<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Cell__closure__2<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Cell__closure__2<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Cell__closure__2<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_CELL__CLOSURE__2_CLOSURE
#ifndef X10_LANG_CELL__CLOSURE__1_CLOSURE
#define X10_LANG_CELL__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Cell__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Cell__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this)->FMGL(value) = x;
    }
    
    // captured environment
    x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this;
    FMGL(T) x;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->x);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Cell<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Cell<FMGL(T)> > >();
        FMGL(T) that_x = buf.read<FMGL(T)>();
        x10aux::ref<x10_lang_Cell__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Cell__closure__1<FMGL(T) > >()) x10_lang_Cell__closure__1<FMGL(T) >(that_saved_this, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Cell__closure__1(x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this, FMGL(T) x) : saved_this(saved_this), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10:62";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Cell__closure__1<FMGL(T) > >x10_lang_Cell__closure__1<FMGL(T) >::_itable(&x10_lang_Cell__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Cell__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Cell__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Cell__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Cell__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Cell__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_CELL__CLOSURE__1_CLOSURE
#ifndef X10_LANG_CELL__CLOSURE__0_CLOSURE
#define X10_LANG_CELL__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_lang_Cell__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_lang_Cell__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply() {
        
        //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
        return x10aux::placeCheck(saved_this)->FMGL(value);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Cell<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Cell<FMGL(T)> > >();
        x10aux::ref<x10_lang_Cell__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Cell__closure__0<FMGL(T) > >()) x10_lang_Cell__closure__0<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Cell__closure__0(x10aux::ref<x10::lang::Cell<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10:54";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_lang_Cell__closure__0<FMGL(T) > >x10_lang_Cell__closure__0<FMGL(T) >::_itable(&x10_lang_Cell__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Cell__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Cell__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >, &x10_lang_Cell__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Cell__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Cell__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_CELL__CLOSURE__0_CLOSURE
#ifndef X10_LANG_CELL_H_GENERICS
#define X10_LANG_CELL_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Cell<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Cell<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Cell<FMGL(T)> >()) x10::lang::Cell<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Cell<FMGL(T)>::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::lang::Cell<FMGL(T)> > this_;
    if (rr.ref != 0) {
        this_ = x10::lang::Cell<FMGL(T)>::template _deserializer<x10::lang::Cell<FMGL(T)> >(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_LANG_CELL_H_GENERICS
#ifndef X10_LANG_CELL_H_IMPLEMENTATION
#define X10_LANG_CELL_H_IMPLEMENTATION
#include <x10/lang/Cell.h>


#include "x10/lang/Cell.inc"

template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Cell<FMGL(T)>");
    
}


//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10FieldDecl_c
/**
     * The value stored in this cell.
     */

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_constructor(FMGL(T) x)
{
    this->x10::lang::Object::_constructor();
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this))->
      FMGL(value) =
      x;
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Cell<FMGL(T)> > x10::lang::Cell<FMGL(T)>::_make(
  FMGL(T) x)
{
    x10aux::ref<x10::lang::Cell<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Cell<FMGL(T)> >(), 0, sizeof(x10::lang::Cell<FMGL(T)>))) x10::lang::Cell<FMGL(T)>();
    this_->_constructor(x);
    return this_;
}



//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::String> x10::lang::Cell<FMGL(T)>::toString(
  ) {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10If_c
    if ((!((x10aux::get_location(((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this)) == (x10::lang::Place_methods::_make(x10aux::here))->FMGL(id)))))
    {
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make()));
    }
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return ((((x10::lang::String::Lit("Cell(")) + (x10aux::to_string(x10aux::nullCheck(((__extension__ ({
                                                                                            x10aux::ref<x10::lang::Cell<FMGL(T)> > __desugarer__var__39__ =
                                                                                              ((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this);
                                                                                            
                                                                                            //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10LocalDecl_c
                                                                                            x10aux::ref<x10::lang::Cell<FMGL(T)> > __var695__;
                                                                                            
                                                                                            //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Labeled_c
                                                                                            goto __ret1975; __ret1975: 
                                                                                            //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Do_c
                                                                                            do
                                                                                            {
                                                                                            {
                                                                                                
                                                                                                //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10If_c
                                                                                                if ((!x10aux::struct_equals(__desugarer__var__39__,
                                                                                                                            x10aux::null)) &&
                                                                                                    !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__39__)->location),
                                                                                                                             x10::lang::Place_methods::_make(x10aux::here)))))
                                                                                                {
                                                                                                    
                                                                                                    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Throw_c
                                                                                                    x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Cell[T]{self.home==here}"))));
                                                                                                }
                                                                                                
                                                                                                //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
                                                                                                __var695__ =
                                                                                                  __desugarer__var__39__;
                                                                                                
                                                                                                //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Branch_c
                                                                                                goto __ret1975_end_;
                                                                                            }
                                                                                            goto __ret1975_next_; __ret1975_next_: ;
                                                                                            }
                                                                                            while (false);
                                                                                            goto __ret1975_end_; __ret1975_end_: ;
                                                                                            __var695__;
                                                                                        }))
                                                                                        ))->
                                                                       FMGL(value))))) + (x10::lang::String::Lit(")")));
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Cell<FMGL(T)>::apply(
  ) {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::template evalAt<FMGL(T) >(
             x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this))),
             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> >(x10aux::ref<x10_lang_Cell__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<FMGL(T)> >(sizeof(x10_lang_Cell__closure__0<FMGL(T)>)))x10_lang_Cell__closure__0<FMGL(T)>(this)))));
    
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::apply(
  FMGL(T) x) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Cell__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Cell__closure__1<FMGL(T)>)))x10_lang_Cell__closure__1<FMGL(T)>(this, x)))));
}

//#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Cell<FMGL(T)>::set(
  FMGL(T) x) {
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Cell<FMGL(T)> >)this))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Cell__closure__2<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Cell__closure__2<FMGL(T)>)))x10_lang_Cell__closure__2<FMGL(T)>(this, x)))));
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return x;
    
}

//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c

//#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Cell<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Cell<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_serialize(x10aux::ref<x10::lang::Cell<FMGL(T)> > this_,
                                                                  x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Cell<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Cell<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Cell<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Cell";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
template<class FMGL(T)> x10aux::ref<x10::lang::Cell<FMGL(T)> >
  x10::lang::Cell<void>::make(FMGL(T) x)
{
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return x10::lang::Cell<FMGL(T)>::_make(x);
    
}
template<class FMGL(T)>
FMGL(T)
  x10::lang::Cell<void>::__implicit_convert(x10aux::ref<x10::lang::Cell<FMGL(T)> > x)
{
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x)->x10::lang::Cell<FMGL(T)>::apply();
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Cell<FMGL(T)> >
  x10::lang::Cell<void>::__implicit_convert(FMGL(T) x)
{
    
    //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Cell.x10": x10.ast.X10Return_c
    return x10::lang::Cell<void>::template make<FMGL(T) >(
             x);
    
}
#endif // X10_LANG_CELL_H_IMPLEMENTATION
#endif // __X10_LANG_CELL_H_NODEPS
