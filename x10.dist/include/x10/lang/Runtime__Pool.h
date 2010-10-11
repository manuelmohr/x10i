#ifndef __X10_LANG_RUNTIME__POOL_H
#define __X10_LANG_RUNTIME__POOL_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_VOIDFUN_0_0_H_NODEPS
#include <x10/lang/VoidFun_0_0.h>
#undef X10_LANG_VOIDFUN_0_0_H_NODEPS
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
class Runtime__Lock;
} } 
namespace x10 { namespace lang { 
class Runtime__Semaphore;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Runtime__Worker;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Runtime__Thread;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class System;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Activity;
} } 
namespace x10 { namespace util { 
class Random;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 

class Runtime__Pool : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::VoidFun_0_0::itable<x10::lang::Runtime__Pool > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__Pool > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Runtime__Latch> FMGL(latch);
    
    x10_int FMGL(size);
    
    x10_int FMGL(spares);
    
    x10aux::ref<x10::lang::Runtime__Lock> FMGL(lock);
    
    x10aux::ref<x10::lang::Runtime__Semaphore> FMGL(semaphore);
    
    static x10_int FMGL(MAX);
    
    static inline x10_int FMGL(MAX__get)() {
        return x10::lang::Runtime__Pool::FMGL(MAX);
    }
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Runtime__Worker> > >
      FMGL(workers);
    
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Runtime__Thread> > >
      FMGL(threads);
    
    void _constructor(x10aux::ref<x10::lang::Runtime__Latch> latch, x10_int size);
    
    static x10aux::ref<x10::lang::Runtime__Pool> _make(x10aux::ref<x10::lang::Runtime__Latch> latch,
                                                       x10_int size);
    
    virtual void apply();
    virtual void increase();
    virtual void decrease(x10_int n);
    virtual void release();
    virtual x10aux::ref<x10::lang::Activity> scan(x10aux::ref<x10::util::Random> random,
                                                  x10aux::ref<x10::lang::Runtime__Latch> latch,
                                                  x10_boolean block);
    virtual void dump();
    
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
#endif // X10_LANG_RUNTIME__POOL_H

namespace x10 { namespace lang { 
class Runtime__Pool;
} } 

#ifndef X10_LANG_RUNTIME__POOL_H_NODEPS
#define X10_LANG_RUNTIME__POOL_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Runtime__Latch.h>
#include <x10/lang/Int.h>
#include <x10/lang/Runtime__Lock.h>
#include <x10/lang/Runtime__Semaphore.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Runtime__Worker.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Runtime__Thread.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/String.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/System.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Activity.h>
#include <x10/util/Random.h>
#include <x10/lang/Boolean.h>
#ifndef X10_LANG_RUNTIME__POOL_H_GENERICS
#define X10_LANG_RUNTIME__POOL_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__Pool::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Pool> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Pool>()) x10::lang::Runtime__Pool();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__POOL_H_GENERICS
#endif // __X10_LANG_RUNTIME__POOL_H_NODEPS
