package x10.array;

final public class VarRow
extends x10.
  array.
  Row
{public static final x10.rtt.RuntimeType<VarRow> _RTT = new x10.rtt.RuntimeType<VarRow>(
/* base class */VarRow.class
, /* parents */ new x10.rtt.Type[] {x10.array.Row._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 16
final public x10.core.Rail<java.lang.Integer>
      row;
    
    
//#line 18
public VarRow(final int cols,
                              final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> init) {
        
//#line 19
super(cols);
        
//#line 20
this.row = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(cols)), init)));
    }
    
    
//#line 23
public VarRow(final int cols) {
        
//#line 24
super(cols);
        
//#line 25
this.row = ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(cols)))));
    }
    
    
//#line 28
public x10.core.Rail<java.lang.Integer>
                  row(
                  ){
        
//#line 28
return x10.
          array.
          VarRow.__$closure$apply$__2002(((x10.core.Rail)(((x10.core.Rail)
                                                            row))));
    }
    
    
//#line 29
public int
                  apply(
                  final int i){
        
//#line 29
return ((int[])this.row().value)[i];
    }
    
    
//#line 31
public int
                  set(
                  final int v,
                  final int i){
        
//#line 31
return (((int[])this.row().value)[i] = v);
    }
    
    final private static x10.core.Rail<java.lang.Integer>
      __$closure$apply$__2002(
      final x10.core.Rail<java.lang.Integer> __desugarer__var__35__){
        
//#line 28
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__35__,null)) &&
                          !(x10.rtt.Equality.equalsequals(((x10.
                              lang.
                              Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__35__)))),x10.
                              lang.
                              Runtime.here()))) {
            
//#line 28
throw new java.lang.ClassCastException("x10.lang.Rail[x10.lang.Int]{self.home==here}");
        }
        
//#line 28
return __desugarer__var__35__;
    }
    
    final public static x10.core.Rail<java.lang.Integer>
      __$closure$apply$__2002$P(
      final x10.core.Rail<java.lang.Integer> __desugarer__var__35__){
        return VarRow.__$closure$apply$__2002(((x10.core.Rail)(__desugarer__var__35__)));
    }

}
