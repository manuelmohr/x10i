package x10.array;


public class BaseDist
extends x10.
  array.
  Dist
{public static final x10.rtt.RuntimeType<BaseDist> _RTT = new x10.rtt.RuntimeType<BaseDist>(
/* base class */BaseDist.class
, /* parents */ new x10.rtt.Type[] {x10.array.Dist._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
    
    
//#line 39
final public static x10.
      array.
      Dist
      UNIQUE =
      ((x10.
      array.
      Dist)(new x10.core.fun.Fun_0_1<x10.
      array.
      Dist, x10.
      array.
      Dist>() {public final x10.
      array.
      Dist apply$G(final x10.
      array.
      Dist __desugarer__var__0__) { return apply(__desugarer__var__0__);}
    public final x10.
      array.
      Dist apply(final x10.
      array.
      Dist __desugarer__var__0__) { {
        
//#line 39
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__0__,null)) &&
                          !(((boolean) __desugarer__var__0__.
                                         region.
                                         rect) ==
                            ((boolean) true) &&
                            ((int) __desugarer__var__0__.
                                     region.
                                     rank) ==
                            ((int) 1))) {
            
//#line 39
throw new java.lang.ClassCastException("x10.array.Dist{self.region.rect==true, self.region.rank==1}");
        }
        
//#line 39
return __desugarer__var__0__;
    }}
    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Dist._RTT;if (i ==1) return x10.array.Dist._RTT;return null;
    }
    }.apply(((x10.
              array.
              Dist)
              x10.
              array.
              BaseDist.makeUnique1(((x10.core.ValRail)(x10.
                                     lang.
                                     Place.places)))))));
    
    
//#line 40
public static x10.
                  array.
                  Dist
                  makeUnique1(
                  ){
        
//#line 41
return x10.
          array.
          BaseDist.UNIQUE;
    }
    
    
//#line 44
public static x10.
                  array.
                  Dist
                  makeUnique1(
                  final x10.core.ValRail<x10.
                    lang.
                    Place> ps){
        
//#line 47
final x10.core.fun.Fun_0_1<java.lang.Integer,x10.
          array.
          Region> init =
          ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final java.lang.Integer i) { return apply((int)i);}
        public final x10.
          array.
          Region apply(final int i) { {
            
//#line 47
return x10.
              array.
              Region.makeRectangular((int)(i),
                                     (int)(i));
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }));
        
//#line 48
final x10.core.ValRail<x10.
          array.
          Region> regions =
          ((x10.core.ValRail)(x10.core.RailFactory.<x10.
          array.
          Region>makeValRail(x10.array.Region._RTT, ((int)(ps.
                                                             length)), init)));
        
//#line 51
final x10.
          array.
          Region overall =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeRectangular((int)(0),
                                 (int)(((((int)(ps.
                                                  length))) - (((int)(1))))))));
        
//#line 53
return new x10.
          array.
          BaseDist(overall,
                   ps,
                   regions);
    }
    
    
