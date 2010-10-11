#include <x10/array/BaseDist.h>


#include "x10/array/BaseDist.inc"

x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, x10::lang::Place>::itable<x10::array::BaseDist >  x10::array::BaseDist::_itable_0(&x10::array::BaseDist::apply, &x10::array::BaseDist::at, &x10::array::BaseDist::at, &x10::array::BaseDist::equals, &x10::array::BaseDist::hashCode, &x10::array::BaseDist::home, &x10::array::BaseDist::toString, &x10::array::BaseDist::typeName);
x10::lang::Any::itable<x10::array::BaseDist >  x10::array::BaseDist::_itable_1(&x10::array::BaseDist::at, &x10::array::BaseDist::at, &x10::array::BaseDist::equals, &x10::array::BaseDist::hashCode, &x10::array::BaseDist::home, &x10::array::BaseDist::toString, &x10::array::BaseDist::typeName);
x10::lang::Iterable<x10aux::ref<x10::array::Point> >::itable<x10::array::BaseDist >  x10::array::BaseDist::_itable_2(&x10::array::BaseDist::at, &x10::array::BaseDist::at, &x10::array::BaseDist::equals, &x10::array::BaseDist::hashCode, &x10::array::BaseDist::home, &x10::array::BaseDist::iterator, &x10::array::BaseDist::toString, &x10::array::BaseDist::typeName);
x10aux::itable_entry x10::array::BaseDist::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, x10::lang::Place> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::BaseDist>())};
void x10::array::BaseDist::_instance_init() {
    _I_("Doing initialisation for class: x10::array::BaseDist");
    
}

 /* static type PolyRegion(val rank: x10.lang.Int) = x10.array.PolyRegion{self.rank==rank}; */ 
 /* static type PolyRow(val rank: x10.lang.Int) = x10.array.PolyRow{self.rank==rank}; */ 
 /* static type PolyMat(val rank: x10.lang.Int) = x10.array.PolyMat{self.rank==rank}; */ 

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::FMGL(UNIQUE);
void x10::array::BaseDist::FMGL(UNIQUE__do_init)() {
    FMGL(UNIQUE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::array::BaseDist.UNIQUE");
    x10aux::ref<x10::array::Dist> __var34__ = (__extension__ ({
        x10aux::ref<x10::array::Dist> __desugarer__var__0__ = x10::array::BaseDist::makeUnique1(
                                                                x10::lang::Place_methods::
                                                                  FMGL(places__get)());
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Dist> __var35__;
        
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
        goto __ret1925; __ret1925: 
        //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
        do {
        {
            
            //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__0__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(x10aux::nullCheck(__desugarer__var__0__)->
                                                             FMGL(region))->
                                           FMGL(rect),
                                         true)) &&
                  (x10aux::struct_equals(x10aux::nullCheck(x10aux::nullCheck(__desugarer__var__0__)->
                                                             FMGL(region))->
                                           FMGL(rank),
                                         ((x10_int)1)))))
            {
                
                //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Dist{self.region.rect==true, self.region.rank==1}"))));
            }
            
            //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
            __var35__ = __desugarer__var__0__;
            
            //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
            goto __ret1925_end_;
        }
        goto __ret1925_next_; __ret1925_next_: ;
        } while (false);
        goto __ret1925_end_; __ret1925_end_: ;
        __var35__;
    }))
    ;
    FMGL(UNIQUE) = __var34__;
    FMGL(UNIQUE__status) = x10aux::INITIALIZED;
}
void x10::array::BaseDist::FMGL(UNIQUE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var36__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(UNIQUE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var36__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(UNIQUE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(UNIQUE),
                                                                    FMGL(UNIQUE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(UNIQUE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__37 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::array::BaseDist::FMGL(UNIQUE__init));

volatile x10aux::status x10::array::BaseDist::FMGL(UNIQUE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::array::BaseDist::FMGL(UNIQUE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(UNIQUE) = buf.read<x10aux::ref<x10::array::Dist> >();
    x10::array::BaseDist::FMGL(UNIQUE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::array::BaseDist::FMGL(UNIQUE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::array::BaseDist::FMGL(UNIQUE__deserialize));


//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeUnique1(
  ) {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::FMGL(UNIQUE__get)();
    
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeUnique1(
  x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps) {
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > init =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__0)))x10_array_BaseDist__closure__0())));
    
    //#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > regions =
      x10::lang::ValRail<x10aux::ref<x10::array::Region> >::make(x10aux::nullCheck(ps)->
                                                                   FMGL(length), init);
    
    //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> overall =
      x10::array::Region::makeRectangular(
        ((x10_int)0),
        ((x10_int) ((x10aux::nullCheck(ps)->
                       FMGL(length)) - (((x10_int)1)))));
    
    //#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Dist> >(x10::array::BaseDist::_make(overall,
                                                                                                    ps,
                                                                                                    regions));
    
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeBlock1(
  x10aux::ref<x10::array::Region> r,
  x10_int axis) {
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> b = x10aux::nullCheck(r)->boundingBox();
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int min = (x10aux::nullCheck(b)->min())->apply(axis);
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int max = (x10aux::nullCheck(b)->max())->apply(axis);
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int P = x10aux::num_hosts;
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int numElems = ((x10_int) ((((x10_int) ((max) - (min)))) + (((x10_int)1))));
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int blockSize = ((x10_int) ((numElems) / (P)));
    
    //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_int leftOver = ((x10_int) ((numElems) - (((x10_int) ((P) * (blockSize))))));
    
    //#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > regions =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::Region> >(P, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__1)))x10_array_BaseDist__closure__1(axis, min, blockSize, leftOver, r)))));
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Dist> >(x10::array::BaseDist::_make(r,
                                                                                                    x10::lang::Place_methods::
                                                                                                      FMGL(places__get)(),
                                                                                                    x10::lang::ValRail<x10aux::ref<x10::array::Region> >::make(regions)));
    
}

