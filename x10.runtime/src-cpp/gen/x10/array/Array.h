#ifndef __X10_ARRAY_ARRAY_H
#define __X10_ARRAY_ARRAY_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_1_H_NODEPS
#include <x10/lang/Fun_0_1.h>
#undef X10_LANG_FUN_0_1_H_NODEPS
namespace x10 { namespace array { 
class Point;
} } 
#define X10_LANG_ITERABLE_H_NODEPS
#include <x10/lang/Iterable.h>
#undef X10_LANG_ITERABLE_H_NODEPS
namespace x10 { namespace array { 
class Point;
} } 
#define X10_UTIL_INDEXEDMEMORYCHUNK_STRUCT_H_NODEPS
#include <x10/util/IndexedMemoryChunk.struct_h>
#undef X10_UTIL_INDEXEDMEMORYCHUNK_STRUCT_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
#define X10_ARRAY_RECTLAYOUT_STRUCT_H_NODEPS
#include <x10/array/RectLayout.struct_h>
#undef X10_ARRAY_RECTLAYOUT_STRUCT_H_NODEPS
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
namespace x10 { namespace array { 
class Region;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace array { 
class RectLayout;
} } 
#include <x10/array/RectLayout.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace compiler { 
class Header;
} } 
namespace x10 { namespace compiler { 
class Inline;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
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
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class UInt;
} } 
#include <x10/lang/UInt.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
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
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class IllegalArgumentException;
} } 
namespace x10 { namespace lang { 
class ArrayIndexOutOfBoundsException;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace compiler { 
class NoInline;
} } 
namespace x10 { namespace compiler { 
class NoReturn;
} } 
namespace x10 { namespace array { 

template<class FMGL(T)> class Array;
template <> class Array<void>;
template<class FMGL(T)> class Array : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10aux::ref<x10::array::Region> FMGL(region);
    
    x10_int FMGL(size);
    
    x10_boolean FMGL(rail);
    
    static x10aux::itable_entry _itables[4];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable<x10::array::Array<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::array::Array<FMGL(T)> > _itable_1;
    
    static typename x10::lang::Iterable<x10aux::ref<x10::array::Point> >::template itable<x10::array::Array<FMGL(T)> > _itable_2;
    
    void _instance_init();
    
    x10_int rank();
    x10_boolean rect();
    x10_boolean zeroBased();
    x10::util::IndexedMemoryChunk<FMGL(T) > FMGL(raw);
    
    x10_int FMGL(rawLength);
    
    x10::array::RectLayout FMGL(layout);
    
    virtual x10::util::IndexedMemoryChunk<FMGL(T) > raw();
    void _constructor(x10aux::ref<x10::array::Region> reg);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(x10aux::ref<x10::array::Region> reg);
    
