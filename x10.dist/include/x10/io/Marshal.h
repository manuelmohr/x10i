#ifndef __X10_IO_MARSHAL_H
#define __X10_IO_MARSHAL_H

#include <x10rt.h>


#define X10_LANG_ANY_H_NODEPS
#include <x10/lang/Any.h>
#undef X10_LANG_ANY_H_NODEPS
namespace x10 { namespace io { 
class Reader;
} } 
namespace x10 { namespace io { 
class IOException;
} } 
namespace x10 { namespace io { 
class Writer;
} } 
namespace x10 { namespace io { 
class Marshal__BooleanMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__ByteMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__CharMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__ShortMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__IntMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__LongMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__FloatMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__DoubleMarshal;
} } 
namespace x10 { namespace io { 
class Marshal__LineMarshal;
} } 
namespace x10 { namespace io { 

template<class FMGL(T)> class Marshal;
template <> class Marshal<void>;
template<class FMGL(T)> class Marshal   {
    public:
    RTT_H_DECLS_INTERFACE
    
    template <class I> struct itable {
        itable(x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>), x10_boolean (I::*_m1__at) (x10::lang::Place), x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>), x10_int (I::*hashCode) (), x10::lang::Place (I::*home) (), FMGL(T) (I::*read) (x10aux::ref<x10::io::Reader>), x10aux::ref<x10::lang::String> (I::*toString) (), x10aux::ref<x10::lang::String> (I::*typeName) (), void (I::*write) (x10aux::ref<x10::io::Writer>, FMGL(T))) : _m0__at(_m0__at), _m1__at(_m1__at), equals(equals), hashCode(hashCode), home(home), read(read), toString(toString), typeName(typeName), write(write) {}
        x10_boolean (I::*_m0__at) (x10aux::ref<x10::lang::Object>);
        x10_boolean (I::*_m1__at) (x10::lang::Place);
        x10_boolean (I::*equals) (x10aux::ref<x10::lang::Any>);
        x10_int (I::*hashCode) ();
        x10::lang::Place (I::*home) ();
        FMGL(T) (I::*read) (x10aux::ref<x10::io::Reader>);
        x10aux::ref<x10::lang::String> (I::*toString) ();
        x10aux::ref<x10::lang::String> (I::*typeName) ();
        void (I::*write) (x10aux::ref<x10::io::Writer>, FMGL(T));
    };
    
    static void _serialize(x10aux::ref<x10::io::Marshal<FMGL(T)> > this_,
                           x10aux::serialization_buffer& buf) {
        x10::lang::Reference::_serialize(this_, buf);
    }
    
    public: template<class __T> static x10aux::ref<__T> _deserialize(x10aux::deserialization_buffer& buf) {
        return x10::lang::Reference::_deserialize<__T>(buf);
    }
    
