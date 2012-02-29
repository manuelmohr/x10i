/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

package x10.lang;

import x10.compiler.Native;
import x10.compiler.NativeRep;
import x10.util.Ordered;

/**
 * ULong is a 64-bit unsigned integral data type, with
 * values ranging from 0 to 18446744073709551616, inclusive.  All of the normal
 * arithmetic and bitwise operations are defined on ULong, and ULong
 * is closed under those operations.  There are also static methods
 * that define conversions from other data types, including String,
 * as well as some ULong constants.
 */
// @NativeRep("java", "long", null, "x10.rtt.Types.ULONG")
@NativeRep("c++", "x10_ulong", "x10_ulong", null)
public struct ULong implements Comparable[ULong] /*TODO implements Arithmetic[ULong], Bitwise[ULong], Ordered[ULong]*/ {


    /** The actual number with Long representation */
    /* [FIRM_CHANGE] */
    /*
    public val longVal:Long;
    public def this(value:Long) {
        this.longVal = value;
    }
    */

    /**
     * A less-than operator.
     * Compares this ULong with another ULong and returns true if this ULong is
     * strictly less than the other ULong.
     * @param x the other ULong
     * @return true if this ULong is strictly less than the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.lt(#this, #1)")
    @Native("c++",  "((#0) < (#1))")
    /* [FIRM_CHANGE] */
    public native operator this < (x:ULong): Boolean;

    /**
     * A greater-than operator.
     * Compares this ULong with another ULong and returns true if this ULong is
     * strictly greater than the other ULong.
     * @param x the other ULong
     * @return true if this ULong is strictly greater than the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.gt(#this, #1)")
    @Native("c++",  "((#0) > (#1))")
    /* [FIRM_CHANGE] */
    public native operator this > (x:ULong): Boolean;

    /**
     * A less-than-or-equal-to operator.
     * Compares this ULong with another ULong and returns true if this ULong is
     * less than or equal to the other ULong.
     * @param x the other ULong
     * @return true if this ULong is less than or equal to the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.le(#this, #1)")
    @Native("c++",  "((#0) <= (#1))")
    /* [FIRM_CHANGE] */
    public native operator this <= (x:ULong): Boolean;

    /**
     * A greater-than-or-equal-to operator.
     * Compares this ULong with another ULong and returns true if this ULong is
     * greater than or equal to the other ULong.
     * @param x the other ULong
     * @return true if this ULong is greater than or equal to the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.ge(#this, #1)")
    @Native("c++",  "((#0) >= (#1))")
    /* [FIRM_CHANGE] */
    public native operator this >= (x:ULong): Boolean;


    /**
     * A binary plus operator.
     * Computes the result of the addition of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other ULong
     * @return the sum of this ULong and the other ULong.
     */
    // @Native("java", "((#this) + (#1))")
    @Native("c++",  "((x10_ulong) ((#0) + (#1)))")
    /* [FIRM_CHANGE] */
    public native operator this + (x:ULong): ULong;

    /**
     * A binary minus operator.
     * Computes the result of the subtraction of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other ULong
     * @return the difference of this ULong and the other ULong.
     */
    // @Native("java", "((#this) - (#1))")
    @Native("c++",  "((x10_ulong) ((#0) - (#1)))")
    /* [FIRM_CHANGE] */
    public native operator this - (x:ULong): ULong;

    /**
     * A binary multiply operator.
     * Computes the result of the multiplication of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other ULong
     * @return the product of this ULong and the other ULong.
     */
    // @Native("java", "((#this) * (#1))")
    @Native("c++",  "((x10_ulong) ((#0) * (#1)))")
    /* [FIRM_CHANGE] */
    public native operator this * (x:ULong): ULong;

    /**
     * A binary divide operator.
     * Computes the result of the division of the two operands.
     * @param x the other ULong
     * @return the quotient of this ULong and the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.div(#this, #x)")
    @Native("java", "x10.lang.ULong.$make(x10.core.Unsigned.div(#this.longVal, #x.longVal))")
    @Native("c++",  "((x10_ulong) ((#0) / x10aux::zeroCheck(#1)))")
    /* [FIRM_CHANGE] */
    public native operator this / (x:ULong): ULong;

