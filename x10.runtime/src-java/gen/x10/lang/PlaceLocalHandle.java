package x10.lang;


final public class PlaceLocalHandle<T extends java.lang.Object>
extends x10.core.Struct
{public static final x10.rtt.RuntimeType<PlaceLocalHandle> _RTT = new x10.rtt.RuntimeType<PlaceLocalHandle>(
/* base class */PlaceLocalHandle.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 35
final public x10.
      runtime.
      impl.
      java.
      PlaceLocalHandle<T>
      __NATIVE_FIELD__;
    
    
//#line 35
private PlaceLocalHandle(final x10.rtt.Type T,
                                         final x10.
                                           runtime.
                                           impl.
                                           java.
                                           PlaceLocalHandle<T> id0) {this.T = T;
                                                                          {
                                                                             
//#line 35
this.__NATIVE_FIELD__ = id0;
                                                                         }}
    
    
//#line 38
public PlaceLocalHandle(final x10.rtt.Type T) {
                                                                       
//#line 35
this(T,
                                                                                        new x10.
                                                                                          runtime.
                                                                                          impl.
                                                                                          java.
                                                                                          PlaceLocalHandle<T>(T));
                                                                    {
                                                                       
                                                                   }}
    
    
//#line 43
final public T
                  apply$G(
                  ){
        
//#line 35
return this.
                             __NATIVE_FIELD__.apply$G();
    }
    
    
//#line 46
final public void
                  set(
                  final T newVal){
        
//#line 35
this.
                      __NATIVE_FIELD__.set(((T)(newVal)));
    }
    
    
//#line 48
final public int
                  hashCode(
                  ){
        
//#line 35
return this.
                             __NATIVE_FIELD__.hashCode();
    }
    
    
//#line 50
final public java.lang.String
                  toString(
                  ){
        
//#line 35
return this.
                             __NATIVE_FIELD__.toString();
    }
    
    
//#line 67
final public <U> void
                  copyTo(
                  final x10.rtt.Type U,
                  final x10.
                    lang.
                    Place dst,
                  final int len,
                  final x10.core.fun.VoidFun_0_0 notifier){
        
//#line 68
final x10.
          lang.
          PlaceLocalHandle<x10.core.Rail<U>> handle =
          ((x10.
          lang.
          PlaceLocalHandle)((new java.lang.Object() {final x10.
          lang.
          PlaceLocalHandle cast(final x10.
          lang.
          PlaceLocalHandle self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.PlaceLocalHandle._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, U));if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          lang.
          PlaceLocalHandle) ((java.lang.Object)
                              this)))));
        
//#line 69
final x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<U>, java.lang.Integer>> finder =
          ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<U>, java.lang.Integer>>() {public final x10.
          util.
          Pair<x10.core.Rail<U>, java.lang.Integer> apply$G() { return apply();}
        public final x10.
          util.
          Pair<x10.core.Rail<U>, java.lang.Integer> apply() { {
            
//#line 69
return new x10.
              util.
              Pair<x10.core.Rail<U>, java.lang.Integer>(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, U),
                                                        x10.rtt.Types.INT,
                                                        handle.apply$G(),
                                                        0);
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, U), x10.rtt.Types.INT);return null;
        }
        }));
        
//#line 70
x10.lang.Rail__NativeRep.copyTo(U, handle.apply$G(),((int)(0)),dst,finder,((int)(len)),notifier);
        
//#line 71
x10.
          lang.
          Runtime.<x10.
          util.
          Pair<x10.core.Rail<U>, java.lang.Integer>>dealloc(new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, U), x10.rtt.Types.INT),
                                                            ((x10.core.fun.Fun_0_0)(finder)));
        
//#line 72
x10.
          lang.
          Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(notifier)));
    }
    
    
