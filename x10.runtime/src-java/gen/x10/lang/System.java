package x10.lang;


public class System
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<System> _RTT = new x10.rtt.RuntimeType<System>(
/* base class */System.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 21
private System() {
        super();
    }
    
    
//#line 28
public static long
                  currentTimeMillis(
                  ){
        
//#line 28
return java.lang.System.currentTimeMillis();
    }
    
    
//#line 35
public static long
                  nanoTime(
                  ){
        
//#line 35
return java.lang.System.nanoTime();
    }
    
    
//#line 46
native public static void
                  exit(
                  final int code);
    
    
//#line 59
public static void
                  exit(
                  ){
        {
            
//#line 59
java.lang.System.exit(((int)(-1)));
            
//#line 59
return;
        }
    }
    
    
//#line 66
public static void
                  setExitCode(
                  final int exitCode){
        
    }
    
    
//#line 80
native public static long
                  heapSize(
                  );
    
    
//#line 92
native public static void
                  setProperty(
                  final java.lang.String p,
                  final java.lang.String v);

}
