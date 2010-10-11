#include <x10/io/PutbackReader.h>


#include "x10/io/PutbackReader.inc"

void x10::io::PutbackReader::_instance_init() {
    _I_("Doing initialisation for class: x10::io::PutbackReader");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10FieldDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::util::GrowableRail<x10_byte > > x10::io::PutbackReader::putback(
  ) {
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::util::GrowableRail<x10_byte > > __desugarer__var__38__ =
          ((x10aux::ref<x10::io::PutbackReader>)this)->
            FMGL(putback);
        
        //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::util::GrowableRail<x10_byte > > __var637__;
        
        //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Labeled_c
        goto __ret1970; __ret1970: 
        //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__38__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__38__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.util.GrowableRail[x10.lang.Byte]{self.home==here}"))));
            }
            
            //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Eval_c
            __var637__ =
              __desugarer__var__38__;
            
            //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Branch_c
            goto __ret1970_end_;
        }
        goto __ret1970_next_; __ret1970_next_: ;
        }
        while (false);
        goto __ret1970_end_; __ret1970_end_: ;
        __var637__;
    }))
    ;
    
}

//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10ConstructorDecl_c
void x10::io::PutbackReader::_constructor(
  x10aux::ref<x10::io::Reader> r) {
    this->x10::io::FilterReader::_constructor(
      r);
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::PutbackReader>)this)->
      FMGL(putback) =
      x10::util::GrowableRail<x10_byte >::_make();
    
}
x10aux::ref<x10::io::PutbackReader> x10::io::PutbackReader::_make(
  x10aux::ref<x10::io::Reader> r) {
    x10aux::ref<x10::io::PutbackReader> this_ = new (memset(x10aux::alloc<x10::io::PutbackReader>(), 0, sizeof(x10::io::PutbackReader))) x10::io::PutbackReader();
    this_->_constructor(r);
    return this_;
}



//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10MethodDecl_c
x10_byte x10::io::PutbackReader::read() {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10If_c
    if ((((((x10aux::ref<x10::io::PutbackReader>)this)->putback())->length()) > (((x10_int)0))))
    {
        
        //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10LocalDecl_c
        x10_byte p =
          (((x10aux::ref<x10::io::PutbackReader>)this)->putback())->apply(((x10_int) (((((x10aux::ref<x10::io::PutbackReader>)this)->putback())->length()) - (((x10_int)1)))));
        
        //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::io::PutbackReader>)this)->putback())->removeLast();
        
        //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10Return_c
        return p;
        
    }
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10Return_c
    return x10::io::FilterReader::read();
    
}

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": x10.ast.X10MethodDecl_c
void x10::io::PutbackReader::putback(x10_byte p) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/PutbackReader.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::io::PutbackReader>)this)->putback())->add(p);
}
const x10aux::serialization_id_t x10::io::PutbackReader::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::PutbackReader::_deserializer<x10::lang::Object>);

void x10::io::PutbackReader::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::FilterReader::_serialize_body(buf);
    buf.write(this->FMGL(putback));
    
}

void x10::io::PutbackReader::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::FilterReader::_deserialize_body(buf);
    FMGL(putback) = buf.read<x10aux::ref<x10::util::GrowableRail<x10_byte > > >();
}

x10aux::RuntimeType x10::io::PutbackReader::rtt;
void x10::io::PutbackReader::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::FilterReader>()};
    rtt.initStageTwo("x10.io.PutbackReader", 1, parents, 0, NULL, NULL);
}
