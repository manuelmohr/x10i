package x10.array;


public class DistArray<T>
extends x10.core.Ref
  implements x10.core.fun.Fun_0_1<x10.
               array.
               Point,T>,
             x10.core.Iterable<x10.
               array.
               Point >
{public static final x10.rtt.RuntimeType<DistArray> _RTT = new x10.rtt.RuntimeType<DistArray>(
/* base class */DistArray.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.array.Point._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), x10.array.Point._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 30
final public x10.
      array.
      Dist
      dist;
    
    
//#line 35
public static class LocalState<T>
                extends x10.core.Ref
                {public static final x10.rtt.RuntimeType<LocalState> _RTT = new x10.rtt.RuntimeType<LocalState>(
    /* base class */LocalState.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
    
        private final x10.rtt.Type T;
        
        
//#line 36
final public x10.
          array.
          RectLayout
          layout;
        
//#line 37
final public x10.core.IndexedMemoryChunk<T>
          raw;
        
        
//#line 39
public LocalState(final x10.rtt.Type T,
                                      final x10.
                                        array.
                                        RectLayout l,
                                      final x10.core.IndexedMemoryChunk<T> r) {
                                                                                       super();
                                                                                   this.T = T;
                                                                                    {
                                                                                       
//#line 40
this.layout = l;
                                                                                       
//#line 41
this.raw = r;
                                                                                   }}
    
    }
    
    
    
//#line 54
final public x10.
                  array.
                  Region
                  region(
                  ){
        
//#line 54
return dist.
                             region;
    }
    
    
//#line 59
final public int
                  rank(
                  ){
        
//#line 59
return dist.rank();
    }
    
    
//#line 64
final public boolean
                  rect(
                  ){
        
//#line 64
return dist.rect();
    }
    
    
//#line 69
final public boolean
                  zeroBased(
                  ){
        
//#line 69
return dist.zeroBased();
    }
    
    
//#line 75
final public boolean
                  rail(
                  ){
        
//#line 75
return dist.rail();
    }
    
    
//#line 80
final public boolean
                  unique(
                  ){
        
//#line 80
return dist.
                             unique;
    }
    
    
//#line 85
final public boolean
                  constant(
                  ){
        
//#line 85
return dist.
                             constant;
    }
    
    
//#line 90
final public x10.
                  lang.
                  Place
                  onePlace(
                  ){
        
//#line 90
return dist.
                             onePlace;
    }
    
    
//#line 108
public static <T> x10.
                   array.
                   DistArray<T>
                   make(
                   final x10.rtt.Type T,
                   final x10.
                     array.
                     Dist dist){
        
//#line 108
return new x10.
          array.
          DistArray<T>(T,
                       dist);
    }
    
    
//#line 121
public static <T> x10.
                   array.
                   DistArray<T>
                   make(
                   final x10.rtt.Type T,
                   final x10.
                     array.
                     Dist dist,
                   final x10.core.fun.Fun_0_1<x10.
                     array.
                     Point,T> init){
        
//#line 121
return new x10.
          array.
          DistArray<T>(T,
                       dist,
                       init);
    }
    
    
//#line 126
final public x10.
      lang.
      PlaceLocalHandle<x10.
      array.
      DistArray.
      LocalState<T>>
      localHandle;
    
    
//#line 127
final public x10.core.IndexedMemoryChunk<T>
                   raw(
                   ){
        
//#line 127
return localHandle.apply$G().
                              raw;
    }
    
    
//#line 128
final public x10.
                   array.
                   RectLayout
                   layout(
                   ){
        
//#line 128
return localHandle.apply$G().
                              layout;
    }
    
    
//#line 131
native private boolean
                   checkBounds(
                   );
    
    public static <T> boolean
      checkBounds$P(
      final x10.rtt.Type T,
      final x10.
        array.
        DistArray<T> DistArray){
        return (!false);
    }
    
    
//#line 135
native private boolean
                   checkPlace(
                   );
    
    public static <T> boolean
      checkPlace$P(
      final x10.rtt.Type T,
      final x10.
        array.
        DistArray<T> DistArray){
        return (!false);
    }
    
    
//#line 140
final public T
                   apply$G(
                   final x10.
                     array.
                     Point pt){
        
//#line 141
if ((!false) &&
                         (!(((boolean)(this.region().contains(((x10.
                                                                array.
                                                                Point)(pt)))))))) {
            
//#line 142
this.raiseBoundsError(((x10.
                                                 array.
                                                 Point)(pt)));
        }
        
//#line 144
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply(((x10.
                                                                      array.
                                                                      Point)(pt))),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 145
this.raisePlaceError(((x10.
                                                array.
                                                Point)(pt)));
        }
        
//#line 147
return (this.raw()).apply$G(((int)(this.layout().offset(((x10.
                                                                               array.
                                                                               Point)(pt))))));
    }
    
    
//#line 153
final public T
                   get$G(
                   final x10.
                     array.
                     Point pt){
        
//#line 153
return this.apply$G(((x10.
                                           array.
                                           Point)(pt)));
    }
    
    
//#line 155
final public T
                   apply$G(
                   final int i0){
        
//#line 156
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0))))))) {
            
//#line 157
this.raiseBoundsError((int)(i0));
        }
        
//#line 159
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 160
this.raisePlaceError((int)(i0));
        }
        
//#line 162
return (this.raw()).apply$G(((int)(this.layout().offset((int)(i0)))));
    }
    
    
//#line 165
final public T
                   apply$G(
                   final int i0,
                   final int i1){
        
//#line 166
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1))))))) {
            
//#line 167
this.raiseBoundsError((int)(i0),
                                               (int)(i1));
        }
        
//#line 169
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 170
this.raisePlaceError((int)(i0),
                                              (int)(i1));
        }
        
//#line 172
return (this.raw()).apply$G(((int)(this.layout().offset((int)(i0),
                                                                             (int)(i1)))));
    }
    
    
