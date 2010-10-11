#include <x10/lang/Runtime__RemoteFinish.h>


#include "x10/lang/Runtime__RemoteFinish.inc"

void x10::lang::Runtime__RemoteFinish::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__RemoteFinish");
    
}


//#line 678 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
/**
         * The Exception Stack is used to collect exceptions
         * issued when activities associated with this finish state terminate abruptly.
         */
                                                                                                                                                                    //#line 683 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                    /**
         * The monitor is used to serialize updates to the finish state.
         */
                                                                                                                                                                                                                                                            //#line 688 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                                            /**
         * Keep track of the number of activities associated with this finish state.
         */
                                                                                                                                                                                                                                                                                                                                                                //#line 690 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                //#line 691 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                                                                                //#line 693 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
                                                                                                                                                                                                                                                                                                                                                                

//#line 695 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RemoteFinish::notifyActivityCreation() {
    
    //#line 696 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->FMGL(count))->getAndIncrement();
}

//#line 703 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RemoteFinish::notifySubActivitySpawn(x10::lang::Place place) {
    
    //#line 704 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->FMGL(lock)->lock();
    
    //#line 705 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10_int) (((__extension__ ({
                                   x10aux::ref<x10::lang::Rail<x10_int > > x =
                                     ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                       FMGL(counts);
                                   x10_int y0 =
                                     place->
                                       FMGL(id);
                                   x10_int z =
                                     ((x10_int)1);
                                   (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
                               }))
                               ) - (((x10_int)1)))), ((x10_int)0))) &&
        (!x10aux::struct_equals(x10::lang::Place_methods::_make(x10aux::here)->
                                  FMGL(id),
                                place->
                                  FMGL(id)))) {
        
        //#line 706 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->FMGL(message))->set(place->
                                                                                      FMGL(id), ((x10_int) (((__extension__ ({
            x10aux::ref<x10::lang::Runtime__RemoteFinish> x =
              ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this);
            x10_int y =
              ((x10_int)1);
            x10aux::nullCheck(x)->
              FMGL(length) =
              ((x10_int) ((x10aux::nullCheck(x)->
                             FMGL(length)) + (y)));
        }))
        ) - (((x10_int)1)))));
    }
    
    //#line 708 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
      FMGL(lock)->unlock();
}

//#line 714 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RemoteFinish::notifyActivityTermination(
  x10aux::ref<x10::lang::Runtime__RootFinish> r) {
    
    //#line 715 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
      FMGL(lock)->lock();
    
    //#line 716 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x = ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                                      FMGL(counts);
        x10_int y0 = x10::lang::Place_methods::_make(x10aux::here)->
                       FMGL(id);
        x10_int z = ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) - (z))), y0);
    }))
    ;
    
    //#line 717 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((((((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
             FMGL(count))->decrementAndGet()) > (((x10_int)0))))
    {
        
        //#line 718 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(lock)->unlock();
        
        //#line 719 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 721 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > e =
      ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
        FMGL(exceptions);
    
    //#line 722 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
      FMGL(exceptions) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 723 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (((((x10_int) ((((x10_int)2)) * (((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                          FMGL(length))))) > (x10aux::num_hosts)))
    {
        
        //#line 724 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > m =
          x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                               FMGL(counts));
        
        //#line 725 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 725 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (x10aux::num_hosts));
                 
                 //#line 725 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 725 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                   FMGL(counts))->set(((x10_int)0), i);
            }
        }
        
        //#line 726 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(length) =
          ((x10_int)1);
        
        //#line 727 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(lock)->unlock();
        
        //#line 728 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(x10aux::null,
                                    e)))
        {
            
            //#line 729 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t;
            
            //#line 730 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->size(),
                                       ((x10_int)1))))
            {
                
                //#line 731 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::nullCheck(e)->peek();
            }
            else
            {
                
                //#line 733 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Throwable> >(x10::lang::MultipleExceptions::_make(e));
            }
            
            //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteFinish__closure__0)))x10_lang_Runtime__RemoteFinish__closure__0(r, m, t))));
            
            //#line 736 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 737 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        else
        {
            
            //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteFinish__closure__1)))x10_lang_Runtime__RemoteFinish__closure__1(r, m))));
            
            //#line 740 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 741 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        
        //#line 743 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    else
    {
        
        //#line 745 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m =
          x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> >::make(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                                                         FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(sizeof(x10_lang_Runtime__RemoteFinish__closure__2)))x10_lang_Runtime__RemoteFinish__closure__2(this)))));
        
        //#line 746 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 746 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (x10aux::num_hosts));
                 
                 //#line 746 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 746 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                   FMGL(counts))->set(((x10_int)0), i);
            }
        }
        
        //#line 747 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(length) =
          ((x10_int)1);
        
        //#line 748 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(lock)->unlock();
        
        //#line 749 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(x10aux::null,
                                    e)))
        {
            
            //#line 750 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t;
            
            //#line 751 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->size(),
                                       ((x10_int)1))))
            {
                
                //#line 752 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::nullCheck(e)->peek();
            }
            else
            {
                
                //#line 754 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Throwable> >(x10::lang::MultipleExceptions::_make(e));
            }
            
            //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__3>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteFinish__closure__3)))x10_lang_Runtime__RemoteFinish__closure__3(r, m, t))));
            
            //#line 757 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 758 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        else
        {
            
            //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__4>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteFinish__closure__4)))x10_lang_Runtime__RemoteFinish__closure__4(r, m))));
            
            //#line 761 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 762 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        
        //#line 764 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
}

