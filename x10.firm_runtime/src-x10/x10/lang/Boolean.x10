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

/**
 * Boolean is a logical data type, with two values: 'true' and 'false'.
 * All of the normal logical operations are defined on Boolean.
 * There are also static methods that define conversions to and from String,
 * as well as some Boolean constants.
 */
@NativeRep("java", "boolean", null, "x10.rtt.Types.BOOLEAN")
@NativeRep("c++", "x10_boolean", "x10_boolean", null)
public struct Boolean implements Comparable[Boolean] {


    /**
     * A logical complement operator.
     * Computes a logical complement of this Boolean.
     * @return the logical complement of this Boolean.
     */
    @Native("java", "!(#this)")
    @Native("c++",  "!(#0)")
    public native operator ! this: Boolean;

    /**
     * A logical and operator (not short-circuiting).
     * Computes a logical AND of this Boolean and the other Boolean.
     * Evaluates both arguments.
     * @param x the other Boolean
     * @return the logical AND of this Boolean and the other Boolean.
     */
    @Native("java", "((#this) & (#x))")
    @Native("c++",  "((x10_boolean) (((#0) ? 1 : 0) & ((#1) ? 1 : 0)))")
    public native operator this & (x:Boolean): Boolean;

    /**
     * A logical or operator (not short-circuiting).
     * Computes a logical OR of this Boolean and the other Boolean.
     * Evaluates both arguments.
     * @param x the other Boolean
     * @return the logical OR of this Boolean and the other Boolean.
     */
    @Native("java", "((#this) | (#x))")
    @Native("c++",  "((x10_boolean) (((#0) ? 1 : 0) | ((#1) ? 1 : 0)))")
    public native operator this | (x:Boolean): Boolean;

    /**
     * A logical xor operator.
     * Computes a logical XOR of this Boolean and the other Boolean.
     * @param x the other Boolean
     * @return the logical XOR of this Boolean and the other Boolean.
     */
    @Native("java", "((#this) ^ (#x))")
    @Native("c++",  "((x10_boolean) (((#0) ? 1 : 0) ^ ((#1) ? 1 : 0)))")
    public native operator this ^ (x:Boolean): Boolean;


    /**
     * A constant holding the Boolean value 'true'.
     */
    @Native("java", "true")
    @Native("c++", "true")
    public static TRUE: Boolean{self==true} = true;

    /**
     * A constant holding the Boolean value 'false'.
     */
    @Native("java", "false")
    @Native("c++", "false")
    public static FALSE: Boolean{self==false} = false;


    /**
     * Returns a String representation of this Boolean.
     * @return a string representation of this Boolean.
     */
    public def toString(): String {
        return this ? "true" : "false";
    }

    /**
     * @deprecated use {@link #parse(String)} instead
     */
    public static def parseBoolean(s:String): Boolean = parse(s);

    /**
     * Parses the String argument as a Boolean.
     * The Boolean returned represents the value 'true' if the String argument
     * is not null and is equal, ignoring case, to the string "true".
     * @param s the String containing the Boolean representation to be parsed
     * @return the Boolean represented by the String argument.
     */
    public static def parse(s:String): Boolean {
        return s.equalsIgnoreCase("true");
    }

    /**
     * Return true if the given entity is a Boolean, and this Boolean is equal
     * to the given entity.
     * @param x the given entity
     * @return true if this Boolean is equal to the given entity.
     */
    public def equals(x:Any):Boolean {
        if(x instanceof Boolean)
            return equals(x as Boolean);
        return false;
    }

    /**
     * Returns true if this Boolean is equal to the given Boolean.
     * @param x the given Boolean
     * @return true if this Boolean is equal to the given Boolean.
     */
    public native def equals(x:Boolean):Boolean;

    public native def hashCode():Int;

    /**
    * Returns a negative Int, zero, or a positive Int if this Boolean is less than, equal
    * to, or greater than the given Boolean.
    * @param x the given Boolean
    * @return a negative Int, zero, or a positive Int if this Boolean is less than, equal
    * to, or greater than the given Boolean.
    */
    public def compareTo(x:Boolean):Int {
        return (this == x) ? 0 : this ? 1 : -1;
    }

    // These operations are built-in.  Declaring them will prevent the
    // short-circuiting behavior.

//    @Native("java", "((#x) && (#y))")
//    @Native("c++",  "((x10_boolean) (((#1) ? 1 : 0) && ((#2) ? 1 : 0)))")
//    public native static operator (x:Boolean) && (y:Boolean): Boolean;
//
//    @Native("java", "((#x) || (#y))")
//    @Native("c++",  "((x10_boolean) (((#1) ? 1 : 0) || ((#2) ? 1 : 0)))")
//    public native static operator (x:Boolean) || (y:Boolean): Boolean;
}
public type Boolean(b:Boolean) = Boolean{self==b};