    void _constructor(x10aux::ref<x10::array::Region> reg, x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(x10aux::ref<x10::array::Region> reg,
                                                          x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init);
    
    void _constructor(x10aux::ref<x10::array::Region> reg, FMGL(T) init);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(x10aux::ref<x10::array::Region> reg,
                                                          FMGL(T) init);
    
    void _constructor(x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(
             x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail);
    
    void _constructor(x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(
             x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail);
    
    void _constructor(x10_int size);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(
             x10_int size);
    
    void _constructor(x10_int size, x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(
             x10_int size,
             x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init);
    
    void _constructor(x10_int size, FMGL(T) init);
    
    static x10aux::ref<x10::array::Array<FMGL(T)> > _make(
             x10_int size,
             FMGL(T) init);
    
    virtual x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
      iterator(
      );
    virtual FMGL(T) apply(x10_int i0);
    virtual FMGL(T) apply(x10_int i0, x10_int i1);
    virtual FMGL(T) apply(x10_int i0, x10_int i1, x10_int i2);
    virtual FMGL(T) apply(x10_int i0, x10_int i1, x10_int i2,
                          x10_int i3);
    virtual FMGL(T) apply(x10aux::ref<x10::array::Point> pt);
    virtual FMGL(T) set(FMGL(T) v, x10_int i0);
    virtual FMGL(T) set(FMGL(T) v, x10_int i0, x10_int i1);
    virtual FMGL(T) set(FMGL(T) v, x10_int i0, x10_int i1,
                        x10_int i2);
    virtual FMGL(T) set(FMGL(T) v, x10_int i0, x10_int i1,
                        x10_int i2,
                        x10_int i3);
    virtual FMGL(T) set(FMGL(T) v, x10aux::ref<x10::array::Point> p);
    virtual void fill(FMGL(T) v);
    template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
      map(
      x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op);
    template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
      map(
      x10aux::ref<x10::array::Array<FMGL(U)> > dst,
      x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op);
    template<class FMGL(S), class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(S)> >
      map(
      x10aux::ref<x10::array::Array<FMGL(U)> > src,
      x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op);
    template<class FMGL(S), class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(S)> >
      map(
      x10aux::ref<x10::array::Array<FMGL(S)> > dst,
      x10aux::ref<x10::array::Array<FMGL(U)> > src,
      x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op);
    template<class FMGL(U)> FMGL(U) reduce(
      x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
      FMGL(U) unit);
    template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
      scan(
      x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
      FMGL(U) unit);
    template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
      scan(
      x10aux::ref<x10::array::Array<FMGL(U)> > dst,
      x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
      FMGL(U) unit);
    virtual void copyTo(x10aux::ref<x10::array::Array<FMGL(T)> > dst);
    virtual void copyTo(x10aux::ref<x10::array::Array<FMGL(T)> > dst,
                        x10_boolean uncounted);
    virtual void copyTo(x10_int srcIndex,
                        x10aux::ref<x10::array::Array<FMGL(T)> > dst,
                        x10_int dstIndex,
                        x10_int numElems);
    virtual void copyTo(x10_int srcIndex,
                        x10aux::ref<x10::array::Array<FMGL(T)> > dst,
                        x10_int dstIndex,
                        x10_int numElems,
                        x10_boolean uncounted);
    virtual void copyFrom(x10aux::ref<x10::array::Array<FMGL(T)> > src);
    virtual void copyFrom(x10aux::ref<x10::array::Array<FMGL(T)> > src,
                          x10_boolean uncounted);
    virtual void copyFrom(x10_int dstIndex,
                          x10aux::ref<x10::array::Array<FMGL(T)> > src,
                          x10_int srcIndex,
                          x10_int numElems);
    virtual void copyFrom(x10_int dstIndex,
                          x10aux::ref<x10::array::Array<FMGL(T)> > src,
                          x10_int srcIndex,
                          x10_int numElems,
                          x10_boolean uncounted);
    x10aux::ref<x10::array::Region> region(
      );
    x10_int size();
    x10_boolean rail();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::Array<FMGL(T)> > this_,
                                   x10aux::serialization_buffer& buf);
    
    public: x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Array<void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    static void
      raiseBoundsError(
      x10_int i0) X10_PRAGMA_NORETURN ;
    
    static void
      raiseBoundsError(
      x10_int i0,
      x10_int i1) X10_PRAGMA_NORETURN ;
    
    static void
      raiseBoundsError(
      x10_int i0,
      x10_int i1,
      x10_int i2) X10_PRAGMA_NORETURN ;
    
    static void
      raiseBoundsError(
      x10_int i0,
      x10_int i1,
      x10_int i2,
      x10_int i3) X10_PRAGMA_NORETURN ;
    
    static void
      raiseBoundsError(
      x10aux::ref<x10::array::Point> pt) X10_PRAGMA_NORETURN ;
    
    
};

} } 
#endif // X10_ARRAY_ARRAY_H

namespace x10 { namespace array { 
template<class FMGL(T)>
class Array;
} } 

#ifndef X10_ARRAY_ARRAY_H_NODEPS
#define X10_ARRAY_ARRAY_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/array/Point.h>
#include <x10/lang/Iterable.h>
#include <x10/array/Point.h>
#include <x10/array/Region.h>
#include <x10/lang/Int.h>
#include <x10/lang/Boolean.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/array/RectLayout.h>
#include <x10/compiler/Native.h>
#include <x10/compiler/Header.h>
#include <x10/compiler/Inline.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/UInt.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/IllegalArgumentException.h>
#include <x10/lang/ArrayIndexOutOfBoundsException.h>
#include <x10/lang/String.h>
#include <x10/compiler/NoInline.h>
#include <x10/compiler/NoReturn.h>
#ifndef X10_ARRAY_ARRAY__CLOSURE__3_CLOSURE
#define X10_ARRAY_ARRAY__CLOSURE__3_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T), class FMGL(S), class FMGL(U)> class x10_array_Array__closure__3 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)>::template itable <x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(S) apply(x10aux::ref<x10::array::Point> p) {
        
        //#line 549 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
          saved_this->x10::array::Array<FMGL(T)>::apply(
            p),
          x10aux::nullCheck(src)->x10::array::Array<FMGL(U)>::apply(
            p));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op;
    x10aux::ref<x10::array::Array<FMGL(T)> > saved_this;
    x10aux::ref<x10::array::Array<FMGL(U)> > src;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->op);
        buf.write(this->saved_this);
        buf.write(this->src);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > that_op = buf.read<x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > >();
        x10aux::ref<x10::array::Array<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::array::Array<FMGL(T)> > >();
        x10aux::ref<x10::array::Array<FMGL(U)> > that_src = buf.read<x10aux::ref<x10::array::Array<FMGL(U)> > >();
        x10aux::ref<x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) > > this_ = new (x10aux::alloc<x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) > >()) x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >(that_op, that_saved_this, that_src);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Array__closure__3(x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op, x10aux::ref<x10::array::Array<FMGL(T)> > saved_this, x10aux::ref<x10::array::Array<FMGL(U)> > src) : op(op), saved_this(saved_this), src(src) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10:549";
    }

};

template<class FMGL(T), class FMGL(S), class FMGL(U)> typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)>::template itable <x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) > >x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::_itable(&x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T), class FMGL(S), class FMGL(U)>
x10aux::itable_entry x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> >, &x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T), class FMGL(S), class FMGL(U)>
const x10aux::serialization_id_t x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) >::template _deserialize<x10::lang::Object>);

#endif // X10_ARRAY_ARRAY__CLOSURE__3_CLOSURE
#ifndef X10_ARRAY_ARRAY__CLOSURE__2_CLOSURE
#define X10_ARRAY_ARRAY__CLOSURE__2_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T), class FMGL(U)> class x10_array_Array__closure__2 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)>::template itable <x10_array_Array__closure__2<FMGL(T),FMGL(U) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(U) apply(x10aux::ref<x10::array::Point> p) {
        
        //#line 501 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
          saved_this->x10::array::Array<FMGL(T)>::apply(
            p));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op;
    x10aux::ref<x10::array::Array<FMGL(T)> > saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->op);
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > that_op = buf.read<x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > >();
        x10aux::ref<x10::array::Array<FMGL(T)> > that_saved_this = buf.read<x10aux::ref<x10::array::Array<FMGL(T)> > >();
        x10aux::ref<x10_array_Array__closure__2<FMGL(T),FMGL(U) > > this_ = new (x10aux::alloc<x10_array_Array__closure__2<FMGL(T),FMGL(U) > >()) x10_array_Array__closure__2<FMGL(T),FMGL(U) >(that_op, that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Array__closure__2(x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op, x10aux::ref<x10::array::Array<FMGL(T)> > saved_this) : op(op), saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10:501";
    }

};

