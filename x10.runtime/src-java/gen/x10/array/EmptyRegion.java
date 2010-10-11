package x10.array;

final public class EmptyRegion
extends x10.
  array.
  Region
{public static final x10.rtt.RuntimeType<EmptyRegion> _RTT = new x10.rtt.RuntimeType<EmptyRegion>(
/* base class */EmptyRegion.class
, /* parents */ new x10.rtt.Type[] {x10.array.Region._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 19
public EmptyRegion(final int rank) {
        
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
return true;
    }
    
    
//#line 26
public int
                  size(
                  ){
        
//#line 26
return 0;
    }
    
    
//#line 27
public x10.
                  array.
                  Region
                  intersection(
                  final x10.
                    array.
                    Region that){
        
//#line 27
return this;
    }
    
    
//#line 28
public x10.
                  array.
                  Region
                  product(
                  final x10.
                    array.
                    Region that){
        
//#line 29
return new x10.
          array.
          EmptyRegion(((((int)(this.
                                 rank))) + (((int)(that.
                                                     rank)))));
    }
    
    
//#line 30
public x10.
                  array.
                  Region
                  projection(
                  final int axis){
        
//#line 30
return new x10.
          array.
          EmptyRegion(1);
    }
    
    
//#line 31
public x10.
                  array.
                  Region
                  translate(
                  final x10.
                    array.
                    Point p){
        
//#line 31
return this;
    }
    
    
//#line 32
public x10.
                  array.
                  EmptyRegion
                  eliminate(
                  final int i){
        
//#line 32
return new x10.
          array.
          EmptyRegion(((((int)(rank))) - (((int)(1)))));
    }
    
    
//#line 33
public x10.
                  array.
                  Region
                  computeBoundingBox(
                  ){
        
//#line 34
throw new x10.
          lang.
          IllegalOperationException("bounding box not not defined for empty region");
    }
    
    
//#line 36
public x10.core.ValRail<java.lang.Integer>
                  min(
                  ){
        
//#line 37
throw new x10.
          lang.
          IllegalOperationException("min not not defined for empty region");
    }
    
    
//#line 39
public x10.core.ValRail<java.lang.Integer>
                  max(
                  ){
        
//#line 40
throw new x10.
          lang.
          IllegalOperationException("max not not defined for empty region");
    }
    
    
//#line 42
public boolean
                  contains(
                  final x10.
                    array.
                    Region that){
        
//#line 42
return that.isEmpty();
    }
    
    
//#line 43
public boolean
                  contains(
                  final x10.
                    array.
                    Point p){
        
//#line 43
return false;
    }
    
    
//#line 45
public static class ERIterator
                extends x10.core.Ref
                  implements x10.core.Iterator<x10.
                               array.
                               Point>
                {public static final x10.rtt.RuntimeType<ERIterator> _RTT = new x10.rtt.RuntimeType<ERIterator>(
    /* base class */ERIterator.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public x10.lang.Iterator.next(): T
    public x10.
      array.
      Point
      next$G(){return next();}
    
        
//#line 45
final public int
          myRank;
        
        
        
//#line 46
public ERIterator(final int r) {
            super();
            
//#line 46
this.myRank = r;
        }
        
        
//#line 47
public boolean
                      hasNext(
                      ){
            
//#line 47
return false;
        }
        
        
//#line 48
public x10.
                      array.
                      Point
                      next(
                      ){
            
//#line 49
throw new x10.
              util.
              NoSuchElementException();
        }
        
        
//#line 45
final public int
                      myRank(
                      ){
            
//#line 45
return this.
                                 myRank;
        }
    
    }
    
    
    
//#line 52
public x10.core.Iterator<x10.
                  array.
                  Point>
                  iterator(
                  ){
        
//#line 53
return new x10.
          array.
          EmptyRegion.
          ERIterator(rank);
    }
    
    
//#line 56
public x10.core.Iterator<x10.
                  array.
                  Region.
                  Scanner>
                  scanners(
                  ){
        
//#line 57
throw new java.lang.UnsupportedOperationException("scanners not defined for empty region");
    }
    
    
//#line 60
public java.lang.String
                  toString(
                  ){
        
//#line 60
return (((("empty(") + (((java.lang.Integer)(rank))))) + (")"));
    }

}
