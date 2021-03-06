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
 * UShort is a 16-bit unsigned integral data type, with
 * values ranging from 0 to 65535, inclusive.  All of the normal
 * arithmetic and bitwise operations are defined on UShort, and UShort
 * is closed under those operations.  There are also static methods
 * that define conversions from other data types, including String,
 * as well as some UShort constants.
 */
// @NativeRep("java", "short", null, "x10.rtt.Types.USHORT")
@NativeRep("c++", "x10_ushort", "x10_ushort", null)
public struct UShort implements Comparable[UShort], Arithmetic[UShort], Bitwise[UShort], Ordered[UShort] {

    /** The actual number with Short representation */
    /*
    public val shortVal:Short;
    public def this(value:Short) {
        this.shortVal = value;
    }
    */

    /**
     * A less-than operator.
     * Compares this UShort with another UShort and returns true if this UShort is
     * strictly less than the other UShort.
     * @param x the other UShort
     * @return true if this UShort is strictly less than the other UShort.
     */
    // @Native("java", "x10.core.Unsigned.lt(#this, #x)")
    @Native("c++",  "((#0) < (#1))")
    public native operator this < (x:UShort): Boolean;

    /**
     * A greater-than operator.
     * Compares this UShort with another UShort and returns true if this UShort is
     * strictly greater than the other UShort.
     * @param x the other UShort
     * @return true if this UShort is strictly greater than the other UShort.
     */
    // @Native("java", "x10.core.Unsigned.gt(#this, #x)")
    @Native("c++",  "((#0) > (#1))")
    public native operator this > (x:UShort): Boolean;

    /**
     * A less-than-or-equal-to operator.
     * Compares this UShort with another UShort and returns true if this UShort is
     * less than or equal to the other UShort.
     * @param x the other UShort
     * @return true if this UShort is less than or equal to the other UShort.
     */
    // @Native("java", "x10.core.Unsigned.le(#this, #x)")
    @Native("c++",  "((#0) <= (#1))")
    public native operator this <= (x:UShort): Boolean;

    /**
     * A greater-than-or-equal-to operator.
     * Compares this UShort with another UShort and returns true if this UShort is
     * greater than or equal to the other UShort.
     * @param x the other UShort
     * @return true if this UShort is greater than or equal to the other UShort.
     */
    // @Native("java", "x10.core.Unsigned.ge(#this, #x)")
    @Native("c++",  "((#0) >= (#1))")
    public native operator this >= (x:UShort): Boolean;


    /**
     * A binary plus operator.
     * Computes the result of the addition of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UShort
     * @return the sum of this UShort and the other UShort.
     */
    // @Native("java", "((short) ((#this) + (#x)))")
    @Native("c++",  "((x10_ushort) ((#0) + (#1)))")
    public native operator this + (x:UShort): UShort;

    /**
     * A binary minus operator.
     * Computes the result of the subtraction of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UShort
     * @return the difference of this UShort and the other UShort.
     */
    // @Native("java", "((short) ((#this) - (#x)))")
    @Native("c++",  "((x10_ushort) ((#0) - (#1)))")
    public native operator this - (x:UShort): UShort;

    /**
     * A binary multiply operator.
     * Computes the result of the multiplication of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UShort
     * @return the product of this UShort and the other UShort.
     */
    // @Native("java", "((short) ((#this) * (#x)))")
    @Native("c++",  "((x10_ushort) ((#0) * (#1)))")
    public native operator this * (x:UShort): UShort;

    /**
     * A binary divide operator.
     * Computes the result of the division of the two operands.
     * @param x the other UShort
     * @return the quotient of this UShort and the other UShort.
     */
    // @Native("java", "((short) x10.core.Unsigned.div(#this, #x))")
    @Native("c++",  "((x10_ushort) ((#0) / x10aux::zeroCheck(#1)))")
    public native operator this / (x:UShort): UShort;

    /**
     * A binary remainder operator.
     * Computes a remainder from the division of the two operands.
     * @param x the other UShort
     * @return the remainder from dividing this UShort by the other UShort.
     */
    // @Native("java", "((short) x10.core.Unsigned.rem(#this, #x))")
    @Native("c++",  "((x10_ushort) ((#0) % x10aux::zeroCheck(#1)))")
    public native operator this % (x:UShort): UShort;

    /**
     * A unary plus operator.
     * A no-op.
     * @return the value of this UShort.
     */
    // @Native("java", "((short) +(#this))")
    @Native("c++",  "((x10_ushort) +(#0))")
    public native operator + this: UShort;

    /**
     * A unary minus operator.
     * Computes the two's complement of the operand.
     * Overflows result in truncating the high bits.
     * @return the two's complement of this UShort.
     */
    // @Native("java", "((short) -(#this))")
    @Native("c++",  "((x10_ushort) -(#0))")
    public native operator - this: UShort;


