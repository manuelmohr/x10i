#include <x10/array/RectRegion.h>


#include "x10/array/RectRegion.inc"

x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::RectRegion >  x10::array::RectRegion::_itable_0(&x10::array::RectRegion::at, &x10::array::RectRegion::at, &x10::array::RectRegion::equals, &x10::array::RectRegion::hashCode, &x10::array::RectRegion::home, &x10::array::RectRegion::iterator, &x10::array::RectRegion::toString, &x10::array::RectRegion::typeName);
x10::lang::Any::itable<x10::array::RectRegion >  x10::array::RectRegion::_itable_1(&x10::array::RectRegion::at, &x10::array::RectRegion::at, &x10::array::RectRegion::equals, &x10::array::RectRegion::hashCode, &x10::array::RectRegion::home, &x10::array::RectRegion::toString, &x10::array::RectRegion::typeName);
x10aux::itable_entry x10::array::RectRegion::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::RectRegion>())};
void x10::array::RectRegion::_instance_init() {
    _I_("Doing initialisation for class: x10::array::RectRegion");
    
}


//#line 20 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::allZeros(x10aux::ref<x10::lang::ValRail<x10_int > > x) {
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10_int> > i1701;
        for (
             //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
             i1701 = (x)->iterator(); (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(i1701))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10_int> >(((x10aux::ref<x10::lang::Reference>)i1701)->_getITables())->hasNext))();
             ) {
            
            //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
            x10_int i = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(i1701))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10_int> >(((x10aux::ref<x10::lang::Reference>)i1701)->_getITables())->next))();
            
            //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(i, ((x10_int)0)))) {
                
                //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::RectRegion::_constructor(x10aux::ref<x10::lang::ValRail<x10_int > > minArg,
                                          x10aux::ref<x10::lang::ValRail<x10_int > > maxArg)
{
    this->x10::array::Region::_constructor(
      x10aux::nullCheck(minArg)->
        FMGL(length),
      true,
      x10::array::RectRegion::allZeros(
        minArg));
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::nullCheck(minArg)->
                                  FMGL(length),
                                x10aux::nullCheck(maxArg)->
                                  FMGL(length))))
    {
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::IllegalOperationException::_make(x10::lang::String::Lit("min and max must have same length"))));
    }
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10_int s =
      ((x10_int)1);
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
             i =
               ((x10_int)0);
             ((i) < (x10aux::nullCheck(minArg)->
                       FMGL(length)));
             
             //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
            x10_int rs =
              ((x10_int) ((((x10_int) (((maxArg)->apply(i)) - ((minArg)->apply(i))))) + (((x10_int)1))));
            
            //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if (((rs) < (((x10_int)0))))
            {
                
                //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
                rs =
                  ((x10_int)0);
            }
            
            //#line 52 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            s =
              ((x10_int) ((s) * (rs)));
        }
    }
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::RectRegion>)this)->
      FMGL(size) =
      s;
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::RectRegion>)this)->
      FMGL(mins) =
      minArg;
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::RectRegion>)this)->
      FMGL(maxs) =
      maxArg;
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::nullCheck(minArg)->
            FMGL(length)) > (((x10_int)0))))
    {
        
        //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min0) =
          (minArg)->apply(((x10_int)0));
        
        //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(max0) =
          (maxArg)->apply(((x10_int)0));
    }
    else
    {
        
        //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min0) =
          ((x10aux::ref<x10::array::RectRegion>)this)->
            FMGL(max0) =
          ((x10_int)0);
    }
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::nullCheck(minArg)->
            FMGL(length)) > (((x10_int)1))))
    {
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min1) =
          (minArg)->apply(((x10_int)1));
        
        //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(max1) =
          (maxArg)->apply(((x10_int)1));
    }
    else
    {
        
        //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min1) =
          ((x10aux::ref<x10::array::RectRegion>)this)->
            FMGL(max1) =
          ((x10_int)0);
    }
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::nullCheck(minArg)->
            FMGL(length)) > (((x10_int)2))))
    {
        
        //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min2) =
          (minArg)->apply(((x10_int)2));
        
        //#line 75 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(max2) =
          (maxArg)->apply(((x10_int)2));
    }
    else
    {
        
        //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min2) =
          ((x10aux::ref<x10::array::RectRegion>)this)->
            FMGL(max2) =
          ((x10_int)0);
    }
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::nullCheck(minArg)->
            FMGL(length)) > (((x10_int)3))))
    {
        
        //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min3) =
          (minArg)->apply(((x10_int)3));
        
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(max3) =
          (maxArg)->apply(((x10_int)3));
    }
    else
    {
        
        //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(min3) =
          ((x10aux::ref<x10::array::RectRegion>)this)->
            FMGL(max3) =
          ((x10_int)0);
    }
    
}
x10aux::ref<x10::array::RectRegion> x10::array::RectRegion::_make(
  x10aux::ref<x10::lang::ValRail<x10_int > > minArg,
  x10aux::ref<x10::lang::ValRail<x10_int > > maxArg)
{
    x10aux::ref<x10::array::RectRegion> this_ = new (memset(x10aux::alloc<x10::array::RectRegion>(), 0, sizeof(x10::array::RectRegion))) x10::array::RectRegion();
    this_->_constructor(minArg,
    maxArg);
    return this_;
}



