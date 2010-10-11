package x10.lang;

final public class Cell<T>
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Cell> _RTT = new x10.rtt.RuntimeType<Cell>(
/* base class */Cell.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 25
/**
     * The value stored in this cell.
     */public T
      value;
    
    
//#line 32
public Cell(final x10.rtt.Type T,
                            final T x) {
                                                super();
                                            this.T = T;
                                             {
                                                
//#line 32
this.value = ((T)(x));
                                            }}
    
    
//#line 42
public java.lang.String
                  toString(
                  ){
        
//#line 43
if ((!(((boolean)(x10.core.Ref.at((java.lang.Object)(this), x10.
                          lang.
                          Runtime.here().id)))))) {
            
//#line 43
throw new java.lang.UnsupportedOperationException();
        }
        
//#line 44
return (((("Cell(") + (((java.lang.Object)(((java.lang.Object)(((x10.
                                                                                       lang.
                                                                                       Cell.<T>__$closure$apply$__2006(T,
                                                                                                                       ((x10.
                                                                                                                         lang.
                                                                                                                         Cell)(((x10.
                                                                                                                                 lang.
                                                                                                                                 Cell)
                                                                                                                                 this)))))).
                                                                                     value)))).toString()))) + (")"));
    }
    
    
//#line 54
public T
                  apply$G(
                  ){
        
//#line 54
return x10.
          lang.
          Runtime.<T>evalAt$G(T,
                              ((x10.
                                lang.
                                Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                              ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<T>() {public final T apply$G() { {
                                  
//#line 54
return value;
                              }}
                              public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;return null;
                              }
                              })));
    }
    
    
//#line 62
public void
                  apply(
                  final T x){
        
//#line 62
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 62
x10.
                              lang.
                              Cell.this.value = ((T)(x));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 71
public T
                  set$G(
                  final T x){
        
//#line 71
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 71
x10.
                              lang.
                              Cell.this.value = ((T)(x));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
        
//#line 71
return x;
    }
    
    
//#line 81
public static <T> x10.
                  lang.
                  Cell<T>
                  make(
                  final x10.rtt.Type T,
                  final T x){
        
//#line 81
return new x10.
          lang.
          Cell<T>(T,
                  x);
    }
    
    
//#line 92
public static <T> T
                  $implicit_convert$G(
                  final x10.rtt.Type T,
                  final x10.
                    lang.
                    Cell<T> x){
        
//#line 92
return x.apply$G();
    }
    
    
//#line 101
public static <T> x10.
                   lang.
                   Cell<T>
                   $implicit_convert(
                   final x10.rtt.Type T,
                   final T x){
        
//#line 101
return x10.
          lang.
          Cell.<T>make(T,
                       ((T)(x)));
    }
    
    final private static <T> x10.
      lang.
      Cell<T>
      __$closure$apply$__2006(
      final x10.rtt.Type T,
      final x10.
        lang.
        Cell<T> __desugarer__var__39__){
        
//#line 44
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__39__,null)) &&
                          !(x10.rtt.Equality.equalsequals(((x10.
                              lang.
                              Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__39__)))),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 44
throw new java.lang.ClassCastException("x10.lang.Cell[T]{self.home==here}");
        }
        
//#line 44
return __desugarer__var__39__;
    }
    
    final public static <T> x10.
      lang.
      Cell<T>
      __$closure$apply$__2006$P(
      final x10.rtt.Type T,
      final x10.
        lang.
        Cell<T> __desugarer__var__39__){
        return Cell.<T>__$closure$apply$__2006(T,
                                               ((x10.
                                                 lang.
                                                 Cell)(__desugarer__var__39__)));
    }

}