template<class FMGL(T), class FMGL(U)> typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)>::template itable <x10_array_Array__closure__2<FMGL(T),FMGL(U) > >x10_array_Array__closure__2<FMGL(T),FMGL(U) >::_itable(&x10_array_Array__closure__2<FMGL(T),FMGL(U) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Array__closure__2<FMGL(T),FMGL(U) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T), class FMGL(U)>
x10aux::itable_entry x10_array_Array__closure__2<FMGL(T),FMGL(U) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> >, &x10_array_Array__closure__2<FMGL(T),FMGL(U) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T), class FMGL(U)>
const x10aux::serialization_id_t x10_array_Array__closure__2<FMGL(T),FMGL(U) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Array__closure__2<FMGL(T),FMGL(U) >::template _deserialize<x10::lang::Object>);

#endif // X10_ARRAY_ARRAY__CLOSURE__2_CLOSURE
#ifndef X10_ARRAY_ARRAY__CLOSURE__1_CLOSURE
#define X10_ARRAY_ARRAY__CLOSURE__1_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T)> class x10_array_Array__closure__1 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable <x10_array_Array__closure__1<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply(x10aux::ref<x10::array::Point> id3) {
        
        //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
        x10_int i = x10aux::nullCheck(id3)->x10::array::Point::apply(((x10_int)0));
        
        //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (aRail)->apply(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->aRail);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::ValRail<FMGL(T) > > that_aRail = buf.read<x10aux::ref<x10::lang::ValRail<FMGL(T) > > >();
        x10aux::ref<x10_array_Array__closure__1<FMGL(T) > > this_ = new (x10aux::alloc<x10_array_Array__closure__1<FMGL(T) > >()) x10_array_Array__closure__1<FMGL(T) >(that_aRail);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Array__closure__1(x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail) : aRail(aRail) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10:209";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable <x10_array_Array__closure__1<FMGL(T) > >x10_array_Array__closure__1<FMGL(T) >::_itable(&x10_array_Array__closure__1<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Array__closure__1<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_array_Array__closure__1<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >, &x10_array_Array__closure__1<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_array_Array__closure__1<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Array__closure__1<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_ARRAY_ARRAY__CLOSURE__1_CLOSURE
#ifndef X10_ARRAY_ARRAY__CLOSURE__0_CLOSURE
#define X10_ARRAY_ARRAY__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
template<class FMGL(T)> class x10_array_Array__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable <x10_array_Array__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    FMGL(T) apply(x10aux::ref<x10::array::Point> id2) {
        
        //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
        x10_int i = x10aux::nullCheck(id2)->x10::array::Point::apply(((x10_int)0));
        
        //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (aRail)->apply(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->aRail);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<FMGL(T) > > that_aRail = buf.read<x10aux::ref<x10::lang::Rail<FMGL(T) > > >();
        x10aux::ref<x10_array_Array__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_array_Array__closure__0<FMGL(T) > >()) x10_array_Array__closure__0<FMGL(T) >(that_aRail);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_Array__closure__0(x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail) : aRail(aRail) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10:194";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable <x10_array_Array__closure__0<FMGL(T) > >x10_array_Array__closure__0<FMGL(T) >::_itable(&x10_array_Array__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Array__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_array_Array__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >, &x10_array_Array__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_array_Array__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Array__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_ARRAY_ARRAY__CLOSURE__0_CLOSURE
