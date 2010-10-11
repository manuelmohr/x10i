#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyRow__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyRow__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(((x10_int) -(saved_this->apply(
                                                                           i))))
          : (x10_int)(((x10_int) ((((x10_int) -(saved_this->apply(
                                                  saved_this->
                                                    FMGL(rank))))) + (((x10_int)1)))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::PolyRow> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::PolyRow> that_saved_this = buf.read<x10aux::ref<x10::array::PolyRow> >();
        x10aux::ref<x10_array_PolyRow__closure__1> this_ = new (x10aux::alloc<x10_array_PolyRow__closure__1>()) x10_array_PolyRow__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyRow__closure__1(x10aux::ref<x10::array::PolyRow> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10:133";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_PolyRow__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyRow__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
        return ((i) < (x10aux::nullCheck(p)->FMGL(rank))) ? (x10_int)(x10aux::nullCheck(p)->x10::array::Point::apply(
                                                                        i))
          : (x10_int)(k);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Point> p;
    x10_int k;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->p);
        buf.write(this->k);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Point> that_p = buf.read<x10aux::ref<x10::array::Point> >();
        x10_int that_k = buf.read<x10_int>();
        x10aux::ref<x10_array_PolyRow__closure__0> this_ = new (x10aux::alloc<x10_array_PolyRow__closure__0>()) x10_array_PolyRow__closure__0(that_p, that_k);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_PolyRow__closure__0(x10aux::ref<x10::array::Point> p, x10_int k) : p(p), k(k) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10:50";
    }

};

