#ifndef __X10_COMPILER_OPS_H
#define __X10_COMPILER_OPS_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace compiler { 

template<class FMGL(B), class FMGL(C)> class Ops;
template <> class Ops<void, void>;
template<class FMGL(B), class FMGL(C)> class Ops   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(FMGL(C) (I::*__ampersand) (FMGL(B)), FMGL(C) (I::*__and) (FMGL(B)), FMGL(C) (I::*__bar) (FMGL(B)), FMGL(C) (I::*__caret) (FMGL(B)), FMGL(C) (I::*__cast) (FMGL(B)), x10_boolean (I::*__eq) (FMGL(B)), x10_boolean (I::*__ge) (FMGL(B)), x10_boolean (I::*__gt) (FMGL(B)), FMGL(C) (I::*__in) (), FMGL(C) (I::*__instanceof) (FMGL(B)), x10_boolean (I::*__le) (FMGL(B)), FMGL(C) (I::*__left) (FMGL(B)), x10_boolean (I::*__lt) (FMGL(B)), FMGL(C) (I::*_m13____minus) (), FMGL(C) (I::*_m14____minus) (FMGL(B)), x10_boolean (I::*__ne) (FMGL(B)), FMGL(C) (I::*__not) (), FMGL(C) (I::*__or) (FMGL(B)), FMGL(C) (I::*__over) (FMGL(B)), FMGL(C) (I::*__percent) (FMGL(B)), FMGL(C) (I::*_m20____plus) (), FMGL(C) (I::*_m21____plus) (FMGL(B)), FMGL(C) (I::*__right) (FMGL(B)), FMGL(C) (I::*__tilde) (), FMGL(C) (I::*__times) (FMGL(B)), x10_boolean (I::*_m25__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m26__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) ()) : __ampersand(__ampersand), __and(__and), __bar(__bar), __caret(__caret), __cast(__cast), __eq(__eq), __ge(__ge), __gt(__gt), __in(__in), __instanceof(__instanceof), __le(__le), __left(__left), __lt(__lt), _m13____minus(_m13____minus), _m14____minus(_m14____minus), __ne(__ne), __not(__not), __or(__or), __over(__over), __percent(__percent), _m20____plus(_m20____plus), _m21____plus(_m21____plus), __right(__right), __tilde(__tilde), __times(__times), _m25__at(_m25__at), _m26__at(_m26__at), equals(equals), hashCode(hashCode), home(home), toString(toString), typeName(typeName) {}
        FMGL(C) (I::*__ampersand) (FMGL(B));
        FMGL(C) (I::*__and) (FMGL(B));
        FMGL(C) (I::*__bar) (FMGL(B));
        FMGL(C) (I::*__caret) (FMGL(B));
        FMGL(C) (I::*__cast) (FMGL(B));
        x10_boolean (I::*__eq) (FMGL(B));
        x10_boolean (I::*__ge) (FMGL(B));
        x10_boolean (I::*__gt) (FMGL(B));
        FMGL(C) (I::*__in) ();
        FMGL(C) (I::*__instanceof) (FMGL(B));
        x10_boolean (I::*__le) (FMGL(B));
        FMGL(C) (I::*__left) (FMGL(B));
        x10_boolean (I::*__lt) (FMGL(B));
        FMGL(C) (I::*_m13____minus) ();
        FMGL(C) (I::*_m14____minus) (FMGL(B));
        x10_boolean (I::*__ne) (FMGL(B));
        FMGL(C) (I::*__not) ();
        FMGL(C) (I::*__or) (FMGL(B));
        FMGL(C) (I::*__over) (FMGL(B));
        FMGL(C) (I::*__percent) (FMGL(B));
        FMGL(C) (I::*_m20____plus) ();
        FMGL(C) (I::*_m21____plus) (FMGL(B));
        FMGL(C) (I::*__right) (FMGL(B));
        FMGL(C) (I::*__tilde) ();
        FMGL(C) (I::*__times) (FMGL(B));
        x10_boolean (I::*_m25__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m26__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
    };
    
    static void _serialize(x10aux::ref<x10::compiler::Ops<FMGL(B), FMGL(C)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Ops<void, void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_COMPILER_OPS_H

namespace x10 { namespace compiler { 
template<class FMGL(B), class FMGL(C)> class Ops;
} } 

#ifndef X10_COMPILER_OPS_H_NODEPS
#define X10_COMPILER_OPS_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Boolean.h>
#ifndef X10_COMPILER_OPS_H_GENERICS
#define X10_COMPILER_OPS_H_GENERICS
#endif // X10_COMPILER_OPS_H_GENERICS
#ifndef X10_COMPILER_OPS_H_IMPLEMENTATION
#define X10_COMPILER_OPS_H_IMPLEMENTATION
#include <x10/compiler/Ops.h>


#include "x10/compiler/Ops.inc"

template<class FMGL(B), class FMGL(C)> void x10::compiler::Ops<FMGL(B), FMGL(C)>::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::Ops<FMGL(B), FMGL(C)>");
    
}

template<class FMGL(B), class FMGL(C)> x10aux::RuntimeType x10::compiler::Ops<FMGL(B), FMGL(C)>::rtt;
template<class FMGL(B), class FMGL(C)> void x10::compiler::Ops<FMGL(B), FMGL(C)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::compiler::Ops<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(B)>(), x10aux::getRTT<FMGL(C)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.compiler.Ops";
    rtt.initStageTwo(baseName, 1, parents, 2, params, variances);
}
#endif // X10_COMPILER_OPS_H_IMPLEMENTATION
#endif // __X10_COMPILER_OPS_H_NODEPS
