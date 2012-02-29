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
 * UByte is an 8-bit unsigned integral data type, with
 * values ranging from 0 to 255, inclusive.  All of the normal
 * arithmetic and bitwise operations are defined on UByte, and UByte
 * is closed under those operations.  There are also static methods
 * that define conversions from other data types, including String,
 * as well as some UByte constants.
 */
// @NativeRep("java", "byte", null, "x10.rtt.Types.UBYTE")
@NativeRep("c++", "x10_ubyte", "x10_ubyte", null)
public struct UByte implements Comparable[UByte] /*TODO implements Arithmetic[UByte], Bitwise[UByte], Ordered[UByte]*/ {

    /** The actual number with Byte representation */
    /* [FIRM_CHANGE] */
    /*
    public val byteVal:Byte;
    public def this(value:Byte) {
        this.byteVal = value;
    }
    */

    /**
     * A less-than operator.
     * Compares this UByte with another UByte and returns true if this UByte is
     * strictly less than the other UByte.
     * @param x the other UByte
     * @return true if this UByte is strictly less than the other UByte.
     */
    // @Native("java", "x10.core.Unsigned.lt(#this, #x)")
    @Native("c++",  "((#0) < (#1))")
     /* [FIRM_CHANGE] */
    public native operator this < (x:UByte): Boolean;

    /**
     * A greater-than operator.
     * Compares this UByte with another UByte and returns true if this UByte is
     * strictly greater than the other UByte.
     * @param x the other UByte
     * @return true if this UByte is strictly greater than the other UByte.
     */
    // @Native("java", "x10.core.Unsigned.gt(#this, #x)")
    @Native("c++",  "((#0) > (#1))")
     /* [FIRM_CHANGE] */
    public native operator this > (x:UByte): Boolean;

    /**
     * A less-than-or-equal-to operator.
     * Compares this UByte with another UByte and returns true if this UByte is
     * less than or equal to the other UByte.
     * @param x the other UByte
     * @return true if this UByte is less than or equal to the other UByte.
     */
    // @Native("java", "x10.core.Unsigned.le(#this, #x)")
    @Native("c++",  "((#0) <= (#1))")
     /* [FIRM_CHANGE] */
    public native operator this <= (x:UByte): Boolean;

    /**
     * A greater-than-or-equal-to operator.
     * Compares this UByte with another UByte and returns true if this UByte is
     * greater than or equal to the other UByte.
     * @param x the other UByte
     * @return true if this UByte is greater than or equal to the other UByte.
     */
    // @Native("java", "x10.core.Unsigned.ge(#this, #x)")
    @Native("c++",  "((#0) >= (#1))")
     /* [FIRM_CHANGE] */
    public native operator this >= (x:UByte): Boolean;


    /**
     * A binary plus operator.
     * Computes the result of the addition of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UByte
     * @return the sum of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) + (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) + (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this + (x:UByte): UByte;

    /**
     * A binary minus operator.
     * Computes the result of the subtraction of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UByte
     * @return the difference of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) - (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) - (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this - (x:UByte): UByte;

    /**
     * A binary multiply operator.
     * Computes the result of the multiplication of the two operands.
     * Overflows result in truncating the high bits.
     * @param x the other UByte
     * @return the product of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) * (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) * (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this * (x:UByte): UByte;

    /**
     * A binary divide operator.
     * Computes the result of the division of the two operands.
     * @param x the other UByte
     * @return the quotient of this UByte and the other UByte.
     */
    // @Native("java", "((byte) x10.core.Unsigned.div(#this, #x))")
    @Native("c++",  "((x10_ubyte) ((#0) / x10aux::zeroCheck(#1)))")
     /* [FIRM_CHANGE] */
    public native operator this / (x:UByte): UByte;

