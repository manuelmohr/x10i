#include <x10/lang/System.h>


#include "x10/lang/System.inc"

void x10::lang::System::_instance_init() {
    _I_("Doing initialisation for class: x10::lang::System");
    
}


//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10ConstructorDecl_c
void x10::lang::System::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::lang::System> x10::lang::System::_make() {
    x10aux::ref<x10::lang::System> this_ = new (memset(x10aux::alloc<x10::lang::System>(), 0, sizeof(x10::lang::System))) x10::lang::System();
    this_->_constructor();
    return this_;
}



//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::System::currentTimeMillis() {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10Return_c
    return x10aux::system_utils::currentTimeMillis();
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c
x10_long x10::lang::System::nanoTime() {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10Return_c
    return x10aux::system_utils::nanoTime();
    
}

//#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c
void x10::lang::System::exit() {
    {
        
        //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": polyglot.ast.Eval_c
        x10aux::system_utils::exit(((x10_int)-1));
        
        //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c
void x10::lang::System::setExitCode(x10_int exitCode) {
 
}

//#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/System.x10": x10.ast.X10MethodDecl_c
const x10aux::serialization_id_t x10::lang::System::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::lang::System::_deserializer<x10::lang::Object>);

void x10::lang::System::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::lang::System::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::lang::System::rtt;
void x10::lang::System::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.lang.System", 1, parents, 0, NULL, NULL);
}
