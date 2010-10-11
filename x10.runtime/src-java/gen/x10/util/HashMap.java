package x10.util;

public class HashMap<K, V>
extends x10.core.Ref
  implements x10.
               util.
               Map<K, V>
{public static final x10.rtt.RuntimeType<HashMap> _RTT = new x10.rtt.RuntimeType<HashMap>(
/* base class */HashMap.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Map._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return K;if (i ==1)return V;return null;}

    private final x10.rtt.Type K;
    private final x10.rtt.Type V;
    
    
//#line 15
public static class HashEntry<Key, Value>
                extends x10.core.Ref
                  implements x10.
                               util.
                               Map.
                               Entry<Key, Value>
                {public static final x10.rtt.RuntimeType<HashEntry> _RTT = new x10.rtt.RuntimeType<HashEntry>(
    /* base class */HashEntry.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
        
//#line 16
public Key
                      getKey$G(
                      ){
            
//#line 16
return key;
        }
        
        
//#line 17
public Value
                      getValue$G(
                      ){
            
//#line 17
return value;
        }
        
        
//#line 18
public void
                      setValue(
                      final Value v){
            
//#line 18
this.value = ((Value)(v));
        }
        
        
//#line 20
final public Key
          key;
        
//#line 21
public Value
          value;
        
//#line 22
public boolean
          removed;
        
//#line 23
final public int
          hash;
        
        
//#line 25
public HashEntry(final x10.rtt.Type Key,
                                     final x10.rtt.Type Value,
                                     final Key key,
                                     final Value value,
                                     final int h) {
                                                           super();
                                                       this.Key = Key;
                                                       this.Value = Value;
                                                        {
                                                           
//#line 22
this.removed = false;
                                                           
//#line 26
this.key = ((Key)(key));
                                                           
//#line 27
this.value = ((Value)(value));
                                                           
//#line 28
this.hash = h;
                                                           
//#line 29
this.removed = false;
                                                       }}
    
    }
    
    
//#line 34
/** The actual table, must be of size 2**n */public x10.core.Rail<x10.
      util.
      HashMap.
      HashEntry<K, V>>
      table;
    
//#line 37
/** Number of non-null, non-removed entries in the table. */public int
      size;
    
//#line 40
/** Number of non-null entries in the table. */public int
      occupation;
    
//#line 43
/** table.length - 1 */public int
      mask;
    
//#line 45
public int
      modCount;
    
//#line 47
public boolean
      shouldRehash;
    
//#line 49
final public static int
      MAX_PROBES =
      3;
    
//#line 50
final public static int
      MIN_SIZE =
      4;
    
    
//#line 52
public HashMap(final x10.rtt.Type K,
                               final x10.rtt.Type V) {
                                                              super();
                                                          this.K = K;
                                                          this.V = V;
                                                           {
                                                              
//#line 34
this.table = null;
                                                              
//#line 37
this.size = 0;
                                                              
//#line 40
this.occupation = 0;
                                                              
//#line 43
this.mask = 0;
                                                              
//#line 45
this.modCount = 0;
                                                              
//#line 47
this.shouldRehash = false;
                                                              
//#line 53
this.init((int)(x10.
                                                                                      util.
                                                                                      HashMap.MIN_SIZE));
                                                          }}
    
    
//#line 56
public HashMap(final x10.rtt.Type K,
                               final x10.rtt.Type V,
                               int sz) {
                                                super();
                                            this.K = K;
                                            this.V = V;
                                             {
                                                
//#line 34
this.table = null;
                                                
//#line 37
this.size = 0;
                                                
//#line 40
this.occupation = 0;
                                                
//#line 43
this.mask = 0;
                                                
//#line 45
this.modCount = 0;
                                                
//#line 47
this.shouldRehash = false;
                                                
//#line 57
int pow2 =
                                                  x10.
                                                  util.
                                                  HashMap.MIN_SIZE;
                                                
//#line 58
while (((((int)(pow2))) < (((int)(sz)))))
                                                    
//#line 59
pow2 = ((((int)(pow2))) << (((int)(1))));
                                                
//#line 60
this.init((int)(pow2));
                                            }}
    
    
//#line 63
public void
                  init(
                  final int sz){
        
//#line 65
assert ((int) ((((((int)(sz))) & (((int)((-(((int)(sz))))))))))) ==
        ((int) sz);
        
//#line 66
assert ((((int)(sz))) >= (((int)(x10.
          util.
          HashMap.MIN_SIZE))));
        
//#line 68
this.table = ((x10.core.Rail)(x10.core.RailFactory.<x10.
          util.
          HashMap.
          HashEntry<K, V>>makeVarRail(new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, K, V), ((int)(sz)))));
        
//#line 69
this.mask = ((((int)(sz))) - (((int)(1))));
        
//#line 70
this.size = 0;
        
//#line 71
this.occupation = 0;
        
//#line 72
this.shouldRehash = false;
    }
    
    
//#line 75
public void
                  clear(
                  ){
        
//#line 76
x10.
          util.
          HashMap.<K,
        V>__$closure$apply$__2078(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(this)),
                                  (int)(1));
        
//#line 77
this.init((int)(x10.
                                util.
                                HashMap.MIN_SIZE));
    }
    
    
