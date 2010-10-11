#include <x10/lang/Runtime__RootFinish.h>


#include "x10/lang/Runtime__RootFinish.inc"

x10::lang::Fun_0_0<x10_boolean>::itable<x10::lang::Runtime__RootFinish >  x10::lang::Runtime__RootFinish::_itable_0(&x10::lang::Runtime__RootFinish::apply, &x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::equals, &x10::lang::Runtime__RootFinish::hashCode, &x10::lang::Runtime__RootFinish::home, &x10::lang::Runtime__RootFinish::toString, &x10::lang::Runtime__RootFinish::typeName);
x10::lang::Any::itable<x10::lang::Runtime__RootFinish >  x10::lang::Runtime__RootFinish::_itable_1(&x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::equals, &x10::lang::Runtime__RootFinish::hashCode, &x10::lang::Runtime__RootFinish::home, &x10::lang::Runtime__RootFinish::toString, &x10::lang::Runtime__RootFinish::typeName);
x10::lang::Runtime__FinishState::itable<x10::lang::Runtime__RootFinish >  x10::lang::Runtime__RootFinish::_itable_2(&x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::equals, &x10::lang::Runtime__RootFinish::hashCode, &x10::lang::Runtime__RootFinish::home, &x10::lang::Runtime__RootFinish::notifyActivityCreation, &x10::lang::Runtime__RootFinish::notifyActivityTermination, &x10::lang::Runtime__RootFinish::notifySubActivitySpawn, &x10::lang::Runtime__RootFinish::pushException, &x10::lang::Runtime__RootFinish::toString, &x10::lang::Runtime__RootFinish::typeName, &x10::lang::Runtime__RootFinish::waitForFinish);
x10::lang::Runtime__Mortal::itable<x10::lang::Runtime__RootFinish >  x10::lang::Runtime__RootFinish::_itable_3(&x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::at, &x10::lang::Runtime__RootFinish::equals, &x10::lang::Runtime__RootFinish::hashCode, &x10::lang::Runtime__RootFinish::home, &x10::lang::Runtime__RootFinish::toString, &x10::lang::Runtime__RootFinish::typeName);
x10aux::itable_entry x10::lang::Runtime__RootFinish::_itables[5] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Runtime__FinishState>, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Runtime__Mortal>, &_itable_3), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__RootFinish>())};
void x10::lang::Runtime__RootFinish::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__RootFinish");
    
}


//#line 462 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 463 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 464 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 465 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__RootFinish::_constructor() {
    this->x10::lang::Runtime__Latch::_constructor();
    
    //#line 464 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->
      FMGL(exceptions) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_int > > c = x10::lang::Rail<void>::make<x10_int >(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_lang_Runtime__RootFinish__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_lang_Runtime__RootFinish__closure__0)))x10_lang_Runtime__RootFinish__closure__0()))));
    
    //#line 467 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->
      FMGL(seen) = x10::lang::Rail<void>::make<x10_boolean >(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> >(x10aux::ref<x10_lang_Runtime__RootFinish__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_boolean> >(sizeof(x10_lang_Runtime__RootFinish__closure__1)))x10_lang_Runtime__RootFinish__closure__1()))));
    
    //#line 468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (c)->set(((x10_int)1), x10::lang::Place_methods::_make(x10aux::here)->
                             FMGL(id));
    
    //#line 469 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->
      FMGL(counts) = c;
    
}
x10aux::ref<x10::lang::Runtime__RootFinish> x10::lang::Runtime__RootFinish::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__RootFinish> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__RootFinish>(), 0, sizeof(x10::lang::Runtime__RootFinish))) x10::lang::Runtime__RootFinish();
    this_->_constructor();
    return this_;
}



//#line 471 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__RemoteFinish> x10::lang::Runtime__RootFinish::makeRemote(
  ) {
    
    //#line 471 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Runtime__RemoteFinish::_make();
    
}

