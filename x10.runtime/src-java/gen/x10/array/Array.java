package x10.array;


final public class Array<T>
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<x10.
               array.
               Point,T>,
             x10.core.Iterable<x10.
               array.
               Point >
{public static final x10.rtt.RuntimeType<Array> _RTT = new x10.rtt.RuntimeType<Array>(
/* base class */Array.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.array.Point._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 58
final public x10.
      array.
      Region
      region;
    
//#line 64
final public int
      size;
    
//#line 70
final public boolean
      rail;
    
    
    
//#line 81
final public int
                  rank(
                  ){
        
//#line 81
return region.
                             rank;
    }
    
    
//#line 86
final public boolean
                  rect(
                  ){
        
//#line 86
return region.
                             rect;
    }
    
    
//#line 91
final public boolean
                  zeroBased(
                  ){
        
//#line 91
return region.
                             zeroBased;
    }
    
    
//#line 93
final public x10.core.IndexedMemoryChunk<T>
      raw;
    
//#line 94
final public int
      rawLength;
    
//#line 95
final public x10.
      array.
      RectLayout
      layout;
    
    
//#line 97
native private boolean
                  checkBounds(
                  );
    
    public static <T> boolean
      checkBounds$P(
      final x10.rtt.Type T,
      final x10.
        array.
        Array<T> Array){
        return (!false);
    }
    
    
//#line 117
public x10.core.IndexedMemoryChunk<T>
                   raw(
                   ){
        
//#line 117
return raw;
    }
    
    
//#line 127
public Array(final x10.rtt.Type T,
                              final x10.
                                array.
                                Region reg) {
                                                     super();
                                                 this.T = T;
                                                  {
                                                     
//#line 128
this.region = ((x10.
                                                       array.
                                                       Region)(reg));
                                                     
//#line 128
this.size = reg.size();
                                                     
//#line 128
this.rail = reg.rail();
                                                     
//#line 130
this.layout = new x10.
                                                       array.
                                                       RectLayout(reg.min(),
                                                                  reg.max());
                                                     
//#line 131
final int n =
                                                       layout.size();
                                                     
//#line 132
this.raw = x10.core.IndexedMemoryChunk.<T>allocate(T, ((int)(n)));
                                                     
//#line 133
this.rawLength = n;
                                                 }}
    
    
//#line 144
public Array(final x10.rtt.Type T,
                              final x10.
                                array.
                                Region reg,
                              final x10.core.fun.Fun_0_1<x10.
                                array.
                                Point,T> init) {
                                                        super();
                                                    this.T = T;
                                                     {
                                                        
//#line 145
this.region = ((x10.
                                                          array.
                                                          Region)(reg));
                                                        
//#line 145
this.size = reg.size();
                                                        
//#line 145
this.rail = reg.rail();
                                                        
//#line 147
this.layout = new x10.
                                                          array.
                                                          RectLayout(reg.min(),
                                                                     reg.max());
                                                        
//#line 148
final int n =
                                                          layout.size();
                                                        
//#line 149
final x10.core.IndexedMemoryChunk<T> r =
                                                          x10.core.IndexedMemoryChunk.<T>allocate(T, ((int)(n)));
                                                        
//#line 150
for (
//#line 150
final x10.core.Iterator<x10.
                                                                            array.
                                                                            Point> p1277 =
                                                                            reg.iterator();
                                                                          p1277.hasNext();
                                                                          ) {
                                                            
//#line 150
final x10.
                                                              array.
                                                              Point p =
                                                              ((x10.
                                                              array.
                                                              Point)(p1277.next$G()));
                                                            
//#line 151
(r).set(init.apply$G(p), ((int)(layout.offset(((x10.
                                                                                                                         array.
                                                                                                                         Point)(p))))));
                                                        }
                                                        
//#line 153
this.raw = r;
                                                        
//#line 154
this.rawLength = n;
                                                    }}
    
    
//#line 165
public Array(final x10.rtt.Type T,
                              final x10.
                                array.
                                Region reg,
                              final T init) {
                                                     super();
                                                 this.T = T;
                                                  {
                                                     
//#line 166
this.region = ((x10.
                                                       array.
                                                       Region)(reg));
                                                     
//#line 166
this.size = reg.size();
                                                     
//#line 166
this.rail = reg.rail();
                                                     
//#line 168
this.layout = new x10.
                                                       array.
                                                       RectLayout(reg.min(),
                                                                  reg.max());
                                                     
//#line 169
final int n =
                                                       layout.size();
                                                     
//#line 170
final x10.core.IndexedMemoryChunk<T> r =
                                                       x10.core.IndexedMemoryChunk.<T>allocate(T, ((int)(n)));
                                                     
//#line 171
if (reg.
                                                                        rect) {
                                                         
//#line 174
for (
//#line 174
int i =
                                                                             0;
                                                                           ((((int)(i))) < (((int)(n))));
                                                                           
//#line 174
i = ((((int)(i))) + (((int)(1))))) {
                                                             
//#line 175
(r).set(init, ((int)(i)));
                                                         }
                                                     } else {
                                                         
//#line 178
for (
//#line 178
final x10.core.Iterator<x10.
                                                                             array.
                                                                             Point> p1278 =
                                                                             reg.iterator();
                                                                           p1278.hasNext();
                                                                           ) {
                                                             
//#line 178
final x10.
                                                               array.
                                                               Point p =
                                                               ((x10.
                                                               array.
                                                               Point)(p1278.next$G()));
                                                             
//#line 179
(r).set(init, ((int)(layout.offset(((x10.
                                                                                                               array.
                                                                                                               Point)(p))))));
                                                         }
                                                     }
                                                     
//#line 182
this.raw = r;
                                                     
//#line 183
this.rawLength = n;
                                                 }}
    
    
//#line 193
public Array(final x10.rtt.Type T,
                              final x10.core.Rail<T> aRail) {
                                                                     
//#line 194
this(T,
                                                                                       x10.
                                                                                         array.
                                                                                         Region.makeRectangular((int)(0),
                                                                                                                (int)(((((int)(aRail.
                                                                                                                                 length))) - (((int)(1)))))),
                                                                                       new x10.core.fun.Fun_0_1<x10.
                                                                                         array.
                                                                                         Point, T>() {public final T apply$G(final x10.
                                                                                         array.
                                                                                         Point id2) { {
                                                                                           
//#line 194
final int i =
                                                                                             id2.apply((int)(0));
                                                                                           
//#line 194
return (aRail).apply$G(((int)(i)));
                                                                                       }}
                                                                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                                                       }
                                                                                       });
                                                                  {
                                                                     
                                                                 }}
    
    
//#line 208
public Array(final x10.rtt.Type T,
                              final x10.core.ValRail<T> aRail) {
                                                                        
//#line 209
this(T,
                                                                                          x10.
                                                                                            array.
                                                                                            Region.makeRectangular((int)(0),
                                                                                                                   (int)(((((int)(aRail.
                                                                                                                                    length))) - (((int)(1)))))),
                                                                                          new x10.core.fun.Fun_0_1<x10.
                                                                                            array.
                                                                                            Point, T>() {public final T apply$G(final x10.
                                                                                            array.
                                                                                            Point id3) { {
                                                                                              
//#line 209
final int i =
                                                                                                id3.apply((int)(0));
                                                                                              
//#line 209
return (aRail).apply$G(((int)(i)));
                                                                                          }}
                                                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                                                          }
                                                                                          });
                                                                     {
                                                                        
                                                                    }}
    
    
