/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright Karlsruhe Institute of Technology 2011.
 */

package x10.lang;

import x10.compiler.Native;

/**
 * Low-level memory operations. The functions here are unsafe!
 * negative numBytes values produce undefined behaviour.
 */
public class NativeSupport {
    /**
     * Returns the number of bytes occupied by an instance of type T.
     * Does not include potential memory allocator overhead. Roughly
     * equals sizeof(T) in C. For reference types (classes) the size
     * of the reference (a pointer) is returned.
     */
    public static native def getSize[T](): Int;

    /** memory compare */
    public static native def memcmp(pointer1: Pointer, pointer2: Pointer, numBytes: Int): Int;

    /** memory copy, memory regions mustn't overlap */
    public static native def memcpy(destination: Pointer, source: Pointer, numBytes: Int): void;

    /** memory copy, overlapping memory regions allowed */
    public static native def memmove(destination:Pointer, source:Pointer, numBytes: Int): void;

    /** memset */
    public static native def memset(destination:Pointer, c:int, numBytes:Int): void;

    /** allocation of memory (uninitialized) */
    public static native def alloc(numBytes: Int): Pointer;

    /** allocation of memory (initialized to zero) */
    public static native def allocZeroed(numBytes: Int): Pointer;

    /** reallocation of memory */
    public static native def realloc(previous: Pointer, previousBytes: Int, numBytes: Int): Pointer;

    /** reallocation of memory sets new elements to zero when growing */
    public static native def reallocZeroed(previous: Pointer, previousBytes: Int, numBytes: Int): Pointer;

    /** deallocation of memory */
    public static native def dealloc(pointer: Pointer): void;
}