//#line 56
public static x10.
                  array.
                  Dist
                  makeBlock1(
                  final x10.
                    array.
                    Region r,
                  final int axis){
        
//#line 57
final x10.
          array.
          Region b =
          ((x10.
          array.
          Region)(r.boundingBox()));
        
//#line 58
final int min =
          ((java.lang.Integer)(((int[])b.min().value)[axis]));
        
//#line 59
final int max =
          ((java.lang.Integer)(((int[])b.max().value)[axis]));
        
//#line 60
final int P =
          x10.runtime.impl.java.Runtime.MAX_PLACES;
        
//#line 61
final int numElems =
          ((((int)(((((int)(max))) - (((int)(min))))))) + (((int)(1))));
        
//#line 62
final int blockSize =
          ((((int)(numElems))) / (((int)(P))));
        
//#line 63
final int leftOver =
          ((((int)(numElems))) - (((int)(((((int)(P))) * (((int)(blockSize))))))));
        
//#line 64
final x10.core.Rail<x10.
          array.
          Region> regions =
          ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<x10.
          array.
          Region> apply(int length) {x10.
          array.
          Region[] array = new x10.
          array.
          Region[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;final x10.
          array.
          Region r1 =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeFull((int)(axis))));final int low =
          ((((int)(((((int)(min))) + (((int)(((((int)(blockSize))) * (((int)(i))))))))))) + (((int)((((((int)(i))) < (((int)(leftOver))))
                                                                                                       ? i
                                                                                                       : leftOver)))));final int hi =
          ((((int)(((((int)(low))) + (((int)(blockSize))))))) + (((int)((((((int)(i))) < (((int)(leftOver))))
                                                                           ? 0
                                                                           : -1)))));final x10.
          array.
          Region r2 =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeRectangular((int)(low),
                                 (int)(hi))));final x10.
          array.
          Region r3 =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeFull((int)(((((int)(((((int)(r.
                                                    rank))) - (((int)(axis))))))) - (((int)(1))))))));array[i] = (new x10.core.fun.Fun_0_1<x10.
                                                                                                                    array.
                                                                                                                    Region, x10.
                                                                                                                    array.
                                                                                                                    Region>() {public final x10.
                                                                                                                    array.
                                                                                                                    Region apply$G(final x10.
                                                                                                                    array.
                                                                                                                    Region __desugarer__var__1__) { return apply(__desugarer__var__1__);}
                                                                                                                  public final x10.
                                                                                                                    array.
                                                                                                                    Region apply(final x10.
                                                                                                                    array.
                                                                                                                    Region __desugarer__var__1__) { {
                                                                                                                      
//#line 71
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__1__,null)) &&
                                                                                                                                        !(((int) __desugarer__var__1__.
                                                                                                                                                   rank) ==
                                                                                                                                          ((int) r.
                                                                                                                                                   rank))) {
                                                                                                                          
//#line 71
throw new java.lang.ClassCastException("x10.array.Region{self.rank==r.rank}");
                                                                                                                      }
                                                                                                                      
//#line 71
return __desugarer__var__1__;
                                                                                                                  }}
                                                                                                                  public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
                                                                                                                  }
                                                                                                                  }.apply(((x10.
                                                                                                                            array.
                                                                                                                            Region)
                                                                                                                            r1.product(((x10.
                                                                                                                                         array.
                                                                                                                                         Region)(r2))).product(((x10.
                                                                                                                                                                 array.
                                                                                                                                                                 Region)(r3)))))).intersection(((x10.
                                                                                                                                                                                                 array.
                                                                                                                                                                                                 Region)(r)));}return new x10.core.Rail<x10.
          array.
          Region>(x10.array.Region._RTT, P, array);}}.apply(P))));
        
//#line 73
return new x10.
          array.
          BaseDist(r,
                   x10.
                     lang.
                     Place.places,
                   x10.core.RailFactory.<x10.
                     array.
                     Region>makeValRailFromRail(x10.array.Region._RTT, regions));
    }
    
    
//#line 102
public static x10.
                   array.
                   Dist
                   makeConstant1(
                   final x10.
                     array.
                     Region r){
        
//#line 103
return x10.
          array.
          Dist.makeConstant(((x10.
                              array.
                              Region)(r)),
                            ((x10.
                              lang.
                              Place)(x10.
                              lang.
                              Runtime.here())));
    }
    
    
//#line 112
public static x10.
                   array.
                   Dist
                   makeUnique1(
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 112
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 114
public static x10.
                   array.
                   Dist
                   makeConstant1(
                   final x10.
                     array.
                     Region r,
                   final x10.
                     lang.
                     Place p){
        
//#line 115
return new x10.
          array.
          BaseDist(r,
                   x10.core.RailFactory.<x10.
                     lang.
                     Place>makeValRailFromJavaArray(x10.lang.Place._RTT, new x10.
                     lang.
                     Place[] {p}),
                   x10.core.RailFactory.<x10.
                     array.
                     Region>makeValRailFromJavaArray(x10.array.Region._RTT, new x10.
                     array.
                     Region[] {r}));
    }
    
    
//#line 118
public static x10.
                   array.
                   Dist
                   makeCyclic1(
                   final x10.
                     array.
                     Region r,
                   final int axis,
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 118
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 120
public static x10.
                   array.
                   Dist
                   makeBlock1(
                   final x10.
                     array.
                     Region r,
                   final int axis,
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 120
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 122
public static x10.
                   array.
                   Dist
                   makeBlockCyclic1(
                   final x10.
                     array.
                     Region r,
                   final int axis,
                   final int blockSize,
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 122
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 129
public x10.core.ValRail<x10.
                   lang.
                   Place>
                   places(
                   ){
        
//#line 130
return places;
    }
    
    
//#line 133
public x10.core.ValRail<x10.
                   array.
                   Region>
                   regions(
                   ){
        
//#line 134
return regions;
    }
    
    
//#line 137
public x10.
                   array.
                   Region
                   get(
                   final x10.
                     lang.
                     Place p){
        
//#line 138
return new x10.core.fun.Fun_0_1<x10.
          array.
          Region, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final x10.
          array.
          Region __desugarer__var__2__) { return apply(__desugarer__var__2__);}
        public final x10.
          array.
          Region apply(final x10.
          array.
          Region __desugarer__var__2__) { {
            
//#line 138
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__2__,null)) &&
                               !(((int) __desugarer__var__2__.
                                          rank) ==
                                 ((int) x10.
                                          array.
                                          BaseDist.this.
                                          region.
                                          rank))) {
                
//#line 138
throw new java.lang.ClassCastException(("x10.array.Region{self.rank==x10.array.BaseDist#this.region.r" +
                                                                     "ank}"));
            }
            
//#line 138
return __desugarer__var__2__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  Region)
                  ((x10.
                  array.
                  Region)((x10.
                  array.
                  Region[])regionMap.value)[p.
                                              id])));
    }
    
    
