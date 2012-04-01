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

import x10.compiler.Native;
import x10.compiler.NativeRep;

public class InputStreamReader extends Reader {
    public native def close(): void; //throws IOException;

    public native def readC(): Int; //throws IOException;

    public native def read(buffer: Pointer, len: Int): void; //throws IOException;

    public native def available(): Int; //throws IOException;

    public native def skip(v:Int): void; //throws IOException;

    public def mark(readAheadLimit: Int): void {
    }
    public def reset(): void {
    }
    public def markSupported(): Boolean {
        return false;
    }

    public def read(): Byte {
        val c = readC();
        if (c == -1) throw new EOFException();
        return c as Byte;
    }
}
