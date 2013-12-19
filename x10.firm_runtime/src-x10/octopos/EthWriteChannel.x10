package octopos;

import x10.compiler.OpaqueHandle;

@OpaqueHandle
public final struct EthWriteChannel {
    public static native def open(channel: UShort): EthWriteChannel;

    /**
     * Starts an asynchronous writing request. The request will be completed
     * when the next finish {} barrier is crossed.
     * Note: buffer must be located in tile local memory.
     */
    public final native def writeAsync(buffer: Pointer, size: Int): void;

    /** no public constructor */
    private def this() : EthWriteChannel;
}
