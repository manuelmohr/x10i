#ifndef __X10_LANG_RUNTIME__WORKER_H
#define __X10_LANG_RUNTIME__WORKER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_VOIDFUN_0_0_H_NODEPS
#include <x10/lang/VoidFun_0_0.h>
#undef X10_LANG_VOIDFUN_0_0_H_NODEPS
#define X10_LANG_LONG_STRUCT_H_NODEPS
#include <x10/lang/Long.struct_h>
#undef X10_LANG_LONG_STRUCT_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Runtime__Latch;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Activity;
} } 
namespace x10 { namespace lang { 
class Runtime__Deque;
} } 
namespace x10 { namespace util { 
class Random;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
class Runtime__Thread;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace compiler { 
class NativeString;
} } 
namespace x10 { namespace lang { 

class Runtime__Worker : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::VoidFun_0_0::itable<x10::lang::Runtime__Worker > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__Worker > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Runtime__Latch> FMGL(latch);
    
    static x10_int FMGL(BOUND);
    
    static inline x10_int FMGL(BOUND__get)() {
        return x10::lang::Runtime__Worker::FMGL(BOUND);
    }
    x10aux::ref<x10::lang::Activity> FMGL(activity);
    
    x10aux::ref<x10::lang::Runtime__Deque> FMGL(queue);
    
    x10aux::ref<x10::util::Random> FMGL(random);
    
    x10aux::ref<x10::util::GrowableRail<x10aux::ref<x10::lang::Activity> > >
      FMGL(debug);
    
    x10_long FMGL(tid);
    
    x10_int FMGL(workerId);
    
    virtual void setWorkerId(x10_int id);
    void _constructor(x10aux::ref<x10::lang::Runtime__Latch> latch, x10_int p);
    
    static x10aux::ref<x10::lang::Runtime__Worker> _make(x10aux::ref<x10::lang::Runtime__Latch> latch,
                                                         x10_int p);
    
    virtual x10_int size();
    virtual x10aux::ref<x10::lang::Activity> activity();
    x10aux::ref<x10::lang::Activity> poll();
    virtual x10aux::ref<x10::lang::Activity> steal();
    virtual void push(x10aux::ref<x10::lang::Activity> activity);
    virtual void apply();
    virtual void join(x10aux::ref<x10::lang::Runtime__Latch> latch);
    x10_boolean loop(x10aux::ref<x10::lang::Runtime__Latch> latch,
                     x10_boolean block);
    virtual void probe();
    virtual void dump(x10_int id, x10aux::ref<x10::lang::Runtime__Thread> thread);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::lang::Runtime__Worker> this_,
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
#endif // X10_LANG_RUNTIME__WORKER_H

namespace x10 { namespace lang { 
class Runtime__Worker;
} } 

#ifndef X10_LANG_RUNTIME__WORKER_H_NODEPS
#define X10_LANG_RUNTIME__WORKER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Runtime__Latch.h>
#include <x10/lang/Int.h>
#include <x10/lang/Activity.h>
#include <x10/lang/Runtime__Deque.h>
#include <x10/util/Random.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Long.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Runtime__Thread.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/compiler/NativeString.h>
#ifndef X10_LANG_RUNTIME__WORKER_H_GENERICS
#define X10_LANG_RUNTIME__WORKER_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Worker::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Worker> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Worker>()) x10::lang::Runtime__Worker();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::lang::Runtime__Worker::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::lang::Runtime__Worker> this_;
    if (rr.ref != 0) {
        this_ = x10::lang::Runtime__Worker::_deserializer<x10::lang::Runtime__Worker>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_LANG_RUNTIME__WORKER_H_GENERICS
#endif // __X10_LANG_RUNTIME__WORKER_H_NODEPS
