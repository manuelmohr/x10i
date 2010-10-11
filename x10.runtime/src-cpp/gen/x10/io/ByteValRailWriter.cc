#include <x10/io/ByteValRailWriter.h>


#include "x10/io/ByteValRailWriter.inc"

void x10::io::ByteValRailWriter::_instance_init() {
    _I_("Doing initialisation for class: x10::io::ByteValRailWriter");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteValRailWriter.x10": x10.ast.X10ConstructorDecl_c
void x10::io::ByteValRailWriter::_constructor() {
    this->x10::io::ByteWriter<x10aux::ref<x10::lang::ValRail<x10_byte > > >::_constructor(
      x10aux::class_cast_unchecked<x10aux::ref<x10::util::Builder<x10_byte, x10aux::ref<x10::lang::ValRail<x10_byte > > > > >(x10::util::ValRailBuilder<x10_byte>::_make()));
    
}
x10aux::ref<x10::io::ByteValRailWriter> x10::io::ByteValRailWriter::_make(
  ) {
    x10aux::ref<x10::io::ByteValRailWriter> this_ = new (memset(x10aux::alloc<x10::io::ByteValRailWriter>(), 0, sizeof(x10::io::ByteValRailWriter))) x10::io::ByteValRailWriter();
    this_->_constructor();
    return this_;
}



//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteValRailWriter.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_byte > > x10::io::ByteValRailWriter::toValRail(
  ) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/ByteValRailWriter.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::ByteValRailWriter>)this)->result();
    
}
const x10aux::serialization_id_t x10::io::ByteValRailWriter::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::ByteValRailWriter::_deserializer<x10::lang::Object>);

void x10::io::ByteValRailWriter::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::ByteWriter<x10aux::ref<x10::lang::ValRail<x10_byte > > >::_serialize_body(buf);
    
}

void x10::io::ByteValRailWriter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::ByteWriter<x10aux::ref<x10::lang::ValRail<x10_byte > > >::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::ByteValRailWriter::rtt;
void x10::io::ByteValRailWriter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::ByteWriter<x10aux::ref<x10::lang::ValRail<x10_byte > > > >()};
    rtt.initStageTwo("x10.io.ByteValRailWriter", 1, parents, 0, NULL, NULL);
}
