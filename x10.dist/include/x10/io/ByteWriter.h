#ifndef __X10_IO_BYTEWRITER_H
#define __X10_IO_BYTEWRITER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(Element), class FMGL(Collection)> class Builder;
} } 
namespace x10 { namespace lang { 
class Byte;
} } 
#include <x10/lang/Byte.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace io { 

template<class FMGL(T)> class ByteWriter;
template <> class ByteWriter<void>;
template<class FMGL(T)> class ByteWriter : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > FMGL(b);
    
    void _constructor(x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > b);
    
    static x10aux::ref<x10::io::ByteWriter<FMGL(T)> > _make(x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > b);
    
    virtual void write(x10_byte x);
    virtual x10_long size();
    virtual x10aux::ref<x10::lang::String> toString();
    virtual FMGL(T) result();
    virtual void flush();
    virtual void close();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ByteWriter<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_IO_BYTEWRITER_H

namespace x10 { namespace io { 
template<class FMGL(T)> class ByteWriter;
} } 

#ifndef X10_IO_BYTEWRITER_H_NODEPS
#define X10_IO_BYTEWRITER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Builder.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Long.h>
#include <x10/lang/RuntimeException.h>
#include <x10/lang/String.h>
#include <x10/lang/Fun_0_0.h>
#ifndef X10_IO_BYTEWRITER__CLOSURE__1_CLOSURE
#define X10_IO_BYTEWRITER__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_io_ByteWriter__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_io_ByteWriter__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply() {
        
        //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10Return_c
        return (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::placeCheck(x10aux::nullCheck(saved_this->
                                                                                                              FMGL(b)));
               (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Builder<x10_byte, FMGL(T)> >(_->_getITables())->result))(); }));
        
    }
    
    // captured environment
    x10aux::ref<x10::io::ByteWriter<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::io::ByteWriter<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::io::ByteWriter<FMGL(T)> > >();
        x10aux::ref<x10_io_ByteWriter__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_io_ByteWriter__closure__1<FMGL(T) > >()) x10_io_ByteWriter__closure__1<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_io_ByteWriter__closure__1(x10aux::ref<x10::io::ByteWriter<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10:24";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<FMGL(T)>::template itable <x10_io_ByteWriter__closure__1<FMGL(T) > >x10_io_ByteWriter__closure__1<FMGL(T) >::_itable(&x10_io_ByteWriter__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_io_ByteWriter__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_io_ByteWriter__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<FMGL(T)> >, &x10_io_ByteWriter__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_io_ByteWriter__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_io_ByteWriter__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_IO_BYTEWRITER__CLOSURE__1_CLOSURE
#ifndef X10_IO_BYTEWRITER__CLOSURE__0_CLOSURE
#define X10_IO_BYTEWRITER__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_io_ByteWriter__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_io_ByteWriter__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": polyglot.ast.Eval_c
        (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::placeCheck(x10aux::nullCheck(saved_this->
                                                                                                       FMGL(b)));
        (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::util::Builder<x10_byte, FMGL(T)> >(_->_getITables())->add))(
          x); }));
    }
    
    // captured environment
    x10aux::ref<x10::io::ByteWriter<FMGL(T)> > saved_this;
    x10_byte x;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->x);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::io::ByteWriter<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::io::ByteWriter<FMGL(T)> > >();
        x10_byte that_x = buf.read<x10_byte>();
        x10aux::ref<x10_io_ByteWriter__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_io_ByteWriter__closure__0<FMGL(T) > >()) x10_io_ByteWriter__closure__0<FMGL(T) >(that_saved_this, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_io_ByteWriter__closure__0(x10aux::ref<x10::io::ByteWriter<FMGL(T)> > saved_this, x10_byte x) : saved_this(saved_this), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10:21";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_io_ByteWriter__closure__0<FMGL(T) > >x10_io_ByteWriter__closure__0<FMGL(T) >::_itable(&x10_io_ByteWriter__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_io_ByteWriter__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_io_ByteWriter__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_io_ByteWriter__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_io_ByteWriter__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_io_ByteWriter__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_IO_BYTEWRITER__CLOSURE__0_CLOSURE
#ifndef X10_IO_BYTEWRITER_H_GENERICS
#define X10_IO_BYTEWRITER_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::io::ByteWriter<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::io::ByteWriter<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::io::ByteWriter<FMGL(T)> >()) x10::io::ByteWriter<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_IO_BYTEWRITER_H_GENERICS
#ifndef X10_IO_BYTEWRITER_H_IMPLEMENTATION
#define X10_IO_BYTEWRITER_H_IMPLEMENTATION
#include <x10/io/ByteWriter.h>


#include "x10/io/ByteWriter.inc"

template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::io::ByteWriter<FMGL(T)>");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10FieldDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::_constructor(x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > b)
{
    this->x10::lang::Object::_constructor();
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::ByteWriter<FMGL(T)> >)this)->
      FMGL(b) =
      b;
    
}
template<class FMGL(T)>
x10aux::ref<x10::io::ByteWriter<FMGL(T)> > x10::io::ByteWriter<FMGL(T)>::_make(
  x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > b)
{
    x10aux::ref<x10::io::ByteWriter<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::io::ByteWriter<FMGL(T)> >(), 0, sizeof(x10::io::ByteWriter<FMGL(T)>))) x10::io::ByteWriter<FMGL(T)>();
    this_->_constructor(b);
    return this_;
}



//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::write(
  x10_byte x) {
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::io::ByteWriter<FMGL(T)> >)this)->
                                                                                     FMGL(b))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_io_ByteWriter__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_io_ByteWriter__closure__0<FMGL(T)>)))x10_io_ByteWriter__closure__0<FMGL(T)>(this, x)))));
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_long x10::io::ByteWriter<FMGL(T)>::size(
  ) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::String>
  x10::io::ByteWriter<FMGL(T)>::toString(
  ) {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10Return_c
    return x10aux::to_string(((x10aux::ref<x10::io::ByteWriter<FMGL(T)> >)this)->
                               FMGL(b));
    
}

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::io::ByteWriter<FMGL(T)>::result(
  ) {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::template evalAt<FMGL(T) >(
             x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::io::ByteWriter<FMGL(T)> >)this)->
                                                                    FMGL(b))),
             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> >(x10aux::ref<x10_io_ByteWriter__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<FMGL(T)> >(sizeof(x10_io_ByteWriter__closure__1<FMGL(T)>)))x10_io_ByteWriter__closure__1<FMGL(T)>(this)))));
    
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::flush(
  ) {
 
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteWriter.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::close(
  ) {
 
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::io::ByteWriter<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::ByteWriter<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(b));
    
}

template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(b) = buf.read<x10aux::ref<x10::util::Builder<x10_byte, FMGL(T)> > >();
}

template<class FMGL(T)> x10aux::RuntimeType x10::io::ByteWriter<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::io::ByteWriter<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::io::ByteWriter<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.io.ByteWriter";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_IO_BYTEWRITER_H_IMPLEMENTATION
#endif // __X10_IO_BYTEWRITER_H_NODEPS
