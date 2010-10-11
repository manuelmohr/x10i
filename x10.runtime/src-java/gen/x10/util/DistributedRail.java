package x10.util;


final public class DistributedRail<T>
extends x10.core.Ref
  implements x10.core.Settable<java.lang.Integer, T>,
             x10.core.Iterable<T >
{public static final x10.rtt.RuntimeType<DistributedRail> _RTT = new x10.rtt.RuntimeType<DistributedRail>(
/* base class */DistributedRail.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Settable.class), x10.rtt.Types.INT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
// bridge for method abstract public x10.lang.Settable.set(v:V,i:I): V
public T
  set$G(T a1,
java.lang.Integer a2){return set$G( a1,
(int) a2);}

    private final x10.rtt.Type T;
    
    
//#line 21
final public x10.
      lang.
      PlaceLocalHandle<x10.core.Rail<T>>
      data;
    
//#line 22
final public x10.
      lang.
      Place
      firstPlace;
    
//#line 24
final public x10.
      lang.
      PlaceLocalHandle<x10.
      util.
      HashMap<x10.
      lang.
      Activity, x10.core.Rail<T>>>
      localRails;
    
//#line 27
final public x10.core.ValRail<T>
      original;
    
//#line 28
final public int
      original_len;
    
//#line 30
final public x10.
      lang.
      PlaceLocalHandle<x10.
      lang.
      Cell<java.lang.Boolean>>
      done;
    
    
//#line 32
public DistributedRail(final x10.rtt.Type T,
                                       final int len,
                                       final x10.core.ValRail<T> init) {
                                                                                super();
                                                                            this.T = T;
                                                                             {
                                                                                
//#line 25
this.localRails = x10.
                                                                                  lang.
                                                                                  PlaceLocalHandle.<x10.
                                                                                  util.
                                                                                  HashMap<x10.
                                                                                  lang.
                                                                                  Activity, x10.core.Rail<T>>>make(new x10.rtt.ParameterizedType(x10.util.HashMap._RTT, x10.lang.Activity._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T)),
                                                                                                                   ((x10.
                                                                                                                     array.
                                                                                                                     Dist)(x10.
                                                                                                                     array.
                                                                                                                     Dist.makeUnique())),
                                                                                                                   ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                                                                                                     util.
                                                                                                                     HashMap<x10.
                                                                                                                     lang.
                                                                                                                     Activity, x10.core.Rail<T>>>() {public final x10.
                                                                                                                     util.
                                                                                                                     HashMap<x10.
                                                                                                                     lang.
                                                                                                                     Activity, x10.core.Rail<T>> apply$G() { return apply();}
                                                                                                                   public final x10.
                                                                                                                     util.
                                                                                                                     HashMap<x10.
                                                                                                                     lang.
                                                                                                                     Activity, x10.core.Rail<T>> apply() { {
                                                                                                                       
//#line 26
return new x10.
                                                                                                                         util.
                                                                                                                         HashMap<x10.
                                                                                                                         lang.
                                                                                                                         Activity, x10.core.Rail<T>>(x10.lang.Activity._RTT,
                                                                                                                                                     new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T));
                                                                                                                   }}
                                                                                                                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.HashMap._RTT, x10.lang.Activity._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T));return null;
                                                                                                                   }
                                                                                                                   })));
                                                                                
//#line 30
this.done = x10.
                                                                                  lang.
                                                                                  PlaceLocalHandle.<x10.
                                                                                  lang.
                                                                                  Cell<java.lang.Boolean>>make(new x10.rtt.ParameterizedType(x10.lang.Cell._RTT, x10.rtt.Types.BOOLEAN),
                                                                                                               ((x10.
                                                                                                                 array.
                                                                                                                 Dist)(x10.
                                                                                                                 array.
                                                                                                                 Dist.makeUnique())),
                                                                                                               ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                                                                                                 lang.
                                                                                                                 Cell<java.lang.Boolean>>() {public final x10.
                                                                                                                 lang.
                                                                                                                 Cell<java.lang.Boolean> apply$G() { return apply();}
                                                                                                               public final x10.
                                                                                                                 lang.
                                                                                                                 Cell<java.lang.Boolean> apply() { {
                                                                                                                   
//#line 30
return new x10.
                                                                                                                     lang.
                                                                                                                     Cell<java.lang.Boolean>(x10.rtt.Types.BOOLEAN,
                                                                                                                                             false);
                                                                                                               }}
                                                                                                               public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.Cell._RTT, x10.rtt.Types.BOOLEAN);return null;
                                                                                                               }
                                                                                                               })));
                                                                                
