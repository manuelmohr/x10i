package x10.array;

final public class FullRegion
extends x10.
  array.
  Region
{public static final x10.rtt.RuntimeType<FullRegion> _RTT = new x10.rtt.RuntimeType<FullRegion>(
/* base class */FullRegion.class
, /* parents */ new x10.rtt.Type[] {x10.array.Region._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 19
public FullRegion(final int rank) {
        
//#line 20
super(rank,
                          true,
                          false);
        
//#line 21
if (((((int)(rank))) < (((int)(0))))) {
            
//#line 21
throw new java.lang.IllegalArgumentException((((("Rank is negative (") + (((java.lang.Integer)(rank))))) + (")")));
        }
    }
    
    
//#line 24
public boolean
                  isConvex(
                  ){
        
//#line 24
return true;
    }
    
    
//#line 25
public boolean
                  isEmpty(
                  ){
        
//#line 25
return false;
    }
    
    
//#line 26
public int
                  size(
                  ){
        
//#line 27
throw new x10.
          lang.
          IllegalOperationException("Full Region is infinite; size not supported");
    }
    
    
//#line 29
public x10.core.ValRail<java.lang.Integer>
                  min(
                  ){
        
//#line 29
return (new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$42$ = 0; id$42$ < length; id$42$++) {final int id$42 = id$42$;array[id$42] = java.lang.Integer.MIN_VALUE;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank));
    }
    
    
//#line 30
public x10.core.ValRail<java.lang.Integer>
                  max(
                  ){
        
//#line 30
return (new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$43$ = 0; id$43$ < length; id$43$++) {final int id$43 = id$43$;array[id$43] = java.lang.Integer.MAX_VALUE;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank));
    }
    
    
//#line 31
public x10.
                  array.
                  Region
                  intersection(
                  final x10.
                    array.
                    Region that){
        
//#line 31
return that;
    }
    
    
//#line 32
public x10.
                  array.
                  Region
                  product(
                  final x10.
                    array.
                    Region that){
        
//#line 33
if (that.isEmpty()) {
            
//#line 34
return x10.
              array.
              Region.makeEmpty((int)(((((int)(rank))) + (((int)(that.
                                                                  rank))))));
        } else {
            
//#line 35
if (x10.array.FullRegion._RTT.instanceof$(that)) {
                
//#line 36
return new x10.
                  array.
                  FullRegion(((((int)(rank))) + (((int)(that.
                                                          rank)))));
            } else {
                
//#line 37
if (x10.array.RectRegion._RTT.instanceof$(that)) {
                    
//#line 38
final x10.core.ValRail<java.lang.Integer> thatMin =
                      ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                             array.
                                             RectRegion cast(final x10.
                                             array.
                                             RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             array.
                                             RectRegion) that))).min()));
                    
//#line 39
final x10.core.ValRail<java.lang.Integer> thatMax =
                      ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                             array.
                                             RectRegion cast(final x10.
                                             array.
                                             RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             array.
                                             RectRegion) that))).max()));
                    
//#line 40
final int newRank =
                      ((((int)(rank))) + (((int)(that.
                                                   rank))));
                    
//#line 41
final x10.core.ValRail<java.lang.Integer> newMin =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                      ? java.lang.Integer.MIN_VALUE
                      : ((int[])thatMin.value)[((((int)(i))) - (((int)(rank))))];}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, newRank, array);}}.apply(newRank))));
                    
//#line 42
final x10.core.ValRail<java.lang.Integer> newMax =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                      ? java.lang.Integer.MAX_VALUE
                      : ((int[])thatMax.value)[((((int)(i))) - (((int)(rank))))];}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, newRank, array);}}.apply(newRank))));
                    
//#line 43
return x10.
                      array.
                      Region.makeRectangular(((x10.core.ValRail)(newMin)),
                                             ((x10.core.ValRail)(newMax)));
                } else {
                    
//#line 45
throw new java.lang.UnsupportedOperationException((("haven\'t implemented FullRegion product with ") + (x10.core.Ref.typeName(that))));
                }
            }
        }
    }
    
    
//#line 48
public x10.
                  array.
                  Region
                  projection(
                  final int axis){
        
//#line 48
return new x10.
          array.
          FullRegion(1);
    }
    
    
//#line 49
public x10.
                  array.
                  Region
                  translate(
                  final x10.
                    array.
                    Point p){
        
//#line 49
return this;
    }
    
    
//#line 50
public x10.
                  array.
                  FullRegion
                  eliminate(
                  final int i){
        
//#line 50
return new x10.
          array.
          FullRegion(((((int)(rank))) - (((int)(1)))));
    }
    
    
//#line 51
public x10.
                  array.
                  Region
                  computeBoundingBox(
                  ){
        
//#line 51
return this;
    }
    
    
//#line 52
public boolean
                  contains(
                  final x10.
                    array.
                    Region that){
        
//#line 52
return true;
    }
    
    
//#line 53
public boolean
                  contains(
                  final x10.
                    array.
                    Point p){
        
//#line 53
return true;
    }
    
    
//#line 54
public java.lang.String
                  toString(
                  ){
        
//#line 54
return (((("full(") + (((java.lang.Integer)(rank))))) + (")"));
    }
    
    
//#line 57
public x10.core.Iterator<x10.
                  array.
                  Region.
                  Scanner>
                  scanners(
                  ){
        
//#line 58
throw new x10.
          lang.
          IllegalOperationException("Full Region is infinite: scanning is not supported");
    }
    
    
//#line 61
public x10.core.Iterator<x10.
                  array.
                  Point>
                  iterator(
                  ){
        
//#line 62
throw new x10.
          lang.
          IllegalOperationException("Full Region is infinite: iteration is not supported");
    }

}
