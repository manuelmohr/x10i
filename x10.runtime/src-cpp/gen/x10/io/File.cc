#include <x10/io/File.h>


#include "x10/io/File.inc"

void x10::io::File::_instance_init() {
    _I_("Doing initialisation for class: x10::io::File");
    
}


//#line 113 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10FieldDecl_c
x10_char x10::io::File::FMGL(SEPARATOR);
void x10::io::File::FMGL(SEPARATOR__do_init)() {
    FMGL(SEPARATOR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::File.SEPARATOR");
    x10_char __var501__ = ((x10_char)'/');
    FMGL(SEPARATOR) = __var501__;
    FMGL(SEPARATOR__status) = x10aux::INITIALIZED;
}
void x10::io::File::FMGL(SEPARATOR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var502__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(SEPARATOR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var502__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(SEPARATOR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(SEPARATOR),
                                                                    FMGL(SEPARATOR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(SEPARATOR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__503 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::File::FMGL(SEPARATOR__init));

volatile x10aux::status x10::io::File::FMGL(SEPARATOR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::File::FMGL(SEPARATOR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(SEPARATOR) = buf.read<x10_char>();
    x10::io::File::FMGL(SEPARATOR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::File::FMGL(SEPARATOR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::File::FMGL(SEPARATOR__deserialize));


//#line 114 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10FieldDecl_c
x10_char x10::io::File::FMGL(PATH_SEPARATOR);
void x10::io::File::FMGL(PATH_SEPARATOR__do_init)() {
    FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZING;
    _I_("Doing static initialisation for field: x10::io::File.PATH_SEPARATOR");
    x10_char __var504__ = ((x10_char)':');
    FMGL(PATH_SEPARATOR) = __var504__;
    FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZED;
}
void x10::io::File::FMGL(PATH_SEPARATOR__init)() {
    if (x10aux::here == 0) {
        x10aux::status __var505__ = (x10aux::status)x10aux::atomic_ops::compareAndSet_32((volatile x10_int*)&FMGL(PATH_SEPARATOR__status), (x10_int)x10aux::UNINITIALIZED, (x10_int)x10aux::INITIALIZING);
        if (__var505__ != x10aux::UNINITIALIZED) goto WAIT;
        FMGL(PATH_SEPARATOR__do_init)();
        x10aux::StaticInitBroadcastDispatcher::broadcastStaticField(FMGL(PATH_SEPARATOR),
                                                                    FMGL(PATH_SEPARATOR__id));
        // Notify all waiting threads
        x10aux::StaticInitBroadcastDispatcher::notify();
    }
    WAIT:
    while (FMGL(PATH_SEPARATOR__status) != x10aux::INITIALIZED) x10aux::StaticInitBroadcastDispatcher::await();
}
static void* __init__506 X10_PRAGMA_UNUSED = x10aux::InitDispatcher::addInitializer(x10::io::File::FMGL(PATH_SEPARATOR__init));

volatile x10aux::status x10::io::File::FMGL(PATH_SEPARATOR__status);
// extract value from a buffer
x10aux::ref<x10::lang::Object> x10::io::File::FMGL(PATH_SEPARATOR__deserialize)(x10aux::deserialization_buffer &buf) {
    FMGL(PATH_SEPARATOR) = buf.read<x10_char>();
    x10::io::File::FMGL(PATH_SEPARATOR__status) = x10aux::INITIALIZED;
    // Notify all waiting threads
    x10aux::StaticInitBroadcastDispatcher::notify();
    return x10aux::null;
}
const x10aux::serialization_id_t x10::io::File::FMGL(PATH_SEPARATOR__id) =
  x10aux::StaticInitBroadcastDispatcher::addRoutine(x10::io::File::FMGL(PATH_SEPARATOR__deserialize));


//#line 116 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10FieldDecl_c

//#line 117 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10FieldDecl_c

//#line 118 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10FieldDecl_c

//#line 120 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10ConstructorDecl_c
void x10::io::File::_constructor(x10aux::ref<x10::lang::String> fullName)
{
    this->x10::lang::Object::_constructor();
    
    //#line 121 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10LocalDecl_c
    x10_int i =
      (fullName)->lastIndexOf(x10::io::File::
                                FMGL(SEPARATOR__get)());
    
    //#line 122 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10If_c
    if ((x10aux::struct_equals(i,
                               ((x10_int)0))))
    {
        
        //#line 123 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(parent) =
          x10aux::class_cast_unchecked<x10aux::ref<x10::io::File> >(x10aux::null);
        
        //#line 124 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(name) =
          fullName;
        
        //#line 125 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(absolute) =
          true;
    }
    else
    
    //#line 127 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10If_c
    if (((i) >= (((x10_int)0))))
    {
        
        //#line 128 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(parent) =
          x10::io::File::_make((fullName)->substring(((x10_int)0), i));
        
        //#line 129 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(name) =
          (fullName)->substring(((x10_int) ((i) + (((x10_int)1)))), (fullName)->length());
        
        //#line 130 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(absolute) =
          (x10aux::struct_equals((fullName)->charAt(((x10_int)0)),
                                 x10::io::File::
                                   FMGL(PATH_SEPARATOR__get)()));
    }
    else
    {
        
        //#line 133 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(parent) =
          x10aux::class_cast_unchecked<x10aux::ref<x10::io::File> >(x10aux::null);
        
        //#line 134 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(name) =
          fullName;
        
        //#line 135 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
        x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
          FMGL(absolute) =
          false;
    }
    
}
x10aux::ref<x10::io::File> x10::io::File::_make(
  x10aux::ref<x10::lang::String> fullName)
{
    x10aux::ref<x10::io::File> this_ = new (memset(x10aux::alloc<x10::io::File>(), 0, sizeof(x10::io::File))) x10::io::File();
    this_->_constructor(fullName);
    return this_;
}



//#line 139 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10ConstructorDecl_c
void x10::io::File::_constructor(x10aux::ref<x10::io::File> p,
                                 x10aux::ref<x10::lang::String> n)
{
    this->x10::lang::Object::_constructor();
    
    //#line 140 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Assert_c
    #ifndef NO_ASSERTIONS
    if (x10aux::x10__assertions_enabled)
        x10aux::x10__assert((!x10aux::struct_equals(p,
                                                    x10aux::null)));
    #endif//NO_ASSERTIONS
    
    //#line 141 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
      FMGL(parent) =
      p;
    
    //#line 142 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
      FMGL(name) =
      n;
    
    //#line 143 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Eval_c
    x10aux::placeCheck(((x10aux::ref<x10::io::File>)this))->
      FMGL(absolute) =
      (!x10aux::struct_equals(p,
                              x10aux::null)) &&
    x10aux::placeCheck(x10aux::nullCheck(p))->
      FMGL(absolute);
    
}
x10aux::ref<x10::io::File> x10::io::File::_make(
  x10aux::ref<x10::io::File> p,
  x10aux::ref<x10::lang::String> n)
{
    x10aux::ref<x10::io::File> this_ = new (memset(x10aux::alloc<x10::io::File>(), 0, sizeof(x10::io::File))) x10::io::File();
    this_->_constructor(p,
    n);
    return this_;
}



//#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10aux::ref<x10::lang::String> > >
  x10::io::File::lines(
  ) {
    
    //#line 148 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->openRead()->lines();
    
}

//#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10_char> > x10::io::File::chars(
  ) {
    
    //#line 149 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->openRead()->chars();
    
}

//#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::ReaderIterator<x10_byte> > x10::io::File::bytes(
  ) {
    
    //#line 150 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->openRead()->bytes();
    
}

//#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::FileReader> x10::io::File::openRead(
  ) {
    
    //#line 151 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::FileReader::_make(((x10aux::ref<x10::io::File>)this));
    
}

//#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::FileWriter> x10::io::File::openWrite(
  ) {
    
    //#line 152 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::FileWriter::_make(((x10aux::ref<x10::io::File>)this));
    
}

//#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::Printer> x10::io::File::printer() {
    
    //#line 153 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::Printer::_make(x10aux::class_cast_unchecked<x10aux::ref<x10::io::Writer> >(((x10aux::ref<x10::io::File>)this)->openWrite()));
    
}

//#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::io::File::getName() {
    
    //#line 155 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->FMGL(name);
    
}

//#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::File> x10::io::File::getParentFile() {
    
    //#line 156 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->FMGL(parent);
    
}

//#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::lang::String> x10::io::File::getPath() {
    
    //#line 157 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (x10aux::struct_equals(((x10aux::ref<x10::io::File>)this)->
                                    FMGL(parent), x10aux::null))
      ? (x10aux::ref<x10::lang::String>)(((x10aux::ref<x10::io::File>)this)->
                                           FMGL(name))
      : (x10aux::ref<x10::lang::String>)((((((x10aux::nullCheck(((x10aux::ref<x10::io::File>)this)->
                                                                  FMGL(parent))->getPath()) + (x10::io::File::
                                                                                                 FMGL(SEPARATOR__get)()))) + (((x10aux::ref<x10::io::File>)this)->
                                                                                                                                FMGL(name)))));
    
}

