#ifndef __X10_UTIL_ARRAYLIST_H
#define __X10_UTIL_ARRAYLIST_H

#include <x10rt.h>


#define X10_UTIL_ABSTRACTCOLLECTION_H_NODEPS
#include <x10/util/AbstractCollection.h>
#undef X10_UTIL_ABSTRACTCOLLECTION_H_NODEPS
#define X10_UTIL_LIST_H_NODEPS
#include <x10/util/List.h>
#undef X10_UTIL_LIST_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Container;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class List;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class ListIterator;
} } 
namespace x10 { namespace util { 
template<class FMGL(S)> class ArrayList__It;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Comparable;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
class Runtime;
} } 
namespace x10 { namespace lang { 
class ClassCastException;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Collection;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace util { 

template<class FMGL(T)> class ArrayList;
template <> class ArrayList<void>;
template<class FMGL(T)> class ArrayList : public x10::util::AbstractCollection<FMGL(T)>
  {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[8];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::Container<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ArrayList<FMGL(T)> > _itable_1;
    
    static typename x10::lang::Iterable<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_2;
    
    static typename x10::util::Collection<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_3;
    
    static typename x10::util::List<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_4;
    
    static typename x10::util::Indexed<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_5;
    
    static typename x10::lang::Settable<x10_int, FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> > _itable_6;
    
    void _instance_init();
    
    x10aux::ref<x10::util::GrowableRail<FMGL(T) > > FMGL(a);
    
    virtual x10_boolean contains(FMGL(T) v);
    virtual x10aux::ref<x10::util::Container<FMGL(T)> > clone();
    virtual x10_boolean add(FMGL(T) v);
    virtual x10_boolean remove(FMGL(T) v);
    virtual void addBefore(x10_int i, FMGL(T) v);
    virtual FMGL(T) set(FMGL(T) v, x10_int i);
    virtual FMGL(T) removeAt(x10_int i);
    virtual FMGL(T) apply(x10_int i);
    virtual FMGL(T) get(x10_int i);
    virtual x10_int size();
    virtual x10_boolean isEmpty();
    virtual x10aux::ref<x10::lang::Rail<FMGL(T) > > toArray();
    virtual x10aux::ref<x10::lang::Rail<FMGL(T) > > toRail();
    virtual x10aux::ref<x10::lang::ValRail<FMGL(T) > > toValRail(
      );
    void _constructor();
    
    static x10aux::ref<x10::util::ArrayList<FMGL(T)> > _make();
    
    void _constructor(x10_int size);
    
    static x10aux::ref<x10::util::ArrayList<FMGL(T)> > _make(x10_int size);
    
    virtual FMGL(T) removeFirst();
    virtual FMGL(T) removeLast();
    virtual FMGL(T) getFirst();
    virtual FMGL(T) getLast();
    virtual x10aux::ref<x10::util::List<x10_int> > indices();
    virtual x10aux::ref<x10::util::List<FMGL(T)> > subList(x10_int begin,
                                                           x10_int end);
    virtual x10_int indexOf(FMGL(T) v);
    virtual x10_int indexOf(x10_int index, FMGL(T) v);
    virtual x10_int lastIndexOf(FMGL(T) v);
    virtual x10_int lastIndexOf(x10_int index, FMGL(T) v);
    virtual x10aux::ref<x10::lang::ValRail<FMGL(T) > > moveSectionToValRail(
      x10_int i,
      x10_int j);
    virtual x10aux::ref<x10::lang::Iterator<FMGL(T)> > iterator();
    virtual x10aux::ref<x10::util::ListIterator<FMGL(T)> > iteratorFrom(
      x10_int i);
    virtual void reverse();
    virtual void sort();
    virtual void sort(x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> > cmp);
    void qsort(x10aux::ref<x10::util::GrowableRail<FMGL(T) > > a,
               x10_int lo,
               x10_int hi,
               x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> > cmp);
    void exch(x10aux::ref<x10::util::GrowableRail<FMGL(T) > > a, x10_int i,
              x10_int j);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ArrayList<void> : public x10::util::AbstractCollection<void>
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    template<class FMGL(T)>
    static x10aux::ref<x10::util::ArrayList<FMGL(T)> >
      make(
      x10aux::ref<x10::util::Container<FMGL(T)> > c);
    
    
};

} } 
#endif // X10_UTIL_ARRAYLIST_H

namespace x10 { namespace util { 
template<class FMGL(T)>
class ArrayList;
} } 

#ifndef X10_UTIL_ARRAYLIST_H_NODEPS
#define X10_UTIL_ARRAYLIST_H_NODEPS
#include <x10/util/AbstractCollection.h>
#include <x10/util/List.h>
#include <x10/util/GrowableRail.h>
#include <x10/util/Container.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Int.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/util/List.h>
#include <x10/lang/ValRail.h>
#include <x10/util/ListIterator.h>
#include <x10/util/ArrayList__It.h>
#include <x10/lang/Comparable.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Runtime.h>
#include <x10/lang/ClassCastException.h>
#include <x10/util/Collection.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Iterator.h>
#ifndef X10_UTIL_ARRAYLIST__CLOSURE__0_CLOSURE
#define X10_UTIL_ARRAYLIST__CLOSURE__0_CLOSURE
#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_2.h>
template<class FMGL(T)> class x10_util_ArrayList__closure__0 : public x10::lang::Closure {
    public:
    
    static typename x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int>::template itable <x10_util_ArrayList__closure__0<FMGL(T) > > _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(FMGL(T) x, FMGL(T) y) {
        
        //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
        return (__extension__ ({ x10aux::ref<x10::lang::Reference> _ = x10aux::nullCheck((__extension__ ({
                   x10aux::ref<x10::lang::Comparable<FMGL(T)> > __desugarer__var__72__ =
                     x10aux::class_cast<x10aux::ref<x10::lang::Comparable<FMGL(T)> > >(x);
                   
                   //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
                   x10aux::ref<x10::lang::Comparable<FMGL(T)> > __var1109__;
                   
                   //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Labeled_c
                   goto __ret2004; __ret2004: 
                   //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Do_c
                   do
                   {
                   {
                       
                       //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
                       if (!((x10aux::struct_equals(x10::lang::Place_methods::place(x10aux::get_location(__desugarer__var__72__)),
                                                    x10::lang::Place_methods::_make(x10aux::here)))))
                       {
                           
                           //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Throw_c
                           x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Comparable[T]{self.home==here}"))));
                       }
                       
                       //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
                       __var1109__ =
                         __desugarer__var__72__;
                       
                       //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Branch_c
                       goto __ret2004_end_;
                   }
                   goto __ret2004_next_; __ret2004_next_: ;
                   }
                   while (false);
                   goto __ret2004_end_; __ret2004_end_: ;
                   __var1109__;
               }))
               ); (((x10::lang::Reference*)(_.operator->()))->*(x10aux::findITable<x10::lang::Comparable<FMGL(T)> >(_->_getITables())->compareTo))(
                 y); }));
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_util_ArrayList__closure__0<FMGL(T) > > this_ = new (x10aux::alloc<x10_util_ArrayList__closure__0<FMGL(T) > >()) x10_util_ArrayList__closure__0<FMGL(T) >();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_util_ArrayList__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10:215";
    }

};

template<class FMGL(T)> typename x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int>::template itable <x10_util_ArrayList__closure__0<FMGL(T) > >x10_util_ArrayList__closure__0<FMGL(T) >::_itable(&x10_util_ArrayList__closure__0<FMGL(T) >::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_util_ArrayList__closure__0<FMGL(T) >::toString, &x10::lang::Closure::typeName);template<class FMGL(T)>
x10aux::itable_entry x10_util_ArrayList__closure__0<FMGL(T) >::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >, &x10_util_ArrayList__closure__0<FMGL(T) >::_itable),x10aux::itable_entry(NULL, NULL)};