//#line 80
public int
                  hash(
                  final K k){
        
//#line 81
return ((((int)(((Object)(((java.lang.Object)(k)))).hashCode()))) * (((int)(17))));
    }
    
    
//#line 84
public x10.
                  util.
                  Box<V>
                  apply(
                  final K k){
        
//#line 84
return this.get(((K)(k)));
    }
    
    
//#line 86
public x10.
                  util.
                  Box<V>
                  get(
                  final K k){
        
//#line 87
final x10.
          util.
          HashMap.
          HashEntry<K, V> e =
          ((x10.
          util.
          HashMap.
          HashEntry)(this.getEntry(((K)(k)))));
        
//#line 88
if (x10.rtt.Equality.equalsequals(e,null) ||
                        e.
                          removed) {
            
//#line 88
return null;
        }
        
//#line 89
return x10.
          util.
          Box.<V>$implicit_convert(V,
                                   ((V)(e.
                                          value)));
    }
    
    
//#line 92
public V
                  getOrElse$G(
                  final K k,
                  final V orelse){
        
//#line 93
final x10.
          util.
          HashMap.
          HashEntry<K, V> e =
          ((x10.
          util.
          HashMap.
          HashEntry)(this.getEntry(((K)(k)))));
        
//#line 94
if (x10.rtt.Equality.equalsequals(e,null) ||
                        e.
                          removed) {
            
//#line 94
return orelse;
        }
        
//#line 95
return e.
                             value;
    }
    
    
//#line 98
public V
                  getOrThrow$G(
                  final K k)
                      throws x10.
                  util.
                  NoSuchElementException{
        
//#line 99
final x10.
          util.
          HashMap.
          HashEntry<K, V> e =
          ((x10.
          util.
          HashMap.
          HashEntry)(this.getEntry(((K)(k)))));
        
//#line 100
if (x10.rtt.Equality.equalsequals(e,null) ||
                         e.
                           removed) {
            
//#line 100
throw new x10.
              util.
              NoSuchElementException("Not found");
        }
        
//#line 101
return e.
                              value;
    }
    
    
//#line 104
public x10.
                   util.
                   HashMap.
                   HashEntry<K, V>
                   getEntry(
                   final K k){
        
//#line 105
if (((int) size) ==
                         ((int) 0)) {
            
//#line 106
return null;
        }
        
//#line 112
final int h =
          this.hash(((K)(k)));
        
//#line 114
int i =
          h;
        
//#line 116
while (true) {
            
//#line 117
final int j =
              ((((int)(i))) & (((int)(mask))));
            
//#line 118
i = ((((int)(i))) + (((int)(1))));
            
//#line 120
final x10.
              util.
              HashMap.
              HashEntry<K, V> e =
              ((x10.
              util.
              HashMap.
              HashEntry)(((x10.
              util.
              HashMap.
              HashEntry<K, V>)((x10.
              util.
              HashMap.
              HashEntry[])table.value)[j])));
            
//#line 121
if (x10.rtt.Equality.equalsequals(e,null)) {
                
//#line 122
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(x10.
                                   util.
                                   HashMap.MAX_PROBES))))) {
                    
//#line 123
this.shouldRehash = true;
                }
                
