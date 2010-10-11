#include <x10/lang/Runtime__Pool.h>


#include "x10/lang/Runtime__Pool.inc"

x10::lang::VoidFun_0_0::itable<x10::lang::Runtime__Pool >  x10::lang::Runtime__Pool::_itable_0(&x10::lang::Runtime__Pool::apply, &x10::lang::Runtime__Pool::at, &x10::lang::Runtime__Pool::at, &x10::lang::Runtime__Pool::equals, &x10::lang::Runtime__Pool::hashCode, &x10::lang::Runtime__Pool::home, &x10::lang::Runtime__Pool::toString, &x10::lang::Runtime__Pool::typeName);
x10::lang::Any::itable<x10::lang::Runtime__Pool >  x10::lang::Runtime__Pool::_itable_1(&x10::lang::Runtime__Pool::at, &x10::lang::Runtime__Pool::at, &x10::lang::Runtime__Pool::equals, &x10::lang::Runtime__Pool::hashCode, &x10::lang::Runtime__Pool::home, &x10::lang::Runtime__Pool::toString, &x10::lang::Runtime__Pool::typeName);
x10aux::itable_entry x10::lang::Runtime__Pool::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__Pool>())};
void x10::lang::Runtime__Pool::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Pool");
    
}


//#line 934 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 935 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 937 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 939 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 941 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 944 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Runtime__Pool::FMGL(MAX) = ((x10_int)1000);


//#line 947 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 950 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 952 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Pool::_constructor(x10aux::ref<x10::lang::Runtime__Latch> latch,
                                            x10_int size) {
    this->x10::lang::Object::_constructor();
    
    //#line 935 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(size) = ((x10_int)0);
    
    //#line 937 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(spares) = ((x10_int)0);
    
    //#line 939 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(lock) = x10::lang::Runtime__Lock::_make();
    
    //#line 941 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(semaphore) = x10::lang::Runtime__Semaphore::_make(((x10_int)0));
    
    //#line 953 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(latch) = latch;
    
    //#line 954 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(size) = size;
    
    //#line 955 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Runtime__Worker> > > workers =
      x10::lang::Rail<void>::make<x10aux::ref<x10::lang::Runtime__Worker> >(x10::lang::Runtime__Pool::
                                                                              FMGL(MAX__get)());
    
    //#line 956 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Runtime__Thread> > > threads =
      x10::lang::Rail<void>::make<x10aux::ref<x10::lang::Runtime__Thread> >(size);
    
    //#line 959 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Worker> master =
      x10::lang::Runtime__Worker::_make(latch,
                                        ((x10_int)0));
    
    //#line 960 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (workers)->set(master, ((x10_int)0));
    
    //#line 961 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (threads)->set(x10::lang::Runtime__Thread::currentThread(), ((x10_int)0));
    
    //#line 962 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::Runtime__Thread::currentThread())->x10::lang::Runtime__Thread::worker(
      master);
    
    //#line 963 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(x10aux::nullCheck((workers)->apply(((x10_int)0))))->x10::lang::Runtime__Worker::setWorkerId(
      ((x10_int)0));
    
    //#line 966 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 966 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (size));
             
             //#line 966 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 967 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Runtime__Worker> worker =
              x10::lang::Runtime__Worker::_make(latch,
                                                i);
            
            //#line 968 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (workers)->set(worker, i);
            
            //#line 969 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (threads)->set(x10::lang::Runtime__Thread::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__Pool__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__Pool__closure__0)))x10_lang_Runtime__Pool__closure__0(worker)))),
                                                             ((x10::lang::String::Lit("thread-")) + (i))), i);
            
            //#line 970 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::placeCheck(x10aux::nullCheck((threads)->apply(i)))->x10::lang::Runtime__Thread::worker(
              worker);
            
            //#line 971 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::placeCheck(x10aux::nullCheck((workers)->apply(i)))->x10::lang::Runtime__Worker::setWorkerId(
              i);
        }
    }
    
    //#line 973 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(workers) = workers;
    
    //#line 974 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Pool>)this))->
      FMGL(threads) = threads;
    
}
x10aux::ref<x10::lang::Runtime__Pool> x10::lang::Runtime__Pool::_make(
  x10aux::ref<x10::lang::Runtime__Latch> latch,
  x10_int size) {
    x10aux::ref<x10::lang::Runtime__Pool> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Pool>(), 0, sizeof(x10::lang::Runtime__Pool))) x10::lang::Runtime__Pool();
    this_->_constructor(latch, size);
    return this_;
}



