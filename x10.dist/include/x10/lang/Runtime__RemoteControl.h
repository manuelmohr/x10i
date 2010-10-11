#ifndef __X10_LANG_RUNTIME__REMOTECONTROL_H
#define __X10_LANG_RUNTIME__REMOTECONTROL_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Runtime__Latch;
} } 
namespace x10 { namespace lang { 

class Runtime__RemoteControl : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::Box<x10aux::ref<x10::lang::Throwable> > > FMGL(e);
    
    x10aux::ref<x10::lang::Runtime__Latch> FMGL(latch);
    
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__RemoteControl> _make();
    
    
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
#endif // X10_LANG_RUNTIME__REMOTECONTROL_H

namespace x10 { namespace lang { 
class Runtime__RemoteControl;
} } 

#ifndef X10_LANG_RUNTIME__REMOTECONTROL_H_NODEPS
#define X10_LANG_RUNTIME__REMOTECONTROL_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Box.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Runtime__Latch.h>
#ifndef X10_LANG_RUNTIME__REMOTECONTROL_H_GENERICS
#define X10_LANG_RUNTIME__REMOTECONTROL_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__RemoteControl::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__RemoteControl> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__RemoteControl>()) x10::lang::Runtime__RemoteControl();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__REMOTECONTROL_H_GENERICS
#endif // __X10_LANG_RUNTIME__REMOTECONTROL_H_NODEPS
