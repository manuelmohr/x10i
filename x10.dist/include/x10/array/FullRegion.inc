#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_FullRegion__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(((x10_int)0x7fffffff))
          : (x10_int)((thatMax)->apply(((x10_int) ((i) - (saved_this->
                                                            FMGL(rank))))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::FullRegion> saved_this;
    x10aux::ref<x10::lang::ValRail<x10_int > > thatMax;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->thatMax);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::FullRegion> that_saved_this = buf.read<x10aux::ref<x10::array::FullRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMax = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_FullRegion__closure__3> this_ = new (x10aux::alloc<x10_array_FullRegion__closure__3>()) x10_array_FullRegion__closure__3(that_saved_this, that_thatMax);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_FullRegion__closure__3(x10aux::ref<x10::array::FullRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMax) : saved_this(saved_this), thatMax(thatMax) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10:42";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_FullRegion__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(((x10_int)0x80000000))
          : (x10_int)((thatMin)->apply(((x10_int) ((i) - (saved_this->
                                                            FMGL(rank))))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::FullRegion> saved_this;
    x10aux::ref<x10::lang::ValRail<x10_int > > thatMin;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->thatMin);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::FullRegion> that_saved_this = buf.read<x10aux::ref<x10::array::FullRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMin = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_FullRegion__closure__2> this_ = new (x10aux::alloc<x10_array_FullRegion__closure__2>()) x10_array_FullRegion__closure__2(that_saved_this, that_thatMin);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_FullRegion__closure__2(x10aux::ref<x10::array::FullRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMin) : saved_this(saved_this), thatMin(thatMin) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10:41";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_FullRegion__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int id__43) {
        
        //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return ((x10_int)0x7fffffff);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_array_FullRegion__closure__1> this_ = new (x10aux::alloc<x10_array_FullRegion__closure__1>()) x10_array_FullRegion__closure__1();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_FullRegion__closure__1() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10:30";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_FullRegion__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int id__42) {
        
        //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return ((x10_int)0x80000000);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_array_FullRegion__closure__0> this_ = new (x10aux::alloc<x10_array_FullRegion__closure__0>()) x10_array_FullRegion__closure__0();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_FullRegion__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10:29";
    }

};