//#line 33
final x10.core.ValRail<T> vr =
                                                                                  ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRail(T, ((int)(len)), init)));
                                                                                
//#line 34
this.data = x10.
                                                                                  lang.
                                                                                  PlaceLocalHandle.<x10.core.Rail<T>>make(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                                                                                          ((x10.
                                                                                                                            array.
                                                                                                                            Dist)(x10.
                                                                                                                            array.
                                                                                                                            Dist.makeUnique())),
                                                                                                                          ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G() { return apply();}
                                                                                                                          public final x10.core.Rail<T> apply() { {
                                                                                                                              
//#line 34
return x10.core.RailFactory.<T>makeVarRail(T, ((int)(len)), vr);
                                                                                                                          }}
                                                                                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
                                                                                                                          }
                                                                                                                          })));
                                                                                
//#line 35
this.firstPlace = x10.
                                                                                  lang.
                                                                                  Runtime.here();
                                                                                
//#line 36
this.original = vr;
                                                                                
//#line 37
this.original_len = len;
                                                                            }}
    
    
//#line 40
public DistributedRail(final x10.rtt.Type T,
                                       final int len,
                                       final x10.core.fun.Fun_0_1<java.lang.Integer,T> init) {
                                                                                                      super();
                                                                                                  this.T = T;
                                                                                                   {
                                                                                                      
//#line 25
this.localRails = x10.
                                                                                                        lang.
                                                                                                        PlaceLocalHandle.<x10.
                                                                                                        util.
                                                                                                        HashMap<x10.
                                                                                                        lang.
                                                                                                        Activity, x10.core.Rail<T>>>make(new x10.rtt.ParameterizedType(x10.util.HashMap._RTT, x10.lang.Activity._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T)),
                                                                                                                                         ((x10.
                                                                                                                                           array.
                                                                                                                                           Dist)(x10.
                                                                                                                                           array.
                                                                                                                                           Dist.makeUnique())),
                                                                                                                                         ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                                                                                                                           util.
                                                                                                                                           HashMap<x10.
                                                                                                                                           lang.
                                                                                                                                           Activity, x10.core.Rail<T>>>() {public final x10.
                                                                                                                                           util.
                                                                                                                                           HashMap<x10.
                                                                                                                                           lang.
                                                                                                                                           Activity, x10.core.Rail<T>> apply$G() { return apply();}
                                                                                                                                         public final x10.
                                                                                                                                           util.
                                                                                                                                           HashMap<x10.
                                                                                                                                           lang.
                                                                                                                                           Activity, x10.core.Rail<T>> apply() { {
                                                                                                                                             
//#line 26
return new x10.
                                                                                                                                               util.
                                                                                                                                               HashMap<x10.
                                                                                                                                               lang.
                                                                                                                                               Activity, x10.core.Rail<T>>(x10.lang.Activity._RTT,
                                                                                                                                                                           new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T));
                                                                                                                                         }}
                                                                                                                                         public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.HashMap._RTT, x10.lang.Activity._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T));return null;
                                                                                                                                         }
                                                                                                                                         })));
                                                                                                      
//#line 30
this.done = x10.
                                                                                                        lang.
                                                                                                        PlaceLocalHandle.<x10.
                                                                                                        lang.
                                                                                                        Cell<java.lang.Boolean>>make(new x10.rtt.ParameterizedType(x10.lang.Cell._RTT, x10.rtt.Types.BOOLEAN),
                                                                                                                                     ((x10.
                                                                                                                                       array.
                                                                                                                                       Dist)(x10.
                                                                                                                                       array.
                                                                                                                                       Dist.makeUnique())),
                                                                                                                                     ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                                                                                                                       lang.
                                                                                                                                       Cell<java.lang.Boolean>>() {public final x10.
                                                                                                                                       lang.
                                                                                                                                       Cell<java.lang.Boolean> apply$G() { return apply();}
                                                                                                                                     public final x10.
                                                                                                                                       lang.
                                                                                                                                       Cell<java.lang.Boolean> apply() { {
                                                                                                                                         
//#line 30
return new x10.
                                                                                                                                           lang.
                                                                                                                                           Cell<java.lang.Boolean>(x10.rtt.Types.BOOLEAN,
                                                                                                                                                                   false);
                                                                                                                                     }}
                                                                                                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.Cell._RTT, x10.rtt.Types.BOOLEAN);return null;
                                                                                                                                     }
                                                                                                                                     })));
                                                                                                      
