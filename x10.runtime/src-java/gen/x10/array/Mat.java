package x10.array;


abstract public class Mat<T extends x10.
                            array.
                            Row>
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<java.lang.Integer,T>,
             x10.core.Iterable<T >
{public static final x10.rtt.RuntimeType<Mat> _RTT = new x10.rtt.RuntimeType<Mat>(
/* base class */Mat.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.rtt.Types.INT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
// bridge for method abstract public (a1:Z1)=> U.apply(a1:Z1): U
public T
  apply$G(java.lang.Integer a1){return apply$G((int) a1);}

    private final x10.rtt.Type T;
    
    
//#line 16
final public int
      rows;
    
//#line 16
final public int
      cols;
    
    
//#line 19
final public x10.core.ValRail<T>
      mat;
    
    
//#line 21
public Mat(final x10.rtt.Type T,
                           final int rows,
                           final int cols,
                           final x10.core.ValRail<T> mat) {
                                                                   super();
                                                               this.T = T;
                                                                {
                                                                   
//#line 22
this.rows = rows;
                                                                   
//#line 22
this.cols = cols;
                                                                   
//#line 23
this.mat = mat;
                                                               }}
    
    
//#line 26
public T
                  apply$G(
                  final int i){
        
//#line 26
return (mat).apply$G(((int)(i)));
    }
    
    
//#line 28
public x10.core.Iterator<T>
                  iterator(
                  ){
        
//#line 28
return (mat).iterator();
    }
    
    
//#line 30
public void
                  printInfo(
                  final x10.
                    io.
                    Printer ps,
                  final java.lang.String label){
        
//#line 31
ps.printf(((java.lang.String)("%s\n")),
                              ((java.lang.Object)(label)));
        
//#line 32
int row =
          0;
        
//#line 33
for (
//#line 33
final x10.core.Iterator<T> r1554 =
                           this.iterator();
                         r1554.hasNext();
                         ) {
            
//#line 33
final x10.
              array.
              Row r =
              ((x10.
                array.
                Row)
                r1554.next$G());
            
//#line 34
ps.printf(((java.lang.String)("    ")));
            
//#line 35
r.printInfo(((x10.
                                      io.
                                      Printer)(ps)),
                                    (int)(((((int)(row = ((((int)(row))) + (((int)(1))))))) - (((int)(1))))));
        }
    }
    
    
//#line 16
final public int
                  rows(
                  ){
        
//#line 16
return this.
                             rows;
    }
    
    
//#line 16
final public int
                  cols(
                  ){
        
//#line 16
return this.
                             cols;
    }

}
