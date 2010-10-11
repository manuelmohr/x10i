#ifndef __X10_UTIL_OPTIONSPARSER_H
#define __X10_UTIL_OPTIONSPARSER_H

#include <x10rt.h>


#define X10_LANG_OBJECT_H_NODEPS
#include <x10/lang/Object.h>
#undef X10_LANG_OBJECT_H_NODEPS
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace util { 
template<class FMGL(K), class FMGL(V)> class HashMap;
} } 
namespace x10 { namespace lang { 
class Boolean;
} } 
#include <x10/lang/Boolean.struct_h>
namespace x10 { namespace util { 
template<class FMGL(T)> class GrowableRail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
template<class FMGL(T)> class ValRail;
} } 
namespace x10 { namespace util { 
class Option;
} } 
#include <x10/util/Option.struct_h>
namespace x10 { namespace util { 
class OptionsParser__Err;
} } 
namespace x10 { namespace lang { 
class Int;
} } 
#include <x10/lang/Int.struct_h>
namespace x10 { namespace lang { 
template<class FMGL(T)> class Iterator;
} } 
namespace x10 { namespace lang { 
class Byte;
} } 
#include <x10/lang/Byte.struct_h>
namespace x10 { namespace lang { 
class NumberFormatException;
} } 
namespace x10 { namespace lang { 
class Short;
} } 
#include <x10/lang/Short.struct_h>
namespace x10 { namespace lang { 
class Long;
} } 
#include <x10/lang/Long.struct_h>
namespace x10 { namespace lang { 
class Double;
} } 
#include <x10/lang/Double.struct_h>
namespace x10 { namespace lang { 
class Float;
} } 
#include <x10/lang/Float.struct_h>
namespace x10 { namespace util { 

class OptionsParser : public x10::lang::Object   {
    public:
    RTT_H_DECLS_CLASS
    
    void _instance_init();
    
    x10aux::ref<x10::util::HashMap<x10aux::ref<x10::lang::String>, x10aux::ref<x10::lang::String> > >
      FMGL(map);
    
    x10aux::ref<x10::util::HashMap<x10aux::ref<x10::lang::String>, x10_boolean> >
      FMGL(set);
    
    x10aux::ref<x10::util::GrowableRail<x10aux::ref<x10::lang::String> > >
      FMGL(filteredArgs);
    
    void _constructor(x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > > args,
                      x10aux::ref<x10::lang::ValRail<x10::util::Option > > flags,
                      x10aux::ref<x10::lang::ValRail<x10::util::Option > > specs);
    
    static x10aux::ref<x10::util::OptionsParser> _make(
             x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > > args,
             x10aux::ref<x10::lang::ValRail<x10::util::Option > > flags,
             x10aux::ref<x10::lang::ValRail<x10::util::Option > > specs);
    
    virtual x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::String> > >
      filteredArgs(
      );
    virtual x10_boolean apply(x10aux::ref<x10::lang::String> key);
    virtual x10aux::ref<x10::lang::String>
      apply(
      x10aux::ref<x10::lang::String> key,
      x10aux::ref<x10::lang::String> d);
    virtual x10_byte apply(x10aux::ref<x10::lang::String> key,
                           x10_byte d);
    virtual x10_short apply(x10aux::ref<x10::lang::String> key,
                            x10_short d);
    virtual x10_int apply(x10aux::ref<x10::lang::String> key,
                          x10_int d);
    virtual x10_long apply(x10aux::ref<x10::lang::String> key,
                           x10_long d);
    virtual x10_double apply(x10aux::ref<x10::lang::String> key,
                             x10_double d);
    virtual x10_float apply(x10aux::ref<x10::lang::String> key,
                            x10_float d);
    
    // Serialization
    public: static const x10aux::serialization_id_t _serialization_id;
    
    public: static void _serialize(x10aux::ref<x10::util::OptionsParser> this_,
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
#endif // X10_UTIL_OPTIONSPARSER_H

namespace x10 { namespace util { 
class OptionsParser;
} } 

#ifndef X10_UTIL_OPTIONSPARSER_H_NODEPS
#define X10_UTIL_OPTIONSPARSER_H_NODEPS
#include <x10/lang/Object.h>
#include <x10/util/HashMap.h>
#include <x10/lang/String.h>
#include <x10/util/HashMap.h>
#include <x10/lang/Boolean.h>
#include <x10/util/GrowableRail.h>
#include <x10/lang/Rail.h>
#include <x10/lang/ValRail.h>
#include <x10/util/Option.h>
#include <x10/util/OptionsParser__Err.h>
#include <x10/lang/Int.h>
#include <x10/lang/Iterator.h>
#include <x10/lang/Byte.h>
#include <x10/lang/NumberFormatException.h>
#include <x10/lang/Short.h>
#include <x10/lang/Long.h>
#include <x10/lang/Double.h>
#include <x10/lang/Float.h>
#ifndef X10_UTIL_OPTIONSPARSER_H_GENERICS
#define X10_UTIL_OPTIONSPARSER_H_GENERICS
template<class __T> x10aux::ref<__T> x10::util::OptionsParser::_deserializer(x10aux::deserialization_buffer& buf) {
    x10aux::ref<x10::util::OptionsParser> this_ = new (x10aux::alloc_remote<x10::util::OptionsParser>()) x10::util::OptionsParser();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

template<class __T> x10aux::ref<__T> x10::util::OptionsParser::_deserialize(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_reference_state rr = x10::lang::Object::_deserialize_reference_state(buf);
    x10aux::ref<x10::util::OptionsParser> this_;
    if (rr.ref != 0) {
        this_ = x10::util::OptionsParser::_deserializer<x10::util::OptionsParser>(buf);
    }
    return x10::lang::Object::_finalize_reference<__T>(this_, rr, buf);
}

#endif // X10_UTIL_OPTIONSPARSER_H_GENERICS
#endif // __X10_UTIL_OPTIONSPARSER_H_NODEPS