#ifndef X10_ARRAY_ARRAY_H_GENERICS
#define X10_ARRAY_ARRAY_H_GENERICS
#ifndef X10_ARRAY_ARRAY_H_map_16
#define X10_ARRAY_ARRAY_H_map_16
template<class FMGL(T)> template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
  x10::array::Array<FMGL(T)>::map(
  x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op) {
    
    //#line 501 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return x10::array::Array<FMGL(U)>::_make(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                               FMGL(region),
                                             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> > >(x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> >(x10aux::ref<x10_array_Array__closure__2<FMGL(T),FMGL(U) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(U)> >(sizeof(x10_array_Array__closure__2<FMGL(T),FMGL(U)>)))x10_array_Array__closure__2<FMGL(T),FMGL(U)>(op, this)))));
    
}
#endif // X10_ARRAY_ARRAY_H_map_16
#ifndef X10_ARRAY_ARRAY_H_map_17
#define X10_ARRAY_ARRAY_H_map_17
template<class FMGL(T)> template<class FMGL(U)> x10aux::ref<x10::array::Array<FMGL(U)> >
  x10::array::Array<FMGL(T)>::map(
  x10aux::ref<x10::array::Array<FMGL(U)> > dst,
  x10aux::ref<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> > op) {
    
    //#line 520 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(region)->FMGL(rect)) {
        
        //#line 524 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 524 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                             FMGL(rawLength)));
                 
                 //#line 524 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 525 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (x10aux::nullCheck(dst)->
                   FMGL(raw))->set((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                  (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                     FMGL(raw))->apply(i)), i);
            }
        }
        
    } else {
        
        //#line 528 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1280;
            for (
                 //#line 528 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 p1280 = ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                           FMGL(region)->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1280))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1280)->_getITables())->hasNext))();
                 ) {
                
                //#line 528 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::Point> p =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1280))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1280)->_getITables())->next))();
                
                //#line 529 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(dst)->x10::array::Array<FMGL(U)>::set(
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::apply(
                      p)),
                  p);
            }
        }
        
    }
    
    //#line 532 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return dst;
    
}
#endif // X10_ARRAY_ARRAY_H_map_17
#ifndef X10_ARRAY_ARRAY_H_map_18
#define X10_ARRAY_ARRAY_H_map_18
template<class FMGL(T)> template<class FMGL(S), class FMGL(U)>
x10aux::ref<x10::array::Array<FMGL(S)> >
  x10::array::Array<FMGL(T)>::map(
  x10aux::ref<x10::array::Array<FMGL(U)> > src,
  x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op) {
    
    //#line 549 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return x10::array::Array<FMGL(S)>::_make(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                               FMGL(region),
                                             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> > >(x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> >(x10aux::ref<x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(S)> >(sizeof(x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U)>)))x10_array_Array__closure__3<FMGL(T),FMGL(S),FMGL(U)>(op, this, src)))));
    
}
#endif // X10_ARRAY_ARRAY_H_map_18
#ifndef X10_ARRAY_ARRAY_H_map_19
#define X10_ARRAY_ARRAY_H_map_19
template<class FMGL(T)> template<class FMGL(S), class FMGL(U)>
x10aux::ref<x10::array::Array<FMGL(S)> >
  x10::array::Array<FMGL(T)>::map(
  x10aux::ref<x10::array::Array<FMGL(S)> > dst,
  x10aux::ref<x10::array::Array<FMGL(U)> > src,
  x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> > op) {
    
    //#line 568 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(region)->FMGL(rect)) {
        
        //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                             FMGL(rawLength)));
                 
                 //#line 572 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 573 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (x10aux::nullCheck(dst)->
                   FMGL(raw))->set((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                  (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                     FMGL(raw))->apply(i),
                  (x10aux::nullCheck(src)->
                     FMGL(raw))->apply(i)), i);
            }
        }
        
    } else {
        
        //#line 576 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1281;
            for (
                 //#line 576 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 p1281 = ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                           FMGL(region)->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1281))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1281)->_getITables())->hasNext))();
                 ) {
                
                //#line 576 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::Point> p =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1281))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1281)->_getITables())->next))();
                
                //#line 577 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(dst)->x10::array::Array<FMGL(S)>::set(
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(T), FMGL(U), FMGL(S)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::apply(
                      p),
                    x10aux::nullCheck(src)->x10::array::Array<FMGL(U)>::apply(
                      p)),
                  p);
            }
        }
        
    }
    
    //#line 580 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return dst;
    
}
#endif // X10_ARRAY_ARRAY_H_map_19
#ifndef X10_ARRAY_ARRAY_H_reduce_20
#define X10_ARRAY_ARRAY_H_reduce_20
template<class FMGL(T)> template<class FMGL(U)>
FMGL(U)
  x10::array::Array<FMGL(T)>::reduce(
  x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
  FMGL(U) unit) {
    
    //#line 599 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    FMGL(U) accum = unit;
    
    //#line 600 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(region)->FMGL(rect)) {
        
        //#line 604 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 604 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                             FMGL(rawLength)));
                 
                 //#line 604 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 605 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                accum =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                  accum,
                  (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                     FMGL(raw))->apply(i));
            }
        }
        
    } else {
        
        //#line 608 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1282;
            for (
                 //#line 608 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 p1282 = ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                           FMGL(region)->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1282))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1282)->_getITables())->hasNext))();
                 ) {
                
                //#line 608 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::Point> p =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1282))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1282)->_getITables())->next))();
                
                //#line 609 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                accum = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
                  accum,
                  ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::apply(
                    p));
            }
        }
        
    }
    
    //#line 612 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return accum;
    
}
#endif // X10_ARRAY_ARRAY_H_reduce_20
#ifndef X10_ARRAY_ARRAY_H_scan_21
#define X10_ARRAY_ARRAY_H_scan_21
template<class FMGL(T)> template<class FMGL(U)>
x10aux::ref<x10::array::Array<FMGL(U)> >
  x10::array::Array<FMGL(T)>::scan(
  x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
  FMGL(U) unit) {
    
    //#line 629 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::template scan<FMGL(U) >(
             x10::array::Array<FMGL(U)>::_make(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                 FMGL(region)),
             op,
             unit);
    
}
#endif // X10_ARRAY_ARRAY_H_scan_21
#ifndef X10_ARRAY_ARRAY_H_scan_22
#define X10_ARRAY_ARRAY_H_scan_22
template<class FMGL(T)> template<class FMGL(U)>
x10aux::ref<x10::array::Array<FMGL(U)> >
  x10::array::Array<FMGL(T)>::scan(
  x10aux::ref<x10::array::Array<FMGL(U)> > dst,
  x10aux::ref<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> > op,
  FMGL(U) unit) {
    
    //#line 647 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    FMGL(U) accum = unit;
    
    //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1283;
        for (
             //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
             p1283 = ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                       FMGL(region)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1283))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1283)->_getITables())->hasNext))();
             ) {
            
            //#line 648 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::Point> p =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1283))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1283)->_getITables())->next))();
            
            //#line 649 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            accum = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(op))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(U), FMGL(T), FMGL(U)> >(((x10aux::ref<x10::lang::Reference>)op)->_getITables())->apply))(
              accum,
              ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::apply(
                p));
            
            //#line 650 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(dst)->x10::array::Array<FMGL(U)>::set(
              accum,
              p);
        }
    }
    
    //#line 652 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return dst;
    
}
#endif // X10_ARRAY_ARRAY_H_scan_22
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::array::Array<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::array::Array<FMGL(T)> >()) x10::array::Array<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::array::Array<FMGL(T)>::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::Array<FMGL(T)> > this_;
    if (rr.ref != 0) {
        this_ = x10::array::Array<FMGL(T)>::template _deserializer<x10::array::Array<FMGL(T)> >(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_ARRAY_H_GENERICS
#ifndef X10_ARRAY_ARRAY_H_IMPLEMENTATION
#define X10_ARRAY_ARRAY_H_IMPLEMENTATION
#include <x10/array/Array.h>


#include "x10/array/Array.inc"


//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.PropertyDecl_c

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.PropertyDecl_c

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.PropertyDecl_c
template<class FMGL(T)> typename x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)>::template itable<x10::array::Array<FMGL(T)> >  x10::array::Array<FMGL(T)>::_itable_0(&x10::array::Array<FMGL(T)>::apply, &x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::equals, &x10::array::Array<FMGL(T)>::hashCode, &x10::array::Array<FMGL(T)>::home, &x10::array::Array<FMGL(T)>::toString, &x10::array::Array<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::array::Array<FMGL(T)> >  x10::array::Array<FMGL(T)>::_itable_1(&x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::equals, &x10::array::Array<FMGL(T)>::hashCode, &x10::array::Array<FMGL(T)>::home, &x10::array::Array<FMGL(T)>::toString, &x10::array::Array<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::lang::Iterable<x10aux::ref<x10::array::Point> >::template itable<x10::array::Array<FMGL(T)> >  x10::array::Array<FMGL(T)>::_itable_2(&x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::at, &x10::array::Array<FMGL(T)>::equals, &x10::array::Array<FMGL(T)>::hashCode, &x10::array::Array<FMGL(T)>::home, &x10::array::Array<FMGL(T)>::iterator, &x10::array::Array<FMGL(T)>::toString, &x10::array::Array<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::array::Array<FMGL(T)>::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::Array<FMGL(T)> >())};
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Array<FMGL(T)>");
    
}


//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::array::Array<FMGL(T)>::rank() {
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(region)->
             FMGL(rank);
    
}

