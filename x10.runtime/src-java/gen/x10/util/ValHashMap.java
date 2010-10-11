package x10.util;

public class ValHashMap<K, V>
extends x10.core.Ref
  implements x10.
               util.
               ValMap<K, V>
{public static final x10.rtt.RuntimeType<ValHashMap> _RTT = new x10.rtt.RuntimeType<ValHashMap>(
/* base class */ValHashMap.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.ValMap._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return K;if (i ==1)return V;return null;}

    private final x10.rtt.Type K;
    private final x10.rtt.Type V;
    
    
    
//#line 15
public static <Key, Value> x10.
                  util.
                  ValHashMap<Key, Value>
                  make(
                  final x10.rtt.Type Key,
                  final x10.rtt.Type Value,
                  final x10.
                    util.
                    Map<Key, Value> map){
        
//#line 16
x10.
          util.
          HashMap<Key, Value> hashMap =
          ((x10.
          util.
          HashMap)(new x10.
          util.
          HashMap<Key, Value>(Key,
                              Value)));
        
//#line 17
final x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> > entries =
          ((x10.core.Iterable)(new x10.core.fun.Fun_0_1<x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> >, x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> >>() {public final x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> > apply$G(final x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> > __desugarer__var__82__) { return apply(__desugarer__var__82__);}
        public final x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> > apply(final x10.core.Iterable<x10.
          util.
          Map.
          Entry<Key, Value> > __desugarer__var__82__) { {
            
//#line 17
if (!(x10.rtt.Equality.equalsequals(((x10.
                                lang.
                                Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__82__)))),x10.
                                lang.
                                Runtime.here()))) {
                
//#line 17
throw new java.lang.ClassCastException(("x10.lang.Iterable[x10.util.Map.Entry[Key, Value]{self.home==" +
                                                                    "_place10933}]{self.home==_place10933}"));
            }
            
//#line 17
return __desugarer__var__82__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.runtimeType(x10.core.Iterable.class);if (i ==1) return x10.rtt.Types.runtimeType(x10.core.Iterable.class);return null;
        }
        }.apply(((x10.core.Iterable)
                  map.entries()))));
        
//#line 18
for (
//#line 18
final x10.core.Iterator<x10.
                           util.
                           Map.
                           Entry<Key, Value>> entry1923 =
                           (entries).iterator();
                         entry1923.hasNext();
                         ) {
            
//#line 18
final x10.
              util.
              Map.
              Entry<Key, Value> entry =
              ((x10.
              util.
              Map.
              Entry)(entry1923.next$G()));
            
//#line 19
if ((!x10.rtt.Equality.equalsequals(entry,null))) {
                
//#line 20
hashMap.put(((Key)(entry.getKey$G())),
                                        ((Value)(entry.getValue$G())));
            }
        }
        
//#line 22
return x10.
          util.
          ValHashMap.<Key,
        Value>make(Key,
                   Value,
                   ((x10.
                     util.
                     HashMap)(hashMap)));
    }
    
    
//#line 24
public static <Key, Value> x10.
                  util.
                  ValHashMap<Key, Value>
                  make(
                  final x10.rtt.Type Key,
                  final x10.rtt.Type Value,
                  final x10.
                    util.
                    HashMap<Key, Value> map){
        
//#line 25
return new x10.
          util.
          ValHashMap<Key, Value>(Key,
                                 Value,
                                 map);
    }
    
    
