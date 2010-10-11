package x10.array;

final public class RectRegion
extends x10.
  array.
  Region
{public static final x10.rtt.RuntimeType<RectRegion> _RTT = new x10.rtt.RuntimeType<RectRegion>(
/* base class */RectRegion.class
, /* parents */ new x10.rtt.Type[] {x10.array.Region._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 20
final public int
      size;
    
//#line 21
final public x10.core.ValRail<java.lang.Integer>
      mins;
    
//#line 22
final public x10.core.ValRail<java.lang.Integer>
      maxs;
    
//#line 28
final public int
      min0;
    
//#line 29
final public int
      min1;
    
//#line 30
final public int
      min2;
    
//#line 31
final public int
      min3;
    
//#line 32
final public int
      max0;
    
//#line 33
final public int
      max1;
    
//#line 34
final public int
      max2;
    
//#line 35
final public int
      max3;
    
    
//#line 37
private static boolean
                  allZeros(
                  final x10.core.ValRail<java.lang.Integer> x){
        
//#line 38
for (
//#line 38
final x10.core.Iterator<java.lang.Integer> i1701 =
                           (x).iterator();
                         i1701.hasNext();
                         ) {
            
//#line 38
final int i =
              ((java.lang.Integer)(i1701.next$G()));
            
//#line 38
if (((int) i) !=
                            ((int) 0)) {
                
//#line 38
return false;
            }
        }
        
//#line 39
return true;
    }
    
    public static boolean
      allZeros$P(
      final x10.core.ValRail<java.lang.Integer> x){
        return RectRegion.allZeros(((x10.core.ValRail)(x)));
    }
    
    
//#line 42
public RectRegion(final x10.core.ValRail<java.lang.Integer> minArg,
                                  final x10.core.ValRail<java.lang.Integer> maxArg) {
        
//#line 43
super(minArg.
                            length,
                          true,
                          x10.
                            array.
                            RectRegion.allZeros(((x10.core.ValRail)(minArg))));
        
//#line 45
if (((int) minArg.
                                 length) !=
                        ((int) maxArg.
                                 length)) {
            
//#line 46
throw new x10.
              lang.
              IllegalOperationException("min and max must have same length");
        }
        
//#line 48
int s =
          1;
        {
            
//#line 49
final int[] maxArg$value1983 =
              ((int[])maxArg.value);
            
//#line 49
final int[] minArg$value1984 =
              ((int[])minArg.value);
            
//#line 49
for (
//#line 49
int i =
                               0;
                             ((((int)(i))) < (((int)(minArg.
                                                       length))));
                             
//#line 49
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 50
int rs =
                  ((((int)(((((int)(((int)maxArg$value1983[i])))) - (((int)(((int)minArg$value1984[i])))))))) + (((int)(1))));
                
//#line 51
if (((((int)(rs))) < (((int)(0))))) {
                    
//#line 51
rs = 0;
                }
                
//#line 52
s = ((((int)(s))) * (((int)(rs))));
            }
        }
        
//#line 54
this.size = s;
        
//#line 56
this.mins = minArg;
        
//#line 57
this.maxs = maxArg;
        
//#line 59
if (((((int)(minArg.
                                   length))) > (((int)(0))))) {
            
//#line 60
this.min0 = ((int[])minArg.value)[0];
            
//#line 61
this.max0 = ((int[])maxArg.value)[0];
        } else {
            
//#line 63
this.min0 = this.max0 = 0;
        }
        
//#line 66
if (((((int)(minArg.
                                   length))) > (((int)(1))))) {
            
//#line 67
this.min1 = ((int[])minArg.value)[1];
            
//#line 68
this.max1 = ((int[])maxArg.value)[1];
        } else {
            
//#line 70
this.min1 = this.max1 = 0;
        }
        
//#line 73
if (((((int)(minArg.
                                   length))) > (((int)(2))))) {
            
//#line 74
this.min2 = ((int[])minArg.value)[2];
            
//#line 75
this.max2 = ((int[])maxArg.value)[2];
        } else {
            
//#line 77
this.min2 = this.max2 = 0;
        }
        
//#line 80
if (((((int)(minArg.
                                   length))) > (((int)(3))))) {
            
//#line 81
this.min3 = ((int[])minArg.value)[3];
            
//#line 82
this.max3 = ((int[])maxArg.value)[3];
        } else {
            
//#line 84
this.min3 = this.max3 = 0;
        }
    }
    
    
//#line 88
public RectRegion(final int min,
                                  final int max) {
        
//#line 89
this(((x10.core.ValRail)
                           x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {min})),
                         x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {max}));
    }
    
    
//#line 92
public int
                  size(
                  ){
        
//#line 92
return size;
    }
    
    
//#line 94
public boolean
                  isConvex(
                  ){
        
//#line 94
return true;
    }
    
    
//#line 96
public boolean
                  isEmpty(
                  ){
        
//#line 96
return ((int) size) ==
        ((int) 0);
    }
    
    
//#line 103
public x10.
                   array.
                   Region
                   computeBoundingBox(
                   ){
        
//#line 103
return this;
    }
    
    
//#line 105
public x10.core.ValRail<java.lang.Integer>
                   min(
                   ){
        
//#line 105
return mins;
    }
    
    
//#line 106
public x10.core.ValRail<java.lang.Integer>
                   max(
                   ){
        
//#line 106
return maxs;
    }
    
    
//#line 108
public boolean
                   contains(
                   final x10.
                     array.
                     Region that){
        
//#line 109
if (x10.array.RectRegion._RTT.instanceof$(that)) {
            
//#line 110
final x10.core.ValRail<java.lang.Integer> thatMin =
              ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                     array.
                                     RectRegion cast(final x10.
                                     array.
                                     RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                     array.
                                     RectRegion) that))).min()));
            