//#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::array::Array<FMGL(T)>::rect() {
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(region)->
             FMGL(rect);
    
}

//#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::array::Array<FMGL(T)>::zeroBased(
  ) {
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(region)->
             FMGL(zeroBased);
    
}

//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10FieldDecl_c

//#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10FieldDecl_c

//#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10FieldDecl_c

//#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline x10::util::IndexedMemoryChunk<FMGL(T) > x10::array::Array<FMGL(T)>::raw(
  ) {
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(raw);
    
}

//#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10aux::ref<x10::array::Region> reg) {
    this->x10::lang::Object::_constructor();
    
    //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(region) =
      reg;
    
    //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(size) =
      x10aux::nullCheck(reg)->size();
    
    //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->FMGL(rail) =
      x10aux::nullCheck(reg)->x10::array::Region::rail();
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
      FMGL(layout) = x10::array::RectLayout_methods::_make(x10aux::nullCheck(reg)->min(),
                                                           x10aux::nullCheck(reg)->max());
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    x10_int n = x10::array::RectLayout_methods::size(x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
                                                       FMGL(layout));
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(raw) = x10::util::IndexedMemoryChunk<void>::allocate<FMGL(T) >(n, 8, false, true);
    
    //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(rawLength) = n;
    
}
template<class FMGL(T)> x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
                          x10aux::ref<x10::array::Region> reg)
{
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(reg);
    return this_;
}



//#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10aux::ref<x10::array::Region> reg,
                          x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init)
{
    this->x10::lang::Object::_constructor();
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(region) =
      reg;
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(size) =
      x10aux::nullCheck(reg)->size();
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(rail) =
      x10aux::nullCheck(reg)->x10::array::Region::rail();
    
    //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
      FMGL(layout) =
      x10::array::RectLayout_methods::_make(x10aux::nullCheck(reg)->min(),
                                            x10aux::nullCheck(reg)->max());
    
    //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    x10_int n =
      x10::array::RectLayout_methods::size(x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
                                             FMGL(layout));
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    x10::util::IndexedMemoryChunk<FMGL(T) > r =
      x10::util::IndexedMemoryChunk<void>::allocate<FMGL(T) >(n, 8, false, false);
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1277;
        for (
             //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
             p1277 =
               x10aux::nullCheck(reg)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1277))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1277)->_getITables())->hasNext))();
             )
        {
            
            //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::Point> p =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1277))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1277)->_getITables())->next))();
            
            //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            (r)->set((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(init))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)init)->_getITables())->apply))(
              p), x10::array::RectLayout_methods::offset(x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
                                                           FMGL(layout), 
                    p));
        }
    }
    
    //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(raw) =
      r;
    
    //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(rawLength) =
      n;
    
}
template<class FMGL(T)>
x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
  x10aux::ref<x10::array::Region> reg,
  x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init)
{
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(reg,
    init);
    return this_;
}



