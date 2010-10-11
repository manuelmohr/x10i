package x10.compiler;

public class CUDAUtilities
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<CUDAUtilities> _RTT = new x10.rtt.RuntimeType<CUDAUtilities>(
/* base class */CUDAUtilities.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 34
public static x10.
                  lang.
                  UInt
                  autoBlocks(
                  ){
        
//#line 34
return x10.
          lang.
          UInt.$implicit_convert((int)(8));
    }
    
    
//#line 39
public static x10.
                  lang.
                  UInt
                  autoThreads(
                  ){
        
//#line 39
return x10.
          lang.
          UInt.$implicit_convert((int)(1));
    }
    
    
//#line 17
public CUDAUtilities() {
        
//#line 17
super();
    }

}