//#line 175
final public T
                   apply$G(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 176
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1),
                                                              (int)(i2))))))) {
            
//#line 177
this.raiseBoundsError((int)(i0),
                                               (int)(i1),
                                               (int)(i2));
        }
        
//#line 179
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1),
                                                                    (int)(i2)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 180
this.raisePlaceError((int)(i0),
                                              (int)(i1),
                                              (int)(i2));
        }
        
//#line 182
return (this.raw()).apply$G(((int)(this.layout().offset((int)(i0),
                                                                             (int)(i1),
                                                                             (int)(i2)))));
    }
    
    
//#line 185
final public T
                   apply$G(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 186
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1),
                                                              (int)(i2),
                                                              (int)(i3))))))) {
            
//#line 187
this.raiseBoundsError((int)(i0),
                                               (int)(i1),
                                               (int)(i2),
                                               (int)(i3));
        }
        
//#line 189
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1),
                                                                    (int)(i2),
                                                                    (int)(i3)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 190
this.raisePlaceError((int)(i0),
                                              (int)(i1),
                                              (int)(i2),
                                              (int)(i3));
        }
        
//#line 192
return (this.raw()).apply$G(((int)(this.layout().offset((int)(i0),
                                                                             (int)(i1),
                                                                             (int)(i2),
                                                                             (int)(i3)))));
    }
    
    
//#line 197
final public T
                   set$G(
                   final T v,
                   final x10.
                     array.
                     Point pt){
        
//#line 198
if ((!false) &&
                         (!(((boolean)(this.region().contains(((x10.
                                                                array.
                                                                Point)(pt)))))))) {
            
//#line 199
this.raiseBoundsError(((x10.
                                                 array.
                                                 Point)(pt)));
        }
        
//#line 201
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply(((x10.
                                                                      array.
                                                                      Point)(pt))),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 202
this.raisePlaceError(((x10.
                                                array.
                                                Point)(pt)));
        }
        
//#line 204
final x10.core.IndexedMemoryChunk<T> r =
          this.raw();
        
//#line 205
(r).set(v, ((int)(this.layout().offset(((x10.
                                                              array.
                                                              Point)(pt))))));
        
//#line 206
return v;
    }
    
    
//#line 209
final public T
                   set$G(
                   final T v,
                   final int i0){
        
//#line 210
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0))))))) {
            
//#line 211
this.raiseBoundsError((int)(i0));
        }
        
//#line 213
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 214
this.raisePlaceError((int)(i0));
        }
        
//#line 216
(this.raw()).set(v, ((int)(this.layout().offset((int)(i0)))));
        
//#line 217
return v;
    }
    
    
//#line 220
final public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1){
        
//#line 221
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1))))))) {
            
//#line 222
this.raiseBoundsError((int)(i0),
                                               (int)(i1));
        }
        
//#line 224
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 225
this.raisePlaceError((int)(i0),
                                              (int)(i1));
        }
        
//#line 227
(this.raw()).set(v, ((int)(this.layout().offset((int)(i0),
                                                                     (int)(i1)))));
        
//#line 228
return v;
    }
    
    
//#line 231
final public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 232
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1),
                                                              (int)(i2))))))) {
            
//#line 233
this.raiseBoundsError((int)(i0),
                                               (int)(i1),
                                               (int)(i2));
        }
        
//#line 235
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1),
                                                                    (int)(i2)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 236
this.raisePlaceError((int)(i0),
                                              (int)(i1),
                                              (int)(i2));
        }
        
//#line 238
(this.raw()).set(v, ((int)(this.layout().offset((int)(i0),
                                                                     (int)(i1),
                                                                     (int)(i2)))));
        
//#line 239
return v;
    }
    
    
//#line 242
final public T
                   set$G(
                   final T v,
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 243
if ((!false) &&
                         (!(((boolean)(this.region().contains((int)(i0),
                                                              (int)(i1),
                                                              (int)(i2),
                                                              (int)(i3))))))) {
            
//#line 244
this.raiseBoundsError((int)(i0),
                                               (int)(i1),
                                               (int)(i2),
                                               (int)(i3));
        }
        
//#line 246
if ((!false) &&
                         (!x10.rtt.Equality.equalsequals(dist.apply((int)(i0),
                                                                    (int)(i1),
                                                                    (int)(i2),
                                                                    (int)(i3)),x10.
                           lang.
                           Runtime.here()))) {
            
//#line 247
this.raisePlaceError((int)(i0),
                                              (int)(i1),
                                              (int)(i2),
                                              (int)(i3));
        }
        
//#line 249
(this.raw()).set(v, ((int)(this.layout().offset((int)(i0),
                                                                     (int)(i1),
                                                                     (int)(i2),
                                                                     (int)(i3)))));
        
//#line 250
return v;
    }
    
    
