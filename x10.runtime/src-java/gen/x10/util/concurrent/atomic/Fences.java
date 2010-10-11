package x10.util.concurrent.atomic;


public class Fences
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Fences> _RTT = new x10.rtt.RuntimeType<Fences>(
/* base class */Fences.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 17
native public static void
                  loadLoadBarrier(
                  );
    
    
//#line 21
native public static void
                  loadStoreBarrier(
                  );
    
    
//#line 25
native public static void
                  storeLoadBarrier(
                  );
    
    
//#line 29
native public static void
                  storeStoreBarrier(
                  );
    
    
//#line 16
public Fences() {
        
//#line 16
super();
    }

}
