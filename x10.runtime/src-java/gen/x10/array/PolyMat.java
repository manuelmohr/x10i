package x10.array;


public class PolyMat
extends x10.
  array.
  Mat<x10.
  array.
  PolyRow>
{public static final x10.rtt.RuntimeType<PolyMat> _RTT = new x10.rtt.RuntimeType<PolyMat>(
/* base class */PolyMat.class
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.array.Mat._RTT, x10.array.PolyRow._RTT)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}


// bridge for method global public x10.array.Mat.apply(i:x10.lang.Int): T
public x10.
  array.
  PolyRow
  apply(int a1){return super.apply$G( a1);}

    
//#line 26
final public int
      rank;
    
    
    
    
//#line 35
final public boolean
      isSimplified;
    
    
//#line 42
public PolyMat(final int rows,
                               final int cols,
                               final x10.core.fun.Fun_0_2<java.lang.Integer,java.lang.Integer,java.lang.Integer> init,
                               final boolean isSimplified) {
        
//#line 43
super(x10.array.PolyRow._RTT,
                          rows,
                          cols,
                          (new java.lang.Object() {final x10.core.ValRail<x10.
                            array.
                            PolyRow> apply(int length) {x10.
                            array.
                            PolyRow[] array = new x10.
                            array.
                            PolyRow[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = new x10.
                            array.
                            PolyRow(cols,
                                    new x10.core.fun.Fun_0_1<java.lang.Integer, java.lang.Integer>() {public final java.lang.Integer apply$G(final java.lang.Integer j) { return apply((int)j);}
                                    public final int apply(final int j) { {
                                        
//#line 43
return init.apply$G(i,
                                                                        j);
                                    }}
                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return x10.rtt.Types.INT;return null;
                                    }
                                    });}return new x10.core.ValRail<x10.
                            array.
                            PolyRow>(x10.array.PolyRow._RTT, rows, array);}}.apply(rows)));
        
//#line 44
this.rank = ((((int)(cols))) - (((int)(1))));
        
//#line 45
this.isSimplified = isSimplified;
    }
    
    
//#line 57
public x10.
                  array.
                  PolyMat
                  simplifyParallel(
                  ){
        
//#line 59
if (((int) rows) ==
                        ((int) 0)) {
            
//#line 60
return this;
        }
        
//#line 62
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(rank)));
        
//#line 63
x10.
          array.
          PolyRow last =
          null;
        
//#line 64
for (
//#line 64
final x10.core.Iterator<x10.
                           array.
                           PolyRow> next1567 =
                           this.iterator();
                         next1567.hasNext();
                         ) {
            
//#line 64
final x10.
              array.
              PolyRow next =
              next1567.next$G();
            
//#line 65
if ((!x10.rtt.Equality.equalsequals(last,null)) &&
                            (!(((boolean)(next.isParallel(((x10.
                                                            array.
                                                            PolyRow)(((x10.
                                                                       array.
                                                                       PolyRow)
                                                                       last))))))))) {
                
//#line 66
pmb.add(((x10.
                                      array.
                                      Row)(((x10.
                                             array.
                                             PolyRow)
                                             last))));
            }
            
//#line 67
last = next;
        }
        
//#line 69
pmb.add(((x10.
                              array.
                              Row)(last)));
        
//#line 71
return pmb.toSortedPolyMat((boolean)(false));
    }
    
    
//#line 84
public x10.
                  array.
                  PolyMat
                  simplifyAll(
                  ){
        
//#line 86
if (isSimplified) {
            
//#line 87
return this;
        }
        
//#line 89
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(rank)));
        
