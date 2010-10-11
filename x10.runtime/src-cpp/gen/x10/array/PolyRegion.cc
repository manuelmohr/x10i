#include <x10/array/PolyRegion.h>


#include "x10/array/PolyRegion.inc"

x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::PolyRegion >  x10::array::PolyRegion::_itable_0(&x10::array::PolyRegion::at, &x10::array::PolyRegion::at, &x10::array::PolyRegion::equals, &x10::array::PolyRegion::hashCode, &x10::array::PolyRegion::home, &x10::array::PolyRegion::iterator, &x10::array::PolyRegion::toString, &x10::array::PolyRegion::typeName);
x10::lang::Any::itable<x10::array::PolyRegion >  x10::array::PolyRegion::_itable_1(&x10::array::PolyRegion::at, &x10::array::PolyRegion::at, &x10::array::PolyRegion::equals, &x10::array::PolyRegion::hashCode, &x10::array::PolyRegion::home, &x10::array::PolyRegion::toString, &x10::array::PolyRegion::typeName);
x10aux::itable_entry x10::array::PolyRegion::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyRegion>())};
void x10::array::PolyRegion::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyRegion");
    
}

 /* static type PolyRegion(val rank: x10.lang.Int) = x10.array.PolyRegion{self.rank==rank}; */ 
 /* static type PolyRow(val rank: x10.lang.Int) = x10.array.PolyRow{self.rank==rank}; */ 
 /* static type PolyMat(val rank: x10.lang.Int) = x10.array.PolyMat{self.rank==rank}; */ 

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10FieldDecl_c

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRegion::isConvex() {
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyRegion::size() {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> > >
  x10::array::PolyRegion::scanners(
  ) {
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion__Scanners::_make(((x10aux::ref<x10::array::PolyRegion>)this));
    
}

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region__Scanner> x10::array::PolyRegion::scanner(
  ) {
    
    //#line 80 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyScanner> scanner = x10::array::PolyScanner::make(
                                                     ((x10aux::ref<x10::array::PolyRegion>)this)->
                                                       FMGL(mat));
    
    //#line 81 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region__Scanner> >(scanner);
    
}

//#line 91 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::PolyRegion::iterator(
  ) {
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > __desugarer__var__23__ =
          x10aux::nullCheck(x10::array::PolyScanner::make(
                              ((x10aux::ref<x10::array::PolyRegion>)this)->
                                FMGL(mat)))->x10::array::PolyScanner::iterator();
        
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > > __var283__;
        
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Labeled_c
        goto __ret1947; __ret1947: 
        //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
            if (!((x10aux::struct_equals(x10::lang::Place_methods::place(x10aux::get_location(__desugarer__var__23__)),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Iterator[x10.array.Point{self.rank==x10.array.PolyRegion#this.rank}]{self.home==here}"))));
            }
            
            //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            __var283__ =
              __desugarer__var__23__;
            
            //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Branch_c
            goto __ret1947_end_;
        }
        goto __ret1947_next_; __ret1947_next_: ;
        }
        while (false);
        goto __ret1947_end_; __ret1947_end_: ;
        __var283__;
    }))
    ;
    
}

