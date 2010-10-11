#include <x10/io/Marshal__IntMarshal.h>


#include "x10/io/Marshal__IntMarshal.inc"

x10::io::Marshal<x10_int>::itable<x10::io::Marshal__IntMarshal >  x10::io::Marshal__IntMarshal::_itable_0(&x10::io::Marshal__IntMarshal::at, &x10::io::Marshal__IntMarshal::at, &x10::io::Marshal__IntMarshal::equals, &x10::io::Marshal__IntMarshal::hashCode, &x10::io::Marshal__IntMarshal::home, &x10::io::Marshal__IntMarshal::read, &x10::io::Marshal__IntMarshal::toString, &x10::io::Marshal__IntMarshal::typeName, &x10::io::Marshal__IntMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__IntMarshal >  x10::io::Marshal__IntMarshal::_itable_1(&x10::io::Marshal__IntMarshal::at, &x10::io::Marshal__IntMarshal::at, &x10::io::Marshal__IntMarshal::equals, &x10::io::Marshal__IntMarshal::hashCode, &x10::io::Marshal__IntMarshal::home, &x10::io::Marshal__IntMarshal::toString, &x10::io::Marshal__IntMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__IntMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__IntMarshal>())};
void x10::io::Marshal__IntMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__IntMarshal");
    
}


//#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::Marshal__IntMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b1 = x10aux::nullCheck(r)->read();
    
    //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b2 = x10aux::nullCheck(r)->read();
    
    //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b3 = x10aux::nullCheck(r)->read();
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b4 = x10aux::nullCheck(r)->read();
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return (((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) (b1))) & (((x10_int)255))))) << (((x10_int)24))))) | (((x10_int) ((((x10_int) ((((x10_int) (b2))) & (((x10_int)255))))) << (((x10_int)16)))))))) | (((x10_int) ((((x10_int) ((((x10_int) (b3))) & (((x10_int)255))))) << (((x10_int)8)))))))) | (((x10_int) ((((x10_int) (b4))) & (((x10_int)255))))))));
    
}

//#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__IntMarshal::write(x10aux::ref<x10::io::Writer> w, x10_int i) {
    
    //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b1 = ((x10_byte) (((x10_int) ((i) >> (((x10_int)24))))));
    
    //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b2 = ((x10_byte) (((x10_int) ((i) >> (((x10_int)16))))));
    
    //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b3 = ((x10_byte) (((x10_int) ((i) >> (((x10_int)8))))));
    
    //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b4 = ((x10_byte) (i));
    
    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b1);
    
    //#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b2);
    
    //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b3);
    
    //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b4);
}

//#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__IntMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__IntMarshal> x10::io::Marshal__IntMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__IntMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__IntMarshal>(), 0, sizeof(x10::io::Marshal__IntMarshal))) x10::io::Marshal__IntMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__IntMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__IntMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__IntMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__IntMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__IntMarshal::rtt;
void x10::io::Marshal__IntMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_int> >()};
    rtt.initStageTwo("x10.io.Marshal$IntMarshal", 2, parents, 0, NULL, NULL);
}
