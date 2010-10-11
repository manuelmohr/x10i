package x10.compiler;

public interface SetOps<T>
{public static final x10.rtt.RuntimeType<SetOps> _RTT = new x10.rtt.RuntimeType<SetOps>(
/* base class */SetOps.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 15
T
                  $not$G(
                  );
    
    
//#line 16
T
                  $and$G(
                  final T that);
    
    
//#line 17
T
                  $or$G(
                  final T that);
    
    
//#line 18
T
                  $minus$G(
                  final T that);

}