//#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::intersection(
  x10aux::ref<x10::array::Region> t) {
    
    //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
    if (x10aux::instanceof<x10aux::ref<x10::array::PolyRegion> >(t))
    {
        
        //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyRegion> that =
          x10aux::class_cast<x10aux::ref<x10::array::PolyRegion> >(t);
        
        //#line 105 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyMatBuilder> pmb =
          x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyRegion>)this)->
                                              FMGL(rank));
        
        //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1601;
            for (
                 //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                 r1601 =
                   x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                                       FMGL(mat))->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1601))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1601)->_getITables())->hasNext))();
                 )
            {
                
                //#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::PolyRow> r =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1601))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1601)->_getITables())->next))();
                
                //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                pmb->add(
                  x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
            }
        }
        
        //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
        {
            x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1602;
            for (
                 //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                 r1602 =
                   x10aux::nullCheck(x10aux::nullCheck(that)->
                                       FMGL(mat))->iterator();
                 (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1602))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1602)->_getITables())->hasNext))();
                 )
            {
                
                //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::array::PolyRow> r =
                  (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1602))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1602)->_getITables())->next))();
                
                //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                pmb->add(
                  x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
            }
        }
        
        //#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyMat> pm =
          pmb->toSortedPolyMat(
            false);
        
        //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
        return (__extension__ ({
            x10aux::ref<x10::array::Region> __desugarer__var__24__ =
              x10::array::PolyRegion::make(
                pm);
            
            //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::Region> __var285__;
            
            //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Labeled_c
            goto __ret1948; __ret1948: 
            //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Do_c
            do
            {
            {
                
                //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(__desugarer__var__24__,
                                            x10aux::null)) &&
                    !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__24__)->
                                               FMGL(rank),
                                             x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this))->
                                               FMGL(rank)))))
                {
                    
                    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
                    x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==x10.array.PolyRegion#this.rank}"))));
                }
                
                //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                __var285__ =
                  __desugarer__var__24__;
                
                //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Branch_c
                goto __ret1948_end_;
            }
            goto __ret1948_next_; __ret1948_next_: ;
            }
            while (false);
            goto __ret1948_end_; __ret1948_end_: ;
            __var285__;
        }))
        ;
        
    }
    else
    {
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(((((x10::lang::String::Lit("intersection(")) + (t))) + (x10::lang::String::Lit(")"))))));
    }
    
}

//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRegion::contains(
  x10aux::ref<x10::array::Region> that) {
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->computeBoundingBox())->contains(
             x10aux::nullCheck(that)->computeBoundingBox());
    
}

//#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::projection(
  x10_int axis) {
    
    //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      ((x10aux::ref<x10::array::PolyRegion>)this)->
        FMGL(mat);
    
    //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (((x10aux::ref<x10::array::PolyRegion>)this)->
                                         FMGL(rank)));
             
             //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(k,
                                        axis)))
            {
                
                //#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                pm =
                  x10aux::nullCheck(pm)->eliminate(
                    k,
                    true);
            }
            
        }
    }
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::Region> __desugarer__var__25__ =
          x10::array::Region::makeRectangular(
            x10aux::nullCheck(pm)->rectMin(
              axis),
            x10aux::nullCheck(pm)->rectMax(
              axis));
        
        //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> __var288__;
        
        //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Labeled_c
        goto __ret1949; __ret1949: 
        //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__25__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__25__)->
                                           FMGL(rank),
                                         ((x10_int)1)))))
            {
                
                //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==1}"))));
            }
            
            //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            __var288__ =
              __desugarer__var__25__;
            
            //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Branch_c
            goto __ret1949_end_;
        }
        goto __ret1949_next_; __ret1949_next_: ;
        }
        while (false);
        goto __ret1949_end_; __ret1949_end_: ;
        __var288__;
    }))
    ;
    
}

//#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::eliminate(
  x10_int axis) {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                          FMGL(mat))->eliminate(
        axis,
        true);
    
    //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> result =
      x10::array::PolyRegion::make(
        pm);
    
    //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::product(
  x10aux::ref<x10::array::Region> r) {
    
    //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::PolyRegion> >(r))))
    {
        
        //#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
        x10aux::throwException(x10aux::nullCheck(x10::lang::UnsupportedOperationException::_make(((((x10::lang::String::Lit("product(")) + (r))) + (x10::lang::String::Lit(")"))))));
    }
    
    //#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyRegion> that =
      x10aux::class_cast<x10aux::ref<x10::array::PolyRegion> >(r);
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10_int) ((((x10aux::ref<x10::array::PolyRegion>)this)->
                                                       FMGL(rank)) + (x10aux::nullCheck(that)->
                                                                        FMGL(rank)))));
    
    //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    x10::array::PolyRegion::copy(pmb, ((x10aux::ref<x10::array::PolyRegion>)this)->
                                        FMGL(mat),
                                 ((x10_int)0));
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    x10::array::PolyRegion::copy(pmb, x10aux::nullCheck(that)->
                                        FMGL(mat),
                                 ((x10aux::ref<x10::array::PolyRegion>)this)->
                                   FMGL(rank));
    
    //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      pmb->toSortedPolyMat(
        false);
    
    //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::make(pm);
    
}

