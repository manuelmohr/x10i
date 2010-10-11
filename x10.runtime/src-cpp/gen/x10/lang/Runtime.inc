#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__10 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__10> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1247 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(e) = x10::util::Box<x10aux::ref<x10::lang::Throwable> >::_make(e);
        
        //#line 1248 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(latch)->release();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RemoteControl> box;
    x10aux::ref<x10::lang::Throwable> e;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->box);
        buf.write(this->e);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RemoteControl> that_box = buf.read<x10aux::ref<x10::lang::Runtime__RemoteControl> >();
        x10aux::ref<x10::lang::Throwable> that_e = buf.read<x10aux::ref<x10::lang::Throwable> >();
        x10aux::ref<x10_lang_Runtime__closure__10> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__10>()) x10_lang_Runtime__closure__10(that_box, that_e);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__10(x10aux::ref<x10::lang::Runtime__RemoteControl> box, x10aux::ref<x10::lang::Throwable> e) : box(box), e(e) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1246-1249";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__9 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__9> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        box->FMGL(latch)->release();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__RemoteControl> box;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->box);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__RemoteControl> that_box = buf.read<x10aux::ref<x10::lang::Runtime__RemoteControl> >();
        x10aux::ref<x10_lang_Runtime__closure__9> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__9>()) x10_lang_Runtime__closure__9(that_box);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__9(x10aux::ref<x10::lang::Runtime__RemoteControl> box) : box(box) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1244";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__8 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__8> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1242 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Try_c
        try {
            
            //#line 1243 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(body))).operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(((x10aux::ref<x10::lang::Reference>)body)->_getITables())->apply))();
            
            //#line 1244 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((box)->location),
                                         x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__9>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__9)))x10_lang_Runtime__closure__9(box)))));
        }
        catch (x10aux::__ref& __ref__923) {
            x10aux::ref<x10::lang::Throwable>& __exc__ref__923 = (x10aux::ref<x10::lang::Throwable>&)__ref__923;
            if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__923)) {
                x10aux::ref<x10::lang::Throwable> e = static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__923);
                {
                    
                    //#line 1246 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::runAsync(x10::lang::Place_methods::place((box)->location),
                                                 x10aux::class_cast_unchecked<x10aux::ref<x10::lang::VoidFun_0_0> >(x10aux::ref<x10::lang::VoidFun_0_0>(x10aux::ref<x10_lang_Runtime__closure__10>(new (x10aux::alloc<x10::lang::VoidFun_0_0>(sizeof(x10_lang_Runtime__closure__10)))x10_lang_Runtime__closure__10(box, e)))));
                }
            } else
            throw;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    x10aux::ref<x10::lang::Runtime__RemoteControl> box;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
        buf.write(this->box);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10::lang::Runtime__RemoteControl> that_box = buf.read<x10aux::ref<x10::lang::Runtime__RemoteControl> >();
        x10aux::ref<x10_lang_Runtime__closure__8> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__8>()) x10_lang_Runtime__closure__8(that_body, that_box);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__8(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::Runtime__RemoteControl> box) : body(body), box(box) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1241-1251";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__7 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__7> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1220 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(x10::lang::Activity::_make(body, false));
            
            //#line 1220 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10_lang_Runtime__closure__7> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__7>()) x10_lang_Runtime__closure__7(that_body);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__7(x10aux::ref<x10::lang::VoidFun_0_0> body) : body(body) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1220";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__6 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__6> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(x10::lang::Activity::_make(body, true));
            
            //#line 1218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10_lang_Runtime__closure__6> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__6>()) x10_lang_Runtime__closure__6(that_body);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__6(x10aux::ref<x10::lang::VoidFun_0_0> body) : body(body) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1218";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__5 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__5> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1190 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(x10::lang::Activity::_make(body, state,
                                                                   false));
            
            //#line 1190 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    x10aux::ref<x10::lang::Runtime__FinishState> state;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
        buf.write(this->state);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10::lang::Runtime__FinishState> that_state = buf.read<x10aux::ref<x10::lang::Runtime__FinishState> >();
        x10aux::ref<x10_lang_Runtime__closure__5> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__5>()) x10_lang_Runtime__closure__5(that_body, that_state);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__5(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::Runtime__FinishState> state) : body(body), state(state) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1190";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1188 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(x10::lang::Activity::_make(body, state,
                                                                   true));
            
            //#line 1188 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    x10aux::ref<x10::lang::Runtime__FinishState> state;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
        buf.write(this->state);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10::lang::Runtime__FinishState> that_state = buf.read<x10aux::ref<x10::lang::Runtime__FinishState> >();
        x10aux::ref<x10_lang_Runtime__closure__4> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__4>()) x10_lang_Runtime__closure__4(that_body, that_state);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__4(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::Runtime__FinishState> state) : body(body), state(state) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1188";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1173 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::execute(x10::lang::Activity::_make(body, state,
                                                                   clocks,
                                                                   phases));
            
            //#line 1173 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    x10aux::ref<x10::lang::Runtime__FinishState> state;
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks;
    x10aux::ref<x10::lang::ValRail<x10_int > > phases;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->body);
        buf.write(this->state);
        buf.write(this->clocks);
        buf.write(this->phases);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10::lang::Runtime__FinishState> that_state = buf.read<x10aux::ref<x10::lang::Runtime__FinishState> >();
        x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > that_clocks = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_phases = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_lang_Runtime__closure__3> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__3>()) x10_lang_Runtime__closure__3(that_body, that_state, that_clocks, that_phases);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__3(x10aux::ref<x10::lang::VoidFun_0_0> body, x10aux::ref<x10::lang::Runtime__FinishState> state, x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks, x10aux::ref<x10::lang::ValRail<x10_int > > phases) : body(body), state(state), clocks(clocks), phases(phases) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1173";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1141 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(x10aux::nullCheck(x10::lang::Runtime::worker())->
                                FMGL(latch))->release();
            
            //#line 1141 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10_lang_Runtime__closure__2> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__2>()) x10_lang_Runtime__closure__2();
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__2() { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1141";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Try_c
        try {
        try {
            
            //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::startFinish();
            {
                
                //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(init))).operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(((x10aux::ref<x10::lang::Reference>)init)->_getITables())->apply))();
            }
        }
        catch (x10aux::__ref& __ref__913) {
            x10aux::ref<x10::lang::Throwable>& __exc__ref__913 = (x10aux::ref<x10::lang::Throwable>&)__ref__913;
            if (x10aux::instanceof<x10aux::ref<x10::lang::Throwable> >(__exc__ref__913)) {
                x10aux::ref<x10::lang::Throwable> __desugarer__var__67__ =
                  static_cast<x10aux::ref<x10::lang::Throwable> >(__exc__ref__913);
                {
                    
                    //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                    x10::lang::Runtime::pushException(
                      __desugarer__var__67__);
                }
            } else
            throw;
        }
        } catch (...) {
            {
                
                //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::stopFinish();
            }
            throw;
        }
        {
            
            //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::stopFinish();
        }
        
        //#line 1137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
        (((x10::lang::Reference*)(((x10aux::ref<x10::lang::Reference>)x10aux::placeCheck(x10aux::nullCheck(body))).operator->()))->*(x10aux::findITable<x10::lang::VoidFun_0_0>(((x10aux::ref<x10::lang::Reference>)body)->_getITables())->apply))();
    }
    
    // captured environment
    x10aux::ref<x10::lang::VoidFun_0_0> init;
    x10aux::ref<x10::lang::VoidFun_0_0> body;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->init);
        buf.write(this->body);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::VoidFun_0_0> that_init = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10::lang::VoidFun_0_0> that_body = buf.read<x10aux::ref<x10::lang::VoidFun_0_0> >();
        x10aux::ref<x10_lang_Runtime__closure__1> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__1>()) x10_lang_Runtime__closure__1(that_init, that_body);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__1(x10aux::ref<x10::lang::VoidFun_0_0> init, x10aux::ref<x10::lang::VoidFun_0_0> body) : init(init), body(body) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1137";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 1132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10::lang::PlaceLocalHandle_methods<x10aux::ref<x10::lang::Runtime> >::set(x10::lang::Runtime::
                                                                                         FMGL(runtime__get)(), 
              x10::lang::Runtime::_make(x10::lang::Runtime::pretendLocal<x10aux::ref<x10::lang::Runtime__Pool> >(
                                          pool)));
            
            //#line 1132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Pool> pool;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->pool);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Pool> that_pool = buf.read<x10aux::ref<x10::lang::Runtime__Pool> >();
        x10aux::ref<x10_lang_Runtime__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__closure__0>()) x10_lang_Runtime__closure__0(that_pool);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__closure__0(x10aux::ref<x10::lang::Runtime__Pool> pool) : pool(pool) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:1132";
    }

};

