#ifndef __X10_LANG_VALRAIL__NATIVEREP_H
#define __X10_LANG_VALRAIL__NATIVEREP_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
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
template<class FMGL(T)> class ValRail;
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

class ValRail__NativeRep : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    static x10_boolean isCPP();
    static x10_boolean isJava();
    static x10_boolean useNativeFor(x10::lang::Place x);
    template<class FMGL(T)> static void copyTo(x10aux::ref<x10::lang::ValRail<FMGL(T) > > src,
                                               x10_int src_off,
                                               x10aux::ref<x10::lang::Rail<FMGL(T) > > dst,
                                               x10_int dst_off,
                                               x10_int len);
    template<class FMGL(T)> static void copyTo(x10aux::ref<x10::lang::ValRail<FMGL(T) > > src,
                                               x10_int src_off,
                                               x10::lang::Place dst_place,
                                               x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > dst_finder,
                                               x10_int len);
    void _constructor();
    
    static x10aux::ref<x10::lang::ValRail__NativeRep> _make(
             );
    
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_LANG_VALRAIL__NATIVEREP_H

namespace x10 { namespace lang { 
class ValRail__NativeRep;
} } 

#ifndef X10_LANG_VALRAIL__NATIVEREP_H_NODEPS
#define X10_LANG_VALRAIL__NATIVEREP_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Boolean.h>
#include <x10/compiler/Native.h>
#include <x10/lang/Place.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Int.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/util/Pair.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_0.h>
#include <x10/util/Pair.h>
#include <x10/lang/Rail.h>
#include <x10/util/Pair.h>
#ifndef X10_LANG_VALRAIL__NATIVEREP__CLOSURE__1_CLOSURE
#define X10_LANG_VALRAIL__NATIVEREP__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_ValRail__NativeRep__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_ValRail__NativeRep__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10LocalDecl_c
        x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> pair =
          (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(dst_finder))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > >(((x10aux::ref<x10::lang::Reference>)dst_finder)->_getITables())->apply))();
        
        //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Rail<FMGL(T) > > dst = pair->FMGL(first);
        
        //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10LocalDecl_c
        x10_int dst_off = pair->FMGL(second);
        
        //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (len)); 
                                                  //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
                                                  i = ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
                (dst)->set((src)->apply(((x10_int) ((src_off) + (i)))), ((x10_int) ((dst_off) + (i))));
            }
        }
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > dst_finder;
    x10_int len;
    x10aux::ref<x10::lang::ValRail<FMGL(T) > > src;
    x10_int src_off;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->dst_finder);
        buf.write(this->len);
        buf.write(this->src);
        buf.write(this->src_off);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > that_dst_finder = buf.read<x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > >();
        x10_int that_len = buf.read<x10_int>();
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > that_src = buf.read<x10aux::ref<x10::lang::ValRail<FMGL(T) > > >();
        x10_int that_src_off = buf.read<x10_int>();
        x10aux::ref<x10_lang_ValRail__NativeRep__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_ValRail__NativeRep__closure__1<FMGL(T) > >()) x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >(that_dst_finder, that_len, that_src, that_src_off);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_ValRail__NativeRep__closure__1(x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > dst_finder, x10_int len, x10aux::ref<x10::lang::ValRail<FMGL(T) > > src, x10_int src_off) : dst_finder(dst_finder), len(len), src(src), src_off(src_off) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10:74-82";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_ValRail__NativeRep__closure__1<FMGL(T) > >x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::_itable(&x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_ValRail__NativeRep__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_VALRAIL__NATIVEREP__CLOSURE__1_CLOSURE
