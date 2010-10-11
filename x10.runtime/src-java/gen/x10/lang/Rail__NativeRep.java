package x10.lang;


public class Rail__NativeRep
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Rail__NativeRep> _RTT = new x10.rtt.RuntimeType<Rail__NativeRep>(
/* base class */Rail__NativeRep.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 23
private static boolean
                  isCPP(
                  ){
        
//#line 24
return ((boolean) (boolean) 
                             (false));
    }
    
    public static boolean
      isCPP$P(
      ){
        return Rail__NativeRep.isCPP();
    }
    
    
//#line 26
private static boolean
                  isJava(
                  ){
        
//#line 27
return false;
    }
    
    public static boolean
      isJava$P(
      ){
        return true;
    }
    
    
//#line 30
private static boolean
                  useNativeFor(
                  final x10.
                    lang.
                    Place x){
        
//#line 30
return x10.
          lang.
          Rail__NativeRep.isCPP() &&
        (!x10.rtt.Equality.equalsequals(x,x10.
          lang.
          Runtime.here()));
    }
    
    public static boolean
      useNativeFor$P(
      final x10.
        lang.
        Place x){
        return Rail__NativeRep.useNativeFor(((x10.
                                              lang.
                                              Place)(x)));
    }
    
    
//#line 35
native private static <T> void
                  copyTo_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len);
    
    public static <T> void
      copyTo_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> src,
      final int src_off,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final int len){
        java.lang.System.out.println("Should never occur, see Rail.x10");
    }
    
    
//#line 40
native private static <T> void
                  copyFrom_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final int len);
    
    public static <T> void
      copyFrom_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final x10.core.Rail<T> src,
      final int src_off,
      final int len){
        java.lang.System.out.println("Should never occur, see Rail.x10");
    }
    
    
//#line 45
native private static <T> void
                  copyFrom_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final int len);
    
    public static <T> void
      copyFrom_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final x10.core.ValRail<T> src,
      final int src_off,
      final int len){
        java.lang.System.out.println("Should never occur, see Rail.x10");
    }
    
    
//#line 53
native private static <T> void
                  copyToLocal_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len);
    
    public static <T> void
      copyToLocal_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> src,
      final int src_off,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final int len){
        (src).copyToLocal(((int)(src_off)),dst,((int)(dst_off)),((int)(len)));
    }
    
    
//#line 58
native private static <T> void
                  copyFromLocal_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final int len);
    
    public static <T> void
      copyFromLocal_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final x10.core.Rail<T> src,
      final int src_off,
      final int len){
        (dst).copyFromLocal(((int)(dst_off)),src,((int)(src_off)),((int)(len)));
    }
    
    
//#line 63
native private static <T> void
                  copyFromLocal_(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final int len);
    
    public static <T> void
      copyFromLocal_$P(
      final x10.rtt.Type T,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final x10.core.ValRail<T> src,
      final int src_off,
      final int len){
        (dst).copyFromLocal(((int)(dst_off)),src,((int)(src_off)),((int)(len)));
    }
    
    
//#line 78
public static <T> void
                  localCopyTo(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len){
        
//#line 79
for (
//#line 79
int i =
                           0;
                         ((((int)(i))) < (((int)(len))));
                         
//#line 79
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 80
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
        }
    }
    
    
//#line 84
public static <T> void
                  copyTo(
                  final x10.rtt.Type T,
                  final x10.core.Rail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len){
        
//#line 85
if (x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(dst)),x10.
                          lang.
                          Runtime.here()) &&
                        true) {
            
//#line 85
(src).copyToLocal(((int)(src_off)),dst,((int)(dst_off)),((int)(len)));
            
//#line 85
return;
        }
        
//#line 86
if (x10.
                          lang.
                          Rail__NativeRep.useNativeFor(((x10.
                                                         lang.
                                                         Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))))) {
            
//#line 86
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 86
return;
        }
        
//#line 88
final x10.core.ValRail<T> to_serialize =
          ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
        
//#line 89
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 90
if (true) {
                                
//#line 90
(to_serialize).copyToLocal(((int)(src_off)),dst,((int)(dst_off)),((int)(len)));
                            } else {
                                
//#line 92
for (
//#line 92
int i =
                                                   0;
                                                 ((((int)(i))) < (((int)(len))));
                                                 
//#line 92
i = ((((int)(i))) + (((int)(1))))) {
                                    
//#line 93
(dst).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                                }
                            }
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 101
public static <T> void
                   localCopyFrom(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final int len){
        
//#line 102
for (
//#line 102
int i =
                            0;
                          ((((int)(i))) < (((int)(len))));
                          
//#line 102
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 103
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
        }
    }
    
    
