#include <x10/array/PolyMat.h>


#include "x10/array/PolyMat.inc"


//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.PropertyDecl_c
x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> >::itable<x10::array::PolyMat >  x10::array::PolyMat::_itable_0(&x10::array::PolyMat::apply, &x10::array::PolyMat::at, &x10::array::PolyMat::at, &x10::array::PolyMat::equals, &x10::array::PolyMat::hashCode, &x10::array::PolyMat::home, &x10::array::PolyMat::toString, &x10::array::PolyMat::typeName);
x10::lang::Any::itable<x10::array::PolyMat >  x10::array::PolyMat::_itable_1(&x10::array::PolyMat::at, &x10::array::PolyMat::at, &x10::array::PolyMat::equals, &x10::array::PolyMat::hashCode, &x10::array::PolyMat::home, &x10::array::PolyMat::toString, &x10::array::PolyMat::typeName);
x10::lang::Iterable<x10aux::ref<x10::array::PolyRow> >::itable<x10::array::PolyMat >  x10::array::PolyMat::_itable_2(&x10::array::PolyMat::at, &x10::array::PolyMat::at, &x10::array::PolyMat::equals, &x10::array::PolyMat::hashCode, &x10::array::PolyMat::home, &x10::array::PolyMat::iterator, &x10::array::PolyMat::toString, &x10::array::PolyMat::typeName);
x10aux::itable_entry x10::array::PolyMat::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::PolyRow> > >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyMat>())};
void x10::array::PolyMat::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyMat");
    
}

 /* static type PolyMat(val rank: x10.lang.Int) = x10.array.PolyMat{self.rank==rank}; */ 
 /* static type PolyMatBuilder(val rank: x10.lang.Int) = x10.array.PolyMatBuilder{self.rank==rank}; */ 

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10FieldDecl_c

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyMat::_constructor(x10_int rows, x10_int cols, x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init,
                                       x10_boolean isSimplified) {
    this->x10::array::Mat<x10aux::ref<x10::array::PolyRow> >::_constructor(
      rows,
      cols,
      x10::lang::ValRail<x10aux::ref<x10::array::PolyRow> >::make(rows, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >(x10aux::ref<x10_array_PolyMat__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >(sizeof(x10_array_PolyMat__closure__0)))x10_array_PolyMat__closure__0(cols, init))))));
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyMat>)this)->
      FMGL(rank) =
      ((x10_int) ((cols) - (((x10_int)1))));
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyMat>)this)->
      FMGL(isSimplified) =
      isSimplified;
    
}
x10aux::ref<x10::array::PolyMat> x10::array::PolyMat::_make(x10_int rows,
                                                            x10_int cols,
                                                            x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init,
                                                            x10_boolean isSimplified)
{
    x10aux::ref<x10::array::PolyMat> this_ = new (memset(x10aux::alloc<x10::array::PolyMat>(), 0, sizeof(x10::array::PolyMat))) x10::array::PolyMat();
    this_->_constructor(rows,
    cols,
    init,
    isSimplified);
    return this_;
}



//#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyMat> x10::array::PolyMat::simplifyParallel(
  ) {
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::array::PolyMat>)this)->
                                 FMGL(rows), ((x10_int)0))))
    {
        
        //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::array::PolyMat>)this);
        
    }
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyMat>)this)->
                                          FMGL(rank));
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyRow> last =
      x10aux::class_cast_unchecked<x10aux::ref<x10::array::PolyRow> >(x10aux::null);
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > next1567;
        for (
             //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             next1567 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(next1567))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)next1567)->_getITables())->hasNext))();
             ) {
            
            //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> next =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(next1567))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)next1567)->_getITables())->next))();
            
            //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(last,
                                        x10aux::null)) &&
                (!(x10aux::nullCheck(next)->isParallel(
                     last)))) {
                
                //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                pmb->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(last));
            }
            
            //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            last = next;
        }
    }
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
    pmb->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(last));
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return pmb->toSortedPolyMat(false);
    
}