    /**
     * A binary remainder operator.
     * Computes a remainder from the division of the two operands.
     * @param x the other ULong
     * @return the remainder from dividing this ULong by the other ULong.
     */
    // @Native("java", "x10.core.Unsigned.rem(#this, #x)")
    @Native("java", "x10.lang.ULong.$make(x10.core.Unsigned.rem(#this.longVal, #x.longVal))")
    @Native("c++",  "((x10_ulong) ((#0) % x10aux::zeroCheck(#1)))")
    /* [FIRM_CHANGE] */
    public native operator this % (x:ULong): ULong;

    /**
     * A unary plus operator.
     * A no-op.
     * @return the value of this ULong.
     */
    // @Native("java", "((long) +(#this))")
    @Native("c++",  "((x10_ulong) +(#0))")
    /* [FIRM_CHANGE] */
    public native operator + this: ULong;

    /**
     * A unary minus operator.
     * Computes the two's complement of the operand.
     * Overflows result in truncating the high bits.
     * @return the two's complement of this ULong.
     */
    // @Native("java", "((long) -(#this))")
    @Native("c++",  "((x10_ulong) -(#0))")
    /* [FIRM_CHANGE] */
    public native operator - this: ULong;


    /**
     * A bitwise and operator.
     * Computes a bitwise AND of the two operands.
     * @param x the other ULong
     * @return the bitwise AND of this ULong and the other ULong.
     */
    public native operator this & (x:ULong): ULong;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(ULong)&(ULong)
     */
    public operator (x:Long) & this: ULong = this & x as ULong;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(ULong)&(ULong)
     */
    public operator this & (x:Long): ULong = this & x as ULong;

    /**
     * A bitwise or operator.
     * Computes a bitwise OR of the two operands.
     * @param x the other ULong
     * @return the bitwise OR of this ULong and the other ULong.
     */
    public native operator this | (x:ULong): ULong;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(ULong)|(ULong)
     */
    public operator (x:Long) | this: ULong = this | x as ULong;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(ULong)|(ULong)
     */
    public operator this | (x:Long): ULong = this | x as ULong;

    /**
     * A bitwise xor operator.
     * Computes a bitwise XOR of the two operands.
     * @param x the other ULong
     * @return the bitwise XOR of this ULong and the other ULong.
     */
    public native operator this ^ (x:ULong): ULong;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(ULong)^(ULong)
     */
    public operator (x:Long) ^ this: ULong = this ^ x as ULong;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(ULong)^(ULong)
     */
    public operator this ^ (x:Long): ULong = this ^ x as ULong;

    /**
     * A bitwise left shift operator.
     * Computes the value of the left-hand operand shifted left by the value of the right-hand operand.
     * The shift count will be masked with 0x3f before the shift is applied.
     * @param count the shift count
     * @return this ULong shifted left by count.
     */
    // @Native("java", "((#this) << (#count))")  // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_ulong) ((#0) << (0x3f & (#1))))")
    /* [FIRM_CHANGE] */
    public native operator this << (count:Int): ULong;

    /**
     * A bitwise right shift operator.
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x3f before the shift is applied.
     * @param count the shift count
     * @return this ULong shifted right by count.
     */
    // @Native("java", "((#this) >>> (#count))")  // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_ulong) ((#0) >> (0x3f & (#1))))")
    /* [FIRM_CHANGE] */
    public native operator this >> (count:Int): ULong;

    /**
     * A bitwise logical right shift operator (zero-fill).
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x3f before the shift is applied.
     * @deprecated use the right-shift operator.
     * @param count the shift count
     * @return this ULong shifted right by count with high bits zero-filled.
     */
    // @Native("java", "((#this) >>> (#count))")  // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_ulong) ((#0) >> (0x3f & (#1))))")
    /* [FIRM_CHANGE] */
    public native operator this >>> (count:Int): ULong;

    /**
     * A bitwise complement operator.
     * Computes a bitwise complement (NOT) of the operand.
     * @return the bitwise complement of this ULong.
     */
    // @Native("java", "((long) ~(#this))")
    @Native("c++",  "((x10_ulong) ~(#0))")
    /* [FIRM_CHANGE] */
    public native operator ~ this: ULong;


