#include <x10/util/Option.h>


#include "x10/util/Option.inc"

namespace x10 { namespace util { 
class Option_ithunk0 : public x10::util::Option {
public:
    static x10::lang::Any::itable<Option_ithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(*this) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(*this) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::util::Option_methods::equals(*this, arg0);
    }
    x10_int hashCode() {
        return x10::util::Option_methods::hashCode(*this);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(*this));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::util::Option_methods::toString(*this);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(*this);
    }
    
};
x10::lang::Any::itable<Option_ithunk0 >  Option_ithunk0::itable(&Option_ithunk0::at, &Option_ithunk0::at, &Option_ithunk0::equals, &Option_ithunk0::hashCode, &Option_ithunk0::home, &Option_ithunk0::toString, &Option_ithunk0::typeName);
class Option_iboxithunk0 : public x10::lang::IBox<x10::util::Option> {
public:
    static x10::lang::Any::itable<Option_iboxithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(this->value) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(this->value) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::util::Option_methods::equals(this->value, arg0);
    }
    x10_int hashCode() {
        return x10::util::Option_methods::hashCode(this->value);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(this->value));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::util::Option_methods::toString(this->value);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(this->value);
    }
    
};
x10::lang::Any::itable<Option_iboxithunk0 >  Option_iboxithunk0::itable(&Option_iboxithunk0::at, &Option_iboxithunk0::at, &Option_iboxithunk0::equals, &Option_iboxithunk0::hashCode, &Option_iboxithunk0::home, &Option_iboxithunk0::toString, &Option_iboxithunk0::typeName);
} } 
x10aux::itable_entry x10::util::Option::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Option_ithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::Option>())};
x10aux::itable_entry x10::util::Option::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Option_iboxithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::util::Option>())};
void x10::util::Option_methods::_instance_init(x10::util::Option& this_) {
    _I_("Doing initialisation for class: x10::util::Option");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10FieldDecl_c

//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10FieldDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10FieldDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10ConstructorDecl_c
void x10::util::Option_methods::_constructor(x10::util::Option& this_, x10aux::ref<x10::lang::String> s,
                                             x10aux::ref<x10::lang::String> l,
                                             x10aux::ref<x10::lang::String> d)
{
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    this_->
      FMGL(short_) =
      ((x10::lang::String::Lit("-")) + (s));
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    this_->
      FMGL(long_) =
      ((x10::lang::String::Lit("--")) + (l));
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    this_->
      FMGL(description) =
      d;
    
}


//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c
x10_int x10::util::Option_methods::hashCode(x10::util::Option this_) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)0);
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(short_)))));
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(long_)))));
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(description)))));
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::util::Option_methods::equals(
  x10::util::Option this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::util::Option>(other))))
    {
        
        //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10Return_c
    return x10::util::Option_methods::equals(this_, 
             x10aux::class_cast<x10::util::Option>(other));
    
}

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::util::Option_methods::_struct_equals(
  x10::util::Option this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::util::Option>(other))))
    {
        
        //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10Return_c
    return x10::util::Option_methods::_struct_equals(this_, 
             x10aux::class_cast<x10::util::Option>(other));
    
}

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/util/Option.x10": x10.ast.X10MethodDecl_c
void x10::util::Option::_serialize(x10::util::Option this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(short_));
    buf.write(this_->FMGL(long_));
    buf.write(this_->FMGL(description));
    
}

void x10::util::Option::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(short_) = buf.read<x10aux::ref<x10::lang::String> >();
    FMGL(long_) = buf.read<x10aux::ref<x10::lang::String> >();
    FMGL(description) = buf.read<x10aux::ref<x10::lang::String> >();
}


x10_boolean x10::util::Option::equals(x10aux::ref<x10::lang::Any> that) {
    return x10::util::Option_methods::equals(*this, that);
}
x10_boolean x10::util::Option::equals(x10::util::Option that) {
    return x10::util::Option_methods::equals(*this, that);
}
x10_boolean x10::util::Option::_struct_equals(x10aux::ref<x10::lang::Any> that) {
    return x10::util::Option_methods::_struct_equals(*this, that);
}
x10_boolean x10::util::Option::_struct_equals(x10::util::Option that) {
    return x10::util::Option_methods::_struct_equals(*this, that);
}
x10aux::ref<x10::lang::String> x10::util::Option::toString() {
    return x10::util::Option_methods::toString(*this);
}
x10_int x10::util::Option::hashCode() {
    return x10::util::Option_methods::hashCode(*this);
}
x10aux::RuntimeType x10::util::Option::rtt;
void x10::util::Option::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.util.Option", 2, parents, 0, NULL, NULL);
}
