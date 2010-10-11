#include <x10/io/Marshal__LineMarshal.h>


#include "x10/io/Marshal__LineMarshal.inc"

x10::io::Marshal<x10aux::ref<x10::lang::String> >::itable<x10::io::Marshal__LineMarshal >  x10::io::Marshal__LineMarshal::_itable_0(&x10::io::Marshal__LineMarshal::at, &x10::io::Marshal__LineMarshal::at, &x10::io::Marshal__LineMarshal::equals, &x10::io::Marshal__LineMarshal::hashCode, &x10::io::Marshal__LineMarshal::home, &x10::io::Marshal__LineMarshal::read, &x10::io::Marshal__LineMarshal::toString, &x10::io::Marshal__LineMarshal::typeName, &x10::io::Marshal__LineMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__LineMarshal >  x10::io::Marshal__LineMarshal::_itable_1(&x10::io::Marshal__LineMarshal::at, &x10::io::Marshal__LineMarshal::at, &x10::io::Marshal__LineMarshal::equals, &x10::io::Marshal__LineMarshal::hashCode, &x10::io::Marshal__LineMarshal::home, &x10::io::Marshal__LineMarshal::toString, &x10::io::Marshal__LineMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__LineMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10aux::ref<x10::lang::String> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__LineMarshal>())};
void x10::io::Marshal__LineMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__LineMarshal");
    
}


//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::io::Marshal__LineMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::StringBuilder> sb = x10::util::StringBuilder::_make();
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_char ch;
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Do_c
    do {
        
        //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        ch = x10::io::Marshal<void>::FMGL(CHAR__get)()->read(r);
        
        //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        sb->add(ch);
    } while ((!x10aux::struct_equals(ch, ((x10_char)'\n'))));
    
    //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return sb->result();
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__LineMarshal::write(x10aux::ref<x10::io::Writer> w,
                                          x10aux::ref<x10::lang::String> s) {
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < ((s)->length())); 
                                                        //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
                                                        i = ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
            x10_char ch =
              (s)->charAt(i);
            
            //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
            x10::io::Marshal<void>::
              FMGL(CHAR__get)()->write(
              w,
              ch);
        }
    }
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__LineMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__LineMarshal> x10::io::Marshal__LineMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__LineMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__LineMarshal>(), 0, sizeof(x10::io::Marshal__LineMarshal))) x10::io::Marshal__LineMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__LineMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__LineMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__LineMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__LineMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__LineMarshal::rtt;
void x10::io::Marshal__LineMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10aux::ref<x10::lang::String> > >()};
    rtt.initStageTwo("x10.io.Marshal$LineMarshal", 2, parents, 0, NULL, NULL);
}
