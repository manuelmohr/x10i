package x10.io;


public class File
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<File> _RTT = new x10.rtt.RuntimeType<File>(
/* base class */File.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 35
;
    
    
//#line 113
final public static char
      SEPARATOR =
      '/';
    
//#line 114
final public static char
      PATH_SEPARATOR =
      ':';
    
//#line 116
final public x10.
      io.
      File
      parent;
    
//#line 117
final public java.lang.String
      name;
    
//#line 118
final public boolean
      absolute;
    
    
//#line 120
public File(final java.lang.String fullName) {
        super();
        
//#line 121
final int i =
          (fullName).lastIndexOf(((char)(x10.
          io.
          File.SEPARATOR)));
        
//#line 122
if (((int) i) ==
                         ((int) 0)) {
            
//#line 123
this.parent = null;
            
//#line 124
this.name = fullName;
            
//#line 125
this.absolute = true;
        } else {
            
//#line 127
if (((((int)(i))) >= (((int)(0))))) {
                
//#line 128
this.parent = ((x10.
                  io.
                  File)(new x10.
                  io.
                  File((fullName).substring(((int)(0)), ((int)(i))))));
                
//#line 129
this.name = (fullName).substring(((int)(((((int)(i))) + (((int)(1)))))), ((int)((fullName).length())));
                
//#line 130
this.absolute = ((char) (fullName).charAt(((int)(0)))) ==
                ((char) x10.
                  io.
                  File.PATH_SEPARATOR);
            } else {
                
//#line 133
this.parent = null;
                
//#line 134
this.name = fullName;
                
//#line 135
this.absolute = false;
            }
        }
    }
    
    
//#line 139
public File(final x10.
                               io.
                               File p,
                             final java.lang.String n) {
        super();
        
//#line 140
assert (!x10.rtt.Equality.equalsequals(p,null));
        
//#line 141
this.parent = ((x10.
          io.
          File)(p));
        
//#line 142
this.name = n;
        
//#line 143
this.absolute = (!x10.rtt.Equality.equalsequals(p,null)) &&
        p.
          absolute;
    }
    
    
//#line 148
public x10.
                   io.
                   ReaderIterator<java.lang.String>
                   lines(
                   )
                       throws java.io.IOException{
        
//#line 148
return this.openRead().lines();
    }
    
    
//#line 149
public x10.
                   io.
                   ReaderIterator<java.lang.Character>
                   chars(
                   )
                       throws java.io.IOException{
        
//#line 149
return this.openRead().chars();
    }
    
    
//#line 150
public x10.
                   io.
                   ReaderIterator<java.lang.Byte>
                   bytes(
                   )
                       throws java.io.IOException{
        
//#line 150
return this.openRead().bytes();
    }
    
    
//#line 151
public x10.
                   io.
                   FileReader
                   openRead(
                   )
                       throws java.io.IOException{
        
//#line 151
return new x10.
          io.
          FileReader(this);
    }
    
    
//#line 152
public x10.
                   io.
                   FileWriter
                   openWrite(
                   )
                       throws java.io.IOException{
        
//#line 152
return new x10.
          io.
          FileWriter(this);
    }
    
    
//#line 153
public x10.
                   io.
                   Printer
                   printer(
                   )
                       throws java.io.IOException{
        
//#line 153
return new x10.
          io.
          Printer(this.openWrite());
    }
    
    
//#line 155
public java.lang.String
                   getName(
                   ){
        
//#line 155
return name;
    }
    
    
//#line 156
public x10.
                   io.
                   File
                   getParentFile(
                   ){
        
//#line 156
return parent;
    }
    
    
//#line 157
public java.lang.String
                   getPath(
                   ){
        
//#line 157
return x10.rtt.Equality.equalsequals(parent,null)
          ? name
          : ((((((parent.getPath()) + (((java.lang.Character)(x10.
                io.
                File.SEPARATOR))))) + (name))));
    }
    
    
//#line 158
public boolean
                   isAbsolute(
                   ){
        
//#line 158
return absolute;
    }
    
    
//#line 160
public java.io.File
                   nativeFile(
                   ){
        
//#line 160
return new java.io.File(this.getPath());
    }
    
    
//#line 162
public x10.
                   io.
                   File
                   getAbsoluteFile(
                   ){
        
//#line 162
return new x10.
          io.
          File(this.nativeFile().getAbsolutePath());
    }
    
    
//#line 163
public x10.
                   io.
                   File
                   getCanonicalFile(
                   )
                       throws java.io.IOException{
        
//#line 163
return new x10.
          io.
          File(this.nativeFile().getCanonicalPath());
    }
    
    
//#line 168
public boolean
                   exists(
                   ){
        
//#line 168
return this.nativeFile().exists();
    }
    
    
//#line 171
public boolean
                   isSymbolicLink(
                   ){
        
//#line 171
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 172
public boolean
                   isAlias(
                   ){
        
//#line 172
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 173
public boolean
                   hardLinkCount(
                   ){
        
//#line 173
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 174
public long
                   inodeNumber(
                   ){
        
//#line 174
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 175
public int
                   permissions(
                   ){
        
//#line 175
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 177
public boolean
                   isDirectory(
                   ){
        
//#line 177
return this.nativeFile().isDirectory();
    }
    
    
//#line 178
public boolean
                   isFile(
                   ){
        
//#line 178
return this.nativeFile().isFile();
    }
    
    
//#line 179
public boolean
                   isHidden(
                   ){
        
//#line 179
return this.nativeFile().isHidden();
    }
    
    
//#line 181
public long
                   lastModified(
                   ){
        
//#line 181
return this.nativeFile().lastModified();
    }
    
    
//#line 182
public boolean
                   setLastModified(
                   final long t){
        
//#line 182
return this.nativeFile().setLastModified(((long)(t)));
    }
    
    
//#line 183
public long
                   size(
                   ){
        
//#line 183
return this.nativeFile().length();
    }
    
    
//#line 185
public int
                   compareTo(
                   final x10.
                     io.
                     File id$62){
        
//#line 185
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 187
public boolean
                   canRead(
                   ){
        
//#line 187
return this.nativeFile().canRead();
    }
    
    
//#line 188
public boolean
                   canWrite(
                   ){
        
//#line 188
return this.nativeFile().canWrite();
    }

}
