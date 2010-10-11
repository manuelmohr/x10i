#include <x10/lang/Runtime.h>


#include "x10/lang/Runtime.inc"

void x10::lang::Runtime::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime");
    
}


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime::nativeThis(x10aux::ref<x10::lang::Object> x) {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10_long)0ll);
    
}

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_boolean x10::lang::Runtime::FMGL(NO_STEALS) = false;


//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_int x10::lang::Runtime::FMGL(INIT_THREADS) = ((x10_int)1);


//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_boolean x10::lang::Runtime::FMGL(STATIC_THREADS) = false;


//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAtNative(x10_int id, x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(body))).operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(((x10aux::ref<x10::lang::Reference>)body)->_getITables())->apply))();
}

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAtLocal(x10_int id, x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(body))).operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(((x10aux::ref<x10::lang::Reference>)body)->_getITables())->apply))();
}

//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Runtime::isLocal(x10_int id) {
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(id, x10::lang::Place_methods::_make(x10aux::here)->
                                        FMGL(id)));
    
}

//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::event_probe() {
 
}

//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime::getAsyncsSent() {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10_long) (((x10_int)0)));
    
}

//#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::setAsyncsSent(x10_long v) {
 
}

//#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime::getAsyncsReceived() {
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10_long) (((x10_int)0)));
    
}

//#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::setAsyncsReceived(x10_long v) {
 
}

//#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime::getSerializedBytes() {
    
    //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10_long) (((x10_int)0)));
    
}

//#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::setSerializedBytes(x10_long v) {
 
}

//#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::Runtime::getDeserializedBytes() {
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return ((x10_long) (((x10_int)0)));
    
}

//#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::setDeserializedBytes(x10_long v) {
 
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::deallocObject(x10aux::ref<x10::lang::Object> o) {
 
}

//#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::dealloc(x10aux::ref<x10::lang::VoidFun_0_0> o) {
 
}

//#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::registerHandlers() {
 
}

//#line 928 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::probe() {
    
    //#line 929 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::event_probe();
    
    //#line 930 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::probe();
}

//#line 1063 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
x10_boolean x10::lang::Runtime::FMGL(PRINT_STATS) = false;


//#line 1065 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::dump() {
    
    //#line 1066 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                                       FMGL(runtime__get)()))->
                        FMGL(pool))->dump();
}

//#line 1072 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1075 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1076 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1080 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::Runtime::_constructor(x10aux::ref<x10::lang::Runtime__Pool> pool)
{
    this->x10::lang::Object::_constructor();
    
    //#line 1075 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime>)this))->
      FMGL(monitor) =
      x10::lang::Runtime__Monitor::_make();
    
    //#line 1076 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime>)this))->
      FMGL(finishStates) =
      x10::lang::Runtime__FinishStates::_make();
    
    //#line 1081 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime>)this))->
      FMGL(pool) =
      pool;
    
}
x10aux::ref<x10::lang::Runtime> x10::lang::Runtime::_make(
  x10aux::ref<x10::lang::Runtime__Pool> pool)
{
    x10aux::ref<x10::lang::Runtime> this_ = new (memset(x10aux::alloc<x10::lang::Runtime>(), 0, sizeof(x10::lang::Runtime))) x10::lang::Runtime();
    this_->_constructor(pool);
    return this_;
}



//#line 1087 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c
/**
     * The runtime instance associated with each place
     */x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Runtime> >
                                                                    x10::lang::Runtime::FMGL(runtime);
