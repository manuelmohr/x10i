package x10.lang;

public class Complex
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<Complex> _RTT = new x10.rtt.RuntimeType<Complex>(
/* base class */Complex.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 21
/** The real component of this complex number. */final public double
      re;
    
//#line 23
/** The imaginary component of this complex number. */final public double
      im;
    
//#line 26
/** The complex number that corresponds to 0.0 */final public static x10.
      lang.
      Complex
      ZERO =
      new x10.
      lang.
      Complex(0.0,
              0.0);
    
//#line 28
/** The complex number that corresponds to 1.0 */final public static x10.
      lang.
      Complex
      ONE =
      new x10.
      lang.
      Complex(1.0,
              0.0);
    
//#line 30
/** The complex number that corresponds to 1.0i */final public static x10.
      lang.
      Complex
      I =
      new x10.
      lang.
      Complex(0.0,
              1.0);
    
//#line 32
/** The complex number that corresponds to +Inf + +Inf*i */final public static x10.
      lang.
      Complex
      INF =
      new x10.
      lang.
      Complex(java.lang.Double.POSITIVE_INFINITY,
              java.lang.Double.POSITIVE_INFINITY);
    
//#line 34
/** The complex number that corresponds to NaN + NaN*i */final public static x10.
      lang.
      Complex
      NaN =
      new x10.
      lang.
      Complex(java.lang.Double.NaN,
              java.lang.Double.NaN);
    
    
//#line 43
public Complex(final double real,
                               final double imaginary) {
        
//#line 44
this.re = real;
        
//#line 45
this.im = imaginary;
    }
    
    
//#line 51
final public x10.
                  lang.
                  Complex
                  $plus(
                  final x10.
                    lang.
                    Complex that){
        
//#line 52
return new x10.
          lang.
          Complex(((((double)(re))) + (((double)(that.
                                                   re)))),
                  ((((double)(im))) + (((double)(that.
                                                   im)))));
    }
    
    
//#line 58
final public static x10.
                  lang.
                  Complex
                  $plus(
                  final double x,
                  final x10.
                    lang.
                    Complex y){
        
//#line 58
return y.$plus((double)(x));
    }
    
    
//#line 63
final public x10.
                  lang.
                  Complex
                  $plus(
                  final double that){
        
//#line 64
return new x10.
          lang.
          Complex(((((double)(re))) + (((double)(that)))),
                  im);
    }
    
    
//#line 70
final public x10.
                  lang.
                  Complex
                  $minus(
                  final x10.
                    lang.
                    Complex that){
        
//#line 71
return new x10.
          lang.
          Complex(((((double)(re))) - (((double)(that.
                                                   re)))),
                  ((((double)(im))) - (((double)(that.
                                                   im)))));
    }
    
    
//#line 77
final public static x10.
                  lang.
                  Complex
                  $minus(
                  final double x,
                  final x10.
                    lang.
                    Complex y){
        
//#line 77
return new x10.
          lang.
          Complex(((((double)(x))) - (((double)(y.
                                                  re)))),
                  (-(((double)(y.
                                 im)))));
    }
    
    
//#line 82
final public x10.
                  lang.
                  Complex
                  $minus(
                  final double that){
        
//#line 83
return new x10.
          lang.
          Complex(((((double)(re))) - (((double)(that)))),
                  im);
    }
    
    
//#line 89
final public x10.
                  lang.
                  Complex
                  $times(
                  final x10.
                    lang.
                    Complex that){
        
//#line 90
return new x10.
          lang.
          Complex(((((double)(((((double)(re))) * (((double)(that.
                                                               re))))))) - (((double)(((((double)(im))) * (((double)(that.
                                                                                                                       im)))))))),
                  ((((double)(((((double)(re))) * (((double)(that.
                                                               im))))))) + (((double)(((((double)(im))) * (((double)(that.
                                                                                                                       re)))))))));
    }
    
    
//#line 97
final public static x10.
                  lang.
                  Complex
                  $times(
                  final double x,
                  final x10.
                    lang.
                    Complex y){
        
//#line 97
return y.$times((double)(x));
    }
    
    
//#line 102
final public x10.
                   lang.
                   Complex
                   $times(
                   final double that){
        
//#line 103
return new x10.
          lang.
          Complex(((((double)(re))) * (((double)(that)))),
                  ((((double)(im))) * (((double)(that)))));
    }
    
    
//#line 112
final public x10.
                   lang.
                   Complex
                   $over(
                   final x10.
                     lang.
                     Complex that){
        
//#line 113
if (this.isNaN() ||
                         that.isNaN()) {
            
//#line 114
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 117
final double c =
          that.
            re;
        
//#line 118
final double d =
          that.
            im;
        
//#line 119
if (((double) c) ==
                         ((double) 0.0) &&
                         ((double) d) ==
                         ((double) 0.0)) {
            
//#line 120
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 123
if (that.isInfinite() &&
                         (!(((boolean)(this.isInfinite()))))) {
            
//#line 124
return x10.
              lang.
              Complex.ZERO;
        }
        
//#line 127
if (((((double)(x10.
                           lang.
                           Math.abs((double)(d))))) <= (((double)(x10.
                           lang.
                           Math.abs((double)(c))))))) {
            
//#line 128
if (((double) c) ==
                             ((double) 0.0)) {
                
//#line 129
return new x10.
                  lang.
                  Complex(((((double)(im))) / (((double)(d)))),
                          ((((double)((-(((double)(re))))))) / (((double)(c)))));
            }
            
//#line 131
final double r =
              ((((double)(d))) / (((double)(c))));
            
//#line 132
final double denominator =
              ((((double)(c))) + (((double)(((((double)(d))) * (((double)(r))))))));
            
//#line 133
return new x10.
              lang.
              Complex(((((double)((((((double)(re))) + (((double)(((((double)(im))) * (((double)(r)))))))))))) / (((double)(denominator)))),
                      ((((double)((((((double)(im))) - (((double)(((((double)(re))) * (((double)(r)))))))))))) / (((double)(denominator)))));
        } else {
            
//#line 136
if (((double) d) ==
                             ((double) 0.0)) {
                
//#line 137
return new x10.
                  lang.
                  Complex(((((double)(re))) / (((double)(c)))),
                          ((((double)(im))) / (((double)(c)))));
            }
            
//#line 139
final double r =
              ((((double)(c))) / (((double)(d))));
            
//#line 140
final double denominator =
              ((((double)(((((double)(c))) * (((double)(r))))))) + (((double)(d))));
            
//#line 141
return new x10.
              lang.
              Complex(((((double)((((((double)(((((double)(re))) * (((double)(r))))))) + (((double)(im)))))))) / (((double)(denominator)))),
                      ((((double)((((((double)(((((double)(im))) * (((double)(r))))))) - (((double)(re)))))))) / (((double)(denominator)))));
        }
    }
    
    
//#line 149
final public static x10.
                   lang.
                   Complex
                   $over(
                   final double x,
                   final x10.
                     lang.
                     Complex y){
        
//#line 149
return new x10.
          lang.
          Complex(x,
                  0.0).$over(((x10.
                               lang.
                               Complex)(y)));
    }
    
    
//#line 154
final public x10.
                   lang.
                   Complex
                   $over(
                   final double that){
        
//#line 155
return new x10.
          lang.
          Complex(((((double)(re))) / (((double)(that)))),
                  ((((double)(im))) / (((double)(that)))));
    }
    
    
//#line 161
final public x10.
                   lang.
                   Complex
                   conjugate(
                   ){
        
//#line 162
if (this.isNaN()) {
            
//#line 163
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 165
return new x10.
          lang.
          Complex(re,
                  (-(((double)(im)))));
    }
    
    
//#line 171
final public x10.
                   lang.
                   Complex
                   $plus(
                   ){
        
//#line 171
return this;
    }
    
    
//#line 176
final public x10.
                   lang.
                   Complex
                   $minus(
                   ){
        
//#line 176
return this.isNaN()
          ? x10.
          lang.
          Complex.NaN
          : new x10.
          lang.
          Complex((-(((double)(re)))),
                  (-(((double)(im)))));
    }
    
    
//#line 188
final public double
                   abs(
                   ){
        
//#line 189
if (this.isNaN()) {
            
//#line 190
return java.lang.Double.NaN;
        }
        
//#line 193
if (this.isInfinite()) {
            
//#line 194
return java.lang.Double.POSITIVE_INFINITY;
        }
        
//#line 197
if (((double) im) ==
                         ((double) 0.0)) {
            
//#line 198
return x10.
              lang.
              Math.abs((double)(re));
        } else {
            
//#line 199
if (((double) re) ==
                             ((double) 0.0)) {
                
//#line 200
return x10.
                  lang.
                  Math.abs((double)(im));
            } else {
                
//#line 203
return java.lang.Math.hypot(((double)(re)),((double)(im)));
            }
        }
    }
    
    
//#line 210
final public boolean
                   isNaN(
                   ){
        
//#line 211
return java.lang.Double.isNaN(re) ||
        java.lang.Double.isNaN(im);
    }
    
    
//#line 218
final public boolean
                   isInfinite(
                   ){
        
//#line 219
return (!(((boolean)(this.isNaN())))) &&
        ((java.lang.Double.isInfinite(re) ||
          java.lang.Double.isInfinite(im)));
    }
    
    
//#line 226
final public java.lang.String
                   toString(
                   ){
        
//#line 227
return (((((((((java.lang.Double)(re))) + (" + "))) + (((java.lang.Double)(im))))) + ("i")));
    }
    
    
//#line 19
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 19
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 19
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 19
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 19
final public int
                  hashCode(
                  ){
        
//#line 19
int result =
          0;
        
//#line 19
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   re)).hashCode()))));
        
