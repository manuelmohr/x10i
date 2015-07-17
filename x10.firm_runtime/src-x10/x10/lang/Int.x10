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
 * Int is a 32-bit signed two's complement integral data type, with
 * values ranging from -2147483648 to 2147483647, inclusive.  All of the normal
 * arithmetic and bitwise operations are defined on Int, and Int
 * is closed under those operations.  There are also static methods
 * that define conversions from other data types, including String,
 * as well as some Int constants.
 */
//@NativeRep("java", "int", null, "x10.rtt.Types.INT")
//                 v-- when used
//@NativeRep("c++", "x10_int", "x10_int", null)
//                            ^ when constructed
public struct Int implements Comparable[Int], Arithmetic[Int], Bitwise[Int], Ordered[Int] {


    /**
     * A less-than operator.
     * Compares this Int with another Int and returns true if this Int is
     * strictly less than the other Int.
     * @param x the other Int
     * @return true if this Int is strictly less than the other Int.
     */
    @Native("java", "((#this) < (#x))")
    @Native("c++",  "((#0) < (#1))")
    public native operator this < (x:Int): Boolean;

    /**
     * A greater-than operator.
     * Compares this Int with another Int and returns true if this Int is
     * strictly greater than the other Int.
     * @param x the other Int
     * @return true if this Int is strictly greater than the other Int.
     */
    @Native("java", "((#this) > (#x))")
    @Native("c++",  "((#0) > (#1))")
    public native operator this > (x:Int): Boolean;

    /**
     * A less-than-or-equal-to operator.
     * Compares this Int with another Int and returns true if this Int is
     * less than or equal to the other Int.
     * @param x the other Int
     * @return true if this Int is less than or equal to the other Int.
     */
    @Native("java", "((#this) <= (#x))")
    @Native("c++",  "((#0) <= (#1))")
    public native operator this <= (x:Int): Boolean;

    /**
     * A greater-than-or-equal-to operator.
     * Compares this Int with another Int and returns true if this Int is
     * greater than or equal to the other Int.
     * @param x the other Int
     * @return true if this Int is greater than or equal to the other Int.
     */
    @Native("java", "((#this) >= (#x))")
    @Native("c++",  "((#0) >= (#1))")
    public native operator this >= (x:Int): Boolean;


    /**
     * A binary plus operator.
     * Computes the result of the addition of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Int
     * @return the sum of this Int and the other Int.
     */
    @Native("java", "((#this) + (#x))")
    @Native("c++",  "((x10_int) ((#0) + (#1)))")
    public native operator this + (x:Int): Int;

    /**
     * A binary minus operator.
     * Computes the result of the subtraction of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Int
     * @return the difference of this Int and the other Int.
     */
    @Native("java", "((#this) - (#x))")
    @Native("c++",  "((x10_int) ((#0) - (#1)))")
    public native operator this - (x:Int): Int;

    /**
     * A binary multiply operator.
     * Computes the result of the multiplication of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Int
     * @return the product of this Int and the other Int.
     */
    @Native("java", "((#this) * (#x))")
    @Native("c++",  "((x10_int) ((#0) * (#1)))")
    public native operator this * (x:Int): Int;

    /**
     * A binary divide operator.
     * Computes the result of the division of the two operands.
     * @param x the other Int
     * @return the quotient of this Int and the other Int.
     */
    @Native("java", "((#this) / (#x))")
    @Native("c++",  "((x10_int) ((#0) / x10aux::zeroCheck(#1)))")
    public native operator this / (x:Int): Int;

    /**
     * A binary remainder operator.
     * Computes a remainder from the division of the two operands.
     * @param x the other Int
     * @return the remainder from dividing this Int by the other Int.
     */
    @Native("java", "((#this) % (#x))")
    @Native("c++",  "((x10_int) ((#0) % x10aux::zeroCheck(#1)))")
    public native operator this % (x:Int): Int;

    /**
     * A unary plus operator.
     * A no-op.
     * @return the value of this Int.
     */
    @Native("java", "(+(#this))")
    @Native("c++",  "((x10_int) +(#0))")
    public native operator + this: Int;

    /**
     * A unary minus operator.
     * Negates the operand.
     * Overflows result in truncating the high bits.
     * @return the negated value of this Int.
     */
    @Native("java", "(-(#this))")
    @Native("c++",  "((x10_int) -(#0))")
    public native operator - this: Int;


    /**
     * A bitwise and operator.
     * Computes a bitwise AND of the two operands.
     * @param x the other Int
     * @return the bitwise AND of this Int and the other Int.
     */
    @Native("java", "((#this) & (#x))")
    @Native("c++",  "((x10_int) ((#0) & (#1)))")
    public native operator this & (x:Int): Int;

