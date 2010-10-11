#include <x10/lang/Runtime__Deque.h>


#include "x10/lang/Runtime__Deque.inc"

void x10::lang::Runtime__Deque::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Deque");
    
}


//#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Deque::_constructor(x10aux::ref<x10::lang::Deque> id0)
{
    this->x10::lang::Object::_constructor();
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Deque>)this))->
      FMGL(__NATIVE_FIELD__) =
      id0;
    
}
x10aux::ref<x10::lang::Runtime__Deque> x10::lang::Runtime__Deque::_make(
  x10aux::ref<x10::lang::Deque> id0)
{
    x10aux::ref<x10::lang::Runtime__Deque> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Deque>(), 0, sizeof(x10::lang::Runtime__Deque))) x10::lang::Runtime__Deque();
    this_->_constructor(id0);
    return this_;
}



//#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Deque::_constructor() {
    this->_constructor(x10::lang::Deque::_make());
    
}
x10aux::ref<x10::lang::Runtime__Deque> x10::lang::Runtime__Deque::_make()
{
    x10aux::ref<x10::lang::Runtime__Deque> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Deque>(), 0, sizeof(x10::lang::Runtime__Deque))) x10::lang::Runtime__Deque();
    this_->_constructor();
    return this_;
}



//#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Deque::size() {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Deque>)this)->
                               FMGL(__NATIVE_FIELD__))->size();
    
}

//#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Object> x10::lang::Runtime__Deque::poll() {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Deque>)this)->
                               FMGL(__NATIVE_FIELD__))->poll();
    
}

//#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Deque::push(x10aux::ref<x10::lang::Object> t) {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Deque>)this)->FMGL(__NATIVE_FIELD__))->push(
      t);
}

//#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Object> x10::lang::Runtime__Deque::steal() {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Deque>)this)->
                               FMGL(__NATIVE_FIELD__))->steal();
    
}
const x10aux::serialization_id_t x10::lang::Runtime__Deque::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Deque::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Deque::_serialize(x10aux::ref<x10::lang::Runtime__Deque> this_,
                                           x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::lang::Runtime__Deque::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Deque::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Deque::rtt;
void x10::lang::Runtime__Deque::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$Deque", 1, parents, 0, NULL, NULL);
}
