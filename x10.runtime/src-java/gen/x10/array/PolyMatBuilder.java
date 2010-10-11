package x10.array;


public class PolyMatBuilder
extends x10.
  array.
  MatBuilder
{public static final x10.rtt.RuntimeType<PolyMatBuilder> _RTT = new x10.rtt.RuntimeType<PolyMatBuilder>(
/* base class */PolyMatBuilder.class
, /* parents */ new x10.rtt.Type[] {x10.array.MatBuilder._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 22
final public int
      rank;
    
    
    
    
    
//#line 33
public PolyMatBuilder(final int rank) {
        
//#line 34
super(((((int)(rank))) + (((int)(1)))));
        
//#line 35
this.rank = rank;
    }
    
    
//#line 43
public x10.
                  array.
                  PolyMat
                  toSortedPolyMat(
                  final boolean isSimplified){
        
//#line 44
mat.sort(((x10.core.fun.Fun_0_2)(new x10.core.fun.Fun_0_2<x10.
                               array.
                               Row, x10.
                               array.
                               Row, java.lang.Integer>() {public final java.lang.Integer apply$G(final x10.
                               array.
                               Row id$51,final x10.
                               array.
                               Row id$52) { return apply(id$51,id$52);}
                             public final int apply(final x10.
                               array.
                               Row id$51, final x10.
                               array.
                               Row id$52) { {
                                 
//#line 44
return x10.
                                   array.
                                   PolyRow.compare(((x10.
                                                     array.
                                                     Row)(id$51)),
                                                   ((x10.
                                                     array.
                                                     Row)(id$52)));
                             }}
                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Row._RTT;if (i ==1) return x10.array.Row._RTT;if (i ==2) return x10.rtt.Types.INT;return null;
                             }
                             })));
        
//#line 45
final x10.
          array.
          PolyMat result =
          ((x10.
          array.
          PolyMat)(new x10.
          array.
          PolyMat(mat.size(),
                  ((((int)(rank))) + (((int)(1)))),
                  new x10.core.fun.Fun_0_2<java.lang.Integer, java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i,final java.lang.Integer j) { return apply((int)i,(int)j);}
                  public final int apply(final int i, final int j) { {
                      
//#line 45
return mat.apply$G((int)(i)).apply((int)(j));
                  }}
                  public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;if (i ==2) return x10.rtt.Types.INT;return null;
                  }
                  },
                  isSimplified)));
        
//#line 46
return new x10.core.fun.Fun_0_1<x10.
          array.
          PolyMat, x10.
          array.
          PolyMat>() {public final x10.
          array.
          PolyMat apply$G(final x10.
          array.
          PolyMat __desugarer__var__22__) { return apply(__desugarer__var__22__);}
        public final x10.
          array.
          PolyMat apply(final x10.
          array.
          PolyMat __desugarer__var__22__) { {
            
//#line 46
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__22__,null)) &&
                              !(((int) __desugarer__var__22__.
                                         rank) ==
                                ((int) x10.
                                         array.
                                         PolyMatBuilder.this.
                                         rank))) {
                
//#line 46
throw new java.lang.ClassCastException(("x10.array.PolyMat{self.rank==x10.array.PolyMatBuilder#this.r" +
                                                                    "ank}"));
            }
            
//#line 46
return __desugarer__var__22__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.PolyMat._RTT;if (i ==1) return x10.array.PolyMat._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  PolyMat)
                  result));
    }
    
    
//#line 59
/**
     * a simple mechanism of somewhat dubious utility to allow
     * semi-symbolic specification of halfspaces. For example
     * X0-Y1 >= n is specified as add(X(0)-Y(1), GE, n)
     *
     * XXX coefficients must be -1,0,+1; can allow larger coefficients
     * by increasing # bits per coeff
     */final public static int
      ZERO =
      178956970;
    
//#line 61
final public static int
      GE =
      0;
    
//#line 62
final public static int
      LE =
      1;
    
    
//#line 64
final public static int
                  X(
                  final int axis){
        
//#line 65
return ((((int)(1))) << (((int)(((((int)(2))) * (((int)(axis))))))));
    }
    
    
//#line 68
public void
                  add(
                  int coeff,
                  final int op,
                  final int k){
        
//#line 69
coeff = ((((int)(coeff))) + (((int)(x10.
          array.
          PolyMatBuilder.ZERO))));
        
//#line 70
final x10.core.Rail<java.lang.Integer> as_ =
          ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(((((int)(rank))) + (((int)(1)))))))));
        {
            
//#line 71
final int[] as_$value1944 =
              ((int[])as_.value);
            
//#line 71
for (
//#line 71
int i =
                               0;
                             ((((int)(i))) < (((int)(rank))));
                             
//#line 71
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 72
final int a =
                  ((((int)((((((int)(coeff))) & (((int)(3)))))))) - (((int)(2))));
                
//#line 73
as_$value1944[i]=((int) op) ==
                ((int) x10.
                  array.
                  PolyMatBuilder.LE)
                  ? a
                  : (-(((int)(a))));
                
//#line 74
coeff = ((((int)(coeff))) >> (((int)(2))));
            }
        }
        
//#line 76
((int[])as_.value)[rank] = ((int) op) ==
        ((int) x10.
          array.
          PolyMatBuilder.LE)
          ? (-(((int)(k))))
          : k;
        
//#line 77
this.add(((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                             public final int apply(final int i) { {
                                 
//#line 77
return ((int[])as_.value)[i];
                             }}
                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                             }
                             })));
    }
    
    
//#line 22
final public int
                  rank(
                  ){
        
//#line 22
return this.
                             rank;
    }

}