//#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyRegion::copy(x10aux::ref<x10::array::PolyMatBuilder> tt,
                                  x10aux::ref<x10::array::PolyMat> ff,
                                  x10_int offset) {
    
    //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1603;
        for (
             //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
             r1603 = x10aux::nullCheck(ff)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1603))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1603)->_getITables())->hasNext))();
             ) {
            
            //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1603))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1603)->_getITables())->next))();
            
            //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> f =
              r;
            
            //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Rail<x10_int > > t =
              x10::lang::Rail<void>::make<x10_int >(((x10_int) ((x10aux::nullCheck(tt)->
                                                                   FMGL(rank)) + (((x10_int)1)))));
            
            //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
            {
                x10_int i;
                for (
                     //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                     i = ((x10_int)0); ((i) < (x10aux::nullCheck(ff)->
                                                 FMGL(rank)));
                     
                     //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                     i =
                       ((x10_int) ((i) + (((x10_int)1)))))
                {
                    
                    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                    (t)->set(x10aux::nullCheck(f)->apply(
                               i), ((x10_int) ((offset) + (i))));
                }
            }
            
            //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            (t)->set(x10aux::nullCheck(f)->apply(
                       x10aux::nullCheck(ff)->
                         FMGL(rank)), x10aux::nullCheck(tt)->
                                        FMGL(rank));
            
            //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(tt)->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(x10::array::PolyRow::_make(x10::lang::ValRail<x10_int >::make(t))));
        }
    }
    
}

//#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::translate(
  x10aux::ref<x10::array::Point> v) {
    
    //#line 186 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyRegion>)this)->
                                          FMGL(rank));
    
    //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    x10::array::PolyRegion::translate(pmb,
                                      ((x10aux::ref<x10::array::PolyRegion>)this)->
                                        FMGL(mat),
                                      v);
    
    //#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      pmb->toSortedPolyMat(
        false);
    
    //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::make(pm);
    
}

//#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyRegion::translate(x10aux::ref<x10::array::PolyMatBuilder> tt,
                                       x10aux::ref<x10::array::PolyMat> ff,
                                       x10aux::ref<x10::array::Point> v) {
    
    //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1604;
        for (
             //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
             r1604 = x10aux::nullCheck(ff)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1604))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1604)->_getITables())->hasNext))();
             ) {
            
            //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1604))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1604)->_getITables())->next))();
            
            //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> f =
              r;
            
            //#line 195 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::lang::Rail<x10_int > > t =
              x10::lang::Rail<void>::make<x10_int >(((x10_int) ((x10aux::nullCheck(ff)->
                                                                   FMGL(rank)) + (((x10_int)1)))));
            
            //#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10_int s = ((x10_int)0);
            
            //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
            {
                x10_int i;
                for (
                     //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                     i = ((x10_int)0); ((i) < (x10aux::nullCheck(ff)->
                                                 FMGL(rank)));
                     
                     //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                     i =
                       ((x10_int) ((i) + (((x10_int)1)))))
                {
                    
                    //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                    (t)->set(x10aux::nullCheck(f)->apply(
                               i), i);
                    
                    //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                    s =
                      ((x10_int) ((s) + (((x10_int) ((x10aux::nullCheck(f)->apply(
                                                        i)) * (x10aux::nullCheck(v)->x10::array::Point::apply(
                                                                 i)))))));
                }
            }
            
            //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            (t)->set(((x10_int) ((x10aux::nullCheck(f)->apply(
                                    x10aux::nullCheck(ff)->
                                      FMGL(rank))) - (s))), x10aux::nullCheck(ff)->
                                                              FMGL(rank));
            
            //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(tt)->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(x10::array::PolyRow::_make(x10::lang::ValRail<x10_int >::make(t))));
        }
    }
    
}

//#line 231 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRegion::isEmpty(
  ) {
    
    //#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10_boolean tmp = x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                                          FMGL(mat))->isEmpty();
    
    //#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return tmp;
    
}

