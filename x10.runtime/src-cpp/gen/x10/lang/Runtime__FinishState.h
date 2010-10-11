#ifndef __X10_LANG_RUNTIME__FINISHSTATE_H
#define __X10_LANG_RUNTIME__FINISHSTATE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 

class Runtime__FinishState   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), void (I::*notifyActivityCreation) (), void (I::*notifyActivityTermination) (), void (I::*notifySubActivitySpawn) (x10::lang::Place), void (I::*pushException) (x10aux::ref<x10::lang::Throwable>), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) (), void (I::*waitForFinish) (x10_boolean)) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hashCode(hashCode), home(home), notifyActivityCreation(notifyActivityCreation), notifyActivityTermination(notifyActivityTermination), notifySubActivitySpawn(notifySubActivitySpawn), pushException(pushException), toString(toString), typeName(typeName), waitForFinish(waitForFinish) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        void (I::*notifyActivityCreation) ();
        void (I::*notifyActivityTermination) ();
        void (I::*notifySubActivitySpawn) (x10::lang::Place);
        void (I::*pushException) (x10aux::ref<x10::lang::Throwable>);
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
        void (I::*waitForFinish) (x10_boolean);
    };
    
    static void _serialize(x10aux::ref<x10::lang::Runtime__FinishState> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};

} } 
#endif // X10_LANG_RUNTIME__FINISHSTATE_H

namespace x10 { namespace lang { 
class Runtime__FinishState;
} } 

#ifndef X10_LANG_RUNTIME__FINISHSTATE_H_NODEPS
#define X10_LANG_RUNTIME__FINISHSTATE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Place.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Boolean.h>
#ifndef X10_LANG_RUNTIME__FINISHSTATE_H_GENERICS
#define X10_LANG_RUNTIME__FINISHSTATE_H_GENERICS
#endif // X10_LANG_RUNTIME__FINISHSTATE_H_GENERICS
#endif // __X10_LANG_RUNTIME__FINISHSTATE_H_NODEPS
