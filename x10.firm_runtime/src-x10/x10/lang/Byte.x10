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
 * Byte is an 8-bit signed two's complement integral data type, with
 * values ranging from -128 to 127, inclusive.  All of the normal
 * arithmetic and bitwise operations are defined on Byte, and Byte
 * is closed under those operations.  There are also static methods
 * that define conversions from other data types, including String,
 * as well as some Byte constants.
 */
@NativeRep("java", "byte", null, "x10.rtt.Types.BYTE")
@NativeRep("c++", "x10_byte", "x10_byte", null)
public struct Byte implements Comparable[Byte] /*TODO implements Arithmetic[Byte], Bitwise[Byte], Ordered[Byte]*/ {


    /**
     * A less-than operator.
     * Compares this Byte with another Byte and returns true if this Byte is
     * strictly less than the other Byte.
     * @param x the other Byte
     * @return true if this Byte is strictly less than the other Byte.
     */
    @Native("java", "((#this) < (#x))")
    @Native("c++",  "((#0) < (#1))")
    public native operator this < (x:Byte): Boolean;

    /**
     * A greater-than operator.
     * Compares this Byte with another Byte and returns true if this Byte is
     * strictly greater than the other Byte.
     * @param x the other Byte
     * @return true if this Byte is strictly greater than the other Byte.
     */
    @Native("java", "((#this) > (#x))")
    @Native("c++",  "((#0) > (#1))")
    public native operator this > (x:Byte): Boolean;

    /**
     * A less-than-or-equal-to operator.
     * Compares this Byte with another Byte and returns true if this Byte is
     * less than or equal to the other Byte.
     * @param x the other Byte
     * @return true if this Byte is less than or equal to the other Byte.
     */
    @Native("java", "((#this) <= (#x))")
    @Native("c++",  "((#0) <= (#1))")
    public native operator this <= (x:Byte): Boolean;

    /**
     * A greater-than-or-equal-to operator.
     * Compares this Byte with another Byte and returns true if this Byte is
     * greater than or equal to the other Byte.
     * @param x the other Byte
     * @return true if this Byte is greater than or equal to the other Byte.
     */
    @Native("java", "((#this) >= (#x))")
    @Native("c++",  "((#0) >= (#1))")
    public native operator this >= (x:Byte): Boolean;


    /**
     * A binary plus operator.
     * Computes the result of the addition of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Byte
     * @return the sum of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) + (#x)))")
    @Native("c++",  "((x10_byte) ((#0) + (#1)))")
    public native operator this + (x:Byte): Byte;

    /**
     * A binary minus operator.
     * Computes the result of the subtraction of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Byte
     * @return the difference of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) - (#x)))")
    @Native("c++",  "((x10_byte) ((#0) - (#1)))")
    public native operator this - (x:Byte): Byte;

    /**
     * A binary multiply operator.
     * Computes the result of the multiplication of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other Byte
     * @return the product of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) * (#x)))")
    @Native("c++",  "((x10_byte) ((#0) * (#1)))")
    public native operator this * (x:Byte): Byte;

    /**
     * A binary divide operator.
     * Computes the result of the division of the two operands.
     * @param x the other Byte
     * @return the quotient of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) / (#x)))")
    @Native("c++",  "((x10_byte) ((#0) / x10aux::zeroCheck(#1)))")
    public native operator this / (x:Byte): Byte;

    /**
     * A binary remainder operator.
     * Computes a remainder from the division of the two operands.
     * @param x the other Byte
     * @return the remainder from dividing this Byte by the other Byte.
     */
    @Native("java", "((byte) ((#this) % (#x)))")
    @Native("c++",  "((x10_byte) ((#0) % x10aux::zeroCheck(#1)))")
    public native operator this % (x:Byte): Byte;

    /**
     * A unary plus operator.
     * A no-op.
     * @return the value of this Byte.
     */
    @Native("java", "((byte) +(#this))")
    @Native("c++",  "((x10_byte) +(#0))")
    public native operator + this: Byte;

    /**
     * A unary minus operator.
     * Negates the operand.
     * Overflows result in truncating the high bits.
     * @return the negated value of this Byte.
     */
    @Native("java", "((byte) -(#this))")
    @Native("c++",  "((x10_byte) -(#0))")
    public native operator - this: Byte;


    /**
     * A bitwise and operator.
     * Computes a bitwise AND of the two operands.
     * @param x the other Byte
     * @return the bitwise AND of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) & (#x)))")
    @Native("c++",  "((x10_byte) ((#0) & (#1)))")
    public native operator this & (x:Byte): Byte;

    /**
     * A bitwise or operator.
     * Computes a bitwise OR of the two operands.
     * @param x the other Byte
     * @return the bitwise OR of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) | (#x)))")
    @Native("c++",  "((x10_byte) ((#0) | (#1)))")
    public native operator this | (x:Byte): Byte;

    /**
     * A bitwise xor operator.
     * Computes a bitwise XOR of the two operands.
     * @param x the other Byte
     * @return the bitwise XOR of this Byte and the other Byte.
     */
    @Native("java", "((byte) ((#this) ^ (#x)))")
    @Native("c++",  "((x10_byte) ((#0) ^ (#1)))")
    public native operator this ^ (x:Byte): Byte;