//#line 977 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Pool::apply() {
    
    //#line 978 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int s = ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                  FMGL(size);
    
    //#line 979 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 979 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (s));
             
             //#line 979 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 980 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                 FMGL(threads))->apply(i))->x10::lang::Runtime__Thread::start();
        }
    }
    
    //#line 982 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                         FMGL(workers))->apply(((x10_int)0)))->x10::lang::Runtime__Worker::apply();
    
    //#line 983 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
    while (((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
               FMGL(size)) > (((x10_int)0))))
    {
        
        //#line 983 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime__Thread::park();
    }
    
}

//#line 989 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Pool::increase() {
    
    //#line 990 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(lock)->lock();
    
    //#line 991 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
            FMGL(spares)) > (((x10_int)0))))
    {
        
        //#line 993 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::lang::Runtime__Pool> x =
              ((x10aux::ref<x10::lang::Runtime__Pool>)this);
            x10_int y =
              ((x10_int)1);
            x10aux::nullCheck(x)->
              FMGL(spares) =
              ((x10_int) ((x10aux::nullCheck(x)->
                             FMGL(spares)) - (y)));
        }))
        ;
        
        //#line 994 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
          FMGL(lock)->unlock();
        
        //#line 995 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
          FMGL(semaphore)->release();
    }
    else
    {
        
        //#line 998 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10_int i =
          ((x10_int) (((__extension__ ({
            x10aux::ref<x10::lang::Runtime__Pool> x =
              ((x10aux::ref<x10::lang::Runtime__Pool>)this);
            x10_int y =
              ((x10_int)1);
            x10aux::nullCheck(x)->
              FMGL(size) =
              ((x10_int) ((x10aux::nullCheck(x)->
                             FMGL(size)) + (y)));
        }))
        ) - (((x10_int)1))));
        
        //#line 999 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
          FMGL(lock)->unlock();
        
        //#line 1000 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Assert_c
        #ifndef NO_ASSERTIONS
        if (x10aux::x10__assertions_enabled)
            x10aux::x10__assert(((i) < (x10::lang::Runtime__Pool::
                                          FMGL(MAX__get)())));
        #endif//NO_ASSERTIONS
        
        //#line 1001 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (((i) >= (x10::lang::Runtime__Pool::
                       FMGL(MAX__get)())))
        {
            
            //#line 1002 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(x10::lang::String::Lit("TOO MANY THREADS... ABORTING")))->toString()->c_str());
            
            //#line 1003 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::system_utils::exit(((x10_int)1));
        }
        
        //#line 1005 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Runtime__Worker> worker =
          x10::lang::Runtime__Worker::_make(((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                              FMGL(latch),
                                            i);
        
        //#line 1006 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__Pool>)this)->
           FMGL(workers))->set(worker, i);
        
        //#line 1007 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Runtime__Thread> thread =
          x10::lang::Runtime__Thread::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__Pool__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__Pool__closure__1)))x10_lang_Runtime__Pool__closure__1(worker)))),
                                            ((x10::lang::String::Lit("thread-")) + (i)));
        
        //#line 1008 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        thread->x10::lang::Runtime__Thread::worker(
          worker);
        
        //#line 1009 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        thread->x10::lang::Runtime__Thread::start();
    }
    
}

