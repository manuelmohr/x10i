#ifndef __X10_ARRAY_MAT_H
#define __X10_ARRAY_MAT_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_FUN_0_1_H_NODEPS
#include <x10/lang/Fun_0_1.h>
#undef X10_LANG_FUN_0_1_H_NODEPS
#define X10_LANG_ITERABLE_H_NODEPS
#include <x10/lang/Iterable.h>
#undef X10_LANG_ITERABLE_H_NODEPS
#define X10_LANG_INT_STRUCT_H_NODEPS
#include <x10/lang/Int.struct_h>
#undef X10_LANG_INT_STRUCT_H_NODEPS
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace array { 
class Row;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace io { 
class Printer;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace array { 

template<class FMGL(T)> class Mat;
template <> class Mat<void>;
template<class FMGL(T)> class Mat : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    x10_int FMGL(rows);
    
    x10_int FMGL(cols);
    
    void _instance_init();
    
    x10aux::ref<x10::lang::ValRail<FMGL(T) > > FMGL(mat);
    
    void _constructor(x10_int rows, x10_int cols, x10aux::ref<x10::lang::ValRail<FMGL(T) > > mat);
    
    virtual FMGL(T) apply(x10_int i);
    virtual x10aux::ref<x10::lang::Iterator<FMGL(T)> > iterator();
    virtual void printInfo(x10aux::ref<x10::io::Printer> ps, x10aux::ref<x10::lang::String> label);
    x10_int rows();
    x10_int cols();
    
    // Serialization
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};
template <> class Mat<void> : public x10::lang::Object {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    
};

} } 
#endif // X10_ARRAY_MAT_H

namespace x10 { namespace array { 
template<class FMGL(T)> class Mat;
} } 

#ifndef X10_ARRAY_MAT_H_NODEPS
#define X10_ARRAY_MAT_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Iterable.h>
#include <x10/lang/Int.h>
#include <x10/array/Row.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Iterator.h>
#include <x10/io/Printer.h>
#include <x10/lang/String.h>
#ifndef X10_ARRAY_MAT_H_GENERICS
#define X10_ARRAY_MAT_H_GENERICS
#endif // X10_ARRAY_MAT_H_GENERICS
#ifndef X10_ARRAY_MAT_H_IMPLEMENTATION
#define X10_ARRAY_MAT_H_IMPLEMENTATION
#include <x10/array/Mat.h>


#include "x10/array/Mat.inc"


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.PropertyDecl_c

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.PropertyDecl_c
template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::array::Mat<FMGL(T)>");
    
}


//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10FieldDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10ConstructorDecl_c
template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::_constructor(x10_int rows,
                                                                    x10_int cols,
                                                                    x10aux::ref<x10::lang::ValRail<FMGL(T) > > mat)
{
    this->x10::lang::Object::_constructor();
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
      FMGL(rows) =
      rows;
    
    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
      FMGL(cols) =
      cols;
    
    //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
      FMGL(mat) =
      mat;
    
}


//#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> FMGL(T) x10::array::Mat<FMGL(T)>::apply(
  x10_int i) {
    
    //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
              FMGL(mat))->apply(i);
    
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10aux::ref<x10::lang::Iterator<FMGL(T)> >
  x10::array::Mat<FMGL(T)>::iterator(
  ) {
    
    //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
              FMGL(mat))->iterator();
    
}

//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::printInfo(
  x10aux::ref<x10::io::Printer> ps,
  x10aux::ref<x10::lang::String> label) {
    
    //#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
    x10aux::nullCheck(ps)->printf(x10::lang::String::Lit("%s\n"),
                                  x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(label));
    
    //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10LocalDecl_c
    x10_int row = ((x10_int)0);
    
    //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.For_c
    {
        x10aux::ref<x10::lang::Iterator<FMGL(T)> > r1554;
        for (
             //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10LocalDecl_c
             r1554 = ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->iterator();
             (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1554))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)r1554)->_getITables())->hasNext))();
             ) {
            
            //#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10LocalDecl_c
            x10aux::ref<x10::array::Row> r =
              x10aux::class_cast_unchecked<x10aux::ref<x10::array::Row> >((((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(r1554))).operator->()))->*(x10aux::findITable<x10::lang::Iterator<FMGL(T)> >(((x10aux::ref<x10::lang::Reference>)r1554)->_getITables())->next))());
            
            //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(ps)->printf(
              x10::lang::String::Lit("    "));
            
            //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(r)->printInfo(
              ps,
              ((x10_int) ((row =
                ((x10_int) ((row) + (((x10_int)1))))) - (((x10_int)1)))));
        }
    }
    
}

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::array::Mat<FMGL(T)>::rows(
  ) {
    
    //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
             FMGL(rows);
    
}

//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10MethodDecl_c
template<class FMGL(T)> x10_int x10::array::Mat<FMGL(T)>::cols(
  ) {
    
    //#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/array/Mat.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::array::Mat<FMGL(T)> >)this)->
             FMGL(cols);
    
}
template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    buf.write(this->FMGL(mat));
    buf.write(this->FMGL(rows));
    buf.write(this->FMGL(cols));
    
}

template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    FMGL(mat) = buf.read<x10aux::ref<x10::lang::ValRail<FMGL(T) > > >();
    FMGL(rows) = buf.read<x10_int>();
    FMGL(cols) = buf.read<x10_int>();
}

template<class FMGL(T)> x10aux::RuntimeType x10::array::Mat<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::array::Mat<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::array::Mat<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[3] = { x10aux::getRTT<x10::lang::Object>(), x10aux::getRTT<x10::lang::Fun_0_1<x10_int, FMGL(T)> >(), x10aux::getRTT<x10::lang::Iterable<FMGL(T)> >()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::covariant};
    const char *baseName = "x10.array.Mat";
    rtt.initStageTwo(baseName, 3, parents, 1, params, variances);
}
#endif // X10_ARRAY_MAT_H_IMPLEMENTATION
#endif // __X10_ARRAY_MAT_H_NODEPS