    /**
     * A bitwise or operator.
     * Computes a bitwise OR of the two operands.
     * @param x the other Int
     * @return the bitwise OR of this Int and the other Int.
     */
    @Native("java", "((#this) | (#x))")
    @Native("c++",  "((x10_int) ((#0) | (#1)))")
    public native operator this | (x:Int): Int;

    /**
     * A bitwise xor operator.
     * Computes a bitwise XOR of the two operands.
     * @param x the other Int
     * @return the bitwise XOR of this Int and the other Int.
     */
    @Native("java", "((#this) ^ (#x))")
    @Native("c++",  "((x10_int) ((#0) ^ (#1)))")
    public native operator this ^ (x:Int): Int;

    /**
     * A bitwise left shift operator.
     * Computes the value of the left-hand operand shifted left by the value of the right-hand operand.
     * The shift count will be masked with 0x1f before the shift is applied.
     * @param count the shift count
     * @return this Int shifted left by count.
     */
    @Native("java", "((#this) << (#count))") // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_int) ((#0) << (0x1f & (#1))))")
    public native operator this << (count:Int): Int;

    /**
     * A bitwise right shift operator.
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * replicating the sign bit into the high bits.
     * The shift count will be masked with 0x1f before the shift is applied.
     * @param count the shift count
     * @return this Int shifted right by count.
     */
    @Native("java", "((#this) >> (#count))") // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_int) ((#0) >> (0x1f & (#1))))")
    public native operator this >> (count:Int): Int;

    /**
     * A bitwise logical right shift operator (zero-fill).
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x1f before the shift is applied.
     * @deprecated use the right-shift operator and unsigned conversions instead.
     * @param count the shift count
     * @return this Int shifted right by count with high bits zero-filled.
     */
    @Native("java", "((#this) >>> (#count))") // no mask. Java defines shift as masked.
    @Native("c++",  "((x10_int) ((x10_uint) (#0) >> (0x1f & (#1))))")
    public native operator this >>> (count:Int): Int;

    /**
     * A bitwise complement operator.
     * Computes a bitwise complement (NOT) of the operand.
     * @return the bitwise complement of this Int.
     */
    @Native("java", "(~(#this))")
    @Native("c++",  "((x10_int) ~(#0))")
    public native operator ~ this: Int;