//#line 771 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__RemoteFinish::pushException(
  x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 772 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
      FMGL(lock)->lock();
    
    //#line 773 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                                 FMGL(exceptions))))
    {
        
        //#line 773 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
          FMGL(exceptions) =
          x10::util::Stack<x10aux::ref<x10::lang::Throwable> >::_make();
    }
    
    //#line 774 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
                        FMGL(exceptions))->push(
      t);
    
    //#line 775 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this)->
      FMGL(lock)->unlock();
}

//#line 673 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__RemoteFinish::_constructor(
  ) {
    this->x10::lang::Object::_constructor();
    
    //#line 678 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(exceptions) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 683 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(lock) = x10::lang::Runtime__Lock::_make();
    
    //#line 688 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(counts) = x10::lang::Rail<void>::make<x10_int >(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__5>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_lang_Runtime__RemoteFinish__closure__5)))x10_lang_Runtime__RemoteFinish__closure__5()))));
    
    //#line 690 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(message) = x10::lang::Rail<void>::make<x10_int >(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__6>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_lang_Runtime__RemoteFinish__closure__6)))x10_lang_Runtime__RemoteFinish__closure__6()))));
    
    //#line 691 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(length) = ((x10_int)1);
    
    //#line 693 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteFinish>)this))->
      FMGL(count) = x10::util::concurrent::atomic::AtomicInteger::_make(((x10_int)0));
    
}
x10aux::ref<x10::lang::Runtime__RemoteFinish> x10::lang::Runtime__RemoteFinish::_make(
  ) {
    x10aux::ref<x10::lang::Runtime__RemoteFinish> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__RemoteFinish>(), 0, sizeof(x10::lang::Runtime__RemoteFinish))) x10::lang::Runtime__RemoteFinish();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::lang::Runtime__RemoteFinish::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__RemoteFinish::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__RemoteFinish::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__RemoteFinish::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__RemoteFinish::rtt;
void x10::lang::Runtime__RemoteFinish::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime$RemoteFinish", 1, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__0>x10_lang_Runtime__RemoteFinish__closure__0::_itable(&x10_lang_Runtime__RemoteFinish__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteFinish__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__1>x10_lang_Runtime__RemoteFinish__closure__1::_itable(&x10_lang_Runtime__RemoteFinish__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteFinish__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> >::itable<x10_lang_Runtime__RemoteFinish__closure__2>x10_lang_Runtime__RemoteFinish__closure__2::_itable(&x10_lang_Runtime__RemoteFinish__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >, &x10_lang_Runtime__RemoteFinish__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__2::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__3>x10_lang_Runtime__RemoteFinish__closure__3::_itable(&x10_lang_Runtime__RemoteFinish__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteFinish__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__3::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__4>x10_lang_Runtime__RemoteFinish__closure__4::_itable(&x10_lang_Runtime__RemoteFinish__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteFinish__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__4::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RemoteFinish__closure__5>x10_lang_Runtime__RemoteFinish__closure__5::_itable(&x10_lang_Runtime__RemoteFinish__closure__5::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__5::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__5::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_lang_Runtime__RemoteFinish__closure__5::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__5::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__5::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RemoteFinish__closure__6>x10_lang_Runtime__RemoteFinish__closure__6::_itable(&x10_lang_Runtime__RemoteFinish__closure__6::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteFinish__closure__6::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__RemoteFinish__closure__6::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_lang_Runtime__RemoteFinish__closure__6::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__RemoteFinish__closure__6::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteFinish__closure__6::_deserialize<x10::lang::Object>);

