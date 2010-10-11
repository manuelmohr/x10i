#ifndef __X10_ARRAY_POINT_H
#define __X10_ARRAY_POINT_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_1_H_NODEPS
#include <x10/lang/Fun_0_1.h>
#undef X10_LANG_FUN_0_1_H_NODEPS
#define X10_UTIL_ORDERED_H_NODEPS
#include <x10/util/Ordered.h>
#undef X10_UTIL_ORDERED_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Any;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace array { 

class Point : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10_int FMGL(rank);
    
    static x10aux::itable_entry _itables[4];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10::array::Point > _itable_0;
    
    static x10::lang::Any::itable<x10::array::Point > _itable_1;
    
    static x10::util::Ordered<x10aux::ref<x10::array::Point> >::itable<x10::array::Point > _itable_2;
    
    void _instance_init();
    
    virtual x10_int apply(x10_int i);
    virtual x10aux::ref<x10::lang::ValRail<x10_int > > coords();
    static x10aux::ref<x10::array::Point> make(x10aux::ref<x10::lang::ValRail<x10_int > > cs);
    static x10aux::ref<x10::array::Point> make(x10aux::ref<x10::lang::Rail<x10_int > > cs);
    static x10aux::ref<x10::array::Point> make(x10_int rank, x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init);
    static x10aux::ref<x10::array::Point> make(x10_int i0);
    static x10aux::ref<x10::array::Point> make(x10_int i0, x10_int i1);
    static x10aux::ref<x10::array::Point> make(x10_int i0, x10_int i1, x10_int i2);
    static x10aux::ref<x10::array::Point> make(x10_int i0, x10_int i1, x10_int i2,
                                               x10_int i3);
    static x10aux::ref<x10::array::Point> __implicit_convert(x10aux::ref<x10::lang::Rail<x10_int > > r);
    static x10aux::ref<x10::array::Point> __implicit_convert(x10aux::ref<x10::lang::ValRail<x10_int > > r);
    virtual x10aux::ref<x10::array::Point> __plus();
    virtual x10aux::ref<x10::array::Point> __minus();
    virtual x10aux::ref<x10::array::Point> __plus(x10aux::ref<x10::array::Point> that);
    virtual x10aux::ref<x10::array::Point> __minus(x10aux::ref<x10::array::Point> that);
    virtual x10aux::ref<x10::array::Point> __times(x10aux::ref<x10::array::Point> that);
    virtual x10aux::ref<x10::array::Point> __over(x10aux::ref<x10::array::Point> that);
    virtual x10aux::ref<x10::array::Point> __plus(x10_int c);
    virtual x10aux::ref<x10::array::Point> __minus(x10_int c);
    virtual x10aux::ref<x10::array::Point> __times(x10_int c);
    virtual x10aux::ref<x10::array::Point> __over(x10_int c);
    virtual x10aux::ref<x10::array::Point> __inv_plus(x10_int c);
    virtual x10aux::ref<x10::array::Point> __inv_minus(x10_int c);
    virtual x10aux::ref<x10::array::Point> __inv_times(x10_int c);
    virtual x10aux::ref<x10::array::Point> __inv_over(x10_int c);
    virtual x10_int hashCode();
    virtual x10_boolean equals(x10aux::ref<x10::lang::Any> other);
    virtual x10_boolean __lt(x10aux::ref<x10::array::Point> that);
    virtual x10_boolean __gt(x10aux::ref<x10::array::Point> that);
    virtual x10_boolean __le(x10aux::ref<x10::array::Point> that);
    virtual x10_boolean __ge(x10aux::ref<x10::array::Point> that);
    virtual x10aux::ref<x10::lang::String> toString();
    x10aux::ref<x10::lang::ValRail<x10_int > > FMGL(coords);
    
    void _constructor(x10aux::ref<x10::lang::ValRail<x10_int > > cs);
    
    static x10aux::ref<x10::array::Point> _make(x10aux::ref<x10::lang::ValRail<x10_int > > cs);
    
    x10_int rank();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::Point> this_,
                                   x10aux::serialization_buffer& buf);
    
    public: x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_ARRAY_POINT_H

namespace x10 { namespace array { 
class Point;
} } 

#ifndef X10_ARRAY_POINT_H_NODEPS
#define X10_ARRAY_POINT_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/util/Ordered.h>
#include <x10/lang/Int.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Any.h>
#include <x10/lang/String.h>
#ifndef X10_ARRAY_POINT_H_GENERICS
#define X10_ARRAY_POINT_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::Point::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::Point> this_ = new (x10aux::alloc_remote<x10::array::Point>()) x10::array::Point();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::array::Point::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::Point> this_;
    if (rr.ref != 0) {
        this_ = x10::array::Point::_deserializer<x10::array::Point>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_POINT_H_GENERICS
#endif // __X10_ARRAY_POINT_H_NODEPS
