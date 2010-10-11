package x10.util;

public class MapIterator<S, T>
extends x10.core.Ref
  implements x10.core.Iterator<T>
{public static final x10.rtt.RuntimeType<MapIterator> _RTT = new x10.rtt.RuntimeType<MapIterator>(
/* base class */MapIterator.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.CONTRAVARIANT, 
x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.UnresolvedType(1)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return S;if (i ==1)return T;return null;}

    private final x10.rtt.Type S;
    private final x10.rtt.Type T;
    
    
//#line 15
final public x10.core.Iterator<S>
      i;
    
//#line 16
final public x10.core.fun.Fun_0_1<S,T>
      f;
    
    
//#line 18
public MapIterator(final x10.rtt.Type S,
                                   final x10.rtt.Type T,
                                   final x10.core.Iterator<S> i,
                                   final x10.core.fun.Fun_0_1<S,T> f) {
                                                                               super();
                                                                           this.S = S;
                                                                           this.T = T;
                                                                            {
                                                                               
//#line 19
this.i = ((x10.core.Iterator)(i));
                                                                               
//#line 20
this.f = f;
                                                                           }}
    
    
//#line 23
public boolean
                  hasNext(
                  ){
        
//#line 23
return i.hasNext();
    }
    
    
//#line 24
public T
                  next$G(
                  ){
        
//#line 24
return f.apply$G(i.next$G());
    }

}
