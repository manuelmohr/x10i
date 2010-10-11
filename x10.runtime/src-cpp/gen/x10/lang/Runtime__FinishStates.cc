#include <x10/lang/Runtime__FinishStates.h>


#include "x10/lang/Runtime__FinishStates.inc"

x10::lang::Fun_0_1<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> >::itable<x10::lang::Runtime__FinishStates >  x10::lang::Runtime__FinishStates::_itable_0(&x10::lang::Runtime__FinishStates::apply, &x10::lang::Runtime__FinishStates::at, &x10::lang::Runtime__FinishStates::at, &x10::lang::Runtime__FinishStates::equals, &x10::lang::Runtime__FinishStates::hashCode, &x10::lang::Runtime__FinishStates::home, &x10::lang::Runtime__FinishStates::toString, &x10::lang::Runtime__FinishStates::typeName);
x10::lang::Any::itable<x10::lang::Runtime__FinishStates >  x10::lang::Runtime__FinishStates::_itable_1(&x10::lang::Runtime__FinishStates::at, &x10::lang::Runtime__FinishStates::at, &x10::lang::Runtime__FinishStates::equals, &x10::lang::Runtime__FinishStates::hashCode, &x10::lang::Runtime__FinishStates::home, &x10::lang::Runtime__FinishStates::toString, &x10::lang::Runtime__FinishStates::typeName);
x10aux::itable_entry x10::lang::Runtime__FinishStates::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__FinishStates>())};
void x10::lang::Runtime__FinishStates::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__FinishStates");
    
}


//#line 341 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 342 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 344 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__RemoteFinish> x10::lang::Runtime__FinishStates::apply(
  x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish) {
    
    //#line 345 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->FMGL(lock)->lock();
    
    //#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__RemoteFinish> finishState = ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
                                                                  FMGL(map)->getOrElse(
                                                                  rootFinish,
                                                                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__RemoteFinish> >(x10aux::null));
    
    //#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null, finishState)))
    {
        
        //#line 348 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
          FMGL(lock)->unlock();
        
        //#line 349 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return finishState;
        
    }
    
    //#line 352 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__RemoteFinish> remoteFinish =
      x10aux::nullCheck(rootFinish)->makeRemote();
    
    //#line 353 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
      FMGL(map)->put(rootFinish, remoteFinish);
    
    //#line 354 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
      FMGL(lock)->unlock();
    
    //#line 355 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return remoteFinish;
    
}

//#line 357 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__FinishStates::remove(x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish) {
    
    //#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
      FMGL(lock)->lock();
    
    //#line 359 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
      FMGL(map)->remove(rootFinish);
    
    //#line 360 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__FinishStates>)this)->
      FMGL(lock)->unlock();
}

//#line 339 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__FinishStates::_constructor(
  ) {
    this->x10::lang::Object::_constructor();
    
    //#line 341 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__FinishStates>)this))->
      FMGL(map) = x10::util::HashMap<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> >::_make();
    
    //#line 342 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__FinishStates>)this))->
      FMGL(lock) = x10::lang::Runtime__Lock::_make();
    
}
x10aux::ref<x10::lang::Runtime__FinishStates> x10::lang::Runtime__FinishStates::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__FinishStates> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__FinishStates>(), 0, sizeof(x10::lang::Runtime__FinishStates))) x10::lang::Runtime__FinishStates();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__FinishStates::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__FinishStates::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__FinishStates::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__FinishStates::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__FinishStates::rtt;
void x10::lang::Runtime__FinishStates::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::lang::Runtime__RootFinish>, x10aux::ref<x10::lang::Runtime__RemoteFinish> > >()};
    rtt.initStageTwo("x10.lang.Runtime$FinishStates", 2, parents, 0, NULL, NULL);
}
