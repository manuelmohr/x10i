#include <x10/io/Marshal__ShortMarshal.h>


#include "x10/io/Marshal__ShortMarshal.inc"

x10::io::Marshal<x10_short>::itable<x10::io::Marshal__ShortMarshal >  x10::io::Marshal__ShortMarshal::_itable_0(&x10::io::Marshal__ShortMarshal::at, &x10::io::Marshal__ShortMarshal::at, &x10::io::Marshal__ShortMarshal::equals, &x10::io::Marshal__ShortMarshal::hashCode, &x10::io::Marshal__ShortMarshal::home, &x10::io::Marshal__ShortMarshal::read, &x10::io::Marshal__ShortMarshal::toString, &x10::io::Marshal__ShortMarshal::typeName, &x10::io::Marshal__ShortMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__ShortMarshal >  x10::io::Marshal__ShortMarshal::_itable_1(&x10::io::Marshal__ShortMarshal::at, &x10::io::Marshal__ShortMarshal::at, &x10::io::Marshal__ShortMarshal::equals, &x10::io::Marshal__ShortMarshal::hashCode, &x10::io::Marshal__ShortMarshal::home, &x10::io::Marshal__ShortMarshal::toString, &x10::io::Marshal__ShortMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__ShortMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_short> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__ShortMarshal>())};
void x10::io::Marshal__ShortMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__ShortMarshal");
    
}


//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_short x10::io::Marshal__ShortMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b1 = x10aux::nullCheck(r)->read();
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b2 = x10aux::nullCheck(r)->read();
    
    //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return ((x10_short) (((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) (b1))) & (((x10_int)255))))) << (((x10_int)8))))) | (((x10_int) ((((x10_int) (b2))) & (((x10_int)255)))))))));
    
}

//#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__ShortMarshal::write(x10aux::ref<x10::io::Writer> w,
                                           x10_short s) {
    
    //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_int i = ((x10_int) (s));
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b1 = ((x10_byte) (((x10_int) ((i) >> (((x10_int)8))))));
    
    //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b2 = ((x10_byte) (i));
    
    //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b1);
    
    //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(w)->write(b2);
}

//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__ShortMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__ShortMarshal> x10::io::Marshal__ShortMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__ShortMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__ShortMarshal>(), 0, sizeof(x10::io::Marshal__ShortMarshal))) x10::io::Marshal__ShortMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__ShortMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__ShortMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__ShortMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__ShortMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__ShortMarshal::rtt;
void x10::io::Marshal__ShortMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_short> >()};
    rtt.initStageTwo("x10.io.Marshal$ShortMarshal", 2, parents, 0, NULL, NULL);
}
