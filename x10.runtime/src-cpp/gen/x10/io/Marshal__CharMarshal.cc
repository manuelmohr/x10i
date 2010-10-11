#include <x10/io/Marshal__CharMarshal.h>


#include "x10/io/Marshal__CharMarshal.inc"

x10::io::Marshal<x10_char>::itable<x10::io::Marshal__CharMarshal >  x10::io::Marshal__CharMarshal::_itable_0(&x10::io::Marshal__CharMarshal::at, &x10::io::Marshal__CharMarshal::at, &x10::io::Marshal__CharMarshal::equals, &x10::io::Marshal__CharMarshal::hashCode, &x10::io::Marshal__CharMarshal::home, &x10::io::Marshal__CharMarshal::read, &x10::io::Marshal__CharMarshal::toString, &x10::io::Marshal__CharMarshal::typeName, &x10::io::Marshal__CharMarshal::write);
x10::lang::Any::itable<x10::io::Marshal__CharMarshal >  x10::io::Marshal__CharMarshal::_itable_1(&x10::io::Marshal__CharMarshal::at, &x10::io::Marshal__CharMarshal::at, &x10::io::Marshal__CharMarshal::equals, &x10::io::Marshal__CharMarshal::hashCode, &x10::io::Marshal__CharMarshal::home, &x10::io::Marshal__CharMarshal::toString, &x10::io::Marshal__CharMarshal::typeName);
x10aux::itable_entry x10::io::Marshal__CharMarshal::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::io::Marshal<x10_char> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::io::Marshal__CharMarshal>())};
void x10::io::Marshal__CharMarshal::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal__CharMarshal");
    
}


//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
x10_char x10::io::Marshal__CharMarshal::read(x10aux::ref<x10::io::Reader> r) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_byte b1 = x10aux::nullCheck(r)->read();
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10_int) (b1)), ((x10_int)-1)))) {
        
        //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::io::EOFException::_make()));
    }
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((((x10_int) (b1))) & (((x10_int)248))))),
                               ((x10_int)240)))) {
        
        //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b2 = x10aux::nullCheck(r)->read();
        
        //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b3 = x10aux::nullCheck(r)->read();
        
        //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b4 = x10aux::nullCheck(r)->read();
        
        //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return ((x10_char) (int) (((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) (b1))) & (((x10_int)3))))) << (((x10_int)18))))) | (((x10_int) ((((x10_int) ((((x10_int) (b2))) & (((x10_int)63))))) << (((x10_int)12)))))))) | (((x10_int) ((((x10_int) ((((x10_int) (b3))) & (((x10_int)63))))) << (((x10_int)6)))))))) | (((x10_int) ((((x10_int) (b4))) & (((x10_int)63)))))))));
        
    }
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((((x10_int) (b1))) & (((x10_int)240))))),
                               ((x10_int)224)))) {
        
        //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b2 = x10aux::nullCheck(r)->read();
        
        //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b3 = x10aux::nullCheck(r)->read();
        
        //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return ((x10_char) (int) (((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) (b1))) & (((x10_int)31))))) << (((x10_int)12))))) | (((x10_int) ((((x10_int) ((((x10_int) (b2))) & (((x10_int)63))))) << (((x10_int)6)))))))) | (((x10_int) ((((x10_int) (b3))) & (((x10_int)63)))))))));
        
    }
    
    //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((((x10_int) (b1))) & (((x10_int)224))))),
                               ((x10_int)192)))) {
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
        x10_byte b2 = x10aux::nullCheck(r)->read();
        
        //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return ((x10_char) (int) (((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) (b1))) & (((x10_int)31))))) << (((x10_int)6))))) | (((x10_int) ((((x10_int) (b2))) & (((x10_int)63)))))))));
        
    }
    
    //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
    return ((x10_char) (int) (((x10_int) (b1))));
    
}

//#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10MethodDecl_c
void x10::io::Marshal__CharMarshal::write(x10aux::ref<x10::io::Writer> w,
                                          x10_char c) {
    
    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10LocalDecl_c
    x10_int i = ((x10_int) (c).v);
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((i) & (((x10_int)0xFFFFFF80u))))),
                               ((x10_int)0)))) {
        
        //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (i)));
        
        //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((i) & (((x10_int)0xFFFFF800u))))),
                               ((x10_int)0)))) {
        
        //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)6))))) & (((x10_int)31))))) | (((x10_int)192)))))));
        
        //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((i) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((i) & (((x10_int)0xFFFF0000u))))),
                               ((x10_int)0)))) {
        
        //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)12))))) & (((x10_int)15))))) | (((x10_int)224)))))));
        
        //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)6))))) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((i) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals((((x10_int) ((i) & (((x10_int)0xFFE00000u))))),
                               ((x10_int)0)))) {
        
        //#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)18))))) & (((x10_int)7))))) | (((x10_int)240)))))));
        
        //#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)12))))) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((((x10_int) ((i) >> (((x10_int)6))))) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(w)->write(((x10_byte) (((x10_int) ((((x10_int) ((i) & (((x10_int)63))))) | (((x10_int)128)))))));
        
        //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10Return_c
        return;
    }
    
}

//#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Marshal__CharMarshal::_constructor(
  ) {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Marshal__CharMarshal> x10::io::Marshal__CharMarshal::_make(
  ) {
    x10aux::ref<x10::io::Marshal__CharMarshal> this_ = new (memset(x10aux::alloc<x10::io::Marshal__CharMarshal>(), 0, sizeof(x10::io::Marshal__CharMarshal))) x10::io::Marshal__CharMarshal();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Marshal__CharMarshal::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Marshal__CharMarshal::_deserializer<x10::lang::Object>);

void x10::io::Marshal__CharMarshal::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Marshal__CharMarshal::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Marshal__CharMarshal::rtt;
void x10::io::Marshal__CharMarshal::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::io::Marshal<x10_char> >()};
    rtt.initStageTwo("x10.io.Marshal$CharMarshal", 2, parents, 0, NULL, NULL);
}
