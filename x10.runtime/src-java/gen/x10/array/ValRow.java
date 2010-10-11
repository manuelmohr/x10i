package x10.array;

public class ValRow
extends x10.
  array.
  Row
{public static final x10.rtt.RuntimeType<ValRow> _RTT = new x10.rtt.RuntimeType<ValRow>(
/* base class */ValRow.class
, /* parents */ new x10.rtt.Type[] {x10.array.Row._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 16
final public x10.core.ValRail<java.lang.Integer>
      row;
    
    
//#line 18
public ValRow(final x10.core.ValRail<java.lang.Integer> row) {
        
//#line 19
super(row.
                            length);
        
//#line 20
this.row = row;
    }
    
    
//#line 23
public ValRow(final x10.core.Rail<java.lang.Integer> row) {
        
//#line 24
this(row.
                           length,
                         new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                         public final int apply(final int i) { {
                             
//#line 24
return ((int[])row.value)[i];
                         }}
                         public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                         }
                         });
    }
    
    
//#line 27
public ValRow(final int cols,
                              final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> init) {
        
//#line 28
super(cols);
        
//#line 29
this.row = x10.core.RailFactory.<java.lang.Integer>makeValRail(x10.rtt.Types.INT, ((int)(cols)), init);
    }
    
    
//#line 32
public int
                  apply(
                  final int i){
        
//#line 32
return ((int[])row.value)[i];
    }
    
    
//#line 34
public int
                  set(
                  final int v,
                  final int i){
        
//#line 35
throw new x10.
          lang.
          IllegalOperationException("ValRow.set");
    }

}
