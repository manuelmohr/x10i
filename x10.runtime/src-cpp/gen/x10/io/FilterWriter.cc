#include <x10/io/FilterWriter.h>


#include "x10/io/FilterWriter.inc"

void x10::io::FilterWriter::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FilterWriter");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10FieldDecl_c

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::Writer> x10::io::FilterWriter::inner() {
    
    //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::FilterWriter>)this)->FMGL(w);
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FilterWriter::_constructor(x10aux::ref<x10::io::Writer> w) {
    this->x10::io::Writer::_constructor();
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::FilterWriter>)this)->FMGL(w) = w;
    
}
x10aux::ref<x10::io::FilterWriter> x10::io::FilterWriter::_make(x10aux::ref<x10::io::Writer> w)
{
    x10aux::ref<x10::io::FilterWriter> this_ = new (memset(x10aux::alloc<x10::io::FilterWriter>(), 0, sizeof(x10::io::FilterWriter))) x10::io::FilterWriter();
    this_->_constructor(w);
    return this_;
}



//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterWriter::close() {
    {
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterWriter>)this)->
                            FMGL(w))->close();
        
        //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterWriter::flush() {
    {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterWriter>)this)->
                            FMGL(w))->flush();
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterWriter::write(x10_byte b) {
    {
        
        //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterWriter>)this)->
                            FMGL(w))->write(b);
        
        //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterWriter.x10": x10.ast.X10Return_c
        return;
    }
}
void x10::io::FilterWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0) {
    x10::io::Writer::write(p0);
}
void x10::io::FilterWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > p0) {
    x10::io::Writer::write(p0);
}
void x10::io::FilterWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0, x10_int p1, x10_int p2) {
    x10::io::Writer::write(p0, p1, p2);
}
void x10::io::FilterWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > p0, x10_int p1, x10_int p2) {
    x10::io::Writer::write(p0, p1, p2);
}
const x10aux::serialization_id_t x10::io::FilterWriter::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::FilterWriter::_deserializer<x10::lang::Object>);

void x10::io::FilterWriter::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::Writer::_serialize_body(buf);
    buf.write(this->FMGL(w));
    
}

void x10::io::FilterWriter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::Writer::_deserialize_body(buf);
    FMGL(w) = buf.read<x10aux::ref<x10::io::Writer> >();
}

x10aux::RuntimeType x10::io::FilterWriter::rtt;
void x10::io::FilterWriter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::Writer>()};
    rtt.initStageTwo("x10.io.FilterWriter", 1, parents, 0, NULL, NULL);
}
