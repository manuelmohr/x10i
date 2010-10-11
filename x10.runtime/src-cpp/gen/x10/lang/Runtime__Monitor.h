#ifndef __X10_LANG_RUNTIME__MONITOR_H
#define __X10_LANG_RUNTIME__MONITOR_H

#include <x10rt.h>


#define X10_LANG_RUNTIME__LOCK_H_NODEPS
#include <x10/lang/Runtime__Lock.h>
#undef X10_LANG_RUNTIME__LOCK_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
class Runtime__Thread;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 

class Runtime__Monitor : public x10::lang::Runtime__Lock   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Runtime__Thread> > >
      FMGL(threads);
    
    virtual void await();
    virtual void release();
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__Monitor> _make();
    
    
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
#endif // X10_LANG_RUNTIME__MONITOR_H

namespace x10 { namespace lang { 
class Runtime__Monitor;
} } 

#ifndef X10_LANG_RUNTIME__MONITOR_H_NODEPS
#define X10_LANG_RUNTIME__MONITOR_H_NODEPS
#include <x10/lang/Runtime__Lock.h>
#include <x10/util/Stack.h>
#include <x10/lang/Runtime__Thread.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/Int.h>
#ifndef X10_LANG_RUNTIME__MONITOR_H_GENERICS
#define X10_LANG_RUNTIME__MONITOR_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Monitor::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Monitor> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Monitor>()) x10::lang::Runtime__Monitor();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__MONITOR_H_GENERICS
#endif // __X10_LANG_RUNTIME__MONITOR_H_NODEPS
