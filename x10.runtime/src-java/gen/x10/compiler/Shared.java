package x10.compiler;

public class Shared<T>
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Shared> _RTT = new x10.rtt.RuntimeType<Shared>(
/* base class */Shared.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 15
public T
      x;
    
    
//#line 16
public Shared(final x10.rtt.Type T,
                              final T x) {
                                                  super();
                                              this.T = T;
                                               {
                                                  
//#line 16
this.x = ((T)(x));
                                              }}
    
    
//#line 17
public T
                  get$G(
                  ){
        
//#line 17
return x;
    }
    
    
//#line 18
public void
                  set(
                  final T x){
        
//#line 18
this.x = ((T)(x));
    }

}
