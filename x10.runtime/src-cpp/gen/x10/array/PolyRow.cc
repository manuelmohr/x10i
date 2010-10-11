#include <x10/array/PolyRow.h>


#include "x10/array/PolyRow.inc"


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.PropertyDecl_c
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10::array::PolyRow >  x10::array::PolyRow::_itable_0(&x10::array::PolyRow::apply, &x10::array::PolyRow::at, &x10::array::PolyRow::at, &x10::array::PolyRow::equals, &x10::array::PolyRow::hashCode, &x10::array::PolyRow::home, &x10::array::PolyRow::toString, &x10::array::PolyRow::typeName);
x10::lang::Any::itable<x10::array::PolyRow >  x10::array::PolyRow::_itable_1(&x10::array::PolyRow::at, &x10::array::PolyRow::at, &x10::array::PolyRow::equals, &x10::array::PolyRow::hashCode, &x10::array::PolyRow::home, &x10::array::PolyRow::toString, &x10::array::PolyRow::typeName);
x10aux::itable_entry x10::array::PolyRow::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyRow>())};
void x10::array::PolyRow::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyRow");
    
}

 /* static type PolyRegion(val rank: x10.lang.Int) = x10.array.PolyRegion{self.rank==rank}; */ 
 /* static type PolyRow(val rank: x10.lang.Int) = x10.array.PolyRow{self.rank==rank}; */ 
 /* static type PolyMat(val rank: x10.lang.Int) = x10.array.PolyMat{self.rank==rank}; */ 

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRow::_constructor(x10aux::ref<x10::lang::ValRail<x10_int > > as_)
{
    this->_constructor(
      as_,
      ((x10_int) ((x10aux::nullCheck(as_)->
                     FMGL(length)) - (((x10_int)1)))));
    
}
x10aux::ref<x10::array::PolyRow> x10::array::PolyRow::_make(
  x10aux::ref<x10::lang::ValRail<x10_int > > as_)
{
    x10aux::ref<x10::array::PolyRow> this_ = new (memset(x10aux::alloc<x10::array::PolyRow>(), 0, sizeof(x10::array::PolyRow))) x10::array::PolyRow();
    this_->_constructor(as_);
    return this_;
}



//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRow::_constructor(x10aux::ref<x10::lang::ValRail<x10_int > > as_,
                                       x10_int n) {
    this->x10::array::ValRow::_constructor(as_);
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyRow>)this)->FMGL(rank) =
      n;
    
}
x10aux::ref<x10::array::PolyRow> x10::array::PolyRow::_make(
  x10aux::ref<x10::lang::ValRail<x10_int > > as_,
  x10_int n) {
    x10aux::ref<x10::array::PolyRow> this_ = new (memset(x10aux::alloc<x10::array::PolyRow>(), 0, sizeof(x10::array::PolyRow))) x10::array::PolyRow();
    this_->_constructor(as_, n);
    return this_;
}



//#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRow::_constructor(x10aux::ref<x10::array::Point> p,
                                       x10_int k) {
    this->x10::array::ValRow::_constructor(((x10_int) ((x10aux::nullCheck(p)->
                                                          FMGL(rank)) + (((x10_int)1)))),
                                           x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyRow__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyRow__closure__0)))x10_array_PolyRow__closure__0(p, k))));
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyRow>)this)->FMGL(rank) =
      x10aux::nullCheck(p)->
        FMGL(rank);
    
}
x10aux::ref<x10::array::PolyRow> x10::array::PolyRow::_make(
  x10aux::ref<x10::array::Point> p,
  x10_int k) {
    x10aux::ref<x10::array::PolyRow> this_ = new (memset(x10aux::alloc<x10::array::PolyRow>(), 0, sizeof(x10::array::PolyRow))) x10::array::PolyRow();
    this_->_constructor(p, k);
    return this_;
}



//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRow::_constructor(x10_int cols,
                                       x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    this->x10::array::ValRow::_constructor(
      cols,
      init);
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyRow>)this)->
      FMGL(rank) =
      ((x10_int) ((cols) - (((x10_int)1))));
    
}
x10aux::ref<x10::array::PolyRow> x10::array::PolyRow::_make(
  x10_int cols,
  x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init)
{
    x10aux::ref<x10::array::PolyRow> this_ = new (memset(x10aux::alloc<x10::array::PolyRow>(), 0, sizeof(x10::array::PolyRow))) x10::array::PolyRow();
    this_->_constructor(cols,
    init);
    return this_;
}



//#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyRow::compare(x10aux::ref<x10::array::Row> a,
                                     x10aux::ref<x10::array::Row> b) {
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(a)->
                                         FMGL(cols)));
             
             //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(a)->apply(
                    i)) < (x10aux::nullCheck(b)->apply(
                             i))))
            {
                
                //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
                return ((x10_int)-1);
                
            }
            else
            
            //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(a)->apply(
                    i)) > (x10aux::nullCheck(b)->apply(
                             i))))
            {
                
                //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
                return ((x10_int)1);
                
            }
            
        }
    }
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return ((x10_int)0);
    
}

