#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMat__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return saved_this->rectMax(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::PolyMat> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::PolyMat> that_saved_this = buf.read<x10aux::ref<x10::array::PolyMat> >();
        x10aux::ref<x10_array_PolyMat__closure__4> this_ = new (x10aux::alloc<x10_array_PolyMat__closure__4>()) x10_array_PolyMat__closure__4(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMat__closure__4(x10aux::ref<x10::array::PolyMat> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10:202";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMat__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return saved_this->rectMin(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::PolyMat> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::PolyMat> that_saved_this = buf.read<x10aux::ref<x10::array::PolyMat> >();
        x10aux::ref<x10_array_PolyMat__closure__3> this_ = new (x10aux::alloc<x10_array_PolyMat__closure__3>()) x10_array_PolyMat__closure__3(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMat__closure__3(x10aux::ref<x10::array::PolyMat> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10:200";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMat__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_boolean>::itable<x10_array_PolyMat__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_boolean apply(x10_int id__52) {
        
        //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
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
        x10aux::ref<x10_array_PolyMat__closure__2> this_ = new (x10aux::alloc<x10_array_PolyMat__closure__2>()) x10_array_PolyMat__closure__2();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMat__closure__2() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10:90";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMat__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int j) {
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(init))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >(((x10aux::ref<x10::lang::Reference>)init)->_getITables())->apply))(
          i,
          j);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init;
    x10_int i;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->init);
        buf.write(this->i);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > that_init = buf.read<x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > >();
        x10_int that_i = buf.read<x10_int>();
        x10aux::ref<x10_array_PolyMat__closure__1> this_ = new (x10aux::alloc<x10_array_PolyMat__closure__1>()) x10_array_PolyMat__closure__1(that_init, that_i);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMat__closure__1(x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init, x10_int i) : init(init), i(i) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10:43";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMat__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> >::itable<x10_array_PolyMat__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::PolyRow> apply(x10_int i) {
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return x10::array::PolyRow::_make(cols, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyMat__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyMat__closure__1)))x10_array_PolyMat__closure__1(init, i)))));
        
    }
    
    // captured environment
    x10_int cols;
    x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->cols);
        buf.write(this->init);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_cols = buf.read<x10_int>();
        x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > that_init = buf.read<x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > >();
        x10aux::ref<x10_array_PolyMat__closure__0> this_ = new (x10aux::alloc<x10_array_PolyMat__closure__0>()) x10_array_PolyMat__closure__0(that_cols, that_init);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMat__closure__0(x10_int cols, x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init) : cols(cols), init(init) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10:43";
    }

};