//#line 28
public static class HashEntry<Key, Value>
                extends x10.core.Ref
                  implements x10.
                               util.
                               ValMap.
                               Entry<Key, Value>
                {public static final x10.rtt.RuntimeType<HashEntry> _RTT = new x10.rtt.RuntimeType<HashEntry>(
    /* base class */HashEntry.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
        
//#line 29
public Key
                      getKey$G(
                      ){
            
//#line 29
return key;
        }
        
        
//#line 30
public Value
                      getValue$G(
                      ){
            
//#line 30
return value;
        }
        
        
//#line 32
final public Key
          key;
        
//#line 33
final public Value
          value;
        
//#line 34
final public int
          hash;
        
        
//#line 36
public HashEntry(final x10.rtt.Type Key,
                                     final x10.rtt.Type Value,
                                     final Key key,
                                     final Value value) {
                                                                 super();
                                                             this.Key = Key;
                                                             this.Value = Value;
                                                              {
                                                                 
//#line 37
this.key = ((Key)(key));
                                                                 
//#line 38
this.value = ((Value)(value));
                                                                 
//#line 39
this.hash = x10.
                                                                   util.
                                                                   ValHashMap.<Key>hash(Key,
                                                                                        ((Key)(key)));
                                                             }}
    
    }
    
    
//#line 43
final public x10.core.ValRail<x10.
      util.
      ValHashMap.
      HashEntry<K, V>>
      table;
    
    
//#line 45
private ValHashMap(final x10.rtt.Type K,
                                   final x10.rtt.Type V,
                                   final x10.
                                     util.
                                     HashMap<K, V> map) {
                                                                 super();
                                                             this.K = K;
                                                             this.V = V;
                                                              {
                                                                 
//#line 46
final x10.core.Rail<x10.
                                                                   util.
                                                                   HashMap.
                                                                   HashEntry<K, V>> t =
                                                                   ((x10.core.Rail)(map.
                                                                                      table));
                                                                 
//#line 47
this.table = ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<x10.
                                                                   util.
                                                                   ValHashMap.
                                                                   HashEntry<K, V>> apply(int length) {x10.
                                                                   util.
                                                                   ValHashMap.
                                                                   HashEntry[] array = new x10.
                                                                   util.
                                                                   ValHashMap.
                                                                   HashEntry[length];for (int index$ = 0; index$ < length; index$++) {final int index = index$;final x10.
                                                                   util.
                                                                   HashMap.
                                                                   HashEntry<K, V> entry =
                                                                   ((x10.
                                                                   util.
                                                                   HashMap.
                                                                   HashEntry)(((x10.
                                                                   util.
                                                                   HashMap.
                                                                   HashEntry<K, V>)((x10.
                                                                   util.
                                                                   HashMap.
                                                                   HashEntry[])t.value)[index])));x10.
                                                                   util.
                                                                   ValHashMap.
                                                                   HashEntry<K, V> res =
                                                                   null;if ((!x10.rtt.Equality.equalsequals(entry,null))) {
                                                                     
//#line 50
res = ((x10.
                                                                       util.
                                                                       ValHashMap.
                                                                       HashEntry)(new x10.
                                                                       util.
                                                                       ValHashMap.
                                                                       HashEntry<K, V>(K,
                                                                                       V,
                                                                                       entry.getKey$G(),
                                                                                       entry.getValue$G())));
                                                                 }array[index] = res;}return new x10.core.ValRail<x10.
                                                                   util.
                                                                   ValHashMap.
                                                                   HashEntry<K, V>>(new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, K, V), t.
                                                                                                                                                               length, array);}}.apply(t.
                                                                                                                                                                                         length))));
                                                             }}
    
    
//#line 55
public static <T> int
                  hash(
                  final x10.rtt.Type T,
                  final T k){
        
//#line 56
return ((((int)(((Object)(((java.lang.Object)(k)))).hashCode()))) * (((int)(17))));
    }
    
    
//#line 58
public x10.
                  util.
                  Box<V>
                  apply(
                  final K k){
        
//#line 58
return this.get(((K)(k)));
    }
    
    
//#line 59
public x10.
                  util.
                  Box<V>
                  get(
                  final K k){
        
//#line 60
final x10.
          util.
          ValHashMap.
          HashEntry<K, V> e =
          this.getEntry(((K)(k)));
        
//#line 61
if (x10.rtt.Equality.equalsequals(e,null)) {
            
//#line 61
return null;
        }
        
//#line 62
return x10.
          util.
          Box.<V>$implicit_convert(V,
                                   ((V)(e.
                                          value)));
    }
    
    
//#line 65
public V
                  getOrElse$G(
                  final K k,
                  final V orelse){
        
//#line 66
final x10.
          util.
          ValHashMap.
          HashEntry<K, V> e =
          this.getEntry(((K)(k)));
        
//#line 67
if (x10.rtt.Equality.equalsequals(e,null)) {
            
//#line 67
return orelse;
        }
        
//#line 68
return e.
                             value;
    }
    
    
//#line 71
public K
                  findMax$G(
                  K index,
                  V max,
                  final x10.core.fun.Fun_0_2<V,V,java.lang.Boolean> cmp){
        
//#line 72
for (
//#line 72
final x10.core.Iterator<K> key1924 =
                           (this.keySet()).iterator();
                         key1924.hasNext();
                         ) {
            
//#line 72
final K key =
              ((K)(key1924.next$G()));
            
//#line 73
final V count =
              ((V)(this.apply(((K)(key))).apply$G()));
            
//#line 74
if (cmp.apply$G(count,
                                        max)) {
                
//#line 74
max = ((V)(count));
                
//#line 74
index = ((K)(key));
            }
        }
        
//#line 76
return index;
    }
    
    
