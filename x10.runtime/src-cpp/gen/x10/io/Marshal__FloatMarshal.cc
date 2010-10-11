#include <x10/io/Marshal__FloatMarshal.h>


#include "x10/io/Marshal__FloatMarshal.inc"

x10::io::Marshal<x10_float>::itable<x10::io::Marshal__FloatMarshal >  x10::io::Marshal__FloatMarshal::_itable_0(&x10::io::Marshal__FloatMarshal::at, &x10::io::Marshal__FloatMarshal::at, &x10::io::Marshal__FloatMarshal::equals, &x10::io::Marshal__FloatMarshal::hashCode, &x10::io::Marshal__FloatMarshal::home, &x10::io::Marshal__FloatMarshal::read, &x10::io::Marshal__FloatMarshal::toString, &x10::io::Marshal__FloatMarshal::typeName, &x10::io::Marshal__FloatMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__FloatMarshal >  x10::io::Marshal__FloatMarshal::_itable_1(&x10::io::Marshal__FloatMarshal::at, &x10::io::Marshal__FloatMarshal::at, &x10::io::Marshal__FloatMarshal::equals, &x10::io::Marshal__FloatMarshal::hashCode, &x10::io::Marshal__FloatMarshal::home, &x10::io::Marshal__FloatMarshal::toString, &x10::io::Marshal__FloatMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__FloatMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_float> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__FloatMarshal>())};
void x10::io::Marshal__FloatMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__FloatMarshal");
    
}


//#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_float x10::io::Marshal__FloatMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_int i = x10::io::Marshal<void>::FMGL(INT__get)()->read(r);
    
    //#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return x10aux::float_utils::fromIntBits(i);
    
}

//#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__FloatMarshal::write(x10aux::ref<x10::io::Writer> w,
                                           x10_float f) {
    
    //#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_int i = x10aux::float_utils::toIntBits(f);
    
    //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10::io::Marshal<void>::FMGL(INT__get)()->write(w, i);
}

//#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__FloatMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__FloatMarshal> x10::io::Marshal__FloatMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__FloatMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__FloatMarshal>(), 0, sizeof(x10::io::Marshal__FloatMarshal))) x10::io::Marshal__FloatMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__FloatMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__FloatMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__FloatMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__FloatMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__FloatMarshal::rtt;
void x10::io::Marshal__FloatMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_float> >()};
    rtt.initStageTwo("x10.io.Marshal$FloatMarshal", 2, parents, 0, NULL, NULL);
}
