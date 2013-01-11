#include "types.h"
#include "x10_inputstreamreader.h"

/* octopos supports no input, so this is a dummy implementation */

/* InputStreamReader.close() */
void _ZN3x102io17InputStreamReader5closeEv(const x10_inputstreamreader *self)
{
	(void)self;
}

/* InputStreamReader.readC(): Int */
x10_int _ZN3x102io17InputStreamReader5readCEv(const x10_inputstreamreader *self)
{
	(void)self;
	return EOF;
}

/* InputStreamReader.read(Pointer, Int) */
void _ZN3x102io17InputStreamReader4readEPvi(const x10_inputstreamreader *self, x10_pointer buf, x10_int len)
{
	(void)self;
	(void)buf;
	if (len > 0) {
		abort();
	}
}

/* InputStreamReader.available(): Int */
x10_int _ZN3x102io17InputStreamReader9availableEv(const x10_inputstreamreader *self)
{
	(void)self;
	return 0;
}

/* InputStreamReader.skip(Int) */
void _ZN3x102io17InputStreamReader4skipEi(const x10_inputstreamreader *self, x10_int len)
{
	(void)self;
	if (len > 0) {
		abort();
	}
}
