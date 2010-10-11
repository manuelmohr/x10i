package x10.util;

public class ValRailBuilder<T>
extends x10.core.Ref
  implements x10.
               util.
               Builder<T, x10.core.ValRail<T>>
{public static final x10.rtt.RuntimeType<ValRailBuilder> _RTT = new x10.rtt.RuntimeType<ValRailBuilder>(
/* base class */ValRailBuilder.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Builder._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.ValRail.class), new x10.rtt.UnresolvedType(0))), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
// bridge for method abstract public x10.util.Builder.result(): Collection
public x10.core.ValRail<T>
  result$G(){return result();}

    private final x10.rtt.Type T;
    
    
//#line 15
final public x10.core.GrowableRail<T>
      buf;
    
    
//#line 17
public ValRailBuilder(final x10.rtt.Type T) {
                                                                     super();
                                                                 this.T = T;
                                                                  {
                                                                     
//#line 18
this.buf = ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T)));
                                                                 }}
    
    
//#line 21
public ValRailBuilder(final x10.rtt.Type T,
                                      final int size) {
                                                               super();
                                                           this.T = T;
                                                            {
                                                               
//#line 22
this.buf = ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T,
                                                                                                                                            size)));
                                                           }}
    
    
//#line 25
public x10.
                  util.
                  ValRailBuilder<T>
                  add(
                  final T x){
        
//#line 26
(buf).add(x);
        
//#line 27
return this;
    }
    
    
//#line 30
public x10.
                  util.
                  ValRailBuilder<T>
                  insert(
                  final int loc,
                  final x10.core.ValRail<T> items){
        
//#line 31
(buf).insert(((int)(loc)), items);
        
//#line 32
return this;
    }
    
    
//#line 35
public int
                  length(
                  ){
        
//#line 36
return (buf).length();
    }
    
    
//#line 39
public x10.core.ValRail<T>
                  result(
                  ){
        
//#line 39
return (buf).toValRail();
    }

}
