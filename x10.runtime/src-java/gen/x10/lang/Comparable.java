package x10.lang;

public interface Comparable<T>
{public static final x10.rtt.RuntimeType<Comparable> _RTT = new x10.rtt.RuntimeType<Comparable>(
/* base class */Comparable.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 39
int
                  compareTo(
                  final T that);

}
