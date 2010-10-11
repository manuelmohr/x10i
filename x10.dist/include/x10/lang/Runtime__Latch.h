#ifndef __X10_LANG_RUNTIME__LATCH_H
#define __X10_LANG_RUNTIME__LATCH_H

#include <x10rt.h>


#define X10_LANG_RUNTIME__MONITOR_H_NODEPS
#include <x10/lang/Runtime__Monitor.h>
#undef X10_LANG_RUNTIME__MONITOR_H_NODEPS
#define X10_LANG_FUN_0_0_H_NODEPS
#include <x10/lang/Fun_0_0.h>
#undef X10_LANG_FUN_0_0_H_NODEPS
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 

class Runtime__Latch : public x10::lang::Runtime__Monitor   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_0<x10_boolean>::itable<x10::lang::Runtime__Latch > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__Latch > _itable_1;
    
    void _instance_init();
    
    x10_boolean FMGL(state);
    
    virtual void release();
    virtual void await();
    virtual x10_boolean apply();
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__Latch> _make();
    
    
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
#endif // X10_LANG_RUNTIME__LATCH_H

namespace x10 { namespace lang { 
class Runtime__Latch;
} } 

#ifndef X10_LANG_RUNTIME__LATCH_H_NODEPS
#define X10_LANG_RUNTIME__LATCH_H_NODEPS
#include <x10/lang/Runtime__Monitor.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Boolean.h>
#ifndef X10_LANG_RUNTIME__LATCH_H_GENERICS
#define X10_LANG_RUNTIME__LATCH_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Latch::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Latch> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Latch>()) x10::lang::Runtime__Latch();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__LATCH_H_GENERICS
#endif // __X10_LANG_RUNTIME__LATCH_H_NODEPS