template<class FMGL(T)>
const x10aux::serialization_id_t x10_util_ArrayList__closure__0<FMGL(T) >::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_util_ArrayList__closure__0<FMGL(T) >::template _deserialize<x10::lang::Object>);

#endif // X10_UTIL_ARRAYLIST__CLOSURE__0_CLOSURE
#ifndef X10_UTIL_ARRAYLIST_H_GENERICS
#define X10_UTIL_ARRAYLIST_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::util::ArrayList<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::util::ArrayList<FMGL(T)> >()) x10::util::ArrayList<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_ARRAYLIST_H_GENERICS
#ifndef X10_UTIL_ARRAYLIST_H_IMPLEMENTATION
#define X10_UTIL_ARRAYLIST_H_IMPLEMENTATION
#include <x10/util/ArrayList.h>


#include "x10/util/ArrayList.inc"

template<class FMGL(T)> typename x10::util::Container<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_0(&x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::clone, &x10::util::ArrayList<FMGL(T)>::contains, &x10::util::ArrayList<FMGL(T)>::containsAll, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::isEmpty, &x10::util::ArrayList<FMGL(T)>::iterator, &x10::util::ArrayList<FMGL(T)>::size, &x10::util::ArrayList<FMGL(T)>::toRail, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::toValRail, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_1(&x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::lang::Iterable<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_2(&x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::iterator, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::util::Collection<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_3(&x10::util::ArrayList<FMGL(T)>::add, &x10::util::ArrayList<FMGL(T)>::addAll, &x10::util::ArrayList<FMGL(T)>::addAllWhere, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::clear, &x10::util::ArrayList<FMGL(T)>::clone, &x10::util::ArrayList<FMGL(T)>::contains, &x10::util::ArrayList<FMGL(T)>::containsAll, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::isEmpty, &x10::util::ArrayList<FMGL(T)>::iterator, &x10::util::ArrayList<FMGL(T)>::remove, &x10::util::ArrayList<FMGL(T)>::removeAll, &x10::util::ArrayList<FMGL(T)>::removeAllWhere, &x10::util::ArrayList<FMGL(T)>::retainAll, &x10::util::ArrayList<FMGL(T)>::size, &x10::util::ArrayList<FMGL(T)>::toRail, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::toValRail, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::util::List<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_4(&x10::util::ArrayList<FMGL(T)>::add, &x10::util::ArrayList<FMGL(T)>::addAll, &x10::util::ArrayList<FMGL(T)>::addAllWhere, &x10::util::ArrayList<FMGL(T)>::addBefore, &x10::util::ArrayList<FMGL(T)>::apply, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::clear, &x10::util::ArrayList<FMGL(T)>::clone, &x10::util::ArrayList<FMGL(T)>::contains, &x10::util::ArrayList<FMGL(T)>::containsAll, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::getFirst, &x10::util::ArrayList<FMGL(T)>::getLast, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::indexOf, &x10::util::ArrayList<FMGL(T)>::indexOf, &x10::util::ArrayList<FMGL(T)>::indices, &x10::util::ArrayList<FMGL(T)>::isEmpty, &x10::util::ArrayList<FMGL(T)>::iterator, &x10::util::ArrayList<FMGL(T)>::iteratorFrom, &x10::util::ArrayList<FMGL(T)>::lastIndexOf, &x10::util::ArrayList<FMGL(T)>::lastIndexOf, &x10::util::ArrayList<FMGL(T)>::remove, &x10::util::ArrayList<FMGL(T)>::removeAll, &x10::util::ArrayList<FMGL(T)>::removeAllWhere, &x10::util::ArrayList<FMGL(T)>::removeAt, &x10::util::ArrayList<FMGL(T)>::removeFirst, &x10::util::ArrayList<FMGL(T)>::removeLast, &x10::util::ArrayList<FMGL(T)>::retainAll, &x10::util::ArrayList<FMGL(T)>::reverse, &x10::util::ArrayList<FMGL(T)>::set, &x10::util::ArrayList<FMGL(T)>::size, &x10::util::ArrayList<FMGL(T)>::sort, &x10::util::ArrayList<FMGL(T)>::sort, &x10::util::ArrayList<FMGL(T)>::subList, &x10::util::ArrayList<FMGL(T)>::toRail, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::toValRail, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::util::Indexed<FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_5(&x10::util::ArrayList<FMGL(T)>::apply, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::clone, &x10::util::ArrayList<FMGL(T)>::contains, &x10::util::ArrayList<FMGL(T)>::containsAll, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::isEmpty, &x10::util::ArrayList<FMGL(T)>::iterator, &x10::util::ArrayList<FMGL(T)>::size, &x10::util::ArrayList<FMGL(T)>::toRail, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::toValRail, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::lang::Settable<x10_int, FMGL(T)>::template itable<x10::util::ArrayList<FMGL(T)> >  x10::util::ArrayList<FMGL(T)>::_itable_6(&x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::at, &x10::util::ArrayList<FMGL(T)>::equals, &x10::util::ArrayList<FMGL(T)>::hashCode, &x10::util::ArrayList<FMGL(T)>::home, &x10::util::ArrayList<FMGL(T)>::set, &x10::util::ArrayList<FMGL(T)>::toString, &x10::util::ArrayList<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::util::ArrayList<FMGL(T)>::_itables[8] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::Container<FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::util::Collection<FMGL(T)> >, &_itable_3), x10aux::itable_entry(&x10aux::getRTT<x10::util::List<FMGL(T)> >, &_itable_4), x10aux::itable_entry(&x10aux::getRTT<x10::util::Indexed<FMGL(T)> >, &_itable_5), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Settable<x10_int, FMGL(T)> >, &_itable_6), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ArrayList<FMGL(T)> >())};
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ArrayList<FMGL(T)>");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10FieldDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::ArrayList<FMGL(T)>::contains(
  FMGL(T) v) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                          FMGL(a))->length())); 
                                                                //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
                                                                i =
                                                                  ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(v,
                                       x10aux::null))
                  ? (x10_boolean)((x10aux::struct_equals((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                            FMGL(a))->apply(i),
                                                         x10aux::null)))
                  : (x10_boolean)(x10aux::equals(v,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                                                                                 FMGL(a))->apply(i)))))
            {
                
                //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::Container<FMGL(T)> >
  x10::util::ArrayList<FMGL(T)>::clone(
  ) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > a =
      x10::util::ArrayList<FMGL(T)>::_make();
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    a->addAll(x10aux::class_cast_unchecked<x10aux::ref<x10::util::Container<FMGL(T)> > >(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)));
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return a;
    
}

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::ArrayList<FMGL(T)>::add(
  FMGL(T) v) {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
       FMGL(a))->add(v);
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::ArrayList<FMGL(T)>::remove(
  FMGL(T) v) {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                          FMGL(a))->length()));
             
             //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(v,
                                       x10aux::null))
                  ? (x10_boolean)((x10aux::struct_equals((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                            FMGL(a))->apply(i),
                                                         x10aux::null)))
                  : (x10_boolean)(x10aux::equals(v,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                                                                                 FMGL(a))->apply(i)))))
            {
                
                //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->removeAt(
                  i);
                
                //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::addBefore(
  x10_int i,
  FMGL(T) v) {
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
       FMGL(a))->add(v);
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int j;
        for (
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             j = ((x10_int) ((i) + (((x10_int)1))));
             ((j) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                        FMGL(a))->length()));
             
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             j =
               ((x10_int) ((j) + (((x10_int)1)))))
        {
            
            //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
               FMGL(a))->set((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                FMGL(a))->apply(((x10_int) ((j) - (((x10_int)1))))), j);
        }
    }
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
       FMGL(a))->set(v, i);
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::set(
  FMGL(T) v,
  x10_int i) {
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
       FMGL(a))->set(v, i);
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::removeAt(
  x10_int i) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    FMGL(T) v = (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                   FMGL(a))->apply(i);
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int j;
        for (
             //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             j = ((x10_int) ((i) + (((x10_int)1))));
             ((j) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                        FMGL(a))->length()));
             
             //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             j =
               ((x10_int) ((j) + (((x10_int)1)))))
        {
            
            //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
               FMGL(a))->set((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                FMGL(a))->apply(j), ((x10_int) ((j) - (((x10_int)1)))));
        }
    }
    
    //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
       FMGL(a))->removeLast();
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return v;
    
}

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::apply(
  x10_int i) {
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->apply(i);
    
}

