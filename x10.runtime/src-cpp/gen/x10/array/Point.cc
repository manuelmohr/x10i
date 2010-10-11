#include <x10/array/Point.h>


#include "x10/array/Point.inc"


//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.PropertyDecl_c
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10::array::Point >  x10::array::Point::_itable_0(&x10::array::Point::apply, &x10::array::Point::at, &x10::array::Point::at, &x10::array::Point::equals, &x10::array::Point::hashCode, &x10::array::Point::home, &x10::array::Point::toString, &x10::array::Point::typeName);
x10::lang::Any::itable<x10::array::Point >  x10::array::Point::_itable_1(&x10::array::Point::at, &x10::array::Point::at, &x10::array::Point::equals, &x10::array::Point::hashCode, &x10::array::Point::home, &x10::array::Point::toString, &x10::array::Point::typeName);
x10::util::Ordered<x10aux::ref<x10::array::Point> >::itable<x10::array::Point >  x10::array::Point::_itable_2(&x10::array::Point::at, &x10::array::Point::at, &x10::array::Point::equals, &x10::array::Point::hashCode, &x10::array::Point::home, &x10::array::Point::__lt, &x10::array::Point::__le, &x10::array::Point::__gt, &x10::array::Point::__ge, &x10::array::Point::toString, &x10::array::Point::typeName);
x10aux::itable_entry x10::array::Point::_itables[4] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(&x10aux::getRTT<x10::util::Ordered<x10aux::ref<x10::array::Point> > >, &_itable_2), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::Point>())};
void x10::array::Point::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Point");
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Point::apply(x10_int i) {
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Point>)this)->FMGL(coords))->apply(i);
    
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10_int > > x10::array::Point::coords() {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Point>)this)->FMGL(coords);
    
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(x10aux::ref<x10::lang::ValRail<x10_int > > cs) {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::_make(cs);
    
}

//#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(x10aux::ref<x10::lang::Rail<x10_int > > cs) {
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > a = x10::lang::ValRail<x10_int >::make(x10aux::nullCheck(cs)->
                                                                                        FMGL(length), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__0)))x10_array_Point__closure__0(cs)))));
    
    //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(a);
    
}

//#line 53 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(x10_int rank,
                                                       x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > init) {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::ValRail<x10_int > > a = x10::lang::ValRail<x10_int >::make(rank, init);
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(a);
    
}

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(x10_int i0) {
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make((x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                   x10::lang::ValRail<x10_int > >(1,(i0)));
    
}

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(x10_int i0,
                                                       x10_int i1) {
    
    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make((x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                   x10::lang::ValRail<x10_int > >(2,(i0),(i1)));
    
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(
  x10_int i0,
  x10_int i1,
  x10_int i2) {
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make((x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                   x10::lang::ValRail<x10_int > >(3,(i0),(i1),(i2)));
    
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::make(
  x10_int i0,
  x10_int i1,
  x10_int i2,
  x10_int i3) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make((x10aux::ref<x10::lang::ValRail<x10_int > >)x10aux::alloc_rail<x10_int,
                                   x10::lang::ValRail<x10_int > >(4,(i0),(i1),(i2),(i3)));
    
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__implicit_convert(
  x10aux::ref<x10::lang::Rail<x10_int > > r) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(r);
    
}

//#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__implicit_convert(
  x10aux::ref<x10::lang::ValRail<x10_int > > r) {
    
    //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(r);
    
}

//#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__plus(
  ) {
    
    //#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Point>)this);
    
}

//#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__minus(
  ) {
    
    //#line 83 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__1)))x10_array_Point__closure__1(this)))));
    
}

//#line 87 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__plus(
  x10aux::ref<x10::array::Point> that) {
    
    //#line 88 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__2)))x10_array_Point__closure__2(this, that)))));
    
}

//#line 93 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__minus(
  x10aux::ref<x10::array::Point> that) {
    
    //#line 94 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__3>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__3)))x10_array_Point__closure__3(this, that)))));
    
}

//#line 98 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__times(
  x10aux::ref<x10::array::Point> that) {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__4>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__4)))x10_array_Point__closure__4(this, that)))));
    
}

//#line 103 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__over(
  x10aux::ref<x10::array::Point> that) {
    
    //#line 104 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__5>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__5)))x10_array_Point__closure__5(this, that)))));
    
}

//#line 108 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__plus(
  x10_int c) {
    
    //#line 109 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__6>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__6)))x10_array_Point__closure__6(this, c)))));
    
}

//#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__minus(
  x10_int c) {
    
    //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__7>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__7)))x10_array_Point__closure__7(this, c)))));
    
}

//#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__times(
  x10_int c) {
    
    //#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__8>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__8)))x10_array_Point__closure__8(this, c)))));
    
}

//#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__over(
  x10_int c) {
    
    //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__9>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__9)))x10_array_Point__closure__9(this, c)))));
    
}

//#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__inv_plus(
  x10_int c) {
    
    //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__10>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__10)))x10_array_Point__closure__10(c, this)))));
    
}

