#ifndef ENDIAN_H
#define ENDIAN_H

#include <stdint.h>

static inline uint64_t byteswap_64(uint64_t val)
{
	return   ((val & 0x00000000000000FFULL) << 56)
	       | ((val & 0x000000000000FF00ULL) << 40)
	       | ((val & 0x0000000000FF0000ULL) << 24)
	       | ((val & 0x00000000FF000000ULL) <<  8)
	       | ((val & 0x000000FF00000000ULL) >>  8)
	       | ((val & 0x0000FF0000000000ULL) >> 24)
	       | ((val & 0x00FF000000000000ULL) >> 40)
	       | ((val & 0xFF00000000000000ULL) >> 56);
}

static inline uint32_t byteswap_32(uint32_t val)
{
	return   ((val & 0x000000FFU) << 24)
	       | ((val & 0x0000FF00U) <<  8)
	       | ((val & 0x00FF0000U) >>  8)
	       | ((val & 0xFF000000U) >> 24);
}

static inline uint16_t byteswap_16(uint16_t val)
{
	return   ((val & 0x00FFU) << 8)
	       | ((val & 0xFF00U) >> 8);
}

#endif