//#line 111
final x10.core.ValRail<java.lang.Integer> thatMax =
              ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                     array.
                                     RectRegion cast(final x10.
                                     array.
                                     RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                     array.
                                     RectRegion) that))).max()));
            {
                
//#line 112
final int[] x10$array$RectRegion$this$mins$value1985 =
                  ((int[])mins.value);
                
//#line 112
final int[] thatMin$value1986 =
                  ((int[])thatMin.value);
                
//#line 112
final int[] x10$array$RectRegion$this$maxs$value1987 =
                  ((int[])maxs.value);
                
//#line 112
final int[] thatMax$value1988 =
                  ((int[])thatMax.value);
                
//#line 112
for (
//#line 112
int i =
                                    0;
                                  ((((int)(i))) < (((int)(rank))));
                                  
//#line 112
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 113
if (((((int)(((int)x10$array$RectRegion$this$mins$value1985[i])))) > (((int)(((int)thatMin$value1986[i])))))) {
                        
//#line 113
return false;
                    }
                    
//#line 114
if (((((int)(((int)x10$array$RectRegion$this$maxs$value1987[i])))) < (((int)(((int)thatMax$value1988[i])))))) {
                        
//#line 114
return false;
                    }
                }
            }
            
//#line 116
return true;
        } else {
            
//#line 118
return this.contains(((x10.
                                                array.
                                                Region)(that.computeBoundingBox())));
        }
    }
    
    
//#line 122
public boolean
                   contains(
                   final x10.
                     array.
                     Point p){
        
//#line 123
if (((int) p.
                                  rank) !=
                         ((int) rank)) {
            
//#line 123
return false;
        }
        {
            
//#line 124
final int r1702min1703 =
              0;
            
//#line 124
final int r1702max1704 =
              ((((int)(p.
                         rank))) - (((int)(1))));
            {
                
//#line 124
final int[] x10$array$RectRegion$this$mins$value1989 =
                  ((int[])mins.value);
                
//#line 124
final int[] x10$array$RectRegion$this$maxs$value1990 =
                  ((int[])maxs.value);
                
//#line 124
for (
//#line 124
int r1702 =
                                    r1702min1703;
                                  ((((int)(r1702))) <= (((int)(r1702max1704))));
                                  
//#line 124
r1702 = ((((int)(r1702))) + (((int)(1))))) {
                    
//#line 124
final int r =
                      r1702;
                    {
                        
//#line 125
if (((((int)(p.apply((int)(r))))) < (((int)(((int)x10$array$RectRegion$this$mins$value1989[r]))))) ||
                                         ((((int)(p.apply((int)(r))))) > (((int)(((int)x10$array$RectRegion$this$maxs$value1990[r])))))) {
                            
//#line 125
return false;
                        }
                    }
                }
            }
        }
        
//#line 127
return true;
    }
    
    
