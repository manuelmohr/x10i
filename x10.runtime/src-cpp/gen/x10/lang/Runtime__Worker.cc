#include <x10/lang/Runtime__Worker.h>


#include "x10/lang/Runtime__Worker.inc"

x10::lang::VoidFun_0_0::itable<x10::lang::Runtime__Worker >  x10::lang::Runtime__Worker::_itable_0(&x10::lang::Runtime__Worker::apply, &x10::lang::Runtime__Worker::at, &x10::lang::Runtime__Worker::at, &x10::lang::Runtime__Worker::equals, &x10::lang::Runtime__Worker::hashCode, &x10::lang::Runtime__Worker::home, &x10::lang::Runtime__Worker::toString, &x10::lang::Runtime__Worker::typeName);
x10::lang::Any::itable<x10::lang::Runtime__Worker >  x10::lang::Runtime__Worker::_itable_1(&x10::lang::Runtime__Worker::at, &x10::lang::Runtime__Worker::at, &x10::lang::Runtime__Worker::equals, &x10::lang::Runtime__Worker::hashCode, &x10::lang::Runtime__Worker::home, &x10::lang::Runtime__Worker::toString, &x10::lang::Runtime__Worker::typeName);
x10aux::itable_entry x10::lang::Runtime__Worker::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__Worker>())};
void x10::lang::Runtime__Worker::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Worker");
    
}


//#line 819 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 823 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Runtime__Worker::FMGL(BOUND) = ((x10_int)100);


//#line 826 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 829 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 832 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 835 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 837 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 840 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 841 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::setWorkerId(x10_int id) {
    
    //#line 842 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Worker>)this)->FMGL(workerId) = id;
}

//#line 845 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime__Worker::_constructor(x10aux::ref<x10::lang::Runtime__Latch> latch,
                                              x10_int p) {
    this->x10::lang::Object::_constructor();
    
    //#line 826 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(activity) = x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Activity> >(x10aux::null);
    
    //#line 829 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(queue) = x10::lang::Runtime__Deque::_make();
    
    //#line 835 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(debug) = x10::util::GrowableRail<x10aux::ref<x10::lang::Activity> >::_make();
    
    //#line 837 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(tid) = ((x10_long)0ll);
    
    //#line 840 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(workerId) = ((x10_int)0);
    
    //#line 846 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(latch) = latch;
    
    //#line 847 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Worker>)this))->
      FMGL(random) = x10::util::Random::_make(((x10_long) (((x10_int) ((((x10_int) ((((x10_int) ((p) + (((x10_int) ((p) << (((x10_int)8)))))))) + (((x10_int) ((p) << (((x10_int)16)))))))) + (((x10_int) ((p) << (((x10_int)24))))))))));
    
}
x10aux::ref<x10::lang::Runtime__Worker> x10::lang::Runtime__Worker::_make(
  x10aux::ref<x10::lang::Runtime__Latch> latch,
  x10_int p) {
    x10aux::ref<x10::lang::Runtime__Worker> this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Worker>(), 0, sizeof(x10::lang::Runtime__Worker))) x10::lang::Runtime__Worker();
    this_->_constructor(latch, p);
    return this_;
}



//#line 853 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime__Worker::size() {
    
    //#line 853 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Runtime__Worker>)this)->FMGL(queue)->x10::lang::Runtime__Deque::size();
    
}

//#line 856 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime__Worker::activity(
  ) {
    
    //#line 856 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::lang::Runtime__Worker>)this)->FMGL(activity);
    
}

//#line 859 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime__Worker::poll(
  ) {
    
    //#line 859 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::class_cast<x10aux::ref<x10::lang::Activity> >(((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                                                   FMGL(queue)->x10::lang::Runtime__Deque::poll());
    
}

//#line 862 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime__Worker::steal(
  ) {
    
    //#line 862 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::class_cast<x10aux::ref<x10::lang::Activity> >(((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                                                   FMGL(queue)->x10::lang::Runtime__Deque::steal());
    
}

//#line 865 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::push(x10aux::ref<x10::lang::Activity> activity) {
    {
        
        //#line 865 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
          FMGL(queue)->x10::lang::Runtime__Deque::push(
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(activity));
        
        //#line 865 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 868 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::apply() {
    
    //#line 869 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
      FMGL(tid) = x10::lang::Runtime__Thread::getTid();
    
    //#line 870 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Try_c
    try {
    try {
        
        //#line 871 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
        while (((x10aux::ref<x10::lang::Runtime__Worker>)this)->x10::lang::Runtime__Worker::loop(
                 ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                   FMGL(latch),
                 true)) {
            
            //#line 871 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Empty_c
            ;
        }
        
    }
    catch (x10aux::__ref& __ref__1034) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__1034 = (x10aux::ref<x10::lang::Throwable>&)__ref__1034;
        if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__1034)) {
            x10aux::ref<x10::lang::Throwable> t =
              static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__1034);
            {
                
                //#line 873 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(x10::lang::String::Lit("Uncaught exception in worker thread")))->toString()->c_str());
                
                //#line 874 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (t)->printStackTrace();
            }
        } else
        throw;
    }
    } catch (...) {
        {
            
            //#line 876 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::report();
        }
        throw;
    }
    {
        
        //#line 876 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::report();
    }
}

