#include <x10/io/Marshal__BooleanMarshal.h>


#include "x10/io/Marshal__BooleanMarshal.inc"

x10::io::Marshal<x10_boolean>::itable<x10::io::Marshal__BooleanMarshal >  x10::io::Marshal__BooleanMarshal::_itable_0(&x10::io::Marshal__BooleanMarshal::at, &x10::io::Marshal__BooleanMarshal::at, &x10::io::Marshal__BooleanMarshal::equals, &x10::io::Marshal__BooleanMarshal::hashCode, &x10::io::Marshal__BooleanMarshal::home, &x10::io::Marshal__BooleanMarshal::read, &x10::io::Marshal__BooleanMarshal::toString, &x10::io::Marshal__BooleanMarshal::typeName, &x10::io::Marshal__BooleanMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__BooleanMarshal >  x10::io::Marshal__BooleanMarshal::_itable_1(&x10::io::Marshal__BooleanMarshal::at, &x10::io::Marshal__BooleanMarshal::at, &x10::io::Marshal__BooleanMarshal::equals, &x10::io::Marshal__BooleanMarshal::hashCode, &x10::io::Marshal__BooleanMarshal::home, &x10::io::Marshal__BooleanMarshal::toString, &x10::io::Marshal__BooleanMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__BooleanMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_boolean> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__BooleanMarshal>())};
void x10::io::Marshal__BooleanMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__BooleanMarshal");
    
}


//#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::Marshal__BooleanMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return (!x10aux::struct_equals(((x10_int) (x10aux::nullCheck(r)->read())),
                                   ((x10_int)0)));
    
}

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__BooleanMarshal::write(x10aux::ref<x10::io::Writer> w,
                                             x10_boolean b) {
    {
        
        //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (b ? (x10_int)(((x10_int)0))
                                      : (x10_int)(((x10_int)1)))));
        
        //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__BooleanMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__BooleanMarshal> x10::io::Marshal__BooleanMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__BooleanMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__BooleanMarshal>(), 0, sizeof(x10::io::Marshal__BooleanMarshal))) x10::io::Marshal__BooleanMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__BooleanMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__BooleanMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__BooleanMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__BooleanMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__BooleanMarshal::rtt;
void x10::io::Marshal__BooleanMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_boolean> >()};
    rtt.initStageTwo("x10.io.Marshal$BooleanMarshal", 2, parents, 0, NULL, NULL);
}
