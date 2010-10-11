package x10.util;

public interface ListIterator<T>
  extends x10.
            util.
            CollectionIterator<T>
{public static final x10.rtt.RuntimeType<ListIterator> _RTT = new x10.rtt.RuntimeType<ListIterator>(
/* base class */ListIterator.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), new x10.rtt.ParameterizedType(x10.util.CollectionIterator._RTT, new x10.rtt.UnresolvedType(0))}
);

    
    
    
//#line 15
boolean
                  hasNext(
                  );
    
    
//#line 16
T
                  next$G(
                  );
    
    
//#line 17
int
                  nextIndex(
                  );
    
    
//#line 19
boolean
                  hasPrevious(
                  );
    
    
//#line 20
T
                  previous$G(
                  );
    
    
//#line 21
int
                  previousIndex(
                  );
    
    
//#line 23
void
                  set(
                  final T id$169);
    
    
//#line 24
void
                  add(
                  final T id$170);

}
