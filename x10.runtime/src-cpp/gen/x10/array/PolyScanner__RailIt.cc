#include <x10/array/PolyScanner__RailIt.h>


#include "x10/array/PolyScanner__RailIt.inc"

x10::lang::Iterator<x10aux::ref<x10::lang::Rail<x10_int > > >::itable<x10::array::PolyScanner__RailIt >  x10::array::PolyScanner__RailIt::_itable_0(&x10::array::PolyScanner__RailIt::at, &x10::array::PolyScanner__RailIt::at, &x10::array::PolyScanner__RailIt::equals, &x10::array::PolyScanner__RailIt::hasNext, &x10::array::PolyScanner__RailIt::hashCode, &x10::array::PolyScanner__RailIt::home, &x10::array::PolyScanner__RailIt::next, &x10::array::PolyScanner__RailIt::toString, &x10::array::PolyScanner__RailIt::typeName);
x10::lang::Any::itable<x10::array::PolyScanner__RailIt >  x10::array::PolyScanner__RailIt::_itable_1(&x10::array::PolyScanner__RailIt::at, &x10::array::PolyScanner__RailIt::at, &x10::array::PolyScanner__RailIt::equals, &x10::array::PolyScanner__RailIt::hashCode, &x10::array::PolyScanner__RailIt::home, &x10::array::PolyScanner__RailIt::toString, &x10::array::PolyScanner__RailIt::typeName);
x10aux::itable_entry x10::array::PolyScanner__RailIt::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::lang::Rail<x10_int > > > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyScanner__RailIt>())};
void x10::array::PolyScanner__RailIt::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyScanner__RailIt");
    
}


//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::PolyScanner> x10::array::PolyScanner__RailIt::outerThis(
  ) {
    
    //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::PolyScanner> __desugarer__var__27__ = ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                                        FMGL(out__);
        
        //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::PolyScanner> __var334__;
        
        //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Labeled_c
        goto __ret1951; __ret1951: 
        //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Do_c
        do {
        {
            
            //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__27__, x10aux::null)) &&
                !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__27__)->location),
                                         x10::lang::Place_methods::_make(x10aux::here)))))
            {
                
                //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.PolyScanner{self.home==here}"))));
            }
            
            //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            __var334__ = __desugarer__var__27__;
            
            //#line 229 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Branch_c
            goto __ret1951_end_;
        }
        goto __ret1951_next_; __ret1951_next_: ;
        } while (false);
        goto __ret1951_end_; __ret1951_end_: ;
        __var334__;
    }))
    ;
    
}

//#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 231 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 238 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyScanner__RailIt::_constructor(
  x10aux::ref<x10::array::PolyScanner> out__)
{
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
      FMGL(out__) =
      out__;
    this->x10::lang::Object::_constructor();
    
    //#line 230 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(rank) =
      x10aux::nullCheck(x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->x10::array::PolyScanner__RailIt::outerThis())->
        FMGL(rank);
    
    //#line 231 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(s) =
      x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->x10::array::PolyScanner__RailIt::outerThis();
    
    //#line 233 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(x) =
      x10::lang::Rail<void>::make<x10_int >(x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
                                              FMGL(rank));
    
    //#line 234 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(myMin) =
      x10::lang::Rail<void>::make<x10_int >(x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
                                              FMGL(rank));
    
    //#line 235 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(myMax) =
      x10::lang::Rail<void>::make<x10_int >(x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
                                              FMGL(rank));
    
    //#line 237 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this))->
      FMGL(k) =
      ((x10_int)0);
    
}
x10aux::ref<x10::array::PolyScanner__RailIt> x10::array::PolyScanner__RailIt::_make(
  x10aux::ref<x10::array::PolyScanner> out__)
{
    x10aux::ref<x10::array::PolyScanner__RailIt> this_ = new (memset(x10aux::alloc<x10::array::PolyScanner__RailIt>(), 0, sizeof(x10::array::PolyScanner__RailIt))) x10::array::PolyScanner__RailIt();
    this_->_constructor(out__);
    return this_;
}



