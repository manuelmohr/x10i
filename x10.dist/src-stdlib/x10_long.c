#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_TYPENAME(_ZN3x104lang4Long8typeNameEv, x10_long, "x10.lang.Long")

X10_MAKE_COMPARETO(_ZN3x104lang4Long9compareToEx, x10_long)
X10_MAKE_EQUALS(_ZN3x104lang4Long6equalsEx, x10_long)
X10_MAKE_HASHCODE(_ZN3x104lang4Long8hashCodeEv, x10_long)
X10_MAKE_TOSTRING(_ZN3x104lang4Long8toStringEv, x10_long, "%ld")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4Long6equalsEPN3x104lang3AnyE, x10_long)

MAKE_INT_BINOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_CMPOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_INT_UNOPS(_ZN3x104lang4Long, v, x10_long)
x10_long _ZN3x104lang4Longv3rbsEx(x10_long a, x10_long b)
{
	return (x10_long) ((x10_ulong) a >> (x10_ulong) b);
}
MAKE_CONFS(_ZN3x104lang4Long, x10_long)

x10_long _ZN3x104lang4Long9parseLongEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    x10_null_check(s); 
    const x10_char *start = x10_string_buf(s); 
    x10_char *end;
    errno = 0;
    x10_long ans = wcstol(start, &end, radix);
    if (errno == ERANGE || (errno != 0 && ans == 0) || ((end-start) != x10_string_len(s))) {
	x10_throw_exception(X10_NUMBER_FORMAT_EXCEPTION, x10_string_buf(s)); 
    }
    return ans;
}

x10_long _ZN3x104lang4Long9parseLongEPN3x104lang6StringE(x10_string *s)
{
    return _ZN3x104lang4Long9parseLongEPN3x104lang6StringEi(s, 10); 
}

x10_long _ZN3x104lang4Long5parseEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    return _ZN3x104lang4Long9parseLongEPN3x104lang6StringEi(s, radix); 
}

x10_long _ZN3x104lang4Long5parseEPN3x104lang6StringE(x10_string *s)
{
    return _ZN3x104lang4Long9parseLongEPN3x104lang6StringEi(s, 10); 
}

x10_long _ZN3x104lang4Long13highestOneBitEv(x10_long self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    self |= (self >> 32);
    return self & ~(((x10_ulong)self) >> 1);
}

x10_long _ZN3x104lang4Long12lowestOneBitEv(x10_long self)
{
   return self & (-self);
}

x10_long _ZN3x104lang4Long8bitCountEv(x10_long self)
{
    x10_ulong ux = (x10_ulong)self;
    ux = ux - ((ux >> 1) & 0x5555555555555555LL);
    ux = (ux & 0x3333333333333333LL) + ((ux >> 2) & 0x3333333333333333LL);
    ux = (ux & 0x0F0F0F0F0F0F0F0FLL) + ((ux >> 4) & 0x0F0F0F0F0F0F0F0FLL);
    ux = (ux & 0x00FF00FF00FF00FFLL) + ((ux >> 8) & 0x00FF00FF00FF00FFLL);
    ux = ux + (ux >> 16);
    ux = ux + (ux >> 32);
    return (x10_int)(ux & 0x7F);
}

x10_long _ZN3x104lang4Long20numberOfLeadingZerosEv(x10_long self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    self |= (self >> 32);
    return _ZN3x104lang4Long8bitCountEv(~self);
}

x10_long _ZN3x104lang4Long21numberOfTrailingZerosEv(x10_long self)
{
   return _ZN3x104lang4Long8bitCountEv(~self & (self-1));
}

x10_long _ZN3x104lang4Long10rotateLeftEi(x10_long self, x10_int distance)
{
   return (self << distance) | (((x10_ulong)self) >> (64 - distance));
}

x10_long _ZN3x104lang4Long11rotateRightEi(x10_long self, x10_int distance)
{
   return (((x10_ulong)self) >> distance) | (self << (64 - distance));
}

x10_long _ZN3x104lang4Long12reverseBytesEv(x10_long self)
{
    x10_ulong ux = self;
    x10_ulong ans = ux << 56; 
    ans |= (ux & 0xFF00L) << 40;
    ans |= (ux & 0xFF0000L) << 24;
    ans |= (ux & 0xFF000000L) << 8;
    ans |= (ux >> 8) & 0xFF000000L;
    ans |= (ux >> 24) & 0xFF0000L;
    ans |= (ux >> 40) & 0xFF00L;
    ans |= (ux >> 56);
    return (x10_long)ans;
}

x10_long _ZN3x104lang4Long7reverseEv(x10_long self)
{
    x10_ulong ux = (x10_ulong)self;
    ux = ((ux & 0x5555555555555555LL) << 1) | ((ux >> 1) & 0x5555555555555555LL);
    ux = ((ux & 0x3333333333333333LL) << 2) | ((ux >> 2) & 0x3333333333333333LL);
    ux = ((ux & 0x0F0F0F0F0F0F0F0FLL) << 4) | ((ux >> 4) & 0x0F0F0F0F0F0F0F0FLL);
    return _ZN3x104lang4Long12reverseBytesEv((x10_long)ux);
}


