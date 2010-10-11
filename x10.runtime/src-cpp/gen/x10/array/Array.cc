#include <x10/array/Array.h>

x10aux::RuntimeType x10::array::Array<void>::rtt;
void x10::array::Array<void>::raiseBoundsError(x10_int i0) {
                                                               
                                                               //#line 858 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
                                                               x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((x10::lang::String::Lit("point (")) + (i0))) + (x10::lang::String::Lit(") not contained in array"))))));
                                                           }
void x10::array::Array<void>::raiseBoundsError(x10_int i0, x10_int i1) {
                                                                           
                                                                           //#line 861 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
                                                                           x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((((((x10::lang::String::Lit("point (")) + (i0))) + (x10::lang::String::Lit(", ")))) + (i1))) + (x10::lang::String::Lit(") not contained in array"))))));
                                                                       }
void x10::array::Array<void>::raiseBoundsError(x10_int i0, x10_int i1, x10_int i2)
{
    
    //#line 864 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((((((((((x10::lang::String::Lit("point (")) + (i0))) + (x10::lang::String::Lit(", ")))) + (i1))) + (x10::lang::String::Lit(", ")))) + (i2))) + (x10::lang::String::Lit(") not contained in array"))))));
}
void
  x10::array::Array<void>::raiseBoundsError(x10_int i0,
                                            x10_int i1,
                                            x10_int i2,
                                            x10_int i3)
{
    
    //#line 867 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((((((((((((((x10::lang::String::Lit("point (")) + (i0))) + (x10::lang::String::Lit(", ")))) + (i1))) + (x10::lang::String::Lit(", ")))) + (i2))) + (x10::lang::String::Lit(", ")))) + (i3))) + (x10::lang::String::Lit(") not contained in array"))))));
}
void
  x10::array::Array<void>::raiseBoundsError(x10aux::ref<x10::array::Point> pt)
{
    
    //#line 870 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Array.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((x10::lang::String::Lit("point ")) + (pt))) + (x10::lang::String::Lit(" not contained in array"))))));
}