//#line 236 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::computeBoundingBox(
  ) {
    
    //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_int > > min =
      x10::lang::Rail<void>::make<x10_int >(((x10aux::ref<x10::array::PolyRegion>)this)->
                                              FMGL(rank));
    
    //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_int > > max =
      x10::lang::Rail<void>::make<x10_int >(((x10aux::ref<x10::array::PolyRegion>)this)->
                                              FMGL(rank));
    
    //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      ((x10aux::ref<x10::array::PolyRegion>)this)->
        FMGL(mat);
    
    //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
    {
        x10_int axis;
        for (
             //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
             axis = ((x10_int)0); ((axis) < (((x10aux::ref<x10::array::PolyRegion>)this)->
                                               FMGL(rank)));
             
             //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
             axis =
               ((x10_int) ((axis) + (((x10_int)1)))))
        {
            
            //#line 241 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyMat> x =
              pm;
            
            //#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
            {
                x10_int k;
                for (
                     //#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
                     k =
                       ((x10_int) ((axis) + (((x10_int)1))));
                     ((k) < (((x10aux::ref<x10::array::PolyRegion>)this)->
                               FMGL(rank)));
                     
                     //#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                     k =
                       ((x10_int) ((k) + (((x10_int)1)))))
                {
                    
                    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
                    x =
                      x10aux::nullCheck(x)->eliminate(
                        k,
                        true);
                }
            }
            
            //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            (min)->set(x10aux::nullCheck(x)->rectMin(
                         axis), axis);
            
            //#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            (max)->set(x10aux::nullCheck(x)->rectMax(
                         axis), axis);
            
            //#line 246 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            pm =
              x10aux::nullCheck(pm)->eliminate(
                axis,
                true);
        }
    }
    
    //#line 248 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::Region::makeRectangular(
             min,
             max);
    
}

