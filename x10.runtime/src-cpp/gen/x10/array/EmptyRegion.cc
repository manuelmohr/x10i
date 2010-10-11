#include <x10/array/EmptyRegion.h>


#include "x10/array/EmptyRegion.inc"

x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::EmptyRegion >  x10::array::EmptyRegion::_itable_0(&x10::array::EmptyRegion::at, &x10::array::EmptyRegion::at, &x10::array::EmptyRegion::equals, &x10::array::EmptyRegion::hashCode, &x10::array::EmptyRegion::home, &x10::array::EmptyRegion::iterator, &x10::array::EmptyRegion::toString, &x10::array::EmptyRegion::typeName);
x10::lang::Any::itable<x10::array::EmptyRegion >  x10::array::EmptyRegion::_itable_1(&x10::array::EmptyRegion::at, &x10::array::EmptyRegion::at, &x10::array::EmptyRegion::equals, &x10::array::EmptyRegion::hashCode, &x10::array::EmptyRegion::home, &x10::array::EmptyRegion::toString, &x10::array::EmptyRegion::typeName);
x10aux::itable_entry x10::array::EmptyRegion::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::EmptyRegion>())};
void x10::array::EmptyRegion::_instance_init() {
    _I_("Doing initialisation for class: x10::array::EmptyRegion");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::EmptyRegion::_constructor(x10_int rank) {
    this->x10::array::Region::_constructor(rank, true, false);
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10If_c
    if (((rank) < (((x10_int)0)))) {
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalArgumentException::_make(((((x10::lang::String::Lit("Rank is negative (")) + (rank))) + (x10::lang::String::Lit(")"))))));
    }
    
}
x10aux::ref<x10::array::EmptyRegion> x10::array::EmptyRegion::_make(x10_int rank)
{
    x10aux::ref<x10::array::EmptyRegion> this_ = new (memset(x10aux::alloc<x10::array::EmptyRegion>(), 0, sizeof(x10::array::EmptyRegion))) x10::array::EmptyRegion();
    this_->_constructor(rank);
    return this_;
}



//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::EmptyRegion::isConvex() {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::EmptyRegion::isEmpty() {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::EmptyRegion::size() {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return ((x10_int)0);
    
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::intersection(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::EmptyRegion>)this));
    
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::product(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::EmptyRegion::_make(((x10_int) ((((x10aux::ref<x10::array::EmptyRegion>)this)->
                                                                                                                        FMGL(rank)) + (x10aux::nullCheck(that)->
                                                                                                                                         FMGL(rank))))));
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::projection(
  x10_int axis) {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::EmptyRegion::_make(((x10_int)1)));
    
}

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::translate(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::EmptyRegion>)this));
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::eliminate(
  x10_int i) {
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10::array::EmptyRegion::_make(((x10_int) ((((x10aux::ref<x10::array::EmptyRegion>)this)->
                                                         FMGL(rank)) - (((x10_int)1)))));
    
}

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::EmptyRegion::computeBoundingBox(
  ) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("bounding box not not defined for empty region"))));
}

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::EmptyRegion::min(
  ) {
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("min not not defined for empty region"))));
}

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::EmptyRegion::max(
  ) {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("max not not defined for empty region"))));
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::EmptyRegion::contains(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(that)->isEmpty();
    
}

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::EmptyRegion::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::EmptyRegion::iterator(
  ) {
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > >(x10::array::EmptyRegion__ERIterator::_make(((x10aux::ref<x10::array::EmptyRegion>)this)->
                                                                                                                                                          FMGL(rank)));
    
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >
  x10::array::EmptyRegion::scanners(
  ) {
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(x10::lang::String::Lit("scanners not defined for empty region"))));
}

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::EmptyRegion::toString(
  ) {
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/EmptyRegion.x10": x10.ast.X10Return_c
    return ((((x10::lang::String::Lit("empty(")) + (((x10aux::ref<x10::array::EmptyRegion>)this)->
                                                      FMGL(rank)))) + (x10::lang::String::Lit(")")));
    
}
x10_int x10::array::EmptyRegion::min(x10_int p0) {
    return x10::array::Region::min(p0);
}
x10_int x10::array::EmptyRegion::max(x10_int p0) {
    return x10::array::Region::max(p0);
}
x10_boolean x10::array::EmptyRegion::contains(x10_int p0) {
    return x10::array::Region::contains(p0);
}
x10_boolean x10::array::EmptyRegion::contains(x10_int p0, x10_int p1) {
    return x10::array::Region::contains(p0, p1);
}
x10_boolean x10::array::EmptyRegion::contains(x10_int p0, x10_int p1, x10_int p2) {
    return x10::array::Region::contains(p0, p1, p2);
}
x10_boolean x10::array::EmptyRegion::contains(x10_int p0, x10_int p1, x10_int p2, x10_int p3) {
    return x10::array::Region::contains(p0, p1, p2, p3);
}
const x10aux::serialization_id_t x10::array::EmptyRegion::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::EmptyRegion::_deserializer<x10::lang::Object>);

void x10::array::EmptyRegion::_serialize(x10aux::ref<x10::array::EmptyRegion> this_,
                                         x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::EmptyRegion::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Region::_serialize_body(buf);
    
}

void x10::array::EmptyRegion::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Region::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::array::EmptyRegion::rtt;
void x10::array::EmptyRegion::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Region>()};
    rtt.initStageTwo("x10.array.EmptyRegion", 1, parents, 0, NULL, NULL);
}
