#ifndef __X10_COMPILER_NATIVE_H
#define __X10_COMPILER_NATIVE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANNOTATIONS_METHODANNOTATION_H_NODEPS
#include <x10/lang/annotations/MethodAnnotation.h>
#undef X10_LANG_ANNOTATIONS_METHODANNOTATION_H_NODEPS
#define X10_LANG_ANNOTATIONS_FIELDANNOTATION_H_NODEPS
#include <x10/lang/annotations/FieldAnnotation.h>
#undef X10_LANG_ANNOTATIONS_FIELDANNOTATION_H_NODEPS
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace compiler { 

class Native   {
    public:
    RTT_H_DECLS_INTERFACE
    
    x10aux::ref<x10::lang::String> FMGL(lang);
    
    x10aux::ref<x10::lang::String> FMGL(code);
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10aux::ref<x10::lang::String> (I::*code) (), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*lang) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), code(code), equals(equals), hashCode(hashCode), home(home), lang(lang), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10aux::ref<x10::lang::String> (I::*code) ();
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*lang) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::compiler::Native> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};

} } 
#endif // X10_COMPILER_NATIVE_H

namespace x10 { namespace compiler { 
class Native;
} } 

#ifndef X10_COMPILER_NATIVE_H_NODEPS
#define X10_COMPILER_NATIVE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/annotations/MethodAnnotation.h>
#include <x10/lang/annotations/FieldAnnotation.h>
#include <x10/lang/String.h>
#ifndef X10_COMPILER_NATIVE_H_GENERICS
#define X10_COMPILER_NATIVE_H_GENERICS
#endif // X10_COMPILER_NATIVE_H_GENERICS
#endif // __X10_COMPILER_NATIVE_H_NODEPS