//#line 41
final x10.core.ValRail<T> vr =
                                                                                                        ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRail(T, ((int)(len)), init)));
                                                                                                      
//#line 42
this.data = x10.
                                                                                                        lang.
                                                                                                        PlaceLocalHandle.<x10.core.Rail<T>>make(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                                                                                                                ((x10.
                                                                                                                                                  array.
                                                                                                                                                  Dist)(x10.
                                                                                                                                                  array.
                                                                                                                                                  Dist.makeUnique())),
                                                                                                                                                ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G() { return apply();}
                                                                                                                                                public final x10.core.Rail<T> apply() { {
                                                                                                                                                    
//#line 42
return x10.core.RailFactory.<T>makeVarRail(T, ((int)(len)), vr);
                                                                                                                                                }}
                                                                                                                                                public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
                                                                                                                                                }
                                                                                                                                                })));
                                                                                                      
//#line 43
this.firstPlace = x10.
                                                                                                        lang.
                                                                                                        Runtime.here();
                                                                                                      
//#line 44
this.original = vr;
                                                                                                      
//#line 45
this.original_len = len;
                                                                                                  }}
    
    
//#line 48
public static <S> x10.core.ValRail<S>
                  $implicit_convert(
                  final x10.rtt.Type S,
                  final x10.
                    util.
                    DistributedRail<S> x){
        
//#line 48
return x10.core.RailFactory.<S>makeValRailFromRail(S, x.apply());
    }
    
    
//#line 50
public x10.core.Rail<T>
                  apply(
                  ){
        
//#line 51
final x10.
          lang.
          Activity a =
          ((x10.
          lang.
          Activity)(x10.
          lang.
          Runtime.activity()));
        
//#line 52
final x10.core.Rail<T> r =
          ((x10.core.Rail)(x10.
          util.
          DistributedRail.<T>__$closure$apply$__2075(T,
                                                     ((x10.core.Rail)(((x10.core.Rail)
                                                                        localRails.apply$G().getOrElse$G(((x10.
                                                                                                           lang.
                                                                                                           Activity)(a)),
                                                                                                         ((x10.core.Rail)(null)))))))));
        
//#line 53
if (x10.rtt.Equality.equalsequals(r,null)) {
            
//#line 54
final x10.core.Rail<T> r_ =
              ((x10.core.Rail)(x10.core.RailFactory.<T>makeVarRail(T, ((int)(original_len)), original)));
            
//#line 55
localRails.apply$G().put(((x10.
                                                   lang.
                                                   Activity)(a)),
                                                 ((x10.core.Rail)(r_)));
            
//#line 56
return r_;
        }
        
//#line 58
return r;
    }
    
    
//#line 61
public x10.core.Rail<T>
                  get(
                  ){
        
//#line 61
return data.apply$G();
    }
    
    
//#line 63
public void
                  drop(
                  ){
        
//#line 63
localRails.apply$G().remove(((x10.
                                                  lang.
                                                  Activity)(x10.
                                                  lang.
                                                  Runtime.activity())));
    }
    
    
//#line 65
public T
                  apply$G(
                  final int i){
        
//#line 65
return (this.apply()).apply$G(((int)(i)));
    }
    
    
//#line 67
public T
                  set$G(
                  final T v,
                  final int i){
        
//#line 68
final x10.core.Rail<T> t =
          ((x10.core.Rail)(this.apply()));
        
//#line 69
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(t)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 70
(t).set$G(v, ((int)(i)));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
        
//#line 71
return v;
    }
    
    
//#line 74
public x10.core.Iterator<T>
                  iterator(
                  ){
        
//#line 75
final x10.core.Rail<T> t =
          ((x10.core.Rail)(this.apply()));
        
//#line 76
return x10.
          lang.
          Runtime.<x10.core.Iterator<T>>evalAt$G(x10.rtt.Types.runtimeType(x10.core.Iterator.class),
                                                 ((x10.
                                                   lang.
                                                   Place)(x10.lang.Place.place(x10.core.Ref.home(t)))),
                                                 ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Iterator<T>>() {public final x10.core.Iterator<T> apply$G() { return apply();}
                                                 public final x10.core.Iterator<T> apply() { {
                                                     
//#line 77
return (t).iterator();
                                                 }}
                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.runtimeType(x10.core.Iterator.class);return null;
                                                 }
                                                 })));
    }
    
    
