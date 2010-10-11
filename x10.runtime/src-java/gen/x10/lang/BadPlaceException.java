package x10.lang;

public class BadPlaceException
extends java.lang.RuntimeException
{public static final x10.rtt.RuntimeType<BadPlaceException> _RTT = new x10.rtt.RuntimeType<BadPlaceException>(
/* base class */BadPlaceException.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.RuntimeException.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 23
public BadPlaceException() {
        
//#line 23
super((("bad place exception at ") + (x10.
                            lang.
                            Runtime.here())));
    }
    
    
//#line 30
public BadPlaceException(final java.lang.String message) {
        
//#line 30
super(message);
    }

}