//#line 107
public static <T> void
                   copyFrom(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final int len){
        
//#line 110
if (x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(src)),x10.
                           lang.
                           Runtime.here()) &&
                         true) {
            
//#line 110
(dst).copyFromLocal(((int)(dst_off)),src,((int)(src_off)),((int)(len)));
            
//#line 110
return;
        }
        
//#line 111
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(x10.lang.Place.place(x10.core.Ref.home(src)))))) {
            
//#line 111
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 111
return;
        }
        
//#line 115
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(src)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 116
final x10.core.ValRail<T> to_serialize =
                              ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
                            
//#line 117
x10.
                              lang.
                              Runtime.runAt(((x10.
                                              lang.
                                              Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))),
                                            ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                                
//#line 118
if (true) {
                                                    
//#line 118
(dst).copyFromLocal(((int)(dst_off)),to_serialize,((int)(src_off)),((int)(len)));
                                                } else {
                                                    
//#line 120
for (
//#line 120
int i =
                                                                        0;
                                                                      ((((int)(i))) < (((int)(len))));
                                                                      
//#line 120
i = ((((int)(i))) + (((int)(1))))) {
                                                        
//#line 121
(dst).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                                                    }
                                                }
                                            }}
                                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                            }
                                            })));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 127
public static <T> void
                   copyFrom(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.core.ValRail<T> src,
                   final int src_off,
                   final int len){
        
//#line 130
if (true) {
            
//#line 130
(dst).copyFromLocal(((int)(dst_off)),src,((int)(src_off)),((int)(len)));
            
//#line 130
return;
        }
        
//#line 131
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(x10.lang.Place.place(x10.core.Ref.home(src)))))) {
            
//#line 131
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 131
return;
        }
        
//#line 136
for (
//#line 136
int i =
                            0;
                          ((((int)(i))) < (((int)(len))));
                          
//#line 136
i = ((((int)(i))) + (((int)(1))))) {
            
//#line 137
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
        }
    }
    
    
//#line 144
native public static <T> void
                   copyTo_(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                   final int len);
    
    
//#line 150
native public static <T> void
                   copyFrom_(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                   final int len);
    
    
//#line 156
native public static <T> void
                   copyFrom1_(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.
                     lang.
                     Place src_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.ValRail<T>, java.lang.Integer>> src_finder,
                   final int len);
    
    
//#line 163
public static <T> void
                   copyTo(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                   final int len){
        
//#line 166
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(dst_place)))) {
            
//#line 166
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 166
return;
        }
        
//#line 170
final x10.core.ValRail<T> to_serialize =
          ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
        
//#line 171
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(dst_place)),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 172
final x10.
                              util.
                              Pair<x10.core.Rail<T>, java.lang.Integer> pair =
                              ((x10.
                              util.
                              Pair)(dst_finder.apply$G()));
                            
//#line 173
final x10.core.Rail<T> dst =
                              ((x10.core.Rail)(pair.
                                                 first));
                            
//#line 174
final int dst_off =
                              pair.
                                second;
                            
//#line 176
for (
//#line 176
int i =
                                                0;
                                              ((((int)(i))) < (((int)(len))));
                                              
//#line 176
i = ((((int)(i))) + (((int)(1))))) {
                                
//#line 177
(dst).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                            }
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 182
public static <T> void
                   copyFrom(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.
                     lang.
                     Place src_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> src_finder,
                   final int len){
        
//#line 185
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(src_place)))) {
            
//#line 185
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 185
return;
        }
        
//#line 189
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(src_place)),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 190
final x10.
                              util.
                              Pair<x10.core.Rail<T>, java.lang.Integer> pair =
                              ((x10.
                              util.
                              Pair)(src_finder.apply$G()));
                            
//#line 191
final x10.core.Rail<T> src =
                              ((x10.core.Rail)(pair.
                                                 first));
                            
//#line 192
final int src_off =
                              pair.
                                second;
                            
//#line 193
final x10.core.ValRail<T> to_serialize =
                              ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
                            
//#line 194
x10.
                              lang.
                              Runtime.runAt(((x10.
                                              lang.
                                              Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))),
                                            ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                                