//#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::get(
  x10_int i) {
    
    //#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->apply(i);
    
}

//#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::util::ArrayList<FMGL(T)>::size(
  ) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->length();
    
}

//#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::util::ArrayList<FMGL(T)>::isEmpty(
  ) {
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->size(),
                                  ((x10_int)0)));
    
}

//#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Rail<FMGL(T) > >
  x10::util::ArrayList<FMGL(T)>::toArray(
  ) {
    
    //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->toRail();
    
}

//#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Rail<FMGL(T) > >
  x10::util::ArrayList<FMGL(T)>::toRail(
  ) {
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->toRail();
    
}

//#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::ValRail<FMGL(T) > >
  x10::util::ArrayList<FMGL(T)>::toValRail(
  ) {
    
    //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->toValRail();
    
}

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_constructor(
                          ) {
    this->x10::util::AbstractCollection<FMGL(T)>::_constructor();
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this))->
      FMGL(a) = x10::util::GrowableRail<FMGL(T) >::_make();
    
}
template<class FMGL(T)> x10aux::ref<x10::util::ArrayList<FMGL(T)> > x10::util::ArrayList<FMGL(T)>::_make(
                          ) {
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::util::ArrayList<FMGL(T)> >(), 0, sizeof(x10::util::ArrayList<FMGL(T)>))) x10::util::ArrayList<FMGL(T)>();
    this_->_constructor();
    return this_;
}



