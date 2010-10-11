#include <x10/array/VarMat.h>


#include "x10/array/VarMat.inc"

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> >::itable<x10::array::VarMat >  x10::array::VarMat::_itable_0(&x10::array::VarMat::apply, &x10::array::VarMat::at, &x10::array::VarMat::at, &x10::array::VarMat::equals, &x10::array::VarMat::hashCode, &x10::array::VarMat::home, &x10::array::VarMat::toString, &x10::array::VarMat::typeName);
x10::lang::Any::itable<x10::array::VarMat >  x10::array::VarMat::_itable_1(&x10::array::VarMat::at, &x10::array::VarMat::at, &x10::array::VarMat::equals, &x10::array::VarMat::hashCode, &x10::array::VarMat::home, &x10::array::VarMat::toString, &x10::array::VarMat::typeName);
x10::lang::Iterable<x10aux::ref<x10::array::VarRow> >::itable<x10::array::VarMat >  x10::array::VarMat::_itable_2(&x10::array::VarMat::at, &x10::array::VarMat::at, &x10::array::VarMat::equals, &x10::array::VarMat::hashCode, &x10::array::VarMat::home, &x10::array::VarMat::iterator, &x10::array::VarMat::toString, &x10::array::VarMat::typeName);
x10aux::itable_entry x10::array::VarMat::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::VarRow> > >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::VarMat>())};
void x10::array::VarMat::_instance_init() {
    _I_("Doing initialisation for class: x10::array::VarMat");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarMat.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarMat::_constructor(x10_int cols, x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::VarRow> > > mat)
{
    this->x10::array::Mat<x10aux::ref<x10::array::VarRow> >::_constructor(
      x10aux::nullCheck(mat)->
        FMGL(length),
      cols,
      mat);
    
}
x10aux::ref<x10::array::VarMat> x10::array::VarMat::_make(
  x10_int cols,
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::VarRow> > > mat)
{
    x10aux::ref<x10::array::VarMat> this_ = new (memset(x10aux::alloc<x10::array::VarMat>(), 0, sizeof(x10::array::VarMat))) x10::array::VarMat();
    this_->_constructor(cols,
    mat);
    return this_;
}



//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarMat.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarMat::_constructor(x10_int rows, x10_int cols,
                                      x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > init)
{
    this->x10::array::Mat<x10aux::ref<x10::array::VarRow> >::_constructor(
      rows,
      cols,
      x10::lang::ValRail<x10aux::ref<x10::array::VarRow> >::make(rows, init));
    
}
x10aux::ref<x10::array::VarMat> x10::array::VarMat::_make(
  x10_int rows,
  x10_int cols,
  x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > init)
{
    x10aux::ref<x10::array::VarMat> this_ = new (memset(x10aux::alloc<x10::array::VarMat>(), 0, sizeof(x10::array::VarMat))) x10::array::VarMat();
    this_->_constructor(rows,
    cols,
    init);
    return this_;
}



//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarMat.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarMat::_constructor(x10_int rows,
                                      x10_int cols,
                                      x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init)
{
    this->_constructor(
      rows,
      cols,
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >(x10aux::ref<x10_array_VarMat__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >(sizeof(x10_array_VarMat__closure__0)))x10_array_VarMat__closure__0(cols, init)))));
    
}
x10aux::ref<x10::array::VarMat> x10::array::VarMat::_make(
  x10_int rows,
  x10_int cols,
  x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init)
{
    x10aux::ref<x10::array::VarMat> this_ = new (memset(x10aux::alloc<x10::array::VarMat>(), 0, sizeof(x10::array::VarMat))) x10::array::VarMat();
    this_->_constructor(rows,
    cols,
    init);
    return this_;
}



//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarMat.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarMat::_constructor(x10_int rows,
                                      x10_int cols)
{
    this->_constructor(
      rows,
      cols,
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >(x10aux::ref<x10_array_VarMat__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >(sizeof(x10_array_VarMat__closure__2)))x10_array_VarMat__closure__2(cols)))));
    
}
x10aux::ref<x10::array::VarMat> x10::array::VarMat::_make(
  x10_int rows,
  x10_int cols)
{
    x10aux::ref<x10::array::VarMat> this_ = new (memset(x10aux::alloc<x10::array::VarMat>(), 0, sizeof(x10::array::VarMat))) x10::array::VarMat();
    this_->_constructor(rows,
    cols);
    return this_;
}


const x10aux::serialization_id_t x10::array::VarMat::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::VarMat::_deserializer<x10::lang::Object>);

void x10::array::VarMat::_serialize(x10aux::ref<x10::array::VarMat> this_,
                                    x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::VarMat::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Mat<x10aux::ref<x10::array::VarRow> >::_serialize_body(buf);
    
}

void x10::array::VarMat::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Mat<x10aux::ref<x10::array::VarRow> >::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::array::VarMat::rtt;
void x10::array::VarMat::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Mat<x10aux::ref<x10::array::VarRow> > >()};
    rtt.initStageTwo("x10.array.VarMat", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> >::itable<x10_array_VarMat__closure__0>x10_array_VarMat__closure__0::_itable(&x10_array_VarMat__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_VarMat__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_VarMat__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >, &x10_array_VarMat__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_VarMat__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_VarMat__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_VarMat__closure__1>x10_array_VarMat__closure__1::_itable(&x10_array_VarMat__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_VarMat__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_VarMat__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_VarMat__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_VarMat__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_VarMat__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> >::itable<x10_array_VarMat__closure__2>x10_array_VarMat__closure__2::_itable(&x10_array_VarMat__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_VarMat__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_VarMat__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > >, &x10_array_VarMat__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_VarMat__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_VarMat__closure__2::_deserialize<x10::lang::Object>);

