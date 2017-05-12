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

public class FileReader extends InputStreamReader {
  public def this(file: File)  //throws IOException
  {
    // FIXME: do something useful
  }

  public def read[T](m:x10.io.Marshal[T],a:x10.array.Array[T]{self.rank==1}): void
  {
    // TODO: more efficient?
    for (i in a) {
      a(i) = m.read(this);
    }
  }
}
