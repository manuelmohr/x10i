/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2011.
 */

package x10.lang;

import x10.compiler.Native;
import x10.compiler.NativeRep;
import x10.util.Ordered;

/**
 * Char is a data type representing a Unicode character.  It is not
 * an integral data type.  The "arithmetic" operations defined on
 * Char are in fact character manipulation operations.  There are
 * also static methods that define conversions from other data types,
 * including String, as well as some Char constants.
 */
@NativeRep("java", "char", null, "x10.rtt.Types.CHAR")
@NativeRep("c++", "x10_char", "x10_char", null)
public struct Char implements Comparable[Char], Ordered[Char] {
    /**
     * Convert a given Byte to a Char with that ordinal value.
     * @param x the given Byte
     * @return the Char with the same ordinal value as the given Byte.
     */
    @Native("java", "((char) (#x))")
    @Native("c++",  "(x10_char((x10_int)(#1)))")
    public native static operator (x:Byte) as Char;

    /**
     * Convert a given Short to a Char with that ordinal value.
     * @param x the given Short
     * @return the Char with the same ordinal value as the given Short.
     */
    @Native("java", "((char) (#x))")
    @Native("c++",  "(x10_char((x10_int)(#1)))")
    public native static operator (x:Short) as Char;

    /**
     * Convert a given Int to a Char with that ordinal value.
     * @param x the given Int
     * @return the Char with the same ordinal value as the given Int.
     */
    @Native("java", "((char) (#x))")
    @Native("c++",  "(x10_char(#1))")
    public native static operator (x:Int) as Char;

    /**
     * Convert a given Long to a Char with that ordinal value.
     * @param x the given Long
     * @return the Char with the same ordinal value as the given Long.
     */
    @Native("java", "((char) (#x))")
    @Native("c++",  "(x10_char((x10_int)(#1)))")
    public native static operator (x:Long) as Char;


    /**
     * Translate a given Char's ordinal value forward by the specified distance.
     * @param x the given Char
     * @param y the specified distance
     * @return the Char whose ordinal value is the sum of the given Char's ordinal value and the given distance.
     */
    public native static operator (x:Char) + (y:Int): Char;

    /**
     * Translate a given Char's ordinal value forward by the specified distance.
     * @param x the specified distance
     * @param y the given Char
     * @return the Char whose ordinal value is the sum of the given Char's ordinal value and the given distance.
     */
    public static operator (x:Int) + (y:Char): Char = y + x;

    /**
     * Translate a given Char's ordinal value backward by the specified distance.
     * @param x the given Char
     * @param y the specified distance
     * @return the Char whose ordinal value is the difference of the given Char's ordinal value and the given distance.
     */
    public native static operator (x:Char) - (y:Int): Char;

    /**
     * Compute the distance between two Chars.
     * @param x the target Char
     * @param y the source Char
     * @return the distance between the source Char and the target Char.
     */
    public native static operator (x:Char) - (y:Char): Int;


    // FIXME: Locale sensitivity
    /**
     * A less-than operator.
     * Compares this Char with another Char and returns true if this Char is
     * strictly before the other Char in dictionary order.
     * @param x the other Char
     * @return true if this Char is strictly before the other Char.
     */
    @Native("java", "((#this) < (#x))")
    @Native("c++",  "((#0) < (#1))")
    public native operator this < (x:Char): Boolean;

    // FIXME: Locale sensitivity
    /**
     * A greater-than operator.
     * Compares this Char with another Char and returns true if this Char is
     * strictly after the other Char in dictionary order.
     * @param x the other Char
     * @return true if this Char is strictly after the other Char.
     */
    @Native("java", "((#this) > (#x))")
    @Native("c++",  "((#0) > (#1))")
    public native operator this > (x:Char): Boolean;

    // FIXME: Locale sensitivity
    /**
     * A less-than-or-equal-to operator.
     * Compares this Char with another Char and returns true if this Char is
     * equal to the other Char or is before it in dictionary order.
     * @param x the other Char
     * @return true if this Char is before or equal to the other Char.
     */
    @Native("java", "((#this) <= (#x))")
    @Native("c++",  "((#0) <= (#1))")
    public native operator this <= (x:Char): Boolean;

    // FIXME: Locale sensitivity
    /**
     * A greater-than-or-equal-to operator.
     * Compares this Char with another Char and returns true if this Char is
     * equal to the other Char or is after it in dictionary order.
     * @param x the other Char
     * @return true if this Char is after or equal to the other Char.
     */
    @Native("java", "((#this) >= (#x))")
    @Native("c++",  "((#0) >= (#1))")
    public native operator this >= (x:Char): Boolean;


    /**
     * Returns a String representation of this Char.
     * @return a String representation of this Char.
     */
    @Native("java", "java.lang.Character.toString(#this)")
    @Native("c++", "x10aux::to_string(#0)")
    public native def toString(): String;


    // Duplicate the methods from java.lang.Character, changing static methods to non-static.
    // We'll ignore the code point methods for now and just include the isXXX ones.

    /**
     * Determines if this Char is a lowercase character.
     * @return true if this Char is lowercase; false otherwise.
     */
    @Native("java", "java.lang.Character.isLowerCase(#this)")
    @Native("c++", "x10aux::char_utils::isLowerCase(#0)")
    public native def isLowerCase(): boolean;