//#line 1014 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Pool::decrease(x10_int n) {
    
    //#line 1016 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(lock)->lock();
    
    //#line 1017 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Runtime__Pool> x =
          ((x10aux::ref<x10::lang::Runtime__Pool>)this);
        x10_int y =
          n;
        x10aux::nullCheck(x)->
          FMGL(spares) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(spares)) + (y)));
    }))
    ;
    
    //#line 1018 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(lock)->unlock();
    
    //#line 1020 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(semaphore)->reduce(n);
}

//#line 1024 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Pool::release() {
    
    //#line 1025 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(semaphore)->release();
    
    //#line 1026 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(lock)->lock();
    
    //#line 1027 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Runtime__Pool> x =
          ((x10aux::ref<x10::lang::Runtime__Pool>)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(size) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(size)) - (y)));
    }))
    ;
    
    //#line 1028 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                 FMGL(size),
                               ((x10_int)0))))
    {
        
        //#line 1028 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                             FMGL(threads))->apply(((x10_int)0)))->x10::lang::Runtime__Thread::unpark();
    }
    
    //#line 1029 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
      FMGL(lock)->unlock();
}

//#line 1033 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime__Pool::scan(
  x10aux::ref<x10::util::Random> random,
  x10aux::ref<x10::lang::Runtime__Latch> latch,
  x10_boolean block) {
    
    //#line 1034 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> activity =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Activity> >(x10aux::null);
    
    //#line 1035 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int next = x10aux::nullCheck(random)->nextInt(
                     ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                       FMGL(size));
    
    //#line 1036 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        for (; ; ) {
            
            //#line 1037 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::event_probe();
            
            //#line 1038 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(x10aux::null,
                                        (((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                           FMGL(workers))->apply(next))))
            {
                
                //#line 1039 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                activity =
                  x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                       FMGL(workers))->apply(next))->x10::lang::Runtime__Worker::steal();
            }
            
            //#line 1041 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(x10aux::null,
                                        activity)) ||
                x10aux::nullCheck(latch)->apply())
            {
                
                //#line 1041 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                return activity;
                
            }
            
            //#line 1042 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                    FMGL(semaphore)->available()) < (((x10_int)0))))
            {
                
                //#line 1043 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                if (block)
                {
                    
                    //#line 1044 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                      FMGL(semaphore)->release();
                    
                    //#line 1045 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                      FMGL(semaphore)->acquire();
                }
                else
                {
                    
                    //#line 1047 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                    return activity;
                    
                }
                
            }
            
            //#line 1050 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals((next =
                                          ((x10_int) ((next) + (((x10_int)1))))),
                                       ((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                         FMGL(size))))
            {
                
                //#line 1050 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                next =
                  ((x10_int)0);
            }
            
        }
    }
    
}

//#line 1054 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Pool::dump() {
    
    //#line 1055 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 1055 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                         FMGL(size)));
             
             //#line 1055 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 1056 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                                 FMGL(workers))->apply(i))->x10::lang::Runtime__Worker::dump(
              i,
              (((x10aux::ref<x10::lang::Runtime__Pool>)this)->
                 FMGL(threads))->apply(i));
        }
    }
    
}
const x10aux::serialization_id_t x10::lang::Runtime__Pool::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Pool::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Pool::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Pool::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Pool::rtt;
void x10::lang::Runtime__Pool::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::VoidFun_0_0>()};
    rtt.initStageTwo("x10.lang.Runtime$Pool", 2, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Pool__closure__0>x10_lang_Runtime__Pool__closure__0::_itable(&x10_lang_Runtime__Pool__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__Pool__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__Pool__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__Pool__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__Pool__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__Pool__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Pool__closure__1>x10_lang_Runtime__Pool__closure__1::_itable(&x10_lang_Runtime__Pool__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__Pool__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__Pool__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__Pool__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__Pool__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__Pool__closure__1::_deserialize<x10::lang::Object>);

