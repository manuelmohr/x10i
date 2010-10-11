package x10.io;


public class InputStreamReader
extends x10.
  io.
  Reader
{public static final x10.rtt.RuntimeType<InputStreamReader> _RTT = new x10.rtt.RuntimeType<InputStreamReader>(
/* base class */InputStreamReader.class
, /* parents */ new x10.rtt.Type[] {x10.io.Reader._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 19
final public java.io.InputStream
      stream;
    
//#line 21
;
    
    
    
//#line 57
public InputStreamReader(final java.io.InputStream stream) {
        super();
        
//#line 58
this.stream = stream;
    }
    
    
//#line 61
public java.io.InputStream
                  stream(
                  ){
        
//#line 61
return stream;
    }
    
    
//#line 63
public void
                  close(
                  )
                      throws java.io.IOException{
        
//#line 63
stream.close();
    }
    
    
//#line 65
public byte
                  read(
                  )
                      throws java.io.IOException{
        
//#line 66
final int n =
          stream.read();
        
//#line 67
if (((int) n) ==
                        ((int) -1)) {
            
//#line 67
throw new java.io.EOFException();
        }
        
//#line 68
return ((byte)(int)(((int)(n))));
    }
    
    
//#line 71
public int
                  available(
                  )
                      throws java.io.IOException{
        
//#line 71
return stream.available();
    }
    
    
//#line 73
public void
                  skip(
                  final int off)
                      throws java.io.IOException{
        {
            
//#line 73
stream.skip(((int)(off)));
            
//#line 73
return;
        }
    }
    
    
//#line 75
public void
                  mark(
                  final int off)
                      throws java.io.IOException{
        {
            
//#line 75
stream.mark(((int)(off)));
            
//#line 75
return;
        }
    }
    
    
//#line 76
public void
                  reset(
                  )
                      throws java.io.IOException{
        {
            
//#line 76
stream.reset();
            
//#line 76
return;
        }
    }
    
    
//#line 77
public boolean
                  markSupported(
                  ){
        
//#line 77
return stream.markSupported();
    }

}
