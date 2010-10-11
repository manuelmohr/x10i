#ifndef __X10_UTIL_ABSTRACTCONTAINER_H
#define __X10_UTIL_ABSTRACTCONTAINER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_UTIL_CONTAINER_H_NODEPS
#include <x10/util/Container.h>
#undef X10_UTIL_CONTAINER_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class AbstractContainer;
template <> class AbstractContainer<void>;
template<class FMGL(T)> class AbstractContainer : public x10::lang::Object
  {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    virtual x10_int size() = 0;
    virtual x10_boolean isEmpty();
    virtual x10_boolean contains(FMGL(T) y) = 0;
    virtual x10aux::ref<x10::util::Container<FMGL(T)> > clone() = 0;
    virtual x10aux::ref<x10::lang::Iterator<FMGL(T)> > iterator() = 0;
    virtual x10aux::ref<x10::lang::ValRail<FMGL(T) > > toValRail();
    virtual x10aux::ref<x10::lang::Rail<FMGL(T) > > toRail();
    virtual x10_boolean containsAll(x10aux::ref<x10::util::Container<FMGL(T)> > c);
    void _constructor();
    
    
    // Serialization
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class AbstractContainer<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_ABSTRACTCONTAINER_H

namespace x10 { namespace util { 
template<class FMGL(T)> class AbstractContainer;
} } 

#ifndef X10_UTIL_ABSTRACTCONTAINER_H_NODEPS
#define X10_UTIL_ABSTRACTCONTAINER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/Container.h>
#include <x10/lang/Int.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/ValRail.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Iterator.h>
#ifndef X10_UTIL_ABSTRACTCONTAINER_H_GENERICS
#define X10_UTIL_ABSTRACTCONTAINER_H_GENERICS
#endif // X10_UTIL_ABSTRACTCONTAINER_H_GENERICS
#ifndef X10_UTIL_ABSTRACTCONTAINER_H_IMPLEMENTATION
#define X10_UTIL_ABSTRACTCONTAINER_H_IMPLEMENTATION
#include <x10/util/AbstractContainer.h>


#include "x10/util/AbstractContainer.inc"

template<class FMGL(T)> void x10::util::AbstractContainer<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::AbstractContainer<FMGL(T)>");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::AbstractContainer<FMGL(T)>::isEmpty(
  ) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->size(),
                                  ((x10_int)0)));
    
}

//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::ValRail<FMGL(T) > >
  x10::util::AbstractContainer<FMGL(T)>::toValRail(
  ) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::GrowableRail<FMGL(T) > > g = x10::util::GrowableRail<FMGL(T) >::_make(((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->size());
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > x1830;
        for (
             //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
             x1830 = ((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1830))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1830)->_getITables())->hasNext))();
             ) {
            
            //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1830))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1830)->_getITables())->next))();
            
            //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": polyglot.ast.Eval_c
            (g)->add(x);
        }
    }
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10Return_c
    return (g)->toValRail();
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Rail<FMGL(T) > >
  x10::util::AbstractContainer<FMGL(T)>::toRail(
  ) {
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::GrowableRail<FMGL(T) > > g =
      x10::util::GrowableRail<FMGL(T) >::_make(((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->size());
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > x1831;
        for (
             //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
             x1831 = ((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1831))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1831)->_getITables())->hasNext))();
             ) {
            
            //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1831))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1831)->_getITables())->next))();
            
            //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": polyglot.ast.Eval_c
            (g)->add(x);
        }
    }
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10Return_c
    return (g)->toRail();
    
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::AbstractContainer<FMGL(T)>::containsAll(
  x10aux::ref<x10::util::Container<FMGL(T)> > c) {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > x1832;
        for (
             //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
             x1832 = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::nullCheck(c)).operator->()))->*(x10aux::findITable<x10::util::Container<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)c)->_getITables())->iterator))();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1832))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1832)->_getITables())->hasNext))();
             ) {
            
            //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(x1832))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)x1832)->_getITables())->next))();
            
            //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10If_c
            if ((!(((x10aux::ref<x10::util::AbstractContainer<FMGL(T)> >)this)->contains(
                     x)))) {
                
                //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/util/AbstractContainer.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::util::AbstractContainer<FMGL(T)>::_constructor(
                          ) {
    this->x10::lang::Object::_constructor();
    
}

template<class FMGL(T)> void x10::util::AbstractContainer<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::util::AbstractContainer<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::AbstractContainer<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::AbstractContainer<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::AbstractContainer<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::Container<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.util.AbstractContainer";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_UTIL_ABSTRACTCONTAINER_H_IMPLEMENTATION
#endif // __X10_UTIL_ABSTRACTCONTAINER_H_NODEPS
