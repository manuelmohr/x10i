#include <x10/lang/Complex.h>


#include "x10/lang/Complex.inc"

namespace x10 { namespace lang { 
class Complex_ithunk0 : public x10::lang::Complex {
public:
    static x10::lang::Any::itable<Complex_ithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(*this) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(*this) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::Complex_methods::equals(*this, arg0);
    }
    x10_int hashCode() {
        return x10::lang::Complex_methods::hashCode(*this);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(*this));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::Complex_methods::toString(*this);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(*this);
    }
    
};
x10::lang::Any::itable<Complex_ithunk0 >  Complex_ithunk0::itable(&Complex_ithunk0::at, &Complex_ithunk0::at, &Complex_ithunk0::equals, &Complex_ithunk0::hashCode, &Complex_ithunk0::home, &Complex_ithunk0::toString, &Complex_ithunk0::typeName);
class Complex_iboxithunk0 : public x10::lang::IBox<x10::lang::Complex> {
public:
    static x10::lang::Any::itable<Complex_iboxithunk0 > itable;
    x10_boolean at(x10aux::ref<x10::lang::Object> arg0) {
        return (x10aux::get_location(this->value) == (arg0)->location);
    }
    x10_boolean at(x10::lang::Place arg0) {
        return (x10aux::get_location(this->value) == (arg0)->FMGL(id));
    }
    x10_boolean equals(x10aux::ref<x10::lang::Any> arg0) {
        return x10::lang::Complex_methods::equals(this->value, arg0);
    }
    x10_int hashCode() {
        return x10::lang::Complex_methods::hashCode(this->value);
    }
    x10::lang::Place home() {
        return x10::lang::Place_methods::place(x10aux::get_location(this->value));
    }
    x10aux::ref<x10::lang::String> toString() {
        return x10::lang::Complex_methods::toString(this->value);
    }
    x10aux::ref<x10::lang::String> typeName() {
        return x10aux::type_name(this->value);
    }
    
};
x10::lang::Any::itable<Complex_iboxithunk0 >  Complex_iboxithunk0::itable(&Complex_iboxithunk0::at, &Complex_iboxithunk0::at, &Complex_iboxithunk0::equals, &Complex_iboxithunk0::hashCode, &Complex_iboxithunk0::home, &Complex_iboxithunk0::toString, &Complex_iboxithunk0::typeName);
} } 
x10aux::itable_entry x10::lang::Complex::_itables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Complex_ithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Complex>())};
x10aux::itable_entry x10::lang::Complex::_iboxitables[2] = {x10aux::itable_entry(&x10aux::getRTT<x10::lang::Any>, &Complex_iboxithunk0::itable), x10aux::itable_entry(NULL, (void*)x10aux::getRTT<x10::lang::Complex>())};
void x10::lang::Complex_methods::_instance_init(x10::lang::Complex& this_) {
    _I_("Doing initialisation for class: x10::lang::Complex");
    
}


