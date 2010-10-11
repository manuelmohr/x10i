package x10.array;

abstract public class Region
extends x10.core.Ref
  implements x10.core.Iterable<x10.
               array.
               Point >
{public static final x10.rtt.RuntimeType<Region> _RTT = new x10.rtt.RuntimeType<Region>(
/* base class */Region.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 25
final public int
      rank;
    
//#line 26
final public boolean
      rect;
    
//#line 27
final public boolean
      zeroBased;
    
    
    
//#line 30
final public boolean
                  rail(
                  ){
        
//#line 30
return ((int) rank) ==
        ((int) 1) &&
        rect &&
        zeroBased;
    }
    
    
//#line 31
final public x10.
                  array.
                  Region
                  region(
                  ){
        
//#line 31
return this;
    }
    
    
//#line 41
public static x10.
                  array.
                  Region
                  makeEmpty(
                  final int rank){
        
//#line 41
return new x10.
          array.
          EmptyRegion(rank);
    }
    
    
//#line 48
public static x10.
                  array.
                  Region
                  makeFull(
                  final int rank){
        
//#line 48
return new x10.
          array.
          FullRegion(rank);
    }
    
    
//#line 54
public static x10.
                  array.
                  Region
                  makeUnit(
                  ){
        
//#line 54
return new x10.
          array.
          FullRegion(0);
    }
    
    
//#line 61
public static x10.
                  array.
                  Region
                  makeHalfspace(
                  final x10.
                    array.
                    Point normal,
                  final int k){
        
//#line 62
final int rank =
          normal.
            rank;
        
//#line 63
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(rank)));
        
//#line 64
final x10.
          array.
          PolyRow r =
          ((x10.
          array.
          PolyRow)(new x10.
          array.
          PolyRow(normal,
                  k)));
        
//#line 65
pmb.add(((x10.
                              array.
                              Row)(r)));
        
//#line 66
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(false))));
        
//#line 67
return new x10.core.fun.Fun_0_1<x10.
          array.
          Region, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final x10.
          array.
          Region __desugarer__var__32__) { return apply(__desugarer__var__32__);}
        public final x10.
          array.
          Region apply(final x10.
          array.
          Region __desugarer__var__32__) { {
            
//#line 67
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__32__,null)) &&
                              !(((int) __desugarer__var__32__.
                                         rank) ==
                                ((int) normal.
                                         rank))) {
                
//#line 67
throw new java.lang.ClassCastException("x10.array.Region{self.rank==normal.rank}");
            }
            
//#line 67
return __desugarer__var__32__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  Region)
                  x10.
                  array.
                  PolyRegion.make(((x10.
                                    array.
                                    PolyMat)(pm)))));
    }
    
    
//#line 79
public static x10.
                  array.
                  Region
                  makeRectangular(
                  final x10.core.Rail<java.lang.Integer> minArg,
                  final x10.core.Rail<java.lang.Integer> maxArg){
        
//#line 80
return x10.
          array.
          Region.makeRectangular(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, minArg))),
                                 ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, maxArg))));
    }
    
    
//#line 81
public static x10.
                  array.
                  Region
                  makeRectangular(
                  final x10.core.ValRail<java.lang.Integer> minArg,
                  final x10.core.ValRail<java.lang.Integer> maxArg){
        
//#line 82
return new x10.
          array.
          RectRegion(minArg,
                     maxArg);
    }
    
    
//#line 89
public static x10.
                  array.
                  Region
                  makeRectangular(
                  final int min,
                  final int max){
        
//#line 90
return new x10.
          array.
          RectRegion(min,
                     max);
    }
    
    
//#line 95
public static x10.
                  array.
                  Region
                  make(
                  final int min,
                  final int max){
        
//#line 95
return new x10.
          array.
          RectRegion(min,
                     max);
    }
    
    
//#line 101
public static x10.
                   array.
                   Region
                   make(
                   final x10.core.ValRail<x10.
                     array.
                     Region> regions){
        
//#line 102
x10.
          array.
          Region r =
          ((x10.
          array.
          Region)((x10.
          array.
          Region[])regions.value)[0]);
        {
            
//#line 103
final x10.
              array.
              Region[] regions$value2001 =
              ((x10.
              array.
              Region[])regions.value);
            
//#line 103
for (
//#line 103
int i =
                                1;
                              ((((int)(i))) < (((int)(regions.
                                                        length))));
                              
//#line 103
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 104
r = r.product(((x10.
                                             array.
                                             Region)(((x10.
                                             array.
                                             Region)regions$value2001[i]))));
            }
        }
        
//#line 105
return new x10.core.fun.Fun_0_1<x10.
          array.
          Region, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final x10.
          array.
          Region __desugarer__var__33__) { return apply(__desugarer__var__33__);}
        public final x10.
          array.
          Region apply(final x10.
          array.
          Region __desugarer__var__33__) { {
            
//#line 105
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__33__,null)) &&
                               !(((boolean) __desugarer__var__33__.
                                              rect) ==
                                 ((boolean) true) &&
                                 ((int) __desugarer__var__33__.
                                          rank) ==
                                 ((int) regions.
                                          length))) {
                
//#line 105
throw new java.lang.ClassCastException("x10.array.Region{self.rect==true, self.rank==regions.length}");
            }
            