//#line 130
public boolean
                   contains(
                   final int i0){
        
//#line 131
return ((((int)(i0))) >= (((int)(min0)))) &&
        ((((int)(i0))) <= (((int)(max0))));
    }
    
    
//#line 134
public boolean
                   contains(
                   final int i0,
                   final int i1){
        
//#line 135
if (zeroBased) {
            
//#line 136
return ((x10.
                                    lang.
                                    UInt.$le((x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(i0)))),
                                             (x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(max0))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i1)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max1)))))));
        } else {
            
//#line 139
return ((((int)(i0))) >= (((int)(min0)))) &&
            ((((int)(i0))) <= (((int)(max0)))) &&
            ((((int)(i1))) >= (((int)(min1)))) &&
            ((((int)(i1))) <= (((int)(max1))));
        }
    }
    
    
//#line 144
public boolean
                   contains(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 145
if (zeroBased) {
            
//#line 146
return ((x10.
                                    lang.
                                    UInt.$le((x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(i0)))),
                                             (x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(max0))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i1)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max1))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i2)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max2)))))));
        } else {
            
//#line 150
return ((((int)(i0))) >= (((int)(min0)))) &&
            ((((int)(i0))) <= (((int)(max0)))) &&
            ((((int)(i1))) >= (((int)(min1)))) &&
            ((((int)(i1))) <= (((int)(max1)))) &&
            ((((int)(i2))) >= (((int)(min2)))) &&
            ((((int)(i2))) <= (((int)(max2))));
        }
    }
    
    
//#line 156
public boolean
                   contains(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 157
if (zeroBased) {
            
//#line 158
return ((x10.
                                    lang.
                                    UInt.$le((x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(i0)))),
                                             (x10.
                                               lang.
                                               UInt)((x10.
                                                        lang.
                                                        UInt.$implicit_convert((int)(max0))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i1)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max1))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i2)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max2))))))) &&
            ((x10.
                lang.
                UInt.$le((x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(i3)))),
                         (x10.
                           lang.
                           UInt)((x10.
                                    lang.
                                    UInt.$implicit_convert((int)(max3)))))));
        } else {
            
//#line 163
return ((((int)(i0))) >= (((int)(min0)))) &&
            ((((int)(i0))) <= (((int)(max0)))) &&
            ((((int)(i1))) >= (((int)(min1)))) &&
            ((((int)(i1))) <= (((int)(max1)))) &&
            ((((int)(i2))) >= (((int)(min2)))) &&
            ((((int)(i2))) <= (((int)(max2)))) &&
            ((((int)(i3))) >= (((int)(min3)))) &&
            ((((int)(i3))) <= (((int)(max3))));
        }
    }
    
    
//#line 171
public x10.
                   array.
                   Region
                   intersection(
                   final x10.
                     array.
                     Region that){
        
//#line 172
if (that.isEmpty()) {
            
//#line 173
return that;
        } else {
            
//#line 174
if (x10.array.FullRegion._RTT.instanceof$(that)) {
                
//#line 175
return this;
            } else {
                
//#line 176
if (x10.array.RectRegion._RTT.instanceof$(that)) {
                    
//#line 177
final x10.core.ValRail<java.lang.Integer> thatMin =
                      ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                             array.
                                             RectRegion cast(final x10.
                                             array.
                                             RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             array.
                                             RectRegion) that))).min()));
                    
//#line 178
final x10.core.ValRail<java.lang.Integer> thatMax =
                      ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                             array.
                                             RectRegion cast(final x10.
                                             array.
                                             RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             array.
                                             RectRegion) that))).max()));
                    
//#line 179
final x10.core.ValRail<java.lang.Integer> newMin =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = x10.
                      lang.
                      Math.max((int)(x10.
                                 array.
                                 RectRegion.this.min((int)(i))),
                               (int)(((int[])thatMin.value)[i]));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank))));
                    
