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

import x10.compiler.Pinned;
import x10.io.SerialData;
import x10.util.Stack;

/**
 * Lock with wait/notify capabilities.
 * Cooperates with runtime scheduler.
 */
@Pinned public class Monitor extends Lock {
    public def this() { super(); }

    public def serialize():SerialData {
        throw new UnsupportedOperationException("Cannot serialize "+typeName());
    }

    private def this(SerialData) {
        throw new UnsupportedOperationException("Cannot deserialize "+typeName());
    }


    private val signals: Stack[Signal] = new Stack[Signal]();

    /**
     * Await notification
     * Must be called while holding the lock
     * Must not be called while holding the lock more than once
     */
    public def await():void {
        val s = new Signal();
        signals.push(s);
        super.unlock();
        s.wait();
        super.lock();
    }

    /**
     * Notify and unlock
     * Must be called while holding the lock
     */
    public def release():void {
        while (!signals.isEmpty()) {
            signals.pop().signal();
        }
        super.unlock();
    }
}