//#line 196
for (
//#line 196
int i =
                                                                    0;
                                                                  ((((int)(i))) < (((int)(len))));
                                                                  
//#line 196
i = ((((int)(i))) + (((int)(1))))) {
                                                    
//#line 197
(dst).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                                                }
                                            }}
                                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                            }
                                            })));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 204
public static <T> void
                   copyFrom1(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final x10.
                     lang.
                     Place src_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.ValRail<T>, java.lang.Integer>> src_finder,
                   final int len){
        
//#line 207
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(src_place)))) {
            
//#line 207
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 207
return;
        }
        
//#line 212
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(src_place)),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 213
final x10.
                              util.
                              Pair<x10.core.ValRail<T>, java.lang.Integer> pair =
                              ((x10.
                              util.
                              Pair)(src_finder.apply$G()));
                            
//#line 214
final x10.core.ValRail<T> src =
                              ((x10.core.ValRail)(pair.
                                                    first));
                            
//#line 215
final int src_off =
                              pair.
                                second;
                            
//#line 216
x10.
                              lang.
                              Runtime.runAt(((x10.
                                              lang.
                                              Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))),
                                            ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                                
//#line 218
for (
//#line 218
int i =
                                                                    0;
                                                                  ((((int)(i))) < (((int)(len))));
                                                                  
//#line 218
i = ((((int)(i))) + (((int)(1))))) {
                                                    
//#line 219
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                                                }
                                            }}
                                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                            }
                                            })));
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 230
native public static <T> void
                   copyTo_(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final int len,
                   final x10.core.fun.VoidFun_0_0 notifier);
    
    
//#line 236
public static <T> void
                   copyTo(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.core.Rail<T> dst,
                   final int dst_off,
                   final int len,
                   final x10.core.fun.VoidFun_0_0 notifier){
        
//#line 239
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))))) {
            
//#line 239
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 239
return;
        }
        
//#line 240
if (x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(dst)),x10.
                           lang.
                           Runtime.here())) {
            
//#line 241
final x10.core.Rail<T> dst2 =
              ((x10.core.Rail)(new x10.core.fun.Fun_0_1<x10.core.Rail<T>, x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G(final x10.core.Rail<T> __desugarer__var__44__) { return apply(__desugarer__var__44__);}
            public final x10.core.Rail<T> apply(final x10.core.Rail<T> __desugarer__var__44__) { {
                
//#line 241
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__44__,null)) &&
                                   !(x10.rtt.Equality.equalsequals(((x10.
                                       lang.
                                       Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__44__)))),x10.
                                       lang.
                                       Runtime.here()))) {
                    
//#line 241
throw new java.lang.ClassCastException("x10.lang.Rail[T]{self.home==here}");
                }
                
//#line 241
return __desugarer__var__44__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
            }
            }.apply(((x10.core.Rail)
                      dst))));
            
//#line 242
for (
//#line 242
int i =
                                0;
                              ((((int)(i))) < (((int)(len))));
                              
//#line 242
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 243
(dst2).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
            }
            
//#line 245
notifier.apply();
            
//#line 246
return;
        }
        
//#line 251
final x10.core.ValRail<T> to_serialize =
          ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
        
//#line 252
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(dst)).
                                                                  id)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
            
//#line 253
final x10.core.Rail<T> dst2 =
              ((x10.core.Rail)(new x10.core.fun.Fun_0_1<x10.core.Rail<T>, x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G(final x10.core.Rail<T> __desugarer__var__45__) { return apply(__desugarer__var__45__);}
            public final x10.core.Rail<T> apply(final x10.core.Rail<T> __desugarer__var__45__) { {
                
//#line 253
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__45__,null)) &&
                                   !(x10.rtt.Equality.equalsequals(((x10.
                                       lang.
                                       Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__45__)))),x10.
                                       lang.
                                       Runtime.here()))) {
                    
//#line 253
throw new java.lang.ClassCastException("x10.lang.Rail[T]{self.home==here}");
                }
                
//#line 253
return __desugarer__var__45__;
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
            }
            }.apply(((x10.core.Rail)
                      dst))));
            
//#line 255
for (
//#line 255
int i =
                                0;
                              ((((int)(i))) < (((int)(len))));
                              
//#line 255
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 256
(dst2).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
            }
            
//#line 258
notifier.apply();
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
        }
        });
    }
    
    