//#line 473 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notifySubActivitySpawnLocal(
  x10::lang::Place place) {
    
    //#line 474 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->lock();
    
    //#line 475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x = ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                                      FMGL(counts);
        x10_int y0 = x10::lang::Place_methods::parent(place)->
                       FMGL(id);
        x10_int z = ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
    }))
    ;
    
    //#line 476 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
}

//#line 479 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notifyActivityTerminationLocal(
  ) {
    
    //#line 480 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->lock();
    
    //#line 481 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x =
          ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
            FMGL(counts);
        x10_int y0 =
          x10::lang::Place_methods::_make(x10aux::here)->
            FMGL(id);
        x10_int z =
          ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) - (z))), y0);
    }))
    ;
    
    //#line 482 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 482 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 482 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 483 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                           FMGL(counts))->apply(i),
                                        ((x10_int)0))))
            {
                
                //#line 484 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
                
                //#line 485 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                return;
            }
            
        }
    }
    
    //#line 488 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->release();
    
    //#line 489 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
}

//#line 492 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::pushExceptionLocal(
  x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 493 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->lock();
    
    //#line 494 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                 FMGL(exceptions))))
    {
        
        //#line 494 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
          FMGL(exceptions) =
          x10::util::Stack<x10aux::ref<x10::lang::Throwable> >::_make();
    }
    
    //#line 495 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                        FMGL(exceptions))->push(
      t);
    
    //#line 496 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
}

//#line 499 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::waitForFinish(
  x10_boolean safe) {
    
    //#line 500 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::no_steals())) && safe)
    {
        
        //#line 500 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::join(
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__Latch> >(((x10aux::ref<x10::lang::Runtime__RootFinish>)this)));
    }
    
    //#line 501 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->await();
    
    //#line 502 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::VoidFun_0_0> closure =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RootFinish__closure__2>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RootFinish__closure__2)))x10_lang_Runtime__RootFinish__closure__2(this))));
    
    //#line 503 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
       FMGL(seen))->set(false, x10aux::here);
    
    //#line 504 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 504 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 504 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 505 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                   FMGL(seen))->apply(i))
            {
                
                //#line 506 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10aux::run_at(i, closure);
            }
            
        }
    }
    
    //#line 509 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::dealloc(closure.operator->());
    
    //#line 510 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null,
                                ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                  FMGL(exceptions))))
    {
        
        //#line 511 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                                       FMGL(exceptions))->size(),
                                   ((x10_int)1))))
        {
            
            //#line 512 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t =
              x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                  FMGL(exceptions))->peek();
            
            //#line 513 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (x10aux::instanceof<x10aux::ref<x10::lang::Error> >(t))
            {
                
                //#line 514 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::Error> >(t)));
            }
            
            //#line 516 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (x10aux::instanceof<x10aux::ref<x10::lang::RuntimeException> >(t))
            {
                
                //#line 517 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::RuntimeException> >(t)));
            }
            
        }
        
        //#line 520 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::MultipleExceptions::_make(((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                                                                        FMGL(exceptions))));
    }
    
}

//#line 524 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notify(
  x10aux::ref<x10::lang::ValRail<x10_int > > rail) {
    
    //#line 525 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_boolean b = true;
    
    //#line 526 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->lock();
    
    //#line 527 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 527 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 527 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 528 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_int > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                    FMGL(counts);
                x10_int y0 =
                  i;
                x10_int z =
                  (rail)->apply(i);
                (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
            }))
            ;
            
            //#line 529 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_boolean > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                    FMGL(seen);
                x10_int y0 =
                  i;
                x10_boolean z =
                  (!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                             FMGL(counts))->apply(i),
                                          ((x10_int)0)));
                (x)->set(((x10_boolean) ((((x)->apply(y0)) ? 1 : 0) | ((z) ? 1 : 0))), y0);
            }))
            ;
            
            //#line 530 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                           FMGL(counts))->apply(i),
                                        ((x10_int)0))))
            {
                
                //#line 530 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                b =
                  false;
            }
            
        }
    }
    
    //#line 532 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (b) {
        
        //#line 532 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->release();
    }
    
    //#line 533 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
}