//#line 253
public DistArray(final x10.rtt.Type T,
                                  final x10.
                                    array.
                                    Dist dist,
                                  final x10.core.fun.Fun_0_1<x10.
                                    array.
                                    Point,T> init) {
                                                            super();
                                                        this.T = T;
                                                         {
                                                            
//#line 254
this.dist = dist;
                                                            
//#line 256
final x10.core.fun.Fun_0_0<x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T>> plsInit =
                                                              (new java.lang.Object() {final x10.core.fun.Fun_0_0 cast(final x10.core.fun.Fun_0_0 self) {if (self==null) return null;x10.rtt.Type rtt = x10.core.fun.Fun_0_0._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.core.fun.Fun_0_0) new x10.core.fun.Fun_0_0<x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T>>() {public final x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T> apply$G() { return apply();}
                                                            public final x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T> apply() { {
                                                                
//#line 257
final x10.
                                                                  array.
                                                                  Region region =
                                                                  ((x10.
                                                                  array.
                                                                  Region)(dist.get(((x10.
                                                                                     lang.
                                                                                     Place)(x10.
                                                                                     lang.
                                                                                     Runtime.here())))));
                                                                
//#line 258
final x10.
                                                                  array.
                                                                  RectLayout localLayout =
                                                                  x10.
                                                                  array.
                                                                  DistArray.layout(((x10.
                                                                                     array.
                                                                                     Region)(region)));
                                                                
//#line 259
final x10.core.IndexedMemoryChunk<T> localRaw =
                                                                  x10.core.IndexedMemoryChunk.<T>allocate(T, ((int)(localLayout.size())));
                                                                
//#line 261
for (
//#line 261
final x10.core.Iterator<x10.
                                                                                    array.
                                                                                    Point> pt1376 =
                                                                                    region.iterator();
                                                                                  pt1376.hasNext();
                                                                                  ) {
                                                                    
//#line 261
final x10.
                                                                      array.
                                                                      Point pt =
                                                                      ((x10.
                                                                      array.
                                                                      Point)(pt1376.next$G()));
                                                                    
//#line 262
(localRaw).set(init.apply$G(new x10.core.fun.Fun_0_1<x10.
                                                                                                               array.
                                                                                                               Point, x10.
                                                                                                               array.
                                                                                                               Point>() {public final x10.
                                                                                                               array.
                                                                                                               Point apply$G(final x10.
                                                                                                               array.
                                                                                                               Point __desugarer__var__9__) { return apply(__desugarer__var__9__);}
                                                                                                             public final x10.
                                                                                                               array.
                                                                                                               Point apply(final x10.
                                                                                                               array.
                                                                                                               Point __desugarer__var__9__) { {
                                                                                                                 
//#line 262
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__9__,null)) &&
                                                                                                                                    !(((int) __desugarer__var__9__.
                                                                                                                                               rank) ==
                                                                                                                                      ((int) dist.
                                                                                                                                               region.
                                                                                                                                               rank))) {
                                                                                                                     
//#line 262
throw new java.lang.ClassCastException("x10.array.Point{self.rank==dist.region.rank}");
                                                                                                                 }
                                                                                                                 
//#line 262
return __desugarer__var__9__;
                                                                                                             }}
                                                                                                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                             }
                                                                                                             }.apply(((x10.
                                                                                                                       array.
                                                                                                                       Point)
                                                                                                                       pt))), ((int)(localLayout.offset(((x10.
                                                                                                                                                          array.
                                                                                                                                                          Point)(pt))))));
                                                                }
                                                                
//#line 265
return new x10.
                                                                  array.
                                                                  DistArray.
                                                                  LocalState<T>(T,
                                                                                localLayout,
                                                                                localRaw);
                                                            }}
                                                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T);return null;
                                                            }
                                                            }));
                                                            
//#line 268
this.localHandle = x10.
                                                              lang.
                                                              PlaceLocalHandle.<x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T>>make(new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T),
                                                                                 ((x10.
                                                                                   array.
                                                                                   Dist)(dist)),
                                                                                 ((x10.core.fun.Fun_0_0)(plsInit)));
                                                        }}
    
    
//#line 270
public DistArray(final x10.rtt.Type T,
                                  final x10.
                                    array.
                                    Dist dist) {
                                                        super();
                                                    this.T = T;
                                                     {
                                                        
//#line 271
this.dist = dist;
                                                        
//#line 273
final x10.core.fun.Fun_0_0<x10.
                                                          array.
                                                          DistArray.
                                                          LocalState<T>> plsInit =
                                                          (new java.lang.Object() {final x10.core.fun.Fun_0_0 cast(final x10.core.fun.Fun_0_0 self) {if (self==null) return null;x10.rtt.Type rtt = x10.core.fun.Fun_0_0._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.core.fun.Fun_0_0) new x10.core.fun.Fun_0_0<x10.
                                                          array.
                                                          DistArray.
                                                          LocalState<T>>() {public final x10.
                                                          array.
                                                          DistArray.
                                                          LocalState<T> apply$G() { return apply();}
                                                        public final x10.
                                                          array.
                                                          DistArray.
                                                          LocalState<T> apply() { {
                                                            
//#line 274
final x10.
                                                              array.
                                                              Region region =
                                                              ((x10.
                                                              array.
                                                              Region)(dist.get(((x10.
                                                                                 lang.
                                                                                 Place)(x10.
                                                                                 lang.
                                                                                 Runtime.here())))));
                                                            
//#line 275
final x10.
                                                              array.
                                                              RectLayout localLayout =
                                                              x10.
                                                              array.
                                                              DistArray.layout(((x10.
                                                                                 array.
                                                                                 Region)(region)));
                                                            
//#line 276
final x10.core.IndexedMemoryChunk<T> localRaw =
                                                              x10.core.IndexedMemoryChunk.<T>allocate(T, ((int)(localLayout.size())));
                                                            
//#line 278
return new x10.
                                                              array.
                                                              DistArray.
                                                              LocalState<T>(T,
                                                                            localLayout,
                                                                            localRaw);
                                                        }}
                                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T);return null;
                                                        }
                                                        }));
                                                        
//#line 281
this.localHandle = x10.
                                                          lang.
                                                          PlaceLocalHandle.<x10.
                                                          array.
                                                          DistArray.
                                                          LocalState<T>>make(new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T),
                                                                             ((x10.
                                                                               array.
                                                                               Dist)(dist)),
                                                                             ((x10.core.fun.Fun_0_0)(plsInit)));
                                                    }}
    
    