//#line 262
native public static <T> void
                   copyTo_(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                   final int len,
                   final x10.core.fun.VoidFun_0_0 notifier);
    
    
//#line 268
public static <T> void
                   copyTo(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.core.fun.Fun_0_0<x10.
                     util.
                     Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                   final int len,
                   final x10.core.fun.VoidFun_0_0 notifier){
        
//#line 271
if (x10.
                           lang.
                           Rail__NativeRep.useNativeFor(((x10.
                                                          lang.
                                                          Place)(dst_place)))) {
            
//#line 271
java.lang.System.out.println("Should never occur, see Rail.x10");
            
//#line 271
return;
        }
        
//#line 272
if (x10.rtt.Equality.equalsequals(dst_place,x10.
                           lang.
                           Runtime.here())) {
            
//#line 273
final x10.
              util.
              Pair<x10.core.Rail<T>, java.lang.Integer> pair =
              dst_finder.apply$G();
            
//#line 274
final x10.core.Rail<T> dst =
              ((x10.core.Rail)(pair.
                                 first));
            
//#line 275
final int dst_off =
              pair.
                second;
            
//#line 276
for (
//#line 276
int i =
                                0;
                              ((((int)(i))) < (((int)(len))));
                              
//#line 276
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 277
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
            }
            
//#line 279
notifier.apply();
            
//#line 280
return;
        }
        
//#line 285
final x10.core.ValRail<T> to_serialize =
          ((x10.core.ValRail)(x10.core.RailFactory.<T>makeValRailFromRail(T, src)));
        
//#line 286
x10.runtime.impl.java.Runtime.runAt(((int)(dst_place.
                                                                  id)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
            
//#line 287
final x10.
              util.
              Pair<x10.core.Rail<T>, java.lang.Integer> pair =
              dst_finder.apply$G();
            
//#line 288
final x10.core.Rail<T> dst =
              ((x10.core.Rail)(pair.
                                 first));
            
//#line 289
final int dst_off =
              pair.
                second;
            
//#line 291
for (
//#line 291
int i =
                                0;
                              ((((int)(i))) < (((int)(len))));
                              
//#line 291
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 292
(dst).set$G((to_serialize).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
            }
            
//#line 294
notifier.apply();
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
        }
        });
    }
    
    
//#line 313
public static <T> void
                   copyTo(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst_place,
                   final x10.
                     lang.
                     PlaceLocalHandle<x10.core.Rail<T>> dst_handle,
                   final int dst_off,
                   final int len){
        
//#line 316
final x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>> finder =
          ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>>() {public final x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer> apply$G() { return apply();}
        public final x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer> apply() { {
            
//#line 316
return new x10.
              util.
              Pair<x10.core.Rail<T>, java.lang.Integer>(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                        x10.rtt.Types.INT,
                                                        dst_handle.apply$G(),
                                                        dst_off);
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T), x10.rtt.Types.INT);return null;
        }
        }));
        
//#line 317
x10.lang.Rail__NativeRep.copyTo(T, src,((int)(src_off)),dst_place,finder,((int)(len)));
        
//#line 318
x10.
          lang.
          Runtime.<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>>dealloc(new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T), x10.rtt.Types.INT),
                                                            ((x10.core.fun.Fun_0_0)(finder)));
    }
    
    
//#line 321
public static <T> void
                   copyTo(
                   final x10.rtt.Type T,
                   final x10.core.Rail<T> src,
                   final int src_off,
                   final x10.
                     lang.
                     Place dst,
                   final x10.
                     lang.
                     PlaceLocalHandle<x10.core.Rail<T>> dst_handle,
                   final int dst_off,
                   final int len,
                   final x10.core.fun.VoidFun_0_0 notifier){
        
//#line 324
final x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>> finder =
          ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>>() {public final x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer> apply$G() { return apply();}
        public final x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer> apply() { {
            
//#line 324
return new x10.
              util.
              Pair<x10.core.Rail<T>, java.lang.Integer>(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                        x10.rtt.Types.INT,
                                                        dst_handle.apply$G(),
                                                        dst_off);
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T), x10.rtt.Types.INT);return null;
        }
        }));
        
//#line 325
x10.lang.Rail__NativeRep.copyTo(T, src,((int)(src_off)),dst,finder,((int)(len)),notifier);
        
