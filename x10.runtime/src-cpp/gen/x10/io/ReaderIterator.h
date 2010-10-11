#ifndef __X10_IO_READERITERATOR_H
#define __X10_IO_READERITERATOR_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
#define X10_LANG_ITERABLE_H_NODEPS
#include <x10/lang/Iterable.h>
#undef X10_LANG_ITERABLE_H_NODEPS
namespace x10 { namespace io { 
class Reader;
} } 
namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 
namespace x10 { namespace util { 
template<class FMGL(T)> class Box;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
class NoSuchElementException;
} } 
namespace x10 { namespace io { 
class IOException;
} } 
namespace x10 { namespace io { 

template<class FMGL(T)> class ReaderIterator;
template <> class ReaderIterator<void>;
template<class FMGL(T)> class ReaderIterator : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[4];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static typename x10::lang::Iterator<FMGL(T)>::template itable<x10::io::ReaderIterator<FMGL(T)> > _itable_0;
    
    static x10::lang::Any::itable<x10::io::ReaderIterator<FMGL(T)> > _itable_1;
    
    static typename x10::lang::Iterable<FMGL(T)>::template itable<x10::io::ReaderIterator<FMGL(T)> > _itable_2;
    
    void _instance_init();
    
    x10aux::ref<x10::io::Reader> FMGL(r);
    
    x10aux::ref<x10::io::Marshal<FMGL(T)> > FMGL(m);
    
    x10aux::ref<x10::util::Box<FMGL(T)> > FMGL(next);
    
    void _constructor(x10aux::ref<x10::io::Marshal<FMGL(T)> > m, x10aux::ref<x10::io::Reader> r);
    
    static x10aux::ref<x10::io::ReaderIterator<FMGL(T)> > _make(x10aux::ref<x10::io::Marshal<FMGL(T)> > m,
                                                                x10aux::ref<x10::io::Reader> r);
    
    virtual x10aux::ref<x10::lang::Iterator<FMGL(T)> > iterator();
    virtual FMGL(T) next();
    virtual x10_boolean hasNext();
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class ReaderIterator<void> : public x10::lang::Object
{
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_IO_READERITERATOR_H

namespace x10 { namespace io { 
template<class FMGL(T)>
class ReaderIterator;
} } 

#ifndef X10_IO_READERITERATOR_H_NODEPS
#define X10_IO_READERITERATOR_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Iterable.h>
#include <x10/io/Reader.h>
#include <x10/io/Marshal.h>
#include <x10/util/Box.h>
#include <x10/lang/Boolean.h>
#include <x10/util/NoSuchElementException.h>
#include <x10/io/IOException.h>
#ifndef X10_IO_READERITERATOR_H_GENERICS
#define X10_IO_READERITERATOR_H_GENERICS
template<class FMGL(T)> template<class __T> x10aux::ref<__T> x10::io::ReaderIterator<FMGL(T)>::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::io::ReaderIterator<FMGL(T)> > this_ = new (x10aux::alloc_remote<x10::io::ReaderIterator<FMGL(T)> >()) x10::io::ReaderIterator<FMGL(T)>();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_IO_READERITERATOR_H_GENERICS
#ifndef X10_IO_READERITERATOR_H_IMPLEMENTATION
#define X10_IO_READERITERATOR_H_IMPLEMENTATION
#include <x10/io/ReaderIterator.h>


#include "x10/io/ReaderIterator.inc"

template<class FMGL(T)> typename x10::lang::Iterator<FMGL(T)>::template itable<x10::io::ReaderIterator<FMGL(T)> >  x10::io::ReaderIterator<FMGL(T)>::_itable_0(&x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::equals, &x10::io::ReaderIterator<FMGL(T)>::hasNext, &x10::io::ReaderIterator<FMGL(T)>::hashCode, &x10::io::ReaderIterator<FMGL(T)>::home, &x10::io::ReaderIterator<FMGL(T)>::next, &x10::io::ReaderIterator<FMGL(T)>::toString, &x10::io::ReaderIterator<FMGL(T)>::typeName);
template<class FMGL(T)> x10::lang::Any::itable<x10::io::ReaderIterator<FMGL(T)> >  x10::io::ReaderIterator<FMGL(T)>::_itable_1(&x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::equals, &x10::io::ReaderIterator<FMGL(T)>::hashCode, &x10::io::ReaderIterator<FMGL(T)>::home, &x10::io::ReaderIterator<FMGL(T)>::toString, &x10::io::ReaderIterator<FMGL(T)>::typeName);
template<class FMGL(T)> typename x10::lang::Iterable<FMGL(T)>::template itable<x10::io::ReaderIterator<FMGL(T)> >  x10::io::ReaderIterator<FMGL(T)>::_itable_2(&x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::at, &x10::io::ReaderIterator<FMGL(T)>::equals, &x10::io::ReaderIterator<FMGL(T)>::hashCode, &x10::io::ReaderIterator<FMGL(T)>::home, &x10::io::ReaderIterator<FMGL(T)>::iterator, &x10::io::ReaderIterator<FMGL(T)>::toString, &x10::io::ReaderIterator<FMGL(T)>::typeName);
template<class FMGL(T)> x10aux::itable_entry x10::io::ReaderIterator<FMGL(T)>::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<FMGL(T)> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::ReaderIterator<FMGL(T)> >())};
template<class FMGL(T)> void x10::io::ReaderIterator<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::io::ReaderIterator<FMGL(T)>");
    
}


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10FieldDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10FieldDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10FieldDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::io::ReaderIterator<FMGL(T)>::_constructor(
                          x10aux::ref<x10::io::Marshal<FMGL(T)> > m,
                          x10aux::ref<x10::io::Reader> r) {
    this->x10::lang::Object::_constructor();
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this))->
      FMGL(next) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(T)> > >(x10aux::null);
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this))->
      FMGL(m) = m;
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this))->
      FMGL(r) = r;
    
}
template<class FMGL(T)> x10aux::ref<x10::io::ReaderIterator<FMGL(T)> > x10::io::ReaderIterator<FMGL(T)>::_make(
                          x10aux::ref<x10::io::Marshal<FMGL(T)> > m,
                          x10aux::ref<x10::io::Reader> r) {
    x10aux::ref<x10::io::ReaderIterator<FMGL(T)> > this_ = new (memset(x10aux::alloc<x10::io::ReaderIterator<FMGL(T)> >(), 0, sizeof(x10::io::ReaderIterator<FMGL(T)>))) x10::io::ReaderIterator<FMGL(T)>();
    this_->_constructor(m, r);
    return this_;
}