    /**
     * A binary remainder operator.
     * Computes a remainder from the division of the two operands.
     * @param x the other UByte
     * @return the remainder from dividing this UByte by the other UByte.
     */
    // @Native("java", "((byte) x10.core.Unsigned.rem(#this, #x))")
    @Native("c++",  "((x10_ubyte) ((#0) % x10aux::zeroCheck(#1)))")
     /* [FIRM_CHANGE] */
    public native operator this % (x:UByte): UByte;

    /**
     * A unary plus operator.
     * A no-op.
     * @return the value of this UByte.
     */
    // @Native("java", "((byte) +(#this))")
    @Native("c++",  "((x10_ubyte) +(#0))")
     /* [FIRM_CHANGE] */
    public native operator + this: UByte;

    /**
     * A unary minus operator.
     * Computes the two's complement of the operand.
     * Overflows result in truncating the high bits.
     * @return the two's complement of this UByte.
     */
    // @Native("java", "((byte) -(#this))")
    @Native("c++",  "((x10_ubyte) -(#0))")
     /* [FIRM_CHANGE] */
    public native operator - this: UByte;


    /**
     * A bitwise and operator.
     * Computes a bitwise AND of the two operands.
     * @param x the other UByte
     * @return the bitwise AND of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) & (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) & (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this & (x:UByte): UByte;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(UByte)&(UByte)
     */
    // @Native("java", "((byte) ((#this) & (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) & (#1)))")
     /* [FIRM_CHANGE] */
    public native operator (x:Byte) & this: UByte;
    /**
     * A bitwise and operator (unsigned disambiguation).
     * @see #operator(UByte)&(UByte)
     */
    // @Native("java", "((byte) ((#this) & (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) & (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this & (x:Byte): UByte;

    /**
     * A bitwise or operator.
     * Computes a bitwise OR of the two operands.
     * @param x the other UByte
     * @return the bitwise OR of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) | (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) | (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this | (x:UByte): UByte;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(UByte)|(UByte)
     */
    // @Native("java", "((byte) ((#this) | (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) | (#1)))")
     /* [FIRM_CHANGE] */
    public native operator (x:Byte) | this: UByte;
    /**
     * A bitwise or operator (unsigned disambiguation).
     * @see #operator(UByte)|(UByte)
     */
    // @Native("java", "((byte) ((#this) | (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) | (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this | (x:Byte): UByte;

    /**
     * A bitwise xor operator.
     * Computes a bitwise XOR of the two operands.
     * @param x the other UByte
     * @return the bitwise XOR of this UByte and the other UByte.
     */
    // @Native("java", "((byte) ((#this) ^ (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) ^ (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this ^ (x:UByte): UByte;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(UByte)^(UByte)
     */
    // @Native("java", "((byte) ((#this) ^ (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) ^ (#1)))")
     /* [FIRM_CHANGE] */
    public native operator (x:Byte) ^ this: UByte;
    /**
     * A bitwise xor operator (unsigned disambiguation).
     * @see #operator(UByte)^(UByte)
     */
    // @Native("java", "((byte) ((#this) ^ (#x)))")
    @Native("c++",  "((x10_ubyte) ((#0) ^ (#1)))")
     /* [FIRM_CHANGE] */
    public native operator this ^ (x:Byte): UByte;

    /**
     * A bitwise left shift operator.
     * Computes the value of the left-hand operand shifted left by the value of the right-hand operand.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @param count the shift count
     * @return this UByte shifted left by count.
     */
    // @Native("java", "((byte) ((#this) << (0x7 & (#count))))")
    @Native("c++",  "((x10_ubyte) ((#0) << (0x7 & (#1))))")
     /* [FIRM_CHANGE] */
    public native operator this << (count:Int): UByte;

    /**
     * A bitwise right shift operator.
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @param count the shift count
     * @return this UByte shifted right by count.
     */
    // @Native("java", "((byte) ((#this) >>> (0x7 & (#count))))")
    @Native("c++",  "((x10_ubyte) ((#0) >> (0x7 & (#1))))")
     /* [FIRM_CHANGE] */
    public native operator this >> (count:Int): UByte;

