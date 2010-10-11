#include <x10/io/FileNotFoundException.h>


#include "x10/io/FileNotFoundException.inc"

void x10::io::FileNotFoundException::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FileNotFoundException");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileNotFoundException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FileNotFoundException::_constructor() {
    this->x10::io::IOException::_constructor();
    
}
x10aux::ref<x10::io::FileNotFoundException> x10::io::FileNotFoundException::_make(
  ) {
    x10aux::ref<x10::io::FileNotFoundException> this_ = new (memset(x10aux::alloc<x10::io::FileNotFoundException>(), 0, sizeof(x10::io::FileNotFoundException))) x10::io::FileNotFoundException();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileNotFoundException.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FileNotFoundException::_constructor(x10aux::ref<x10::lang::String> message)
{
    this->x10::io::IOException::_constructor(
      message);
    
}
x10aux::ref<x10::io::FileNotFoundException> x10::io::FileNotFoundException::_make(
  x10aux::ref<x10::lang::String> message)
{
    x10aux::ref<x10::io::FileNotFoundException> this_ = new (memset(x10aux::alloc<x10::io::FileNotFoundException>(), 0, sizeof(x10::io::FileNotFoundException))) x10::io::FileNotFoundException();
    this_->_constructor(message);
    return this_;
}


const x10aux::serialization_id_t x10::io::FileNotFoundException::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::FileNotFoundException::_deserializer<x10::lang::Object>);

void x10::io::FileNotFoundException::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::IOException::_serialize_body(buf);
    
}

void x10::io::FileNotFoundException::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::IOException::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::FileNotFoundException::rtt;
void x10::io::FileNotFoundException::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::IOException>()};
    rtt.initStageTwo("x10.io.FileNotFoundException", 1, parents, 0, NULL, NULL);
}
