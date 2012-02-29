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
    private val alloc_ptr: Pointer;
    // Pointer to the allocated aligned memory
    private val ptr : Pointer;
    // len of the memory chunk
    private val len: Int;

    private native static def alloc_internal(numElements: Int, sizeElement: Int, alignment: Int, congruent: Boolean, zeroed: Boolean) : Pointer;
    private native static def dealloc_internal(ptr: Pointer) : void;

    private static def checkBounds(index: Int, len: Int) :void {
        if(index >= len) {
            throw new ArrayIndexOutOfBoundsException(index + " out of bound");
        }
    }

    private static def alloc[T](numElements: Int, sizeElements: Int, alignment: Int, congruent: Boolean, zeroed: Boolean) : IndexedMemoryChunk[T] {
        if(numElements <= 0) {
            return IndexedMemoryChunk[T](Pointer.NULL, Pointer.NULL, 0);
        }

        val alloc_ptr : Pointer = alloc_internal(numElements, sizeElements, alignment, congruent, zeroed);
        val align_ptr : Pointer = Pointer.align(alloc_ptr, alignment);
        return IndexedMemoryChunk[T](alloc_ptr, align_ptr, numElements);
    }

    private def this(alloc_p: Pointer, align_p : Pointer, l: Int) {
        alloc_ptr = alloc_p;
        ptr = align_p;
        len = l;
    }

    private native def this(); // unused; prevent instantiaton outside of native code

    public static def allocateUninitialized[T](numElements:Int):IndexedMemoryChunk[T] {
        return alloc[T](numElements, NativeSupport.getSize[T](), 8, false, false);
    }

    public static def allocateZeroed[T](numElements:Int):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, NativeSupport.getSize[T](), 8, false, true);
    }

    public static def allocateUninitialized[T](numElements:Int, alignment:Int, congruent:boolean):IndexedMemoryChunk[T] {
        return alloc[T](numElements, NativeSupport.getSize[T](), alignment, congruent, false);
    }

    public static def allocateZeroed[T](numElements:Int, alignment:Int, congruent:boolean):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, NativeSupport.getSize[T](), alignment, congruent, true);
    }

    /**
     * Deallocate the backing storage for the IndexedMemoryChunk and
     * set its length to 0.  This is an unsafe operation, as other
     * IndexedMemoryChunks might have been created by copying this
     * IndexedMemoryChunk and will contain dangling pointers to the
     * freed memory.  This operation should only be called when
     * the caller is certain that no such copies of the IMC exist.
     */
    public def deallocate():void {
        if(length() > 0) {
            dealloc_internal(alloc_ptr);
        }
    }

    /**
     * Operator that allows access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    public operator this(index:Int):T {
        checkBounds(index, length());
        return Pointer.read[T](ptr + index * NativeSupport.getSize[T]());
    }

    /**
     * Operator that allows assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    public operator this(index:Int)=(value:T):void {
        checkBounds(index, length());
        Pointer.write[T](ptr + index * NativeSupport.getSize[T](), value);
    }

    /**
     * Clears numElems of the backing storage starting at index start
     * by zeroing the storage.  Note that this is intentionally not
     * type safe because it does require T hasZero.
     */
    public def clear(index:Int, numElems:Int):void {
        if(numElems > 0) {
            checkBounds(index, length());
            checkBounds(index + numElems, length() + 1);
            NativeSupport.memset(ptr + index * NativeSupport.getSize[T](), 0, numElems * NativeSupport.getSize[T]());
        }
    }

    /**
     * Operator that allows UNSAFE access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    public def apply_unsafe(index:Int):T {
        return Pointer.read[T](ptr + index * NativeSupport.getSize[T]());
    }

    /**
     * Operator that allows UNSAFE assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    public def set_unsafe(value:T, index:Int):void {
        Pointer.write[T](ptr + index * NativeSupport.getSize[T](), value);
    }

    /**
     * Return the size of the IndexedMemoryChunk (in elements)
     *
     * @return the size of the IndexedMemoryChunk (in elements)
     */
    public def length():Int {
        return len as Int;
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
    public static native def asyncCopy[T](src:IndexedMemoryChunk[T], srcIndex:Int,
                                          dst:RemoteIndexedMemoryChunk[T], dstIndex:Int,
                                          numElems:Int):void;

    public static native def uncountedCopy[T](src:IndexedMemoryChunk[T], srcIndex:Int,
                                              dst:RemoteIndexedMemoryChunk[T], dstIndex:Int,
                                              numElems:Int,
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
    public static native def asyncCopy[T](src:RemoteIndexedMemoryChunk[T], srcIndex:Int,
                                          dst:IndexedMemoryChunk[T], dstIndex:Int,
                                          numElems:Int):void;

    public static native def uncountedCopy[T](src:RemoteIndexedMemoryChunk[T], srcIndex:Int,
                                              dst:IndexedMemoryChunk[T], dstIndex:Int,
                                              numElems:Int,
                                              notifier:()=>void):void;

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
    public static def copy[T](src:IndexedMemoryChunk[T], srcIndex:Int,
                             dst:IndexedMemoryChunk[T], dstIndex:Int,
                             numElems:Int):void {
        if(numElems <= 0) return;
        checkBounds(srcIndex, src.length());
        checkBounds(srcIndex + numElems, src.length() + 1);
        checkBounds(dstIndex, dst.length());
        checkBounds(dstIndex + numElems, dst.length() + 1);
        NativeSupport.memcpy(dst.ptr + dstIndex * NativeSupport.getSize[T](), src.ptr + srcIndex * NativeSupport.getSize[T](), numElems * NativeSupport.getSize[T](), src.ptr.compareTo(dst.ptr) == 0);
    }


   /*
    * @Native methods from Any because the handwritten C++ code doesn't 100% match
    * what the compiler would have generated.
    */

    // TODO: Use String Builder (Need support for StringBuilder);
    public def  toString():String {
        var s : String = "IndexedMemoryChunk(";
        var sz: Int = length() > 10 ? 10 : length();
        for(var i : Int = 0; i < sz; i++) {
            if(i > 0)
                s = s + ",";
            s = s + this(i).toString();
        }
        if(sz < length())
            s = s + "...(omitted " + (length() - sz) + " elements";
        s = s + ")";
        return s;
    }

    public def equals(that:Any):Boolean {
        if(!(that instanceof IndexedMemoryChunk[T])) return false;
        val other = that as IndexedMemoryChunk[T];
        return length() == other.length() && NativeSupport.memcmp(ptr, other.ptr, length() * NativeSupport.getSize[T]());
    }

    public def hashCode():Int = ptr.hashCode();
}
