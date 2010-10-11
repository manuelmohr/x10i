#include <x10/array/Row.h>


#include "x10/array/Row.inc"


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.PropertyDecl_c
void x10::array::Row::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Row");
    
}


//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c

//#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10ConstructorDecl_c
void x10::array::Row::_constructor(x10_int cols) {
    this->x10::lang::Object::_constructor();
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Row>)this)->FMGL(cols) = cols;
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c
void x10::array::Row::printInfo(x10aux::ref<x10::io::Printer> ps, x10_int row) {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->print(x10::lang::String::Lit("["));
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Row>)this)->
                                         FMGL(cols))); 
                                                       //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                                                       i = ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(ps)->x10::io::Printer::print(
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(((x10aux::ref<x10::array::Row>)this)->apply(
                                                                           i)));
            
            //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(i,
                                       ((x10_int) ((((x10aux::ref<x10::array::Row>)this)->
                                                      FMGL(cols)) - (((x10_int)2)))))))
            {
                
                //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(ps)->print(
                  x10::lang::String::Lit(" |"));
            }
            
        }
    }
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->print(x10::lang::String::Lit(" ]   "));
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Row>)this)->printEqn(
      ps,
      x10::lang::String::Lit(" "),
      row);
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->println();
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c
void x10::array::Row::printEqn(x10aux::ref<x10::io::Printer> ps,
                               x10aux::ref<x10::lang::String> spc,
                               x10_int row) {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
    x10_boolean first = true;
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->print(((((x10::lang::String::Lit("y")) + (row))) + (x10::lang::String::Lit(" = "))));
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::Row>)this)->
                                                      FMGL(cols)) - (((x10_int)1))))));
             
             //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
            x10_int c =
              ((x10aux::ref<x10::array::Row>)this)->apply(
                i);
            
            //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(c,
                                       ((x10_int)1))))
            {
                
                //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
                if (first)
                {
                    
                    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      ((x10::lang::String::Lit("x")) + (i)));
                }
                else
                {
                    
                    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      ((x10::lang::String::Lit("+x")) + (i)));
                }
                
            }
            else
            
            //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(c,
                                       ((x10_int)-1))))
            {
                
                //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(ps)->print(
                  ((x10::lang::String::Lit("-x")) + (i)));
            }
            else
            
            //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(c,
                                        ((x10_int)0))))
            {
                
                //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(ps)->print(
                  ((((((((((c) >= (((x10_int)0))) &&
                  (!(first))
                    ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("+"))
                    : (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit(""))) + (c))) + (x10::lang::String::Lit("*x")))) + (i))) + (x10::lang::String::Lit(" "))));
            }
            
            //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(c,
                                        ((x10_int)0))))
            {
                
                //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
                first =
                  false;
            }
            
        }
    }
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
    x10_int c = ((x10aux::ref<x10::array::Row>)this)->apply(
                  ((x10_int) ((((x10aux::ref<x10::array::Row>)this)->
                                 FMGL(cols)) - (((x10_int)1)))));
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(c, ((x10_int)0))) ||
        first) {
        
        //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(ps)->print(((((c) >= (((x10_int)0))) &&
                                     (!(first))
                                       ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("+"))
                                       : (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit(""))) + (c)));
    }
    
}

//#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::Row::toString(
  ) {
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::io::StringWriter> os =
      x10::io::StringWriter::_make();
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::io::Printer> ps = x10::io::Printer::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Writer> >(os));
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Row>)this)->printEqn(
      ps,
      x10::lang::String::Lit(""),
      ((x10_int)0));
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10Return_c
    return os->result();
    
}

//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Row::cols() {
    
    //#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Row.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Row>)this)->
             FMGL(cols);
    
}
void x10::array::Row::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(cols));
    
}

void x10::array::Row::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(cols) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::Row::rtt;
void x10::array::Row::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >()};
    rtt.initStageTwo("x10.array.Row", 2, parents, 0, NULL, NULL);
}