//#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__inv_minus(
  x10_int c) {
    
    //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__11>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__11)))x10_array_Point__closure__11(c, this)))));
    
}

//#line 138 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__inv_times(
  x10_int c) {
    
    //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__12>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__12)))x10_array_Point__closure__12(c, this)))));
    
}

//#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::Point::__inv_over(
  x10_int c) {
    
    //#line 144 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return x10::array::Point::make(((x10aux::ref<x10::array::Point>)this)->
                                     FMGL(rank),
                                   x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_Point__closure__13>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_Point__closure__13)))x10_array_Point__closure__13(c, this)))));
    
}

//#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Point::hashCode() {
    
    //#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
    x10_int hc = (((x10aux::ref<x10::array::Point>)this)->
                    FMGL(coords))->apply(((x10_int)0));
    
    //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (((x10aux::ref<x10::array::Point>)this)->
                                         FMGL(rank)));
             
             //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
            hc =
              ((x10_int) ((((x10_int) ((hc) * (((x10_int)17))))) ^ ((((x10aux::ref<x10::array::Point>)this)->
                                                                       FMGL(coords))->apply(i))));
        }
    }
    
    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return hc;
    
}

//#line 164 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Point::equals(x10aux::ref<x10::lang::Any> other) {
    
    //#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10aux::ref<x10::array::Point> >(other))))
    {
        
        //#line 165 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 166 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Point> otherPoint =
      x10aux::class_cast<x10aux::ref<x10::array::Point> >(other);
    
    //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
    if ((!x10aux::struct_equals(((x10aux::ref<x10::array::Point>)this)->
                                  FMGL(rank),
                                x10aux::nullCheck(otherPoint)->
                                  FMGL(rank))))
    {
        
        //#line 167 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::Point>)this)->
                                         FMGL(rank)));
             
             //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 169 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if ((!((x10aux::struct_equals((((x10aux::ref<x10::array::Point>)this)->
                                             FMGL(coords))->apply(i),
                                          (x10aux::nullCheck(otherPoint)->
                                             FMGL(coords))->apply(i))))))
            {
                
                //#line 170 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return false;
                
            }
            
        }
    }
    
    //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Point::__lt(x10aux::ref<x10::array::Point> that) {
    
    //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                      FMGL(rank)) - (((x10_int)1))))));
             
             //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              (((x10aux::ref<x10::array::Point>)this)->
                 FMGL(coords))->apply(i);
            
            //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              (x10aux::nullCheck(that)->
                 FMGL(coords))->apply(i);
            
            //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) > (b)))
            {
                
                //#line 180 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return false;
                
            }
            
            //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) < (b)))
            {
                
                //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return (((((x10aux::ref<x10::array::Point>)this)->
                FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                    FMGL(rank)) - (((x10_int)1)))))) < ((x10aux::nullCheck(that)->
                                                                                           FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                                                                                               FMGL(rank)) - (((x10_int)1)))))));
    
}

//#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Point::__gt(x10aux::ref<x10::array::Point> that) {
    
    //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                      FMGL(rank)) - (((x10_int)1))))));
             
             //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              (((x10aux::ref<x10::array::Point>)this)->
                 FMGL(coords))->apply(i);
            
            //#line 191 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              (x10aux::nullCheck(that)->
                 FMGL(coords))->apply(i);
            
            //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) < (b)))
            {
                
                //#line 192 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return false;
                
            }
            
            //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) > (b)))
            {
                
                //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 195 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return (((((x10aux::ref<x10::array::Point>)this)->
                FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                    FMGL(rank)) - (((x10_int)1)))))) > ((x10aux::nullCheck(that)->
                                                                                           FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                                                                                               FMGL(rank)) - (((x10_int)1)))))));
    
}

//#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Point::__le(x10aux::ref<x10::array::Point> that) {
    
    //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                      FMGL(rank)) - (((x10_int)1))))));
             
             //#line 201 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 202 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              (((x10aux::ref<x10::array::Point>)this)->
                 FMGL(coords))->apply(i);
            
            //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              (x10aux::nullCheck(that)->
                 FMGL(coords))->apply(i);
            
            //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) > (b)))
            {
                
                //#line 204 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return false;
                
            }
            
            //#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) < (b)))
            {
                
                //#line 205 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 207 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return (((((x10aux::ref<x10::array::Point>)this)->
                FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                    FMGL(rank)) - (((x10_int)1)))))) <= ((x10aux::nullCheck(that)->
                                                                                            FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                                                                                                FMGL(rank)) - (((x10_int)1)))))));
    
}

