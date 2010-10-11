#include <x10/array/RectLayout.h>


#include "x10/array/RectLayout.inc"


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.PropertyDecl_c
namespace x10 { namespace array { 
class RectLayout_ithunk0 : public x10::array::RectLayout {
public:
    static x10::lang::Any::itable<RectLayout_ithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(*this) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(*this) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::array::RectLayout_methods::equals(*this, arg0);
    }
    x10_int hashCode() {
        return x10::array::RectLayout_methods::hashCode(*this);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(*this));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::array::RectLayout_methods::toString(*this);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(*this);
    }
    
};
x10::lang::Any::itable<RectLayout_ithunk0 >  RectLayout_ithunk0::itable(&RectLayout_ithunk0::at, &RectLayout_ithunk0::at, &RectLayout_ithunk0::equals, &RectLayout_ithunk0::hashCode, &RectLayout_ithunk0::home, &RectLayout_ithunk0::toString, &RectLayout_ithunk0::typeName);
class RectLayout_iboxithunk0 : public x10::lang::IBox<x10::array::RectLayout> {
public:
    static x10::lang::Any::itable<RectLayout_iboxithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(this->value) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(this->value) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::array::RectLayout_methods::equals(this->value, arg0);
    }
    x10_int hashCode() {
        return x10::array::RectLayout_methods::hashCode(this->value);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(this->value));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::array::RectLayout_methods::toString(this->value);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(this->value);
    }
    
};
x10::lang::Any::itable<RectLayout_iboxithunk0 >  RectLayout_iboxithunk0::itable(&RectLayout_iboxithunk0::at, &RectLayout_iboxithunk0::at, &RectLayout_iboxithunk0::equals, &RectLayout_iboxithunk0::hashCode, &RectLayout_iboxithunk0::home, &RectLayout_iboxithunk0::toString, &RectLayout_iboxithunk0::typeName);
} } 
x10aux::itable_entry x10::array::RectLayout::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &RectLayout_ithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::RectLayout>())};
x10aux::itable_entry x10::array::RectLayout::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &RectLayout_iboxithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::RectLayout>())};
void x10::array::RectLayout_methods::_instance_init(x10::array::RectLayout& this_) {
    _I_("Doing initialisation for class: x10::array::RectLayout");
    
}


//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10FieldDecl_c

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10ConstructorDecl_c
void x10::array::RectLayout_methods::_constructor(x10::array::RectLayout& this_, x10aux::ref<x10::lang::ValRail<x10_int > > min,
                                                  x10aux::ref<x10::lang::ValRail<x10_int > > max)
{
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::nullCheck(max)->
                                  FMGL(length),
                                x10aux::nullCheck(min)->
                                  FMGL(length))))
    {
        
        //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalArgumentException::_make(x10::lang::String::Lit("min and max must have same length"))));
    }
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10_int r =
      x10aux::nullCheck(min)->
        FMGL(length);
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(rank) =
      r;
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(min) =
      min;
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > d0 =
      x10::lang::ValRail<x10_int >::make(r, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectLayout__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectLayout__closure__0)))x10_array_RectLayout__closure__0(max, min)))));
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(delta) =
      d0;
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10_int size =
      ((x10_int)1);
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10_int> > d1678;
        for (
             //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
             d1678 =
               (d0)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(d1678))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10_int> >(((x10aux::ref<x10::lang::Reference>)d1678)->_getITables())->hasNext))();
             )
        {
            
            //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
            x10_int d =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(d1678))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10_int> >(((x10aux::ref<x10::lang::Reference>)d1678)->_getITables())->next))();
            
            //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
            size =
              ((x10_int) ((size) * (d)));
        }
    }
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(size) =
      size;
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(min0) =
      ((r) >= (((x10_int)1)))
      ? (x10_int)((min)->apply(((x10_int)0)))
      : (x10_int)(((x10_int)0));
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(min1) =
      ((r) >= (((x10_int)2)))
      ? (x10_int)((min)->apply(((x10_int)1)))
      : (x10_int)(((x10_int)0));
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(min2) =
      ((r) >= (((x10_int)3)))
      ? (x10_int)((min)->apply(((x10_int)2)))
      : (x10_int)(((x10_int)0));
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(min3) =
      ((r) >= (((x10_int)4)))
      ? (x10_int)((min)->apply(((x10_int)3)))
      : (x10_int)(((x10_int)0));
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(delta0) =
      ((r) >= (((x10_int)1)))
      ? (x10_int)((d0)->apply(((x10_int)0)))
      : (x10_int)(((x10_int)0));
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(delta1) =
      ((r) >= (((x10_int)2)))
      ? (x10_int)((d0)->apply(((x10_int)1)))
      : (x10_int)(((x10_int)0));
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(delta2) =
      ((r) >= (((x10_int)3)))
      ? (x10_int)((d0)->apply(((x10_int)2)))
      : (x10_int)(((x10_int)0));
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    this_->
      FMGL(delta3) =
      ((r) >= (((x10_int)4)))
      ? (x10_int)((d0)->apply(((x10_int)3)))
      : (x10_int)(((x10_int)0));
    
}


