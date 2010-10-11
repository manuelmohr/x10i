#include <x10/io/Marshal__LongMarshal.h>


#include "x10/io/Marshal__LongMarshal.inc"

x10::io::Marshal<x10_long>::itable<x10::io::Marshal__LongMarshal >  x10::io::Marshal__LongMarshal::_itable_0(&x10::io::Marshal__LongMarshal::at, &x10::io::Marshal__LongMarshal::at, &x10::io::Marshal__LongMarshal::equals, &x10::io::Marshal__LongMarshal::hashCode, &x10::io::Marshal__LongMarshal::home, &x10::io::Marshal__LongMarshal::read, &x10::io::Marshal__LongMarshal::toString, &x10::io::Marshal__LongMarshal::typeName, &x10::io::Marshal__LongMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__LongMarshal >  x10::io::Marshal__LongMarshal::_itable_1(&x10::io::Marshal__LongMarshal::at, &x10::io::Marshal__LongMarshal::at, &x10::io::Marshal__LongMarshal::equals, &x10::io::Marshal__LongMarshal::hashCode, &x10::io::Marshal__LongMarshal::home, &x10::io::Marshal__LongMarshal::toString, &x10::io::Marshal__LongMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__LongMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_long> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__LongMarshal>())};
void x10::io::Marshal__LongMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__LongMarshal");
    
}


//#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::Marshal__LongMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_long l = ((x10_long)0ll);
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int)8))); 
                                                       //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
                                                       i = ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
            x10_byte b =
              x10aux::nullCheck(r)->read();
            
            //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
            l =
              ((x10_long) ((((x10_long) ((l) << (((x10_int)8))))) | (((x10_long) (((x10_int) ((((x10_int) (b))) & (((x10_int)255)))))))));
        }
    }
    
    //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return l;
    
}

//#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__LongMarshal::write(x10aux::ref<x10::io::Writer> w,
                                          x10_long l) {
    
    //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_int shift = ((x10_int)64);
    
    //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10While_c
    while (((shift) > (((x10_int)0)))) {
        
        //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        shift = ((x10_int) ((shift) - (((x10_int)8))));
        
        //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b = ((x10_byte) (((x10_long) ((l) >> (shift)))));
        
        //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(b);
    }
    
}

//#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__LongMarshal::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__LongMarshal> x10::io::Marshal__LongMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__LongMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__LongMarshal>(), 0, sizeof(x10::io::Marshal__LongMarshal))) x10::io::Marshal__LongMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__LongMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__LongMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__LongMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__LongMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__LongMarshal::rtt;
void x10::io::Marshal__LongMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_long> >()};
    rtt.initStageTwo("x10.io.Marshal$LongMarshal", 2, parents, 0, NULL, NULL);
}