//#line 536 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notify2(
  x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail) {
    
    //#line 537 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->lock();
    
    //#line 538 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 538 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(rail)->
                                         FMGL(length)));
             
             //#line 538 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 539 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_int > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                    FMGL(counts);
                x10_int y0 =
                  (rail)->apply(i)->
                    FMGL(first);
                x10_int z =
                  (rail)->apply(i)->
                    FMGL(second);
                (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
            }))
            ;
            
            //#line 540 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
               FMGL(seen))->set(true, (rail)->apply(i)->
                                        FMGL(first));
        }
    }
    
    //#line 542 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 542 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 542 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 543 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->
                                           FMGL(counts))->apply(i),
                                        ((x10_int)0))))
            {
                
                //#line 544 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
                
                //#line 545 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                return;
            }
            
        }
    }
    
    //#line 548 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->release();
    
    //#line 549 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->unlock();
}

//#line 552 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notify(
  x10aux::ref<x10::lang::ValRail<x10_int > > rail,
  x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 553 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->pushExceptionLocal(
      t);
    
    //#line 554 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->notify(
      rail);
}

//#line 557 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notify2(
  x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail,
  x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 558 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->pushExceptionLocal(
      t);
    
    //#line 559 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootFinish>)this)->notify2(
      rail);
}

//#line 562 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notifySubActivitySpawn(
  x10::lang::Place place) {
    
    //#line 563 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
          x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->location)))
    {
        
        //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__49__ =
                                 ((x10aux::ref<x10::lang::Runtime__RootFinish>)this);
                               
                               //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var989__;
                               
                               //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1983; __ret1983: 
                               //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__49__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__49__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var989__ =
                                     __desugarer__var__49__;
                                   
                                   //#line 564 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1983_end_;
                               }
                               goto __ret1983_next_; __ret1983_next_: ;
                               }
                               while (false);
                               goto __ret1983_end_; __ret1983_end_: ;
                               __var989__;
                           }))
                           ))->notifySubActivitySpawnLocal(
          place);
    }
    else
    {
        
        //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __desugarer__var__50__ =
                                 x10::lang::Runtime::proxy(
                                   ((x10aux::ref<x10::lang::Runtime__RootFinish>)this));
                               
                               //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __var990__;
                               
                               //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1984; __ret1984: 
                               //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__50__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__50__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RemoteFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var990__ =
                                     __desugarer__var__50__;
                                   
                                   //#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1984_end_;
                               }
                               goto __ret1984_next_; __ret1984_next_: ;
                               }
                               while (false);
                               goto __ret1984_end_; __ret1984_end_: ;
                               __var990__;
                           }))
                           ))->notifySubActivitySpawn(
          place);
    }
    
}

//#line 570 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notifyActivityCreation(
  ) {
    
    //#line 571 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
             x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->location)))))
    {
        
        //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __desugarer__var__51__ =
                                 x10::lang::Runtime::proxy(
                                   ((x10aux::ref<x10::lang::Runtime__RootFinish>)this));
                               
                               //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __var992__;
                               
                               //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1985; __ret1985: 
                               //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__51__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__51__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RemoteFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var992__ =
                                     __desugarer__var__51__;
                                   
                                   //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1985_end_;
                               }
                               goto __ret1985_next_; __ret1985_next_: ;
                               }
                               while (false);
                               goto __ret1985_end_; __ret1985_end_: ;
                               __var992__;
                           }))
                           ))->notifyActivityCreation();
    }
    
}

