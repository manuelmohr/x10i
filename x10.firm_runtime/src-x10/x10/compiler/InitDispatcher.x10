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

package x10.compiler;

import x10.compiler.StaticAllocate;
import x10.compiler.NativeRep;
import x10.util.concurrent.Monitor;

/**
 * Used for generating static initialization code in Java backend.
 *
 */
@NativeRep("java", "x10.runtime.impl.java.InitDispatcher", null, null)
class InitDispatcher {
    static staticMonitor = @StaticAllocate new Monitor();

    public static val UNINITIALIZED    = 0;
    public static val INITIALIZING     = 1;
    public static val INITIALIZED      = 2;
    public static val EXCEPTION_RAISED = 3;

    public static def lockInitialized() {
        staticMonitor.lock();
    }
    public static def unlockInitialized() {
        staticMonitor.unlock();
    }
    public static def awaitInitialized() {
        staticMonitor.await();
    }
    public static def notifyInitialized() {
        staticMonitor.release();
    }
}

// vim:shiftwidth=4:tabstop=4:expandtab
