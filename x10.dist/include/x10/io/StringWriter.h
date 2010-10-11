#ifndef __X10_IO_STRINGWRITER_H
#define __X10_IO_STRINGWRITER_H

#include <x10rt.h>


#define X10_IO_WRITER_H_NODEPS
#include <x10/io/Writer.h>
#undef X10_IO_WRITER_H_NODEPS
namespace x10 { namespace util { 
class StringBuilder;
} } 
namespace x10 { namespace lang { 
class Byte;
} } 
#include <x10/lang/Byte.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
class Char;
} } 
#include <x10/lang/Char.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace io { 
class IOException;
} } 
namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace io { 

class StringWriter : public x10::io::Writer   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::StringBuilder> FMGL(b);
    
    void _constructor();
    
    static x10aux::ref<x10::io::StringWriter> _make();
    
    virtual void write(x10_byte x);
    virtual x10_int size();
    virtual x10aux::ref<x10::lang::String> result();
    virtual void flush();
    virtual void close();
    public: template<class FMGL(T1974)> void write(x10aux::ref<x10::io::Marshal<FMGL(T1974)> > p0, FMGL(T1974) p1);
    public: virtual void write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0);
    public: virtual void write(x10aux::ref<x10::lang::Rail<x10_byte > > p0);
    public: virtual void write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0, x10_int p1, x10_int p2);
    public: virtual void write(x10aux::ref<x10::lang::Rail<x10_byte > > p0, x10_int p1, x10_int p2);
    
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
#endif // X10_IO_STRINGWRITER_H

namespace x10 { namespace io { 
class StringWriter;
} } 

#ifndef X10_IO_STRINGWRITER_H_NODEPS
#define X10_IO_STRINGWRITER_H_NODEPS
#include <x10/io/Writer.h>
#include <x10/util/StringBuilder.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Char.h>
#include <x10/lang/Int.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/String.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/io/IOException.h>
#include <x10/io/Marshal.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#ifndef X10_IO_STRINGWRITER_H_GENERICS
#define X10_IO_STRINGWRITER_H_GENERICS
template<class FMGL(T1974)> void x10::io::StringWriter::write(x10aux::ref<x10::io::Marshal<FMGL(T1974)> > p0, FMGL(T1974) p1) {
    x10::io::Writer::write<FMGL(T1974)>(p0, p1);
}
template<class __T> x10aux::ref<__T> x10::io::StringWriter::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::io::StringWriter> this_ = new (x10aux::alloc_remote<x10::io::StringWriter>()) x10::io::StringWriter();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_IO_STRINGWRITER_H_GENERICS
#endif // __X10_IO_STRINGWRITER_H_NODEPS
