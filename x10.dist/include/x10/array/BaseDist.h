#ifndef __X10_ARRAY_BASEDIST_H
#define __X10_ARRAY_BASEDIST_H

#include <x10rt.h>


#define X10_ARRAY_DIST_H_NODEPS
#include <x10/array/Dist.h>
#undef X10_ARRAY_DIST_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace array { 
class PolyRegion;
} } 
namespace x10 { namespace array { 
class PolyRow;
} } 
namespace x10 { namespace array { 
class PolyMat;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace array { 
class Region;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace array { 
class Point;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ArrayIndexOutOfBoundsException;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Any;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class ArrayList;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class ArrayList;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace array { 

class BaseDist : public x10::array::Dist   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[4];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, x10::lang::Place>::itable<x10::array::BaseDist > _itable_0;
    
    static x10::lang::Any::itable<x10::array::BaseDist > _itable_1;
    
    static x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::BaseDist > _itable_2;
    
    void _instance_init();
    
    static x10aux::ref<x10::array::Dist> FMGL(UNIQUE);
    
    static void FMGL(UNIQUE__do_init)();
    static void FMGL(UNIQUE__init)();
    static volatile x10aux::status FMGL(UNIQUE__status);
    static inline x10aux::ref<x10::array::Dist> FMGL(UNIQUE__get)() {
        if (FMGL(UNIQUE__status) != x10aux::INITIALIZED) {
            FMGL(UNIQUE__init)();
        }
        return x10::array::BaseDist::FMGL(UNIQUE);
    }
    static x10aux::ref<x10::lang::Object> FMGL(UNIQUE__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(UNIQUE__id);
    
    static x10aux::ref<x10::array::Dist> makeUnique1();
    static x10aux::ref<x10::array::Dist> makeUnique1(x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps);
    static x10aux::ref<x10::array::Dist> makeBlock1(x10aux::ref<x10::array::Region> r,
                                                    x10_int axis);
    static x10aux::ref<x10::array::Dist> makeConstant1(x10aux::ref<x10::array::Region> r);
    static x10aux::ref<x10::array::Dist> makeUnique1(x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    static x10aux::ref<x10::array::Dist> makeConstant1(x10aux::ref<x10::array::Region> r,
                                                       x10::lang::Place p);
    static x10aux::ref<x10::array::Dist> makeCyclic1(x10aux::ref<x10::array::Region> r,
                                                     x10_int axis,
                                                     x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    static x10aux::ref<x10::array::Dist> makeBlock1(
      x10aux::ref<x10::array::Region> r,
      x10_int axis,
      x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    static x10aux::ref<x10::array::Dist> makeBlockCyclic1(
      x10aux::ref<x10::array::Region> r,
      x10_int axis,
      x10_int blockSize,
      x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    virtual x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
      places(
      );
    virtual x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >
      regions(
      );
    virtual x10aux::ref<x10::array::Region> get(x10::lang::Place p);
    virtual x10aux::ref<x10::array::Region> apply(
      x10::lang::Place p);
    virtual x10::lang::Place apply(x10aux::ref<x10::array::Point> pt);
    virtual x10::lang::Place apply(x10_int i0);
    virtual x10::lang::Place apply(x10_int i0, x10_int i1);
    virtual x10::lang::Place apply(x10_int i0, x10_int i1,
                                   x10_int i2);
    virtual x10::lang::Place apply(x10_int i0, x10_int i1,
                                   x10_int i2,
                                   x10_int i3);
    virtual x10aux::ref<x10::array::Dist> restriction(
      x10aux::ref<x10::array::Region> r);
    virtual x10aux::ref<x10::array::Dist> restriction(
      x10::lang::Place p);
    virtual x10_boolean isSubdistribution(x10aux::ref<x10::array::Dist> that);
    static x10_boolean isUnique(x10aux::ref<x10::lang::Rail<x10::lang::Place > > places);
    static x10_boolean isConstant(x10aux::ref<x10::lang::Rail<x10::lang::Place > > places);
    static x10::lang::Place onePlace(x10aux::ref<x10::lang::Rail<x10::lang::Place > > places);
    virtual x10_boolean equals(x10aux::ref<x10::lang::Any> thatObj);
    virtual x10_boolean contains(x10aux::ref<x10::array::Point> p);
    x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
      FMGL(places);
    
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >
      FMGL(regions);
    
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >
      FMGL(regionMap);
    
    void _constructor(x10aux::ref<x10::array::Region> r,
                      x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps,
                      x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs);
    
    static x10aux::ref<x10::array::BaseDist> _make(
             x10aux::ref<x10::array::Region> r,
             x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps,
             x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs);
    
    virtual x10aux::ref<x10::lang::String> toString(
      );
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_ARRAY_BASEDIST_H

namespace x10 { namespace array { 
class BaseDist;
} } 

#ifndef X10_ARRAY_BASEDIST_H_NODEPS
#define X10_ARRAY_BASEDIST_H_NODEPS
#include <x10/array/Dist.h>
#include <x10/lang/Int.h>
#include <x10/array/PolyRegion.h>
#include <x10/array/PolyRow.h>
#include <x10/array/PolyMat.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Place.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/array/Region.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Runtime.h>
#include <x10/util/Set.h>
#include <x10/lang/RuntimeException.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/array/Point.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ArrayIndexOutOfBoundsException.h>
#include <x10/lang/String.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Any.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/ValRail.h>
#include <x10/util/ArrayList.h>
#include <x10/util/ArrayList.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#ifndef X10_ARRAY_BASEDIST_H_GENERICS
#define X10_ARRAY_BASEDIST_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::BaseDist::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::BaseDist> this_ = new (x10aux::alloc_remote<x10::array::BaseDist>()) x10::array::BaseDist();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_ARRAY_BASEDIST_H_GENERICS
#endif // __X10_ARRAY_BASEDIST_H_NODEPS
