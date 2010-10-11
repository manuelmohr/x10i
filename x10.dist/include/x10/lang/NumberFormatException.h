#ifndef __X10_LANG_NUMBERFORMATEXCEPTION_H
#define __X10_LANG_NUMBERFORMATEXCEPTION_H

#include <x10rt.h>


#define X10_LANG_ILLEGALARGUMENTEXCEPTION_H_NODEPS
#include <x10/lang/IllegalArgumentException.h>
#undef X10_LANG_ILLEGALARGUMENTEXCEPTION_H_NODEPS
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace compiler { 
class NativeRep;
} } 
namespace x10 { namespace lang { 

class NumberFormatException : public x10::lang::IllegalArgumentException 
 {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    void _constructor(
      );
    
    static x10aux::ref<x10::lang::NumberFormatException> _make(
             );
    
    void _constructor(
      x10aux::ref<x10::lang::String> message);
    
    static x10aux::ref<x10::lang::NumberFormatException> _make(
             x10aux::ref<x10::lang::String> message);
    
    
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
#endif // X10_LANG_NUMBERFORMATEXCEPTION_H

namespace x10 { namespace lang { 
class NumberFormatException;
} } 

#ifndef X10_LANG_NUMBERFORMATEXCEPTION_H_NODEPS
#define X10_LANG_NUMBERFORMATEXCEPTION_H_NODEPS
#include <x10/lang/IllegalArgumentException.h>
#include <x10/lang/String.h>
#include <x10/compiler/NativeRep.h>
#ifndef X10_LANG_NUMBERFORMATEXCEPTION_H_GENERICS
#define X10_LANG_NUMBERFORMATEXCEPTION_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::NumberFormatException::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::NumberFormatException> this_ = new (x10aux::alloc_remote<x10::lang::NumberFormatException>()) x10::lang::NumberFormatException();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_NUMBERFORMATEXCEPTION_H_GENERICS
#endif // __X10_LANG_NUMBERFORMATEXCEPTION_H_NODEPS