//#line 141
public x10.
                   array.
                   Region
                   apply(
                   final x10.
                     lang.
                     Place p){
        
//#line 141
return this.get(((x10.
                                       lang.
                                       Place)(p)));
    }
    
    
//#line 148
public x10.
                   lang.
                   Place
                   apply(
                   final x10.
                     array.
                     Point pt){
        {
            
//#line 149
final x10.
              array.
              Region[] x10$array$BaseDist$this$regionMap$value1925 =
              ((x10.
              array.
              Region[])regionMap.value);
            
//#line 149
for (
//#line 149
int i =
                                0;
                              ((((int)(i))) < (((int)(regionMap.
                                                        length))));
                              
//#line 149
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 150
if (((x10.
                                   array.
                                   Region)x10$array$BaseDist$this$regionMap$value1925[i]).contains(((x10.
                                                                                                     array.
                                                                                                     Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                     array.
                                                                                                     Point, x10.
                                                                                                     array.
                                                                                                     Point>() {public final x10.
                                                                                                     array.
                                                                                                     Point apply$G(final x10.
                                                                                                     array.
                                                                                                     Point __desugarer__var__3__) { return apply(__desugarer__var__3__);}
                                                                                                   public final x10.
                                                                                                     array.
                                                                                                     Point apply(final x10.
                                                                                                     array.
                                                                                                     Point __desugarer__var__3__) { {
                                                                                                       
//#line 150
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__3__,null)) &&
                                                                                                                          !(((int) __desugarer__var__3__.
                                                                                                                                     rank) ==
                                                                                                                            ((int) x10.
                                                                                                                                     array.
                                                                                                                                     BaseDist.this.
                                                                                                                                     region.
                                                                                                                                     rank))) {
                                                                                                           
//#line 150
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.BaseDist#this.region.ra" +
                                                                                                                                                                "nk}"));
                                                                                                       }
                                                                                                       
//#line 150
return __desugarer__var__3__;
                                                                                                   }}
                                                                                                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                   }
                                                                                                   }.apply(((x10.
                                                                                                             array.
                                                                                                             Point)
                                                                                                             pt)))))) {
                    
//#line 151
return ((x10.
                      lang.
                      Place)((x10.
                      lang.
                      Place[])x10.
                      lang.
                      Place.places.value)[i]);
                }
            }
        }
        
//#line 152
throw new java.lang.ArrayIndexOutOfBoundsException((((("point ") + (pt))) + (" not contained in distribution")));
    }
    
    
//#line 155
public x10.
                   lang.
                   Place
                   apply(
                   final int i0){
        
//#line 155
return this.apply(((x10.
                                         array.
                                         Point)(new x10.core.fun.Fun_0_1<x10.
                                         array.
                                         Point, x10.
                                         array.
                                         Point>() {public final x10.
                                         array.
                                         Point apply$G(final x10.
                                         array.
                                         Point __desugarer__var__4__) { return apply(__desugarer__var__4__);}
                                       public final x10.
                                         array.
                                         Point apply(final x10.
                                         array.
                                         Point __desugarer__var__4__) { {
                                           
//#line 155
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__4__,null)) &&
                                                              !(((int) __desugarer__var__4__.
                                                                         rank) ==
                                                                ((int) x10.
                                                                         array.
                                                                         BaseDist.this.
                                                                         region.
                                                                         rank))) {
                                               
//#line 155
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.BaseDist#this.region.ra" +
                                                                                                    "nk}"));
                                           }
                                           
//#line 155
return __desugarer__var__4__;
                                       }}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                       }
                                       }.apply(((x10.
                                                 array.
                                                 Point)
                                                 x10.
                                                 array.
                                                 Point.$implicit_convert(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0})))))))));
    }
    
    