//#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeConstant1(
  x10aux::ref<x10::array::Region> r) {
    
    //#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10::array::Dist::makeConstant(
             r,
             x10::lang::Place_methods::_make(x10aux::here));
    
}

//#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeUnique1(
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeConstant1(
  x10aux::ref<x10::array::Region> r,
  x10::lang::Place p) {
    
    //#line 115 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Dist> >(x10::array::BaseDist::_make(r,
                                                                                                    (x10aux::ref<x10::lang::ValRail<x10::lang::Place > >)x10aux::alloc_rail<x10::lang::Place,
                                                                                                    x10::lang::ValRail<x10::lang::Place > >(1,(p)),
                                                                                                    (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >)x10aux::alloc_rail<x10aux::ref<x10::array::Region>,
                                                                                                    x10::lang::ValRail<x10aux::ref<x10::array::Region> > >(1,(r))));
    
}

//#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeCyclic1(
  x10aux::ref<x10::array::Region> r,
  x10_int axis,
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeBlock1(
  x10aux::ref<x10::array::Region> r,
  x10_int axis,
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::makeBlockCyclic1(
  x10aux::ref<x10::array::Region> r,
  x10_int axis,
  x10_int blockSize,
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10::lang::Place > >
  x10::array::BaseDist::places(
  ) {
    
    //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->
             FMGL(places);
    
}

//#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > >
  x10::array::BaseDist::regions(
  ) {
    
    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->
             FMGL(regions);
    
}

//#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::BaseDist::get(
  x10::lang::Place p) {
    
    //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::Region> __desugarer__var__2__ =
          (((x10aux::ref<x10::array::BaseDist>)this)->
             FMGL(regionMap))->apply(p->
                                       FMGL(id));
        
        //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> __var53__;
        
        //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
        goto __ret1927; __ret1927: 
        //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__2__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__2__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                             FMGL(region))->
                                           FMGL(rank)))))
            {
                
                //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==x10.array.BaseDist#this.region.rank}"))));
            }
            
            //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
            __var53__ =
              __desugarer__var__2__;
            
            //#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
            goto __ret1927_end_;
        }
        goto __ret1927_next_; __ret1927_next_: ;
        }
        while (false);
        goto __ret1927_end_; __ret1927_end_: ;
        __var53__;
    }))
    ;
    
}

