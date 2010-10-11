#ifndef __X10_IO_WRITABLE_H
#define __X10_IO_WRITABLE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace io { 
class Writer;
} } 
namespace x10 { namespace io { 
class IOException;
} } 
namespace x10 { namespace io { 

class Writable   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) (), void (I::*write) (x10aux::ref<x10::io::Writer>)) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hashCode(hashCode), home(home), toString(toString), typeName(typeName), write(write) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
        void (I::*write) (x10aux::ref<x10::io::Writer>);
    };
    
    static void _serialize(x10aux::ref<x10::io::Writable> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};

} } 
#endif // X10_IO_WRITABLE_H

namespace x10 { namespace io { 
class Writable;
} } 

#ifndef X10_IO_WRITABLE_H_NODEPS
#define X10_IO_WRITABLE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/io/Writer.h>
#include <x10/io/IOException.h>
#ifndef X10_IO_WRITABLE_H_GENERICS
#define X10_IO_WRITABLE_H_GENERICS
#endif // X10_IO_WRITABLE_H_GENERICS
#endif // __X10_IO_WRITABLE_H_NODEPS
