package x10.io;

public class FilterReader
extends x10.
  io.
  Reader
{public static final x10.rtt.RuntimeType<FilterReader> _RTT = new x10.rtt.RuntimeType<FilterReader>(
/* base class */FilterReader.class
, /* parents */ new x10.rtt.Type[] {x10.io.Reader._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 15
final public x10.
      io.
      Reader
      r;
    
    
//#line 17
public x10.
                  io.
                  Reader
                  inner(
                  ){
        
//#line 17
return r;
    }
    
    
//#line 19
public FilterReader(final x10.
                                      io.
                                      Reader r) {
        super();
        
//#line 19
this.r = r;
    }
    
    
//#line 20
public void
                  close(
                  )
                      throws java.io.IOException{
        {
            
//#line 20
r.close();
            
//#line 20
return;
        }
    }
    
    
//#line 21
public byte
                  read(
                  )
                      throws java.io.IOException{
        
//#line 21
return r.read();
    }
    
    
//#line 23
public int
                  available(
                  )
                      throws java.io.IOException{
        
//#line 23
return r.available();
    }
    
    
//#line 25
public void
                  skip(
                  final int off)
                      throws java.io.IOException{
        {
            
//#line 25
r.skip((int)(off));
            
//#line 25
return;
        }
    }
    
    
//#line 27
public void
                  mark(
                  final int off)
                      throws java.io.IOException{
        {
            
//#line 27
r.mark((int)(off));
            
//#line 27
return;
        }
    }
    
    
//#line 28
public void
                  reset(
                  )
                      throws java.io.IOException{
        {
            
//#line 28
r.reset();
            
//#line 28
return;
        }
    }
    
    
//#line 29
public boolean
                  markSupported(
                  ){
        
//#line 29
return r.markSupported();
    }

}
