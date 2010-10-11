#include <x10/array/PolyScanner__PointIt.h>


#include "x10/array/PolyScanner__PointIt.inc"

x10::lang::Iterator<x10aux::ref<x10::array::Point> >::itable<x10::array::PolyScanner__PointIt >  x10::array::PolyScanner__PointIt::_itable_0(&x10::array::PolyScanner__PointIt::at, &x10::array::PolyScanner__PointIt::at, &x10::array::PolyScanner__PointIt::equals, &x10::array::PolyScanner__PointIt::hasNext, &x10::array::PolyScanner__PointIt::hashCode, &x10::array::PolyScanner__PointIt::home, &x10::array::PolyScanner__PointIt::next, &x10::array::PolyScanner__PointIt::toString, &x10::array::PolyScanner__PointIt::typeName);
x10::lang::Any::itable<x10::array::PolyScanner__PointIt >  x10::array::PolyScanner__PointIt::_itable_1(&x10::array::PolyScanner__PointIt::at, &x10::array::PolyScanner__PointIt::at, &x10::array::PolyScanner__PointIt::equals, &x10::array::PolyScanner__PointIt::hashCode, &x10::array::PolyScanner__PointIt::home, &x10::array::PolyScanner__PointIt::toString, &x10::array::PolyScanner__PointIt::typeName);
x10aux::itable_entry x10::array::PolyScanner__PointIt::_itables[3] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >, &_itable_0), x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &_itable_1), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::array::PolyScanner__PointIt>())};
void x10::array::PolyScanner__PointIt::_instance_init() {
    _I_("Doing initialisation for class: x10::array::PolyScanner__PointIt");
    
}


//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 286 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10FieldDecl_c

//#line 288 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10ConstructorDecl_c
void x10::array::PolyScanner__PointIt::_constructor(x10aux::ref<x10::array::PolyScanner> out__)
{
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
      FMGL(out__) =
      out__;
    this->x10::lang::Object::_constructor();
    
    //#line 289 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::PolyScanner__PointIt>)this))->
      FMGL(it) =
      x10::array::PolyScanner__RailIt::_make(((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
                                               FMGL(out__));
    
}
x10aux::ref<x10::array::PolyScanner__PointIt> x10::array::PolyScanner__PointIt::_make(
  x10aux::ref<x10::array::PolyScanner> out__)
{
    x10aux::ref<x10::array::PolyScanner__PointIt> this_ = new (memset(x10aux::alloc<x10::array::PolyScanner__PointIt>(), 0, sizeof(x10::array::PolyScanner__PointIt))) x10::array::PolyScanner__PointIt();
    this_->_constructor(out__);
    return this_;
}



//#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::array::PolyScanner__PointIt::hasNext(
  ) {
    
    //#line 292 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
                               FMGL(it))->x10::array::PolyScanner__RailIt::hasNext();
    
}

//#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::array::Point> x10::array::PolyScanner__PointIt::next(
  ) {
    
    //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
    return (__extension__ ({
        x10aux::ref<x10::array::Point> __desugarer__var__28__ =
          x10::array::Point::__implicit_convert(
            x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
                                FMGL(it))->x10::array::PolyScanner__RailIt::next());
        
        //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Point> __var341__;
        
        //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Labeled_c
        goto __ret1952; __ret1952: 
        //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Do_c
        do
        {
        {
            
            //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10If_c
            if ((!x10aux::struct_equals(__desugarer__var__28__,
                                        x10aux::null)) &&
                !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__28__)->
                                           FMGL(rank),
                                         x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
                                                             FMGL(out__))->
                                           FMGL(rank)))))
            {
                
                //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Point{self.rank==x10.array.PolyScanner#this.rank}"))));
            }
            
            //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
            __var341__ =
              __desugarer__var__28__;
            
            //#line 293 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Branch_c
            goto __ret1952_end_;
        }
        goto __ret1952_next_; __ret1952_next_: ;
        }
        while (false);
        goto __ret1952_end_; __ret1952_end_: ;
        __var341__;
    }))
    ;
    
}

//#line 294 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10MethodDecl_c
void x10::array::PolyScanner__PointIt::remove(
  ) {
    {
        
        //#line 294 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((x10aux::ref<x10::array::PolyScanner__PointIt>)this)->
                            FMGL(it))->x10::array::PolyScanner__RailIt::remove();
        
        //#line 294 "/home/tux/workspace/x10.runtime/src-x10/x10/array/PolyScanner.x10": x10.ast.X10Return_c
        return;
    }
}
const x10aux::serialization_id_t x10::array::PolyScanner__PointIt::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::PolyScanner__PointIt::_deserializer<x10::lang::Object>);

void x10::array::PolyScanner__PointIt::_serialize(x10aux::ref<x10::array::PolyScanner__PointIt> this_,
                                                  x10aux::serialization_buffer& buf) {
    _serialize_reference(this_, buf);
    if (this_ != x10aux::null) {
        this_->_serialize_body(buf);
    }
}

void x10::array::PolyScanner__PointIt::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(out__));
    
}

void x10::array::PolyScanner__PointIt::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(out__) = buf.read<x10aux::ref<x10::array::PolyScanner> >();
}

x10aux::RuntimeType x10::array::PolyScanner__PointIt::rtt;
void x10::array::PolyScanner__PointIt::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Iterator<x10aux::ref<x10::array::Point> > >()};
    rtt.initStageTwo("x10.array.PolyScanner$PointIt", 2, parents, 0, NULL, NULL);
}