//#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::BaseDist::apply(
  x10::lang::Place p) {
    
    //#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->get(
             p);
    
}

//#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::apply(
  x10aux::ref<x10::array::Point> pt) {
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->
                                                           FMGL(regionMap))->
                                         FMGL(length)));
             
             //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if (x10aux::nullCheck((((x10aux::ref<x10::array::BaseDist>)this)->
                                     FMGL(regionMap))->apply(i))->contains(
                  (__extension__ ({
                      x10aux::ref<x10::array::Point> __desugarer__var__3__ =
                        pt;
                      
                      //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                      x10aux::ref<x10::array::Point> __var56__;
                      
                      //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                      goto __ret1928; __ret1928: 
                      //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                      do
                      {
                      {
                          
                          //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                          if ((!x10aux::struct_equals(__desugarer__var__3__,
                                                      x10aux::null)) &&
                              !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__3__)->
                                                         FMGL(rank),
                                                       x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                           FMGL(region))->
                                                         FMGL(rank)))))
                          {
                              
                              //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                              x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.BaseDist#this.region.rank}"))));
                          }
                          
                          //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                          __var56__ =
                            __desugarer__var__3__;
                          
                          //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                          goto __ret1928_end_;
                      }
                      goto __ret1928_next_; __ret1928_next_: ;
                      }
                      while (false);
                      goto __ret1928_end_; __ret1928_end_: ;
                      __var56__;
                  }))
                  ))
            {
                
                //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
                return (x10::lang::Place_methods::
                          FMGL(places__get)())->apply(i);
                
            }
            
        }
    }
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::ArrayIndexOutOfBoundsException::_make(((((x10::lang::String::Lit("point ")) + (pt))) + (x10::lang::String::Lit(" not contained in distribution"))))));
}

//#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::apply(
  x10_int i0) {
    
    //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->apply(
             (__extension__ ({
                 x10aux::ref<x10::array::Point> __desugarer__var__4__ =
                   x10::array::Point::__implicit_convert(
                     (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                     x10::lang::ValRail<x10_int > >(1,(i0)));
                 
                 //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                 x10aux::ref<x10::array::Point> __var58__;
                 
                 //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                 goto __ret1929; __ret1929: 
                 //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                 do
                 {
                 {
                     
                     //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                     if ((!x10aux::struct_equals(__desugarer__var__4__,
                                                 x10aux::null)) &&
                         !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__4__)->
                                                    FMGL(rank),
                                                  x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                      FMGL(region))->
                                                    FMGL(rank)))))
                     {
                         
                         //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                         x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.BaseDist#this.region.rank}"))));
                     }
                     
                     //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                     __var58__ =
                       __desugarer__var__4__;
                     
                     //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                     goto __ret1929_end_;
                 }
                 goto __ret1929_next_; __ret1929_next_: ;
                 }
                 while (false);
                 goto __ret1929_end_; __ret1929_end_: ;
                 __var58__;
             }))
             );
    
}

