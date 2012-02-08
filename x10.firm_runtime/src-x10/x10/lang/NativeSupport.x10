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

public class NativeSupport {
	/** equals sizeof(x) in C */
    public static native def getSize[T]():int;

    /** memory compare */
    public static native def memcmp(ptr1: Pointer, ptr2: Pointer, bytes: long) : Boolean;
   
    /** memory copy */
    public static native def memcpy(dest: Pointer, src: Pointer, bytes: long, overlap: Boolean) : void;
   
    /** memset */
    public static native def memset(dest: Pointer, c: int, bytes: long) : void;
   
    /** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
    public static native def alloc(numBytes: long, alignment: int, congruent: Boolean, zeroed: Boolean) : Pointer;

    /** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
    public static native def dealloc(memPtr: Pointer) : void;
}