    /**
     * A bitwise left shift operator.
     * Computes the value of the left-hand operand shifted left by the value of the right-hand operand.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @param count the shift count
     * @return this Byte shifted left by count.
     */
    @Native("java", "((byte) ((#this) << (0x7 & (#count))))")
    @Native("c++",  "((x10_byte) ((#0) << (0x7 & (#1))))")
    public native operator this << (count:Int): Byte;

    /**
     * A bitwise right shift operator.
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * replicating the sign bit into the high bits.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @param count the shift count
     * @return this Byte shifted right by count.
     */
    @Native("java", "((byte) ((#this) >> (0x7 & (#count))))")
    @Native("c++",  "((x10_byte) ((#0) >> (0x7 & (#1))))")
    public native operator this >> (count:Int): Byte;

    /**
     * A bitwise logical right shift operator (zero-fill).
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @deprecated use the right-shift operator and unsigned conversions instead.
     * @param count the shift count
     * @return this Byte shifted right by count with high bits zero-filled.
     */
    @Native("java", "((byte) ((#this) >>> (0x7 & (#count))))")
    @Native("c++",  "((x10_byte) ((x10_uint) (#0) >> (0x7 & (#1))))")
    public native operator this >>> (count:Int): Byte;

    /**
     * A bitwise complement operator.
     * Computes a bitwise complement (NOT) of the operand.
     * @return the bitwise complement of this Byte.
     */
    @Native("java", "((byte) ~(#this))")
    @Native("c++",  "((x10_byte) ~(#0))")
    public native operator ~ this: Byte;


    /**
     * Convert a given Short to a Byte.
     * @param x the given Short
     * @return the given Short converted to a Byte.
     */
    @Native("java", "((byte)(short)(#x))")
    @Native("c++",  "((x10_byte) (#1))")
    public native static operator (x:Short) as Byte;

    /**
     * Convert a given Int to a Byte.
     * @param x the given Int
     * @return the given Int converted to a Byte.
     */
    @Native("java", "((byte)(int)(#x))")
    @Native("c++",  "((x10_byte) (#1))")
    public native static operator (x:Int) as Byte;

    /**
     * Convert a given Long to a Byte.
     * @param x the given Long
     * @return the given Long converted to a Byte.
     */
    @Native("java", "((byte)(long)(#x))")
    @Native("c++",  "((x10_byte) (#1))")
    public native static operator (x:Long) as Byte;

    /**
     * Convert a given Float to a Byte.
     * @param x the given Float
     * @return the given Float converted to a Byte.
     */
    @Native("java", "x10.core.Floats.toByte(#x)")
    @Native("c++",  "x10aux::float_utils::toByte(#1)")
    public native static operator (x:Float) as Byte;

    /**
     * Convert a given Double to a Byte.
     * @param x the given Double
     * @return the given Double converted to a Byte.
     */
    @Native("java", "x10.core.Floats.toByte(#x)")
    @Native("c++",  "x10aux::double_utils::toByte(#1)")
    public native static operator (x:Double) as Byte;

    /**
     * Coerce a given UByte to a Byte.
     * @param x the given UByte
     * @return the given UByte converted to a Byte.
     */
    @Native("java", "((byte)(#x.byteVal))")
    @Native("c++",  "((x10_byte) (#1))")
    public native static operator (x:UByte) as Byte;


    /**
     * A constant holding the minimum value a Byte can have, -2<sup>7</sup>.
     */
    @Native("java", "java.lang.Byte.MIN_VALUE")
    @Native("c++", "((x10_byte)0x80)")
    public static MIN_VALUE: Byte{self==0x80Y} = 0x80Y;

    /**
     * A constant holding the maximum value a Byte can have, 2<sup>7</sup>-1.
     */
    @Native("java", "java.lang.Byte.MAX_VALUE")
    @Native("c++", "((x10_byte)0x7f)")
    public static MAX_VALUE: Byte{self==0x7fY} = 0x7fY;

    /**
     * Returns a String representation of this Byte in the specified radix.
     * @param radix the radix to use in the String representation
     * @return a String representation of this Byte in the specified radix.
     */
    @Native("java", "x10.core.Signed.toString(#this, #radix)")
    @Native("c++", "x10aux::byte_utils::toString(#0, #1)")
    public native def toString(radix:Int): String;