//#line 218
public Array(final x10.rtt.Type T,
                              final int size) {
                                                       
//#line 219
this(T,
                                                                         x10.
                                                                           array.
                                                                           Region.makeRectangular((int)(0),
                                                                                                  (int)(((((int)(size))) - (((int)(1)))))));
                                                    {
                                                       
                                                   }}
    
    
//#line 230
public Array(final x10.rtt.Type T,
                              final int size,
                              final x10.core.fun.Fun_0_1<x10.
                                array.
                                Point,T> init) {
                                                        
//#line 231
this(T,
                                                                          x10.
                                                                            array.
                                                                            Region.makeRectangular((int)(0),
                                                                                                   (int)(((((int)(size))) - (((int)(1)))))),
                                                                          init);
                                                     {
                                                        
                                                    }}
    
    
//#line 242
public Array(final x10.rtt.Type T,
                              final int size,
                              final T init) {
                                                     
//#line 243
this(T,
                                                                       x10.
                                                                         array.
                                                                         Region.makeRectangular((int)(0),
                                                                                                (int)(((((int)(size))) - (((int)(1)))))),
                                                                       init);
                                                  {
                                                     
                                                 }}
    
    
//#line 254
public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   ){
        
//#line 254
return ((x10.core.Iterator)
                              region.iterator());
    }
    
    
