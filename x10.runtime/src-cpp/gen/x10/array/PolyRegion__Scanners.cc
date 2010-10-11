#include <x10/array/PolyRegion__Scanners.h>


#include "x10/array/PolyRegion__Scanners.inc"

x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> >::itable<x10::array::PolyRegion__Scanners >  x10::array::PolyRegion__Scanners::_itable_0(&x10::array::PolyRegion__Scanners::at, &x10::array::PolyRegion__Scanners::at, &x10::array::PolyRegion__Scanners::equals, &x10::array::PolyRegion__Scanners::hasNext, &x10::array::PolyRegion__Scanners::hashCode, &x10::array::PolyRegion__Scanners::home, &x10::array::PolyRegion__Scanners::next, &x10::array::PolyRegion__Scanners::toString, &x10::array::PolyRegion__Scanners::typeName);
x10::lang::Any::itable<x10::array::PolyRegion__Scanners >  x10::array::PolyRegion__Scanners::_itable_1(&x10::array::PolyRegion__Scanners::at, &x10::array::PolyRegion__Scanners::at, &x10::array::PolyRegion__Scanners::equals, &x10::array::PolyRegion__Scanners::hashCode, &x10::array::PolyRegion__Scanners::home, &x10::array::PolyRegion__Scanners::toString, &x10::array::PolyRegion__Scanners::typeName);
x10aux::itable_entry x10::array::PolyRegion__Scanners::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyRegion__Scanners>())};
void x10::array::PolyRegion__Scanners::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyRegion__Scanners");
    
}


//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10FieldDecl_c

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10FieldDecl_c

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRegion__Scanners::hasNext() {
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyRegion__Scanners>)this)->FMGL(hasNext);
    
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region__Scanner> x10::array::PolyRegion__Scanners::next(
  ) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::PolyRegion__Scanners>)this)->FMGL(hasNext))
    {
        
        //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::PolyRegion__Scanners>)this)->
          FMGL(hasNext) =
          false;
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion__Scanners>)this)->
                                   FMGL(out__))->scanner();
        
    }
    else
    {
        
        //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::util::NoSuchElementException::_make(x10::lang::String::Lit("in scanner"))));
    }
    
}

//#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyRegion__Scanners::remove() {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(x10::lang::String::Lit("remove"))));
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRegion__Scanners::_constructor(x10aux::ref<x10::array::PolyRegion> out__)
{
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyRegion__Scanners>)this)->
      FMGL(out__) =
      out__;
    this->x10::lang::Object::_constructor();
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyRegion__Scanners>)this))->
      FMGL(hasNext) =
      true;
    
}
x10aux::ref<x10::array::PolyRegion__Scanners> x10::array::PolyRegion__Scanners::_make(
  x10aux::ref<x10::array::PolyRegion> out__)
{
    x10aux::ref<x10::array::PolyRegion__Scanners> this_ = new (memset(x10aux::alloc<x10::array::PolyRegion__Scanners>(), 0, sizeof(x10::array::PolyRegion__Scanners))) x10::array::PolyRegion__Scanners();
    this_->_constructor(out__);
    return this_;
}


const x10aux::serialization_id_t x10::array::PolyRegion__Scanners::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyRegion__Scanners::_deserializer<x10::lang::Object>);

void x10::array::PolyRegion__Scanners::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(out__));
    
}

void x10::array::PolyRegion__Scanners::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(out__) = buf.read<x10aux::ref<x10::array::PolyRegion> >();
}

x10aux::RuntimeType x10::array::PolyRegion__Scanners::rtt;
void x10::array::PolyRegion__Scanners::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >()};
    rtt.initStageTwo("x10.array.PolyRegion$Scanners", 2, parents, 0, NULL, NULL);
}
