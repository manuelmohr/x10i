#ifndef __X10_LANG_RUNTIME__THREAD_H
#define __X10_LANG_RUNTIME__THREAD_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class Thread;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class InterruptedException;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Runtime__Worker;
} } 
namespace x10 { namespace compiler { 
class NativeClass;
} } 
namespace x10 { namespace lang { 

class Runtime__Thread : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Thread> FMGL(__NATIVE_FIELD__);
    
    void _constructor(x10aux::ref<x10::lang::Thread> id0);
    
    static x10aux::ref<x10::lang::Runtime__Thread> _make(x10aux::ref<x10::lang::Thread> id0);
    
    void _constructor(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::String> name);
    
    static x10aux::ref<x10::lang::Runtime__Thread> _make(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                                         x10aux::ref<x10::lang::String> name);
    
    static x10aux::ref<x10::lang::Runtime__Thread> currentThread(
      );
    virtual void start();
    static void sleep(x10_long millis);
    static void sleep(x10_long millis, x10_int nanos);
    static void park();
    static void parkNanos(x10_long nanos);
    virtual void unpark();
    virtual x10aux::ref<x10::lang::Object> worker();
    virtual void worker(x10aux::ref<x10::lang::Runtime__Worker> worker);
    virtual x10aux::ref<x10::lang::String> name();
    virtual void name(x10aux::ref<x10::lang::String> name);
    virtual x10_int locInt();
    static x10_long getTid();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::lang::Runtime__Thread> this_,
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
#endif // X10_LANG_RUNTIME__THREAD_H

namespace x10 { namespace lang { 
class Runtime__Thread;
} } 

#ifndef X10_LANG_RUNTIME__THREAD_H_NODEPS
#define X10_LANG_RUNTIME__THREAD_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Thread.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/String.h>
#include <x10/lang/Long.h>
#include <x10/lang/InterruptedException.h>
#include <x10/lang/Int.h>
#include <x10/lang/Runtime__Worker.h>
#include <x10/compiler/NativeClass.h>
#ifndef X10_LANG_RUNTIME__THREAD_H_GENERICS
#define X10_LANG_RUNTIME__THREAD_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Thread::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Thread> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Thread>()) x10::lang::Runtime__Thread();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::lang::Runtime__Thread::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::lang::Runtime__Thread> this_;
    if (rr.ref != 0) {
        this_ = x10::lang::Runtime__Thread::_deserializer<x10::lang::Runtime__Thread>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_LANG_RUNTIME__THREAD_H_GENERICS
#endif // __X10_LANG_RUNTIME__THREAD_H_NODEPS
