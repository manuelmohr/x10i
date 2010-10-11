#ifndef __X10_LANG_CLOCK_H
#define __X10_LANG_CLOCK_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class ClockUseException;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Math;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 

class Clock : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10aux::ref<x10::lang::String> FMGL(name);
    
    void _instance_init();
    
    static x10aux::ref<x10::lang::Clock> make();
    static x10_int FMGL(FIRST_PHASE);
    
    static inline x10_int FMGL(FIRST_PHASE__get)() {
        return x10::lang::Clock::FMGL(FIRST_PHASE);
    }
    static x10aux::ref<x10::lang::Clock> make(x10aux::ref<x10::lang::String> name);
    x10_int FMGL(count);
    
    x10_int FMGL(alive);
    
    x10_int FMGL(phase);
    
    void _constructor(x10aux::ref<x10::lang::String> name);
    
    static x10aux::ref<x10::lang::Clock> _make(x10aux::ref<x10::lang::String> name);
    
    x10_int get();
    x10aux::ref<x10::util::Box<x10_int> > put(x10_int ph);
    x10_int remove();
    void resumeLocal();
    void dropLocal(x10_int ph);
    virtual x10_int _kwd__register();
    virtual void resumeUnsafe();
    virtual void nextUnsafe();
    virtual void dropUnsafe();
    virtual void dropInternal();
    virtual x10_boolean registered();
    virtual x10_boolean dropped();
    virtual x10_int phase();
    virtual void resume();
    virtual void next();
    virtual void drop();
    x10aux::ref<x10::lang::String> name();
    
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
#endif // X10_LANG_CLOCK_H

namespace x10 { namespace lang { 
class Clock;
} } 

#ifndef X10_LANG_CLOCK_H_NODEPS
#define X10_LANG_CLOCK_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/String.h>
#include <x10/lang/Int.h>
#include <x10/lang/Runtime.h>
#include <x10/util/Box.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/ClockUseException.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Math.h>
#include <x10/lang/Boolean.h>
#ifndef X10_LANG_CLOCK_H_GENERICS
#define X10_LANG_CLOCK_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Clock::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Clock> this_ = new (x10aux::alloc_remote<x10::lang::Clock>()) x10::lang::Clock();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_CLOCK_H_GENERICS
#endif // __X10_LANG_CLOCK_H_NODEPS
