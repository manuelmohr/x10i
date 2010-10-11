package x10.lang;


final public class Math
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Math> _RTT = new x10.rtt.RuntimeType<Math>(
/* base class */Math.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 18
final public static double
      E =
      2.718281828459045;
    
//#line 19
final public static double
      PI =
      3.141592653589793;
    
    
//#line 21
public static double
                  abs(
                  final double a){
        
//#line 21
return ((((double)(a))) <= (((double)(0.0))))
          ? ((((double)(0.0))) - (((double)(a))))
          : a;
    }
    
    
//#line 22
public static int
                  abs(
                  final int a){
        
//#line 22
return ((((int)(a))) < (((int)(0))))
          ? (-(((int)(a))))
          : a;
    }
    
    
//#line 24
public static float
                  abs(
                  final float a){
        
//#line 25
return ((((float)(a))) <= (((float)(0.0F))))
          ? ((((float)(0.0F))) - (((float)(a))))
          : a;
    }
    
    
//#line 27
public static long
                  abs(
                  final long a){
        
//#line 27
return ((((long)(a))) < (((long)(0L))))
          ? (-(((long)(a))))
          : a;
    }
    
    
//#line 29
native public static double
                  ceil(
                  final double a);
    
    
//#line 33
native public static double
                  floor(
                  final double a);
    
    
//#line 37
native public static double
                  round(
                  final double a);
    
    
//#line 41
native public static double
                  pow(
                  final double a,
                  final double b);
    
    
//#line 52
public static x10.
                  lang.
                  Complex
                  pow(
                  final x10.
                    lang.
                    Complex a,
                  final x10.
                    lang.
                    Complex b){
        
//#line 52
return x10.
          lang.
          Math.exp(((x10.
                     lang.
                     Complex)(x10.
                     lang.
                     Math.log(((x10.
                                lang.
                                Complex)(a))).$times(((x10.
                                                       lang.
                                                       Complex)(b))))));
    }
    
    
//#line 54
native public static double
                  exp(
                  final double a);
    
    
//#line 59
native public static float
                  exp(
                  final float a);
    
    
//#line 68
public static x10.
                  lang.
                  Complex
                  exp(
                  final x10.
                    lang.
                    Complex a){
        
//#line 69
if (a.isNaN()) {
            
//#line 70
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 72
final double expRe =
          java.lang.Math.exp(((double)(a.
                                         re)));
        
//#line 73
return new x10.
          lang.
          Complex(((((double)(expRe))) * (((double)(java.lang.Math.cos(((double)(a.
                                                                                   im))))))),
                  ((((double)(expRe))) * (((double)(java.lang.Math.sin(((double)(a.
                                                                                   im))))))));
    }
    
    
//#line 76
native public static double
                  expm1(
                  final double a);
    
    
//#line 80
native public static double
                  cos(
                  final double a);
    
    
//#line 88
public static x10.
                  lang.
                  Complex
                  cos(
                  final x10.
                    lang.
                    Complex z){
        
//#line 89
if (((double) z.
                                    im) ==
                        ((double) 0.0)) {
            
//#line 90
return new x10.
              lang.
              Complex(java.lang.Math.cos(((double)(z.
                                                     re))),
                      0.0);
        } else {
            
//#line 92
return new x10.
              lang.
              Complex(((((double)(java.lang.Math.cos(((double)(z.
                                                                 re)))))) * (((double)(java.lang.Math.cosh(((double)(z.
                                                                                                                       im))))))),
                      ((((double)(java.lang.Math.sin(((double)(z.
                                                                 re)))))) * (((double)(java.lang.Math.sinh(((double)((-(((double)((z.
                                                                                                                                     im)))))))))))));
        }
    }
    
    
//#line 96
native public static double
                  sin(
                  final double a);
    
    
//#line 104
public static x10.
                   lang.
                   Complex
                   sin(
                   final x10.
                     lang.
                     Complex z){
        
//#line 105
if (((double) z.
                                     im) ==
                         ((double) 0.0)) {
            
//#line 106
return new x10.
              lang.
              Complex(java.lang.Math.sin(((double)(z.
                                                     re))),
                      0.0);
        } else {
            
//#line 108
return new x10.
              lang.
              Complex(((((double)(java.lang.Math.sin(((double)(z.
                                                                 re)))))) * (((double)(java.lang.Math.cosh(((double)(z.
                                                                                                                       im))))))),
                      ((((double)(java.lang.Math.cos(((double)(z.
                                                                 re)))))) * (((double)(java.lang.Math.sinh(((double)(z.
                                                                                                                       im))))))));
        }
    }
    
    
//#line 112
native public static double
                   tan(
                   final double a);
    
    
//#line 120
public static x10.
                   lang.
                   Complex
                   tan(
                   final x10.
                     lang.
                     Complex z){
        
//#line 121
if (((double) z.
                                     im) ==
                         ((double) 0.0)) {
            
//#line 122
return new x10.
              lang.
              Complex(java.lang.Math.tan(((double)(z.
                                                     re))),
                      0.0);
        } else {
            
//#line 125
final x10.
              lang.
              Complex e2IZ =
              x10.
              lang.
              Math.exp(((x10.
                         lang.
                         Complex)(x10.
                         lang.
                         Complex.$times((double)(2.0),
                                        ((x10.
                                          lang.
                                          Complex)(x10.
                                          lang.
                                          Complex.I))).$times(((x10.
                                                                lang.
                                                                Complex)(z))))));
            
//#line 126
return (e2IZ.$minus((double)(1.0))).$over(((x10.
                                                                     lang.
                                                                     Complex)((x10.
                                                                                 lang.
                                                                                 Complex.I.$times(((x10.
                                                                                                    lang.
                                                                                                    Complex)((e2IZ.$plus((double)(1.0))))))))));
        }
    }
    
    
//#line 130
native public static double
                   acos(
                   final double a);
    
    
//#line 141
public static x10.
                   lang.
                   Complex
                   acos(
                   final x10.
                     lang.
                     Complex z){
        
//#line 142
if (((double) z.
                                     im) ==
                         ((double) 0.0) &&
                         ((((double)(x10.
                           lang.
                           Math.abs((double)(z.
                                               re))))) <= (((double)(1.0))))) {
            
//#line 143
return new x10.
              lang.
              Complex(java.lang.Math.acos(((double)(z.
                                                      re))),
                      0.0);
        } else {
            
//#line 146
return x10.
              lang.
              Complex.$plus((double)(((((double)(x10.
                              lang.
                              Math.PI))) / (((double)(2.0))))),
                            ((x10.
                              lang.
                              Complex)(x10.
                              lang.
                              Complex.I.$times(((x10.
                                                 lang.
                                                 Complex)(x10.
                                                 lang.
                                                 Math.log(((x10.
                                                            lang.
                                                            Complex)(x10.
                                                            lang.
                                                            Complex.I.$times(((x10.
                                                                               lang.
                                                                               Complex)(z))).$plus(((x10.
                                                                                                     lang.
                                                                                                     Complex)(x10.
                                                                                                     lang.
                                                                                                     Math.sqrt(((x10.
                                                                                                                 lang.
                                                                                                                 Complex)(x10.
                                                                                                                 lang.
                                                                                                                 Complex.$minus((double)(1.0),
                                                                                                                                ((x10.
                                                                                                                                  lang.
                                                                                                                                  Complex)(z.$times(((x10.
                                                                                                                                                      lang.
                                                                                                                                                      Complex)(z)))))))))))))))))))));
        }
    }
    
    
//#line 150
native public static double
                   asin(
                   final double a);
    
    
//#line 161
public static x10.
                   lang.
                   Complex
                   asin(
                   final x10.
                     lang.
                     Complex z){
        
//#line 162
if (((double) z.
                                     im) ==
                         ((double) 0.0) &&
                         ((((double)(x10.
                           lang.
                           Math.abs((double)(z.
                                               re))))) <= (((double)(1.0))))) {
            
//#line 163
return new x10.
              lang.
              Complex(java.lang.Math.asin(((double)(z.
                                                      re))),
                      0.0);
        } else {
            
//#line 166
return x10.
              lang.
              Complex.I.$minus().$times(((x10.
                                          lang.
                                          Complex)(x10.
                                          lang.
                                          Math.log(((x10.
                                                     lang.
                                                     Complex)(x10.
                                                     lang.
                                                     Complex.I.$times(((x10.
                                                                        lang.
                                                                        Complex)(z))).$plus(((x10.
                                                                                              lang.
                                                                                              Complex)(x10.
                                                                                              lang.
                                                                                              Math.sqrt(((x10.
                                                                                                          lang.
                                                                                                          Complex)(x10.
                                                                                                          lang.
                                                                                                          Complex.$minus((double)(1.0),
                                                                                                                         ((x10.
                                                                                                                           lang.
                                                                                                                           Complex)(z.$times(((x10.
                                                                                                                                               lang.
                                                                                                                                               Complex)(z))))))))))))))))));
        }
    }
    
    
//#line 170
native public static double
                   atan(
                   final double a);
    
    
//#line 181
public static x10.
                   lang.
                   Complex
                   atan(
                   final x10.
                     lang.
                     Complex z){
        
//#line 182
if (((double) z.
                                     im) ==
                         ((double) 0.0)) {
            
//#line 183
return new x10.
              lang.
              Complex(java.lang.Math.atan(((double)(z.
                                                      re))),
                      0.0);
        } else {
            
//#line 184
if (x10.rtt.Equality.equalsequals(z,x10.
                               lang.
                               Complex.I)) {
                
//#line 185
return new x10.
                  lang.
                  Complex(0.0,
                          java.lang.Double.POSITIVE_INFINITY);
            } else {
                
//#line 186
if (x10.rtt.Equality.equalsequals(z,x10.
                                   lang.
                                   Complex.I.$minus())) {
                    
//#line 187
return new x10.
                      lang.
                      Complex(0.0,
                              java.lang.Double.NEGATIVE_INFINITY);
                } else {
                    
//#line 190
return x10.
                      lang.
                      Complex.I.$over((double)(2.0)).$times(((x10.
                                                              lang.
                                                              Complex)((x10.
                                                                          lang.
                                                                          Math.log(((x10.
                                                                                     lang.
                                                                                     Complex)(x10.
                                                                                     lang.
                                                                                     Complex.$minus((double)(1.0),
                                                                                                    ((x10.
                                                                                                      lang.
                                                                                                      Complex)(x10.
                                                                                                      lang.
                                                                                                      Complex.I.$times(((x10.
                                                                                                                         lang.
                                                                                                                         Complex)(z))))))))).$minus(((x10.
                                                                                                                                                      lang.
                                                                                                                                                      Complex)(x10.
                                                                                                                                                      lang.
                                                                                                                                                      Math.log(((x10.
                                                                                                                                                                 lang.
                                                                                                                                                                 Complex)(x10.
                                                                                                                                                                 lang.
                                                                                                                                                                 Complex.$plus((double)(1.0),
                                                                                                                                                                               ((x10.
                                                                                                                                                                                 lang.
                                                                                                                                                                                 Complex)(x10.
                                                                                                                                                                                 lang.
                                                                                                                                                                                 Complex.I.$times(((x10.
                                                                                                                                                                                                    lang.
                                                                                                                                                                                                    Complex)(z))))))))))))))));
                }
            }
        }
    }
    
    
//#line 194
native public static double
                   atan2(
                   final double a,
                   final double b);
    
    
//#line 198
native public static double
                   cosh(
                   final double a);
    
    
//#line 206
public static x10.
                   lang.
                   Complex
                   cosh(
                   final x10.
                     lang.
                     Complex z){
        
//#line 207
if (z.isNaN()) {
            
//#line 208
return x10.
              lang.
              Complex.NaN;
        } else {
            
//#line 209
if (((double) z.
                                         im) ==
                             ((double) 0.0)) {
                
//#line 210
return new x10.
                  lang.
                  Complex(java.lang.Math.cosh(((double)(z.
                                                          re))),
                          0.0);
            } else {
                
//#line 212
return new x10.
                  lang.
                  Complex(((((double)(java.lang.Math.cosh(((double)(z.
                                                                      re)))))) * (((double)(java.lang.Math.cos(((double)(z.
                                                                                                                           im))))))),
                          ((((double)(java.lang.Math.sinh(((double)(z.
                                                                      re)))))) * (((double)(java.lang.Math.sin(((double)(z.
                                                                                                                           im))))))));
            }
        }
    }
    
    
//#line 216
native public static double
                   sinh(
                   final double a);
    
    
//#line 224
public static x10.
                   lang.
                   Complex
                   sinh(
                   final x10.
                     lang.
                     Complex z){
        
//#line 225
if (z.isNaN()) {
            
//#line 226
return x10.
              lang.
              Complex.NaN;
        } else {
            
//#line 227
if (((double) z.
                                         im) ==
                             ((double) 0.0)) {
                
//#line 228
return new x10.
                  lang.
                  Complex(java.lang.Math.sinh(((double)(z.
                                                          re))),
                          0.0);
            } else {
                
//#line 230
return new x10.
                  lang.
                  Complex(((((double)(java.lang.Math.sinh(((double)(z.
                                                                      re)))))) * (((double)(java.lang.Math.cos(((double)(z.
                                                                                                                           im))))))),
                          ((((double)(java.lang.Math.cosh(((double)(z.
                                                                      re)))))) * (((double)(java.lang.Math.sin(((double)(z.
                                                                                                                           im))))))));
            }
        }
    }
    
    
//#line 234
native public static double
                   tanh(
                   final double a);
    
    
//#line 242
public static x10.
                   lang.
                   Complex
                   tanh(
                   final x10.
                     lang.
                     Complex z){
        
//#line 243
if (z.isNaN()) {
            
//#line 244
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 246
final double d =
          ((((double)(java.lang.Math.cosh(((double)(((((double)(2.0))) * (((double)(z.
                                                                                      re)))))))))) + (((double)(java.lang.Math.cos(((double)(((((double)(2.0))) * (((double)(z.
                                                                                                                                                                               im)))))))))));
        
//#line 247
return new x10.
          lang.
          Complex(((((double)(java.lang.Math.sinh(((double)(((((double)(2.0))) * (((double)(z.
                                                                                              re)))))))))) / (((double)(d)))),
                  ((((double)(java.lang.Math.sin(((double)(((((double)(2.0))) * (((double)(z.
                                                                                             im)))))))))) / (((double)(d)))));
    }
    
    
//#line 250
native public static double
                   sqrt(
                   final double a);
    
    
//#line 260
public static x10.
                   lang.
                   Complex
                   sqrt(
                   final x10.
                     lang.
                     Complex z){
        
//#line 261
if (z.isNaN()) {
            
//#line 262
return x10.
              lang.
              Complex.NaN;
        } else {
            
//#line 263
if (x10.rtt.Equality.equalsequals(z,x10.
                               lang.
                               Complex.ZERO)) {
                
//#line 264
return x10.
                  lang.
                  Complex.ZERO;
            } else {
                
//#line 266
final double t =
                  java.lang.Math.sqrt(((double)(((((double)((((((double)(x10.
                                                               lang.
                                                               Math.abs((double)(z.
                                                                                   re))))) + (((double)(z.abs())))))))) / (((double)(2.0)))))));
                
//#line 267
if (((((double)(z.
                                               re))) >= (((double)(0.0))))) {
                    
//#line 268
return new x10.
                      lang.
                      Complex(t,
                              ((((double)(z.
                                            im))) / (((double)((((((double)(2.0))) * (((double)(t))))))))));
                } else {
                    
//#line 270
return new x10.
                      lang.
                      Complex(((((double)(x10.
                                lang.
                                Math.abs((double)(z.
                                                    im))))) / (((double)((((((double)(2.0))) * (((double)(t))))))))),
                              java.lang.Math.signum(((double)(t))) == java.lang.Math.signum(((double)(z.
                                                                                                        im))) ? ((double)(t)) : -1 * ((double)(t)));
                }
            }
        }
    }
    
    
//#line 276
native public static float
                   sqrt(
                   final float a);
    
    
//#line 281
native public static double
                   cbrt(
                   final double a);
    
    
//#line 286
native public static double
                   erf(
                   final double a);
    
    
//#line 291
native public static double
                   erfc(
                   final double a);
    
    
//#line 295
native public static double
                   hypot(
                   final double a,
                   final double b);
    
    
//#line 299
native public static double
                   log(
                   final double a);
    
    
//#line 304
native public static float
                   log(
                   final float a);
    
    
//#line 315
public static x10.
                   lang.
                   Complex
                   log(
                   final x10.
                     lang.
                     Complex a){
        
//#line 316
if (a.isNaN()) {
            
//#line 317
return x10.
              lang.
              Complex.NaN;
        }
        
//#line 319
return new x10.
          lang.
          Complex(java.lang.Math.log(((double)(a.abs()))),
                  java.lang.Math.atan2(((double)(a.
                                                   im)),((double)(a.
                                                                    re))));
    }
    
    
//#line 322
native public static double
                   log10(
                   final double a);
    
    
//#line 326
native public static double
                   log1p(
                   final double a);
    
    
//#line 331
public static int
                   max(
                   final int a,
                   final int b){
        
//#line 331
return ((((int)(a))) < (((int)(b))))
          ? b
          : a;
    }
    
    
//#line 332
public static int
                   min(
                   final int a,
                   final int b){
        
//#line 332
return ((((int)(a))) < (((int)(b))))
          ? a
          : b;
    }
    
    
//#line 335
public static long
                   max(
                   final long a,
                   final long b){
        
//#line 335
return ((((long)(a))) < (((long)(b))))
          ? b
          : a;
    }
    
    
//#line 336
public static long
                   min(
                   final long a,
                   final long b){
        
//#line 336
return ((((long)(a))) < (((long)(b))))
          ? a
          : b;
    }
    
    
//#line 339
public static float
                   max(
                   final float a,
                   final float b){
        
//#line 339
return ((((float)(a))) < (((float)(b))))
          ? b
          : a;
    }
    
    
//#line 340
public static float
                   min(
                   final float a,
                   final float b){
        
//#line 340
return ((((float)(a))) < (((float)(b))))
          ? a
          : b;
    }
    
    
//#line 341
public static double
                   max(
                   final double a,
                   final double b){
        
//#line 341
return ((((double)(a))) < (((double)(b))))
          ? b
          : a;
    }
    
    
//#line 342
public static double
                   min(
                   final double a,
                   final double b){
        
//#line 342
return ((((double)(a))) < (((double)(b))))
          ? a
          : b;
    }
    
    
//#line 347
native public static double
                   copySign(
                   final double a,
                   final double b);
    
    
//#line 351
public static int
                   nextPowerOf2(
                   final int p){
        
//#line 352
if (((int) p) ==
                         ((int) 0)) {
            
//#line 352
return 0;
        }
        
//#line 353
int pow2 =
          1;
        
//#line 354
while (((((int)(pow2))) < (((int)(p)))))
            
//#line 355
pow2 = ((((int)(pow2))) << (((int)(1))));
        
//#line 356
return pow2;
    }
    
    
//#line 359
public static boolean
                   powerOf2(
                   final int p){
        
//#line 360
return ((int) ((((((int)(p))) & (((int)((-(((int)(p))))))))))) ==
        ((int) p);
    }
    
    
//#line 362
public static int
                   log2(
                   int p){
        
//#line 363
assert x10.
          lang.
          Math.powerOf2((int)(p));
        
//#line 364
int i =
          0;
        
//#line 365
while (((((int)(p))) > (((int)(1))))) {
            
//#line 365
p = ((((int)(p))) / (((int)(2))));
            
//#line 365
i = ((((int)(i))) + (((int)(1))));
        }
        
//#line 366
return i;
    }
    
    
//#line 369
public static int
                   pow2(
                   final int i){
        
//#line 370
return ((((int)(1))) << (((int)(i))));
    }
    
    
//#line 17
public Math() {
        
//#line 17
super();
    }

}
