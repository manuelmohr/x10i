#include <x10/lang/Closure.h>
#include <x10/lang/Fun_0_1.h>
class x10_array_RectLayout__closure__0 : public x10::lang::Closure {
    public:
    
    static x10::lang::Fun_0_1<x10_int, x10_int>::itable<x10_array_RectLayout__closure__0> _itable;
    static x10aux::itable_entry _itables[2];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    // closure body
    x10_int apply(x10_int i) {
        
        //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10": x10.ast.X10Return_c
        return ((x10_int) ((((x10_int) (((max)->apply(i)) - ((min)->apply(i))))) + (((x10_int)1))));
        
    }
    
    // captured environment
    x10aux::ref<x10::lang::ValRail<x10_int > > max;
    x10aux::ref<x10::lang::ValRail<x10_int > > min;
    
    x10aux::serialization_id_t _get_serialization_id() {
        return _serialization_id;
    }
    
    // TODO: handle serialization of ref fields correctly
    
    void _serialize_body(x10aux::serialization_buffer &buf) {
        buf.write(this->max);
        buf.write(this->min);
    }
    
    template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer &buf) {
        x10aux::ref<x10::lang::ValRail<x10_int > > that_max = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10::lang::ValRail<x10_int > > that_min = buf.read<x10aux::ref<x10::lang::ValRail<x10_int > > >();
        x10aux::ref<x10_array_RectLayout__closure__0> this_ = new (x10aux::alloc<x10_array_RectLayout__closure__0>()) x10_array_RectLayout__closure__0(that_max, that_min);
        buf.record_reference(this_); // TODO: avoid; closure
        return this_;
    }
    
    x10_array_RectLayout__closure__0(x10aux::ref<x10::lang::ValRail<x10_int > > max, x10aux::ref<x10::lang::ValRail<x10_int > > min) : max(max), min(min) { }
    
    static const x10aux::serialization_id_t _serialization_id;
    
    static const x10aux::RuntimeType* getRTT() { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    virtual const x10aux::RuntimeType *_type() const { return x10aux::getRTT<x10::lang::Fun_0_1<x10_int, x10_int> >(); }
    
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::String::Lit(this->toNativeString());
    }
    
    const char* toNativeString() {
        return "/home/tux/workspace/x10.runtime/src-x10/x10/array/RectLayout.x10:47";
    }

};

