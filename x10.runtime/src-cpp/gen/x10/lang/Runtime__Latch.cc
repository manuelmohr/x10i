#include <x10/lang/Runtime__Latch.h>


#include "x10/lang/Runtime__Latch.inc"

x10::lang::Fun_0_0<x10_boolean>::itable<x10::lang::Runtime__Latch >  x10::lang::Runtime__Latch::_itable_0(&x10::lang::Runtime__Latch::apply, &x10::lang::Runtime__Latch::at, &x10::lang::Runtime__Latch::at, &x10::lang::Runtime__Latch::equals, &x10::lang::Runtime__Latch::hashCode, &x10::lang::Runtime__Latch::home, &x10::lang::Runtime__Latch::toString, &x10::lang::Runtime__Latch::typeName);
x10::lang::Any::itable<x10::lang::Runtime__Latch >  x10::lang::Runtime__Latch::_itable_1(&x10::lang::Runtime__Latch::at, &x10::lang::Runtime__Latch::at, &x10::lang::Runtime__Latch::equals, &x10::lang::Runtime__Latch::hashCode, &x10::lang::Runtime__Latch::home, &x10::lang::Runtime__Latch::toString, &x10::lang::Runtime__Latch::typeName);
x10aux::itable_entry x10::lang::Runtime__Latch::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__Latch>())};
void x10::lang::Runtime__Latch::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Latch");
    
}


//#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Latch::release() {
    
    //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Latch>)this)->lock();
    
    //#line 210 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Latch>)this)->FMGL(state) = true;
    
    //#line 211 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime__Monitor::release();
}

//#line 214 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Latch::await() {
    
    //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(((x10aux::ref<x10::lang::Runtime__Latch>)this)->FMGL(state))))
    {
        
        //#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Latch>)this)->lock();
        
        //#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
        while ((!(((x10aux::ref<x10::lang::Runtime__Latch>)this)->
                    FMGL(state))))
        {
            
            //#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime__Monitor::await();
        }
        
        //#line 219 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Latch>)this)->unlock();
    }
    
}

//#line 223 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Runtime__Latch::apply() {
    
    //#line 223 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Runtime__Latch>)this)->FMGL(state);
    
}

//#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Latch::_constructor() {
    this->x10::lang::Runtime__Monitor::_constructor();
    
    //#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Latch>)this))->FMGL(state) =
      false;
    
}
x10aux::ref<x10::lang::Runtime__Latch> x10::lang::Runtime__Latch::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__Latch> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Latch>(), 0, sizeof(x10::lang::Runtime__Latch))) x10::lang::Runtime__Latch();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__Latch::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Latch::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Latch::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Runtime__Monitor::_serialize_body(buf);
    
}

void x10::lang::Runtime__Latch::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Runtime__Monitor::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Latch::rtt;
void x10::lang::Runtime__Latch::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Runtime__Monitor>(), x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >()};
    rtt.initStageTwo("x10.lang.Runtime$Latch", 2, parents, 0, NULL, NULL);
}
