
package x10.lang;

import x10.compiler.Native;
import x10.compiler.NativeRep;
import x10.util.Ordered;

public struct FirmPointer implements Comparable[FirmPointer] {

  public static val NULL : FirmPointer = getNullPointer();

  public static native def read[T](x: FirmPointer) : T;
  public static native def write[T](x: FirmPointer, val y: T) : void;
  
  /** alignment of memory; */
  public static native def align(memPtr: FirmPointer, alignment: int) : FirmPointer;
  
  public native def native_ptr() : Long;
  
  public native operator this +(x : Long) : FirmPointer;
  public native operator this -(x : Long) : FirmPointer;
  public native operator this -(x : FirmPointer)  : Long;
  public native operator this <(x : FirmPointer)  : Boolean;
  public native operator this >(x : FirmPointer)  : Boolean;
  public native operator this <=(x : FirmPointer) : Boolean;
  public native operator this >=(x : FirmPointer) : Boolean;
  
  public native def compareTo(x:FirmPointer) : Int;
  
  private static native def getNullPointer() : FirmPointer;
}