//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
/** The real component of this complex number. */
                                                 //#line 23 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                 /** The imaginary component of this complex number. */
                                                                                                       //#line 26 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                                                                       /** The complex number that corresponds to 0.0 */x10::lang::Complex
                                                                                                                                                          x10::lang::Complex_methods::FMGL(ZERO);
                                                                                                       void x10::lang::Complex_methods::FMGL(ZERO__do_init)() {
                                                                                                           FMGL(ZERO__status) = x10aux::INITIALIZING;
                                                                                                           _I_("Doing static initialisation for field: x10::lang::Complex_methods.ZERO");
                                                                                                           x10::lang::Complex
                                                                                                             __var721__ =
                                                                                                             x10::lang::Complex_methods::_make(0.0,
                                                                                                                                               0.0);
                                                                                                           FMGL(ZERO) = __var721__;
                                                                                                           FMGL(ZERO__status) = x10aux::INITIALIZED;
                                                                                                       }
                                                                                                       void x10::lang::Complex_methods::FMGL(ZERO__init)() {
                                                                                                           if (x10aux::here == 0) {
                                                                                                               x10aux::status __var722__ =
                                                                                                                 (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(ZERO__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
                                                                                                               if (__var722__ != x10aux::UNINITIALIZED) goto WAIT;
                                                                                                               FMGL(ZERO__do_init)();
                                                                                                               x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(ZERO),
                                                                                                                                                                           FMGL(ZERO__id));
                                                                                                               // Notify all waiting threads
                                                                                                               x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           }
                                                                                                           WAIT:
                                                                                                           while (FMGL(ZERO__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
                                                                                                       }
                                                                                                       static void* __init__723 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Complex_methods::FMGL(ZERO__init));
                                                                                                       
                                                                                                       volatile x10aux::status x10::lang::Complex_methods::FMGL(ZERO__status);
                                                                                                       // extract value from a buffer
                                                                                                       x10aux::ref<x10::lang::Object>
                                                                                                         x10::lang::Complex_methods::FMGL(ZERO__deserialize)(x10aux::deserialization_buffer &buf) {
                                                                                                           FMGL(ZERO) =
                                                                                                             buf.read<x10::lang::Complex>();
                                                                                                           x10::lang::Complex_methods::FMGL(ZERO__status) = x10aux::INITIALIZED;
                                                                                                           // Notify all waiting threads
                                                                                                           x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           return x10aux::null;
                                                                                                       }
                                                                                                       const x10aux::serialization_id_t x10::lang::Complex_methods::FMGL(ZERO__id) =
                                                                                                         x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Complex_methods::FMGL(ZERO__deserialize));
                                                                                                       
                                                                                                       
                                                                                                       //#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                                                                       /** The complex number that corresponds to 1.0 */x10::lang::Complex
                                                                                                                                                          x10::lang::Complex_methods::FMGL(ONE);
                                                                                                       void x10::lang::Complex_methods::FMGL(ONE__do_init)() {
                                                                                                           FMGL(ONE__status) = x10aux::INITIALIZING;
                                                                                                           _I_("Doing static initialisation for field: x10::lang::Complex_methods.ONE");
                                                                                                           x10::lang::Complex
                                                                                                             __var724__ =
                                                                                                             x10::lang::Complex_methods::_make(1.0,
                                                                                                                                               0.0);
                                                                                                           FMGL(ONE) = __var724__;
                                                                                                           FMGL(ONE__status) = x10aux::INITIALIZED;
                                                                                                       }
                                                                                                       void x10::lang::Complex_methods::FMGL(ONE__init)() {
                                                                                                           if (x10aux::here == 0) {
                                                                                                               x10aux::status __var725__ =
                                                                                                                 (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(ONE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
                                                                                                               if (__var725__ != x10aux::UNINITIALIZED) goto WAIT;
                                                                                                               FMGL(ONE__do_init)();
                                                                                                               x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(ONE),
                                                                                                                                                                           FMGL(ONE__id));
                                                                                                               // Notify all waiting threads
                                                                                                               x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           }
                                                                                                           WAIT:
                                                                                                           while (FMGL(ONE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
                                                                                                       }
                                                                                                       static void* __init__726 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Complex_methods::FMGL(ONE__init));
                                                                                                       
                                                                                                       volatile x10aux::status x10::lang::Complex_methods::FMGL(ONE__status);
                                                                                                       // extract value from a buffer
                                                                                                       x10aux::ref<x10::lang::Object>
                                                                                                         x10::lang::Complex_methods::FMGL(ONE__deserialize)(x10aux::deserialization_buffer &buf) {
                                                                                                           FMGL(ONE) =
                                                                                                             buf.read<x10::lang::Complex>();
                                                                                                           x10::lang::Complex_methods::FMGL(ONE__status) = x10aux::INITIALIZED;
                                                                                                           // Notify all waiting threads
                                                                                                           x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           return x10aux::null;
                                                                                                       }
                                                                                                       const x10aux::serialization_id_t x10::lang::Complex_methods::FMGL(ONE__id) =
                                                                                                         x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Complex_methods::FMGL(ONE__deserialize));
                                                                                                       
                                                                                                       
                                                                                                       //#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                                                                       /** The complex number that corresponds to 1.0i */x10::lang::Complex
                                                                                                                                                           x10::lang::Complex_methods::FMGL(I);
                                                                                                       void x10::lang::Complex_methods::FMGL(I__do_init)() {
                                                                                                           FMGL(I__status) = x10aux::INITIALIZING;
                                                                                                           _I_("Doing static initialisation for field: x10::lang::Complex_methods.I");
                                                                                                           x10::lang::Complex
                                                                                                             __var727__ =
                                                                                                             x10::lang::Complex_methods::_make(0.0,
                                                                                                                                               1.0);
                                                                                                           FMGL(I) = __var727__;
                                                                                                           FMGL(I__status) = x10aux::INITIALIZED;
                                                                                                       }
                                                                                                       void x10::lang::Complex_methods::FMGL(I__init)() {
                                                                                                           if (x10aux::here == 0) {
                                                                                                               x10aux::status __var728__ =
                                                                                                                 (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(I__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
                                                                                                               if (__var728__ != x10aux::UNINITIALIZED) goto WAIT;
                                                                                                               FMGL(I__do_init)();
                                                                                                               x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(I),
                                                                                                                                                                           FMGL(I__id));
                                                                                                               // Notify all waiting threads
                                                                                                               x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           }
                                                                                                           WAIT:
                                                                                                           while (FMGL(I__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
                                                                                                       }
                                                                                                       static void* __init__729 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Complex_methods::FMGL(I__init));
                                                                                                       
                                                                                                       volatile x10aux::status x10::lang::Complex_methods::FMGL(I__status);
                                                                                                       // extract value from a buffer
                                                                                                       x10aux::ref<x10::lang::Object>
                                                                                                         x10::lang::Complex_methods::FMGL(I__deserialize)(x10aux::deserialization_buffer &buf) {
                                                                                                           FMGL(I) =
                                                                                                             buf.read<x10::lang::Complex>();
                                                                                                           x10::lang::Complex_methods::FMGL(I__status) = x10aux::INITIALIZED;
                                                                                                           // Notify all waiting threads
                                                                                                           x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           return x10aux::null;
                                                                                                       }
                                                                                                       const x10aux::serialization_id_t x10::lang::Complex_methods::FMGL(I__id) =
                                                                                                         x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Complex_methods::FMGL(I__deserialize));
                                                                                                       
                                                                                                       
                                                                                                       //#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                                                                       /** The complex number that corresponds to +Inf + +Inf*i */x10::lang::Complex
                                                                                                                                                                    x10::lang::Complex_methods::FMGL(INF);
                                                                                                       void x10::lang::Complex_methods::FMGL(INF__do_init)() {
                                                                                                           FMGL(INF__status) = x10aux::INITIALIZING;
                                                                                                           _I_("Doing static initialisation for field: x10::lang::Complex_methods.INF");
                                                                                                           x10::lang::Complex
                                                                                                             __var730__ =
                                                                                                             x10::lang::Complex_methods::_make(x10aux::double_utils::fromLongBits(0x7ff0000000000000LL),
                                                                                                                                               x10aux::double_utils::fromLongBits(0x7ff0000000000000LL));
                                                                                                           FMGL(INF) = __var730__;
                                                                                                           FMGL(INF__status) = x10aux::INITIALIZED;
                                                                                                       }
                                                                                                       void x10::lang::Complex_methods::FMGL(INF__init)() {
                                                                                                           if (x10aux::here == 0) {
                                                                                                               x10aux::status __var731__ =
                                                                                                                 (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(INF__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
                                                                                                               if (__var731__ != x10aux::UNINITIALIZED) goto WAIT;
                                                                                                               FMGL(INF__do_init)();
                                                                                                               x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(INF),
                                                                                                                                                                           FMGL(INF__id));
                                                                                                               // Notify all waiting threads
                                                                                                               x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           }
                                                                                                           WAIT:
                                                                                                           while (FMGL(INF__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
                                                                                                       }
                                                                                                       static void* __init__732 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Complex_methods::FMGL(INF__init));
                                                                                                       
                                                                                                       volatile x10aux::status x10::lang::Complex_methods::FMGL(INF__status);
                                                                                                       // extract value from a buffer
                                                                                                       x10aux::ref<x10::lang::Object>
                                                                                                         x10::lang::Complex_methods::FMGL(INF__deserialize)(x10aux::deserialization_buffer &buf) {
                                                                                                           FMGL(INF) =
                                                                                                             buf.read<x10::lang::Complex>();
                                                                                                           x10::lang::Complex_methods::FMGL(INF__status) = x10aux::INITIALIZED;
                                                                                                           // Notify all waiting threads
                                                                                                           x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           return x10aux::null;
                                                                                                       }
                                                                                                       const x10aux::serialization_id_t x10::lang::Complex_methods::FMGL(INF__id) =
                                                                                                         x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Complex_methods::FMGL(INF__deserialize));
                                                                                                       
                                                                                                       
                                                                                                       //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10FieldDecl_c
                                                                                                       /** The complex number that corresponds to NaN + NaN*i */x10::lang::Complex
                                                                                                                                                                  x10::lang::Complex_methods::FMGL(NaN);
                                                                                                       void x10::lang::Complex_methods::FMGL(NaN__do_init)() {
                                                                                                           FMGL(NaN__status) = x10aux::INITIALIZING;
                                                                                                           _I_("Doing static initialisation for field: x10::lang::Complex_methods.NaN");
                                                                                                           x10::lang::Complex
                                                                                                             __var733__ =
                                                                                                             x10::lang::Complex_methods::_make(x10aux::double_utils::fromLongBits(0x7ff8000000000000LL),
                                                                                                                                               x10aux::double_utils::fromLongBits(0x7ff8000000000000LL));
                                                                                                           FMGL(NaN) = __var733__;
                                                                                                           FMGL(NaN__status) = x10aux::INITIALIZED;
                                                                                                       }
                                                                                                       void x10::lang::Complex_methods::FMGL(NaN__init)() {
                                                                                                           if (x10aux::here == 0) {
                                                                                                               x10aux::status __var734__ =
                                                                                                                 (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(NaN__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
                                                                                                               if (__var734__ != x10aux::UNINITIALIZED) goto WAIT;
                                                                                                               FMGL(NaN__do_init)();
                                                                                                               x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(NaN),
                                                                                                                                                                           FMGL(NaN__id));
                                                                                                               // Notify all waiting threads
                                                                                                               x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           }
                                                                                                           WAIT:
                                                                                                           while (FMGL(NaN__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
                                                                                                       }
                                                                                                       static void* __init__735 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::lang::Complex_methods::FMGL(NaN__init));
                                                                                                       
                                                                                                       volatile x10aux::status x10::lang::Complex_methods::FMGL(NaN__status);
                                                                                                       // extract value from a buffer
                                                                                                       x10aux::ref<x10::lang::Object>
                                                                                                         x10::lang::Complex_methods::FMGL(NaN__deserialize)(x10aux::deserialization_buffer &buf) {
                                                                                                           FMGL(NaN) =
                                                                                                             buf.read<x10::lang::Complex>();
                                                                                                           x10::lang::Complex_methods::FMGL(NaN__status) = x10aux::INITIALIZED;
                                                                                                           // Notify all waiting threads
                                                                                                           x10aux::StaticInitBroadcastDispatcher::notify();
                                                                                                           return x10aux::null;
                                                                                                       }
                                                                                                       const x10aux::serialization_id_t x10::lang::Complex_methods::FMGL(NaN__id) =
                                                                                                         x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::lang::Complex_methods::FMGL(NaN__deserialize));
                                                                                                       
                                                                                                       

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10ConstructorDecl_c


//#line 51 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 63 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 82 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 89 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 97 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 102 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 112 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10::lang::Complex x10::lang::Complex_methods::__over(
  x10::lang::Complex this_, x10::lang::Complex that) {
    
    //#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(this_) ||
        x10::lang::Complex_methods::isNaN(that))
    {
        
        //#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    
    //#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
    x10_double c = that->FMGL(re);
    
    //#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
    x10_double d = that->FMGL(im);
    
    //#line 119 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(c, 0.0)) &&
        (x10aux::struct_equals(d,
                               0.0))) {
        
        //#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(NaN__get)();
        
    }
    
    //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isInfinite(that) &&
        (!(x10::lang::Complex_methods::isInfinite(this_))))
    {
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::
                 FMGL(ZERO__get)();
        
    }
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if (((x10::lang::Math::abs(d)) <= (x10::lang::Math::abs(
                                         c))))
    {
        
        //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(c,
                                   0.0)))
        {
            
            //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
            return x10::lang::Complex_methods::_make(((this_->
                                                         FMGL(im)) / (d)),
                                                     (((-(this_->
                                                            FMGL(re)))) / (c)));
            
        }
        
        //#line 131 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
        x10_double r =
          ((d) / (c));
        
        //#line 132 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
        x10_double denominator =
          ((c) + (((d) * (r))));
        
        //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((((this_->
                                                       FMGL(re)) + (((this_->
                                                                        FMGL(im)) * (r))))) / (denominator)),
                                                 ((((this_->
                                                       FMGL(im)) - (((this_->
                                                                        FMGL(re)) * (r))))) / (denominator)));
        
    }
    else
    {
        
        //#line 136 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
        if ((x10aux::struct_equals(d,
                                   0.0)))
        {
            
            //#line 137 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
            return x10::lang::Complex_methods::_make(((this_->
                                                         FMGL(re)) / (c)),
                                                     ((this_->
                                                         FMGL(im)) / (c)));
            
        }
        
        //#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
        x10_double r =
          ((c) / (d));
        
        //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
        x10_double denominator =
          ((((c) * (r))) + (d));
        
        //#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Complex_methods::_make(((((((this_->
                                                         FMGL(re)) * (r))) + (this_->
                                                                                FMGL(im)))) / (denominator)),
                                                 ((((((this_->
                                                         FMGL(im)) * (r))) - (this_->
                                                                                FMGL(re)))) / (denominator)));
        
    }
    
}