    /**
     * Returns a String representation of this Byte as a hexadecimal number.
     * @return a String representation of this Byte as a hexadecimal number.
     */
    @Native("java", "x10.core.Signed.toString(#this, 16)")
    @Native("c++", "x10aux::byte_utils::toHexString(#0)")
    public native def toHexString(): String;

    /**
     * Returns a String representation of this Byte as an octal number.
     * @return a String representation of this Byte as an octal number.
     */
    @Native("java", "x10.core.Signed.toString(#this, 8)")
    @Native("c++", "x10aux::byte_utils::toOctalString(#0)")
    public native def toOctalString(): String;

    /**
     * Returns a String representation of this Byte as a binary number.
     * @return a String representation of this Byte as a binary number.
     */
    @Native("java", "x10.core.Signed.toString(#this, 2)")
    @Native("c++", "x10aux::byte_utils::toBinaryString(#0)")
    public native def toBinaryString(): String;

    /**
     * Returns a String representation of this Byte as a decimal number.
     * @return a String representation of this Byte as a decimal number.
     */
    @Native("java", "java.lang.Byte.toString(#this)")
    @Native("c++", "x10aux::to_string(#0)")
    public native def toString(): String;

    /**
     * @deprecated use {@link #parse(String,Int)} instead
     */
    // @Native("java", "x10.core.Signed.parseByte(#s, #radix)")
    @Native("java", "java.lang.Byte.parseByte(#s, #radix)")
    @Native("c++", "x10aux::byte_utils::parseByte(#1, #2)")
    public native static def parseByte(s:String, radix:Int): Byte; //throwsNumberFormatException;

    /**
     * @deprecated use {@link #parse(String)} instead
     */
    // @Native("java", "x10.core.Signed.parseByte(#s)")
    @Native("java", "java.lang.Byte.parseByte(#s)")
    @Native("c++", "x10aux::byte_utils::parseByte(#1)")
    public native static def parseByte(s:String): Byte ; //throwsNumberFormatException;

    /**
     * Parses the String argument as a Byte in the radix specified by the second argument.
     * @param s the String containing the Byte representation to be parsed
     * @param radix the radix to be used while parsing s
     * @return the Byte represented by the String argument in the specified radix.
     * @; //throwsNumberFormatException if the String does not contain a parsable Byte.
     */
    // @Native("java", "x10.core.Signed.parseByte(#s, #radix)")
    @Native("java", "java.lang.Byte.parseByte(#s, #radix)")
    @Native("c++", "x10aux::byte_utils::parseByte(#1, #2)")
    public native static def parse(s:String, radix:Int): Byte ; //throwsNumberFormatException;

    /**
     * Parses the String argument as a decimal Byte.
     * @param s the String containing the Byte representation to be parsed
     * @return the Byte represented by the String argument.
     * @throws NumberFormatException if the String does not contain a parsable Byte.
     */
    // @Native("java", "x10.core.Signed.parseByte(#s)")
    @Native("java", "java.lang.Byte.parseByte(#s)")
    @Native("c++", "x10aux::byte_utils::parseByte(#1)")
    public native static def parse(s:String): Byte ; //throwsNumberFormatException;


    /**
     * Returns the value obtained by reversing the order of the bits in the
     * two's complement binary representation of this Byte.
     * @return the value obtained by reversing order of the bits in this Byte.
     */
    @Native("java", "((byte)(java.lang.Integer.reverse(#this)>>>24))")
    @Native("c++", "((x10_byte)(x10aux::int_utils::reverse(#0)>>24))")
    public native def reverse(): Byte;

    /**
     * Returns the signum function of this Byte.  The return value is -1 if
     * this Byte is negative; 0 if this Byte is zero; and 1 if this Byte is
     * positive.
     * @return the signum function of this Byte.
     */
    @Native("java", "java.lang.Integer.signum(#this)")
    @Native("c++", "x10aux::int_utils::signum((x10_int)#0)")
    public native def signum(): Int;


    /**
     * Return true if the given entity is a Byte, and this Byte is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this Byte is equal to the given entity.
     */
    @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    public native def equals(x:Any):Boolean;

    /**
     * Returns true if this Byte is equal to the given Byte.
     * @param x the given Byte
     * @return true if this Byte is equal to the given Byte.
     */
    @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
    public native def equals(x:Byte):Boolean;

    /**
    * Returns a negative Int, zero, or a positive Int if this Byte is less than, equal
    * to, or greater than the given Byte.
    * @param x the given Byte
    * @return a negative Int, zero, or a positive Int if this Byte is less than, equal
    * to, or greater than the given Byte.
    */
   @Native("java", "x10.rtt.Equality.compareTo(#this, #x)")
   @Native("c++", "x10aux::byte_utils::compareTo(#0, #1)")
   public native def compareTo(x:Byte):Int;
}
public type Byte(b:Byte) = Byte{self==b};