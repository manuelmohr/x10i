package x10.util;

public class ArrayList<T>
extends x10.
  util.
  AbstractCollection<T>
  implements x10.
               util.
               List<T>
{public static final x10.rtt.RuntimeType<ArrayList> _RTT = new x10.rtt.RuntimeType<ArrayList>(
/* base class */ArrayList.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.List._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.UnresolvedType(0))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
// bridge for method abstract public x10.lang.Settable.set(v:V,i:I): V
public T
  set$G(T a1,
java.lang.Integer a2){return set$G( a1,
(int) a2);}

    private final x10.rtt.Type T;
    
    
//#line 16
final public x10.core.GrowableRail<T>
      a;
    
    
//#line 18
public static <T> x10.
                  util.
                  ArrayList<T>
                  make(
                  final x10.rtt.Type T,
                  final x10.
                    util.
                    Container<T> c){
        
//#line 19
final x10.
          util.
          ArrayList<T> a =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<T>(T)));
        
//#line 20
a.addAll(((x10.
                               util.
                               Container)(c)));
        
//#line 21
return a;
    }
    
    
//#line 24
public boolean
                  contains(
                  final T v){
        
//#line 25
for (
//#line 25
int i =
                           0;
                         ((((int)(i))) < (((int)((a).length()))));
                         
//#line 25
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 26
if (x10.rtt.Equality.equalsequals(v,null)
                              ? x10.rtt.Equality.equalsequals((a).apply$G(((int)(i))),null)
                              : ((java.lang.Object)(((java.lang.Object)(v)))).equals((a).apply$G(((int)(i))))) {
                
//#line 27
return true;
            }
        }
        
//#line 30
return false;
    }
    
    
//#line 33
public x10.
                  util.
                  ArrayList<T>
                  clone(
                  ){
        
//#line 34
final x10.
          util.
          ArrayList<T> a =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<T>(T)));
        
//#line 35
a.addAll(((x10.
                               util.
                               Container)(this)));
        
//#line 36
return a;
    }
    
    
//#line 39
public boolean
                  add(
                  final T v){
        
//#line 40
(a).add(v);
        
//#line 41
return true;
    }
    
    
//#line 44
public boolean
                  remove(
                  final T v){
        
//#line 45
for (
//#line 45
int i =
                           0;
                         ((((int)(i))) < (((int)((a).length()))));
                         
//#line 45
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 46
if (x10.rtt.Equality.equalsequals(v,null)
                              ? x10.rtt.Equality.equalsequals((a).apply$G(((int)(i))),null)
                              : ((java.lang.Object)(((java.lang.Object)(v)))).equals((a).apply$G(((int)(i))))) {
                
//#line 47
this.removeAt$G((int)(i));
                
//#line 48
return true;
            }
        }
        
//#line 51
return false;
    }
    
    
//#line 54
public void
                  addBefore(
                  final int i,
                  final T v){
        
//#line 55
(a).add(v);
        
//#line 56
for (
//#line 56
int j =
                           ((((int)(i))) + (((int)(1))));
                         ((((int)(j))) < (((int)((a).length()))));
                         
//#line 56
j = ((((int)(j))) + (((int)(1))))) {
            
//#line 57
(a).set$G((a).apply$G(((int)(((((int)(j))) - (((int)(1))))))), ((int)(j)));
        }
        
//#line 59
(a).set$G(v, ((int)(i)));
    }
    
    
//#line 62
public T
                  set$G(
                  final T v,
                  final int i){
        
//#line 63
(a).set$G(v, ((int)(i)));
        
//#line 64
return v;
    }
    
    
//#line 67
public T
                  removeAt$G(
                  final int i){
        
//#line 68
final T v =
          ((T)((a).apply$G(((int)(i)))));
        
//#line 69
for (
//#line 69
int j =
                           ((((int)(i))) + (((int)(1))));
                         ((((int)(j))) < (((int)((a).length()))));
                         
//#line 69
j = ((((int)(j))) + (((int)(1))))) {
            
//#line 70
(a).set$G((a).apply$G(((int)(j))), ((int)(((((int)(j))) - (((int)(1)))))));
        }
        
//#line 72
(a).removeLast();
        
//#line 73
return v;
    }
    
    
