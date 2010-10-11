package x10.array;

final public class VarMat
extends x10.
  array.
  Mat<x10.
  array.
  VarRow>
{public static final x10.rtt.RuntimeType<VarMat> _RTT = new x10.rtt.RuntimeType<VarMat>(
/* base class */VarMat.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.array.Mat._RTT, x10.array.VarRow._RTT)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method global public x10.array.Mat.apply(i:x10.lang.Int): T
public x10.
  array.
  VarRow
  apply(int a1){return super.apply$G( a1);}

    
    
//#line 16
public VarMat(final int cols,
                              final x10.core.ValRail<x10.
                                array.
                                VarRow> mat) {
        
//#line 17
super(x10.array.VarRow._RTT,
                          mat.
                            length,
                          cols,
                          mat);
    }
    
    
//#line 19
public VarMat(final int rows,
                              final int cols,
                              final x10.core.fun.Fun_0_1<java.lang.Integer,x10.
                                array.
                                VarRow> init) {
        
//#line 20
super(x10.array.VarRow._RTT,
                          rows,
                          cols,
                          x10.core.RailFactory.<x10.
                            array.
                            VarRow>makeValRail(x10.array.VarRow._RTT, ((int)(rows)), init));
    }
    
    
//#line 22
public VarMat(final int rows,
                              final int cols,
                              final x10.core.fun.Fun_0_2<java.lang.Integer,java.lang.Integer,java.lang.Integer> init) {
        
//#line 23
this(rows,
                         cols,
                         ((x10.core.fun.Fun_0_1)
                           new x10.core.fun.Fun_0_1<java.lang.Integer, x10.
                           array.
                           VarRow>() {public final x10.
                           array.
                           VarRow apply$G(final java.lang.Integer i) { return apply((int)i);}
                         public final x10.
                           array.
                           VarRow apply(final int i) { {
                             
//#line 23
return new x10.
                               array.
                               VarRow(cols,
                                      new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer j) { return apply((int)j);}
                                      public final int apply(final int j) { {
                                          
//#line 23
return init.apply$G(i,
                                                                          j);
                                      }}
                                      public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                                      }
                                      });
                         }}
                         public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.array.VarRow._RTT;return null;
                         }
                         }));
    }
    
    
//#line 25
public VarMat(final int rows,
                              final int cols) {
        
//#line 26
this(rows,
                         cols,
                         ((x10.core.fun.Fun_0_1)
                           new x10.core.fun.Fun_0_1<java.lang.Integer, x10.
                           array.
                           VarRow>() {public final x10.
                           array.
                           VarRow apply$G(final java.lang.Integer id$58) { return apply((int)id$58);}
                         public final x10.
                           array.
                           VarRow apply(final int id$58) { {
                             
//#line 26
return new x10.
                               array.
                               VarRow(cols);
                         }}
                         public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.array.VarRow._RTT;return null;
                         }
                         }));
    }

}
