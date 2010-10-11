package x10.array;


public class PolyRegion
extends x10.
  array.
  Region
{public static final x10.rtt.RuntimeType<PolyRegion> _RTT = new x10.rtt.RuntimeType<PolyRegion>(
/* base class */PolyRegion.class
, /* parents */ new x10.rtt.Type[] {x10.array.Region._RTT}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
    
    
//#line 38
final public x10.
      array.
      PolyMat
      mat;
    
    
//#line 45
public boolean
                  isConvex(
                  ){
        
//#line 46
return true;
    }
    
    
//#line 49
public int
                  size(
                  ){
        
//#line 49
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 56
public static class Scanners
                extends x10.core.Ref
                  implements x10.core.Iterator<x10.
                               array.
                               Region.
                               Scanner>
                {public static final x10.rtt.RuntimeType<Scanners> _RTT = new x10.rtt.RuntimeType<Scanners>(
    /* base class */Scanners.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), x10.array.Region.Scanner._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public x10.lang.Iterator.next(): T
    public x10.
      array.
      Region.
      Scanner
      next$G(){return next();}
    
        
//#line 25
final public x10.
          array.
          PolyRegion
          out$;
        
//#line 58
public boolean
          hasNext;
        
        
//#line 60
public boolean
                      hasNext(
                      ){
            
//#line 61
return hasNext;
        }
        
        
//#line 64
public x10.
                      array.
                      Region.
                      Scanner
                      next(
                      ){
            
//#line 65
if (hasNext) {
                
//#line 66
this.hasNext = false;
                
//#line 67
return this.
                                     out$.scanner();
            } else {
                
//#line 69
throw new x10.
                  util.
                  NoSuchElementException("in scanner");
            }
        }
        
        
//#line 72
public void
                      remove(
                      ){
            
//#line 73
throw new java.lang.UnsupportedOperationException("remove");
        }
        
        
//#line 56
public Scanners(final x10.
                                      array.
                                      PolyRegion out$) {
            
//#line 56
super();
            
//#line 25
this.out$ = out$;
            
//#line 58
this.hasNext = true;
        }
    
    }
    
    
    
//#line 77
public x10.
                  array.
                  PolyRegion.
                  Scanners
                  scanners(
                  ){
        
//#line 77
return new x10.
          array.
          PolyRegion.
          Scanners(this);
    }
    
    
//#line 79
public x10.
                  array.
                  Region.
                  Scanner
                  scanner(
                  ){
        
//#line 80
final x10.
          array.
          PolyScanner scanner =
          ((x10.
          array.
          PolyScanner)(x10.
          array.
          PolyScanner.make(((x10.
                             array.
                             PolyMat)(mat)))));
        
//#line 81
return scanner;
    }
    
    
//#line 91
public x10.core.Iterator<x10.
                  array.
                  Point>
                  iterator(
                  ){
        
//#line 92
return x10.
          array.
          PolyRegion.__$closure$apply$__1945(((x10.core.Iterator)(((x10.core.Iterator)
                                                                    x10.
                                                                    array.
                                                                    PolyScanner.make(((x10.
                                                                                       array.
                                                                                       PolyMat)(mat))).iterator()))));
    }
    
    
//#line 99
public x10.
                  array.
                  Region
                  intersection(
                  final x10.
                    array.
                    Region t){
        
//#line 101
if (x10.array.PolyRegion._RTT.instanceof$(t)) {
            
//#line 104
final x10.
              array.
              PolyRegion that =
              ((x10.
              array.
              PolyRegion)((new java.lang.Object() {final x10.
              array.
              PolyRegion cast(final x10.
              array.
              PolyRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.PolyRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
              array.
              PolyRegion) t))));
            
//#line 105
final x10.
              array.
              PolyMatBuilder pmb =
              ((x10.
              array.
              PolyMatBuilder)(new x10.
              array.
              PolyMatBuilder(rank)));
            
//#line 108
for (
//#line 108
final x10.core.Iterator<x10.
                                array.
                                PolyRow> r1601 =
                                this.
                                  mat.iterator();
                              r1601.hasNext();
                              ) {
                
//#line 108
final x10.
                  array.
                  PolyRow r =
                  r1601.next$G();
                
//#line 109
pmb.add(((x10.
                                       array.
                                       Row)(r)));
            }
            
//#line 112
for (
//#line 112
final x10.core.Iterator<x10.
                                array.
                                PolyRow> r1602 =
                                that.
                                  mat.iterator();
                              r1602.hasNext();
                              ) {
                
//#line 112
final x10.
                  array.
                  PolyRow r =
                  r1602.next$G();
                
//#line 113
pmb.add(((x10.
                                       array.
                                       Row)(r)));
            }
            
//#line 116
final x10.
              array.
              PolyMat pm =
              ((x10.
              array.
              PolyMat)(pmb.toSortedPolyMat((boolean)(false))));
            
//#line 117
return new x10.core.fun.Fun_0_1<x10.
              array.
              Region, x10.
              array.
              Region>() {public final x10.
              array.
              Region apply$G(final x10.
              array.
              Region __desugarer__var__24__) { return apply(__desugarer__var__24__);}
            public final x10.
              array.
              Region apply(final x10.
              array.
              Region __desugarer__var__24__) { {
                
//#line 117
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__24__,null)) &&
                                   !(((int) __desugarer__var__24__.
                                              rank) ==
                                     ((int) x10.
                                              array.
                                              PolyRegion.this.
                                              rank))) {
                    
//#line 117
throw new java.lang.ClassCastException("x10.array.Region{self.rank==x10.array.PolyRegion#this.rank}");
                }
                
//#line 117
return __desugarer__var__24__;
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
        } else {
            
//#line 124
throw new java.lang.UnsupportedOperationException((((("intersection(") + (t))) + (")")));
        }
    }
    
    
//#line 129
public boolean
                   contains(
                   final x10.
                     array.
                     Region that){
        
//#line 130
return this.computeBoundingBox().contains(((x10.
                                                                 array.
                                                                 Region)(that.computeBoundingBox())));
    }
    
    
//#line 137
public x10.
                   array.
                   Region
                   projection(
                   final int axis){
        
//#line 138
x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(mat));
        
//#line 139
for (
//#line 139
int k =
                            0;
                          ((((int)(k))) < (((int)(rank))));
                          
//#line 139
k = ((((int)(k))) + (((int)(1))))) {
            
//#line 140
if (((int) k) !=
                             ((int) axis)) {
                
//#line 141
pm = ((x10.
                  array.
                  PolyMat)(pm.eliminate((int)(k),
                                        (boolean)(true))));
            }
        }
        
//#line 142
return x10.
          array.
          PolyRegion.__$closure$apply$__1946(((x10.
                                               array.
                                               Region)(((x10.
                                                         array.
                                                         Region)
                                                         x10.
                                                         array.
                                                         Region.makeRectangular((int)(pm.rectMin((int)(axis))),
                                                                                (int)(pm.rectMax((int)(axis))))))));
    }
    
    
//#line 151
public x10.
                   array.
                   Region
                   eliminate(
                   final int axis){
        
//#line 152
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(mat.eliminate((int)(axis),
                                 (boolean)(true))));
        
//#line 153
final x10.
          array.
          Region result =
          ((x10.
          array.
          Region)(x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)))));
        
