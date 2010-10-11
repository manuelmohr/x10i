#include <x10/io/FileSystem.h>


#include "x10/io/FileSystem.inc"

void x10::io::FileSystem::_instance_init() {
    _I_("Doing initialisation for class: x10::io::FileSystem");
    
}


//#line 29 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10FieldDecl_c
x10_char x10::io::FileSystem::FMGL(SEPARATOR_CHAR);
void x10::io::FileSystem::FMGL(SEPARATOR_CHAR__do_init)() {
    FMGL(SEPARATOR_CHAR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::FileSystem.SEPARATOR_CHAR");
    x10_char __var479__ = ((x10_char)'/');
    FMGL(SEPARATOR_CHAR) = __var479__;
    FMGL(SEPARATOR_CHAR__status) = x10aux::INITIALIZED;
}
void x10::io::FileSystem::FMGL(SEPARATOR_CHAR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var480__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(SEPARATOR_CHAR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var480__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(SEPARATOR_CHAR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(SEPARATOR_CHAR),
                                                                    FMGL(SEPARATOR_CHAR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(SEPARATOR_CHAR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__481 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::FileSystem::FMGL(SEPARATOR_CHAR__init));

volatile x10aux::status x10::io::FileSystem::FMGL(SEPARATOR_CHAR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::FileSystem::FMGL(SEPARATOR_CHAR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(SEPARATOR_CHAR) = buf.read<x10_char>();
    x10::io::FileSystem::FMGL(SEPARATOR_CHAR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::FileSystem::FMGL(SEPARATOR_CHAR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::FileSystem::FMGL(SEPARATOR_CHAR__deserialize));


//#line 30 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::lang::String> x10::io::FileSystem::FMGL(SEPARATOR);
void x10::io::FileSystem::FMGL(SEPARATOR__do_init)() {
    FMGL(SEPARATOR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::FileSystem.SEPARATOR");
    x10aux::ref<x10::lang::String> __var482__ = x10::lang::String::Lit("/");
    FMGL(SEPARATOR) = __var482__;
    FMGL(SEPARATOR__status) = x10aux::INITIALIZED;
}
void x10::io::FileSystem::FMGL(SEPARATOR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var483__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(SEPARATOR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var483__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(SEPARATOR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(SEPARATOR),
                                                                    FMGL(SEPARATOR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(SEPARATOR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__484 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::FileSystem::FMGL(SEPARATOR__init));

volatile x10aux::status x10::io::FileSystem::FMGL(SEPARATOR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::FileSystem::FMGL(SEPARATOR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(SEPARATOR) = buf.read<x10aux::ref<x10::lang::String> >();
    x10::io::FileSystem::FMGL(SEPARATOR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::FileSystem::FMGL(SEPARATOR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::FileSystem::FMGL(SEPARATOR__deserialize));


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10FieldDecl_c
x10_char x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR);
void x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__do_init)() {
    FMGL(PATH_SEPARATOR_CHAR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::FileSystem.PATH_SEPARATOR_CHAR");
    x10_char __var485__ = ((x10_char)':');
    FMGL(PATH_SEPARATOR_CHAR) = __var485__;
    FMGL(PATH_SEPARATOR_CHAR__status) = x10aux::INITIALIZED;
}
void x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var486__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(PATH_SEPARATOR_CHAR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var486__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(PATH_SEPARATOR_CHAR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(PATH_SEPARATOR_CHAR),
                                                                    FMGL(PATH_SEPARATOR_CHAR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(PATH_SEPARATOR_CHAR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__487 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__init));

volatile x10aux::status x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(PATH_SEPARATOR_CHAR) = buf.read<x10_char>();
    x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::FileSystem::FMGL(PATH_SEPARATOR_CHAR__deserialize));


//#line 32 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10FieldDecl_c
x10aux::ref<x10::lang::String> x10::io::FileSystem::FMGL(PATH_SEPARATOR);
void x10::io::FileSystem::FMGL(PATH_SEPARATOR__do_init)() {
    FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::FileSystem.PATH_SEPARATOR");
    x10aux::ref<x10::lang::String> __var488__ =
      x10::lang::String::Lit(":");
    FMGL(PATH_SEPARATOR) = __var488__;
    FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZED;
}
void x10::io::FileSystem::FMGL(PATH_SEPARATOR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var489__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(PATH_SEPARATOR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var489__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(PATH_SEPARATOR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(PATH_SEPARATOR),
                                                                    FMGL(PATH_SEPARATOR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(PATH_SEPARATOR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__490 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::FileSystem::FMGL(PATH_SEPARATOR__init));

volatile x10aux::status x10::io::FileSystem::FMGL(PATH_SEPARATOR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::FileSystem::FMGL(PATH_SEPARATOR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(PATH_SEPARATOR) = buf.read<x10aux::ref<x10::lang::String> >();
    x10::io::FileSystem::FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::FileSystem::FMGL(PATH_SEPARATOR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::FileSystem::FMGL(PATH_SEPARATOR__deserialize));


//#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
void x10::io::FileSystem::_kwd__delete(x10aux::ref<x10::io::File> id__61) {
    
    //#line 34 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
void x10::io::FileSystem::deleteOnExit(x10aux::ref<x10::io::File> id__62) {
    
    //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
void x10::io::FileSystem::rename(x10aux::ref<x10::io::File> f,
                                 x10aux::ref<x10::io::File> t) {
    
    //#line 36 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
void x10::io::FileSystem::mkdir(x10aux::ref<x10::io::File> id__63) {
    
    //#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
void x10::io::FileSystem::mkdirs(x10aux::ref<x10::io::File> id__64) {
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::FileSystem::exists(x10aux::ref<x10::io::File> id__65) {
    
    //#line 39 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::FileSystem::size(x10aux::ref<x10::io::File> id__66) {
    
    //#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::io::File> > >
  x10::io::FileSystem::listFiles(
  x10aux::ref<x10::io::File> id__67) {
    
    //#line 42 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::io::File> > >
  x10::io::FileSystem::listFiles(
  x10aux::ref<x10::io::File> id__68,
  x10aux::ref<x10::lang::Fun_0_1<x10aux::ref<x10::io::File>, x10_boolean> > id__70) {
    
    //#line 43 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 28 "/home/tux/workspace/x10.runtime/src-x10/x10/io/FileSystem.x10": x10.ast.X10ConstructorDecl_c
void x10::io::FileSystem::_constructor() {
    this->x10::lang::Object::_constructor();
    
}

void x10::io::FileSystem::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::FileSystem::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::FileSystem::rtt;
void x10::io::FileSystem::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.io.FileSystem", 1, parents, 0, NULL, NULL);
}