//#line 180
final x10.core.ValRail<java.lang.Integer> newMax =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = x10.
                      lang.
                      Math.min((int)(x10.
                                 array.
                                 RectRegion.this.max((int)(i))),
                               (int)(((int[])thatMax.value)[i]));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank))));
                    {
                        
//#line 181
final int i1705min1706 =
                          0;
                        
//#line 181
final int i1705max1707 =
                          ((((int)(newMin.
                                     length))) - (((int)(1))));
                        {
                            
//#line 181
final int[] newMax$value1991 =
                              ((int[])newMax.value);
                            
//#line 181
final int[] newMin$value1992 =
                              ((int[])newMin.value);
                            
//#line 181
for (
//#line 181
int i1705 =
                                                i1705min1706;
                                              ((((int)(i1705))) <= (((int)(i1705max1707))));
                                              
//#line 181
i1705 = ((((int)(i1705))) + (((int)(1))))) {
                                
//#line 181
final int i =
                                  i1705;
                                {
                                    
//#line 182
if (((((int)(((int)newMax$value1991[i])))) < (((int)(((int)newMin$value1992[i])))))) {
                                        
//#line 182
return x10.
                                          array.
                                          Region.makeEmpty((int)(rank));
                                    }
                                }
                            }
                        }
                    }
                    
//#line 184
return new x10.
                      array.
                      RectRegion(newMin,
                                 newMax);
                } else {
                    
//#line 186
throw new java.lang.UnsupportedOperationException((("haven\'t implemented RectRegion intersection with ") + (x10.core.Ref.typeName(that))));
                }
            }
        }
    }
    
    
//#line 191
public x10.
                   array.
                   Region
                   product(
                   final x10.
                     array.
                     Region that){
        
//#line 192
if (that.isEmpty()) {
            
//#line 193
return x10.
              array.
              Region.makeEmpty((int)(((((int)(rank))) + (((int)(that.
                                                                  rank))))));
        } else {
            
//#line 194
if (x10.array.RectRegion._RTT.instanceof$(that)) {
                
//#line 195
final x10.core.ValRail<java.lang.Integer> thatMin =
                  ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                         array.
                                         RectRegion cast(final x10.
                                         array.
                                         RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         array.
                                         RectRegion) that))).min()));
                
//#line 196
final x10.core.ValRail<java.lang.Integer> thatMax =
                  ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                         array.
                                         RectRegion cast(final x10.
                                         array.
                                         RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         array.
                                         RectRegion) that))).max()));
                
//#line 197
final int k =
                  ((((int)(rank))) + (((int)(that.
                                               rank))));
                
//#line 198
final x10.core.ValRail<java.lang.Integer> newMin =
                  ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                  ? x10.
                  array.
                  RectRegion.this.min((int)(i))
                  : ((int[])thatMin.value)[((((int)(i))) - (((int)(rank))))];}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
                
//#line 199
final x10.core.ValRail<java.lang.Integer> newMax =
                  ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                  ? x10.
                  array.
                  RectRegion.this.max((int)(i))
                  : ((int[])thatMax.value)[((((int)(i))) - (((int)(rank))))];}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
                
//#line 200
return new x10.
                  array.
                  RectRegion(newMin,
                             newMax);
            } else {
                
//#line 201
if (x10.array.FullRegion._RTT.instanceof$(that)) {
                    
//#line 202
final int k =
                      ((((int)(rank))) + (((int)(that.
                                                   rank))));
                    
//#line 203
final x10.core.ValRail<java.lang.Integer> newMin =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                      ? x10.
                      array.
                      RectRegion.this.min((int)(i))
                      : java.lang.Integer.MIN_VALUE;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
                    
//#line 204
final x10.core.ValRail<java.lang.Integer> newMax =
                      ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(rank))))
                      ? x10.
                      array.
                      RectRegion.this.max((int)(i))
                      : java.lang.Integer.MAX_VALUE;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
                    
//#line 205
return new x10.
                      array.
                      RectRegion(newMin,
                                 newMax);
                } else {
                    
//#line 207
throw new java.lang.UnsupportedOperationException((("haven\'t implemented RectRegion product with ") + (x10.core.Ref.typeName(that))));
                }
            }
        }
    }
    
    
//#line 211
public x10.
                   array.
                   Region
                   translate(
                   final x10.
                     array.
                     Point v){
        
//#line 212
final x10.core.ValRail<java.lang.Integer> newMin =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(x10.
          array.
          RectRegion.this.min((int)(i))))) + (((int)(v.apply((int)(i))))));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank))));
        
//#line 213
final x10.core.ValRail<java.lang.Integer> newMax =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(x10.
          array.
          RectRegion.this.max((int)(i))))) + (((int)(v.apply((int)(i))))));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank))));
        
//#line 214
return new x10.
          array.
          RectRegion(newMin,
                     newMax);
    }
    
    