//#line 266
public T
                   apply$G(
                   final int i0){
        
//#line 267
if (rail) {
            
//#line 268
if ((!false) &&
                             (!(((boolean)((x10.
                                              lang.
                                              UInt.$lt((x10.
                                                         lang.
                                                         UInt)((x10.
                                                                  lang.
                                                                  UInt.$implicit_convert((int)(i0)))),
                                                       (x10.
                                                         lang.
                                                         UInt)((x10.
                                                                  lang.
                                                                  UInt.$implicit_convert((int)(size))))))))))) {
                
//#line 269
x10.
                  array.
                  Array.raiseBoundsError((int)(i0));
            }
            
//#line 271
return (raw).apply$G(((int)(i0)));
        } else {
            
//#line 273
if ((!false) &&
                             (!(((boolean)(region.contains((int)(i0))))))) {
                
//#line 274
x10.
                  array.
                  Array.raiseBoundsError((int)(i0));
            }
            
//#line 276
return (raw).apply$G(((int)(layout.offset((int)(i0)))));
        }
    }
    
    
//#line 291
public T
                   apply$G(
                   final int i0,
                   final int i1){
        
//#line 292
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1))))))) {
            
//#line 293
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1));
        }
        
//#line 295
return (raw).apply$G(((int)(layout.offset((int)(i0),
                                                               (int)(i1)))));
    }
    
    
//#line 310
public T
                   apply$G(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 311
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2))))))) {
            
//#line 312
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1),
                                     (int)(i2));
        }
        
//#line 314
return (raw).apply$G(((int)(layout.offset((int)(i0),
                                                               (int)(i1),
                                                               (int)(i2)))));
    }
    
    
//#line 330
public T
                   apply$G(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 331
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2),
                                                       (int)(i3))))))) {
            
//#line 332
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1),
                                     (int)(i2),
                                     (int)(i3));
        }
        
//#line 334
return (raw).apply$G(((int)(layout.offset((int)(i0),
                                                               (int)(i1),
                                                               (int)(i2),
                                                               (int)(i3)))));
    }
    
    
//#line 346
public T
                   apply$G(
                   final x10.
                     array.
                     Point pt){
        
//#line 347
if ((!false) &&
                         (!(((boolean)(region.contains(((x10.
                                                         array.
                                                         Point)(pt)))))))) {
            
//#line 348
x10.
              array.
              Array.raiseBoundsError(((x10.
                                       array.
                                       Point)(pt)));
        }
        
//#line 350
return (raw).apply$G(((int)(layout.offset(((x10.
                                                                 array.
                                                                 Point)(pt))))));
    }
    
    
