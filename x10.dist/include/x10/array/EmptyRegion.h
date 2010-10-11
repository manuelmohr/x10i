#ifndef __X10_ARRAY_EMPTYREGION_H
#define __X10_ARRAY_EMPTYREGION_H

#include <x10rt.h>


#define X10_ARRAY_REGION_H_NODEPS
#include <x10/array/Region.h>
#undef X10_ARRAY_REGION_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class IllegalArgumentException;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace array { 
class Point;
} } 
namespace x10 { namespace lang { 
class IllegalOperationException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace array { 
class EmptyRegion__ERIterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace array { 
class Region__Scanner;
} } 
namespace x10 { namespace lang { 
class UnsupportedOperationException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace array { 

class EmptyRegion : public x10::array::Region   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::EmptyRegion > _itable_0;
    
    static x10::lang::Any::itable<x10::array::EmptyRegion > _itable_1;
    
    void _instance_init();
    
    void _constructor(x10_int rank);
    
    static x10aux::ref<x10::array::EmptyRegion> _make(x10_int rank);
    
    virtual x10_boolean isConvex();
    virtual x10_boolean isEmpty();
    virtual x10_int size();
    virtual x10aux::ref<x10::array::Region> intersection(x10aux::ref<x10::array::Region> that);
    virtual x10aux::ref<x10::array::Region> product(x10aux::ref<x10::array::Region> that);
    virtual x10aux::ref<x10::array::Region> projection(x10_int axis);
    virtual x10aux::ref<x10::array::Region> translate(x10aux::ref<x10::array::Point> p);
    virtual x10aux::ref<x10::array::Region> eliminate(x10_int i);
    virtual x10aux::ref<x10::array::Region> computeBoundingBox();
    virtual x10aux::ref<x10::lang::ValRail<x10_int > > min();
    virtual x10aux::ref<x10::lang::ValRail<x10_int > > max();
    virtual x10_boolean contains(x10aux::ref<x10::array::Region> that);
    virtual x10_boolean contains(x10aux::ref<x10::array::Point> p);
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
      iterator(
      );
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >
      scanners(
      );
    virtual x10aux::ref<x10::lang::String> toString();
    public: virtual x10_int min(x10_int p0);
    public: virtual x10_int max(x10_int p0);
    public: virtual x10_boolean contains(x10_int p0);
    public: virtual x10_boolean contains(x10_int p0, x10_int p1);
    public: virtual x10_boolean contains(x10_int p0, x10_int p1, x10_int p2);
    public: virtual x10_boolean contains(x10_int p0, x10_int p1, x10_int p2, x10_int p3);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::EmptyRegion> this_,
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
#endif // X10_ARRAY_EMPTYREGION_H

namespace x10 { namespace array { 
class EmptyRegion;
} } 

#ifndef X10_ARRAY_EMPTYREGION_H_NODEPS
#define X10_ARRAY_EMPTYREGION_H_NODEPS
#include <x10/array/Region.h>
#include <x10/lang/Int.h>
#include <x10/lang/IllegalArgumentException.h>
#include <x10/lang/String.h>
#include <x10/lang/Boolean.h>
#include <x10/array/Point.h>
#include <x10/lang/IllegalOperationException.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Iterator.h>
#include <x10/array/EmptyRegion__ERIterator.h>
#include <x10/lang/Iterator.h>
#include <x10/array/Region__Scanner.h>
#include <x10/lang/UnsupportedOperationException.h>
#include <x10/lang/Iterator.h>
#ifndef X10_ARRAY_EMPTYREGION_H_GENERICS
#define X10_ARRAY_EMPTYREGION_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::EmptyRegion::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::EmptyRegion> this_ = new (x10aux::alloc_remote<x10::array::EmptyRegion>()) x10::array::EmptyRegion();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::array::EmptyRegion::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::EmptyRegion> this_;
    if (rr.ref != 0) {
        this_ = x10::array::EmptyRegion::_deserializer<x10::array::EmptyRegion>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_EMPTYREGION_H_GENERICS
#endif // __X10_ARRAY_EMPTYREGION_H_NODEPS
