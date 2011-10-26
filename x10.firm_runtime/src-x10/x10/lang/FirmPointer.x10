
package x10.lang;

import x10.compiler.Native;
import x10.compiler.NativeRep;
import x10.util.Ordered;

public struct FirmPointer implements Comparable[FirmPointer] {
  public static native def read[T](x: FirmPointer) : T;
  public static native def write[T](x: FirmPointer, val y: T) : void;
  
  public native operator this +(x : Long) : FirmPointer;
  public native operator this -(x : Long) : FirmPointer;
  public native operator this -(x : FirmPointer)  : Long;
  public native operator this <(x : FirmPointer)  : Boolean;
  public native operator this >(x : FirmPointer)  : Boolean;
  public native operator this <=(x : FirmPointer) : Boolean;
  public native operator this >=(x : FirmPointer) : Boolean;
  
  public native def compareTo(x:FirmPointer) : Int;
}

