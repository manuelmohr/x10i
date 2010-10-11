package x10.lang;


public class MultipleExceptions
extends java.lang.RuntimeException
{public static final x10.rtt.RuntimeType<MultipleExceptions> _RTT = new x10.rtt.RuntimeType<MultipleExceptions>(
/* base class */MultipleExceptions.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.RuntimeException.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 22
final public x10.core.ValRail<java.lang.Throwable>
      exceptions;
    
    
    
//#line 24
public MultipleExceptions(final x10.
                                            util.
                                            Stack<java.lang.Throwable> stack) {
        super();
        
//#line 25
final x10.
          util.
          Stack<java.lang.Throwable> s =
          ((x10.
          util.
          Stack)(new x10.
          util.
          Stack<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class))));
        
//#line 27
for (
//#line 27
final x10.core.Iterator<java.lang.Throwable> t1787 =
                           (stack.toValRail()).iterator();
                         t1787.hasNext();
                         ) {
            
//#line 27
final java.lang.Throwable t =
              ((java.lang.Throwable)(t1787.next$G()));
            
//#line 28
if (x10.lang.MultipleExceptions._RTT.instanceof$(t)) {
                
//#line 29
for (
//#line 29
final x10.core.Iterator<java.lang.Throwable> u1786 =
                                   ((((new java.lang.Object() {final x10.
                                        lang.
                                        MultipleExceptions cast(final x10.
                                        lang.
                                        MultipleExceptions self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.MultipleExceptions._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                        lang.
                                        MultipleExceptions) t)))).
                                      exceptions).iterator();
                                 u1786.hasNext();
                                 ) {
                    
//#line 29
final java.lang.Throwable u =
                      u1786.next$G();
                    
//#line 30
s.push(((java.lang.Throwable)(u)));
                }
            } else {
                
//#line 32
s.push(((java.lang.Throwable)(t)));
            }
        }
        
//#line 35
this.exceptions = s.toValRail();
    }
    
    
//#line 38
public MultipleExceptions(final java.lang.Throwable t) {
        super();
        
//#line 39
final x10.
          util.
          Stack<java.lang.Throwable> s =
          ((x10.
          util.
          Stack)(new x10.
          util.
          Stack<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class))));
        
//#line 40
if (x10.lang.MultipleExceptions._RTT.instanceof$(t)) {
            
//#line 41
for (
//#line 41
final x10.core.Iterator<java.lang.Throwable> u1788 =
                               ((((new java.lang.Object() {final x10.
                                    lang.
                                    MultipleExceptions cast(final x10.
                                    lang.
                                    MultipleExceptions self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.MultipleExceptions._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                    lang.
                                    MultipleExceptions) t)))).
                                  exceptions).iterator();
                             u1788.hasNext();
                             ) {
                
//#line 41
final java.lang.Throwable u =
                  u1788.next$G();
                
//#line 42
s.push(((java.lang.Throwable)(u)));
            }
        } else {
            
//#line 44
s.push(((java.lang.Throwable)(t)));
        }
        
//#line 46
this.exceptions = s.toValRail();
    }
    
    
//#line 51
public void
                  printStackTrace(
                  ){
        
//#line 53
for (
//#line 53
final x10.core.Iterator<java.lang.Throwable> t1789 =
                           (exceptions).iterator();
                         t1789.hasNext();
                         ) {
            
//#line 53
final java.lang.Throwable t =
              t1789.next$G();
            
//#line 54
t.printStackTrace();
        }
    }
    
    
//#line 58
public void
                  printStackTrace(
                  final x10.
                    io.
                    Printer p){
        
    }
    
    
//#line 22
final public x10.core.ValRail<java.lang.Throwable>
                  exceptions(
                  ){
        
//#line 22
return this.
                             exceptions;
    }

}