//#line 366
public T
                   set$G(
                   final T v,
                   final int i0){
        
//#line 367
if (rail) {
            
//#line 368
if ((!false) &&
                             (!(((boolean)((x10.
                                              lang.
                                              UInt.$lt((x10.
                                                         lang.
                                                         UInt)((x10.
                                                                  lang.
                                                                  UInt.$implicit_convert((int)(i0)))),
                                                       (x10.
                                                         lang.
                                                         UInt)((x10.
                                                                  lang.
                                                                  UInt.$implicit_convert((int)(size))))))))))) {
                
//#line 369
x10.
                  array.
                  Array.raiseBoundsError((int)(i0));
            }
            
//#line 371
(raw).set(v, ((int)(i0)));
        } else {
            
//#line 373
if ((!false) &&
                             (!(((boolean)(region.contains((int)(i0))))))) {
                
//#line 374
x10.
                  array.
                  Array.raiseBoundsError((int)(i0));
            }
            
//#line 376
(raw).set(v, ((int)(layout.offset((int)(i0)))));
        }
        
//#line 378
return v;
    }
    
    
//#line 394
public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1){
        
//#line 395
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1))))))) {
            
//#line 396
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1));
        }
        
//#line 398
(raw).set(v, ((int)(layout.offset((int)(i0),
                                                       (int)(i1)))));
        
//#line 399
return v;
    }
    
    
//#line 416
public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 417
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2))))))) {
            
//#line 418
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1),
                                     (int)(i2));
        }
        
//#line 420
(raw).set(v, ((int)(layout.offset((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2)))));
        
//#line 421
return v;
    }
    
    
//#line 439
public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 440
if ((!false) &&
                         (!(((boolean)(region.contains((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2),
                                                       (int)(i3))))))) {
            
//#line 441
x10.
              array.
              Array.raiseBoundsError((int)(i0),
                                     (int)(i1),
                                     (int)(i2),
                                     (int)(i3));
        }
        
//#line 443
(raw).set(v, ((int)(layout.offset((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2),
                                                       (int)(i3)))));
        
//#line 444
return v;
    }
    
    
//#line 458
public T
                   set$G(
                   final T v,
                   final x10.
                     array.
                     Point p){
        
//#line 459
if ((!false) &&
                         (!(((boolean)(region.contains(((x10.
                                                         array.
                                                         Point)(p)))))))) {
            
//#line 460
x10.
              array.
              Array.raiseBoundsError(((x10.
                                       array.
                                       Point)(p)));
        }
        
//#line 462
(raw).set(v, ((int)(layout.offset(((x10.
                                                         array.
                                                         Point)(p))))));
        
//#line 463
return v;
    }
    
    
//#line 472
public void
                   fill(
                   final T v){
        
//#line 473
if (region.
                           rect) {
            
//#line 477
for (
//#line 477
int i =
                                0;
                              ((((int)(i))) < (((int)(rawLength))));
                              
//#line 477
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 478
(raw).set(v, ((int)(i)));
            }
        } else {
            
//#line 481
for (
//#line 481
final x10.core.Iterator<x10.
                                array.
                                Point> p1279 =
                                region.iterator();
                              p1279.hasNext();
                              ) {
                
//#line 481
final x10.
                  array.
                  Point p =
                  ((x10.
                  array.
                  Point)(p1279.next$G()));
                
//#line 482
(raw).set(v, ((int)(layout.offset(((x10.
                                                                 array.
                                                                 Point)(p))))));
            }
        }
    }
    
    
//#line 500
public <U> x10.
                   array.
                   Array<U>
                   map(
                   final x10.rtt.Type U,
                   final x10.core.fun.Fun_0_1<T,U> op){
        
//#line 501
return new x10.
          array.
          Array<U>(U,
                   region,
                   new x10.core.fun.Fun_0_1<x10.
                     array.
                     Point, U>() {public final U apply$G(final x10.
                     array.
                     Point p) { {
                       
//#line 501
return op.apply$G(x10.
                                                        array.
                                                        Array.this.apply$G(((x10.
                                                                             array.
                                                                             Point)(p))));
                   }}
                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return U;return null;
                   }
                   });
    }
    
    
