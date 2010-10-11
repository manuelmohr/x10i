package x10.util;

public interface ValMap<K, V>
{public static final x10.rtt.RuntimeType<ValMap> _RTT = new x10.rtt.RuntimeType<ValMap>(
/* base class */ValMap.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);

    
    
    
//#line 16
boolean
                  containsKey(
                  final K k);
    
    
//#line 17
x10.
                  util.
                  Box<V>
                  get(
                  final K k);
    
    
//#line 18
V
                  getOrElse$G(
                  final K k,
                  final V orelse);
    
    
//#line 19
V
                  getOrThrow$G(
                  final K k)
                      throws x10.
                  util.
                  NoSuchElementException;
    
    
//#line 20
x10.
                  util.
                  Set<K>
                  keySet(
                  );
    
    
//#line 21
x10.
                  util.
                  Set<x10.
                  util.
                  ValMap.
                  Entry<K, V>>
                  entries(
                  );
    
    
//#line 23
public static interface Entry<Key, Val>
                {public static final x10.rtt.RuntimeType<Entry> _RTT = new x10.rtt.RuntimeType<Entry>(
    /* base class */Entry.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
    x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    
        
        
        
//#line 24
Key
                      getKey$G(
                      );
        
        
//#line 25
Val
                      getValue$G(
                      );
    
    }
    

}
