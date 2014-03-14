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

import x10.compiler.NativeRep;
import x10.compiler.Native;

public abstract class OutputStreamWriter extends Writer {
    public native def close(): void; //throws IOException;

    public native def flush(): void; //throws IOException;

    public native def write(v: Int): void; //throws IOException

    public native def write(r: Pointer, len: Int): void; //throws IOException

    public def write(x: Byte): void {
        write(x as Int);
    }

    /*
    public def write(buf:Array[Byte](1)): void //throws IOException
    {
        out.write(buf);
    }

    public def write(buf:Array[Byte](1), off: Int, len: Int): void //throws IOException
    {
        out.write(buf, off, len);
    }
    */
}