//#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::RectRegion::_constructor(x10_int min,
                                          x10_int max)
{
    this->_constructor(
      (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
      x10::lang::ValRail<x10_int > >(1,(min)),
      (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
      x10::lang::ValRail<x10_int > >(1,(max)));
    
}
x10aux::ref<x10::array::RectRegion> x10::array::RectRegion::_make(
  x10_int min,
  x10_int max)
{
    x10aux::ref<x10::array::RectRegion> this_ = new (memset(x10aux::alloc<x10::array::RectRegion>(), 0, sizeof(x10::array::RectRegion))) x10::array::RectRegion();
    this_->_constructor(min,
    max);
    return this_;
}



//#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::RectRegion::size() {
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::RectRegion>)this)->
             FMGL(size);
    
}

//#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::isConvex() {
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::isEmpty() {
    
    //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(((x10aux::ref<x10::array::RectRegion>)this)->
                                    FMGL(size), ((x10_int)0)));
    
}

//#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::computeBoundingBox(
  ) {
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::RectRegion>)this));
    
}

//#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::array::RectRegion::min(
  ) {
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::RectRegion>)this)->
             FMGL(mins);
    
}

//#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::array::RectRegion::max(
  ) {
    
    //#line 106 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::RectRegion>)this)->
             FMGL(maxs);
    
}

//#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(x10aux::ref<x10::array::Region> that) {
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::RectRegion> >(that))
    {
        
        //#line 110 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMin =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::min();
        
        //#line 111 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMax =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::max();
        
        //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
                 i =
                   ((x10_int)0);
                 ((i) < (((x10aux::ref<x10::array::RectRegion>)this)->
                           FMGL(rank)));
                 
                 //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
                if ((((((x10aux::ref<x10::array::RectRegion>)this)->
                         FMGL(mins))->apply(i)) > ((thatMin)->apply(i))))
                {
                    
                    //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                    return false;
                    
                }
                
                //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
                if ((((((x10aux::ref<x10::array::RectRegion>)this)->
                         FMGL(maxs))->apply(i)) < ((thatMax)->apply(i))))
                {
                    
                    //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                    return false;
                    
                }
                
            }
        }
        
        //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return true;
        
    }
    else
    {
        
        //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::contains(
                 x10aux::nullCheck(that)->computeBoundingBox());
        
    }
    
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::nullCheck(p)->
                                  FMGL(rank),
                                ((x10aux::ref<x10::array::RectRegion>)this)->
                                  FMGL(rank))))
    {
        
        //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return false;
        
    }
    {
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10_int r1702min1703 = ((x10_int)0);
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10_int r1702max1704 = ((x10_int) ((x10aux::nullCheck(p)->
                                              FMGL(rank)) - (((x10_int)1))));
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
        {
            x10_int r1702;
            for (
                 //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
                 r1702 = r1702min1703; ((r1702) <= (r1702max1704));
                 
                 //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
                 r1702 =
                   ((x10_int) ((r1702) + (((x10_int)1)))))
            {
                
                //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
                x10_int r =
                  r1702;
                {
                    
                    //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
                    if (((x10aux::nullCheck(p)->x10::array::Point::apply(
                            r)) < ((((x10aux::ref<x10::array::RectRegion>)this)->
                                      FMGL(mins))->apply(r))) ||
                        ((x10aux::nullCheck(p)->x10::array::Point::apply(
                            r)) > ((((x10aux::ref<x10::array::RectRegion>)this)->
                                      FMGL(maxs))->apply(r))))
                    {
                        
                        //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                        return false;
                        
                    }
                    
                }
            }
        }
        
    }
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(
  x10_int i0) {
    
    //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ((i0) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                       FMGL(min0))) && ((i0) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                                                   FMGL(max0)));
    
}

