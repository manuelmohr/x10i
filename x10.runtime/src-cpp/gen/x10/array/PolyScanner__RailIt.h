#ifndef __X10_ARRAY_POLYSCANNER__RAILIT_H
#define __X10_ARRAY_POLYSCANNER__RAILIT_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace array { 
class PolyScanner;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace array { 

class PolyScanner__RailIt : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Iterator<x10aux::ref<x10::lang::Rail<x10_int > > >::itable<x10::array::PolyScanner__RailIt > _itable_0;
    
    static x10::lang::Any::itable<x10::array::PolyScanner__RailIt > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::array::PolyScanner> FMGL(out__);
    
    virtual x10aux::ref<x10::array::PolyScanner> outerThis();
    x10_int FMGL(rank);
    
    x10aux::ref<x10::array::PolyScanner> FMGL(s);
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(x);
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(myMin);
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(myMax);
    
    x10_int FMGL(k);
    
    void _constructor(x10aux::ref<x10::array::PolyScanner> out__);
    
    static x10aux::ref<x10::array::PolyScanner__RailIt> _make(x10aux::ref<x10::array::PolyScanner> out__);
    
    virtual void init();
    virtual x10_boolean hasNext();
    virtual x10aux::ref<x10::lang::Rail<x10_int > > next();
    virtual void remove();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::PolyScanner__RailIt> this_,
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
#endif // X10_ARRAY_POLYSCANNER__RAILIT_H

namespace x10 { namespace array { 
class PolyScanner__RailIt;
} } 

#ifndef X10_ARRAY_POLYSCANNER__RAILIT_H_NODEPS
#define X10_ARRAY_POLYSCANNER__RAILIT_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Int.h>
#include <x10/array/PolyScanner.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#ifndef X10_ARRAY_POLYSCANNER__RAILIT_H_GENERICS
#define X10_ARRAY_POLYSCANNER__RAILIT_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::PolyScanner__RailIt::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::PolyScanner__RailIt> this_ = new (x10aux::alloc_remote<x10::array::PolyScanner__RailIt>()) x10::array::PolyScanner__RailIt();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::array::PolyScanner__RailIt::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::PolyScanner__RailIt> this_;
    if (rr.ref != 0) {
        this_ = x10::array::PolyScanner__RailIt::_deserializer<x10::array::PolyScanner__RailIt>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_POLYSCANNER__RAILIT_H_GENERICS
#endif // __X10_ARRAY_POLYSCANNER__RAILIT_H_NODEPS
