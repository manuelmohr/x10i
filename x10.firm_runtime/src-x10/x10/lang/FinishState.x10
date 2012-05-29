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

import x10.compiler.*;

import x10.util.HashMap;
import x10.util.IndexedMemoryChunk;
import x10.util.Pair;
import x10.util.Stack;

import x10.util.concurrent.AtomicInteger;
import x10.util.concurrent.Lock;
import x10.util.concurrent.SimpleLatch;

import x10.io.CustomSerialization;
import x10.io.SerialData;

abstract class FinishState {
  
}

// vim:shiftwidth=4:tabstop=4:expandtab