    /**
     * A bitwise and operator.
     * Computes a bitwise AND of the two operands.
     * @param x the other UShort
     * @return the bitwise AND of this UShort and the other UShort.
     */
    public native operator this & (x:UShort): UShort;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(UShort)&(UShort)
     */
    public operator (x:Short) & this: UShort = this & x as UShort;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(UShort)&(UShort)
     */
    public operator this & (x:Short): UShort = this & x as UShort;

    /**
     * A bitwise or operator.
     * Computes a bitwise OR of the two operands.
     * @param x the other UShort
     * @return the bitwise OR of this UShort and the other UShort.
     */
    public native operator this | (x:UShort): UShort;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(UShort)|(UShort)
     */
    public operator (x:Short) | this: UShort = this | x as UShort;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(UShort)|(UShort)
     */
    public operator this | (x:Short): UShort = this | x as UShort;

    /**
     * A bitwise xor operator.
     * Computes a bitwise XOR of the two operands.
     * @param x the other UShort
     * @return the bitwise XOR of this UShort and the other UShort.
     */
    public native operator this ^ (x:UShort): UShort;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(UShort)^(UShort)
     */
    public operator (x:Short) ^ this: UShort = this ^ x as UShort;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(UShort)^(UShort)
     */
    public operator this ^ (x:Short): UShort = this ^ x as UShort;

    /**
     * A bitwise left shift operator.
     * Computes the value of the left-hand operand shifted left by the value of the right-hand operand.
     * The shift count will be masked with 0xf before the shift is applied.
     * @param count the shift count
     * @return this UShort shifted left by count.
     */
    // @Native("java", "((short) ((#this) << (0xf & (#count))))")
    @Native("c++",  "((x10_ushort) ((#0) << (0xf & (#1))))")
    public native operator this << (count:Int): UShort;

    /**
     * A bitwise right shift operator.
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0xf before the shift is applied.
     * @param count the shift count
     * @return this UShort shifted right by count.
     */
    // @Native("java", "((short) ((#this) >>> (0xf & (#count))))")
    @Native("c++",  "((x10_ushort) ((#0) >> (0xf & (#1))))")
    public native operator this >> (count:Int): UShort;

    /**
     * A bitwise logical right shift operator (zero-fill).
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0xf before the shift is applied.
     * @deprecated use the right-shift operator.
     * @param count the shift count
     * @return this UShort shifted right by count with high bits zero-filled.
     */
    // @Native("java", "((short) ((#this) >>> (0xf & (#count))))")
    @Native("c++",  "((x10_ushort) ((#0) >> (0xf & (#1))))")
    public native operator this >>> (count:Int): UShort;

    /**
     * A bitwise complement operator.
     * Computes a bitwise complement (NOT) of the operand.
     * @return the bitwise complement of this UShort.
     */
    // @Native("java", "((short) ~(#this))")
    @Native("c++",  "((x10_ushort) ~(#0))")
    public native operator ~ this: UShort;


    /**
     * Coerce a given UByte to a UShort.
     * @param x the given UByte
     * @return the given UByte converted to a UShort.
     */
    // @Native("java", "((short) ((#x) & 0xff))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:UByte): UShort;

    /**
     * Convert a given UInt to a UShort.
     * @param x the given UInt
     * @return the given UInt converted to a UShort.
     */
    // @Native("java", "((short) (#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:UInt) as UShort;

    /**
     * Convert a given ULong to a UShort.
     * @param x the given ULong
     * @return the given ULong converted to a UShort.
     */
    // @Native("java", "((short)(long)(#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:ULong) as UShort;


    /**
     * Coerce a given Byte to a UShort.
     * @param x the given Byte
     * @return the given Byte converted to a UShort.
     */
    // @Native("java", "((short)(byte)(#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:Byte): UShort;

    /**
     * Convert a given Int to a UShort.
     * @param x the given Int
     * @return the given Int converted to a UShort.
     */
    // @Native("java", "((short)(int)(#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:Int) as UShort;

    /**
     * Convert a given Long to a UShort.
     * @param x the given Long
     * @return the given Long converted to a UShort.
     */
    // @Native("java", "((short)(long)(#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:Long) as UShort;

    /**
     * Convert a given Float to a UShort.
     * @param x the given Float
     * @return the given Float converted to a UShort.
     */
    // @Native("java", "x10.core.Floats.toUShort(#x)")
    @Native("c++",  "x10aux::float_utils::toUShort(#1)")
    public native static operator (x:Float) as UShort;

    /**
     * Convert a given Double to a UShort.
     * @param x the given Double
     * @return the given Double converted to a UShort.
     */
    // @Native("java", "x10.core.Floats.toUShort(#x)")
    @Native("c++",  "x10aux::double_utils::toUShort(#1)")
    public native static operator (x:Double) as UShort;

    /**
     * Coerce a given Short to a UShort.
     * @param x the given Short
     * @return the given Short converted to a UShort.
     */
    // @Native("java", "((short)(short)(#x))")
    @Native("c++",  "((x10_ushort) (#1))")
    public native static operator (x:Short) as UShort;