//#line 518
public <U> x10.
                   array.
                   Array<U>
                   map(
                   final x10.rtt.Type U,
                   final x10.
                     array.
                     Array<U> dst,
                   final x10.core.fun.Fun_0_1<T,U> op){
        
//#line 520
if (region.
                           rect) {
            
//#line 524
for (
//#line 524
int i =
                                0;
                              ((((int)(i))) < (((int)(rawLength))));
                              
//#line 524
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 525
(dst.
                                raw).set(op.apply$G((raw).apply$G(((int)(i)))), ((int)(i)));
            }
        } else {
            
//#line 528
for (
//#line 528
final x10.core.Iterator<x10.
                                array.
                                Point> p1280 =
                                region.iterator();
                              p1280.hasNext();
                              ) {
                
//#line 528
final x10.
                  array.
                  Point p =
                  ((x10.
                  array.
                  Point)(p1280.next$G()));
                
//#line 529
dst.set$G(((U)(op.apply$G(this.apply$G(((x10.
                                                                      array.
                                                                      Point)(p)))))),
                                       ((x10.
                                         array.
                                         Point)(p)));
            }
        }
        
//#line 532
return dst;
    }
    
    
//#line 548
public <S, U> x10.
                   array.
                   Array<S>
                   map(
                   final x10.rtt.Type S,
                   final x10.rtt.Type U,
                   final x10.
                     array.
                     Array<U> src,
                   final x10.core.fun.Fun_0_2<T,U,S> op){
        
//#line 549
return new x10.
          array.
          Array<S>(S,
                   region,
                   new x10.core.fun.Fun_0_1<x10.
                     array.
                     Point, S>() {public final S apply$G(final x10.
                     array.
                     Point p) { {
                       
//#line 549
return op.apply$G(x10.
                                                        array.
                                                        Array.this.apply$G(((x10.
                                                                             array.
                                                                             Point)(p))),
                                                      src.apply$G(((x10.
                                                                    array.
                                                                    Point)(p))));
                   }}
                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return S;return null;
                   }
                   });
    }
    
    
//#line 566
public <S, U> x10.
                   array.
                   Array<S>
                   map(
                   final x10.rtt.Type S,
                   final x10.rtt.Type U,
                   final x10.
                     array.
                     Array<S> dst,
                   final x10.
                     array.
                     Array<U> src,
                   final x10.core.fun.Fun_0_2<T,U,S> op){
        
//#line 568
if (region.
                           rect) {
            
//#line 572
for (
//#line 572
int i =
                                0;
                              ((((int)(i))) < (((int)(rawLength))));
                              
//#line 572
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 573
(dst.
                                raw).set(op.apply$G((raw).apply$G(((int)(i))),
                                                    (src.
                                                       raw).apply$G(((int)(i)))), ((int)(i)));
            }
        } else {
            
//#line 576
for (
//#line 576
final x10.core.Iterator<x10.
                                array.
                                Point> p1281 =
                                region.iterator();
                              p1281.hasNext();
                              ) {
                
//#line 576
final x10.
                  array.
                  Point p =
                  ((x10.
                  array.
                  Point)(p1281.next$G()));
                
//#line 577
dst.set$G(((S)(op.apply$G(this.apply$G(((x10.
                                                                      array.
                                                                      Point)(p))),
                                                       src.apply$G(((x10.
                                                                     array.
                                                                     Point)(p)))))),
                                       ((x10.
                                         array.
                                         Point)(p)));
            }
        }
        
//#line 580
return dst;
    }
    
    
