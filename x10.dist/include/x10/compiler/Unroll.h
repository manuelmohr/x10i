#ifndef __X10_COMPILER_UNROLL_H
#define __X10_COMPILER_UNROLL_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANNOTATIONS_STATEMENTANNOTATION_H_NODEPS
#include <x10/lang/annotations/StatementAnnotation.h>
#undef X10_LANG_ANNOTATIONS_STATEMENTANNOTATION_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace compiler { 

class Unroll   {
    public:
    RTT_H_DECLS_INTERFACE
    
    x10_int FMGL(factor);
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*factor) (), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), factor(factor), hashCode(hashCode), home(home), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*factor) ();
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::compiler::Unroll> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};

} } 
#endif // X10_COMPILER_UNROLL_H

namespace x10 { namespace compiler { 
class Unroll;
} } 

#ifndef X10_COMPILER_UNROLL_H_NODEPS
#define X10_COMPILER_UNROLL_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/annotations/StatementAnnotation.h>
#include <x10/lang/Int.h>
#ifndef X10_COMPILER_UNROLL_H_GENERICS
#define X10_COMPILER_UNROLL_H_GENERICS
#endif // X10_COMPILER_UNROLL_H_GENERICS
#endif // __X10_COMPILER_UNROLL_H_NODEPS