//#line 79
public V
                  getOrThrow$G(
                  final K k)
                      throws x10.
                  util.
                  NoSuchElementException{
        
//#line 80
final x10.
          util.
          ValHashMap.
          HashEntry<K, V> e =
          this.getEntry(((K)(k)));
        
//#line 81
if (x10.rtt.Equality.equalsequals(e,null)) {
            
//#line 81
throw new x10.
              util.
              NoSuchElementException("Not found");
        }
        
//#line 82
return e.
                             value;
    }
    
    
//#line 84
public x10.
                  util.
                  ValHashMap.
                  HashEntry<K, V>
                  getEntry(
                  final K k){
        
//#line 85
final int size =
          table.
            length;
        
//#line 86
final int mask =
          ((((int)(size))) - (((int)(1))));
        
//#line 88
if (((int) size) ==
                        ((int) 0)) {
            
//#line 89
return null;
        }
        
//#line 92
final int h =
          x10.
          util.
          ValHashMap.<K>hash(K,
                             ((K)(k)));
        
//#line 94
int i =
          h;
        {
            
//#line 96
final x10.
              util.
              ValHashMap.
              HashEntry[] x10$util$ValHashMap$this$table$value2098 =
              ((x10.
              util.
              ValHashMap.
              HashEntry[])table.value);
            
//#line 96
while (true) {
                
//#line 97
final int j =
                  ((((int)(i))) & (((int)(mask))));
                
//#line 98
i = ((((int)(i))) + (((int)(1))));
                
//#line 100
final x10.
                  util.
                  ValHashMap.
                  HashEntry<K, V> e =
                  ((x10.
                  util.
                  ValHashMap.
                  HashEntry)(((x10.
                  util.
                  ValHashMap.
                  HashEntry<K, V>)x10$util$ValHashMap$this$table$value2098[j])));
                
//#line 101
if (x10.rtt.Equality.equalsequals(e,null)) {
                    
//#line 102
return null;
                }
                
//#line 104
if ((!x10.rtt.Equality.equalsequals(e,null))) {
                    
//#line 105
if (((int) e.
                                              hash) ==
                                     ((int) h) &&
                                     ((java.lang.Object)(((java.lang.Object)(k)))).equals(e.
                                                                                            key)) {
                        
//#line 106
return e;
                    }
                    
//#line 108
if (((((int)(((((int)(i))) - (((int)(h))))))) > (((int)(table.
                                                                                           length))))) {
                        
//#line 109
return null;
                    }
                }
            }
        }
    }
    
    
//#line 115
public boolean
                   containsKey(
                   final K k){
        
//#line 116
final x10.
          util.
          ValHashMap.
          HashEntry<K, V> e =
          this.getEntry(((K)(k)));
        
//#line 117
return (!x10.rtt.Equality.equalsequals(e,null));
    }
    
    
//#line 120
public x10.
                   util.
                   Set<K>
                   keySet(
                   ){
        
//#line 120
return new x10.
          util.
          ValHashMap.
          KeySet<K, V>(K,
                       V,
                       this);
    }
    
    
//#line 121
public x10.
                   util.
                   Set<x10.
                   util.
                   ValMap.
                   Entry<K, V>>
                   entries(
                   ){
        
//#line 121
return new x10.
          util.
          ValHashMap.
          EntrySet<K, V>(K,
                         V,
                         this);
    }
    
    
//#line 122
public int
                   size(
                   ){
        
//#line 122
return table.
                              length;
    }
    
    
//#line 124
public x10.core.Iterator<x10.
                   util.
                   ValHashMap.
                   HashEntry<K, V>>
                   entriesIterator(
                   ){
        
//#line 125
final x10.
          util.
          ValHashMap.
          EntriesIterator<K, V> iterator =
          ((x10.
          util.
          ValHashMap.
          EntriesIterator)(new x10.
          util.
          ValHashMap.
          EntriesIterator<K, V>(K,
                                V,
                                this)));
        
//#line 126
iterator.advance();
        
//#line 127
return iterator;
    }
    
    
//#line 130
public static class EntriesIterator<Key, Value>
                 extends x10.core.Ref
                   implements x10.core.Iterator<x10.
                                util.
                                ValHashMap.
                                HashEntry<Key, Value>>
                 {public static final x10.rtt.RuntimeType<EntriesIterator> _RTT = new x10.rtt.RuntimeType<EntriesIterator>(
    /* base class */EntriesIterator.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1))), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    // bridge for method abstract public x10.lang.Iterator.next(): T
    public x10.
      util.
      ValHashMap.
      HashEntry<Key, Value>
      next$G(){return next();}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 131
