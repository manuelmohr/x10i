#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__13 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__13> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) ((c) / ((saved_this->FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10_int c;
    x10aux::ref<x10::array::Point> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->c);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__13> this_ = new (x10aux::alloc<x10_array_Point__closure__13>()) x10_array_Point__closure__13(that_c, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__13(x10_int c, x10aux::ref<x10::array::Point> saved_this) : c(c), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:144";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__12 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__12> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) ((c) * ((saved_this->FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10_int c;
    x10aux::ref<x10::array::Point> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->c);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__12> this_ = new (x10aux::alloc<x10_array_Point__closure__12>()) x10_array_Point__closure__12(that_c, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__12(x10_int c, x10aux::ref<x10::array::Point> saved_this) : c(c), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:139";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__11 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__11> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) ((c) - ((saved_this->FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10_int c;
    x10aux::ref<x10::array::Point> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->c);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__11> this_ = new (x10aux::alloc<x10_array_Point__closure__11>()) x10_array_Point__closure__11(that_c, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__11(x10_int c, x10aux::ref<x10::array::Point> saved_this) : c(c), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:134";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__10 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__10> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) ((c) + ((saved_this->FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10_int c;
    x10aux::ref<x10::array::Point> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->c);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__10> this_ = new (x10aux::alloc<x10_array_Point__closure__10>()) x10_array_Point__closure__10(that_c, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__10(x10_int c, x10aux::ref<x10::array::Point> saved_this) : c(c), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:129";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__9 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__9> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) / (c)));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10_int c;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->c);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10_array_Point__closure__9> this_ = new (x10aux::alloc<x10_array_Point__closure__9>()) x10_array_Point__closure__9(that_saved_this, that_c);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__9(x10aux::ref<x10::array::Point> saved_this, x10_int c) : saved_this(saved_this), c(c) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:124";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__8 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__8> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) * (c)));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10_int c;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->c);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10_array_Point__closure__8> this_ = new (x10aux::alloc<x10_array_Point__closure__8>()) x10_array_Point__closure__8(that_saved_this, that_c);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__8(x10aux::ref<x10::array::Point> saved_this, x10_int c) : saved_this(saved_this), c(c) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:119";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__7 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__7> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) - (c)));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10_int c;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->c);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10_array_Point__closure__7> this_ = new (x10aux::alloc<x10_array_Point__closure__7>()) x10_array_Point__closure__7(that_saved_this, that_c);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__7(x10aux::ref<x10::array::Point> saved_this, x10_int c) : saved_this(saved_this), c(c) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:114";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__6 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__6> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) + (c)));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10_int c;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->c);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10_int that_c = buf.read<x10_int>();
        x10aux::ref<x10_array_Point__closure__6> this_ = new (x10aux::alloc<x10_array_Point__closure__6>()) x10_array_Point__closure__6(that_saved_this, that_c);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__6(x10aux::ref<x10::array::Point> saved_this, x10_int c) : saved_this(saved_this), c(c) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:109";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__5 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__5> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) / ((x10aux::nullCheck(that)->
                                                                        FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10aux::ref<x10::array::Point> that;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->that);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10::array::Point> that_that = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__5> this_ = new (x10aux::alloc<x10_array_Point__closure__5>()) x10_array_Point__closure__5(that_saved_this, that_that);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__5(x10aux::ref<x10::array::Point> saved_this, x10aux::ref<x10::array::Point> that) : saved_this(saved_this), that(that) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:104";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) * ((x10aux::nullCheck(that)->
                                                                        FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10aux::ref<x10::array::Point> that;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->that);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10::array::Point> that_that = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__4> this_ = new (x10aux::alloc<x10_array_Point__closure__4>()) x10_array_Point__closure__4(that_saved_this, that_that);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__4(x10aux::ref<x10::array::Point> saved_this, x10aux::ref<x10::array::Point> that) : saved_this(saved_this), that(that) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:99";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) - ((x10aux::nullCheck(that)->
                                                                        FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10aux::ref<x10::array::Point> that;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->that);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10::array::Point> that_that = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__3> this_ = new (x10aux::alloc<x10_array_Point__closure__3>()) x10_array_Point__closure__3(that_saved_this, that_that);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__3(x10aux::ref<x10::array::Point> saved_this, x10aux::ref<x10::array::Point> that) : saved_this(saved_this), that(that) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:94";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) (((saved_this->FMGL(coords))->apply(i)) + ((x10aux::nullCheck(that)->
                                                                        FMGL(coords))->apply(i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    x10aux::ref<x10::array::Point> that;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->that);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10::array::Point> that_that = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__2> this_ = new (x10aux::alloc<x10_array_Point__closure__2>()) x10_array_Point__closure__2(that_saved_this, that_that);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__2(x10aux::ref<x10::array::Point> saved_this, x10aux::ref<x10::array::Point> that) : saved_this(saved_this), that(that) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:88";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return ((x10_int) -((saved_this->FMGL(coords))->apply(i)));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_saved_this = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_Point__closure__1> this_ = new (x10aux::alloc<x10_array_Point__closure__1>()) x10_array_Point__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__1(x10aux::ref<x10::array::Point> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:83";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_Point__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return (cs)->apply(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10_int > > cs;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->cs);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10_int > > that_cs = buf.read<x10aux::ref<x10::lang::Rail<x10_int > > >();
        x10aux::ref<x10_array_Point__closure__0> this_ = new (x10aux::alloc<x10_array_Point__closure__0>()) x10_array_Point__closure__0(that_cs);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Point__closure__0(x10aux::ref<x10::lang::Rail<x10_int > > cs) : cs(cs) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10:46";
    }

};

