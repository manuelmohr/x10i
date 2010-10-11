package x10.array;


public class RectLayout
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<RectLayout> _RTT = new x10.rtt.RuntimeType<RectLayout>(
/* base class */RectLayout.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 22
final public int
      rank;
    
    
//#line 24
final public int
      size;
    
//#line 26
final public x10.core.ValRail<java.lang.Integer>
      min;
    
//#line 27
final public int
      min0;
    
//#line 28
final public int
      min1;
    
//#line 29
final public int
      min2;
    
//#line 30
final public int
      min3;
    
//#line 32
final public x10.core.ValRail<java.lang.Integer>
      delta;
    
//#line 33
final public int
      delta0;
    
//#line 34
final public int
      delta1;
    
//#line 35
final public int
      delta2;
    
//#line 36
final public int
      delta3;
    
    
//#line 38
public RectLayout(final x10.core.ValRail<java.lang.Integer> min,
                                  final x10.core.ValRail<java.lang.Integer> max) {
        
//#line 40
if (((int) max.
                                 length) !=
                        ((int) min.
                                 length)) {
            
//#line 41
throw new java.lang.IllegalArgumentException("min and max must have same length");
        }
        
//#line 43
final int r =
          min.
            length;
        
//#line 44
this.rank = r;
        
//#line 45
this.min = min;
        
//#line 47
final x10.core.ValRail<java.lang.Integer> d0 =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(((((int)(((int[])max.value)[i]))) - (((int)(((int[])min.value)[i]))))))) + (((int)(1))));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, r, array);}}.apply(r))));
        
//#line 48
this.delta = d0;
        
//#line 50
int size =
          1;
        
//#line 51
for (
//#line 51
final x10.core.Iterator<java.lang.Integer> d1678 =
                           (d0).iterator();
                         d1678.hasNext();
                         ) {
            
//#line 51
final int d =
              ((java.lang.Integer)(d1678.next$G()));
            
//#line 52
size = ((((int)(size))) * (((int)(d))));
        }
        
//#line 53
this.size = size;
        
//#line 55
this.min0 = ((((int)(r))) >= (((int)(1))))
          ? ((int[])min.value)[0]
          : 0;
        
//#line 56
this.min1 = ((((int)(r))) >= (((int)(2))))
          ? ((int[])min.value)[1]
          : 0;
        
//#line 57
this.min2 = ((((int)(r))) >= (((int)(3))))
          ? ((int[])min.value)[2]
          : 0;
        
//#line 58
this.min3 = ((((int)(r))) >= (((int)(4))))
          ? ((int[])min.value)[3]
          : 0;
        
//#line 60
this.delta0 = ((((int)(r))) >= (((int)(1))))
          ? ((int[])d0.value)[0]
          : 0;
        
//#line 61
this.delta1 = ((((int)(r))) >= (((int)(2))))
          ? ((int[])d0.value)[1]
          : 0;
        
//#line 62
this.delta2 = ((((int)(r))) >= (((int)(3))))
          ? ((int[])d0.value)[2]
          : 0;
        
//#line 63
this.delta3 = ((((int)(r))) >= (((int)(4))))
          ? ((int[])d0.value)[3]
          : 0;
    }
    
    
//#line 70
final public int
                  size(
                  ){
        
//#line 71
return size;
    }
    
    
//#line 74
final public int
                  offset(
                  final x10.
                    array.
                    Point pt){
        
//#line 75
int offset =
          ((((int)(pt.apply((int)(0))))) - (((int)(((int[])min.value)[0]))));
        {
            
//#line 76
final int[] x10$array$RectLayout$this$delta$value1979 =
              ((int[])delta.value);
            
//#line 76
final int[] x10$array$RectLayout$this$min$value1980 =
              ((int[])min.value);
            
//#line 76
for (
//#line 76
int i =
                               1;
                             ((((int)(i))) < (((int)(rank))));
                             
//#line 76
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 77
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(((int)x10$array$RectLayout$this$delta$value1979[i])))))))) + (((int)(pt.apply((int)(i))))))))) - (((int)(((int)x10$array$RectLayout$this$min$value1980[i])))));
            }
        }
        
//#line 78
return offset;
    }
    
    
//#line 81
final public int
                  offset(
                  final int i0){
        
//#line 82
int offset =
          ((((int)(i0))) - (((int)(min0))));
        
//#line 83
return offset;
    }
    
    
//#line 86
final public int
                  offset(
                  final int i0,
                  final int i1){
        
//#line 87
int offset =
          ((((int)(i0))) - (((int)(min0))));
        
//#line 88
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta1))))))) + (((int)(i1))))))) - (((int)(min1))));
        
//#line 89
return offset;
    }
    
    
//#line 92
final public int
                  offset(
                  final int i0,
                  final int i1,
                  final int i2){
        
//#line 93
int offset =
          ((((int)(i0))) - (((int)(min0))));
        
//#line 94
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta1))))))) + (((int)(i1))))))) - (((int)(min1))));
        
//#line 95
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta2))))))) + (((int)(i2))))))) - (((int)(min2))));
        
//#line 96
return offset;
    }
    
    
//#line 99
final public int
                  offset(
                  final int i0,
                  final int i1,
                  final int i2,
                  final int i3){
        
//#line 100
int offset =
          ((((int)(i0))) - (((int)(min0))));
        
//#line 101
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta1))))))) + (((int)(i1))))))) - (((int)(min1))));
        