//#line 90
x10.core.Rail<java.lang.Boolean> removed =
          ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<java.lang.Boolean> apply(int length) {boolean[] array = new boolean[length];for (int id$50$ = 0; id$50$ < length; id$50$++) {final int id$50 = id$50$;array[id$50] = false;}return new x10.core.Rail<java.lang.Boolean>(x10.rtt.Types.BOOLEAN, rows, array);}}.apply(rows))));
        {
            
//#line 92
final boolean[] removed$value1940 =
              ((boolean[])removed.value);
            
//#line 92
for (
//#line 92
int i =
                               0;
                             ((((int)(i))) < (((int)(rows))));
                             
//#line 92
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 93
final x10.
                  array.
                  PolyRow r =
                  this.apply$G((int)(i));
                
//#line 94
final x10.
                  array.
                  PolyMatBuilder trial =
                  ((x10.
                  array.
                  PolyMatBuilder)(new x10.
                  array.
                  PolyMatBuilder(rank)));
                {
                    
//#line 95
for (
//#line 95
int j =
                                       0;
                                     ((((int)(j))) < (((int)(rows))));
                                     
//#line 95
j = ((((int)(j))) + (((int)(1))))) {
                        
//#line 96
if ((!(((boolean)(((boolean)removed$value1940[j])))))) {
                            
//#line 97
trial.add(((x10.
                                                    array.
                                                    Row)(((int) i) ==
                                                  ((int) j)
                                                    ? r.complement()
                                                    : this.apply$G((int)(j)))));
                        }
                    }
                }
                
//#line 98
if ((!(((boolean)(trial.toSortedPolyMat((boolean)(false)).isEmpty()))))) {
                    
//#line 99
pmb.add(((x10.
                                          array.
                                          Row)(r)));
                } else {
                    
//#line 101
removed$value1940[i]=true;
                }
            }
        }
        
//#line 104
return pmb.toSortedPolyMat((boolean)(true));
    }
    
    
//#line 124
public x10.
                   array.
                   PolyMat
                   eliminate(
                   final int k,
                   final boolean simplifyDegenerate){
        
//#line 125
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(rank)));
        
//#line 126
for (
//#line 126
final x10.core.Iterator<x10.
                            array.
                            PolyRow> ir1569 =
                            this.iterator();
                          ir1569.hasNext();
                          ) {
            
//#line 126
final x10.
              array.
              PolyRow ir =
              ir1569.next$G();
            
//#line 127
final int ia =
              ir.apply((int)(k));
            
//#line 128
if (((int) ia) ==
                             ((int) 0)) {
                
//#line 129
pmb.add(((x10.
                                       array.
                                       Row)(ir)));
            } else {
                
//#line 131
for (
//#line 131
final x10.core.Iterator<x10.
                                    array.
                                    PolyRow> jr1568 =
                                    this.iterator();
                                  jr1568.hasNext();
                                  ) {
                    
//#line 131
final x10.
                      array.
                      PolyRow jr =
                      jr1568.next$G();
                    
//#line 132
final int ja =
                      jr.apply((int)(k));
                    
//#line 133
final x10.core.Rail<java.lang.Integer> as_ =
                      ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(((((int)(rank))) + (((int)(1)))))))));
                    
//#line 134
if (((((int)(ia))) > (((int)(0)))) &&
                                     ((((int)(ja))) < (((int)(0))))) {
                        {
                            
//#line 135
final int[] as_$value1941 =
                              ((int[])as_.value);
                            
//#line 135
for (
//#line 135
int l =
                                                0;
                                              ((((int)(l))) <= (((int)(rank))));
                                              
//#line 135
l = ((((int)(l))) + (((int)(1))))) {
                                
//#line 136
as_$value1941[l]=((((int)(((((int)(ia))) * (((int)(jr.apply((int)(l))))))))) - (((int)(((((int)(ja))) * (((int)(ir.apply((int)(l))))))))));
                            }
                        }
                    } else {
                        
//#line 137
if (((((int)(ia))) < (((int)(0)))) &&
                                         ((((int)(ja))) > (((int)(0))))) {
                            {
                                
//#line 138
final int[] as_$value1942 =
                                  ((int[])as_.value);
                                
//#line 138
for (
//#line 138
int l =
                                                    0;
                                                  ((((int)(l))) <= (((int)(rank))));
                                                  
//#line 138
l = ((((int)(l))) + (((int)(1))))) {
                                    
//#line 139
as_$value1942[l]=((((int)(((((int)(ja))) * (((int)(ir.apply((int)(l))))))))) - (((int)(((((int)(ia))) * (((int)(jr.apply((int)(l))))))))));
                                }
                            }
                        }
                    }
                    