//#line 154
return result;
    }
    
    
//#line 162
public x10.
                   array.
                   Region
                   product(
                   final x10.
                     array.
                     Region r){
        
//#line 163
if ((!(((boolean)((x10.array.PolyRegion._RTT.instanceof$(r))))))) {
            
//#line 164
throw new java.lang.UnsupportedOperationException((((("product(") + (r))) + (")")));
        }
        
//#line 165
final x10.
          array.
          PolyRegion that =
          ((x10.
          array.
          PolyRegion)((new java.lang.Object() {final x10.
          array.
          PolyRegion cast(final x10.
          array.
          PolyRegion self) {if (self==null) return null;x10.rtt.Type rtt = x10.array.PolyRegion._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          array.
          PolyRegion) r))));
        
//#line 166
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(((((int)(this.
                                    rank))) + (((int)(that.
                                                        rank)))))));
        
//#line 167
x10.
          array.
          PolyRegion.copy(((x10.
                            array.
                            PolyMatBuilder)(pmb)),
                          ((x10.
                            array.
                            PolyMat)(this.
                                       mat)),
                          (int)(0));
        
//#line 168
x10.
          array.
          PolyRegion.copy(((x10.
                            array.
                            PolyMatBuilder)(pmb)),
                          ((x10.
                            array.
                            PolyMat)(that.
                                       mat)),
                          (int)(this.
                                  rank));
        
