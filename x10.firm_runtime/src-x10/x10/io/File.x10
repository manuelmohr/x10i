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
import x10.compiler.Incomplete;

/**
 * Represents a file path.
 * Modeled after java.nio.file.Path.
 *
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
public class File {
    private static final class NativeFile {
    	
    	public static SEPARATOR: Char = '/';
    	
        public static def getName(path: String): String {
        	val i = path.lastIndexOf(SEPARATOR);
        	if (i > 0) {
        		return path.substring(i + 1, path.length());
        	} else {
        		return path;
        	}
        }
        
        public static def getParent(path: String): String {
        	val i = path.lastIndexOf(SEPARATOR);
        	if (i > 0) {
        		return path.substring(0, i);
        	} else {
        		return null;
        	}
        }
        
        public static def getPath(path: String): String = path;
        
        public static def isAbsolute(path: String): Boolean {
        	if (path.length() == 0) {
        		return false;
        	}
        	else if (path.charAt(0) == SEPARATOR) {
        		return true;
        	}
        	else {
        		return false;
        	}
        }
        
        public static def getAbsolutePath(path: String): String {
        	if (path.length() == 0 || isAbsolute(path)) {
        		return path;
        	}
        	else {
        		return getCwd() + SEPARATOR + path;
        	}
        }
        
        public static def getCanonicalPath(path: String): String {
        	throw new UnsupportedOperationException();
        }
        
        public static def isHidden(path: String): Boolean {
        	if (path.length() == 0) {
        		return false;
        	}
        	else if (path.charAt(0) == '.') {
        		return true;
        	}
        	else {
        		return false;
        	}
        }
        
        private static native def getCwd(): String;

        public static native def list(path: String): Rail[String];

        public static native def canRead(path: String): Boolean;
        public static native def canWrite(path: String): Boolean;
        public static native def exists(path: String): Boolean;
        public static native def isDirectory(path: String): Boolean;
        public static native def isFile(path: String): Boolean;
        public static native def lastModified(path: String): Long;
        public static native def length(path: String): Long;
        public static native def setLastModified(path: String, v:Long): Boolean;
        public static native def delete(path: String): Boolean;
        public static native def mkdir(path: String): Boolean;
        
        public static native def renameTo(src: String, dest: String): Boolean;
        
        public static def mkdirs(path: String): Boolean {
        	var i:int = 0;
        	i = path.indexOf(SEPARATOR, i);
        	while (i >= 0) {
        		val spath = path.substring(0, i);
        		if (!exists(spath)) {
        			if (!mkdir(spath)) {
        				return false;
        			}
        		}
        		++i;
        		i = path.indexOf(SEPARATOR, i);
        	}
        	if (!exists(path)) {
        		if (!mkdir(path)) {
        			return false;
        		}
        	}
        	return true;
        }
    }
/*
FileSystem operations

    public boolean createNewFile()       throws java.io.IOException;
    public void deleteOnExit();
    public java.lang.String[] list(java.io.FilenameFilter);
    public java.io.File[] listFiles();
    public java.io.File[] listFiles(java.io.FilenameFilter);
    public java.io.File[] listFiles(java.io.FileFilter);
    public boolean setReadOnly();
    public static java.io.File[] listRoots();
    public static java.io.File createTempFile(java.lang.String, java.lang.String, java.io.File)       throws java.io.IOException;
    public static java.io.File createTempFile(java.lang.String, java.lang.String)       throws java.io.IOException;
*/

    public static SEPARATOR: Char = '/';
    public static PATH_SEPARATOR: Char = ':';

    // TODO: This is questionable.
    //       What does it mean to send a File to another node?
    val parent: File;
    val name: String;
    val absolute: Boolean;

    public def this(fullName: String) {
        val i = fullName.lastIndexOf(SEPARATOR);
        if (i == 0) {
                parent = null;
                name = fullName;
                absolute = true;
        }
        else if (i >= 0) {
                parent = new File(fullName.substring(0, i));
                name = fullName.substring(i+1, fullName.length());
                absolute = fullName.charAt(0) == PATH_SEPARATOR;
        }
        else {
                parent = null;
                name = fullName;
                absolute = false;
        }
    }

    public def this(p: File, n: String) {
        assert p != null;
        parent = p;
        name = n;
        absolute = p != null && p.absolute;
    }

    // @Incomplete def this(u: URI);

    public def lines(): ReaderIterator[String] //throws IOException
     = openRead().lines();
    public def chars(): ReaderIterator[Char] //throws IOException
     = openRead().chars();
    public def bytes(): ReaderIterator[Byte] //throws IOException
    = openRead().bytes();
    private static native def nativeOpenRead(path: String): FileReader{self!=null};
    public def openRead() = nativeOpenRead(getPath()); //throws IOException
    private static native def nativeOpenWrite(path: String, append: Boolean): FileWriter{self!=null};
    public def openWrite() = openWrite(false);
    public def openWrite(append:Boolean) = nativeOpenWrite(getPath(), append); //throws IOException
    public def printer() = printer(false);
    public def printer(append:Boolean):Printer //throws IOException
    = new Printer(openWrite(append));

    public def getName(): String = name;
    public def getParentFile(): File = parent;
    public def getPath(): String = parent == null ? name : (parent.getPath() + SEPARATOR + name);
    public def isAbsolute(): Boolean = absolute;

    public def getAbsoluteFile(): File = new File(NativeFile.getAbsolutePath(getPath()));
    public def getCanonicalFile(): File  // throws IOException
    = new File(NativeFile.getCanonicalPath(getPath()));

    // incomplete def toURL(): URL;
    // incomplete def toURI(): URI;

    public def exists(): Boolean = NativeFile.exists(getPath());

    // OS-specific
    @Incomplete def isSymbolicLink(): Boolean {         throw new UnsupportedOperationException();}
    @Incomplete def isAlias(): Boolean  {         throw new UnsupportedOperationException(); }
    @Incomplete def hardLinkCount(): Boolean {         throw new UnsupportedOperationException(); }
    @Incomplete def inodeNumber(): Long {         throw new UnsupportedOperationException(); }
    @Incomplete def permissions(): Int {         throw new UnsupportedOperationException();}
    // FilePermission;

    public def isDirectory(): Boolean = NativeFile.isDirectory(getPath());
    public def isFile(): Boolean = NativeFile.isFile(getPath());
    public def isHidden(): Boolean = NativeFile.isHidden(getPath());

    public def lastModified(): Long = NativeFile.lastModified(getPath());
    public def setLastModified(t:Long): Boolean = NativeFile.setLastModified(getPath(), t);
    public def size(): Long = NativeFile.length(getPath());

    @Incomplete public def compareTo(File): Int {         throw new UnsupportedOperationException();}

    public def canRead(): Boolean = NativeFile.canRead(getPath());
    public def canWrite(): Boolean = NativeFile.canWrite(getPath());

    public def delete(): Boolean = NativeFile.delete(getPath());
    public def list(): Rail[String] = NativeFile.list(getPath());
    public def mkdir(): Boolean = NativeFile.mkdir(getPath());
    public def mkdirs(): Boolean = NativeFile.mkdirs(getPath());
    public def renameTo(dest:File): Boolean = NativeFile.renameTo(getPath(), dest.getPath());
}