//#line 124
return null;
            }
            
//#line 126
if ((!x10.rtt.Equality.equalsequals(e,null))) {
                
//#line 127
if (((int) e.
                                          hash) ==
                                 ((int) h) &&
                                 ((java.lang.Object)(((java.lang.Object)(k)))).equals(e.
                                                                                        key)) {
                    
//#line 128
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(x10.
                                       util.
                                       HashMap.MAX_PROBES))))) {
                        
//#line 129
this.shouldRehash = true;
                    }
                    
//#line 130
return e;
                }
                
//#line 132
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(table.
                                                                                       length))))) {
                    
//#line 133
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(x10.
                                       util.
                                       HashMap.MAX_PROBES))))) {
                        
//#line 134
this.shouldRehash = true;
                    }
                    
//#line 135
return null;
                }
            }
        }
    }
    
    
//#line 141
public x10.
                   util.
                   Box<V>
                   put(
                   final K k,
                   final V v){
        
//#line 142
if (((int) occupation) ==
                         ((int) table.
                                  length) ||
                         ((shouldRehash &&
                           ((((int)(occupation))) >= (((int)(((((int)(table.
                                                                        length))) / (((int)(2))))))))))) {
            
//#line 143
this.rehash();
        }
        
//#line 145
final int h =
          this.hash(((K)(k)));
        
//#line 146
int i =
          h;
        
//#line 148
while (true) {
            
//#line 149
final int j =
              ((((int)(i))) & (((int)(mask))));
            
//#line 150
i = ((((int)(i))) + (((int)(1))));
            
//#line 152
final x10.
              util.
              HashMap.
              HashEntry<K, V> e =
              ((x10.
              util.
              HashMap.
              HashEntry)(((x10.
              util.
              HashMap.
              HashEntry<K, V>)((x10.
              util.
              HashMap.
              HashEntry[])table.value)[j])));
            
//#line 153
if (x10.rtt.Equality.equalsequals(e,null)) {
                
//#line 154
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(x10.
                                   util.
                                   HashMap.MAX_PROBES))))) {
                    
//#line 155
this.shouldRehash = true;
                }
                
//#line 156
x10.
                  util.
                  HashMap.<K,
                V>__$closure$apply$__2079(K,
                                          V,
                                          ((x10.
                                            util.
                                            HashMap)(this)),
                                          (int)(1));
                
//#line 157
((x10.
                  util.
                  HashMap.
                  HashEntry[])table.value)[j] = new x10.
                  util.
                  HashMap.
                  HashEntry<K, V>(K,
                                  V,
                                  k,
                                  v,
                                  h);
                
//#line 158
x10.
                  util.
                  HashMap.<K,
                V>__$closure$apply$__2080(K,
                                          V,
                                          ((x10.
                                            util.
                                            HashMap)(this)),
                                          (int)(1));
                
//#line 159
x10.
                  util.
                  HashMap.<K,
                V>__$closure$apply$__2081(K,
                                          V,
                                          ((x10.
                                            util.
                                            HashMap)(this)),
                                          (int)(1));
                
//#line 160
return null;
            } else {
                
//#line 161
if (((int) e.
                                          hash) ==
                                 ((int) h) &&
                                 ((java.lang.Object)(((java.lang.Object)(k)))).equals(e.
                                                                                        key)) {
                    
//#line 164
final V old =
                      ((V)(e.
                             value));
                    
//#line 165
e.value = ((V)(v));
                    
//#line 166
if (e.
                                       removed) {
                        
//#line 167
e.removed = false;
                        
//#line 168
x10.
                          util.
                          HashMap.<K,
                        V>__$closure$apply$__2082(K,
                                                  V,
                                                  ((x10.
                                                    util.
                                                    HashMap)(this)),
                                                  (int)(1));
                        
//#line 169
return null;
                    }
                    
//#line 171
return x10.
                      util.
                      Box.<V>$implicit_convert(V,
                                               ((V)((((V)
                                                       old)))));
                }
            }
        }
    }
    
    