//#line 76
public T
                  apply$G(
                  final int i){
        
//#line 76
return (a).apply$G(((int)(i)));
    }
    
    
//#line 78
public T
                  get$G(
                  final int i){
        
//#line 78
return (a).apply$G(((int)(i)));
    }
    
    
//#line 80
public int
                  size(
                  ){
        
//#line 80
return (a).length();
    }
    
    
//#line 82
public boolean
                  isEmpty(
                  ){
        
//#line 82
return ((int) this.size()) ==
        ((int) 0);
    }
    
    
//#line 85
public x10.core.Rail<T>
                  toArray(
                  ){
        
//#line 85
return (a).toRail();
    }
    
    
//#line 86
public x10.core.Rail<T>
                  toRail(
                  ){
        
//#line 86
return (a).toRail();
    }
    
    
//#line 87
public x10.core.ValRail<T>
                  toValRail(
                  ){
        
//#line 87
return (a).toValRail();
    }
    
    
//#line 89
public ArrayList(final x10.rtt.Type T) {
                                                                super(T);
                                                            this.T = T;
                                                             {
                                                                
//#line 90
this.a = ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T)));
                                                            }}
    
    
//#line 93
public ArrayList(final x10.rtt.Type T,
                                 final int size) {
                                                          super(T);
                                                      this.T = T;
                                                       {
                                                          
//#line 94
this.a = ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T,
                                                                                                                                     size)));
                                                      }}
    
    
//#line 97
public T
                  removeFirst$G(
                  ){
        
//#line 97
return this.removeAt$G((int)(0));
    }
    
    
//#line 98
public T
                  removeLast$G(
                  ){
        
//#line 98
return this.removeAt$G((int)(((((int)((a).length()))) - (((int)(1))))));
    }
    
    
//#line 99
public T
                  getFirst$G(
                  ){
        
//#line 99
return this.get$G((int)(0));
    }
    
    
//#line 100
public T
                   getLast$G(
                   ){
        
//#line 100
return this.get$G((int)(((((int)((a).length()))) - (((int)(1))))));
    }
    
    
//#line 102
public x10.
                   util.
                   List<java.lang.Integer>
                   indices(
                   ){
        
//#line 103
final x10.
          util.
          ArrayList<java.lang.Integer> l =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<java.lang.Integer>(x10.rtt.Types.INT)));
        
//#line 104
for (
//#line 104
int i =
                            0;
                          ((((int)(i))) < (((int)((a).length()))));
                          
//#line 104
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 105
l.add((java.lang.Integer)(i));
        }
        
//#line 107
return l;
    }
    
    
//#line 110
public x10.
                   util.
                   List<T>
                   subList(
                   final int begin,
                   final int end){
        
//#line 111
final x10.
          util.
          ArrayList<T> l =
          ((x10.
          util.
          ArrayList)(new x10.
          util.
          ArrayList<T>(T)));
        
//#line 112
for (
//#line 112
int i =
                            begin;
                          ((((int)(i))) < (((int)((a).length())))) &&
                          ((((int)(i))) < (((int)(end))));
                          
//#line 112
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 113
l.add(((T)((a).apply$G(((int)(i))))));
        }
        
//#line 115
return l;
    }
    
    
//#line 118
public int
                   indexOf(
                   final T v){
        
//#line 119
return this.indexOf((int)(0),
                                         ((T)(v)));
    }
    
    
//#line 122
public int
                   indexOf(
                   final int index,
                   final T v){
        
//#line 123
for (
//#line 123
int i =
                            index;
                          ((((int)(i))) < (((int)((a).length()))));
                          
//#line 123
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 124
if (x10.rtt.Equality.equalsequals(v,null)
                               ? x10.rtt.Equality.equalsequals((a).apply$G(((int)(i))),null)
                               : ((java.lang.Object)(((java.lang.Object)(v)))).equals((a).apply$G(((int)(i))))) {
                
//#line 125
return i;
            }
        }
        
//#line 127
return -1;
    }
    
    
//#line 130
public int
                   lastIndexOf(
                   final T v){
        
//#line 131
return this.lastIndexOf((int)(((((int)((a).length()))) - (((int)(1))))),
                                             ((T)(v)));
    }
    
    
