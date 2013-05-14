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

/**
 * A GrowableIndexedMemoryChunk provides the abstraction of
 * a variable size IndexedMemoryChunk.  It is implemented
 * by wrapping a backing IndexedMemoryChunk and automatically
 * growing the backing store as needed to support the requested
 * insertion operations.
 *
 * @See ArrayList, which provides a similar abstraction of a
 *      Growable Array. Like Array, ArrayList is type safe.
 */
public final class GrowableIndexedMemoryChunk[T] {
    private var imc:IndexedMemoryChunk[T];

   /**
    * Elements 0..length-1 have valid entries of type T.
    * Elements length..imc.length-1 may not be valid
    * values of type T.
    * It is an invariant of this class, that such elements
    * will never be accessed.
    */
    private var length: Int;

    /**
     * Create a GrowableIndexedMemoryChunk with an initial
     * capacity of 0.
     */
    public def this() {
        this(0);
    }

    /**
     * Create a GrowableIndexedMemoryChunk with an initial
     * capacity of cap.
     */
    public def this(cap:Int) {
        imc = IndexedMemoryChunk.allocateZeroed[T](cap);
        length = 0;
    }

    /**
     * Store v as the length element, growing the backing store if needed.
     */
    public final def add(v:T):void {
        if (length+1 > capacity()) grow(length+1);
        imc(length++) = v;
    }

    /**
     * Insert all elements of items starting at the specified index.
     * This will raise an UnsupportedOperationException if p &gt; length.
     * If p &lt; length, then the elements from p..length-1 will first
     * be slide out of the way (growing the backing storage if needed)
     * and then the items inserted.
     * If p==length, then insert is equivalent to calling add for
     * each element of items in turn.
     */
    public final def insert(p:Int, items:IndexedMemoryChunk[T]):void {
        val addLen = items.length();
        val newLen = length + addLen;
        val movLen = length - p;
        if (newLen > capacity()) grow(newLen);
        if (movLen > 0) {
            IndexedMemoryChunk.copy(imc, p, imc, p+addLen, movLen);
        }
        IndexedMemoryChunk.copy(items, 0, imc, p, items.length());
        length = newLen;
    }

    public final operator this(idx:Int):T = imc(idx);

    public final operator this(idx:Int)=(v:T):void {
        imc(idx) = v;
    }

    /**
     * Get the current length; indices from 0..length-1 are currently valid
     * values of type T and may be accessed.
     */
    public final def length():Int = length;

    /**
     * What is the current capacity (size of backing storage)
     */
    public final def capacity():Int = imc.length();

    /**
     * Remove the last element. May shrink backing storage.
     */
    public final def removeLast():void {
        imc.clear(length-1,1);
        --length;
        shrink(length+1);
    }

    /**
     * Remove all elements.
     */
    public final def clear():void {
        if (length == 0)
            return;
        imc.clear(0,length-1);
        length = 0;
    }

    /**
     * Transfer elements between i and j (inclusive) into a new IMC,
     * in the order in which they appear in this rail.  The elements
     * following element j are shifted over to position i.
     * (j-i+1) must be no greater than s, the size of the rail.
     * On return the rail has s-(j-i+1) elements.
     * May shrink backing storage.
     */
    public final def moveSectionToIndexedMemoryChunk(i:Int, j:Int):IndexedMemoryChunk[T] {
        val len = j - i + 1;
        if (len < 1) return IndexedMemoryChunk.allocateUninitialized[T](0);
	val tmp = IndexedMemoryChunk.allocateUninitialized[T](len);
        IndexedMemoryChunk.copy(imc, i, tmp, 0, len);
        IndexedMemoryChunk.copy(imc, j+1, imc, i, length-j-1);
        imc.clear(length-len, len);
        length-=len;
        shrink(length+1);
        return tmp;
    }

    /*
    public def moveSectionToArray(i:Int, j:Int):Rail[T] {
        return new Array[T](moveSectionToIndexedMemoryChunk(i, j));
    }
    */

    /**
     * Copy current data into IndexedMemoryChunk
     */
    public final def toIndexedMemoryChunk():IndexedMemoryChunk[T] {
       val ans = IndexedMemoryChunk.allocateUninitialized[T](length);
       IndexedMemoryChunk.copy(imc, 0, ans, 0, length);
       return ans;
    }

    /**
     * Copy current data into an Array.
     */
    public final def toArray():Rail[T] {
      return new Array[T](toIndexedMemoryChunk());
    }

    public final def grow(var newCapacity:int):void {
        var oldCapacity:int = capacity();
        if (newCapacity < oldCapacity*2) {
            newCapacity = oldCapacity*2;
        }
        if (newCapacity < 8) {
            newCapacity = 8;
        }

        val tmp = IndexedMemoryChunk.allocateUninitialized[T](newCapacity);
        IndexedMemoryChunk.copy(imc, 0, tmp, 0, length);
        tmp.clear(length, newCapacity-length);
        imc.deallocate();
        imc = tmp;
    }

    public final def shrink(var newCapacity:int):void {
        if (newCapacity > capacity()/4 || newCapacity < 8)
            return;
        newCapacity = x10.lang.Math.max(newCapacity, length);
        newCapacity = x10.lang.Math.max(newCapacity, 8);
        val tmp = IndexedMemoryChunk.allocateUninitialized[T](newCapacity);
        IndexedMemoryChunk.copy(imc, 0, tmp, 0, length);
        tmp.clear(length, newCapacity-length);
        imc.deallocate();
        imc = tmp;
    }
}

