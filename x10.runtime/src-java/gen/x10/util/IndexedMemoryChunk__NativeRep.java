package x10.util;


abstract public class IndexedMemoryChunk__NativeRep
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<IndexedMemoryChunk__NativeRep> _RTT = new x10.rtt.RuntimeType<IndexedMemoryChunk__NativeRep>(
/* base class */IndexedMemoryChunk__NativeRep.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 24
private static <T> void
                  copyToLocal(
                  final x10.rtt.Type T,
                  final x10.core.IndexedMemoryChunk<T> src,
                  final int srcIndex,
                  final x10.core.IndexedMemoryChunk<T> dst,
                  final int dstIndex,
                  final int numElems){
        
    }
    
    public static <T> void
      copyToLocal$P(
      final x10.rtt.Type T,
      final x10.core.IndexedMemoryChunk<T> src,
      final int srcIndex,
      final x10.core.IndexedMemoryChunk<T> dst,
      final int dstIndex,
      final int numElems){
        (src)._copyToLocal(((int)(srcIndex)),dst,((int)(dstIndex)),((int)(numElems)));
    }
    
    
//#line 27
private static <T> void
                  copyFromLocal(
                  final x10.rtt.Type T,
                  final x10.core.IndexedMemoryChunk<T> dst,
                  final int dstIndex,
                  final x10.core.IndexedMemoryChunk<T> src,
                  final int srcIndex,
                  final int numElems){
        
    }
    
    public static <T> void
      copyFromLocal$P(
      final x10.rtt.Type T,
      final x10.core.IndexedMemoryChunk<T> dst,
      final int dstIndex,
      final x10.core.IndexedMemoryChunk<T> src,
      final int srcIndex,
      final int numElems){
        (dst)._copyFromLocal(((int)(dstIndex)),src,((int)(srcIndex)),((int)(numElems)));
    }
    
    
//#line 30
public static <T> void
                  copyTo(
                  final x10.rtt.Type T,
                  final x10.core.IndexedMemoryChunk<T> src,
                  final int srcIndex,
                  final x10.
                    lang.
                    Place dstPlace,
                  final x10.core.IndexedMemoryChunk<T> dst,
                  final int dstIndex,
                  final int numElems,
                  final boolean uncounted){
        
//#line 34
if (x10.rtt.Equality.equalsequals(dstPlace,x10.
                          lang.
                          Runtime.here())) {
            
//#line 35
(src)._copyToLocal(((int)(srcIndex)),dst,((int)(dstIndex)),((int)(numElems)));
        } else {
            
//#line 37
x10.
              lang.
              Runtime.runAt(((x10.
                              lang.
                              Place)(dstPlace)),
                            ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                
//#line 39
for (
//#line 39
int i =
                                                   0;
                                                 ((((int)(i))) < (((int)(numElems))));
                                                 
//#line 39
i = ((((int)(i))) + (((int)(1))))) {
                                    
//#line 40
(dst).set((src).apply$G(((int)(((((int)(srcIndex))) + (((int)(i))))))), ((int)(((((int)(dstIndex))) + (((int)(i)))))));
                                }
                            }}
                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                            }
                            })));
        }
    }
    
    
//#line 46
public static <T> void
                  copyFrom(
                  final x10.rtt.Type T,
                  final x10.core.IndexedMemoryChunk<T> dst,
                  final int dstIndex,
                  final x10.
                    lang.
                    Place srcPlace,
                  final x10.core.IndexedMemoryChunk<T> src,
                  final int srcIndex,
                  final int numElems,
                  final boolean uncounted){
        
//#line 50
if (x10.rtt.Equality.equalsequals(srcPlace,x10.
                          lang.
                          Runtime.here())) {
            
//#line 51
(dst)._copyFromLocal(((int)(dstIndex)),src,((int)(srcIndex)),((int)(numElems)));
        } else {
            
//#line 54
for (
//#line 54
int i =
                               0;
                             ((((int)(i))) < (((int)(numElems))));
                             
//#line 54
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 55
(dst).set((src).apply$G(((int)(((((int)(srcIndex))) + (((int)(i))))))), ((int)(((((int)(dstIndex))) + (((int)(i)))))));
            }
        }
    }
    
    
//#line 22
public IndexedMemoryChunk__NativeRep() {
        
//#line 22
super();
    }

}
