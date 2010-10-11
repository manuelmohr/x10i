#include <x10/io/Console.h>


#include "x10/io/Console.inc"

void x10::io::Console::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Console");
    
}


//#line 17 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10MethodDecl_c

//#line 21 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10MethodDecl_c

//#line 25 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10MethodDecl_c

//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::io::Printer> x10::io::Console::FMGL(OUT);
void x10::io::Console::FMGL(OUT__do_init)() {
    FMGL(OUT__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Console.OUT");
    x10aux::ref<x10::io::Printer> __var470__ = x10::io::Printer::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Writer> >(x10::io::OutputStreamWriter::_make(x10::io::OutputStreamWriter__OutputStream::STANDARD_OUT())));
    FMGL(OUT) = __var470__;
    FMGL(OUT__status) = x10aux::INITIALIZED;
}
void x10::io::Console::FMGL(OUT__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var471__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(OUT__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var471__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(OUT__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(OUT),
                                                                    FMGL(OUT__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(OUT__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__472 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Console::FMGL(OUT__init));

volatile x10aux::status x10::io::Console::FMGL(OUT__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::Console::FMGL(OUT__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(OUT) = buf.read<x10aux::ref<x10::io::Printer> >();
    x10::io::Console::FMGL(OUT__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Console::FMGL(OUT__id) = x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Console::FMGL(OUT__deserialize));


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::io::Printer> x10::io::Console::FMGL(ERR);
void x10::io::Console::FMGL(ERR__do_init)() {
    FMGL(ERR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Console.ERR");
    x10aux::ref<x10::io::Printer> __var473__ = x10::io::Printer::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Writer> >(x10::io::OutputStreamWriter::_make(x10::io::OutputStreamWriter__OutputStream::STANDARD_ERR())));
    FMGL(ERR) = __var473__;
    FMGL(ERR__status) = x10aux::INITIALIZED;
}
void x10::io::Console::FMGL(ERR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var474__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(ERR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var474__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(ERR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(ERR),
                                                                    FMGL(ERR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(ERR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__475 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Console::FMGL(ERR__init));

volatile x10aux::status x10::io::Console::FMGL(ERR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::Console::FMGL(ERR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(ERR) = buf.read<x10aux::ref<x10::io::Printer> >();
    x10::io::Console::FMGL(ERR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Console::FMGL(ERR__id) = x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Console::FMGL(ERR__deserialize));


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::io::Reader> x10::io::Console::FMGL(IN);
void x10::io::Console::FMGL(IN__do_init)() {
    FMGL(IN__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Console.IN");
    x10aux::ref<x10::io::Reader> __var476__ = x10aux::class_cast_unchecked<x10aux::ref<x10::io::Reader> >(x10::io::InputStreamReader::_make(x10::io::InputStreamReader__InputStream::STANDARD_IN()));
    FMGL(IN) = __var476__;
    FMGL(IN__status) = x10aux::INITIALIZED;
}
void x10::io::Console::FMGL(IN__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var477__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(IN__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var477__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(IN__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(IN),
                                                                    FMGL(IN__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(IN__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__478 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Console::FMGL(IN__init));

volatile x10aux::status x10::io::Console::FMGL(IN__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::Console::FMGL(IN__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(IN) = buf.read<x10aux::ref<x10::io::Reader> >();
    x10::io::Console::FMGL(IN__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Console::FMGL(IN__id) = x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Console::FMGL(IN__deserialize));


//#line 16 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Console.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Console::_constructor() {
    this->x10::lang::Object::_constructor();
    
}
x10aux::ref<x10::io::Console> x10::io::Console::_make() {
    x10aux::ref<x10::io::Console> this_ = new (memset(x10aux::alloc<x10::io::Console>(), 0, sizeof(x10::io::Console))) x10::io::Console();
    this_->_constructor();
    return this_;
}


const x10aux::serialization_id_t x10::io::Console::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Console::_deserializer<x10::lang::Object>);

void x10::io::Console::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::Console::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Console::rtt;
void x10::io::Console::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.io.Console", 1, parents, 0, NULL, NULL);
}