//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_constructor(
                          x10_int size) {
    this->x10::util::AbstractCollection<FMGL(T)>::_constructor();
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this))->
      FMGL(a) = x10::util::GrowableRail<FMGL(T) >::_make(size);
    
}
template<class FMGL(T)> x10aux::ref<x10::util::ArrayList<FMGL(T)> > x10::util::ArrayList<FMGL(T)>::_make(
                          x10_int size) {
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::util::ArrayList<FMGL(T)> >(), 0, sizeof(x10::util::ArrayList<FMGL(T)>))) x10::util::ArrayList<FMGL(T)>();
    this_->_constructor(size);
    return this_;
}



//#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::removeFirst(
  ) {
    
    //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->removeAt(
             ((x10_int)0));
    
}

//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::removeLast(
  ) {
    
    //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->removeAt(
             ((x10_int) (((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                             FMGL(a))->length()) - (((x10_int)1)))));
    
}

//#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::getFirst(
  ) {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->get(
             ((x10_int)0));
    
}

//#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::util::ArrayList<FMGL(T)>::getLast(
  ) {
    
    //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->get(
             ((x10_int) (((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                             FMGL(a))->length()) - (((x10_int)1)))));
    
}

//#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::List<x10_int> >
  x10::util::ArrayList<FMGL(T)>::indices(
  ) {
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<x10_int> > l =
      x10::util::ArrayList<x10_int>::_make();
    
    //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                          FMGL(a))->length()));
             
             //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
            l->add(
              i);
        }
    }
    
    //#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::List<x10_int> > >(l);
    
}

