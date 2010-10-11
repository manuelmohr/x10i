#ifndef __X10_ARRAY_POLYSCANNER_H
#define __X10_ARRAY_POLYSCANNER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_ARRAY_REGION__SCANNER_H_NODEPS
#include <x10/array/Region__Scanner.h>
#undef X10_ARRAY_REGION__SCANNER_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace array { 
class PolyMat;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace array { 
class VarMat;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace array { 
class PolyRow;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace array { 
class UnboundedRegionException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace array { 
class Point;
} } 
namespace x10 { namespace array { 
class PolyScanner__PointIt;
} } 
namespace x10 { namespace io { 
class Printer;
} } 
namespace x10 { namespace array { 

class PolyScanner : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10_int FMGL(rank);
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::array::Region__Scanner::itable<x10::array::PolyScanner > _itable_0;
    
    static x10::lang::Any::itable<x10::array::PolyScanner > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::array::PolyMat> FMGL(C);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > FMGL(myMin);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > FMGL(myMax);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > FMGL(minSum);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > FMGL(maxSum);
    
    x10aux::ref<x10::lang::Rail<x10_boolean > > FMGL(parFlags);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > > >
      FMGL(min2);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > > >
      FMGL(max2);
    
    static x10aux::ref<x10::array::PolyScanner> make(x10aux::ref<x10::array::PolyMat> pm);
    void _constructor(x10aux::ref<x10::array::PolyMat> pm);
    
    static x10aux::ref<x10::array::PolyScanner> _make(x10aux::ref<x10::array::PolyMat> pm);
    
    void init();
    void init(x10aux::ref<x10::array::PolyMat> pm, x10_int axis);
    virtual void set(x10_int axis, x10_int v);
    virtual x10_int min(x10_int axis);
    virtual x10_int max(x10_int axis);
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
      iterator(
      );
    virtual void printInfo(x10aux::ref<x10::io::Printer> ps);
    virtual void printInfo2(x10aux::ref<x10::io::Printer> ps);
    x10_int rank();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::PolyScanner> this_,
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
#endif // X10_ARRAY_POLYSCANNER_H

namespace x10 { namespace array { 
class PolyScanner;
} } 

#ifndef X10_ARRAY_POLYSCANNER_H_NODEPS
#define X10_ARRAY_POLYSCANNER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/array/Region__Scanner.h>
#include <x10/lang/Int.h>
#include <x10/array/PolyMat.h>
#include <x10/lang/Rail.h>
#include <x10/array/VarMat.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/array/PolyRow.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/String.h>
#include <x10/array/UnboundedRegionException.h>
#include <x10/lang/Iterator.h>
#include <x10/array/Point.h>
#include <x10/array/PolyScanner__PointIt.h>
#include <x10/io/Printer.h>
#ifndef X10_ARRAY_POLYSCANNER_H_GENERICS
#define X10_ARRAY_POLYSCANNER_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::PolyScanner::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::PolyScanner> this_ = new (x10aux::alloc_remote<x10::array::PolyScanner>()) x10::array::PolyScanner();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::array::PolyScanner::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::PolyScanner> this_;
    if (rr.ref != 0) {
        this_ = x10::array::PolyScanner::_deserializer<x10::array::PolyScanner>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_POLYSCANNER_H_GENERICS
#endif // __X10_ARRAY_POLYSCANNER_H_NODEPS
