#include <x10/compiler/RemoteOperation.h>


#include "x10/compiler/RemoteOperation.inc"

void x10::compiler::RemoteOperation::_instance_init() {
    _I_("Doing initialisation for class: x10::compiler::RemoteOperation");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10MethodDecl_c
void x10::compiler::RemoteOperation::_kwd__xor(x10::lang::Place p, x10aux::ref<x10::lang::Rail<x10_long > > r,
                                               x10_int i,
                                               x10_long v) {
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(p, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_compiler_RemoteOperation__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_compiler_RemoteOperation__closure__0)))x10_compiler_RemoteOperation__closure__0(r, i, v)))));
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10MethodDecl_c
void x10::compiler::RemoteOperation::_kwd__xor(x10_int id, x10aux::ref<x10::lang::Rail<x10_long > > r,
                                               x10_int i,
                                               x10_long v) {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(x10::lang::Place_methods::_make(id),
                                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_compiler_RemoteOperation__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_compiler_RemoteOperation__closure__1)))x10_compiler_RemoteOperation__closure__1(r, i, v)))));
}

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10MethodDecl_c
void x10::compiler::RemoteOperation::fence() {
 
}

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10ConstructorDecl_c
void x10::compiler::RemoteOperation::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::compiler::RemoteOperation> x10::compiler::RemoteOperation::_make(
  ) {
    x10aux::ref<x10::compiler::RemoteOperation> this_ = new (memset(x10aux::alloc<x10::compiler::RemoteOperation>(), 0, sizeof(x10::compiler::RemoteOperation))) x10::compiler::RemoteOperation();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::compiler::RemoteOperation::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::compiler::RemoteOperation::_deserializer<x10::lang::Object>);

void x10::compiler::RemoteOperation::_serialize(x10aux::ref<x10::compiler::RemoteOperation> this_,
                                                x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::compiler::RemoteOperation::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::compiler::RemoteOperation::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::compiler::RemoteOperation::rtt;
void x10::compiler::RemoteOperation::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.compiler.RemoteOperation", 1, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_compiler_RemoteOperation__closure__0>x10_compiler_RemoteOperation__closure__0::_itable(&x10_compiler_RemoteOperation__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_compiler_RemoteOperation__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_compiler_RemoteOperation__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_compiler_RemoteOperation__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_compiler_RemoteOperation__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_compiler_RemoteOperation__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_compiler_RemoteOperation__closure__1>x10_compiler_RemoteOperation__closure__1::_itable(&x10_compiler_RemoteOperation__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_compiler_RemoteOperation__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_compiler_RemoteOperation__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_compiler_RemoteOperation__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_compiler_RemoteOperation__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_compiler_RemoteOperation__closure__1::_deserialize<x10::lang::Object>);

