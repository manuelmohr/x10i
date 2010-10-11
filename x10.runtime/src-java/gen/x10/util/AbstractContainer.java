package x10.util;

abstract public class AbstractContainer<T>
extends x10.core.Ref
  implements x10.
               util.
               Container<T>
{public static final x10.rtt.RuntimeType<AbstractContainer> _RTT = new x10.rtt.RuntimeType<AbstractContainer>(
/* base class */AbstractContainer.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.Container._RTT, new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
    
//#line 16
abstract public int
                  size(
                  );
    
    
//#line 18
public boolean
                  isEmpty(
                  ){
        
//#line 18
return ((int) this.size()) ==
        ((int) 0);
    }
    
    
//#line 20
abstract public boolean
                  contains(
                  final T y);
    
    
//#line 21
abstract public x10.
                  util.
                  Container<T>
                  clone(
                  );
    
    
//#line 22
abstract public x10.core.Iterator<T>
                  iterator(
                  );
    
    
//#line 24
public x10.core.ValRail<T>
                  toValRail(
                  ){
        
//#line 25
final x10.core.GrowableRail<T> g =
          ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T,
                                                                this.size())));
        
//#line 26
for (
//#line 26
final x10.core.Iterator<T> x1830 =
                           this.iterator();
                         x1830.hasNext();
                         ) {
            
//#line 26
final T x =
              ((T)(x1830.next$G()));
            
//#line 27
(g).add(x);
        }
        
//#line 29
return (g).toValRail();
    }
    
    
//#line 32
public x10.core.Rail<T>
                  toRail(
                  ){
        
//#line 33
final x10.core.GrowableRail<T> g =
          ((x10.core.GrowableRail)(new x10.core.GrowableRail<T>(T,
                                                                this.size())));
        
//#line 34
for (
//#line 34
final x10.core.Iterator<T> x1831 =
                           this.iterator();
                         x1831.hasNext();
                         ) {
            
//#line 34
final T x =
              ((T)(x1831.next$G()));
            
//#line 35
(g).add(x);
        }
        
//#line 37
return (g).toRail();
    }
    
    
//#line 40
public boolean
                  containsAll(
                  final x10.
                    util.
                    Container<T> c){
        
//#line 41
for (
//#line 41
final x10.core.Iterator<T> x1832 =
                           (c).iterator();
                         x1832.hasNext();
                         ) {
            
//#line 41
final T x =
              ((T)(x1832.next$G()));
            
//#line 42
if ((!(((boolean)(this.contains(((T)(x)))))))) {
                
//#line 43
return false;
            }
        }
        
//#line 45
return true;
    }
    
    
//#line 15
public AbstractContainer(final x10.rtt.Type T) {
                                                                        
//#line 15
super();
                                                                    this.T = T;
                                                                     {
                                                                        
                                                                    }}

}
