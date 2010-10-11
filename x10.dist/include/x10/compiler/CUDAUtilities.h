#ifndef __X10_COMPILER_CUDAUTILITIES_H
#define __X10_COMPILER_CUDAUTILITIES_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class UInt;
} } 
#include <x10/lang/UInt.struct_h>
namespace x10 { namespace compiler { 

class CUDAUtilities : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    static x10_uint autoBlocks();
    static x10_uint autoThreads();
    void _constructor();
    
    static x10aux::ref<x10::compiler::CUDAUtilities> _make();
    
    
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
#endif // X10_COMPILER_CUDAUTILITIES_H

namespace x10 { namespace compiler { 
class CUDAUtilities;
} } 

#ifndef X10_COMPILER_CUDAUTILITIES_H_NODEPS
#define X10_COMPILER_CUDAUTILITIES_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/UInt.h>
#ifndef X10_COMPILER_CUDAUTILITIES_H_GENERICS
#define X10_COMPILER_CUDAUTILITIES_H_GENERICS
template<class __T> x10aux::ref<__T> x10::compiler::CUDAUtilities::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::compiler::CUDAUtilities> this_ = new (x10aux::alloc_remote<x10::compiler::CUDAUtilities>()) x10::compiler::CUDAUtilities();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_COMPILER_CUDAUTILITIES_H_GENERICS
#endif // __X10_COMPILER_CUDAUTILITIES_H_NODEPS