//#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(
  x10_int i0,
  x10_int i1) {
    
    //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(zeroBased)) {
        
        //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return (((((x10_uint) (i0))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                        FMGL(max0)))))) &&
        (((((x10_uint) (i1))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max1))))));
        
    } else {
        
        //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i0) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                           FMGL(min0))) &&
        ((i0) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max0))) &&
        ((i1) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min1))) &&
        ((i1) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max1)));
        
    }
    
}

//#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(zeroBased)) {
        
        //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return (((((x10_uint) (i0))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                        FMGL(max0)))))) &&
        (((((x10_uint) (i1))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max1)))))) &&
        (((((x10_uint) (i2))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max2))))));
        
    } else {
        
        //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i0) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                           FMGL(min0))) &&
        ((i0) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max0))) &&
        ((i1) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min1))) &&
        ((i1) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max1))) &&
        ((i2) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min2))) &&
        ((i2) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max2)));
        
    }
    
}

//#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::contains(
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::RectRegion>)this)->
          FMGL(zeroBased)) {
        
        //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return (((((x10_uint) (i0))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                        FMGL(max0)))))) &&
        (((((x10_uint) (i1))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max1)))))) &&
        (((((x10_uint) (i2))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max2)))))) &&
        (((((x10_uint) (i3))) <= (((x10_uint) (((x10aux::ref<x10::array::RectRegion>)this)->
                                                 FMGL(max3))))));
        
    } else {
        
        //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return ((i0) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                           FMGL(min0))) &&
        ((i0) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max0))) &&
        ((i1) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min1))) &&
        ((i1) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max1))) &&
        ((i2) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min2))) &&
        ((i2) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max2))) &&
        ((i3) >= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(min3))) &&
        ((i3) <= (((x10aux::ref<x10::array::RectRegion>)this)->
                    FMGL(max3)));
        
    }
    
}

//#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::intersection(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(that)->isEmpty())
    {
        
        //#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return that;
        
    }
    else
    
    //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::FullRegion> >(that))
    {
        
        //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(((x10aux::ref<x10::array::RectRegion>)this));
        
    }
    else
    
    //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::RectRegion> >(that))
    {
        
        //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMin =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::min();
        
        //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMax =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::max();
        
        //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
          x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::RectRegion>)this)->
                                               FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__0)))x10_array_RectRegion__closure__0(this, thatMin)))));
        
        //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
          x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::RectRegion>)this)->
                                               FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__1)))x10_array_RectRegion__closure__1(this, thatMax)))));
        {
            
            //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
            x10_int i1705min1706 =
              ((x10_int)0);
            
            //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
            x10_int i1705max1707 =
              ((x10_int) ((x10aux::nullCheck(newMin)->
                             FMGL(length)) - (((x10_int)1))));
            
            //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
            {
                x10_int i1705;
                for (
                     //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
                     i1705 =
                       i1705min1706;
                     ((i1705) <= (i1705max1707));
                     
                     //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
                     i1705 =
                       ((x10_int) ((i1705) + (((x10_int)1)))))
                {
                    
                    //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
                    x10_int i =
                      i1705;
                    {
                        
                        //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
                        if ((((newMax)->apply(i)) < ((newMin)->apply(i))))
                        {
                            
                            //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                            return x10::array::Region::makeEmpty(
                                     ((x10aux::ref<x10::array::RectRegion>)this)->
                                       FMGL(rank));
                            
                        }
                        
                    }
                }
            }
            
        }
        
        //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(newMin,
                                                                                                            newMax));
        
    }
    else
    {
        
        //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(((x10::lang::String::Lit("haven\'t implemented RectRegion intersection with ")) + (x10aux::type_name(that))))));
    }
    
}