//#line 86
final public static <T> x10.
                  lang.
                  PlaceLocalHandle<T>
                  make(
                  final x10.rtt.Type T,
                  final x10.
                    array.
                    Dist dist,
                  final x10.core.fun.Fun_0_0<T> init){
        
//#line 87
final x10.
          lang.
          PlaceLocalHandle<T> handle =
          x10.
          lang.
          Runtime.<x10.
          lang.
          PlaceLocalHandle<T>>evalAt$G(new x10.rtt.ParameterizedType(x10.lang.PlaceLocalHandle._RTT, T),
                                       ((x10.
                                         lang.
                                         Place)(x10.
                                         lang.
                                         Place.FIRST_PLACE)),
                                       ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                         lang.
                                         PlaceLocalHandle<T>>() {public final x10.
                                         lang.
                                         PlaceLocalHandle<T> apply$G() { return apply();}
                                       public final x10.
                                         lang.
                                         PlaceLocalHandle<T> apply() { {
                                           
//#line 87
return new x10.
                                             lang.
                                             PlaceLocalHandle<T>(T);
                                       }}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.PlaceLocalHandle._RTT, T);return null;
                                       }
                                       })));
        
//#line 88
try {{
            
//#line 88
x10.
              lang.
              Runtime.startFinish();
            {
                
//#line 88
for (
//#line 88
final x10.core.Iterator<x10.
                                   lang.
                                   Place> p1796 =
                                   (dist.places()).iterator();
                                 p1796.hasNext();
                                 ) {
                    
//#line 88
final x10.
                      lang.
                      Place p =
                      p1796.next$G();
                    
//#line 89
x10.
                      lang.
                      Runtime.runAsync(((x10.
                                         lang.
                                         Place)(p)),
                                       new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                           
//#line 89
handle.set(((T)(init.apply$G())));
                                       }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                       }
                                       });
                }
            }
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
        java.lang.Throwable __desugarer__var__43__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
        {
            
//#line 88
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__43__)));
            throw new java.lang.RuntimeException();
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (java.lang.Throwable __desugarer__var__43__) {
            
//#line 88
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__43__)));
            throw new java.lang.RuntimeException();
        }finally {{
             
//#line 88
x10.
               lang.
               Runtime.stopFinish();
         }}
        
//#line 91
return handle;
        }
    
    
//#line 35
final public x10.
                  lang.
                  Place
                  home(
                  ){
        
//#line 35
return x10.lang.Place.place(x10.core.Ref.home(this.
                                                                    __NATIVE_FIELD__));
    }
    
    
//#line 35
final public java.lang.String
                  typeName(
                  ){
        
//#line 35
return x10.core.Ref.typeName(this.
                                                   __NATIVE_FIELD__);
    }
    
    
//#line 35
final public boolean
                  at(
                  x10.
                    lang.
                    Place p){
        
//#line 35
return x10.core.Ref.at((java.lang.Object)(this.
                                                                __NATIVE_FIELD__), p.id);
    }
    
    
//#line 35
final public boolean
                  at(
                  java.lang.Object r){
        
//#line 35
return x10.core.Ref.at((java.lang.Object)(this.
                                                                __NATIVE_FIELD__), r);
    }
    
    
//#line 35
final public boolean
                  equals(
                  java.lang.Object other){
        
//#line 35
if ((!(((boolean)(x10.lang.PlaceLocalHandle._RTT.instanceof$(other, T)))))) {
            
//#line 35
return false;
        }
        
//#line 35
return this.equals(((x10.
                                         lang.
                                         PlaceLocalHandle)((new java.lang.Object() {final x10.
                                         lang.
                                         PlaceLocalHandle cast(final x10.
                                         lang.
                                         PlaceLocalHandle self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.PlaceLocalHandle._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                         lang.
                                         PlaceLocalHandle) other)))));
    }
    
    
//#line 35
final public boolean
                  equals(
                  x10.
                    lang.
                    PlaceLocalHandle<T> other){
        
//#line 35
return true;
    }
    
    
//#line 35
final public boolean
                  _struct_equals(
                  java.lang.Object other){
        
//#line 35
if ((!(((boolean)(x10.lang.PlaceLocalHandle._RTT.instanceof$(other, T)))))) {
            
//#line 35
return false;
        }
        
//#line 35
return this._struct_equals(((x10.
                                                 lang.
                                                 PlaceLocalHandle)((new java.lang.Object() {final x10.
                                                 lang.
                                                 PlaceLocalHandle cast(final x10.
                                                 lang.
                                                 PlaceLocalHandle self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.PlaceLocalHandle._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                 lang.
                                                 PlaceLocalHandle) other)))));
    }
    
    
//#line 35
final public boolean
                  _struct_equals(
                  x10.
                    lang.
                    PlaceLocalHandle<T> other){
        
//#line 35
return true;
    }
    
    }
    