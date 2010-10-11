#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_lang_Runtime__ClockPhases__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_lang_Runtime__ClockPhases__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 287 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10": x10.ast.X10Return_c
        return x10aux::nullCheck(((clocks)->apply(i)))->_kwd__register();
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->clocks);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > that_clocks = buf.read<x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > >();
        x10aux::ref<x10_lang_Runtime__ClockPhases__closure__0> this_ = new (x10aux::alloc<x10_lang_Runtime__ClockPhases__closure__0>()) x10_lang_Runtime__ClockPhases__closure__0(that_clocks);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_lang_Runtime__ClockPhases__closure__0(x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Clock> > > clocks) : clocks(clocks) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Runtime.x10:287";
    }

};

