#ifndef __X10_ARRAY_DIST_H
#define __X10_ARRAY_DIST_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_1_H_NODEPS
#include <x10/lang/Fun_0_1.h>
#undef X10_LANG_FUN_0_1_H_NODEPS
namespace x10 { namespace array { 
class Point;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#define X10_LANG_ITERABLE_H_NODEPS
#include <x10/lang/Iterable.h>
#undef X10_LANG_ITERABLE_H_NODEPS
namespace x10 { namespace array { 
class Point;
} } 
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#define X10_LANG_PLACE_STRUCT_H_NODEPS
#include <x10/lang/Place.struct_h>
#undef X10_LANG_PLACE_STRUCT_H_NODEPS
namespace x10 { namespace array { 
class Region;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace array { 
class BaseDist;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Set;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class Any;
} } 
namespace x10 { namespace array { 

class Dist : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10aux::ref<x10::array::Region> FMGL(region);
    
    x10_boolean FMGL(unique);
    
    x10_boolean FMGL(constant);
    
    x10::lang::Place FMGL(onePlace);
    
    void _instance_init();
    
    x10_int rank();
    x10_boolean rect();
    x10_boolean zeroBased();
    x10_boolean rail();
    static x10aux::ref<x10::array::Dist> makeUnique();
    static x10aux::ref<x10::array::Dist> makeConstant(x10aux::ref<x10::array::Region> r);
    static x10aux::ref<x10::array::Dist> make(x10aux::ref<x10::array::Region> r);
    static x10aux::ref<x10::array::Dist> makeBlock(x10aux::ref<x10::array::Region> r,
                                                   x10_int axis);
    static x10aux::ref<x10::array::Dist> makeBlock(x10aux::ref<x10::array::Region> r);
    static x10aux::ref<x10::array::Dist> makeUnique(x10aux::ref<x10::lang::Rail<x10::lang::Place > > ps);
    static x10aux::ref<x10::array::Dist> makeUnique(x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    static x10aux::ref<x10::array::Dist> makeConstant(x10aux::ref<x10::array::Region> r,
                                                      x10::lang::Place p);
    static x10aux::ref<x10::array::Dist> makeBlock(x10aux::ref<x10::array::Region> r,
                                                   x10_int axis,
                                                   x10aux::ref<x10::util::Set<x10::lang::Place> > ps);
    virtual x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
      places(
      ) = 0;
    virtual x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >
      regions(
      ) = 0;
    virtual x10aux::ref<x10::array::Region> get(x10::lang::Place p) = 0;
    virtual x10::lang::Place apply(x10aux::ref<x10::array::Point> pt) = 0;
    virtual x10::lang::Place apply(x10_int i0) = 0;
    virtual x10::lang::Place apply(x10_int i0, x10_int i1) = 0;
    virtual x10::lang::Place apply(x10_int i0, x10_int i1,
                                   x10_int i2) = 0;
    virtual x10::lang::Place apply(x10_int i0, x10_int i1,
                                   x10_int i2,
                                   x10_int i3) = 0;
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
      iterator(
      );
    virtual x10aux::ref<x10::array::Dist> restriction(
      x10aux::ref<x10::array::Region> r) = 0;
    virtual x10_boolean isSubdistribution(x10aux::ref<x10::array::Dist> that) = 0;
    virtual x10_boolean equals(x10aux::ref<x10::lang::Any> that) = 0;
    virtual x10aux::ref<x10::array::Dist> restriction(
      x10::lang::Place p) = 0;
    virtual x10_boolean contains(x10aux::ref<x10::array::Point> p) = 0;
    virtual x10aux::ref<x10::array::Dist> __bar(x10aux::ref<x10::array::Region> r);
    virtual x10aux::ref<x10::array::Dist> __bar(x10::lang::Place p);
    void _constructor(x10aux::ref<x10::array::Region> region,
                      x10_boolean unique,
                      x10_boolean constant,
                      x10::lang::Place onePlace);
    
    x10aux::ref<x10::array::Region> region();
    x10_boolean unique();
    x10_boolean constant();
    x10::lang::Place onePlace();
    
    // Serialization
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_ARRAY_DIST_H

namespace x10 { namespace array { 
class Dist;
} } 

#ifndef X10_ARRAY_DIST_H_NODEPS
#define X10_ARRAY_DIST_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/array/Point.h>
#include <x10/lang/Place.h>
#include <x10/lang/Iterable.h>
#include <x10/array/Point.h>
#include <x10/array/Region.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Int.h>
#include <x10/array/BaseDist.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Set.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Any.h>
#ifndef X10_ARRAY_DIST_H_GENERICS
#define X10_ARRAY_DIST_H_GENERICS
#endif // X10_ARRAY_DIST_H_GENERICS
#endif // __X10_ARRAY_DIST_H_NODEPS
