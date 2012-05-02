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

import x10.util.concurrent.Lock;

/**
 * Usage:
 *
 * try {
 *    val input = new File(inputFileName);
 *    val output = new File(outputFileName);
 *    val p = output.printer();
 *    for (line in input.lines()) {
 *       p.println(line);
 *    }
 *    p.flush();
 * } catch (IOException) { }
 */
public class Printer extends FilterWriter {
    public def this(w: Writer) { super(w); }

    private static NEWLINE:Char = '\n'; // System.getProperty("line.separator");

    private lock = new Lock();

    public def println(): void { print(NEWLINE); }

    public final def println(o:Any): void {
        print(o==null? "null\n" : o.toString()+"\n");
    }
    // this is needed to avoid extra boxing in Managed X10
    public final def println(s:String): void {
    	print(s==null? "null\n" : s+"\n");
    }

    public final def print(o:Any): void {
    	print(o==null? "null" : o.toString());
    }

    public def print(s:String): void {
        lock.lock();
        try {
            val ss = s != null ? s : "null";
            val ptr = ss.getPointer();
            val len = ss.length() * NativeSupport.getSize[Char]();
            write(ptr, len);
        }
        catch (e: IOException) {
            // should use a finally block here but until we fix XTENLANG-203 this is better
            lock.unlock();
            throw e;
        }
        // should use a finally block here but until we fix XTENLANG-203 this is better
        lock.unlock();
    }

    /*
    public def printf(fmt: String): void { printfArray(fmt, new Array[Any](0)); }
    public def printf(fmt: String, o1: Any): void { printfArray(fmt, [o1 as Any]); }
    public def printf(fmt: String, o1: Any, o2: Any): void { printfArray(fmt, [o1 as Any,o2]); }
    public def printf(fmt: String, o1: Any, o2: Any, o3: Any): void { printfArray(fmt, [o1 as Any,o2,o3]); }
    public def printf(fmt: String, o1: Any, o2: Any, o3: Any, o4: Any): void {
        printfArray(fmt, [o1,o2,o3,o4]);
    }
    public def printf(fmt: String, o1: Any, o2: Any, o3: Any, o4: Any, o5: Any): void {
       printfArray(fmt, [o1,o2,o3,o4,o5]);
    }
    public def printf(fmt: String, o1: Any, o2: Any, o3: Any, o4: Any, o5: Any, o6: Any): void {
       printfArray(fmt, [o1,o2,o3,o4,o5,o6]);
    }

    public def printf(fmt: String, args: Rail[Any]): void {
        print(String.format(fmt, new Array[Any](args.size, (i:int)=>args(i))));
    }
    public def printfArray(fmt: String, args: Array[Any](1)): void {
        print(String.format(fmt, args));
    }
    */

    public def flush(): void {
        try {
            super.flush();
        }
        catch (IOException) { }
    }

    public def close(): void {
        try {
            super.close();
        }
        catch (IOException) { }
    }

}
