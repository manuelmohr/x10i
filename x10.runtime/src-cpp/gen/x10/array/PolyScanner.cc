#include <x10/array/PolyScanner.h>


#include "x10/array/PolyScanner.inc"


//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.PropertyDecl_c
x10::array::Region__Scanner::itable<x10::array::PolyScanner >  x10::array::PolyScanner::_itable_0(&x10::array::PolyScanner::at, &x10::array::PolyScanner::at, &x10::array::PolyScanner::equals, &x10::array::PolyScanner::hashCode, &x10::array::PolyScanner::home, &x10::array::PolyScanner::max, &x10::array::PolyScanner::min, &x10::array::PolyScanner::set, &x10::array::PolyScanner::toString, &x10::array::PolyScanner::typeName);
x10::lang::Any::itable<x10::array::PolyScanner >  x10::array::PolyScanner::_itable_1(&x10::array::PolyScanner::at, &x10::array::PolyScanner::at, &x10::array::PolyScanner::equals, &x10::array::PolyScanner::hashCode, &x10::array::PolyScanner::home, &x10::array::PolyScanner::toString, &x10::array::PolyScanner::typeName);
x10aux::itable_entry x10::array::PolyScanner::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::array::Region__Scanner>, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyScanner>())};
void x10::array::PolyScanner::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyScanner");
    
}


//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyScanner> x10::array::PolyScanner::make(x10aux::ref<x10::array::PolyMat> pm) {
    
    //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyScanner> x = x10::array::PolyScanner::_make(pm);
    
    //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x->x10::array::PolyScanner::init();
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return x;
    
}

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyScanner::_constructor(x10aux::ref<x10::array::PolyMat> pm)
{
    this->x10::lang::Object::_constructor();
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyScanner>)this)->
      FMGL(rank) =
      x10aux::nullCheck(pm)->
        FMGL(rank);
    
    //#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm0 =
      x10aux::nullCheck(pm)->simplifyAll();
    
    //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(C) =
      pm;
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10_int r =
      x10aux::nullCheck(pm0)->
        FMGL(rank);
    
    //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > n =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::VarMat> >(r);
    
    //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(myMin) =
      n;
    
    //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > x =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::VarMat> >(r);
    
    //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(myMax) =
      x;
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > nSum =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::VarMat> >(r);
    
    //#line 100 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(minSum) =
      nSum;
    
    //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::VarMat> > > xSum =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::VarMat> >(r);
    
    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(maxSum) =
      xSum;
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > > > n2 =
      x10::lang::Rail<void>::make<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > >(r);
    
    //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(min2) =
      n2;
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > > > x2 =
      x10::lang::Rail<void>::make<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::PolyRow> > > >(r);
    
    //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(max2) =
      x2;
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner>)this))->
      FMGL(parFlags) =
      x10::lang::Rail<void>::make<x10_boolean >(r);
    
}
x10aux::ref<x10::array::PolyScanner> x10::array::PolyScanner::_make(
  x10aux::ref<x10::array::PolyMat> pm)
{
    x10aux::ref<x10::array::PolyScanner> this_ = new (memset(x10aux::alloc<x10::array::PolyScanner>(), 0, sizeof(x10::array::PolyScanner))) x10::array::PolyScanner();
    this_->_constructor(pm);
    return this_;
}



