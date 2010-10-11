#ifndef __X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H
#define __X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANNOTATIONS_ANNOTATION_H_NODEPS
#include <x10/lang/annotations/Annotation.h>
#undef X10_LANG_ANNOTATIONS_ANNOTATION_H_NODEPS
namespace x10 { namespace lang { namespace annotations { 

class ImportAnnotation   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hashCode(hashCode), home(home), toString(toString), typeName(typeName) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::lang::annotations::ImportAnnotation> this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    
};

} } } 
#endif // X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H

namespace x10 { namespace lang { namespace annotations { 
class ImportAnnotation;
} } } 

#ifndef X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_NODEPS
#define X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/annotations/Annotation.h>
#ifndef X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_GENERICS
#define X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_GENERICS
#endif // X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_GENERICS
#endif // __X10_LANG_ANNOTATIONS_IMPORTANNOTATION_H_NODEPS