//#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyMat> x10::array::PolyMat::simplifyAll(
  ) {
    
    //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
    if (((x10aux::ref<x10::array::PolyMat>)this)->
          FMGL(isSimplified)) {
        
        //#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return ((x10aux::ref<x10::array::PolyMat>)this);
        
    }
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyMat>)this)->
                                          FMGL(rank));
    
    //#line 90 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_boolean > > removed =
      x10::lang::Rail<void>::make<x10_boolean >(((x10aux::ref<x10::array::PolyMat>)this)->
                                                  FMGL(rows), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_boolean> >(x10aux::ref<x10_array_PolyMat__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_boolean> >(sizeof(x10_array_PolyMat__closure__2)))x10_array_PolyMat__closure__2()))));
    
    //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyMat>)this)->
                                         FMGL(rows)));
             
             //#line 92 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              ((x10aux::ref<x10::array::PolyMat>)this)->apply(
                i);
            
            //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyMatBuilder> trial =
              x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyMat>)this)->
                                                  FMGL(rank));
            
            //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
            {
                x10_int j;
                for (
                     //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                     j =
                       ((x10_int)0);
                     ((j) < (((x10aux::ref<x10::array::PolyMat>)this)->
                               FMGL(rows)));
                     
                     //#line 95 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                     j =
                       ((x10_int) ((j) + (((x10_int)1)))))
                {
                    
                    //#line 96 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                    if ((!((removed)->apply(j))))
                    {
                        
                        //#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                        trial->add(
                          x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >((x10aux::struct_equals(i,
                                                                                                             j))
                            ? (x10aux::ref<x10::array::PolyRow>)(x10aux::nullCheck(r)->complement())
                            : (x10aux::ref<x10::array::PolyRow>)(((x10aux::ref<x10::array::PolyMat>)this)->apply(
                                                                   j))));
                    }
                    
                }
            }
            
            //#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck(trial->toSortedPolyMat(
                                       false))->isEmpty())))
            {
                
                //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                pmb->add(
                  x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
            }
            else
            {
                
                //#line 101 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                (removed)->set(true, i);
            }
            
        }
    }
    
    //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return pmb->toSortedPolyMat(true);
    
}

