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

    private static native def deepCopyAny(o : Any) : Any;
    private static native def runAtOtherPlace(placeId : Int, o: Any) : void;
    private static native def evalAtOtherPlace(placeId : Int, o: Any) : Any;
    private static native def getHereId() : Int;

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
    public static def home():Place = Place(getHereId());

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
    private static def evaluate(eval:()=>Any):Any {
    	return eval();
    }

	public static def runFinish(body:()=>void):void {
	    finish body();
	}

    /**
     * Run at statement
     */
    public static def runAt(place:Place, body:()=>void):void {
    	Runtime.ensureNotInAtomic();
    	
    	if (place == here) {
	    	try {
	    		val bodyCopy = deepCopy(body);
	    		bodyCopy();
	    	} catch (t : Throwable) {
	    		throw deepCopy(t);
	    	}
	    } else {
	    	try {
		    	runAtOtherPlace(place.id(), body);
		    } catch (t : Throwable) {
		    	throw deepCopy(t);
		    }
	    }
    }

    /**
     * Eval at expression
     */
    public static def evalAt[T](place:Place, eval:()=>T):T {
    	Runtime.ensureNotInAtomic();
    	
    	var res : T;
    	if (place == here) {
	    	try {
	    		val evalCopy = deepCopy(eval);
	    		res = evalCopy();
	    		res = deepCopy(res);
	    	} catch (t : Throwable) {
	    		throw deepCopy(t);
	    	}
	    } else {
	    	try {
	    		if (eval instanceof () => Object)
	    			res = evalAtOtherPlace(place.id(), eval) as T;
	    		else {
	    			/* enforce boxing of return value by wrapping eval
	    			   in a closure of type "() => Any" */
	    			res = evalAtOtherPlace(place.id(), () => eval() as Any) as T;
	    		}
	    	} catch (t : Throwable) {
	    		throw deepCopy(t);
	    	}
	    }
	    return res;
    }

    // atomic and when

    public static native def enterAtomic(): void;

    public static native def ensureNotInAtomic(): void;

    public static native def exitAtomic(): void;

    public static native def awaitAtomic(): void;

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