//#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isAbsolute() {
    
    //#line 158 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return ((x10aux::ref<x10::io::File>)this)->
             FMGL(absolute);
    
}

//#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::File__NativeFile> x10::io::File::nativeFile(
  ) {
    
    //#line 160 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::File__NativeFile::_make(((x10aux::ref<x10::io::File>)this)->getPath());
    
}

//#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::File> x10::io::File::getAbsoluteFile(
  ) {
    
    //#line 162 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::File::_make((((x10aux::ref<x10::io::File>)this)->nativeFile())->getAbsolutePath());
    
}

//#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10aux::ref<x10::io::File> x10::io::File::getCanonicalFile(
  ) {
    
    //#line 163 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return x10::io::File::_make((((x10aux::ref<x10::io::File>)this)->nativeFile())->getCanonicalPath());
    
}

//#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::exists() {
    
    //#line 168 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->exists();
    
}

//#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isSymbolicLink(
  ) {
    
    //#line 171 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isAlias() {
    
    //#line 172 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::hardLinkCount(
  ) {
    
    //#line 173 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::File::inodeNumber() {
    
    //#line 174 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::File::permissions() {
    
    //#line 175 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isDirectory() {
    
    //#line 177 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->isDirectory();
    
}

//#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isFile() {
    
    //#line 178 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->isFile();
    
}

