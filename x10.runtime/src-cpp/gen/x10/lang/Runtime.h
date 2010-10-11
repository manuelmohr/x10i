#ifndef __X10_LANG_RUNTIME_H
#define __X10_LANG_RUNTIME_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
class Runtime__Pool;
} } 
namespace x10 { namespace lang { 
class Runtime__Monitor;
} } 
namespace x10 { namespace lang { 
class Runtime__FinishStates;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class PlaceLocalHandle;
} } 
#include <x10/lang/PlaceLocalHandle.struct_h>
namespace x10 { namespace lang { 
class Runtime__RemoteFinish;
} } 
namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 
namespace x10 { namespace lang { 
class Runtime__Worker;
} } 
namespace x10 { namespace lang { 
class Runtime__Thread;
} } 
namespace x10 { namespace lang { 
class Activity;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Clock;
} } 
namespace x10 { namespace lang { 
class Runtime__FinishState;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Runtime__RemoteControl;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
class Error;
} } 
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__Remote;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Future;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
class Runtime__ClockPhases;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace util { 
class Random;
} } 
namespace x10 { namespace lang { 
class Runtime__Latch;
} } 
namespace x10 { namespace lang { 

class Runtime : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    static x10_long nativeThis(x10aux::ref<x10::lang::Object> x);
    template<class FMGL(T)> static x10aux::ref<x10::lang::String> nativeClosureName(
      FMGL(T) cl);
    static x10_boolean FMGL(NO_STEALS);
    
    static inline x10_boolean FMGL(NO_STEALS__get)() {
        return x10::lang::Runtime::FMGL(NO_STEALS);
    }
    static x10_int FMGL(INIT_THREADS);
    
    static inline x10_int FMGL(INIT_THREADS__get)() {
        return x10::lang::Runtime::FMGL(INIT_THREADS);
    }
    static x10_boolean FMGL(STATIC_THREADS);
    
