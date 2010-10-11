#ifndef __X10_IO_PUTBACKREADER_H
#define __X10_IO_PUTBACKREADER_H

#include <x10rt.h>


#define X10_IO_FILTERREADER_H_NODEPS
#include <x10/io/FilterReader.h>
#undef X10_IO_FILTERREADER_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
class Byte;
} } 
#include <x10/lang/Byte.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace io { 
class Reader;
} } 
namespace x10 { namespace io { 
class IOException;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 
namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace io { 

class PutbackReader : public x10::io::FilterReader   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::GrowableRail<x10_byte > > FMGL(putback);
    
    virtual x10aux::ref<x10::util::GrowableRail<x10_byte > > putback();
    void _constructor(x10aux::ref<x10::io::Reader> r);
    
    static x10aux::ref<x10::io::PutbackReader> _make(x10aux::ref<x10::io::Reader> r);
    
    virtual x10_byte read();
    virtual void putback(x10_byte p);
    public: template<class FMGL(T1971)> FMGL(T1971) read(x10aux::ref<x10::io::Marshal<FMGL(T1971)> > p0);
    public: template<class FMGL(T1972)> void read(x10aux::ref<x10::io::Marshal<FMGL(T1972)> > p0, x10aux::ref<x10::lang::Rail<FMGL(T1972) > > p1);
    public: template<class FMGL(T1973)> void read(x10aux::ref<x10::io::Marshal<FMGL(T1973)> > p0, x10aux::ref<x10::lang::Rail<FMGL(T1973) > > p1, x10_int p2, x10_int p3);
    
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
#endif // X10_IO_PUTBACKREADER_H

namespace x10 { namespace io { 
class PutbackReader;
} } 

#ifndef X10_IO_PUTBACKREADER_H_NODEPS
#define X10_IO_PUTBACKREADER_H_NODEPS
#include <x10/io/FilterReader.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/io/Reader.h>
#include <x10/io/IOException.h>
#include <x10/lang/Int.h>
#include <x10/io/Marshal.h>
#include <x10/io/Marshal.h>
#include <x10/lang/Rail.h>
#include <x10/io/Marshal.h>
#include <x10/lang/Rail.h>
#ifndef X10_IO_PUTBACKREADER_H_GENERICS
#define X10_IO_PUTBACKREADER_H_GENERICS
template<class FMGL(T1971)> FMGL(T1971) x10::io::PutbackReader::read(x10aux::ref<x10::io::Marshal<FMGL(T1971)> > p0) {
    return x10::io::FilterReader::read<FMGL(T1971)>(p0);
}
template<class FMGL(T1972)> void x10::io::PutbackReader::read(x10aux::ref<x10::io::Marshal<FMGL(T1972)> > p0, x10aux::ref<x10::lang::Rail<FMGL(T1972) > > p1) {
    x10::io::FilterReader::read<FMGL(T1972)>(p0, p1);
}
template<class FMGL(T1973)> void x10::io::PutbackReader::read(x10aux::ref<x10::io::Marshal<FMGL(T1973)> > p0, x10aux::ref<x10::lang::Rail<FMGL(T1973) > > p1, x10_int p2, x10_int p3) {
    x10::io::FilterReader::read<FMGL(T1973)>(p0, p1, p2, p3);
}
template<class __T> x10aux::ref<__T> x10::io::PutbackReader::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::io::PutbackReader> this_ = new (x10aux::alloc_remote<x10::io::PutbackReader>()) x10::io::PutbackReader();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_IO_PUTBACKREADER_H_GENERICS
#endif // __X10_IO_PUTBACKREADER_H_NODEPS
