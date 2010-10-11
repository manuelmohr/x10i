#ifndef __X10_UTIL_ARRAYLIST__IT_H
#define __X10_UTIL_ARRAYLIST__IT_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_UTIL_LISTITERATOR_H_NODEPS
#include <x10/util/ListIterator.h>
#undef X10_UTIL_LISTITERATOR_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class ArrayList;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace util { 

template<class FMGL(S)> class ArrayList__It;
template <> class ArrayList__It<void>;
template<class FMGL(S)> class ArrayList__It : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[5];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::util::ListIterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> > _itable_0;
    
    static x10::lang::Any::itable<x10::util::ArrayList__It<FMGL(S)> > _itable_1;
    
    static typename x10::util::CollectionIterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> > _itable_2;
    
    static typename x10::lang::Iterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> > _itable_3;
    
    void _instance_init();
    
    x10_int FMGL(i);
    
    x10aux::ref<x10::util::ArrayList<FMGL(S)> > FMGL(al);
    
    void _constructor(x10aux::ref<x10::util::ArrayList<FMGL(S)> > al);
    
    static x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > _make(x10aux::ref<x10::util::ArrayList<FMGL(S)> > al);
    
    void _constructor(x10aux::ref<x10::util::ArrayList<FMGL(S)> > al, x10_int i);
    
    static x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > _make(x10aux::ref<x10::util::ArrayList<FMGL(S)> > al,
                                                                 x10_int i);
    
    virtual x10_boolean hasNext();
    virtual x10_int nextIndex();
    virtual FMGL(S) next();
    virtual x10_boolean hasPrevious();
    virtual x10_int previousIndex();
    virtual FMGL(S) previous();
    virtual void remove();
    virtual void set(FMGL(S) v);
    virtual void add(FMGL(S) v);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ArrayList__It<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_UTIL_ARRAYLIST__IT_H

namespace x10 { namespace util { 
template<class FMGL(S)> class ArrayList__It;
} } 

#ifndef X10_UTIL_ARRAYLIST__IT_H_NODEPS
#define X10_UTIL_ARRAYLIST__IT_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/ListIterator.h>
#include <x10/lang/Int.h>
#include <x10/util/ArrayList.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_2.h>
#ifndef X10_UTIL_ARRAYLIST__IT_H_GENERICS
#define X10_UTIL_ARRAYLIST__IT_H_GENERICS
template<class FMGL(S)> template<class __T> x10aux::ref<__T> x10::util::ArrayList__It<FMGL(S)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > this_ = new (x10aux::alloc_remote<x10::util::ArrayList__It<FMGL(S)> >()) x10::util::ArrayList__It<FMGL(S)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_UTIL_ARRAYLIST__IT_H_GENERICS
#ifndef X10_UTIL_ARRAYLIST__IT_H_IMPLEMENTATION
#define X10_UTIL_ARRAYLIST__IT_H_IMPLEMENTATION
#include <x10/util/ArrayList__It.h>


#include "x10/util/ArrayList__It.inc"

template<class FMGL(S)> typename x10::util::ListIterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> >  x10::util::ArrayList__It<FMGL(S)>::_itable_0(&x10::util::ArrayList__It<FMGL(S)>::add, &x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::equals, &x10::util::ArrayList__It<FMGL(S)>::hasNext, &x10::util::ArrayList__It<FMGL(S)>::hasPrevious, &x10::util::ArrayList__It<FMGL(S)>::hashCode, &x10::util::ArrayList__It<FMGL(S)>::home, &x10::util::ArrayList__It<FMGL(S)>::next, &x10::util::ArrayList__It<FMGL(S)>::nextIndex, &x10::util::ArrayList__It<FMGL(S)>::previous, &x10::util::ArrayList__It<FMGL(S)>::previousIndex, &x10::util::ArrayList__It<FMGL(S)>::remove, &x10::util::ArrayList__It<FMGL(S)>::set, &x10::util::ArrayList__It<FMGL(S)>::toString, &x10::util::ArrayList__It<FMGL(S)>::typeName);
template<class FMGL(S)> x10::lang::Any::itable<x10::util::ArrayList__It<FMGL(S)> >  x10::util::ArrayList__It<FMGL(S)>::_itable_1(&x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::equals, &x10::util::ArrayList__It<FMGL(S)>::hashCode, &x10::util::ArrayList__It<FMGL(S)>::home, &x10::util::ArrayList__It<FMGL(S)>::toString, &x10::util::ArrayList__It<FMGL(S)>::typeName);
template<class FMGL(S)> typename x10::util::CollectionIterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> >  x10::util::ArrayList__It<FMGL(S)>::_itable_2(&x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::equals, &x10::util::ArrayList__It<FMGL(S)>::hasNext, &x10::util::ArrayList__It<FMGL(S)>::hashCode, &x10::util::ArrayList__It<FMGL(S)>::home, &x10::util::ArrayList__It<FMGL(S)>::next, &x10::util::ArrayList__It<FMGL(S)>::remove, &x10::util::ArrayList__It<FMGL(S)>::toString, &x10::util::ArrayList__It<FMGL(S)>::typeName);
template<class FMGL(S)> typename x10::lang::Iterator<FMGL(S)>::template itable<x10::util::ArrayList__It<FMGL(S)> >  x10::util::ArrayList__It<FMGL(S)>::_itable_3(&x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::at, &x10::util::ArrayList__It<FMGL(S)>::equals, &x10::util::ArrayList__It<FMGL(S)>::hasNext, &x10::util::ArrayList__It<FMGL(S)>::hashCode, &x10::util::ArrayList__It<FMGL(S)>::home, &x10::util::ArrayList__It<FMGL(S)>::next, &x10::util::ArrayList__It<FMGL(S)>::toString, &x10::util::ArrayList__It<FMGL(S)>::typeName);
template<class FMGL(S)> x10aux::itable_entry x10::util::ArrayList__It<FMGL(S)>::_itables[5] = {x10aux::itable_entry(&x10aux::getRTT<x10::util::ListIterator<FMGL(S)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::util::CollectionIterator<FMGL(S)> >, &_itable_2), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<FMGL(S)> >, &_itable_3), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::ArrayList__It<FMGL(S)> >())};
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_instance_init() {
    _I_("Doing initialisation for class: x10::util::ArrayList__It<FMGL(S)>");
    
}