//#line 156
public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1){
        
//#line 156
return this.apply(((x10.
                                         array.
                                         Point)(new x10.core.fun.Fun_0_1<x10.
                                         array.
                                         Point, x10.
                                         array.
                                         Point>() {public final x10.
                                         array.
                                         Point apply$G(final x10.
                                         array.
                                         Point __desugarer__var__5__) { return apply(__desugarer__var__5__);}
                                       public final x10.
                                         array.
                                         Point apply(final x10.
                                         array.
                                         Point __desugarer__var__5__) { {
                                           
//#line 156
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__5__,null)) &&
                                                              !(((int) __desugarer__var__5__.
                                                                         rank) ==
                                                                ((int) x10.
                                                                         array.
                                                                         BaseDist.this.
                                                                         region.
                                                                         rank))) {
                                               
//#line 156
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.BaseDist#this.region.ra" +
                                                                                                    "nk}"));
                                           }
                                           
//#line 156
return __desugarer__var__5__;
                                       }}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                       }
                                       }.apply(((x10.
                                                 array.
                                                 Point)
                                                 x10.
                                                 array.
                                                 Point.$implicit_convert(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1})))))))));
    }
    
    
//#line 157
public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 157
return this.apply(((x10.
                                         array.
                                         Point)(new x10.core.fun.Fun_0_1<x10.
                                         array.
                                         Point, x10.
                                         array.
                                         Point>() {public final x10.
                                         array.
                                         Point apply$G(final x10.
                                         array.
                                         Point __desugarer__var__6__) { return apply(__desugarer__var__6__);}
                                       public final x10.
                                         array.
                                         Point apply(final x10.
                                         array.
                                         Point __desugarer__var__6__) { {
                                           
//#line 157
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__6__,null)) &&
                                                              !(((int) __desugarer__var__6__.
                                                                         rank) ==
                                                                ((int) x10.
                                                                         array.
                                                                         BaseDist.this.
                                                                         region.
                                                                         rank))) {
                                               
//#line 157
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.BaseDist#this.region.ra" +
                                                                                                    "nk}"));
                                           }
                                           
//#line 157
return __desugarer__var__6__;
                                       }}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                       }
                                       }.apply(((x10.
                                                 array.
                                                 Point)
                                                 x10.
                                                 array.
                                                 Point.$implicit_convert(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1, i2})))))))));
    }
    
    
//#line 158
public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 158
return this.apply(((x10.
                                         array.
                                         Point)(new x10.core.fun.Fun_0_1<x10.
                                         array.
                                         Point, x10.
                                         array.
                                         Point>() {public final x10.
                                         array.
                                         Point apply$G(final x10.
                                         array.
                                         Point __desugarer__var__7__) { return apply(__desugarer__var__7__);}
                                       public final x10.
                                         array.
                                         Point apply(final x10.
                                         array.
                                         Point __desugarer__var__7__) { {
                                           
//#line 158
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__7__,null)) &&
                                                              !(((int) __desugarer__var__7__.
                                                                         rank) ==
                                                                ((int) x10.
                                                                         array.
                                                                         BaseDist.this.
                                                                         region.
                                                                         rank))) {
                                               
//#line 158
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.BaseDist#this.region.ra" +
                                                                                                    "nk}"));
                                           }
                                           
//#line 158
return __desugarer__var__7__;
                                       }}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                       }
                                       }.apply(((x10.
                                                 array.
                                                 Point)
                                                 x10.
                                                 array.
                                                 Point.$implicit_convert(((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {i0, i1, i2, i3})))))))));
    }
    
    