//#line 596
public <U> U
                   reduce$G(
                   final x10.rtt.Type U,
                   final x10.core.fun.Fun_0_2<U,T,U> op,
                   final U unit){
        
//#line 599
U accum =
          ((U)(unit));
        
//#line 600
if (region.
                           rect) {
            
//#line 604
for (
//#line 604
int i =
                                0;
                              ((((int)(i))) < (((int)(rawLength))));
                              
//#line 604
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 605
accum = ((U)(op.apply$G(accum,
                                                     (raw).apply$G(((int)(i))))));
            }
        } else {
            
//#line 608
for (
//#line 608
final x10.core.Iterator<x10.
                                array.
                                Point> p1282 =
                                region.iterator();
                              p1282.hasNext();
                              ) {
                
//#line 608
final x10.
                  array.
                  Point p =
                  ((x10.
                  array.
                  Point)(p1282.next$G()));
                
//#line 609
accum = ((U)(op.apply$G(accum,
                                                     this.apply$G(((x10.
                                                                    array.
                                                                    Point)(p))))));
            }
        }
        
//#line 612
return accum;
    }
    
    
//#line 629
public <U> x10.
                   array.
                   Array<U>
                   scan(
                   final x10.rtt.Type U,
                   final x10.core.fun.Fun_0_2<U,T,U> op,
                   final U unit){
        
//#line 629
return this.<U>scan(U,
                                         ((x10.
                                           array.
                                           Array)(new x10.
                                           array.
                                           Array<U>(U,
                                                    region))),
                                         ((x10.core.fun.Fun_0_2)(op)),
                                         ((U)(unit)));
    }
    
    
//#line 646
public <U> x10.
                   array.
                   Array<U>
                   scan(
                   final x10.rtt.Type U,
                   final x10.
                     array.
                     Array<U> dst,
                   final x10.core.fun.Fun_0_2<U,T,U> op,
                   final U unit){
        
//#line 647
U accum =
          ((U)(unit));
        
//#line 648
for (
//#line 648
final x10.core.Iterator<x10.
                            array.
                            Point> p1283 =
                            region.iterator();
                          p1283.hasNext();
                          ) {
            
//#line 648
final x10.
              array.
              Point p =
              ((x10.
              array.
              Point)(p1283.next$G()));
            
//#line 649
accum = ((U)(op.apply$G(accum,
                                                 this.apply$G(((x10.
                                                                array.
                                                                Point)(p))))));
            
//#line 650
dst.set$G(((U)(accum)),
                                   ((x10.
                                     array.
                                     Point)(p)));
        }
        
//#line 652
return dst;
    }
    
    
//#line 673
public void
                   copyTo(
                   final x10.
                     array.
                     Array<T> dst){
        
//#line 674
this.copyTo(((x10.
                                   array.
                                   Array)(dst)),
                                 (boolean)(false));
    }
    
    
//#line 697
public void
                   copyTo(
                   final x10.
                     array.
                     Array<T> dst,
                   final boolean uncounted){
        
//#line 698
if ((!false) &&
                         (!(((boolean)(region.equals(((java.lang.Object)(dst.
                                                                           region)))))))) {
            
//#line 698
throw new java.lang.IllegalArgumentException("source and destination Regions are not equal");
        }
        
//#line 699
x10.util.IndexedMemoryChunk__NativeRep.copyTo(T, raw,((int)(0)),x10.lang.Place.place(x10.core.Ref.home(dst)),dst.
                                                                                                                                    raw,((int)(0)),((int)(rawLength)),((boolean)(uncounted)));
    }
    
    
//#line 721
public void
                   copyTo(
                   final int srcIndex,
                   final x10.
                     array.
                     Array<T> dst,
                   final int dstIndex,
                   final int numElems){
        
//#line 722
this.copyTo((int)(srcIndex),
                                 ((x10.
                                   array.
                                   Array)(dst)),
                                 (int)(dstIndex),
                                 (int)(numElems),
                                 (boolean)(false));
    }
    
    
