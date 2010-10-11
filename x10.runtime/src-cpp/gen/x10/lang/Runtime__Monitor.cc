#include <x10/lang/Runtime__Monitor.h>


#include "x10/lang/Runtime__Monitor.inc"

void x10::lang::Runtime__Monitor::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Monitor");
    
}


//#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
/**
         * Parked threads
         */

//#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Monitor::await() {
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::increaseParallelism();
    
    //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Thread> thread = x10::lang::Runtime__Thread::currentThread();
    
    //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->FMGL(threads)->push(
      thread);
    
    //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
    while (((x10aux::ref<x10::lang::Runtime__Monitor>)this)->FMGL(threads)->contains(
             thread)) {
        
        //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->unlock();
        
        //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::park();
        
        //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->lock();
    }
    
}

//#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Monitor::release() {
    
    //#line 195 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int size = ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->
                     FMGL(threads)->size();
    
    //#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (((size) > (((x10_int)0)))) {
        
        //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::decreaseParallelism(size);
        
        //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (size)); 
                                                   //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                                   i = ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::unpark(
                  ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->
                    FMGL(threads)->pop());
            }
        }
        
    }
    
    //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Monitor>)this)->unlock();
}

//#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Monitor::_constructor() {
    this->x10::lang::Runtime__Lock::_constructor();
    
    //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Monitor>)this))->
      FMGL(threads) = x10::util::Stack<x10aux::ref<x10::lang::Runtime__Thread> >::_make();
    
}
x10aux::ref<x10::lang::Runtime__Monitor> x10::lang::Runtime__Monitor::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__Monitor> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Monitor>(), 0, sizeof(x10::lang::Runtime__Monitor))) x10::lang::Runtime__Monitor();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__Monitor::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Monitor::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Monitor::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Runtime__Lock::_serialize_body(buf);
    
}

void x10::lang::Runtime__Monitor::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Runtime__Lock::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Monitor::rtt;
void x10::lang::Runtime__Monitor::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Runtime__Lock>()};
    rtt.initStageTwo("x10.lang.Runtime$Monitor", 1, parents, 0, NULL, NULL);
}
