#include <x10/array/RectRegion__RRIterator.h>


#include "x10/array/RectRegion__RRIterator.inc"


//#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.PropertyDecl_c
x10::lang::Iterator<x10aux::ref<x10::array::Point> >::itable<x10::array::RectRegion__RRIterator >  x10::array::RectRegion__RRIterator::_itable_0(&x10::array::RectRegion__RRIterator::at, &x10::array::RectRegion__RRIterator::at, &x10::array::RectRegion__RRIterator::equals, &x10::array::RectRegion__RRIterator::hasNext, &x10::array::RectRegion__RRIterator::hashCode, &x10::array::RectRegion__RRIterator::home, &x10::array::RectRegion__RRIterator::next, &x10::array::RectRegion__RRIterator::toString, &x10::array::RectRegion__RRIterator::typeName);
x10::lang::Any::itable<x10::array::RectRegion__RRIterator >  x10::array::RectRegion__RRIterator::_itable_1(&x10::array::RectRegion__RRIterator::at, &x10::array::RectRegion__RRIterator::at, &x10::array::RectRegion__RRIterator::equals, &x10::array::RectRegion__RRIterator::hashCode, &x10::array::RectRegion__RRIterator::home, &x10::array::RectRegion__RRIterator::toString, &x10::array::RectRegion__RRIterator::typeName);
x10aux::itable_entry x10::array::RectRegion__RRIterator::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::RectRegion__RRIterator>())};
void x10::array::RectRegion__RRIterator::_instance_init() {
    _I_("Doing initialisation for class: x10::array::RectRegion__RRIterator");
    
}


//#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 231 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10FieldDecl_c

//#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10ConstructorDecl_c
void x10::array::RectRegion__RRIterator::_constructor(x10aux::ref<x10::array::RectRegion> rr)
{
    this->x10::lang::Object::_constructor();
    
    //#line 232 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
      FMGL(done) =
      false;
    
    //#line 236 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
      FMGL(myRank) =
      x10aux::nullCheck(rr)->
        FMGL(rank);
    
    //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
      FMGL(min) =
      (__extension__ ({
        x10aux::ref<x10::lang::ValRail<x10_int > > __desugarer__var__29__ =
          x10aux::nullCheck(rr)->
            FMGL(mins);
        
        //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > __var382__;
        
        //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Labeled_c
        goto __ret1953; __ret1953: 
        //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__29__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__29__)->
                                           FMGL(length),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
                                           FMGL(myRank)))))
            {
                
                //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.ValRail[x10.lang.Int]{self.length==x10.array.RectRegion.RRIterator#this.myRank}"))));
            }
            
            //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            __var382__ =
              __desugarer__var__29__;
            
            //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Branch_c
            goto __ret1953_end_;
        }
        goto __ret1953_next_; __ret1953_next_: ;
        }
        while (false);
        goto __ret1953_end_; __ret1953_end_: ;
        __var382__;
    }))
    ;
    
    //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
      FMGL(max) =
      (__extension__ ({
        x10aux::ref<x10::lang::ValRail<x10_int > > __desugarer__var__30__ =
          x10aux::nullCheck(rr)->
            FMGL(maxs);
        
        //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_int > > __var383__;
        
        //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Labeled_c
        goto __ret1954; __ret1954: 
        //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__30__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__30__)->
                                           FMGL(length),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
                                           FMGL(myRank)))))
            {
                
                //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.ValRail[x10.lang.Int]{self.length==x10.array.RectRegion.RRIterator#this.myRank}"))));
            }
            
            //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            __var383__ =
              __desugarer__var__30__;
            
            //#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Branch_c
            goto __ret1954_end_;
        }
        goto __ret1954_next_; __ret1954_next_: ;
        }
        while (false);
        goto __ret1954_end_; __ret1954_end_: ;
        __var383__;
    }))
    ;
    
    //#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
      FMGL(done) =
      (x10aux::struct_equals(x10aux::nullCheck(rr)->
                               FMGL(size),
                             ((x10_int)0)));
    
    //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
      FMGL(cur) =
      (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > __desugarer__var__31__ =
          x10::lang::Rail<void>::make<x10_int >(x10aux::nullCheck(rr)->
                                                  FMGL(mins));
        
        //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::Rail<x10_int > > __var384__;
        
        //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Labeled_c
        goto __ret1955; __ret1955: 
        //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__31__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__31__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here))) &&
                  (x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__31__)->
                                           FMGL(length),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::RectRegion__RRIterator>)this))->
                                           FMGL(myRank)))))
            {
                
                //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Rail[x10.lang.Int]{self.home==here, self.length==x10.array.RectRegion.RRIterator#this.myRank}"))));
            }
            
            //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            __var384__ =
              __desugarer__var__31__;
            
            //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Branch_c
            goto __ret1955_end_;
        }
        goto __ret1955_next_; __ret1955_next_: ;
        }
        while (false);
        goto __ret1955_end_; __ret1955_end_: ;
        __var384__;
    }))
    ;
    
}
x10aux::ref<x10::array::RectRegion__RRIterator> x10::array::RectRegion__RRIterator::_make(
  x10aux::ref<x10::array::RectRegion> rr)
{
    x10aux::ref<x10::array::RectRegion__RRIterator> this_ = new (memset(x10aux::alloc<x10::array::RectRegion__RRIterator>(), 0, sizeof(x10::array::RectRegion__RRIterator))) x10::array::RectRegion__RRIterator();
    this_->_constructor(rr);
    return this_;
}