//#line 176
public void
                   rehash(
                   ){
        
//#line 177
x10.
          util.
          HashMap.<K,
        V>__$closure$apply$__2083(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(this)),
                                  (int)(1));
        
//#line 178
final x10.core.Rail<x10.
          util.
          HashMap.
          HashEntry<K, V>> t =
          ((x10.core.Rail)(table));
        
//#line 179
final int oldSize =
          size;
        
//#line 180
this.table = ((x10.core.Rail)(x10.core.RailFactory.<x10.
          util.
          HashMap.
          HashEntry<K, V>>makeVarRail(new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, K, V), ((int)(((((int)(t.
                                                                                                                              length))) * (((int)(2)))))))));
        
//#line 181
this.mask = ((((int)(table.
                                            length))) - (((int)(1))));
        
//#line 182
this.size = 0;
        
//#line 183
this.occupation = 0;
        
//#line 184
this.shouldRehash = false;
        {
            
//#line 186
final x10.
              util.
              HashMap.
              HashEntry[] t$value2086 =
              ((x10.
              util.
              HashMap.
              HashEntry[])t.value);
            
//#line 186
for (
//#line 186
int i =
                                0;
                              ((((int)(i))) < (((int)(t.
                                                        length))));
                              
//#line 186
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 187
if ((!x10.rtt.Equality.equalsequals(((x10.
                                   util.
                                   HashMap.
                                   HashEntry<K, V>)t$value2086[i]),null)) &&
                                 (!(((boolean)(((x10.
                                                 util.
                                                 HashMap.
                                                 HashEntry<K, V>)t$value2086[i]).
                                                 removed))))) {
                    
//#line 188
this.put(((K)(((x10.
                                                 util.
                                                 HashMap.
                                                 HashEntry<K, V>)t$value2086[i]).
                                                 key)),
                                          ((V)(((x10.
                                                 util.
                                                 HashMap.
                                                 HashEntry<K, V>)t$value2086[i]).
                                                 value)));
                    
//#line 189
this.shouldRehash = false;
                }
            }
        }
        
//#line 192
assert ((int) size) ==
        ((int) oldSize);
        
//#line 193
this.size = oldSize;
    }
    
    
//#line 196
public boolean
                   containsKey(
                   final K k){
        
//#line 197
final x10.
          util.
          HashMap.
          HashEntry<K, V> e =
          ((x10.
          util.
          HashMap.
          HashEntry)(this.getEntry(((K)(k)))));
        
//#line 198
return (!x10.rtt.Equality.equalsequals(e,null)) &&
        (!(((boolean)(e.
                        removed))));
    }
    
    
//#line 201
public x10.
                   util.
                   Box<V>
                   remove(
                   final K k){
        
//#line 202
x10.
          util.
          HashMap.<K,
        V>__$closure$apply$__2084(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(this)),
                                  (int)(1));
        
//#line 203
final x10.
          util.
          HashMap.
          HashEntry<K, V> e =
          ((x10.
          util.
          HashMap.
          HashEntry)(this.getEntry(((K)(k)))));
        
//#line 204
if ((!x10.rtt.Equality.equalsequals(e,null)) &&
                         (!(((boolean)(e.
                                         removed))))) {
            
//#line 205
x10.
              util.
              HashMap.<K,
            V>__$closure$apply$__2085(K,
                                      V,
                                      ((x10.
                                        util.
                                        HashMap)(this)),
                                      (int)(1));
            
//#line 206
e.removed = true;
            
//#line 207
return x10.
              util.
              Box.<V>$implicit_convert(V,
                                       ((V)(e.
                                              value)));
        }
        
//#line 209
return null;
    }
    
    
//#line 212
public x10.
                   util.
                   Set<K>
                   keySet(
                   ){
        
//#line 212
return new x10.
          util.
          HashMap.
          KeySet<K, V>(K,
                       V,
                       this);
    }
    
    
