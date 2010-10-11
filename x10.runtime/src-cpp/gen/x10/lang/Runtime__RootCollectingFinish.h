#ifndef __X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H
#define __X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H

#include <x10rt.h>


#define X10_LANG_RUNTIME__ROOTFINISH_H_NODEPS
#include <x10/lang/Runtime__RootFinish.h>
#undef X10_LANG_RUNTIME__ROOTFINISH_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__StatefulReducer;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Reducible;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__RemoteCollectingFinish;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Runtime__RemoteFinish;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Runtime__RootCollectingFinish;
template <> class Runtime__RootCollectingFinish<void>;
template<class FMGL(T)> class Runtime__RootCollectingFinish : public x10::lang::Runtime__RootFinish
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[5];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Fun_0_0<x10_boolean>::template itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > _itable_1;
    
    static x10::lang::Runtime__FinishState::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > _itable_2;
    
    static x10::lang::Runtime__Mortal::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > _itable_3;
    
    virtual x10_boolean _isMortal() { return true; }
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > FMGL(sr);
    
    x10aux::ref<x10::lang::Reducible<FMGL(T)> > FMGL(reducer);
    
    void _constructor(x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    static x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > _make(
             x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    virtual void accept(FMGL(T) t);
    virtual void accept(FMGL(T) t, x10_int id);
    virtual void notify(x10aux::ref<x10::lang::ValRail<x10_int > > rail,
                        FMGL(T) v);
    virtual void notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail,
                         FMGL(T) v);
    virtual x10aux::ref<x10::lang::Runtime__RemoteFinish>
      makeRemote(
      );
    virtual FMGL(T) waitForFinishExpr(x10_boolean safe);
    public: virtual void notify(x10aux::ref<x10::lang::ValRail<x10_int > > p0);
    public: virtual void notify(x10aux::ref<x10::lang::ValRail<x10_int > > p0, x10aux::ref<x10::lang::Throwable> p1);
    public: virtual void notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > p0);
    public: virtual void notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > p0, x10aux::ref<x10::lang::Throwable> p1);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Runtime__RootCollectingFinish<void> : public x10::lang::Runtime__RootFinish
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H

namespace x10 { namespace lang { 
template<class FMGL(T)>
class Runtime__RootCollectingFinish;
} } 

#ifndef X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_NODEPS
#define X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_NODEPS
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/Runtime__StatefulReducer.h>
#include <x10/lang/Reducible.h>
#include <x10/lang/Int.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Place.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Pair.h>
#include <x10/lang/Runtime__RemoteCollectingFinish.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Runtime__RemoteFinish.h>
#ifndef X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_GENERICS
#define X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >()) x10::lang::Runtime__RootCollectingFinish<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_GENERICS
#ifndef X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_IMPLEMENTATION
#define X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_IMPLEMENTATION
#include <x10/lang/Runtime__RootCollectingFinish.h>


#include "x10/lang/Runtime__RootCollectingFinish.inc"

template<class FMGL(T)> typename x10::lang::Fun_0_0<x10_boolean>::template itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >  x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_itable_0(&x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::apply, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::equals, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::hashCode, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::home, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::toString, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >  x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_itable_1(&x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::equals, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::hashCode, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::home, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::toString, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Runtime__FinishState::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >  x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_itable_2(&x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::equals, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::hashCode, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::home, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notifyActivityCreation, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notifyActivityTermination, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notifySubActivitySpawn, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::pushException, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::toString, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::typeName, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::waitForFinish);
template<class FMGL(T)> x10::lang::Runtime__Mortal::itable<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >  x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_itable_3(&x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::at, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::equals, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::hashCode, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::home, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::toString, &x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_itables[5] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10_boolean> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Runtime__FinishState>, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Runtime__Mortal>, &_itable_3), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >())};
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__RootCollectingFinish<FMGL(T)>");
    
}


//#line 401 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 402 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 403 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    this->x10::lang::Runtime__RootFinish::_constructor();
    
    //#line 405 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
      FMGL(reducer) =
      r;
    
    //#line 406 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this))->
      FMGL(sr) =
      x10::lang::Runtime__StatefulReducer<FMGL(T)>::_make(r);
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >(), 0, sizeof(x10::lang::Runtime__RootCollectingFinish<FMGL(T)>))) x10::lang::Runtime__RootCollectingFinish<FMGL(T)>();
    this_->_constructor(r);
    return this_;
}



