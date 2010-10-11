package x10.array;


final public class Point
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer>,
             x10.
               util.
               Ordered<x10.
               array.
               Point>
{public static final x10.rtt.RuntimeType<Point> _RTT = new x10.rtt.RuntimeType<Point>(
/* base class */Point.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.rtt.Types.INT, x10.rtt.Types.INT), new x10.rtt.ParameterizedType(x10.util.Ordered._RTT, x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method abstract public (a1:Z1)=> U.apply(a1:Z1): U
public java.lang.Integer
  apply$G(java.lang.Integer a1){return apply((int) a1);}

    
//#line 24
final public int
      rank;
    
    
    
//#line 29
public int
                  apply(
                  final int i){
        
//#line 29
return ((int[])coords.value)[i];
    }
    
    
//#line 35
public x10.core.ValRail<java.lang.Integer>
                  coords(
                  ){
        
//#line 35
return coords;
    }
    
    
//#line 40
public static x10.
                  array.
                  Point
                  make(
                  final x10.core.ValRail<java.lang.Integer> cs){
        
//#line 40
return new x10.
          array.
          Point(cs);
    }
    
    
//#line 45
public static x10.
                  array.
                  Point
                  make(
                  final x10.core.Rail<java.lang.Integer> cs){
        
//#line 46
final x10.core.ValRail<java.lang.Integer> a =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((int[])cs.value)[i];}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, cs.
                                                                                                                                                                                                                                                                                                             length, array);}}.apply(cs.
                                                                                                                                                                                                                                                                                                                                       length))));
        
//#line 47
return x10.
          array.
          Point.make(((x10.core.ValRail)(a)));
    }
    
    
//#line 53
public static x10.
                  array.
                  Point
                  make(
                  final int rank,
                  final x10.core.fun.Fun_0_1<java.lang.Integer,java.lang.Integer> init){
        
//#line 54
final x10.core.ValRail<java.lang.Integer> a =
          ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRail(x10.rtt.Types.INT, ((int)(rank)), init)));
        
//#line 55
return x10.
          array.
          Point.make(((x10.core.ValRail)(a)));
    }
    
    
//#line 59
public static x10.
                  array.
                  Point
                  make(
                  final int i0){
        
//#line 59
return x10.
          array.
          Point.make(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0}))));
    }
    
    
//#line 60
public static x10.
                  array.
                  Point
                  make(
                  final int i0,
                  final int i1){
        
//#line 60
return x10.
          array.
          Point.make(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1}))));
    }
    
    
//#line 61
public static x10.
                  array.
                  Point
                  make(
                  final int i0,
                  final int i1,
                  final int i2){
        
//#line 61
return x10.
          array.
          Point.make(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1, i2}))));
    }
    
    
//#line 62
public static x10.
                  array.
                  Point
                  make(
                  final int i0,
                  final int i1,
                  final int i2,
                  final int i3){
        
//#line 62
return x10.
          array.
          Point.make(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1, i2, i3}))));
    }
    
    
//#line 68
public static x10.
                  array.
                  Point
                  $implicit_convert(
                  final x10.core.Rail<java.lang.Integer> r){
        
//#line 68
return x10.
          array.
          Point.make(((x10.core.Rail)(r)));
    }
    
    
//#line 73
public static x10.
                  array.
                  Point
                  $implicit_convert(
                  final x10.core.ValRail<java.lang.Integer> r){
        
//#line 73
return x10.
          array.
          Point.make(((x10.core.ValRail)(r)));
    }
    
    
//#line 78
public x10.
                  array.
                  Point
                  $plus(
                  ){
        
//#line 78
return this;
    }
    
    
