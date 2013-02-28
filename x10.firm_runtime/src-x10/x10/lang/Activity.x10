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

import x10.compiler.LinkSymbol;

public class Activity {
    @LinkSymbol("activity_get_atomic_depth")
    public static native def getAtomicDepth(): UInt;
    @LinkSymbol("activity_inc_atomic_depth")
    public static native def incrementAtomicDepth(): void;
    @LinkSymbol("activity_dec_atomic_depth")
    public static native def decrementAtomicDepth(): void;
}
