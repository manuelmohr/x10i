#ifndef __X10_LANG_RUNTIME__COLLECTINGFINISH_H
#define __X10_LANG_RUNTIME__COLLECTINGFINISH_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Reducible;
} } 
namespace x10 { namespace lang { 
class Activity;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
class Runtime__FinishState;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__RootCollectingFinish;
} } 
namespace x10 { namespace lang { 
class Runtime__Worker;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__RootCollectingFinish;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__RemoteCollectingFinish;
} } 
namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Runtime__CollectingFinish;
template <> class Runtime__CollectingFinish<void>;
template<class FMGL(T)> class Runtime__CollectingFinish : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    void _constructor(x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    static x10aux::ref<x10::lang::Runtime__CollectingFinish<FMGL(T)> > _make(
             x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    virtual FMGL(T) stopFinishExpr();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Runtime__CollectingFinish<void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    template<class FMGL(T)>
    static void
      offer(
      FMGL(T) t);
    
    
};

} } 
#endif // X10_LANG_RUNTIME__COLLECTINGFINISH_H

namespace x10 { namespace lang { 
template<class FMGL(T)>
class Runtime__CollectingFinish;
} } 

#ifndef X10_LANG_RUNTIME__COLLECTINGFINISH_H_NODEPS
#define X10_LANG_RUNTIME__COLLECTINGFINISH_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Reducible.h>
#include <x10/lang/Activity.h>
#include <x10/lang/Runtime.h>
#include <x10/util/Stack.h>
#include <x10/lang/Runtime__FinishState.h>
#include <x10/lang/Runtime__RootCollectingFinish.h>
#include <x10/lang/Runtime__Worker.h>
#include <x10/lang/Int.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime__RootCollectingFinish.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime__RemoteCollectingFinish.h>
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_LANG_RUNTIME__COLLECTINGFINISH_H_GENERICS
#define X10_LANG_RUNTIME__COLLECTINGFINISH_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Runtime__CollectingFinish<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__CollectingFinish<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Runtime__CollectingFinish<FMGL(T)> >()) x10::lang::Runtime__CollectingFinish<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__COLLECTINGFINISH_H_GENERICS
#ifndef X10_LANG_RUNTIME__COLLECTINGFINISH_H_IMPLEMENTATION
#define X10_LANG_RUNTIME__COLLECTINGFINISH_H_IMPLEMENTATION
#include <x10/lang/Runtime__CollectingFinish.h>


#include "x10/lang/Runtime__CollectingFinish.inc"

template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__CollectingFinish<FMGL(T)>");
    
}


//#line 1452 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    this->x10::lang::Object::_constructor();
    
    //#line 1453 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a =
      x10::lang::Runtime::activity();
    
    //#line 1454 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10aux::null,
                               x10aux::placeCheck(x10aux::nullCheck(a))->
                                 FMGL(finishStack))))
    {
        
        //#line 1455 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(x10aux::nullCheck(a))->
          FMGL(finishStack) =
          x10::util::Stack<x10aux::ref<x10::lang::Runtime__FinishState> >::_make();
    }
    
    //#line 1456 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(x10aux::nullCheck(x10aux::placeCheck(x10aux::nullCheck(a))->
                                           FMGL(finishStack)))->push(
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Runtime__FinishState> >(x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_make(r)));
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Runtime__CollectingFinish<FMGL(T)> > x10::lang::Runtime__CollectingFinish<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    x10aux::ref<x10::lang::Runtime__CollectingFinish<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Runtime__CollectingFinish<FMGL(T)> >(), 0, sizeof(x10::lang::Runtime__CollectingFinish<FMGL(T)>))) x10::lang::Runtime__CollectingFinish<FMGL(T)>();
    this_->_constructor(r);
    return this_;
}



//#line 1460 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c

