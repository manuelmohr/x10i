#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <wchar.h>

void _ZN9SimpleLib5printEJvx(int64_t v)
{
	printf("%"PRIi64"\n", v);
}
void _ZN9SimpleLib5printEJvy(uint64_t v)
{
	printf("%"PRIu64"\n", v);
}
void _ZN9SimpleLib5printEJvi(int32_t v)
{
	printf("%"PRIi32"\n", v);
}
void _ZN9SimpleLib5printEJvj(uint32_t v)
{
	printf("%"PRIu32"\n", v);
}
void _ZN9SimpleLib5printEJvs(int16_t v)
{
	printf("%"PRIi16"\n", v);
}
void _ZN9SimpleLib5printEJvt(uint16_t v)
{
	printf("%"PRIu16"\n", v);
}
void _ZN9SimpleLib5printEJva(int8_t v)
{
	printf("%"PRIi8"\n", v);
}
void _ZN9SimpleLib5printEJvh(uint8_t v)
{
	printf("%"PRIu8"\n", v);
}
void _ZN9SimpleLib5printEJvDi(wchar_t v)
{
	printf("%lc\n", v);
}
void _ZN9SimpleLib5printEJvf(float v)
{
	printf("%f\n", v);
}
void _ZN9SimpleLib5printEJvd(double v)
{
	printf("%f\n", v);
}
void _ZN9SimpleLib5printEJvb(bool v)
{
	printf("%s\n", v ? "true" : "false");
}