//#line 326
x10.
          lang.
          Runtime.<x10.
          util.
          Pair<x10.core.Rail<T>, java.lang.Integer>>dealloc(new x10.rtt.ParameterizedType(x10.util.Pair._RTT, new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T), x10.rtt.Types.INT),
                                                            ((x10.core.fun.Fun_0_0)(finder)));
        
//#line 327
x10.
          lang.
          Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(notifier)));
    }
    
    
//#line 331
private static <T> x10.core.Rail<T>
                   cudaMakeRail(
                   final x10.rtt.Type T,
                   final x10.
                     lang.
                     Place dst,
                   final int length){
        
//#line 332
return null;
    }
    
    public static <T> x10.core.Rail<T>
      cudaMakeRail$P(
      final x10.rtt.Type T,
      final x10.
        lang.
        Place dst,
      final int length){
        return Rail__NativeRep.<T>cudaMakeRail(T,
                                               ((x10.
                                                 lang.
                                                 Place)(dst)),
                                               (int)(length));
    }
    
    
//#line 334
public static <T> x10.core.Rail<T>
                   makeRemoteRail(
                   final x10.rtt.Type T,
                   final x10.
                     lang.
                     Place p,
                   final int length,
                   final x10.core.fun.Fun_0_1<java.lang.Integer,T> init){
        
//#line 337
final x10.core.Rail<T> tmp =
          ((x10.core.Rail)(x10.core.RailFactory.<T>makeVarRail(T, ((int)(length)), init)));
        
//#line 338
return x10.
          lang.
          Rail__NativeRep.<T>makeRemoteRail(T,
                                            ((x10.
                                              lang.
                                              Place)(p)),
                                            (int)(length),
                                            ((x10.core.Rail)(tmp)));
    }
    
    
//#line 341
public static <T> x10.core.Rail<T>
                   makeRemoteRail(
                   final x10.rtt.Type T,
                   final x10.
                     lang.
                     Place p,
                   final int length,
                   final x10.core.Rail<T> init){
        
//#line 345
final x10.core.Rail<T> r =
          ((x10.core.Rail)(new x10.core.fun.Fun_0_1<x10.core.Rail<T>, x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G(final x10.core.Rail<T> __desugarer__var__46__) { return apply(__desugarer__var__46__);}
        public final x10.core.Rail<T> apply(final x10.core.Rail<T> __desugarer__var__46__) { {
            
//#line 345
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__46__,null)) &&
                               !(((int) __desugarer__var__46__.
                                          length) ==
                                 ((int) length))) {
                
//#line 345
throw new java.lang.ClassCastException("x10.lang.Rail[T]{self.length==length}");
            }
            
//#line 345
return __desugarer__var__46__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
        }
        }.apply(((x10.core.Rail)
                  (p.isCUDA()
                     ? x10.
                     lang.
                     Rail__NativeRep.<T>cudaMakeRail(T,
                                                     ((x10.
                                                       lang.
                                                       Place)(p)),
                                                     (int)(length))
                     : x10.
                     lang.
                     Runtime.<x10.core.Rail<T>>evalAt$G(new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T),
                                                        ((x10.
                                                          lang.
                                                          Place)(p)),
                                                        ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.core.Rail<T>>() {public final x10.core.Rail<T> apply$G() { return apply();}
                                                        public final x10.core.Rail<T> apply() { {
                                                            
//#line 345
return x10.core.RailFactory.<T>makeVarRail(T, ((int)(length)));
                                                        }}
                                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.core.Rail._RTT, T);return null;
                                                        }
                                                        }))))))));
        
//#line 346
try {{
            
//#line 346
x10.
              lang.
              Runtime.startFinish();
            {
                
//#line 346
x10.lang.Rail__NativeRep.copyTo(T, init,((int)(0)),r,((int)(0)),((int)(length)));
            }
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
        java.lang.Throwable __desugarer__var__47__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
        {
            
//#line 346
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__47__)));
            throw new java.lang.RuntimeException();
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (java.lang.Throwable __desugarer__var__47__) {
            
//#line 346
x10.
              lang.
              Runtime.pushException(((java.lang.Throwable)(__desugarer__var__47__)));
            throw new java.lang.RuntimeException();
        }finally {{
             
//#line 346
x10.
               lang.
               Runtime.stopFinish();
         }}
        
//#line 347
return r;
        }
    
    
//#line 21
public Rail__NativeRep() {
        
//#line 21
super();
    }
    
    }
    