    void _instance_init();
    
    
};
template <> class Marshal<void> {
    public:
    static x10aux::RuntimeType rtt;
    static const x10aux::RuntimeType* getRTT() { return & rtt; }
    static x10aux::ref<x10::io::Marshal__BooleanMarshal> FMGL(BOOLEAN);
    
    static x10aux::ref<x10::io::Marshal__ByteMarshal> FMGL(BYTE);
    
    static x10aux::ref<x10::io::Marshal__CharMarshal> FMGL(CHAR);
    
    static x10aux::ref<x10::io::Marshal__ShortMarshal> FMGL(SHORT);
    
    static x10aux::ref<x10::io::Marshal__IntMarshal> FMGL(INT);
    
    static x10aux::ref<x10::io::Marshal__LongMarshal> FMGL(LONG);
    
    static x10aux::ref<x10::io::Marshal__FloatMarshal> FMGL(FLOAT);
    
    static x10aux::ref<x10::io::Marshal__DoubleMarshal> FMGL(DOUBLE);
    
    static x10aux::ref<x10::io::Marshal__LineMarshal> FMGL(LINE);
    
    static void FMGL(BOOLEAN__do_init)();
    static void FMGL(BOOLEAN__init)();
    static volatile x10aux::status FMGL(BOOLEAN__status);
    static inline x10aux::ref<x10::io::Marshal__BooleanMarshal> FMGL(BOOLEAN__get)() {
        if (FMGL(BOOLEAN__status) != x10aux::INITIALIZED) {
            FMGL(BOOLEAN__init)();
        }
        return x10::io::Marshal<void>::FMGL(BOOLEAN);
    }
    static x10aux::ref<x10::lang::Object> FMGL(BOOLEAN__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(BOOLEAN__id);
    
    static void FMGL(BYTE__do_init)();
    static void FMGL(BYTE__init)();
    static volatile x10aux::status FMGL(BYTE__status);
    static inline x10aux::ref<x10::io::Marshal__ByteMarshal> FMGL(BYTE__get)() {
        if (FMGL(BYTE__status) != x10aux::INITIALIZED) {
            FMGL(BYTE__init)();
        }
        return x10::io::Marshal<void>::FMGL(BYTE);
    }
    static x10aux::ref<x10::lang::Object> FMGL(BYTE__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(BYTE__id);
    
    static void FMGL(CHAR__do_init)();
    static void FMGL(CHAR__init)();
    static volatile x10aux::status FMGL(CHAR__status);
    static inline x10aux::ref<x10::io::Marshal__CharMarshal> FMGL(CHAR__get)() {
        if (FMGL(CHAR__status) != x10aux::INITIALIZED) {
            FMGL(CHAR__init)();
        }
        return x10::io::Marshal<void>::FMGL(CHAR);
    }
    static x10aux::ref<x10::lang::Object> FMGL(CHAR__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(CHAR__id);
    
    static void FMGL(SHORT__do_init)();
    static void FMGL(SHORT__init)();
    static volatile x10aux::status FMGL(SHORT__status);
    static inline x10aux::ref<x10::io::Marshal__ShortMarshal> FMGL(SHORT__get)() {
        if (FMGL(SHORT__status) != x10aux::INITIALIZED) {
            FMGL(SHORT__init)();
        }
        return x10::io::Marshal<void>::FMGL(SHORT);
    }
    static x10aux::ref<x10::lang::Object> FMGL(SHORT__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(SHORT__id);
    
    static void FMGL(INT__do_init)();
    static void FMGL(INT__init)();
    static volatile x10aux::status FMGL(INT__status);
    static inline x10aux::ref<x10::io::Marshal__IntMarshal> FMGL(INT__get)() {
        if (FMGL(INT__status) != x10aux::INITIALIZED) {
            FMGL(INT__init)();
        }
        return x10::io::Marshal<void>::FMGL(INT);
    }
    static x10aux::ref<x10::lang::Object> FMGL(INT__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(INT__id);
    
    static void FMGL(LONG__do_init)();
    static void FMGL(LONG__init)();
    static volatile x10aux::status FMGL(LONG__status);
    static inline x10aux::ref<x10::io::Marshal__LongMarshal> FMGL(LONG__get)() {
        if (FMGL(LONG__status) != x10aux::INITIALIZED) {
            FMGL(LONG__init)();
        }
        return x10::io::Marshal<void>::FMGL(LONG);
    }
    static x10aux::ref<x10::lang::Object> FMGL(LONG__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(LONG__id);
    
    static void FMGL(FLOAT__do_init)();
    static void FMGL(FLOAT__init)();
    static volatile x10aux::status FMGL(FLOAT__status);
    static inline x10aux::ref<x10::io::Marshal__FloatMarshal> FMGL(FLOAT__get)() {
        if (FMGL(FLOAT__status) != x10aux::INITIALIZED) {
            FMGL(FLOAT__init)();
        }
        return x10::io::Marshal<void>::FMGL(FLOAT);
    }
    static x10aux::ref<x10::lang::Object> FMGL(FLOAT__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(FLOAT__id);
    
    static void FMGL(DOUBLE__do_init)();
    static void FMGL(DOUBLE__init)();
    static volatile x10aux::status FMGL(DOUBLE__status);
    static inline x10aux::ref<x10::io::Marshal__DoubleMarshal> FMGL(DOUBLE__get)() {
        if (FMGL(DOUBLE__status) != x10aux::INITIALIZED) {
            FMGL(DOUBLE__init)();
        }
        return x10::io::Marshal<void>::FMGL(DOUBLE);
    }
    static x10aux::ref<x10::lang::Object> FMGL(DOUBLE__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(DOUBLE__id);
    
    static void FMGL(LINE__do_init)();
    static void FMGL(LINE__init)();
    static volatile x10aux::status FMGL(LINE__status);
    static inline x10aux::ref<x10::io::Marshal__LineMarshal> FMGL(LINE__get)() {
        if (FMGL(LINE__status) != x10aux::INITIALIZED) {
            FMGL(LINE__init)();
        }
        return x10::io::Marshal<void>::FMGL(LINE);
    }
    static x10aux::ref<x10::lang::Object> FMGL(LINE__deserialize)(x10aux::deserialization_buffer &buf);
    static const x10aux::serialization_id_t FMGL(LINE__id);
    
    
};

} } 
#endif // X10_IO_MARSHAL_H

namespace x10 { namespace io { 
template<class FMGL(T)> class Marshal;
} } 

#ifndef X10_IO_MARSHAL_H_NODEPS
#define X10_IO_MARSHAL_H_NODEPS
#include <x10/lang/Any.h>
#include <x10/io/Reader.h>
#include <x10/io/IOException.h>
#include <x10/io/Writer.h>
#include <x10/io/Marshal__BooleanMarshal.h>
#include <x10/io/Marshal__ByteMarshal.h>
#include <x10/io/Marshal__CharMarshal.h>
#include <x10/io/Marshal__ShortMarshal.h>
#include <x10/io/Marshal__IntMarshal.h>
#include <x10/io/Marshal__LongMarshal.h>
#include <x10/io/Marshal__FloatMarshal.h>
#include <x10/io/Marshal__DoubleMarshal.h>
#include <x10/io/Marshal__LineMarshal.h>
#ifndef X10_IO_MARSHAL_H_GENERICS
#define X10_IO_MARSHAL_H_GENERICS
#endif // X10_IO_MARSHAL_H_GENERICS
#ifndef X10_IO_MARSHAL_H_IMPLEMENTATION
#define X10_IO_MARSHAL_H_IMPLEMENTATION
#include <x10/io/Marshal.h>


#include "x10/io/Marshal.inc"

template<class FMGL(T)> void x10::io::Marshal<FMGL(T)>::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Marshal<FMGL(T)>");
    
}


//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Marshal.x10": x10.ast.X10FieldDecl_c
template<class FMGL(T)> x10aux::RuntimeType x10::io::Marshal<FMGL(T)>::rtt;
template<class FMGL(T)> void x10::io::Marshal<FMGL(T)>::_initRTT() {
    const x10aux::RuntimeType *canonical = x10aux::getRTT<x10::io::Marshal<void> >();
    if (rtt.initStageOne(canonical)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Any>()};
    const x10aux::RuntimeType* params[1] = { x10aux::getRTT<FMGL(T)>()};
    x10aux::RuntimeType::Variance variances[1] = { x10aux::RuntimeType::invariant};
    const char *baseName = "x10.io.Marshal";
    rtt.initStageTwo(baseName, 1, parents, 1, params, variances);
}
#endif // X10_IO_MARSHAL_H_IMPLEMENTATION
#endif // __X10_IO_MARSHAL_H_NODEPS
