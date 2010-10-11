#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
class x10_io_StringWriter__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> >::itable<x10_io_StringWriter__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::lang::String> apply() {
        
        //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10Return_c
        return x10aux::placeCheck(x10aux::nullCheck(saved_this->FMGL(b)))->result();
        
    }
    
    // captured environment
    x10aux::ref<x10::io::StringWriter> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::io::StringWriter> that_saved_this = buf.read<x10aux::ref<x10::io::StringWriter> >();
        x10aux::ref<x10_io_StringWriter__closure__2> this_ = new (x10aux::alloc<x10_io_StringWriter__closure__2>()) x10_io_StringWriter__closure__2(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_io_StringWriter__closure__2(x10aux::ref<x10::io::StringWriter> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10:25";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
class x10_io_StringWriter__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_0<x10_int>::itable<x10_io_StringWriter__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply() {
        
        //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10Return_c
        return x10aux::placeCheck(x10aux::nullCheck(saved_this->FMGL(b)))->length();
        
    }
    
    // captured environment
    x10aux::ref<x10::io::StringWriter> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::io::StringWriter> that_saved_this = buf.read<x10aux::ref<x10::io::StringWriter> >();
        x10aux::ref<x10_io_StringWriter__closure__1> this_ = new (x10aux::alloc<x10_io_StringWriter__closure__1>()) x10_io_StringWriter__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_io_StringWriter__closure__1(x10aux::ref<x10::io::StringWriter> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10:24";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_io_StringWriter__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_io_StringWriter__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(x10aux::nullCheck(saved_this->FMGL(b)))->add(((x10_char) (char) (x)));
    }
    
    // captured environment
    x10aux::ref<x10::io::StringWriter> saved_this;
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
        x10aux::ref<x10::io::StringWriter> that_saved_this = buf.read<x10aux::ref<x10::io::StringWriter> >();
        x10_byte that_x = buf.read<x10_byte>();
        x10aux::ref<x10_io_StringWriter__closure__0> this_ = new (x10aux::alloc<x10_io_StringWriter__closure__0>()) x10_io_StringWriter__closure__0(that_saved_this, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_io_StringWriter__closure__0(x10aux::ref<x10::io::StringWriter> saved_this, x10_byte x) : saved_this(saved_this), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10:21";
    }

};