//#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner::init() {
    
    //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm = ((x10aux::ref<x10::array::PolyScanner>)this)->
                                            FMGL(C);
    
    //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyScanner>)this)->x10::array::PolyScanner::init(
      pm,
      ((x10_int) ((((x10aux::ref<x10::array::PolyScanner>)this)->
                     FMGL(rank)) - (((x10_int)1)))));
    
    //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int) ((((x10aux::ref<x10::array::PolyScanner>)this)->
                                FMGL(rank)) - (((x10_int)2))));
             ((k) >= (((x10_int)0)));
             
             //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) - (((x10_int)1)))))
        {
            
            //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            pm =
              x10aux::nullCheck(pm)->eliminate(
                ((x10_int) ((k) + (((x10_int)1)))),
                true);
            
            //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::array::PolyScanner>)this)->x10::array::PolyScanner::init(
              pm,
              k);
        }
    }
    
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner::init(x10aux::ref<x10::array::PolyMat> pm,
                                   x10_int axis) {
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10_int imin = ((x10_int)0);
    
    //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10_int imax = ((x10_int)0);
    
    //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1656;
        for (
             //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             r1656 = x10aux::nullCheck(pm)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1656))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1656)->_getITables())->hasNext))();
             ) {
            
            //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1656))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1656)->_getITables())->next))();
            
            //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(r)->apply(
                    axis)) < (((x10_int)0))))
            {
                
                //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                imin =
                  ((x10_int) ((imin) + (((x10_int)1))));
            }
            
            //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(r)->apply(
                    axis)) > (((x10_int)0))))
            {
                
                //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                imax =
                  ((x10_int) ((imax) + (((x10_int)1))));
            }
            
        }
    }
    
    //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(imin, ((x10_int)0))) ||
        (x10aux::struct_equals(imax,
                               ((x10_int)0))))
    {
        
        //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::String> m =
          (x10aux::struct_equals(imin,
                                 ((x10_int)0)))
          ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("minimum"))
          : (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("maximum"));
        
        //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::String> msg =
          ((((((x10::lang::String::Lit("axis ")) + (axis))) + (x10::lang::String::Lit(" has no ")))) + (m));
        
        //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::array::UnboundedRegionException::_make(msg)));
    }
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(myMin))->set(x10::array::VarMat::_make(imin,
                                                   ((x10_int) ((axis) + (((x10_int)1))))), axis);
    
    //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(myMax))->set(x10::array::VarMat::_make(imax,
                                                   ((x10_int) ((axis) + (((x10_int)1))))), axis);
    
    //#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(minSum))->set(x10::array::VarMat::_make(imin,
                                                    ((x10_int) ((axis) + (((x10_int)1))))), axis);
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(maxSum))->set(x10::array::VarMat::_make(imax,
                                                    ((x10_int) ((axis) + (((x10_int)1))))), axis);
    
    //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(min2))->set(x10::lang::Rail<void>::make<x10aux::ref<x10::array::PolyRow> >(imin), axis);
    
    //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner>)this)->
       FMGL(max2))->set(x10::lang::Rail<void>::make<x10aux::ref<x10::array::PolyRow> >(imax), axis);
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    imin = ((x10_int)0);
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    imax = ((x10_int)0);
    
    //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1657;
        for (
             //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             r1657 = x10aux::nullCheck(pm)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1657))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1657)->_getITables())->hasNext))();
             ) {
            
            //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1657))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1657)->_getITables())->next))();
            
            //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(r)->apply(
                    axis)) < (((x10_int)0))))
            {
                
                //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                {
                    x10_int i;
                    for (
                         //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                         i =
                           ((x10_int)0);
                         ((i) <= (axis));
                         
                         //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                         i =
                           ((x10_int) ((i) + (((x10_int)1)))))
                    {
                        
                        //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                        x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                               FMGL(myMin))->apply(axis))->x10::array::VarMat::apply(
                                            imin))->x10::array::VarRow::set(
                          x10aux::nullCheck(r)->apply(
                            i),
                          i);
                    }
                }
                
                //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                       FMGL(minSum))->apply(axis))->x10::array::VarMat::apply(
                                    imin))->x10::array::VarRow::set(
                  x10aux::nullCheck(r)->apply(
                    ((x10aux::ref<x10::array::PolyScanner>)this)->
                      FMGL(rank)),
                  ((x10_int)0));
                
                //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                ((((x10aux::ref<x10::array::PolyScanner>)this)->
                    FMGL(min2))->apply(axis))->set(r, imin);
                
                //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                imin =
                  ((x10_int) ((imin) + (((x10_int)1))));
            }
            
            //#line 159 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(r)->apply(
                    axis)) > (((x10_int)0))))
            {
                
                //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                {
                    x10_int i;
                    for (
                         //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                         i =
                           ((x10_int)0);
                         ((i) <= (axis));
                         
                         //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                         i =
                           ((x10_int) ((i) + (((x10_int)1)))))
                    {
                        
                        //#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                        x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                               FMGL(myMax))->apply(axis))->x10::array::VarMat::apply(
                                            imax))->x10::array::VarRow::set(
                          x10aux::nullCheck(r)->apply(
                            i),
                          i);
                    }
                }
                
                //#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                       FMGL(maxSum))->apply(axis))->x10::array::VarMat::apply(
                                    imax))->x10::array::VarRow::set(
                  x10aux::nullCheck(r)->apply(
                    ((x10aux::ref<x10::array::PolyScanner>)this)->
                      FMGL(rank)),
                  ((x10_int)0));
                
                //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                ((((x10aux::ref<x10::array::PolyScanner>)this)->
                    FMGL(max2))->apply(axis))->set(r, imax);
                
                //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                imax =
                  ((x10_int) ((imax) + (((x10_int)1))));
            }
            
        }
    }
    
}

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner::set(x10_int axis,
                                  x10_int v) {
    
    //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int) ((axis) + (((x10_int)1))));
             ((k) < (((x10aux::ref<x10::array::PolyScanner>)this)->
                       FMGL(rank)));
             
             //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
            {
                x10_int l;
                for (
                     //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                     l =
                       ((x10_int)0);
                     ((l) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                  FMGL(minSum))->apply(k))->
                               FMGL(rows)));
                     
                     //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                     l =
                       ((x10_int) ((l) + (((x10_int)1)))))
                {
                    
                    //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                           FMGL(minSum))->apply(k))->x10::array::VarMat::apply(
                                        l))->x10::array::VarRow::set(
                      ((x10_int) ((((x10_int) ((x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                       FMGL(myMin))->apply(k))->x10::array::VarMat::apply(
                                                                    l))->x10::array::VarRow::apply(
                                                  axis)) * (v)))) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                            FMGL(minSum))->apply(k))->x10::array::VarMat::apply(
                                                                                         l))->x10::array::VarRow::apply(
                                                                       axis)))),
                      ((x10_int) ((axis) + (((x10_int)1)))));
                }
            }
            
        }
    }
    
    //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int) ((axis) + (((x10_int)1))));
             ((k) < (((x10aux::ref<x10::array::PolyScanner>)this)->
                       FMGL(rank)));
             
             //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
            {
                x10_int l;
                for (
                     //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                     l =
                       ((x10_int)0);
                     ((l) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                  FMGL(maxSum))->apply(k))->
                               FMGL(rows)));
                     
                     //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                     l =
                       ((x10_int) ((l) + (((x10_int)1)))))
                {
                    
                    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                           FMGL(maxSum))->apply(k))->x10::array::VarMat::apply(
                                        l))->x10::array::VarRow::set(
                      ((x10_int) ((((x10_int) ((x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                       FMGL(myMax))->apply(k))->x10::array::VarMat::apply(
                                                                    l))->x10::array::VarRow::apply(
                                                  axis)) * (v)))) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                            FMGL(maxSum))->apply(k))->x10::array::VarMat::apply(
                                                                                         l))->x10::array::VarRow::apply(
                                                                       axis)))),
                      ((x10_int) ((axis) + (((x10_int)1)))));
                }
            }
            
        }
    }
    
}

