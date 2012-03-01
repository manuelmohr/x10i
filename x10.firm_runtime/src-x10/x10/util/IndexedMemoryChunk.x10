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

package x10.util;

import x10.compiler.Header;
import x10.compiler.Inline;
import x10.compiler.Native;
import x10.compiler.NativeRep;

/**
 * A low-level abstraction of a chunk of memory that
 * contains a dense, indexed from 0 collection of values of type T.<p>
 *
 * This abstraction is provide to enable other higher-level
 * abstractions (such as Array) to be implemented efficiently
 * and to allow low-level programming of memory regions at the
 * X10 level when absolutely required for performance.
 *
 * This class performs unsafe memory operations, no bounds checking is
 * performed. Use Array[] if you need safe access.
 */
public struct IndexedMemoryChunk[T] {
    // Pointer to the allocated aligned memory
    private val ptr: Pointer;

    private def this(ptr: Pointer) {
        this.ptr = ptr;
    }

    /** unused; prevent instantiaton outside of native code */
    private native def this();

    private static def calculateSize[T](numElements: Int): Int {
        /* TODO: check for overflow */
        return numElements * NativeSupport.getSize[T]();
    }

    public static def allocateUninitialized[T](numElements: Int): IndexedMemoryChunk[T] {
        val size   = calculateSize[T](numElements);
        val memory = NativeSupport.alloc(size);
        return IndexedMemoryChunk[T](memory);
    }

    public static def allocateZeroed[T](numElements: Int): IndexedMemoryChunk[T]{T haszero} {
        val size   = calculateSize[T](numElements);
        val memory = NativeSupport.alloc(size);
        return IndexedMemoryChunk[T](memory);
    }

    /**
     * Deallocate the backing storage for the IndexedMemoryChunk and
     * set its length to 0.  This is an unsafe operation, as other
     * IndexedMemoryChunks might have been created by copying this
     * IndexedMemoryChunk and will contain dangling pointers to the
     * freed memory.  This operation should only be called when
     * the caller is certain that no such copies of the IMC exist.
     */
    public def deallocate(): void {
        NativeSupport.dealloc(ptr);
    }

    /**
     * Operator that allows access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    public operator this(index: Int): T {
        val p = ptr + index*NativeSupport.getSize[T]();
        return p.read[T]();
    }

    /**
     * Operator that allows assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    public operator this(index: Int) = (value: T): void {
        val p = ptr + index*NativeSupport.getSize[T]();
        p.write[T](value);
    }

    /**
     * Clears numElems of the backing storage starting at index start
     * by zeroing the storage.  Note that this is intentionally not
     * type safe because it does require T hasZero.
     */
    public def clear(index: Int, numElems: Int): void {
        val p    = ptr + index*NativeSupport.getSize[T]();
        val size = numElems * NativeSupport.getSize[T]();
        NativeSupport.memset(p, 0, size);
    }

    /**
     * Copies a contiguous portion of a local IndexedMemoryChunk
     * to a destination RemoteIndexedMemoryChunk at the specified place.
     * If the destination place is the current place, then the copy happens synchronously.
     * If the destination place is not the same as the current place, then
     * the copy happens asynchronously and the created remote activity will be
     * registered with the dynamically enclosing finish of the activity that invoked
     * asyncCopyTo.</p>
     *
     * Note: This copy is a "raw" copy of the bytes from one indexed memory chunk
     *       to another. If elements of type T contain references to class instances,
     *       they will not be properly serialized.  This method is intended only for use
     *       on non-pointer containing data structures.
     *
     * @param src the source IndexedMemoryChunk.
     * @param srcIndex the index of the first element to copy in the source.
     * @param dst the destination RemoteIndexedMemoryChunk.
     * @param dstIndex the index of the first element to store in the destination.
     * @param numElems the number of elements to copy.
     */
    public static native def asyncCopy[T](src:IndexedMemoryChunk[T], srcIndex: Int,
                                          dst:RemoteIndexedMemoryChunk[T], dstIndex: Int,
                                          numElems: Int):void;

    public static native def uncountedCopy[T](src:IndexedMemoryChunk[T], srcIndex: Int,
                                              dst:RemoteIndexedMemoryChunk[T], dstIndex: Int,
                                              numElems: Int,
                                              notifier:()=>void):void;

    /**
     * Copies a contiguous portion of the remote src RemoteIndexedMemoryChunk
     * into the local destination IndexedMemoryChunk.
     * If the source place is the current place, then the copy happens synchronously.
     * If the source place is not the same as the current place, then
     * the copy happens asynchronously and the created remote activity will be
     * registered with the dynamically enclosing finish of the activity that invoked
     * asyncCopyFrom.<p>
     *
     * Note: This copy is a "raw" copy of the bytes from one indexed memory chunk
     *       to another. If elements of type T contain references to class instances,
     *       they will not be properly serialized.  This method is intended only for use
     *       on non-pointer containing data structures.
     *
     * @param src the source RemoteIndexedMemoryChunk.
     * @param srcIndex the index of the first element to copy in the source.
     * @param dst the destination IndexedMemoryChunk.
     * @param dstIndex the index of the first element to store in the destination.
     * @param numElems the number of elements to copy.
     */
    public static native def asyncCopy[T](src: RemoteIndexedMemoryChunk[T], srcIndex: Int,
                                          dst: IndexedMemoryChunk[T], dstIndex: Int,
                                          numElems: Int): void;

    public static native def uncountedCopy[T](src: RemoteIndexedMemoryChunk[T], srcIndex: Int,
                                              dst: IndexedMemoryChunk[T], dstIndex: Int,
                                              numElems: Int,
                                              notifier:()=>void): void;

    /**
     * Synchronously copy a contiguous portion of the src IndexedMemoryChunk
     * into the destination IndexedMemoryChunk. Both src and dst are local.
     *
     * @param src the source IndexedMemoryChunk.
     * @param srcIndex the index of the first element to copy in the source.
     * @param dst the destination IndexedMemoryChunk.
     * @param dstIndex the index of the first element to store in the destination.
     * @param numElems the number of elements to copy.
     */
    public static def copy[T](src: IndexedMemoryChunk[T], srcIndex: Int,
                              dst: IndexedMemoryChunk[T], dstIndex: Int,
                              numElems: Int): void {
        val srcPtr = src.ptr + srcIndex*NativeSupport.getSize[T]();
        val dstPtr = dst.ptr + dstIndex*NativeSupport.getSize[T]();
        val size   = numElems * NativeSupport.getSize[T]();
        NativeSupport.memcpy(dstPtr, srcPtr, size);
    }

    public def toString(): String = "IndexedMemoryChunk:" + ptr;
    public def equals(that: Any): Boolean {
        if (!(that instanceof IndexedMemoryChunk[T]))
            return false;
        val other = that as IndexedMemoryChunk[T];
        return other.ptr == ptr;
    }
    public def hashCode(): Int = ptr.hashCode();
}
