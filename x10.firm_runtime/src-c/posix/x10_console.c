#include "x10.h"
#include "x10_inputstreamreader.h"

/* vtable for InputStreamReader */
extern x10_vtable _ZTVN3x102io17InputStreamReaderE;
/* avoid linker complaining if X10 vtable is not compiled */
x10_vtable __attribute__((weak)) _ZTVN3x102io17InputStreamReaderE;

/* static Console.readIn(): InputStreamReader */
x10_inputstreamreader *_ZN3x102io7Console6realInEv(void)
{
	x10_inputstreamreader *stream = X10_ALLOC_OBJECT(x10_inputstreamreader, &_ZTVN3x102io17InputStreamReaderE);
	stream->in = stdin;
	return stream;
}