//#line 80
private void
                  reduceLocal(
                  final x10.core.fun.Fun_0_2<T,T,T> op){
        
//#line 81
final x10.core.Rail<T> master =
          ((x10.core.Rail)(data.apply$G()));
        
//#line 82
boolean first =
          true;
        
//#line 83
for (
//#line 83
final x10.core.Iterator<x10.
                           util.
                           Map.
                           Entry<x10.
                           lang.
                           Activity, x10.core.Rail<T>>> e1833 =
                           (localRails.apply$G().entries()).iterator();
                         e1833.hasNext();
                         ) {
            
//#line 83
final x10.
              util.
              Map.
              Entry<x10.
              lang.
              Activity, x10.core.Rail<T>> e =
              ((x10.
              util.
              Map.
              Entry)(e1833.next$G()));
            
//#line 84
final x10.core.Rail<T> r =
              x10.
              lang.
              Runtime.<x10.core.Rail<T>>evalAt$G(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                 ((x10.
                                                   lang.
                                                   Place)(x10.lang.Place.place(x10.core.Ref.home(e)))),
                                                 ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G() { return apply();}
                                                 public final x10.core.Rail<T> apply() { {
                                                     
//#line 84
return e.getValue$G();
                                                 }}
                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
                                                 }
                                                 })));
            
//#line 85
if (first) {
                
//#line 86
x10.
                  lang.
                  Runtime.runAt(((x10.
                                  lang.
                                  Place)(x10.lang.Place.place(x10.core.Ref.home(r)))),
                                ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                    
//#line 87
try {{
                                        
//#line 87
x10.
                                          lang.
                                          Runtime.startFinish();
                                        {
                                            
//#line 87
x10.lang.Rail__NativeRep.copyTo(T, r,((int)(0)),master,((int)(0)),((int)(r.
                                                                                                                                   length)));
                                        }
                                    }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
                                    if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
                                    java.lang.Throwable __desugarer__var__74__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
                                    {
                                        
//#line 87
x10.
                                          lang.
                                          Runtime.pushException(((java.lang.Throwable)(__desugarer__var__74__)));
                                        throw new java.lang.RuntimeException();
                                    }
                                    }
                                    else {
                                    throw __$generated_wrappedex$__;
                                    }
                                    }catch (java.lang.Throwable __desugarer__var__74__) {
                                        
//#line 87
x10.
                                          lang.
                                          Runtime.pushException(((java.lang.Throwable)(__desugarer__var__74__)));
                                        throw new java.lang.RuntimeException();
                                    }finally {{
                                         
//#line 87
x10.
                                           lang.
                                           Runtime.stopFinish();
                                     }}
                                    }}
                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                    }
                                    })));
                
//#line 88
first = false;
                } else {
                    
//#line 91
for (
//#line 91
int i =
                                       0;
                                     ((((int)(i))) < (((int)(master.
                                                               length))));
                                     
//#line 91
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 92
final int i0 =
                          i;
                        
//#line 93
(master).set$G(op.apply$G((master).apply$G(((int)(i))),
                                                              x10.
                                                                lang.
                                                                Runtime.<T>evalAt$G(T,
                                                                                    ((x10.
                                                                                      lang.
                                                                                      Place)(x10.lang.Place.place(x10.core.Ref.home(r)))),
                                                                                    ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<T>() {public final T apply$G() { {
                                                                                        
//#line 93
return ((T)((T[])r.value)[i0]);
                                                                                    }}
                                                                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;return null;
                                                                                    }
                                                                                    })))), ((int)(i)));
                    }
                }
            }
        }
    
    public static <T> void
      reduceLocal$P(
      final x10.rtt.Type T,
      final x10.core.fun.Fun_0_2<T,T,T> op,
      final x10.
        util.
        DistributedRail<T> DistributedRail){
        DistributedRail.reduceLocal(((x10.core.fun.Fun_0_2)(op)));
    }
    
    
//#line 99
private void
                  reduceGlobal(
                  final x10.core.fun.Fun_0_2<T,T,T> op){
        
//#line 100
if ((!x10.rtt.Equality.equalsequals(firstPlace,x10.
                           lang.
                           Runtime.here()))) {
            
//#line 101
final x10.core.Rail<T> lrail_ =
              ((x10.core.Rail)(data.apply$G()));
            {
                
//#line 103
final x10.core.ValRail<T> lrail =
                  ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, lrail_)));
                
