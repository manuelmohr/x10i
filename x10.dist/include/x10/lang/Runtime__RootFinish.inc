#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__RootFinish__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__RootFinish__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 502 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::apply(x10::lang::Runtime::
                                                                                                             FMGL(runtime__get)()))->
              FMGL(finishStates)->remove(saved_this);
            
            //#line 502 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RootFinish> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RootFinish> that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__RootFinish> >();
        x10aux::ref<x10_lang_Runtime__RootFinish__closure__2> this_ = new (x10aux::alloc<x10_lang_Runtime__RootFinish__closure__2>()) x10_lang_Runtime__RootFinish__closure__2(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RootFinish__closure__2(x10aux::ref<x10::lang::Runtime__RootFinish> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:502";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__RootFinish__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_boolean>::itable<x10_lang_Runtime__RootFinish__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_boolean apply(x10_int id__38) {
        
        //#line 467 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Runtime__RootFinish__closure__1> this_ = new (x10aux::alloc<x10_lang_Runtime__RootFinish__closure__1>()) x10_lang_Runtime__RootFinish__closure__1();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RootFinish__closure__1() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_boolean> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:467";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__RootFinish__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__RootFinish__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int id__37) {
        
        //#line 466 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
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
        x10aux::ref<x10_lang_Runtime__RootFinish__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__RootFinish__closure__0>()) x10_lang_Runtime__RootFinish__closure__0();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__RootFinish__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:466";
    }

};

