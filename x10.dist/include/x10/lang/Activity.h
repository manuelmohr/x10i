#ifndef __X10_LANG_ACTIVITY_H
#define __X10_LANG_ACTIVITY_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class Runtime__Thread;
} } 
namespace x10 { namespace lang { 
class InterruptedException;
} } 
namespace x10 { namespace lang { 
class Runtime__FinishState;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
class Runtime__ClockPhases;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Clock;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 

class Activity : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    static x10_boolean sleep(x10_long millis);
    x10aux::ref<x10::lang::Runtime__FinishState> FMGL(finishState);
    
    x10_boolean FMGL(safe);
    
    x10aux::ref<x10::lang::VoidFun_0_0> FMGL(body);
    
    x10aux::ref<x10::lang::Runtime__ClockPhases> FMGL(clockPhases);
    
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Runtime__FinishState> > >
      FMGL(finishStack);
    
    void _constructor(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                      x10_boolean safe);
    
    static x10aux::ref<x10::lang::Activity> _make(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                                  x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                                                  x10_boolean safe);
    
    void _constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                      x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                      x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
                      x10aux::ref<x10::lang::ValRail<x10_int > > phases);
    
    static x10aux::ref<x10::lang::Activity> _make(
             x10aux::ref<x10::lang::VoidFun_0_0> body,
             x10aux::ref<x10::lang::Runtime__FinishState> finishState,
             x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
             x10aux::ref<x10::lang::ValRail<x10_int > > phases);
    
    void _constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                      x10_boolean safe);
    
    static x10aux::ref<x10::lang::Activity> _make(
             x10aux::ref<x10::lang::VoidFun_0_0> body,
             x10_boolean safe);
    
    virtual void run();
    x10aux::ref<x10::lang::Object> FMGL(tag);
    
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
#endif // X10_LANG_ACTIVITY_H

namespace x10 { namespace lang { 
class Activity;
} } 

#ifndef X10_LANG_ACTIVITY_H_NODEPS
#define X10_LANG_ACTIVITY_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Long.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/Runtime__Thread.h>
#include <x10/lang/InterruptedException.h>
#include <x10/lang/Runtime__FinishState.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Runtime__ClockPhases.h>
#include <x10/util/Stack.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Clock.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Int.h>
#include <x10/lang/Throwable.h>
#ifndef X10_LANG_ACTIVITY_H_GENERICS
#define X10_LANG_ACTIVITY_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Activity::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Activity> this_ = new (x10aux::alloc_remote<x10::lang::Activity>()) x10::lang::Activity();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_ACTIVITY_H_GENERICS
#endif // __X10_LANG_ACTIVITY_H_NODEPS