//#line 746
public void
                   copyTo(
                   final int srcIndex,
                   final x10.
                     array.
                     Array<T> dst,
                   final int dstIndex,
                   final int numElems,
                   final boolean uncounted){
        
//#line 747
if ((!false)) {
            
//#line 748
if ((!(((boolean)(region.contains((int)(srcIndex))))))) {
                
//#line 748
x10.
                  array.
                  Array.raiseBoundsError((int)(srcIndex));
            }
            
//#line 749
if ((!(((boolean)(region.contains((int)(((((int)(((((int)(srcIndex))) + (((int)(numElems))))))) - (((int)(1))))))))))) {
                
//#line 749
x10.
                  array.
                  Array.raiseBoundsError((int)(((((int)(((((int)(srcIndex))) + (((int)(numElems))))))) - (((int)(1))))));
            }
            
//#line 750
if ((!(((boolean)(dst.
                                             region.contains((int)(dstIndex))))))) {
                
//#line 750
x10.
                  array.
                  Array.raiseBoundsError((int)(dstIndex));
            }
            
//#line 751
if ((!(((boolean)(dst.
                                             region.contains((int)(((((int)(((((int)(dstIndex))) + (((int)(numElems))))))) - (((int)(1))))))))))) {
                
//#line 751
dst.raiseBoundsError((int)(((((int)(((((int)(dstIndex))) + (((int)(numElems))))))) - (((int)(1))))));
            }
        }
        
//#line 754
x10.util.IndexedMemoryChunk__NativeRep.copyTo(T, raw,((int)(((((int)(srcIndex))) - (((int)(((int[])region.min().value)[0])))))),x10.lang.Place.place(x10.core.Ref.home(dst)),dst.
                                                                                                                                                                                                    raw,((int)(((((int)(dstIndex))) - (((int)(((int[])dst.
                                                                                                                                                                                                                                                        region.min().value)[0])))))),((int)(numElems)),((boolean)(uncounted)));
    }
    
    
//#line 775
public void
                   copyFrom(
                   final x10.
                     array.
                     Array<T> src){
        
//#line 776
this.copyFrom(((x10.
                                     array.
                                     Array)(src)),
                                   (boolean)(false));
    }
    
    
//#line 798
public void
                   copyFrom(
                   final x10.
                     array.
                     Array<T> src,
                   final boolean uncounted){
        
//#line 799
if ((!false) &&
                         (!(((boolean)(region.equals(((java.lang.Object)(src.
                                                                           region)))))))) {
            
//#line 799
throw new java.lang.IllegalArgumentException("source and destination Regions are not equal");
        }
        
//#line 800
x10.util.IndexedMemoryChunk__NativeRep.copyFrom(T, raw,((int)(0)),x10.lang.Place.place(x10.core.Ref.home(src)),src.
                                                                                                                                      raw,((int)(0)),((int)(rawLength)),((boolean)(uncounted)));
    }
    
    
//#line 822
public void
                   copyFrom(
                   final int dstIndex,
                   final x10.
                     array.
                     Array<T> src,
                   final int srcIndex,
                   final int numElems){
        
//#line 823
this.copyFrom((int)(dstIndex),
                                   ((x10.
                                     array.
                                     Array)(src)),
                                   (int)(srcIndex),
                                   (int)(numElems),
                                   (boolean)(false));
    }
    
    
