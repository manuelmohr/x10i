package x10.io;


public class OutputStreamWriter
extends x10.
  io.
  Writer
{public static final x10.rtt.RuntimeType<OutputStreamWriter> _RTT = new x10.rtt.RuntimeType<OutputStreamWriter>(
/* base class */OutputStreamWriter.class
, /* parents */ new x10.rtt.Type[] {x10.io.Writer._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 18
;
    
    
//#line 50
final public java.io.OutputStream
      out;
    
    
//#line 52
public java.io.OutputStream
                  stream(
                  ){
        
//#line 52
return out;
    }
    
    
//#line 54
public OutputStreamWriter(final java.io.OutputStream out) {
        super();
        
//#line 55
this.out = out;
    }
    
    
//#line 58
public void
                  flush(
                  )
                      throws java.io.IOException{
        {
            
//#line 58
out.flush();
            
//#line 58
return;
        }
    }
    
    
//#line 60
public void
                  close(
                  )
                      throws java.io.IOException{
        {
            
//#line 60
out.close();
            
//#line 60
return;
        }
    }
    
    
//#line 62
public void
                  write(
                  final byte x)
                      throws java.io.IOException{
        {
            
//#line 62
out.write(((int)(((int)(byte)(((byte)(x)))))));
            
//#line 62
return;
        }
    }
    
    
//#line 64
public void
                  write(
                  final x10.core.ValRail<java.lang.Byte> buf)
                      throws java.io.IOException{
        
//#line 65
out.write((buf).getByteArray());
    }
    
    
//#line 68
public void
                  write(
                  final x10.core.Rail<java.lang.Byte> buf)
                      throws java.io.IOException{
        
//#line 69
out.write((buf).getByteArray());
    }
    
    
//#line 72
public void
                  write(
                  final x10.core.Rail<java.lang.Byte> buf,
                  final int off,
                  final int len)
                      throws java.io.IOException{
        
//#line 73
out.write((buf).getByteArray(), ((int)(off)), ((int)(len)));
    }
    
    
//#line 76
public void
                  write(
                  final x10.core.ValRail<java.lang.Byte> buf,
                  final int off,
                  final int len)
                      throws java.io.IOException{
        
//#line 77
out.write((buf).getByteArray(), ((int)(off)), ((int)(len)));
    }

}
