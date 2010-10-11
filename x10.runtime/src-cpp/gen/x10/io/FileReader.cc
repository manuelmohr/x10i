#include <x10/io/FileReader.h>


#include "x10/io/FileReader.inc"

void x10::io::FileReader::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FileReader");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileReader.x10": x10.ast.X10FieldDecl_c

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileReader.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FileReader::_constructor(x10aux::ref<x10::io::File> file) {
    this->x10::io::InputStreamReader::_constructor(x10aux::class_cast_unchecked<x10aux::ref<x10::io::InputStreamReader__InputStream> >(x10::io::FileReader__FileInputStream::_make(x10aux::placeCheck(x10aux::nullCheck(file))->getPath())));
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileReader.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::FileReader>)this)->FMGL(file) = file;
    
}
x10aux::ref<x10::io::FileReader> x10::io::FileReader::_make(x10aux::ref<x10::io::File> file)
{
    x10aux::ref<x10::io::FileReader> this_ = new (memset(x10aux::alloc<x10::io::FileReader>(), 0, sizeof(x10::io::FileReader))) x10::io::FileReader();
    this_->_constructor(file);
    return this_;
}


const x10aux::serialization_id_t x10::io::FileReader::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::FileReader::_deserializer<x10::lang::Object>);

void x10::io::FileReader::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::InputStreamReader::_serialize_body(buf);
    buf.write(this->FMGL(file));
    
}

void x10::io::FileReader::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::InputStreamReader::_deserialize_body(buf);
    FMGL(file) = buf.read<x10aux::ref<x10::io::File> >();
}

x10aux::RuntimeType x10::io::FileReader::rtt;
void x10::io::FileReader::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::InputStreamReader>()};
    rtt.initStageTwo("x10.io.FileReader", 1, parents, 0, NULL, NULL);
}
