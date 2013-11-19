package invasic;

import x10.compiler.LinkSymbol;
import x10.lang.Pointer;

public class Memory {
    @LinkSymbol("mem_free_tlm")
    public static native def free(p: Pointer): void;

    @LinkSymbol("mem_get_global_address")
    public static native def getGlobalAddress(p: Pointer): Pointer;

    @LinkSymbol("mem_get_local_address")
    public static native def getLocalAddress(p: Pointer): Pointer;
}
