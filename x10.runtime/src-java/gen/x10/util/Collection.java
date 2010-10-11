package x10.util;

public interface Collection<T>
  extends x10.
            util.
            Container<T>
{public static final x10.rtt.RuntimeType<Collection> _RTT = new x10.rtt.RuntimeType<Collection>(
/* base class */Collection.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), new x10.rtt.ParameterizedType(x10.util.Container._RTT, new x10.rtt.UnresolvedType(0))}
);

    
    
    
//#line 16
boolean
                  add(
                  final T id$132);
    
    
//#line 17
boolean
                  remove(
                  final T id$133);
    
    
//#line 18
boolean
                  addAll(
                  final x10.
                    util.
                    Container<T> id$134);
    
    
//#line 19
boolean
                  retainAll(
                  final x10.
                    util.
                    Container<T> id$135);
    
    
//#line 20
boolean
                  removeAll(
                  final x10.
                    util.
                    Container<T> id$136);
    
    
//#line 21
boolean
                  addAllWhere(
                  final x10.
                    util.
                    Container<T> id$137,
                  final x10.core.fun.Fun_0_1<T,java.lang.Boolean> id$139);
    
    
//#line 22
boolean
                  removeAllWhere(
                  final x10.core.fun.Fun_0_1<T,java.lang.Boolean> id$141);
    
    
//#line 23
void
                  clear(
                  );
    
    
//#line 24
x10.
                  util.
                  Collection<T>
                  clone(
                  );

}