//#line 256 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyRegion::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1605;
        for (
             //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
             r1605 = x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                                         FMGL(mat))->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1605))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1605)->_getITables())->hasNext))();
             ) {
            
            //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1605))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1605)->_getITables())->next))();
            
            //#line 259 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck(r)->contains(
                     p)))) {
                
                //#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 279 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10FieldDecl_c
/**
     * lower==1 and lower==1 include the diagonal
     * lower==size and upper==size includes entire size x size square
     *
     * col-colMin >= row-rowMin - (lower-1)
     * col-colMin <= row-rowMin + (upper-1)
     *
     * col-row >= colMin-rowMin - (lower-1)
     * col-row <= colMin-rowMin + (upper-1)
     */x10_int
                                                                                                                                                                                                                                                                                                                                   x10::array::PolyRegion::FMGL(ROW);
void x10::array::PolyRegion::FMGL(ROW__do_init)() {
    FMGL(ROW__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::array::PolyRegion.ROW");
    x10_int __var297__ = x10::array::PolyMatBuilder::X(
                           ((x10_int)0));
    FMGL(ROW) = __var297__;
    FMGL(ROW__status) = x10aux::INITIALIZED;
}
void x10::array::PolyRegion::FMGL(ROW__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var298__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(ROW__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var298__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(ROW__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(ROW),
                                                                    FMGL(ROW__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(ROW__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__299 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::array::PolyRegion::FMGL(ROW__init));

volatile x10aux::status x10::array::PolyRegion::FMGL(ROW__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::array::PolyRegion::FMGL(ROW__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(ROW) = buf.read<x10_int>();
    x10::array::PolyRegion::FMGL(ROW__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::array::PolyRegion::FMGL(ROW__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::array::PolyRegion::FMGL(ROW__deserialize));


//#line 280 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10FieldDecl_c
x10_int x10::array::PolyRegion::FMGL(COL);
void x10::array::PolyRegion::FMGL(COL__do_init)() {
    FMGL(COL__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::array::PolyRegion.COL");
    x10_int __var300__ = x10::array::PolyMatBuilder::X(
                           ((x10_int)1));
    FMGL(COL) = __var300__;
    FMGL(COL__status) = x10aux::INITIALIZED;
}
void x10::array::PolyRegion::FMGL(COL__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var301__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(COL__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var301__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(COL__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(COL),
                                                                    FMGL(COL__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(COL__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__302 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::array::PolyRegion::FMGL(COL__init));

volatile x10aux::status x10::array::PolyRegion::FMGL(COL__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::array::PolyRegion::FMGL(COL__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(COL) = buf.read<x10_int>();
    x10::array::PolyRegion::FMGL(COL__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::array::PolyRegion::FMGL(COL__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::array::PolyRegion::FMGL(COL__deserialize));


//#line 282 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::makeBanded(
  x10_int rowMin,
  x10_int colMin,
  x10_int rowMax,
  x10_int colMax,
  x10_int upper,
  x10_int lower) {
    
    //#line 283 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10_int)2));
    
    //#line 284 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(ROW__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             rowMin);
    
    //#line 285 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(ROW__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(LE)),
             rowMax);
    
    //#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(COL__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             colMin);
    
    //#line 287 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(COL__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(LE)),
             colMax);
    
    //#line 288 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(((x10_int) ((x10::array::PolyRegion::
                            FMGL(COL__get)()) - (x10::array::PolyRegion::
                                                   FMGL(ROW__get)()))),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             ((x10_int) ((((x10_int) ((colMin) - (rowMin)))) - (((x10_int) ((lower) - (((x10_int)1))))))));
    
    //#line 289 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(((x10_int) ((x10::array::PolyRegion::
                            FMGL(COL__get)()) - (x10::array::PolyRegion::
                                                   FMGL(ROW__get)()))),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(LE)),
             ((x10_int) ((((x10_int) ((colMin) - (rowMin)))) + (((x10_int) ((upper) - (((x10_int)1))))))));
    
    //#line 290 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      pmb->toSortedPolyMat(
        false);
    
    //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::make(pm);
    
}

//#line 294 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::makeBanded(
  x10_int size,
  x10_int upper,
  x10_int lower) {
    
    //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::makeBanded(
             ((x10_int)0),
             ((x10_int)0),
             ((x10_int) ((size) - (((x10_int)1)))),
             ((x10_int) ((size) - (((x10_int)1)))),
             upper,
             lower);
    
}

//#line 298 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::makeUpperTriangular2(
  x10_int rowMin,
  x10_int colMin,
  x10_int size) {
    
    //#line 299 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10_int)2));
    
    //#line 300 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(ROW__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             rowMin);
    
    //#line 301 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(COL__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(LE)),
             ((x10_int) ((((x10_int) ((colMin) + (size)))) - (((x10_int)1)))));
    
    //#line 302 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(((x10_int) ((x10::array::PolyRegion::
                            FMGL(COL__get)()) - (x10::array::PolyRegion::
                                                   FMGL(ROW__get)()))),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             ((x10_int) ((colMin) - (rowMin))));
    
    //#line 303 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      pmb->toSortedPolyMat(
        true);
    
    //#line 304 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::make(pm);
    
}

//#line 307 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::makeLowerTriangular2(
  x10_int rowMin,
  x10_int colMin,
  x10_int size) {
    
    //#line 308 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10_int)2));
    
    //#line 309 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(COL__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             colMin);
    
    //#line 310 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(x10::array::PolyRegion::FMGL(ROW__get)(),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(LE)),
             ((x10_int) ((((x10_int) ((rowMin) + (size)))) - (((x10_int)1)))));
    
    //#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    pmb->add(((x10_int) ((x10::array::PolyRegion::
                            FMGL(ROW__get)()) - (x10::array::PolyRegion::
                                                   FMGL(COL__get)()))),
             ((void)(pmb),x10::array::PolyMatBuilder::
               FMGL(GE)),
             ((x10_int) ((rowMin) - (colMin))));
    
    //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      pmb->toSortedPolyMat(
        true);
    
    //#line 313 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10::array::PolyRegion::make(pm);
    
}

//#line 323 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::PolyRegion::make(
  x10aux::ref<x10::array::PolyMat> pm) {
    
    //#line 324 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
    if (x10aux::nullCheck(pm)->isEmpty())
    {
        
        //#line 325 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::EmptyRegion::_make(x10aux::nullCheck(pm)->
                                                                                                               FMGL(rank)));
        
    }
    else
    {
        
        //#line 327 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
        return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Region> >(x10::array::PolyRegion::_make(pm,
                                                                                                            false));
        
    }
    
}

