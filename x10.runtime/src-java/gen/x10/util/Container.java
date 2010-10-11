package x10.util;

public interface Container<T>
  extends x10.core.Iterable<T >
{public static final x10.rtt.RuntimeType<Container> _RTT = new x10.rtt.RuntimeType<Container>(
/* base class */Container.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), new x10.rtt.UnresolvedType(0))}
);

    
    
    
//#line 16
int
                  size(
                  );
    
    
//#line 17
boolean
                  isEmpty(
                  );
    
    
//#line 18
boolean
                  contains(
                  final T id$142);
    
    
//#line 19
x10.core.ValRail<T>
                  toValRail(
                  );
    
    
//#line 20
x10.core.Rail<T>
                  toRail(
                  );
    
    
//#line 21
boolean
                  containsAll(
                  final x10.
                    util.
                    Container<T> id$143);
    
    
//#line 22
x10.
                  util.
                  Container<T>
                  clone(
                  );

}
