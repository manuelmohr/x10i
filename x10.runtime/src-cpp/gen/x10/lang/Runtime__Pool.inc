#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__Pool__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Pool__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1007 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            worker->x10::lang::Runtime__Worker::apply();
            
            //#line 1007 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Worker> worker;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->worker);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Worker> that_worker = buf.read<x10aux::ref<x10::lang::Runtime__Worker> >();
        x10aux::ref<x10_lang_Runtime__Pool__closure__1> this_ = new (x10aux::alloc<x10_lang_Runtime__Pool__closure__1>()) x10_lang_Runtime__Pool__closure__1(that_worker);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__Pool__closure__1(x10aux::ref<x10::lang::Runtime__Worker> worker) : worker(worker) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1007";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__Pool__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Pool__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 969 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::placeCheck(worker)->x10::lang::Runtime__Worker::apply();
            
            //#line 969 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Worker> worker;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->worker);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Worker> that_worker = buf.read<x10aux::ref<x10::lang::Runtime__Worker> >();
        x10aux::ref<x10_lang_Runtime__Pool__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__Pool__closure__0>()) x10_lang_Runtime__Pool__closure__0(that_worker);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__Pool__closure__0(x10aux::ref<x10::lang::Runtime__Worker> worker) : worker(worker) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:969";
    }

};

