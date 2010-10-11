#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__RemoteFinish__closure__6 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RemoteFinish__closure__6> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int id__40) {
        
        //#line 690 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::_make(x10aux::here)->FMGL(id);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__6> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__6>()) x10_lang_Runtime__RemoteFinish__closure__6();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__6() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:690";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__RemoteFinish__closure__5 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RemoteFinish__closure__5> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int id__39) {
        
        //#line 688 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return ((x10_int)0);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__5> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__5>()) x10_lang_Runtime__RemoteFinish__closure__5();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__5() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:688";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__RemoteFinish__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__63__ =
                                 r;
                               
                               //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var1012__;
                               
                               //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1997; __ret1997: 
                               //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__63__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__63__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1012__ =
                                     __desugarer__var__63__;
                                   
                                   //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1997_end_;
                               }
                               goto __ret1997_next_; __ret1997_next_: ;
                               }
                               while (false);
                               goto __ret1997_end_; __ret1997_end_: ;
                               __var1012__;
                           }))
                           ))->notify2(m);
        
        //#line 760 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > >();
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__4> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__4>()) x10_lang_Runtime__RemoteFinish__closure__4(that_r, that_m);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__4(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m) : r(r), m(m) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:760";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__RemoteFinish__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__62__ =
                                 r;
                               
                               //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var1011__;
                               
                               //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1996; __ret1996: 
                               //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__62__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__62__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1011__ =
                                     __desugarer__var__62__;
                                   
                                   //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1996_end_;
                               }
                               goto __ret1996_next_; __ret1996_next_: ;
                               }
                               while (false);
                               goto __ret1996_end_; __ret1996_end_: ;
                               __var1011__;
                           }))
                           ))->notify2(m,
                                       t);
        
        //#line 756 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m;
    x10aux::ref<x10::lang::Throwable> t;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->t);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > >();
        x10aux::ref<x10::lang::Throwable> that_t = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__3> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__3>()) x10_lang_Runtime__RemoteFinish__closure__3(that_r, that_m, that_t);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__3(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10::util::Pair<x10_int, x10_int> > > m, x10aux::ref<x10::lang::Throwable> t) : r(r), m(m), t(t) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:756";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__RemoteFinish__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> >::itable<x10_lang_Runtime__RemoteFinish__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::util::Pair<x10_int, x10_int> apply(x10_int i) {
        
        //#line 745 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10::util::Pair_methods<x10_int, x10_int>::_make((saved_this->
                                                                   FMGL(message))->apply(i),
                                                                (saved_this->
                                                                   FMGL(counts))->apply((saved_this->
                                                                                           FMGL(message))->apply(i)));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RemoteFinish> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RemoteFinish> that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__RemoteFinish> >();
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__2> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__2>()) x10_lang_Runtime__RemoteFinish__closure__2(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__2(x10aux::ref<x10::lang::Runtime__RemoteFinish> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::util::Pair<x10_int, x10_int> > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:745";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__RemoteFinish__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__61__ =
                                 r;
                               
                               //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var1010__;
                               
                               //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1995; __ret1995: 
                               //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__61__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__61__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1010__ =
                                     __desugarer__var__61__;
                                   
                                   //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1995_end_;
                               }
                               goto __ret1995_next_; __ret1995_next_: ;
                               }
                               while (false);
                               goto __ret1995_end_; __ret1995_end_: ;
                               __var1010__;
                           }))
                           ))->notify(m);
        
        //#line 739 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10_int > > m;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__1> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__1>()) x10_lang_Runtime__RemoteFinish__closure__1(that_r, that_m);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__1(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10_int > > m) : r(r), m(m) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:739";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__RemoteFinish__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RemoteFinish__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10aux::nullCheck(((__extension__ ({
                               x10aux::ref<x10::lang::Runtime__RootFinish> __desugarer__var__60__ =
                                 r;
                               
                               //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                               x10aux::ref<x10::lang::Runtime__RootFinish> __var1009__;
                               
                               //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                               goto __ret1994; __ret1994: 
                               //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                               do
                               {
                               {
                                   
                                   //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                   if ((!x10aux::struct_equals(__desugarer__var__60__,
                                                               x10aux::null)) &&
                                       !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__60__)->location),
                                                                x10::lang::Place_methods::_make(x10aux::here)))))
                                   {
                                       
                                       //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                       x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Runtime.RootFinish{self.home==here}"))));
                                   }
                                   
                                   //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                   __var1009__ =
                                     __desugarer__var__60__;
                                   
                                   //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                   goto __ret1994_end_;
                               }
                               goto __ret1994_next_; __ret1994_next_: ;
                               }
                               while (false);
                               goto __ret1994_end_; __ret1994_end_: ;
                               __var1009__;
                           }))
                           ))->notify(m, t);
        
        //#line 735 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        x10::lang::Object::dealloc_object((x10::lang::Object*)x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Object> >(m).operator->());
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> r;
    x10aux::ref<x10::lang::ValRail<x10_int > > m;
    x10aux::ref<x10::lang::Throwable> t;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->m);
        buf.write(this->t);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_r = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_m = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10::lang::Throwable> that_t = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__RemoteFinish__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__RemoteFinish__closure__0>()) x10_lang_Runtime__RemoteFinish__closure__0(that_r, that_m, that_t);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RemoteFinish__closure__0(x10aux::ref<x10::lang::Runtime__RootFinish> r, x10aux::ref<x10::lang::ValRail<x10_int > > m, x10aux::ref<x10::lang::Throwable> t) : r(r), m(m), t(t) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:735";
    }

};

