#include <x10/lang/Runtime__Semaphore.h>


#include "x10/lang/Runtime__Semaphore.inc"

void x10::lang::Runtime__Semaphore::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Semaphore");
    
}


//#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Semaphore::_constructor(x10_int n) {
    this->x10::lang::Object::_constructor();
    
    //#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Semaphore>)this))->
      FMGL(lock) = x10::lang::Runtime__Lock::_make();
    
    //#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Semaphore>)this))->
      FMGL(threads) = x10::util::Stack<x10aux::ref<x10::lang::Runtime__Thread> >::_make();
    
    //#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Semaphore>)this))->
      FMGL(permits) = ((x10_int)0);
    
    //#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Semaphore>)this))->
      FMGL(permits) = n;
    
}
x10aux::ref<x10::lang::Runtime__Semaphore> x10::lang::Runtime__Semaphore::_make(
  x10_int n) {
    x10aux::ref<x10::lang::Runtime__Semaphore> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Semaphore>(), 0, sizeof(x10::lang::Runtime__Semaphore))) x10::lang::Runtime__Semaphore();
    this_->_constructor(n);
    return this_;
}



//#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Semaphore::min(x10_int i, x10_int j) {
    
    //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((i) < (j)) ? (x10_int)(i) : (x10_int)(j);
    
}

//#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Semaphore::release(x10_int n) {
    
    //#line 241 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->FMGL(lock)->lock();
    
    //#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Runtime__Semaphore> x = ((x10aux::ref<x10::lang::Runtime__Semaphore>)this);
        x10_int y = n;
        x10aux::nullCheck(x)->FMGL(permits) = ((x10_int) ((x10aux::nullCheck(x)->
                                                             FMGL(permits)) + (y)));
    }))
    ;
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int m = x10::lang::Runtime__Semaphore::min(((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
                                                     FMGL(permits),
                                                   x10::lang::Runtime__Semaphore::min(
                                                     n,
                                                     ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
                                                       FMGL(threads)->size()));
    
    //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (m));
             
             //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
                                FMGL(threads)->pop())->x10::lang::Runtime__Thread::unpark();
        }
    }
    
    //#line 247 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
      FMGL(lock)->unlock();
}

//#line 250 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Semaphore::release(
  ) {
    
    //#line 251 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->release(
      ((x10_int)1));
}

//#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Semaphore::reduce(
  x10_int n) {
    
    //#line 255 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
      FMGL(lock)->lock();
    
    //#line 256 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Runtime__Semaphore> x =
          ((x10aux::ref<x10::lang::Runtime__Semaphore>)this);
        x10_int y =
          n;
        x10aux::nullCheck(x)->
          FMGL(permits) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(permits)) - (y)));
    }))
    ;
    
    //#line 257 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
      FMGL(lock)->unlock();
}

//#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Semaphore::acquire(
  ) {
    
    //#line 261 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
      FMGL(lock)->lock();
    
    //#line 262 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Thread> thread =
      x10::lang::Runtime__Thread::currentThread();
    
    //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
    while (((((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
               FMGL(permits)) <= (((x10_int)0))))
    {
        
        //#line 264 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
          FMGL(threads)->push(
          thread);
        
        //#line 265 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
        while (((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
                 FMGL(threads)->contains(
                 thread))
        {
            
            //#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
              FMGL(lock)->unlock();
            
            //#line 267 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime__Thread::park();
            
            //#line 268 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
              FMGL(lock)->lock();
        }
        
    }
    
    //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Runtime__Semaphore> x =
          ((x10aux::ref<x10::lang::Runtime__Semaphore>)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(permits) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(permits)) - (y)));
    }))
    ;
    
    //#line 272 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
      FMGL(lock)->unlock();
}

//#line 275 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Semaphore::available(
  ) {
    
    //#line 275 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Runtime__Semaphore>)this)->
             FMGL(permits);
    
}
const x10aux::serialization_id_t x10::lang::Runtime__Semaphore::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Semaphore::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Semaphore::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Semaphore::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Semaphore::rtt;
void x10::lang::Runtime__Semaphore::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$Semaphore", 1, parents, 0, NULL, NULL);
}