//#line 331 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyRegion::_constructor(
  x10aux::ref<x10::array::PolyMat> pm,
  x10_boolean hack198) {
    this->x10::array::Region::_constructor(
      x10aux::nullCheck(pm)->
        FMGL(rank),
      x10aux::nullCheck(pm)->isRect(),
      x10aux::nullCheck(pm)->isZeroBased());
    
    //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyRegion>)this)->
      FMGL(mat) =
      (__extension__ ({
        x10aux::ref<x10::array::PolyMat> __desugarer__var__26__ =
          x10aux::nullCheck(pm)->simplifyAll();
        
        //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyMat> __var308__;
        
        //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Labeled_c
        goto __ret1950; __ret1950: 
        //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__26__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__26__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this))->
                                           FMGL(rank)))))
            {
                
                //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.PolyMat{self.rank==x10.array.PolyRegion#this.rank}"))));
            }
            
            //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
            __var308__ =
              __desugarer__var__26__;
            
            //#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Branch_c
            goto __ret1950_end_;
        }
        goto __ret1950_next_; __ret1950_next_: ;
        }
        while (false);
        goto __ret1950_end_; __ret1950_end_: ;
        __var308__;
    }))
    ;
    
}
x10aux::ref<x10::array::PolyRegion> x10::array::PolyRegion::_make(
  x10aux::ref<x10::array::PolyMat> pm,
  x10_boolean hack198) {
    x10aux::ref<x10::array::PolyRegion> this_ = new (memset(x10aux::alloc<x10::array::PolyRegion>(), 0, sizeof(x10::array::PolyRegion))) x10::array::PolyRegion();
    this_->_constructor(pm, hack198);
    return this_;
}



//#line 345 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::PolyRegion::min(
  ) {
    
    //#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->boundingBox())->min();
    
}

//#line 349 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::PolyRegion::max(
  ) {
    
    //#line 350 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->boundingBox())->max();
    
}

//#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyRegion::printInfo(x10aux::ref<x10::io::Printer> out) {
    
    //#line 359 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                        FMGL(mat))->printInfo(
      out,
      ((x10aux::ref<x10::array::PolyRegion>)this)->toString());
}

//#line 362 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::PolyRegion::toString(
  ) {
    
    //#line 363 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyRegion.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::PolyRegion>)this)->
                               FMGL(mat))->toString();
    
}
x10_boolean x10::array::PolyRegion::contains(x10_int p0) {
    return x10::array::Region::contains(p0);
}
x10_boolean x10::array::PolyRegion::contains(x10_int p0, x10_int p1) {
    return x10::array::Region::contains(p0, p1);
}
x10_boolean x10::array::PolyRegion::contains(x10_int p0, x10_int p1, x10_int p2) {
    return x10::array::Region::contains(p0, p1, p2);
}
x10_boolean x10::array::PolyRegion::contains(x10_int p0, x10_int p1, x10_int p2, x10_int p3) {
    return x10::array::Region::contains(p0, p1, p2, p3);
}
x10_int x10::array::PolyRegion::min(x10_int p0) {
    return x10::array::Region::min(p0);
}
x10_int x10::array::PolyRegion::max(x10_int p0) {
    return x10::array::Region::max(p0);
}
const x10aux::serialization_id_t x10::array::PolyRegion::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyRegion::_deserializer<x10::lang::Object>);

void x10::array::PolyRegion::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Region::_serialize_body(buf);
    buf.write(this->FMGL(mat));
    
}

void x10::array::PolyRegion::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Region::_deserialize_body(buf);
    FMGL(mat) = buf.read<x10aux::ref<x10::array::PolyMat> >();
    
}

x10aux::RuntimeType x10::array::PolyRegion::rtt;
void x10::array::PolyRegion::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Region>()};
    rtt.initStageTwo("x10.array.PolyRegion", 1, parents, 0, NULL, NULL);
}
