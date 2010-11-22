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

package x10.util.concurrent.atomic;

import x10.compiler.Native;
import x10.compiler.NativeRep;
import x10.compiler.Volatile;

@NativeRep("java", "java.util.concurrent.atomic.AtomicBoolean", null, "x10.rtt.Types.ATOMIC_BOOLEAN")
public final class AtomicBoolean {
   /*
    * An int that will only contain 0 or 1 and is interpreted as an boolean.
    * We do this instead of using a boolean so that we know that compareAndSet_32 
    * can work on the whole memory word.
    */
    private @Volatile var value:int;
    
    public def this():AtomicBoolean {
        value = 0;
    }
    public def this(v:boolean):AtomicBoolean {
        value = v ? 1 : 0;
    }
    
    @Native("java", "#0.get()")
    public def get():boolean = value == 1;

    @Native("java", "#0.set(#1)")
    public def set(v:boolean):void {
        value = v ? 1 : 0;
    }

    @Native("java", "#0.compareAndSet(#1,#2)")
    @Native("c++", "x10aux::atomic_boolean_funs::compareAndSet(#0, #1, #2)")
    public native def compareAndSet(expect:boolean, update:boolean):boolean;

    @Native("java", "#0.weakCompareAndSet(#1,#2)")
    @Native("c++", "x10aux::atomic_boolean_funs::weakCompareAndSet(#0, #1, #2)")
    public native def weakCompareAndSet(expect:boolean, update:boolean):boolean;
    
    @Native("java", "#0.getAndSet(#1)")
    public def getAndSet(v:boolean):boolean {
	val oldVal = get();
	set(v);
	return oldVal;
    }

    @Native("java", "#0.toString()")
    public def toString():String = get().toString();
}
 