#ifndef X10_LANG_VALRAIL__NATIVEREP__CLOSURE__0_CLOSURE
#define X10_LANG_VALRAIL__NATIVEREP__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_lang_ValRail__NativeRep__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_lang_ValRail__NativeRep__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10If_c
        if (x10::lang::ValRail__NativeRep::isJava()) {
            
            //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
            printf("Should never occur, see ValRail.x10");
        } else {
            
            //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.For_c
            {
                x10_int i;
                for (
                     //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10LocalDecl_c
                     i = ((x10_int)0); ((i) < (len)); 
                                                      //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
                                                      i = ((x10_int) ((i) + (((x10_int)1)))))
                {
                    
                    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
                    (dst)->set((src)->apply(((x10_int) ((src_off) + (i)))), ((x10_int) ((dst_off) + (i))));
                }
            }
            
        }
        
    }
    
    // captured environment
    x10_int len;
    x10aux::ref<x10::lang::Rail<FMGL(T) > > dst;
    x10aux::ref<x10::lang::ValRail<FMGL(T) > > src;
    x10_int src_off;
    x10_int dst_off;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->len);
        buf.write(this->dst);
        buf.write(this->src);
        buf.write(this->src_off);
        buf.write(this->dst_off);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_len = buf.read<x10_int>();
        x10aux::ref<x10::lang::Rail<FMGL(T) > > that_dst = buf.read<x10aux::ref<x10::lang::Rail<FMGL(T) > > >();
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > that_src = buf.read<x10aux::ref<x10::lang::ValRail<FMGL(T) > > >();
        x10_int that_src_off = buf.read<x10_int>();
        x10_int that_dst_off = buf.read<x10_int>();
        x10aux::ref<x10_lang_ValRail__NativeRep__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_lang_ValRail__NativeRep__closure__0<FMGL(T) > >()) x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >(that_len, that_dst, that_src, that_src_off, that_dst_off);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_ValRail__NativeRep__closure__0(x10_int len, x10aux::ref<x10::lang::Rail<FMGL(T) > > dst, x10aux::ref<x10::lang::ValRail<FMGL(T) > > src, x10_int src_off, x10_int dst_off) : len(len), dst(dst), src(src), src_off(src_off), dst_off(dst_off) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10:52-58";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_lang_ValRail__NativeRep__closure__0<FMGL(T) > >x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::_itable(&x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_lang_ValRail__NativeRep__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_LANG_VALRAIL__NATIVEREP__CLOSURE__0_CLOSURE
#ifndef X10_LANG_VALRAIL__NATIVEREP_H_GENERICS
#define X10_LANG_VALRAIL__NATIVEREP_H_GENERICS
#ifndef X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1059
#define X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1059
template<class FMGL(T)> void x10::lang::ValRail__NativeRep::copyTo(x10aux::ref<x10::lang::ValRail<FMGL(T) > > src,
                                                                   x10_int src_off,
                                                                   x10aux::ref<x10::lang::Rail<FMGL(T) > > dst,
                                                                   x10_int dst_off,
                                                                   x10_int len) {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(x10::lang::Place_methods::place((dst)->location),
                               x10::lang::Place_methods::_make(x10aux::here))) &&
        x10::lang::ValRail__NativeRep::isJava())
    {
        
        //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
        printf("Should never occur, see ValRail.x10");
        
        //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(dst)),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_ValRail__NativeRep__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_ValRail__NativeRep__closure__0<FMGL(T)>)))x10_lang_ValRail__NativeRep__closure__0<FMGL(T)>(len, dst, src, src_off, dst_off)))));
}
#endif // X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1059
#ifndef X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1060
#define X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1060
template<class FMGL(T)> void x10::lang::ValRail__NativeRep::copyTo(
  x10aux::ref<x10::lang::ValRail<FMGL(T) > > src,
  x10_int src_off,
  x10::lang::Place dst_place,
  x10aux::ref<x10::lang::Fun_0_0<x10::util::Pair<x10aux::ref<x10::lang::Rail<FMGL(T) > >, x10_int> > > dst_finder,
  x10_int len) {
    
    //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/ValRail__NativeRep.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(dst_place, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_ValRail__NativeRep__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_ValRail__NativeRep__closure__1<FMGL(T)>)))x10_lang_ValRail__NativeRep__closure__1<FMGL(T)>(dst_finder, len, src, src_off)))));
}
#endif // X10_LANG_VALRAIL__NATIVEREP_H_copyTo_1060
template<class __T> x10aux::ref<__T> x10::lang::ValRail__NativeRep::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::ValRail__NativeRep> this_ = new (x10aux::alloc_remote<x10::lang::ValRail__NativeRep>()) x10::lang::ValRail__NativeRep();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_VALRAIL__NATIVEREP_H_GENERICS
#endif // __X10_LANG_VALRAIL__NATIVEREP_H_NODEPS