//#line 217
public x10.
                   array.
                   Region
                   projection(
                   final int axis){
        
//#line 218
return new x10.
          array.
          RectRegion(x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {this.min((int)(axis))}),
                     x10.core.RailFactory.<java.lang.Integer>makeValRailFromJavaArray(x10.rtt.Types.INT, new int[] {this.max((int)(axis))}));
    }
    
    
//#line 221
public x10.
                   array.
                   Region
                   eliminate(
                   final int axis){
        
//#line 222
final int k =
          ((((int)(rank))) - (((int)(1))));
        
//#line 223
final x10.core.ValRail<java.lang.Integer> newMin =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(axis))))
          ? x10.
          array.
          RectRegion.this.min((int)(i))
          : x10.
          array.
          RectRegion.this.min((int)(((((int)(i))) + (((int)(i))))));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
        
//#line 224
final x10.core.ValRail<java.lang.Integer> newMax =
          ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = ((((int)(i))) < (((int)(axis))))
          ? x10.
          array.
          RectRegion.this.max((int)(i))
          : x10.
          array.
          RectRegion.this.max((int)(((((int)(i))) + (((int)(i))))));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, k, array);}}.apply(k))));
        
//#line 225
return new x10.
          array.
          RectRegion(newMin,
                     newMax);
    }
    
    
//#line 229
public static class RRIterator
                 extends x10.core.Ref
                   implements x10.core.Iterator<x10.
                                array.
                                Point>
                 {public static final x10.rtt.RuntimeType<RRIterator> _RTT = new x10.rtt.RuntimeType<RRIterator>(
    /* base class */RRIterator.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public x10.lang.Iterator.next(): T
    public x10.
      array.
      Point
      next$G(){return next();}
    
        
//#line 229
final public int
          myRank;
        
        
//#line 230
final public x10.core.ValRail<java.lang.Integer>
          min;
        
//#line 231
final public x10.core.ValRail<java.lang.Integer>
          max;
        
//#line 232
public boolean
          done;
        
//#line 233
final public x10.core.Rail<java.lang.Integer>
          cur;
        
        
//#line 235
public RRIterator(final x10.
                                         array.
                                         RectRegion rr) {
            super();
            
//#line 232
this.done = false;
            
//#line 236
this.myRank = rr.
                                         rank;
            
//#line 237
this.min = ((x10.core.ValRail)(new x10.core.fun.Fun_0_1<x10.core.ValRail<java.lang.Integer>, x10.core.ValRail<java.lang.Integer>>() {public final x10.core.ValRail<java.lang.Integer> apply$G(final x10.core.ValRail<java.lang.Integer> __desugarer__var__29__) { return apply(__desugarer__var__29__);}
            public final x10.core.ValRail<java.lang.Integer> apply(final x10.core.ValRail<java.lang.Integer> __desugarer__var__29__) { {
                
//#line 237
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__29__,null)) &&
                                   !(((int) __desugarer__var__29__.
                                              length) ==
                                     ((int) x10.
                                              array.
                                              RectRegion.
                                              RRIterator.this.
                                              myRank))) {
                    
//#line 237
throw new java.lang.ClassCastException(("x10.lang.ValRail[x10.lang.Int]{self.length==x10.array.RectRe" +
                                                                         "gion.RRIterator#this.myRank}"));
                }
                
//#line 237
return __desugarer__var__29__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.rtt.Types.INT);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.rtt.Types.INT);return null;
            }
            }.apply(((x10.core.ValRail)
                      rr.
                        mins))));
            
//#line 238
this.max = ((x10.core.ValRail)(new x10.core.fun.Fun_0_1<x10.core.ValRail<java.lang.Integer>, x10.core.ValRail<java.lang.Integer>>() {public final x10.core.ValRail<java.lang.Integer> apply$G(final x10.core.ValRail<java.lang.Integer> __desugarer__var__30__) { return apply(__desugarer__var__30__);}
            public final x10.core.ValRail<java.lang.Integer> apply(final x10.core.ValRail<java.lang.Integer> __desugarer__var__30__) { {
                
//#line 238
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__30__,null)) &&
                                   !(((int) __desugarer__var__30__.
                                              length) ==
                                     ((int) x10.
                                              array.
                                              RectRegion.
                                              RRIterator.this.
                                              myRank))) {
                    
//#line 238
throw new java.lang.ClassCastException(("x10.lang.ValRail[x10.lang.Int]{self.length==x10.array.RectRe" +
                                                                         "gion.RRIterator#this.myRank}"));
                }
                
//#line 238
return __desugarer__var__30__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.rtt.Types.INT);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.ValRail._RTT, x10.rtt.Types.INT);return null;
            }
            }.apply(((x10.core.ValRail)
                      rr.
                        maxs))));
            
