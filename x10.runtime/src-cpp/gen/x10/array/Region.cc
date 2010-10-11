#include <x10/array/Region.h>


#include "x10/array/Region.inc"


//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.PropertyDecl_c

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.PropertyDecl_c

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.PropertyDecl_c
void x10::array::Region::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Region");
    
}


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::rail() {
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(((x10aux::ref<x10::array::Region>)this)->
                                    FMGL(rank), ((x10_int)1))) && ((x10aux::ref<x10::array::Region>)this)->
                                                                    FMGL(rect) &&
    ((x10aux::ref<x10::array::Region>)this)->
      FMGL(zeroBased);
    
}

//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::region(
  ) {
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this);
    
}

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeEmpty(
  x10_int rank) {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::EmptyRegion::_make(rank));
    
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeFull(
  x10_int rank) {
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::FullRegion::_make(rank));
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeUnit(
  ) {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::FullRegion::_make(((x10_int)0)));
    
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeHalfspace(
  x10aux::ref<x10::array::Point> normal,
  x10_int k) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10_int rank = x10aux::nullCheck(normal)->FMGL(rank);
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb = x10::array::PolyMatBuilder::_make(rank);
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyRow> r = x10::array::PolyRow::_make(normal,
                                                                    k);
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
    pmb->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
    
    //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm = pmb->toSortedPolyMat(
                                            false);
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::Region> __desugarer__var__32__ =
          x10::array::PolyRegion::make(
            pm);
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> __var394__;
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Labeled_c
        goto __ret1956; __ret1956: 
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__32__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__32__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(normal)->
                                           FMGL(rank)))))
            {
                
                //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==normal.rank}"))));
            }
            
            //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
            __var394__ =
              __desugarer__var__32__;
            
            //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Branch_c
            goto __ret1956_end_;
        }
        goto __ret1956_next_; __ret1956_next_: ;
        }
        while (false);
        goto __ret1956_end_; __ret1956_end_: ;
        __var394__;
    }))
    ;
    
}

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeRectangular(
  x10aux::ref<x10::lang::Rail<x10_int > > minArg,
  x10aux::ref<x10::lang::Rail<x10_int > > maxArg) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::Region::makeRectangular(x10::lang::ValRail<x10_int >::make(minArg),
                                               x10::lang::ValRail<x10_int >::make(maxArg));
    
}

//#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeRectangular(
  x10aux::ref<x10::lang::ValRail<x10_int > > minArg,
  x10aux::ref<x10::lang::ValRail<x10_int > > maxArg) {
    
    //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(minArg,
                                                                                                        maxArg));
    
}

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeRectangular(
  x10_int min,
  x10_int max) {
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(min,
                                                                                                        max));
    
}

//#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::make(
  x10_int min,
  x10_int max) {
    
    //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::RectRegion::_make(min,
                                                                                                        max));
    
}

//#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::make(
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > regions) {
    
    //#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> r = (regions)->apply(((x10_int)0));
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (x10aux::nullCheck(regions)->
                                         FMGL(length)));
             
             //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
            r =
              x10aux::nullCheck(r)->product(
                (regions)->apply(i));
        }
    }
    
    //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::Region> __desugarer__var__33__ =
          r;
        
        //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> __var400__;
        
        //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Labeled_c
        goto __ret1957; __ret1957: 
        //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__33__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__33__)->
                                           FMGL(rect),
                                         true)) &&
                  (x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__33__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(regions)->
                                           FMGL(length)))))
            {
                
                //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rect==true, self.rank==regions.length}"))));
            }
            
            //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
            __var400__ =
              __desugarer__var__33__;
            
            //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Branch_c
            goto __ret1957_end_;
        }
        goto __ret1957_next_; __ret1957_next_: ;
        }
        while (false);
        goto __ret1957_end_; __ret1957_end_: ;
        __var400__;
    }))
    ;
    
}

//#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeBanded(
  x10_int size,
  x10_int upper,
  x10_int lower) {
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::makeBanded(
             size,
             upper,
             lower);
    
}

//#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeBanded(
  x10_int size) {
    
    //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::makeBanded(
             size,
             ((x10_int)1),
             ((x10_int)1));
    
}

//#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeUpperTriangular(
  x10_int size) {
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::Region::makeUpperTriangular(
             ((x10_int)0),
             ((x10_int)0),
             size);
    
}

//#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeUpperTriangular(
  x10_int rowMin,
  x10_int colMin,
  x10_int size) {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::makeUpperTriangular2(
             rowMin,
             colMin,
             size);
    
}

//#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeLowerTriangular(
  x10_int size) {
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::Region::makeLowerTriangular(
             ((x10_int)0),
             ((x10_int)0),
             size);
    
}

