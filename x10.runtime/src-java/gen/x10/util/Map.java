package x10.util;

public interface Map<K, V>
{public static final x10.rtt.RuntimeType<Map> _RTT = new x10.rtt.RuntimeType<Map>(
/* base class */Map.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 15
boolean
                  containsKey(
                  final K k);
    
    
//#line 17
x10.
                  util.
                  Box<V>
                  get(
                  final K k);
    
    
//#line 19
V
                  getOrElse$G(
                  final K k,
                  final V orelse);
    
    
//#line 21
V
                  getOrThrow$G(
                  final K k)
                      throws x10.
                  util.
                  NoSuchElementException;
    
    
//#line 23
x10.
                  util.
                  Box<V>
                  put(
                  final K k,
                  final V v);
    
    
//#line 25
x10.
                  util.
                  Box<V>
                  remove(
                  final K k);
    
    
//#line 27
x10.
                  util.
                  Set<K>
                  keySet(
                  );
    
    
//#line 29
void
                  clear(
                  );
    
    
//#line 31
x10.
                  util.
                  Set<x10.
                  util.
                  Map.
                  Entry<K, V>>
                  entries(
                  );
    
    
//#line 33
public static interface Entry<Key, Val>
                {public static final x10.rtt.RuntimeType<Entry> _RTT = new x10.rtt.RuntimeType<Entry>(
    /* base class */Entry.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    
        
        
        
//#line 34
Key
                      getKey$G(
                      );
        
        
//#line 35
Val
                      getValue$G(
                      );
        
        
//#line 36
void
                      setValue(
                      final Val id$171);
    
    }
    

}