    /**
     * Coerce a given Byte to an Int.
     * @param x the given Byte
     * @return the given Byte converted to an Int.
     */
    @Native("java", "((int)(byte)(#x))")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:Byte): Int;

    /**
     * Coerce a given Short to an Int.
     * @param x the given Short
     * @return the given Short converted to an Int.
     */
    @Native("java", "((int)(short)(#x))")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:Short): Int;

    /**
     * Convert a given Long to an Int.
     * @param x the given Long
     * @return the given Long converted to an Int.
     */
    @Native("java", "((int)(long)(#x))")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:Long) as Int;

    /**
     * Convert a given Float to an Int.
     * @param x the given Float
     * @return the given Float converted to an Int.
     */
    @Native("java", "((int)(float)(#x))")
    @Native("c++",  "x10aux::float_utils::toInt(#1)")
    @Native("cuda",  "((x10_int)#1)")
    public native static operator (x:Float) as Int;

    /**
     * Convert a given Double to an Int.
     * @param x the given Double
     * @return the given Double converted to an Int.
     */
    @Native("java", "((int)(double)(#x))")
    @Native("c++",  "x10aux::double_utils::toInt(#1)")
    public native static operator (x:Double) as Int;

    /**
     * Coerce a given UByte to an Int.
     * @param x the given UByte
     * @return the given UByte converted to an Int.
     */
    @Native("java", "((int)#x)")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:UByte): Int;

    /**
     * Coerce a given UShort to an Int.
     * @param x the given UShort
     * @return the given UShort converted to an Int.
     */
    @Native("java", "((int)#x)")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:UShort): Int;

    /**
     * Coerce a given UInt to an Int.
     * @param x the given UInt
     * @return the given UInt converted to an Int.
     */
    @Native("java", "((int)#x)")
    @Native("c++",  "((x10_int) (#1))")
    public native static operator (x:UInt) as Int;


    /**
     * A constant holding the minimum value an Int can have, -2<sup>31</sup>.
     */
    @Native("java", "java.lang.Integer.MIN_VALUE")
    @Native("c++", "((x10_int)0x80000000)")
    public static MIN_VALUE: Int{self==0x80000000} = 0x80000000;

    /**
     * A constant holding the maximum value an Int can have, 2<sup>31</sup>-1.
     */
    @Native("java", "java.lang.Integer.MAX_VALUE")
    @Native("c++", "((x10_int)0x7fffffff)")
    public static MAX_VALUE: Int{self==0x7fffffff} = 0x7fffffff;


    /**
     * Returns a String representation of this Int in the specified radix.
     * @param radix the radix to use in the String representation
     * @return a String representation of this Int in the specified radix.
     */
    @Native("java", "java.lang.Integer.toString(#this, #radix)")
    @Native("c++", "x10aux::int_utils::toString(#0, #1)")
    public native def toString(radix:Int): String;

    /**
     * Returns a String representation of this Int in base 16.
     * This method is simply a synonym for toString(16).
     * In particular toHexString(-20) will print -14; to print
     * the 32 bit two's complement hexadecimal representation of an Int v
     * use (v as UInt).toHexString().
     *
     * @return a String representation of this Int in base 16.
     */
    public def toHexString(): String = toString(16);

    /**
     * Returns a String representation of this Int in base 8.
     * This method is simply a synonym for toString(8).
     * In particular toOctalString(-20) will print -24; to print
     * the 32 bit two's complement octal representation of an Int v
     * use (v as UInt).toHexString().
     *
     * @return a String representation of this Int in base 8.
     */
    public def toOctalString(): String = toString(8);

    /**
     * Returns a String representation of this Int in base 2.
     * This method is simply a synonym for toString(2).
     * In particular toBinaryString(-20) will print -10100; to print
     * the 32 bit two's complement binary representation of an Int v
     * use (v as UInt).toBinaryString().
     *
     * @return a String representation of this Int in base 2.
     */
    public def toBinaryString(): String = toString(2);

    /**
     * Returns a String representation of this Int as a decimal number.
     * @return a String representation of this Int as a decimal number.
     */
    public def toString(): String = toString(10);

    /**
     * @deprecated use {@link #parse(String,Int)} instead
     */
    public static def parseInt(s:String, radix:Int): Int = parse(s, radix);

    /**
     * @deprecated use {@link #parse(String)} instead
     */
    public static def parseInt(s:String): Int = parse(s);

    /**
     * Parses the String argument as an Int in the radix specified by the second argument.
     * @param s the String containing the Int representation to be parsed
     * @param radix the radix to be used while parsing s
     * @return the Int represented by the String argument in the specified radix.
     * @throws NumberFormatException if the String does not contain a parsable Int.
     */
    // @Native("java", "x10.core.Signed.parseInt(#s, #radix)")
    @Native("java", "java.lang.Integer.parseInt(#s, #radix)")
    @Native("c++", "x10aux::int_utils::parseInt(#1, #2)")
    public native static def parse(s:String, radix:Int): Int; //throwsNumberFormatException;

    /**
     * Parses the String argument as a decimal Int.
     * @param s the String containing the Int representation to be parsed
     * @return the Int represented by the String argument.
     * @throws NumberFormatException if the String does not contain a parsable Int.
     */
    public static def parse(s:String): Int = parse(s, 10);

    /**
     * Returns an Int value with at most a single one-bit, in the position
     * of the highest-order ("leftmost") one-bit in this Int value.
     * Returns zero if this Int has no one-bits in its two's complement
     * binary representation, that is, if it is equal to zero.
     * @return an Int value with a single one-bit, in the position of the highest-order one-bit in this Int, or zero if this Int is itself equal to zero.
     */
    public def highestOneBit(): Int = (this as UInt).highestOneBit() as Int;

    /**
     * Returns an Int value with at most a single one-bit, in the position
     * of the lowest-order ("rightmost") one-bit in this Int value.
     * Returns zero if this Int has no one-bits in its two's complement
     * binary representation, that is, if it is equal to zero.
     * @return an Int value with a single one-bit, in the position of the lowest-order one-bit in this Int, or zero if this Int is itself equal to zero.
     */
    public def lowestOneBit(): Int = (this as UInt).lowestOneBit() as Int;

    /**
     * Returns the number of zero bits preceding the highest-order ("leftmost")
     * one-bit in the two's complement binary representation of this Int.
     * Returns 32 if this Int has no one-bits in its two's complement
     * representation, in other words if it is equal to zero.
     * @return the number of zero bits preceding the highest-order one-bit in the two's complement binary representation of this Int, or 32 if this Int is equal to zero.
     */
    public def numberOfLeadingZeros(): Int = (this as UInt).numberOfLeadingZeros();

    /**
     * Returns the number of zero bits following the lowest-order ("rightmost")
     * one-bit in the two's complement binary representation of this Int.
     * Returns 32 if this Int has no one-bits in its two's complement
     * representation, in other words if it is equal to zero.
     * @return the number of zero bits following the lowest-order one-bit in the two's complement binary representation of this Int, or 32 if this Int is equal to zero.
     */
    public def numberOfTrailingZeros(): Int = (this as UInt).numberOfTrailingZeros();

    /**
     * Returns the number of one-bits in the two's complement binary
     * representation of this Int.  This function is sometimes referred
     * to as the <i>population count</i>.
     * @return the number of one-bits in the two's complement binary representation of this Int.
     */
    public def bitCount(): Int = (this as UInt).bitCount();

    /**
     * Returns the value obtained by rotating the two's complement binary
     * representation of this Int left by the specified number of bits.
     * (Bits shifted out of the left hand, or high-order, side reenter on
     * the right, or low-order.)<br>
     * Note that left rotation with a negative distance is equivalent to
     * right rotation:
     * <code>rotateLeft(val, -distance) == rotateRight(val, distance)</code>.
     * Note also that rotation by any multiple of 32 is a no-op, so all but
     * the last five bits of the rotation distance can be ignored, even if
     * the distance is negative:
     * <code>rotateLeft(val, distance) == rotateLeft(val, distance &amp; 0x1F)</code>.
     * @param distance the distance to rotate by
     * @return the value obtained by rotating the two's complement binary representation of this Int left by the specified number of bits.
     * @see #rotateRight(Int)
     */
    public def rotateLeft(distance:Int): Int = (this << distance) | (this >>> -distance);

    /**
     * Returns the value obtained by rotating the two's complement binary
     * representation of this Int right by the specified number of bits.
     * (Bits shifted out of the right hand, or low-order, side reenter on
     * the left, or high-order.)<br>
     * Note that right rotation with a negative distance is equivalent to
     * left rotation:
     * <code>rotateRight(val, -distance) == rotateLeft(val, distance)</code>.
     * Note also that rotation by any multiple of 32 is a no-op, so all but
     * the last five bits of the rotation distance can be ignored, even if
     * the distance is negative:
     * <code>rotateRight(val, distance) == rotateRight(val, distance &amp; 0x1F)</code>.
     * @param distance the distance to rotate by
     * @return the value obtained by rotating the two's complement binary representation of this Int right by the specified number of bits.
     * @see #rotateLeft(Int)
     */
    public def rotateRight(distance:Int): Int = (this << -distance) | (this >>> distance);

    /**
     * Returns the value obtained by reversing the order of the bits in the
     * two's complement binary representation of this Int.
     * @return the value obtained by reversing order of the bits in this Int.
     */
    public def reverse(): Int {
        var x : Int = this;
        x = (x & 0x55555555 as Int) << 1 | ((x>>>1) & 0x55555555 as Int);
        x = (x & 0x33333333 as Int) << 2 | ((x>>>2) & 0x33333333 as Int);
        x = (x & 0x0F0F0F0F as Int) << 4 | ((x>>>4) & 0x0F0F0F0F as Int);
        return x.reverseBytes();
    }

    /**
     * Returns the signum function of this Int.  The return value is -1 if
     * this Int is negative; 0 if this Int is zero; and 1 if this Int is
     * positive.
     * @return the signum function of this Int.
     */
    public def signum(): Int = this < 0 ? -1 : this > 0 ? 1 : 0;

    /**
     * Returns the value obtained by reversing the order of the bytes in the
     * two's complement representation of this Int.
     * @return the value obtained by reversing the bytes in this Int.
     */
    public def reverseBytes(): Int {
        var x : Int = this << 16 | this >>> 16;
        return x << 8 & 0xFF00FF00 | x >> 8 & 0x00FF00FF;
    }

    /**
     * Return true if the given entity is an Int, and this Int is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this Int is equal to the given entity.
     */
    @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    public def equals(x:Any): Boolean {
        if(x instanceof Int)
            return equals(x as Int);
        return false;
    }

    /**
     * Returns true if this Int is equal to the given Int.
     * @param x the given Int
     * @return true if this Int is equal to the given Int.
     */
    @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    public native def equals(x:Int): Boolean;

    public def hashCode(): Int = this;

    /**
     * Returns a negative Int, zero, or a positive Int if this Int is less than, equal
     * to, or greater than the given Int.
     * @param x the given Int
     * @return a negative Int, zero, or a positive Int if this Int is less than, equal
     * to, or greater than the given Int.
     */
    public def compareTo(x:Int):Int = this == x ? 0 : this < x ? -1 : 1;

    /**
     * Constructs a IntRange from
     * the lower bound to the upper bound, inclusive.
     * @param lower the lower bound
     * @param upper the upper bound
     * @return a range from lower to upper, inclusive.
     */
    public static operator (x:Int) .. (y:Int):IntRange{min==x,max==y}
        = new IntRange(x, y);
}
public type Int(b:Int) = Int{self==b};
