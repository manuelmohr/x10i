#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyMatBuilder__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMatBuilder__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
        return (as_)->apply(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10_int > > as_;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->as_);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10_int > > that_as_ = buf.read<x10aux::ref<x10::lang::Rail<x10_int > > >();
        x10aux::ref<x10_array_PolyMatBuilder__closure__2> this_ = new (x10aux::alloc<x10_array_PolyMatBuilder__closure__2>()) x10_array_PolyMatBuilder__closure__2(that_as_);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMatBuilder__closure__2(x10aux::ref<x10::lang::Rail<x10_int > > as_) : as_(as_) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10:77";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_2.h>
class x10_array_PolyMatBuilder__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_2<x10_int, x10_int, x10_int>::itable<x10_array_PolyMatBuilder__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i, x10_int j) {
        
        //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(x10aux::nullCheck(saved_this->FMGL(mat))->apply(
                                   i))->apply(j);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::PolyMatBuilder> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::PolyMatBuilder> that_saved_this = buf.read<x10aux::ref<x10::array::PolyMatBuilder> >();
        x10aux::ref<x10_array_PolyMatBuilder__closure__1> this_ = new (x10aux::alloc<x10_array_PolyMatBuilder__closure__1>()) x10_array_PolyMatBuilder__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMatBuilder__closure__1(x10aux::ref<x10::array::PolyMatBuilder> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10:45";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_2.h>
class x10_array_PolyMatBuilder__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int>::itable<x10_array_PolyMatBuilder__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10aux::ref<x10::array::Row> id__50, x10aux::ref<x10::array::Row> id__51) {
        
        //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
        return x10::array::PolyRow::compare(id__50, id__51);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_array_PolyMatBuilder__closure__0> this_ = new (x10aux::alloc<x10_array_PolyMatBuilder__closure__0>()) x10_array_PolyMatBuilder__closure__0();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyMatBuilder__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10:44";
    }

};

