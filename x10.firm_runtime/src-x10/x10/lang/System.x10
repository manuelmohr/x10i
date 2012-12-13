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

import x10.compiler.Native;
import x10.io.Console;
import x10.util.HashMap;
import x10.util.Map;
import x10.util.Timer;
import x10.util.Pair;

public class System {

    private def this() {}

    /**
     * Provides the current time in milliseconds.
     *
     * @return The current time in milliseconds.
     */
    public static def currentTimeMillis():Long = Timer.milliTime();

    /**
     * Provides the current time in nanoseconds, as precise as the system timers provide.
     *
     * @return The current time in nanoseconds.
     */
    public static def nanoTime():Long = Timer.nanoTime();

    /**
     * Sets the system exit code.
     * The exit code will be returned from the application when main() terminates.
     * Can only be invoked in place 0.
     */
    @Native("java", "x10.runtime.impl.java.Runtime.setExitCode(#exitCode)")
    @Native("c++", "(x10aux::exitCode = (#exitCode))")
    public static native def setExitCode(exitCode: int){here==Place.FIRST_PLACE}: void;

    /**
     * Trigger a garbage collection.
     */
    @Native("java", "java.lang.System.gc()")
    @Native("c++", "x10aux::trigger_gc()")
    public static native def gc():void;

    /**
     * Sleep for the specified number of milliseconds.
     * [IP] NOTE: Unlike Java, x10 sleep() simply exits when interrupted.
     * @param millis the number of milliseconds to sleep
     * @return true if completed normally, false if interrupted
     */
    public static native def sleep(millis: long): Boolean;
}
