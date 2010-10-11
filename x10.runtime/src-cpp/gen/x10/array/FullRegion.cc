#include <x10/array/FullRegion.h>


#include "x10/array/FullRegion.inc"

x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::FullRegion >  x10::array::FullRegion::_itable_0(&x10::array::FullRegion::at, &x10::array::FullRegion::at, &x10::array::FullRegion::equals, &x10::array::FullRegion::hashCode, &x10::array::FullRegion::home, &x10::array::FullRegion::iterator, &x10::array::FullRegion::toString, &x10::array::FullRegion::typeName);
x10::lang::Any::itable<x10::array::FullRegion >  x10::array::FullRegion::_itable_1(&x10::array::FullRegion::at, &x10::array::FullRegion::at, &x10::array::FullRegion::equals, &x10::array::FullRegion::hashCode, &x10::array::FullRegion::home, &x10::array::FullRegion::toString, &x10::array::FullRegion::typeName);
x10aux::itable_entry x10::array::FullRegion::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::FullRegion>())};
void x10::array::FullRegion::_instance_init() {
    _I_("Doing initialisation for class: x10::array::FullRegion");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::FullRegion::_constructor(x10_int rank) {
    this->x10::array::Region::_constructor(rank, true, false);
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10If_c
    if (((rank) < (((x10_int)0)))) {
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalArgumentException::_make(((((x10::lang::String::Lit("Rank is negative (")) + (rank))) + (x10::lang::String::Lit(")"))))));
    }
    
}
x10aux::ref<x10::array::FullRegion> x10::array::FullRegion::_make(x10_int rank)
{
    x10aux::ref<x10::array::FullRegion> this_ = new (memset(x10aux::alloc<x10::array::FullRegion>(), 0, sizeof(x10::array::FullRegion))) x10::array::FullRegion();
    this_->_constructor(rank);
    return this_;
}



//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::FullRegion::isConvex() {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::FullRegion::isEmpty() {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::FullRegion::size() {
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("Full Region is infinite; size not supported"))));
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::array::FullRegion::min() {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::FullRegion>)this)->
                                                FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_FullRegion__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_FullRegion__closure__0)))x10_array_FullRegion__closure__0()))));
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::array::FullRegion::max(
  ) {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::FullRegion>)this)->
                                                FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_FullRegion__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_FullRegion__closure__1)))x10_array_FullRegion__closure__1()))));
    
}

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::intersection(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return that;
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::product(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(that)->isEmpty()) {
        
        //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return x10::array::Region::makeEmpty(((x10_int) ((((x10aux::ref<x10::array::FullRegion>)this)->
                                                            FMGL(rank)) + (x10aux::nullCheck(that)->
                                                                             FMGL(rank)))));
        
    } else 
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::FullRegion> >(that))
    {
        
        //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::FullRegion::_make(((x10_int) ((((x10aux::ref<x10::array::FullRegion>)this)->
                                                                                                                           FMGL(rank)) + (x10aux::nullCheck(that)->
                                                                                                                                            FMGL(rank))))));
        
    }
    else
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::RectRegion> >(that))
    {
        
        //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMin =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::min();
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMax =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::max();
        
        //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10LocalDecl_c
        x10_int newRank =
          ((x10_int) ((((x10aux::ref<x10::array::FullRegion>)this)->
                         FMGL(rank)) + (x10aux::nullCheck(that)->
                                          FMGL(rank))));
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
          x10::lang::ValRail<x10_int >::make(newRank, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_FullRegion__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_FullRegion__closure__2)))x10_array_FullRegion__closure__2(this, thatMin)))));
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
          x10::lang::ValRail<x10_int >::make(newRank, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_FullRegion__closure__3>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_FullRegion__closure__3)))x10_array_FullRegion__closure__3(this, thatMax)))));
        
        //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
        return x10::array::Region::makeRectangular(
                 newMin,
                 newMax);
        
    }
    else
    {
        
        //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(((x10::lang::String::Lit("haven\'t implemented FullRegion product with ")) + (x10aux::type_name(that))))));
    }
    
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::projection(
  x10_int axis) {
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::FullRegion::_make(((x10_int)1)));
    
}

//#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::translate(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::FullRegion>)this));
    
}

//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::eliminate(
  x10_int i) {
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10::array::FullRegion::_make(((x10_int) ((((x10aux::ref<x10::array::FullRegion>)this)->
                                                        FMGL(rank)) - (((x10_int)1)))));
    
}

//#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::FullRegion::computeBoundingBox(
  ) {
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::FullRegion>)this));
    
}

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::FullRegion::contains(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::FullRegion::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::FullRegion::toString(
  ) {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10Return_c
    return ((((x10::lang::String::Lit("full(")) + (((x10aux::ref<x10::array::FullRegion>)this)->
                                                     FMGL(rank)))) + (x10::lang::String::Lit(")")));
    
}

//#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >
  x10::array::FullRegion::scanners(
  ) {
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("Full Region is infinite: scanning is not supported"))));
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::FullRegion::iterator(
  ) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/FullRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("Full Region is infinite: iteration is not supported"))));
}
x10_int x10::array::FullRegion::min(x10_int p0) {
    return x10::array::Region::min(p0);
}
x10_int x10::array::FullRegion::max(x10_int p0) {
    return x10::array::Region::max(p0);
}
x10_boolean x10::array::FullRegion::contains(x10_int p0) {
    return x10::array::Region::contains(p0);
}
x10_boolean x10::array::FullRegion::contains(x10_int p0, x10_int p1) {
    return x10::array::Region::contains(p0, p1);
}
x10_boolean x10::array::FullRegion::contains(x10_int p0, x10_int p1, x10_int p2) {
    return x10::array::Region::contains(p0, p1, p2);
}
x10_boolean x10::array::FullRegion::contains(x10_int p0, x10_int p1, x10_int p2, x10_int p3) {
    return x10::array::Region::contains(p0, p1, p2, p3);
}
const x10aux::serialization_id_t x10::array::FullRegion::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::FullRegion::_deserializer<x10::lang::Object>);

void x10::array::FullRegion::_serialize(x10aux::ref<x10::array::FullRegion> this_,
                                        x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::FullRegion::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Region::_serialize_body(buf);
    
}

void x10::array::FullRegion::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Region::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::array::FullRegion::rtt;
void x10::array::FullRegion::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Region>()};
    rtt.initStageTwo("x10.array.FullRegion", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__0>x10_array_FullRegion__closure__0::_itable(&x10_array_FullRegion__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_FullRegion__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_FullRegion__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_FullRegion__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_FullRegion__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_FullRegion__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__1>x10_array_FullRegion__closure__1::_itable(&x10_array_FullRegion__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_FullRegion__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_FullRegion__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_FullRegion__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_FullRegion__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_FullRegion__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__2>x10_array_FullRegion__closure__2::_itable(&x10_array_FullRegion__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_FullRegion__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_FullRegion__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_FullRegion__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_FullRegion__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_FullRegion__closure__2::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_FullRegion__closure__3>x10_array_FullRegion__closure__3::_itable(&x10_array_FullRegion__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_FullRegion__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_FullRegion__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_FullRegion__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_FullRegion__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_FullRegion__closure__3::_deserialize<x10::lang::Object>);

