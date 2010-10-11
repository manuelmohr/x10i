package x10.util;

public class Stack<T>
extends x10.
  util.
  ArrayList<T>
{public static final x10.rtt.RuntimeType<Stack> _RTT = new x10.rtt.RuntimeType<Stack>(
/* base class */Stack.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.ArrayList._RTT, new x10.rtt.UnresolvedType(0))}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
    
//#line 15
public Stack(final x10.rtt.Type T) {
                                                            
//#line 15
super(T);
                                                        this.T = T;
                                                         {
                                                            
                                                        }}
    
    
//#line 18
public boolean
                  push(
                  final T v){
        
//#line 18
return this.add(((T)(v)));
    }
    
    
//#line 21
public T
                  pop$G(
                  ){
        
//#line 21
return this.removeLast$G();
    }
    
    
//#line 23
public x10.core.ValRail<T>
                  pop(
                  final int k){
        
//#line 24
final int n =
          this.size();
        
//#line 25
if (((((int)(n))) < (((int)(k))))) {
            
//#line 26
return null;
        }
        
//#line 27
return this.moveSectionToValRail((int)(((((int)(n))) - (((int)(k))))),
                                                     (int)(((((int)(n))) - (((int)(1))))));
    }
    
    
//#line 30
public T
                  peek$G(
                  ){
        
//#line 30
return this.getLast$G();
    }
    
    
//#line 39
public int
                  search(
                  final T v){
        
//#line 40
final int i =
          this.lastIndexOf(((T)(v)));
        
//#line 41
if (((((int)(i))) >= (((int)(0))))) {
            
//#line 42
return ((((int)(this.size()))) - (((int)(i))));
        } else {
            
//#line 44
return -1;
        }
    }

}