//#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10aux::ref<x10::array::Region> reg,
                          FMGL(T) init) {
    this->x10::lang::Object::_constructor();
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(region) = reg;
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(size) = x10aux::nullCheck(reg)->size();
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(rail) = x10aux::nullCheck(reg)->x10::array::Region::rail();
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
      FMGL(layout) = x10::array::RectLayout_methods::_make(x10aux::nullCheck(reg)->min(),
                                                           x10aux::nullCheck(reg)->max());
    
    //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    x10_int n = x10::array::RectLayout_methods::size(x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
                                                       FMGL(layout));
    
    //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
    x10::util::IndexedMemoryChunk<FMGL(T) > r =
      x10::util::IndexedMemoryChunk<void>::allocate<FMGL(T) >(n, 8, false, false);
    
    //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(reg)->FMGL(rect))
    {
        
        //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (n));
                 
                 //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (r)->set(init, i);
            }
        }
        
    }
    else
    {
        
        //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1278;
            for (
                 //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 p1278 =
                   x10aux::nullCheck(reg)->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1278))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1278)->_getITables())->hasNext))();
                 )
            {
                
                //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::Point> p =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1278))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1278)->_getITables())->next))();
                
                //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (r)->set(init, x10::array::RectLayout_methods::offset(x10aux::placeCheck(((x10aux::ref<x10::array::Array<FMGL(T)> >)this))->
                                                                        FMGL(layout), 
                                 p));
            }
        }
        
    }
    
    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(raw) = r;
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
      FMGL(rawLength) = n;
    
}
template<class FMGL(T)> x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
                          x10aux::ref<x10::array::Region> reg,
                          FMGL(T) init) {
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(reg, init);
    return this_;
}



//#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail)
{
    this->_constructor(
      x10::array::Region::makeRectangular(
        ((x10_int)0),
        ((x10_int) ((x10aux::nullCheck(aRail)->
                       FMGL(length)) - (((x10_int)1))))),
      x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(x10aux::ref<x10_array_Array__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(sizeof(x10_array_Array__closure__0<FMGL(T)>)))x10_array_Array__closure__0<FMGL(T)>(aRail))));
    
}
template<class FMGL(T)>
x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
  x10aux::ref<x10::lang::Rail<FMGL(T) > > aRail)
{
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(aRail);
    return this_;
}



//#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail)
{
    this->_constructor(
      x10::array::Region::makeRectangular(
        ((x10_int)0),
        ((x10_int) ((x10aux::nullCheck(aRail)->
                       FMGL(length)) - (((x10_int)1))))),
      x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(x10aux::ref<x10_array_Array__closure__1<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(sizeof(x10_array_Array__closure__1<FMGL(T)>)))x10_array_Array__closure__1<FMGL(T)>(aRail))));
    
}
template<class FMGL(T)>
x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
  x10aux::ref<x10::lang::ValRail<FMGL(T) > > aRail)
{
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(aRail);
    return this_;
}



//#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10_int size) {
    this->_constructor(x10::array::Region::makeRectangular(
                         ((x10_int)0),
                         ((x10_int) ((size) - (((x10_int)1))))));
    
}
template<class FMGL(T)> x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
                          x10_int size) {
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(size);
    return this_;
}



//#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10_int size,
                          x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init)
{
    this->_constructor(
      x10::array::Region::makeRectangular(
        ((x10_int)0),
        ((x10_int) ((size) - (((x10_int)1))))),
      init);
    
}
template<class FMGL(T)>
x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
  x10_int size,
  x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> > init)
{
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(size,
    init);
    return this_;
}



//#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_constructor(
                          x10_int size,
                          FMGL(T) init) {
    this->_constructor(x10::array::Region::makeRectangular(
                         ((x10_int)0),
                         ((x10_int) ((size) - (((x10_int)1))))),
                       init);
    
}
template<class FMGL(T)> x10aux::ref<x10::array::Array<FMGL(T)> > x10::array::Array<FMGL(T)>::_make(
                          x10_int size,
                          FMGL(T) init) {
    x10aux::ref<x10::array::Array<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::array::Array<FMGL(T)> >(), 0, sizeof(x10::array::Array<FMGL(T)>))) x10::array::Array<FMGL(T)>();
    this_->_constructor(size, init);
    return this_;
}



//#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::Array<FMGL(T)>::iterator(
  ) {
    
    //#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
             FMGL(region)->iterator();
    
}

//#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::apply(
  x10_int i0) {
    
    //#line 267 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(rail)) {
        
        //#line 268 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if (BOUNDS_CHECK_BOOL && (!(((((x10_uint) (i0))) < (((x10_uint) (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                           FMGL(size))))))))
        {
            
            //#line 269 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              i0);
        }
        
        //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                  FMGL(raw))->apply(i0);
        
    } else {
        
        //#line 273 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                      FMGL(region)->contains(
                                      i0))))
        {
            
            //#line 274 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              i0);
        }
        
        //#line 276 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
        return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                  FMGL(raw))->apply(x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                             FMGL(layout), 
                                      i0));
        
    }
    
}

//#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::apply(
  x10_int i0,
  x10_int i1) {
    
    //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1)))) {
        
        //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1);
    }
    
    //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
              FMGL(raw))->apply(x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                         FMGL(layout), 
                                  i0,
                                  i1));
    
}

//#line 310 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::apply(
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1,
                                  i2)))) {
        
        //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1,
          i2);
    }
    
    //#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
              FMGL(raw))->apply(x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                         FMGL(layout), 
                                  i0,
                                  i1,
                                  i2));
    
}

