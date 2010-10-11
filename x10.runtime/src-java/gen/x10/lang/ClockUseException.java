package x10.lang;

public class ClockUseException
extends java.lang.RuntimeException
{public static final x10.rtt.RuntimeType<ClockUseException> _RTT = new x10.rtt.RuntimeType<ClockUseException>(
/* base class */ClockUseException.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.RuntimeException.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 23
public ClockUseException() {
        
//#line 23
super("clock use exception");
    }
    
    
//#line 30
public ClockUseException(final java.lang.String message) {
        
//#line 30
super(message);
    }

}
