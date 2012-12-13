#include "x10.h"
#include "x10_outputstreamwriter.h"

/* OutputStreamWriter.close() */
void _ZN3x102io18OutputStreamWriter5closeEv(const x10_outputstreamwriter *self)
{
	fclose(self->out);
}

/* OutputStreamWriter.flush() */
void _ZN3x102io18OutputStreamWriter5flushEv(const x10_outputstreamwriter *self)
{
	fflush(self->out);
}

/* OutputStreamWriter.write(v: Int) */
void _ZN3x102io18OutputStreamWriter5writeEi(const x10_outputstreamwriter *self,
                                            x10_int c)
{
	fputc(c, self->out);
}

/* OutputStreamWriter.write(p: Pointer, len: Int) */
void _ZN3x102io18OutputStreamWriter5writeEPvi(const x10_outputstreamwriter *self,
                                              x10_pointer p, x10_int len)
{
	size_t written = fwrite(p, len, 1, self->out);
#ifndef __OCTOPOS__
	if (written != 1) {
		abort();
	}
#else
	(void)written;
#endif
}