//#line 289
public x10.
                   array.
                   DistArray<T>
                   restriction(
                   final x10.
                     array.
                     Dist d){
        
//#line 290
return new x10.core.fun.Fun_0_1<x10.
          array.
          DistArray<T>, x10.
          array.
          DistArray<T>>() {public final x10.
          array.
          DistArray<T> apply$G(final x10.
          array.
          DistArray<T> __desugarer__var__10__) { return apply(__desugarer__var__10__);}
        public final x10.
          array.
          DistArray<T> apply(final x10.
          array.
          DistArray<T> __desugarer__var__10__) { {
            
//#line 290
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__10__,null)) &&
                               !(((int) __desugarer__var__10__.
                                          dist.
                                          region.
                                          rank) ==
                                 ((int) x10.
                                          array.
                                          DistArray.this.
                                          dist.
                                          region.
                                          rank))) {
                
//#line 290
throw new java.lang.ClassCastException(("x10.array.DistArray[T]{self.dist.region.rank==x10.array.Dist" +
                                                                     "Array#this.dist.region.rank}"));
            }
            
//#line 290
return __desugarer__var__10__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.array.DistArray._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.array.DistArray._RTT, T);return null;
        }
        }.apply(((x10.
                  array.
                  DistArray)
                  new x10.
                  array.
                  DistArray<T>(T,
                               this,
                               d)));
    }
    
    
//#line 293
public DistArray(final x10.rtt.Type T,
                                  final x10.
                                    array.
                                    DistArray<T> a,
                                  final x10.
                                    array.
                                    Dist d) {
                                                     super();
                                                 this.T = T;
                                                  {
                                                     
//#line 294
this.dist = d;
                                                     
//#line 295
this.localHandle = x10.
                                                       lang.
                                                       PlaceLocalHandle.<x10.
                                                       array.
                                                       DistArray.
                                                       LocalState<T>>make(new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T),
                                                                          ((x10.
                                                                            array.
                                                                            Dist)(d)),
                                                                          ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                                                            array.
                                                                            DistArray.
                                                                            LocalState<T>>() {public final x10.
                                                                            array.
                                                                            DistArray.
                                                                            LocalState<T> apply$G() { return apply();}
                                                                          public final x10.
                                                                            array.
                                                                            DistArray.
                                                                            LocalState<T> apply() { {
                                                                              
//#line 296
return a.
                                                                                                    localHandle.apply$G();
                                                                          }}
                                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.array.DistArray.LocalState._RTT, T);return null;
                                                                          }
                                                                          })));
                                                 }}
    
    
//#line 306
public x10.
                   array.
                   DistArray<T>
                   restriction(
                   final x10.
                     array.
                     Region r){
        
//#line 307
return this.restriction(((x10.
                                               array.
                                               Dist)(new x10.core.fun.Fun_0_1<x10.
                                               array.
                                               Dist, x10.
                                               array.
                                               Dist>() {public final x10.
                                               array.
                                               Dist apply$G(final x10.
                                               array.
                                               Dist __desugarer__var__11__) { return apply(__desugarer__var__11__);}
                                             public final x10.
                                               array.
                                               Dist apply(final x10.
                                               array.
                                               Dist __desugarer__var__11__) { {
                                                 
//#line 307
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__11__,null)) &&
                                                                    !(((int) __desugarer__var__11__.
                                                                               region.
                                                                               rank) ==
                                                                      ((int) x10.
                                                                               array.
                                                                               DistArray.this.
                                                                               dist.
                                                                               region.
                                                                               rank))) {
                                                     
//#line 307
throw new java.lang.ClassCastException(("x10.array.Dist{self.region.rank==x10.array.DistArray#this.di" +
                                                                                                          "st.region.rank}"));
                                                 }
                                                 
//#line 307
return __desugarer__var__11__;
                                             }}
                                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Dist._RTT;if (i ==1) return x10.array.Dist._RTT;return null;
                                             }
                                             }.apply(((x10.
                                                       array.
                                                       Dist)
                                                       dist.restriction(((x10.
                                                                          array.
                                                                          Region)(r))))))));
    }
    
    
//#line 310
public x10.
                   array.
                   DistArray<T>
                   restriction(
                   final x10.
                     lang.
                     Place p){
        
//#line 311
return this.restriction(((x10.
                                               array.
                                               Dist)(new x10.core.fun.Fun_0_1<x10.
                                               array.
                                               Dist, x10.
                                               array.
                                               Dist>() {public final x10.
                                               array.
                                               Dist apply$G(final x10.
                                               array.
                                               Dist __desugarer__var__12__) { return apply(__desugarer__var__12__);}
                                             public final x10.
                                               array.
                                               Dist apply(final x10.
                                               array.
                                               Dist __desugarer__var__12__) { {
                                                 
//#line 311
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__12__,null)) &&
                                                                    !(((int) __desugarer__var__12__.
                                                                               region.
                                                                               rank) ==
                                                                      ((int) x10.
                                                                               array.
                                                                               DistArray.this.
                                                                               dist.
                                                                               region.
                                                                               rank))) {
                                                     
//#line 311
throw new java.lang.ClassCastException(("x10.array.Dist{self.region.rank==x10.array.DistArray#this.di" +
                                                                                                          "st.region.rank}"));
                                                 }
                                                 
//#line 311
return __desugarer__var__12__;
                                             }}
                                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Dist._RTT;if (i ==1) return x10.array.Dist._RTT;return null;
                                             }
                                             }.apply(((x10.
                                                       array.
                                                       Dist)
                                                       dist.restriction(((x10.
                                                                          lang.
                                                                          Place)(p))))))));
    }
    
    
