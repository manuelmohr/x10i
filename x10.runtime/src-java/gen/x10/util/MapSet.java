package x10.util;

abstract public class MapSet<T>
extends x10.
  util.
  AbstractCollection<T>
  implements x10.
               util.
               Set<T>
{public static final x10.rtt.RuntimeType<MapSet> _RTT = new x10.rtt.RuntimeType<MapSet>(
/* base class */MapSet.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Set._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.AbstractCollection._RTT, new x10.rtt.UnresolvedType(0))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 15
final public x10.
      util.
      Map<T, java.lang.Boolean>
      map;
    
    
//#line 17
public MapSet(final x10.rtt.Type T,
                              final x10.
                                util.
                                Map<T, java.lang.Boolean> map) {
                                                                        super(T);
                                                                    this.T = T;
                                                                     {
                                                                        
//#line 17
this.map = ((x10.
                                                                          util.
                                                                          Map)(map));
                                                                    }}
    
    
//#line 19
public int
                  size(
                  ){
        
//#line 19
return map.keySet().size();
    }
    
    
//#line 20
public boolean
                  contains(
                  final T v){
        
//#line 20
return map.containsKey(((T)(v)));
    }
    
    
//#line 22
public boolean
                  add(
                  final T v){
        
//#line 22
return x10.rtt.Equality.equalsequals(map.put(((T)(v)),
                                                                 (java.lang.Boolean)(true)),null);
    }
    
    
//#line 23
public boolean
                  remove(
                  final T v){
        
//#line 23
return (!x10.rtt.Equality.equalsequals(map.remove(((T)(v))),null));
    }
    
    
//#line 24
public void
                  clear(
                  ){
        {
            
//#line 24
map.clear();
            
//#line 24
return;
        }
    }
    
    
//#line 25
public x10.core.Iterator<T>
                  iterator(
                  ){
        
//#line 25
return (map.keySet()).iterator();
    }

}