    /**
     * Determines if this Char is an uppercase character.
     * @return true if this Char is uppercase; false otherwise.
     */
    @Native("java", "java.lang.Character.isUpperCase(#this)")
    @Native("c++", "x10aux::char_utils::isUpperCase(#0)")
    public native def isUpperCase(): boolean;

    /**
     * Determines if this Char is a titlecase character.
     * @return true if this Char is titlecase; false otherwise.
     */
    @Native("java", "java.lang.Character.isTitleCase(#this)")
    @Native("c++", "x10aux::char_utils::isTitleCase(#0)")
    public native def isTitleCase(): boolean;

    /**
     * Determines if this Char is a digit.
     * @return true if this Char is a digit; false otherwise.
     */
    @Native("java", "java.lang.Character.isDigit(#this)")
    @Native("c++", "x10aux::char_utils::isDigit(#0)")
    public native def isDigit(): boolean;

    /**
     * Determines if this Char is a letter.
     * @return true if this Char is a letter; false otherwise.
     */
    @Native("java", "java.lang.Character.isLetter(#this)")
    @Native("c++", "x10aux::char_utils::isLetter(#0)")
    public native def isLetter(): boolean;

    /**
     * Determines if this Char is a letter or digit.
     * @return true if this Char is a letter or digit; false otherwise.
     */
    @Native("java", "java.lang.Character.isLetterOrDigit(#this)")
    @Native("c++", "x10aux::char_utils::isLetterOrDigit(#0)")
    public native def isLetterOrDigit(): boolean;

    /**
     * Determines if this Char is a Unicode space character.
     * A Char is considered to be a space character if and only if it
     * is specified to be a space character by the Unicode standard.
     * @return true if this Char is a space character; false otherwise.
     */
    @Native("java", "java.lang.Character.isSpaceChar(#this)")
    @Native("c++", "x10aux::char_utils::isSpaceChar(#0)")
    public native def isSpaceChar(): boolean;

    /**
     * Determines if this Char is whitespace according to X10.
     * A Char is an X10 whitespace character if and only if it serves
     * as a whitespace separator in an X10 program.
     * @return true if this Char is an X10 whitespace character; false otherwise.
     */
    @Native("java", "java.lang.Character.isWhitespace(#this)")
    @Native("c++", "x10aux::char_utils::isWhitespace(#0)")
    public native def isWhitespace(): boolean;

    /**
     * Determines if this Char is an ISO control character.
     * @return true if this Char is an ISO control character; false otherwise.
     */
    @Native("java", "java.lang.Character.isISOControl(#this)")
    @Native("c++", "x10aux::char_utils::isISOControl(#0)")
    public native def isISOControl(): boolean;

    /**
     * Converts this Char to lowercase using case mapping information from
     * the UnicodeData file.
     * @return the lowercase equivalent of this Char, if any; otherwise, the Char itself.
     */
    @Native("java", "java.lang.Character.toLowerCase(#this)")
    @Native("c++", "x10aux::char_utils::toLowerCase(#0)")
    public native def toLowerCase(): Char;

    /**
     * Converts this Char to uppercase using case mapping information from
     * the UnicodeData file.
     * @return the lowercase equivalent of this Char, if any; otherwise, the Char itself.
     */
    @Native("java", "java.lang.Character.toUpperCase(#this)")
    @Native("c++", "x10aux::char_utils::toUpperCase(#0)")
    public native def toUpperCase(): Char;

    /**
     * Converts this Char to titlecase using case mapping information from
     * the UnicodeData file.
     * If a Char has no explicit titlecase mapping and is not itself a
     * titlecase Char according to UnicodeData, then the uppercase mapping
     * is returned as an equivalent titlecase mapping.  If this Char is
     * already a titlecase Char, the same Char value will be returned.
     * @return the titlecase equivalent of this Char, if any; otherwise, the Char itself.
     */
    @Native("java", "java.lang.Character.toTitleCase(#this)")
    @Native("c++", "x10aux::char_utils::toTitleCase(#0)")
    public native def toTitleCase(): Char;

    /**
     * Returns the ordinal value of this Char.
     * @return the ordinal value of this Char.
     */
    public native def ord(): Int;

    /**
     * Return the Char with the same ordinal value as the given Int.
     * @param x the given Int
     * @return the Char with the same ordinal value as the given Int.
     */
    public static def chr(x:Int): Char = x as Char;

    /**
     * Return true if the given entity is a Byte, and this Byte is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this Byte is equal to the given entity.
     */
    public def equals(x:Any):Boolean {
        if(x instanceof Char)
            return equals(x as Char);
        return false;
    }

    /**
     * Returns true if this Byte is equal to the given Byte.
     * @param x the given Byte
     * @return true if this Byte is equal to the given Byte.
     */
    public native def equals(x:Char):Boolean;

    public def hashCode(): Int = ord();

    /**
    * Returns a negative Int, zero, or a positive Int if this Char is less than, equal
    * to, or greater than the given Char.
    * @param x the given Char
    * @return a negative Int, zero, or a positive Int if this Char is less than, equal
    * to, or greater than the given Char.
    */
   public def compareTo(x:Char):Int = this == x ? 0 : this < x ? -1 : 1;
}
public type Char(b:Char) = Char{self==b};
