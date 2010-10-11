#include <x10/lang/Runtime__Thread.h>


#include "x10/lang/Runtime__Thread.inc"

void x10::lang::Runtime__Thread::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Thread");
    
}


//#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Thread::_constructor(x10aux::ref<x10::lang::Thread> id0)
{
    this->x10::lang::Object::_constructor();
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this))->
      FMGL(__NATIVE_FIELD__) =
      id0;
    
}
x10aux::ref<x10::lang::Runtime__Thread> x10::lang::Runtime__Thread::_make(
  x10aux::ref<x10::lang::Thread> id0)
{
    x10aux::ref<x10::lang::Runtime__Thread> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Thread>(), 0, sizeof(x10::lang::Runtime__Thread))) x10::lang::Runtime__Thread();
    this_->_constructor(id0);
    return this_;
}



//#line 788 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Thread::_constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                              x10aux::ref<x10::lang::String> name)
{
    this->_constructor(
      x10::lang::Thread::_make(body,
                               name));
    
}
x10aux::ref<x10::lang::Runtime__Thread> x10::lang::Runtime__Thread::_make(
  x10aux::ref<x10::lang::VoidFun_0_0> body,
  x10aux::ref<x10::lang::String> name)
{
    x10aux::ref<x10::lang::Runtime__Thread> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Thread>(), 0, sizeof(x10::lang::Runtime__Thread))) x10::lang::Runtime__Thread();
    this_->_constructor(body,
    name);
    return this_;
}



//#line 790 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__Thread> x10::lang::Runtime__Thread::currentThread(
  ) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Runtime__Thread::_make(x10::lang::Thread::currentThread());
    
}

//#line 792 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::start() {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                        FMGL(__NATIVE_FIELD__))->start();
}

//#line 794 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::sleep(x10_long millis) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Thread::sleep(millis);
}

//#line 796 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::sleep(x10_long millis,
                                       x10_int nanos) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Thread::sleep(millis, nanos);
}

//#line 798 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::park() {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Thread::park();
}

//#line 800 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::parkNanos(
  x10_long nanos) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Thread::parkNanos(nanos);
}

//#line 802 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::unpark() {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this))->
                        FMGL(__NATIVE_FIELD__))->unpark();
}

//#line 804 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Object> x10::lang::Runtime__Thread::worker(
  ) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                               FMGL(__NATIVE_FIELD__))->worker();
    
}

//#line 806 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::worker(x10aux::ref<x10::lang::Runtime__Worker> worker) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                        FMGL(__NATIVE_FIELD__))->worker(
      worker);
}

//#line 808 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::lang::Runtime__Thread::name(
  ) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                               FMGL(__NATIVE_FIELD__))->name();
    
}

//#line 810 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Thread::name(x10aux::ref<x10::lang::String> name) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                        FMGL(__NATIVE_FIELD__))->name(
      name);
}

//#line 812 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Thread::locInt(
  ) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Thread>)this)->
                               FMGL(__NATIVE_FIELD__))->locInt();
    
}

//#line 814 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime__Thread::getTid(
  ) {
    
    //#line 783 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Thread::getTid();
    
}
const x10aux::serialization_id_t x10::lang::Runtime__Thread::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Thread::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Thread::_serialize(x10aux::ref<x10::lang::Runtime__Thread> this_,
                                            x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::lang::Runtime__Thread::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Thread::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Thread::rtt;
void x10::lang::Runtime__Thread::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$Thread", 1, parents, 0, NULL, NULL);
}
