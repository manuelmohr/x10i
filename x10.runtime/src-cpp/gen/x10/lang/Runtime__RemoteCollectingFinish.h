#ifndef __X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H
#define __X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H

#include <x10rt.h>


#define X10_LANG_RUNTIME__REMOTEFINISH_H_NODEPS
#include <x10/lang/Runtime__RemoteFinish.h>
#undef X10_LANG_RUNTIME__REMOTEFINISH_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(T)> class Runtime__StatefulReducer;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Reducible;
} } 
namespace x10 { namespace lang { 
class Runtime__RootFinish;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(Z3), class FMGL(U)> class Fun_0_3;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Stack;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class MultipleExceptions;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
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
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T), class FMGL(U)> class Pair;
} } 
#include <x10/util/Pair.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Runtime__RemoteCollectingFinish;
template <> class Runtime__RemoteCollectingFinish<void>;
template<class FMGL(T)> class Runtime__RemoteCollectingFinish : public x10::lang::Runtime__RemoteFinish
  {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::lang::Runtime__StatefulReducer<FMGL(T)> > FMGL(sr);
    
    void _constructor(x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    static x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > _make(
             x10aux::ref<x10::lang::Reducible<FMGL(T)> > r);
    
    virtual void notifyActivityTermination(x10aux::ref<x10::lang::Runtime__RootFinish> r);
    virtual void accept(FMGL(T) t);
    virtual void accept(FMGL(T) t, x10_int id);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Runtime__RemoteCollectingFinish<void> : public x10::lang::Runtime__RemoteFinish
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H

namespace x10 { namespace lang { 
template<class FMGL(T)>
class Runtime__RemoteCollectingFinish;
} } 

#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_NODEPS
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_NODEPS
#include <x10/lang/Runtime__RemoteFinish.h>
#include <x10/lang/Runtime__StatefulReducer.h>
#include <x10/lang/Reducible.h>
#include <x10/lang/Runtime__RootFinish.h>
#include <x10/lang/Fun_0_3.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Int.h>
#include <x10/lang/Runtime.h>
#include <x10/util/Stack.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Place.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/MultipleExceptions.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime__RootCollectingFinish.h>
#include <x10/lang/ClassCastException.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Pair.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__4_CLOSURE
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__4_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__RemoteCollectingFinish__closure__4 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__59__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(r);
                               
                               //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1003__;
                               
                               //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1993; __ret1993: 
                               //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__59__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__59__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1003__ =
                                     __desugarer__var__59__;
                                   
                                   //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1993_end_;
                               }
                               goto __ret1993_next_; __ret1993_next_: ;
                               }
                               while (false);
                               goto __ret1993_end_; __ret1993_end_: ;
                               __var1003__;
                           }))
                           ))->notify2(m,
                                       x);
        
        //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m;
    FMGL(T) x;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->x);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > >();
        FMGL(T) that_x = buf.read<FMGL(T)>();
        x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) > >()) x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >(that_r, that_m, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteCollectingFinish__closure__4(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m, FMGL(T) x) : r(r), m(m), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:655";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) > >x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::_itable(&x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__4_CLOSURE
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__3_CLOSURE
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__3_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__RemoteCollectingFinish__closure__3 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__58__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(r);
                               
                               //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1002__;
                               
                               //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1992; __ret1992: 
                               //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__58__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__58__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1002__ =
                                     __desugarer__var__58__;
                                   
                                   //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1992_end_;
                               }
                               goto __ret1992_next_; __ret1992_next_: ;
                               }
                               while (false);
                               goto __ret1992_end_; __ret1992_end_: ;
                               __var1002__;
                           }))
                           ))->notify2(m,
                                       t);
        
        //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m;
    x10aux::ref<x10::lang::Throwable> t;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->t);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > >();
        x10aux::ref<x10::lang::Throwable> that_t = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) > >()) x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >(that_r, that_m, that_t);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteCollectingFinish__closure__3(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m, x10aux::ref<x10::lang::Throwable> t) : r(r), m(m), t(t) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:648";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) > >x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::_itable(&x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__3_CLOSURE
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__2_CLOSURE
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__2_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T)> class x10_lang_Runtime__RemoteCollectingFinish__closure__2 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> >::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::util::Pair<x10_int, x10_int> apply(x10_int i) {
        
        //#line 637 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10::util::Pair_methods<x10_int, x10_int>::_make((saved_this->
                                                                   FMGL(message))->apply(i),
                                                                (saved_this->
                                                                   FMGL(counts))->apply((saved_this->
                                                                                           FMGL(message))->apply(i)));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > >();
        x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) > >()) x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteCollectingFinish__closure__2(x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:637";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> >::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) > >x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::_itable(&x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >, &x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__2_CLOSURE
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__1_CLOSURE
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__RemoteCollectingFinish__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__57__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(r);
                               
                               //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1001__;
                               
                               //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1991; __ret1991: 
                               //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__57__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__57__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1001__ =
                                     __desugarer__var__57__;
                                   
                                   //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1991_end_;
                               }
                               goto __ret1991_next_; __ret1991_next_: ;
                               }
                               while (false);
                               goto __ret1991_end_; __ret1991_end_: ;
                               __var1001__;
                           }))
                           ))->notify(m, x);
        
        //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10_int > > m;
    FMGL(T) x;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->x);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        FMGL(T) that_x = buf.read<FMGL(T)>();
        x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) > >()) x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >(that_r, that_m, that_x);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteCollectingFinish__closure__1(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10_int > > m, FMGL(T) x) : r(r), m(m), x(x) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:631";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) > >x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::_itable(&x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__1_CLOSURE
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__0_CLOSURE
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_Runtime__RemoteCollectingFinish__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __desugarer__var__56__ =
                                 x10aux::class_cast<x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > >(r);
                               
                               //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootCollectingFinish<FMGL(T)> > __var1000__;
                               
                               //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1990; __ret1990: 
                               //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__56__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__56__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}"))));
                                   }
                                   
                                   //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1000__ =
                                     __desugarer__var__56__;
                                   
                                   //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1990_end_;
                               }
                               goto __ret1990_next_; __ret1990_next_: ;
                               }
                               while (false);
                               goto __ret1990_end_; __ret1990_end_: ;
                               __var1000__;
                           }))
                           ))->notify(m, t);
        
        //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10_int > > m;
    x10aux::ref<x10::lang::Throwable> t;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->t);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10::lang::Throwable> that_t = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) > >()) x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >(that_r, that_m, that_t);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteCollectingFinish__closure__0(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10_int > > m, x10aux::ref<x10::lang::Throwable> t) : r(r), m(m), t(t) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:624";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) > >x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::_itable(&x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH__CLOSURE__0_CLOSURE
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_GENERICS
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >()) x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_GENERICS
#ifndef X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_IMPLEMENTATION
#define X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_IMPLEMENTATION
#include <x10/lang/Runtime__RemoteCollectingFinish.h>


