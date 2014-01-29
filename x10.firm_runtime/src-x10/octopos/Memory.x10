package octopos;

import x10.compiler.LinkSymbol;

public class Memory {
    public static native def allocateTLM(size: Int): Pointer;

    @LinkSymbol("mem_free_tlm")
    public static native def freeTLM(p: Pointer): void;

    private def this(): Memory;
}