//#line 408 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::accept(
  FMGL(T) t) {
    
    //#line 409 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->lock();
    
    //#line 410 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      t);
    
    //#line 411 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->unlock();
}

//#line 413 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::accept(
  FMGL(T) t,
  x10_int id) {
    
    //#line 414 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      t,
      id);
}

//#line 416 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify(
  x10aux::ref<x10::lang::ValRail<x10_int > > rail,
  FMGL(T) v) {
    
    //#line 417 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10_boolean b = true;
    
    //#line 418 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->lock();
    
    //#line 419 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 419 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 419 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 420 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_int > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                    FMGL(counts);
                x10_int y0 =
                  i;
                x10_int z =
                  (rail)->apply(i);
                (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
            }))
            ;
            
            //#line 421 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_boolean > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                    FMGL(seen);
                x10_int y0 =
                  i;
                x10_boolean z =
                  (!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                             FMGL(counts))->apply(i),
                                          ((x10_int)0)));
                (x)->set(((x10_boolean) ((((x)->apply(y0)) ? 1 : 0) | ((z) ? 1 : 0))), y0);
            }))
            ;
            
            //#line 422 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                           FMGL(counts))->apply(i),
                                        ((x10_int)0))))
            {
                
                //#line 422 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                b =
                  false;
            }
            
        }
    }
    
    //#line 424 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      v);
    
    //#line 425 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (b) {
        
        //#line 425 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->release();
    }
    
    //#line 426 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->unlock();
}

//#line 428 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify2(
  x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > rail,
  FMGL(T) v) {
    
    //#line 429 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->lock();
    
    //#line 430 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 430 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(rail)->
                                         FMGL(length)));
             
             //#line 430 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 431 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_int > > x =
                  ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
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
            
            //#line 432 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
               FMGL(seen))->set(true, (rail)->apply(i)->
                                        FMGL(first));
        }
    }
    
    //#line 434 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 434 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::num_hosts));
             
             //#line 434 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 435 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                           FMGL(counts))->apply(i),
                                        ((x10_int)0))))
            {
                
                //#line 436 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                    FMGL(sr))->accept(
                  v);
                
                //#line 437 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->unlock();
                
                //#line 438 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
                return;
            }
            
        }
    }
    
    //#line 441 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      v);
    
    //#line 442 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->release();
    
    //#line 443 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->unlock();
}

//#line 446 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Runtime__RemoteFinish>
  x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::makeRemote(
  ) {
    
    //#line 446 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_make(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                                                        FMGL(reducer));
    
}

//#line 449 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::waitForFinishExpr(
  x10_boolean safe) {
    
    //#line 450 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->waitForFinish(
      safe);
    
    //#line 451 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->placeMerge();
    
    //#line 452 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    FMGL(T) result = x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                                         FMGL(sr))->result();
    
    //#line 453 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->reset();
    
    //#line 454 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return result;
    
}
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify(x10aux::ref<x10::lang::ValRail<x10_int > > p0) {
    x10::lang::Runtime__RootFinish::notify(p0);
}
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify(x10aux::ref<x10::lang::ValRail<x10_int > > p0, x10aux::ref<x10::lang::Throwable> p1) {
    x10::lang::Runtime__RootFinish::notify(p0, p1);
}
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > p0) {
    x10::lang::Runtime__RootFinish::notify2(p0);
}
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::notify2(x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > p0, x10aux::ref<x10::lang::Throwable> p1) {
    x10::lang::Runtime__RootFinish::notify2(p0, p1);
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Runtime__RootFinish::_serialize_body(buf);
    buf.write(this->FMGL(reducer));
    
}

template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Runtime__RootFinish::_deserialize_body(buf);
    FMGL(reducer) = buf.read<x10aux::ref<x10::lang::Reducible<FMGL(T)> > >();
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Runtime__RootCollectingFinish<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Runtime__RootCollectingFinish<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Runtime__RootFinish>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Runtime$RootCollectingFinish";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_IMPLEMENTATION
#endif // __X10_LANG_RUNTIME__ROOTCOLLECTINGFINISH_H_NODEPS
