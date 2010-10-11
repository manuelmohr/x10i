#include <x10/lang/Clock.h>


#include "x10/lang/Clock.inc"


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.PropertyDecl_c
void x10::lang::Clock::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Clock");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Clock> x10::lang::Clock::make() {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10::lang::Clock::make(x10::lang::String::Lit(""));
    
}

//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Clock::FMGL(FIRST_PHASE) = ((x10_int)1);


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Clock> x10::lang::Clock::make(x10aux::ref<x10::lang::String> name) {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Clock> clock = x10::lang::Clock::_make(name);
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::Runtime::clockPhases())->put(clock, x10::lang::Clock::
                                                                       FMGL(FIRST_PHASE__get)());
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return clock;
    
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10FieldDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10FieldDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10FieldDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Clock::_constructor(x10aux::ref<x10::lang::String> name)
{
    this->x10::lang::Object::_constructor();
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Clock>)this))->
      FMGL(count) =
      ((x10_int)1);
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Clock>)this))->
      FMGL(alive) =
      ((x10_int)1);
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Clock>)this))->
      FMGL(phase) =
      x10::lang::Clock::
        FMGL(FIRST_PHASE__get)();
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->
      FMGL(name) =
      name;
    
}
x10aux::ref<x10::lang::Clock> x10::lang::Clock::_make(
  x10aux::ref<x10::lang::String> name)
{
    x10aux::ref<x10::lang::Clock> this_ = new (memset(x10aux::alloc<x10::lang::Clock>(), 0, sizeof(x10::lang::Clock))) x10::lang::Clock();
    this_->_constructor(name);
    return this_;
}



//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Clock::get() {
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10aux::nullCheck(x10::lang::Runtime::clockPhases())->get(
                               ((x10aux::ref<x10::lang::Clock>)this)))->
             FMGL(value);
    
}

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::Box<x10_int> > x10::lang::Clock::put(
  x10_int ph) {
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10::lang::Runtime::clockPhases())->put(
             ((x10aux::ref<x10::lang::Clock>)this),
             ph);
    
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Clock::remove() {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10aux::nullCheck(x10::lang::Runtime::clockPhases())->remove(
                               ((x10aux::ref<x10::lang::Clock>)this)))->
             FMGL(value);
    
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::resumeLocal() {
    
    //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Try_c
    try {
    try {
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::lock();
        {
            
            //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals((__extension__ ({
                                           x10aux::ref<x10::lang::Clock> x =
                                             ((x10aux::ref<x10::lang::Clock>)this);
                                           x10_int y =
                                             ((x10_int)1);
                                           x10aux::nullCheck(x)->
                                             FMGL(alive) =
                                             ((x10_int) ((x10aux::nullCheck(x)->
                                                            FMGL(alive)) - (y)));
                                       }))
                                       , ((x10_int)0))))
            {
                
                //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Clock>)this)->
                  FMGL(alive) =
                  ((x10aux::ref<x10::lang::Clock>)this)->
                    FMGL(count);
                
                //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                (__extension__ ({
                    x10aux::ref<x10::lang::Clock> x =
                      ((x10aux::ref<x10::lang::Clock>)this);
                    x10_int y =
                      ((x10_int)1);
                    x10aux::nullCheck(x)->
                      FMGL(phase) =
                      ((x10_int) ((x10aux::nullCheck(x)->
                                     FMGL(phase)) + (y)));
                }))
                ;
            }
            
        }
    }
    catch (x10aux::__ref& __ref__705) {
        throw;
    }
    } catch (...) {
        {
            
            //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::release();
        }
        throw;
    }
    {
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::release();
    }
}

//#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::dropLocal(x10_int ph) {
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Clock> x = ((x10aux::ref<x10::lang::Clock>)this);
        x10_int y = ((x10_int)1);
        x10aux::nullCheck(x)->FMGL(count) = ((x10_int) ((x10aux::nullCheck(x)->
                                                           FMGL(count)) - (y)));
    }))
    ;
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(((x10_int) -(ph)),
                                ((x10aux::ref<x10::lang::Clock>)this)->
                                  FMGL(phase)))) {
        
        //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Clock>)this)->resumeLocal();
    }
    
}

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Clock::_kwd__register() {
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::lang::Clock>)this)->dropped())
    {
        
        //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::ClockUseException::_make()));
    }
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int ph = ((x10aux::ref<x10::lang::Clock>)this)->get();
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Clock>)this))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Clock__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Clock__closure__0)))x10_lang_Clock__closure__0(this, ph)))));
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return ph;
    
}

