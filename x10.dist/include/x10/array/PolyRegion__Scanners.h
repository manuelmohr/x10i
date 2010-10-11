#ifndef __X10_ARRAY_POLYREGION__SCANNERS_H
#define __X10_ARRAY_POLYREGION__SCANNERS_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
#define X10_LANG_ITERATOR_H_NODEPS
#include <x10/lang/Iterator.h>
#undef X10_LANG_ITERATOR_H_NODEPS
namespace x10 { namespace array { 
class Region__Scanner;
} } 
#define X10_LANG_BOOLEAN_STRUCT_H_NODEPS
#include <x10/lang/Boolean.struct_h>
#undef X10_LANG_BOOLEAN_STRUCT_H_NODEPS
namespace x10 { namespace array { 
class PolyRegion;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
class NoSuchElementException;
} } 
namespace x10 { namespace lang { 
class UnsupportedOperationException;
} } 
namespace x10 { namespace array { 

class PolyRegion__Scanners : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10aux::itable_entry _itables[3];
    
    virtual x10aux::itable_entry* _getITables() { return _itables; }
    
    static x10::lang::Iterator<x10aux::ref<x10::array::Region__Scanner> >::itable<x10::array::PolyRegion__Scanners > _itable_0;
    
    static x10::lang::Any::itable<x10::array::PolyRegion__Scanners > _itable_1;
    
    void _instance_init();
    
    x10aux::ref<x10::array::PolyRegion> FMGL(out__);
    
    x10_boolean FMGL(hasNext);
    
    virtual x10_boolean hasNext();
    virtual x10aux::ref<x10::array::Region__Scanner> next();
    virtual void remove();
    void _constructor(x10aux::ref<x10::array::PolyRegion> out__);
    
    static x10aux::ref<x10::array::PolyRegion__Scanners> _make(x10aux::ref<x10::array::PolyRegion> out__);
    
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: virtual x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(x10aux::serialization_buffer& buf);
    
    public: template<class __T> static x10aux::ref<__T> _deserializer(x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(x10aux::deserialization_buffer& buf);
    
};

} } 
#endif // X10_ARRAY_POLYREGION__SCANNERS_H

namespace x10 { namespace array { 
class PolyRegion__Scanners;
} } 

#ifndef X10_ARRAY_POLYREGION__SCANNERS_H_NODEPS
#define X10_ARRAY_POLYREGION__SCANNERS_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/lang/Iterator.h>
#include <x10/array/Region__Scanner.h>
#include <x10/array/PolyRegion.h>
#include <x10/lang/Boolean.h>
#include <x10/util/NoSuchElementException.h>
#include <x10/lang/UnsupportedOperationException.h>
#ifndef X10_ARRAY_POLYREGION__SCANNERS_H_GENERICS
#define X10_ARRAY_POLYREGION__SCANNERS_H_GENERICS
template<class __T> x10aux::ref<__T> x10::array::PolyRegion__Scanners::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::array::PolyRegion__Scanners> this_ = new (x10aux::alloc_remote<x10::array::PolyRegion__Scanners>()) x10::array::PolyRegion__Scanners();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

#endif // X10_ARRAY_POLYREGION__SCANNERS_H_GENERICS
#endif // __X10_ARRAY_POLYREGION__SCANNERS_H_NODEPS