//#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::makeLowerTriangular(
  x10_int rowMin,
  x10_int colMin,
  x10_int size) {
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::makeLowerTriangular2(
             rowMin,
             colMin,
             size);
    
}

//#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::boundingBox(
  ) {
    
    //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->computeBoundingBox();
    
}

//#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Region::min(x10_int i) {
    
    //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Region>)this)->min())->apply(i);
    
}

//#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Region::max(x10_int i) {
    
    //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Region>)this)->max())->apply(i);
    
}

//#line 252 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::disjoint(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Region>)this)->intersection(
                               that))->isEmpty();
    
}

//#line 277 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 303 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 341 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 350 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__implicit_convert(
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs) {
    
    //#line 350 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return x10::array::Region::make(rs);
    
}

//#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__and(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->intersection(
             that);
    
}

//#line 362 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__times(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 362 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->product(
             that);
    
}

//#line 364 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__plus(
  x10aux::ref<x10::array::Point> v) {
    
    //#line 364 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->translate(
             v);
    
}

//#line 365 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__inv_plus(
  x10aux::ref<x10::array::Point> v) {
    
    //#line 365 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->translate(
             v);
    
}

//#line 367 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Region::__minus(
  x10aux::ref<x10::array::Point> v) {
    
    //#line 367 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->translate(
             x10aux::nullCheck(v)->x10::array::Point::__minus());
    
}

//#line 374 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::equals(x10aux::ref<x10::lang::Any> that) {
    
    //#line 375 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::array::Region>)this),
                               that))) {
        
        //#line 375 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
        return true;
        
    }
    
    //#line 376 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::Region> >(that))))
    {
        
        //#line 376 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 377 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> t1 = x10aux::class_cast<x10aux::ref<x10::array::Region> >(that);
    
    //#line 378 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(((x10aux::ref<x10::array::Region>)this)->
                                  FMGL(rank),
                                x10aux::nullCheck(t1)->
                                  FMGL(rank))))
    {
        
        //#line 378 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> t2 = (__extension__ ({
        x10aux::ref<x10::array::Region> __desugarer__var__34__ =
          t1;
        
        //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> __var431__;
        
        //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Labeled_c
        goto __ret1958; __ret1958: 
        //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__34__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__34__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::Region>)this))->
                                           FMGL(rank)))))
            {
                
                //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==x10.array.Region#this.rank}"))));
            }
            
            //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
            __var431__ =
              __desugarer__var__34__;
            
            //#line 379 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Branch_c
            goto __ret1958_end_;
        }
        goto __ret1958_next_; __ret1958_next_: ;
        }
        while (false);
        goto __ret1958_end_; __ret1958_end_: ;
        __var431__;
    }))
    ;
    
    //#line 380 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->contains(
             t2) && x10aux::nullCheck(t2)->contains(
                      ((x10aux::ref<x10::array::Region>)this));
    
}

//#line 383 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 386 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c

//#line 388 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::contains(
  x10_int i) {
    
    //#line 388 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->contains(
             x10::array::Point::make(
               i));
    
}

//#line 390 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::contains(
  x10_int i0,
  x10_int i1) {
    
    //#line 390 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->contains(
             x10::array::Point::make(
               i0,
               i1));
    
}

//#line 392 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::contains(
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 392 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->contains(
             x10::array::Point::make(
               i0,
               i1,
               i2));
    
}

//#line 394 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::contains(
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 394 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->contains(
             x10::array::Point::make(
               i0,
               i1,
               i2,
               i3));
    
}

//#line 398 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10ConstructorDecl_c
void x10::array::Region::_constructor(x10_int r,
                                      x10_boolean t,
                                      x10_boolean z)
{
    this->x10::lang::Object::_constructor();
    
    //#line 400 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Region>)this)->
      FMGL(rank) =
      r;
    
    //#line 400 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Region>)this)->
      FMGL(rect) =
      t;
    
    //#line 400 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Region>)this)->
      FMGL(zeroBased) =
      z;
    
}


//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Region::rank() {
    
    //#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->
             FMGL(rank);
    
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::rect() {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->
             FMGL(rect);
    
}

//#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Region::zeroBased(
  ) {
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Region.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Region>)this)->
             FMGL(zeroBased);
    
}
void x10::array::Region::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(rank));
    buf.write(this->FMGL(rect));
    buf.write(this->FMGL(zeroBased));
    
}

void x10::array::Region::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(rank) = buf.read<x10_int>();
    FMGL(rect) = buf.read<x10_boolean>();
    FMGL(zeroBased) = buf.read<x10_boolean>();
}

x10aux::RuntimeType x10::array::Region::rtt;
void x10::array::Region::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.Region", 2, parents, 0, NULL, NULL);
}
