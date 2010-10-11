package x10.io;

public class FilterWriter
extends x10.
  io.
  Writer
{public static final x10.rtt.RuntimeType<FilterWriter> _RTT = new x10.rtt.RuntimeType<FilterWriter>(
/* base class */FilterWriter.class
, /* parents */ new x10.rtt.Type[] {x10.io.Writer._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 15
final public x10.
      io.
      Writer
      w;
    
    
//#line 17
public x10.
                  io.
                  Writer
                  inner(
                  ){
        
//#line 17
return w;
    }
    
    
//#line 19
public FilterWriter(final x10.
                                      io.
                                      Writer w) {
        super();
        
//#line 19
this.w = w;
    }
    
    
//#line 21
public void
                  close(
                  )
                      throws java.io.IOException{
        {
            
//#line 21
w.close();
            
//#line 21
return;
        }
    }
    
    
//#line 22
public void
                  flush(
                  )
                      throws java.io.IOException{
        {
            
//#line 22
w.flush();
            
//#line 22
return;
        }
    }
    
    
//#line 24
public void
                  write(
                  final byte b)
                      throws java.io.IOException{
        {
            
//#line 24
w.write((byte)(b));
            
//#line 24
return;
        }
    }

}