void x10::lang::Runtime::FMGL(runtime__do_init)() {
    FMGL(runtime__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::lang::Runtime.runtime");
    x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Runtime> >
      __var902__ =
      x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::_make();
    FMGL(runtime) = __var902__;
    FMGL(runtime__status) = x10aux::INITIALIZED;
}
void x10::lang::Runtime::FMGL(runtime__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var903__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(runtime__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var903__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(runtime__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(runtime),
                                                                    FMGL(runtime__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(runtime__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__904 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Runtime::FMGL(runtime__init));

volatile x10aux::status x10::lang::Runtime::FMGL(runtime__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::lang::Runtime::FMGL(runtime__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(runtime) = buf.read<x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Runtime> > >();
    x10::lang::Runtime::FMGL(runtime__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::lang::Runtime::FMGL(runtime__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Runtime::FMGL(runtime__deserialize));


//#line 1089 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__RemoteFinish>
  x10::lang::Runtime::proxy(
  x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish) {
    
    //#line 1089 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                            FMGL(runtime__get)()))->
             FMGL(finishStates)->apply(rootFinish);
    
}

//#line 1094 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__Worker> x10::lang::Runtime::worker(
  ) {
    
    //#line 1095 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::pretendLocal<x10aux::ref<x10::lang::Runtime__Worker> >(
             x10aux::class_cast<x10aux::ref<x10::lang::Runtime__Worker> >(x10aux::nullCheck(x10::lang::Runtime__Thread::currentThread())->x10::lang::Runtime__Thread::worker()));
    
}

//#line 1100 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime::activity(
  ) {
    
    //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::lang::Activity> __desugarer__var__66__ =
          x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::activity();
        
        //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Activity> __var908__;
        
        //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
        goto __ret1982; __ret1982: 
        //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__66__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__66__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Activity{self.home==here}"))));
            }
            
            //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            __var908__ =
              __desugarer__var__66__;
            
            //#line 1101 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
            goto __ret1982_end_;
        }
        goto __ret1982_next_; __ret1982_next_: ;
        }
        while (false);
        goto __ret1982_end_; __ret1982_end_: ;
        __var908__;
    }))
    ;
    
}

//#line 1106 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::lang::Runtime::here(
  ) {
    
    //#line 1107 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Place_methods::place((x10::lang::Runtime__Thread::currentThread())->location);
    
}

//#line 1112 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime::hereInt() {
    
    //#line 1113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10::lang::Runtime__Thread::currentThread())->x10::lang::Runtime__Thread::locInt();
    
}

//#line 1120 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Runtime::surplusActivityCount(
  ) {
    
    //#line 1120 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::size();
    
}

//#line 1125 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::start(x10aux::ref<x10::lang::VoidFun_0_0> init,
                               x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1126 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish =
      x10::lang::Runtime__RootFinish::_make();
    
    //#line 1127 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Pool> pool =
      x10::lang::Runtime__Pool::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__Latch> >(rootFinish),
                                      x10aux::num_threads());
    
    //#line 1128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Try_c
    try {
    try {
        
        //#line 1129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 1129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (x10aux::num_hosts));
                 
                 //#line 1129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 1130 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                if (x10::lang::Runtime::isLocal(
                      i))
                {
                    
                    //#line 1132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::runAtLocal(
                      i,
                      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__0)))x10_lang_Runtime__closure__0(pool)))));
                }
                
            }
        }
        
        //#line 1135 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::DeserializationDispatcher::registerHandlers();
        
        //#line 1136 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(x10aux::here,
                                   ((x10_int)0))))
        {
            
            //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(
              x10::lang::Activity::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__1>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__1)))x10_lang_Runtime__closure__1(init, body)))),
                                         x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__FinishState> >(rootFinish),
                                         true));
            
            //#line 1138 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            pool->apply();
            
            //#line 1139 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!(x10::lang::Runtime::isLocal(
                     ((x10_int) ((x10aux::num_hosts) - (((x10_int)1))))))))
            {
                
                //#line 1140 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
                {
                    x10_int i;
                    for (
                         //#line 1140 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                         i =
                           ((x10_int)1);
                         ((i) < (x10aux::num_hosts));
                         
                         //#line 1140 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                         i =
                           ((x10_int) ((i) + (((x10_int)1)))))
                    {
                        
                        //#line 1141 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                        x10aux::run_at(i, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__2>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__2)))x10_lang_Runtime__closure__2()))));
                    }
                }
                
            }
            
            //#line 1144 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            rootFinish->waitForFinish(
              false);
        }
        else
        {
            
            //#line 1146 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            pool->apply();
        }
        
    }
    catch (x10aux::__ref& __ref__914) {
        throw;
    }
    } catch (...) {
        {
            
            //#line 1149 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (x10::lang::Runtime::FMGL(PRINT_STATS__get)())
            {
                
                //#line 1150 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(((((((x10::lang::String::Lit("ASYNC SENT AT PLACE ")) + (x10::lang::Place_methods::_make(x10aux::here)->
                                                                                                                                                                        FMGL(id)))) + (x10::lang::String::Lit(" = ")))) + (x10aux::asyncs_sent))))->toString()->c_str());
                
                //#line 1151 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(((((((x10::lang::String::Lit("ASYNC RECV AT PLACE ")) + (x10::lang::Place_methods::_make(x10aux::here)->
                                                                                                                                                                        FMGL(id)))) + (x10::lang::String::Lit(" = ")))) + (x10aux::asyncs_received))))->toString()->c_str());
            }
            
        }
        throw;
    }
    {
        
        //#line 1149 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (x10::lang::Runtime::FMGL(PRINT_STATS__get)())
        {
            
            //#line 1150 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(((((((x10::lang::String::Lit("ASYNC SENT AT PLACE ")) + (x10::lang::Place_methods::_make(x10aux::here)->
                                                                                                                                                                    FMGL(id)))) + (x10::lang::String::Lit(" = ")))) + (x10aux::asyncs_sent))))->toString()->c_str());
            
            //#line 1151 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::system_utils::println((x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(((((((x10::lang::String::Lit("ASYNC RECV AT PLACE ")) + (x10::lang::Place_methods::_make(x10aux::here)->
                                                                                                                                                                    FMGL(id)))) + (x10::lang::String::Lit(" = ")))) + (x10aux::asyncs_received))))->toString()->c_str());
        }
        
    }
}

