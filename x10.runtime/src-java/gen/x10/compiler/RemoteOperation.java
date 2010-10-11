package x10.compiler;

final public class RemoteOperation
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<RemoteOperation> _RTT = new x10.rtt.RuntimeType<RemoteOperation>(
/* base class */RemoteOperation.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 19
public static void
                  xor(
                  final x10.
                    lang.
                    Place p,
                  final x10.core.Rail<java.lang.Long> r,
                  final int i,
                  final long v){
        
//#line 21
x10.
          lang.
          Runtime.runAsync(((x10.
                             lang.
                             Place)(p)),
                           new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                               
//#line 22
((long[])(new x10.core.fun.Fun_0_1<x10.core.Rail<java.lang.Long>, x10.core.Rail<java.lang.Long>>() {public final x10.core.Rail<java.lang.Long> apply$G(final x10.core.Rail<java.lang.Long> __desugarer__var__36__) { return apply(__desugarer__var__36__);}
                                                     public final x10.core.Rail<java.lang.Long> apply(final x10.core.Rail<java.lang.Long> __desugarer__var__36__) { {
                                                         
//#line 22
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__36__,null)) &&
                                                                           !(x10.rtt.Equality.equalsequals(((x10.
                                                                               lang.
                                                                               Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__36__)))),x10.
                                                                               lang.
                                                                               Runtime.here()))) {
                                                             
//#line 22
throw new java.lang.ClassCastException("x10.lang.Rail[x10.lang.Long]{self.home==here}");
                                                         }
                                                         
//#line 22
return __desugarer__var__36__;
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.LONG);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.LONG);return null;
                                                     }
                                                     }.apply(((x10.core.Rail)
                                                               r))).value)[i] ^= v;
                           }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                           public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                           }
                           });
    }
    
    
//#line 26
public static void
                  xor(
                  final int id,
                  final x10.core.Rail<java.lang.Long> r,
                  final int i,
                  final long v){
        
//#line 28
x10.
          lang.
          Runtime.runAsync(((x10.
                             lang.
                             Place)(new x10.
                             lang.
                             Place(id))),
                           new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                               
//#line 29
((long[])(new x10.core.fun.Fun_0_1<x10.core.Rail<java.lang.Long>, x10.core.Rail<java.lang.Long>>() {public final x10.core.Rail<java.lang.Long> apply$G(final x10.core.Rail<java.lang.Long> __desugarer__var__37__) { return apply(__desugarer__var__37__);}
                                                     public final x10.core.Rail<java.lang.Long> apply(final x10.core.Rail<java.lang.Long> __desugarer__var__37__) { {
                                                         
//#line 29
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__37__,null)) &&
                                                                           !(x10.rtt.Equality.equalsequals(((x10.
                                                                               lang.
                                                                               Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__37__)))),x10.
                                                                               lang.
                                                                               Runtime.here()))) {
                                                             
//#line 29
throw new java.lang.ClassCastException("x10.lang.Rail[x10.lang.Long]{self.home==here}");
                                                         }
                                                         
//#line 29
return __desugarer__var__37__;
                                                     }}
                                                     public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.LONG);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, x10.rtt.Types.LONG);return null;
                                                     }
                                                     }.apply(((x10.core.Rail)
                                                               r))).value)[i] ^= v;
                           }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                           public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                           }
                           });
    }
    
    
//#line 33
public static void
                  fence(
                  ){
        
    }
    
    
//#line 17
public RemoteOperation() {
        
//#line 17
super();
    }

}
