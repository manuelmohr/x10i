package octopos;

import x10.compiler.OpaqueHandle;

@OpaqueHandle
public final struct EthReadChannel {
    /** Opens a new ethernet communication channel for reading. */
    public static native def open(channelId: UShort): EthReadChannel;

    /**
     * Starts an asynchronous reading request. The request will be completed
     * at the next finish {} barrier.
     * Note: buffer must be located in tile local memory.
     */
    public final native def readAsync(buffer: Pointer, size: Int): void;

    private def this(): EthReadChannel;
}