//#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRow::isParallel(
  x10aux::ref<x10::array::PolyRow> that) {
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                      FMGL(cols)) - (((x10_int)1))))));
             
             //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                          i),
                                        x10aux::nullCheck(that)->apply(
                                          i))))
            {
                
                //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRow::isRect() {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10_boolean nz = false;
    
    //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                      FMGL(cols)) - (((x10_int)1))))));
             
             //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                          i),
                                        ((x10_int)0))))
            {
                
                //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
                if (nz)
                {
                    
                    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
                    return false;
                    
                }
                
                //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                nz =
                  true;
            }
            
        }
    }
    
    //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRow::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10_int sum = ((x10aux::ref<x10::array::PolyRow>)this)->apply(
                    ((x10aux::ref<x10::array::PolyRow>)this)->
                      FMGL(rank));
    
    //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyRow>)this)->
                                         FMGL(rank)));
             
             //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
            sum =
              ((x10_int) ((sum) + (((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                                  i)) * (x10aux::nullCheck(p)->x10::array::Point::apply(
                                                           i)))))));
        }
    }
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return ((sum) <= (((x10_int)0)));
    
}

//#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyRow> x10::array::PolyRow::complement(
  ) {
    
    //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyRow__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyRow__closure__1)))x10_array_PolyRow__closure__1(this))));
    
    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > as_ =
      x10::lang::ValRail<x10_int >::make(((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                        FMGL(rank)) + (((x10_int)1)))), init);
    
    //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return x10::array::PolyRow::_make(as_);
    
}

//#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyRow::printEqn(x10aux::ref<x10::io::Printer> ps,
                                   x10aux::ref<x10::lang::String> spc,
                                   x10_int row) {
    
    //#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10_int sgn = ((x10_int)0);
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
    x10_boolean first = true;
    
    //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                      FMGL(cols)) - (((x10_int)1))))));
             
             //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(sgn,
                                       ((x10_int)0))))
            {
                
                //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
                if (((((x10aux::ref<x10::array::PolyRow>)this)->apply(
                        i)) < (((x10_int)0))))
                {
                    
                    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                    sgn =
                      ((x10_int)-1);
                }
                else
                
                //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
                if (((((x10aux::ref<x10::array::PolyRow>)this)->apply(
                        i)) > (((x10_int)0))))
                {
                    
                    //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                    sgn =
                      ((x10_int)1);
                }
                
            }
            
            //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10LocalDecl_c
            x10_int c =
              ((x10_int) ((sgn) * (((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                     i))));
            
            //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(c,
                                       ((x10_int)1))))
            {
                
                //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
                if (first)
                {
                    
                    //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      ((x10::lang::String::Lit("x")) + (i)));
                }
                else
                {
                    
                    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      ((x10::lang::String::Lit("+x")) + (i)));
                }
                
            }
            else
            
            //#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(c,
                                       ((x10_int)-1))))
            {
                
                //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(ps)->print(
                  ((x10::lang::String::Lit("-x")) + (i)));
            }
            else
            
            //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(c,
                                        ((x10_int)0))))
            {
                
                //#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(ps)->print(
                  ((((((((((c) >= (((x10_int)0))) &&
                  (!(first))
                    ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("+"))
                    : (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit(""))) + (c))) + (x10::lang::String::Lit("*x")))) + (i))) + (x10::lang::String::Lit(" "))));
            }
            
            //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(c,
                                        ((x10_int)0))))
            {
                
                //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
                first =
                  false;
            }
            
        }
    }
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
    if (first) {
        
        //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(ps)->print(x10::lang::String::Lit("0"));
    }
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10If_c
    if (((sgn) > (((x10_int)0)))) {
        
        //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(ps)->print(((((((spc) + (x10::lang::String::Lit("<=")))) + (spc))) + (((x10_int) -(((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                                                                                               ((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                                                                                              FMGL(cols)) - (((x10_int)1))))))))));
    } else {
        
        //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(ps)->print(((((((spc) + (x10::lang::String::Lit(">=")))) + (spc))) + (((x10aux::ref<x10::array::PolyRow>)this)->apply(
                                                                                                  ((x10_int) ((((x10aux::ref<x10::array::PolyRow>)this)->
                                                                                                                 FMGL(cols)) - (((x10_int)1))))))));
    }
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyRow::rank() {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRow.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyRow>)this)->
             FMGL(rank);
    
}
const x10aux::serialization_id_t x10::array::PolyRow::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyRow::_deserializer<x10::lang::Object>);

void x10::array::PolyRow::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::ValRow::_serialize_body(buf);
    buf.write(this->FMGL(rank));
    
}

void x10::array::PolyRow::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::ValRow::_deserialize_body(buf);
    FMGL(rank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::PolyRow::rtt;
void x10::array::PolyRow::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::ValRow>()};
    rtt.initStageTwo("x10.array.PolyRow", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyRow__closure__0>x10_array_PolyRow__closure__0::_itable(&x10_array_PolyRow__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyRow__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyRow__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyRow__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyRow__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyRow__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyRow__closure__1>x10_array_PolyRow__closure__1::_itable(&x10_array_PolyRow__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyRow__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyRow__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyRow__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyRow__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyRow__closure__1::_deserialize<x10::lang::Object>);