//#line 239 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner__RailIt::init(
  ) {
    
    //#line 240 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
       FMGL(myMin))->set(x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                             FMGL(s))->x10::array::PolyScanner::min(
                           ((x10_int)0)), ((x10_int)0));
    
    //#line 241 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
       FMGL(myMax))->set(x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                             FMGL(s))->x10::array::PolyScanner::max(
                           ((x10_int)0)), ((x10_int)0));
    
    //#line 242 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
       FMGL(x))->set(x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                         FMGL(s))->x10::array::PolyScanner::min(
                       ((x10_int)0)), ((x10_int)0));
    
    //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        for (
             //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(k) = ((x10_int)1); ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                           FMGL(k)) < (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                         FMGL(rank)));
             
             //#line 243 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             (__extension__ ({
                 x10aux::ref<x10::array::PolyScanner__RailIt> x =
                   ((x10aux::ref<x10::array::PolyScanner__RailIt>)this);
                 x10_int y =
                   ((x10_int)1);
                 x10aux::nullCheck(x)->
                   FMGL(k) =
                   ((x10_int) ((x10aux::nullCheck(x)->
                                  FMGL(k)) + (y)));
             }))
             ) {
            
            //#line 244 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                FMGL(s))->x10::array::PolyScanner::set(
              ((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                             FMGL(k)) - (((x10_int)1)))),
              (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                 FMGL(x))->apply(((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                FMGL(k)) - (((x10_int)1))))));
            
            //#line 245 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int m = x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                            FMGL(s))->x10::array::PolyScanner::min(
                          ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                            FMGL(k));
            
            //#line 246 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(x))->set(m, ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                  FMGL(k));
            
            //#line 247 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(myMin))->set(m, ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                      FMGL(k));
            
            //#line 248 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(myMax))->set(x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                     FMGL(s))->x10::array::PolyScanner::max(
                                   ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                     FMGL(k)), ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                 FMGL(k));
        }
    }
    
    //#line 250 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x =
          ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
            FMGL(x);
        x10_int y0 =
          ((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                         FMGL(rank)) - (((x10_int)1))));
        x10_int z =
          ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) - (z))), y0);
    }))
    ;
}

//#line 253 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyScanner__RailIt::hasNext(
  ) {
    
    //#line 254 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
      FMGL(k) = ((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                               FMGL(rank)) - (((x10_int)1))));
    
    //#line 255 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10While_c
    while ((((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                FMGL(x))->apply(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                  FMGL(k))) >= ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                   FMGL(myMax))->apply(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                                         FMGL(k)))))
    {
        
        //#line 256 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
        if ((((__extension__ ({
                x10aux::ref<x10::array::PolyScanner__RailIt> x =
                  ((x10aux::ref<x10::array::PolyScanner__RailIt>)this);
                x10_int y =
                  ((x10_int)1);
                x10aux::nullCheck(x)->
                  FMGL(k) =
                  ((x10_int) ((x10aux::nullCheck(x)->
                                 FMGL(k)) - (y)));
            }))
            ) < (((x10_int)0))))
        {
            
            //#line 257 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
            return false;
            
        }
        
    }
    
    //#line 258 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return true;
    
}

//#line 261 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::Rail<x10_int > > x10::array::PolyScanner__RailIt::next(
  ) {
    
    //#line 262 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    (__extension__ ({
        x10aux::ref<x10::lang::Rail<x10_int > > x =
          ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
            FMGL(x);
        x10_int y0 =
          ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
            FMGL(k);
        x10_int z =
          ((x10_int)1);
        (x)->set(((x10_int) (((x)->apply(y0)) + (z))), y0);
    }))
    ;
    
    //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.For_c
    {
        for (
             //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(k) = ((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                        FMGL(k)) + (((x10_int)1))));
             ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                 FMGL(k)) < (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                               FMGL(rank)));
             
             //#line 263 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
             (__extension__ ({
                 x10aux::ref<x10::array::PolyScanner__RailIt> x =
                   ((x10aux::ref<x10::array::PolyScanner__RailIt>)this);
                 x10_int y =
                   ((x10_int)1);
                 x10aux::nullCheck(x)->
                   FMGL(k) =
                   ((x10_int) ((x10aux::nullCheck(x)->
                                  FMGL(k)) + (y)));
             }))
             ) {
            
            //#line 264 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                FMGL(s))->x10::array::PolyScanner::set(
              ((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                             FMGL(k)) - (((x10_int)1)))),
              (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                 FMGL(x))->apply(((x10_int) ((((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                FMGL(k)) - (((x10_int)1))))));
            
            //#line 265 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
            x10_int m = x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                            FMGL(s))->x10::array::PolyScanner::min(
                          ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                            FMGL(k));
            
            //#line 266 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(x))->set(m, ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                  FMGL(k));
            
            //#line 267 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(myMin))->set(m, ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                      FMGL(k));
            
            //#line 268 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            (((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
               FMGL(myMax))->set(x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                     FMGL(s))->x10::array::PolyScanner::max(
                                   ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                     FMGL(k)), ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
                                                 FMGL(k));
        }
    }
    
    //#line 270 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::PolyScanner__RailIt>)this)->
             FMGL(x);
    
}

//#line 273 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner__RailIt::remove(
  ) {
 
}
const x10aux::serialization_id_t x10::array::PolyScanner__RailIt::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyScanner__RailIt::_deserializer<x10::lang::Object>);

void x10::array::PolyScanner__RailIt::_serialize(x10aux::ref<x10::array::PolyScanner__RailIt> this_,
                                                 x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::PolyScanner__RailIt::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(out__));
    
}

void x10::array::PolyScanner__RailIt::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(out__) = buf.read<x10aux::ref<x10::array::PolyScanner> >();
}

x10aux::RuntimeType x10::array::PolyScanner__RailIt::rtt;
void x10::array::PolyScanner__RailIt::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::lang::Rail<x10_int > > > >()};
    rtt.initStageTwo("x10.array.PolyScanner$RailIt", 2, parents, 0, NULL, NULL);
}