//#line 166
public x10.
                   array.
                   Dist
                   restriction(
                   final x10.
                     array.
                     Region r){
        
//#line 172
final x10.core.ValRail<x10.
          lang.
          Place> ps =
          ((x10.core.ValRail)(this.
                                places));
        
//#line 175
final x10.core.fun.Fun_0_1<java.lang.Integer,x10.
          array.
          Region> init =
          ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<java.lang.Integer, x10.
          array.
          Region>() {public final x10.
          array.
          Region apply$G(final java.lang.Integer i) { return apply((int)i);}
        public final x10.
          array.
          Region apply(final int i) { {
            
//#line 175
return ((x10.
              array.
              Region)((x10.
              array.
              Region[])x10.
                         array.
                         BaseDist.this.
                         regions.value)[i]).intersection(((x10.
                                                           array.
                                                           Region)(r)));
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.array.Region._RTT;return null;
        }
        }));
        
//#line 176
final x10.core.ValRail<x10.
          array.
          Region> rs =
          ((x10.core.ValRail)(x10.core.RailFactory.<x10.
          array.
          Region>makeValRail(x10.array.Region._RTT, ((int)(this.
                                                             regions.
                                                             length)), init)));
        
//#line 178
return new x10.
          array.
          BaseDist(r,
                   ps,
                   rs);
    }
    
    
//#line 181
public x10.
                   array.
                   Dist
                   restriction(
                   final x10.
                     lang.
                     Place p){
        
//#line 182
final x10.core.ValRail<x10.
          lang.
          Place> ps =
          ((x10.core.ValRail)(x10.core.RailFactory.<x10.
          lang.
          Place>makeValRailFromJavaArray(x10.lang.Place._RTT, new x10.
          lang.
          Place[] {p})));
        
//#line 183
final x10.core.ValRail<x10.
          array.
          Region> rs =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<x10.
          array.
          Region> apply(int length) {x10.
          array.
          Region[] array = new x10.
          array.
          Region[length];for (int id$17$ = 0; id$17$ < length; id$17$++) {final int id$17 = id$17$;array[id$17] = x10.
          array.
          BaseDist.this.get(((x10.
                              lang.
                              Place)(p)));}return new x10.core.ValRail<x10.
          array.
          Region>(x10.array.Region._RTT, 1, array);}}.apply(1))));
        
//#line 184
return new x10.
          array.
          BaseDist(new x10.core.fun.Fun_0_1<x10.
                     array.
                     Region, x10.
                     array.
                     Region>() {public final x10.
                     array.
                     Region apply$G(final x10.
                     array.
                     Region __desugarer__var__8__) { return apply(__desugarer__var__8__);}
                   public final x10.
                     array.
                     Region apply(final x10.
                     array.
                     Region __desugarer__var__8__) { {
                       
//#line 184
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__8__,null)) &&
                                          !(((int) __desugarer__var__8__.
                                                     rank) ==
                                            ((int) x10.
                                                     array.
                                                     BaseDist.this.
                                                     region.
                                                     rank))) {
                           
//#line 184
throw new java.lang.ClassCastException(("x10.array.Region{self.rank==x10.array.BaseDist#this.region.r" +
                                                                                "ank}"));
                       }
                       
//#line 184
return __desugarer__var__8__;
                   }}
                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Region._RTT;if (i ==1) return x10.array.Region._RTT;return null;
                   }
                   }.apply(((x10.
                             array.
                             Region)
                             region.intersection(((x10.
                                                   array.
                                                   Region)(((x10.
                                                   array.
                                                   Region)((x10.
                                                   array.
                                                   Region[])rs.value)[0])))))),
                   ps,
                   rs);
    }
    
    
//#line 277
public boolean
                   isSubdistribution(
                   final x10.
                     array.
                     Dist that){
        
//#line 278
for (
//#line 278
final x10.core.Iterator<x10.
                            lang.
                            Place> p1350 =
                            (x10.
                            lang.
                            Place.places).iterator();
                          p1350.hasNext();
                          ) {
            
//#line 278
final x10.
              lang.
              Place p =
              p1350.next$G();
            
//#line 279
if ((!(((boolean)(that.get(((x10.
                                                      lang.
                                                      Place)(p))).contains(((x10.
                                                                             array.
                                                                             Region)(this.get(((x10.
                                                                                                lang.
                                                                                                Place)(p))))))))))) {
                
//#line 280
return false;
            }
        }
        
//#line 281
return true;
    }
    
    
