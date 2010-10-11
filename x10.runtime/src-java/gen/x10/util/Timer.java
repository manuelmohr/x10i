package x10.util;


public class Timer
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Timer> _RTT = new x10.rtt.RuntimeType<Timer>(
/* base class */Timer.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 18
native public static long
                  milliTime(
                  );
    
    
//#line 23
native public static long
                  nanoTime(
                  );
    
    
//#line 16
public Timer() {
        
//#line 16
super();
    }

}
