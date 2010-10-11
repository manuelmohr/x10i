#include <x10/array/MatBuilder.h>


#include "x10/array/MatBuilder.inc"

void x10::array::MatBuilder::_instance_init() {
    _I_("Doing initialisation for class: x10::array::MatBuilder");
    
}


//#line 18 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10FieldDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10FieldDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10ConstructorDecl_c
void x10::array::MatBuilder::_constructor(x10_int cols) {
    this->x10::lang::Object::_constructor();
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::MatBuilder>)this))->FMGL(cols) =
      cols;
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::MatBuilder>)this))->
      FMGL(mat) = x10::util::ArrayList<x10aux::ref<x10::array::Row> >::_make();
    
}
x10aux::ref<x10::array::MatBuilder> x10::array::MatBuilder::_make(
  x10_int cols) {
    x10aux::ref<x10::array::MatBuilder> this_ = new (memset(x10aux::alloc<x10::array::MatBuilder>(), 0, sizeof(x10::array::MatBuilder))) x10::array::MatBuilder();
    this_->_constructor(cols);
    return this_;
}



//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10ConstructorDecl_c
void x10::array::MatBuilder::_constructor(x10_int rows, x10_int cols)
{
    this->x10::lang::Object::_constructor();
    
    //#line 27 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::MatBuilder>)this))->
      FMGL(cols) =
      cols;
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10LocalDecl_c
    x10aux::ref<x10::util::ArrayList<x10aux::ref<x10::array::Row> > > m =
      x10::util::ArrayList<x10aux::ref<x10::array::Row> >::_make(rows);
    
    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::array::MatBuilder>)this))->
      FMGL(mat) =
      m;
    
    //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10::array::MatBuilder::need(
      rows,
      m,
      cols);
    
}
x10aux::ref<x10::array::MatBuilder> x10::array::MatBuilder::_make(
  x10_int rows,
  x10_int cols)
{
    x10aux::ref<x10::array::MatBuilder> this_ = new (memset(x10aux::alloc<x10::array::MatBuilder>(), 0, sizeof(x10::array::MatBuilder))) x10::array::MatBuilder();
    this_->_constructor(rows,
    cols);
    return this_;
}



//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::add(x10aux::ref<x10::array::Row> row) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                        FMGL(mat))->add(row);
}

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::add(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > a) {
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                        FMGL(mat))->add(x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(x10::array::VarRow::_make(((x10aux::ref<x10::array::MatBuilder>)this)->
                                                                                                                                FMGL(cols),
                                                                                                                              a)));
}

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
x10_int x10::array::MatBuilder::apply(x10_int i, x10_int j) {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10Return_c
    return x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                                                 FMGL(mat))->apply(
                               i))->apply(
             j);
    
}

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::set(x10_int v,
                                 x10_int i,
                                 x10_int j) {
    
    //#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::MatBuilder>)this)->need(
      ((x10_int) ((i) + (((x10_int)1)))));
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                                          FMGL(mat))->apply(
                        i))->set(v, j);
}

//#line 48 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::setDiagonal(
  x10_int i,
  x10_int j,
  x10_int n,
  x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > v) {
    
    //#line 49 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::MatBuilder>)this)->need(
      ((x10_int) ((i) + (n))));
    
    //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (n));
             
             //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                                                  FMGL(mat))->apply(
                                ((x10_int) ((i) + (k)))))->set(
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(v))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<x10_int, x10_int> >(((x10aux::ref<x10::lang::Reference>)v)->_getITables())->apply))(
                k),
              ((x10_int) ((j) + (k))));
        }
    }
    
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::setColumn(x10_int i,
                                       x10_int j,
                                       x10_int n,
                                       x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > v) {
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::MatBuilder>)this)->need(
      ((x10_int) ((i) + (n))));
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (n));
             
             //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                                                  FMGL(mat))->apply(
                                ((x10_int) ((i) + (k)))))->set(
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(v))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<x10_int, x10_int> >(((x10aux::ref<x10::lang::Reference>)v)->_getITables())->apply))(
                k),
              j);
        }
    }
    
}

//#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::setRow(x10_int i,
                                    x10_int j,
                                    x10_int n,
                                    x10aux::ref<x10::lang::Fun_0_1<x10_int, x10_int> > v) {
    
    //#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::MatBuilder>)this)->need(
      ((x10_int) ((i) + (((x10_int)1)))));
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.For_c
    {
        x10_int k;
        for (
             //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10LocalDecl_c
             k = ((x10_int)0); ((k) < (n));
             
             //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
             k =
               ((x10_int) ((k) + (((x10_int)1)))))
        {
            
            //#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(x10aux::nullCheck(((x10aux::ref<x10::array::MatBuilder>)this)->
                                                  FMGL(mat))->apply(
                                i))->set(
              (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(v))).operator->()))->*(x10aux::findITable<x10::lang::Fun_0_1<x10_int, x10_int> >(((x10aux::ref<x10::lang::Reference>)v)->_getITables())->apply))(
                k),
              ((x10_int) ((j) + (k))));
        }
    }
    
}

//#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::need(x10_int n) {
    {
        
        //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
        x10::array::MatBuilder::need(n, ((x10aux::ref<x10::array::MatBuilder>)this)->
                                          FMGL(mat),
                                     ((x10aux::ref<x10::array::MatBuilder>)this)->
                                       FMGL(cols));
        
        //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10MethodDecl_c
void x10::array::MatBuilder::need(x10_int n,
                                  x10aux::ref<x10::util::ArrayList<x10aux::ref<x10::array::Row> > > mat,
                                  x10_int cols) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": x10.ast.X10While_c
    while (((x10aux::nullCheck(mat)->size()) < (n)))
    {
        
        //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/MatBuilder.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(mat)->add(
          x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >(x10::array::VarRow::_make(cols)));
    }
    
}
const x10aux::serialization_id_t x10::array::MatBuilder::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::array::MatBuilder::_deserializer<x10::lang::Object>);

void x10::array::MatBuilder::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::array::MatBuilder::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::array::MatBuilder::rtt;
void x10::array::MatBuilder::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.array.MatBuilder", 1, parents, 0, NULL, NULL);
}