//#line 212 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Point::__ge(x10aux::ref<x10::array::Point> that) {
    
    //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                      FMGL(rank)) - (((x10_int)1))))));
             
             //#line 213 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 214 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              (((x10aux::ref<x10::array::Point>)this)->
                 FMGL(coords))->apply(i);
            
            //#line 215 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
            x10_int b =
              (x10aux::nullCheck(that)->
                 FMGL(coords))->apply(i);
            
            //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) < (b)))
            {
                
                //#line 216 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return false;
                
            }
            
            //#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
            if (((a) > (b)))
            {
                
                //#line 217 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
                return true;
                
            }
            
        }
    }
    
    //#line 219 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return (((((x10aux::ref<x10::array::Point>)this)->
                FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                    FMGL(rank)) - (((x10_int)1)))))) >= ((x10aux::nullCheck(that)->
                                                                                            FMGL(coords))->apply(((x10_int) ((((x10aux::ref<x10::array::Point>)this)->
                                                                                                                                FMGL(rank)) - (((x10_int)1)))))));
    
}

//#line 224 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::array::Point::toString(
  ) {
    
    //#line 225 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::String> s = x10::lang::String::Lit("(");
    
    //#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10If_c
    if (((x10aux::nullCheck(((x10aux::ref<x10::array::Point>)this)->
                              FMGL(coords))->
            FMGL(length)) > (((x10_int)0))))
    {
        
        //#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
        s =
          ((s) + ((((x10aux::ref<x10::array::Point>)this)->
                     FMGL(coords))->apply(((x10_int)0))));
    }
    
    //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)1); ((i) < (x10aux::nullCheck(((x10aux::ref<x10::array::Point>)this)->
                                                           FMGL(coords))->
                                         FMGL(length)));
             
             //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 228 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
            s =
              ((s) + (((x10::lang::String::Lit(",")) + ((((x10aux::ref<x10::array::Point>)this)->
                                                           FMGL(coords))->apply(i)))));
        }
    }
    
    //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
    s = ((s) + (x10::lang::String::Lit(")")));
    
    //#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return s;
    
}

//#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10FieldDecl_c

//#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10ConstructorDecl_c
void x10::array::Point::_constructor(x10aux::ref<x10::lang::ValRail<x10_int > > cs)
{
    this->x10::lang::Object::_constructor();
    
    //#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Point>)this)->
      FMGL(rank) =
      x10aux::nullCheck(cs)->
        FMGL(length);
    
    //#line 236 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Point>)this)->
      FMGL(coords) =
      cs;
    
}
x10aux::ref<x10::array::Point> x10::array::Point::_make(
  x10aux::ref<x10::lang::ValRail<x10_int > > cs)
{
    x10aux::ref<x10::array::Point> this_ = new (memset(x10aux::alloc<x10::array::Point>(), 0, sizeof(x10::array::Point))) x10::array::Point();
    this_->_constructor(cs);
    return this_;
}



//#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Point::rank() {
    
    //#line 24 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Point.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Point>)this)->
             FMGL(rank);
    
}
const x10aux::serialization_id_t x10::array::Point::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::Point::_deserializer<x10::lang::Object>);

void x10::array::Point::_serialize(x10aux::ref<x10::array::Point> this_,
                                   x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::Point::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(coords));
    buf.write(this->FMGL(rank));
    
}

void x10::array::Point::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(coords) = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
    FMGL(rank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::Point::rtt;
void x10::array::Point::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(), x10aux::getRTT<x10::util::Ordered<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.Point", 3, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__0>x10_array_Point__closure__0::_itable(&x10_array_Point__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__1>x10_array_Point__closure__1::_itable(&x10_array_Point__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__2>x10_array_Point__closure__2::_itable(&x10_array_Point__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__2::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__3>x10_array_Point__closure__3::_itable(&x10_array_Point__closure__3::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__3::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__3::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__3::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__3::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__3::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__4>x10_array_Point__closure__4::_itable(&x10_array_Point__closure__4::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__4::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__4::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__4::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__4::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__4::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__5>x10_array_Point__closure__5::_itable(&x10_array_Point__closure__5::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__5::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__5::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__5::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__5::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__5::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__6>x10_array_Point__closure__6::_itable(&x10_array_Point__closure__6::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__6::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__6::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__6::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__6::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__6::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__7>x10_array_Point__closure__7::_itable(&x10_array_Point__closure__7::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__7::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__7::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__7::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__7::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__7::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__8>x10_array_Point__closure__8::_itable(&x10_array_Point__closure__8::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__8::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__8::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__8::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__8::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__8::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__9>x10_array_Point__closure__9::_itable(&x10_array_Point__closure__9::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__9::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__9::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__9::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__9::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__9::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__10>x10_array_Point__closure__10::_itable(&x10_array_Point__closure__10::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__10::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__10::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__10::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__10::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__10::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__11>x10_array_Point__closure__11::_itable(&x10_array_Point__closure__11::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__11::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__11::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__11::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__11::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__11::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__12>x10_array_Point__closure__12::_itable(&x10_array_Point__closure__12::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__12::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__12::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__12::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__12::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__12::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_Point__closure__13>x10_array_Point__closure__13::_itable(&x10_array_Point__closure__13::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_Point__closure__13::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_Point__closure__13::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_Point__closure__13::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_Point__closure__13::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_Point__closure__13::_deserialize<x10::lang::Object>);