//#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::List<FMGL(T)> >
  x10::util::ArrayList<FMGL(T)>::subList(
  x10_int begin,
  x10_int end) {
    
    //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > l =
      x10::util::ArrayList<FMGL(T)>::_make();
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = begin; ((i) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                   FMGL(a))->length())) &&
                        ((i) < (end)); 
                                       //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
                                       i =
                                         ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
            l->add(
              (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                 FMGL(a))->apply(i));
        }
    }
    
    //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::List<FMGL(T)> > >(l);
    
}

//#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::util::ArrayList<FMGL(T)>::indexOf(
  FMGL(T) v) {
    
    //#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->indexOf(
             ((x10_int)0),
             v);
    
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::util::ArrayList<FMGL(T)>::indexOf(
  x10_int index,
  FMGL(T) v) {
    
    //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = index; ((i) < ((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                   FMGL(a))->length()));
             
             //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(v,
                                       x10aux::null))
                  ? (x10_boolean)((x10aux::struct_equals((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                            FMGL(a))->apply(i),
                                                         x10aux::null)))
                  : (x10_boolean)(x10aux::equals(v,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                                                                                 FMGL(a))->apply(i)))))
            {
                
                //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
                return i;
                
            }
            
        }
    }
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10_int)-1);
    
}

//#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::util::ArrayList<FMGL(T)>::lastIndexOf(
  FMGL(T) v) {
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->lastIndexOf(
             ((x10_int) (((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                             FMGL(a))->length()) - (((x10_int)1)))),
             v);
    
}

//#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::util::ArrayList<FMGL(T)>::lastIndexOf(
  x10_int index,
  FMGL(T) v) {
    
    //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = index; ((i) >= (((x10_int)0)));
             
             //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) - (((x10_int)1)))))
        {
            
            //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(v,
                                       x10aux::null))
                  ? (x10_boolean)((x10aux::struct_equals((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                            FMGL(a))->apply(i),
                                                         x10aux::null)))
                  : (x10_boolean)(x10aux::equals(v,x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                                                                                                                 FMGL(a))->apply(i)))))
            {
                
                //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
                return i;
                
            }
            
        }
    }
    
    //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((x10_int)-1);
    
}

//#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::ValRail<FMGL(T) > >
  x10::util::ArrayList<FMGL(T)>::moveSectionToValRail(
  x10_int i,
  x10_int j) {
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
              FMGL(a))->moveSectionToValRail(i, j);
    
}

//#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Iterator<FMGL(T)> >
  x10::util::ArrayList<FMGL(T)>::iterator(
  ) {
    
    //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::ListIterator<FMGL(T)> > >(x10::util::ArrayList__It<FMGL(T)>::_make(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)));
    
}