//#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::apply(
  x10_int i0,
  x10_int i1) {
    
    //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->apply(
             (__extension__ ({
                 x10aux::ref<x10::array::Point> __desugarer__var__5__ =
                   x10::array::Point::__implicit_convert(
                     (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                     x10::lang::ValRail<x10_int > >(2,(i0),(i1)));
                 
                 //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                 x10aux::ref<x10::array::Point> __var61__;
                 
                 //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                 goto __ret1930; __ret1930: 
                 //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                 do
                 {
                 {
                     
                     //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                     if ((!x10aux::struct_equals(__desugarer__var__5__,
                                                 x10aux::null)) &&
                         !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__5__)->
                                                    FMGL(rank),
                                                  x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                      FMGL(region))->
                                                    FMGL(rank)))))
                     {
                         
                         //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                         x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.BaseDist#this.region.rank}"))));
                     }
                     
                     //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                     __var61__ =
                       __desugarer__var__5__;
                     
                     //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                     goto __ret1930_end_;
                 }
                 goto __ret1930_next_; __ret1930_next_: ;
                 }
                 while (false);
                 goto __ret1930_end_; __ret1930_end_: ;
                 __var61__;
             }))
             );
    
}

//#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::apply(
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->apply(
             (__extension__ ({
                 x10aux::ref<x10::array::Point> __desugarer__var__6__ =
                   x10::array::Point::__implicit_convert(
                     (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                     x10::lang::ValRail<x10_int > >(3,(i0),(i1),(i2)));
                 
                 //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                 x10aux::ref<x10::array::Point> __var64__;
                 
                 //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                 goto __ret1931; __ret1931: 
                 //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                 do
                 {
                 {
                     
                     //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                     if ((!x10aux::struct_equals(__desugarer__var__6__,
                                                 x10aux::null)) &&
                         !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__6__)->
                                                    FMGL(rank),
                                                  x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                      FMGL(region))->
                                                    FMGL(rank)))))
                     {
                         
                         //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                         x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.BaseDist#this.region.rank}"))));
                     }
                     
                     //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                     __var64__ =
                       __desugarer__var__6__;
                     
                     //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                     goto __ret1931_end_;
                 }
                 goto __ret1931_next_; __ret1931_next_: ;
                 }
                 while (false);
                 goto __ret1931_end_; __ret1931_end_: ;
                 __var64__;
             }))
             );
    
}

//#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::apply(
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::BaseDist>)this)->apply(
             (__extension__ ({
                 x10aux::ref<x10::array::Point> __desugarer__var__7__ =
                   x10::array::Point::__implicit_convert(
                     (x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                     x10::lang::ValRail<x10_int > >(4,(i0),(i1),(i2),(i3)));
                 
                 //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                 x10aux::ref<x10::array::Point> __var67__;
                 
                 //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                 goto __ret1932; __ret1932: 
                 //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                 do
                 {
                 {
                     
                     //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                     if ((!x10aux::struct_equals(__desugarer__var__7__,
                                                 x10aux::null)) &&
                         !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__7__)->
                                                    FMGL(rank),
                                                  x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                      FMGL(region))->
                                                    FMGL(rank)))))
                     {
                         
                         //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                         x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.BaseDist#this.region.rank}"))));
                     }
                     
                     //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                     __var67__ =
                       __desugarer__var__7__;
                     
                     //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                     goto __ret1932_end_;
                 }
                 goto __ret1932_next_; __ret1932_next_: ;
                 }
                 while (false);
                 goto __ret1932_end_; __ret1932_end_: ;
                 __var67__;
             }))
             );
    
}

//#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::restriction(
  x10aux::ref<x10::array::Region> r) {
    
    //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps =
      ((x10aux::ref<x10::array::BaseDist>)this)->
        FMGL(places);
    
    //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > init =
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__2)))x10_array_BaseDist__closure__2(this, r))));
    
    //#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs =
      x10::lang::ValRail<x10aux::ref<x10::array::Region> >::make(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->
                                                                                     FMGL(regions))->
                                                                   FMGL(length), init);
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Dist> >(x10::array::BaseDist::_make(r,
                                                                                                    ps,
                                                                                                    rs));
    
}

