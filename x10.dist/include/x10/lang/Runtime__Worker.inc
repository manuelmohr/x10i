#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__Worker__closure__1 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Worker__closure__1> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((__extension__ ({
                                   x10aux::ref<x10::lang::Activity> __desugarer__var__65__ =
                                     saved_this->
                                       FMGL(activity);
                                   
                                   //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                                   x10aux::ref<x10::lang::Activity> __var1039__;
                                   
                                   //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                                   goto __ret1999; __ret1999: 
                                   //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                                   do
                                   {
                                   {
                                       
                                       //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                       if ((!x10aux::struct_equals(__desugarer__var__65__,
                                                                   x10aux::null)) &&
                                           !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__65__)->location),
                                                                    x10::lang::Place_methods::_make(x10aux::here)))))
                                       {
                                           
                                           //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                           x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Activity{self.home==here}"))));
                                       }
                                       
                                       //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                       __var1039__ =
                                         __desugarer__var__65__;
                                       
                                       //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                       goto __ret1999_end_;
                                   }
                                   goto __ret1999_next_; __ret1999_next_: ;
                                   }
                                   while (false);
                                   goto __ret1999_end_; __ret1999_end_: ;
                                   __var1039__;
                               }))
                               ))->run();
            
            //#line 913 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Worker> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Worker> that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__Worker> >();
        x10aux::ref<x10_lang_Runtime__Worker__closure__1> this_ = new (x10aux::alloc<x10_lang_Runtime__Worker__closure__1>()) x10_lang_Runtime__Worker__closure__1(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__Worker__closure__1(x10aux::ref<x10::lang::Runtime__Worker> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:913";
    }

};

#include <x10/lang/Closure.h>
#include <x10/lang/VoidFun_0_0.h>
class x10_lang_Runtime__Worker__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::VoidFun_0_0::itable<x10_lang_Runtime__Worker__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    void apply() {
        {
            
            //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
            x10aux::nullCheck(((__extension__ ({
                                   x10aux::ref<x10::lang::Activity> __desugarer__var__64__ =
                                     saved_this->
                                       FMGL(activity);
                                   
                                   //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10LocalDecl_c
                                   x10aux::ref<x10::lang::Activity> __var1037__;
                                   
                                   //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Labeled_c
                                   goto __ret1998; __ret1998: 
                                   //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Do_c
                                   do
                                   {
                                   {
                                       
                                       //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10If_c
                                       if ((!x10aux::struct_equals(__desugarer__var__64__,
                                                                   x10aux::null)) &&
                                           !((x10aux::struct_equals(x10::lang::Place_methods::place((__desugarer__var__64__)->location),
                                                                    x10::lang::Place_methods::_make(x10aux::here)))))
                                       {
                                           
                                           //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Throw_c
                                           x10aux::throwException(x10aux::nullCheck(x10::lang::ClassCastException::_make(x10::lang::String::Lit("x10.lang.Activity{self.home==here}"))));
                                       }
                                       
                                       //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Eval_c
                                       __var1037__ =
                                         __desugarer__var__64__;
                                       
                                       //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": polyglot.ast.Branch_c
                                       goto __ret1998_end_;
                                   }
                                   goto __ret1998_next_; __ret1998_next_: ;
                                   }
                                   while (false);
                                   goto __ret1998_end_; __ret1998_end_: ;
                                   __var1037__;
                               }))
                               ))->run();
            
            //#line 897 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
            return;
        }
    }
    
    // captured environment
    x10aux::ref<x10::lang::Runtime__Worker> saved_this;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->saved_this);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::Runtime__Worker> that_saved_this = buf.read<x10aux::ref<x10::lang::Runtime__Worker> >();
        x10aux::ref<x10_lang_Runtime__Worker__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__Worker__closure__0>()) x10_lang_Runtime__Worker__closure__0(that_saved_this);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__Worker__closure__0(x10aux::ref<x10::lang::Runtime__Worker> saved_this) : saved_this(saved_this) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::VoidFun_0_0>(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:897";
    }

};

