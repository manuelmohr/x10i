package x10.lang;


public class Activity
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Activity> _RTT = new x10.rtt.RuntimeType<Activity>(
/* base class */Activity.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 29
public static boolean
                  sleep(
                  final long millis){
        
//#line 30
try {{
            
//#line 31
x10.
              lang.
              Runtime.increaseParallelism();
            
//#line 32
x10.
              lang.
              Runtime.
              Thread.sleep((long)(millis));
            
//#line 33
x10.
              lang.
              Runtime.decreaseParallelism((int)(1));
            
//#line 34
return true;
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.InterruptedException) {
        final java.lang.InterruptedException e = (java.lang.InterruptedException) __$generated_wrappedex$__.getCause();
        {
            
//#line 36
x10.
              lang.
              Runtime.decreaseParallelism((int)(1));
            
//#line 37
return false;
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.InterruptedException e) {
            
//#line 36
x10.
              lang.
              Runtime.decreaseParallelism((int)(1));
            
//#line 37
return false;
        }
    }
    
    
//#line 44
/**
     * the finish state governing the execution of this activity (may be remote)
     */final public x10.
      lang.
      Runtime.
      FinishState
      finishState;
    
//#line 49
/**
     * safe to run pending jobs while waiting for a finish (temporary)
     */final public boolean
      safe;
    
//#line 54
/**
     * The user-specified code for this activity.
     */final public x10.core.fun.VoidFun_0_0
      body;
    
//#line 60
/**
     * The mapping from registered clocks to phases for this activity.
     * Lazily created.
     */public x10.
      lang.
      Runtime.
      ClockPhases
      clockPhases;
    
//#line 66
/**
     * The finish states for the finish statements currently executed by this activity.
     * Lazily created.
     */public x10.
      util.
      Stack<x10.
      lang.
      Runtime.
      FinishState>
      finishStack;
    
    
//#line 71
public Activity(final x10.core.fun.VoidFun_0_0 body,
                                final x10.
                                  lang.
                                  Runtime.
                                  FinishState finishState,
                                final boolean safe) {
        super();
        
//#line 60
this.clockPhases = null;
        
//#line 66
this.finishStack = null;
        
//#line 117
this.tag = null;
        
//#line 72
this.finishState = finishState;
        
//#line 73
this.safe = safe;
        
//#line 74
finishState.notifyActivityCreation();
        
//#line 75
this.body = body;
    }
    
    
//#line 81
public Activity(final x10.core.fun.VoidFun_0_0 body,
                                final x10.
                                  lang.
                                  Runtime.
                                  FinishState finishState,
                                final x10.core.ValRail<x10.
                                  lang.
                                  Clock> clocks,
                                final x10.core.ValRail<java.lang.Integer> phases) {
        
//#line 82
this(body,
                         finishState,
                         false);
        
//#line 83
this.clockPhases = ((x10.
          lang.
          Runtime.
          ClockPhases)(x10.
          lang.
          Runtime.
          ClockPhases.make(((x10.core.ValRail)(clocks)),
                           ((x10.core.ValRail)(phases)))));
    }
    
    
//#line 89
public Activity(final x10.core.fun.VoidFun_0_0 body,
                                final boolean safe) {
        super();
        
//#line 60
this.clockPhases = null;
        
//#line 66
this.finishStack = null;
        
//#line 117
this.tag = null;
        
//#line 90
this.finishState = null;
        
//#line 91
this.safe = safe;
        
//#line 92
this.body = body;
    }
    
    
//#line 98
public void
                  run(
                  ){
        
//#line 99
try {{
            
//#line 100
body.apply();
        }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
        if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
        final java.lang.Throwable t = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
        {
            
//#line 102
if ((!x10.rtt.Equality.equalsequals(null,finishState))) {
                
//#line 103
finishState.pushException(((java.lang.Throwable)(t)));
            } else {
                
//#line 105
java.lang.System.err.println("Uncaught exception in uncounted activity");
                
//#line 106
t.printStackTrace();
            }
        }
        }
        else {
        throw __$generated_wrappedex$__;
        }
        }catch (final java.lang.Throwable t) {
            
//#line 102
if ((!x10.rtt.Equality.equalsequals(null,finishState))) {
                
//#line 103
finishState.pushException(((java.lang.Throwable)(t)));
            } else {
                
//#line 105
java.lang.System.err.println("Uncaught exception in uncounted activity");
                
//#line 106
t.printStackTrace();
            }
        }
        
//#line 109
if ((!x10.rtt.Equality.equalsequals(null,clockPhases))) {
            
//#line 109
clockPhases.drop();
        }
        
//#line 110
if ((!x10.rtt.Equality.equalsequals(null,finishState))) {
            
//#line 110
finishState.notifyActivityTermination();
        }
        
//#line 111
x10.
          lang.
          Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(body)));
    }
    
    
//#line 117
/**
     * Activity-local storage
     */public java.lang.Object
      tag;
    
    
//#line 119
public void
                   dump(
                   ){
        
    }

}
