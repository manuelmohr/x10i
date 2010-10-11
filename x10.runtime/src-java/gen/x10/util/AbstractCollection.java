package x10.util;

abstract public class AbstractCollection<T>
extends x10.
  util.
  AbstractContainer<T>
  implements x10.
               util.
               Collection<T>
{public static final x10.rtt.RuntimeType<AbstractCollection> _RTT = new x10.rtt.RuntimeType<AbstractCollection>(
/* base class */AbstractCollection.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Collection._RTT, new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(x10.util.AbstractContainer._RTT, new x10.rtt.UnresolvedType(0))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
    
//#line 16
abstract public boolean
                  add(
                  final T id$121);
    
    
//#line 17
abstract public boolean
                  remove(
                  final T id$122);
    
    
//#line 19
public boolean
                  addAll(
                  final x10.
                    util.
                    Container<T> c){
        
//#line 19
return this.addAllWhere(((x10.
                                              util.
                                              Container)(c)),
                                            ((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<T, java.lang.Boolean>() {public final java.lang.Boolean apply$G(final T id$123) { return apply(id$123);}
                                            public final boolean apply(final T id$123) { {
                                                
//#line 19
return true;
                                            }}
                                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return x10.rtt.Types.BOOLEAN;return null;
                                            }
                                            })));
    }
    
    
//#line 20
public boolean
                  retainAll(
                  final x10.
                    util.
                    Container<T> c){
        
//#line 20
return this.removeAllWhere(((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<T, java.lang.Boolean>() {public final java.lang.Boolean apply$G(final T x) { return apply(x);}
                                               public final boolean apply(final T x) { {
                                                   
//#line 20
return (!(((boolean)(c.contains(((T)(x)))))));
                                               }}
                                               public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return x10.rtt.Types.BOOLEAN;return null;
                                               }
                                               })));
    }
    
    
//#line 21
public boolean
                  removeAll(
                  final x10.
                    util.
                    Container<T> c){
        
//#line 21
return this.removeAllWhere(((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<T, java.lang.Boolean>() {public final java.lang.Boolean apply$G(final T x) { return apply(x);}
                                               public final boolean apply(final T x) { {
                                                   
//#line 21
return c.contains(((T)(x)));
                                               }}
                                               public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return x10.rtt.Types.BOOLEAN;return null;
                                               }
                                               })));
    }
    
    
//#line 23
public boolean
                  addAllWhere(
                  final x10.
                    util.
                    Container<T> c,
                  final x10.core.fun.Fun_0_1<T,java.lang.Boolean> p){
        
//#line 24
boolean result =
          false;
        
//#line 25
for (
//#line 25
final x10.core.Iterator<T> x1828 =
                           (c).iterator();
                         x1828.hasNext();
                         ) {
            
//#line 25
final T x =
              ((T)(x1828.next$G()));
            
//#line 26
if (p.apply$G(x)) {
                
//#line 27
result = ((((boolean)(result))) | (((boolean)(this.add(((T)(x)))))));
            }
        }
        
//#line 29
return result;
    }
    
    
//#line 32
public boolean
                  removeAllWhere(
                  final x10.core.fun.Fun_0_1<T,java.lang.Boolean> p){
        
//#line 33
boolean result =
          false;
        
//#line 34
for (
//#line 34
final x10.core.Iterator<T> x1829 =
                           (this.clone()).iterator();
                         x1829.hasNext();
                         ) {
            
//#line 34
final T x =
              ((T)(x1829.next$G()));
            
//#line 35
if (p.apply$G(x)) {
                
//#line 36
result = ((((boolean)(result))) | (((boolean)(this.remove(((T)(x)))))));
            }
        }
        
//#line 38
return result;
    }
    
    
//#line 41
public void
                  clear(
                  ){
        
//#line 41
this.removeAllWhere(((x10.core.fun.Fun_0_1)(new x10.core.fun.Fun_0_1<T, java.lang.Boolean>() {public final java.lang.Boolean apply$G(final T id$126) { return apply(id$126);}
                                        public final boolean apply(final T id$126) { {
                                            
//#line 41
return true;
                                        }}
                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return x10.rtt.Types.BOOLEAN;return null;
                                        }
                                        })));
    }
    
    
//#line 43
abstract public x10.
                  util.
                  Collection<T>
                  clone(
                  );
    
    
//#line 15
public AbstractCollection(final x10.rtt.Type T) {
                                                                         
//#line 15
super(T);
                                                                     this.T = T;
                                                                      {
                                                                         
                                                                     }}

}
