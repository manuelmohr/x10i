package x10.array;


abstract public class Row
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer>
{public static final x10.rtt.RuntimeType<Row> _RTT = new x10.rtt.RuntimeType<Row>(
/* base class */Row.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.rtt.Types.INT, x10.rtt.Types.INT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method abstract public (a1:Z1)=> U.apply(a1:Z1): U
public java.lang.Integer
  apply$G(java.lang.Integer a1){return apply((int) a1);}

    
//#line 18
final public int
      cols;
    
    
    
//#line 20
abstract public int
                  apply(
                  final int i);
    
    
//#line 21
abstract public int
                  set(
                  final int v,
                  final int i);
    
    
//#line 23
public Row(final int cols) {
        super();
        
//#line 23
this.cols = cols;
    }
    
    
//#line 29
public void
                  printInfo(
                  final x10.
                    io.
                    Printer ps,
                  final int row){
        
//#line 30
ps.print(((java.lang.String)("[")));
        
//#line 31
for (
//#line 31
int i =
                           0;
                         ((((int)(i))) < (((int)(cols))));
                         
//#line 31
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 32
ps.print((int)(this.apply((int)(i))));
            
//#line 33
if (((int) i) ==
                            ((int) ((((int)(cols))) - (((int)(2)))))) {
                
//#line 33
ps.print(((java.lang.String)(" |")));
            }
        }
        
//#line 35
ps.print(((java.lang.String)(" ]   ")));
        
//#line 36
this.printEqn(((x10.
                                    io.
                                    Printer)(ps)),
                                  ((java.lang.String)(" ")),
                                  (int)(row));
        
//#line 37
ps.println();
    }
    
    
//#line 44
public void
                  printEqn(
                  final x10.
                    io.
                    Printer ps,
                  final java.lang.String spc,
                  final int row){
        
//#line 45
boolean first =
          true;
        
//#line 46
ps.print(((java.lang.String)((((("y") + (((java.lang.Integer)(row))))) + (" = ")))));
        
//#line 47
for (
//#line 47
int i =
                           0;
                         ((((int)(i))) < (((int)(((((int)(cols))) - (((int)(1))))))));
                         
//#line 47
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 48
final int c =
              this.apply((int)(i));
            
//#line 49
if (((int) c) ==
                            ((int) 1)) {
                
//#line 50
if (first) {
                    
//#line 51
ps.print(((java.lang.String)((("x") + (((java.lang.Integer)(i)))))));
                } else {
                    
//#line 53
ps.print(((java.lang.String)((("+x") + (((java.lang.Integer)(i)))))));
                }
            } else {
                
//#line 54
if (((int) c) ==
                                ((int) -1)) {
                    
//#line 55
ps.print(((java.lang.String)((("-x") + (((java.lang.Integer)(i)))))));
                } else {
                    
//#line 56
if (((int) c) !=
                                    ((int) 0)) {
                        
//#line 57
ps.print(((java.lang.String)((((((((((((((int)(c))) >= (((int)(0)))) &&
                                                                          (!(((boolean)(first))))
                                                                            ? "+"
                                                                            : "")) + (((java.lang.Integer)(c))))) + ("*x"))) + (((java.lang.Integer)(i))))) + (" ")))));
                    }
                }
            }
            
//#line 58
if (((int) c) !=
                            ((int) 0)) {
                
//#line 59
first = false;
            }
        }
        
//#line 61
final int c =
          this.apply((int)(((((int)(cols))) - (((int)(1))))));
        
//#line 62
if (((int) c) !=
                        ((int) 0) ||
                        first) {
            
//#line 62
ps.print(((java.lang.String)((((((((int)(c))) >= (((int)(0)))) &&
                                                        (!(((boolean)(first))))
                                                          ? "+"
                                                          : "")) + (((java.lang.Integer)(c)))))));
        }
    }
    
    
//#line 65
public java.lang.String
                  toString(
                  ){
        
//#line 66
final x10.
          io.
          StringWriter os =
          ((x10.
          io.
          StringWriter)(new x10.
          io.
          StringWriter()));
        
//#line 67
final x10.
          io.
          Printer ps =
          ((x10.
          io.
          Printer)(new x10.
          io.
          Printer(os)));
        
//#line 68
this.printEqn(((x10.
                                    io.
                                    Printer)(ps)),
                                  ((java.lang.String)("")),
                                  (int)(0));
        
//#line 69
return os.result();
    }
    
    
//#line 18
final public int
                  cols(
                  ){
        
//#line 18
return this.
                             cols;
    }

}
