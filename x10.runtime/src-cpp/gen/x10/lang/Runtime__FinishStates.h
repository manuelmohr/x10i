#ifndef __X10_LANG_RUNTIME__FINISHSTATES_H
#define __X10_LANG_RUNTIME__FINISHSTATES_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_1_H_NODEPS
#include <x10/lang/Fun_0_1.h>
#undef X10_LANG_FUN_0_1_H_NODEPS
namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 
namespace x10 { namespace lang { 
class Runtime__RemoteFinish;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
class Runtime__Lock;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 

class Runtime__FinishStates : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_1<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> >::itable<x10::lang::Runtime__FinishStates > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__FinishStates > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::util::HashMap<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> > >
      FMGL(map);
    
    x10aux::ref<x10::lang::Runtime__Lock> FMGL(lock);
    
    virtual x10aux::ref<x10::lang::Runtime__RemoteFinish> apply(x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish);
    virtual void remove(x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish);
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__FinishStates> _make();
    
    
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
#endif // X10_LANG_RUNTIME__FINISHSTATES_H

namespace x10 { namespace lang { 
class Runtime__FinishStates;
} } 

#ifndef X10_LANG_RUNTIME__FINISHSTATES_H_NODEPS
#define X10_LANG_RUNTIME__FINISHSTATES_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/Runtime__RemoteFinish.h>
#include <x10/util/HashMap.h>
#include <x10/lang/Runtime__Lock.h>
#include <x10/util/HashMap.h>
#ifndef X10_LANG_RUNTIME__FINISHSTATES_H_GENERICS
#define X10_LANG_RUNTIME__FINISHSTATES_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__FinishStates::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__FinishStates> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__FinishStates>()) x10::lang::Runtime__FinishStates();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__FINISHSTATES_H_GENERICS
#endif // __X10_LANG_RUNTIME__FINISHSTATES_H_NODEPS