    /**
     * Coerce a given UByte to a ULong.
     * @param x the given UByte
     * @return the given UByte converted to a ULong.
     */
    // @Native("java", "((long) ((#x) & 0xffL))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:UByte): ULong;
    /**
     * Coerce a given UShort to a ULong.
     * @param x the given UShort
     * @return the given UShort converted to a ULong.
     */
    // @Native("java", "((long) ((#x) & 0xffffL))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:UShort): ULong;

    /**
     * Coerce a given UInt to a ULong.
     * @param x the given UInt
     * @return the given UInt converted to a ULong.
     */
    // @Native("java", "((long) ((#x) & 0xffffffffL))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:UInt): ULong;


    /**
     * Coerce a given Byte to a ULong.
     * @param x the given Byte
     * @return the given Byte converted to a ULong.
     */
    // @Native("java", "((long)(byte)(#x))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:Byte): ULong;

    /**
     * Coerce a given Short to a ULong.
     * @param x the given Short
     * @return the given Short converted to a ULong.
     */
    // @Native("java", "((long)(short)(#x))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:Short): ULong;

    /**
     * Coerce a given Int to a ULong.
     * @param x the given Int
     * @return the given Int converted to a ULong.
     */
    // @Native("java", "((long)(int)(#x))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:Int): ULong;

    /**
     * Convert a given Float to a ULong.
     * @param x the given Float
     * @return the given Float converted to a ULong.
     */
    // @Native("java", "((long)(float)(#x))")
    @Native("c++",  "x10aux::float_utils::toULong(#1)")
    /* [FIRM_CHANGE] */
    public native static operator (x:Float) as ULong;

    /**
     * Convert a given Double to a ULong.
     * @param x the given Double
     * @return the given Double converted to a ULong.
     */
    // @Native("java", "((long)(double)(#x))")
    @Native("c++",  "x10aux::double_utils::toULong(#1)")
    /* [FIRM_CHANGE] */
    public native static operator (x:Double) as ULong;

    /**
     * Coerce a given Long to a ULong.
     * @param x the given Long
     * @return the given Long converted to a ULong.
     */
    // @Native("java", "((long)(long)(#x))")
    @Native("c++",  "((x10_ulong) (#1))")
    /* [FIRM_CHANGE] */
    public native static operator (x:Long) as ULong;


    /**
     * A constant holding the minimum value a ULong can have, 0.
     */
    // @Native("java", "0L")
    @Native("c++", "((x10_ulong)0LLU)")
    public static MIN_VALUE: ULong{self==0ul} = 0UL;

    /**
     * A constant holding the maximum value a ULong can have, 2<sup>64</sup>-1.
     */
    // @Native("java", "0xffffffffffffffffL")
    @Native("c++", "0xffffffffffffffffLLU")
    public static MAX_VALUE: ULong{self==0xffffffffffffffffUL} = 0xffffffffffffffffUL;


    /**
     * Returns a String representation of this ULong in the specified radix.
     * @param radix the radix to use in the String representation
     * @return a String representation of this ULong in the specified radix.
     */
    @Native("c++", "x10aux::long_utils::toString(#0, #1)")
    /* [FIRM_CHANGE] */
    public native def toString(radix:Int): String;

    /**
     * Returns a String representation of this ULong as a hexadecimal number.
     * @return a String representation of this ULong as a hexadecimal number.
     */
    public def toHexString(): String = toString(16);

    /**
     * Returns a String representation of this ULong as an octal number.
     * @return a String representation of this ULong as an octal number.
     */
    public def toOctalString(): String = toString(8);

    /**
     * Returns a String representation of this ULong as a binary number.
     * @return a String representation of this ULong as a binary number.
     */
    public def toBinaryString(): String = toString(2);

    /**
     * Returns a String representation of this ULong as a decimal number.
     * @return a String representation of this ULong as a decimal number.
     */
    public def toString(): String = toString(10);

    /**
     * @deprecated use {@link #parse(String,Int)} instead
     */
    public static def parseULong(s:String, radix:Int): ULong = parse(s, radix);
    /**
     * @deprecated use {@link #parse(String)} instead
     */
    public static def parseULong(s:String): ULong = parse(s);

