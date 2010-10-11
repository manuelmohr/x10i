#include <x10/util/OptionsParser__Err.h>


#include "x10/util/OptionsParser__Err.inc"

void x10::util::OptionsParser__Err::_instance_init() {
    _I_("Doing initialisation for class: x10::util::OptionsParser__Err");
    
}


//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10FieldDecl_c

//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10ConstructorDecl_c
void x10::util::OptionsParser__Err::_constructor(x10aux::ref<x10::lang::String> m)
{
    this->x10::lang::Exception::_constructor();
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::util::OptionsParser__Err>)this)->
      FMGL(msg) =
      m;
    
}
x10aux::ref<x10::util::OptionsParser__Err> x10::util::OptionsParser__Err::_make(
  x10aux::ref<x10::lang::String> m)
{
    x10aux::ref<x10::util::OptionsParser__Err> this_ = new (memset(x10aux::alloc<x10::util::OptionsParser__Err>(), 0, sizeof(x10::util::OptionsParser__Err))) x10::util::OptionsParser__Err();
    this_->_constructor(m);
    return this_;
}



//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::util::OptionsParser__Err::toString(
  ) {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/OptionsParser.x10": x10.ast.X10Return_c
    return ((x10::lang::String::Lit("Commandline error: ")) + (((x10aux::ref<x10::util::OptionsParser__Err>)this)->
                                                                 FMGL(msg)));
    
}
const x10aux::serialization_id_t x10::util::OptionsParser__Err::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::util::OptionsParser__Err::_deserializer<x10::lang::Object>);

void x10::util::OptionsParser__Err::_serialize(x10aux::ref<x10::util::OptionsParser__Err> this_,
                                               x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::util::OptionsParser__Err::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Exception::_serialize_body(buf);
    buf.write(this->FMGL(msg));
    
}

void x10::util::OptionsParser__Err::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Exception::_deserialize_body(buf);
    FMGL(msg) = buf.read<x10aux::ref<x10::lang::String> >();
}

x10aux::RuntimeType x10::util::OptionsParser__Err::rtt;
void x10::util::OptionsParser__Err::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Exception>()};
    rtt.initStageTwo("x10.util.OptionsParser$Err", 1, parents, 0, NULL, NULL);
}