//#line 141
final int lim =
                      simplifyDegenerate
                      ? rank
                      : ((((int)(rank))) + (((int)(1))));
                    
//#line 142
boolean degenerate =
                      true;
                    {
                        
//#line 143
final int[] as_$value1943 =
                          ((int[])as_.value);
                        
//#line 143
for (
//#line 143
int l =
                                            0;
                                          ((((int)(l))) < (((int)(lim))));
                                          
//#line 143
l = ((((int)(l))) + (((int)(1))))) {
                            
//#line 144
if (((int) ((int)as_$value1943[l])) !=
                                             ((int) 0)) {
                                
//#line 145
degenerate = false;
                            }
                        }
                    }
                    
//#line 146
if ((!(((boolean)(degenerate))))) {
                        
//#line 147
x10.
                          array.
                          PolyRow r =
                          new x10.
                          array.
                          PolyRow(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, as_));
                        
//#line 148
pmb.add(((x10.
                                               array.
                                               Row)(r)));
                    }
                }
            }
        }
        
//#line 153
return pmb.toSortedPolyMat((boolean)(false)).simplifyParallel();
    }
    
    
//#line 168
public boolean
                   isRect(
                   ){
        
//#line 169
for (
//#line 169
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1570 =
                            this.iterator();
                          r1570.hasNext();
                          ) {
            
//#line 169
final x10.
              array.
              PolyRow r =
              r1570.next$G();
            
//#line 170
if ((!(((boolean)(r.isRect()))))) {
                
//#line 171
return false;
            }
        }
        
//#line 173
return true;
    }
    
    
//#line 176
public int
                   rectMin(
                   final int axis){
        
//#line 178
for (
//#line 178
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1571 =
                            this.iterator();
                          r1571.hasNext();
                          ) {
            
//#line 178
final x10.
              array.
              PolyRow r =
              r1571.next$G();
            
//#line 179
final int a =
              r.apply((int)(axis));
            
//#line 180
if (((((int)(a))) < (((int)(0))))) {
                
//#line 181
return ((((int)((-(((int)(r.apply((int)(this.rank()))))))))) / (((int)(a))));
            }
        }
        
//#line 184
java.lang.String msg =
          (((("axis ") + (((java.lang.Integer)(axis))))) + (" has no minimum"));
        
//#line 185
throw new x10.
          array.
          UnboundedRegionException(msg);
    }
    
    
//#line 188
public int
                   rectMax(
                   final int axis){
        
//#line 190
for (
//#line 190
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1572 =
                            this.iterator();
                          r1572.hasNext();
                          ) {
            
//#line 190
final x10.
              array.
              PolyRow r =
              r1572.next$G();
            
//#line 191
final int a =
              r.apply((int)(axis));
            
//#line 192
if (((((int)(a))) > (((int)(0))))) {
                
//#line 193
return ((((int)((-(((int)(r.apply((int)(this.rank()))))))))) / (((int)(a))));
            }
        }
        
//#line 196
final java.lang.String msg =
          (((("axis ") + (((java.lang.Integer)(axis))))) + (" has no maximum"));
        
//#line 197
throw new x10.
          array.
          UnboundedRegionException(msg);
    }
    
    
//#line 200
public x10.core.ValRail<java.lang.Integer>
                   rectMin(
                   ){
        
//#line 200
return (new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = x10.
          array.
          PolyMat.this.rectMin((int)(i));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank));
    }
    
    
//#line 202
public x10.core.ValRail<java.lang.Integer>
                   rectMax(
                   ){
        
//#line 202
return (new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = x10.
          array.
          PolyMat.this.rectMax((int)(i));}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, rank, array);}}.apply(rank));
    }
    
    