//#line 1471 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Runtime__CollectingFinish<FMGL(T)>::stopFinishExpr(
  ) {
    
    //#line 1472 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Worker> thisWorker =
      x10::lang::Runtime::worker();
    
    //#line 1473 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int id = x10aux::nullCheck(thisWorker)->
                   FMGL(workerId);
    
    //#line 1474 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((__extension__ ({
                           x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__70__ =
                             x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(state);
                           
                           //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                           x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1048__;
                           
                           //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                           goto __ret2000; __ret2000: 
                           //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                           do
                           {
                           {
                               
                               //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                               if ((!x10aux::struct_equals(__desugarer__var__70__,
                                                           x10aux::null)) &&
                                   !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__70__)->location),
                                                            x10::lang::Place_methods::_make(x10aux::here)))))
                               {
                                   
                                   //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                   x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                               }
                               
                               //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                               __var1048__ =
                                 __desugarer__var__70__;
                               
                               //#line 1475 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                               goto __ret2000_end_;
                           }
                           goto __ret2000_next_; __ret2000_next_: ;
                           }
                           while (false);
                           goto __ret2000_end_; __ret2000_end_: ;
                           __var1048__;
                       }))
                       ))->notifyActivityTermination();
    
    //#line 1476 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert(x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
                              x10::lang::Place_methods::place((((x10aux::ref<x10::lang::Runtime__CollectingFinish<FMGL(T)> >)this))->location)));
    #endif//NO_ASSERTIONS
    
    //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    FMGL(T) result = x10aux::nullCheck(((__extension__ ({
                                            x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__71__ =
                                              x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(state);
                                            
                                            //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                                            x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1049__;
                                            
                                            //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                                            goto __ret2001; __ret2001: 
                                            //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                                            do
                                            {
                                            {
                                                
                                                //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                                if ((!x10aux::struct_equals(__desugarer__var__71__,
                                                                            x10aux::null)) &&
                                                    !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__71__)->location),
                                                                             x10::lang::Place_methods::_make(x10aux::here)))))
                                                {
                                                    
                                                    //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                                    x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                                }
                                                
                                                //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                                __var1049__ =
                                                  __desugarer__var__71__;
                                                
                                                //#line 1477 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                                goto __ret2001_end_;
                                            }
                                            goto __ret2001_next_; __ret2001_next_: ;
                                            }
                                            while (false);
                                            goto __ret2001_end_; __ret2001_end_: ;
                                            __var1049__;
                                        }))
                                        ))->x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::waitForFinishExpr(
                       true);
    
    //#line 1478 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Activity> a = x10::lang::Runtime::activity();
    
    //#line 1479 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::nullCheck(a)->
                        FMGL(finishStack))->pop();
    
    //#line 1480 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return result;
    
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Runtime__CollectingFinish<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__CollectingFinish<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Runtime__CollectingFinish<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Runtime__CollectingFinish<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Runtime$CollectingFinish";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
template<class FMGL(T)> void x10::lang::Runtime__CollectingFinish<void>::offer(FMGL(T) t)
{
    
    //#line 1461 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Worker> thisWorker =
      x10::lang::Runtime::worker();
    
    //#line 1462 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_int id =
      x10aux::nullCheck(thisWorker)->
        FMGL(workerId);
    
    //#line 1463 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__FinishState> state =
      x10::lang::Runtime::currentState();
    
    //#line 1465 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (x10::lang::Place_methods::equals(x10::lang::Place_methods::_make(x10aux::here), 
          x10::lang::Place_methods::place(x10aux::get_location(state))))
    {
        
        //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__68__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(state);
                               
                               //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1050__;
                               
                               //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret2002; __ret2002: 
                               //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__68__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__68__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1050__ =
                                     __desugarer__var__68__;
                                   
                                   //#line 1466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret2002_end_;
                               }
                               goto __ret2002_next_; __ret2002_next_: ;
                               }
                               while (false);
                               goto __ret2002_end_; __ret2002_end_: ;
                               __var1050__;
                           }))
                           ))->accept(
          t,
          id);
    }
    else
    {
        
        //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > __desugarer__var__69__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > >(x10::lang::Runtime::proxy(
                                                                                                                          x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootFinish> >(state)));
                               
                               //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > __var1051__;
                               
                               //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret2003; __ret2003: 
                               //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__69__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__69__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RemoteCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1051__ =
                                     __desugarer__var__69__;
                                   
                                   //#line 1468 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret2003_end_;
                               }
                               goto __ret2003_next_; __ret2003_next_: ;
                               }
                               while (false);
                               goto __ret2003_end_; __ret2003_end_: ;
                               __var1051__;
                           }))
                           ))->accept(
          t,
          id);
    }
    
}
#endif // X10_LANG_RUNTIME__COLLECTINGFINISH_H_IMPLEMENTATION
#endif // __X10_LANG_RUNTIME__COLLECTINGFINISH_H_NODEPS