#include "x10/lang/Runtime__RemoteCollectingFinish.inc"

template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>");
    
}


//#line 594 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 595 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    this->x10::lang::Runtime__RemoteFinish::_constructor();
    
    //#line 597 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this))->
      FMGL(sr) =
      x10::lang::Runtime__StatefulReducer<FMGL(T)>::_make(r);
    
}
template<class FMGL(T)>
x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Reducible<FMGL(T)> > r)
{
    x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >(), 0, sizeof(x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>))) x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>();
    this_->_constructor(r);
    return this_;
}



//#line 603 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::notifyActivityTermination(
  x10aux::ref<x10::lang::Runtime__RootFinish> r) {
    
    //#line 604 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
      FMGL(lock)->lock();
    
    //#line 605 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x =
          ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
            FMGL(counts);
        x10_int y0 =
          x10::lang::Place_methods::_make(x10aux::here)->
            FMGL(id);
        x10_int z =
          ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) - (z))), y0);
    }))
    ;
    
    //#line 606 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if ((((((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
             FMGL(count))->decrementAndGet()) > (((x10_int)0))))
    {
        
        //#line 607 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
          FMGL(lock)->unlock();
        
        //#line 608 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 610 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > e =
      ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
        FMGL(exceptions);
    
    //#line 611 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
      FMGL(exceptions) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Stack<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 612 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
    if (((((x10_int) ((((x10_int)2)) * (((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                          FMGL(length))))) > (x10aux::num_hosts)))
    {
        
        //#line 613 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > m =
          x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                               FMGL(counts));
        
        //#line 614 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 614 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (x10aux::num_hosts));
                 
                 //#line 614 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 614 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                   FMGL(counts))->set(((x10_int)0), i);
            }
        }
        
        //#line 615 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
          FMGL(length) =
          ((x10_int)1);
        
        //#line 616 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
          FMGL(lock)->unlock();
        
        //#line 617 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(x10aux::null,
                                    e)))
        {
            
            //#line 618 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t;
            
            //#line 619 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->size(),
                                       ((x10_int)1))))
            {
                
                //#line 620 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::nullCheck(e)->peek();
            }
            else
            {
                
                //#line 622 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Throwable> >(x10::lang::MultipleExceptions::_make(e));
            }
            
            //#line 624 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T)>)))x10_lang_Runtime__RemoteCollectingFinish__closure__0<FMGL(T)>(r, m, t))));
            
            //#line 625 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 626 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        else
        {
            
            //#line 628 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                FMGL(sr))->placeMerge();
            
            //#line 629 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x =
              x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                  FMGL(sr))->result();
            
            //#line 630 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                FMGL(sr))->reset();
            
            //#line 631 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T)>)))x10_lang_Runtime__RemoteCollectingFinish__closure__1<FMGL(T)>(r, m, x))));
            
            //#line 632 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 633 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        
        //#line 635 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    else
    {
        
        //#line 637 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m =
          x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> >::make(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                                                         FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(sizeof(x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T)>)))x10_lang_Runtime__RemoteCollectingFinish__closure__2<FMGL(T)>(this)))));
        
        //#line 638 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 638 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (x10aux::num_hosts));
                 
                 //#line 638 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 638 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                   FMGL(counts))->set(((x10_int)0), i);
            }
        }
        
        //#line 639 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
          FMGL(length) =
          ((x10_int)1);
        
        //#line 640 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
          FMGL(lock)->unlock();
        
        //#line 641 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
        if ((!x10aux::struct_equals(x10aux::null,
                                    e)))
        {
            
            //#line 642 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Throwable> t;
            
            //#line 643 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(x10aux::nullCheck(e)->size(),
                                       ((x10_int)1))))
            {
                
                //#line 644 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::nullCheck(e)->peek();
            }
            else
            {
                
                //#line 646 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                t =
                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Throwable> >(x10::lang::MultipleExceptions::_make(e));
            }
            
            //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T)>)))x10_lang_Runtime__RemoteCollectingFinish__closure__3<FMGL(T)>(r, m, t))));
            
            //#line 649 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 650 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        else
        {
            
            //#line 652 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                FMGL(sr))->placeMerge();
            
            //#line 653 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x =
              x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                  FMGL(sr))->result();
            
            //#line 654 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                                FMGL(sr))->reset();
            
            //#line 655 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::VoidFun_0_0> closure =
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T)>)))x10_lang_Runtime__RemoteCollectingFinish__closure__4<FMGL(T)>(r, m, x))));
            
            //#line 656 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::run_at(x10::lang::Place_methods::place((r)->location)->
                             FMGL(id), closure);
            
            //#line 657 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::dealloc(closure.operator->());
        }
        
        //#line 659 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
}

//#line 662 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::accept(
  FMGL(T) t) {
    
    //#line 663 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
      FMGL(lock)->lock();
    
    //#line 664 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      t);
    
    //#line 665 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
      FMGL(lock)->unlock();
}

//#line 667 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::accept(
  FMGL(T) t,
  x10_int id) {
    
    //#line 668 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)> >)this)->
                        FMGL(sr))->accept(
      t,
      id);
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Runtime__RemoteFinish::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Runtime__RemoteFinish::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Runtime__RemoteCollectingFinish<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Runtime__RemoteCollectingFinish<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Runtime__RemoteFinish>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Runtime$RemoteCollectingFinish";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_IMPLEMENTATION
#endif // __X10_LANG_RUNTIME__REMOTECOLLECTINGFINISH_H_NODEPS
