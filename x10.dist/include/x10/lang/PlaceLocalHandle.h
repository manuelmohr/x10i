#ifndef __X10_LANG_PLACELOCALHANDLE_H
#define __X10_LANG_PLACELOCALHANDLE_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Object;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace array { 
class Dist;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(U)> class Fun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace compiler { 
class NativeClass;
} } 
#include <x10/lang/PlaceLocalHandle.struct_h>

namespace x10 { namespace lang { 

template<class FMGL(T)> class PlaceLocalHandle_methods  {
    public:
    static void _instance_init(x10::lang::PlaceLocalHandle<FMGL(T)>& this_);
    
    static void _constructor(x10::lang::PlaceLocalHandle<FMGL(T)>& this_, x10::lang::PlaceLocalHandle_Impl<FMGL(T)> id0)
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
        this_->
          FMGL(__NATIVE_FIELD__) =
          id0;
        
    }
    inline static x10::lang::PlaceLocalHandle<FMGL(T)> _make(
             x10::lang::PlaceLocalHandle_Impl<FMGL(T)> id0)
    {
        x10::lang::PlaceLocalHandle<FMGL(T)> this_; 
        _constructor(this_, id0);
        return this_;
    }
    
    static void _constructor(
      x10::lang::PlaceLocalHandle<FMGL(T)>& this_);
    
    inline static x10::lang::PlaceLocalHandle<FMGL(T)> _make(
             )
    {
        x10::lang::PlaceLocalHandle<FMGL(T)> this_; 
        _constructor(this_);
        return this_;
    }
    
    static FMGL(T)
      apply(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_);
    static void
      set(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, FMGL(T) newVal);
    static x10_int
      hashCode(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_);
    static x10aux::ref<x10::lang::String>
      toString(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_);
    template<class FMGL(U)>
    static void
      copyTo(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::Place dst,
      x10_int len,
      x10aux::ref<x10::lang::VoidFun_0_0> notifier);
    static x10::lang::Place
      home(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_);
    static x10aux::ref<x10::lang::String>
      typeName(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_);
    static x10_boolean
      at(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::Place p);
    static x10_boolean
      at(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Object> r);
    static x10_boolean
      equals(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Any> other);
    static x10_boolean
      equals(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::PlaceLocalHandle<FMGL(T)> other);
    static x10_boolean
      _struct_equals(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Any> other);
    static x10_boolean
      _struct_equals(
      x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::PlaceLocalHandle<FMGL(T)> other);
    
};
template <> class PlaceLocalHandle_methods<void> {
    public:
    template<class FMGL(T)> static x10::lang::PlaceLocalHandle<FMGL(T)>
      make(
      x10aux::ref<x10::array::Dist> dist,
      x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > init);
    
    
};

} } 
#endif // X10_LANG_PLACELOCALHANDLE_H

namespace x10 { namespace lang { 
template<class FMGL(T)> class PlaceLocalHandle;
} } 

#ifndef X10_LANG_PLACELOCALHANDLE_H_NODEPS
#define X10_LANG_PLACELOCALHANDLE_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Any.h>
#include <x10/lang/PlaceLocalHandle_Impl.h>
#include <x10/lang/Object.h>
#include <x10/lang/Int.h>
#include <x10/lang/String.h>
#include <x10/lang/Place.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/util/Pair.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/util/Pair.h>
#include <x10/lang/Rail.h>
#include <x10/util/Pair.h>
#include <x10/lang/Rail.h>
#include <x10/util/Pair.h>
#include <x10/lang/Runtime.h>
#include <x10/array/Dist.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Throwable.h>
#include <x10/compiler/Native.h>
#include <x10/lang/Boolean.h>
#include <x10/compiler/NativeClass.h>
#ifndef X10_LANG_PLACELOCALHANDLE__CLOSURE__2_CLOSURE
#define X10_LANG_PLACELOCALHANDLE__CLOSURE__2_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_PlaceLocalHandle__closure__2 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_PlaceLocalHandle__closure__2<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
        x10::lang::PlaceLocalHandle_methods<FMGL(T)>::set(handle, (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(init))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_0<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)init)->_getITables())->apply))());
    }
    
    // captured environment
    x10::lang::PlaceLocalHandle<FMGL(T)> handle;
    x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > init;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->handle);
        buf.write(this->init);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10::lang::PlaceLocalHandle<FMGL(T)> that_handle = buf.read<x10::lang::PlaceLocalHandle<FMGL(T)> >();
        x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > that_init = buf.read<x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > >();
        x10aux::ref<x10_lang_PlaceLocalHandle__closure__2<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_PlaceLocalHandle__closure__2<FMGL(T) > >()) x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >(that_handle, that_init);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_PlaceLocalHandle__closure__2(x10::lang::PlaceLocalHandle<FMGL(T)> handle, x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > init) : handle(handle), init(init) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10:89";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_PlaceLocalHandle__closure__2<FMGL(T) > >x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::_itable(&x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_PlaceLocalHandle__closure__2<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_PLACELOCALHANDLE__CLOSURE__2_CLOSURE
