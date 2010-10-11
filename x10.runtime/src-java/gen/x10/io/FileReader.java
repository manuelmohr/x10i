package x10.io;


public class FileReader
extends x10.
  io.
  InputStreamReader
{public static final x10.rtt.RuntimeType<FileReader> _RTT = new x10.rtt.RuntimeType<FileReader>(
/* base class */FileReader.class
, /* parents */ new x10.rtt.Type[] {x10.io.InputStreamReader._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 18
final public x10.
      io.
      File
      file;
    
//#line 20
;
    
    
    
//#line 26
public FileReader(final x10.
                                    io.
                                    File file)
                      throws java.io.IOException {
        
//#line 27
super(((java.io.InputStream)
                            new java.io.FileInputStream(file.getPath())));
        
//#line 28
this.file = file;
    }

}
