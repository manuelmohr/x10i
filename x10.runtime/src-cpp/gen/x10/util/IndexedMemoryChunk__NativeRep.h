#ifndef __X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H
#define __X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class IndexedMemoryChunk;
} } 
#include <x10/util/IndexedMemoryChunk.struct_h>
namespace x10 { namespace util { 

class IndexedMemoryChunk__NativeRep : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    template<class FMGL(T)> static void copyToLocal(x10::util::IndexedMemoryChunk<FMGL(T) > src,
                                                    x10_int srcIndex,
                                                    x10::util::IndexedMemoryChunk<FMGL(T) > dst,
                                                    x10_int dstIndex,
                                                    x10_int numElems);
    template<class FMGL(T)> static void copyFromLocal(x10::util::IndexedMemoryChunk<FMGL(T) > dst,
                                                      x10_int dstIndex,
                                                      x10::util::IndexedMemoryChunk<FMGL(T) > src,
                                                      x10_int srcIndex,
                                                      x10_int numElems);
    template<class FMGL(T)> static void copyTo(
      x10::util::IndexedMemoryChunk<FMGL(T) > src,
      x10_int srcIndex,
      x10::lang::Place dstPlace,
      x10::util::IndexedMemoryChunk<FMGL(T) > dst,
      x10_int dstIndex,
      x10_int numElems,
      x10_boolean uncounted);
    template<class FMGL(T)> static void copyFrom(
      x10::util::IndexedMemoryChunk<FMGL(T) > dst,
      x10_int dstIndex,
      x10::lang::Place srcPlace,
      x10::util::IndexedMemoryChunk<FMGL(T) > src,
      x10_int srcIndex,
      x10_int numElems,
      x10_boolean uncounted);
    void _constructor();
    
    
    // Serialization
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H

namespace x10 { namespace util { 
class IndexedMemoryChunk__NativeRep;
} } 

#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_NODEPS
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/lang/Int.h>
#include <x10/compiler/Native.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/util/IndexedMemoryChunk.h>
#include <x10/lang/Place.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/VoidFun_0_0.h>
#include <x10/util/IndexedMemoryChunk.h>
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP__CLOSURE__0_CLOSURE
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
template<class FMGL(T)> class x10_util_IndexedMemoryChunk__NativeRep__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::VoidFun_0_0::template itable <x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (numElems)); 
                                                       //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
                                                       i = ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
                (dst)->set((src)->apply(((x10_int) ((srcIndex) + (i)))), ((x10_int) ((dstIndex) + (i))));
            }
        }
        
    }
    
    // captured environment
    x10_int numElems;
    x10::util::IndexedMemoryChunk<FMGL(T) > dst;
    x10::util::IndexedMemoryChunk<FMGL(T) > src;
    x10_int srcIndex;
    x10_int dstIndex;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->numElems);
        buf.write(this->dst);
        buf.write(this->src);
        buf.write(this->srcIndex);
        buf.write(this->dstIndex);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_numElems = buf.read<x10_int>();
        x10::util::IndexedMemoryChunk<FMGL(T) > that_dst = buf.read<x10::util::IndexedMemoryChunk<FMGL(T) > >();
        x10::util::IndexedMemoryChunk<FMGL(T) > that_src = buf.read<x10::util::IndexedMemoryChunk<FMGL(T) > >();
        x10_int that_srcIndex = buf.read<x10_int>();
        x10_int that_dstIndex = buf.read<x10_int>();
        x10aux::ref<x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) > >()) x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >(that_numElems, that_dst, that_src, that_srcIndex, that_dstIndex);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_util_IndexedMemoryChunk__NativeRep__closure__0(x10_int numElems, x10::util::IndexedMemoryChunk<FMGL(T) > dst, x10::util::IndexedMemoryChunk<FMGL(T) > src, x10_int srcIndex, x10_int dstIndex) : numElems(numElems), dst(dst), src(src), srcIndex(srcIndex), dstIndex(dstIndex) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10:37-42";
    }

};

template<class FMGL(T)> typename x10::lang::VoidFun_0_0::template itable <x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) > >x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::_itable(&x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP__CLOSURE__0_CLOSURE
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_GENERICS
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_GENERICS
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyToLocal_1180
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyToLocal_1180
template<class FMGL(T)> void x10::util::IndexedMemoryChunk__NativeRep::copyToLocal(
  x10::util::IndexedMemoryChunk<FMGL(T) > src,
  x10_int srcIndex,
  x10::util::IndexedMemoryChunk<FMGL(T) > dst,
  x10_int dstIndex,
  x10_int numElems) {
 
}
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyToLocal_1180
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFromLocal_1181
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFromLocal_1181
template<class FMGL(T)> void x10::util::IndexedMemoryChunk__NativeRep::copyFromLocal(
  x10::util::IndexedMemoryChunk<FMGL(T) > dst,
  x10_int dstIndex,
  x10::util::IndexedMemoryChunk<FMGL(T) > src,
  x10_int srcIndex,
  x10_int numElems) {
 
}
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFromLocal_1181
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyTo_1182
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyTo_1182
template<class FMGL(T)> void x10::util::IndexedMemoryChunk__NativeRep::copyTo(
  x10::util::IndexedMemoryChunk<FMGL(T) > src,
  x10_int srcIndex,
  x10::lang::Place dstPlace,
  x10::util::IndexedMemoryChunk<FMGL(T) > dst,
  x10_int dstIndex,
  x10_int numElems,
  x10_boolean uncounted) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(dstPlace, x10::lang::Place_methods::_make(x10aux::here))))
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
        x10::util::IndexedMemoryChunk__NativeRep::template copyToLocal<FMGL(T) >(
          src,
          srcIndex,
          dst,
          dstIndex,
          numElems);
    }
    else
    {
        
        //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
        x10::lang::Runtime::runAt(
          dstPlace,
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T)>)))x10_util_IndexedMemoryChunk__NativeRep__closure__0<FMGL(T)>(numElems, dst, src, srcIndex, dstIndex)))));
    }
    
}
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyTo_1182
#ifndef X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFrom_1183
#define X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFrom_1183
template<class FMGL(T)> void x10::util::IndexedMemoryChunk__NativeRep::copyFrom(
  x10::util::IndexedMemoryChunk<FMGL(T) > dst,
  x10_int dstIndex,
  x10::lang::Place srcPlace,
  x10::util::IndexedMemoryChunk<FMGL(T) > src,
  x10_int srcIndex,
  x10_int numElems,
  x10_boolean uncounted) {
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(srcPlace, x10::lang::Place_methods::_make(x10aux::here))))
    {
        
        //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
        x10::util::IndexedMemoryChunk__NativeRep::template copyFromLocal<FMGL(T) >(
          dst,
          dstIndex,
          src,
          srcIndex,
          numElems);
    }
    else
    {
        
        //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (numElems));
                 
                 //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/IndexedMemoryChunk__NativeRep.x10": polyglot.ast.Eval_c
                (dst)->set((src)->apply(((x10_int) ((srcIndex) + (i)))), ((x10_int) ((dstIndex) + (i))));
            }
        }
        
    }
    
}
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_copyFrom_1183
#endif // X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_GENERICS
#endif // __X10_UTIL_INDEXEDMEMORYCHUNK__NATIVEREP_H_NODEPS
