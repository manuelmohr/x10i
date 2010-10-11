#include <x10/array/PolyMatBuilder.h>


#include "x10/array/PolyMatBuilder.inc"


//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.PropertyDecl_c
void x10::array::PolyMatBuilder::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyMatBuilder");
    
}

 /* static type PolyMat(val rank: x10.lang.Int) = x10.array.PolyMat{self.rank==rank}; */ 
 /* static type PolyMatBuilder(val rank: x10.lang.Int) = x10.array.PolyMatBuilder{self.rank==rank}; */ 

//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyMatBuilder::_constructor(x10_int rank) {
    this->x10::array::MatBuilder::_constructor(((x10_int) ((rank) + (((x10_int)1)))));
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyMatBuilder>)this)->FMGL(rank) = rank;
    
}
x10aux::ref<x10::array::PolyMatBuilder> x10::array::PolyMatBuilder::_make(
  x10_int rank) {
    x10aux::ref<x10::array::PolyMatBuilder> this_ = new (memset(x10aux::alloc<x10::array::PolyMatBuilder>(), 0, sizeof(x10::array::PolyMatBuilder))) x10::array::PolyMatBuilder();
    this_->_constructor(rank);
    return this_;
}



//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyMat> x10::array::PolyMatBuilder::toSortedPolyMat(
  x10_boolean isSimplified) {
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::array::PolyMatBuilder>)this)->FMGL(mat))->sort(
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> > >(x10aux::ref<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> >(x10aux::ref<x10_array_PolyMatBuilder__closure__0>(new (x10aux::alloc<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> >(sizeof(x10_array_PolyMatBuilder__closure__0)))x10_array_PolyMatBuilder__closure__0()))));
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::PolyMat> result = x10::array::PolyMat::_make(x10aux::nullCheck(((x10aux::ref<x10::array::PolyMatBuilder>)this)->
                                                                                             FMGL(mat))->size(),
                                                                         ((x10_int) ((((x10aux::ref<x10::array::PolyMatBuilder>)this)->
                                                                                        FMGL(rank)) + (((x10_int)1)))),
                                                                         x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >(x10aux::ref<x10_array_PolyMatBuilder__closure__1>(new (x10aux::alloc<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >(sizeof(x10_array_PolyMatBuilder__closure__1)))x10_array_PolyMatBuilder__closure__1(this)))),
                                                                         isSimplified);
    
    //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::PolyMat> __desugarer__var__22__ =
          result;
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyMat> __var258__;
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Labeled_c
        goto __ret1946; __ret1946: 
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__22__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__22__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::PolyMatBuilder>)this))->
                                           FMGL(rank)))))
            {
                
                //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.PolyMat{self.rank==x10.array.PolyMatBuilder#this.rank}"))));
            }
            
            //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
            __var258__ =
              __desugarer__var__22__;
            
            //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Branch_c
            goto __ret1946_end_;
        }
        goto __ret1946_next_; __ret1946_next_: ;
        }
        while (false);
        goto __ret1946_end_; __ret1946_end_: ;
        __var258__;
    }))
    ;
    
}

//#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10FieldDecl_c
/**
     * a simple mechanism of somewhat dubious utility to allow
     * semi-symbolic specification of halfspaces. For example
     * X0-Y1 >= n is specified as add(X(0)-Y(1), GE, n)
     *
     * XXX coefficients must be -1,0,+1; can allow larger coefficients
     * by increasing # bits per coeff
     */x10_int
                                                                                                                                                                                                                                                                                                                      x10::array::PolyMatBuilder::FMGL(ZERO) =
  ((x10_int)178956970);


//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10FieldDecl_c
x10_int x10::array::PolyMatBuilder::FMGL(GE) =
  ((x10_int)0);


//#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10FieldDecl_c
x10_int x10::array::PolyMatBuilder::FMGL(LE) =
  ((x10_int)1);