//#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyMat> x10::array::PolyMat::eliminate(
  x10_int k,
  x10_boolean simplifyDegenerate) {
    
    //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyMat>)this)->
                                          FMGL(rank));
    
    //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > ir1569;
        for (
             //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             ir1569 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(ir1569))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)ir1569)->_getITables())->hasNext))();
             ) {
            
            //#line 126 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> ir =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(ir1569))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)ir1569)->_getITables())->next))();
            
            //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10_int ia = x10aux::nullCheck(ir)->apply(
                           k);
            
            //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if ((x10aux::struct_equals(ia,
                                       ((x10_int)0))))
            {
                
                //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                pmb->add(
                  x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(ir));
            }
            else
            {
                
                //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
                {
                    x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > jr1568;
                    for (
                         //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                         jr1568 =
                           ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
                         (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(jr1568))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)jr1568)->_getITables())->hasNext))();
                         )
                    {
                        
                        //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                        x10aux::ref<x10::array::PolyRow> jr =
                          (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(jr1568))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)jr1568)->_getITables())->next))();
                        
                        //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                        x10_int ja =
                          x10aux::nullCheck(jr)->apply(
                            k);
                        
                        //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                        x10aux::ref<x10::lang::Rail<x10_int > > as_ =
                          x10::lang::Rail<void>::make<x10_int >(((x10_int) ((((x10aux::ref<x10::array::PolyMat>)this)->
                                                                               FMGL(rank)) + (((x10_int)1)))));
                        
                        //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                        if (((ia) > (((x10_int)0))) &&
                            ((ja) < (((x10_int)0))))
                        {
                            
                            //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
                            {
                                x10_int l;
                                for (
                                     //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                                     l =
                                       ((x10_int)0);
                                     ((l) <= (((x10aux::ref<x10::array::PolyMat>)this)->
                                                FMGL(rank)));
                                     
                                     //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                     l =
                                       ((x10_int) ((l) + (((x10_int)1)))))
                                {
                                    
                                    //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                    (as_)->set(((x10_int) ((((x10_int) ((ia) * (x10aux::nullCheck(jr)->apply(
                                                                                  l))))) - (((x10_int) ((ja) * (x10aux::nullCheck(ir)->apply(
                                                                                                                  l))))))), l);
                                }
                            }
                            
                        }
                        else
                        
                        //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                        if (((ia) < (((x10_int)0))) &&
                            ((ja) > (((x10_int)0))))
                        {
                            
                            //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
                            {
                                x10_int l;
                                for (
                                     //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                                     l =
                                       ((x10_int)0);
                                     ((l) <= (((x10aux::ref<x10::array::PolyMat>)this)->
                                                FMGL(rank)));
                                     
                                     //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                     l =
                                       ((x10_int) ((l) + (((x10_int)1)))))
                                {
                                    
                                    //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                    (as_)->set(((x10_int) ((((x10_int) ((ja) * (x10aux::nullCheck(ir)->apply(
                                                                                  l))))) - (((x10_int) ((ia) * (x10aux::nullCheck(jr)->apply(
                                                                                                                  l))))))), l);
                                }
                            }
                            
                        }
                        
                        //#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                        x10_int lim =
                          simplifyDegenerate
                          ? (x10_int)(((x10aux::ref<x10::array::PolyMat>)this)->
                                        FMGL(rank))
                          : (x10_int)(((x10_int) ((((x10aux::ref<x10::array::PolyMat>)this)->
                                                     FMGL(rank)) + (((x10_int)1)))));
                        
                        //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                        x10_boolean degenerate =
                          true;
                        
                        //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
                        {
                            x10_int l;
                            for (
                                 //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                                 l =
                                   ((x10_int)0);
                                 ((l) < (lim));
                                 
                                 //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                 l =
                                   ((x10_int) ((l) + (((x10_int)1)))))
                            {
                                
                                //#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                                if ((!x10aux::struct_equals((as_)->apply(l),
                                                            ((x10_int)0))))
                                {
                                    
                                    //#line 145 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                                    degenerate =
                                      false;
                                }
                                
                            }
                        }
                        
                        //#line 146 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                        if ((!(degenerate)))
                        {
                            
                            //#line 147 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                            x10aux::ref<x10::array::PolyRow> r =
                              x10::array::PolyRow::_make(x10::lang::ValRail<x10_int >::make(as_));
                            
                            //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                            pmb->add(
                              x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
                        }
                        
                    }
                }
                
            }
            
        }
    }
    
    //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(pmb->toSortedPolyMat(
                               false))->simplifyParallel();
    
}

//#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyMat::isRect() {
    
    //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1570;
        for (
             //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1570 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1570))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1570)->_getITables())->hasNext))();
             ) {
            
            //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1570))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1570)->_getITables())->next))();
            
            //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck(r)->isRect())))
            {
                
                //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyMat::rectMin(x10_int axis) {
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1571;
        for (
             //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1571 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1571))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1571)->_getITables())->hasNext))();
             ) {
            
            //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1571))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1571)->_getITables())->next))();
            
            //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10_int a = x10aux::nullCheck(r)->apply(
                          axis);
            
            //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if (((a) < (((x10_int)0)))) {
                
                //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return ((x10_int) ((((x10_int) -(x10aux::nullCheck(r)->apply(
                                                   ((x10aux::ref<x10::array::PolyMat>)this)->x10::array::PolyMat::rank())))) / (a)));
                
            }
            
        }
    }
    
    //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> msg = ((((x10::lang::String::Lit("axis ")) + (axis))) + (x10::lang::String::Lit(" has no minimum")));
    
    //#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::array::UnboundedRegionException::_make(msg)));
}

