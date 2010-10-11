#ifndef __X10_LANG_RUNTIME__LOCK_H
#define __X10_LANG_RUNTIME__LOCK_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class Lock__ReentrantLock;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace compiler { 
class NativeClass;
} } 
namespace x10 { namespace lang { 

class Runtime__Lock : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Lock__ReentrantLock> FMGL(__NATIVE_FIELD__);
    
    void _constructor(x10aux::ref<x10::lang::Lock__ReentrantLock> id0);
    
    static x10aux::ref<x10::lang::Runtime__Lock> _make(x10aux::ref<x10::lang::Lock__ReentrantLock> id0);
    
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__Lock> _make();
    
    virtual void lock();
    virtual x10_boolean tryLock();
    virtual void unlock();
    virtual x10_int getHoldCount();
    
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
#endif // X10_LANG_RUNTIME__LOCK_H

namespace x10 { namespace lang { 
class Runtime__Lock;
} } 

#ifndef X10_LANG_RUNTIME__LOCK_H_NODEPS
#define X10_LANG_RUNTIME__LOCK_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Lock__ReentrantLock.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Int.h>
#include <x10/compiler/NativeClass.h>
#ifndef X10_LANG_RUNTIME__LOCK_H_GENERICS
#define X10_LANG_RUNTIME__LOCK_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Lock::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Lock> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Lock>()) x10::lang::Runtime__Lock();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__LOCK_H_GENERICS
#endif // __X10_LANG_RUNTIME__LOCK_H_NODEPS
