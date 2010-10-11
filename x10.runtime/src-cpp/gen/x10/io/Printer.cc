#include <x10/io/Printer.h>


#include "x10/io/Printer.inc"

void x10::io::Printer::_instance_init() {
    _I_("Doing initialisation for class: x10::io::Printer");
    
}


//#line 31 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10ConstructorDecl_c
void x10::io::Printer::_constructor(x10aux::ref<x10::io::Writer> w) {
    this->x10::io::FilterWriter::_constructor(w);
    
}
x10aux::ref<x10::io::Printer> x10::io::Printer::_make(x10aux::ref<x10::io::Writer> w)
{
    x10aux::ref<x10::io::Printer> this_ = new (memset(x10aux::alloc<x10::io::Printer>(), 0, sizeof(x10::io::Printer))) x10::io::Printer();
    this_->_constructor(w);
    return this_;
}



//#line 33 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10FieldDecl_c
x10_char x10::io::Printer::FMGL(NEWLINE);
void x10::io::Printer::FMGL(NEWLINE__do_init)() {
    FMGL(NEWLINE__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::Printer.NEWLINE");
    x10_char __var608__ = ((x10_char)'\n');
    FMGL(NEWLINE) = __var608__;
    FMGL(NEWLINE__status) = x10aux::INITIALIZED;
}
void x10::io::Printer::FMGL(NEWLINE__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var609__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(NEWLINE__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var609__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(NEWLINE__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(NEWLINE),
                                                                    FMGL(NEWLINE__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(NEWLINE__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__610 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::Printer::FMGL(NEWLINE__init));

volatile x10aux::status x10::io::Printer::FMGL(NEWLINE__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::Printer::FMGL(NEWLINE__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(NEWLINE) = buf.read<x10_char>();
    x10::io::Printer::FMGL(NEWLINE__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::Printer::FMGL(NEWLINE__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::Printer::FMGL(NEWLINE__deserialize));


//#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::println() {
    {
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::io::Printer>)this)->x10::io::Printer::print(
          x10aux::class_cast_unchecked<x10aux::ref<x10::lang::Any> >(x10::io::Printer::
                                                                       FMGL(NEWLINE__get)()));
        
        //#line 35 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10Return_c
        return;
    }
}

//#line 37 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::println(x10aux::ref<x10::lang::Any> o) {
    
    //#line 38 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->print(
      (x10aux::struct_equals(o,
                             x10aux::null))
        ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("null\n"))
        : (x10aux::ref<x10::lang::String>)(((x10aux::to_string(o)) + (x10::lang::String::Lit("\n")))));
}

//#line 40 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::print(x10aux::ref<x10::lang::Any> o) {
    
    //#line 41 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->print(
      (x10aux::struct_equals(o,
                             x10aux::null))
        ? (x10aux::ref<x10::lang::String>)(x10::lang::String::Lit("null"))
        : (x10aux::ref<x10::lang::String>)(x10aux::to_string(o)));
}

//#line 44 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::print(x10aux::ref<x10::lang::String> s) {
    
    //#line 45 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Try_c
    try {
        
        //#line 46 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10LocalDecl_c
        x10aux::ref<x10::lang::ValRail<x10_byte > > b =
          (s)->bytes();
        
        //#line 47 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
        ((x10aux::ref<x10::io::Printer>)this)->write(
          b,
          ((x10_int)0),
          x10aux::nullCheck(b)->
            FMGL(length));
    }
    catch (x10aux::__ref& __ref__615) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__615 = (x10aux::ref<x10::lang::Throwable>&)__ref__615;
        if (x10aux::instanceof<x10aux::ref<x10::io::IOException> >(__exc__ref__615)) {
            x10aux::ref<x10::io::IOException> e =
              static_cast<x10aux::ref<x10::io::IOException> >(__exc__ref__615);
            {
                
                //#line 50 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Throw_c
                x10aux::throwException(x10aux::nullCheck(x10::io::IORuntimeException::_make((e)->getMessage())));
            }
        } else
        throw;
    }
}

//#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt) {
    
    //#line 54 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(0));
}

//#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1) {
    
    //#line 55 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(1,(o1)));
}