//#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10FieldDecl_c

//#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10FieldDecl_c

//#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_constructor(
                          x10aux::ref<x10::util::ArrayList<FMGL(S)> > al)
{
    this->_constructor(
      al,
      ((x10_int)-1));
    
}
template<class FMGL(S)>
x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x10::util::ArrayList__It<FMGL(S)>::_make(
  x10aux::ref<x10::util::ArrayList<FMGL(S)> > al)
{
    x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > this_ = new (memset(x10aux::alloc<x10::util::ArrayList__It<FMGL(S)> >(), 0, sizeof(x10::util::ArrayList__It<FMGL(S)>))) x10::util::ArrayList__It<FMGL(S)>();
    this_->_constructor(al);
    return this_;
}



//#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_constructor(
                          x10aux::ref<x10::util::ArrayList<FMGL(S)> > al,
                          x10_int i) {
    this->x10::lang::Object::_constructor();
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this))->
      FMGL(i) = ((x10_int)0);
    
    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this))->
      FMGL(al) = al;
    
    //#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this))->
      FMGL(i) = i;
    
}
template<class FMGL(S)> x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x10::util::ArrayList__It<FMGL(S)>::_make(
                          x10aux::ref<x10::util::ArrayList<FMGL(S)> > al,
                          x10_int i) {
    x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > this_ = new (memset(x10aux::alloc<x10::util::ArrayList__It<FMGL(S)> >(), 0, sizeof(x10::util::ArrayList__It<FMGL(S)>))) x10::util::ArrayList__It<FMGL(S)>();
    this_->_constructor(al, i);
    return this_;
}



//#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> x10_boolean x10::util::ArrayList__It<FMGL(S)>::hasNext(
  ) {
    
    //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((((x10_int) ((((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                            FMGL(i)) + (((x10_int)1))))) < (x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                                                                                FMGL(al))->size()));
    
}

//#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> x10_int x10::util::ArrayList__It<FMGL(S)>::nextIndex(
  ) {
    
    //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x =
          ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(i) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(i)) + (y)));
    }))
    ;
    
}

//#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> FMGL(S) x10::util::ArrayList__It<FMGL(S)>::next(
  ) {
    
    //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                                FMGL(al))->
              FMGL(a))->apply((__extension__ ({
        x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x =
          ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(i) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(i)) + (y)));
    }))
    );
    
}

//#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> x10_boolean x10::util::ArrayList__It<FMGL(S)>::hasPrevious(
  ) {
    
    //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return ((((x10_int) ((((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                            FMGL(i)) - (((x10_int)1))))) >= (((x10_int)0)));
    
}

//#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> x10_int x10::util::ArrayList__It<FMGL(S)>::previousIndex(
  ) {
    
    //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x =
          ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(i) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(i)) - (y)));
    }))
    ;
    
}

//#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> FMGL(S) x10::util::ArrayList__It<FMGL(S)>::previous(
  ) {
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10Return_c
    return (x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                                FMGL(al))->
              FMGL(a))->apply((__extension__ ({
        x10aux::ref<x10::util::ArrayList__It<FMGL(S)> > x =
          ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this);
        x10_int y =
          ((x10_int)1);
        x10aux::nullCheck(x)->
          FMGL(i) =
          ((x10_int) ((x10aux::nullCheck(x)->
                         FMGL(i)) - (y)));
    }))
    );
    
}

//#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::remove(
  ) {
    
    //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                        FMGL(al))->removeAt(
      ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
        FMGL(i));
}

//#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::set(
  FMGL(S) v) {
    
    //#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                        FMGL(al))->set(v,
                                       ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                                         FMGL(i));
}

//#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": x10.ast.X10MethodDecl_c
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::add(
  FMGL(S) v) {
    
    //#line 195 "/home/tux/workspace/x10.runtime/src-x10/x10/util/ArrayList.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
                        FMGL(al))->addBefore(
      ((x10aux::ref<x10::util::ArrayList__It<FMGL(S)> >)this)->
        FMGL(i),
      v);
}
template<class FMGL(S)> const x10aux::serialization_id_t x10::util::ArrayList__It<FMGL(S)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::ArrayList__It<FMGL(S)>::template _deserializer<x10::lang::Object>);

template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(S)> x10aux::RuntimeType x10::util::ArrayList__It<FMGL(S)>::rtt;
template<class FMGL(S)> void x10::util::ArrayList__It<FMGL(S)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::util::ArrayList__It<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::util::ListIterator<FMGL(S)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(S)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.util.ArrayList$It";
    rtt.initStageTwo(baseName, 2, parents, 1, params, variances);
}
#endif // X10_UTIL_ARRAYLIST__IT_H_IMPLEMENTATION
#endif // __X10_UTIL_ARRAYLIST__IT_H_NODEPS