#ifndef X10_LANG_PLACELOCALHANDLE__CLOSURE__1_CLOSURE
#define X10_LANG_PLACELOCALHANDLE__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T)> class x10_lang_PlaceLocalHandle__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> >::template itable <x10_lang_PlaceLocalHandle__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::lang::PlaceLocalHandle<FMGL(T)> apply() {
        
        //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_make();
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_PlaceLocalHandle__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_PlaceLocalHandle__closure__1<FMGL(T) > >()) x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_PlaceLocalHandle__closure__1() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10:87";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> >::template itable <x10_lang_PlaceLocalHandle__closure__1<FMGL(T) > >x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::_itable(&x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > >, &x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_PlaceLocalHandle__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_PLACELOCALHANDLE__CLOSURE__1_CLOSURE
#ifndef X10_LANG_PLACELOCALHANDLE__CLOSURE__0_CLOSURE
#define X10_LANG_PLACELOCALHANDLE__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_0.h>
template<class FMGL(T), class FMGL(U)> class x10_lang_PlaceLocalHandle__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> >::template itable <x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> apply() {
        
        //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
        return x10::util::Pair_methods<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int>::_make(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Rail<FMGL(U) > > >::apply(handle),
                                                                                                ((x10_int)0));
        
    }
    
    // captured environment
    x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > handle;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->handle);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > that_handle = buf.read<x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > >();
        x10aux::ref<x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) > > this_ = new (x10aux::alloc<x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) > >()) x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >(that_handle);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_PlaceLocalHandle__closure__0(x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > handle) : handle(handle) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10:69";
    }

};

template<class FMGL(T), class FMGL(U)> typename x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> >::template itable <x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) > >x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::_itable(&x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T), class FMGL(U)>
x10aux::itable_entry x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > >, &x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T), class FMGL(U)>
const x10aux::serialization_id_t x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_PLACELOCALHANDLE__CLOSURE__0_CLOSURE
#ifndef X10_LANG_PLACELOCALHANDLE_H_GENERICS
#define X10_LANG_PLACELOCALHANDLE_H_GENERICS
#ifndef X10_LANG_PLACELOCALHANDLE_H_copyTo_804
#define X10_LANG_PLACELOCALHANDLE_H_copyTo_804
template<class FMGL(T)> template<class FMGL(U)> void x10::lang::PlaceLocalHandle_methods<FMGL(T)>::copyTo(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::Place dst,
  x10_int len,
  x10aux::ref<x10::lang::VoidFun_0_0> notifier) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10LocalDecl_c
    x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > handle =
      x10aux::class_cast<x10::lang::PlaceLocalHandle<x10aux::ref<x10::lang::Rail<FMGL(U) > > > >(x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(this_));
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > > finder =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > > >(x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > >(x10aux::ref<x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U) > >(new (x10aux::alloc<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(U) > >, x10_int> > >(sizeof(x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U)>)))x10_lang_PlaceLocalHandle__closure__0<FMGL(T),FMGL(U)>(handle))));
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
    x10::lang::Rail__NativeRep::copyTo(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Rail<FMGL(U) > > >::apply(handle),((x10_int)0),dst,finder,len,notifier);
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
    x10aux::dealloc(finder.operator->());
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
    x10aux::dealloc(notifier.operator->());
}
#endif // X10_LANG_PLACELOCALHANDLE_H_copyTo_804
#endif // X10_LANG_PLACELOCALHANDLE_H_GENERICS
#ifndef X10_LANG_PLACELOCALHANDLE_H_IMPLEMENTATION
#define X10_LANG_PLACELOCALHANDLE_H_IMPLEMENTATION
#include <x10/lang/PlaceLocalHandle.h>


#include "x10/lang/PlaceLocalHandle.inc"

