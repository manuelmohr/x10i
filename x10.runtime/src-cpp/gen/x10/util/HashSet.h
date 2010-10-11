#ifndef __X10_UTIL_HASHSET_H
#define __X10_UTIL_HASHSET_H

#include <x10rt.h>


#define X10_UTIL_MAPSET_H_NODEPS
#include <x10/util/MapSet.h>
#undef X10_UTIL_MAPSET_H_NODEPS
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class Map;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class RuntimeException;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Collection;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class HashSet;
template <> class HashSet<void>;
template<class FMGL(T)> class HashSet : public x10::util::MapSet<FMGL(T)>
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[6];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::Container<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::HashSet<FMGL(T)> > _itable_1;
    
    static typename x10::lang::Iterable<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> > _itable_2;
    
    static typename x10::util::Collection<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> > _itable_3;
    
    static typename x10::util::Set<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> > _itable_4;
    
    void _instance_init();
    
    void _constructor();
    
    static x10aux::ref<x10::util::HashSet<FMGL(T)> > _make();
    
    void _constructor(x10_int sz);
    
    static x10aux::ref<x10::util::HashSet<FMGL(T)> > _make(x10_int sz);
    
    virtual x10aux::ref<x10::util::Container<FMGL(T)> > clone();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class HashSet<void> : public x10::util::MapSet<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_HASHSET_H

namespace x10 { namespace util { 
template<class FMGL(T)> class HashSet;
} } 

#ifndef X10_UTIL_HASHSET_H_NODEPS
#define X10_UTIL_HASHSET_H_NODEPS
#include <x10/util/MapSet.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/util/Map.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/util/HashMap.h>
#include <x10/lang/Int.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/RuntimeException.h>
#include <x10/util/Collection.h>
#ifndef X10_UTIL_HASHSET_H_GENERICS
#define X10_UTIL_HASHSET_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::util::HashSet<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::HashSet<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::util::HashSet<FMGL(T)> >()) x10::util::HashSet<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_HASHSET_H_GENERICS
#ifndef X10_UTIL_HASHSET_H_IMPLEMENTATION
#define X10_UTIL_HASHSET_H_IMPLEMENTATION
#include <x10/util/HashSet.h>


#include "x10/util/HashSet.inc"

