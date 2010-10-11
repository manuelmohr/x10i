package x10.array;


abstract public class Dist
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<x10.
               array.
               Point,x10.
               lang.
               Place>,
             x10.core.Iterable<x10.
               array.
               Point >
{public static final x10.rtt.RuntimeType<Dist> _RTT = new x10.rtt.RuntimeType<Dist>(
/* base class */Dist.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.array.Point._RTT, x10.lang.Place._RTT), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method abstract public (a1:Z1)=> U.apply(a1:Z1): U
public x10.
  lang.
  Place
  apply$G(x10.
  array.
  Point a1){return apply( a1);}

    
//#line 28
final public x10.
      array.
      Region
      region;
    
//#line 32
final public boolean
      unique;
    
//#line 36
final public boolean
      constant;
    
//#line 40
final public x10.
      lang.
      Place
      onePlace;
    
    
    
//#line 50
final public int
                  rank(
                  ){
        
//#line 50
return region.
                             rank;
    }
    
    
//#line 54
final public boolean
                  rect(
                  ){
        
//#line 54
return region.
                             rect;
    }
    
    
//#line 58
final public boolean
                  zeroBased(
                  ){
        
//#line 58
return region.
                             zeroBased;
    }
    
    
//#line 62
final public boolean
                  rail(
                  ){
        
//#line 62
return region.rail();
    }
    
    
//#line 79
public static x10.
                  array.
                  Dist
                  makeUnique(
                  ){
        
//#line 79
return x10.
          array.
          BaseDist.makeUnique1();
    }
    
    
//#line 89
public static x10.
                  array.
                  Dist
                  makeConstant(
                  final x10.
                    array.
                    Region r){
        
//#line 89
return x10.
          array.
          BaseDist.makeConstant1(((x10.
                                   array.
                                   Region)(r)));
    }
    
    
//#line 99
public static x10.
                  array.
                  Dist
                  make(
                  final x10.
                    array.
                    Region r){
        
//#line 99
return x10.
          array.
          Dist.makeConstant(((x10.
                              array.
                              Region)(r)));
    }
    
    
//#line 136
public static x10.
                   array.
                   Dist
                   makeBlock(
                   final x10.
                     array.
                     Region r,
                   final int axis){
        
//#line 137
return x10.
          array.
          BaseDist.makeBlock1(((x10.
                                array.
                                Region)(r)),
                              (int)(axis));
    }
    
    
//#line 149
public static x10.
                   array.
                   Dist
                   makeBlock(
                   final x10.
                     array.
                     Region r){
        
//#line 149
return x10.
          array.
          Dist.makeBlock(((x10.
                           array.
                           Region)(r)),
                         (int)(0));
    }
    
    
//#line 177
public static x10.
                   array.
                   Dist
                   makeUnique(
                   final x10.core.Rail<x10.
                     lang.
                     Place> ps){
        
//#line 178
return x10.
          array.
          BaseDist.makeUnique1(((x10.core.ValRail)(x10.core.RailFactory.<x10.
                                 lang.
                                 Place>makeValRailFromRail(x10.lang.Place._RTT, ps))));
    }
    
    
//#line 188
public static x10.
                   array.
                   Dist
                   makeUnique(
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 189
return x10.
          array.
          BaseDist.makeUnique1(((x10.
                                 util.
                                 Set)(ps)));
    }
    
    
//#line 199
public static x10.
                   array.
                   Dist
                   makeConstant(
                   final x10.
                     array.
                     Region r,
                   final x10.
                     lang.
                     Place p){
        
//#line 200
return x10.
          array.
          BaseDist.makeConstant1(((x10.
                                   array.
                                   Region)(r)),
                                 ((x10.
                                   lang.
                                   Place)(p)));
    }
    
    
//#line 226
public static x10.
                   array.
                   Dist
                   makeBlock(
                   final x10.
                     array.
                     Region r,
                   final int axis,
                   final x10.
                     util.
                     Set<x10.
                     lang.
                     Place> ps){
        
//#line 227
return x10.
          array.
          BaseDist.makeBlock1(((x10.
                                array.
                                Region)(r)),
                              (int)(axis),
                              ((x10.
                                util.
                                Set)(ps)));
    }
    
    
//#line 252
abstract public x10.core.ValRail<x10.
                   lang.
                   Place>
                   places(
                   );
    
    
//#line 257
abstract public x10.core.ValRail<x10.
                   array.
                   Region>
                   regions(
                   );
    
    
//#line 266
abstract public x10.
                   array.
                   Region
                   get(
                   final x10.
                     lang.
                     Place p);
    
    
//#line 280
abstract public x10.
                   lang.
                   Place
                   apply(
                   final x10.
                     array.
                     Point pt);
    
    
//#line 291
abstract public x10.
                   lang.
                   Place
                   apply(
                   final int i0);
    
    
//#line 303
abstract public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1);
    
    
//#line 316
abstract public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1,
                   final int i2);
    
    
//#line 330
abstract public x10.
                   lang.
                   Place
                   apply(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3);
    
    
//#line 347
public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   ){
        
//#line 347
return ((x10.core.Iterator)
                              region.iterator());
    }
    
    
//#line 384
abstract public x10.
                   array.
                   Dist
                   restriction(
                   final x10.
                     array.
                     Region r);
    
    
//#line 399
abstract public boolean
                   isSubdistribution(
                   final x10.
                     array.
                     Dist that);
    
    
//#line 451
abstract public boolean
                   equals(
                   final java.lang.Object that);
    
    
//#line 464
abstract public x10.
                   array.
                   Dist
                   restriction(
                   final x10.
                     lang.
                     Place p);
    
    
//#line 472
abstract public boolean
                   contains(
                   final x10.
                     array.
                     Point p);
    
    
//#line 485
public x10.
                   array.
                   Dist
                   $bar(
                   final x10.
                     array.
                     Region r){
        
//#line 486
return this.restriction(((x10.
                                               array.
                                               Region)(r)));
    }
    
    
//#line 494
public x10.
                   array.
                   Dist
                   $bar(
                   final x10.
                     lang.
                     Place p){
        
//#line 494
return this.restriction(((x10.
                                               lang.
                                               Place)(p)));
    }
    
    
//#line 543
public Dist(final x10.
                               array.
                               Region region,
                             final boolean unique,
                             final boolean constant,
                             final x10.
                               lang.
                               Place onePlace) {
        super();
        
//#line 544
this.region = region;
        
//#line 544
this.unique = unique;
        
//#line 544
this.constant = constant;
        
//#line 544
this.onePlace = onePlace;
    }
    
    
//#line 28
final public x10.
                  array.
                  Region
                  region(
                  ){
        
//#line 28
return this.
                             region;
    }
    
    
//#line 32
final public boolean
                  unique(
                  ){
        
//#line 32
return this.
                             unique;
    }
    
    
//#line 36
final public boolean
                  constant(
                  ){
        
//#line 36
return this.
                             constant;
    }
    
    
//#line 40
final public x10.
                  lang.
                  Place
                  onePlace(
                  ){
        
//#line 40
return this.
                             onePlace;
    }

}
