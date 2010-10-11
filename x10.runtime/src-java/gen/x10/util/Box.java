package x10.util;

final public class Box<T>
extends x10.core.Ref
  implements x10.core.fun.Fun_0_0<T>
{public static final x10.rtt.RuntimeType<Box> _RTT = new x10.rtt.RuntimeType<Box>(
/* base class */Box.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.COVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_0._RTT, new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 14
final public T
      value;
    
    
    
//#line 15
public Box(final x10.rtt.Type T,
                           final T x) {
                                               super();
                                           this.T = T;
                                            {
                                               
//#line 15
this.value = ((T)(x));
                                           }}
    
    
//#line 17
public T
                  apply$G(
                  ){
        
//#line 17
return value;
    }
    
    
//#line 18
public int
                  hashCode(
                  ){
        
//#line 18
return ((Object)(((java.lang.Object)(value)))).hashCode();
    }
    
    
//#line 20
public java.lang.String
                  toString(
                  ){
        
//#line 20
return ((java.lang.Object)(((java.lang.Object)(value)))).toString();
    }
    
    
//#line 22
public boolean
                  equals(
                  final java.lang.Object x){
        
//#line 23
if (x10.rtt.Equality.equalsequals(x,null)) {
            
//#line 24
return false;
        }
        
//#line 26
if (T.instanceof$(x)) {
            
//#line 27
final T y =
              ((T)((new java.lang.Object() {final T cast(final Object self) {x10.rtt.Type rtt = T;T dep = (T) x10.rtt.Types.conversion(rtt,self);if (self==null) return null;if (rtt != null && ! rtt.instanceof$(dep)) throw new java.lang.ClassCastException();return dep;}}.cast(x))));
            
//#line 28
return ((java.lang.Object)(((java.lang.Object)(value)))).equals(y);
        }
        
//#line 30
if (x10.util.Box._RTT.instanceof$(x, T)) {
            
//#line 31
final T y =
              ((T)((((new java.lang.Object() {final x10.
                       util.
                       Box cast(final x10.
                       util.
                       Box self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.util.Box._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                       util.
                       Box) x)))).
                     value));
            
//#line 32
return ((java.lang.Object)(((java.lang.Object)(value)))).equals(y);
        }
        
//#line 34
return false;
    }
    
    
//#line 37
public static <T> x10.
                  util.
                  Box<T>
                  $implicit_convert(
                  final x10.rtt.Type T,
                  final T x){
        
//#line 37
return new x10.
          util.
          Box<T>(T,
                 x);
    }
    
    
//#line 14
final public T
                  value$G(
                  ){
        
//#line 14
return this.
                             value;
    }

}
