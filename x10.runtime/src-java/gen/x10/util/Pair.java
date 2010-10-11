package x10.util;

public class Pair<T, U>
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<Pair> _RTT = new x10.rtt.RuntimeType<Pair>(
/* base class */Pair.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT, 
x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;if (i ==1)return U;return null;}

    private final x10.rtt.Type T;
    private final x10.rtt.Type U;
    
    
//#line 18
final public T
      first;
    
//#line 19
final public U
      second;
    
    
//#line 21
public Pair(final x10.rtt.Type T,
                            final x10.rtt.Type U,
                            final T first,
                            final U second) {this.T = T;
                                                 this.U = U;
                                                  {
                                                     
//#line 22
this.first = ((T)(first));
                                                     
//#line 23
this.second = ((U)(second));
                                                 }}
    
    
//#line 26
final public java.lang.String
                  toString(
                  ){
        
//#line 27
return (((((((("(") + (first))) + (", "))) + (second))) + (")"));
    }
    
    
//#line 17
final native public x10.
                  lang.
                  Place
                  home(
                  );
    
    
//#line 17
final native public java.lang.String
                  typeName(
                  );
    
    
//#line 17
final native public boolean
                  at(
                  x10.
                    lang.
                    Place p);
    
    
//#line 17
final native public boolean
                  at(
                  java.lang.Object r);
    
    
//#line 17
final public int
                  hashCode(
                  ){
        
//#line 17
int result =
          0;
        
//#line 17
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(((java.lang.Object)(this.
                                                                                                                       first)))).hashCode()))));
        
//#line 17
result = ((((int)(((((int)(31))) * (((int)(result))))))) + (((int)(((Object)(((java.lang.Object)(this.
                                                                                                                       second)))).hashCode()))));
        
//#line 17
return result;
    }
    
    
//#line 17
final public boolean
                  equals(
                  java.lang.Object other){
        
//#line 17
if ((!(((boolean)(x10.util.Pair._RTT.instanceof$(other, T, U)))))) {
            
//#line 17
return false;
        }
        
//#line 17
return this.equals(((x10.
                                         util.
                                         Pair)((new java.lang.Object() {final x10.
                                         util.
                                         Pair cast(final x10.
                                         util.
                                         Pair self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.util.Pair._RTT, T, U);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         util.
                                         Pair) other)))));
    }
    
    
//#line 17
final public boolean
                  equals(
                  x10.
                    util.
                    Pair<T, U> other){
        
//#line 17
return x10.rtt.Equality.equalsequals(this.
                                                           first,((T)(other.
                                                                        first))) &&
        x10.rtt.Equality.equalsequals(this.
                                        second,((U)(other.
                                                      second)));
    }
    
    
//#line 17
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 17
if ((!(((boolean)(x10.util.Pair._RTT.instanceof$(other, T, U)))))) {
            
//#line 17
return false;
        }
        
//#line 17
return this._struct_equals(((x10.
                                                 util.
                                                 Pair)((new java.lang.Object() {final x10.
                                                 util.
                                                 Pair cast(final x10.
                                                 util.
                                                 Pair self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.util.Pair._RTT, T, U);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 util.
                                                 Pair) other)))));
    }
    
    
//#line 17
final public boolean
                  _struct_equals(
                  x10.
                    util.
                    Pair<T, U> other){
        
//#line 17
return x10.rtt.Equality.equalsequals(this.
                                                           first,((T)(other.
                                                                        first))) &&
        x10.rtt.Equality.equalsequals(this.
                                        second,((U)(other.
                                                      second)));
    }

}