//#line 105
return __desugarer__var__33__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  Region)
                  r));
    }
    
    
//#line 117
public static x10.
                   array.
                   Region
                   makeBanded(
                   final int size,
                   final int upper,
                   final int lower){
        
//#line 118
return x10.
          array.
          PolyRegion.makeBanded((int)(size),
                                (int)(upper),
                                (int)(lower));
    }
    
    
//#line 124
public static x10.
                   array.
                   Region
                   makeBanded(
                   final int size){
        
//#line 124
return x10.
          array.
          PolyRegion.makeBanded((int)(size),
                                (int)(1),
                                (int)(1));
    }
    
    
//#line 130
public static x10.
                   array.
                   Region
                   makeUpperTriangular(
                   final int size){
        
//#line 130
return x10.
          array.
          Region.makeUpperTriangular((int)(0),
                                     (int)(0),
                                     (int)(size));
    }
    
    
//#line 136
public static x10.
                   array.
                   Region
                   makeUpperTriangular(
                   final int rowMin,
                   final int colMin,
                   final int size){
        
//#line 137
return x10.
          array.
          PolyRegion.makeUpperTriangular2((int)(rowMin),
                                          (int)(colMin),
                                          (int)(size));
    }
    
    
//#line 142
public static x10.
                   array.
                   Region
                   makeLowerTriangular(
                   final int size){
        
//#line 142
return x10.
          array.
          Region.makeLowerTriangular((int)(0),
                                     (int)(0),
                                     (int)(size));
    }
    
    
//#line 148
public static x10.
                   array.
                   Region
                   makeLowerTriangular(
                   final int rowMin,
                   final int colMin,
                   final int size){
        
//#line 149
return x10.
          array.
          PolyRegion.makeLowerTriangular2((int)(rowMin),
                                          (int)(colMin),
                                          (int)(size));
    }
    
    
//#line 160
abstract public int
                   size(
                   );
    
    
//#line 166
abstract public boolean
                   isConvex(
                   );
    
    
//#line 172
abstract public boolean
                   isEmpty(
                   );
    
    
//#line 184
public x10.
                   array.
                   Region
                   boundingBox(
                   ){
        
//#line 184
return this.computeBoundingBox();
    }
    
    
//#line 187
abstract public x10.
                   array.
                   Region
                   computeBoundingBox(
                   );
    
    
//#line 194
abstract public x10.core.ValRail<java.lang.Integer>
                   min(
                   );
    
    
//#line 201
abstract public x10.core.ValRail<java.lang.Integer>
                   max(
                   );
    
    
//#line 208
public int
                   min(
                   final int i){
        
//#line 208
return ((int[])this.min().value)[i];
    }
    
    
//#line 215
public int
                   max(
                   final int i){
        
//#line 215
return ((int[])this.max().value)[i];
    }
    
    
//#line 252
abstract public x10.
                   array.
                   Region
                   intersection(
                   final x10.
                     array.
                     Region that);
    
    
//#line 266
public boolean
                   disjoint(
                   final x10.
                     array.
                     Region that){
        
//#line 266
return this.intersection(((x10.
                                                array.
                                                Region)(that))).isEmpty();
    }
    
    
//#line 277
abstract public x10.
                   array.
                   Region
                   product(
                   final x10.
                     array.
                     Region that);
    
    
//#line 286
abstract public x10.
                   array.
                   Region
                   translate(
                   final x10.
                     array.
                     Point v);
    
    
//#line 295
abstract public x10.
                   array.
                   Region
                   projection(
                   final int axis);
    
    
//#line 303
abstract public x10.
                   array.
                   Region
                   eliminate(
                   final int axis);
    
    
