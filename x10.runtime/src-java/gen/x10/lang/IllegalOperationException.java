package x10.lang;

public class IllegalOperationException
extends java.lang.RuntimeException
{public static final x10.rtt.RuntimeType<IllegalOperationException> _RTT = new x10.rtt.RuntimeType<IllegalOperationException>(
/* base class */IllegalOperationException.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.RuntimeException.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 21
public IllegalOperationException() {
        
//#line 21
super("illegal operation exception");
    }
    
    
//#line 28
public IllegalOperationException(final java.lang.String message) {
        
//#line 28
super(message);
    }

}
