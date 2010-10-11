#include <x10/io/FilterReader.h>


#include "x10/io/FilterReader.inc"

void x10::io::FilterReader::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FilterReader");
    
}


//#line 15 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10FieldDecl_c

//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::Reader> x10::io::FilterReader::inner() {
    
    //#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::FilterReader>)this)->FMGL(r);
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FilterReader::_constructor(x10aux::ref<x10::io::Reader> r) {
    this->x10::io::Reader::_constructor();
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::FilterReader>)this)->FMGL(r) = r;
    
}
x10aux::ref<x10::io::FilterReader> x10::io::FilterReader::_make(x10aux::ref<x10::io::Reader> r)
{
    x10aux::ref<x10::io::FilterReader> this_ = new (memset(x10aux::alloc<x10::io::FilterReader>(), 0, sizeof(x10::io::FilterReader))) x10::io::FilterReader();
    this_->_constructor(r);
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterReader::close() {
    {
        
        //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                            FMGL(r))->close();
        
        //#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
x10_byte x10::io::FilterReader::read() {
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                               FMGL(r))->read();
    
}

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::FilterReader::available() {
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                               FMGL(r))->available();
    
}

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterReader::skip(x10_int off) {
    {
        
        //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                            FMGL(r))->skip(off);
        
        //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterReader::mark(x10_int off) {
    {
        
        //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                            FMGL(r))->mark(off);
        
        //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
void x10::io::FilterReader::reset() {
    {
        
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                            FMGL(r))->reset();
        
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::FilterReader::markSupported() {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FilterReader.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::io::FilterReader>)this)->
                               FMGL(r))->markSupported();
    
}
const x10aux::serialization_id_t x10::io::FilterReader::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::FilterReader::_deserializer<x10::lang::Object>);

void x10::io::FilterReader::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::Reader::_serialize_body(buf);
    buf.write(this->FMGL(r));
    
}

void x10::io::FilterReader::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::Reader::_deserialize_body(buf);
    FMGL(r) = buf.read<x10aux::ref<x10::io::Reader> >();
}

x10aux::RuntimeType x10::io::FilterReader::rtt;
void x10::io::FilterReader::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::Reader>()};
    rtt.initStageTwo("x10.io.FilterReader", 1, parents, 0, NULL, NULL);
}