//#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 154 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 161 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 176 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10_double x10::lang::Complex_methods::abs(
  x10::lang::Complex this_) {
    
    //#line 189 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isNaN(this_))
    {
        
        //#line 190 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10aux::double_utils::fromLongBits(0x7ff8000000000000LL);
        
    }
    
    //#line 193 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if (x10::lang::Complex_methods::isInfinite(this_))
    {
        
        //#line 194 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10aux::double_utils::fromLongBits(0x7ff0000000000000LL);
        
    }
    
    //#line 197 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(this_->FMGL(im),
                               0.0))) {
        
        //#line 198 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Math::abs(this_->
                                      FMGL(re));
        
    } else 
    //#line 199 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(this_->FMGL(re),
                               0.0))) {
        
        //#line 200 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10::lang::Math::abs(this_->
                                      FMGL(im));
        
    } else {
        
        //#line 203 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return x10aux::math_utils::hypot(this_->
                                           FMGL(re),this_->
                                                      FMGL(im));
        
    }
    
}

//#line 210 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 218 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 226 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::lang::Complex_methods::toString(
  x10::lang::Complex this_) {
    
    //#line 227 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
    return ((((((this_->FMGL(re)) + (x10::lang::String::Lit(" + ")))) + (this_->
                                                                           FMGL(im)))) + (x10::lang::String::Lit("i")));
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10_int x10::lang::Complex_methods::hashCode(
  x10::lang::Complex this_) {
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10LocalDecl_c
    x10_int result = ((x10_int)0);
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(re)))));
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": polyglot.ast.Eval_c
    result = ((x10_int) ((((x10_int) ((((x10_int)31)) * (result)))) + (x10aux::hash_code(this_->
                                                                                           FMGL(im)))));
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
    return result;
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Complex_methods::equals(
  x10::lang::Complex this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::lang::Complex>(other))))
    {
        
        //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
    return x10::lang::Complex_methods::equals(this_, 
             x10aux::class_cast<x10::lang::Complex>(other));
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::lang::Complex_methods::_struct_equals(
  x10::lang::Complex this_, x10aux::ref<x10::lang::Any> other) {
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10If_c
    if ((!(x10aux::instanceof<x10::lang::Complex>(other))))
    {
        
        //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
        return false;
        
    }
    
    //#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10Return_c
    return x10::lang::Complex_methods::_struct_equals(this_, 
             x10aux::class_cast<x10::lang::Complex>(other));
    
}

//#line 19 "/home/tux/workspace/x10.runtime/src-x10/x10/lang/Complex.x10": x10.ast.X10MethodDecl_c
void x10::lang::Complex::_serialize(x10::lang::Complex this_, x10aux::serialization_buffer& buf) {
    buf.write(this_->FMGL(re));
    buf.write(this_->FMGL(im));
    
}

void x10::lang::Complex::_deserialize_body(x10aux::deserialization_buffer& buf) {
    FMGL(re) = buf.read<x10_double>();
    FMGL(im) = buf.read<x10_double>();
    
}


x10_boolean x10::lang::Complex::equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::Complex_methods::equals(*this, that);
}
x10_boolean x10::lang::Complex::equals(x10::lang::Complex that) {
    return x10::lang::Complex_methods::equals(*this, that);
}
x10_boolean x10::lang::Complex::_struct_equals(x10aux::ref<x10::lang::Any> that) {
    return x10::lang::Complex_methods::_struct_equals(*this, that);
}
x10_boolean x10::lang::Complex::_struct_equals(x10::lang::Complex that) {
    return x10::lang::Complex_methods::_struct_equals(*this, that);
}
x10aux::ref<x10::lang::String> x10::lang::Complex::toString() {
    return x10::lang::Complex_methods::toString(*this);
}
x10_int x10::lang::Complex::hashCode() {
    return x10::lang::Complex_methods::hashCode(*this);
}
x10aux::RuntimeType x10::lang::Complex::rtt;
void x10::lang::Complex::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[2] = { x10aux::getRTT<x10::lang::Any>(), x10aux::getRTT<x10::lang::Any>()};
    rtt.initStageTwo("x10.lang.Complex", 2, parents, 0, NULL, NULL);
    rtt.containsPtrs = false;
}