//#line 1156 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::report() {
    
    //#line 1157 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                                       FMGL(runtime__get)()))->
                        FMGL(pool))->release();
}

//#line 1166 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAsync(x10::lang::Place place,
                                  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
                                  x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1167 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1168 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > phases =
      x10aux::nullCheck(x10::lang::Runtime::clockPhases())->_kwd__register(
        clocks);
    
    //#line 1169 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(state)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)state)->_getITables())->notifySubActivitySpawn))(
      place);
    
    //#line 1170 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(place->FMGL(id),
                               x10aux::here)))
    {
        
        //#line 1171 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::execute(
          x10::lang::Activity::_make(body,
                                     state,
                                     clocks,
                                     phases));
    }
    else
    {
        
        //#line 1173 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::VoidFun_0_0> c =
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__3>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__3)))x10_lang_Runtime__closure__3(body, state, clocks, phases))));
        
        //#line 1174 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::run_at(place->
                         FMGL(id), c);
    }
    
}

//#line 1178 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAsync(x10::lang::Place place,
                                  x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1179 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1180 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(state)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)state)->_getITables())->notifySubActivitySpawn))(
      place);
    
    //#line 1181 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_boolean ok = x10::lang::Runtime::safe();
    
    //#line 1182 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(place->FMGL(id),
                               x10aux::here)))
    {
        
        //#line 1183 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::execute(
          x10::lang::Activity::_make(body,
                                     state,
                                     ok));
    }
    else
    {
        
        //#line 1185 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::VoidFun_0_0> closure;
        
        //#line 1187 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (ok)
        {
            
            //#line 1188 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__4>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__4)))x10_lang_Runtime__closure__4(body, state))));
        }
        else
        {
            
            //#line 1190 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__5>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__5)))x10_lang_Runtime__closure__5(body, state))));
        }
        
        //#line 1192 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::run_at(place->
                         FMGL(id), closure);
        
        //#line 1193 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::dealloc(closure.operator->());
    }
    
}

//#line 1197 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAsync(x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
                                  x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1199 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > phases =
      x10aux::nullCheck(x10::lang::Runtime::clockPhases())->_kwd__register(
        clocks);
    
    //#line 1200 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(state)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)state)->_getITables())->notifySubActivitySpawn))(
      x10::lang::Place_methods::_make(x10aux::here));
    
    //#line 1201 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::execute(x10::lang::Activity::_make(body,
                                                           state,
                                                           clocks,
                                                           phases));
}

//#line 1204 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAsync(x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1205 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1206 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(state)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)state)->_getITables())->notifySubActivitySpawn))(
      x10::lang::Place_methods::_make(x10aux::here));
    
    //#line 1207 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::execute(x10::lang::Activity::_make(body,
                                                           state,
                                                           x10::lang::Runtime::safe()));
}

