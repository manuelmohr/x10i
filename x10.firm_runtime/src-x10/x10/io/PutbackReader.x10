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

package x10.io;

import x10.util.GrowableIndexedMemoryChunk;

public class PutbackReader extends FilterReader {
    val putback:GrowableIndexedMemoryChunk[Byte];

    public def this(r: Reader) {
        super(r);
        putback = new GrowableIndexedMemoryChunk[Byte]();
    }

    public def read() //throws IOException
    {
       if (putback.length() > 0) {
           val p = putback(putback.length()-1);
           putback.removeLast();
           return p;
       }
       return super.read();
    }

    public def putback(p: Byte) {
       putback.add(p);
    }
}
