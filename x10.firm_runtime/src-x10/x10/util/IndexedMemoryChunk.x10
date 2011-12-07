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
@NativeRep("java", "x10.core.IndexedMemoryChunk<#T$box>", null, "new x10.rtt.ParameterizedType(x10.core.IndexedMemoryChunk.$RTT, #T$rtt)")
@NativeRep("c++", "x10::util::IndexedMemoryChunk<#T >", "x10::util::IndexedMemoryChunk<#T >", null)
public struct IndexedMemoryChunk[T] {
    // Pointer to the allocated memory
    private val alloc_ptr: FirmPointer;
    // Pointer to the allocated aligned memory 
    private val ptr : FirmPointer;
    // len of the memory chunk
    private val len: long;
    
    private native static def alloc_internal(numElements: long, sizeElement: int, alignment: int, congruent: Boolean, zeroed: Boolean) : FirmPointer;
    private native static def dealloc_internal(ptr: FirmPointer) : void;
    
    private static def checkBounds(index: long, len: long) :void {
        if(index >= len) {
            throw new ArrayIndexOutOfBoundsException(index + " out of bound");
        }
    }

    private static def alloc[T](numElements: long, sizeElements: int, alignment: int, congruent: Boolean, zeroed: Boolean) : IndexedMemoryChunk[T] {
        if(numElements <= 0) {
            return IndexedMemoryChunk[T](FirmPointer.NULL, FirmPointer.NULL, 0L);
        }
    
        val alloc_ptr : FirmPointer = alloc_internal(numElements, sizeElements, alignment, congruent, zeroed);
        val align_ptr : FirmPointer = FirmPointer.align(alloc_ptr, alignment);
        return IndexedMemoryChunk[T](alloc_ptr, align_ptr, numElements); 
    }
    
    private def this(alloc_p: FirmPointer, align_p : FirmPointer, l: long) {
        alloc_ptr = alloc_p;
        ptr = align_p;
        len = l;
    }