//#line 319
public x10.
                   array.
                   DistArray<T>
                   map(
                   final x10.core.fun.Fun_0_1<T,T> op){
        
//#line 320
return x10.
          array.
          DistArray.<T>make(T,
                            ((x10.
                              array.
                              Dist)(dist)),
                            ((x10.core.fun.Fun_0_1)((new x10.core.fun.Fun_0_1<x10.
                                                       array.
                                                       Point, T>() {public final T apply$G(final x10.
                                                       array.
                                                       Point p) { {
                                                         
//#line 320
return op.apply$G(x10.
                                                                                          array.
                                                                                          DistArray.this.apply$G(((x10.
                                                                                                                   array.
                                                                                                                   Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                                   array.
                                                                                                                   Point, x10.
                                                                                                                   array.
                                                                                                                   Point>() {public final x10.
                                                                                                                   array.
                                                                                                                   Point apply$G(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__13__) { return apply(__desugarer__var__13__);}
                                                                                                                 public final x10.
                                                                                                                   array.
                                                                                                                   Point apply(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__13__) { {
                                                                                                                     
//#line 320
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__13__,null)) &&
                                                                                                                                        !(((int) __desugarer__var__13__.
                                                                                                                                                   rank) ==
                                                                                                                                          ((int) x10.
                                                                                                                                                   array.
                                                                                                                                                   DistArray.this.
                                                                                                                                                   dist.
                                                                                                                                                   region.
                                                                                                                                                   rank))) {
                                                                                                                         
//#line 320
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                              "ion.rank}"));
                                                                                                                     }
                                                                                                                     
//#line 320
return __desugarer__var__13__;
                                                                                                                 }}
                                                                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                                 }
                                                                                                                 }.apply(((x10.
                                                                                                                           array.
                                                                                                                           Point)
                                                                                                                           p))))));
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                     }
                                                     }))));
    }
    
    
//#line 322
public x10.
                   array.
                   DistArray<T>
                   map(
                   final x10.
                     array.
                     Region r,
                   final x10.core.fun.Fun_0_1<T,T> op){
        
//#line 323
return x10.
          array.
          DistArray.<T>make(T,
                            ((x10.
                              array.
                              Dist)(dist.$bar(((x10.
                                                array.
                                                Region)(r))))),
                            ((x10.core.fun.Fun_0_1)((new x10.core.fun.Fun_0_1<x10.
                                                       array.
                                                       Point, T>() {public final T apply$G(final x10.
                                                       array.
                                                       Point p) { {
                                                         
//#line 323
return op.apply$G(x10.
                                                                                          array.
                                                                                          DistArray.this.apply$G(((x10.
                                                                                                                   array.
                                                                                                                   Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                                   array.
                                                                                                                   Point, x10.
                                                                                                                   array.
                                                                                                                   Point>() {public final x10.
                                                                                                                   array.
                                                                                                                   Point apply$G(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__14__) { return apply(__desugarer__var__14__);}
                                                                                                                 public final x10.
                                                                                                                   array.
                                                                                                                   Point apply(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__14__) { {
                                                                                                                     
//#line 323
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__14__,null)) &&
                                                                                                                                        !(((int) __desugarer__var__14__.
                                                                                                                                                   rank) ==
                                                                                                                                          ((int) x10.
                                                                                                                                                   array.
                                                                                                                                                   DistArray.this.
                                                                                                                                                   dist.
                                                                                                                                                   region.
                                                                                                                                                   rank))) {
                                                                                                                         
//#line 323
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                              "ion.rank}"));
                                                                                                                     }
                                                                                                                     
//#line 323
return __desugarer__var__14__;
                                                                                                                 }}
                                                                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                                 }
                                                                                                                 }.apply(((x10.
                                                                                                                           array.
                                                                                                                           Point)
                                                                                                                           p))))));
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                     }
                                                     }))));
    }
    
    
//#line 326
public x10.
                   array.
                   DistArray<T>
                   map(
                   final x10.
                     array.
                     DistArray<T> src,
                   final x10.core.fun.Fun_0_2<T,T,T> op){
        
//#line 327
return x10.
          array.
          DistArray.<T>make(T,
                            ((x10.
                              array.
                              Dist)(dist)),
                            ((x10.core.fun.Fun_0_1)((new x10.core.fun.Fun_0_1<x10.
                                                       array.
                                                       Point, T>() {public final T apply$G(final x10.
                                                       array.
                                                       Point p) { {
                                                         
//#line 327
return op.apply$G(x10.
                                                                                          array.
                                                                                          DistArray.this.apply$G(((x10.
                                                                                                                   array.
                                                                                                                   Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                                   array.
                                                                                                                   Point, x10.
                                                                                                                   array.
                                                                                                                   Point>() {public final x10.
                                                                                                                   array.
                                                                                                                   Point apply$G(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__15__) { return apply(__desugarer__var__15__);}
                                                                                                                 public final x10.
                                                                                                                   array.
                                                                                                                   Point apply(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__15__) { {
                                                                                                                     
//#line 327
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__15__,null)) &&
                                                                                                                                        !(((int) __desugarer__var__15__.
                                                                                                                                                   rank) ==
                                                                                                                                          ((int) x10.
                                                                                                                                                   array.
                                                                                                                                                   DistArray.this.
                                                                                                                                                   dist.
                                                                                                                                                   region.
                                                                                                                                                   rank))) {
                                                                                                                         
//#line 327
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                              "ion.rank}"));
                                                                                                                     }
                                                                                                                     
//#line 327
return __desugarer__var__15__;
                                                                                                                 }}
                                                                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                                 }
                                                                                                                 }.apply(((x10.
                                                                                                                           array.
                                                                                                                           Point)
                                                                                                                           p))))),
                                                                                        src.apply$G(((x10.
                                                                                                      array.
                                                                                                      Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                      array.
                                                                                                      Point, x10.
                                                                                                      array.
                                                                                                      Point>() {public final x10.
                                                                                                      array.
                                                                                                      Point apply$G(final x10.
                                                                                                      array.
                                                                                                      Point __desugarer__var__16__) { return apply(__desugarer__var__16__);}
                                                                                                    public final x10.
                                                                                                      array.
                                                                                                      Point apply(final x10.
                                                                                                      array.
                                                                                                      Point __desugarer__var__16__) { {
                                                                                                        
//#line 327
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__16__,null)) &&
                                                                                                                           !(((int) __desugarer__var__16__.
                                                                                                                                      rank) ==
                                                                                                                             ((int) x10.
                                                                                                                                      array.
                                                                                                                                      DistArray.this.
                                                                                                                                      dist.
                                                                                                                                      region.
                                                                                                                                      rank))) {
                                                                                                            
//#line 327
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                 "ion.rank}"));
                                                                                                        }
                                                                                                        
//#line 327
return __desugarer__var__16__;
                                                                                                    }}
                                                                                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                    }
                                                                                                    }.apply(((x10.
                                                                                                              array.
                                                                                                              Point)
                                                                                                              p))))));
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                     }
                                                     }))));
    }
    
    