    /**
     * A bitwise logical right shift operator (zero-fill).
     * Computes the value of the left-hand operand shifted right by the value of the right-hand operand,
     * filling the high bits with zeros.
     * The shift count will be masked with 0x7 before the shift is applied.
     * @deprecated use the right-shift operator.
     * @param count the shift count
     * @return this UByte shifted right by count with high bits zero-filled.
     */
    // @Native("java", "((byte) ((#this) >>> (0x7 & (#count))))")
    @Native("c++",  "((x10_ubyte) ((#0) >> (0x7 & (#1))))")
     /* [FIRM_CHANGE] */
    public native operator this >>> (count:Int): UByte;

    /**
     * A bitwise complement operator.
     * Computes a bitwise complement (NOT) of the operand.
     * @return the bitwise complement of this UByte.
     */
    // @Native("java", "((byte) ~(#this))")
    @Native("c++",  "((x10_ubyte) ~(#0))")
     /* [FIRM_CHANGE] */
    public native operator ~ this: UByte;

    /**
     * Convert a given UShort to a UByte.
     * @param x the given UShort
     * @return the given UShort converted to a UByte.
     */
    // @Native("java", "((byte)(short)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:UShort) as UByte;

    /**
     * Convert a given UInt to a UByte.
     * @param x the given UInt
     * @return the given UInt converted to a UByte.
     */
    // @Native("java", "((byte)(int)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:UInt) as UByte;

    /**
     * Convert a given ULong to a UByte.
     * @param x the given ULong
     * @return the given ULong converted to a UByte.
     */
    // @Native("java", "((byte)(long)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:ULong) as UByte;


    /**
     * Convert a given Short to a UByte.
     * @param x the given Short
     * @return the given Short converted to a UByte.
     */
    // @Native("java", "((byte)(short)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:Short) as UByte;

    /**
     * Convert a given Int to a UByte.
     * @param x the given Int
     * @return the given Int converted to a UByte.
     */
    // @Native("java", "((byte)(int)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:Int) as UByte;

    /**
     * Convert a given Long to a UByte.
     * @param x the given Long
     * @return the given Long converted to a UByte.
     */
    // @Native("java", "((byte)(long)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:Long) as UByte;

    /**
     * Convert a given Float to a UByte.
     * @param x the given Float
     * @return the given Float converted to a UByte.
     */
    // @Native("java", "x10.core.Floats.toUByte(#x)")
    @Native("c++",  "x10aux::float_utils::toUByte(#1)")
     /* [FIRM_CHANGE] */
    public native static operator (x:Float) as UByte;

    /**
     * Convert a given Double to a UByte.
     * @param x the given Double
     * @return the given Double converted to a UByte.
     */
    // @Native("java", "x10.core.Floats.toUByte(#x)")
    @Native("c++",  "x10aux::double_utils::toUByte(#1)")
     /* [FIRM_CHANGE] */
    public native static operator (x:Double) as UByte;

    /**
     * Coerce a given Byte to a UByte.
     * @param x the given Byte
     * @return the given Byte converted to a UByte.
     */
    // @Native("java", "((byte)(#x))")
    @Native("c++",  "((x10_ubyte) (#1))")
     /* [FIRM_CHANGE] */
    public native static operator (x:Byte) as UByte;


    /**
     * A constant holding the minimum value a UByte can have, 0.
     */
    // @Native("java", "0")
    @Native("c++", "((x10_ubyte)0U)")
    public static MIN_VALUE: UByte{self==0UY} = 0UY;

    /**
     * A constant holding the maximum value a UByte can have, 2<sup>8</sup>-1.
     */
    // @Native("java", "((byte)0xff)")
    @Native("c++", "((x10_ubyte)0xffU)")
    public static MAX_VALUE: UByte{self==0xffUY} = 0xffUY;


    /**
     * Returns a String representation of this UByte in the specified radix.
     * @param radix the radix to use in the String representation
     * @return a String representation of this UByte in the specified radix.
     */
    public native def toString(radix:Int): String;