//#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::resumeUnsafe() {
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int ph = ((x10aux::ref<x10::lang::Clock>)this)->get();
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((ph) < (((x10_int)0)))) {
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Clock>)this))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Clock__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Clock__closure__1)))x10_lang_Clock__closure__1(this)))));
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->put(
      ((x10_int) -(ph)));
}

//#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::nextUnsafe() {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int ph = ((x10aux::ref<x10::lang::Clock>)this)->get();
    
    //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int abs = x10::lang::Math::abs(ph);
    
    //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::lang::Clock>)this))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Clock__closure__2>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Clock__closure__2)))x10_lang_Clock__closure__2(ph, this, abs)))));
    
    //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->put(
      ((x10_int) ((abs) + (((x10_int)1)))));
}

//#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::dropUnsafe() {
    
    //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int ph = ((x10aux::ref<x10::lang::Clock>)this)->remove();
    
    //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Clock>)this))->location),
                                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Clock__closure__3>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Clock__closure__3)))x10_lang_Clock__closure__3(this, ph)))));
}

//#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::dropInternal() {
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10LocalDecl_c
    x10_int ph = ((x10aux::ref<x10::lang::Clock>)this)->get();
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Clock>)this))->location),
                                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Clock__closure__4>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Clock__closure__4)))x10_lang_Clock__closure__4(this, ph)))));
}

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Clock::registered(
  ) {
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10::lang::Runtime::clockPhases())->containsKey(
             ((x10aux::ref<x10::lang::Clock>)this));
    
}

//#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Clock::dropped() {
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return (!(((x10aux::ref<x10::lang::Clock>)this)->registered()));
    
}

//#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Clock::phase() {
    
    //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::lang::Clock>)this)->dropped())
    {
        
        //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::ClockUseException::_make()));
    }
    
    //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return x10::lang::Math::abs(((x10aux::ref<x10::lang::Clock>)this)->get());
    
}

//#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::resume() {
    
    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::lang::Clock>)this)->dropped())
    {
        
        //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::ClockUseException::_make()));
    }
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->resumeUnsafe();
}

//#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::next() {
    
    //#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::lang::Clock>)this)->dropped())
    {
        
        //#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::ClockUseException::_make()));
    }
    
    //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->nextUnsafe();
}

//#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
void x10::lang::Clock::drop() {
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::lang::Clock>)this)->dropped())
    {
        
        //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::ClockUseException::_make()));
    }
    
    //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Clock>)this)->dropUnsafe();
}

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::lang::Clock::name(
  ) {
    
    //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Clock>)this)->
             FMGL(name);
    
}
const x10aux::serialization_id_t x10::lang::Clock::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Clock::_deserializer<x10::lang::Object>);

void x10::lang::Clock::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(name));
    
}

void x10::lang::Clock::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(name) = buf.read<x10aux::ref<x10::lang::String> >();
}

x10aux::RuntimeType x10::lang::Clock::rtt;
void x10::lang::Clock::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Clock", 1, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__0>x10_lang_Clock__closure__0::_itable(&x10_lang_Clock__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Clock__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Clock__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Clock__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Clock__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Clock__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__1>x10_lang_Clock__closure__1::_itable(&x10_lang_Clock__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Clock__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Clock__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Clock__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Clock__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Clock__closure__1::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__2>x10_lang_Clock__closure__2::_itable(&x10_lang_Clock__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Clock__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Clock__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Clock__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Clock__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Clock__closure__2::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__3>x10_lang_Clock__closure__3::_itable(&x10_lang_Clock__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Clock__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Clock__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Clock__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Clock__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Clock__closure__3::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__4>x10_lang_Clock__closure__4::_itable(&x10_lang_Clock__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Clock__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Clock__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Clock__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Clock__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Clock__closure__4::_deserialize<x10::lang::Object>);