//#line 204
public boolean
                   isZeroBased(
                   ){
        
//#line 205
if ((!(((boolean)(this.isRect()))))) {
            
//#line 206
return false;
        }
        
//#line 207
try {{
            
//#line 208
for (
//#line 208
int i =
                                0;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 208
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 209
if (((int) this.rectMin((int)(i))) !=
                                 ((int) 0)) {
                    
//#line 210
return false;
                }
            }
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof x10.
          array.
          UnboundedRegionException) {
        final x10.
          array.
          UnboundedRegionException e = (x10.
          array.
          UnboundedRegionException) __$generated_wrappedex$__.getCause();
        {
            
//#line 212
return false;
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final x10.
                  array.
                  UnboundedRegionException e) {
            
//#line 212
return false;
        }
        
//#line 214
return true;
    }
    
    
//#line 217
public boolean
                   isBounded(
                   ){
        
//#line 218
try {{
            
//#line 219
for (
//#line 219
int i =
                                0;
                              ((((int)(i))) < (((int)(rank))));
                              
//#line 219
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 220
this.rectMin((int)(i));
                
//#line 221
this.rectMax((int)(i));
            }
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof x10.
          array.
          UnboundedRegionException) {
        final x10.
          array.
          UnboundedRegionException e = (x10.
          array.
          UnboundedRegionException) __$generated_wrappedex$__.getCause();
        {
            
//#line 224
return false;
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final x10.
                  array.
                  UnboundedRegionException e) {
            
//#line 224
return false;
        }
        
//#line 226
return true;
    }
    
    
//#line 236
public boolean
                   isEmpty(
                   ){
        
//#line 238
x10.
          array.
          PolyMat pm =
          this;
        
//#line 239
for (
//#line 239
int i =
                            0;
                          ((((int)(i))) < (((int)(rank))));
                          
//#line 239
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 240
pm = pm.eliminate((int)(i),
                                           (boolean)(false));
        }
        
//#line 243
for (
//#line 243
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1573 =
                            pm.iterator();
                          r1573.hasNext();
                          ) {
            
//#line 243
final x10.
              array.
              PolyRow r =
              r1573.next$G();
            
//#line 244
if (((((int)(r.apply((int)(rank))))) > (((int)(0))))) {
                
//#line 245
return true;
            }
        }
        
//#line 248
return false;
    }
    
    
//#line 256
public x10.
                   array.
                   PolyMat
                   $or(
                   final x10.
                     array.
                     PolyMat that){
        
//#line 257
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(rank)));
        
//#line 258
for (
//#line 258
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1574 =
                            this.iterator();
                          r1574.hasNext();
                          ) {
            
//#line 258
final x10.
              array.
              PolyRow r =
              r1574.next$G();
            
//#line 259
pmb.add(((x10.
                                   array.
                                   Row)(r)));
        }
        
//#line 260
for (
//#line 260
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1575 =
                            that.iterator();
                          r1575.hasNext();
                          ) {
            
//#line 260
final x10.
              array.
              PolyRow r =
              r1575.next$G();
            
//#line 261
pmb.add(((x10.
                                   array.
                                   Row)(r)));
        }
        
//#line 262
return pmb.toSortedPolyMat((boolean)(false));
    }
    
    
//#line 266
public java.lang.String
                   toString(
                   ){
        
//#line 268
java.lang.String s =
          "(";
        
//#line 269
boolean first =
          true;
        
//#line 271
for (
//#line 271
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1576 =
                            this.iterator();
                          r1576.hasNext();
                          ) {
            
//#line 271
final x10.
              array.
              PolyRow r =
              r1576.next$G();
            
//#line 272
if ((!(((boolean)(first))))) {
                
//#line 272
s = ((s) + (" && "));
            }
            
//#line 273
s = ((s) + (r.toString()));
            
//#line 274
first = false;
        }
        
//#line 277
s = ((s) + (")"));
        
//#line 278
return s;
    }
    
    
//#line 26
final public int
                  rank(
                  ){
        
//#line 26
return this.
                             rank;
    }

}
