#ifndef __X10_UTIL_VALHASHMAP__HASHENTRY_H
#define __X10_UTIL_VALHASHMAP__HASHENTRY_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_UTIL_VALMAP__ENTRY_H_NODEPS
#include <x10/util/ValMap__Entry.h>
#undef X10_UTIL_VALMAP__ENTRY_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class ValHashMap;
} } 
namespace x10 { namespace util { 

template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry;
template <> class ValHashMap__HashEntry<void, void>;
template<class FMGL(Key), class FMGL(Value)> class ValHashMap__HashEntry : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::ValMap__Entry<FMGL(Key), FMGL(Value)>::template itable<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > _itable_1;
    
    void _instance_init();
    
    virtual FMGL(Key) getKey();
    virtual FMGL(Value) getValue();
    FMGL(Key) FMGL(key);
    
    FMGL(Value) FMGL(value);
    
    x10_int FMGL(hash);
    
    void _constructor(FMGL(Key) key, FMGL(Value) value);
    
    static x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > _make(
             FMGL(Key) key,
             FMGL(Value) value);
    
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ValHashMap__HashEntry<void, void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_VALHASHMAP__HASHENTRY_H

namespace x10 { namespace util { 
template<class FMGL(Key), class FMGL(Value)>
class ValHashMap__HashEntry;
} } 

#ifndef X10_UTIL_VALHASHMAP__HASHENTRY_H_NODEPS
#define X10_UTIL_VALHASHMAP__HASHENTRY_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/ValMap__Entry.h>
#include <x10/lang/Int.h>
#include <x10/util/ValHashMap.h>
#ifndef X10_UTIL_VALHASHMAP__HASHENTRY_H_GENERICS
#define X10_UTIL_VALHASHMAP__HASHENTRY_H_GENERICS
template<class FMGL(Key), class FMGL(Value)> template<class __T> x10aux::ref<__T> x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > this_ = new (x10aux::alloc_remote<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >()) x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_VALHASHMAP__HASHENTRY_H_GENERICS
#ifndef X10_UTIL_VALHASHMAP__HASHENTRY_H_IMPLEMENTATION
#define X10_UTIL_VALHASHMAP__HASHENTRY_H_IMPLEMENTATION
#include <x10/util/ValHashMap__HashEntry.h>


#include "x10/util/ValHashMap__HashEntry.inc"

template<class FMGL(Key), class FMGL(Value)> typename x10::util::ValMap__Entry<FMGL(Key), FMGL(Value)>::template itable<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_itable_0(&x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::getKey, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::getValue, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10::lang::Any::itable<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >  x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_itable_1(&x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::at, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::equals, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::hashCode, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::home, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::toString, &x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::typeName);
template<class FMGL(Key), class FMGL(Value)> x10aux::itable_entry x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::ValMap__Entry<FMGL(Key), FMGL(Value)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >())};
template<class FMGL(Key), class FMGL(Value)> void x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>");
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)> FMGL(Key) x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::getKey(
  ) {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >)this)->
             FMGL(key);
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10MethodDecl_c
template<class FMGL(Key), class FMGL(Value)> FMGL(Value) x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::getValue(
  ) {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >)this)->
             FMGL(value);
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10FieldDecl_c

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_constructor(
  FMGL(Key) key,
  FMGL(Value) value)
{
    this->x10::lang::Object::_constructor();
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >)this)->
      FMGL(key) =
      key;
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >)this)->
      FMGL(value) =
      value;
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ValHashMap.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >)this)->
      FMGL(hash) =
      x10::util::ValHashMap<void, void>::template hash<FMGL(Key) >(
        key);
    
}
template<class FMGL(Key), class FMGL(Value)>
x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_make(
  FMGL(Key) key,
  FMGL(Value) value)
{
    x10aux::ref<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> > this_ = new (memset(x10aux::alloc<x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)> >(), 0, sizeof(x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>))) x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>();
    this_->_constructor(key,
    value);
    return this_;
}


template<class FMGL(Key), class FMGL(Value)>
const x10aux::serialization_id_t x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::template _deserializer<x10::lang::Object>);

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(key));
    buf.write(this->FMGL(value));
    buf.write(this->FMGL(hash));
    
}

template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(key) = buf.read<FMGL(Key)>();
    FMGL(value) = buf.read<FMGL(Value)>();
    FMGL(hash) = buf.read<x10_int>();
}

template<class FMGL(Key), class FMGL(Value)>
x10aux::RuntimeType x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::rtt;
template<class FMGL(Key), class FMGL(Value)>
void x10::util::ValHashMap__HashEntry<FMGL(Key), FMGL(Value)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ValHashMap__HashEntry<void, void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::ValMap__Entry<FMGL(Key), FMGL(Value)> >()};
    const x10aux::RuntimeType* params[2] = { x10aux::getRTT<FMGL(Key)>(), x10aux::getRTT<FMGL(Value)>()};
    x10aux::RuntimeType::Variance variances[2] = { x10aux::RuntimeType::invariant, x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ValHashMap$HashEntry";
    rtt.initStageTwo(baseName, 2, parents, 2, params, variances);
}
#endif // X10_UTIL_VALHASHMAP__HASHENTRY_H_IMPLEMENTATION
#endif // __X10_UTIL_VALHASHMAP__HASHENTRY_H_NODEPS