namespace x10 { namespace lang { 
template<class FMGL(T)> class PlaceLocalHandle_ithunk0 : public x10::lang::PlaceLocalHandle<FMGL(T)> {
public:
    static x10::lang::Any::itable<PlaceLocalHandle_ithunk0<FMGL(T)> > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(*this) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(*this) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(*this, arg0);
    }
    x10_int hashCode() {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::hashCode(*this);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(*this));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::toString(*this);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(*this);
    }
    
};
template<class FMGL(T)> x10::lang::Any::itable<PlaceLocalHandle_ithunk0<FMGL(T)> >  PlaceLocalHandle_ithunk0<FMGL(T)>::itable(&PlaceLocalHandle_ithunk0<FMGL(T)>::at, &PlaceLocalHandle_ithunk0<FMGL(T)>::at, &PlaceLocalHandle_ithunk0<FMGL(T)>::equals, &PlaceLocalHandle_ithunk0<FMGL(T)>::hashCode, &PlaceLocalHandle_ithunk0<FMGL(T)>::home, &PlaceLocalHandle_ithunk0<FMGL(T)>::toString, &PlaceLocalHandle_ithunk0<FMGL(T)>::typeName);
template<class FMGL(T)> class PlaceLocalHandle_iboxithunk0 : public x10::lang::IBox<x10::lang::PlaceLocalHandle<FMGL(T)> > {
public:
    static x10::lang::Any::itable<PlaceLocalHandle_iboxithunk0<FMGL(T)> > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(this->value) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(this->value) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(this->value, arg0);
    }
    x10_int hashCode() {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::hashCode(this->value);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(this->value));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::toString(this->value);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(this->value);
    }
    
};
template<class FMGL(T)> x10::lang::Any::itable<PlaceLocalHandle_iboxithunk0<FMGL(T)> >  PlaceLocalHandle_iboxithunk0<FMGL(T)>::itable(&PlaceLocalHandle_iboxithunk0<FMGL(T)>::at, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::at, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::equals, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::hashCode, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::home, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::toString, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::typeName);
} } 
template<class FMGL(T)> x10aux::itable_entry x10::lang::PlaceLocalHandle<FMGL(T)>::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &PlaceLocalHandle_ithunk0<FMGL(T)>::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::PlaceLocalHandle<FMGL(T)> >())};
template<class FMGL(T)> x10aux::itable_entry x10::lang::PlaceLocalHandle<FMGL(T)>::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &PlaceLocalHandle_iboxithunk0<FMGL(T)>::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::PlaceLocalHandle<FMGL(T)> >())};
template<class FMGL(T)> void x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_instance_init(x10::lang::PlaceLocalHandle<FMGL(T)>& this_) {
    _I_("Doing initialisation for class: x10::lang::PlaceLocalHandle<FMGL(T)>");
    
}


//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10FieldDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10ConstructorDecl_c


//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_constructor(
                          x10::lang::PlaceLocalHandle<FMGL(T)>& this_)
{
    _constructor(this_, 
      x10::lang::PlaceLocalHandle_Impl_methods<FMGL(T)>::_make());
    
}


//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::lang::PlaceLocalHandle_methods<FMGL(T)>::apply(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::PlaceLocalHandle_Impl_methods<FMGL(T)>::apply(this_->
                                                                      FMGL(__NATIVE_FIELD__));
    
}

//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::PlaceLocalHandle_methods<FMGL(T)>::set(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, FMGL(T) newVal) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
    x10::lang::PlaceLocalHandle_Impl_methods<FMGL(T)>::set(this_->
                                                             FMGL(__NATIVE_FIELD__), 
      newVal);
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::lang::PlaceLocalHandle_methods<FMGL(T)>::hashCode(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::PlaceLocalHandle_Impl_methods<FMGL(T)>::hashCode(this_->
                                                                         FMGL(__NATIVE_FIELD__));
    
}

//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::String>
  x10::lang::PlaceLocalHandle_methods<FMGL(T)>::toString(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::PlaceLocalHandle_Impl_methods<FMGL(T)>::toString(this_->
                                                                         FMGL(__NATIVE_FIELD__));
    
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c

//#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10::lang::Place x10::lang::PlaceLocalHandle_methods<FMGL(T)>::home(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::Place_methods::place(x10aux::get_location(this_->
                                                                  FMGL(__NATIVE_FIELD__)));
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::String>
  x10::lang::PlaceLocalHandle_methods<FMGL(T)>::typeName(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10aux::type_name(this_->FMGL(__NATIVE_FIELD__));
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::at(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::Place p) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return (x10aux::get_location(this_->FMGL(__NATIVE_FIELD__)) == (p)->FMGL(id));
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::at(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Object> r) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return (x10aux::get_location(this_->FMGL(__NATIVE_FIELD__)) == (r)->location);
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::lang::PlaceLocalHandle<FMGL(T)> >(other))))
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(this_, 
             x10aux::class_cast<x10::lang::PlaceLocalHandle<FMGL(T)> >(other));
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::PlaceLocalHandle<FMGL(T)> other) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_struct_equals(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::lang::PlaceLocalHandle<FMGL(T)> >(other))))
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_struct_equals(this_, 
             x10aux::class_cast<x10::lang::PlaceLocalHandle<FMGL(T)> >(other));
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_struct_equals(
  x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10::lang::PlaceLocalHandle<FMGL(T)> other) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return true;
    
}
template<class FMGL(T)> void x10::lang::PlaceLocalHandle<FMGL(T)>::_serialize(x10::lang::PlaceLocalHandle<FMGL(T)> this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(__NATIVE_FIELD__));
    
}

