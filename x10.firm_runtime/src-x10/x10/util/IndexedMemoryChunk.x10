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
 * contains a dense, indexed from 0 collection of
 * values of type T.<p>
 *
 * This abstraction is provide to enable other higher-level
 * abstractions (such as Array) to be implemented efficiently
 * and to allow low-level programming of memory regions at the
 * X10 level when absolutely required for performance. Most of the API
 * of this class is safe, but there are some loopholes that can be
 * used when absolutely necessary for performance..<p>
 */
public struct IndexedMemoryChunk[T] {
    // Pointer to the allocated memory
    private val ptr: Pointer;
    // Length of the allocated memory chunk (number of Ts not number of bytes)
    private val length: Int;

    public def this(ptr: Pointer, length: Int) {
        this.ptr = ptr;
        this.length = length;
    }

    /** unused; prevent instantiaton outside of native code */
    private native def this();

    private static def calculateSize[T](length: Int): Int {
        /* TODO: check for overflow */
        return length * NativeSupport.getSize[T]();
    }

    private def calculateIndex(i: Int): Pointer {
        return ptr + calculateSize[T](i);
    }

    public static def allocateUninitialized[T](length: Int): IndexedMemoryChunk[T] {
        val size = calculateSize[T](length);
        val ptrFree = NativeSupport.isPointerFree[T]();
        val memory = ptrFree ? NativeSupport.allocAtomic(size) : NativeSupport.alloc(size);
        return IndexedMemoryChunk[T](memory, length);
    }

    public static def allocateZeroed[T](length: Int): IndexedMemoryChunk[T]{T haszero} {
        val size = calculateSize[T](length);
        val ptrFree = NativeSupport.isPointerFree[T]();
        val memory = ptrFree ? NativeSupport.allocAtomicZeroed(size) : NativeSupport.allocZeroed(size);
        return IndexedMemoryChunk[T](memory, length);
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
    public static def resize[T](old: IndexedMemoryChunk[T], newLength: Int): IndexedMemoryChunk[T] {
        val prevSize = calculateSize[T](old.length);
        val newSize = calculateSize[T](newLength);
        val newptr = NativeSupport.realloc(old.ptr, prevSize, newSize);
        return IndexedMemoryChunk[T](newptr, newLength);
    }

    /**
     * Resizes the indexed memory chunk, set new elements to zero. Returns a new
     * IndexedMemoryChunk, the old one is not valid anymore after this call.
     */
    public static def resizeZeroed[T](old: IndexedMemoryChunk[T], newLength: Int): IndexedMemoryChunk[T] {
        val prevSize = calculateSize[T](old.length);
        val newSize = calculateSize[T](newLength);
        val newptr = NativeSupport.reallocZeroed(old.ptr, prevSize, newSize);
        return IndexedMemoryChunk[T](newptr, newLength);
    }

    /**
     * Operator that allows access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    public operator this(index: Int): T {
        val p = calculateIndex(index);
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
        val p = calculateIndex(index);
        p.write[T](value);
    }

    /**
     * Clears numElems of the backing storage starting at index start
     * by zeroing the storage.  Note that this is intentionally not
     * type safe because it does require T hasZero.
     */
    public def clear(index: Int, length: Int): void {
        val p    = calculateIndex(index);
        val size = calculateSize[T](length);
        NativeSupport.memset(p, 0, size);
    }

    /**
     * Operator that allows UNSAFE access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    public def length(): Int = length;

    /**
     * Return pointer to data (unsafe)
     */
    public def pointer(): Pointer = ptr;

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
        val srcPtr = src.calculateIndex(srcIndex);
        val dstPtr = dst.calculateIndex(dstIndex);
        val size   = calculateSize[T](numElems);
        NativeSupport.memcpy(dstPtr, srcPtr, size);
    }

    public def toString(): String = "IndexedMemoryChunk:" + ptr;
    public def equals(that: Any): Boolean {
        if (!(that instanceof IndexedMemoryChunk[T]))
            return false;
        val other = that as IndexedMemoryChunk[T];
        return other.ptr == ptr && other.length == length;
    }
    public def hashCode(): Int = ptr.hashCode();
}

// vim:shiftwidth=4:tabstop=4:expandtab
