#include <x10/io/FileWriter.h>


#include "x10/io/FileWriter.inc"

void x10::io::FileWriter::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FileWriter");
    
}


//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileWriter.x10": x10.ast.X10FieldDecl_c

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileWriter.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::OutputStreamWriter__OutputStream> x10::io::FileWriter::make(
  x10aux::ref<x10::lang::String> path) {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileWriter.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::io::OutputStreamWriter__OutputStream> >(x10::io::FileWriter__FileOutputStream::_make(path));
    
}

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileWriter.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FileWriter::_constructor(x10aux::ref<x10::io::File> file)
{
    this->x10::io::OutputStreamWriter::_constructor(
      x10::io::FileWriter::make(
        x10aux::placeCheck(x10aux::nullCheck(file))->getPath()));
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileWriter.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::FileWriter>)this)->
      FMGL(file) =
      file;
    
}
x10aux::ref<x10::io::FileWriter> x10::io::FileWriter::_make(
  x10aux::ref<x10::io::File> file)
{
    x10aux::ref<x10::io::FileWriter> this_ = new (memset(x10aux::alloc<x10::io::FileWriter>(), 0, sizeof(x10::io::FileWriter))) x10::io::FileWriter();
    this_->_constructor(file);
    return this_;
}


const x10aux::serialization_id_t x10::io::FileWriter::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::FileWriter::_deserializer<x10::lang::Object>);

void x10::io::FileWriter::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::OutputStreamWriter::_serialize_body(buf);
    buf.write(this->FMGL(file));
    
}

void x10::io::FileWriter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::OutputStreamWriter::_deserialize_body(buf);
    FMGL(file) = buf.read<x10aux::ref<x10::io::File> >();
}

x10aux::RuntimeType x10::io::FileWriter::rtt;
void x10::io::FileWriter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::OutputStreamWriter>()};
    rtt.initStageTwo("x10.io.FileWriter", 1, parents, 0, NULL, NULL);
}