//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyMatBuilder::X(x10_int axis) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
    return ((x10_int) ((((x10_int)1)) << (((x10_int) ((((x10_int)2)) * (axis))))));
    
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyMatBuilder::add(x10_int coeff,
                                     x10_int op,
                                     x10_int k) {
    
    //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
    coeff = ((x10_int) ((coeff) + (x10::array::PolyMatBuilder::
                                     FMGL(ZERO__get)())));
    
    //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::lang::Rail<x10_int > > as_ =
      x10::lang::Rail<void>::make<x10_int >(((x10_int) ((((x10aux::ref<x10::array::PolyMatBuilder>)this)->
                                                           FMGL(rank)) + (((x10_int)1)))));
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.For_c
    {
        x10_int i;
        for (
             //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10LocalDecl_c
             i = ((x10_int)0); ((i) < (((x10aux::ref<x10::array::PolyMatBuilder>)this)->
                                         FMGL(rank)));
             
             //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
             i =
               ((x10_int) ((i) + (((x10_int)1)))))
        {
            
            //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10LocalDecl_c
            x10_int a =
              ((x10_int) ((((x10_int) ((coeff) & (((x10_int)3))))) - (((x10_int)2))));
            
            //#line 73 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
            (as_)->set((x10aux::struct_equals(op,
                                              x10::array::PolyMatBuilder::
                                                FMGL(LE__get)()))
              ? (x10_int)(a)
              : (x10_int)(((x10_int) -(a))), i);
            
            //#line 74 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
            coeff =
              ((x10_int) ((coeff) >> (((x10_int)2))));
        }
    }
    
    //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
    (as_)->set((x10aux::struct_equals(op,
                                      x10::array::PolyMatBuilder::
                                        FMGL(LE__get)()))
      ? (x10_int)(((x10_int) -(k)))
      : (x10_int)(k), ((x10aux::ref<x10::array::PolyMatBuilder>)this)->
                        FMGL(rank));
    
    //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyMatBuilder>)this)->add(
      x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> >(x10aux::ref<x10_array_PolyMatBuilder__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10_int> >(sizeof(x10_array_PolyMatBuilder__closure__2)))x10_array_PolyMatBuilder__closure__2(as_)))));
}

//#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::PolyMatBuilder::rank(
  ) {
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyMatBuilder.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyMatBuilder>)this)->
             FMGL(rank);
    
}
void x10::array::PolyMatBuilder::add(x10aux::ref<x10::array::Row> p0) {
    x10::array::MatBuilder::add(p0);
}
void x10::array::PolyMatBuilder::add(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > p0) {
    x10::array::MatBuilder::add(p0);
}
const x10aux::serialization_id_t x10::array::PolyMatBuilder::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyMatBuilder::_deserializer<x10::lang::Object>);

void x10::array::PolyMatBuilder::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::array::MatBuilder::_serialize_body(buf);
    buf.write(this->FMGL(rank));
    
}

void x10::array::PolyMatBuilder::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::array::MatBuilder::_deserialize_body(buf);
    FMGL(rank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::PolyMatBuilder::rtt;
void x10::array::PolyMatBuilder::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::array::MatBuilder>()};
    rtt.initStageTwo("x10.array.PolyMatBuilder", 1, parents, 0, NULL, NULL);
}
x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int>::itable<x10_array_PolyMatBuilder__closure__0>x10_array_PolyMatBuilder__closure__0::_itable(&x10_array_PolyMatBuilder__closure__0::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMatBuilder__closure__0::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMatBuilder__closure__0::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_2<x10aux::ref<x10::array::Row>, x10aux::ref<x10::array::Row>, x10_int> >, &x10_array_PolyMatBuilder__closure__0::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMatBuilder__closure__0::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMatBuilder__closure__0::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_2<x10_int, x10_int, x10_int>::itable<x10_array_PolyMatBuilder__closure__1>x10_array_PolyMatBuilder__closure__1::_itable(&x10_array_PolyMatBuilder__closure__1::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMatBuilder__closure__1::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMatBuilder__closure__1::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> >, &x10_array_PolyMatBuilder__closure__1::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMatBuilder__closure__1::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMatBuilder__closure__1::_deserialize<x10::lang::Object>);

x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_PolyMatBuilder__closure__2>x10_array_PolyMatBuilder__closure__2::_itable(&x10_array_PolyMatBuilder__closure__2::apply, &x10::lang::Reference::at, &x10::lang::Reference::at, &x10::lang::Reference::equals, &x10::lang::Closure::hashCode, &x10::lang::Reference::home, &x10_array_PolyMatBuilder__closure__2::toString, &x10::lang::Closure::typeName);x10aux::itable_entry x10_array_PolyMatBuilder__closure__2::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >, &x10_array_PolyMatBuilder__closure__2::_itable),x10aux::itable_entry(NULL, NULL)};

const x10aux::serialization_id_t x10_array_PolyMatBuilder__closure__2::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10_array_PolyMatBuilder__closure__2::_deserialize<x10::lang::Object>);