//#line 314
abstract public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   );
    
    
//#line 335
public static interface Scanner
                 {public static final x10.rtt.RuntimeType<Scanner> _RTT = new x10.rtt.RuntimeType<Scanner>(
    /* base class */Scanner.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    
        
        
//#line 336
void
                       set(
                       final int axis,
                       final int position);
        
        
//#line 337
int
                       min(
                       final int axis);
        
        
//#line 338
int
                       max(
                       final int axis);
    
    }
    
    
    
//#line 341
abstract public x10.core.Iterator<x10.
                   array.
                   Region.
                   Scanner>
                   scanners(
                   );
    
    
//#line 350
public static x10.
                   array.
                   Region
                   $implicit_convert(
                   final x10.core.ValRail<x10.
                     array.
                     Region> rs){
        
//#line 350
return x10.
          array.
          Region.make(((x10.core.ValRail)(rs)));
    }
    
    
//#line 358
public x10.
                   array.
                   Region
                   $and(
                   final x10.
                     array.
                     Region that){
        
//#line 358
return this.intersection(((x10.
                                                array.
                                                Region)(that)));
    }
    
    
//#line 362
public x10.
                   array.
                   Region
                   $times(
                   final x10.
                     array.
                     Region that){
        
//#line 362
return this.product(((x10.
                                           array.
                                           Region)(that)));
    }
    
    
//#line 364
public x10.
                   array.
                   Region
                   $plus(
                   final x10.
                     array.
                     Point v){
        
//#line 364
return this.translate(((x10.
                                             array.
                                             Point)(v)));
    }
    
    
//#line 365
public x10.
                   array.
                   Region
                   $inv_plus(
                   final x10.
                     array.
                     Point v){
        
//#line 365
return this.translate(((x10.
                                             array.
                                             Point)(v)));
    }
    
    
//#line 367
public x10.
                   array.
                   Region
                   $minus(
                   final x10.
                     array.
                     Point v){
        
//#line 367
return this.translate(((x10.
                                             array.
                                             Point)(v.$minus())));
    }
    
    
//#line 374
public boolean
                   equals(
                   final java.lang.Object that){
        
//#line 375
if (x10.rtt.Equality.equalsequals(this,that)) {
            
//#line 375
return true;
        }
        
//#line 376
if ((!(((boolean)((x10.array.Region._RTT.instanceof$(that))))))) {
            
//#line 376
return false;
        }
        
//#line 377
final x10.
          array.
          Region t1 =
          ((x10.
          array.
          Region)((new java.lang.Object() {final x10.
          array.
          Region cast(final x10.
          array.
          Region self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.Region._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          array.
          Region) that))));
        
//#line 378
if (((int) rank) !=
                         ((int) t1.
                                  rank)) {
            
//#line 378
return false;
        }
        
//#line 379
final x10.
          array.
          Region t2 =
          ((x10.
          array.
          Region)(new x10.core.fun.Fun_0_1<x10.
          array.
          Region, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final x10.
          array.
          Region __desugarer__var__34__) { return apply(__desugarer__var__34__);}
        public final x10.
          array.
          Region apply(final x10.
          array.
          Region __desugarer__var__34__) { {
            
//#line 379
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__34__,null)) &&
                               !(((int) __desugarer__var__34__.
                                          rank) ==
                                 ((int) x10.
                                          array.
                                          Region.this.
                                          rank))) {
                
//#line 379
throw new java.lang.ClassCastException("x10.array.Region{self.rank==x10.array.Region#this.rank}");
            }
            
//#line 379
return __desugarer__var__34__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  Region)
                  t1))));
        
//#line 380
return this.contains(((x10.
                                            array.
                                            Region)(t2))) &&
        t2.contains(((x10.
                      array.
                      Region)(this)));
    }
    
    
//#line 383
abstract public boolean
                   contains(
                   final x10.
                     array.
                     Region that);
    
    
//#line 386
abstract public boolean
                   contains(
                   final x10.
                     array.
                     Point p);
    
    
//#line 388
public boolean
                   contains(
                   final int i){
        
//#line 388
return this.contains(((x10.
                                            array.
                                            Point)(x10.
                                            array.
                                            Point.make((int)(i)))));
    }
    
    
//#line 390
public boolean
                   contains(
                   final int i0,
                   final int i1){
        
//#line 390
return this.contains(((x10.
                                            array.
                                            Point)(x10.
                                            array.
                                            Point.make((int)(i0),
                                                       (int)(i1)))));
    }
    
    
//#line 392
public boolean
                   contains(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 392
return this.contains(((x10.
                                            array.
                                            Point)(x10.
                                            array.
                                            Point.make((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2)))));
    }
    
    
//#line 394
public boolean
                   contains(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 394
return this.contains(((x10.
                                            array.
                                            Point)(x10.
                                            array.
                                            Point.make((int)(i0),
                                                       (int)(i1),
                                                       (int)(i2),
                                                       (int)(i3)))));
    }
    
    
//#line 398
public Region(final int r,
                               final boolean t,
                               final boolean z) {
        super();
        
//#line 400
this.rank = r;
        
//#line 400
this.rect = t;
        
//#line 400
this.zeroBased = z;
    }
    
    
//#line 25
final public int
                  rank(
                  ){
        
//#line 25
return this.
                             rank;
    }
    
    
//#line 26
final public boolean
                  rect(
                  ){
        
//#line 26
return this.
                             rect;
    }
    
    
//#line 27
final public boolean
                  zeroBased(
                  ){
        
//#line 27
return this.
                             zeroBased;
    }

}
