package x10.lang;


public class ValRail__NativeRep
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<ValRail__NativeRep> _RTT = new x10.rtt.RuntimeType<ValRail__NativeRep>(
/* base class */ValRail__NativeRep.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 22
private static boolean
                  isCPP(
                  ){
        
//#line 23
return ((boolean) (boolean) 
                             (false));
    }
    
    public static boolean
      isCPP$P(
      ){
        return ValRail__NativeRep.isCPP();
    }
    
    
//#line 25
private static boolean
                  isJava(
                  ){
        
//#line 26
return false;
    }
    
    public static boolean
      isJava$P(
      ){
        return true;
    }
    
    
//#line 28
private static boolean
                  useNativeFor(
                  final x10.
                    lang.
                    Place x){
        
//#line 28
return x10.
          lang.
          ValRail__NativeRep.isCPP() &&
        (!x10.rtt.Equality.equalsequals(x,x10.
          lang.
          Runtime.here()));
    }
    
    public static boolean
      useNativeFor$P(
      final x10.
        lang.
        Place x){
        return ValRail__NativeRep.useNativeFor(((x10.
                                                 lang.
                                                 Place)(x)));
    }
    
    
//#line 32
native private static <T> void
                  copyTo_(
                  final x10.rtt.Type T,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len);
    
    public static <T> void
      copyTo_$P(
      final x10.rtt.Type T,
      final x10.core.ValRail<T> src,
      final int src_off,
      final x10.core.Rail<T> dst,
      final int dst_off,
      final int len){
        java.lang.System.out.println("Should never occur, see ValRail.x10");
    }
    
    
//#line 40
native public static <T> void
                  copyToLocal_(
                  final x10.rtt.Type T,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len);
    
    
//#line 46
public static <T> void
                  copyTo(
                  final x10.rtt.Type T,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final x10.core.Rail<T> dst,
                  final int dst_off,
                  final int len){
        
//#line 49
if (x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(dst)),x10.
                          lang.
                          Runtime.here()) &&
                        true) {
            
//#line 49
(src).copyToLocal(((int)(src_off)),dst,((int)(dst_off)),((int)(len)));
            
//#line 49
return;
        }
        
//#line 52
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(dst)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 53
if (true) {
                                
//#line 53
(src).copyToLocal(((int)(src_off)),dst,((int)(dst_off)),((int)(len)));
                            } else {
                                
//#line 55
for (
//#line 55
int i =
                                                   0;
                                                 ((((int)(i))) < (((int)(len))));
                                                 
//#line 55
i = ((((int)(i))) + (((int)(1))))) {
                                    
//#line 56
(dst).set$G((src).apply$G(((int)(((((int)(src_off))) + (((int)(i))))))), ((int)(((((int)(dst_off))) + (((int)(i)))))));
                                }
                            }
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 63
native private static <T> void
                  copyTo_(
                  final x10.rtt.Type T,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final x10.
                    lang.
                    Place dst_place,
                  final x10.core.fun.Fun_0_0<x10.
                    util.
                    Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                  final int len);
    
    public static <T> void
      copyTo_$P(
      final x10.rtt.Type T,
      final x10.core.ValRail<T> src,
      final int src_off,
      final x10.
        lang.
        Place dst_place,
      final x10.core.fun.Fun_0_0<x10.
        util.
        Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
      final int len){
        java.lang.System.out.println("Should never occur, see ValRail.x10");
    }
    
    
//#line 69
public static <T> void
                  copyTo(
                  final x10.rtt.Type T,
                  final x10.core.ValRail<T> src,
                  final int src_off,
                  final x10.
                    lang.
                    Place dst_place,
                  final x10.core.fun.Fun_0_0<x10.
                    util.
                    Pair<x10.core.Rail<T>, java.lang.Integer>> dst_finder,
                  final int len){
        
//#line 74
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(dst_place)),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 75
final x10.
                              util.
                              Pair<x10.core.Rail<T>, java.lang.Integer> pair =
                              ((x10.
                              util.
                              Pair)(dst_finder.apply$G()));
                            
//#line 76
final x10.core.Rail<T> dst =
                              ((x10.core.Rail)(pair.
                                                 first));
                            
//#line 77
final int dst_off =
                              pair.
                                second;
                            
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
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
    }
    
    
//#line 20
public ValRail__NativeRep() {
        
//#line 20
super();
    }

}
