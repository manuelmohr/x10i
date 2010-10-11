#include <x10/io/Marshal__DoubleMarshal.h>


#include "x10/io/Marshal__DoubleMarshal.inc"

x10::io::Marshal<x10_double>::itable<x10::io::Marshal__DoubleMarshal >  x10::io::Marshal__DoubleMarshal::_itable_0(&x10::io::Marshal__DoubleMarshal::at, &x10::io::Marshal__DoubleMarshal::at, &x10::io::Marshal__DoubleMarshal::equals, &x10::io::Marshal__DoubleMarshal::hashCode, &x10::io::Marshal__DoubleMarshal::home, &x10::io::Marshal__DoubleMarshal::read, &x10::io::Marshal__DoubleMarshal::toString, &x10::io::Marshal__DoubleMarshal::typeName, &x10::io::Marshal__DoubleMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__DoubleMarshal >  x10::io::Marshal__DoubleMarshal::_itable_1(&x10::io::Marshal__DoubleMarshal::at, &x10::io::Marshal__DoubleMarshal::at, &x10::io::Marshal__DoubleMarshal::equals, &x10::io::Marshal__DoubleMarshal::hashCode, &x10::io::Marshal__DoubleMarshal::home, &x10::io::Marshal__DoubleMarshal::toString, &x10::io::Marshal__DoubleMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__DoubleMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_double> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__DoubleMarshal>())};
void x10::io::Marshal__DoubleMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__DoubleMarshal");
    
}


//#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_double x10::io::Marshal__DoubleMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_long l = x10::io::Marshal<void>::FMGL(LONG__get)()->read(r);
    
    //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return x10aux::double_utils::fromLongBits(l);
    
}

//#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__DoubleMarshal::write(x10aux::ref<x10::io::Writer> w,
                                            x10_double d) {
    
    //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_long l = x10aux::double_utils::toLongBits(d);
    
    //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
    x10::io::Marshal<void>::FMGL(LONG__get)()->write(w, l);
}

//#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__DoubleMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__DoubleMarshal> x10::io::Marshal__DoubleMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__DoubleMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__DoubleMarshal>(), 0, sizeof(x10::io::Marshal__DoubleMarshal))) x10::io::Marshal__DoubleMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__DoubleMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__DoubleMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__DoubleMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__DoubleMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__DoubleMarshal::rtt;
void x10::io::Marshal__DoubleMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_double> >()};
    rtt.initStageTwo("x10.io.Marshal$DoubleMarshal", 2, parents, 0, NULL, NULL);
}