//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Iterator<FMGL(T)> >
  x10::io::ReaderIterator<FMGL(T)>::iterator(
  ) {
    
    //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<FMGL(T)> > >(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this));
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::io::ReaderIterator<FMGL(T)>::next(
  ) {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10If_c
    if ((!(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->hasNext())))
    {
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::util::NoSuchElementException::_make()));
    }
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10LocalDecl_c
    FMGL(T) x = x10aux::nullCheck(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
                                    FMGL(next))->FMGL(value);
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
      FMGL(next) = x10aux::class_cast_unchecked<x10aux::ref<x10::util::Box<FMGL(T)> > >(x10aux::null);
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10Return_c
    return x;
    
}

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_boolean x10::io::ReaderIterator<FMGL(T)>::hasNext(
  ) {
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
                                 FMGL(next), x10aux::null)))
    {
        
        //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Try_c
        try {
            
            //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10LocalDecl_c
            FMGL(T) x =
              x10aux::nullCheck(((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
                                  FMGL(r))->x10::io::Reader::template read<FMGL(T) >(
                ((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
                  FMGL(m));
            
            //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::io::ReaderIterator<FMGL(T)> >)this)->
              FMGL(next) =
              x10::util::Box<FMGL(T)>::_make(x);
        }
        catch (x10aux::__ref& __ref__643) {
            x10aux::ref<x10::lang::Throwable>& __exc__ref__643 = (x10aux::ref<x10::lang::Throwable>&)__ref__643;
            if (x10aux::instanceof<x10aux::ref<x10::io::IOException> >(__exc__ref__643)) {
                x10aux::ref<x10::io::IOException> id__89 =
                  static_cast<x10aux::ref<x10::io::IOException> >(__exc__ref__643);
                {
                    
                    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10Return_c
                    return false;
                    
                }
            } else
            throw;
        }
    }
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ReaderIterator.x10": x10.ast.X10Return_c
    return true;
    
}
template<class FMGL(T)> const x10aux::serialization_id_t x10::io::ReaderIterator<FMGL(T)>::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::ReaderIterator<FMGL(T)>::template _deserializer<x10::lang::Object>);

template<class FMGL(T)> void x10::io::ReaderIterator<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

template<class FMGL(T)> void x10::io::ReaderIterator<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

template<class FMGL(T)> x10aux::RuntimeType x10::io::ReaderIterator<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::io::ReaderIterator<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::io::ReaderIterator<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<FMGL(T)> >(), x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.io.ReaderIterator";
    rtt.initStageTwo(baseName, 3, parents, 1, params, variances);
}
#endif // X10_IO_READERITERATOR_H_IMPLEMENTATION
#endif // __X10_IO_READERITERATOR_H_NODEPS
