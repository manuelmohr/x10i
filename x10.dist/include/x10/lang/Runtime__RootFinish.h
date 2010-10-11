#ifndef __X10_LANG_RUNTIME__ROOTFINISH_H
#define __X10_LANG_RUNTIME__ROOTFINISH_H

#include <x10rt.h>


#define X10_LANG_RUNTIME__LATCH_H_NODEPS
#include <x10/lang/Runtime__Latch.h>
#undef X10_LANG_RUNTIME__LATCH_H_NODEPS
#define X10_LANG_RUNTIME__FINISHSTATE_H_NODEPS
#include <x10/lang/Runtime__FinishState.h>
#undef X10_LANG_RUNTIME__FINISHSTATE_H_NODEPS
#define X10_LANG_RUNTIME__MORTAL_H_NODEPS
#include <x10/lang/Runtime__Mortal.h>
#undef X10_LANG_RUNTIME__MORTAL_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class Runtime__RemoteFinish;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
class Error;
} } 
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace lang { 
class MultipleExceptions;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
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
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
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
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 

class Runtime__RootFinish : public x10::lang::Runtime__Latch   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[5];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_0<x10_boolean>::itable<x10::lang::Runtime__RootFinish > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__RootFinish > _itable_1;
    
    static x10::lang::Runtime__FinishState::itable<x10::lang::Runtime__RootFinish > _itable_2;
    
    static x10::lang::Runtime__Mortal::itable<x10::lang::Runtime__RootFinish > _itable_3;
    
    virtual x10_boolean _isMortal() { return true; }
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Rail<x10_int > > FMGL(counts);
    
    x10aux::ref<x10::lang::Rail<x10_boolean > > FMGL(seen);
    
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > FMGL(exceptions);
    
    void _constructor();
    
    static x10aux::ref<x10::lang::Runtime__RootFinish> _make();
    
    virtual x10aux::ref<x10::lang::Runtime__RemoteFinish> makeRemote();
    void notifySubActivitySpawnLocal(x10::lang::Place place);
    void notifyActivityTerminationLocal();
    void pushExceptionLocal(x10aux::ref<x10::lang::Throwable> t);
    virtual void waitForFinish(x10_boolean safe);
    virtual void notify(x10aux::ref<x10::lang::ValRail<x10_int > > rail);
    virtual void notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail);
    virtual void notify(x10aux::ref<x10::lang::ValRail<x10_int > > rail, x10aux::ref<x10::lang::Throwable> t);
    virtual void notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail,
                         x10aux::ref<x10::lang::Throwable> t);
    virtual void notifySubActivitySpawn(x10::lang::Place place);
    virtual void notifyActivityCreation();
    virtual void notifyActivityTermination();
    virtual void pushException(x10aux::ref<x10::lang::Throwable> t);
    
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
#endif // X10_LANG_RUNTIME__ROOTFINISH_H

namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 

#ifndef X10_LANG_RUNTIME__ROOTFINISH_H_NODEPS
#define X10_LANG_RUNTIME__ROOTFINISH_H_NODEPS
#include <x10/lang/Runtime__Latch.h>
#include <x10/lang/Runtime__FinishState.h>
#include <x10/lang/Runtime__Mortal.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Int.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Boolean.h>
#include <x10/util/Stack.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Place.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/Runtime__RemoteFinish.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Error.h>
#include <x10/lang/RuntimeException.h>
#include <x10/lang/MultipleExceptions.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Pair.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_LANG_RUNTIME__ROOTFINISH_H_GENERICS
#define X10_LANG_RUNTIME__ROOTFINISH_H_GENERICS
template<class __T> x10aux::ref<__T> x10::lang::Runtime__RootFinish::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__RootFinish> this_ = new (x10aux::alloc_remote<x10::lang::Runtime__RootFinish>()) x10::lang::Runtime__RootFinish();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__ROOTFINISH_H_GENERICS
#endif // __X10_LANG_RUNTIME__ROOTFINISH_H_NODEPS