    static inline x10_boolean FMGL(STATIC_THREADS__get)() {
        return x10::lang::Runtime::FMGL(STATIC_THREADS);
    }
    static void runAtNative(x10_int id, x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void runAtLocal(x10_int id, x10aux::ref<x10::lang::VoidFun_0_0> body);
    template<class FMGL(T)> static FMGL(T) pretendLocal(FMGL(T) x);
    static x10_boolean isLocal(x10_int id);
    static void event_probe();
    static x10_long getAsyncsSent();
    static void setAsyncsSent(x10_long v);
    static x10_long getAsyncsReceived();
    static void setAsyncsReceived(x10_long v);
    static x10_long getSerializedBytes();
    static void setSerializedBytes(x10_long v);
    static x10_long getDeserializedBytes();
    static void setDeserializedBytes(x10_long v);
    static void deallocObject(x10aux::ref<x10::lang::Object> o);
    template<class FMGL(T)> static void dealloc(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > o);
    static void dealloc(x10aux::ref<x10::lang::VoidFun_0_0> o);
    static void registerHandlers();
    static void probe();
    static x10_boolean FMGL(PRINT_STATS);
    
    static inline x10_boolean FMGL(PRINT_STATS__get)() {
        return x10::lang::Runtime::FMGL(PRINT_STATS);
    }
    static void dump();
    x10aux::ref<x10::lang::Runtime__Pool> FMGL(pool);
    
    x10aux::ref<x10::lang::Runtime__Monitor> FMGL(monitor);
    
    x10aux::ref<x10::lang::Runtime__FinishStates> FMGL(finishStates);
    
    void _constructor(x10aux::ref<x10::lang::Runtime__Pool> pool);
    
    static x10aux::ref<x10::lang::Runtime> _make(x10aux::ref<x10::lang::Runtime__Pool> pool);
    
    static x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Runtime> >
      FMGL(runtime);
    
    static void FMGL(runtime__do_init)();
    static void FMGL(runtime__init)();
    static volatile x10aux::status FMGL(runtime__status);
    static inline x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Runtime> >
      FMGL(runtime__get)() {
        if (FMGL(runtime__status) != x10aux::INITIALIZED) {
            FMGL(runtime__init)();
        }
        return x10::lang::Runtime::FMGL(runtime);
    }
    static x10aux::ref<x10::lang::Object>
      FMGL(runtime__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(runtime__id);
    
    static x10aux::ref<x10::lang::Runtime__RemoteFinish>
      proxy(
      x10aux::ref<x10::lang::Runtime__RootFinish> rootFinish);
    static x10aux::ref<x10::lang::Runtime__Worker>
      worker(
      );
    static x10aux::ref<x10::lang::Activity>
      activity(
      );
    static x10::lang::Place
      here(
      );
    static x10_int
      hereInt(
      );
    static x10_int
      surplusActivityCount(
      );
    static void
      start(
      x10aux::ref<x10::lang::VoidFun_0_0> init,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      report(
      );
    static void
      runAsync(
      x10::lang::Place place,
      x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runAsync(
      x10::lang::Place place,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runAsync(
      x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runAsync(
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runUncountedAsync(
      x10::lang::Place place,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runUncountedAsync(
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    static void
      runAt(
      x10::lang::Place place,
      x10aux::ref<x10::lang::VoidFun_0_0> body);
    template<class FMGL(T)>
    static FMGL(T)
      evalAt(
      x10::lang::Place place,
      x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval);
    template<class FMGL(T)>
    static x10aux::ref<x10::lang::Future<FMGL(T)> >
      evalFuture(
      x10::lang::Place place,
      x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval);
    static void
      lock(
      );
    static void
      await(
      );
    static void
      release(
      );
    static x10aux::ref<x10::lang::Runtime__ClockPhases>
      clockPhases(
      );
    static void
      next(
      );
    static x10aux::ref<x10::lang::Runtime__FinishState>
      currentState(
      );
    static void
      startFinish(
      );
    static void
      stopFinish(
      );
    static void
      pushException(
      x10aux::ref<x10::lang::Throwable> t);
    static x10_boolean
      safe(
      );
    static x10aux::ref<x10::lang::Activity>
      scan(
      x10aux::ref<x10::util::Random> random,
      x10aux::ref<x10::lang::Runtime__Latch> latch,
      x10_boolean block);
    static void
      execute(
      x10aux::ref<x10::lang::Activity> activity);
    static void
      increaseParallelism(
      );
    static void
      decreaseParallelism(
      x10_int n);
    static void
      park(
      );
    static void
      unpark(
      x10aux::ref<x10::lang::Runtime__Thread> thread);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::lang::Runtime> this_,
                                   x10aux::serialization_buffer& buf);
    
    public: x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_LANG_RUNTIME_H

namespace x10 { namespace lang { 
class Runtime;
} } 

#ifndef X10_LANG_RUNTIME_H_NODEPS
#define X10_LANG_RUNTIME_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/compiler/Native.h>
#include <x10/lang/String.h>
#include <x10/lang/Long.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Int.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Runtime__Pool.h>
#include <x10/lang/Runtime__Monitor.h>
#include <x10/lang/Runtime__FinishStates.h>
#include <x10/lang/PlaceLocalHandle.h>
#include <x10/lang/Runtime__RemoteFinish.h>
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/Runtime__Worker.h>
#include <x10/lang/Runtime__Thread.h>
#include <x10/lang/Activity.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Place.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Clock.h>
#include <x10/lang/Runtime__FinishState.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Runtime__RemoteControl.h>
#include <x10/util/Box.h>
#include <x10/lang/Error.h>
#include <x10/lang/RuntimeException.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Runtime__Remote.h>
#include <x10/util/Box.h>
#include <x10/lang/Future.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Runtime__ClockPhases.h>
#include <x10/util/Stack.h>
#include <x10/util/Random.h>
#include <x10/lang/Runtime__Latch.h>
#ifndef X10_LANG_RUNTIME__CLOSURE__15_CLOSURE
#define X10_LANG_RUNTIME__CLOSURE__15_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__closure__15 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__15<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1306 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(f1)->run();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Future<FMGL(T)> > f1;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->f1);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Future<FMGL(T)> > that_f1 = buf.read<x10aux::ref<x10::lang::Future<FMGL(T)> > >();
        x10aux::ref<x10_lang_Runtime__closure__15<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__closure__15<FMGL(T) > >()) x10_lang_Runtime__closure__15<FMGL(T) >(that_f1);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__15(x10aux::ref<x10::lang::Future<FMGL(T)> > f1) : f1(f1) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1306";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__15<FMGL(T) > >x10_lang_Runtime__closure__15<FMGL(T) >::_itable(&x10_lang_Runtime__closure__15<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__15<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__closure__15<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__15<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__closure__15<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__15<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__CLOSURE__15_CLOSURE
#ifndef X10_LANG_RUNTIME__CLOSURE__14_CLOSURE
#define X10_LANG_RUNTIME__CLOSURE__14_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__closure__14 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > >::template itable <x10_lang_Runtime__closure__14<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::lang::Future<FMGL(T)> > apply() {
        
        //#line 1305 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Future<FMGL(T)> > f1 = x10::lang::Future<FMGL(T)>::_make(eval);
        
        //#line 1306 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::runAsync(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__15<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__15<FMGL(T)>)))x10_lang_Runtime__closure__15<FMGL(T)>(f1)))));
        
        //#line 1307 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return f1;
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->eval);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > that_eval = buf.read<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >();
        x10aux::ref<x10_lang_Runtime__closure__14<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__closure__14<FMGL(T) > >()) x10_lang_Runtime__closure__14<FMGL(T) >(that_eval);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__14(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval) : eval(eval) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1304-1308";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > >::template itable <x10_lang_Runtime__closure__14<FMGL(T) > >x10_lang_Runtime__closure__14<FMGL(T) >::_itable(&x10_lang_Runtime__closure__14<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__14<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__closure__14<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > >, &x10_lang_Runtime__closure__14<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__closure__14<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__14<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__CLOSURE__14_CLOSURE
#ifndef X10_LANG_RUNTIME__CLOSURE__13_CLOSURE
#define X10_LANG_RUNTIME__CLOSURE__13_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__closure__13 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__13<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1283 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(e) = x10::util::Box<void>::__implicit_convert<x10aux::ref<x10::lang::Throwable> >(
                         e);
        
        //#line 1284 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(latch)->release();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box;
    x10aux::ref<x10::lang::Throwable> e;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->box);
        buf.write(this->e);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > that_box = buf.read<x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > >();
        x10aux::ref<x10::lang::Throwable> that_e = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__closure__13<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__closure__13<FMGL(T) > >()) x10_lang_Runtime__closure__13<FMGL(T) >(that_box, that_e);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__13(x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box, x10aux::ref<x10::lang::Throwable> e) : box(box), e(e) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1282-1285";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__13<FMGL(T) > >x10_lang_Runtime__closure__13<FMGL(T) >::_itable(&x10_lang_Runtime__closure__13<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__13<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__closure__13<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__13<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__closure__13<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__13<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__CLOSURE__13_CLOSURE
#ifndef X10_LANG_RUNTIME__CLOSURE__12_CLOSURE
#define X10_LANG_RUNTIME__CLOSURE__12_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__closure__12 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__12<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1278 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(t) = x10::util::Box<void>::__implicit_convert<FMGL(T) >(
                         result);
        
        //#line 1279 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(latch)->release();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box;
    FMGL(T) result;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->box);
        buf.write(this->result);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > that_box = buf.read<x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > >();
        FMGL(T) that_result = buf.read<FMGL(T)>();
        x10aux::ref<x10_lang_Runtime__closure__12<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__closure__12<FMGL(T) > >()) x10_lang_Runtime__closure__12<FMGL(T) >(that_box, that_result);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__12(x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box, FMGL(T) result) : box(box), result(result) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1277-1280";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__12<FMGL(T) > >x10_lang_Runtime__closure__12<FMGL(T) >::_itable(&x10_lang_Runtime__closure__12<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__12<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__closure__12<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__12<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__closure__12<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__12<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__CLOSURE__12_CLOSURE
#ifndef X10_LANG_RUNTIME__CLOSURE__11_CLOSURE
#define X10_LANG_RUNTIME__CLOSURE__11_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__closure__11 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__11<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1275 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Try_c
        try {
            
            //#line 1276 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            FMGL(T) result = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(eval))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_0<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)eval)->_getITables())->apply))();
            
            //#line 1277 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((box)->location),
                                         x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__12<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__12<FMGL(T)>)))x10_lang_Runtime__closure__12<FMGL(T)>(box, result)))));
        }
        catch (x10aux::__ref& __ref__925) {
            x10aux::ref<x10::lang::Throwable>& __exc__ref__925 = (x10aux::ref<x10::lang::Throwable>&)__ref__925;
            if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__925)) {
                x10aux::ref<x10::lang::Throwable> e = static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__925);
                {
                    
                    //#line 1282 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((box)->location),
                                                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__13<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__13<FMGL(T)>)))x10_lang_Runtime__closure__13<FMGL(T)>(box, e)))));
                }
            } else
            throw;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval;
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->eval);
        buf.write(this->box);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > that_eval = buf.read<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >();
        x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > that_box = buf.read<x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > >();
        x10aux::ref<x10_lang_Runtime__closure__11<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__closure__11<FMGL(T) > >()) x10_lang_Runtime__closure__11<FMGL(T) >(that_eval, that_box);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__11(x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval, x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box) : eval(eval), box(box) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1274-1287";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__closure__11<FMGL(T) > >x10_lang_Runtime__closure__11<FMGL(T) >::_itable(&x10_lang_Runtime__closure__11<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__closure__11<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__closure__11<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__closure__11<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__closure__11<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__closure__11<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__CLOSURE__11_CLOSURE
