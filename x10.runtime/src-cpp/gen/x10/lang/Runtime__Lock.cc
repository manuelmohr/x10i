#include <x10/lang/Runtime__Lock.h>


#include "x10/lang/Runtime__Lock.inc"

void x10::lang::Runtime__Lock::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Lock");
    
}


//#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Lock::_constructor(x10aux::ref<x10::lang::Lock__ReentrantLock> id0)
{
    this->x10::lang::Object::_constructor();
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Lock>)this))->
      FMGL(__NATIVE_FIELD__) =
      id0;
    
}
x10aux::ref<x10::lang::Runtime__Lock> x10::lang::Runtime__Lock::_make(
  x10aux::ref<x10::lang::Lock__ReentrantLock> id0)
{
    x10aux::ref<x10::lang::Runtime__Lock> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Lock>(), 0, sizeof(x10::lang::Runtime__Lock))) x10::lang::Runtime__Lock();
    this_->_constructor(id0);
    return this_;
}



//#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Lock::_constructor() {
    this->_constructor(x10::lang::Lock__ReentrantLock::_make());
    
}
x10aux::ref<x10::lang::Runtime__Lock> x10::lang::Runtime__Lock::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__Lock> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Lock>(), 0, sizeof(x10::lang::Runtime__Lock))) x10::lang::Runtime__Lock();
    this_->_constructor();
    return this_;
}



//#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Lock::lock() {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Lock>)this)->
                        FMGL(__NATIVE_FIELD__))->lock();
}

//#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Runtime__Lock::tryLock() {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Lock>)this)->
                               FMGL(__NATIVE_FIELD__))->tryLock();
    
}

//#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Lock::unlock() {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Lock>)this)->
                        FMGL(__NATIVE_FIELD__))->unlock();
}

//#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Lock::getHoldCount() {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Lock>)this)->
                               FMGL(__NATIVE_FIELD__))->getHoldCount();
    
}
const x10aux::serialization_id_t x10::lang::Runtime__Lock::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Lock::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Lock::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Lock::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Lock::rtt;
void x10::lang::Runtime__Lock::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$Lock", 1, parents, 0, NULL, NULL);
}
