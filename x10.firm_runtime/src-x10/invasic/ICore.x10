package invasic;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

public class ICore {
    @LinkSymbol("icore_is_on_icore")
    public static native def isOnICore(): Boolean;

    @LinkSymbol("icore_init_fmm")
    public static native def initFmm(): void;

    @LinkSymbol("icore_init_sift")
    public static native def initSift(): void;

    @LinkSymbol("icore_fmm")
    public static native def fmm(matrix0: Pointer, matrix1: Pointer, dest: Pointer): void;

    @LinkSymbol("icore_sift")
    public static native def sift(vector0: Pointer, vector1: Pointer): Float;

    public static def fmm(matrix0: Array[Float], matrix1: Array[Float], result: Array[Float]) {
        fmm(matrix0.raw().pointer(), matrix1.raw().pointer(), result.raw().pointer());
    }

    public static def sift(vector0: Array[Float], vector1: Array[Float]): Float {
        return sift(vector0.raw().pointer(), vector1.raw().pointer());
    }
}