template<class FMGL(T)> typename x10::util::Container<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> >  x10::util::HashSet<FMGL(T)>::_itable_0(&x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::clone, &x10::util::HashSet<FMGL(T)>::contains, &x10::util::HashSet<FMGL(T)>::containsAll, &x10::util::HashSet<FMGL(T)>::equals, &x10::util::HashSet<FMGL(T)>::hashCode, &x10::util::HashSet<FMGL(T)>::home, &x10::util::HashSet<FMGL(T)>::isEmpty, &x10::util::HashSet<FMGL(T)>::iterator, &x10::util::HashSet<FMGL(T)>::size, &x10::util::HashSet<FMGL(T)>::toRail, &x10::util::HashSet<FMGL(T)>::toString, &x10::util::HashSet<FMGL(T)>::toValRail, &x10::util::HashSet<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::util::HashSet<FMGL(T)> >  x10::util::HashSet<FMGL(T)>::_itable_1(&x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::equals, &x10::util::HashSet<FMGL(T)>::hashCode, &x10::util::HashSet<FMGL(T)>::home, &x10::util::HashSet<FMGL(T)>::toString, &x10::util::HashSet<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::lang::Iterable<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> >  x10::util::HashSet<FMGL(T)>::_itable_2(&x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::equals, &x10::util::HashSet<FMGL(T)>::hashCode, &x10::util::HashSet<FMGL(T)>::home, &x10::util::HashSet<FMGL(T)>::iterator, &x10::util::HashSet<FMGL(T)>::toString, &x10::util::HashSet<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::util::Collection<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> >  x10::util::HashSet<FMGL(T)>::_itable_3(&x10::util::HashSet<FMGL(T)>::add, &x10::util::HashSet<FMGL(T)>::addAll, &x10::util::HashSet<FMGL(T)>::addAllWhere, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::clear, &x10::util::HashSet<FMGL(T)>::clone, &x10::util::HashSet<FMGL(T)>::contains, &x10::util::HashSet<FMGL(T)>::containsAll, &x10::util::HashSet<FMGL(T)>::equals, &x10::util::HashSet<FMGL(T)>::hashCode, &x10::util::HashSet<FMGL(T)>::home, &x10::util::HashSet<FMGL(T)>::isEmpty, &x10::util::HashSet<FMGL(T)>::iterator, &x10::util::HashSet<FMGL(T)>::remove, &x10::util::HashSet<FMGL(T)>::removeAll, &x10::util::HashSet<FMGL(T)>::removeAllWhere, &x10::util::HashSet<FMGL(T)>::retainAll, &x10::util::HashSet<FMGL(T)>::size, &x10::util::HashSet<FMGL(T)>::toRail, &x10::util::HashSet<FMGL(T)>::toString, &x10::util::HashSet<FMGL(T)>::toValRail, &x10::util::HashSet<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::util::Set<FMGL(T)>::template itable<x10::util::HashSet<FMGL(T)> >  x10::util::HashSet<FMGL(T)>::_itable_4(&x10::util::HashSet<FMGL(T)>::add, &x10::util::HashSet<FMGL(T)>::addAll, &x10::util::HashSet<FMGL(T)>::addAllWhere, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::at, &x10::util::HashSet<FMGL(T)>::clear, &x10::util::HashSet<FMGL(T)>::clone, &x10::util::HashSet<FMGL(T)>::contains, &x10::util::HashSet<FMGL(T)>::containsAll, &x10::util::HashSet<FMGL(T)>::equals, &x10::util::HashSet<FMGL(T)>::hashCode, &x10::util::HashSet<FMGL(T)>::home, &x10::util::HashSet<FMGL(T)>::isEmpty, &x10::util::HashSet<FMGL(T)>::iterator, &x10::util::HashSet<FMGL(T)>::remove, &x10::util::HashSet<FMGL(T)>::removeAll, &x10::util::HashSet<FMGL(T)>::removeAllWhere, &x10::util::HashSet<FMGL(T)>::retainAll, &x10::util::HashSet<FMGL(T)>::size, &x10::util::HashSet<FMGL(T)>::toRail, &x10::util::HashSet<FMGL(T)>::toString, &x10::util::HashSet<FMGL(T)>::toValRail, &x10::util::HashSet<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::util::HashSet<FMGL(T)>::_itables[6] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Container<FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::util::Collection<FMGL(T)> >, &_itable_3), x10aux::itable_entry(&x10aux::getRTT<x10::util::Set<FMGL(T)> >, &_itable_4), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::HashSet<FMGL(T)> >())};
template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::HashSet<FMGL(T)>");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_constructor() {
    this->x10::util::MapSet<FMGL(T)>::_constructor((__extension__ ({
                                                       x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > __desugarer__var__77__ =
                                                         x10aux::class_cast<x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > >(x10::util::HashMap<FMGL(T), x10_boolean>::_make());
                                                       
                                                       //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10LocalDecl_c
                                                       x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > __var1177__;
                                                       
                                                       //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Labeled_c
                                                       goto __ret2006; __ret2006: 
                                                       //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10Do_c
                                                       do
                                                       {
                                                       {
                                                           
                                                           //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10If_c
                                                           if (!((x10aux::struct_equals(x10::lang::Place_methods::place(x10aux::get_location(__desugarer__var__77__)),
                                                                                        x10::lang::Place_methods::_make(x10aux::here)))))
                                                           {
                                                               
                                                               //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Throw_c
                                                               x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.util.Map[T, x10.lang.Boolean]{self.home==here}"))));
                                                           }
                                                           
                                                           //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Eval_c
                                                           __var1177__ =
                                                             __desugarer__var__77__;
                                                           
                                                           //#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Branch_c
                                                           goto __ret2006_end_;
                                                       }
                                                       goto __ret2006_next_; __ret2006_next_: ;
                                                       }
                                                       while (false);
                                                       goto __ret2006_end_; __ret2006_end_: ;
                                                       __var1177__;
                                                   }))
                                                   );
    
}
template<class FMGL(T)> x10aux::ref<x10::util::HashSet<FMGL(T)> > x10::util::HashSet<FMGL(T)>::_make(
                          ) {
    x10aux::ref<x10::util::HashSet<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::util::HashSet<FMGL(T)> >(), 0, sizeof(x10::util::HashSet<FMGL(T)>))) x10::util::HashSet<FMGL(T)>();
    this_->_constructor();
    return this_;
}



//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_constructor(
                          x10_int sz) {
    this->x10::util::MapSet<FMGL(T)>::_constructor(
      (__extension__ ({
          x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > __desugarer__var__78__ =
            x10aux::class_cast<x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > >(x10::util::HashMap<FMGL(T), x10_boolean>::_make(sz));
          
          //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10LocalDecl_c
          x10aux::ref<x10::util::Map<FMGL(T), x10_boolean> > __var1178__;
          
          //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Labeled_c
          goto __ret2007; __ret2007: 
          //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10Do_c
          do
          {
          {
              
              //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10If_c
              if (!((x10aux::struct_equals(x10::lang::Place_methods::place(x10aux::get_location(__desugarer__var__78__)),
                                           x10::lang::Place_methods::_make(x10aux::here)))))
              {
                  
                  //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Throw_c
                  x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.util.Map[T, x10.lang.Boolean]{self.home==here}"))));
              }
              
              //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Eval_c
              __var1178__ =
                __desugarer__var__78__;
              
              //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Branch_c
              goto __ret2007_end_;
          }
          goto __ret2007_next_; __ret2007_next_: ;
          }
          while (false);
          goto __ret2007_end_; __ret2007_end_: ;
          __var1178__;
      }))
      );
    
}
template<class FMGL(T)> x10aux::ref<x10::util::HashSet<FMGL(T)> > x10::util::HashSet<FMGL(T)>::_make(
                          x10_int sz) {
    x10aux::ref<x10::util::HashSet<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::util::HashSet<FMGL(T)> >(), 0, sizeof(x10::util::HashSet<FMGL(T)>))) x10::util::HashSet<FMGL(T)>();
    this_->_constructor(sz);
    return this_;
}



//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::Container<FMGL(T)> >
  x10::util::HashSet<FMGL(T)>::clone(
  ) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/HashSet.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::util::HashSet<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::HashSet<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::util::MapSet<FMGL(T)>::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::util::MapSet<FMGL(T)>::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::HashSet<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::HashSet<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::HashSet<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::util::MapSet<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.HashSet";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_UTIL_HASHSET_H_IMPLEMENTATION
#endif // __X10_UTIL_HASHSET_H_NODEPS