//#line 290
public static boolean
                   isUnique(
                   final x10.core.Rail<x10.
                     lang.
                     Place> places){
        
//#line 291
if (((int) places.
                                  length) !=
                         ((int) x10.runtime.impl.java.Runtime.MAX_PLACES)) {
            
//#line 292
return false;
        }
        {
            
//#line 293
final x10.
              lang.
              Place[] places$value1926 =
              ((x10.
              lang.
              Place[])places.value);
            
//#line 293
for (
//#line 293
int i =
                                0;
                              ((((int)(i))) < (((int)(places.
                                                        length))));
                              
//#line 293
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 294
if (((int) ((x10.
                                          lang.
                                          Place)places$value1926[i]).
                                          id) !=
                                 ((int) i)) {
                    
//#line 295
return false;
                }
            }
        }
        
//#line 297
return true;
    }
    
    
//#line 300
public static boolean
                   isConstant(
                   final x10.core.Rail<x10.
                     lang.
                     Place> places){
        {
            
//#line 301
final x10.
              lang.
              Place[] places$value1927 =
              ((x10.
              lang.
              Place[])places.value);
            
//#line 301
for (
//#line 301
final x10.core.Iterator<x10.
                                lang.
                                Place> p1351 =
                                (places).iterator();
                              p1351.hasNext();
                              ) {
                
//#line 301
final x10.
                  lang.
                  Place p =
                  p1351.next$G();
                
//#line 302
if ((!x10.rtt.Equality.equalsequals(p,((x10.
                                   lang.
                                   Place)places$value1927[0])))) {
                    
//#line 303
return false;
                }
            }
        }
        
//#line 304
return true;
    }
    
    
//#line 307
public static x10.
                   lang.
                   Place
                   onePlace(
                   final x10.core.Rail<x10.
                     lang.
                     Place> places){
        
//#line 308
return ((int) places.
                                     length) ==
        ((int) 0)
          ? x10.
          lang.
          Runtime.here()
          : ((x10.
          lang.
          Place)((x10.
          lang.
          Place[])places.value)[0]);
    }
    
    
//#line 311
public boolean
                   equals(
                   final java.lang.Object thatObj){
        
//#line 312
if ((!(((boolean)((x10.array.Dist._RTT.instanceof$(thatObj))))))) {
            
//#line 312
return false;
        }
        
//#line 313
final x10.
          array.
          Dist that =
          (new java.lang.Object() {final x10.
          array.
          Dist cast(final x10.
          array.
          Dist self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.Dist._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          array.
          Dist) thatObj));
        
//#line 314
for (
//#line 314
final x10.core.Iterator<x10.
                            lang.
                            Place> p1352 =
                            (x10.
                            lang.
                            Place.places).iterator();
                          p1352.hasNext();
                          ) {
            
//#line 314
final x10.
              lang.
              Place p =
              p1352.next$G();
            
//#line 315
if ((!(((boolean)(this.get(((x10.
                                                      lang.
                                                      Place)(p))).equals(((java.lang.Object)(that.get(((x10.
                                                                                                        lang.
                                                                                                        Place)(p))))))))))) {
                
//#line 316
return false;
            }
        }
        
//#line 317
return true;
    }
    
    
//#line 321
public boolean
                   contains(
                   final x10.
                     array.
                     Point p){
        
//#line 321
return region.contains(((x10.
                                              array.
                                              Point)(p)));
    }
    
    
//#line 333
final public x10.core.ValRail<x10.
      lang.
      Place>
      places;
    
//#line 334
final public x10.core.ValRail<x10.
      array.
      Region>
      regions;
    
//#line 335
final public x10.core.ValRail<x10.
      array.
      Region>
      regionMap;
    
    
//#line 337
public BaseDist(final x10.
                                   array.
                                   Region r,
                                 final x10.core.ValRail<x10.
                                   lang.
                                   Place> ps,
                                 final x10.core.ValRail<x10.
                                   array.
                                   Region> rs) {
        
//#line 339
super(r,
                           x10.
                             array.
                             BaseDist.isUnique(((x10.core.Rail)(x10.core.RailFactory.<x10.
                                                 lang.
                                                 Place>makeRailFromValRail(x10.lang.Place._RTT, ps)))),
                           x10.
                             array.
                             BaseDist.isConstant(((x10.core.Rail)(x10.core.RailFactory.<x10.
                                                   lang.
                                                   Place>makeRailFromValRail(x10.lang.Place._RTT, ps)))),
                           x10.
                             array.
                             BaseDist.onePlace(((x10.core.Rail)(x10.core.RailFactory.<x10.
                                                 lang.
                                                 Place>makeRailFromValRail(x10.lang.Place._RTT, ps)))));
        
//#line 342
final x10.
          util.
          ArrayList<x10.
          array.
          Region> rl =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<x10.
          array.
          Region>(x10.array.Region._RTT)));
        