//#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::RectRegion__RRIterator::hasNext(
  ) {
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return (!(((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                FMGL(done)));
    
}

//#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::RectRegion__RRIterator::next(
  ) {
    
    //#line 246 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::array::Point> ans = x10::array::Point::make(
                                           ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                             FMGL(cur));
    
    //#line 247 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
             FMGL(cur))->apply(((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                              FMGL(myRank)) - (((x10_int)1)))))) < ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                                                       FMGL(max))->apply(((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                                                                                        FMGL(myRank)) - (((x10_int)1))))))))
    {
        
        //#line 248 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::lang::Rail<x10_int > > x =
              ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                FMGL(cur);
            x10_int y0 =
              ((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                             FMGL(myRank)) - (((x10_int)1))));
            x10_int z =
              ((x10_int)1);
            (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
        }))
        ;
    }
    else
    
    //#line 250 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                 FMGL(myRank),
                               ((x10_int)1))))
    {
        
        //#line 251 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
          FMGL(done) =
          true;
    }
    else
    {
        
        //#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        (((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
           FMGL(cur))->set((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                              FMGL(min))->apply(((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                               FMGL(myRank)) - (((x10_int)1))))), ((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                                                                                 FMGL(myRank)) - (((x10_int)1)))));
        
        //#line 255 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::lang::Rail<x10_int > > x =
              ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                FMGL(cur);
            x10_int y0 =
              ((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                             FMGL(myRank)) - (((x10_int)2))));
            x10_int z =
              ((x10_int)1);
            (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
        }))
        ;
        
        //#line 256 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10LocalDecl_c
        x10_int carryRank =
          ((x10_int) ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                         FMGL(myRank)) - (((x10_int)2))));
        
        //#line 257 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10While_c
        while (((carryRank) > (((x10_int)0))) &&
               (((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                    FMGL(cur))->apply(carryRank)) > ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                        FMGL(max))->apply(carryRank))))
        {
            
            //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
               FMGL(cur))->set((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                  FMGL(min))->apply(carryRank), carryRank);
            
            //#line 259 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_int > > x =
                  ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                    FMGL(cur);
                x10_int y0 =
                  ((x10_int) ((carryRank) - (((x10_int)1))));
                x10_int z =
                  ((x10_int)1);
                (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
            }))
            ;
            
            //#line 260 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            carryRank =
              ((x10_int) ((carryRank) - (((x10_int)1))));
        }
        
        //#line 262 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(carryRank,
                                   ((x10_int)0))) &&
            (((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                 FMGL(cur))->apply(((x10_int)0))) > ((((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
                                                        FMGL(max))->apply(((x10_int)0)))))
        {
            
            //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": polyglot.ast.Eval_c
            ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
              FMGL(done) =
              true;
        }
        
    }
    
    //#line 267 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ans;
    
}

//#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::RectRegion__RRIterator::myRank(
  ) {
    
    //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectRegion.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::RectRegion__RRIterator>)this)->
             FMGL(myRank);
    
}
const x10aux::serialization_id_t x10::array::RectRegion__RRIterator::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::RectRegion__RRIterator::_deserializer<x10::lang::Object>);

void x10::array::RectRegion__RRIterator::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(myRank));
    
}

void x10::array::RectRegion__RRIterator::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(myRank) = buf.read<x10_int>();
}

x10aux::RuntimeType x10::array::RectRegion__RRIterator::rtt;
void x10::array::RectRegion__RRIterator::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.RectRegion$RRIterator", 2, parents, 0, NULL, NULL);
}
