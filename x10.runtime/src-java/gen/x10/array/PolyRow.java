package x10.array;


public class PolyRow
extends x10.
  array.
  ValRow
{public static final x10.rtt.RuntimeType<PolyRow> _RTT = new x10.rtt.RuntimeType<PolyRow>(
/* base class */PolyRow.class
, /* parents */ new x10.rtt.Type[] {x10.array.ValRow._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 30
final public int
      rank;
    
    
    
    
    
    
//#line 42
public PolyRow(final x10.core.ValRail<java.lang.Integer> as_) {
        
//#line 42
this(as_,
                         ((((int)(as_.
                                    length))) - (((int)(1)))));
    }
    
    
//#line 44
private PolyRow(final x10.core.ValRail<java.lang.Integer> as_,
                                final int n) {
        
//#line 45
super(as_);
        
//#line 46
this.rank = n;
    }
    
    
//#line 49
public PolyRow(final x10.
                                 array.
                                 Point p,
                               final int k) {
        
//#line 50
super(((((int)(p.
                                     rank))) + (((int)(1)))),
                          new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                          public final int apply(final int i) { {
                              
//#line 50
return ((((int)(i))) < (((int)(p.
                                                                           rank))))
                                ? p.apply((int)(i))
                                : k;
                          }}
                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                          }
                          });
        
//#line 51
this.rank = p.
                                  rank;
    }
    
    
//#line 54
public PolyRow(final int cols,
                               final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> init) {
        
//#line 55
super(cols,
                          init);
        
//#line 56
this.rank = ((((int)(cols))) - (((int)(1))));
    }
    
    
//#line 66
public static int
                  compare(
                  final x10.
                    array.
                    Row a,
                  final x10.
                    array.
                    Row b){
        
//#line 67
for (
//#line 67
int i =
                           0;
                         ((((int)(i))) < (((int)(a.
                                                   cols))));
                         
//#line 67
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 68
if (((((int)(a.apply((int)(i))))) < (((int)(b.apply((int)(i))))))) {
                
//#line 69
return -1;
            } else {
                
//#line 70
if (((((int)(a.apply((int)(i))))) > (((int)(b.apply((int)(i))))))) {
                    
//#line 71
return 1;
                }
            }
        }
        
//#line 73
return 0;
    }
    
    
//#line 85
public boolean
                  isParallel(
                  final x10.
                    array.
                    PolyRow that){
        
//#line 86
for (
//#line 86
int i =
                           0;
                         ((((int)(i))) < (((int)(((((int)(cols))) - (((int)(1))))))));
                         
//#line 86
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 87
if (((int) this.apply((int)(i))) !=
                            ((int) that.apply((int)(i)))) {
                
//#line 88
return false;
            }
        }
        
//#line 89
return true;
    }
    
    
//#line 98
public boolean
                  isRect(
                  ){
        
//#line 99
boolean nz =
          false;
        
//#line 100
for (
//#line 100
int i =
                            0;
                          ((((int)(i))) < (((int)(((((int)(cols))) - (((int)(1))))))));
                          
//#line 100
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 101
if (((int) this.apply((int)(i))) !=
                             ((int) 0)) {
                
//#line 102
if (nz) {
                    
//#line 102
return false;
                }
                
//#line 103
nz = true;
            }
        }
        
//#line 106
return true;
    }
    
    
//#line 114
public boolean
                   contains(
                   final x10.
                     array.
                     Point p){
        
//#line 115
int sum =
          this.apply((int)(rank));
        
//#line 116
for (
//#line 116
int i =
                            0;
                          ((((int)(i))) < (((int)(rank))));
                          
//#line 116
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 117
sum = ((((int)(sum))) + (((int)(((((int)(this.apply((int)(i))))) * (((int)(p.apply((int)(i))))))))));
        }
        
//#line 118
return ((((int)(sum))) <= (((int)(0))));
    }
    
    
//#line 132
public x10.
                   array.
                   PolyRow
                   complement(
                   ){
        
//#line 133
final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> init =
          ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
        public final int apply(final int i) { {
            
//#line 133
return ((((int)(i))) < (((int)(rank))))
              ? (-(((int)(x10.
              array.
              PolyRow.this.apply((int)(i))))))
              : ((((int)((-(((int)(x10.
              array.
              PolyRow.this.apply((int)(rank))))))))) + (((int)(1))));
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
        }
        }));
        
//#line 134
final x10.core.ValRail<java.lang.Integer> as_ =
          ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRail(x10.rtt.Types.INT, ((int)(((((int)(rank))) + (((int)(1)))))), init)));
        
//#line 135
return new x10.
          array.
          PolyRow(as_);
    }
    
    
//#line 143
public void
                   printEqn(
                   final x10.
                     io.
                     Printer ps,
                   final java.lang.String spc,
                   final int row){
        
//#line 144
int sgn =
          0;
        
//#line 145
boolean first =
          true;
        
//#line 146
for (
//#line 146
int i =
                            0;
                          ((((int)(i))) < (((int)(((((int)(cols))) - (((int)(1))))))));
                          
//#line 146
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 147
if (((int) sgn) ==
                             ((int) 0)) {
                
//#line 148
if (((((int)(this.apply((int)(i))))) < (((int)(0))))) {
                    
//#line 149
sgn = -1;
                } else {
                    
//#line 150
if (((((int)(this.apply((int)(i))))) > (((int)(0))))) {
                        
//#line 151
sgn = 1;
                    }
                }
            }
            
//#line 153
final int c =
              ((((int)(sgn))) * (((int)(this.apply((int)(i))))));
            
//#line 154
if (((int) c) ==
                             ((int) 1)) {
                
//#line 155
if (first) {
                    
//#line 156
ps.print(((java.lang.String)((("x") + (((java.lang.Integer)(i)))))));
                } else {
                    
//#line 158
ps.print(((java.lang.String)((("+x") + (((java.lang.Integer)(i)))))));
                }
            } else {
                
//#line 159
if (((int) c) ==
                                 ((int) -1)) {
                    
//#line 160
ps.print(((java.lang.String)((("-x") + (((java.lang.Integer)(i)))))));
                } else {
                    
//#line 161
if (((int) c) !=
                                     ((int) 0)) {
                        
//#line 162
ps.print(((java.lang.String)((((((((((((((int)(c))) >= (((int)(0)))) &&
                                                                           (!(((boolean)(first))))
                                                                             ? "+"
                                                                             : "")) + (((java.lang.Integer)(c))))) + ("*x"))) + (((java.lang.Integer)(i))))) + (" ")))));
                    }
                }
            }
            
//#line 163
if (((int) c) !=
                             ((int) 0)) {
                
//#line 164
first = false;
            }
        }
        
//#line 166
if (first) {
            
//#line 167
ps.print(((java.lang.String)("0")));
        }
        
//#line 168
if (((((int)(sgn))) > (((int)(0))))) {
            
//#line 169
ps.print(((java.lang.String)(((((((spc) + ("<="))) + (spc))) + (((java.lang.Integer)(((-(((int)(this.apply((int)(((((int)(cols))) - (((int)(1))))))))))))))))));
        } else {
            
//#line 171
ps.print(((java.lang.String)(((((((spc) + (">="))) + (spc))) + (((java.lang.Integer)((this.apply((int)(((((int)(cols))) - (((int)(1))))))))))))));
        }
    }
    
    
//#line 30
final public int
                  rank(
                  ){
        
//#line 30
return this.
                             rank;
    }

}
