#ifndef __X10_LANG_RUNTIME__REMOTE_H
#define __X10_LANG_RUNTIME__REMOTE_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
class Throwable;
} } 
namespace x10 { namespace lang { 
class Runtime__Latch;
} } 
namespace x10 { namespace lang { 

template<class FMGL(T)> class Runtime__Remote;
template <> class Runtime__Remote<void>;
template<class FMGL(T)> class Runtime__Remote : public x10::lang::Object 
 {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::Box<FMGL(T)> >
      FMGL(t);
    
    x10aux::ref<x10::util::Box<x10aux::ref<x10::lang::Throwable> > >
      FMGL(e);
    
    x10aux::ref<x10::lang::Runtime__Latch>
      FMGL(latch);
    
    void _constructor(
      );
    
    static x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > _make(
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
template <> class Runtime__Remote<void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_LANG_RUNTIME__REMOTE_H

namespace x10 { namespace lang { 
template<class FMGL(T)>
class Runtime__Remote;
} } 

#ifndef X10_LANG_RUNTIME__REMOTE_H_NODEPS
#define X10_LANG_RUNTIME__REMOTE_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Box.h>
#include <x10/util/Box.h>
#include <x10/lang/Throwable.h>
#include <x10/lang/Runtime__Latch.h>
#ifndef X10_LANG_RUNTIME__REMOTE_H_GENERICS
#define X10_LANG_RUNTIME__REMOTE_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::lang::Runtime__Remote<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::lang::Runtime__Remote<FMGL(T)> >()) x10::lang::Runtime__Remote<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_LANG_RUNTIME__REMOTE_H_GENERICS
#ifndef X10_LANG_RUNTIME__REMOTE_H_IMPLEMENTATION
#define X10_LANG_RUNTIME__REMOTE_H_IMPLEMENTATION
#include <x10/lang/Runtime__Remote.h>


#include "x10/lang/Runtime__Remote.inc"

template<class FMGL(T)> void x10::lang::Runtime__Remote<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::Runtime__Remote<FMGL(T)>");
    
}


//#line 1267 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1268 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1269 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10FieldDecl_c

//#line 1266 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::lang::Runtime__Remote<FMGL(T)>::_constructor(
                          ) {
    this->x10::lang::Object::_constructor();
    
    //#line 1267 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> >)this))->
      FMGL(t) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(T)> > >(x10aux::null);
    
    //#line 1268 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> >)this))->
      FMGL(e) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<x10aux::ref<x10::lang::Throwable> > > >(x10aux::null);
    
    //#line 1269 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> >)this))->
      FMGL(latch) = x10::lang::Runtime__Latch::_make();
    
}
template<class FMGL(T)> x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > x10::lang::Runtime__Remote<FMGL(T)>::_make(
                          ) {
    x10aux::ref<x10::lang::Runtime__Remote<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::lang::Runtime__Remote<FMGL(T)> >(), 0, sizeof(x10::lang::Runtime__Remote<FMGL(T)>))) x10::lang::Runtime__Remote<FMGL(T)>();
    this_->_constructor();
    return this_;
}


template<class FMGL(T)> const x10aux::serialization_id_t x10::lang::Runtime__Remote<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::Runtime__Remote<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::lang::Runtime__Remote<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::lang::Runtime__Remote<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::lang::Runtime__Remote<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::lang::Runtime__Remote<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::lang::Runtime__Remote<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.lang.Runtime$Remote";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_LANG_RUNTIME__REMOTE_H_IMPLEMENTATION
#endif // __X10_LANG_RUNTIME__REMOTE_H_NODEPS