//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::RectLayout_methods::offset(x10::array::RectLayout this_, x10aux::ref<x10::array::Point> pt) {
    
    //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10_int offset = ((x10_int) ((x10aux::nullCheck(pt)->x10::array::Point::apply(
                                    ((x10_int)0))) - ((this_->
                                                         FMGL(min))->apply(((x10_int)0)))));
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (this_->
                                         FMGL(rank)));
             
             //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
            offset =
              ((x10_int) ((((x10_int) ((((x10_int) ((offset) * ((this_->
                                                                   FMGL(delta))->apply(i))))) + (x10aux::nullCheck(pt)->x10::array::Point::apply(
                                                                                                   i))))) - ((this_->
                                                                                                                FMGL(min))->apply(i))));
        }
    }
    
    //#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
    return offset;
    
}

//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 107 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::RectLayout_methods::toString(
  x10::array::RectLayout this_) {
    
    //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> s = x10::lang::String::Lit("RectLayout[");
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    s = ((s) + (((x10::lang::String::Lit("size=")) + (this_->
                                                        FMGL(size)))));
    
    //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(this_->
                                                           FMGL(min))->
                                         FMGL(length)));
             
             //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
            s =
              ((s) + (((((((x10::lang::String::Lit(",")) + ((this_->
                                                               FMGL(min))->apply(i)))) + (x10::lang::String::Lit("/")))) + ((this_->
                                                                                                                               FMGL(delta))->apply(i)))));
        }
    }
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    s = ((s) + (x10::lang::String::Lit("]")));
    
    //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
    return s;
    
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::RectLayout_methods::hashCode(
  x10::array::RectLayout this_) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)0);
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(rank)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(size)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(min)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(min0)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(min1)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(min2)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(min3)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(delta)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(delta0)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(delta1)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(delta2)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(delta3)))));
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectLayout_methods::equals(
  x10::array::RectLayout this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::array::RectLayout>(other))))
    {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
    return x10::array::RectLayout_methods::equals(this_, 
             x10aux::class_cast<x10::array::RectLayout>(other));
    
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectLayout_methods::_struct_equals(
  x10::array::RectLayout this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::array::RectLayout>(other))))
    {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
    return x10::array::RectLayout_methods::_struct_equals(this_, 
             x10aux::class_cast<x10::array::RectLayout>(other));
    
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10MethodDecl_c
void x10::array::RectLayout::_serialize(x10::array::RectLayout this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(size));
    buf.write(this_->FMGL(min));
    buf.write(this_->FMGL(min0));
    buf.write(this_->FMGL(min1));
    buf.write(this_->FMGL(min2));
    buf.write(this_->FMGL(min3));
    buf.write(this_->FMGL(delta));
    buf.write(this_->FMGL(delta0));
    buf.write(this_->FMGL(delta1));
    buf.write(this_->FMGL(delta2));
    buf.write(this_->FMGL(delta3));
    buf.write(this_->FMGL(rank));
    
}

void x10::array::RectLayout::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(size) = buf.read<x10_int>();
    FMGL(min) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
    FMGL(min0) = buf.read<x10_int>();
    FMGL(min1) = buf.read<x10_int>();
    FMGL(min2) = buf.read<x10_int>();
    FMGL(min3) = buf.read<x10_int>();
    FMGL(delta) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
    FMGL(delta0) = buf.read<x10_int>();
    FMGL(delta1) = buf.read<x10_int>();
    FMGL(delta2) = buf.read<x10_int>();
    FMGL(delta3) = buf.read<x10_int>();
    FMGL(rank) = buf.read<x10_int>();
}


x10_boolean x10::array::RectLayout::equals(x10aux::ref<x10::lang::Any> that) {
    return x10::array::RectLayout_methods::equals(*this, that);
}
x10_boolean x10::array::RectLayout::equals(x10::array::RectLayout that) {
    return x10::array::RectLayout_methods::equals(*this, that);
}
x10_boolean x10::array::RectLayout::_struct_equals(x10aux::ref<x10::lang::Any> that) {
    return x10::array::RectLayout_methods::_struct_equals(*this, that);
}
x10_boolean x10::array::RectLayout::_struct_equals(x10::array::RectLayout that) {
    return x10::array::RectLayout_methods::_struct_equals(*this, that);
}
x10aux::ref<x10::lang::String> x10::array::RectLayout::toString() {
    return x10::array::RectLayout_methods::toString(*this);
}
x10_int x10::array::RectLayout::hashCode() {
    return x10::array::RectLayout_methods::hashCode(*this);
}
x10aux::RuntimeType x10::array::RectLayout::rtt;
void x10::array::RectLayout::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.array.RectLayout", 2, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectLayout__closure__0>x10_array_RectLayout__closure__0::_itable(&x10_array_RectLayout__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectLayout__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectLayout__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectLayout__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectLayout__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectLayout__closure__0::_deserialize<x10::lang::Object>);

