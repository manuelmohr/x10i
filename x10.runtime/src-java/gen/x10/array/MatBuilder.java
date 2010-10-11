package x10.array;


public class MatBuilder
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<MatBuilder> _RTT = new x10.rtt.RuntimeType<MatBuilder>(
/* base class */MatBuilder.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 18
final public x10.
      util.
      ArrayList<x10.
      array.
      Row>
      mat;
    
//#line 19
final public int
      cols;
    
    
//#line 21
public MatBuilder(final int cols) {
        super();
        
//#line 22
this.cols = cols;
        
//#line 23
this.mat = ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<x10.
          array.
          Row>(x10.array.Row._RTT)));
    }
    
    
//#line 26
public MatBuilder(final int rows,
                                  final int cols) {
        super();
        
//#line 27
this.cols = cols;
        
//#line 28
final x10.
          util.
          ArrayList<x10.
          array.
          Row> m =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<x10.
          array.
          Row>(x10.array.Row._RTT,
               rows)));
        
//#line 29
this.mat = ((x10.
          util.
          ArrayList)(m));
        
//#line 30
x10.
          array.
          MatBuilder.need((int)(rows),
                          ((x10.
                            util.
                            ArrayList)(m)),
                          (int)(cols));
    }
    
    
//#line 33
public void
                  add(
                  final x10.
                    array.
                    Row row){
        
//#line 34
mat.add(((x10.
                              array.
                              Row)(row)));
    }
    
    
//#line 37
public void
                  add(
                  final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> a){
        
//#line 38
mat.add(((x10.
                              array.
                              Row)(new x10.
                              array.
                              VarRow(cols,
                                     a))));
    }
    
    
//#line 41
public int
                  apply(
                  final int i,
                  final int j){
        
//#line 41
return mat.apply$G((int)(i)).apply((int)(j));
    }
    
    
//#line 43
public void
                  set(
                  final int v,
                  final int i,
                  final int j){
        
//#line 44
this.need((int)(((((int)(i))) + (((int)(1))))));
        
//#line 45
mat.apply$G((int)(i)).set((int)(v),
                                              (int)(j));
    }
    
    
//#line 48
public void
                  setDiagonal(
                  final int i,
                  final int j,
                  final int n,
                  final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> v){
        
//#line 49
this.need((int)(((((int)(i))) + (((int)(n))))));
        
//#line 50
for (
//#line 50
int k =
                           0;
                         ((((int)(k))) < (((int)(n))));
                         
//#line 50
k = ((((int)(k))) + (((int)(1))))) {
            
//#line 51
mat.apply$G((int)(((((int)(i))) + (((int)(k)))))).set((int)(java.lang.Integer)(v.apply$G(k)),
                                                                              (int)(((((int)(j))) + (((int)(k))))));
        }
    }
    
    
//#line 54
public void
                  setColumn(
                  final int i,
                  final int j,
                  final int n,
                  final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> v){
        
//#line 55
this.need((int)(((((int)(i))) + (((int)(n))))));
        
//#line 56
for (
//#line 56
int k =
                           0;
                         ((((int)(k))) < (((int)(n))));
                         
//#line 56
k = ((((int)(k))) + (((int)(1))))) {
            
//#line 57
mat.apply$G((int)(((((int)(i))) + (((int)(k)))))).set((int)(java.lang.Integer)(v.apply$G(k)),
                                                                              (int)(j));
        }
    }
    
    
//#line 60
public void
                  setRow(
                  final int i,
                  final int j,
                  final int n,
                  final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> v){
        
//#line 61
this.need((int)(((((int)(i))) + (((int)(1))))));
        
//#line 62
for (
//#line 62
int k =
                           0;
                         ((((int)(k))) < (((int)(n))));
                         
//#line 62
k = ((((int)(k))) + (((int)(1))))) {
            
//#line 63
mat.apply$G((int)(i)).set((int)(java.lang.Integer)(v.apply$G(k)),
                                                  (int)(((((int)(j))) + (((int)(k))))));
        }
    }
    
    
//#line 66
private void
                  need(
                  final int n){
        {
            
//#line 66
x10.
              array.
              MatBuilder.need((int)(n),
                              ((x10.
                                util.
                                ArrayList)(this.
                                             mat)),
                              (int)(this.
                                      cols));
            
//#line 66
return;
        }
    }
    
    public static void
      need$P(
      final int n,
      final x10.
        array.
        MatBuilder MatBuilder){
        MatBuilder.need((int)(n));
    }
    
    
//#line 67
private static void
                  need(
                  final int n,
                  final x10.
                    util.
                    ArrayList<x10.
                    array.
                    Row> mat,
                  final int cols){
        
//#line 68
while (((((int)(mat.size()))) < (((int)(n)))))
            
//#line 69
mat.add(((x10.
                                  array.
                                  Row)(new x10.
                                  array.
                                  VarRow(cols))));
    }
    
    public static void
      need$P(
      final int n,
      final x10.
        util.
        ArrayList<x10.
        array.
        Row> mat,
      final int cols){
        MatBuilder.need((int)(n),
                        ((x10.
                          util.
                          ArrayList)(mat)),
                        (int)(cols));
    }

}
