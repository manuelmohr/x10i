#ifndef __X10_COMPILER_NATIVEREP_H
#define __X10_COMPILER_NATIVEREP_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANNOTATIONS_CLASSANNOTATION_H_NODEPS
#include <x10/lang/annotations/ClassAnnotation.h>
#undef X10_LANG_ANNOTATIONS_CLASSANNOTATION_H_NODEPS
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace compiler { 

class NativeRep   {
    public:
    RTT_H_DECLS_INTERFACE
    
    x10aux::ref<x10::lang::String> FMGL(lang);
    
    x10aux::ref<x10::lang::String> FMGL(type);
    
    x10aux::ref<x10::lang::String> FMGL(constructedType);
    
    x10aux::ref<x10::lang::String> FMGL(_kwd__rtt);
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10aux::ref<x10::lang::String> (I::*constructedType) (), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*lang) (), x10aux::ref<x10::lang::String> (I::*_kwd__rtt) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*type) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), constructedType(constructedType), equals(equals), hashCode(hashCode), home(home), lang(lang), _kwd__rtt(_kwd__rtt), toString(toString), type(type), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10aux::ref<x10::lang::String> (I::*constructedType) ();
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*lang) ();
        x10aux::ref<x10::lang::String> (I::*_kwd__rtt) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*type) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::compiler::NativeRep> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};

} } 
#endif // X10_COMPILER_NATIVEREP_H

namespace x10 { namespace compiler { 
class NativeRep;
} } 

#ifndef X10_COMPILER_NATIVEREP_H_NODEPS
#define X10_COMPILER_NATIVEREP_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/annotations/ClassAnnotation.h>
#include <x10/lang/String.h>
#ifndef X10_COMPILER_NATIVEREP_H_GENERICS
#define X10_COMPILER_NATIVEREP_H_GENERICS
#endif // X10_COMPILER_NATIVEREP_H_GENERICS
#endif // __X10_COMPILER_NATIVEREP_H_NODEPS