//#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::product(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(that)->isEmpty())
    {
        
        //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10::array::Region::makeEmpty(
                 ((x10_int) ((((x10aux::ref<x10::array::RectRegion>)this)->
                                FMGL(rank)) + (x10aux::nullCheck(that)->
                                                 FMGL(rank)))));
        
    }
    else
    
    //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::RectRegion> >(that))
    {
        
        //#line 195 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMin =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::min();
        
        //#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > thatMax =
          x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::max();
        
        //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10_int k =
          ((x10_int) ((((x10aux::ref<x10::array::RectRegion>)this)->
                         FMGL(rank)) + (x10aux::nullCheck(that)->
                                          FMGL(rank))));
        
        //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
          x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__2)))x10_array_RectRegion__closure__2(this, thatMin)))));
        
        //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
          x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__3>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__3)))x10_array_RectRegion__closure__3(this, thatMax)))));
        
        //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(newMin,
                                                                                                            newMax));
        
    }
    else
    
    //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::FullRegion> >(that))
    {
        
        //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10_int k =
          ((x10_int) ((((x10aux::ref<x10::array::RectRegion>)this)->
                         FMGL(rank)) + (x10aux::nullCheck(that)->
                                          FMGL(rank))));
        
        //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
          x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__4>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__4)))x10_array_RectRegion__closure__4(this)))));
        
        //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
          x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__5>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__5)))x10_array_RectRegion__closure__5(this)))));
        
        //#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(newMin,
                                                                                                            newMax));
        
    }
    else
    {
        
        //#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(((x10::lang::String::Lit("haven\'t implemented RectRegion product with ")) + (x10aux::type_name(that))))));
    }
    
}

//#line 211 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::translate(
  x10aux::ref<x10::array::Point> v) {
    
    //#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
      x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::RectRegion>)this)->
                                           FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__6>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__6)))x10_array_RectRegion__closure__6(this, v)))));
    
    //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
      x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::RectRegion>)this)->
                                           FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__7>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__7)))x10_array_RectRegion__closure__7(this, v)))));
    
    //#line 214 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(newMin,
                                                                                                        newMax));
    
}

//#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::projection(
  x10_int axis) {
    
    //#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make((x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                                                                                        x10::lang::ValRail<x10_int > >(1,(((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::min(
                                                                                                                                            axis))),
                                                                                                        (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                                                                                        x10::lang::ValRail<x10_int > >(1,(((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::max(
                                                                                                                                            axis)))));
    
}

//#line 221 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::RectRegion::eliminate(
  x10_int axis) {
    
    //#line 222 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10_int k = ((x10_int) ((((x10aux::ref<x10::array::RectRegion>)this)->
                               FMGL(rank)) - (((x10_int)1))));
    
    //#line 223 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > newMin =
      x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__8>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__8)))x10_array_RectRegion__closure__8(axis, this)))));
    
    //#line 224 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > newMax =
      x10::lang::ValRail<x10_int >::make(k, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_RectRegion__closure__9>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_RectRegion__closure__9)))x10_array_RectRegion__closure__9(axis, this)))));
    
    //#line 225 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(newMin,
                                                                                                        newMax));
    
}

//#line 270 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::RectRegion::iterator(
  ) {
    
    //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > >(x10::array::RectRegion__RRIterator::_make(((x10aux::ref<x10::array::RectRegion>)this)));
    
}

//#line 275 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion::equals(
  x10aux::ref<x10::lang::Any> thatObj) {
    
    //#line 276 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::array::RectRegion>)this),
                               thatObj)))
    {
        
        //#line 276 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return true;
        
    }
    
    //#line 277 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::Region> >(thatObj))))
    {
        
        //#line 277 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 278 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> that =
      x10aux::class_cast<x10aux::ref<x10::array::Region> >(thatObj);
    
    //#line 281 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::RectRegion> >(that))))
    {
        
        //#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return x10::array::Region::equals(
                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(that));
        
    }
    
    //#line 285 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(((x10aux::ref<x10::array::RectRegion>)this)->
                                  FMGL(rank),
                                x10aux::nullCheck(that)->
                                  FMGL(rank))))
    {
        
        //#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 289 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thisMin =
      ((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::min();
    
    //#line 290 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thisMax =
      ((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::max();
    
    //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thatMin =
      x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::min();
    
    //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thatMax =
      x10aux::nullCheck((x10aux::class_cast<x10aux::ref<x10::array::RectRegion> >(that)))->x10::array::RectRegion::max();
    
    //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::RectRegion>)this)->
                                         FMGL(rank)));
             
             //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 296 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((thisMin)->apply(i),
                                        (thatMin)->apply(i))) ||
                (!x10aux::struct_equals((thisMax)->apply(i),
                                        (thatMax)->apply(i))))
            {
                
                //#line 297 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 299 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 307 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::RectRegion::toString(
  ) {
    
    //#line 308 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thisMin =
      ((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::min();
    
    //#line 309 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > thisMax =
      ((x10aux::ref<x10::array::RectRegion>)this)->x10::array::RectRegion::max();
    
    //#line 310 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> s = x10::lang::String::Lit("[");
    
    //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::RectRegion>)this)->
                                         FMGL(rank)));
             
             //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if (((i) > (((x10_int)0))))
            {
                
                //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
                s =
                  ((s) + (x10::lang::String::Lit(",")));
            }
            
            //#line 313 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            s =
              ((s) + ((((((thisMin)->apply(i)) + (x10::lang::String::Lit("..")))) + ((thisMax)->apply(i)))));
        }
    }
    
    //#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    s = ((s) + (x10::lang::String::Lit("]")));
    
    //#line 316 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return s;
    
}