//#line 213
public x10.
                   util.
                   Set<x10.
                   util.
                   Map.
                   Entry<K, V>>
                   entries(
                   ){
        
//#line 213
return new x10.
          util.
          HashMap.
          EntrySet<K, V>(K,
                         V,
                         this);
    }
    
    
//#line 215
public x10.core.Iterator<x10.
                   util.
                   HashMap.
                   HashEntry<K, V>>
                   entriesIterator(
                   ){
        
//#line 216
final x10.
          util.
          HashMap.
          EntriesIterator<K, V> iterator =
          ((x10.
          util.
          HashMap.
          EntriesIterator)(new x10.
          util.
          HashMap.
          EntriesIterator<K, V>(K,
                                V,
                                this)));
        
//#line 217
iterator.advance();
        
//#line 218
return iterator;
    }
    
    
//#line 221
public static class EntriesIterator<Key, Value>
                 extends x10.core.Ref
                   implements x10.core.Iterator<x10.
                                util.
                                HashMap.
                                HashEntry<Key, Value>>
                 {public static final x10.rtt.RuntimeType<EntriesIterator> _RTT = new x10.rtt.RuntimeType<EntriesIterator>(
    /* base class */EntriesIterator.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.CONTRAVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1))), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    // bridge for method abstract public x10.lang.Iterator.next(): T
    public x10.
      util.
      HashMap.
      HashEntry<Key, Value>
      next$G(){return next();}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 222
final public x10.
          util.
          HashMap<Key, Value>
          map;
        
//#line 223
public int
          i;
        
//#line 224
public int
          originalModCount;
        
        
//#line 226
public EntriesIterator(final x10.rtt.Type Key,
                                            final x10.rtt.Type Value,
                                            final x10.
                                              util.
                                              HashMap<Key, Value> map) {
                                                                                super();
                                                                            this.Key = Key;
                                                                            this.Value = Value;
                                                                             {
                                                                                
//#line 223
this.i = 0;
                                                                                
//#line 224
this.originalModCount = 0;
                                                                                
//#line 226
this.map = ((x10.
                                                                                  util.
                                                                                  HashMap)(map));
                                                                                
//#line 226
this.i = 0;
                                                                                
//#line 226
this.originalModCount = map.
                                                                                                                       modCount;
                                                                            }}
        
        
//#line 228
public void
                       advance(
                       ){
            
//#line 229
while (((((int)(i))) < (((int)(map.
                                                          table.
                                                          length))))) {
                
//#line 230
if ((!x10.rtt.Equality.equalsequals(((x10.
                                   util.
                                   HashMap.
                                   HashEntry<Key, Value>)((x10.
                                   util.
                                   HashMap.
                                   HashEntry[])map.
                                                 table.value)[i]),null)) &&
                                 (!(((boolean)(((x10.
                                                 util.
                                                 HashMap.
                                                 HashEntry<Key, Value>)((x10.
                                                 util.
                                                 HashMap.
                                                 HashEntry[])map.
                                                               table.value)[i]).
                                                 removed))))) {
                    
//#line 231
return;
                }
                
//#line 232
x10.
                  util.
                  HashMap.
                  EntriesIterator.<Key,
                Value>__$closure$apply$__2076(Key,
                                              Value,
                                              ((x10.
                                                util.
                                                HashMap.
                                                EntriesIterator)(this)),
                                              (int)(1));
            }
        }
        
        
//#line 236
public boolean
                       hasNext(
                       ){
            
//#line 237
if (((((int)(i))) < (((int)(map.
                                                       table.
                                                       length))))) {
                
//#line 239
return true;
            }
            
//#line 241
return false;
        }
        
        
