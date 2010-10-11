#include <x10/io/Marshal__ByteMarshal.h>


#include "x10/io/Marshal__ByteMarshal.inc"

x10::io::Marshal<x10_byte>::itable<x10::io::Marshal__ByteMarshal >  x10::io::Marshal__ByteMarshal::_itable_0(&x10::io::Marshal__ByteMarshal::at, &x10::io::Marshal__ByteMarshal::at, &x10::io::Marshal__ByteMarshal::equals, &x10::io::Marshal__ByteMarshal::hashCode, &x10::io::Marshal__ByteMarshal::home, &x10::io::Marshal__ByteMarshal::read, &x10::io::Marshal__ByteMarshal::toString, &x10::io::Marshal__ByteMarshal::typeName, &x10::io::Marshal__ByteMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__ByteMarshal >  x10::io::Marshal__ByteMarshal::_itable_1(&x10::io::Marshal__ByteMarshal::at, &x10::io::Marshal__ByteMarshal::at, &x10::io::Marshal__ByteMarshal::equals, &x10::io::Marshal__ByteMarshal::hashCode, &x10::io::Marshal__ByteMarshal::home, &x10::io::Marshal__ByteMarshal::toString, &x10::io::Marshal__ByteMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__ByteMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_byte> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__ByteMarshal>())};
void x10::io::Marshal__ByteMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__ByteMarshal");
    
}


//#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_byte x10::io::Marshal__ByteMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(r)->read();
    
}

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__ByteMarshal::write(x10aux::ref<x10::io::Writer> w,
                                          x10_byte b) {
    {
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(b);
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__ByteMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__ByteMarshal> x10::io::Marshal__ByteMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__ByteMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__ByteMarshal>(), 0, sizeof(x10::io::Marshal__ByteMarshal))) x10::io::Marshal__ByteMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__ByteMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__ByteMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__ByteMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__ByteMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__ByteMarshal::rtt;
void x10::io::Marshal__ByteMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_byte> >()};
    rtt.initStageTwo("x10.io.Marshal$ByteMarshal", 2, parents, 0, NULL, NULL);
}