//#line 104
final x10.
                  lang.
                  PlaceLocalHandle<x10.core.Rail<T>> data_ =
                  ((x10.
                  lang.
                  PlaceLocalHandle)(data));
                
//#line 105
x10.
                  lang.
                  Runtime.runAt(((x10.
                                  lang.
                                  Place)(firstPlace)),
                                ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                    
//#line 106
final x10.core.Rail<T> master =
                                      ((x10.core.Rail)(data_.apply$G()));
                                    
//#line 107
try {{
                                        
//#line 107
x10.
                                          lang.
                                          Runtime.lock();
                                        {
                                            
//#line 107
for (
//#line 107
int i =
                                                                0;
                                                              ((((int)(i))) < (((int)(master.
                                                                                        length))));
                                                              
//#line 107
i = ((((int)(i))) + (((int)(1))))) {
                                                
//#line 108
((T[])master.value)[i] = op.apply$G(((T)((T[])master.value)[i]),
                                                                                                 (lrail).apply$G(((int)(i))));
                                            }
                                        }
                                    }}finally {{
                                          
//#line 107
x10.
                                            lang.
                                            Runtime.release();
                                      }}
                                    }}
                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                    }
                                    })));
                }
            
//#line 112
x10.
              lang.
              Runtime.next();
            
//#line 113
final x10.
              lang.
              PlaceLocalHandle<x10.core.Rail<T>> handle =
              ((x10.
              lang.
              PlaceLocalHandle)(data));
            
//#line 114
try {{
                
//#line 114
x10.
                  lang.
                  Runtime.startFinish();
                {
                    
//#line 114
x10.lang.Rail__NativeRep.copyFrom(T, lrail_,((int)(0)),firstPlace,new x10.core.fun.Fun_0_0<x10.
                      util.
                      Pair<x10.core.Rail<T>, java.lang.Integer>>() {public final x10.
                      util.
                      Pair<x10.core.Rail<T>, java.lang.Integer> apply$G() { return apply();}
                    public final x10.
                      util.
                      Pair<x10.core.Rail<T>, java.lang.Integer> apply() { {
                        
//#line 114
return new x10.
                          util.
                          Pair<x10.core.Rail<T>, java.lang.Integer>(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                                    x10.rtt.Types.INT,
                                                                    handle.apply$G(),
                                                                    0);
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T), x10.rtt.Types.INT);return null;
                    }
                    },((int)(lrail_.
                               length)));
                }
            }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
            if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
            java.lang.Throwable __desugarer__var__75__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
            {
                
//#line 114
x10.
                  lang.
                  Runtime.pushException(((java.lang.Throwable)(__desugarer__var__75__)));
                throw new java.lang.RuntimeException();
            }
            }
            else {
            throw __$generated_wrappedex$__;
            }
            }catch (java.lang.Throwable __desugarer__var__75__) {
                
//#line 114
x10.
                  lang.
                  Runtime.pushException(((java.lang.Throwable)(__desugarer__var__75__)));
                throw new java.lang.RuntimeException();
            }finally {{
                 
//#line 114
x10.
                   lang.
                   Runtime.stopFinish();
             }}
            } else {
                
//#line 116
x10.
                  lang.
                  Runtime.next();
            }
        }
        
        public static <T> void
          reduceGlobal$P(
          final x10.rtt.Type T,
          final x10.core.fun.Fun_0_2<T,T,T> op,
          final x10.
            util.
            DistributedRail<T> DistributedRail){
            DistributedRail.reduceGlobal(((x10.core.fun.Fun_0_2)(op)));
        }
        
        
//#line 120
private void
                       bcastLocal(
                       final x10.core.fun.Fun_0_2<T,T,T> op){
            
//#line 121
final x10.core.Rail<T> master =
              ((x10.core.Rail)(data.apply$G()));
            
//#line 122
for (
//#line 122
final x10.core.Iterator<x10.
                                util.
                                Map.
                                Entry<x10.
                                lang.
                                Activity, x10.core.Rail<T>>> e1834 =
                                (localRails.apply$G().entries()).iterator();
                              e1834.hasNext();
                              ) {
                
//#line 122
final x10.
                  util.
                  Map.
                  Entry<x10.
                  lang.
                  Activity, x10.core.Rail<T>> e =
                  ((x10.
                  util.
                  Map.
                  Entry)(e1834.next$G()));
                
//#line 124
final x10.core.Rail<T> r =
                  x10.
                  lang.
                  Runtime.<x10.core.Rail<T>>evalAt$G(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                     ((x10.
                                                       lang.
                                                       Place)(x10.lang.Place.place(x10.core.Ref.home(e)))),
                                                     ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G() { return apply();}
                                                     public final x10.core.Rail<T> apply() { {
                                                         
//#line 124
return e.getValue$G();
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
                                                     }
                                                     })));
                