//#line 244
public x10.
                       util.
                       HashMap.
                       HashEntry<Key, Value>
                       next(
                       ){
            
//#line 245
if (((int) originalModCount) !=
                             ((int) map.
                                      modCount)) {
                
//#line 245
throw new java.lang.RuntimeException((((("Your code has a concurrency bug! You updated the hashmap ") + (((java.lang.Integer)((((((int)(map.
                                                                                                                                                                       modCount))) - (((int)(originalModCount)))))))))) + (" times since you created the iterator.")));
            }
            
//#line 246
final int j =
              i;
            
//#line 248
x10.
              util.
              HashMap.
              EntriesIterator.<Key,
            Value>__$closure$apply$__2077(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            HashMap.
                                            EntriesIterator)(this)),
                                          (int)(1));
            
//#line 249
this.advance();
            
//#line 250
return ((x10.
              util.
              HashMap.
              HashEntry<Key, Value>)((x10.
              util.
              HashMap.
              HashEntry[])map.
                            table.value)[j]);
        }
        
        final private static <Key, Value> int
          __$closure$apply$__2076(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            HashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            
//#line 232
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <Key, Value> int
          __$closure$apply$__2076$P(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            HashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            return EntriesIterator.<Key,
            Value>__$closure$apply$__2076(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            HashMap.
                                            EntriesIterator)(x)),
                                          (int)(y));
        }
        
        final private static <Key, Value> int
          __$closure$apply$__2077(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            HashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            
//#line 248
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <Key, Value> int
          __$closure$apply$__2077$P(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            HashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            return EntriesIterator.<Key,
            Value>__$closure$apply$__2077(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            HashMap.
                                            EntriesIterator)(x)),
                                          (int)(y));
        }
    
    }
    
    
    
//#line 254
public int
                   size(
                   ){
        
//#line 254
return size;
    }
    
    
//#line 256
public static class KeySet<Key, Value>
                 extends x10.
                   util.
                   AbstractCollection<Key>
                   implements x10.
                                util.
                                Set<Key>
                 {public static final x10.rtt.RuntimeType<KeySet> _RTT = new x10.rtt.RuntimeType<KeySet>(
    /* base class */KeySet.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.CONTRAVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Set._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.UnresolvedType(0))}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 257
final public x10.
          util.
          HashMap<Key, Value>
          map;
        
        
//#line 259
public KeySet(final x10.rtt.Type Key,
                                   final x10.rtt.Type Value,
                                   final x10.
                                     util.
                                     HashMap<Key, Value> map) {
                                                                       super(Key);
                                                                   this.Key = Key;
                                                                   this.Value = Value;
                                                                    {
                                                                       
//#line 259
this.map = ((x10.
                                                                         util.
                                                                         HashMap)(map));
                                                                   }}
        
        
//#line 261
public x10.core.Iterator<Key>
                       iterator(
                       ){
            
//#line 262
return new x10.
              util.
              MapIterator<x10.
              util.
              HashMap.
              HashEntry<Key, Value>, Key>(new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, Key, Value),
                                          Key,
                                          map.entriesIterator(),
                                          new x10.core.fun.Fun_0_1<x10.
                                            util.
                                            HashMap.
                                            HashEntry<Key, Value>, Key>() {public final Key apply$G(final x10.
                                            util.
                                            HashMap.
                                            HashEntry<Key, Value> e) { {
                                              
//#line 262
return e.
                                                                    key;
                                          }}
                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, Key, Value);if (i ==1) return Key;return null;
                                          }
                                          });
        }
        
        
//#line 265
public boolean
                       contains(
                       final Key k){
            
//#line 266
return map.containsKey(((Key)(k)));
        }
        
        
//#line 269
public boolean
                       add(
                       final Key k){
            
//#line 269
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 270
public boolean
                       remove(
                       final Key k){
            
//#line 270
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 271
public x10.
                       util.
                       HashMap.
                       KeySet<Key, Value>
                       clone(
                       ){
            
//#line 271
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 272
public int
                       size(
                       ){
            
//#line 272
return map.size();
        }
    
    }
    
    
//#line 275
public static class EntrySet<Key, Value>
                 extends x10.
                   util.
                   AbstractCollection<x10.
                   util.
                   Map.
                   Entry<Key, Value>>
                   implements x10.
                                util.
                                Set<x10.
                                util.
                                Map.
                                Entry<Key, Value>>
                 {public static final x10.rtt.RuntimeType<EntrySet> _RTT = new x10.rtt.RuntimeType<EntrySet>(
    /* base class */EntrySet.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.CONTRAVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Set._RTT, new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1))), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)))}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 276