    /**
     * Parses the String argument as a ULong in the radix specified by the second argument.
     * @param s the String containing the ULong representation to be parsed
     * @param radix the radix to be used while parsing s
     * @return the ULong represented by the String argument in the specified radix.
     * @throws NumberFormatException if the String does not contain a parsable ULong.
     */
    @Native("java", "x10.lang.ULong.$make(x10.core.Unsigned.parseULong(#s, #radix))")
    @Native("c++", "x10aux::long_utils::parseULong(#1, #2)")
    /* [FIRM_CHANGE] */
    public native static def parse(s:String, radix:Int): ULong; //throws NumberFormatException 

    /**
     * Parses the String argument as a decimal ULong.
     * @param s the String containing the ULong representation to be parsed
     * @return the ULong represented by the String argument.
     * @throws NumberFormatException if the String does not contain a parsable ULong.
     */
    public static def parse(s:String): ULong = parse(s, 10);


    /**
     * Returns a ULong value with at most a single one-bit, in the position
     * of the highest-order ("leftmost") one-bit in this ULong value.
     * Returns zero if this ULong has no one-bits in its
     * binary representation, that is, if it is equal to zero.
     * @return a ULong value with a single one-bit, in the position of the highest-order one-bit in this ULong, or zero if this ULong is itself equal to zero.
     */
    // @Native("java", "java.lang.Long.highestOneBit(#this)")
    @Native("c++", "((x10_ulong) x10aux::long_utils::highestOneBit(#0))")
    /* [FIRM_CHANGE] */
    public native def highestOneBit(): ULong;

    /**
     * Returns a ULong value with at most a single one-bit, in the position
     * of the lowest-order ("rightmost") one-bit in this ULong value.
     * Returns zero if this ULong has no one-bits in its
     * binary representation, that is, if it is equal to zero.
     * @return a ULong value with a single one-bit, in the position of the lowest-order one-bit in this ULong, or zero if this ULong is itself equal to zero.
     */
    // @Native("java", "java.lang.Long.lowestOneBit(#this)")
    @Native("c++", "((x10_ulong) x10aux::long_utils::lowestOneBit(#0))")
    /* [FIRM_CHANGE] */
    public native def lowestOneBit(): ULong;

    /**
     * Returns the number of zero bits preceding the highest-order ("leftmost")
     * one-bit in the binary representation of this ULong.
     * Returns 64 if this ULong has no one-bits in its representation,
     * in other words if it is equal to zero.
     * @return the number of zero bits preceding the highest-order one-bit in the binary representation of this ULong, or 64 if this ULong is equal to zero.
     */
    // @Native("java", "java.lang.Long.numberOfLeadingZeros(#this)")
    @Native("c++", "x10aux::long_utils::numberOfLeadingZeros(#0)")
    /* [FIRM_CHANGE] */
    public native def numberOfLeadingZeros(): Int;

    /**
     * Returns the number of zero bits following the lowest-order ("rightmost")
     * one-bit in the binary representation of this ULong.
     * Returns 64 if this ULong has no one-bits in its representation,
     * in other words if it is equal to zero.
     * @return the number of zero bits following the lowest-order one-bit in the binary representation of this ULong, or 64 if this ULong is equal to zero.
     */
    // @Native("java", "java.lang.Long.numberOfTrailingZeros(#this)")
    @Native("c++", "x10aux::long_utils::numberOfTrailingZeros(#0)")
    /* [FIRM_CHANGE] */
    public native def numberOfTrailingZeros(): Int;

    /**
     * Returns the number of one-bits in the binary representation
     * of this ULong.  This function is sometimes referred
     * to as the <i>population count</i>.
     * @return the number of one-bits in the binary representation of this ULong.
     */
    // @Native("java", "java.lang.Long.bitCount(#this)")
    @Native("c++", "x10aux::long_utils::bitCount(#0)")
    /* [FIRM_CHANGE] */
    public native def bitCount(): Int;