//#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyScanner::min(x10_int axis) {
    
    //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)0x80000000);
    
    //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                            FMGL(myMin))->apply(axis))->
                                         FMGL(rows)));
             
             //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                     FMGL(myMin))->apply(axis))->x10::array::VarMat::apply(
                                  k))->x10::array::VarRow::apply(
                axis);
            
            //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                     FMGL(minSum))->apply(axis))->x10::array::VarMat::apply(
                                  k))->x10::array::VarRow::apply(
                axis);
            
            //#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int m =
              ((b) > (((x10_int)0)))
              ? (x10_int)(((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) -(b))) + (a)))) + (((x10_int)1))))) / (a))))
              : (x10_int)(((x10_int) ((((x10_int) -(b))) / (a))));
            
            //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((m) > (result)))
            {
                
                //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                result =
                  m;
            }
            
        }
    }
    
    //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyScanner::max(x10_int axis) {
    
    //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)0x7fffffff);
    
    //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                            FMGL(myMax))->apply(axis))->
                                         FMGL(rows)));
             
             //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                     FMGL(myMax))->apply(axis))->x10::array::VarMat::apply(
                                  k))->x10::array::VarRow::apply(
                axis);
            
            //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                     FMGL(maxSum))->apply(axis))->x10::array::VarMat::apply(
                                  k))->x10::array::VarRow::apply(
                axis);
            
            //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int m =
              ((b) > (((x10_int)0)))
              ? (x10_int)(((x10_int) ((((x10_int) ((((x10_int) ((((x10_int) -(b))) - (a)))) + (((x10_int)1))))) / (a))))
              : (x10_int)(((x10_int) ((((x10_int) -(b))) / (a))));
            
            //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if (((m) < (result)))
            {
                
                //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                result =
                  m;
            }
            
        }
    }
    
    //#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 297 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::PolyScanner::iterator(
  ) {
    
    //#line 298 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyScanner__PointIt> it =
      x10::array::PolyScanner__PointIt::_make(((x10aux::ref<x10::array::PolyScanner>)this));
    
    //#line 299 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(it->FMGL(it))->x10::array::PolyScanner__RailIt::init();
    
    //#line 300 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > >(it);
    
}