//#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::BaseDist::restriction(
  x10::lang::Place p) {
    
    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps =
      (x10aux::ref<x10::lang::ValRail<x10::lang::Place > >)x10aux::alloc_rail<x10::lang::Place,
    x10::lang::ValRail<x10::lang::Place > >(1,(p));
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs =
      x10::lang::ValRail<x10aux::ref<x10::array::Region> >::make(((x10_int)1), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__3>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__3)))x10_array_BaseDist__closure__3(this, p)))));
    
    //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::class_cast_unchecked<x10aux::ref<x10::array::Dist> >(x10::array::BaseDist::_make((__extension__ ({
                                                                                                        x10aux::ref<x10::array::Region> __desugarer__var__8__ =
                                                                                                          x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->
                                                                                                                              FMGL(region))->intersection(
                                                                                                            (rs)->apply(((x10_int)0)));
                                                                                                        
                                                                                                        //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                                                                                                        x10aux::ref<x10::array::Region> __var72__;
                                                                                                        
                                                                                                        //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                                                                                                        goto __ret1933; __ret1933: 
                                                                                                        //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                                                                                                        do
                                                                                                        {
                                                                                                        {
                                                                                                            
                                                                                                            //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                                                                                                            if ((!x10aux::struct_equals(__desugarer__var__8__,
                                                                                                                                        x10aux::null)) &&
                                                                                                                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__8__)->
                                                                                                                                           FMGL(rank),
                                                                                                                                         x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this))->
                                                                                                                                                             FMGL(region))->
                                                                                                                                           FMGL(rank)))))
                                                                                                            {
                                                                                                                
                                                                                                                //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                                                                                                                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==x10.array.BaseDist#this.region.rank}"))));
                                                                                                            }
                                                                                                            
                                                                                                            //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                                                                                                            __var72__ =
                                                                                                              __desugarer__var__8__;
                                                                                                            
                                                                                                            //#line 184 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                                                                                                            goto __ret1933_end_;
                                                                                                        }
                                                                                                        goto __ret1933_next_; __ret1933_next_: ;
                                                                                                        }
                                                                                                        while (false);
                                                                                                        goto __ret1933_end_; __ret1933_end_: ;
                                                                                                        __var72__;
                                                                                                    }))
                                                                                                    ,
                                                                                                    ps,
                                                                                                    rs));
    
}

//#line 277 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::BaseDist::isSubdistribution(
  x10aux::ref<x10::array::Dist> that) {
    
    //#line 278 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10::lang::Place> > p1350;
        for (
             //#line 278 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             p1350 = (x10::lang::Place_methods::
                        FMGL(places__get)())->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1350))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1350)->_getITables())->hasNext))();
             ) {
            
            //#line 278 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
            x10::lang::Place p = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1350))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1350)->_getITables())->next))();
            
            //#line 279 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck(x10aux::nullCheck(that)->get(
                                       p))->contains(
                     ((x10aux::ref<x10::array::BaseDist>)this)->get(
                       p))))) {
                
                //#line 280 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 281 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 290 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::BaseDist::isUnique(
  x10aux::ref<x10::lang::Rail<x10::lang::Place > > places) {
    
    //#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(x10aux::nullCheck(places)->
                                  FMGL(length),
                                x10aux::num_hosts)))
    {
        
        //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (x10aux::nullCheck(places)->
                                         FMGL(length)));
             
             //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 294 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals((places)->apply(i)->
                                          FMGL(id),
                                        i)))
            {
                
                //#line 295 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 297 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 300 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::BaseDist::isConstant(
  x10aux::ref<x10::lang::Rail<x10::lang::Place > > places) {
    
    //#line 301 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10::lang::Place> > p1351;
        for (
             //#line 301 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             p1351 = (places)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1351))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1351)->_getITables())->hasNext))();
             ) {
            
            //#line 301 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
            x10::lang::Place p = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1351))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1351)->_getITables())->next))();
            
            //#line 302 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(p,
                                        (places)->apply(((x10_int)0)))))
            {
                
                //#line 303 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 304 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 307 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::BaseDist::onePlace(
  x10aux::ref<x10::lang::Rail<x10::lang::Place > > places) {
    
    //#line 308 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(x10aux::nullCheck(places)->
                                    FMGL(length),
                                  ((x10_int)0)))
      ? (x10::lang::Place)(x10::lang::Place_methods::_make(x10aux::here))
      : (x10::lang::Place)((places)->apply(((x10_int)0)));
    
}