    @Native("java", "null")
    @Native("c++", "null")
    private native def this(); // unused; prevent instantiaton outside of native code

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, false)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, 8, false, false)")
    public static def allocateUninitialized[T](numElements:int):IndexedMemoryChunk[T] {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), 8, false, false);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, true)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, 8, false, true)")
    public static def allocateZeroed[T](numElements:int):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), 8, false, true);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, false)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, #alignment, #congruent, false)")
    public static def allocateUninitialized[T](numElements:int, alignment:int, congruent:boolean):IndexedMemoryChunk[T] {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), alignment, congruent, false);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, true)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, #alignment, #congruent, true)")
    public static def allocateZeroed[T](numElements:int, alignment:int, congruent:boolean):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), alignment, congruent, true);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, false)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, 8, false, false)")
    public static def allocateUninitialized[T](numElements:long):IndexedMemoryChunk[T] {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), 8, false, false);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, true)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, 8, false, true)")
    public static def allocateZeroed[T](numElements:long):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), 8, false, true);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, false)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, #alignment, #congruent, false)")
    public static def allocateUninitialized[T](numElements:long, alignment:int, congruent:boolean):IndexedMemoryChunk[T] {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), alignment, congruent, false);
    }

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>allocate(#T$rtt, #numElements, true)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::allocate<#T >(#numElements, #alignment, #congruent, true)")
    public static def allocateZeroed[T](numElements:long, alignment:int, congruent:boolean):IndexedMemoryChunk[T]{T haszero} {
        return alloc[T](numElements, X10FirmSupport.getSize[T](), alignment, congruent, true);
    }

    /**
     * Deallocate the backing storage for the IndexedMemoryChunk and
     * set its length to 0.  This is an unsafe operation, as other
     * IndexedMemoryChunks might have been created by copying this
     * IndexedMemoryChunk and will contain dangling pointers to the 
     * freed memory.  This operation should only be called when 
     * the caller is certain that no such copies of the IMC exist.
     */
    @Native("java", "(#this).deallocate()")
    @Native("c++", "(#this)->deallocate()")
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
    @Native("java", "(#this).$apply$G(#index)")
    @Native("c++", "(#this)->__apply(#index)")
    public operator this(index:int):T {
        checkBounds(index, length());
        return FirmPointer.read[T](ptr + index * X10FirmSupport.getSize[T]());
    }

    /**
     * Operator that allows access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    @Native("java", "(#this).$apply$G((int)(#index))")
    @Native("c++", "(#this)->__apply(#index)")
    public operator this(index:long):T {
        checkBounds(index, length());
        return FirmPointer.read[T](ptr + index * X10FirmSupport.getSize[T]());
    }


    /**
     * Operator that allows assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    @Native("java", "(#this).$set(#index, #value)")
    @Native("c++", "(#this)->__set(#index, #value)")
    public operator this(index:int)=(value:T):void {
        checkBounds(index, length());
        FirmPointer.write[T](ptr + index * X10FirmSupport.getSize[T](), value);
    }


    /**
     * Operator that allows assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    @Native("java", "(#this).$set((int)(#index), #value)")
    @Native("c++", "(#this)->__set(#index, #value)")
    public operator this(index:long)=(value:T):void {
        checkBounds(index, length());
        FirmPointer.write[T](ptr + index * X10FirmSupport.getSize[T](), value);
    }


    /**
     * Clears numElems of the backing storage starting at index start
     * by zeroing the storage.  Note that this is intentionally not
     * type safe because it does require T hasZero.
     */
    @Native("java", "(#this).clear(#index, #numElems)")
    @Native("c++", "(#this)->clear(#index, #numElems)")
    public def clear(index:int, numElems:int):void { 
        if(numElems > 0) {
            checkBounds(index, length());
            checkBounds(index + numElems, length() + 1);
            X10FirmSupport.memset(ptr + index, 0, numElems * X10FirmSupport.getSize[T]());
        }
    }


    /**
     * Clears numElems of the backing storage starting at index start
     * by zeroing the storage.  Note that this is intentionally not
     * type safe because it does require T hasZero.
     */
    @Native("java", "(#this).clear((int)(#index), (int)(#numElems))")
    @Native("c++", "(#this)->clear(#index, #numElems)")
    public def clear(index:long, numElems:long):void {
        if(numElems > 0) {
            checkBounds(index, length());
            checkBounds(index + numElems, length() + 1);
            X10FirmSupport.memset(ptr + index, 0, numElems * X10FirmSupport.getSize[T]());
        }
    }


    /**
     * Operator that allows UNSAFE access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    @Native("java", "(#this).$apply$G(#index)")
    @Native("c++", "(#this)->apply_unsafe(#index)")
    public def apply_unsafe(index:int):T {
        return FirmPointer.read[T](ptr + index * X10FirmSupport.getSize[T]());
    }


    /**
     * Operator that allows UNSAFE access of IndexedMemoryChunk elements by index.
     *
     * @param i The index to retreive.
     * @return The value at that index.
     */
    @Native("java", "(#this).$apply$G((int)(#index))")
    @Native("c++", "(#this)->apply_unsafe(#index)")
    public def apply_unsafe(index:long):T {
        return FirmPointer.read[T](ptr + index * X10FirmSupport.getSize[T]());
    }


    /**
     * Operator that allows UNSAFE assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    @Native("java", "(#this).set_unsafe(#value, #index)")
    @Native("c++", "(#this)->set_unsafe(#value, #index)")
    public def set_unsafe(value:T, index:int):void {
        FirmPointer.write[T](ptr + index * X10FirmSupport.getSize[T](), value);
    }


    /**
     * Operator that allows UNSAFE assignment of IndexedMemoryChunk elements by index.
     *
     * @param v The value to assign.
     * @param i The index of the element to be changed.
     * @return The new value.
     */
    @Native("java", "(#this).set_unsafe(#value, (int)(#index))")
    @Native("c++", "(#this)->set_unsafe(#value, #index)")
    public def set_unsafe(value:T, index:long):void {
        FirmPointer.write[T](ptr + index * X10FirmSupport.getSize[T](), value);
    }


    /**
     * Return the size of the IndexedMemoryChunk (in elements)
     *
     * @return the size of the IndexedMemoryChunk (in elements)
     */
    @Native("java", "((#this).length)")
    @Native("c++", "(#this)->length()")
    public def length():int { /* TODO: We need to convert this to returning a long */
        return len as int;
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
    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>asyncCopy(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::asyncCopy<#T >(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    public static native def asyncCopy[T](src:IndexedMemoryChunk[T], srcIndex:int, 
                                          dst:RemoteIndexedMemoryChunk[T], dstIndex:int, 
                                          numElems:int):void;

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>asyncCopy(#src,#srcIndex,#dst,#dstIndex,#numElems,#notifier)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::asyncCopy<#T >(#src,#srcIndex,#dst,#dstIndex,#numElems,#notifier)")
    public static native def uncountedCopy[T](src:IndexedMemoryChunk[T], srcIndex:int, 
                                              dst:RemoteIndexedMemoryChunk[T], dstIndex:int, 
                                              numElems:int,
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
    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>asyncCopy(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::asyncCopy<#T >(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    public static native def asyncCopy[T](src:RemoteIndexedMemoryChunk[T], srcIndex:int, 
                                          dst:IndexedMemoryChunk[T], dstIndex:int, 
                                          numElems:int):void;

    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>asyncCopy(#src,#srcIndex,#dst,#dstIndex,#numElems,#notifier)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::asyncCopy<#T >(#src,#srcIndex,#dst,#dstIndex,#numElems,#notifier)")
    public static native def uncountedCopy[T](src:RemoteIndexedMemoryChunk[T], srcIndex:int, 
                                              dst:IndexedMemoryChunk[T], dstIndex:int, 
                                              numElems:int,
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
    @Native("java", "x10.core.IndexedMemoryChunk.<#T$box>copy(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    @Native("c++", "x10::util::IndexedMemoryChunk<void>::copy<#T >(#src,#srcIndex,#dst,#dstIndex,#numElems)")
    public static def copy[T](src:IndexedMemoryChunk[T], srcIndex:int, 
                                     dst:IndexedMemoryChunk[T], dstIndex:int, 
                                     numElems:int):void {
        if(numElems <= 0) return;
        checkBounds(srcIndex, src.length());
        checkBounds(srcIndex + numElems, src.length() + 1);
        checkBounds(dstIndex, dst.length());
        checkBounds(dstIndex + numElems, dst.length() + 1);
        X10FirmSupport.memcpy(dst.ptr + dstIndex * X10FirmSupport.getSize[T](), src.ptr + srcIndex * X10FirmSupport.getSize[T](), numElems * X10FirmSupport.getSize[T](), src.ptr.compareTo(dst.ptr) == 0);
    }


   /*
    * @Native methods from Any because the handwritten C++ code doesn't 100% match 
    * what the compiler would have generated.
    */

    @Native("java", "(#this).toString()")
    @Native("c++", "(#this)->toString()")
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

    @Native("java", "(#this).equals(#that)")
    @Native("c++", "(#this)->equals(#that)")
    public def equals(that:Any):Boolean {
        if(!(that instanceof IndexedMemoryChunk[T])) return false;
        val other = that as IndexedMemoryChunk[T];
        return length() == other.length() && X10FirmSupport.memcmp(ptr, other.ptr, length() * X10FirmSupport.getSize[T]());
    }

    @Native("java", "(#this).hashCode()")
    @Native("c++", "(#this)->hashCode()")
    public def hashCode():Int = ptr.native_ptr() as Int;

    // TODO: FIRM IMPLEMENT IT although it is nowhere used :) (Need support for RemoteIndexedMemoryChunk)
    //@Native("java", "(#this).getCongruentSibling(#p)")
    //@Native("c++", "(#this)->getCongruentSibling(#p)")
    //public native def getCongruentSibling(p:Place):RemoteIndexedMemoryChunk[T];
    
}

// vim:shiftwidth=4:tabstop=4:expandtab