//#line 134
public int
                   lastIndexOf(
                   final int index,
                   final T v){
        
//#line 135
for (
//#line 135
int i =
                            index;
                          ((((int)(i))) >= (((int)(0))));
                          
//#line 135
i = ((((int)(i))) - (((int)(1))))) {
            
//#line 136
if (x10.rtt.Equality.equalsequals(v,null)
                               ? x10.rtt.Equality.equalsequals((a).apply$G(((int)(i))),null)
                               : ((java.lang.Object)(((java.lang.Object)(v)))).equals((a).apply$G(((int)(i))))) {
                
//#line 137
return i;
            }
        }
        
//#line 139
return -1;
    }
    
    
//#line 141
public x10.core.ValRail<T>
                   moveSectionToValRail(
                   final int i,
                   final int j){
        
//#line 142
return (a).moveSectionToValRail(((int)(i)), ((int)(j)));
    }
    
    
//#line 148
public static class It<S>
                 extends x10.core.Ref
                   implements x10.
                                util.
                                ListIterator<S>
                 {public static final x10.rtt.RuntimeType<It> _RTT = new x10.rtt.RuntimeType<It>(
    /* base class */It.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.ListIterator._RTT, new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return S;return null;}
    
        private final x10.rtt.Type S;
        
        
//#line 150
public int
          i;
        
//#line 151
final public x10.
          util.
          ArrayList<S>
          al;
        
        
//#line 153
public It(final x10.rtt.Type S,
                               final x10.
                                 util.
                                 ArrayList<S> al) {
                                                           
//#line 154
this(S,
                                                                             al,
                                                                             -1);
                                                        {
                                                           
                                                       }}
        
        
//#line 157
public It(final x10.rtt.Type S,
                               final x10.
                                 util.
                                 ArrayList<S> al,
                               final int i) {
                                                     super();
                                                 this.S = S;
                                                  {
                                                     
//#line 150
this.i = 0;
                                                     
//#line 158
this.al = ((x10.
                                                       util.
                                                       ArrayList)(al));
                                                     
//#line 159
this.i = i;
                                                 }}
        
        
//#line 162
public boolean
                       hasNext(
                       ){
            
//#line 163
return ((((int)(((((int)(i))) + (((int)(1))))))) < (((int)(al.size()))));
        }
        
        
//#line 166
public int
                       nextIndex(
                       ){
            
//#line 167
return x10.
              util.
              ArrayList.
              It.<S>__$closure$apply$__2070(S,
                                            ((x10.
                                              util.
                                              ArrayList.
                                              It)(this)),
                                            (int)(1));
        }
        
        
//#line 170
public S
                       next$G(
                       ){
            
//#line 171
return (al.
                                   a).apply$G(x10.
              util.
              ArrayList.
              It.<S>__$closure$apply$__2071(S,
                                            ((x10.
                                              util.
                                              ArrayList.
                                              It)(this)),
                                            (int)(1)));
        }
        
        
//#line 174
public boolean
                       hasPrevious(
                       ){
            
//#line 175
return ((((int)(((((int)(i))) - (((int)(1))))))) >= (((int)(0))));
        }
        
        
//#line 178
public int
                       previousIndex(
                       ){
            
//#line 179
return x10.
              util.
              ArrayList.
              It.<S>__$closure$apply$__2072(S,
                                            ((x10.
                                              util.
                                              ArrayList.
                                              It)(this)),
                                            (int)(1));
        }
        
        
//#line 182
public S
                       previous$G(
                       ){
            
//#line 183
return (al.
                                   a).apply$G(x10.
              util.
              ArrayList.
              It.<S>__$closure$apply$__2073(S,
                                            ((x10.
                                              util.
                                              ArrayList.
                                              It)(this)),
                                            (int)(1)));
        }
        
        
//#line 186
public void
                       remove(
                       ){
            
//#line 187
al.removeAt$G((int)(i));
        }
        
        
//#line 190
public void
                       set(
                       final S v){
            
//#line 191
al.set$G(((S)(v)),
                                  (int)(i));
        }
        
        
//#line 194
public void
                       add(
                       final S v){
            
//#line 195
al.addBefore((int)(i),
                                      ((S)(v)));
        }
        
        final private static <S> int
          __$closure$apply$__2070(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            
//#line 167
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <S> int
          __$closure$apply$__2070$P(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            return It.<S>__$closure$apply$__2070(S,
                                                 ((x10.
                                                   util.
                                                   ArrayList.
                                                   It)(x)),
                                                 (int)(y));
        }
        
        final private static <S> int
          __$closure$apply$__2071(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            
//#line 171
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <S> int
          __$closure$apply$__2071$P(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            return It.<S>__$closure$apply$__2071(S,
                                                 ((x10.
                                                   util.
                                                   ArrayList.
                                                   It)(x)),
                                                 (int)(y));
        }
        
        final private static <S> int
          __$closure$apply$__2072(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            
//#line 179
return x.i = ((((int)(x.
                                                 i))) - (((int)(y))));
        }
        
        final public static <S> int
          __$closure$apply$__2072$P(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            return It.<S>__$closure$apply$__2072(S,
                                                 ((x10.
                                                   util.
                                                   ArrayList.
                                                   It)(x)),
                                                 (int)(y));
        }
        
        final private static <S> int
          __$closure$apply$__2073(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            
//#line 183
return x.i = ((((int)(x.
                                                 i))) - (((int)(y))));
        }
        
        final public static <S> int
          __$closure$apply$__2073$P(
          final x10.rtt.Type S,
          final x10.
            util.
            ArrayList.
            It<S> x,
          final int y){
            return It.<S>__$closure$apply$__2073(S,
                                                 ((x10.
                                                   util.
                                                   ArrayList.
                                                   It)(x)),
                                                 (int)(y));
        }
    
    }
    
    
    
//#line 199
public x10.
                   util.
                   ListIterator<T>
                   iterator(
                   ){
        
//#line 200
return new x10.
          util.
          ArrayList.
          It<T>(T,
                this);
    }
    
    
//#line 203
public x10.
                   util.
                   ListIterator<T>
                   iteratorFrom(
                   final int i){
        
//#line 204
return new x10.
          util.
          ArrayList.
          It<T>(T,
                this,
                i);
    }
    
    
//#line 207
public void
                   reverse(
                   ){
        
//#line 208
final int length =
          (a).length();
        
//#line 209
for (
//#line 209
int i =
                            0;
                          ((((int)(i))) < (((int)(((((int)(length))) / (((int)(2))))))));
                          
//#line 209
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 210
this.exch(((x10.core.GrowableRail)(a)),
                                   (int)(i),
                                   (int)(((((int)(((((int)(length))) - (((int)(1))))))) - (((int)(i))))));
        }
    }
    
    
//#line 215
public void
                   sort(
                   ){
        {
            
//#line 215
this.sort(((x10.core.fun.Fun_0_2)(new x10.core.fun.Fun_0_2<T, T, java.lang.Integer>() {public final java.lang.Integer apply$G(final T x,final T y) { return apply(x,y);}
                                   public final int apply(final T x, final T y) { {
                                       
//#line 215
return (x10.
                                                              util.
                                                              ArrayList.<T>__$closure$apply$__2074(T,
                                                                                                   ((x10.
                                                                                                     lang.
                                                                                                     Comparable)((new java.lang.Object() {final x10.
                                                                                                     lang.
                                                                                                     Comparable cast(final x10.
                                                                                                     lang.
                                                                                                     Comparable self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Comparable._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                                                     lang.
                                                                                                     Comparable) x)))))).compareTo(((T)(y)));
                                   }}
                                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return T;if (i ==2) return x10.rtt.Types.INT;return null;
                                   }
                                   })));
            
//#line 215
return;
        }
    }
    
    
//#line 216
public void
                   sort(
                   final x10.core.fun.Fun_0_2<T,T,java.lang.Integer> cmp){
        {
            
//#line 216
this.qsort(((x10.core.GrowableRail)(a)),
                                    (int)(0),
                                    (int)(((((int)((a).length()))) - (((int)(1))))),
                                    ((x10.core.fun.Fun_0_2)(cmp)));
            
//#line 216
return;
        }
    }
    
    
//#line 227
private void
                   qsort(
                   final x10.core.GrowableRail<T> a,
                   final int lo,
                   final int hi,
                   final x10.core.fun.Fun_0_2<T,T,java.lang.Integer> cmp){
        
//#line 228
if (((((int)(hi))) <= (((int)(lo))))) {
            
//#line 228
return;
        }
        
//#line 229
int l =
          ((((int)(lo))) - (((int)(1))));
        
//#line 230
int h =
          hi;
        
//#line 231
while (true) {
            
//#line 232
while (((((int)(cmp.apply$G((a).apply$G(((int)(l = ((((int)(l))) + (((int)(1))))))),
                                                     (a).apply$G(((int)(hi))))))) < (((int)(0)))))
                
//#line 232
;
            
//#line 233
while (((((int)(cmp.apply$G((a).apply$G(((int)(hi))),
                                                     (a).apply$G(((int)(h = ((((int)(h))) - (((int)(1))))))))))) < (((int)(0)))) &&
                                ((((int)(h))) > (((int)(lo)))))
                
//#line 233
;
            
//#line 234
if (((((int)(l))) >= (((int)(h))))) {
                
//#line 234
break;
            }
            
//#line 235
this.exch(((x10.core.GrowableRail)(a)),
                                   (int)(l),
                                   (int)(h));
        }
        
//#line 237
this.exch(((x10.core.GrowableRail)(a)),
                               (int)(l),
                               (int)(hi));
        
//#line 238
this.qsort(((x10.core.GrowableRail)(a)),
                                (int)(lo),
                                (int)(((((int)(l))) - (((int)(1))))),
                                ((x10.core.fun.Fun_0_2)(cmp)));
        
//#line 239
this.qsort(((x10.core.GrowableRail)(a)),
                                (int)(((((int)(l))) + (((int)(1))))),
                                (int)(hi),
                                ((x10.core.fun.Fun_0_2)(cmp)));
    }
    
    public static <T> void
      qsort$P(
      final x10.rtt.Type T,
      final x10.core.GrowableRail<T> a,
      final int lo,
      final int hi,
      final x10.core.fun.Fun_0_2<T,T,java.lang.Integer> cmp,
      final x10.
        util.
        ArrayList<T> ArrayList){
        ArrayList.qsort(((x10.core.GrowableRail)(a)),
                        (int)(lo),
                        (int)(hi),
                        ((x10.core.fun.Fun_0_2)(cmp)));
    }
    
    
//#line 242
private void
                   exch(
                   final x10.core.GrowableRail<T> a,
                   final int i,
                   final int j){
        
//#line 243
final T temp =
          ((T)((a).apply$G(((int)(i)))));
        
//#line 244
(a).set$G((a).apply$G(((int)(j))), ((int)(i)));
        
//#line 245
(a).set$G(temp, ((int)(j)));
    }
    
    public static <T> void
      exch$P(
      final x10.rtt.Type T,
      final x10.core.GrowableRail<T> a,
      final int i,
      final int j,
      final x10.
        util.
        ArrayList<T> ArrayList){
        ArrayList.exch(((x10.core.GrowableRail)(a)),
                       (int)(i),
                       (int)(j));
    }
    
    final private static <T> x10.
      lang.
      Comparable<T>
      __$closure$apply$__2074(
      final x10.rtt.Type T,
      final x10.
        lang.
        Comparable<T> __desugarer__var__72__){
        
//#line 215
if (!(x10.rtt.Equality.equalsequals(((x10.
                             lang.
                             Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__72__)))),x10.
                             lang.
                             Runtime.here()))) {
            
//#line 215
throw new java.lang.ClassCastException("x10.lang.Comparable[T]{self.home==here}");
        }
        
//#line 215
return __desugarer__var__72__;
    }
    
    final public static <T> x10.
      lang.
      Comparable<T>
      __$closure$apply$__2074$P(
      final x10.rtt.Type T,
      final x10.
        lang.
        Comparable<T> __desugarer__var__72__){
        return ArrayList.<T>__$closure$apply$__2074(T,
                                                    ((x10.
                                                      lang.
                                                      Comparable)(__desugarer__var__72__)));
    }

}
