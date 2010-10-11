#ifndef __X10_LANG_RUNTIME__DEQUE_H
#define __X10_LANG_RUNTIME__DEQUE_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class Deque;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace compiler { 
class NativeClass;
} } 
namespace x10 { namespace lang { 

class Runtime__Deque : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Deque> FMGL(__NATIVE_FIELD__);
    
    void _constructor(x10aux::ref<x10::lang::Deque> id0);
    
    static x10aux::ref<x10::lang::Runtime__Deque> _make(x10aux::ref<x10::lang::Deque> id0);
    
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__Deque> _make();
    
    virtual x10_int size();
    virtual x10aux::ref<x10::lang::Object> poll();
    virtual void push(x10aux::ref<x10::lang::Object> t);
    virtual x10aux::ref<x10::lang::Object> steal();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::lang::Runtime__Deque> this_,
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
#endif // X10_LANG_RUNTIME__DEQUE_H

namespace x10 { namespace lang { 
class Runtime__Deque;
} } 

#ifndef X10_LANG_RUNTIME__DEQUE_H_NODEPS
#define X10_LANG_RUNTIME__DEQUE_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Deque.h>
#include <x10/lang/Int.h>
#include <x10/compiler/NativeClass.h>
#ifndef X10_LANG_RUNTIME__DEQUE_H_GENERICS
#define X10_LANG_RUNTIME__DEQUE_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Deque::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Deque> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Deque>()) x10::lang::Runtime__Deque();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::lang::Runtime__Deque::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::lang::Runtime__Deque> this_;
    if (rr.ref != 0) {
        this_ = x10::lang::Runtime__Deque::_deserializer<x10::lang::Runtime__Deque>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_LANG_RUNTIME__DEQUE_H_GENERICS
#endif // __X10_LANG_RUNTIME__DEQUE_H_NODEPS
