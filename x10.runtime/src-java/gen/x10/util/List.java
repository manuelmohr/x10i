package x10.util;

public interface List<T>
  extends x10.
            util.
            Collection<T>,
          x10.
            util.
            Indexed<T>,
          x10.core.Settable<java.lang.Integer, T>
{public static final x10.rtt.RuntimeType<List> _RTT = new x10.rtt.RuntimeType<List>(
/* base class */List.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), new x10.rtt.ParameterizedType(x10.util.Collection._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.Indexed._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Settable.class), x10.rtt.Types.INT, new x10.rtt.UnresolvedType(0))}
);

    
    
    
//#line 15
x10.
                  util.
                  List<java.lang.Integer>
                  indices(
                  );
    
    
//#line 17
void
                  addBefore(
                  final int i,
                  final T id$160);
    
    
//#line 18
T
                  removeAt$G(
                  final int i);
    
    
//#line 19
int
                  indexOf(
                  final T id$161);
    
    
//#line 20
int
                  lastIndexOf(
                  final T id$162);
    
    
//#line 21
int
                  indexOf(
                  final int id$163,
                  final T id$164);
    
    
//#line 22
int
                  lastIndexOf(
                  final int id$165,
                  final T id$166);
    
    
//#line 23
x10.
                  util.
                  ListIterator<T>
                  iterator(
                  );
    
    
//#line 24
x10.
                  util.
                  ListIterator<T>
                  iteratorFrom(
                  final int i);
    
    
//#line 25
x10.
                  util.
                  List<T>
                  subList(
                  final int fromIndex,
                  final int toIndex);
    
    
//#line 27
T
                  removeFirst$G(
                  );
    
    
//#line 28
T
                  removeLast$G(
                  );
    
    
//#line 29
T
                  getFirst$G(
                  );
    
    
//#line 30
T
                  getLast$G(
                  );
    
    
//#line 32
void
                  reverse(
                  );
    
    
//#line 34
void
                  sort(
                  );
    
    
//#line 35
void
                  sort(
                  final x10.core.fun.Fun_0_2<T,T,java.lang.Integer> cmp);

}