//#line 330 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::apply(
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 331 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1,
                                  i2,
                                  i3)))) {
        
        //#line 332 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1,
          i2,
          i3);
    }
    
    //#line 334 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
              FMGL(raw))->apply(x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                         FMGL(layout), 
                                  i0,
                                  i1,
                                  i2,
                                  i3));
    
}

//#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::apply(
  x10aux::ref<x10::array::Point> pt) {
    
    //#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  pt)))) {
        
        //#line 348 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          pt);
    }
    
    //#line 350 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
              FMGL(raw))->apply(x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                         FMGL(layout), 
                                  pt));
    
}

//#line 366 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::set(
  FMGL(T) v,
  x10_int i0) {
    
    //#line 367 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(rail)) {
        
        //#line 368 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if (BOUNDS_CHECK_BOOL && (!(((((x10_uint) (i0))) < (((x10_uint) (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                           FMGL(size))))))))
        {
            
            //#line 369 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              i0);
        }
        
        //#line 371 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
           FMGL(raw))->set(v, i0);
    } else {
        
        //#line 373 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                      FMGL(region)->contains(
                                      i0))))
        {
            
            //#line 374 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              i0);
        }
        
        //#line 376 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
           FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                       FMGL(layout), 
                                i0));
    }
    
    //#line 378 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 394 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::set(
  FMGL(T) v,
  x10_int i0,
  x10_int i1) {
    
    //#line 395 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1)))) {
        
        //#line 396 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1);
    }
    
    //#line 398 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                   FMGL(layout), 
                            i0,
                            i1));
    
    //#line 399 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 416 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::set(
  FMGL(T) v,
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 417 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1,
                                  i2)))) {
        
        //#line 418 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1,
          i2);
    }
    
    //#line 420 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                   FMGL(layout), 
                            i0,
                            i1,
                            i2));
    
    //#line 421 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 439 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::set(
  FMGL(T) v,
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 440 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  i0,
                                  i1,
                                  i2,
                                  i3)))) {
        
        //#line 441 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          i0,
          i1,
          i2,
          i3);
    }
    
    //#line 443 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                   FMGL(layout), 
                            i0,
                            i1,
                            i2,
                            i3));
    
    //#line 444 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 458 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> inline FMGL(T) x10::array::Array<FMGL(T)>::set(
  FMGL(T) v,
  x10aux::ref<x10::array::Point> p) {
    
    //#line 459 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->contains(
                                  p)))) {
        
        //#line 460 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
        x10::array::Array<void>::raiseBoundsError(
          p);
    }
    
    //#line 462 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                   FMGL(layout), 
                            p));
    
    //#line 463 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 472 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::fill(
  FMGL(T) v) {
    
    //#line 473 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
          FMGL(region)->FMGL(rect)) {
        
        //#line 477 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 477 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                             FMGL(rawLength)));
                 
                 //#line 477 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 478 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                   FMGL(raw))->set(v, i);
            }
        }
        
    } else {
        
        //#line 481 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > p1279;
            for (
                 //#line 481 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                 p1279 = ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                           FMGL(region)->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1279))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1279)->_getITables())->hasNext))();
                 ) {
                
                //#line 481 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::Point> p =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1279))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >(((x10aux::ref<x10::lang::Reference>)p1279)->_getITables())->next))();
                
                //#line 482 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
                (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                   FMGL(raw))->set(v, x10::array::RectLayout_methods::offset(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                               FMGL(layout), 
                                        p));
            }
        }
        
    }
    
}

//#line 500 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 518 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 548 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 566 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 596 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 629 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 646 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 673 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyTo(
  x10aux::ref<x10::array::Array<FMGL(T)> > dst) {
    
    //#line 674 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::copyTo(
      dst,
      false);
}

//#line 697 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyTo(
  x10aux::ref<x10::array::Array<FMGL(T)> > dst,
  x10_boolean uncounted) {
    
    //#line 698 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->equals(
                                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(dst)->
                                                                                               FMGL(region))))))
    {
        
        //#line 698 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalArgumentException::_make(x10::lang::String::Lit("source and destination Regions are not equal"))));
    }
    
    //#line 699 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->copyTo(((x10_int)0),x10::lang::Place_methods::place((dst)->location),x10aux::nullCheck(dst)->
                                                                                          FMGL(raw),((x10_int)0),((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                                                                   FMGL(rawLength),uncounted);
}

//#line 721 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyTo(
  x10_int srcIndex,
  x10aux::ref<x10::array::Array<FMGL(T)> > dst,
  x10_int dstIndex,
  x10_int numElems) {
    
    //#line 722 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::copyTo(
      srcIndex,
      dst,
      dstIndex,
      numElems,
      false);
}

//#line 746 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyTo(
  x10_int srcIndex,
  x10aux::ref<x10::array::Array<FMGL(T)> > dst,
  x10_int dstIndex,
  x10_int numElems,
  x10_boolean uncounted) {
    
    //#line 747 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL) {
        
        //#line 748 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                 FMGL(region)->contains(srcIndex))))
        {
            
            //#line 748 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              srcIndex);
        }
        
        //#line 749 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                 FMGL(region)->contains(((x10_int) ((((x10_int) ((srcIndex) + (numElems)))) - (((x10_int)1))))))))
        {
            
            //#line 749 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              ((x10_int) ((((x10_int) ((srcIndex) + (numElems)))) - (((x10_int)1)))));
        }
        
        //#line 750 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(x10aux::nullCheck(dst)->FMGL(region)->contains(
                 dstIndex)))) {
            
            //#line 750 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              dstIndex);
        }
        
        //#line 751 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(x10aux::nullCheck(dst)->FMGL(region)->contains(
                 ((x10_int) ((((x10_int) ((dstIndex) + (numElems)))) - (((x10_int)1))))))))
        {
            
            //#line 751 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              ((x10_int) ((((x10_int) ((dstIndex) + (numElems)))) - (((x10_int)1)))));
        }
        
    }
    
    //#line 754 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->copyTo(((x10_int) ((srcIndex) - ((((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                       FMGL(region)->min())->apply(((x10_int)0))))),x10::lang::Place_methods::place((dst)->location),x10aux::nullCheck(dst)->
                                                                                                                                                       FMGL(raw),((x10_int) ((dstIndex) - ((x10aux::nullCheck(dst)->
                                                                                                                                                                                              FMGL(region)->min())->apply(((x10_int)0))))),numElems,uncounted);
}

