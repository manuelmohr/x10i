#ifndef __X10_LANG_RUNTIME__REMOTEFINISH_H
#define __X10_LANG_RUNTIME__REMOTEFINISH_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Runtime__Lock;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { namespace concurrent { namespace atomic { 
class AtomicInteger;
} } } } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class MultipleExceptions;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 

class Runtime__RemoteFinish : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > FMGL(exceptions);
    
    x10aux::ref<x10::lang::Runtime__Lock> FMGL(lock);
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(counts);
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(message);
    
    x10_int FMGL(length);
    
    x10aux::ref<x10::util::concurrent::atomic::AtomicInteger> FMGL(count);
    
    virtual void notifyActivityCreation();
    virtual void notifySubActivitySpawn(x10::lang::Place place);
    virtual void notifyActivityTermination(x10aux::ref<x10::lang::Runtime__RootFinish> r);
    virtual void pushException(x10aux::ref<x10::lang::Throwable> t);
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__RemoteFinish> _make();
    
    
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
#endif // X10_LANG_RUNTIME__REMOTEFINISH_H

namespace x10 { namespace lang { 
class Runtime__RemoteFinish;
} } 

#ifndef X10_LANG_RUNTIME__REMOTEFINISH_H_NODEPS
#define X10_LANG_RUNTIME__REMOTEFINISH_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Stack.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Runtime__Lock.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Int.h>
#include <x10/util/concurrent/atomic/AtomicInteger.h>
#include <x10/lang/Place.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/MultipleExceptions.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Pair.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_LANG_RUNTIME__REMOTEFINISH_H_GENERICS
#define X10_LANG_RUNTIME__REMOTEFINISH_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__RemoteFinish::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__RemoteFinish> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__RemoteFinish>()) x10::lang::Runtime__RemoteFinish();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__REMOTEFINISH_H_GENERICS
#endif // __X10_LANG_RUNTIME__REMOTEFINISH_H_NODEPS