//#line 169
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(false))));
        
//#line 170
return x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)));
    }
    
    
//#line 173
private static void
                   copy(
                   final x10.
                     array.
                     PolyMatBuilder tt,
                   final x10.
                     array.
                     PolyMat ff,
                   final int offset){
        
//#line 174
for (
//#line 174
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1603 =
                            ff.iterator();
                          r1603.hasNext();
                          ) {
            
//#line 174
final x10.
              array.
              PolyRow r =
              r1603.next$G();
            
//#line 175
final x10.
              array.
              PolyRow f =
              ((x10.
              array.
              PolyRow)(r));
            
//#line 176
final x10.core.Rail<java.lang.Integer> t =
              ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(((((int)(tt.
                                                                                                                        rank))) + (((int)(1)))))))));
            {
                
//#line 177
final int[] t$value1947 =
                  ((int[])t.value);
                
//#line 177
for (
//#line 177
int i =
                                    0;
                                  ((((int)(i))) < (((int)(ff.
                                                            rank))));
                                  
//#line 177
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 178
t$value1947[((((int)(offset))) + (((int)(i))))]=f.apply((int)(i));
                }
            }
            
//#line 179
((int[])t.value)[tt.
                                            rank] = f.apply((int)(ff.
                                                                    rank));
            
//#line 180
tt.add(((x10.
                                  array.
                                  Row)(new x10.
                                  array.
                                  PolyRow(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, t)))));
        }
    }
    
    public static void
      copy$P(
      final x10.
        array.
        PolyMatBuilder tt,
      final x10.
        array.
        PolyMat ff,
      final int offset){
        PolyRegion.copy(((x10.
                          array.
                          PolyMatBuilder)(tt)),
                        ((x10.
                          array.
                          PolyMat)(ff)),
                        (int)(offset));
    }
    
    
//#line 185
public x10.
                   array.
                   Region
                   translate(
                   final x10.
                     array.
                     Point v){
        
//#line 186
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(this.
                           rank)));
        
//#line 187
x10.
          array.
          PolyRegion.translate(((x10.
                                 array.
                                 PolyMatBuilder)(pmb)),
                               ((x10.
                                 array.
                                 PolyMat)(this.
                                            mat)),
                               ((x10.
                                 array.
                                 Point)(v)));
        
//#line 188
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(false))));
        
//#line 189
return x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)));
    }
    
    
//#line 192
private static void
                   translate(
                   final x10.
                     array.
                     PolyMatBuilder tt,
                   final x10.
                     array.
                     PolyMat ff,
                   final x10.
                     array.
                     Point v){
        
//#line 193
for (
//#line 193
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1604 =
                            ff.iterator();
                          r1604.hasNext();
                          ) {
            
//#line 193
final x10.
              array.
              PolyRow r =
              r1604.next$G();
            
//#line 194
final x10.
              array.
              PolyRow f =
              ((x10.
              array.
              PolyRow)(r));
            
//#line 195
final x10.core.Rail<java.lang.Integer> t =
              ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(((((int)(ff.
                                                                                                                        rank))) + (((int)(1)))))))));
            
//#line 196
int s =
              0;
            {
                
//#line 197
final int[] t$value1948 =
                  ((int[])t.value);
                
//#line 197
for (
//#line 197
int i =
                                    0;
                                  ((((int)(i))) < (((int)(ff.
                                                            rank))));
                                  
//#line 197
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 198
t$value1948[i]=f.apply((int)(i));
                    
//#line 199
s = ((((int)(s))) + (((int)(((((int)(f.apply((int)(i))))) * (((int)(v.apply((int)(i))))))))));
                }
            }
            
//#line 201
((int[])t.value)[ff.
                                            rank] = ((((int)(f.apply((int)(ff.
                                                                             rank))))) - (((int)(s))));
            