//#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::isHidden() {
    
    //#line 179 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->isHidden();
    
}

//#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::File::lastModified() {
    
    //#line 181 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->lastModified();
    
}

//#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::setLastModified(
  x10_long t) {
    
    //#line 182 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->setLastModified(t);
    
}

//#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_long x10::io::File::size() {
    
    //#line 183 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->length();
    
}

//#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_int x10::io::File::compareTo(x10aux::ref<x10::io::File> id__74) {
    
    //#line 185 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": polyglot.ast.Throw_c
    x10aux::throwException(x10aux::nullCheck(x10::lang::RuntimeException::_make(x10::lang::String::Lit("Incomplete method."))));
}

//#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::canRead() {
    
    //#line 187 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->canRead();
    
}

//#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10MethodDecl_c
x10_boolean x10::io::File::canWrite() {
    
    //#line 188 "/home/tux/workspace/x10.runtime/src-x10/x10/io/File.x10": x10.ast.X10Return_c
    return (((x10aux::ref<x10::io::File>)this)->nativeFile())->canWrite();
    
}
const x10aux::serialization_id_t x10::io::File::_serialization_id = 
    x10aux::DeserializationDispatcher::addDeserializer(x10::io::File::_deserializer<x10::lang::Object>);

void x10::io::File::_serialize_body(x10aux::serialization_buffer& buf) {
    x10::lang::Object::_serialize_body(buf);
    
}

void x10::io::File::_deserialize_body(x10aux::deserialization_buffer& buf) {
    x10::lang::Object::_deserialize_body(buf);
    
}

x10aux::RuntimeType x10::io::File::rtt;
void x10::io::File::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const x10aux::RuntimeType* parents[1] = { x10aux::getRTT<x10::lang::Object>()};
    rtt.initStageTwo("x10.io.File", 1, parents, 0, NULL, NULL);
}