//#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1,
                              x10aux::ref<x10::lang::Any> o2) {
    
    //#line 56 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(2,(o1),(o2)));
}

//#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1,
                              x10aux::ref<x10::lang::Any> o2,
                              x10aux::ref<x10::lang::Any> o3) {
    
    //#line 57 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(3,(o1),(o2),(o3)));
}

//#line 58 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1,
                              x10aux::ref<x10::lang::Any> o2,
                              x10aux::ref<x10::lang::Any> o3,
                              x10aux::ref<x10::lang::Any> o4) {
    
    //#line 59 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(4,(o1),(o2),(o3),(o4)));
}

//#line 61 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1,
                              x10aux::ref<x10::lang::Any> o2,
                              x10aux::ref<x10::lang::Any> o3,
                              x10aux::ref<x10::lang::Any> o4,
                              x10aux::ref<x10::lang::Any> o5) {
    
    //#line 62 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(5,(o1),(o2),(o3),(o4),(o5)));
}

//#line 64 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Any> o1,
                              x10aux::ref<x10::lang::Any> o2,
                              x10aux::ref<x10::lang::Any> o3,
                              x10aux::ref<x10::lang::Any> o4,
                              x10aux::ref<x10::lang::Any> o5,
                              x10aux::ref<x10::lang::Any> o6) {
    
    //#line 65 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->printf(
      fmt,
      (x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >)x10aux::alloc_rail<x10aux::ref<x10::lang::Any>,
      x10::lang::ValRail<x10aux::ref<x10::lang::Any> > >(6,(o1),(o2),(o3),(o4),(o5),(o6)));
}

//#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::Rail<x10aux::ref<x10::lang::Any> > > args) {
    
    //#line 67 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->print(
      x10::lang::String::format(fmt,x10::lang::ValRail<x10aux::ref<x10::lang::Any> >::make(args)));
}

//#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::printf(x10aux::ref<x10::lang::String> fmt,
                              x10aux::ref<x10::lang::ValRail<x10aux::ref<x10::lang::Any> > > args) {
    
    //#line 68 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
    ((x10aux::ref<x10::io::Printer>)this)->print(
      x10::lang::String::format(fmt,args));
}

//#line 70 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::flush() {
    
    //#line 71 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Try_c
    try {
        
        //#line 72 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
        x10::io::FilterWriter::flush();
    }
    catch (x10aux::__ref& __ref__633) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__633 = (x10aux::ref<x10::lang::Throwable>&)__ref__633;
        if (x10aux::instanceof<x10aux::ref<x10::io::IOException> >(__exc__ref__633)) {
            x10aux::ref<x10::io::IOException> id__87 =
              static_cast<x10aux::ref<x10::io::IOException> >(__exc__ref__633);
            {
             
            }
        } else
        throw;
    }
}

//#line 77 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": x10.ast.X10MethodDecl_c
void x10::io::Printer::close() {
    
    //#line 78 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Try_c
    try {
        
        //#line 79 "/home/tux/workspace/x10.runtime/src-x10/x10/io/Printer.x10": polyglot.ast.Eval_c
        x10::io::FilterWriter::close();
    }
    catch (x10aux::__ref& __ref__635) {
        x10aux::ref<x10::lang::Throwable>& __exc__ref__635 = (x10aux::ref<x10::lang::Throwable>&)__ref__635;
        if (x10aux::instanceof<x10aux::ref<x10::io::IOException> >(__exc__ref__635)) {
            x10aux::ref<x10::io::IOException> id__88 =
              static_cast<x10aux::ref<x10::io::IOException> >(__exc__ref__635);
            {
             
            }
        } else
        throw;
    }
}
const x10aux::serialization_id_t x10::io::Printer::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::Printer::_deserializer<x10::lang::Object>);

void x10::io::Printer::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::io::FilterWriter::_serialize_body(buf);
    
}

void x10::io::Printer::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::io::FilterWriter::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::Printer::rtt;
void x10::io::Printer::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::io::FilterWriter>()};
    rtt.initStageTwo("x10.io.Printer", 1, parents, 0, NULL, NULL);
}
