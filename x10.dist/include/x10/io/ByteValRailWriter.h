#ifndef __X10_IO_BYTEVALRAILWRITER_H
#define __X10_IO_BYTEVALRAILWRITER_H

#include <x10rt.h>


#define X10_IO_BYTEWRITER_H_NODEPS
#include <x10/io/ByteWriter.h>
#undef X10_IO_BYTEWRITER_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Byte;
} } 
#include <x10/lang/Byte.struct_h>
namespace x10 { namespace util { 
template<class FMGL(Element), class FMGL(Collection)> class Builder;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class ValRailBuilder;
} } 
namespace x10 { namespace io { 

class ByteValRailWriter : public x10::io::ByteWriter<x10aux::ref<x10::lang::ValRail<x10_byte > > >
  {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    void _constructor();
    
    static x10aux::ref<x10::io::ByteValRailWriter> _make();
    
    virtual x10aux::ref<x10::lang::ValRail<x10_byte > > toValRail(
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
#endif // X10_IO_BYTEVALRAILWRITER_H

namespace x10 { namespace io { 
class ByteValRailWriter;
} } 

#ifndef X10_IO_BYTEVALRAILWRITER_H_NODEPS
#define X10_IO_BYTEVALRAILWRITER_H_NODEPS
#include <x10/io/ByteWriter.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Byte.h>
#include <x10/util/Builder.h>
#include <x10/util/ValRailBuilder.h>
#ifndef X10_IO_BYTEVALRAILWRITER_H_GENERICS
#define X10_IO_BYTEVALRAILWRITER_H_GENERICS
template<class __T> x10aux::ref<__T> x10::io::ByteValRailWriter::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::io::ByteValRailWriter> this_ = new (x10aux::alloc_remote<x10::io::ByteValRailWriter>()) x10::io::ByteValRailWriter();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_IO_BYTEVALRAILWRITER_H_GENERICS
#endif // __X10_IO_BYTEVALRAILWRITER_H_NODEPS
