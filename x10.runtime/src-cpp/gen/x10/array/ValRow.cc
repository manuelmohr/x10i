#include <x10/array/ValRow.h>


#include "x10/array/ValRow.inc"

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10::array::ValRow >  x10::array::ValRow::_itable_0(&x10::array::ValRow::apply, &x10::array::ValRow::at, &x10::array::ValRow::at, &x10::array::ValRow::equals, &x10::array::ValRow::hashCode, &x10::array::ValRow::home, &x10::array::ValRow::toString, &x10::array::ValRow::typeName);
x10::lang::Any::itable<x10::array::ValRow >  x10::array::ValRow::_itable_1(&x10::array::ValRow::at, &x10::array::ValRow::at, &x10::array::ValRow::equals, &x10::array::ValRow::hashCode, &x10::array::ValRow::home, &x10::array::ValRow::toString, &x10::array::ValRow::typeName);
x10aux::itable_entry x10::array::ValRow::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::ValRow>())};
void x10::array::ValRow::_instance_init() {
    _I_("Doing initialisation for class: x10::array::ValRow");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10FieldDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::ValRow::_constructor(x10aux::ref<x10::lang::ValRail<x10_int > > row)
{
    this->x10::array::Row::_constructor(
      x10aux::nullCheck(row)->
        FMGL(length));
    
    //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::ValRow>)this)->
      FMGL(row) =
      row;
    
}
x10aux::ref<x10::array::ValRow> x10::array::ValRow::_make(
  x10aux::ref<x10::lang::ValRail<x10_int > > row)
{
    x10aux::ref<x10::array::ValRow> this_ = new (memset(x10aux::alloc<x10::array::ValRow>(), 0, sizeof(x10::array::ValRow))) x10::array::ValRow();
    this_->_constructor(row);
    return this_;
}



//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::ValRow::_constructor(x10aux::ref<x10::lang::Rail<x10_int > > row)
{
    this->_constructor(
      x10aux::nullCheck(row)->
        FMGL(length),
      x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_ValRow__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_ValRow__closure__0)))x10_array_ValRow__closure__0(row))));
    
}
x10aux::ref<x10::array::ValRow> x10::array::ValRow::_make(
  x10aux::ref<x10::lang::Rail<x10_int > > row)
{
    x10aux::ref<x10::array::ValRow> this_ = new (memset(x10aux::alloc<x10::array::ValRow>(), 0, sizeof(x10::array::ValRow))) x10::array::ValRow();
    this_->_constructor(row);
    return this_;
}



//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::ValRow::_constructor(x10_int cols, x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    this->x10::array::Row::_constructor(
      cols);
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::ValRow>)this)->
      FMGL(row) =
      x10::lang::ValRail<x10_int >::make(cols, init);
    
}
x10aux::ref<x10::array::ValRow> x10::array::ValRow::_make(
  x10_int cols,
  x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    x10aux::ref<x10::array::ValRow> this_ = new (memset(x10aux::alloc<x10::array::ValRow>(), 0, sizeof(x10::array::ValRow))) x10::array::ValRow();
    this_->_constructor(cols,
    init);
    return this_;
}



//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::ValRow::apply(x10_int i) {
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::ValRow>)this)->
              FMGL(row))->apply(i);
    
}

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::ValRow::set(x10_int v, x10_int i) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/ValRow.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("ValRow.set"))));
}
const x10aux::serialization_id_t x10::array::ValRow::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::ValRow::_deserializer<x10::lang::Object>);

void x10::array::ValRow::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Row::_serialize_body(buf);
    buf.write(this->FMGL(row));
    
}

void x10::array::ValRow::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Row::_deserialize_body(buf);
    FMGL(row) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
}

x10aux::RuntimeType x10::array::ValRow::rtt;
void x10::array::ValRow::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Row>()};
    rtt.initStageTwo("x10.array.ValRow", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_ValRow__closure__0>x10_array_ValRow__closure__0::_itable(&x10_array_ValRow__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_ValRow__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_ValRow__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_ValRow__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_ValRow__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_ValRow__closure__0::_deserialize<x10::lang::Object>);

