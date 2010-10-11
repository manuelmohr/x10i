#include <x10/lang/Activity.h>


#include "x10/lang/Activity.inc"

void x10::lang::Activity::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Activity");
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Activity::sleep(x10_long millis) {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Try_c
    try {
        
        //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::increaseParallelism();
        
        //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        x10::lang::Runtime__Thread::sleep(millis);
        
        //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::decreaseParallelism(((x10_int)1));
        
        //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10Return_c
        return true;
        
    }
    catch (x10aux::__ref& __ref__690) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__690 = (x10aux::ref<x10::lang::Throwable>&)__ref__690;
        if (x10aux::instanceof<x10aux::ref<x10::lang::InterruptedException> >(__exc__ref__690)) {
            x10aux::ref<x10::lang::InterruptedException> e = static_cast<x10aux::ref<x10::lang::InterruptedException> >(__exc__ref__690);
            {
                
                //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::decreaseParallelism(((x10_int)1));
                
                //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10Return_c
                return false;
                
            }
        } else
        throw;
    }
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
/**
     * the finish state governing the execution of this activity (may be remote)
     */
                                                                                            //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
                                                                                            /**
     * safe to run pending jobs while waiting for a finish (temporary)
     */
                                                                                                                                                                              //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                              /**
     * The user-specified code for this activity.
     */
                                                                                                                                                                                                                                           //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                           /**
     * The mapping from registered clocks to phases for this activity.
     * Lazily created.
     */
                                                                                                                                                                                                                                                                                                                                                    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                                                                                                                                    /**
     * The finish states for the finish statements currently executed by this activity.
     * Lazily created.
     */

//#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Activity::_constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                       x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                                       x10_boolean safe) {
    this->x10::lang::Object::_constructor();
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(clockPhases) = x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__ClockPhases> >(x10aux::null);
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(finishStack) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Runtime__FinishState> > > >(x10aux::null);
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(tag) = x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(x10aux::null);
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(finishState) = finishState;
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(safe) = safe;
    
    //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(finishState)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)finishState)->_getITables())->notifyActivityCreation))();
    
    //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(body) = body;
    
}
x10aux::ref<x10::lang::Activity> x10::lang::Activity::_make(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                                            x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                                                            x10_boolean safe)
{
    x10aux::ref<x10::lang::Activity> this_ = new (memset(x10aux::alloc<x10::lang::Activity>(), 0, sizeof(x10::lang::Activity))) x10::lang::Activity();
    this_->_constructor(body,
    finishState,
    safe);
    return this_;
}



//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Activity::_constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                       x10aux::ref<x10::lang::Runtime__FinishState> finishState,
                                       x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
                                       x10aux::ref<x10::lang::ValRail<x10_int > > phases)
{
    this->_constructor(
      body,
      finishState,
      false);
    
    //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(clockPhases) =
      x10::lang::Runtime__ClockPhases::make(
        clocks,
        phases);
    
}
x10aux::ref<x10::lang::Activity> x10::lang::Activity::_make(
  x10aux::ref<x10::lang::VoidFun_0_0> body,
  x10aux::ref<x10::lang::Runtime__FinishState> finishState,
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
  x10aux::ref<x10::lang::ValRail<x10_int > > phases)
{
    x10aux::ref<x10::lang::Activity> this_ = new (memset(x10aux::alloc<x10::lang::Activity>(), 0, sizeof(x10::lang::Activity))) x10::lang::Activity();
    this_->_constructor(body,
    finishState,
    clocks,
    phases);
    return this_;
}



//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Activity::_constructor(x10aux::ref<x10::lang::VoidFun_0_0> body,
                                       x10_boolean safe)
{
    this->x10::lang::Object::_constructor();
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(clockPhases) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__ClockPhases> >(x10aux::null);
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(finishStack) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Runtime__FinishState> > > >(x10aux::null);
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(tag) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(x10aux::null);
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(finishState) =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__FinishState> >(x10aux::null);
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(safe) =
      safe;
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Activity>)this))->
      FMGL(body) =
      body;
    
}
x10aux::ref<x10::lang::Activity> x10::lang::Activity::_make(
  x10aux::ref<x10::lang::VoidFun_0_0> body,
  x10_boolean safe)
{
    x10aux::ref<x10::lang::Activity> this_ = new (memset(x10aux::alloc<x10::lang::Activity>(), 0, sizeof(x10::lang::Activity))) x10::lang::Activity();
    this_->_constructor(body,
    safe);
    return this_;
}



//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10MethodDecl_c
void x10::lang::Activity::run() {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Try_c
    try {
        
        //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::placeCheck(x10aux::nullCheck(((x10aux::ref<x10::lang::Activity>)this)->
                                                                                                       FMGL(body)));
        (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(_->_getITables())->apply))(); }));
    }
    catch (x10aux::__ref& __ref__692) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__692 = (x10aux::ref<x10::lang::Throwable>&)__ref__692;
        if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__692)) {
            x10aux::ref<x10::lang::Throwable> t =
              static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__692);
            {
                
                //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(x10aux::null,
                                            ((x10aux::ref<x10::lang::Activity>)this)->
                                              FMGL(finishState))))
                {
                    
                    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
                    (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Activity>)this)->
                                                                                                FMGL(finishState));
                    (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(_->_getITables())->pushException))(
                      t); }));
                }
                else
                {
                    
                    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
                    x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(x10::lang::String::Lit("Uncaught exception in uncounted activity")))->toString()->c_str());
                    
                    //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
                    (t)->printStackTrace();
                }
                
            }
        } else
        throw;
    }
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null,
                                ((x10aux::ref<x10::lang::Activity>)this)->
                                  FMGL(clockPhases))))
    {
        
        //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::lang::Activity>)this)->
                            FMGL(clockPhases))->drop();
    }
    
    //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null,
                                ((x10aux::ref<x10::lang::Activity>)this)->
                                  FMGL(finishState))))
    {
        
        //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
        (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(((x10aux::ref<x10::lang::Activity>)this)->
                                                                                    FMGL(finishState));
        (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(_->_getITables())->notifyActivityTermination))(); }));
    }
    
    //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": polyglot.ast.Eval_c
    x10aux::dealloc(((x10aux::ref<x10::lang::Activity>)this)->
                      FMGL(body).operator->());
}

//#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10FieldDecl_c
/**
     * Activity-local storage
     */

//#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Activity.x10": x10.ast.X10MethodDecl_c
void x10::lang::Activity::dump() {
 
}
const x10aux::serialization_id_t x10::lang::Activity::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Activity::_deserializer<x10::lang::Object>);

void x10::lang::Activity::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Activity::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Activity::rtt;
void x10::lang::Activity::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Activity", 1, parents, 0, NULL, NULL);
}
