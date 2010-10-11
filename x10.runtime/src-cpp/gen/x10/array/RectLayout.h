#ifndef __X10_ARRAY_RECTLAYOUT_H
#define __X10_ARRAY_RECTLAYOUT_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
class IllegalArgumentException;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace compiler { 
class Header;
} } 
namespace x10 { namespace compiler { 
class Inline;
} } 
namespace x10 { namespace array { 
class Point;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Place;
} } 
#include <x10/lang/Place.struct_h>
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace lang { 
class Object;
} } 
#include <x10/array/RectLayout.struct_h>

namespace x10 { namespace array { 

class RectLayout_methods  {
    public:
    static void _instance_init(x10::array::RectLayout& this_);
    
    static void _constructor(x10::array::RectLayout& this_, x10aux::ref<x10::lang::ValRail<x10_int > > min,
                             x10aux::ref<x10::lang::ValRail<x10_int > > max);
    
    inline static x10::array::RectLayout _make(x10aux::ref<x10::lang::ValRail<x10_int > > min,
                                               x10aux::ref<x10::lang::ValRail<x10_int > > max)
    {
        x10::array::RectLayout this_; 
        _constructor(this_, min,
        max);
        return this_;
    }
    
    static x10_int
      size(
      x10::array::RectLayout this_) {
        
        //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return this_->
                 FMGL(size);
        
    }
    static x10_int
      offset(
      x10::array::RectLayout this_, x10aux::ref<x10::array::Point> pt);
    static x10_int
      offset(
      x10::array::RectLayout this_, x10_int i0) {
        
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
        x10_int offset =
          ((x10_int) ((i0) - (this_->
                                FMGL(min0))));
        
        //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return offset;
        
    }
    static x10_int
      offset(
      x10::array::RectLayout this_, x10_int i0,
      x10_int i1) {
        
        //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
        x10_int offset =
          ((x10_int) ((i0) - (this_->
                                FMGL(min0))));
        
        //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta1))))) + (i1)))) - (this_->
                                                                                              FMGL(min1))));
        
        //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return offset;
        
    }
    static x10_int
      offset(
      x10::array::RectLayout this_, x10_int i0,
      x10_int i1,
      x10_int i2) {
        
        //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
        x10_int offset =
          ((x10_int) ((i0) - (this_->
                                FMGL(min0))));
        
        //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta1))))) + (i1)))) - (this_->
                                                                                              FMGL(min1))));
        
        //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta2))))) + (i2)))) - (this_->
                                                                                              FMGL(min2))));
        
        //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return offset;
        
    }
    static x10_int
      offset(
      x10::array::RectLayout this_, x10_int i0,
      x10_int i1,
      x10_int i2,
      x10_int i3) {
        
        //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
        x10_int offset =
          ((x10_int) ((i0) - (this_->
                                FMGL(min0))));
        
        //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta1))))) + (i1)))) - (this_->
                                                                                              FMGL(min1))));
        
        //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta2))))) + (i2)))) - (this_->
                                                                                              FMGL(min2))));
        
        //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
        offset =
          ((x10_int) ((((x10_int) ((((x10_int) ((offset) * (this_->
                                                              FMGL(delta3))))) + (i3)))) - (this_->
                                                                                              FMGL(min3))));
        
        //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return offset;
        
    }
    static x10aux::ref<x10::lang::String>
      toString(
      x10::array::RectLayout this_);
    static x10_int
      rank(
      x10::array::RectLayout this_) {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return this_->
                 FMGL(rank);
        
    }
    static x10_int
      hashCode(
      x10::array::RectLayout this_);
    static x10_boolean
      equals(
      x10::array::RectLayout this_, x10aux::ref<x10::lang::Any> other);
    static x10_boolean
      equals(
      x10::array::RectLayout this_, x10::array::RectLayout other) {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(this_->
                                        FMGL(rank),
                                      other->
                                        FMGL(rank))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(size),
                               other->
                                 FMGL(size))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min),
                               other->
                                 FMGL(min))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min0),
                               other->
                                 FMGL(min0))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min1),
                               other->
                                 FMGL(min1))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min2),
                               other->
                                 FMGL(min2))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min3),
                               other->
                                 FMGL(min3))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta),
                               other->
                                 FMGL(delta))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta0),
                               other->
                                 FMGL(delta0))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta1),
                               other->
                                 FMGL(delta1))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta2),
                               other->
                                 FMGL(delta2))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta3),
                               other->
                                 FMGL(delta3)));
        
    }
    static x10_boolean
      _struct_equals(
      x10::array::RectLayout this_, x10aux::ref<x10::lang::Any> other);
    static x10_boolean
      _struct_equals(
      x10::array::RectLayout this_, x10::array::RectLayout other) {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return (x10aux::struct_equals(this_->
                                        FMGL(rank),
                                      other->
                                        FMGL(rank))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(size),
                               other->
                                 FMGL(size))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min),
                               other->
                                 FMGL(min))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min0),
                               other->
                                 FMGL(min0))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min1),
                               other->
                                 FMGL(min1))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min2),
                               other->
                                 FMGL(min2))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(min3),
                               other->
                                 FMGL(min3))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta),
                               other->
                                 FMGL(delta))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta0),
                               other->
                                 FMGL(delta0))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta1),
                               other->
                                 FMGL(delta1))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta2),
                               other->
                                 FMGL(delta2))) &&
        (x10aux::struct_equals(this_->
                                 FMGL(delta3),
                               other->
                                 FMGL(delta3)));
        
    }
    
};

} } 
#endif // X10_ARRAY_RECTLAYOUT_H

namespace x10 { namespace array { 
class RectLayout;
} } 

#ifndef X10_ARRAY_RECTLAYOUT_H_NODEPS
#define X10_ARRAY_RECTLAYOUT_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/lang/Any.h>
#include <x10/lang/Int.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/IllegalArgumentException.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterator.h>
#include <x10/compiler/Header.h>
#include <x10/compiler/Inline.h>
#include <x10/array/Point.h>
#include <x10/lang/String.h>
#include <x10/lang/Place.h>
#include <x10/compiler/Native.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/Object.h>
#ifndef X10_ARRAY_RECTLAYOUT_H_GENERICS
#define X10_ARRAY_RECTLAYOUT_H_GENERICS
#endif // X10_ARRAY_RECTLAYOUT_H_GENERICS
#endif // __X10_ARRAY_RECTLAYOUT_H_NODEPS
