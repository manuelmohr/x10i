#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Place__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10::lang::Place>::itable<x10_lang_Place__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::lang::Place apply(x10_int i) {
        
        //#line 86 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::_make(x10aux::child(p,i));
        
    }
    
    // captured environment
    x10_int p;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->p);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_p = buf.read<x10_int>();
        x10aux::ref<x10_lang_Place__closure__2> this_ = new (x10aux::alloc<x10_lang_Place__closure__2>()) x10_lang_Place__closure__2(that_p);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Place__closure__2(x10_int p) : p(p) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10:86";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Place__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > >::itable<x10_lang_Place__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10aux::ref<x10::lang::ValRail<x10::lang::Place > > apply(x10_int p) {
        
        //#line 85 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::ValRail<x10::lang::Place >::make(x10aux::num_children(p), x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::lang::Place> > >(x10aux::ref<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(x10aux::ref<x10_lang_Place__closure__2>(new (x10aux::alloc<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(sizeof(x10_lang_Place__closure__2)))x10_lang_Place__closure__2(p)))));
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Place__closure__1> this_ = new (x10aux::alloc<x10_lang_Place__closure__1>()) x10_lang_Place__closure__1();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Place__closure__1() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::lang::ValRail<x10::lang::Place > > > >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10:85-86";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Place__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10::lang::Place>::itable<x10_lang_Place__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10::lang::Place apply(x10_int id) {
        
        //#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10": x10.ast.X10Return_c
        return x10::lang::Place_methods::_make(id);
        
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Place__closure__0> this_ = new (x10aux::alloc<x10_lang_Place__closure__0>()) x10_lang_Place__closure__0();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Place__closure__0() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10::lang::Place> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Place.x10:82";
    }

};