//#line 881 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::join(x10aux::ref<x10::lang::Runtime__Latch> latch) {
    
    //#line 882 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> tmp =
      ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
        FMGL(activity);
    
    //#line 883 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
    while (((x10aux::ref<x10::lang::Runtime__Worker>)this)->x10::lang::Runtime__Worker::loop(
             latch,
             false)) {
        
        //#line 883 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Empty_c
        ;
    }
    
    //#line 884 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
      FMGL(activity) = tmp;
}

//#line 888 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Runtime__Worker::loop(
  x10aux::ref<x10::lang::Runtime__Latch> latch,
  x10_boolean block) {
    
    //#line 889 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 889 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10::lang::Runtime__Worker::
                                         FMGL(BOUND__get)()));
             
             //#line 889 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 890 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (x10aux::nullCheck(latch)->apply())
            {
                
                //#line 890 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                return false;
                
            }
            
            //#line 891 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
              FMGL(activity) =
              ((x10aux::ref<x10::lang::Runtime__Worker>)this)->x10::lang::Runtime__Worker::poll();
            
            //#line 892 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                         FMGL(activity),
                                       x10aux::null)))
            {
                
                //#line 893 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                  FMGL(activity) =
                  x10::lang::Runtime::scan(
                    ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                      FMGL(random),
                    latch,
                    block);
                
                //#line 894 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                if ((x10aux::struct_equals(((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                             FMGL(activity),
                                           x10aux::null)))
                {
                    
                    //#line 894 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                    return false;
                    
                }
                
            }
            
            //#line 896 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::lang::Runtime__Worker>)this)->
               FMGL(debug))->add(x10::lang::Runtime::pretendLocal<x10aux::ref<x10::lang::Activity> >(
                                   ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                     FMGL(activity)));
            
            //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::runAtLocal(
              x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                                 FMGL(activity))->location)->
                FMGL(id),
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__Worker__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__Worker__closure__0)))x10_lang_Runtime__Worker__closure__0(this)))));
            
            //#line 898 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::lang::Runtime__Worker>)this)->
               FMGL(debug))->removeLast();
        }
    }
    
    //#line 900 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 903 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::probe() {
    
    //#line 905 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> tmp =
      ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
        FMGL(activity);
    
    //#line 906 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 907 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
          FMGL(activity) = ((x10aux::ref<x10::lang::Runtime__Worker>)this)->x10::lang::Runtime__Worker::poll();
        
        //#line 908 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                     FMGL(activity),
                                   x10aux::null)))
        {
            
            //#line 909 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
              FMGL(activity) =
              tmp;
            
            //#line 910 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
        
        //#line 912 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__Worker>)this)->
           FMGL(debug))->add(x10::lang::Runtime::pretendLocal<x10aux::ref<x10::lang::Activity> >(
                               ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                 FMGL(activity)));
        
        //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::runAtLocal(x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                                                          FMGL(activity))->location)->
                                         FMGL(id),
                                       x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__Worker__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__Worker__closure__1)))x10_lang_Runtime__Worker__closure__1(this)))));
        
        //#line 914 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::lang::Runtime__Worker>)this)->
           FMGL(debug))->removeLast();
    }
    
}

//#line 918 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime__Worker::dump(x10_int id,
                                      x10aux::ref<x10::lang::Runtime__Thread> thread) {
    
    //#line 919 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::system_utils::printf("WORKER %d", id);
    
    //#line 920 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::system_utils::printf(" = THREAD %#lx\n", ((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                                       FMGL(tid));
    
    //#line 921 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 921 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int) (((((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                 FMGL(debug))->length()) - (((x10_int)1))));
             ((i) >= (((x10_int)0)));
             
             //#line 921 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) - (((x10_int)1)))))
        {
            
            //#line 922 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck((((x10aux::ref<x10::lang::Runtime__Worker>)this)->
                                 FMGL(debug))->apply(i))->dump();
        }
    }
    
    //#line 924 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::system_utils::println("");
}
const x10aux::serialization_id_t x10::lang::Runtime__Worker::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Worker::_deserializer<x10::lang::Object>);

void x10::lang::Runtime__Worker::_serialize(x10aux::ref<x10::lang::Runtime__Worker> this_,
                                            x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::lang::Runtime__Worker::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime__Worker::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime__Worker::rtt;
void x10::lang::Runtime__Worker::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::VoidFun_0_0>()};
    rtt.initStageTwo("x10.lang.Runtime$Worker", 2, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Worker__closure__0>x10_lang_Runtime__Worker__closure__0::_itable(&x10_lang_Runtime__Worker__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__Worker__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__Worker__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__Worker__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__Worker__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__Worker__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Worker__closure__1>x10_lang_Runtime__Worker__closure__1::_itable(&x10_lang_Runtime__Worker__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__Worker__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__Worker__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__Worker__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__Worker__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__Worker__closure__1::_deserialize<x10::lang::Object>);

