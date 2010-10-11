#include <x10/lang/Runtime__RemoteControl.h>


#include "x10/lang/Runtime__RemoteControl.inc"

void x10::lang::Runtime__RemoteControl::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__RemoteControl");
    
}


//#line 1235 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1236 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1234 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__RemoteControl::_constructor() {
    this->x10::lang::Object::_constructor();
    
    //#line 1235 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteControl>)this))->
      FMGL(e) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 1236 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteControl>)this))->
      FMGL(latch) = x10::lang::Runtime__Latch::_make();
    
}
x10aux::ref<x10::lang::Runtime__RemoteControl> x10::lang::Runtime__RemoteControl::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__RemoteControl> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__RemoteControl>(), 0, sizeof(x10::lang::Runtime__RemoteControl))) x10::lang::Runtime__RemoteControl();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__RemoteControl::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__RemoteControl::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__RemoteControl::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__RemoteControl::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__RemoteControl::rtt;
void x10::lang::Runtime__RemoteControl::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$RemoteControl", 1, parents, 0, NULL, NULL);
}
