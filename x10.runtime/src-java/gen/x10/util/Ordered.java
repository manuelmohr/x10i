package x10.util;

public interface Ordered<T>
{public static final x10.rtt.RuntimeType<Ordered> _RTT = new x10.rtt.RuntimeType<Ordered>(
/* base class */Ordered.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 27
boolean
                  $lt(
                  final T that);
    
    
//#line 36
boolean
                  $gt(
                  final T that);
    
    
//#line 45
boolean
                  $le(
                  final T that);
    
    
//#line 54
boolean
                  $ge(
                  final T that);

}