//#line 239
this.done = ((int) rr.
                                              size) ==
            ((int) 0);
            
//#line 240
this.cur = ((x10.core.Rail)(new x10.core.fun.Fun_0_1<x10.core.Rail<java.lang.Integer>, x10.core.Rail<java.lang.Integer>>() {public final x10.core.Rail<java.lang.Integer> apply$G(final x10.core.Rail<java.lang.Integer> __desugarer__var__31__) { return apply(__desugarer__var__31__);}
            public final x10.core.Rail<java.lang.Integer> apply(final x10.core.Rail<java.lang.Integer> __desugarer__var__31__) { {
                
//#line 240
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__31__,null)) &&
                                   !(x10.rtt.Equality.equalsequals(((x10.
                                       lang.
                                       Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__31__)))),x10.
                                       lang.
                                       Runtime.here()) &&
                                     ((int) __desugarer__var__31__.
                                              length) ==
                                     ((int) x10.
                                              array.
                                              RectRegion.
                                              RRIterator.this.
                                              myRank))) {
                    
//#line 240
throw new java.lang.ClassCastException(("x10.lang.Rail[x10.lang.Int]{self.home==here, self.length==x1" +
                                                                         "0.array.RectRegion.RRIterator#this.myRank}"));
                }
                
//#line 240
return __desugarer__var__31__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.INT);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.INT);return null;
            }
            }.apply(((x10.core.Rail)
                      (x10.core.RailFactory.<java.lang.Integer>makeRailFromValRail(x10.rtt.Types.INT, rr.
                                                                                                        mins))))));
        }
        
        
//#line 243
public boolean
                       hasNext(
                       ){
            
//#line 243
return (!(((boolean)(done))));
        }
        
        
//#line 245
public x10.
                       array.
                       Point
                       next(
                       ){
            
//#line 246
final x10.
              array.
              Point ans =
              ((x10.
              array.
              Point)(x10.
              array.
              Point.make(((x10.core.Rail)(cur)))));
            
//#line 247
if (((((int)(((int[])cur.value)[((((int)(myRank))) - (((int)(1))))]))) < (((int)(((int[])max.value)[((((int)(myRank))) - (((int)(1))))]))))) {
                
//#line 248
((int[])cur.value)[((((int)(myRank))) - (((int)(1))))] += 1;
            } else {
                
//#line 250
if (((int) myRank) ==
                                 ((int) 1)) {
                    
//#line 251
this.done = true;
                } else {
                    
//#line 254
((int[])cur.value)[((((int)(myRank))) - (((int)(1))))] = ((int[])min.value)[((((int)(myRank))) - (((int)(1))))];
                    
//#line 255
((int[])cur.value)[((((int)(myRank))) - (((int)(2))))] += 1;
                    
//#line 256
int carryRank =
                      ((((int)(myRank))) - (((int)(2))));
                    {
                        
//#line 257
final int[] x10$array$RectRegion$RRIterator$this$min$value1993 =
                          ((int[])min.value);
                        
//#line 257
final int[] x10$array$RectRegion$RRIterator$this$cur$value1994 =
                          ((int[])cur.value);
                        
//#line 257
while (((((int)(carryRank))) > (((int)(0)))) &&
                                            ((((int)(((int[])cur.value)[carryRank]))) > (((int)(((int[])max.value)[carryRank]))))) {
                            
//#line 258
x10$array$RectRegion$RRIterator$this$cur$value1994[carryRank]=((int)x10$array$RectRegion$RRIterator$this$min$value1993[carryRank]);
                            
//#line 259
x10$array$RectRegion$RRIterator$this$cur$value1994[((((int)(carryRank))) - (((int)(1))))]+=1;
                            
//#line 260
carryRank = ((((int)(carryRank))) - (((int)(1))));
                        }
                    }
                    
//#line 262
if (((int) carryRank) ==
                                     ((int) 0) &&
                                     ((((int)(((int[])cur.value)[0]))) > (((int)(((int[])max.value)[0]))))) {
                        
//#line 263
this.done = true;
                    }
                }
            }
            
//#line 267
return ans;
        }
        
        