//#line 1210 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runUncountedAsync(
  x10::lang::Place place,
  x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1211 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_boolean ok = x10::lang::Runtime::safe();
    
    //#line 1212 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(place->FMGL(id),
                               x10aux::here)))
    {
        
        //#line 1213 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::execute(
          x10::lang::Activity::_make(body,
                                     ok));
    }
    else
    {
        
        //#line 1215 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::VoidFun_0_0> closure;
        
        //#line 1217 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (ok)
        {
            
            //#line 1218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__6>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__6)))x10_lang_Runtime__closure__6(body))));
        }
        else
        {
            
            //#line 1220 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__7>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__7)))x10_lang_Runtime__closure__7(body))));
        }
        
        //#line 1222 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::run_at(place->
                         FMGL(id), closure);
        
        //#line 1223 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::dealloc(closure.operator->());
    }
    
}

//#line 1227 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runUncountedAsync(
  x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1228 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::execute(x10::lang::Activity::_make(body,
                                                           x10::lang::Runtime::safe()));
}

//#line 1239 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::runAt(x10::lang::Place place,
                               x10aux::ref<x10::lang::VoidFun_0_0> body) {
    
    //#line 1240 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__RemoteControl> box =
      x10::lang::Runtime__RemoteControl::_make();
    
    //#line 1241 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(place, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__8>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__8)))x10_lang_Runtime__closure__8(body, box)))));
    
    //#line 1252 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::no_steals())) && x10::lang::Runtime::safe())
    {
        
        //#line 1252 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::join(
          box->
            FMGL(latch));
    }
    
    //#line 1253 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    box->FMGL(latch)->await();
    
    //#line 1254 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null,
                                box->
                                  FMGL(e))))
    {
        
        //#line 1255 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Throwable> x =
          x10aux::nullCheck(box->
                              FMGL(e))->
            FMGL(value);
        
        //#line 1256 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (x10aux::instanceof<x10aux::ref<x10::lang::Error> >(x))
        {
            
            //#line 1257 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
            x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::Error> >(x)));
        }
        
        //#line 1258 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (x10aux::instanceof<x10aux::ref<x10::lang::RuntimeException> >(x))
        {
            
            //#line 1259 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
            x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::RuntimeException> >(x)));
        }
        
    }
    
}

//#line 1272 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 1303 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 1319 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::lock() {
    
    //#line 1320 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                     FMGL(runtime__get)()))->
      FMGL(monitor)->lock();
}

//#line 1327 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::await() {
    
    //#line 1328 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                     FMGL(runtime__get)()))->
      FMGL(monitor)->await();
}

//#line 1335 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::release() {
    
    //#line 1336 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                     FMGL(runtime__get)()))->
      FMGL(monitor)->release();
}

//#line 1345 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__ClockPhases>
  x10::lang::Runtime::clockPhases(
  ) {
    
    //#line 1346 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1347 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               x10aux::nullCheck(a)->
                                 FMGL(clockPhases))))
    {
        
        //#line 1348 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(a)->
          FMGL(clockPhases) =
          x10::lang::Runtime__ClockPhases::_make();
    }
    
    //#line 1349 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(a)->FMGL(clockPhases);
    
}

//#line 1355 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::next() {
    {
        
        //#line 1355 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10::lang::Runtime::clockPhases())->next();
        
        //#line 1355 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 1363 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Runtime__FinishState>
  x10::lang::Runtime::currentState(
  ) {
    
    //#line 1364 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1365 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               x10aux::nullCheck(a)->
                                 FMGL(finishStack))) ||
        x10aux::nullCheck(x10aux::nullCheck(a)->
                            FMGL(finishStack))->isEmpty())
    {
        
        //#line 1366 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(a)->
                 FMGL(finishState);
        
    }
    
    //#line 1367 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10aux::nullCheck(a)->
                               FMGL(finishStack))->peek();
    
}

//#line 1374 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::startFinish() {
    
    //#line 1375 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1376 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               x10aux::nullCheck(a)->
                                 FMGL(finishStack))))
    {
        
        //#line 1377 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(a)->
          FMGL(finishStack) =
          x10::util::Stack<x10aux::ref<x10::lang::Runtime__FinishState> >::_make();
    }
    
    //#line 1378 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::nullCheck(a)->
                        FMGL(finishStack))->push(
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__FinishState> >(x10::lang::Runtime__RootFinish::_make()));
}

