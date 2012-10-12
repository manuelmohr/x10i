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

public final class Runtime {

    static native def deepCopyAny(o : Any) : Any;
	
    /**
     * Return a deep copy of the parameter.
     */
    public static def deepCopy[T](o:T):T {
    	return deepCopyAny(o) as T;
    }

    /**
     * Return the current activity
     */
    //static def activity():Activity = null as Activity;

    /**
     * Return the current place
     */
    //public static def home():Place = null as Place;

    // asyncat, async, at statement, and at expression implementation
    // at is implemented using asyncat
    // asyncat and at must make a copy of the closure parameter (local or remote)
    // asyncat at and at should dealloc the closure parameter
    // async must not copy or dealloc the closure parameter

    /**
     * Run asyncat
     */
    //public static def runAsync(place:Place, clocks:Rail[Clock], body:()=>void):void { }

    //public static def runAsync(place:Place, body:()=>void):void { }

    /**
     * Run async
     */
    //public static def runAsync(clocks:Rail[Clock], body:()=>void):void { }

    public static def runAsync(body:()=>void):void {
    	executeParallel(body);
    }
    
    /** Spawn of a thread/iLet to execute body() */
    private static native def executeParallel(body:()=>void):void;
    
    /** This is called from our C runtime to execute activity closures */
    private static def execute(body:()=>void):void {
    	body();
    }

	public static def runFinish(body:()=>void):void {
	    finish body();
	}

    /**
     * Run at statement
     */
    //public static def runAt(place:Place, body:()=>void):void { }

    /**
     * Eval at expression
     */
    //public static def evalAt[T](place:Place, eval:()=>T):T { }

    // atomic and when

    public static def enterAtomic() {
    }

    public static def ensureNotInAtomic() {
    }

    public static def exitAtomic() {
    }

    public static def awaitAtomic():void {
    }

    // finish
    private static native def finishBlockBegin():void;
    private static native def finishBlockEnd():void;

    /**
     * Start executing current activity synchronously
     * (i.e. within a finish statement).
     */
    public static def startFinish():FinishState {
    	finishBlockBegin();
    	return null as FinishState; // For compatability with X10c frontend
    }

    /**
     * Suspend until all activities spawned during this finish
     * operation have terminated. Throw an exception if any
     * async terminated abruptly. Otherwise continue normally.
     * Should only be called by the thread executing the current activity.
     */
    public static def stopFinish(f:FinishState):void {
		finishBlockEnd();
    }

    /**
     * Push the exception thrown while executing s in a finish s,
     * onto the finish state.
     */
    public static def pushException(t:Throwable):void  {
    }

    // submit
    public static def execute(body:()=>void, finishState:FinishState):void {
    }
}

// vim:shiftwidth=4:tabstop=4:expandtab
