#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Clock__closure__4 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__4> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this)->dropLocal(ph);
    }
    
    // captured environment
    x10aux::ref<x10::lang::Clock> saved_this;
    x10_int ph;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->ph);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Clock> that_saved_this = buf.read<x10aux::ref<x10::lang::Clock> >();
        x10_int that_ph = buf.read<x10_int>();
        x10aux::ref<x10_lang_Clock__closure__4> this_ = new (x10aux::alloc<x10_lang_Clock__closure__4>()) x10_lang_Clock__closure__4(that_saved_this, that_ph);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Clock__closure__4(x10aux::ref<x10::lang::Clock> saved_this, x10_int ph) : saved_this(saved_this), ph(ph) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10:89";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Clock__closure__3 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__3> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 84 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this)->dropLocal(ph);
    }
    
    // captured environment
    x10aux::ref<x10::lang::Clock> saved_this;
    x10_int ph;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->ph);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Clock> that_saved_this = buf.read<x10aux::ref<x10::lang::Clock> >();
        x10_int that_ph = buf.read<x10_int>();
        x10aux::ref<x10_lang_Clock__closure__3> this_ = new (x10aux::alloc<x10_lang_Clock__closure__3>()) x10_lang_Clock__closure__3(that_saved_this, that_ph);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Clock__closure__3(x10aux::ref<x10::lang::Clock> saved_this, x10_int ph) : saved_this(saved_this), ph(ph) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10:84";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Clock__closure__2 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__2> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
        if (((ph) > (((x10_int)0)))) {
            
            //#line 76 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10aux::placeCheck(saved_this)->resumeLocal();
        }
        
        //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Try_c
        try {
        try {
            
            //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::lock();
            
            //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10While_c
            while (!(((abs) < (x10aux::placeCheck(saved_this)->FMGL(phase)))))
            {
                
                //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::await();
            }
            
        }
        catch (x10aux::__ref& __ref__711) {
            throw;
        }
        } catch (...) {
            {
                
                //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::release();
            }
            throw;
        }
        {
            
            //#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::release();
        }
    }
    
    // captured environment
    x10_int ph;
    x10aux::ref<x10::lang::Clock> saved_this;
    x10_int abs;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->ph);
        buf.write(this->saved_this);
        buf.write(this->abs);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10_int that_ph = buf.read<x10_int>();
        x10aux::ref<x10::lang::Clock> that_saved_this = buf.read<x10aux::ref<x10::lang::Clock> >();
        x10_int that_abs = buf.read<x10_int>();
        x10aux::ref<x10_lang_Clock__closure__2> this_ = new (x10aux::alloc<x10_lang_Clock__closure__2>()) x10_lang_Clock__closure__2(that_ph, that_saved_this, that_abs);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Clock__closure__2(x10_int ph, x10aux::ref<x10::lang::Clock> saved_this, x10_int abs) : ph(ph), saved_this(saved_this), abs(abs) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10:75-78";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Clock__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(saved_this)->resumeLocal();
    }
    
    // captured environment
    x10aux::ref<x10::lang::Clock> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Clock> that_saved_this = buf.read<x10aux::ref<x10::lang::Clock> >();
        x10aux::ref<x10_lang_Clock__closure__1> this_ = new (x10aux::alloc<x10_lang_Clock__closure__1>()) x10_lang_Clock__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Clock__closure__1(x10aux::ref<x10::lang::Clock> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10:68";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Clock__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Clock__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Try_c
        try {
        try {
            
            //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::lock();
            {
                
                //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                (__extension__ ({
                    x10aux::ref<x10::lang::Clock> x = saved_this;
                    x10_int y = ((x10_int)1);
                    x10aux::placeCheck(x10aux::nullCheck(x))->FMGL(count) =
                      ((x10_int) ((x10aux::placeCheck(x10aux::nullCheck(x))->
                                     FMGL(count)) + (y)));
                }))
                ;
                
                //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": x10.ast.X10If_c
                if ((!x10aux::struct_equals(((x10_int) -(ph)), x10aux::placeCheck(saved_this)->
                                                                 FMGL(phase))))
                {
                    
                    //#line 60 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                    (__extension__ ({
                        x10aux::ref<x10::lang::Clock> x =
                          saved_this;
                        x10_int y =
                          ((x10_int)1);
                        x10aux::placeCheck(x10aux::nullCheck(x))->
                          FMGL(alive) =
                          ((x10_int) ((x10aux::placeCheck(x10aux::nullCheck(x))->
                                         FMGL(alive)) + (y)));
                    }))
                    ;
                }
                
            }
        }
        catch (x10aux::__ref& __ref__708) {
            throw;
        }
        } catch (...) {
            {
                
                //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
                x10::lang::Runtime::release();
            }
            throw;
        }
        {
            
            //#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10": polyglot.ast.Eval_c
            x10::lang::Runtime::release();
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Clock> saved_this;
    x10_int ph;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
        buf.write(this->ph);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Clock> that_saved_this = buf.read<x10aux::ref<x10::lang::Clock> >();
        x10_int that_ph = buf.read<x10_int>();
        x10aux::ref<x10_lang_Clock__closure__0> this_ = new (x10aux::alloc<x10_lang_Clock__closure__0>()) x10_lang_Clock__closure__0(that_saved_this, that_ph);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Clock__closure__0(x10aux::ref<x10::lang::Clock> saved_this, x10_int ph) : saved_this(saved_this), ph(ph) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Clock.x10:58-61";
    }

};