//#line 82
public x10.
                  array.
                  Point
                  $minus(
                  ){
        
//#line 83
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 83
return (-(((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 87
public x10.
                  array.
                  Point
                  $plus(
                  final x10.
                    array.
                    Point that){
        
//#line 88
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 88
return ((((int)(((int[])x10.
                                                               array.
                                                               Point.this.
                                                               coords.value)[i]))) + (((int)(((int[])that.
                                                                                                       coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 93
public x10.
                  array.
                  Point
                  $minus(
                  final x10.
                    array.
                    Point that){
        
//#line 94
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 94
return ((((int)(((int[])x10.
                                                               array.
                                                               Point.this.
                                                               coords.value)[i]))) - (((int)(((int[])that.
                                                                                                       coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 98
public x10.
                  array.
                  Point
                  $times(
                  final x10.
                    array.
                    Point that){
        
//#line 99
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 99
return ((((int)(((int[])x10.
                                                               array.
                                                               Point.this.
                                                               coords.value)[i]))) * (((int)(((int[])that.
                                                                                                       coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 103
public x10.
                   array.
                   Point
                   $over(
                   final x10.
                     array.
                     Point that){
        
//#line 104
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 104
return ((((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))) / (((int)(((int[])that.
                                                                                                        coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 108
public x10.
                   array.
                   Point
                   $plus(
                   final int c){
        
//#line 109
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 109
return ((((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))) + (((int)(c))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 113
public x10.
                   array.
                   Point
                   $minus(
                   final int c){
        
//#line 114
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 114
return ((((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))) - (((int)(c))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 118
public x10.
                   array.
                   Point
                   $times(
                   final int c){
        
//#line 119
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 119
return ((((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))) * (((int)(c))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 123
public x10.
                   array.
                   Point
                   $over(
                   final int c){
        
//#line 124
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 124
return ((((int)(((int[])x10.
                                                                array.
                                                                Point.this.
                                                                coords.value)[i]))) / (((int)(c))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 128
public x10.
                   array.
                   Point
                   $inv_plus(
                   final int c){
        
//#line 129
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 129
return ((((int)(c))) + (((int)(((int[])x10.
                                                                               array.
                                                                               Point.this.
                                                                               coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 133
public x10.
                   array.
                   Point
                   $inv_minus(
                   final int c){
        
//#line 134
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 134
return ((((int)(c))) - (((int)(((int[])x10.
                                                                               array.
                                                                               Point.this.
                                                                               coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 138
public x10.
                   array.
                   Point
                   $inv_times(
                   final int c){
        
//#line 139
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 139
return ((((int)(c))) * (((int)(((int[])x10.
                                                                               array.
                                                                               Point.this.
                                                                               coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 143
public x10.
                   array.
                   Point
                   $inv_over(
                   final int c){
        
//#line 144
return x10.
          array.
          Point.make((int)(rank),
                     ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer i) { return apply((int)i);}
                     public final int apply(final int i) { {
                         
//#line 144
return ((((int)(c))) / (((int)(((int[])x10.
                                                                               array.
                                                                               Point.this.
                                                                               coords.value)[i]))));
                     }}
                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                     }
                     })));
    }
    
    
//#line 153
public int
                   hashCode(
                   ){
        
//#line 154
int hc =
          ((int[])coords.value)[0];
        {
            
//#line 155
final int[] x10$array$Point$this$coords$value1933 =
              ((int[])coords.value);
            
//#line 155
for (
//#line 155
int i =
                                1;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 155
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 156
hc = ((((int)((((((int)(hc))) * (((int)(17)))))))) ^ (((int)(((int)x10$array$Point$this$coords$value1933[i])))));
            }
        }
        
//#line 158
return hc;
    }
    
    
//#line 164
public boolean
                   equals(
                   final java.lang.Object other){
        
//#line 165
if ((!(((boolean)((x10.array.Point._RTT.instanceof$(other))))))) {
            
//#line 165
return false;
        }
        
//#line 166
final x10.
          array.
          Point otherPoint =
          ((x10.
          array.
          Point)((new java.lang.Object() {final x10.
          array.
          Point cast(final x10.
          array.
          Point self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.Point._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          array.
          Point) other))));
        
//#line 167
if (((int) rank) !=
                         ((int) otherPoint.
                                  rank)) {
            
//#line 167
return false;
        }
        {
            
//#line 168
final int[] x10$array$Point$this$coords$value1934 =
              ((int[])this.
                        coords.value);
            
//#line 168
for (
//#line 168
int i =
                                0;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 168
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 169
if ((!(((boolean)((((int) ((int)x10$array$Point$this$coords$value1934[i])) ==
                                                ((int) ((int[])otherPoint.
                                                                 coords.value)[i]))))))) {
                    
//#line 170
return false;
                }
            }
        }
        
//#line 171
return true;
    }
    
    
//#line 176
public boolean
                   $lt(
                   final x10.
                     array.
                     Point that){
        {
            
//#line 177
final int[] x10$array$Point$this$coords$value1935 =
              ((int[])this.
                        coords.value);
            
//#line 177
for (
//#line 177
int i =
                                0;
                              ((((int)(i))) < (((int)(((((int)(rank))) - (((int)(1))))))));
                              
//#line 177
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 178
final int a =
                  ((int)x10$array$Point$this$coords$value1935[i]);
                
//#line 179
final int b =
                  ((int[])that.
                            coords.value)[i];
                
//#line 180
if (((((int)(a))) > (((int)(b))))) {
                    
//#line 180
return false;
                }
                
//#line 181
if (((((int)(a))) < (((int)(b))))) {
                    
//#line 181
return true;
                }
            }
        }
        
//#line 183
return ((((int)(((int[])this.
                                               coords.value)[((((int)(rank))) - (((int)(1))))]))) < (((int)(((int[])that.
                                                                                                                      coords.value)[((((int)(rank))) - (((int)(1))))]))));
    }
    
    
//#line 188
public boolean
                   $gt(
                   final x10.
                     array.
                     Point that){
        {
            
//#line 189
final int[] x10$array$Point$this$coords$value1936 =
              ((int[])this.
                        coords.value);
            
//#line 189
for (
//#line 189
int i =
                                0;
                              ((((int)(i))) < (((int)(((((int)(rank))) - (((int)(1))))))));
                              
//#line 189
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 190
final int a =
                  ((int)x10$array$Point$this$coords$value1936[i]);
                
//#line 191
final int b =
                  ((int[])that.
                            coords.value)[i];
                
//#line 192
if (((((int)(a))) < (((int)(b))))) {
                    
//#line 192
return false;
                }
                
//#line 193
if (((((int)(a))) > (((int)(b))))) {
                    
//#line 193
return true;
                }
            }
        }
        
//#line 195
return ((((int)(((int[])this.
                                               coords.value)[((((int)(rank))) - (((int)(1))))]))) > (((int)(((int[])that.
                                                                                                                      coords.value)[((((int)(rank))) - (((int)(1))))]))));
    }
    
    
//#line 200
public boolean
                   $le(
                   final x10.
                     array.
                     Point that){
        {
            
//#line 201
final int[] x10$array$Point$this$coords$value1937 =
              ((int[])this.
                        coords.value);
            
//#line 201
for (
//#line 201
int i =
                                0;
                              ((((int)(i))) < (((int)(((((int)(rank))) - (((int)(1))))))));
                              
//#line 201
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 202
final int a =
                  ((int)x10$array$Point$this$coords$value1937[i]);
                
//#line 203
final int b =
                  ((int[])that.
                            coords.value)[i];
                
//#line 204
if (((((int)(a))) > (((int)(b))))) {
                    
//#line 204
return false;
                }
                
//#line 205
if (((((int)(a))) < (((int)(b))))) {
                    
//#line 205
return true;
                }
            }
        }
        
//#line 207
return ((((int)(((int[])this.
                                               coords.value)[((((int)(rank))) - (((int)(1))))]))) <= (((int)(((int[])that.
                                                                                                                       coords.value)[((((int)(rank))) - (((int)(1))))]))));
    }
    
    
//#line 212
public boolean
                   $ge(
                   final x10.
                     array.
                     Point that){
        {
            
//#line 213
final int[] x10$array$Point$this$coords$value1938 =
              ((int[])this.
                        coords.value);
            
//#line 213
for (
//#line 213
int i =
                                0;
                              ((((int)(i))) < (((int)(((((int)(rank))) - (((int)(1))))))));
                              
//#line 213
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 214
final int a =
                  ((int)x10$array$Point$this$coords$value1938[i]);
                
//#line 215
final int b =
                  ((int[])that.
                            coords.value)[i];
                
//#line 216
if (((((int)(a))) < (((int)(b))))) {
                    
//#line 216
return false;
                }
                
//#line 217
if (((((int)(a))) > (((int)(b))))) {
                    
//#line 217
return true;
                }
            }
        }
        
//#line 219
return ((((int)(((int[])this.
                                               coords.value)[((((int)(rank))) - (((int)(1))))]))) >= (((int)(((int[])that.
                                                                                                                       coords.value)[((((int)(rank))) - (((int)(1))))]))));
    }
    
    
//#line 224
public java.lang.String
                   toString(
                   ){
        
//#line 225
java.lang.String s =
          "(";
        
//#line 226
if (((((int)(coords.
                                    length))) > (((int)(0))))) {
            
//#line 226
s = ((s) + (((java.lang.Integer)(((int[])coords.value)[0]))));
        }
        {
            
//#line 227
final int[] x10$array$Point$this$coords$value1939 =
              ((int[])coords.value);
            
//#line 227
for (
//#line 227
int i =
                                1;
                              ((((int)(i))) < (((int)(coords.
                                                        length))));
                              
//#line 227
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 228
s = ((s) + (((",") + (((java.lang.Integer)(((int)x10$array$Point$this$coords$value1939[i])))))));
            }
        }
        
//#line 229
s = ((s) + (")"));
        
//#line 230
return s;
    }
    
    
//#line 233
final public x10.core.ValRail<java.lang.Integer>
      coords;
    
    
//#line 234
private Point(final x10.core.ValRail<java.lang.Integer> cs) {
        super();
        
//#line 235
this.rank = cs.
                                   length;
        
//#line 236
this.coords = cs;
    }
    
    
//#line 24
final public int
                  rank(
                  ){
        
//#line 24
return this.
                             rank;
    }

}
