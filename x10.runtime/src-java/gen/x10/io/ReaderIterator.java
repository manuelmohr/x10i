package x10.io;


public class ReaderIterator<T>
extends x10.core.Ref
  implements x10.core.Iterator<T>,
             x10.core.Iterable<T >
{public static final x10.rtt.RuntimeType<ReaderIterator> _RTT = new x10.rtt.RuntimeType<ReaderIterator>(
/* base class */ReaderIterator.class, 
/* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
, /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterator.class), new x10.rtt.UnresolvedType(0)), new x10.rtt.ParameterizedType(new x10.rtt.RuntimeType(x10.core.Iterable.class), new x10.rtt.UnresolvedType(0)), x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}

public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}

    private final x10.rtt.Type T;
    
    
//#line 31
final public x10.
      io.
      Reader
      r;
    
//#line 32
final public x10.
      io.
      Marshal<T>
      m;
    
//#line 33
public x10.
      util.
      Box<T>
      next;
    
    
//#line 35
public ReaderIterator(final x10.rtt.Type T,
                                      final x10.
                                        io.
                                        Marshal<T> m,
                                      final x10.
                                        io.
                                        Reader r) {
                                                           super();
                                                       this.T = T;
                                                        {
                                                           
//#line 33
this.next = null;
                                                           
//#line 36
this.m = m;
                                                           
//#line 37
this.r = r;
                                                       }}
    
    
//#line 42
public x10.core.Iterator<T>
                  iterator(
                  ){
        
//#line 42
return this;
    }
    
    
//#line 44
public T
                  next$G(
                  ){
        
//#line 45
if ((!(((boolean)(this.hasNext()))))) {
            
//#line 46
throw new x10.
              util.
              NoSuchElementException();
        }
        
//#line 47
final T x =
          ((T)(next.
                 value));
        
//#line 48
this.next = null;
        
//#line 49
return x;
    }
    
    
//#line 52
public boolean
                  hasNext(
                  ){
        
//#line 53
if (x10.rtt.Equality.equalsequals(next,null)) {
            
//#line 54
try {{
                
//#line 55
final T x =
                  ((T)(r.<T>read$G(T,
                                   ((x10.
                                     io.
                                     Marshal)(m)))));
                
//#line 56
this.next = new x10.
                  util.
                  Box<T>(T,
                         x);
            }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
            if (__$generated_wrappedex$__.getCause() instanceof java.io.IOException) {
            final java.io.IOException id$91 = (java.io.IOException) __$generated_wrappedex$__.getCause();
            {
                
//#line 59
return false;
            }
            }
            else {
            throw __$generated_wrappedex$__;
            }
            }catch (final java.io.IOException id$91) {
                
//#line 59
return false;
            }
        }
        
//#line 62
return true;
    }

}
