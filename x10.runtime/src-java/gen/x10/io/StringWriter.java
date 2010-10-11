package x10.io;


public class StringWriter
extends x10.
  io.
  Writer
{public static final x10.rtt.RuntimeType<StringWriter> _RTT = new x10.rtt.RuntimeType<StringWriter>(
/* base class */StringWriter.class
, /* parents */ new x10.rtt.Type[] {x10.io.Writer._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 17
final public x10.
      util.
      StringBuilder
      b;
    
    
//#line 18
public StringWriter() {
        super();
        
//#line 18
this.b = new x10.
          util.
          StringBuilder();
    }
    
    
//#line 20
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
b.add((char)(((char) (((byte)((((byte) (byte) 
                                                                         x))))))));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 24
public int
                  size(
                  ){
        
//#line 24
return x10.
          lang.
          Runtime.<java.lang.Integer>evalAt$G(x10.rtt.Types.INT,
                                              ((x10.
                                                lang.
                                                Place)(x10.lang.Place.place(x10.core.Ref.home(b)))),
                                              ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<java.lang.Integer>() {public final java.lang.Integer apply$G() { return apply();}
                                              public final int apply() { {
                                                  
//#line 24
return b.length();
                                              }}
                                              public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;return null;
                                              }
                                              })));
    }
    
    
//#line 25
public java.lang.String
                  result(
                  ){
        
//#line 25
return x10.
          lang.
          Runtime.<java.lang.String>evalAt$G(x10.rtt.Types.STR,
                                             ((x10.
                                               lang.
                                               Place)(x10.lang.Place.place(x10.core.Ref.home(b)))),
                                             ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<java.lang.String>() {public final java.lang.String apply$G() { return apply();}
                                             public final java.lang.String apply() { {
                                                 
//#line 25
return b.result();
                                             }}
                                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.STR;return null;
                                             }
                                             })));
    }
    
    
//#line 27
public void
                  flush(
                  ){
        
    }
    
    
//#line 28
public void
                  close(
                  ){
        
    }

}