//#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::util::ListIterator<FMGL(T)> >
  x10::util::ArrayList<FMGL(T)>::iteratorFrom(
  x10_int i) {
    
    //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::util::ListIterator<FMGL(T)> > >(x10::util::ArrayList__It<FMGL(T)>::_make(((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this),
                                                                                                                                  i));
    
}

//#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::reverse(
  ) {
    
    //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10_int length = (((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                        FMGL(a))->length();
    
    //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((length) / (((x10_int)2))))));
             
             //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 210 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->exch(
              ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                FMGL(a),
              i,
              ((x10_int) ((((x10_int) ((length) - (((x10_int)1))))) - (i))));
        }
    }
    
}

//#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::sort(
  ) {
    {
        
        //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->sort(
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> > >(x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(x10aux::ref<x10_util_ArrayList__closure__0<FMGL(T) > >(new (x10aux::alloc<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(sizeof(x10_util_ArrayList__closure__0<FMGL(T)>)))x10_util_ArrayList__closure__0<FMGL(T)>()))));
        
        //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::sort(
  x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> > cmp) {
    {
        
        //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->qsort(
          ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
            FMGL(a),
          ((x10_int)0),
          ((x10_int) (((((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->
                          FMGL(a))->length()) - (((x10_int)1)))),
          cmp);
        
        //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::qsort(
  x10aux::ref<x10::util::GrowableRail<FMGL(T) > > a,
  x10_int lo,
  x10_int hi,
  x10aux::ref<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> > cmp) {
    
    //#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
    if (((hi) <= (lo))) {
        
        //#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10_int l = ((x10_int) ((lo) - (((x10_int)1))));
    
    //#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10_int h = hi;
    
    //#line 231 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10While_c
    while (true) {
        
        //#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10While_c
        while ((((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(cmp))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(((x10aux::ref<x10::lang::Reference>)cmp)->_getITables())->apply))(
                 (a)->apply(l =
                   ((x10_int) ((l) + (((x10_int)1))))),
                 (a)->apply(hi))) < (((x10_int)0))))
        {
            
            //#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Empty_c
            ;
        }
        
        //#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10While_c
        while ((((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(cmp))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_2<FMGL(T), FMGL(T), x10_int> >(((x10aux::ref<x10::lang::Reference>)cmp)->_getITables())->apply))(
                 (a)->apply(hi),
                 (a)->apply(h =
                   ((x10_int) ((h) - (((x10_int)1))))))) < (((x10_int)0))) &&
               ((h) > (lo))) {
            
            //#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Empty_c
            ;
        }
        
        //#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10If_c
        if (((l) >= (h))) {
            
            //#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Branch_c
            break;
        }
        
        //#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->exch(
          a,
          l,
          h);
    }
    
    //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->exch(
      a,
      l,
      hi);
    
    //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->qsort(
      a,
      lo,
      ((x10_int) ((l) - (((x10_int)1)))),
      cmp);
    
    //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::ArrayList<FMGL(T)> >)this)->qsort(
      a,
      ((x10_int) ((l) + (((x10_int)1)))),
      hi,
      cmp);
}

//#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::exch(
  x10aux::ref<x10::util::GrowableRail<FMGL(T) > > a,
  x10_int i,
  x10_int j) {
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    FMGL(T) temp = (a)->apply(i);
    
    //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (a)->set((a)->apply(j), i);
    
    //#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    (a)->set(temp, j);
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::util::ArrayList<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ArrayList<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::util::AbstractCollection<FMGL(T)>::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::util::AbstractCollection<FMGL(T)>::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::util::ArrayList<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::util::ArrayList<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ArrayList<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::util::AbstractCollection<FMGL(T)> >(), x10aux::getRTT<x10::util::List<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ArrayList";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
template<class FMGL(T)> x10aux::ref<x10::util::ArrayList<FMGL(T)> >
  x10::util::ArrayList<void>::make(x10aux::ref<x10::util::Container<FMGL(T)> > c)
{
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<FMGL(T)> > a =
      x10::util::ArrayList<FMGL(T)>::_make();
    
    //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    a->addAll(
      c);
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return a;
    
}
#endif // X10_UTIL_ARRAYLIST_H_IMPLEMENTATION
#endif // __X10_UTIL_ARRAYLIST_H_NODEPS
