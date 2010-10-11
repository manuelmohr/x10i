#include <x10/io/OutputStreamWriter.h>


#include "x10/io/OutputStreamWriter.inc"

void x10::io::OutputStreamWriter::_instance_init() {
    _I_("Doing initialisation for class: x10::io::OutputStreamWriter");
    
}


//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10FieldDecl_c

//#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::OutputStreamWriter__OutputStream> x10::io::OutputStreamWriter::stream(
  ) {
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::OutputStreamWriter>)this)->FMGL(out);
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10ConstructorDecl_c
void x10::io::OutputStreamWriter::_constructor(x10aux::ref<x10::io::OutputStreamWriter__OutputStream> out)
{
    this->x10::io::Writer::_constructor();
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::OutputStreamWriter>)this)->
      FMGL(out) =
      out;
    
}
x10aux::ref<x10::io::OutputStreamWriter> x10::io::OutputStreamWriter::_make(
  x10aux::ref<x10::io::OutputStreamWriter__OutputStream> out)
{
    x10aux::ref<x10::io::OutputStreamWriter> this_ = new (memset(x10aux::alloc<x10::io::OutputStreamWriter>(), 0, sizeof(x10::io::OutputStreamWriter))) x10::io::OutputStreamWriter();
    this_->_constructor(out);
    return this_;
}



//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::flush() {
    {
        
        //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::OutputStreamWriter>)this)->
           FMGL(out))->flush();
        
        //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::close() {
    {
        
        //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::OutputStreamWriter>)this)->
           FMGL(out))->close();
        
        //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::write(x10_byte x) {
    {
        
        //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::OutputStreamWriter>)this)->
           FMGL(out))->write(((x10_int) (x)));
        
        //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > buf) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::OutputStreamWriter>)this)->FMGL(out))->write(buf);
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > buf) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::OutputStreamWriter>)this)->FMGL(out))->write(buf);
}

//#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > buf,
                                        x10_int off,
                                        x10_int len) {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::OutputStreamWriter>)this)->
       FMGL(out))->write(buf);
}

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::OutputStreamWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > buf,
                                        x10_int off,
                                        x10_int len) {
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/io/OutputStreamWriter.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::OutputStreamWriter>)this)->
       FMGL(out))->write(buf);
}
const x10aux::serialization_id_t x10::io::OutputStreamWriter::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::OutputStreamWriter::_deserializer<x10::lang::Object>);

void x10::io::OutputStreamWriter::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::Writer::_serialize_body(buf);
    buf.write(this->FMGL(out));
    
}

void x10::io::OutputStreamWriter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::Writer::_deserialize_body(buf);
    FMGL(out) = buf.read<x10aux::ref<x10::io::OutputStreamWriter__OutputStream> >();
}

x10aux::RuntimeType x10::io::OutputStreamWriter::rtt;
void x10::io::OutputStreamWriter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::Writer>()};
    rtt.initStageTwo("x10.io.OutputStreamWriter", 1, parents, 0, NULL, NULL);
}
