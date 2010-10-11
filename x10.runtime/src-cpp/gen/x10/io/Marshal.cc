#include <x10/io/Marshal.h>

x10aux::RuntimeType x10::io::Marshal<void>::rtt;
x10aux::ref<x10::io::Marshal__BooleanMarshal> x10::io::Marshal<void>::FMGL(BOOLEAN);
void x10::io::Marshal<void>::FMGL(BOOLEAN__do_init)() {
    FMGL(BOOLEAN__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.BOOLEAN");
    x10aux::ref<x10::io::Marshal__BooleanMarshal> __var555__ = x10::io::Marshal__BooleanMarshal::_make();
    FMGL(BOOLEAN) = __var555__;
    FMGL(BOOLEAN__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(BOOLEAN__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var556__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(BOOLEAN__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var556__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(BOOLEAN__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(BOOLEAN),
                                                                    FMGL(BOOLEAN__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(BOOLEAN__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__557 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(BOOLEAN__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(BOOLEAN__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::Marshal<void>::FMGL(BOOLEAN__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(BOOLEAN) = buf.read<x10aux::ref<x10::io::Marshal__BooleanMarshal> >();
    x10::io::Marshal<void>::FMGL(BOOLEAN__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(BOOLEAN__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(BOOLEAN__deserialize));
x10aux::ref<x10::io::Marshal__ByteMarshal>
  x10::io::Marshal<void>::FMGL(BYTE);
void x10::io::Marshal<void>::FMGL(BYTE__do_init)() {
    FMGL(BYTE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.BYTE");
    x10aux::ref<x10::io::Marshal__ByteMarshal>
      __var558__ =
      x10::io::Marshal__ByteMarshal::_make();
    FMGL(BYTE) = __var558__;
    FMGL(BYTE__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(BYTE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var559__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(BYTE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var559__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(BYTE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(BYTE),
                                                                    FMGL(BYTE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(BYTE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__560 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(BYTE__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(BYTE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(BYTE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(BYTE) =
      buf.read<x10aux::ref<x10::io::Marshal__ByteMarshal> >();
    x10::io::Marshal<void>::FMGL(BYTE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(BYTE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(BYTE__deserialize));
x10aux::ref<x10::io::Marshal__CharMarshal>
  x10::io::Marshal<void>::FMGL(CHAR);
void x10::io::Marshal<void>::FMGL(CHAR__do_init)() {
    FMGL(CHAR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.CHAR");
    x10aux::ref<x10::io::Marshal__CharMarshal>
      __var561__ =
      x10::io::Marshal__CharMarshal::_make();
    FMGL(CHAR) = __var561__;
    FMGL(CHAR__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(CHAR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var562__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(CHAR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var562__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(CHAR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(CHAR),
                                                                    FMGL(CHAR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(CHAR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__563 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(CHAR__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(CHAR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(CHAR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(CHAR) =
      buf.read<x10aux::ref<x10::io::Marshal__CharMarshal> >();
    x10::io::Marshal<void>::FMGL(CHAR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(CHAR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(CHAR__deserialize));
x10aux::ref<x10::io::Marshal__ShortMarshal>
  x10::io::Marshal<void>::FMGL(SHORT);
void x10::io::Marshal<void>::FMGL(SHORT__do_init)() {
    FMGL(SHORT__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.SHORT");
    x10aux::ref<x10::io::Marshal__ShortMarshal>
      __var564__ =
      x10::io::Marshal__ShortMarshal::_make();
    FMGL(SHORT) = __var564__;
    FMGL(SHORT__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(SHORT__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var565__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(SHORT__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var565__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(SHORT__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(SHORT),
                                                                    FMGL(SHORT__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(SHORT__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__566 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(SHORT__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(SHORT__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(SHORT__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(SHORT) =
      buf.read<x10aux::ref<x10::io::Marshal__ShortMarshal> >();
    x10::io::Marshal<void>::FMGL(SHORT__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(SHORT__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(SHORT__deserialize));
x10aux::ref<x10::io::Marshal__IntMarshal>
  x10::io::Marshal<void>::FMGL(INT);
void x10::io::Marshal<void>::FMGL(INT__do_init)() {
    FMGL(INT__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.INT");
    x10aux::ref<x10::io::Marshal__IntMarshal>
      __var567__ =
      x10::io::Marshal__IntMarshal::_make();
    FMGL(INT) = __var567__;
    FMGL(INT__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(INT__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var568__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(INT__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var568__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(INT__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(INT),
                                                                    FMGL(INT__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(INT__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__569 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(INT__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(INT__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(INT__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(INT) =
      buf.read<x10aux::ref<x10::io::Marshal__IntMarshal> >();
    x10::io::Marshal<void>::FMGL(INT__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(INT__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(INT__deserialize));
x10aux::ref<x10::io::Marshal__LongMarshal>
  x10::io::Marshal<void>::FMGL(LONG);
void x10::io::Marshal<void>::FMGL(LONG__do_init)() {
    FMGL(LONG__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.LONG");
    x10aux::ref<x10::io::Marshal__LongMarshal>
      __var570__ =
      x10::io::Marshal__LongMarshal::_make();
    FMGL(LONG) = __var570__;
    FMGL(LONG__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(LONG__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var571__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(LONG__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var571__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(LONG__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(LONG),
                                                                    FMGL(LONG__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(LONG__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__572 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(LONG__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(LONG__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(LONG__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(LONG) =
      buf.read<x10aux::ref<x10::io::Marshal__LongMarshal> >();
    x10::io::Marshal<void>::FMGL(LONG__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(LONG__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(LONG__deserialize));
x10aux::ref<x10::io::Marshal__FloatMarshal>
  x10::io::Marshal<void>::FMGL(FLOAT);
void x10::io::Marshal<void>::FMGL(FLOAT__do_init)() {
    FMGL(FLOAT__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.FLOAT");
    x10aux::ref<x10::io::Marshal__FloatMarshal>
      __var573__ =
      x10::io::Marshal__FloatMarshal::_make();
    FMGL(FLOAT) = __var573__;
    FMGL(FLOAT__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(FLOAT__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var574__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(FLOAT__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var574__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(FLOAT__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(FLOAT),
                                                                    FMGL(FLOAT__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(FLOAT__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__575 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(FLOAT__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(FLOAT__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(FLOAT__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(FLOAT) =
      buf.read<x10aux::ref<x10::io::Marshal__FloatMarshal> >();
    x10::io::Marshal<void>::FMGL(FLOAT__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(FLOAT__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(FLOAT__deserialize));
x10aux::ref<x10::io::Marshal__DoubleMarshal>
  x10::io::Marshal<void>::FMGL(DOUBLE);
void x10::io::Marshal<void>::FMGL(DOUBLE__do_init)() {
    FMGL(DOUBLE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.DOUBLE");
    x10aux::ref<x10::io::Marshal__DoubleMarshal>
      __var576__ =
      x10::io::Marshal__DoubleMarshal::_make();
    FMGL(DOUBLE) = __var576__;
    FMGL(DOUBLE__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(DOUBLE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var577__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(DOUBLE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var577__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(DOUBLE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(DOUBLE),
                                                                    FMGL(DOUBLE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(DOUBLE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__578 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(DOUBLE__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(DOUBLE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(DOUBLE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(DOUBLE) =
      buf.read<x10aux::ref<x10::io::Marshal__DoubleMarshal> >();
    x10::io::Marshal<void>::FMGL(DOUBLE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(DOUBLE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(DOUBLE__deserialize));
x10aux::ref<x10::io::Marshal__LineMarshal>
  x10::io::Marshal<void>::FMGL(LINE);
void x10::io::Marshal<void>::FMGL(LINE__do_init)() {
    FMGL(LINE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Marshal<void>.LINE");
    x10aux::ref<x10::io::Marshal__LineMarshal>
      __var579__ =
      x10::io::Marshal__LineMarshal::_make();
    FMGL(LINE) = __var579__;
    FMGL(LINE__status) = x10aux::INITIALIZED;
}
void x10::io::Marshal<void>::FMGL(LINE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var580__ =
          (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(LINE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var580__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(LINE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(LINE),
                                                                    FMGL(LINE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(LINE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__581 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Marshal<void>::FMGL(LINE__init));

volatile x10aux::status x10::io::Marshal<void>::FMGL(LINE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object>
  x10::io::Marshal<void>::FMGL(LINE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(LINE) =
      buf.read<x10aux::ref<x10::io::Marshal__LineMarshal> >();
    x10::io::Marshal<void>::FMGL(LINE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Marshal<void>::FMGL(LINE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Marshal<void>::FMGL(LINE__deserialize));