//#line 125
try {{
                    
//#line 125
x10.
                      lang.
                      Runtime.startFinish();
                    {
                        
//#line 125
x10.
                          lang.
                          Runtime.runAt(((x10.
                                          lang.
                                          Place)(x10.lang.Place.place(x10.core.Ref.home(r)))),
                                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                            
//#line 125
x10.lang.Rail__NativeRep.copyFrom(T, r,((int)(0)),master,((int)(0)),((int)(r.
                                                                                                                                      length)));
                                        }}
                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                        }
                                        })));
                    }
                }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
                if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
                java.lang.Throwable __desugarer__var__76__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
                {
                    
//#line 125
x10.
                      lang.
                      Runtime.pushException(((java.lang.Throwable)(__desugarer__var__76__)));
                    throw new java.lang.RuntimeException();
                }
                }
                else {
                throw __$generated_wrappedex$__;
                }
                }catch (java.lang.Throwable __desugarer__var__76__) {
                    
//#line 125
x10.
                      lang.
                      Runtime.pushException(((java.lang.Throwable)(__desugarer__var__76__)));
                    throw new java.lang.RuntimeException();
                }finally {{
                     
//#line 125
x10.
                       lang.
                       Runtime.stopFinish();
                 }}
                }
            }
        
        public static <T> void
          bcastLocal$P(
          final x10.rtt.Type T,
          final x10.core.fun.Fun_0_2<T,T,T> op,
          final x10.
            util.
            DistributedRail<T> DistributedRail){
            DistributedRail.bcastLocal(((x10.core.fun.Fun_0_2)(op)));
        }
        
        
//#line 131
public void
                       collectiveReduce(
                       final x10.core.fun.Fun_0_2<T,T,T> op){
            
//#line 132
boolean i_won =
              false;
            
//#line 133
try {{
                
//#line 133
x10.
                  lang.
                  Runtime.lock();
                {
                    
//#line 134
if ((!(((boolean)(done.apply$G().
                                                     value))))) {
                        
//#line 135
i_won = true;
                        
//#line 136
done.apply$G().value = true;
                    }
                }
            }}finally {{
                  
//#line 133
x10.
                    lang.
                    Runtime.release();
              }}
            
//#line 139
x10.
              lang.
              Runtime.next();
            
//#line 140
if (i_won) {
                
//#line 142
this.reduceLocal(((x10.core.fun.Fun_0_2)(op)));
                
//#line 143
x10.
                  lang.
                  Runtime.next();
                
//#line 144
this.reduceGlobal(((x10.core.fun.Fun_0_2)(op)));
                
//#line 145
this.bcastLocal(((x10.core.fun.Fun_0_2)(op)));
                
//#line 146
done.apply$G().value = false;
            } else {
                
//#line 148
x10.
                  lang.
                  Runtime.next();
                
//#line 149
x10.
                  lang.
                  Runtime.next();
            }
            
//#line 151
x10.
              lang.
              Runtime.next();
            }
        
        final private static <T> x10.core.Rail<T>
          __$closure$apply$__2075(
          final x10.rtt.Type T,
          final x10.core.Rail<T> __desugarer__var__73__){
            
//#line 52
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__73__,null)) &&
                              !(x10.rtt.Equality.equalsequals(((x10.
                                  lang.
                                  Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__73__)))),x10.
                                  lang.
                                  Runtime.here()))) {
                
//#line 52
throw new java.lang.ClassCastException("x10.lang.Rail[T]{self.home==here}");
            }
            
//#line 52
return __desugarer__var__73__;
        }
        
        final public static <T> x10.core.Rail<T>
          __$closure$apply$__2075$P(
          final x10.rtt.Type T,
          final x10.core.Rail<T> __desugarer__var__73__){
            return DistributedRail.<T>__$closure$apply$__2075(T,
                                                              ((x10.core.Rail)(__desugarer__var__73__)));
        }
        
        }
        