//#line 202
tt.add(((x10.
                                  array.
                                  Row)(new x10.
                                  array.
                                  PolyRow(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, t)))));
        }
    }
    
    public static void
      translate$P(
      final x10.
        array.
        PolyMatBuilder tt,
      final x10.
        array.
        PolyMat ff,
      final x10.
        array.
        Point v){
        PolyRegion.translate(((x10.
                               array.
                               PolyMatBuilder)(tt)),
                             ((x10.
                               array.
                               PolyMat)(ff)),
                             ((x10.
                               array.
                               Point)(v)));
    }
    
    
//#line 231
public boolean
                   isEmpty(
                   ){
        
//#line 232
final boolean tmp =
          mat.isEmpty();
        
//#line 233
return tmp;
    }
    
    
//#line 236
public x10.
                   array.
                   Region
                   computeBoundingBox(
                   ){
        
//#line 237
final x10.core.Rail<java.lang.Integer> min =
          ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(rank)))));
        
//#line 238
final x10.core.Rail<java.lang.Integer> max =
          ((x10.core.Rail)(x10.core.RailFactory.<java.lang.Integer>makeVarRail(x10.rtt.Types.INT, ((int)(rank)))));
        
//#line 239
x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(mat));
        {
            
//#line 240
final int[] min$value1949 =
              ((int[])min.value);
            
//#line 240
final int[] max$value1950 =
              ((int[])max.value);
            
//#line 240
for (
//#line 240
int axis =
                                0;
                              ((((int)(axis))) < (((int)(rank))));
                              
//#line 240
axis = ((((int)(axis))) + (((int)(1))))) {
                
//#line 241
x10.
                  array.
                  PolyMat x =
                  pm;
                
//#line 242
for (
//#line 242
int k =
                                    ((((int)(axis))) + (((int)(1))));
                                  ((((int)(k))) < (((int)(rank))));
                                  
//#line 242
k = ((((int)(k))) + (((int)(1))))) {
                    
//#line 243
x = x.eliminate((int)(k),
                                                 (boolean)(true));
                }
                
//#line 244
min$value1949[axis]=x.rectMin((int)(axis));
                
//#line 245
max$value1950[axis]=x.rectMax((int)(axis));
                
//#line 246
pm = ((x10.
                  array.
                  PolyMat)(pm.eliminate((int)(axis),
                                        (boolean)(true))));
            }
        }
        
//#line 248
return x10.
          array.
          Region.makeRectangular(((x10.core.Rail)(min)),
                                 ((x10.core.Rail)(max)));
    }
    
    
//#line 256
public boolean
                   contains(
                   final x10.
                     array.
                     Point p){
        
//#line 258
for (
//#line 258
final x10.core.Iterator<x10.
                            array.
                            PolyRow> r1605 =
                            mat.iterator();
                          r1605.hasNext();
                          ) {
            
//#line 258
final x10.
              array.
              PolyRow r =
              r1605.next$G();
            
//#line 259
if ((!(((boolean)(r.contains(((x10.
                                                        array.
                                                        Point)(p)))))))) {
                
//#line 260
return false;
            }
        }
        
//#line 263
return true;
    }
    
    
//#line 279
/**
     * lower==1 and lower==1 include the diagonal
     * lower==size and upper==size includes entire size x size square
     *
     * col-colMin >= row-rowMin - (lower-1)
     * col-colMin <= row-rowMin + (upper-1)
     *
     * col-row >= colMin-rowMin - (lower-1)
     * col-row <= colMin-rowMin + (upper-1)
     */final public static int
      ROW =
      x10.
      array.
      PolyMatBuilder.X((int)(0));
    
//#line 280
final public static int
      COL =
      x10.
      array.
      PolyMatBuilder.X((int)(1));
    
    
//#line 282
public static x10.
                   array.
                   Region
                   makeBanded(
                   final int rowMin,
                   final int colMin,
                   final int rowMax,
                   final int colMax,
                   final int upper,
                   final int lower){
        
//#line 283
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(2)));
        
//#line 284
pmb.add((int)(x10.
                               array.
                               PolyRegion.ROW),
                             (int)(pmb.
                                     GE),
                             (int)(rowMin));
        