//#line 329
public x10.
                   array.
                   DistArray<T>
                   map(
                   final x10.
                     array.
                     DistArray<T> src,
                   final x10.
                     array.
                     Region r,
                   final x10.core.fun.Fun_0_2<T,T,T> op){
        
//#line 330
return x10.
          array.
          DistArray.<T>make(T,
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
                              Dist __desugarer__var__17__) { return apply(__desugarer__var__17__);}
                            public final x10.
                              array.
                              Dist apply(final x10.
                              array.
                              Dist __desugarer__var__17__) { {
                                
//#line 330
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__17__,null)) &&
                                                   !(((int) __desugarer__var__17__.
                                                              region.
                                                              rank) ==
                                                     ((int) x10.
                                                              array.
                                                              DistArray.this.
                                                              dist.
                                                              region.
                                                              rank))) {
                                    
//#line 330
throw new java.lang.ClassCastException(("x10.array.Dist{self.region.rank==x10.array.DistArray#this.di" +
                                                                                         "st.region.rank}"));
                                }
                                
//#line 330
return __desugarer__var__17__;
                            }}
                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Dist._RTT;if (i ==1) return x10.array.Dist._RTT;return null;
                            }
                            }.apply(((x10.
                                      array.
                                      Dist)
                                      (dist.$bar(((x10.
                                                   array.
                                                   Region)(r)))))))),
                            ((x10.core.fun.Fun_0_1)((new x10.core.fun.Fun_0_1<x10.
                                                       array.
                                                       Point, T>() {public final T apply$G(final x10.
                                                       array.
                                                       Point p) { {
                                                         
//#line 330
return op.apply$G(x10.
                                                                                          array.
                                                                                          DistArray.this.apply$G(((x10.
                                                                                                                   array.
                                                                                                                   Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                                   array.
                                                                                                                   Point, x10.
                                                                                                                   array.
                                                                                                                   Point>() {public final x10.
                                                                                                                   array.
                                                                                                                   Point apply$G(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__18__) { return apply(__desugarer__var__18__);}
                                                                                                                 public final x10.
                                                                                                                   array.
                                                                                                                   Point apply(final x10.
                                                                                                                   array.
                                                                                                                   Point __desugarer__var__18__) { {
                                                                                                                     
//#line 330
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__18__,null)) &&
                                                                                                                                        !(((int) __desugarer__var__18__.
                                                                                                                                                   rank) ==
                                                                                                                                          ((int) x10.
                                                                                                                                                   array.
                                                                                                                                                   DistArray.this.
                                                                                                                                                   dist.
                                                                                                                                                   region.
                                                                                                                                                   rank))) {
                                                                                                                         
//#line 330
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                              "ion.rank}"));
                                                                                                                     }
                                                                                                                     
//#line 330
return __desugarer__var__18__;
                                                                                                                 }}
                                                                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                                 }
                                                                                                                 }.apply(((x10.
                                                                                                                           array.
                                                                                                                           Point)
                                                                                                                           p))))),
                                                                                        src.apply$G(((x10.
                                                                                                      array.
                                                                                                      Point)(new x10.core.fun.Fun_0_1<x10.
                                                                                                      array.
                                                                                                      Point, x10.
                                                                                                      array.
                                                                                                      Point>() {public final x10.
                                                                                                      array.
                                                                                                      Point apply$G(final x10.
                                                                                                      array.
                                                                                                      Point __desugarer__var__19__) { return apply(__desugarer__var__19__);}
                                                                                                    public final x10.
                                                                                                      array.
                                                                                                      Point apply(final x10.
                                                                                                      array.
                                                                                                      Point __desugarer__var__19__) { {
                                                                                                        
//#line 330
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__19__,null)) &&
                                                                                                                           !(((int) __desugarer__var__19__.
                                                                                                                                      rank) ==
                                                                                                                             ((int) x10.
                                                                                                                                      array.
                                                                                                                                      DistArray.this.
                                                                                                                                      dist.
                                                                                                                                      region.
                                                                                                                                      rank))) {
                                                                                                            
//#line 330
throw new java.lang.ClassCastException(("x10.array.Point{self.rank==x10.array.DistArray#this.dist.reg" +
                                                                                                                                                                 "ion.rank}"));
                                                                                                        }
                                                                                                        
//#line 330
return __desugarer__var__19__;
                                                                                                    }}
                                                                                                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return x10.array.Point._RTT;return null;
                                                                                                    }
                                                                                                    }.apply(((x10.
                                                                                                              array.
                                                                                                              Point)
                                                                                                              p))))));
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.array.Point._RTT;if (i ==1) return T;return null;
                                                     }
                                                     }))));
    }
    
    