    /**
     * A constant holding the minimum value a UShort can have, 0.
     */
    // @Native("java", "((short)0)")
    @Native("c++", "((x10_ushort)0U)")
    public static MIN_VALUE: UShort{self==0US} = 0US;

    /**
     * A constant holding the maximum value a UShort can have, 2<sup>16</sup>-1.
     */
    // @Native("java", "((short)0xffff)")
    @Native("c++", "((x10_ushort)0xffffU)")
    public static MAX_VALUE: UShort{self==0xffffUS} = 0xffffUS;

    /**
     * Returns a String representation of this UShort in the specified radix.
     * @param radix the radix to use in the String representation
     * @return a String representation of this UShort in the specified radix.
     */
    // @Native("java", "java.lang.Integer.toString((#this) & 0xffff, #radix)")
    @Native("c++", "x10aux::int_utils::toString((#0) & 0xffff, #1)")
    public native def toString(radix:Int): String;

    /**
     * Returns a String representation of this UShort as a hexadecimal number.
     * @return a String representation of this UShort as a hexadecimal number.
     */
    public def toHexString(): String = toString(16);

    /**
     * Returns a String representation of this UShort as an octal number.
     * @return a String representation of this UShort as an octal number.
     */
    public def toOctalString(): String = toString(8);

    /**
     * Returns a String representation of this UShort as a binary number.
     * @return a String representation of this UShort as a binary number.
     */
    public def toBinaryString(): String = toString(2);

    /**
     * Returns a String representation of this UShort as a decimal number.
     * @return a String representation of this UShort as a decimal number.
     */
    public def toString(): String = toString(10);

    /**
     * @deprecated use {@link #parse(String,Int)} instead
     */
    public static def parseUShort(s:String, radix:Int): UShort = parse(s, radix);

    /**
     * @deprecated use {@link #parse(String)} instead
     */
    public static def parseUShort(s:String): UShort = parse(s);

    /**
     * Parses the String argument as a UShort in the radix specified by the second argument.
     * @param s the String containing the UShort representation to be parsed
     * @param radix the radix to be used while parsing s
     * @return the UShort represented by the String argument in the specified radix.
     * @throws NumberFormatException if the String does not contain a parsable UShort.
     */
    // @Native("java", "((short) (java.lang.Integer.parseInt(#s, #radix) & 0xffff))")
    @Native("c++", "x10aux::short_utils::parseUShort(#1, #2)")
    public native static def parse(s:String, radix:Int): UShort; //throwsNumberFormatException

    /**
     * Parses the String argument as a decimal UShort.
     * @param s the String containing the UShort representation to be parsed
     * @return the UShort represented by the String argument.
     * @throws NumberFormatException if the String does not contain a parsable UShort.
     */
    public static def parse(s:String): UShort = parse(s, 10);


    /**
     * Returns the value obtained by reversing the order of the bits in the
     * binary representation of this UShort.
     * @return the value obtained by reversing order of the bits in this UShort.
     */
    public def reverse(): UShort {
        var x : UShort = this;
        x = (x & 0x5555US) << 1 | ((x>>>1) & 0x5555US);
        x = (x & 0x3333US) << 2 | ((x>>>2) & 0x3333US);
        x = (x & 0x0F0FUS) << 4 | ((x>>>4) & 0x0F0FUS);
        return x.reverseBytes();
    }

    /**
     * Returns the signum function of this UShort.  The return value is 0 if
     * this UShort is zero and 1 if this UShort is non-zero.
     * @return the signum function of this UShort.
     */
    public def signum(): Int = this > 0US ? 1 : 0;

    /**
     * Returns the value obtained by reversing the order of the bytes in the
     * representation of this UShort.
     * @return the value obtained by reversing (or, equivalently, swapping) the bytes in this UShort.
     */
    public def reverseBytes(): UShort {
        return (this << 8) | (this >> 8);
    }

    /**
     * Return true if the given entity is a UShort, and this UShort is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this UShort is equal to the given entity.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0, #1)")
    public def equals(x:Any):Boolean {
        if(x instanceof UShort) {
            return equals(x as UShort);
        }
        return false;
    }

    /**
     * Returns true if this UShort is equal to the given UShort.
     * @param x the given UShort
     * @return true if this UShort is equal to the given UShort.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0, #1)")
    public native def equals(x:UShort):Boolean;

    public def hashCode(): Int = this as Short;

    /**
    * Returns a negative Int, zero, or a positive Int if this UShort is less than, equal
    * to, or greater than the given UShort.
    * @param x the given UShort
    * @return a negative Int, zero, or a positive Int if this UShort is less than, equal
    * to, or greater than the given UShort.
    */
    public def compareTo(x:UShort): Int = this == x ? 0 : this < x ? -1 : 1;
}
