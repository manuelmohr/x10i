#include <x10/array/VarRow.h>


#include "x10/array/VarRow.inc"

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10::array::VarRow >  x10::array::VarRow::_itable_0(&x10::array::VarRow::apply, &x10::array::VarRow::at, &x10::array::VarRow::at, &x10::array::VarRow::equals, &x10::array::VarRow::hashCode, &x10::array::VarRow::home, &x10::array::VarRow::toString, &x10::array::VarRow::typeName);
x10::lang::Any::itable<x10::array::VarRow >  x10::array::VarRow::_itable_1(&x10::array::VarRow::at, &x10::array::VarRow::at, &x10::array::VarRow::equals, &x10::array::VarRow::hashCode, &x10::array::VarRow::home, &x10::array::VarRow::toString, &x10::array::VarRow::typeName);
x10aux::itable_entry x10::array::VarRow::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::VarRow>())};
void x10::array::VarRow::_instance_init() {
    _I_("Doing initialisation for class: x10::array::VarRow");
    
}


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10FieldDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarRow::_constructor(x10_int cols, x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    this->x10::array::Row::_constructor(
      cols);
    
    //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::VarRow>)this)->
      FMGL(row) =
      x10::lang::Rail<void>::make<x10_int >(cols, init);
    
}
x10aux::ref<x10::array::VarRow> x10::array::VarRow::_make(
  x10_int cols,
  x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    x10aux::ref<x10::array::VarRow> this_ = new (memset(x10aux::alloc<x10::array::VarRow>(), 0, sizeof(x10::array::VarRow))) x10::array::VarRow();
    this_->_constructor(cols,
    init);
    return this_;
}



//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::VarRow::_constructor(x10_int cols) {
    this->x10::array::Row::_constructor(cols);
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::VarRow>)this)->FMGL(row) = x10::lang::Rail<void>::make<x10_int >(cols);
    
}
x10aux::ref<x10::array::VarRow> x10::array::VarRow::_make(x10_int cols)
{
    x10aux::ref<x10::array::VarRow> this_ = new (memset(x10aux::alloc<x10::array::VarRow>(), 0, sizeof(x10::array::VarRow))) x10::array::VarRow();
    this_->_constructor(cols);
    return this_;
}



//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Rail<x10_int > > x10::array::VarRow::row() {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > __desugarer__var__35__ =
          ((x10aux::ref<x10::array::VarRow>)this)->
            FMGL(row);
        
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Rail<x10_int > > __var450__;
        
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Labeled_c
        goto __ret1959; __ret1959: 
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__35__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__35__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Rail[x10.lang.Int]{self.home==here}"))));
            }
            
            //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Eval_c
            __var450__ =
              __desugarer__var__35__;
            
            //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": polyglot.ast.Branch_c
            goto __ret1959_end_;
        }
        goto __ret1959_next_; __ret1959_next_: ;
        }
        while (false);
        goto __ret1959_end_; __ret1959_end_: ;
        __var450__;
    }))
    ;
    
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::VarRow::apply(x10_int i) {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::VarRow>)this)->x10::array::VarRow::row())->apply(i);
    
}

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::VarRow::set(x10_int v, x10_int i) {
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/VarRow.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::VarRow>)this)->x10::array::VarRow::row())->set(v, i);
    
}
const x10aux::serialization_id_t x10::array::VarRow::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::VarRow::_deserializer<x10::lang::Object>);

void x10::array::VarRow::_serialize(x10aux::ref<x10::array::VarRow> this_,
                                    x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::VarRow::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Row::_serialize_body(buf);
    buf.write(this->FMGL(row));
    
}

void x10::array::VarRow::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Row::_deserialize_body(buf);
    FMGL(row) = buf.read<x10aux::ref<x10::lang::Rail<x10_int > > >();
}

x10aux::RuntimeType x10::array::VarRow::rtt;
void x10::array::VarRow::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Row>()};
    rtt.initStageTwo("x10.array.VarRow", 1, parents, 0, NULL, NULL);
}