//#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyMat::rectMax(x10_int axis) {
    
    //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1572;
        for (
             //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1572 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1572))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1572)->_getITables())->hasNext))();
             ) {
            
            //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1572))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1572)->_getITables())->next))();
            
            //#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10_int a = x10aux::nullCheck(r)->apply(
                          axis);
            
            //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if (((a) > (((x10_int)0)))) {
                
                //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return ((x10_int) ((((x10_int) -(x10aux::nullCheck(r)->apply(
                                                   ((x10aux::ref<x10::array::PolyMat>)this)->x10::array::PolyMat::rank())))) / (a)));
                
            }
            
        }
    }
    
    //#line 196 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> msg = ((((x10::lang::String::Lit("axis ")) + (axis))) + (x10::lang::String::Lit(" has no maximum")));
    
    //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::array::UnboundedRegionException::_make(msg)));
}

//#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::PolyMat::rectMin(
  ) {
    
    //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::PolyMat>)this)->
                                                FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyMat__closure__3>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyMat__closure__3)))x10_array_PolyMat__closure__3(this)))));
    
}

//#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > >
  x10::array::PolyMat::rectMax(
  ) {
    
    //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return x10::lang::ValRail<x10_int >::make(((x10aux::ref<x10::array::PolyMat>)this)->
                                                FMGL(rank), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyMat__closure__4>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyMat__closure__4)))x10_array_PolyMat__closure__4(this)))));
    
}

//#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyMat::isZeroBased(
  ) {
    
    //#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
    if ((!(((x10aux::ref<x10::array::PolyMat>)this)->isRect())))
    {
        
        //#line 206 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Try_c
    try {
        
        //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyMat>)this)->
                                             FMGL(rank)));
                 
                 //#line 208 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 209 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(((x10aux::ref<x10::array::PolyMat>)this)->rectMin(
                                              i),
                                            ((x10_int)0))))
                {
                    
                    //#line 210 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                    return false;
                    
                }
                
            }
        }
        
    }
    catch (x10aux::__ref& __ref__271) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__271 = (x10aux::ref<x10::lang::Throwable>&)__ref__271;
        if (x10aux::instanceof<x10aux::ref<x10::array::UnboundedRegionException> >(__exc__ref__271)) {
            x10aux::ref<x10::array::UnboundedRegionException> e =
              static_cast<x10aux::ref<x10::array::UnboundedRegionException> >(__exc__ref__271);
            {
                
                //#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return false;
                
            }
        } else
        throw;
    }
    
    //#line 214 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyMat::isBounded(
  ) {
    
    //#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Try_c
    try {
        
        //#line 219 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
        {
            x10_int i;
            for (
                 //#line 219 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
                 i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyMat>)this)->
                                             FMGL(rank)));
                 
                 //#line 219 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                 i =
                   ((x10_int) ((i) + (((x10_int)1)))))
            {
                
                //#line 220 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::array::PolyMat>)this)->rectMin(
                  i);
                
                //#line 221 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                ((x10aux::ref<x10::array::PolyMat>)this)->rectMax(
                  i);
            }
        }
        
    }
    catch (x10aux::__ref& __ref__273) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__273 = (x10aux::ref<x10::lang::Throwable>&)__ref__273;
        if (x10aux::instanceof<x10aux::ref<x10::array::UnboundedRegionException> >(__exc__ref__273)) {
            x10aux::ref<x10::array::UnboundedRegionException> e =
              static_cast<x10aux::ref<x10::array::UnboundedRegionException> >(__exc__ref__273);
            {
                
                //#line 224 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return false;
                
            }
        } else
        throw;
    }
    
    //#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 236 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyMat::isEmpty(
  ) {
    
    //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> pm =
      ((x10aux::ref<x10::array::PolyMat>)this);
    
    //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyMat>)this)->
                                         FMGL(rank)));
             
             //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            pm =
              x10aux::nullCheck(pm)->eliminate(
                i,
                false);
        }
    }
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1573;
        for (
             //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1573 = x10aux::nullCheck(pm)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1573))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1573)->_getITables())->hasNext))();
             ) {
            
            //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1573))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1573)->_getITables())->next))();
            
            //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if (((x10aux::nullCheck(r)->apply(
                    ((x10aux::ref<x10::array::PolyMat>)this)->
                      FMGL(rank))) > (((x10_int)0))))
            {
                
                //#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 248 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return false;
    
}

