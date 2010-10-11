#include <x10/io/Writer.h>


#include "x10/io/Writer.inc"

void x10::io::Writer::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Writer");
    
}


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeByte(x10_byte x) {
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(BYTE__get)()->write(((x10aux::ref<x10::io::Writer>)this),
                                                         x);
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeChar(x10_char x) {
    {
        
        //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(CHAR__get)()->write(((x10aux::ref<x10::io::Writer>)this),
                                                         x);
        
        //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeShort(x10_short x) {
    {
        
        //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(SHORT__get)()->write(
          ((x10aux::ref<x10::io::Writer>)this),
          x);
        
        //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeInt(x10_int x) {
    {
        
        //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(INT__get)()->write(((x10aux::ref<x10::io::Writer>)this),
                                                        x);
        
        //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeLong(x10_long x) {
    {
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(LONG__get)()->write(
          ((x10aux::ref<x10::io::Writer>)this),
          x);
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeFloat(x10_float x) {
    {
        
        //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(FLOAT__get)()->write(
          ((x10aux::ref<x10::io::Writer>)this),
          x);
        
        //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeDouble(x10_double x) {
    {
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(DOUBLE__get)()->write(
          ((x10aux::ref<x10::io::Writer>)this),
          x);
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::writeBoolean(x10_boolean x) {
    {
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
        x10::io::Marshal<void>::FMGL(BOOLEAN__get)()->write(
          ((x10aux::ref<x10::io::Writer>)this),
          x);
        
        //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c

//#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::write(x10aux::ref<x10::lang::ValRail<x10_byte > > buf) {
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Writer>)this)->write(buf,
                                                ((x10_int)0),
                                                x10aux::nullCheck(buf)->
                                                  FMGL(length));
}

//#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::write(x10aux::ref<x10::lang::Rail<x10_byte > > buf) {
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Writer>)this)->write(buf,
                                                ((x10_int)0),
                                                x10aux::nullCheck(buf)->
                                                  FMGL(length));
}

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::write(x10aux::ref<x10::lang::ValRail<x10_byte > > buf,
                            x10_int off,
                            x10_int len) {
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10LocalDecl_c
             i = off; ((i) < (((x10_int) ((off) + (len)))));
             
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::io::Writer>)this)->write(
              (buf)->apply(i));
        }
    }
    
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
void x10::io::Writer::write(x10aux::ref<x10::lang::Rail<x10_byte > > buf,
                            x10_int off,
                            x10_int len) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10LocalDecl_c
             i = off; ((i) < (((x10_int) ((off) + (len)))));
             
             //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::io::Writer>)this)->write(
              (buf)->apply(i));
        }
    }
    
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::OutputStreamWriter__OutputStream>
  x10::io::Writer::oos(
  ) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::Writer>)this)->oos();
    
}

//#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::OutputStreamWriter__OutputStream>
  x10::io::Writer::getNativeOutputStream(
  ) {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::Writer>)this)->oos();
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Writer.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Writer::_constructor() {
    this->x10::lang::Object::_constructor();
    
}

void x10::io::Writer::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Writer::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Writer::rtt;
void x10::io::Writer::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.io.Writer", 1, parents, 0, NULL, NULL);
}