//#line 19
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   im)).hashCode()))));
        
//#line 19
return result;
    }
    
    
//#line 19
final public boolean
                  equals(
                  java.lang.Object other){
        
//#line 19
if ((!(((boolean)(x10.lang.Complex._RTT.instanceof$(other)))))) {
            
//#line 19
return false;
        }
        
//#line 19
return this.equals(((x10.
                                         lang.
                                         Complex)((new java.lang.Object() {final x10.
                                         lang.
                                         Complex cast(final x10.
                                         lang.
                                         Complex self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Complex._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         lang.
                                         Complex) other)))));
    }
    
    
//#line 19
final public boolean
                  equals(
                  x10.
                    lang.
                    Complex other){
        
//#line 19
return ((double) this.
                                       re) ==
        ((double) other.
                    re) &&
        ((double) this.
                    im) ==
        ((double) other.
                    im);
    }
    
    
//#line 19
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 19
if ((!(((boolean)(x10.lang.Complex._RTT.instanceof$(other)))))) {
            
//#line 19
return false;
        }
        
//#line 19
return this._struct_equals(((x10.
                                                 lang.
                                                 Complex)((new java.lang.Object() {final x10.
                                                 lang.
                                                 Complex cast(final x10.
                                                 lang.
                                                 Complex self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Complex._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 lang.
                                                 Complex) other)))));
    }
    
    
//#line 19
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    Complex other){
        
//#line 19
return ((double) this.
                                       re) ==
        ((double) other.
                    re) &&
        ((double) this.
                    im) ==
        ((double) other.
                    im);
    }

}
