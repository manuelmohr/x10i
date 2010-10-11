#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_compiler_RemoteOperation__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_compiler_RemoteOperation__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::lang::Rail<x10_long > > x = (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_long > > __desugarer__var__37__ =
                  r;
                
                //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::lang::Rail<x10_long > > __var458__;
                
                //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Labeled_c
                goto __ret1961; __ret1961: 
                //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10Do_c
                do
                {
                {
                    
                    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10If_c
                    if ((!x10aux::struct_equals(__desugarer__var__37__,
                                                x10aux::null)) &&
                        !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__37__)->location),
                                                 x10::lang::Place_methods::_make(x10aux::here)))))
                    {
                        
                        //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Throw_c
                        x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Rail[x10.lang.Long]{self.home==here}"))));
                    }
                    
                    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
                    __var458__ =
                      __desugarer__var__37__;
                    
                    //#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Branch_c
                    goto __ret1961_end_;
                }
                goto __ret1961_next_; __ret1961_next_: ;
                }
                while (false);
                goto __ret1961_end_; __ret1961_end_: ;
                __var458__;
            }))
            ;
            x10_int y0 = i;
            x10_long z = v;
            (x)->set(((x10_long) (((x)->apply(y0)) ^ (z))), y0);
        }))
        ;
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10_long > > r;
    x10_int i;
    x10_long v;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->i);
        buf.write(this->v);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10_long > > that_r = buf.read<x10aux::ref<x10::lang::Rail<x10_long > > >();
        x10_int that_i = buf.read<x10_int>();
        x10_long that_v = buf.read<x10_long>();
        x10aux::ref<x10_compiler_RemoteOperation__closure__1> this_ = new (x10aux::alloc<x10_compiler_RemoteOperation__closure__1>()) x10_compiler_RemoteOperation__closure__1(that_r, that_i, that_v);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_compiler_RemoteOperation__closure__1(x10aux::ref<x10::lang::Rail<x10_long > > r, x10_int i, x10_long v) : r(r), i(i), v(v) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10:28-30";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_compiler_RemoteOperation__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_compiler_RemoteOperation__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        
        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
        (__extension__ ({
            x10aux::ref<x10::lang::Rail<x10_long > > x = (__extension__ ({
                x10aux::ref<x10::lang::Rail<x10_long > > __desugarer__var__36__ =
                  r;
                
                //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10LocalDecl_c
                x10aux::ref<x10::lang::Rail<x10_long > > __var456__;
                
                //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Labeled_c
                goto __ret1960; __ret1960: 
                //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10Do_c
                do
                {
                {
                    
                    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": x10.ast.X10If_c
                    if ((!x10aux::struct_equals(__desugarer__var__36__,
                                                x10aux::null)) &&
                        !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__36__)->location),
                                                 x10::lang::Place_methods::_make(x10aux::here)))))
                    {
                        
                        //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Throw_c
                        x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Rail[x10.lang.Long]{self.home==here}"))));
                    }
                    
                    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Eval_c
                    __var456__ =
                      __desugarer__var__36__;
                    
                    //#line 22 "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10": polyglot.ast.Branch_c
                    goto __ret1960_end_;
                }
                goto __ret1960_next_; __ret1960_next_: ;
                }
                while (false);
                goto __ret1960_end_; __ret1960_end_: ;
                __var456__;
            }))
            ;
            x10_int y0 = i;
            x10_long z = v;
            (x)->set(((x10_long) (((x)->apply(y0)) ^ (z))), y0);
        }))
        ;
    }
    
    // captured environment
    x10aux::ref<x10::lang::Rail<x10_long > > r;
    x10_int i;
    x10_long v;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->r);
        buf.write(this->i);
        buf.write(this->v);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Rail<x10_long > > that_r = buf.read<x10aux::ref<x10::lang::Rail<x10_long > > >();
        x10_int that_i = buf.read<x10_int>();
        x10_long that_v = buf.read<x10_long>();
        x10aux::ref<x10_compiler_RemoteOperation__closure__0> this_ = new (x10aux::alloc<x10_compiler_RemoteOperation__closure__0>()) x10_compiler_RemoteOperation__closure__0(that_r, that_i, that_v);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_compiler_RemoteOperation__closure__0(x10aux::ref<x10::lang::Rail<x10_long > > r, x10_int i, x10_long v) : r(r), i(i), v(v) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/compiler/RemoteOperation.x10:21-23";
    }

};