//#line 311 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::BaseDist::equals(
  x10aux::ref<x10::lang::Any> thatObj) {
    
    //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::Dist> >(thatObj))))
    {
        
        //#line 312 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 313 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Dist> that = x10aux::class_cast<x10aux::ref<x10::array::Dist> >(thatObj);
    
    //#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10::lang::Place> > p1352;
        for (
             //#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             p1352 = (x10::lang::Place_methods::
                        FMGL(places__get)())->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1352))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1352)->_getITables())->hasNext))();
             ) {
            
            //#line 314 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
            x10::lang::Place p = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1352))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1352)->_getITables())->next))();
            
            //#line 315 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->get(
                                       p))->equals(
                     x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10aux::nullCheck(that)->get(
                                                                                  p))))))
            {
                
                //#line 316 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 317 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 321 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::BaseDist::contains(
  x10aux::ref<x10::array::Point> p) {
    
    //#line 321 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->
                               FMGL(region))->contains(
             p);
    
}

//#line 333 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10FieldDecl_c

//#line 334 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10FieldDecl_c

//#line 335 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10FieldDecl_c

//#line 337 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10ConstructorDecl_c
void x10::array::BaseDist::_constructor(x10aux::ref<x10::array::Region> r,
                                        x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps,
                                        x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs)
{
    this->x10::array::Dist::_constructor(
      r,
      x10::array::BaseDist::isUnique(
        x10::lang::Rail<void>::make<x10::lang::Place >(ps)),
      x10::array::BaseDist::isConstant(
        x10::lang::Rail<void>::make<x10::lang::Place >(ps)),
      x10::array::BaseDist::onePlace(
        x10::lang::Rail<void>::make<x10::lang::Place >(ps)));
    
    //#line 342 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<x10aux::ref<x10::array::Region> > > rl =
      x10::util::ArrayList<x10aux::ref<x10::array::Region> >::_make();
    
    //#line 345 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::GrowableRail<x10::lang::Place > > pl =
      x10::util::GrowableRail<x10::lang::Place >::_make();
    
    //#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             i =
               ((x10_int)0);
             ((i) < (x10aux::nullCheck(rs)->
                       FMGL(length)));
             
             //#line 346 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!(x10aux::nullCheck((rs)->apply(i))->isEmpty())))
            {
                
                //#line 348 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                x10aux::placeCheck(rl)->add(
                  (rs)->apply(i));
                
                //#line 349 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                (pl)->add((ps)->apply(i));
            }
            
        }
    }
    
    //#line 352 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::BaseDist>)this)->
      FMGL(regions) =
      (x10aux::placeCheck(rl)->toValRail());
    
    //#line 353 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::BaseDist>)this)->
      FMGL(places) =
      (pl)->toValRail();
    
    //#line 356 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Region> empty =
      x10::array::Region::makeEmpty(
        ((x10aux::ref<x10::array::BaseDist>)this)->x10::array::BaseDist::rank());
    
    //#line 357 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > regionMap =
      x10::lang::Rail<void>::make<x10aux::ref<x10::array::Region> >(x10aux::num_hosts, x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__4>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__4)))x10_array_BaseDist__closure__4(empty)))));
    
    //#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             i =
               ((x10_int)0);
             ((i) < (x10aux::nullCheck(((x10aux::ref<x10::array::BaseDist>)this)->
                                         FMGL(places))->
                       FMGL(length)));
             
             //#line 358 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 359 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
            (regionMap)->set((((x10aux::ref<x10::array::BaseDist>)this)->
                                FMGL(regions))->apply(i), (((x10aux::ref<x10::array::BaseDist>)this)->
                                                             FMGL(places))->apply(i)->
                                                            FMGL(id));
        }
    }
    
    //#line 360 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::BaseDist>)this)->
      FMGL(regionMap) =
      x10::lang::ValRail<x10aux::ref<x10::array::Region> >::make(x10aux::nullCheck(regionMap)->
                                                                   FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(x10aux::ref<x10_array_BaseDist__closure__5>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(sizeof(x10_array_BaseDist__closure__5)))x10_array_BaseDist__closure__5(regionMap)))));
    
}
x10aux::ref<x10::array::BaseDist> x10::array::BaseDist::_make(
  x10aux::ref<x10::array::Region> r,
  x10aux::ref<x10::lang::ValRail<x10::lang::Place > > ps,
  x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > rs)
{
    x10aux::ref<x10::array::BaseDist> this_ = new (memset(x10aux::alloc<x10::array::BaseDist>(), 0, sizeof(x10::array::BaseDist))) x10::array::BaseDist();
    this_->_constructor(r,
    ps,
    rs);
    return this_;
}



