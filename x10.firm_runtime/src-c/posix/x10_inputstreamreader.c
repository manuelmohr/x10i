#include "types.h"
#include "x10_inputstreamreader.h"

/* InputStreamReader.close() */
void _ZN3x102io17InputStreamReader5closeEv(const x10_inputstreamreader *self)
{
	fclose(self->in);
}

/* InputStreamReader.readC(): Int */
x10_int _ZN3x102io17InputStreamReader5readCEv(const x10_inputstreamreader *self)
{
	return fgetc(self->in);
}

/* InputStreamReader.read(Pointer, Int) */
void _ZN3x102io17InputStreamReader4readEPvi(const x10_inputstreamreader *self, x10_pointer buf, x10_int len)
{
	size_t read = fread(buf, len, 1, self->in);
	if (read != 1) {
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
	int err = fseek(self->in, len, SEEK_CUR);
	if (err != 0) {
		abort();
	}
}
