#include <x10/io/InputStreamReader.h>


#include "x10/io/InputStreamReader.inc"

void x10::io::InputStreamReader::_instance_init() {
    _I_("Doing initialisation for class: x10::io::InputStreamReader");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10FieldDecl_c

//#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10ConstructorDecl_c
void x10::io::InputStreamReader::_constructor(x10aux::ref<x10::io::InputStreamReader__InputStream> stream)
{
    this->x10::io::Reader::_constructor();
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::InputStreamReader>)this)->
      FMGL(stream) =
      stream;
    
}
x10aux::ref<x10::io::InputStreamReader> x10::io::InputStreamReader::_make(
  x10aux::ref<x10::io::InputStreamReader__InputStream> stream)
{
    x10aux::ref<x10::io::InputStreamReader> this_ = new (memset(x10aux::alloc<x10::io::InputStreamReader>(), 0, sizeof(x10::io::InputStreamReader))) x10::io::InputStreamReader();
    this_->_constructor(stream);
    return this_;
}



//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::InputStreamReader__InputStream> x10::io::InputStreamReader::stream(
  ) {
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::InputStreamReader>)this)->
             FMGL(stream);
    
}

//#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
void x10::io::InputStreamReader::close() {
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::InputStreamReader>)this)->FMGL(stream))->close();
}

//#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
x10_byte x10::io::InputStreamReader::read() {
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10LocalDecl_c
    x10_int n = (((x10aux::ref<x10::io::InputStreamReader>)this)->
                   FMGL(stream))->read();
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(n, ((x10_int)-1)))) {
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::io::EOFException::_make()));
    }
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
    return ((x10_byte) (n));
    
}

//#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::InputStreamReader::available() {
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::InputStreamReader>)this)->
              FMGL(stream))->available();
    
}

//#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
void x10::io::InputStreamReader::skip(x10_int off) {
    {
        
        //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::InputStreamReader>)this)->
           FMGL(stream))->skip(off);
        
        //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
void x10::io::InputStreamReader::mark(x10_int off) {
    {
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::InputStreamReader>)this)->
           FMGL(stream))->mark(off);
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
void x10::io::InputStreamReader::reset() {
    {
        
        //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::InputStreamReader>)this)->
           FMGL(stream))->reset();
        
        //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::InputStreamReader::markSupported() {
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/io/InputStreamReader.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::InputStreamReader>)this)->
              FMGL(stream))->markSupported();
    
}
const x10aux::serialization_id_t x10::io::InputStreamReader::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::InputStreamReader::_deserializer<x10::lang::Object>);

void x10::io::InputStreamReader::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::Reader::_serialize_body(buf);
    buf.write(this->FMGL(stream));
    
}

void x10::io::InputStreamReader::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::Reader::_deserialize_body(buf);
    FMGL(stream) = buf.read<x10aux::ref<x10::io::InputStreamReader__InputStream> >();
}

x10aux::RuntimeType x10::io::InputStreamReader::rtt;
void x10::io::InputStreamReader::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::Reader>()};
    rtt.initStageTwo("x10.io.InputStreamReader", 1, parents, 0, NULL, NULL);
}
