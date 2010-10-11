#include <x10/array/EmptyRegion__ERIterator.h>


#include "x10/array/EmptyRegion__ERIterator.inc"


//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.PropertyDecl_c
x10::lang::Iterator<x10aux::ref<x10::array::Point> >::itable<x10::array::EmptyRegion__ERIterator >  x10::array::EmptyRegion__ERIterator::_itable_0(&x10::array::EmptyRegion__ERIterator::at, &x10::array::EmptyRegion__ERIterator::at, &x10::array::EmptyRegion__ERIterator::equals, &x10::array::EmptyRegion__ERIterator::hasNext, &x10::array::EmptyRegion__ERIterator::hashCode, &x10::array::EmptyRegion__ERIterator::home, &x10::array::EmptyRegion__ERIterator::next, &x10::array::EmptyRegion__ERIterator::toString, &x10::array::EmptyRegion__ERIterator::typeName);
x10::lang::Any::itable<x10::array::EmptyRegion__ERIterator >  x10::array::EmptyRegion__ERIterator::_itable_1(&x10::array::EmptyRegion__ERIterator::at, &x10::array::EmptyRegion__ERIterator::at, &x10::array::EmptyRegion__ERIterator::equals, &x10::array::EmptyRegion__ERIterator::hashCode, &x10::array::EmptyRegion__ERIterator::home, &x10::array::EmptyRegion__ERIterator::toString, &x10::array::EmptyRegion__ERIterator::typeName);
x10aux::itable_entry x10::array::EmptyRegion__ERIterator::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::EmptyRegion__ERIterator>())};
void x10::array::EmptyRegion__ERIterator::_instance_init() {
    _I_("Doing initialisation for class: x10::array::EmptyRegion__ERIterator");
    
}


//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::EmptyRegion__ERIterator::_constructor(x10_int r) {
    this->x10::lang::Object::_constructor();
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::EmptyRegion__ERIterator>)this)->FMGL(myRank) =
      r;
    
}
x10aux::ref<x10::array::EmptyRegion__ERIterator> x10::array::EmptyRegion__ERIterator::_make(
  x10_int r) {
    x10aux::ref<x10::array::EmptyRegion__ERIterator> this_ = new (memset(x10aux::alloc<x10::array::EmptyRegion__ERIterator>(), 0, sizeof(x10::array::EmptyRegion__ERIterator))) x10::array::EmptyRegion__ERIterator();
    this_->_constructor(r);
    return this_;
}



//#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::EmptyRegion__ERIterator::hasNext() {
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::EmptyRegion__ERIterator::next(
  ) {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::util::NoSuchElementException::_make()));
}

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::EmptyRegion__ERIterator::myRank() {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::EmptyRegion__ERIterator>)this)->
             FMGL(myRank);
    
}
const x10aux::serialization_id_t x10::array::EmptyRegion__ERIterator::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::EmptyRegion__ERIterator::_deserializer<x10::lang::Object>);

void x10::array::EmptyRegion__ERIterator::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(myRank));
    
}

void x10::array::EmptyRegion__ERIterator::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(myRank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::EmptyRegion__ERIterator::rtt;
void x10::array::EmptyRegion__ERIterator::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.EmptyRegion$ERIterator", 2, parents, 0, NULL, NULL);
}