//#line 256 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyMat> x10::array::PolyMat::__or(
  x10aux::ref<x10::array::PolyMat> that) {
    
    //#line 257 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMatBuilder> pmb =
      x10::array::PolyMatBuilder::_make(((x10aux::ref<x10::array::PolyMat>)this)->
                                          FMGL(rank));
    
    //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1574;
        for (
             //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1574 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1574))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1574)->_getITables())->hasNext))();
             ) {
            
            //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1574))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1574)->_getITables())->next))();
            
            //#line 259 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            pmb->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
        }
    }
    
    //#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1575;
        for (
             //#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1575 = x10aux::nullCheck(that)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1575))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1575)->_getITables())->hasNext))();
             ) {
            
            //#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1575))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1575)->_getITables())->next))();
            
            //#line 261 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            pmb->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(r));
        }
    }
    
    //#line 262 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return pmb->toSortedPolyMat(false);
    
}

//#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::PolyMat::toString(
  ) {
    
    //#line 268 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> s = x10::lang::String::Lit("(");
    
    //#line 269 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
    x10_boolean first = true;
    
    //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > > r1576;
        for (
             //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
             r1576 = ((x10aux::ref<x10::array::PolyMat>)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1576))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1576)->_getITables())->hasNext))();
             ) {
            
            //#line 271 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::PolyRow> r =
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1576))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10aux::ref<x10::array::PolyRow> > >(((x10aux::ref<x10::lang::Reference>)r1576)->_getITables())->next))();
            
            //#line 272 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10If_c
            if ((!(first))) {
                
                //#line 272 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
                s = ((s) + (x10::lang::String::Lit(" && ")));
            }
            
            //#line 273 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            s = ((s) + (x10aux::nullCheck(r)->toString()));
            
            //#line 274 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
            first = false;
        }
    }
    
    //#line 277 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": polyglot.ast.Eval_c
    s = ((s) + (x10::lang::String::Lit(")")));
    
    //#line 278 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return s;
    
}

//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyMat::rank() {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMat.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyMat>)this)->
             FMGL(rank);
    
}
const x10aux::serialization_id_t x10::array::PolyMat::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyMat::_deserializer<x10::lang::Object>);

void x10::array::PolyMat::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Mat<x10aux::ref<x10::array::PolyRow> >::_serialize_body(buf);
    buf.write(this->FMGL(isSimplified));
    buf.write(this->FMGL(rank));
    
}

void x10::array::PolyMat::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Mat<x10aux::ref<x10::array::PolyRow> >::_deserialize_body(buf);
    FMGL(isSimplified) = buf.read<x10_boolean>();
    FMGL(rank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::PolyMat::rtt;
void x10::array::PolyMat::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Mat<x10aux::ref<x10::array::PolyRow> > >()};
    rtt.initStageTwo("x10.array.PolyMat", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> >::itable<x10_array_PolyMat__closure__0>x10_array_PolyMat__closure__0::_itable(&x10_array_PolyMat__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMat__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMat__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::PolyRow> > >, &x10_array_PolyMat__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMat__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMat__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__1>x10_array_PolyMat__closure__1::_itable(&x10_array_PolyMat__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMat__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMat__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyMat__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMat__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMat__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_boolean>::itable<x10_array_PolyMat__closure__2>x10_array_PolyMat__closure__2::_itable(&x10_array_PolyMat__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMat__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMat__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >, &x10_array_PolyMat__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMat__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMat__closure__2::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__3>x10_array_PolyMat__closure__3::_itable(&x10_array_PolyMat__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMat__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMat__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyMat__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMat__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMat__closure__3::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMat__closure__4>x10_array_PolyMat__closure__4::_itable(&x10_array_PolyMat__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMat__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMat__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyMat__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMat__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMat__closure__4::_deserialize<x10::lang::Object>);