final public x10.
          util.
          HashMap<Key, Value>
          map;
        
        
//#line 278
public EntrySet(final x10.rtt.Type Key,
                                     final x10.rtt.Type Value,
                                     final x10.
                                       util.
                                       HashMap<Key, Value> map) {
                                                                         super(new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, Key, Value));
                                                                     this.Key = Key;
                                                                     this.Value = Value;
                                                                      {
                                                                         
//#line 278
this.map = ((x10.
                                                                           util.
                                                                           HashMap)(map));
                                                                     }}
        
        
//#line 280
public x10.core.Iterator<x10.
                       util.
                       Map.
                       Entry<Key, Value>>
                       iterator(
                       ){
            
//#line 281
return new x10.
              util.
              MapIterator<x10.
              util.
              HashMap.
              HashEntry<Key, Value>, x10.
              util.
              Map.
              Entry<Key, Value>>(new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, Key, Value),
                                 new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, Key, Value),
                                 map.entriesIterator(),
                                 new x10.core.fun.Fun_0_1<x10.
                                   util.
                                   HashMap.
                                   HashEntry<Key, Value>, x10.
                                   util.
                                   Map.
                                   Entry<Key, Value>>() {public final x10.
                                   util.
                                   Map.
                                   Entry<Key, Value> apply$G(final x10.
                                   util.
                                   HashMap.
                                   HashEntry<Key, Value> e) { return apply(e);}
                                 public final x10.
                                   util.
                                   Map.
                                   Entry<Key, Value> apply(final x10.
                                   util.
                                   HashMap.
                                   HashEntry<Key, Value> e) { {
                                     
//#line 281
return e;
                                 }}
                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.HashMap.HashEntry._RTT, Key, Value);if (i ==1) return new x10.rtt.ParameterizedType(x10.util.Map.Entry._RTT, Key, Value);return null;
                                 }
                                 });
        }
        
        
//#line 284
public boolean
                       contains(
                       final x10.
                         util.
                         Map.
                         Entry<Key, Value> k){
            
//#line 284
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 285
public boolean
                       add(
                       final x10.
                         util.
                         Map.
                         Entry<Key, Value> k){
            
//#line 285
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 286
public boolean
                       remove(
                       final x10.
                         util.
                         Map.
                         Entry<Key, Value> k){
            
//#line 286
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 287
public x10.
                       util.
                       HashMap.
                       EntrySet<Key, Value>
                       clone(
                       ){
            
//#line 287
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 288
public int
                       size(
                       ){
            
//#line 288
return map.size();
        }
    
    }
    
    
    final private static <K, V> int
      __$closure$apply$__2078(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 76
return x.modCount = ((((int)(x.
                                                   modCount))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2078$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2078(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2079(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 156
return x.modCount = ((((int)(x.
                                                    modCount))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2079$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2079(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2080(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 158
return x.size = ((((int)(x.
                                                size))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2080$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2080(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2081(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 159
return x.occupation = ((((int)(x.
                                                      occupation))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2081$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2081(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2082(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 168
return x.size = ((((int)(x.
                                                size))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2082$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2082(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2083(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 177
return x.modCount = ((((int)(x.
                                                    modCount))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2083$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2083(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2084(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 202
return x.modCount = ((((int)(x.
                                                    modCount))) + (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2084$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2084(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }
    
    final private static <K, V> int
      __$closure$apply$__2085(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        
//#line 205
return x.size = ((((int)(x.
                                                size))) - (((int)(y))));
    }
    
    final public static <K, V> int
      __$closure$apply$__2085$P(
      final x10.rtt.Type K,
      final x10.rtt.Type V,
      final x10.
        util.
        HashMap<K, V> x,
      final int y){
        return HashMap.<K,
        V>__$closure$apply$__2085(K,
                                  V,
                                  ((x10.
                                    util.
                                    HashMap)(x)),
                                  (int)(y));
    }

}