//#line 102
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta2))))))) + (((int)(i2))))))) - (((int)(min2))));
        
//#line 103
offset = ((((int)(((((int)(((((int)(offset))) * (((int)(delta3))))))) + (((int)(i3))))))) - (((int)(min3))));
        
//#line 104
return offset;
    }
    
    
//#line 107
final public java.lang.String
                   toString(
                   ){
        
//#line 108
java.lang.String s =
          "RectLayout[";
        
//#line 109
s = ((s) + ((("size=") + (((java.lang.Integer)(size))))));
        {
            
//#line 110
final int[] x10$array$RectLayout$this$min$value1981 =
              ((int[])min.value);
            
//#line 110
final int[] x10$array$RectLayout$this$delta$value1982 =
              ((int[])delta.value);
            
//#line 110
for (
//#line 110
int i =
                                0;
                              ((((int)(i))) < (((int)(min.
                                                        length))));
                              
//#line 110
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 111
s = ((s) + (((((((",") + (((java.lang.Integer)(((int)x10$array$RectLayout$this$min$value1981[i])))))) + ("/"))) + (((java.lang.Integer)(((int)x10$array$RectLayout$this$delta$value1982[i])))))));
            }
        }
        
//#line 112
s = ((s) + ("]"));
        
//#line 113
return s;
    }
    
    
//#line 22
final public int
                  rank(
                  ){
        
//#line 22
return this.
                             rank;
    }
    
    
//#line 22
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 22
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 22
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 22
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 22
final public int
                  hashCode(
                  ){
        
//#line 22
int result =
          0;
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   rank)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   size)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   min)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   min0)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   min1)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   min2)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   min3)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   delta)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   delta0)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   delta1)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   delta2)).hashCode()))));
        
//#line 22
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(this.
                                                                                                   delta3)).hashCode()))));
        
//#line 22
return result;
    }
    
    
//#line 22
final public boolean
                  equals(
                  java.lang.Object other){
        
//#line 22
if ((!(((boolean)(x10.array.RectLayout._RTT.instanceof$(other)))))) {
            
//#line 22
return false;
        }
        
//#line 22
return this.equals(((x10.
                                         array.
                                         RectLayout)((new java.lang.Object() {final x10.
                                         array.
                                         RectLayout cast(final x10.
                                         array.
                                         RectLayout self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectLayout._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         array.
                                         RectLayout) other)))));
    }
    
    
//#line 22
final public boolean
                  equals(
                  x10.
                    array.
                    RectLayout other){
        
//#line 22
return ((int) this.
                                    rank) ==
        ((int) other.
                 rank) &&
        ((int) this.
                 size) ==
        ((int) other.
                 size) &&
        x10.rtt.Equality.equalsequals(this.
                                        min,other.
                                              min) &&
        ((int) this.
                 min0) ==
        ((int) other.
                 min0) &&
        ((int) this.
                 min1) ==
        ((int) other.
                 min1) &&
        ((int) this.
                 min2) ==
        ((int) other.
                 min2) &&
        ((int) this.
                 min3) ==
        ((int) other.
                 min3) &&
        x10.rtt.Equality.equalsequals(this.
                                        delta,other.
                                                delta) &&
        ((int) this.
                 delta0) ==
        ((int) other.
                 delta0) &&
        ((int) this.
                 delta1) ==
        ((int) other.
                 delta1) &&
        ((int) this.
                 delta2) ==
        ((int) other.
                 delta2) &&
        ((int) this.
                 delta3) ==
        ((int) other.
                 delta3);
    }
    
    
//#line 22
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 22
if ((!(((boolean)(x10.array.RectLayout._RTT.instanceof$(other)))))) {
            
//#line 22
return false;
        }
        
//#line 22
return this._struct_equals(((x10.
                                                 array.
                                                 RectLayout)((new java.lang.Object() {final x10.
                                                 array.
                                                 RectLayout cast(final x10.
                                                 array.
                                                 RectLayout self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectLayout._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 array.
                                                 RectLayout) other)))));
    }
    
    
//#line 22
final public boolean
                  _struct_equals(
                  x10.
                    array.
                    RectLayout other){
        
//#line 22
return ((int) this.
                                    rank) ==
        ((int) other.
                 rank) &&
        ((int) this.
                 size) ==
        ((int) other.
                 size) &&
        x10.rtt.Equality.equalsequals(this.
                                        min,other.
                                              min) &&
        ((int) this.
                 min0) ==
        ((int) other.
                 min0) &&
        ((int) this.
                 min1) ==
        ((int) other.
                 min1) &&
        ((int) this.
                 min2) ==
        ((int) other.
                 min2) &&
        ((int) this.
                 min3) ==
        ((int) other.
                 min3) &&
        x10.rtt.Equality.equalsequals(this.
                                        delta,other.
                                                delta) &&
        ((int) this.
                 delta0) ==
        ((int) other.
                 delta0) &&
        ((int) this.
                 delta1) ==
        ((int) other.
                 delta1) &&
        ((int) this.
                 delta2) ==
        ((int) other.
                 delta2) &&
        ((int) this.
                 delta3) ==
        ((int) other.
                 delta3);
    }

}