final public x10.
          util.
          ValHashMap<Key, Value>
          map;
        
//#line 132
public int
          i;
        
        
//#line 134
public EntriesIterator(final x10.rtt.Type Key,
                                            final x10.rtt.Type Value,
                                            final x10.
                                              util.
                                              ValHashMap<Key, Value> map) {
                                                                                   super();
                                                                               this.Key = Key;
                                                                               this.Value = Value;
                                                                                {
                                                                                   
//#line 132
this.i = 0;
                                                                                   
//#line 134
this.map = map;
                                                                                   
//#line 134
this.i = 0;
                                                                               }}
        
        
//#line 136
public void
                       advance(
                       ){
            
//#line 137
while (((((int)(i))) < (((int)(map.
                                                          table.
                                                          length))))) {
                
//#line 138
if ((!x10.rtt.Equality.equalsequals(((x10.
                                   util.
                                   ValHashMap.
                                   HashEntry<Key, Value>)((x10.
                                   util.
                                   ValHashMap.
                                   HashEntry[])map.
                                                 table.value)[i]),null))) {
                    
//#line 139
return;
                }
                
//#line 140
x10.
                  util.
                  ValHashMap.
                  EntriesIterator.<Key,
                Value>__$closure$apply$__2096(Key,
                                              Value,
                                              ((x10.
                                                util.
                                                ValHashMap.
                                                EntriesIterator)(this)),
                                              (int)(1));
            }
        }
        
        
//#line 144
public boolean
                       hasNext(
                       ){
            
//#line 145
if (((((int)(i))) < (((int)(map.
                                                       table.
                                                       length))))) {
                
//#line 146
return true;
            }
            
//#line 148
return false;
        }
        
        
//#line 151
public x10.
                       util.
                       ValHashMap.
                       HashEntry<Key, Value>
                       next(
                       ){
            
//#line 152
final int j =
              i;
            
//#line 153
x10.
              util.
              ValHashMap.
              EntriesIterator.<Key,
            Value>__$closure$apply$__2097(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            ValHashMap.
                                            EntriesIterator)(this)),
                                          (int)(1));
            
//#line 154
this.advance();
            
//#line 155
return ((x10.
              util.
              ValHashMap.
              HashEntry<Key, Value>)((x10.
              util.
              ValHashMap.
              HashEntry[])map.
                            table.value)[j]);
        }
        
        final private static <Key, Value> int
          __$closure$apply$__2096(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            ValHashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            
//#line 140
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <Key, Value> int
          __$closure$apply$__2096$P(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            ValHashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            return EntriesIterator.<Key,
            Value>__$closure$apply$__2096(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            ValHashMap.
                                            EntriesIterator)(x)),
                                          (int)(y));
        }
        
        final private static <Key, Value> int
          __$closure$apply$__2097(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            ValHashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            
//#line 153
return x.i = ((((int)(x.
                                                 i))) + (((int)(y))));
        }
        
        final public static <Key, Value> int
          __$closure$apply$__2097$P(
          final x10.rtt.Type Key,
          final x10.rtt.Type Value,
          final x10.
            util.
            ValHashMap.
            EntriesIterator<Key, Value> x,
          final int y){
            return EntriesIterator.<Key,
            Value>__$closure$apply$__2097(Key,
                                          Value,
                                          ((x10.
                                            util.
                                            ValHashMap.
                                            EntriesIterator)(x)),
                                          (int)(y));
        }
    
    }
    
    
//#line 160
public static class KeySet<Key, Value>
                 extends x10.
                   util.
                   AbstractCollection<Key>
                   implements x10.
                                util.
                                Set<Key>
                 {public static final x10.rtt.RuntimeType<KeySet> _RTT = new x10.rtt.RuntimeType<KeySet>(
    /* base class */KeySet.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Set._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.UnresolvedType(0))}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 161
final public x10.
          util.
          ValHashMap<Key, Value>
          map;
        
        
//#line 163
public KeySet(final x10.rtt.Type Key,
                                   final x10.rtt.Type Value,
                                   final x10.
                                     util.
                                     ValHashMap<Key, Value> map) {
                                                                          super(Key);
                                                                      this.Key = Key;
                                                                      this.Value = Value;
                                                                       {
                                                                          
//#line 163
this.map = map;
                                                                      }}
        
        
