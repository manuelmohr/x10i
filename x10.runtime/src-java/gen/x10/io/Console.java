package x10.io;


public class Console
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Console> _RTT = new x10.rtt.RuntimeType<Console>(
/* base class */Console.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 17
native private static java.io.OutputStream
                  realOut(
                  );
    
    public static java.io.OutputStream
      realOut$P(
      ){
        return java.lang.System.out;
    }
    
    
//#line 21
native private static java.io.OutputStream
                  realErr(
                  );
    
    public static java.io.OutputStream
      realErr$P(
      ){
        return new java.io.FileOutputStream(java.io.FileDescriptor.err);
    }
    
    
//#line 25
native private static java.io.InputStream
                  realIn(
                  );
    
    public static java.io.InputStream
      realIn$P(
      ){
        return java.lang.System.in;
    }
    
    
//#line 29
final public static x10.
      io.
      Printer
      OUT =
      new x10.
      io.
      Printer(new x10.
                io.
                OutputStreamWriter(java.lang.System.out));
    
//#line 30
final public static x10.
      io.
      Printer
      ERR =
      new x10.
      io.
      Printer(new x10.
                io.
                OutputStreamWriter(new java.io.FileOutputStream(java.io.FileDescriptor.err)));
    
//#line 31
final public static x10.
      io.
      Reader
      IN =
      ((x10.
        io.
        Reader)
        new x10.
        io.
        InputStreamReader(java.lang.System.in));
    
    
//#line 16
public Console() {
        
//#line 16
super();
    }

}
