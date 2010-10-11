package x10.io;


public class ByteWriter<T>
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<ByteWriter> _RTT = new x10.rtt.RuntimeType<ByteWriter>(
/* base class */ByteWriter.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 17
final public x10.
      util.
      Builder<java.lang.Byte, T>
      b;
    
    
//#line 19
public ByteWriter(final x10.rtt.Type T,
                                  final x10.
                                    util.
                                    Builder<java.lang.Byte, T> b) {
                                                                           super();
                                                                       this.T = T;
                                                                        {
                                                                           
//#line 19
this.b = b;
                                                                       }}
    
    
//#line 21
public void
                  write(
                  final byte x){
        
//#line 21
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(b)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 21
b.add((java.lang.Byte)(x));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 22
public long
                  size(
                  ){
        
//#line 22
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 23
public java.lang.String
                  toString(
                  ){
        
//#line 23
return ((java.lang.Object)(b)).toString();
    }
    
    
//#line 24
public T
                  result$G(
                  ){
        
//#line 24
return x10.
          lang.
          Runtime.<T>evalAt$G(T,
                              ((x10.
                                lang.
                                Place)(x10.lang.Place.place(x10.core.Ref.home(b)))),
                              ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<T>() {public final T apply$G() { {
                                  
//#line 24
return b.result$G();
                              }}
                              public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;return null;
                              }
                              })));
    }
    
    
//#line 26
public void
                  flush(
                  ){
        
    }
    
    
//#line 27
public void
                  close(
                  ){
        
    }

}