//#line 846
public void
                   copyFrom(
                   final int dstIndex,
                   final x10.
                     array.
                     Array<T> src,
                   final int srcIndex,
                   final int numElems,
                   final boolean uncounted){
        
//#line 847
if ((!false)) {
            
//#line 848
if ((!(((boolean)(src.
                                             region.contains((int)(srcIndex))))))) {
                
//#line 848
x10.
                  array.
                  Array.raiseBoundsError((int)(srcIndex));
            }
            
//#line 849
if ((!(((boolean)(src.
                                             region.contains((int)(((((int)(((((int)(srcIndex))) + (((int)(numElems))))))) - (((int)(1))))))))))) {
                
//#line 849
x10.
                  array.
                  Array.raiseBoundsError((int)(((((int)(((((int)(srcIndex))) + (((int)(numElems))))))) - (((int)(1))))));
            }
            
//#line 850
if ((!(((boolean)(region.contains((int)(dstIndex))))))) {
                
//#line 850
x10.
                  array.
                  Array.raiseBoundsError((int)(dstIndex));
            }
            
//#line 851
if ((!(((boolean)(region.contains((int)(((((int)(((((int)(dstIndex))) + (((int)(numElems))))))) - (((int)(1))))))))))) {
                
//#line 851
x10.
                  array.
                  Array.raiseBoundsError((int)(((((int)(((((int)(dstIndex))) + (((int)(numElems))))))) - (((int)(1))))));
            }
        }
        
//#line 854
x10.util.IndexedMemoryChunk__NativeRep.copyFrom(T, raw,((int)(((((int)(dstIndex))) - (((int)(((int[])region.min().value)[0])))))),x10.lang.Place.place(x10.core.Ref.home(src)),src.
                                                                                                                                                                                                      raw,((int)(((((int)(srcIndex))) - (((int)(((int[])src.
                                                                                                                                                                                                                                                          region.min().value)[0])))))),((int)(numElems)),((boolean)(uncounted)));
    }
    
    
//#line 857
private static void
                   raiseBoundsError(
                   final int i0){
        
//#line 858
throw new java.lang.ArrayIndexOutOfBoundsException((((("point (") + (((java.lang.Integer)(i0))))) + (") not contained in array")));
    }
    
    public static void
      raiseBoundsError$P(
      final int i0){
        Array.raiseBoundsError((int)(i0));
    }
    
    
//#line 860
private static void
                   raiseBoundsError(
                   final int i0,
                   final int i1){
        
//#line 861
throw new java.lang.ArrayIndexOutOfBoundsException((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (") not contained in array")));
    }
    
    public static void
      raiseBoundsError$P(
      final int i0,
      final int i1){
        Array.raiseBoundsError((int)(i0),
                               (int)(i1));
    }
    
    
//#line 863
private static void
                   raiseBoundsError(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 864
throw new java.lang.ArrayIndexOutOfBoundsException((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (") not contained in array")));
    }
    
    public static void
      raiseBoundsError$P(
      final int i0,
      final int i1,
      final int i2){
        Array.raiseBoundsError((int)(i0),
                               (int)(i1),
                               (int)(i2));
    }
    
    
//#line 866
private static void
                   raiseBoundsError(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 867
throw new java.lang.ArrayIndexOutOfBoundsException((((((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (", "))) + (((java.lang.Integer)(i3))))) + (") not contained in array")));
    }
    
    public static void
      raiseBoundsError$P(
      final int i0,
      final int i1,
      final int i2,
      final int i3){
        Array.raiseBoundsError((int)(i0),
                               (int)(i1),
                               (int)(i2),
                               (int)(i3));
    }
    
    
//#line 869
private static void
                   raiseBoundsError(
                   final x10.
                     array.
                     Point pt){
        
//#line 870
throw new java.lang.ArrayIndexOutOfBoundsException((((("point ") + (pt))) + (" not contained in array")));
    }
    
    public static void
      raiseBoundsError$P(
      final x10.
        array.
        Point pt){
        Array.raiseBoundsError(((x10.
                                 array.
                                 Point)(pt)));
    }
    
    
//#line 58
final public x10.
                  array.
                  Region
                  region(
                  ){
        
//#line 58
return this.
                             region;
    }
    
    
//#line 64
final public int
                  size(
                  ){
        
//#line 64
return this.
                             size;
    }
    
    
//#line 70
final public boolean
                  rail(
                  ){
        
//#line 70
return this.
                             rail;
    }

}