    /**
     * Returns a String representation of this UByte as a hexadecimal number.
     * @return a String representation of this UByte as a hexadecimal number.
     */
    public def toHexString(): String = toString(16);

    /**
     * Returns a String representation of this UByte as an octal number.
     * @return a String representation of this UByte as an octal number.
     */
    public def toOctalString(): String = toString(8);

    /**
     * Returns a String representation of this UByte as a binary number.
     * @return a String representation of this UByte as a binary number.
     */
    public def toBinaryString(): String = toString(2);

    /**
     * Returns a String representation of this UByte as a decimal number.
     * @return a String representation of this UByte as a decimal number.
     */
    public def toString(): String = toString(10);

    /**
     * @deprecated use {@link #parse(String,Int)} instead
     */
    public static def parseUByte(s:String, radix:Int): UByte = parse(s, radix);

    /**
     * @deprecated use {@link #parse(String)} instead
     */
    public static def parseUByte(s:String): UByte = parse(s);

    /**
     * Parses the String argument as a UByte in the radix specified by the second argument.
     * @param s the String containing the UByte representation to be parsed
     * @param radix the radix to be used while parsing s
     * @return the UByte represented by the String argument in the specified radix.
     * @throws NumberFormatException if the String does not contain a parsable UByte.
     */
    // @Native("java", "((byte) (java.lang.Integer.parseInt(#s, #radix) & 0xff))")
    @Native("c++", "(x10aux::byte_utils::parseUByte(#1, #2))")
     /* [FIRM_CHANGE] */
    public native static def parse(s:String, radix:Int): UByte; //throws NumberFormatException 

    /**
     * Parses the String argument as a decimal UByte.
     * @param s the String containing the UByte representation to be parsed
     * @return the UByte represented by the String argument.
     * @throws NumberFormatException if the String does not contain a parsable UByte.
     */
    public static def parse(s:String): UByte = parse(s, 10);

    /**
     * Returns the value obtained by reversing the order of the bits in the
     * binary representation of this UByte.
     * @return the value obtained by reversing order of the bits in this UByte.
     */
    // @Native("java", "((byte)(java.lang.Integer.reverse(#this)>>>24))")
    @Native("c++", "((x10_ubyte)(x10aux::int_utils::reverse(#0)>>24))")
     /* [FIRM_CHANGE] */
    public native def reverse(): UByte;

    /**
     * Returns the signum function of this UByte.  The return value is 0 if
     * this UByte is zero and 1 if this UByte is non-zero.
     * @return the signum function of this UByte.
     */
    public def signum(): Int = this > 0 as UByte ? 1 : 0;


    /**
     * Return true if the given entity is a UByte, and this UByte is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this UByte is equal to the given entity.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
     /* [FIRM_CHANGE] */
    public def equals(x:Any):Boolean {
    	if(x instanceof UByte) {
    		return equals(x as UByte); 
    	}
    	return false;
    }

    /**
     * Returns true if this UByte is equal to the given UByte.
     * @param x the given UByte
     * @return true if this UByte is equal to the given UByte.
     */
    // @Native("java", "x10.rtt.Equality.equalsequals(#this, #x)")
    @Native("c++", "x10aux::equals(#0,#1)")
     /* [FIRM_CHANGE] */
    public native def equals(x:UByte):Boolean;

    /**
    * Returns a negative Int, zero, or a positive Int if this UByte is less than, equal
    * to, or greater than the given UByte.
    * @param x the given UByte
    * @return a negative Int, zero, or a positive Int if this UByte is less than, equal
    * to, or greater than the given UByte.
    */
    // @Native("java", "x10.rtt.Equality.compareTo(#this.byteVal + java.lang.Byte.MIN_VALUE, #x.byteVal + java.lang.Byte.MIN_VALUE)")
    @Native("c++", "x10aux::_utils::compareTo(#0, #1)")
     /* [FIRM_CHANGE] */
    public native def compareTo(x:UByte): Int;
}
