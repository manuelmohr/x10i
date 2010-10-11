#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__5 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__5> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int i) {
        
        //#line 360 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return (regionMap)->apply(i);
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > regionMap;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->regionMap);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > that_regionMap = buf.read<x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > >();
        x10aux::ref<x10_array_BaseDist__closure__5> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__5>()) x10_array_BaseDist__closure__5(that_regionMap);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__5(x10aux::ref<x10::lang::Rail<x10aux::ref<x10::array::Region> > > regionMap) : regionMap(regionMap) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:360";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int id__18) {
        
        //#line 357 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return empty;
        
    }
    
    // captured environment
    x10aux::ref<x10::array::Region> empty;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->empty);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::Region> that_empty = buf.read<x10aux::ref<x10::array::Region> >();
        x10aux::ref<x10_array_BaseDist__closure__4> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__4>()) x10_array_BaseDist__closure__4(that_empty);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__4(x10aux::ref<x10::array::Region> empty) : empty(empty) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:357";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int id__17) {
        
        //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return saved_this->get(p);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::BaseDist> saved_this;
    x10::lang::Place p;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->p);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::BaseDist> that_saved_this = buf.read<x10aux::ref<x10::array::BaseDist> >();
        x10::lang::Place that_p = buf.read<x10::lang::Place>();
        x10aux::ref<x10_array_BaseDist__closure__3> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__3>()) x10_array_BaseDist__closure__3(that_saved_this, that_p);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__3(x10aux::ref<x10::array::BaseDist> saved_this, x10::lang::Place p) : saved_this(saved_this), p(p) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:183";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int i) {
        
        //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return x10aux::nullCheck((saved_this->FMGL(regions))->apply(i))->intersection(
                 r);
        
    }
    
    // captured environment
    x10aux::ref<x10::array::BaseDist> saved_this;
    x10aux::ref<x10::array::Region> r;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->r);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::array::BaseDist> that_saved_this = buf.read<x10aux::ref<x10::array::BaseDist> >();
        x10aux::ref<x10::array::Region> that_r = buf.read<x10aux::ref<x10::array::Region> >();
        x10aux::ref<x10_array_BaseDist__closure__2> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__2>()) x10_array_BaseDist__closure__2(that_saved_this, that_r);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__2(x10aux::ref<x10::array::BaseDist> saved_this, x10aux::ref<x10::array::Region> r) : saved_this(saved_this), r(r) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:175";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int i) {
        
        //#line 66 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> r1 = x10::array::Region::makeFull(
                                               axis);
        
        //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10_int low = ((x10_int) ((((x10_int) ((min) + (((x10_int) ((blockSize) * (i))))))) + (((i) < (leftOver))
          ? (x10_int)(i)
          : (x10_int)(leftOver))));
        
        //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10_int hi = ((x10_int) ((((x10_int) ((low) + (blockSize)))) + (((i) < (leftOver))
          ? (x10_int)(((x10_int)0))
          : (x10_int)(((x10_int)-1)))));
        
        //#line 69 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> r2 = x10::array::Region::makeRectangular(
                                               low,
                                               hi);
        
        //#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::array::Region> r3 = x10::array::Region::makeFull(
                                               ((x10_int) ((((x10_int) ((x10aux::nullCheck(r)->
                                                                           FMGL(rank)) - (axis)))) - (((x10_int)1)))));
        
        //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(((__extension__ ({
                                      x10aux::ref<x10::array::Region> __desugarer__var__1__ =
                                        x10aux::nullCheck(x10aux::nullCheck(r1)->product(
                                                            r2))->product(
                                          r3);
                                      
                                      //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10LocalDecl_c
                                      x10aux::ref<x10::array::Region> __var41__;
                                      
                                      //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Labeled_c
                                      goto __ret1926; __ret1926: 
                                      //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Do_c
                                      do
                                      {
                                      {
                                          
                                          //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10If_c
                                          if ((!x10aux::struct_equals(__desugarer__var__1__,
                                                                      x10aux::null)) &&
                                              !((x10aux::struct_equals(x10aux::nullCheck(__desugarer__var__1__)->
                                                                         FMGL(rank),
                                                                       x10aux::nullCheck(r)->
                                                                         FMGL(rank)))))
                                          {
                                              
                                              //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Throw_c
                                              x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.array.Region{self.rank==r.rank}"))));
                                          }
                                          
                                          //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Eval_c
                                          __var41__ =
                                            __desugarer__var__1__;
                                          
                                          //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": polyglot.ast.Branch_c
                                          goto __ret1926_end_;
                                      }
                                      goto __ret1926_next_; __ret1926_next_: ;
                                      }
                                      while (false);
                                      goto __ret1926_end_; __ret1926_end_: ;
                                      __var41__;
                                  }))
                                  ))->intersection(
                 r);
        
    }
    
    // captured environment
    x10_int axis;
    x10_int min;
    x10_int blockSize;
    x10_int leftOver;
    x10aux::ref<x10::array::Region> r;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->axis);
        buf.write(this->min);
        buf.write(this->blockSize);
        buf.write(this->leftOver);
        buf.write(this->r);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_axis = buf.read<x10_int>();
        x10_int that_min = buf.read<x10_int>();
        x10_int that_blockSize = buf.read<x10_int>();
        x10_int that_leftOver = buf.read<x10_int>();
        x10aux::ref<x10::array::Region> that_r = buf.read<x10aux::ref<x10::array::Region> >();
        x10aux::ref<x10_array_BaseDist__closure__1> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__1>()) x10_array_BaseDist__closure__1(that_axis, that_min, that_blockSize, that_leftOver, that_r);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__1(x10_int axis, x10_int min, x10_int blockSize, x10_int leftOver, x10aux::ref<x10::array::Region> r) : axis(axis), min(min), blockSize(blockSize), leftOver(leftOver), r(r) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:65-72";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_BaseDist__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> >::itable<x10_array_BaseDist__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::array::Region> apply(x10_int i) {
        
        //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10": x10.ast.X10Return_c
        return x10::array::Region::makeRectangular(i, i);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_array_BaseDist__closure__0> this_ = new (x10aux::alloc<x10_array_BaseDist__closure__0>()) x10_array_BaseDist__closure__0();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_BaseDist__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::Region> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/BaseDist.x10:47";
    }

};

