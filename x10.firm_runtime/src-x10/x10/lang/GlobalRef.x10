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

package x10.lang;

import x10.lang.Pointer;

/**
 * Create a global reference encapsulating a given object.  The ref has
 * the property home specifying the place at which it was
 * created. Besides that, the ref offers only the operations of Any at a
 * place other than the one where it was created (its home place).  Two
 * such refs are == if and only if they were created at the same place
 * and at that place the objects they encapsulate are ==.
 *
 * <p> At its home place, the value when applied to the empty list of
 * arguments returns its encapsulated value.
 */
public struct GlobalRef[T](home: Place) {T <: Any, T isref} {
    public property home(): Place = home;

    private val ptr: Pointer;

    /**
     * Create a value encapsulating the given object of type T.
     */
    public def this(t: T): GlobalRef[T]{self.home==here} {
        property(here);
        ptr = t as Pointer;
    }

    /**
     * Can only be invoked at the place at which the value was
     * created. Returns the object encapsulated in the value.
     */
    public operator this(){here==this.home}: T {
        return localApply();
    }

    /**
     * Unsafe method to get value.
     * Assumes here == this.home; however this is not enforced
     * by a constraint because it would entail dynamic checks.
     * Must only be called at this.home !
     */
    private def localApply(): T {
        return ptr.castTo[T]();
    }

    /**
     * Evaluates the given closure at (this.home), passing as a
     * parameter the object that is encapsulated by this GlobalRef.
     */
    public def evalAtHome[U](eval: (T) => U): U {
        if (here == this.home) {
            return eval(localApply());
        } else {
            return at (this.home) eval(localApply());
        }
    }

    /**
     * If (this.home == here), returns the object that is
     * encapsulated by this GlobalRef.  If (this.home != here),
     * returns a copy at the current place.
     */
    public def getLocalOrCopy(): T {
        if (here == this.home) {
            return localApply();
        } else {
            return at (this.home) localApply();
        }
    }

    private static class LocalEval {
        /**
         * Evaluates the given closure at the home place of <code>ref</code>.
         * This is equivalent to the following idiom:
         *   if (here == ref.home) return eval(ref);
         *   else return at (ref.home) eval(ref);
         */
        public static def evalAtHome[T,U](ref:GlobalRef[T], eval:(T)=> U){T isref}:U {
            if (here == ref.home) {
                return eval(ref.localApply());
            } else {
                return at (ref.home) eval(ref());
            }
        }

        /**
         * If (ref.home == here), returns the object that is
         * encapsulated by ref.  If (ref.home != here),
         * returns a copy at the current place.
         */
        public static def getLocalOrCopy[T](ref:GlobalRef[T]){T isref}:T {
            if (here == ref.home) {
                return ref.localApply();
            } else {
                return at (ref.home) ref();
            }
        }
    }

}
//public type GlobalRef[T](p:Place) {T isref} = GlobalRef[T]{self.home==p};