//#line 332
public T
                   reduce$G(
                   final x10.core.fun.Fun_0_2<T,T,T> op,
                   final T unit){
        
//#line 335
final x10.core.ValRail<x10.
          lang.
          Place> ps =
          dist.places();
        
//#line 336
final x10.core.Rail<T> results =
          ((x10.core.Rail)(x10.core.RailFactory.<T>makeVarRail(T, ((int)(ps.
                                                                           length)), new x10.core.fun.Fun_0_1<java.lang.Integer, T>() {public final T apply$G(final java.lang.Integer p) { return apply$G((int)p);}
        public final T apply$G(final int p) { {
            
//#line 336
return unit;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return T;return null;
        }
        })));
        
//#line 337
final x10.
          array.
          Region r =
          ((x10.
          array.
          Region)(x10.
          array.
          Region.makeRectangular((int)(0),
                                 (int)((((((int)(ps.
                                                   length))) - (((int)(1)))))))));
        
//#line 340
try {{
            
//#line 340
x10.
              lang.
              Runtime.startFinish();
            {
                
//#line 340
for (x10.core.Iterator p__ = (r).iterator(); p__.hasNext(); ) { final  x10.
                  array.
                  Point p = (x10.
                  array.
                  Point) p__.next$G(); 
{
                    
//#line 340
x10.
                      lang.
                      Runtime.runAsync(((x10.
                                         lang.
                                         Place)(x10.
                                         lang.
                                         Runtime.here())),
                                       new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                           
//#line 341
(results).set$G(x10.
                                             lang.
                                             Runtime.<T>evalAt$G(T,
                                                                 ((x10.
                                                                   lang.
                                                                   Place)(((x10.
                                                                   lang.
                                                                   Place)((x10.
                                                                   lang.
                                                                   Place[])ps.value)[p.apply((int)(0))]))),
                                                                 ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<T>() {public final T apply$G() { {
                                                                     
//#line 342
T result =
                                                                       ((T)(unit));
                                                                     
//#line 343
final x10.
                                                                       array.
                                                                       DistArray<T> a =
                                                                       ((x10.
                                                                       array.
                                                                       DistArray)(new x10.core.fun.Fun_0_1<x10.
                                                                       array.
                                                                       DistArray<T>, x10.
                                                                       array.
                                                                       DistArray<T>>() {public final x10.
                                                                       array.
                                                                       DistArray<T> apply$G(final x10.
                                                                       array.
                                                                       DistArray<T> __desugarer__var__20__) { return apply(__desugarer__var__20__);}
                                                                     public final x10.
                                                                       array.
                                                                       DistArray<T> apply(final x10.
                                                                       array.
                                                                       DistArray<T> __desugarer__var__20__) { {
                                                                         
//#line 343
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__20__,null)) &&
                                                                                            !(((int) __desugarer__var__20__.
                                                                                                       dist.
                                                                                                       region.
                                                                                                       rank) ==
                                                                                              ((int) x10.
                                                                                                       array.
                                                                                                       DistArray.this.
                                                                                                       dist.
                                                                                                       region.
                                                                                                       rank))) {
                                                                             
//#line 343
throw new java.lang.ClassCastException(("x10.array.DistArray[T]{self.dist.region.rank==x10.array.Dist" +
                                                                                                                                  "Array#this.dist.region.rank}"));
                                                                         }
                                                                         
//#line 343
return __desugarer__var__20__;
                                                                     }}
                                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.array.DistArray._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.array.DistArray._RTT, T);return null;
                                                                     }
                                                                     }.apply(((x10.
                                                                               array.
                                                                               DistArray)
                                                                               (x10.
                                                                                  array.
                                                                                  DistArray.this.$bar(((x10.
                                                                                                        lang.
                                                                                                        Place)(x10.
                                                                                                        lang.
                                                                                                        Runtime.here()))))))));
                                                                     
//#line 344
for (
//#line 344
final x10.core.Iterator<x10.
                                                                                         array.
                                                                                         Point> pt1377 =
                                                                                         a.region().iterator();
                                                                                       pt1377.hasNext();
                                                                                       ) {
                                                                         
//#line 344
final x10.
                                                                           array.
                                                                           Point pt =
                                                                           ((x10.
                                                                           array.
                                                                           Point)(pt1377.next$G()));
                                                                         
//#line 345
result = ((T)(op.apply$G(result,
                                                                                                               a.apply$G(((x10.
                                                                                                                           array.
                                                                                                                           Point)(pt))))));
                                                                     }
                                                                     
//#line 346
return result;
                                                                 }}
                                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;return null;
                                                                 }
                                                                 }))), ((int)(p.apply((int)(0)))));
                                       }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                       }
                                       });
                } }
            }
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
        java.lang.Throwable __desugarer__var__21__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
        {
            
//#line 340
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__21__)));
            throw new java.lang.RuntimeException();
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (java.lang.Throwable __desugarer__var__21__) {
            
//#line 340
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__21__)));
            throw new java.lang.RuntimeException();
        }finally {{
             
//#line 340
x10.
               lang.
               Runtime.stopFinish();
         }}
        
//#line 351
T result =
          ((T)(unit));
        
//#line 352
for (
//#line 352
int i =
                            0;
                          ((((int)(i))) < (((int)(results.
                                                    length))));
                          
//#line 352
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 353
result = ((T)(op.apply$G(result,
                                                  (results).apply$G(((int)(i))))));
        }
        
//#line 355
return result;
        }
    
    
//#line 382
public x10.
                   array.
                   DistArray<T>
                   scan(
                   final x10.core.fun.Fun_0_2<T,T,T> op,
                   final T unit){
        
//#line 382
throw new java.lang.RuntimeException("Incomplete method.");
    }
    
    
//#line 389
public x10.
                   array.
                   DistArray<T>
                   $bar(
                   final x10.
                     array.
                     Region r){
        
//#line 389
return this.restriction(((x10.
                                               array.
                                               Region)(r)));
    }
    
    
//#line 390
public x10.
                   array.
                   DistArray<T>
                   $bar(
                   final x10.
                     lang.
                     Place p){
        
//#line 390
return this.restriction(((x10.
                                               lang.
                                               Place)(p)));
    }
    
    
//#line 404
public static x10.
                   array.
                   RectLayout
                   layout(
                   final x10.
                     array.
                     Region r){
        
//#line 405
if (r.isEmpty()) {
            
//#line 407
final x10.core.ValRail<java.lang.Integer> min =
              ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$33$ = 0; id$33$ < length; id$33$++) {final int id$33 = id$33$;array[id$33] = 0;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, r.
                                                                                                                                                                                                                                                                                                                      rank, array);}}.apply(r.
                                                                                                                                                                                                                                                                                                                                              rank))));
            
