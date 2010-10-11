#include <x10/array/Dist.h>


#include "x10/array/Dist.inc"


//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.PropertyDecl_c

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.PropertyDecl_c

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.PropertyDecl_c

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.PropertyDecl_c
void x10::array::Dist::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Dist");
    
}


//#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::Dist::rank() {
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Dist>)this)->FMGL(region))->
             FMGL(rank);
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Dist::rect() {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Dist>)this)->
                               FMGL(region))->FMGL(rect);
    
}

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Dist::zeroBased() {
    
    //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Dist>)this)->
                               FMGL(region))->FMGL(zeroBased);
    
}

//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Dist::rail() {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Dist>)this)->
                               FMGL(region))->x10::array::Region::rail();
    
}

//#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeUnique() {
    
    //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeUnique1();
    
}

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeConstant(x10aux::ref<x10::array::Region> r) {
    
    //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeConstant1(r);
    
}

//#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::make(x10aux::ref<x10::array::Region> r) {
    
    //#line 99 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::Dist::makeConstant(r);
    
}

//#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeBlock(x10aux::ref<x10::array::Region> r,
                                                          x10_int axis) {
    
    //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeBlock1(r, axis);
    
}

//#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeBlock(
  x10aux::ref<x10::array::Region> r) {
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::Dist::makeBlock(r, ((x10_int)0));
    
}

//#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeUnique(
  x10aux::ref<x10::lang::Rail<x10::lang::Place > > ps) {
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeUnique1(x10::lang::ValRail<x10::lang::Place >::make(ps));
    
}

//#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeUnique(
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeUnique1(ps);
    
}

//#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeConstant(
  x10aux::ref<x10::array::Region> r,
  x10::lang::Place p) {
    
    //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeConstant1(r, p);
    
}

//#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::makeBlock(
  x10aux::ref<x10::array::Region> r,
  x10_int axis,
  x10aux::ref<x10::util::Set<x10::lang::Place> > ps) {
    
    //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10::array::BaseDist::makeBlock1(r, axis, ps);
    
}

//#line 252 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 257 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 280 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 291 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 303 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 316 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 330 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >
  x10::array::Dist::iterator(
  ) {
    
    //#line 347 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::Dist>)this)->
                               FMGL(region))->iterator();
    
}

//#line 384 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 399 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 451 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 464 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 472 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c

//#line 485 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::__bar(x10aux::ref<x10::array::Region> r) {
    
    //#line 486 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->restriction(
             r);
    
}

//#line 494 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Dist> x10::array::Dist::__bar(x10::lang::Place p) {
    
    //#line 494 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->restriction(
             p);
    
}

//#line 543 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10ConstructorDecl_c
void x10::array::Dist::_constructor(x10aux::ref<x10::array::Region> region,
                                    x10_boolean unique,
                                    x10_boolean constant,
                                    x10::lang::Place onePlace)
{
    this->x10::lang::Object::_constructor();
    
    //#line 544 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Dist>)this)->
      FMGL(region) =
      region;
    
    //#line 544 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Dist>)this)->
      FMGL(unique) =
      unique;
    
    //#line 544 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Dist>)this)->
      FMGL(constant) =
      constant;
    
    //#line 544 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Dist>)this)->
      FMGL(onePlace) =
      onePlace;
    
}


//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Region> x10::array::Dist::region(
  ) {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->FMGL(region);
    
}

//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Dist::unique() {
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->FMGL(unique);
    
}

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::Dist::constant() {
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->FMGL(constant);
    
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10MethodDecl_c
x10::lang::Place x10::array::Dist::onePlace() {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Dist.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Dist>)this)->FMGL(onePlace);
    
}
void x10::array::Dist::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(region));
    buf.write(this->FMGL(unique));
    buf.write(this->FMGL(constant));
    buf.write(this->FMGL(onePlace));
    
}

void x10::array::Dist::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(region) = buf.read<x10aux::ref<x10::array::Region> >();
    FMGL(unique) = buf.read<x10_boolean>();
    FMGL(constant) = buf.read<x10_boolean>();
    FMGL(onePlace) = buf.read<x10::lang::Place>();
}

x10aux::RuntimeType x10::array::Dist::rtt;
void x10::array::Dist::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10aux::ref<x10::array::Point>, x10::lang::Place> >(), x10aux::getRTT<x10::lang::Iterable<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.Dist", 3, parents, 0, NULL, NULL);
}