//#line 285
pmb.add((int)(x10.
                               array.
                               PolyRegion.ROW),
                             (int)(pmb.
                                     LE),
                             (int)(rowMax));
        
//#line 286
pmb.add((int)(x10.
                               array.
                               PolyRegion.COL),
                             (int)(pmb.
                                     GE),
                             (int)(colMin));
        
//#line 287
pmb.add((int)(x10.
                               array.
                               PolyRegion.COL),
                             (int)(pmb.
                                     LE),
                             (int)(colMax));
        
//#line 288
pmb.add((int)(((((int)(x10.
                               array.
                               PolyRegion.COL))) - (((int)(x10.
                               array.
                               PolyRegion.ROW))))),
                             (int)(pmb.
                                     GE),
                             (int)(((((int)(((((int)(colMin))) - (((int)(rowMin))))))) - (((int)((((((int)(lower))) - (((int)(1)))))))))));
        
//#line 289
pmb.add((int)(((((int)(x10.
                               array.
                               PolyRegion.COL))) - (((int)(x10.
                               array.
                               PolyRegion.ROW))))),
                             (int)(pmb.
                                     LE),
                             (int)(((((int)(((((int)(colMin))) - (((int)(rowMin))))))) + (((int)((((((int)(upper))) - (((int)(1)))))))))));
        
//#line 290
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(false))));
        
//#line 291
return x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)));
    }
    
    
//#line 294
public static x10.
                   array.
                   Region
                   makeBanded(
                   final int size,
                   final int upper,
                   final int lower){
        
//#line 295
return x10.
          array.
          PolyRegion.makeBanded((int)(0),
                                (int)(0),
                                (int)(((((int)(size))) - (((int)(1))))),
                                (int)(((((int)(size))) - (((int)(1))))),
                                (int)(upper),
                                (int)(lower));
    }
    
    
//#line 298
public static x10.
                   array.
                   Region
                   makeUpperTriangular2(
                   final int rowMin,
                   final int colMin,
                   final int size){
        
//#line 299
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(2)));
        
//#line 300
pmb.add((int)(x10.
                               array.
                               PolyRegion.ROW),
                             (int)(pmb.
                                     GE),
                             (int)(rowMin));
        
//#line 301
pmb.add((int)(x10.
                               array.
                               PolyRegion.COL),
                             (int)(pmb.
                                     LE),
                             (int)(((((int)(((((int)(colMin))) + (((int)(size))))))) - (((int)(1))))));
        
//#line 302
pmb.add((int)(((((int)(x10.
                               array.
                               PolyRegion.COL))) - (((int)(x10.
                               array.
                               PolyRegion.ROW))))),
                             (int)(pmb.
                                     GE),
                             (int)(((((int)(colMin))) - (((int)(rowMin))))));
        
//#line 303
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(true))));
        
//#line 304
return x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)));
    }
    
    
//#line 307
public static x10.
                   array.
                   Region
                   makeLowerTriangular2(
                   final int rowMin,
                   final int colMin,
                   final int size){
        
//#line 308
final x10.
          array.
          PolyMatBuilder pmb =
          ((x10.
          array.
          PolyMatBuilder)(new x10.
          array.
          PolyMatBuilder(2)));
        
//#line 309
pmb.add((int)(x10.
                               array.
                               PolyRegion.COL),
                             (int)(pmb.
                                     GE),
                             (int)(colMin));
        
//#line 310
pmb.add((int)(x10.
                               array.
                               PolyRegion.ROW),
                             (int)(pmb.
                                     LE),
                             (int)(((((int)(((((int)(rowMin))) + (((int)(size))))))) - (((int)(1))))));
        
//#line 311
pmb.add((int)(((((int)(x10.
                               array.
                               PolyRegion.ROW))) - (((int)(x10.
                               array.
                               PolyRegion.COL))))),
                             (int)(pmb.
                                     GE),
                             (int)(((((int)(rowMin))) - (((int)(colMin))))));
        
//#line 312
final x10.
          array.
          PolyMat pm =
          ((x10.
          array.
          PolyMat)(pmb.toSortedPolyMat((boolean)(true))));
        
//#line 313
return x10.
          array.
          PolyRegion.make(((x10.
                            array.
                            PolyMat)(pm)));
    }
    
    