//#line 165
public x10.core.Iterator<Key>
                       iterator(
                       ){
            
//#line 166
return new x10.
              util.
              MapIterator<x10.
              util.
              ValHashMap.
              HashEntry<Key, Value>, Key>(new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, Key, Value),
                                          Key,
                                          map.entriesIterator(),
                                          new x10.core.fun.Fun_0_1<x10.
                                            util.
                                            ValHashMap.
                                            HashEntry<Key, Value>, Key>() {public final Key apply$G(final x10.
                                            util.
                                            ValHashMap.
                                            HashEntry<Key, Value> e) { {
                                              
//#line 166
return e.
                                                                    key;
                                          }}
                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, Key, Value);if (i ==1) return Key;return null;
                                          }
                                          });
        }
        
        
//#line 169
public boolean
                       contains(
                       final Key k){
            
//#line 170
return map.containsKey(((Key)(k)));
        }
        
        
//#line 173
public boolean
                       add(
                       final Key k){
            
//#line 173
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 174
public boolean
                       remove(
                       final Key k){
            
//#line 174
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 175
public x10.
                       util.
                       ValHashMap.
                       KeySet<Key, Value>
                       clone(
                       ){
            
//#line 175
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 176
public int
                       size(
                       ){
            
//#line 176
return map.size();
        }
    
    }
    
    
//#line 179
public static class EntrySet<Key, Value>
                 extends x10.
                   util.
                   AbstractCollection<x10.
                   util.
                   ValMap.
                   Entry<Key, Value>>
                   implements x10.
                                util.
                                Set<x10.
                                util.
                                ValMap.
                                Entry<Key, Value>>
                 {public static final x10.rtt.RuntimeType<EntrySet> _RTT = new x10.rtt.RuntimeType<EntrySet>(
    /* base class */EntrySet.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Set._RTT, new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1))), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, new x10.rtt.UnresolvedType(0), new x10.rtt.UnresolvedType(1)))}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return Key;if (i ==1)return Value;return null;}
    
        private final x10.rtt.Type Key;
        private final x10.rtt.Type Value;
        
        
//#line 180
final public x10.
          util.
          ValHashMap<Key, Value>
          map;
        
        
//#line 182
public EntrySet(final x10.rtt.Type Key,
                                     final x10.rtt.Type Value,
                                     final x10.
                                       util.
                                       ValHashMap<Key, Value> map) {
                                                                            super(new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, Key, Value));
                                                                        this.Key = Key;
                                                                        this.Value = Value;
                                                                         {
                                                                            
//#line 182
this.map = map;
                                                                        }}
        
        
//#line 184
public x10.core.Iterator<x10.
                       util.
                       ValMap.
                       Entry<Key, Value>>
                       iterator(
                       ){
            
//#line 185
return new x10.
              util.
              MapIterator<x10.
              util.
              ValHashMap.
              HashEntry<Key, Value>, x10.
              util.
              ValMap.
              Entry<Key, Value>>(new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, Key, Value),
                                 new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, Key, Value),
                                 map.entriesIterator(),
                                 new x10.core.fun.Fun_0_1<x10.
                                   util.
                                   ValHashMap.
                                   HashEntry<Key, Value>, x10.
                                   util.
                                   ValMap.
                                   Entry<Key, Value>>() {public final x10.
                                   util.
                                   ValMap.
                                   Entry<Key, Value> apply$G(final x10.
                                   util.
                                   ValHashMap.
                                   HashEntry<Key, Value> e) { return apply(e);}
                                 public final x10.
                                   util.
                                   ValMap.
                                   Entry<Key, Value> apply(final x10.
                                   util.
                                   ValHashMap.
                                   HashEntry<Key, Value> e) { {
                                     
//#line 185
return e;
                                 }}
                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.ValHashMap.HashEntry._RTT, Key, Value);if (i ==1) return new x10.rtt.ParameterizedType(x10.util.ValMap.Entry._RTT, Key, Value);return null;
                                 }
                                 });
        }
        
        
//#line 188
public boolean
                       contains(
                       final x10.
                         util.
                         ValMap.
                         Entry<Key, Value> k){
            
//#line 188
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 189
public boolean
                       add(
                       final x10.
                         util.
                         ValMap.
                         Entry<Key, Value> k){
            
//#line 189
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 190
public boolean
                       remove(
                       final x10.
                         util.
                         ValMap.
                         Entry<Key, Value> k){
            
//#line 190
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 191
public x10.
                       util.
                       ValHashMap.
                       EntrySet<Key, Value>
                       clone(
                       ){
            
//#line 191
throw new java.lang.UnsupportedOperationException();
        }
        
        
//#line 192
public int
                       size(
                       ){
            
//#line 192
return map.size();
        }
    
    }
    

}