//#line 309 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner::printInfo(x10aux::ref<x10::io::Printer> ps) {
    
    //#line 310 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->x10::io::Printer::println(
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10::lang::String::Lit("PolyScanner")));
    
    //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner>)this)->
                        FMGL(C))->printInfo(
      ps,
      x10::lang::String::Lit("  C"));
}

//#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner::printInfo2(
  x10aux::ref<x10::io::Printer> ps) {
    
    //#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner>)this)->
                                                           FMGL(myMin))->
                                         FMGL(length)));
             
             //#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 316 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(ps)->x10::io::Printer::println(
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(((x10::lang::String::Lit("axis ")) + (k))));
            
            //#line 317 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(ps)->x10::io::Printer::println(
              x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10::lang::String::Lit("  min")));
            
            //#line 318 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
            {
                x10_int l;
                for (
                     //#line 318 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                     l =
                       ((x10_int)0);
                     ((l) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                  FMGL(myMin))->apply(k))->
                               FMGL(rows)));
                     
                     //#line 318 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                     l =
                       ((x10_int) ((l) + (((x10_int)1)))))
                {
                    
                    //#line 319 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      x10::lang::String::Lit("  "));
                    
                    //#line 320 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                    {
                        x10_int m;
                        for (
                             //#line 320 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                             m =
                               ((x10_int)0);
                             ((m) < (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                            FMGL(myMin))->apply(k))->x10::array::VarMat::apply(
                                                         l))->
                                       FMGL(cols)));
                             
                             //#line 320 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                             m =
                               ((x10_int) ((m) + (((x10_int)1)))))
                        {
                            
                            //#line 321 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                            x10aux::nullCheck(ps)->print(
                              ((x10::lang::String::Lit(" ")) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                       FMGL(myMin))->apply(k))->x10::array::VarMat::apply(
                                                                                    l))->x10::array::VarRow::apply(
                                                                  m))));
                        }
                    }
                    
                    //#line 322 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      x10::lang::String::Lit("  sum"));
                    
                    //#line 323 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                    {
                        x10_int m;
                        for (
                             //#line 323 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                             m =
                               ((x10_int)0);
                             ((m) < (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                            FMGL(minSum))->apply(k))->x10::array::VarMat::apply(
                                                         l))->
                                       FMGL(cols)));
                             
                             //#line 323 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                             m =
                               ((x10_int) ((m) + (((x10_int)1)))))
                        {
                            
                            //#line 324 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                            x10aux::nullCheck(ps)->print(
                              ((x10::lang::String::Lit(" ")) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                       FMGL(minSum))->apply(k))->x10::array::VarMat::apply(
                                                                                    l))->x10::array::VarRow::apply(
                                                                  m))));
                        }
                    }
                    
                    //#line 325 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      x10::lang::String::Lit("\n"));
                }
            }
            
            //#line 327 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(ps)->printf(
              x10::lang::String::Lit("  max\n"));
            
            //#line 328 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
            {
                x10_int l;
                for (
                     //#line 328 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                     l =
                       ((x10_int)0);
                     ((l) < (x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                  FMGL(myMax))->apply(k))->
                               FMGL(rows)));
                     
                     //#line 328 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                     l =
                       ((x10_int) ((l) + (((x10_int)1)))))
                {
                    
                    //#line 329 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      x10::lang::String::Lit("  "));
                    
                    //#line 330 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                    {
                        x10_int m;
                        for (
                             //#line 330 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                             m =
                               ((x10_int)0);
                             ((m) < (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                            FMGL(myMax))->apply(k))->x10::array::VarMat::apply(
                                                         l))->
                                       FMGL(cols)));
                             
                             //#line 330 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                             m =
                               ((x10_int) ((m) + (((x10_int)1)))))
                        {
                            
                            //#line 331 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                            x10aux::nullCheck(ps)->print(
                              ((x10::lang::String::Lit(" ")) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                       FMGL(myMax))->apply(k))->x10::array::VarMat::apply(
                                                                                    l))->x10::array::VarRow::apply(
                                                                  m))));
                        }
                    }
                    
                    //#line 332 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->print(
                      x10::lang::String::Lit("  sum"));
                    
                    //#line 333 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
                    {
                        x10_int m;
                        for (
                             //#line 333 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
                             m =
                               ((x10_int)0);
                             ((m) < (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                            FMGL(maxSum))->apply(k))->x10::array::VarMat::apply(
                                                         l))->
                                       FMGL(cols)));
                             
                             //#line 333 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                             m =
                               ((x10_int) ((m) + (((x10_int)1)))))
                        {
                            
                            //#line 334 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                            x10aux::nullCheck(ps)->print(
                              ((x10::lang::String::Lit(" ")) + (x10aux::nullCheck(x10aux::nullCheck((((x10aux::ref<x10::array::PolyScanner>)this)->
                                                                                                       FMGL(maxSum))->apply(k))->x10::array::VarMat::apply(
                                                                                    l))->x10::array::VarRow::apply(
                                                                  m))));
                        }
                    }
                    
                    //#line 335 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
                    x10aux::nullCheck(ps)->println();
                }
            }
            
        }
    }
    
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyScanner::rank() {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyScanner>)this)->
             FMGL(rank);
    
}
const x10aux::serialization_id_t x10::array::PolyScanner::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyScanner::_deserializer<x10::lang::Object>);

void x10::array::PolyScanner::_serialize(x10aux::ref<x10::array::PolyScanner> this_,
                                         x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::PolyScanner::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(rank));
    
}

void x10::array::PolyScanner::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(rank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::PolyScanner::rtt;
void x10::array::PolyScanner::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::array::Region__Scanner>()};
    rtt.initStageTwo("x10.array.PolyScanner", 2, parents, 0, NULL, NULL);
}
