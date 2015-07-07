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

package x10.util.concurrent;

import x10.lang.Pointer;

import x10.compiler.TLMAllocate;
import x10.compiler.LinkSymbol;

@TLMAllocate
public final class AtomicReference[T]{T isref} {
	private var ptr:Pointer;

	public def this():AtomicReference[T] {
		this.ptr = Pointer.NULL;
	}

	public def this(v:T):AtomicReference[T] {
		this.ptr = v as Pointer;
	}

	// Hack around XTENLANG-127.  Delete as soon as it is fixed.
	public static def newAtomicReference[T]() {T isref} :AtomicReference[T] {
		return new AtomicReference[T]();
	}

	// Hack around XTENLANG-127.  Delete as soon as it is fixed.
	public static def newAtomicReference[T](v:T) {T isref} :AtomicReference[T] {
		return new AtomicReference[T](v);
	}

	public def get():T = this.ptr.castTo[T]();

	public def set(v:T) {T isref} :void {
		this.ptr = v as Pointer; // TODO memory fence?
	}

	public def compareAndSet(expect:T, update:T) {T isref} :Boolean {
		/* "expect as Pointer" would fail,
		    because it becomes a cast instead of a conversion. */
		val e = Pointer.explicitAs(expect);
		val u = Pointer.explicitAs(update);
		return internal_compareAndSet(this as Pointer,e,u);
	}

	public def weakCompareAndSet(expect:T, update:T) {T isref} :Boolean = compareAndSet(expect, update);

	public def getAndSet(v:T) {T isref} :T {
		while (true) {
			val prev = get();
			if (compareAndSet(prev, v))
				return prev;
		}
	}

	public def toString():String = "atomic "+this.ptr.toString();

	@LinkSymbol("x10_compare_and_set")
	private static native def internal_compareAndSet(adr:Pointer, old:Pointer, neu:Pointer):Boolean;
}