//#line 229
final public int
                       myRank(
                       ){
            
//#line 229
return this.
                                  myRank;
        }
    
    }
    
    
    
//#line 270
public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   ){
        
//#line 271
return new x10.
          array.
          RectRegion.
          RRIterator(this);
    }
    
    
//#line 275
public boolean
                   equals(
                   final java.lang.Object thatObj){
        
//#line 276
if (x10.rtt.Equality.equalsequals(this,thatObj)) {
            
//#line 276
return true;
        }
        
//#line 277
if ((!(((boolean)((x10.array.Region._RTT.instanceof$(thatObj))))))) {
            
//#line 277
return false;
        }
        
//#line 278
final x10.
          array.
          Region that =
          (new java.lang.Object() {final x10.
          array.
          Region cast(final x10.
          array.
          Region self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.Region._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          array.
          Region) thatObj));
        
//#line 281
if ((!(((boolean)((x10.array.RectRegion._RTT.instanceof$(that))))))) {
            
//#line 282
return super.equals(((java.lang.Object)(that)));
        }
        
//#line 285
if (((int) this.
                                  rank) !=
                         ((int) that.
                                  rank)) {
            
//#line 286
return false;
        }
        
//#line 289
final x10.core.ValRail<java.lang.Integer> thisMin =
          ((x10.core.ValRail)(this.min()));
        
//#line 290
final x10.core.ValRail<java.lang.Integer> thisMax =
          ((x10.core.ValRail)(this.max()));
        
//#line 291
final x10.core.ValRail<java.lang.Integer> thatMin =
          ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                 array.
                                 RectRegion cast(final x10.
                                 array.
                                 RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                 array.
                                 RectRegion) that))).min()));
        
//#line 292
final x10.core.ValRail<java.lang.Integer> thatMax =
          ((x10.core.ValRail)(((new java.lang.Object() {final x10.
                                 array.
                                 RectRegion cast(final x10.
                                 array.
                                 RectRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.RectRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                 array.
                                 RectRegion) that))).max()));
        {
            
//#line 295
final int[] thisMin$value1995 =
              ((int[])thisMin.value);
            
//#line 295
final int[] thatMin$value1996 =
              ((int[])thatMin.value);
            
//#line 295
final int[] thisMax$value1997 =
              ((int[])thisMax.value);
            
//#line 295
final int[] thatMax$value1998 =
              ((int[])thatMax.value);
            
//#line 295
for (
//#line 295
int i =
                                0;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 295
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 296
if (((int) ((int)thisMin$value1995[i])) !=
                                 ((int) ((int)thatMin$value1996[i])) ||
                                 ((int) ((int)thisMax$value1997[i])) !=
                                 ((int) ((int)thatMax$value1998[i]))) {
                    
//#line 297
return false;
                }
            }
        }
        
//#line 299
return true;
    }
    
    
//#line 307
public java.lang.String
                   toString(
                   ){
        
//#line 308
final x10.core.ValRail<java.lang.Integer> thisMin =
          ((x10.core.ValRail)(this.min()));
        
//#line 309
final x10.core.ValRail<java.lang.Integer> thisMax =
          ((x10.core.ValRail)(this.max()));
        
//#line 310
java.lang.String s =
          "[";
        {
            
//#line 311
final int[] thisMin$value1999 =
              ((int[])thisMin.value);
            
//#line 311
final int[] thisMax$value2000 =
              ((int[])thisMax.value);
            
//#line 311
for (
//#line 311
int i =
                                0;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 311
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 312
if (((((int)(i))) > (((int)(0))))) {
                    
//#line 312
s = ((s) + (","));
                }
                
//#line 313
s = ((s) + (((((((java.lang.Integer)(((int)thisMin$value1999[i])))) + (".."))) + (((java.lang.Integer)(((int)thisMax$value2000[i])))))));
            }
        }
        
//#line 315
s = ((s) + ("]"));
        
//#line 316
return s;
    }
    
    
//#line 320
public x10.core.Iterator<x10.
                   array.
                   Region.
                   Scanner>
                   scanners(
                   ){
        
//#line 321
throw new java.lang.UnsupportedOperationException("TODO: scanners not defined for RectRegion");
    }
    
    final public boolean
      x10$array$RectRegion$equals$S(
      final java.lang.Object a0){
        return super.equals(((java.lang.Object)(a0)));
    }

}