//#line 408
final x10.core.ValRail<java.lang.Integer> max =
              ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$34$ = 0; id$34$ < length; id$34$++) {final int id$34 = id$34$;array[id$34] = -1;}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, r.
                                                                                                                                                                                                                                                                                                                       rank, array);}}.apply(r.
                                                                                                                                                                                                                                                                                                                                               rank))));
            
//#line 409
return new x10.
              array.
              RectLayout(min,
                         max);
        } else {
            
//#line 411
return new x10.
              array.
              RectLayout(r.min(),
                         r.max());
        }
    }
    
    
//#line 415
public java.lang.String
                   toString(
                   ){
        
//#line 416
return (((("Array(") + (dist))) + (")"));
    }
    
    
//#line 426
public x10.core.Iterator<x10.
                   array.
                   Point>
                   iterator(
                   ){
        
//#line 426
return ((x10.core.Iterator)
                              this.region().iterator());
    }
    
    
//#line 429
private void
                   raiseBoundsError(
                   final int i0){
        
//#line 430
throw new java.lang.ArrayIndexOutOfBoundsException((((("point (") + (((java.lang.Integer)(i0))))) + (") not contained in array")));
    }
    
    public static <T> void
      raiseBoundsError$P(
      final x10.rtt.Type T,
      final int i0,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raiseBoundsError((int)(i0));
    }
    
    
//#line 432
private void
                   raiseBoundsError(
                   final int i0,
                   final int i1){
        
//#line 433
throw new java.lang.ArrayIndexOutOfBoundsException((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (") not contained in array")));
    }
    
    public static <T> void
      raiseBoundsError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raiseBoundsError((int)(i0),
                                   (int)(i1));
    }
    
    
//#line 435
private void
                   raiseBoundsError(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 436
throw new java.lang.ArrayIndexOutOfBoundsException((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (") not contained in array")));
    }
    
    public static <T> void
      raiseBoundsError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final int i2,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raiseBoundsError((int)(i0),
                                   (int)(i1),
                                   (int)(i2));
    }
    
    
//#line 438
private void
                   raiseBoundsError(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 439
throw new java.lang.ArrayIndexOutOfBoundsException((((((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (", "))) + (((java.lang.Integer)(i3))))) + (") not contained in array")));
    }
    
    public static <T> void
      raiseBoundsError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final int i2,
      final int i3,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raiseBoundsError((int)(i0),
                                   (int)(i1),
                                   (int)(i2),
                                   (int)(i3));
    }
    
    
//#line 441
private void
                   raiseBoundsError(
                   final x10.
                     array.
                     Point pt){
        
//#line 442
throw new java.lang.ArrayIndexOutOfBoundsException((((("point ") + (pt))) + (" not contained in array")));
    }
    
    public static <T> void
      raiseBoundsError$P(
      final x10.rtt.Type T,
      final x10.
        array.
        Point pt,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raiseBoundsError(((x10.
                                     array.
                                     Point)(pt)));
    }
    
    
//#line 446
private void
                   raisePlaceError(
                   final int i0){
        
//#line 447
throw new x10.
          lang.
          BadPlaceException((((((("point (") + (((java.lang.Integer)(i0))))) + (") not defined at "))) + (x10.
                              lang.
                              Runtime.here())));
    }
    
    public static <T> void
      raisePlaceError$P(
      final x10.rtt.Type T,
      final int i0,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raisePlaceError((int)(i0));
    }
    
    
//#line 449
private void
                   raisePlaceError(
                   final int i0,
                   final int i1){
        
//#line 450
throw new x10.
          lang.
          BadPlaceException((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (") not defined at "))) + (x10.
                              lang.
                              Runtime.here())));
    }
    
    public static <T> void
      raisePlaceError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raisePlaceError((int)(i0),
                                  (int)(i1));
    }
    
    
//#line 452
private void
                   raisePlaceError(
                   final int i0,
                   final int i1,
                   final int i2){
        
//#line 453
throw new x10.
          lang.
          BadPlaceException((((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (") not defined at "))) + (x10.
                              lang.
                              Runtime.here())));
    }
    
    public static <T> void
      raisePlaceError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final int i2,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raisePlaceError((int)(i0),
                                  (int)(i1),
                                  (int)(i2));
    }
    
    
//#line 455
private void
                   raisePlaceError(
                   final int i0,
                   final int i1,
                   final int i2,
                   final int i3){
        
//#line 456
throw new x10.
          lang.
          BadPlaceException((((((((((((((((((("point (") + (((java.lang.Integer)(i0))))) + (", "))) + (((java.lang.Integer)(i1))))) + (", "))) + (((java.lang.Integer)(i2))))) + (", "))) + (((java.lang.Integer)(i3))))) + (") not defined at "))) + (x10.
                              lang.
                              Runtime.here())));
    }
    
    public static <T> void
      raisePlaceError$P(
      final x10.rtt.Type T,
      final int i0,
      final int i1,
      final int i2,
      final int i3,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raisePlaceError((int)(i0),
                                  (int)(i1),
                                  (int)(i2),
                                  (int)(i3));
    }
    
    
//#line 458
private void
                   raisePlaceError(
                   final x10.
                     array.
                     Point pt){
        
//#line 459
throw new x10.
          lang.
          BadPlaceException((((((("point ") + (pt))) + (" not defined at "))) + (x10.
                              lang.
                              Runtime.here())));
    }
    
    public static <T> void
      raisePlaceError$P(
      final x10.rtt.Type T,
      final x10.
        array.
        Point pt,
      final x10.
        array.
        DistArray<T> DistArray){
        DistArray.raisePlaceError(((x10.
                                    array.
                                    Point)(pt)));
    }
    
    
//#line 30
final public x10.
                  array.
                  Dist
                  dist(
                  ){
        
//#line 30
return this.
                             dist;
    }
    
    }
    