#ifndef X10_LANG_RUNTIME_H_GENERICS
#define X10_LANG_RUNTIME_H_GENERICS
#ifndef X10_LANG_RUNTIME_H_nativeClosureName_881
#define X10_LANG_RUNTIME_H_nativeClosureName_881
template<class FMGL(T)> x10aux::ref<x10::lang::String> x10::lang::Runtime::nativeClosureName(
  FMGL(T) cl) {
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::to_string(cl);
    
}
#endif // X10_LANG_RUNTIME_H_nativeClosureName_881
#ifndef X10_LANG_RUNTIME_H_pretendLocal_884
#define X10_LANG_RUNTIME_H_pretendLocal_884
template<class FMGL(T)> FMGL(T) x10::lang::Runtime::pretendLocal(
  FMGL(T) x) {
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return (__extension__ ({
        FMGL(T) __desugarer__var__48__ = x;
        
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        FMGL(T) __var885__;
        
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
        goto __ret1981; __ret1981: 
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
        do {
        {
            
            //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if (!((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__48__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("T{self.home==here}"))));
            }
            
            //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            __var885__ = __desugarer__var__48__;
            
            //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
            goto __ret1981_end_;
        }
        goto __ret1981_next_; __ret1981_next_: ;
        } while (false);
        goto __ret1981_end_; __ret1981_end_: ;
        __var885__;
    }))
    ;
    
}
#endif // X10_LANG_RUNTIME_H_pretendLocal_884
#ifndef X10_LANG_RUNTIME_H_dealloc_897
#define X10_LANG_RUNTIME_H_dealloc_897
template<class FMGL(T)> void x10::lang::Runtime::dealloc(
  x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > o) {
 
}
#endif // X10_LANG_RUNTIME_H_dealloc_897
#ifndef X10_LANG_RUNTIME_H_evalAt_924
#define X10_LANG_RUNTIME_H_evalAt_924
template<class FMGL(T)> FMGL(T) x10::lang::Runtime::evalAt(
  x10::lang::Place place,
  x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval) {
    
    //#line 1273 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > box =
      x10::lang::Runtime__Remote<FMGL(T)>::_make();
    
    //#line 1274 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAsync(place, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__11<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__11<FMGL(T)>)))x10_lang_Runtime__closure__11<FMGL(T)>(eval, box)))));
    
    //#line 1288 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!(x10aux::no_steals())) && x10::lang::Runtime::safe())
    {
        
        //#line 1288 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(x10::lang::Runtime::worker())->x10::lang::Runtime__Worker::join(
          box->
            FMGL(latch));
    }
    
    //#line 1289 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    box->FMGL(latch)->await();
    
    //#line 1290 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::null,
                                box->
                                  FMGL(e))))
    {
        
        //#line 1291 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Throwable> x =
          x10aux::nullCheck(box->
                              FMGL(e))->
            FMGL(value);
        
        //#line 1292 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (x10aux::instanceof<x10aux::ref<x10::lang::Error> >(x))
        {
            
            //#line 1293 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
            x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::Error> >(x)));
        }
        
        //#line 1294 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if (x10aux::instanceof<x10aux::ref<x10::lang::RuntimeException> >(x))
        {
            
            //#line 1295 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
            x10aux::throwException(x10aux::nullCheck(x10aux::class_cast<x10aux::ref<x10::lang::RuntimeException> >(x)));
        }
        
    }
    
    //#line 1297 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(box->FMGL(t))->
             FMGL(value);
    
}
#endif // X10_LANG_RUNTIME_H_evalAt_924
#ifndef X10_LANG_RUNTIME_H_evalFuture_926
#define X10_LANG_RUNTIME_H_evalFuture_926
template<class FMGL(T)> x10aux::ref<x10::lang::Future<FMGL(T)> >
  x10::lang::Runtime::evalFuture(
  x10::lang::Place place,
  x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > eval) {
    
    //#line 1304 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Future<FMGL(T)> > f =
      x10::lang::Runtime::template evalAt<x10aux::ref<x10::lang::Future<FMGL(T)> > >(
        place,
        x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > > >(x10aux::ref<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > >(x10aux::ref<x10_lang_Runtime__closure__14<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<x10aux::ref<x10::lang::Future<FMGL(T)> > > >(sizeof(x10_lang_Runtime__closure__14<FMGL(T)>)))x10_lang_Runtime__closure__14<FMGL(T)>(eval)))));
    
    //#line 1309 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
    return f;
    
}
#endif // X10_LANG_RUNTIME_H_evalFuture_926
template<class __T> x10aux::ref<__T> x10::lang::Runtime::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime> this_ = new (x10aux::alloc_remote<x10::lang::Runtime>()) x10::lang::Runtime();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::lang::Runtime::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::lang::Runtime> this_;
    if (rr.ref != 0) {
        this_ = x10::lang::Runtime::_deserializer<x10::lang::Runtime>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_LANG_RUNTIME_H_GENERICS
#endif // __X10_LANG_RUNTIME_H_NODEPS
