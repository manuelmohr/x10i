package x10.lang;


public class Future<T>
extends x10.core.Ref
  implements x10.core.fun.Fun_0_0<T>
{public static final x10.rtt.RuntimeType<Future> _RTT = new x10.rtt.RuntimeType<Future>(
/* base class */Future.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_0._RTT, new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 26
/**
     * Latch for signaling and wait
     */final public x10.
      lang.
      Runtime.
      Latch
      latch;
    
//#line 32
/**
     * Set if the activity terminated with an exception.
     * Can only be of type Error or RuntimeException
     */final public x10.core.GrowableRail<java.lang.Throwable>
      exception;
    
//#line 34
final public x10.core.GrowableRail<T>
      result;
    
//#line 36
final public x10.core.fun.Fun_0_0<T>
      eval;
    
    
//#line 38
public Future(final x10.rtt.Type T,
                              final x10.core.fun.Fun_0_0<T> eval) {
                                                                           super();
                                                                       this.T = T;
                                                                        {
                                                                           
//#line 26
this.latch = ((x10.
                                                                             lang.
                                                                             Runtime.
                                                                             Latch)(new x10.
                                                                             lang.
                                                                             Runtime.
                                                                             Latch()));
                                                                           
//#line 32
this.exception = ((x10.core.GrowableRail)(new x10.core.GrowableRail<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class))));
                                                                           
//#line 39
this.eval = eval;
                                                                           
//#line 40
this.result = new x10.core.GrowableRail<T>(T);
                                                                       }}
    
    
//#line 43
private x10.core.GrowableRail<T>
                  result(
                  ){
        
//#line 43
return x10.
          lang.
          Future.<T>__$closure$apply$__2012(T,
                                            ((x10.core.GrowableRail)(((x10.core.GrowableRail)
                                                                       result))));
    }
    
    public static <T> x10.core.GrowableRail<T>
      result$P(
      final x10.rtt.Type T,
      final x10.
        lang.
        Future<T> Future){
        return Future.result();
    }
    
    
//#line 48
public boolean
                  forced(
                  ){
        
//#line 48
return x10.
          lang.
          Runtime.<java.lang.Boolean>evalAt$G(x10.rtt.Types.BOOLEAN,
                                              ((x10.
                                                lang.
                                                Place)(x10.lang.Place.place(x10.core.Ref.home(latch)))),
                                              ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<java.lang.Boolean>() {public final java.lang.Boolean apply$G() { return apply();}
                                              public final boolean apply() { {
                                                  
//#line 48
return latch.apply();
                                              }}
                                              public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.BOOLEAN;return null;
                                              }
                                              })));
    }
    
    
//#line 50
public T
                  apply$G(
                  ){
        
//#line 50
return this.force$G();
    }
    
    
//#line 55
public T
                  force$G(
                  ){
        
//#line 56
return x10.
          lang.
          Runtime.<T>evalAt$G(T,
                              ((x10.
                                lang.
                                Place)(x10.lang.Place.place(x10.core.Ref.home(latch)))),
                              ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<T>() {public final T apply$G() { {
                                  
//#line 57
latch.await();
                                  
//#line 58
if (((((int)((exception).length()))) > (((int)(0))))) {
                                      
//#line 59
final java.lang.Throwable e =
                                        (exception).apply$G(((int)(0)));
                                      
//#line 60
if (x10.rtt.Types.runtimeType(java.lang.Error.class).instanceof$(e)) {
                                          
//#line 61
throw (new java.lang.Object() {final java.lang.Error cast(final java.lang.Error self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.Error.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.Error) e));
                                      }
                                      
//#line 62
if (x10.rtt.Types.runtimeType(java.lang.RuntimeException.class).instanceof$(e)) {
                                          
//#line 63
throw (new java.lang.Object() {final java.lang.RuntimeException cast(final java.lang.RuntimeException self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.RuntimeException.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.RuntimeException) e));
                                      }
                                      
//#line 64
assert false;
                                  }
                                  
//#line 66
return (x10.
                                    lang.
                                    Future.this.result()).apply$G(((int)(0)));
                              }}
                              public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;return null;
                              }
                              })));
    }
    
    
//#line 70
public void
                  run(
                  ){
        
//#line 71
try {{
            
//#line 72
try {{
                
//#line 72
x10.
                  lang.
                  Runtime.startFinish();
                {
                    
//#line 72
(this.result()).add(eval.apply$G());
                }
            }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
            if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
            java.lang.Throwable __desugarer__var__41__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
            {
                
//#line 72
x10.
                  lang.
                  Runtime.pushException(((java.lang.Throwable)(__desugarer__var__41__)));
                throw new java.lang.RuntimeException();
            }
            }
            else {
            throw __$generated_wrappedex$__;
            }
            }catch (java.lang.Throwable __desugarer__var__41__) {
                
//#line 72
x10.
                  lang.
                  Runtime.pushException(((java.lang.Throwable)(__desugarer__var__41__)));
                throw new java.lang.RuntimeException();
            }finally {{
                 
//#line 72
x10.
                   lang.
                   Runtime.stopFinish();
             }}
            
//#line 73
latch.release();
            }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
            if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
            final java.lang.Throwable t = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
            {
                
//#line 75
(exception).add(t);
                
//#line 76
latch.release();
            }
            }
            else {
            throw __$generated_wrappedex$__;
            }
            }catch (final java.lang.Throwable t) {
                
//#line 75
(exception).add(t);
                
//#line 76
latch.release();
            }
        }
    
    final private static <T> x10.core.GrowableRail<T>
      __$closure$apply$__2012(
      final x10.rtt.Type T,
      final x10.core.GrowableRail<T> __desugarer__var__40__){
        
//#line 43
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__40__,null)) &&
                          !(x10.rtt.Equality.equalsequals(((x10.
                              lang.
                              Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__40__)))),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 43
throw new java.lang.ClassCastException("x10.util.GrowableRail[T]{self.home==here}");
        }
        
//#line 43
return __desugarer__var__40__;
    }
    
    final public static <T> x10.core.GrowableRail<T>
      __$closure$apply$__2012$P(
      final x10.rtt.Type T,
      final x10.core.GrowableRail<T> __desugarer__var__40__){
        return Future.<T>__$closure$apply$__2012(T,
                                                 ((x10.core.GrowableRail)(__desugarer__var__40__)));
    }
    
    }
    