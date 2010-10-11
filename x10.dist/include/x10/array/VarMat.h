#ifndef __X10_ARRAY_VARMAT_H
#define __X10_ARRAY_VARMAT_H

#include <x10rt.h>


#define X10_ARRAY_MAT_H_NODEPS
#include <x10/array/Mat.h>
#undef X10_ARRAY_MAT_H_NODEPS
namespace x10 { namespace array { 
class VarRow;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(Z2), class FMGL(U)> class Fun_0_2;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace lang { 
template<class FMGL(Z1), class FMGL(U)> class Fun_0_1;
} } 
namespace x10 { namespace array { 

class VarMat : public x10::array::Mat<x10aux::ref<x10::array::VarRow> >   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[4];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> >::itable<x10::array::VarMat > _itable_0;
    
    static x10::lang::Any::itable<x10::array::VarMat > _itable_1;
    
    static x10::lang::Iterable<x10aux::ref<x10::array::VarRow> >::itable<x10::array::VarMat > _itable_2;
    
    void _instance_init();
    
    void _constructor(x10_int cols, x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::VarRow> > > mat);
    
    static x10aux::ref<x10::array::VarMat> _make(x10_int cols, x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::array::VarRow> > > mat);
    
    void _constructor(x10_int rows, x10_int cols, x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > init);
    
    static x10aux::ref<x10::array::VarMat> _make(x10_int rows, x10_int cols,
                                                 x10aux::ref<x10::lang::Fun_0_1<x10_int, x10aux::ref<x10::array::VarRow> > > init);
    
    void _constructor(x10_int rows, x10_int cols, x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init);
    
    static x10aux::ref<x10::array::VarMat> _make(x10_int rows, x10_int cols,
                                                 x10aux::ref<x10::lang::Fun_0_2<x10_int, x10_int, x10_int> > init);
    
    void _constructor(x10_int rows, x10_int cols);
    
    static x10aux::ref<x10::array::VarMat> _make(x10_int rows, x10_int cols);
    
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::array::VarMat> this_,
                                   x10aux::serialization_buffer& buf);
    
    public: x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_ARRAY_VARMAT_H

namespace x10 { namespace array { 
class VarMat;
} } 

#ifndef X10_ARRAY_VARMAT_H_NODEPS
#define X10_ARRAY_VARMAT_H_NODEPS
#include <x10/array/Mat.h>
#include <x10/array/VarRow.h>
#include <x10/lang/Int.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/ValRail.h>
#include <x10/lang/Fun_0_2.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#include <x10/lang/Fun_0_1.h>
#ifndef X10_ARRAY_VARMAT_H_GENERICS
#define X10_ARRAY_VARMAT_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::VarMat::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::VarMat> this_ = new (x10aux::alloc_remote<x10::array::VarMat>()) x10::array::VarMat();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::array::VarMat::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::array::VarMat> this_;
    if (rr.ref != 0) {
        this_ = x10::array::VarMat::_deserializer<x10::array::VarMat>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_ARRAY_VARMAT_H_GENERICS
#endif // __X10_ARRAY_VARMAT_H_NODEPS
