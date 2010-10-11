#include <x10/io/StringWriter.h>


#include "x10/io/StringWriter.inc"

void x10::io::StringWriter::_instance_init() {
    _I_("Doing initialisation for class: x10::io::StringWriter");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10FieldDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10ConstructorDecl_c
void x10::io::StringWriter::_constructor() {
    this->x10::io::Writer::_constructor();
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::StringWriter>)this)->FMGL(b) = x10::util::StringBuilder::_make();
    
}
x10aux::ref<x10::io::StringWriter> x10::io::StringWriter::_make() {
    x10aux::ref<x10::io::StringWriter> this_ = new (memset(x10aux::alloc<x10::io::StringWriter>(), 0, sizeof(x10::io::StringWriter))) x10::io::StringWriter();
    this_->_constructor();
    return this_;
}



//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::StringWriter::write(x10_byte x) {
    
    //#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": polyglot.ast.Eval_c
    x10::lang::Runtime::runAt(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::io::StringWriter>)this)->
                                                                                     FMGL(b))),
                              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_io_StringWriter__closure__0>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_io_StringWriter__closure__0)))x10_io_StringWriter__closure__0(this, x)))));
}

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::StringWriter::size() {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::evalAt<x10_int >(x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::io::StringWriter>)this)->
                                                                                                       FMGL(b))),
                                                x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10_int> > >(x10aux::ref<x10::lang::Fun_0_0<x10_int> >(x10aux::ref<x10_io_StringWriter__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_0<x10_int> >(sizeof(x10_io_StringWriter__closure__1)))x10_io_StringWriter__closure__1(this)))));
    
}

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::io::StringWriter::result(
  ) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10Return_c
    return x10::lang::Runtime::evalAt<x10aux::ref<x10::lang::String> >(
             x10::lang::Place_methods::place(x10aux::get_location(((x10aux::ref<x10::io::StringWriter>)this)->
                                                                    FMGL(b))),
             x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > > >(x10aux::ref<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > >(x10aux::ref<x10_io_StringWriter__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > >(sizeof(x10_io_StringWriter__closure__2)))x10_io_StringWriter__closure__2(this)))));
    
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::StringWriter::flush() {
 
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/StringWriter.x10": x10.ast.X10MethodDecl_c
void x10::io::StringWriter::close() {
 
}
void x10::io::StringWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0) {
    x10::io::Writer::write(p0);
}
void x10::io::StringWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > p0) {
    x10::io::Writer::write(p0);
}
void x10::io::StringWriter::write(x10aux::ref<x10::lang::ValRail<x10_byte > > p0, x10_int p1, x10_int p2) {
    x10::io::Writer::write(p0, p1, p2);
}
void x10::io::StringWriter::write(x10aux::ref<x10::lang::Rail<x10_byte > > p0, x10_int p1, x10_int p2) {
    x10::io::Writer::write(p0, p1, p2);
}
const x10aux::serialization_id_t x10::io::StringWriter::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::StringWriter::_deserializer<x10::lang::Object>);

void x10::io::StringWriter::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::Writer::_serialize_body(buf);
    buf.write(this->FMGL(b));
    
}

void x10::io::StringWriter::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::Writer::_deserialize_body(buf);
    FMGL(b) = buf.read<x10aux::ref<x10::util::StringBuilder> >();
}

x10aux::RuntimeType x10::io::StringWriter::rtt;
void x10::io::StringWriter::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::Writer>()};
    rtt.initStageTwo("x10.io.StringWriter", 1, parents, 0, NULL, NULL);
}
x10::lang::VoidFun_0_0::itable<x10_io_StringWriter__closure__0>x10_io_StringWriter__closure__0::_itable(&x10_io_StringWriter__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_io_StringWriter__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_io_StringWriter__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::VoidFun_0_0>, &x10_io_StringWriter__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_io_StringWriter__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_io_StringWriter__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_0<x10_int>::itable<x10_io_StringWriter__closure__1>x10_io_StringWriter__closure__1::_itable(&x10_io_StringWriter__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_io_StringWriter__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_io_StringWriter__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10_int> >, &x10_io_StringWriter__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_io_StringWriter__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_io_StringWriter__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> >::itable<x10_io_StringWriter__closure__2>x10_io_StringWriter__closure__2::_itable(&x10_io_StringWriter__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_io_StringWriter__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_io_StringWriter__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_0<x10aux::ref<x10::lang::String> > >, &x10_io_StringWriter__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_io_StringWriter__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_io_StringWriter__closure__2::_deserialize<x10::lang::Object>);

