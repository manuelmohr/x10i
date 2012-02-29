package x10.lang;

import x10.util.Ordered;

public struct Pointer implements Comparable[Pointer] {
    public static val NULL : Pointer = getNullPointer();

    public static native def read[T](x: Pointer) : T;
    public static native def write[T](x: Pointer, val y: T) : void;

    /** alignment of memory; */
    public static native def align(memPtr: Pointer, alignment: int) : Pointer;

    public native def hashCode() : Int;

    public native operator this +(x : Long) : Pointer;
    public native operator this -(x : Long) : Pointer;
    public native operator this -(x : Pointer)  : Long;
    public native operator this <(x : Pointer)  : Boolean;
    public native operator this >(x : Pointer)  : Boolean;
    public native operator this <=(x : Pointer) : Boolean;
    public native operator this >=(x : Pointer) : Boolean;

    public def compareTo(x:Pointer) : Int = this == x ? 0 : this < x ? -1 : 1;

    private static native def getNullPointer() : Pointer;
}
