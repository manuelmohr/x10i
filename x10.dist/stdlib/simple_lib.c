#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <wchar.h>

void _ZN9SimpleLib5printEx(int64_t v)
{
	printf("%"PRIi64"\n", v);
}
void _ZN9SimpleLib5printEy(uint64_t v)
{
	printf("%"PRIu64"\n", v);
}
void _ZN9SimpleLib5printEi(int32_t v)
{
	printf("%"PRIi32"\n", v);
}
void _ZN9SimpleLib5printEj(uint32_t v)
{
	printf("%"PRIu32"\n", v);
}
void _ZN9SimpleLib5printEs(int16_t v)
{
	printf("%"PRIi16"\n", v);
}
void _ZN9SimpleLib5printEt(uint16_t v)
{
	printf("%"PRIu16"\n", v);
}
void _ZN9SimpleLib5printEa(int8_t v)
{
	printf("%"PRIi8"\n", v);
}
void _ZN9SimpleLib5printEh(uint8_t v)
{
	printf("%"PRIu8"\n", v);
}
void _ZN9SimpleLib5printEDi(wchar_t v)
{
	printf("%lc\n", v);
}
void _ZN9SimpleLib5printEf(float v)
{
	printf("%f\n", v);
}
void _ZN9SimpleLib5printEd(double v)
{
	printf("%f\n", v);
}
void _ZN9SimpleLib5printEb(bool v)
{
	printf("%s\n", v ? "true" : "false");
}
