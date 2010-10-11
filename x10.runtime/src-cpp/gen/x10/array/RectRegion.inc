#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__9 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__9> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 224 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (axis)) ? (x10_int)(saved_this->x10::array::RectRegion::max(
                                            i)) : (x10_int)(saved_this->x10::array::RectRegion::max(
                                                              ((x10_int) ((i) + (i)))));
        
    }
    
    // captured environment
    x10_int axis;
    x10aux::ref<x10::array::RectRegion> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->axis);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_axis = buf.read<x10_int>();
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10_array_RectRegion__closure__9> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__9>()) x10_array_RectRegion__closure__9(that_axis, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__9(x10_int axis, x10aux::ref<x10::array::RectRegion> saved_this) : axis(axis), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:224";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__8 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__8> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 223 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (axis)) ? (x10_int)(saved_this->x10::array::RectRegion::min(
                                            i)) : (x10_int)(saved_this->x10::array::RectRegion::min(
                                                              ((x10_int) ((i) + (i)))));
        
    }
    
    // captured environment
    x10_int axis;
    x10aux::ref<x10::array::RectRegion> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->axis);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_axis = buf.read<x10_int>();
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10_array_RectRegion__closure__8> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__8>()) x10_array_RectRegion__closure__8(that_axis, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__8(x10_int axis, x10aux::ref<x10::array::RectRegion> saved_this) : axis(axis), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:223";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__7 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__7> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((x10_int) ((saved_this->x10::array::RectRegion::max(i)) + (x10aux::nullCheck(v)->x10::array::Point::apply(
                                                                             i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
    x10aux::ref<x10::array::Point> v;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->v);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::array::Point> that_v = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_RectRegion__closure__7> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__7>()) x10_array_RectRegion__closure__7(that_saved_this, that_v);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__7(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::array::Point> v) : saved_this(saved_this), v(v) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:213";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__6 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__6> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((x10_int) ((saved_this->x10::array::RectRegion::min(i)) + (x10aux::nullCheck(v)->x10::array::Point::apply(
                                                                             i))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
    x10aux::ref<x10::array::Point> v;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->v);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::array::Point> that_v = buf.read<x10aux::ref<x10::array::Point> >();
        x10aux::ref<x10_array_RectRegion__closure__6> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__6>()) x10_array_RectRegion__closure__6(that_saved_this, that_v);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__6(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::array::Point> v) : saved_this(saved_this), v(v) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:212";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__5 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__5> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(saved_this->x10::array::RectRegion::max(
                                                              i))
          : (x10_int)(((x10_int)0x7fffffff));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10_array_RectRegion__closure__5> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__5>()) x10_array_RectRegion__closure__5(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__5(x10aux::ref<x10::array::RectRegion> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:204";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(saved_this->x10::array::RectRegion::min(
                                                              i))
          : (x10_int)(((x10_int)0x80000000));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10_array_RectRegion__closure__4> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__4>()) x10_array_RectRegion__closure__4(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__4(x10aux::ref<x10::array::RectRegion> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:203";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(saved_this->x10::array::RectRegion::max(
                                                              i))
          : (x10_int)((thatMax)->apply(((x10_int) ((i) - (saved_this->
                                                            FMGL(rank))))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
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
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMax = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_RectRegion__closure__3> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__3>()) x10_array_RectRegion__closure__3(that_saved_this, that_thatMax);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__3(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMax) : saved_this(saved_this), thatMax(thatMax) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:199";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i) < (saved_this->FMGL(rank))) ? (x10_int)(saved_this->x10::array::RectRegion::min(
                                                              i))
          : (x10_int)((thatMin)->apply(((x10_int) ((i) - (saved_this->
                                                            FMGL(rank))))));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
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
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMin = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_RectRegion__closure__2> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__2>()) x10_array_RectRegion__closure__2(that_saved_this, that_thatMin);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__2(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMin) : saved_this(saved_this), thatMin(thatMin) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:198";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10::lang::Math::min(saved_this->x10::array::RectRegion::max(
                                      i), (thatMax)->apply(i));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
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
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMax = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_RectRegion__closure__1> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__1>()) x10_array_RectRegion__closure__1(that_saved_this, that_thatMax);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__1(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMax) : saved_this(saved_this), thatMax(thatMax) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:180";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectRegion__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10::lang::Math::max(saved_this->x10::array::RectRegion::min(
                                      i), (thatMin)->apply(i));
        
    }
    
    // captured environment
    x10aux::ref<x10::array::RectRegion> saved_this;
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
        x10aux::ref<x10::array::RectRegion> that_saved_this = buf.read<x10aux::ref<x10::array::RectRegion> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_thatMin = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_RectRegion__closure__0> this_ = new (x10aux::alloc<x10_array_RectRegion__closure__0>()) x10_array_RectRegion__closure__0(that_saved_this, that_thatMin);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectRegion__closure__0(x10aux::ref<x10::array::RectRegion> saved_this, x10aux::ref<x10::lang::ValRail<x10_int > > thatMin) : saved_this(saved_this), thatMin(thatMin) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10:179";
    }

};

