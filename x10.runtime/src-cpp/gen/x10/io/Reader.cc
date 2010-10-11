#include <x10/io/Reader.h>


#include "x10/io/Reader.inc"

void x10::io::Reader::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Reader");
    
}


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::Reader::readBoolean() {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(BOOLEAN__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_byte x10::io::Reader::readByte() {
    
    //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(BYTE__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_char x10::io::Reader::readChar() {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(CHAR__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_short x10::io::Reader::readShort() {
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(SHORT__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::Reader::readInt() {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(INT__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::Reader::readLong() {
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(LONG__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_float x10::io::Reader::readFloat() {
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(FLOAT__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10_double x10::io::Reader::readDouble() {
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(DOUBLE__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::io::Reader::readLine() {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::Marshal<void>::FMGL(LINE__get)()->read(((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c

//#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10aux::ref<x10::lang::String> > > x10::io::Reader::lines(
  ) {
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::ReaderIterator<x10aux::ref<x10::lang::String> >::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Marshal<x10aux::ref<x10::lang::String> > > >(x10::io::Marshal<void>::
                                                                                                                                                                            FMGL(LINE__get)()),
                                                                           ((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10_char> > x10::io::Reader::chars(
  ) {
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::ReaderIterator<x10_char>::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Marshal<x10_char> > >(x10::io::Marshal<void>::
                                                                                                                              FMGL(CHAR__get)()),
                                                    ((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10_byte> >
  x10::io::Reader::bytes(
  ) {
    
    //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10Return_c
    return x10::io::ReaderIterator<x10_byte>::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Marshal<x10_byte> > >(x10::io::Marshal<void>::
                                                                                                                              FMGL(BYTE__get)()),
                                                    ((x10aux::ref<x10::io::Reader>)this));
    
}

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Reader.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Reader::_constructor() {
    this->x10::lang::Object::_constructor();
    
}

void x10::io::Reader::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Reader::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Reader::rtt;
void x10::io::Reader::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.io.Reader", 1, parents, 0, NULL, NULL);
}