//#line 323
public static x10.
                   array.
                   Region
                   make(
                   final x10.
                     array.
                     PolyMat pm){
        
//#line 324
if (pm.isEmpty()) {
            
//#line 325
return new x10.
              array.
              EmptyRegion(pm.
                            rank);
        } else {
            
//#line 327
return new x10.
              array.
              PolyRegion(pm,
                         false);
        }
    }
    
    
//#line 331
public PolyRegion(final x10.
                                     array.
                                     PolyMat pm,
                                   final boolean hack198) {
        
//#line 333
super(pm.
                             rank,
                           pm.isRect(),
                           pm.isZeroBased());
        
//#line 337
this.mat = ((x10.
          array.
          PolyMat)(new x10.core.fun.Fun_0_1<x10.
          array.
          PolyMat, x10.
          array.
          PolyMat>() {public final x10.
          array.
          PolyMat apply$G(final x10.
          array.
          PolyMat __desugarer__var__26__) { return apply(__desugarer__var__26__);}
        public final x10.
          array.
          PolyMat apply(final x10.
          array.
          PolyMat __desugarer__var__26__) { {
            
//#line 337
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__26__,null)) &&
                               !(((int) __desugarer__var__26__.
                                          rank) ==
                                 ((int) x10.
                                          array.
                                          PolyRegion.this.
                                          rank))) {
                
//#line 337
throw new java.lang.ClassCastException("x10.array.PolyMat{self.rank==x10.array.PolyRegion#this.rank}");
            }
            
//#line 337
return __desugarer__var__26__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.PolyMat._RTT;if (i ==1) return x10.array.PolyMat._RTT;return null;
        }
        }.apply(((x10.
                  array.
                  PolyMat)
                  pm.simplifyAll()))));
    }
    
    
//#line 345
public x10.core.ValRail<java.lang.Integer>
                   min(
                   ){
        
//#line 346
return this.boundingBox().min();
    }
    
    
//#line 349
public x10.core.ValRail<java.lang.Integer>
                   max(
                   ){
        
//#line 350
return this.boundingBox().max();
    }
    
    
//#line 358
public void
                   printInfo(
                   final x10.
                     io.
                     Printer out){
        
//#line 359
mat.printInfo(((x10.
                                     io.
                                     Printer)(out)),
                                   ((java.lang.String)(this.toString())));
    }
    
    
//#line 362
public java.lang.String
                   toString(
                   ){
        
//#line 363
return mat.toString();
    }
    
    final private static x10.core.Iterator<x10.
      array.
      Point>
      __$closure$apply$__1945(
      final x10.core.Iterator<x10.
        array.
        Point> __desugarer__var__23__){
        
//#line 92
if (!(x10.rtt.Equality.equalsequals(((x10.
                            lang.
                            Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__23__)))),x10.
                            lang.
                            Runtime.here()))) {
            
//#line 92
throw new java.lang.ClassCastException(("x10.lang.Iterator[x10.array.Point{self.rank==x10.array.PolyR" +
                                                                "egion#this.rank}]{self.home==here}"));
        }
        
//#line 92
return __desugarer__var__23__;
    }
    
    final public static x10.core.Iterator<x10.
      array.
      Point>
      __$closure$apply$__1945$P(
      final x10.core.Iterator<x10.
        array.
        Point> __desugarer__var__23__){
        return PolyRegion.__$closure$apply$__1945(((x10.core.Iterator)(__desugarer__var__23__)));
    }
    
    final private static x10.
      array.
      Region
      __$closure$apply$__1946(
      final x10.
        array.
        Region __desugarer__var__25__){
        
//#line 142
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__25__,null)) &&
                           !(((int) __desugarer__var__25__.
                                      rank) ==
                             ((int) 1))) {
            
//#line 142
throw new java.lang.ClassCastException("x10.array.Region{self.rank==1}");
        }
        
//#line 142
return __desugarer__var__25__;
    }
    
    final public static x10.
      array.
      Region
      __$closure$apply$__1946$P(
      final x10.
        array.
        Region __desugarer__var__25__){
        return PolyRegion.__$closure$apply$__1946(((x10.
                                                    array.
                                                    Region)(__desugarer__var__25__)));
    }

}