    /**
     * Returns the value obtained by rotating the binary representation
     * of this ULong left by the specified number of bits.
     * (Bits shifted out of the left hand, or high-order, side reenter on
     * the right, or low-order.)<br>
     * Note that left rotation with a negative distance is equivalent to
     * right rotation:
     * <code>rotateLeft(val, -distance) == rotateRight(val, distance)</code>.
     * Note also that rotation by any multiple of 64 is a no-op, so all but
     * the last five bits of the rotation distance can be ignored, even if
     * the distance is negative:
     * <code>rotateLeft(val, distance) == rotateLeft(val, distance &amp; 0x3F)</code>.
     * @param distance the distance to rotate by
     * @return the value obtained by rotating the binary representation of this ULong left by the specified number of bits.
     * @see #rotateRight(Int)
     */
    public def rotateLeft(distance:Int): ULong = (this << distance) | (this >>> -distance);

    /**
     * Returns the value obtained by rotating the binary representation
     * of this ULong right by the specified number of bits.
     * (Bits shifted out of the right hand, or low-order, side reenter on
     * the left, or high-order.)<br>
     * Note that right rotation with a negative distance is equivalent to
     * left rotation:
     * <code>rotateRight(val, -distance) == rotateLeft(val, distance)</code>.
     * Note also that rotation by any multiple of 64 is a no-op, so all but
     * the last five bits of the rotation distance can be ignored, even if
     * the distance is negative:
     * <code>rotateRight(val, distance) == rotateRight(val, distance &amp; 0x3F)</code>.
     * @param distance the distance to rotate by
     * @return the value obtained by rotating the binary representation of this ULong right by the specified number of bits.
     * @see #rotateLeft(Int)
     */
    public def rotateRight(distance:Int): ULong = (this << -distance) | (this >>> distance);

    /**
     * Returns the value obtained by reversing the order of the bits in the
     * binary representation of this ULong.
     * @return the value obtained by reversing order of the bits in this ULong.
     */
    public def reverse(): ULong {
        var x : ULong = this;
        x = (x & 0x5555555555555555UL) << 1 | ((x>>>1) & 0x5555555555555555UL);
        x = (x & 0x3333333333333333UL) << 2 | ((x>>>2) & 0x3333333333333333UL);
        x = (x & 0x0F0F0F0F0F0F0F0FUL) << 4 | ((x>>>4) & 0x0F0F0F0F0F0F0F0FUL);
        return x.reverseBytes();
    }

    /**
     * Returns the signum function of this ULong.  The return value is 0 if
     * this ULong is zero and 1 if this ULong is non-zero.
     * @return the signum function of this ULong.
     */
    public def signum(): Int = this > 0 as ULong ? 1 : 0;

    /**
     * Returns the value obtained by reversing the order of the bytes in the
     * representation of this ULong.
     * @return the value obtained by reversing the bytes in this ULong.
     */
    public def reverseBytes(): ULong {
        var x : ULong = this << 32 | this >>> 32;
        x = x << 16 & 0xFFFF0000FFFF0000UL | x >>> 16 & 0x0000FFFF0000FFFFUL;
        x = x <<  8 & 0xFF00FF00FF00FF00UL | x >>>  8 & 0x00FF00FF00FF00FFUL;
        return x;
    }

    /**
     * Return true if the given entity is a ULong, and this ULong is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this ULong is equal to the given entity.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    /* [FIRM_CHANGE] */
    public def equals(x:Any):Boolean {
    	if(x instanceof ULong)
    		return equals(x as ULong);
    	return false; 
    }

    /**
     * Returns true if this ULong is equal to the given ULong.
     * @param x the given ULong
     * @return true if this ULong is equal to the given ULong.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    /* [FIRM_CHANGE] */
    public native def equals(x:ULong):Boolean;

    /**
    * Returns a negative Int, zero, or a positive Int if this ULong is less than, equal
    * to, or greater than the given ULong.
    * @param x the given ULong
    * @return a negative Int, zero, or a positive Int if this ULong is less than, equal
    * to, or greater than the given ULong.
    */
    // @Native("java", "x10.rtt.Equality.compareTo(#this.longVal + java.lang.Long.MIN_VALUE, #x.longVal + java.lang.Long.MIN_VALUE)")
    @Native("c++", "x10aux::long_utils::compareTo(#0, #1)")
    /* [FIRM_CHANGE] */
    public native def compareTo(x:ULong): Int;
}