//#line 368 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::BaseDist::toString(
  ) {
    
    //#line 369 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> s = x10::lang::String::Lit("Dist(");
    
    //#line 370 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
    x10_boolean first = true;
    
    //#line 371 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<x10::lang::Place> > p1353;
        for (
             //#line 371 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
             p1353 = (((x10aux::ref<x10::array::BaseDist>)this)->
                        FMGL(places))->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1353))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1353)->_getITables())->hasNext))();
             ) {
            
            //#line 371 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
            x10::lang::Place p = (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(p1353))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<x10::lang::Place> >(((x10aux::ref<x10::lang::Reference>)p1353)->_getITables())->next))();
            
            //#line 372 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
            if ((!(first))) {
                
                //#line 372 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                s = ((s) + (x10::lang::String::Lit(",")));
            }
            
            //#line 373 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
            s = ((s) + (((((((x10aux::ref<x10::array::BaseDist>)this)->get(
                              p)) + (x10::lang::String::Lit("->")))) + (p->
                                                                          FMGL(id)))));
            
            //#line 374 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
            first = false;
        }
    }
    
    //#line 376 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
    s = ((s) + (x10::lang::String::Lit(")")));
    
    //#line 377 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
    return s;
    
}
const x10aux::serialization_id_t x10::array::BaseDist::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::BaseDist::_deserializer<x10::lang::Object>);

void x10::array::BaseDist::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::Dist::_serialize_body(buf);
    buf.write(this->FMGL(places));
    buf.write(this->FMGL(regions));
    buf.write(this->FMGL(regionMap));
    
}

void x10::array::BaseDist::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::Dist::_deserialize_body(buf);
    FMGL(places) = buf.read<x10aux::ref<x10::lang::ValRail<x10::lang::Place > > >();
    FMGL(regions) = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > >();
    FMGL(regionMap) = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::Region> > > >();
}

x10aux::RuntimeType x10::array::BaseDist::rtt;
void x10::array::BaseDist::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::Dist>()};
    rtt.initStageTwo("x10.array.BaseDist", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__0>x10_array_BaseDist__closure__0::_itable(&x10_array_BaseDist__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__1>x10_array_BaseDist__closure__1::_itable(&x10_array_BaseDist__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__2>x10_array_BaseDist__closure__2::_itable(&x10_array_BaseDist__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__2::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__3>x10_array_BaseDist__closure__3::_itable(&x10_array_BaseDist__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__3::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__4>x10_array_BaseDist__closure__4::_itable(&x10_array_BaseDist__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__4::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__5>x10_array_BaseDist__closure__5::_itable(&x10_array_BaseDist__closure__5::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_BaseDist__closure__5::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_BaseDist__closure__5::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >, &x10_array_BaseDist__closure__5::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_BaseDist__closure__5::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_BaseDist__closure__5::_deserialize<x10::lang::Object>);

