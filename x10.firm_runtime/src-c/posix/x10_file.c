#include "types.h"
#include "x10_string.h"
#include "x10_inputstreamreader.h"
#include "x10_outputstreamwriter.h"

/* vtable for FileReader */
extern x10_vtable _ZTVN3x102io10FileReaderE;
/* avoid linker complaining if X10 vtable is not compiled */
x10_vtable __attribute__((weak)) _ZTVN3x102io10FileReaderE;

/* vtable for FileWriter */
extern x10_vtable _ZTVN3x102io10FileWriterE;
/* avoid linker complaining if X10 vtable is not compiled */
x10_vtable __attribute__((weak)) _ZTVN3x102io10FileWriterE;

/* static File.nativeOpenRead(path: String): FileReader{self!=null} */
x10_inputstreamreader *_ZN3x102io4File14nativeOpenReadEPN3x104lang6StringE(const x10_string *path)
{
	x10_inputstreamreader *stream = X10_ALLOC_OBJECT(x10_inputstreamreader, &_ZTVN3x102io10FileReaderE);
	char *zpath  = cstring_from_x10_string(path);
	FILE *handle = fopen(zpath, "r");
	assert(handle != NULL && "Failed to open file for reading");
	free(zpath);
	stream->in = handle;
	return stream;
}

/* static File.nativeOpenWrite(path: String, append: Boolean): FileWriter{self!=null} */
x10_outputstreamwriter *_ZN3x102io4File15nativeOpenWriteEPN3x104lang6StringEb(const x10_string *path, x10_boolean append)
{
	x10_outputstreamwriter *stream = X10_ALLOC_OBJECT(x10_outputstreamwriter, &_ZTVN3x102io10FileWriterE);
	char *zpath  = cstring_from_x10_string(path);
	FILE *handle = fopen(zpath, append ? "a" : "w");
	assert(handle != NULL && "Failed to open file for writing");
	free(zpath);
	stream->out = handle;
	return stream;
}
