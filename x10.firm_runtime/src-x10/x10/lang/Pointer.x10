package x10.lang;

import x10.util.Ordered;

import x10.compiler.LinkSymbol;

/**
 * Represent native pointers. This shoould only be used by internal library code!
 */
public struct Pointer implements Comparable[Pointer] {
    public static val NULL: Pointer = getNullPointer();

    public native def read[T](): T;
    public native def write[T](val y:T): void;

    /** alignment of memory; */
    public static native def align(memPtr:Pointer, alignment:Int): Pointer;

    public native def hashCode(): Int;
    public native def equals(other:Pointer): Boolean;
    public native def toString(): String;
    public def equals(other : Any): Boolean {
        if (!(other instanceof Pointer))
            return false;
        return equals(other as Pointer);
    }

    public static native operator (p:Pointer) + (x:Int): Pointer;
    public static operator (x:Int) + (y:Pointer): Pointer = y + x;
    public static native operator (p:Pointer) - (x:Int): Pointer;
    public static native operator (p:Pointer) - (x:Pointer): Int;
    public native operator this <(x:Pointer): Boolean;
    public native operator this >(x:Pointer): Boolean;
    public native operator this <=(x:Pointer): Boolean;
    public native operator this >=(x:Pointer): Boolean;

    public def compareTo(x:Pointer): Int = this == x ? 0 : this < x ? -1 : 1;

    private static native def getNullPointer(): Pointer;

    /** Cast pointer to type T, i.e. (T) ptr in C. */
    public native def castTo[T](): T;

    @LinkSymbol("x10_asPointer")
    public static native operator (x:Any) as Pointer;

    @LinkSymbol("x10_asPointer")
    public static native explicitAs(x:Any):Pointer;
}