//#line 575 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::notifyActivityTermination(
  ) {
    
    //#line 576 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
          x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->location)))
    {
        
        //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__52__ =
                                 ((x10aux::ref<x10::lang::Runtime__RootFinish>)this);
                               
                               //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var994__;
                               
                               //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1986; __ret1986: 
                               //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__52__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__52__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var994__ =
                                     __desugarer__var__52__;
                                   
                                   //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1986_end_;
                               }
                               goto __ret1986_next_; __ret1986_next_: ;
                               }
                               while (false);
                               goto __ret1986_end_; __ret1986_end_: ;
                               __var994__;
                           }))
                           ))->notifyActivityTerminationLocal();
    }
    else
    {
        
        //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __desugarer__var__53__ =
                                 x10::lang::Runtime::proxy(
                                   ((x10aux::ref<x10::lang::Runtime__RootFinish>)this));
                               
                               //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __var995__;
                               
                               //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1987; __ret1987: 
                               //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__53__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__53__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RemoteFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var995__ =
                                     __desugarer__var__53__;
                                   
                                   //#line 579 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1987_end_;
                               }
                               goto __ret1987_next_; __ret1987_next_: ;
                               }
                               while (false);
                               goto __ret1987_end_; __ret1987_end_: ;
                               __var995__;
                           }))
                           ))->notifyActivityTermination(
          ((x10aux::ref<x10::lang::Runtime__RootFinish>)this));
    }
    
}

//#line 583 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RootFinish::pushException(
  x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 584 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
          x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__RootFinish>)this))->location)))
    {
        
        //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__54__ =
                                 ((x10aux::ref<x10::lang::Runtime__RootFinish>)this);
                               
                               //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var997__;
                               
                               //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1988; __ret1988: 
                               //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__54__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__54__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var997__ =
                                     __desugarer__var__54__;
                                   
                                   //#line 585 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1988_end_;
                               }
                               goto __ret1988_next_; __ret1988_next_: ;
                               }
                               while (false);
                               goto __ret1988_end_; __ret1988_end_: ;
                               __var997__;
                           }))
                           ))->pushExceptionLocal(
          t);
    }
    else
    {
        
        //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __desugarer__var__55__ =
                                 x10::lang::Runtime::proxy(
                                   ((x10aux::ref<x10::lang::Runtime__RootFinish>)this));
                               
                               //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RemoteFinish> __var998__;
                               
                               //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1989; __ret1989: 
                               //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__55__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__55__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RemoteFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var998__ =
                                     __desugarer__var__55__;
                                   
                                   //#line 587 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1989_end_;
                               }
                               goto __ret1989_next_; __ret1989_next_: ;
                               }
                               while (false);
                               goto __ret1989_end_; __ret1989_end_: ;
                               __var998__;
                           }))
                           ))->pushException(
          t);
    }
    
}
const x10aux::serialization_id_t x10::lang::Runtime__RootFinish::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__RootFinish::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__RootFinish::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Runtime__Latch::_serialize_body(buf);
    
}

void x10::lang::Runtime__RootFinish::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Runtime__Latch::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__RootFinish::rtt;
void x10::lang::Runtime__RootFinish::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Runtime__Latch>(), x10aux::getRTT<x10::lang::Runtime__FinishState>(), x10aux::getRTT<x10::lang::Runtime__Mortal>()};
    rtt.initStageTwo("x10.lang.Runtime$RootFinish", 3, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RootFinish__closure__0>x10_lang_Runtime__RootFinish__closure__0::_itable(&x10_lang_Runtime__RootFinish__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RootFinish__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RootFinish__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_lang_Runtime__RootFinish__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RootFinish__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RootFinish__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_boolean>::itable<x10_lang_Runtime__RootFinish__closure__1>x10_lang_Runtime__RootFinish__closure__1::_itable(&x10_lang_Runtime__RootFinish__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RootFinish__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RootFinish__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >, &x10_lang_Runtime__RootFinish__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RootFinish__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RootFinish__closure__1::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RootFinish__closure__2>x10_lang_Runtime__RootFinish__closure__2::_itable(&x10_lang_Runtime__RootFinish__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RootFinish__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RootFinish__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RootFinish__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RootFinish__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RootFinish__closure__2::_deserialize<x10::lang::Object>);

