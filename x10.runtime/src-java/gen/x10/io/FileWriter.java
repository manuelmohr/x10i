package x10.io;


public class FileWriter
extends x10.
  io.
  OutputStreamWriter
{public static final x10.rtt.RuntimeType<FileWriter> _RTT = new x10.rtt.RuntimeType<FileWriter>(
/* base class */FileWriter.class
, /* parents */ new x10.rtt.Type[] {x10.io.OutputStreamWriter._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 18
;
    
    
//#line 24
final public x10.
      io.
      File
      file;
    
    
//#line 26
private static java.io.OutputStream
                  make(
                  final java.lang.String path)
                      throws java.io.IOException{
        
//#line 28
return new java.io.FileOutputStream(path);
    }
    
    public static java.io.OutputStream
      make$P(
      final java.lang.String path)
          throws java.io.IOException{
        return new java.io.BufferedOutputStream(new java.io.FileOutputStream(path));
    }
    
    
//#line 31
public FileWriter(final x10.
                                    io.
                                    File file)
                      throws java.io.IOException {
        
//#line 32
super(new java.io.BufferedOutputStream(new java.io.FileOutputStream(file.getPath())));
        
//#line 33
this.file = file;
    }

}
