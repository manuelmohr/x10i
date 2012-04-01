#include "x10.h"
#include "x10_outputstreamwriter.h"

/* vtable of OutputStreamWriter */
extern x10_vtable _ZTVN3x102io18OutputStreamWriterE;
/* avoid linker complaining if X10 vtable is not compiled */
x10_vtable __attribute__((weak)) _ZTVN3x102io18OutputStreamWriterE;

/* static Console.realOut(): OutputStreamWriter */
x10_outputstreamwriter *_ZN3x102io7Console7realOutEv(void)
{
	x10_outputstreamwriter *stream = X10_ALLOC_OBJECT(x10_outputstreamwriter, &_ZTVN3x102io18OutputStreamWriterE);
	stream->out = stdout;
	return stream;
}

/* static Console.realErr(): OutputStreamWriter */
x10_outputstreamwriter *_ZN3x102io7Console7realErrEv(void)
{
	x10_outputstreamwriter *stream = X10_ALLOC_OBJECT(x10_outputstreamwriter, &_ZTVN3x102io18OutputStreamWriterE);
	stream->out = stderr;
	return stream;
}