template<class FMGL(T)> void x10::lang::PlaceLocalHandle<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(__NATIVE_FIELD__) = buf.read<x10::lang::PlaceLocalHandle_Impl<FMGL(T)> >();
}


template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle<FMGL(T)>::equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(*this, that);
}
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle<FMGL(T)>::equals(x10::lang::PlaceLocalHandle<FMGL(T)> that) {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::equals(*this, that);
}
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle<FMGL(T)>::_struct_equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_struct_equals(*this, that);
}
template<class FMGL(T)> x10_boolean x10::lang::PlaceLocalHandle<FMGL(T)>::_struct_equals(x10::lang::PlaceLocalHandle<FMGL(T)> that) {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::_struct_equals(*this, that);
}
template<class FMGL(T)> x10aux::ref<x10::lang::String> x10::lang::PlaceLocalHandle<FMGL(T)>::toString() {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::toString(*this);
}
template<class FMGL(T)> x10_int x10::lang::PlaceLocalHandle<FMGL(T)>::hashCode() {
    return x10::lang::PlaceLocalHandle_methods<FMGL(T)>::hashCode(*this);
}
template<class FMGL(T)> x10aux::RuntimeType x10::lang::PlaceLocalHandle<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::PlaceLocalHandle<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::PlaceLocalHandle<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.PlaceLocalHandle";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
template<class FMGL(T)> x10::lang::PlaceLocalHandle<FMGL(T)>
  x10::lang::PlaceLocalHandle_methods<void>::make(x10aux::ref<x10::array::Dist> dist,
                                                  x10aux::ref<x10::lang::Fun_0_0<FMGL(T)> > init)
{
    
    //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10LocalDecl_c
    x10::lang::PlaceLocalHandle<FMGL(T)> handle =
      x10::lang::Runtime::template evalAt<x10::lang::PlaceLocalHandle<FMGL(T)> >(
        x10::lang::Place_methods::
          FMGL(FIRST_PLACE__get)(),
        x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > > >(x10aux::ref<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > >(x10aux::ref<x10_lang_PlaceLocalHandle__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_0<x10::lang::PlaceLocalHandle<FMGL(T)> > >(sizeof(x10_lang_PlaceLocalHandle__closure__1<FMGL(T)>)))x10_lang_PlaceLocalHandle__closure__1<FMGL(T)>()))));
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Try_c
    try {
    try {
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::startFinish();
        {
            
            //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.For_c
            {
                x10aux::ref<x10::lang::Iterator<x10::lang::Place> > p1790;
                for (
                     //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10LocalDecl_c
                     p1790 =
                       (x10aux::nullCheck(dist)->places())->iterator();
                     (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1790))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1790)->_getITables())->hasNext))();
                     )
                {
                    
                    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10LocalDecl_c
                    x10::lang::Place p =
                      (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1790))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1790)->_getITables())->next))();
                    
                    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::runAsync(
                      p,
                      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_PlaceLocalHandle__closure__2<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_PlaceLocalHandle__closure__2<FMGL(T)>)))x10_lang_PlaceLocalHandle__closure__2<FMGL(T)>(handle, init)))));
                }
            }
            
        }
    }
    catch (x10aux::__ref& __ref__813) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__813 = (x10aux::ref<x10::lang::Throwable>&)__ref__813;
        if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__813)) {
            x10aux::ref<x10::lang::Throwable> __desugarer__var__42__ =
              static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__813);
            {
                
                //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::pushException(
                  __desugarer__var__42__);
            }
        } else
        throw;
    }
    } catch (...) {
        {
            
            //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::stopFinish();
        }
        throw;
    }
    {
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::stopFinish();
    }
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/PlaceLocalHandle.x10": x10.ast.X10Return_c
    return handle;
    
}
#endif // X10_LANG_PLACELOCALHANDLE_H_IMPLEMENTATION
#endif // __X10_LANG_PLACELOCALHANDLE_H_NODEPS