//#line 345
final x10.core.GrowableRail<x10.
          lang.
          Place> pl =
          ((x10.core.GrowableRail)(new x10.core.GrowableRail<x10.
          lang.
          Place>(x10.lang.Place._RTT)));
        {
            
//#line 346
final x10.
              array.
              Region[] rs$value1928 =
              ((x10.
              array.
              Region[])rs.value);
            
//#line 346
final x10.
              lang.
              Place[] ps$value1929 =
              ((x10.
              lang.
              Place[])ps.value);
            
//#line 346
for (
//#line 346
int i =
                                0;
                              ((((int)(i))) < (((int)(rs.
                                                        length))));
                              
//#line 346
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 347
if ((!(((boolean)(((x10.
                                   array.
                                   Region)rs$value1928[i]).isEmpty()))))) {
                    
//#line 348
rl.add(((x10.
                                          array.
                                          Region)(((x10.
                                          array.
                                          Region)rs$value1928[i]))));
                    
//#line 349
(pl).add(((x10.
                      lang.
                      Place)ps$value1929[i]));
                }
            }
        }
        
//#line 352
this.regions = (new java.lang.Object() {final x10.core.ValRail cast(final x10.core.ValRail self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.array.Region._RTT);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.core.ValRail) rl.toValRail()));
        
//#line 353
this.places = (pl).toValRail();
        
//#line 356
final x10.
          array.
          Region empty =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeEmpty((int)(this.rank()))));
        
//#line 357
final x10.core.Rail<x10.
          array.
          Region> regionMap =
          ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<x10.
          array.
          Region> apply(int length) {x10.
          array.
          Region[] array = new x10.
          array.
          Region[length];for (int id$18$ = 0; id$18$ < length; id$18$++) {final int id$18 = id$18$;array[id$18] = empty;}return new x10.core.Rail<x10.
          array.
          Region>(x10.array.Region._RTT, x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
        {
            
//#line 358
final x10.
              array.
              Region[] x10$array$BaseDist$this$regions$value1930 =
              ((x10.
              array.
              Region[])this.
                         regions.value);
            
//#line 358
final x10.
              lang.
              Place[] x10$array$BaseDist$this$places$value1931 =
              ((x10.
              lang.
              Place[])this.
                        places.value);
            
//#line 358
final x10.
              array.
              Region[] regionMap$value1932 =
              ((x10.
              array.
              Region[])regionMap.value);
            
//#line 358
for (
//#line 358
int i =
                                0;
                              ((((int)(i))) < (((int)(this.
                                                        places.
                                                        length))));
                              
//#line 358
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 359
regionMap$value1932[((x10.
                                                   lang.
                                                   Place)x10$array$BaseDist$this$places$value1931[i]).
                                                   id]=((x10.
                  array.
                  Region)x10$array$BaseDist$this$regions$value1930[i]);
            }
        }
        
//#line 360
this.regionMap = (new java.lang.Object() {final x10.core.ValRail<x10.
          array.
          Region> apply(int length) {x10.
          array.
          Region[] array = new x10.
          array.
          Region[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((x10.
          array.
          Region)((x10.
          array.
          Region[])regionMap.value)[i]);}return new x10.core.ValRail<x10.
          array.
          Region>(x10.array.Region._RTT, regionMap.
                                           length, array);}}.apply(regionMap.
                                                                     length));
    }
    
    
//#line 368
public java.lang.String
                   toString(
                   ){
        
//#line 369
java.lang.String s =
          "Dist(";
        
//#line 370
boolean first =
          true;
        
//#line 371
for (
//#line 371
final x10.core.Iterator<x10.
                            lang.
                            Place> p1353 =
                            (places).iterator();
                          p1353.hasNext();
                          ) {
            
//#line 371
final x10.
              lang.
              Place p =
              p1353.next$G();
            
//#line 372
if ((!(((boolean)(first))))) {
                
//#line 372
s = ((s) + (","));
            }
            
//#line 373
s = ((s) + (((((this.get(((x10.
                                                    lang.
                                                    Place)(p)))) + ("->"))) + (((java.lang.Integer)(p.
                                                                                                      id))))));
            
//#line 374
first = false;
        }
        
//#line 376
s = ((s) + (")"));
        
//#line 377
return s;
    }

}