//#line 320 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >
  x10::array::RectRegion::scanners(
  ) {
    
    //#line 321 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(x10::lang::String::Lit("TODO: scanners not defined for RectRegion"))));
}
x10_int x10::array::RectRegion::min(x10_int p0) {
    return x10::array::Region::min(p0);
}
x10_int x10::array::RectRegion::max(x10_int p0) {
    return x10::array::Region::max(p0);
}
const x10aux::serialization_id_t x10::array::RectRegion::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::RectRegion::_deserializer<x10::lang::Object>);

void x10::array::RectRegion::_serialize(x10aux::ref<x10::array::RectRegion> this_,
                                        x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::RectRegion::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Region::_serialize_body(buf);
    buf.write(this->FMGL(size));
    buf.write(this->FMGL(mins));
    buf.write(this->FMGL(maxs));
    buf.write(this->FMGL(min0));
    buf.write(this->FMGL(min1));
    buf.write(this->FMGL(min2));
    buf.write(this->FMGL(min3));
    buf.write(this->FMGL(max0));
    buf.write(this->FMGL(max1));
    buf.write(this->FMGL(max2));
    buf.write(this->FMGL(max3));
    
}

void x10::array::RectRegion::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Region::_deserialize_body(buf);
    FMGL(size) = buf.read<x10_int>();
    FMGL(mins) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
    FMGL(maxs) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
    FMGL(min0) = buf.read<x10_int>();
    FMGL(min1) = buf.read<x10_int>();
    FMGL(min2) = buf.read<x10_int>();
    FMGL(min3) = buf.read<x10_int>();
    FMGL(max0) = buf.read<x10_int>();
    FMGL(max1) = buf.read<x10_int>();
    FMGL(max2) = buf.read<x10_int>();
    FMGL(max3) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::RectRegion::rtt;
void x10::array::RectRegion::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Region>()};
    rtt.initStageTwo("x10.array.RectRegion", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__0>x10_array_RectRegion__closure__0::_itable(&x10_array_RectRegion__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__1>x10_array_RectRegion__closure__1::_itable(&x10_array_RectRegion__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__2>x10_array_RectRegion__closure__2::_itable(&x10_array_RectRegion__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__2::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__3>x10_array_RectRegion__closure__3::_itable(&x10_array_RectRegion__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__3::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__4>x10_array_RectRegion__closure__4::_itable(&x10_array_RectRegion__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__4::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__5>x10_array_RectRegion__closure__5::_itable(&x10_array_RectRegion__closure__5::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__5::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__5::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__5::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__5::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__5::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__6>x10_array_RectRegion__closure__6::_itable(&x10_array_RectRegion__closure__6::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__6::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__6::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__6::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__6::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__6::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__7>x10_array_RectRegion__closure__7::_itable(&x10_array_RectRegion__closure__7::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__7::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__7::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__7::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__7::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__7::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__8>x10_array_RectRegion__closure__8::_itable(&x10_array_RectRegion__closure__8::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__8::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__8::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__8::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__8::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__8::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectRegion__closure__9>x10_array_RectRegion__closure__9::_itable(&x10_array_RectRegion__closure__9::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_RectRegion__closure__9::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_RectRegion__closure__9::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_RectRegion__closure__9::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_RectRegion__closure__9::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_RectRegion__closure__9::_deserialize<x10::lang::Object>);