//#line 1387 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::stopFinish() {
    
    //#line 1388 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1389 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> finishState =
      x10aux::nullCheck(x10aux::nullCheck(a)->
                          FMGL(finishStack))->pop();
    
    //#line 1390 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(finishState)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)finishState)->_getITables())->notifyActivityTermination))();
    
    //#line 1391 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(finishState)).operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(((x10aux::ref<x10::lang::Reference>)finishState)->_getITables())->waitForFinish))(
      x10::lang::Runtime::safe());
}

//#line 1398 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::pushException(x10aux::ref<x10::lang::Throwable> t) {
    
    //#line 1399 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck(x10::lang::Runtime::currentState());
    (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Runtime__FinishState>(_->_getITables())->pushException))(
      t); }));
}

//#line 1402 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Runtime::safe() {
    
    //#line 1403 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1404 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(a)->FMGL(safe) &&
    ((x10aux::struct_equals(x10aux::null,
                            x10aux::nullCheck(a)->
                              FMGL(clockPhases))));
    
}

//#line 1408 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Activity> x10::lang::Runtime::scan(
  x10aux::ref<x10::util::Random> random,
  x10aux::ref<x10::lang::Runtime__Latch> latch,
  x10_boolean block) {
    
    //#line 1409 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                                              FMGL(runtime__get)()))->
                               FMGL(pool))->scan(
             random,
             latch,
             block);
    
}

//#line 1414 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::execute(x10aux::ref<x10::lang::Activity> activity) {
    
    //#line 1415 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::push(
      activity);
}

//#line 1419 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::increaseParallelism(
  ) {
    
    //#line 1420 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::static_threads()))) {
        
        //#line 1421 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                                           FMGL(runtime__get)()))->
                            FMGL(pool))->increase();
    }
    
}

//#line 1426 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::decreaseParallelism(
  x10_int n) {
    
    //#line 1427 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::static_threads()))) {
        
        //#line 1428 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                                           FMGL(runtime__get)()))->
                            FMGL(pool))->decrease(
          n);
    }
    
}

//#line 1433 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::park() {
    
    //#line 1434 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::static_threads()))) {
        
        //#line 1435 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime__Thread::park();
    } else {
        
        //#line 1437 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::event_probe();
    }
    
}

//#line 1442 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
void x10::lang::Runtime::unpark(x10aux::ref<x10::lang::Runtime__Thread> thread) {
    
    //#line 1443 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::static_threads()))) {
        
        //#line 1444 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(thread)->x10::lang::Runtime__Thread::unpark();
    }
    
}
const x10aux::serialization_id_t x10::lang::Runtime::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime::_deserializer<x10::lang::Object>);

void x10::lang::Runtime::_serialize(x10aux::ref<x10::lang::Runtime> this_,
                                    x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::lang::Runtime::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::Runtime::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::Runtime::rtt;
void x10::lang::Runtime::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.Runtime", 1, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__0>x10_lang_Runtime__closure__0::_itable(&x10_lang_Runtime__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__0::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__1>x10_lang_Runtime__closure__1::_itable(&x10_lang_Runtime__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__1::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__2>x10_lang_Runtime__closure__2::_itable(&x10_lang_Runtime__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__2::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__3>x10_lang_Runtime__closure__3::_itable(&x10_lang_Runtime__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__3::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__4>x10_lang_Runtime__closure__4::_itable(&x10_lang_Runtime__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__4::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__5>x10_lang_Runtime__closure__5::_itable(&x10_lang_Runtime__closure__5::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__5::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__5::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__5::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__5::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__5::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__6>x10_lang_Runtime__closure__6::_itable(&x10_lang_Runtime__closure__6::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__6::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__6::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__6::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__6::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__6::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__7>x10_lang_Runtime__closure__7::_itable(&x10_lang_Runtime__closure__7::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__7::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__7::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__7::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__7::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__7::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__8>x10_lang_Runtime__closure__8::_itable(&x10_lang_Runtime__closure__8::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__8::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__8::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__8::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__8::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__8::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__9>x10_lang_Runtime__closure__9::_itable(&x10_lang_Runtime__closure__9::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__9::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__9::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__9::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__9::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__9::_deserialize<x10::lang::Object>);

x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__10>x10_lang_Runtime__closure__10::_itable(&x10_lang_Runtime__closure__10::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__10::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_lang_Runtime__closure__10::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__10::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_lang_Runtime__closure__10::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__10::_deserialize<x10::lang::Object>);