//#line 775 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyFrom(
  x10aux::ref<x10::array::Array<FMGL(T)> > src) {
    
    //#line 776 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::copyFrom(
      src,
      false);
}

//#line 798 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyFrom(
  x10aux::ref<x10::array::Array<FMGL(T)> > src,
  x10_boolean uncounted) {
    
    //#line 799 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL && (!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                  FMGL(region)->equals(
                                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(src)->
                                                                                               FMGL(region))))))
    {
        
        //#line 799 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalArgumentException::_make(x10::lang::String::Lit("source and destination Regions are not equal"))));
    }
    
    //#line 800 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->copyFrom(((x10_int)0),x10::lang::Place_methods::place((src)->location),x10aux::nullCheck(src)->
                                                                                            FMGL(raw),((x10_int)0),((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                                                                                     FMGL(rawLength),uncounted);
}

//#line 822 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyFrom(
  x10_int dstIndex,
  x10aux::ref<x10::array::Array<FMGL(T)> > src,
  x10_int srcIndex,
  x10_int numElems) {
    
    //#line 823 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->x10::array::Array<FMGL(T)>::copyFrom(
      dstIndex,
      src,
      srcIndex,
      numElems,
      false);
}

//#line 846 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::copyFrom(
  x10_int dstIndex,
  x10aux::ref<x10::array::Array<FMGL(T)> > src,
  x10_int srcIndex,
  x10_int numElems,
  x10_boolean uncounted) {
    
    //#line 847 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
    if (BOUNDS_CHECK_BOOL) {
        
        //#line 848 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(x10aux::nullCheck(src)->FMGL(region)->contains(
                 srcIndex)))) {
            
            //#line 848 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              srcIndex);
        }
        
        //#line 849 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(x10aux::nullCheck(src)->FMGL(region)->contains(
                 ((x10_int) ((((x10_int) ((srcIndex) + (numElems)))) - (((x10_int)1))))))))
        {
            
            //#line 849 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              ((x10_int) ((((x10_int) ((srcIndex) + (numElems)))) - (((x10_int)1)))));
        }
        
        //#line 850 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                 FMGL(region)->contains(dstIndex))))
        {
            
            //#line 850 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              dstIndex);
        }
        
        //#line 851 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10If_c
        if ((!(((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                 FMGL(region)->contains(((x10_int) ((((x10_int) ((dstIndex) + (numElems)))) - (((x10_int)1))))))))
        {
            
            //#line 851 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
            x10::array::Array<void>::raiseBoundsError(
              ((x10_int) ((((x10_int) ((dstIndex) + (numElems)))) - (((x10_int)1)))));
        }
        
    }
    
    //#line 854 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
       FMGL(raw))->copyFrom(((x10_int) ((dstIndex) - ((((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
                                                         FMGL(region)->min())->apply(((x10_int)0))))),x10::lang::Place_methods::place((src)->location),x10aux::nullCheck(src)->
                                                                                                                                                         FMGL(raw),((x10_int) ((srcIndex) - ((x10aux::nullCheck(src)->
                                                                                                                                                                                                FMGL(region)->min())->apply(((x10_int)0))))),numElems,uncounted);
}

//#line 857 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 860 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 863 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 866 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 869 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::array::Region>
  x10::array::Array<FMGL(T)>::region(
  ) {
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
             FMGL(region);
    
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::array::Array<FMGL(T)>::size(
  ) {
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
             FMGL(size);
    
}

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::array::Array<FMGL(T)>::rail(
  ) {
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Array<FMGL(T)> >)this)->
             FMGL(rail);
    
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::array::Array<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::Array<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_serialize(x10aux::ref<x10::array::Array<FMGL(T)> > this_,
                                                                    x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(raw));
    buf.write(this->FMGL(rawLength));
    buf.write(this->FMGL(region));
    buf.write(this->FMGL(size));
    buf.write(this->FMGL(rail));
    
}

template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(raw) = buf.read<x10::util::IndexedMemoryChunk<FMGL(T) > >();
    FMGL(rawLength) = buf.read<x10_int>();
    FMGL(region) = buf.read<x10aux::ref<x10::array::Region> >();
    FMGL(size) = buf.read<x10_int>();
    FMGL(rail) = buf.read<x10_boolean>();
}

template<class FMGL(T)> x10aux::RuntimeType x10::array::Array<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::array::Array<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::array::Array<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, FMGL(T)> >(), x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.array.Array";
    rtt.initStageTwo(baseName, 3, parents, 1, params, variances);
}
#endif // X10_ARRAY_ARRAY_H_IMPLEMENTATION
#endif // __X10_ARRAY_ARRAY_H_NODEPS
