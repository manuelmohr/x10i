#ifndef __X10_COMPILER_REMOTEOPERATION_H
#define __X10_COMPILER_REMOTEOPERATION_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace compiler { 

class RemoteOperation : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    static void _kwd__xor(x10::lang::Place p, x10aux::ref<x10::lang::Rail<x10_long > > r,
                          x10_int i,
                          x10_long v);
    static void _kwd__xor(x10_int id, x10aux::ref<x10::lang::Rail<x10_long > > r,
                          x10_int i,
                          x10_long v);
    static void fence();
    void _constructor();
    
    static x10aux::ref<x10::compiler::RemoteOperation> _make(
             );
    
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::compiler::RemoteOperation> this_,
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
#endif // X10_COMPILER_REMOTEOPERATION_H

namespace x10 { namespace compiler { 
class RemoteOperation;
} } 

#ifndef X10_COMPILER_REMOTEOPERATION_H_NODEPS
#define X10_COMPILER_REMOTEOPERATION_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Place.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Long.h>
#include <x10/lang/Int.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/compiler/Native.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_COMPILER_REMOTEOPERATION_H_GENERICS
#define X10_COMPILER_REMOTEOPERATION_H_GENERICS
template<class __T> x10aux::ref<__T> x10::compiler::RemoteOperation::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::compiler::RemoteOperation> this_ = new (x10aux::alloc_remote<x10::compiler::RemoteOperation>()) x10::compiler::RemoteOperation();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::compiler::RemoteOperation::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::compiler::RemoteOperation> this_;
    if (rr.ref != 0) {
        this_ = x10::compiler::RemoteOperation::_deserializer<x10::compiler::RemoteOperation>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_COMPILER_REMOTEOPERATION_H_GENERICS
#endif // __X10_COMPILER_REMOTEOPERATION_H_NODEPS
