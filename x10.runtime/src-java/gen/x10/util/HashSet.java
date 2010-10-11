package x10.util;

public class HashSet<T>
extends x10.
  util.
  MapSet<T>
{public static final x10.rtt.RuntimeType<HashSet> _RTT = new x10.rtt.RuntimeType<HashSet>(
/* base class */HashSet.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.MapSet._RTT, new x10.rtt.UnresolvedType(0))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
    
//#line 15
public HashSet(final x10.rtt.Type T) {
                                                              
//#line 15
super(T,
                                                                                new x10.core.fun.Fun_0_1<x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean>, x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean>>() {public final x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean> apply$G(final x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean> __desugarer__var__77__) { return apply(__desugarer__var__77__);}
                                                                                public final x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean> apply(final x10.
                                                                                  util.
                                                                                  Map<T, java.lang.Boolean> __desugarer__var__77__) { {
                                                                                    
//#line 15
if (!(x10.rtt.Equality.equalsequals(((x10.
                                                                                                        lang.
                                                                                                        Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__77__)))),x10.
                                                                                                        lang.
                                                                                                        Runtime.here()))) {
                                                                                        
//#line 15
throw new java.lang.ClassCastException("x10.util.Map[T, x10.lang.Boolean]{self.home==here}");
                                                                                    }
                                                                                    
//#line 15
return __desugarer__var__77__;
                                                                                }}
                                                                                public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Map._RTT, T, x10.rtt.Types.BOOLEAN);if (i ==1) return new x10.rtt.ParameterizedType(x10.util.Map._RTT, T, x10.rtt.Types.BOOLEAN);return null;
                                                                                }
                                                                                }.apply(((x10.
                                                                                          util.
                                                                                          Map)
                                                                                          new x10.
                                                                                          util.
                                                                                          HashMap<T, java.lang.Boolean>(T,
                                                                                                                        x10.rtt.Types.BOOLEAN))));
                                                          this.T = T;
                                                           {
                                                              
                                                          }}
    
    
//#line 16
public HashSet(final x10.rtt.Type T,
                               final int sz) {
                                                      
//#line 16
super(T,
                                                                        new x10.core.fun.Fun_0_1<x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean>, x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean>>() {public final x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean> apply$G(final x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean> __desugarer__var__78__) { return apply(__desugarer__var__78__);}
                                                                        public final x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean> apply(final x10.
                                                                          util.
                                                                          Map<T, java.lang.Boolean> __desugarer__var__78__) { {
                                                                            
//#line 16
if (!(x10.rtt.Equality.equalsequals(((x10.
                                                                                                lang.
                                                                                                Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__78__)))),x10.
                                                                                                lang.
                                                                                                Runtime.here()))) {
                                                                                
//#line 16
throw new java.lang.ClassCastException("x10.util.Map[T, x10.lang.Boolean]{self.home==here}");
                                                                            }
                                                                            
//#line 16
return __desugarer__var__78__;
                                                                        }}
                                                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Map._RTT, T, x10.rtt.Types.BOOLEAN);if (i ==1) return new x10.rtt.ParameterizedType(x10.util.Map._RTT, T, x10.rtt.Types.BOOLEAN);return null;
                                                                        }
                                                                        }.apply(((x10.
                                                                                  util.
                                                                                  Map)
                                                                                  new x10.
                                                                                  util.
                                                                                  HashMap<T, java.lang.Boolean>(T,
                                                                                                                x10.rtt.Types.BOOLEAN,
                                                                                                                sz))));
                                                  this.T = T;
                                                   {
                                                      
                                                  }}
    
    
//#line 18
public x10.
                  util.
                  HashSet<T>
                  clone(
                  ){
        
//#line 18
throw new java.lang.RuntimeException("Incomplete method.");
    }

}
