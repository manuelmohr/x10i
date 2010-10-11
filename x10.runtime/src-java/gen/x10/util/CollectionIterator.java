package x10.util;

public interface CollectionIterator<T>
  extends x10.core.Iterator<T>
{public static final x10.rtt.RuntimeType<CollectionIterator> _RTT = new x10.rtt.RuntimeType<CollectionIterator>(
/* base class */CollectionIterator.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.UnresolvedType(0))}
);

    
    
    
//#line 15
void
                  remove(
                  );

}
