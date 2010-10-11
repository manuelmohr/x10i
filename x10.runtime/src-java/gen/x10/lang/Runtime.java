package x10.lang;


final public class Runtime
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Runtime> _RTT = new x10.rtt.RuntimeType<Runtime>(
/* base class */Runtime.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
    
//#line 30
native public static void
                  println(
                  final java.lang.Object o);
    
    
//#line 34
native public static void
                  println(
                  );
    
    
//#line 38
native public static <T> void
                  printf(
                  final x10.rtt.Type T,
                  final java.lang.String fmt,
                  final T t);
    
    
//#line 42
public static long
                  nativeThis(
                  final java.lang.Object x){
        
//#line 43
return 0L;
    }
    
    
//#line 45
public static <T> java.lang.String
                  nativeClosureName(
                  final x10.rtt.Type T,
                  final T cl){
        
//#line 46
return ((java.lang.Object)(((java.lang.Object)(cl)))).toString();
    }
    
    
//#line 52
final public static boolean
      NO_STEALS =
      false;
    
//#line 56
final public static int
      INIT_THREADS =
      1;
    
//#line 60
final public static boolean
      STATIC_THREADS =
      false;
    
    
//#line 67
public static void
                  runAtNative(
                  final int id,
                  final x10.core.fun.VoidFun_0_0 body){
        
//#line 69
body.apply();
    }
    
    
//#line 75
public static void
                  runAtLocal(
                  final int id,
                  final x10.core.fun.VoidFun_0_0 body){
        
//#line 76
body.apply();
    }
    
    
//#line 81
public static <T> T
                  pretendLocal$G(
                  final x10.rtt.Type T,
                  final T x){
        
//#line 82
return new x10.core.fun.Fun_0_1<T, T>() {public final T apply$G(final T __desugarer__var__48__) { {
            
//#line 82
if (!(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__48__)),x10.
                                lang.
                                Runtime.here()))) {
                
//#line 82
throw new java.lang.ClassCastException("T{self.home==here}");
            }
            
//#line 82
return __desugarer__var__48__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return T;if (i ==1) return T;return null;
        }
        }.apply$G(((T)
                    x));
    }
    
    
//#line 87
public static boolean
                  isLocal(
                  final int id){
        
//#line 88
return ((int) id) ==
        ((int) x10.
                 lang.
                 Runtime.here().
                 id);
    }
    
    
//#line 93
public static void
                  event_probe(
                  ){
        
    }
    
    
//#line 98
public static long
                  getAsyncsSent(
                  ){
        
//#line 99
return ((long)(((int)(0))));
    }
    
    
//#line 101
public static void
                   setAsyncsSent(
                   final long v){
        
    }
    
    
//#line 104
public static long
                   getAsyncsReceived(
                   ){
        
//#line 105
return ((long)(((int)(0))));
    }
    
    
//#line 107
public static void
                   setAsyncsReceived(
                   final long v){
        
    }
    
    
//#line 110
public static long
                   getSerializedBytes(
                   ){
        
//#line 111
return ((long)(((int)(0))));
    }
    
    
//#line 113
public static void
                   setSerializedBytes(
                   final long v){
        
    }
    
    
//#line 116
public static long
                   getDeserializedBytes(
                   ){
        
//#line 117
return ((long)(((int)(0))));
    }
    
    
//#line 119
public static void
                   setDeserializedBytes(
                   final long v){
        
    }
    
    
//#line 122
public static void
                   deallocObject(
                   final java.lang.Object o){
        
    }
    
    
//#line 125
public static <T> void
                   dealloc(
                   final x10.rtt.Type T,
                   final x10.core.fun.Fun_0_0<T> o){
        
    }
    
    
//#line 128
public static void
                   dealloc(
                   final x10.core.fun.VoidFun_0_0 o){
        
    }
    
    
//#line 131
public static void
                   registerHandlers(
                   ){
        
    }
    
    
//#line 135
final public static class Deque
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<Deque> _RTT = new x10.rtt.RuntimeType<Deque>(
    /* base class */Deque.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 137
final public x10.
          runtime.
          impl.
          java.
          Deque
          __NATIVE_FIELD__;
        
        
//#line 137
private Deque(final x10.
                                     runtime.
                                     impl.
                                     java.
                                     Deque id0) {
            
//#line 137
super();
            
//#line 137
this.__NATIVE_FIELD__ = id0;
        }
        
        
//#line 138
public Deque() {
            
//#line 137
this(new x10.
                                runtime.
                                impl.
                                java.
                                Deque());
        }
        
        
//#line 140
public int
                       size(
                       ){
            
//#line 137
return this.
                                  __NATIVE_FIELD__.size();
        }
        
        
//#line 142
public java.lang.Object
                       poll(
                       ){
            
//#line 137
return this.
                                  __NATIVE_FIELD__.poll();
        }
        
        
//#line 144
public void
                       push(
                       final java.lang.Object t){
            
//#line 137
this.
                           __NATIVE_FIELD__.push(((java.lang.Object)(t)));
        }
        
        
//#line 146
public java.lang.Object
                       steal(
                       ){
            
//#line 137
return this.
                                  __NATIVE_FIELD__.steal();
        }
    
    }
    
    
//#line 150
public static class Lock
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<Lock> _RTT = new x10.rtt.RuntimeType<Lock>(
    /* base class */Lock.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 152
final public java.
          util.
          concurrent.
          locks.
          ReentrantLock
          __NATIVE_FIELD__;
        
        
//#line 152
private Lock(final java.
                                    util.
                                    concurrent.
                                    locks.
                                    ReentrantLock id0) {
            
//#line 152
super();
            
//#line 152
this.__NATIVE_FIELD__ = id0;
        }
        
        
//#line 153
public Lock() {
            
//#line 152
this(new java.
                                util.
                                concurrent.
                                locks.
                                ReentrantLock());
        }
        
        
//#line 155
public void
                       lock(
                       ){
            
//#line 152
this.
                           __NATIVE_FIELD__.lock();
        }
        
        
//#line 157
public boolean
                       tryLock(
                       ){
            
//#line 152
return this.
                                  __NATIVE_FIELD__.tryLock();
        }
        
        
//#line 159
public void
                       unlock(
                       ){
            
//#line 152
this.
                           __NATIVE_FIELD__.unlock();
        }
        
        
//#line 161
public int
                       getHoldCount(
                       ){
            
//#line 152
return this.
                                  __NATIVE_FIELD__.getHoldCount();
        }
    
    }
    
    
//#line 165
public static class Monitor
                 extends x10.
                   lang.
                   Runtime.
                   Lock
                 {public static final x10.rtt.RuntimeType<Monitor> _RTT = new x10.rtt.RuntimeType<Monitor>(
    /* base class */Monitor.class
    , /* parents */ new x10.rtt.Type[] {x10.lang.Runtime.Lock._RTT}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 169
/**
         * Parked threads
         */final public x10.
          util.
          Stack<x10.
          lang.
          Runtime.
          Thread>
          threads;
        
        
//#line 177
public void
                       await(
                       ){
            
//#line 178
x10.
              lang.
              Runtime.increaseParallelism();
            
//#line 179
final x10.
              lang.
              Runtime.
              Thread thread =
              ((x10.
              lang.
              Runtime.
              Thread)(x10.
              lang.
              Runtime.
              Thread.currentThread()));
            
//#line 180
threads.push(((x10.
                                        lang.
                                        Runtime.
                                        Thread)(thread)));
            
//#line 181
while (threads.contains(((x10.
                                                   lang.
                                                   Runtime.
                                                   Thread)(thread)))) {
                
//#line 182
this.unlock();
                
//#line 183
x10.
                  lang.
                  Runtime.park();
                
//#line 184
this.lock();
            }
        }
        
        
//#line 194
public void
                       release(
                       ){
            
//#line 195
final int size =
              threads.size();
            
//#line 196
if (((((int)(size))) > (((int)(0))))) {
                
//#line 197
x10.
                  lang.
                  Runtime.decreaseParallelism((int)(size));
                
//#line 198
for (
//#line 198
int i =
                                    0;
                                  ((((int)(i))) < (((int)(size))));
                                  
//#line 198
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 198
x10.
                      lang.
                      Runtime.unpark(((x10.
                                       lang.
                                       Runtime.
                                       Thread)(threads.pop$G())));
                }
            }
            
//#line 200
this.unlock();
        }
        
        
//#line 165
public Monitor() {
            
//#line 165
super();
            
//#line 169
this.threads = ((x10.
              util.
              Stack)(new x10.
              util.
              Stack<x10.
              lang.
              Runtime.
              Thread>(x10.lang.Runtime.Thread._RTT)));
        }
    
    }
    
    
//#line 205
public static class Latch
                 extends x10.
                   lang.
                   Runtime.
                   Monitor
                   implements x10.core.fun.Fun_0_0<java.lang.Boolean>
                 {public static final x10.rtt.RuntimeType<Latch> _RTT = new x10.rtt.RuntimeType<Latch>(
    /* base class */Latch.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_0._RTT, x10.rtt.Types.BOOLEAN), x10.lang.Runtime.Monitor._RTT}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public ()=> U.apply(): U
    public java.lang.Boolean
      apply$G(){return apply();}
    
        
//#line 206
public boolean
          state;
        
        
//#line 208
public void
                       release(
                       ){
            
//#line 209
this.lock();
            
//#line 210
this.state = true;
            
//#line 211
super.release();
        }
        
        
//#line 214
public void
                       await(
                       ){
            
//#line 216
if ((!(((boolean)(state))))) {
                
//#line 217
this.lock();
                
//#line 218
while ((!(((boolean)(state)))))
                    
//#line 218
super.await();
                
//#line 219
this.unlock();
            }
        }
        
        
//#line 223
public boolean
                       apply(
                       ){
            
//#line 223
return state;
        }
        
        
//#line 205
public Latch() {
            
//#line 205
super();
            
//#line 206
this.state = false;
        }
        
        final public void
          x10$lang$Runtime$Latch$release$S(
          ){
            super.release();
        }
        
        final public void
          x10$lang$Runtime$Latch$await$S(
          ){
            super.await();
        }
    
    }
    
    
//#line 227
public static class Semaphore
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<Semaphore> _RTT = new x10.rtt.RuntimeType<Semaphore>(
    /* base class */Semaphore.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 228
final public x10.
          lang.
          Runtime.
          Lock
          lock;
        
//#line 230
final public x10.
          util.
          Stack<x10.
          lang.
          Runtime.
          Thread>
          threads;
        
//#line 232
public int
          permits;
        
        
//#line 234
public Semaphore(final int n) {
            super();
            
//#line 228
this.lock = ((x10.
              lang.
              Runtime.
              Lock)(new x10.
              lang.
              Runtime.
              Lock()));
            
//#line 230
this.threads = ((x10.
              util.
              Stack)(new x10.
              util.
              Stack<x10.
              lang.
              Runtime.
              Thread>(x10.lang.Runtime.Thread._RTT)));
            
//#line 232
this.permits = 0;
            
//#line 235
this.permits = n;
        }
        
        
//#line 238
private static int
                       min(
                       final int i,
                       final int j){
            
//#line 238
return ((((int)(i))) < (((int)(j))))
              ? i
              : j;
        }
        
        public static int
          min$P(
          final int i,
          final int j){
            return Semaphore.min((int)(i),
                                 (int)(j));
        }
        
        
//#line 240
public void
                       release(
                       final int n){
            
//#line 241
lock.lock();
            
//#line 242
x10.
              lang.
              Runtime.
              Semaphore.__$closure$apply$__2014(((x10.
                                                  lang.
                                                  Runtime.
                                                  Semaphore)(this)),
                                                (int)(n));
            
//#line 243
final int m =
              x10.
              lang.
              Runtime.
              Semaphore.min((int)(permits),
                            (int)(x10.
                              lang.
                              Runtime.
                              Semaphore.min((int)(n),
                                            (int)(threads.size()))));
            
//#line 244
for (
//#line 244
int i =
                                0;
                              ((((int)(i))) < (((int)(m))));
                              
//#line 244
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 245
threads.pop$G().unpark();
            }
            
//#line 247
lock.unlock();
        }
        
        
//#line 250
public void
                       release(
                       ){
            
//#line 251
this.release((int)(1));
        }
        
        
//#line 254
public void
                       reduce(
                       final int n){
            
//#line 255
lock.lock();
            
//#line 256
x10.
              lang.
              Runtime.
              Semaphore.__$closure$apply$__2015(((x10.
                                                  lang.
                                                  Runtime.
                                                  Semaphore)(this)),
                                                (int)(n));
            
//#line 257
lock.unlock();
        }
        
        
//#line 260
public void
                       acquire(
                       ){
            
//#line 261
lock.lock();
            
//#line 262
final x10.
              lang.
              Runtime.
              Thread thread =
              ((x10.
              lang.
              Runtime.
              Thread)(x10.
              lang.
              Runtime.
              Thread.currentThread()));
            
//#line 263
while (((((int)(permits))) <= (((int)(0))))) {
                
//#line 264
threads.push(((x10.
                                            lang.
                                            Runtime.
                                            Thread)(thread)));
                
//#line 265
while (threads.contains(((x10.
                                                       lang.
                                                       Runtime.
                                                       Thread)(thread)))) {
                    
//#line 266
lock.unlock();
                    
//#line 267
x10.
                      lang.
                      Runtime.
                      Thread.park();
                    
//#line 268
lock.lock();
                }
            }
            
//#line 271
x10.
              lang.
              Runtime.
              Semaphore.__$closure$apply$__2016(((x10.
                                                  lang.
                                                  Runtime.
                                                  Semaphore)(this)),
                                                (int)(1));
            
//#line 272
lock.unlock();
        }
        
        
//#line 275
public int
                       available(
                       ){
            
//#line 275
return permits;
        }
        
        final private static int
          __$closure$apply$__2014(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            
//#line 242
return x.permits = ((((int)(x.
                                                       permits))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2014$P(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            return Semaphore.__$closure$apply$__2014(((x10.
                                                       lang.
                                                       Runtime.
                                                       Semaphore)(x)),
                                                     (int)(y));
        }
        
        final private static int
          __$closure$apply$__2015(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            
//#line 256
return x.permits = ((((int)(x.
                                                       permits))) - (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2015$P(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            return Semaphore.__$closure$apply$__2015(((x10.
                                                       lang.
                                                       Runtime.
                                                       Semaphore)(x)),
                                                     (int)(y));
        }
        
        final private static int
          __$closure$apply$__2016(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            
//#line 271
return x.permits = ((((int)(x.
                                                       permits))) - (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2016$P(
          final x10.
            lang.
            Runtime.
            Semaphore x,
          final int y){
            return Semaphore.__$closure$apply$__2016(((x10.
                                                       lang.
                                                       Runtime.
                                                       Semaphore)(x)),
                                                     (int)(y));
        }
    
    }
    
    
//#line 279
public static class ClockPhases
                 extends x10.
                   util.
                   HashMap<x10.
                   lang.
                   Clock, java.lang.Integer>
                 {public static final x10.rtt.RuntimeType<ClockPhases> _RTT = new x10.rtt.RuntimeType<ClockPhases>(
    /* base class */ClockPhases.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.util.HashMap._RTT, x10.lang.Clock._RTT, x10.rtt.Types.INT)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method public safe x10.util.HashMap.getOrElse(k:K,orelse:V): V
    public int
      getOrElse(x10.
      lang.
      Clock a1,
    int a2){return super.getOrElse$G( a1,
    (java.lang.Integer) a2);}
    
        
        
//#line 280
public static x10.
                       lang.
                       Runtime.
                       ClockPhases
                       make(
                       final x10.core.ValRail<x10.
                         lang.
                         Clock> clocks,
                       final x10.core.ValRail<java.lang.Integer> phases){
            
//#line 281
final x10.
              lang.
              Runtime.
              ClockPhases clockPhases =
              ((x10.
              lang.
              Runtime.
              ClockPhases)(new x10.
              lang.
              Runtime.
              ClockPhases()));
            {
                
//#line 282
final x10.
                  lang.
                  Clock[] clocks$value2041 =
                  ((x10.
                  lang.
                  Clock[])clocks.value);
                
//#line 282
final int[] phases$value2042 =
                  ((int[])phases.value);
                
//#line 282
for (
//#line 282
int i =
                                    0;
                                  ((((int)(i))) < (((int)(clocks.
                                                            length))));
                                  
//#line 282
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 282
clockPhases.put(((x10.
                                                   lang.
                                                   Clock)(((x10.
                                                   lang.
                                                   Clock)clocks$value2041[i]))),
                                                 (java.lang.Integer)(((int)phases$value2042[i])));
                }
            }
            
//#line 283
return clockPhases;
        }
        
        
//#line 286
public x10.core.ValRail<java.lang.Integer>
                       register(
                       final x10.core.ValRail<x10.
                         lang.
                         Clock> clocks){
            
//#line 287
return (new java.lang.Object() {final x10.core.ValRail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = (((x10.
                                                                                                                                                                                                                        lang.
                                                                                                                                                                                                                        Clock)((x10.
                                                                                                                                                                                                                        lang.
                                                                                                                                                                                                                        Clock[])clocks.value)[i])).register();}return new x10.core.ValRail<java.lang.Integer>(x10.rtt.Types.INT, clocks.
                                                                                                                                                                                                                                                                                                                                   length, array);}}.apply(clocks.
                                                                                                                                                                                                                                                                                                                                                             length));
        }
        
        
//#line 290
public void
                       next(
                       ){
            
//#line 291
for (
//#line 291
final x10.core.Iterator<x10.
                                lang.
                                Clock> clock1797 =
                                (this.keySet()).iterator();
                              clock1797.hasNext();
                              ) {
                
//#line 291
final x10.
                  lang.
                  Clock clock =
                  clock1797.next$G();
                
//#line 291
clock.resumeUnsafe();
            }
            
//#line 292
for (
//#line 292
final x10.core.Iterator<x10.
                                lang.
                                Clock> clock1798 =
                                (this.keySet()).iterator();
                              clock1798.hasNext();
                              ) {
                
//#line 292
final x10.
                  lang.
                  Clock clock =
                  clock1798.next$G();
                
//#line 292
clock.nextUnsafe();
            }
        }
        
        
//#line 295
public void
                       drop(
                       ){
            
//#line 296
for (
//#line 296
final x10.core.Iterator<x10.
                                lang.
                                Clock> clock1799 =
                                (this.keySet()).iterator();
                              clock1799.hasNext();
                              ) {
                
//#line 296
final x10.
                  lang.
                  Clock clock =
                  clock1799.next$G();
                
//#line 296
clock.dropInternal();
            }
            
//#line 297
this.clear();
        }
        
        
//#line 279
public ClockPhases() {
            
//#line 279
super(x10.lang.Clock._RTT,
                               x10.rtt.Types.INT);
        }
    
    }
    
    
//#line 305
public static interface Mortal
                 {public static final x10.rtt.RuntimeType<Mortal> _RTT = new x10.rtt.RuntimeType<Mortal>(
    /* base class */Mortal.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    
    }
    
    
//#line 308
public static interface FinishState
                 {public static final x10.rtt.RuntimeType<FinishState> _RTT = new x10.rtt.RuntimeType<FinishState>(
    /* base class */FinishState.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    
        
        
//#line 313
void
                       notifySubActivitySpawn(
                       final x10.
                         lang.
                         Place place);
        
        
//#line 318
void
                       notifyActivityCreation(
                       );
        
        
//#line 324
void
                       notifyActivityTermination(
                       );
        
        
//#line 329
void
                       pushException(
                       final java.lang.Throwable t);
        
        
//#line 334
void
                       waitForFinish(
                       final boolean safe);
    
    }
    
    
//#line 339
public static class FinishStates
                 extends x10.core.Ref
                   implements x10.core.fun.Fun_0_1<x10.
                                lang.
                                Runtime.
                                RootFinish,x10.
                                lang.
                                Runtime.
                                RemoteFinish>
                 {public static final x10.rtt.RuntimeType<FinishStates> _RTT = new x10.rtt.RuntimeType<FinishStates>(
    /* base class */FinishStates.class
    , /* parents */ new x10.rtt.Type[] {new x10.rtt.ParameterizedType(x10.core.fun.Fun_0_1._RTT, x10.lang.Runtime.RootFinish._RTT, x10.lang.Runtime.RemoteFinish._RTT), x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    // bridge for method abstract public (a1:Z1)=> U.apply(a1:Z1): U
    public x10.
      lang.
      Runtime.
      RemoteFinish
      apply$G(x10.
      lang.
      Runtime.
      RootFinish a1){return apply( a1);}
    
        
//#line 341
final public x10.
          util.
          HashMap<x10.
          lang.
          Runtime.
          RootFinish, x10.
          lang.
          Runtime.
          RemoteFinish>
          map;
        
//#line 342
final public x10.
          lang.
          Runtime.
          Lock
          lock;
        
        
//#line 344
public x10.
                       lang.
                       Runtime.
                       RemoteFinish
                       apply(
                       final x10.
                         lang.
                         Runtime.
                         RootFinish rootFinish){
            
//#line 345
lock.lock();
            
//#line 346
final x10.
              lang.
              Runtime.
              RemoteFinish finishState =
              ((x10.
              lang.
              Runtime.
              RemoteFinish)(map.getOrElse$G(((x10.
                                              lang.
                                              Runtime.
                                              RootFinish)(rootFinish)),
                                            ((x10.
                                              lang.
                                              Runtime.
                                              RemoteFinish)(null)))));
            
//#line 347
if ((!x10.rtt.Equality.equalsequals(null,finishState))) {
                
//#line 348
lock.unlock();
                
//#line 349
return finishState;
            }
            
//#line 352
final x10.
              lang.
              Runtime.
              RemoteFinish remoteFinish =
              ((x10.
              lang.
              Runtime.
              RemoteFinish)(rootFinish.makeRemote()));
            
//#line 353
map.put(((x10.
                                   lang.
                                   Runtime.
                                   RootFinish)(rootFinish)),
                                 ((x10.
                                   lang.
                                   Runtime.
                                   RemoteFinish)(remoteFinish)));
            
//#line 354
lock.unlock();
            
//#line 355
return remoteFinish;
        }
        
        
//#line 357
public void
                       remove(
                       final x10.
                         lang.
                         Runtime.
                         RootFinish rootFinish){
            
//#line 358
lock.lock();
            
//#line 359
map.remove(((x10.
                                      lang.
                                      Runtime.
                                      RootFinish)(rootFinish)));
            
//#line 360
lock.unlock();
        }
        
        
//#line 339
public FinishStates() {
            
//#line 339
super();
            
//#line 341
this.map = ((x10.
              util.
              HashMap)(new x10.
              util.
              HashMap<x10.
              lang.
              Runtime.
              RootFinish, x10.
              lang.
              Runtime.
              RemoteFinish>(x10.lang.Runtime.RootFinish._RTT,
                            x10.lang.Runtime.RemoteFinish._RTT)));
            
//#line 342
this.lock = ((x10.
              lang.
              Runtime.
              Lock)(new x10.
              lang.
              Runtime.
              Lock()));
        }
    
    }
    
    
//#line 365
public static class StatefulReducer<T>
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<StatefulReducer> _RTT = new x10.rtt.RuntimeType<StatefulReducer>(
    /* base class */StatefulReducer.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
    
        private final x10.rtt.Type T;
        
        
//#line 366
final public x10.
          lang.
          Reducible<T>
          reducer;
        
//#line 367
public T
          result;
        
//#line 368
final public int
          MAX =
          1000;
        
//#line 369
public x10.core.Rail<T>
          resultRail;
        
//#line 370
public x10.core.Rail<java.lang.Boolean>
          workerFlag;
        
        
//#line 371
public StatefulReducer(final x10.rtt.Type T,
                                            final x10.
                                              lang.
                                              Reducible<T> r) {
                                                                       super();
                                                                   this.T = T;
                                                                    {
                                                                       
//#line 369
this.resultRail = null;
                                                                       
//#line 370
this.workerFlag = (new java.lang.Object() {final x10.core.Rail<java.lang.Boolean> apply(int length) {boolean[] array = new boolean[length];for (int id$36$ = 0; id$36$ < length; id$36$++) {final int id$36 = id$36$;array[id$36] = false;}return new x10.core.Rail<java.lang.Boolean>(x10.rtt.Types.BOOLEAN, MAX, array);}}.apply(MAX));
                                                                       
//#line 372
this.reducer = r;
                                                                       
//#line 373
this.result = ((T)(reducer.zero$G()));
                                                                       
//#line 374
this.resultRail = x10.core.RailFactory.<T>makeVarRail(T, ((int)(MAX)), new x10.core.fun.Fun_0_1<java.lang.Integer, T>() {public final T apply$G(final java.lang.Integer id$37) { return apply$G((int)id$37);}
                                                                       public final T apply$G(final int id$37) { {
                                                                           
//#line 374
return x10.
                                                                                                 lang.
                                                                                                 Runtime.
                                                                                                 StatefulReducer.this.
                                                                                                 result;
                                                                       }}
                                                                       public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.rtt.Types.INT;if (i ==1) return T;return null;
                                                                       }
                                                                       });
                                                                   }}
        
        
//#line 376
public void
                       accept(
                       final T t){
            
//#line 377
this.result = ((T)(reducer.apply$G(((T)(result)),
                                                            ((T)(t)))));
        }
        
        
//#line 379
public void
                       accept(
                       final T t,
                       final int id){
            
//#line 380
if (((((((int)(id))) >= (((int)(0)))))) &&
                             ((((((int)(id))) < (((int)(MAX))))))) {
                
//#line 381
(this.
                                resultRail).set$G(reducer.apply$G(((T)((this.
                                                                          resultRail).apply$G(((int)(id))))),
                                                                  ((T)(t))), ((int)(id)));
                
//#line 382
((boolean[])this.
                                           workerFlag.value)[id] = true;
            }
        }
        
        
//#line 385
public void
                       placeMerge(
                       ){
            
//#line 386
for (
//#line 386
int i =
                                0;
                              ((((int)(i))) < (((int)(MAX))));
                              
//#line 386
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 387
if (((boolean[])this.
                                               workerFlag.value)[i]) {
                    
//#line 388
this.result = ((T)(reducer.apply$G(((T)(result)),
                                                                    ((T)((resultRail).apply$G(((int)(i))))))));
                    
//#line 389
(resultRail).set$G(reducer.zero$G(), ((int)(i)));
                }
            }
        }
        
        
//#line 394
public T
                       result$G(
                       ){
            
//#line 394
return result;
        }
        
        
//#line 395
public void
                       reset(
                       ){
            
//#line 396
this.result = ((T)(reducer.zero$G()));
        }
    
    }
    
    
//#line 400
public static class RootCollectingFinish<T>
                 extends x10.
                   lang.
                   Runtime.
                   RootFinish
                 {public static final x10.rtt.RuntimeType<RootCollectingFinish> _RTT = new x10.rtt.RuntimeType<RootCollectingFinish>(
    /* base class */RootCollectingFinish.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.lang.Runtime.RootFinish._RTT}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
    
        private final x10.rtt.Type T;
        
        
//#line 401
final public x10.
          lang.
          Runtime.
          StatefulReducer<T>
          sr;
        
//#line 402
final public x10.
          lang.
          Reducible<T>
          reducer;
        
        
//#line 403
public RootCollectingFinish(final x10.rtt.Type T,
                                                 final x10.
                                                   lang.
                                                   Reducible<T> r) {
                                                                            
//#line 404
super();
                                                                        this.T = T;
                                                                         {
                                                                            
//#line 405
this.reducer = r;
                                                                            
//#line 406
this.sr = ((x10.
                                                                              lang.
                                                                              Runtime.
                                                                              StatefulReducer)(new x10.
                                                                              lang.
                                                                              Runtime.
                                                                              StatefulReducer<T>(T,
                                                                                                 r)));
                                                                        }}
        
        
//#line 408
public void
                       accept(
                       final T t){
            
//#line 409
this.lock();
            
//#line 410
sr.accept(((T)(t)));
            
//#line 411
this.unlock();
        }
        
        
//#line 413
public void
                       accept(
                       final T t,
                       final int id){
            
//#line 414
sr.accept(((T)(t)),
                                   (int)(id));
        }
        
        
//#line 416
public void
                       notify(
                       final x10.core.ValRail<java.lang.Integer> rail,
                       final T v){
            
//#line 417
boolean b =
              true;
            
//#line 418
this.lock();
            {
                
//#line 419
final int[] rail$value2043 =
                  ((int[])rail.value);
                
//#line 419
final int[] x10$lang$Runtime$RootCollectingFinish$this$counts$value2044 =
                  ((int[])counts.value);
                
//#line 419
final boolean[] x10$lang$Runtime$RootCollectingFinish$this$seen$value2045 =
                  ((boolean[])seen.value);
                
//#line 419
for (
//#line 419
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 419
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 420
x10$lang$Runtime$RootCollectingFinish$this$counts$value2044[i]+=((int)rail$value2043[i]);
                    
//#line 421
x10$lang$Runtime$RootCollectingFinish$this$seen$value2045[i]|=((int) ((int)x10$lang$Runtime$RootCollectingFinish$this$counts$value2044[i])) !=
                    ((int) 0);
                    
//#line 422
if (((int) ((int)x10$lang$Runtime$RootCollectingFinish$this$counts$value2044[i])) !=
                                     ((int) 0)) {
                        
//#line 422
b = false;
                    }
                }
            }
            
//#line 424
sr.accept(((T)(v)));
            
//#line 425
if (b) {
                
//#line 425
this.release();
            }
            
//#line 426
this.unlock();
        }
        
        
//#line 428
public void
                       notify2(
                       final x10.core.ValRail<x10.
                         util.
                         Pair<java.lang.Integer, java.lang.Integer>> rail,
                       final T v){
            
//#line 429
this.lock();
            {
                
//#line 430
final x10.
                  util.
                  Pair[] rail$value2046 =
                  ((x10.
                  util.
                  Pair[])rail.value);
                
//#line 430
final int[] x10$lang$Runtime$RootCollectingFinish$this$counts$value2047 =
                  ((int[])counts.value);
                
//#line 430
final boolean[] x10$lang$Runtime$RootCollectingFinish$this$seen$value2048 =
                  ((boolean[])seen.value);
                
//#line 430
for (
//#line 430
int i =
                                    0;
                                  ((((int)(i))) < (((int)(rail.
                                                            length))));
                                  
//#line 430
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 431
x10$lang$Runtime$RootCollectingFinish$this$counts$value2047[((x10.
                                                                                               util.
                                                                                               Pair<java.lang.Integer, java.lang.Integer>)rail$value2046[i]).
                                                                                               first]+=((x10.
                                                                                                         util.
                                                                                                         Pair<java.lang.Integer, java.lang.Integer>)rail$value2046[i]).
                                                                                                         second;
                    
//#line 432
x10$lang$Runtime$RootCollectingFinish$this$seen$value2048[((x10.
                                                                                             util.
                                                                                             Pair<java.lang.Integer, java.lang.Integer>)rail$value2046[i]).
                                                                                             first]=true;
                }
            }
            {
                
//#line 434
final int[] x10$lang$Runtime$RootCollectingFinish$this$counts$value2049 =
                  ((int[])counts.value);
                
//#line 434
for (
//#line 434
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 434
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 435
if (((int) ((int)x10$lang$Runtime$RootCollectingFinish$this$counts$value2049[i])) !=
                                     ((int) 0)) {
                        
//#line 436
sr.accept(((T)(v)));
                        
//#line 437
this.unlock();
                        
//#line 438
return;
                    }
                }
            }
            
//#line 441
sr.accept(((T)(v)));
            
//#line 442
this.release();
            
//#line 443
this.unlock();
        }
        
        
//#line 446
public x10.
                       lang.
                       Runtime.
                       RemoteCollectingFinish<T>
                       makeRemote(
                       ){
            
//#line 446
return new x10.
              lang.
              Runtime.
              RemoteCollectingFinish<T>(T,
                                        reducer);
        }
        
        
//#line 449
final public T
                       waitForFinishExpr$G(
                       final boolean safe){
            
//#line 450
this.waitForFinish((boolean)(safe));
            
//#line 451
sr.placeMerge();
            
//#line 452
final T result =
              ((T)(sr.result$G()));
            
//#line 453
sr.reset();
            
//#line 454
return result;
        }
    
    }
    
    
//#line 461
public static class RootFinish
                 extends x10.
                   lang.
                   Runtime.
                   Latch
                   implements x10.
                                lang.
                                Runtime.
                                FinishState,
                              x10.
                                lang.
                                Runtime.
                                Mortal
                 {public static final x10.rtt.RuntimeType<RootFinish> _RTT = new x10.rtt.RuntimeType<RootFinish>(
    /* base class */RootFinish.class
    , /* parents */ new x10.rtt.Type[] {x10.lang.Runtime.FinishState._RTT, x10.lang.Runtime.Mortal._RTT, x10.lang.Runtime.Latch._RTT}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 462
final public x10.core.Rail<java.lang.Integer>
          counts;
        
//#line 463
final public x10.core.Rail<java.lang.Boolean>
          seen;
        
//#line 464
public x10.
          util.
          Stack<java.lang.Throwable>
          exceptions;
        
        
//#line 465
public RootFinish() {
            super();
            
//#line 464
this.exceptions = null;
            
//#line 466
final x10.core.Rail<java.lang.Integer> c =
              ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$38$ = 0; id$38$ < length; id$38$++) {final int id$38 = id$38$;array[id$38] = 0;}return new x10.core.Rail<java.lang.Integer>(x10.rtt.Types.INT, x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
            
//#line 467
this.seen = ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<java.lang.Boolean> apply(int length) {boolean[] array = new boolean[length];for (int id$39$ = 0; id$39$ < length; id$39$++) {final int id$39 = id$39$;array[id$39] = false;}return new x10.core.Rail<java.lang.Boolean>(x10.rtt.Types.BOOLEAN, x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
            
//#line 468
((int[])c.value)[x10.
                                            lang.
                                            Runtime.here().
                                            id] = 1;
            
//#line 469
this.counts = ((x10.core.Rail)(c));
        }
        
        
//#line 471
public x10.
                       lang.
                       Runtime.
                       RemoteFinish
                       makeRemote(
                       ){
            
//#line 471
return new x10.
              lang.
              Runtime.
              RemoteFinish();
        }
        
        
//#line 473
private void
                       notifySubActivitySpawnLocal(
                       final x10.
                         lang.
                         Place place){
            
//#line 474
this.lock();
            
//#line 475
((int[])counts.value)[place.parent().
                                                 id] += 1;
            
//#line 476
this.unlock();
        }
        
        public static void
          notifySubActivitySpawnLocal$P(
          final x10.
            lang.
            Place place,
          final x10.
            lang.
            Runtime.
            RootFinish RootFinish){
            RootFinish.notifySubActivitySpawnLocal(((x10.
                                                     lang.
                                                     Place)(place)));
        }
        
        
//#line 479
private void
                       notifyActivityTerminationLocal(
                       ){
            
//#line 480
this.lock();
            
//#line 481
((int[])counts.value)[x10.
                                                 lang.
                                                 Runtime.here().
                                                 id] -= 1;
            {
                
//#line 482
final int[] x10$lang$Runtime$RootFinish$this$counts$value2050 =
                  ((int[])counts.value);
                
//#line 482
for (
//#line 482
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 482
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 483
if (((int) ((int)x10$lang$Runtime$RootFinish$this$counts$value2050[i])) !=
                                     ((int) 0)) {
                        
//#line 484
this.unlock();
                        
//#line 485
return;
                    }
                }
            }
            
//#line 488
this.release();
            
//#line 489
this.unlock();
        }
        
        public static void
          notifyActivityTerminationLocal$P(
          final x10.
            lang.
            Runtime.
            RootFinish RootFinish){
            RootFinish.notifyActivityTerminationLocal();
        }
        
        
//#line 492
private void
                       pushExceptionLocal(
                       final java.lang.Throwable t){
            
//#line 493
this.lock();
            
//#line 494
if (x10.rtt.Equality.equalsequals(null,exceptions)) {
                
//#line 494
this.exceptions = ((x10.
                  util.
                  Stack)(new x10.
                  util.
                  Stack<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class))));
            }
            
//#line 495
exceptions.push(((java.lang.Throwable)(t)));
            
//#line 496
this.unlock();
        }
        
        public static void
          pushExceptionLocal$P(
          final java.lang.Throwable t,
          final x10.
            lang.
            Runtime.
            RootFinish RootFinish){
            RootFinish.pushExceptionLocal(((java.lang.Throwable)(t)));
        }
        
        
//#line 499
public void
                       waitForFinish(
                       final boolean safe){
            
//#line 500
if ((!(((boolean)(x10.runtime.impl.java.Runtime.NO_STEALS)))) &&
                             safe) {
                
//#line 500
x10.
                  lang.
                  Runtime.worker$P().join(((x10.
                                            lang.
                                            Runtime.
                                            Latch)(this)));
            }
            
//#line 501
this.await();
            
//#line 502
final x10.core.fun.VoidFun_0_0 closure =
              ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                {
                    
//#line 502
x10.
                                   lang.
                                   Runtime.runtime.apply$G().
                                   finishStates.remove(((x10.
                                                         lang.
                                                         Runtime.
                                                         RootFinish)(x10.
                                                         lang.
                                                         Runtime.
                                                         RootFinish.this)));
                    
//#line 502
return;
                }
            }}
            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
            }
            }));
            
//#line 503
((boolean[])seen.value)[x10.
              lang.
              Runtime.hereInt()] = false;
            {
                
//#line 504
final boolean[] x10$lang$Runtime$RootFinish$this$seen$value2051 =
                  ((boolean[])seen.value);
                
//#line 504
for (
//#line 504
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 504
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 505
if (((boolean)x10$lang$Runtime$RootFinish$this$seen$value2051[i])) {
                        
//#line 506
x10.runtime.impl.java.Runtime.runAt(((int)(i)), closure);
                    }
                }
            }
            
//#line 509
x10.
              lang.
              Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
            
//#line 510
if ((!x10.rtt.Equality.equalsequals(null,exceptions))) {
                
//#line 511
if (((int) exceptions.size()) ==
                                 ((int) 1)) {
                    
//#line 512
final java.lang.Throwable t =
                      exceptions.peek$G();
                    
//#line 513
if (x10.rtt.Types.runtimeType(java.lang.Error.class).instanceof$(t)) {
                        
//#line 514
throw (new java.lang.Object() {final java.lang.Error cast(final java.lang.Error self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.Error.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.Error) t));
                    }
                    
//#line 516
if (x10.rtt.Types.runtimeType(java.lang.RuntimeException.class).instanceof$(t)) {
                        
//#line 517
throw (new java.lang.Object() {final java.lang.RuntimeException cast(final java.lang.RuntimeException self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.RuntimeException.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.RuntimeException) t));
                    }
                }
                
//#line 520
throw new x10.
                  lang.
                  MultipleExceptions(exceptions);
            }
        }
        
        
//#line 524
public void
                       notify(
                       final x10.core.ValRail<java.lang.Integer> rail){
            
//#line 525
boolean b =
              true;
            
//#line 526
this.lock();
            {
                
//#line 527
final int[] rail$value2052 =
                  ((int[])rail.value);
                
//#line 527
final int[] x10$lang$Runtime$RootFinish$this$counts$value2053 =
                  ((int[])counts.value);
                
//#line 527
final boolean[] x10$lang$Runtime$RootFinish$this$seen$value2054 =
                  ((boolean[])seen.value);
                
//#line 527
for (
//#line 527
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 527
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 528
x10$lang$Runtime$RootFinish$this$counts$value2053[i]+=((int)rail$value2052[i]);
                    
//#line 529
x10$lang$Runtime$RootFinish$this$seen$value2054[i]|=((int) ((int)x10$lang$Runtime$RootFinish$this$counts$value2053[i])) !=
                    ((int) 0);
                    
//#line 530
if (((int) ((int)x10$lang$Runtime$RootFinish$this$counts$value2053[i])) !=
                                     ((int) 0)) {
                        
//#line 530
b = false;
                    }
                }
            }
            
//#line 532
if (b) {
                
//#line 532
this.release();
            }
            
//#line 533
this.unlock();
        }
        
        
//#line 536
public void
                       notify2(
                       final x10.core.ValRail<x10.
                         util.
                         Pair<java.lang.Integer, java.lang.Integer>> rail){
            
//#line 537
this.lock();
            {
                
//#line 538
final x10.
                  util.
                  Pair[] rail$value2055 =
                  ((x10.
                  util.
                  Pair[])rail.value);
                
//#line 538
final int[] x10$lang$Runtime$RootFinish$this$counts$value2056 =
                  ((int[])counts.value);
                
//#line 538
final boolean[] x10$lang$Runtime$RootFinish$this$seen$value2057 =
                  ((boolean[])seen.value);
                
//#line 538
for (
//#line 538
int i =
                                    0;
                                  ((((int)(i))) < (((int)(rail.
                                                            length))));
                                  
//#line 538
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 539
x10$lang$Runtime$RootFinish$this$counts$value2056[((x10.
                                                                                     util.
                                                                                     Pair<java.lang.Integer, java.lang.Integer>)rail$value2055[i]).
                                                                                     first]+=((x10.
                                                                                               util.
                                                                                               Pair<java.lang.Integer, java.lang.Integer>)rail$value2055[i]).
                                                                                               second;
                    
//#line 540
x10$lang$Runtime$RootFinish$this$seen$value2057[((x10.
                                                                                   util.
                                                                                   Pair<java.lang.Integer, java.lang.Integer>)rail$value2055[i]).
                                                                                   first]=true;
                }
            }
            {
                
//#line 542
final int[] x10$lang$Runtime$RootFinish$this$counts$value2058 =
                  ((int[])counts.value);
                
//#line 542
for (
//#line 542
int i =
                                    0;
                                  ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                  
//#line 542
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 543
if (((int) ((int)x10$lang$Runtime$RootFinish$this$counts$value2058[i])) !=
                                     ((int) 0)) {
                        
//#line 544
this.unlock();
                        
//#line 545
return;
                    }
                }
            }
            
//#line 548
this.release();
            
//#line 549
this.unlock();
        }
        
        
//#line 552
public void
                       notify(
                       final x10.core.ValRail<java.lang.Integer> rail,
                       final java.lang.Throwable t){
            
//#line 553
this.pushExceptionLocal(((java.lang.Throwable)(t)));
            
//#line 554
this.notify(((x10.core.ValRail)(rail)));
        }
        
        
//#line 557
public void
                       notify2(
                       final x10.core.ValRail<x10.
                         util.
                         Pair<java.lang.Integer, java.lang.Integer>> rail,
                       final java.lang.Throwable t){
            
//#line 558
this.pushExceptionLocal(((java.lang.Throwable)(t)));
            
//#line 559
this.notify2(((x10.core.ValRail)(rail)));
        }
        
        
//#line 562
public void
                       notifySubActivitySpawn(
                       final x10.
                         lang.
                         Place place){
            
//#line 563
if (x10.
                               lang.
                               Runtime.here().equals(((x10.
                                                       lang.
                                                       Place)(x10.lang.Place.place(x10.core.Ref.home(this)))))) {
                
//#line 564
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2017(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RootFinish)(((x10.
                                                                                   lang.
                                                                                   Runtime.
                                                                                   RootFinish)
                                                                                   this))))).notifySubActivitySpawnLocal(((x10.
                                                                                                                           lang.
                                                                                                                           Place)(place)));
            } else {
                
//#line 566
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2018(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RemoteFinish)(((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     RemoteFinish)
                                                                                     x10.
                                                                                     lang.
                                                                                     Runtime.proxy(((x10.
                                                                                                     lang.
                                                                                                     Runtime.
                                                                                                     RootFinish)(this)))))))).notifySubActivitySpawn(((x10.
                                                                                                                                                       lang.
                                                                                                                                                       Place)(place)));
            }
        }
        
        
//#line 570
public void
                       notifyActivityCreation(
                       ){
            
//#line 571
if ((!(((boolean)(x10.
                               lang.
                               Runtime.here().equals(((x10.
                                                       lang.
                                                       Place)(x10.lang.Place.place(x10.core.Ref.home(this)))))))))) {
                
//#line 572
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2019(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RemoteFinish)(((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     RemoteFinish)
                                                                                     x10.
                                                                                     lang.
                                                                                     Runtime.proxy(((x10.
                                                                                                     lang.
                                                                                                     Runtime.
                                                                                                     RootFinish)(this)))))))).notifyActivityCreation();
            }
        }
        
        
//#line 575
public void
                       notifyActivityTermination(
                       ){
            
//#line 576
if (x10.
                               lang.
                               Runtime.here().equals(((x10.
                                                       lang.
                                                       Place)(x10.lang.Place.place(x10.core.Ref.home(this)))))) {
                
//#line 577
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2020(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RootFinish)(((x10.
                                                                                   lang.
                                                                                   Runtime.
                                                                                   RootFinish)
                                                                                   this))))).notifyActivityTerminationLocal();
            } else {
                
//#line 579
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2021(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RemoteFinish)(((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     RemoteFinish)
                                                                                     x10.
                                                                                     lang.
                                                                                     Runtime.proxy(((x10.
                                                                                                     lang.
                                                                                                     Runtime.
                                                                                                     RootFinish)(this)))))))).notifyActivityTermination(((x10.
                                                                                                                                                          lang.
                                                                                                                                                          Runtime.
                                                                                                                                                          RootFinish)(this)));
            }
        }
        
        
//#line 583
public void
                       pushException(
                       final java.lang.Throwable t){
            
//#line 584
if (x10.
                               lang.
                               Runtime.here().equals(((x10.
                                                       lang.
                                                       Place)(x10.lang.Place.place(x10.core.Ref.home(this)))))) {
                
//#line 585
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2022(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RootFinish)(((x10.
                                                                                   lang.
                                                                                   Runtime.
                                                                                   RootFinish)
                                                                                   this))))).pushExceptionLocal(((java.lang.Throwable)(t)));
            } else {
                
//#line 587
(x10.
                                lang.
                                Runtime.
                                RootFinish.__$closure$apply$__2023(((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RemoteFinish)(((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     RemoteFinish)
                                                                                     x10.
                                                                                     lang.
                                                                                     Runtime.proxy(((x10.
                                                                                                     lang.
                                                                                                     Runtime.
                                                                                                     RootFinish)(this)))))))).pushException(((java.lang.Throwable)(t)));
            }
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2017(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__49__){
            
//#line 564
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__49__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__49__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 564
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 564
return __desugarer__var__49__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2017$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__49__){
            return RootFinish.__$closure$apply$__2017(((x10.
                                                        lang.
                                                        Runtime.
                                                        RootFinish)(__desugarer__var__49__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2018(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__50__){
            
//#line 566
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__50__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__50__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 566
throw new java.lang.ClassCastException("x10.lang.Runtime.RemoteFinish{self.home==here}");
            }
            
//#line 566
return __desugarer__var__50__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2018$P(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__50__){
            return RootFinish.__$closure$apply$__2018(((x10.
                                                        lang.
                                                        Runtime.
                                                        RemoteFinish)(__desugarer__var__50__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2019(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__51__){
            
//#line 572
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__51__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__51__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 572
throw new java.lang.ClassCastException("x10.lang.Runtime.RemoteFinish{self.home==here}");
            }
            
//#line 572
return __desugarer__var__51__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2019$P(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__51__){
            return RootFinish.__$closure$apply$__2019(((x10.
                                                        lang.
                                                        Runtime.
                                                        RemoteFinish)(__desugarer__var__51__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2020(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__52__){
            
//#line 577
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__52__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__52__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 577
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 577
return __desugarer__var__52__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2020$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__52__){
            return RootFinish.__$closure$apply$__2020(((x10.
                                                        lang.
                                                        Runtime.
                                                        RootFinish)(__desugarer__var__52__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2021(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__53__){
            
//#line 579
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__53__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__53__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 579
throw new java.lang.ClassCastException("x10.lang.Runtime.RemoteFinish{self.home==here}");
            }
            
//#line 579
return __desugarer__var__53__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2021$P(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__53__){
            return RootFinish.__$closure$apply$__2021(((x10.
                                                        lang.
                                                        Runtime.
                                                        RemoteFinish)(__desugarer__var__53__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2022(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__54__){
            
//#line 585
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__54__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__54__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 585
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 585
return __desugarer__var__54__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2022$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__54__){
            return RootFinish.__$closure$apply$__2022(((x10.
                                                        lang.
                                                        Runtime.
                                                        RootFinish)(__desugarer__var__54__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2023(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__55__){
            
//#line 587
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__55__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__55__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 587
throw new java.lang.ClassCastException("x10.lang.Runtime.RemoteFinish{self.home==here}");
            }
            
//#line 587
return __desugarer__var__55__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RemoteFinish
          __$closure$apply$__2023$P(
          final x10.
            lang.
            Runtime.
            RemoteFinish __desugarer__var__55__){
            return RootFinish.__$closure$apply$__2023(((x10.
                                                        lang.
                                                        Runtime.
                                                        RemoteFinish)(__desugarer__var__55__)));
        }
    
    }
    
    
//#line 593
public static class RemoteCollectingFinish<T>
                 extends x10.
                   lang.
                   Runtime.
                   RemoteFinish
                 {public static final x10.rtt.RuntimeType<RemoteCollectingFinish> _RTT = new x10.rtt.RuntimeType<RemoteCollectingFinish>(
    /* base class */RemoteCollectingFinish.class, 
    /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
    , /* parents */ new x10.rtt.Type[] {x10.lang.Runtime.RemoteFinish._RTT}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
    
        private final x10.rtt.Type T;
        
        
//#line 594
final public x10.
          lang.
          Runtime.
          StatefulReducer<T>
          sr;
        
        
//#line 595
public RemoteCollectingFinish(final x10.rtt.Type T,
                                                   final x10.
                                                     lang.
                                                     Reducible<T> r) {
                                                                              
//#line 596
super();
                                                                          this.T = T;
                                                                           {
                                                                              
//#line 597
this.sr = ((x10.
                                                                                lang.
                                                                                Runtime.
                                                                                StatefulReducer)(new x10.
                                                                                lang.
                                                                                Runtime.
                                                                                StatefulReducer<T>(T,
                                                                                                   r)));
                                                                          }}
        
        
//#line 603
public void
                       notifyActivityTermination(
                       final x10.
                         lang.
                         Runtime.
                         RootFinish r){
            
//#line 604
lock.lock();
            
//#line 605
((int[])counts.value)[x10.
                                                 lang.
                                                 Runtime.here().
                                                 id] -= 1;
            
//#line 606
if (((((int)(count.decrementAndGet()))) > (((int)(0))))) {
                
//#line 607
lock.unlock();
                
//#line 608
return;
            }
            
//#line 610
final x10.
              util.
              Stack<java.lang.Throwable> e =
              ((x10.
              util.
              Stack)(exceptions));
            
//#line 611
this.exceptions = null;
            
//#line 612
if (((((int)(((((int)(2))) * (((int)(length))))))) > (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))))) {
                
//#line 613
final x10.core.ValRail<java.lang.Integer> m =
                  ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, counts)));
                {
                    
//#line 614
final int[] x10$lang$Runtime$RemoteCollectingFinish$this$counts$value2059 =
                      ((int[])counts.value);
                    
//#line 614
for (
//#line 614
int i =
                                        0;
                                      ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                      
//#line 614
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 614
x10$lang$Runtime$RemoteCollectingFinish$this$counts$value2059[i]=0;
                    }
                }
                
//#line 615
this.length = 1;
                
//#line 616
lock.unlock();
                
//#line 617
if ((!x10.rtt.Equality.equalsequals(null,e))) {
                    
//#line 618
final java.lang.Throwable t;
                    
//#line 619
if (((int) e.size()) ==
                                     ((int) 1)) {
                        
//#line 620
t = ((java.lang.Throwable)(e.peek$G()));
                    } else {
                        
//#line 622
t = ((java.lang.Throwable)(new x10.
                          lang.
                          MultipleExceptions(e)));
                    }
                    
//#line 624
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 624
(x10.
                                        lang.
                                        Runtime.
                                        RemoteCollectingFinish.<T>__$closure$apply$__2024(T,
                                                                                          ((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish cast(final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish) r)))))).notify(((x10.core.ValRail)(m)),
                                                                                                                                 ((java.lang.Throwable)(t)));
                        
//#line 624
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 625
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 626
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                } else {
                    
//#line 628
sr.placeMerge();
                    
//#line 629
final T x =
                      ((T)(sr.result$G()));
                    
//#line 630
sr.reset();
                    
//#line 631
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 631
(x10.
                                        lang.
                                        Runtime.
                                        RemoteCollectingFinish.<T>__$closure$apply$__2025(T,
                                                                                          ((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish cast(final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish) r)))))).notify(((x10.core.ValRail)(m)),
                                                                                                                                 ((T)(x)));
                        
//#line 631
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 632
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 633
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                }
                
//#line 635
x10.
                  lang.
                  Runtime.deallocObject(((java.lang.Object)(m)));
            } else {
                
//#line 637
final x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>> m =
                  ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>> apply(int length) {x10.
                  util.
                  Pair[] array = new x10.
                  util.
                  Pair[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = new x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>(x10.rtt.Types.INT,
                                                             x10.rtt.Types.INT,
                                                             ((int[])message.value)[i],
                                                             ((int[])counts.value)[((int[])message.value)[i]]);}return new x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>>(new x10.rtt.ParameterizedType(x10.util.Pair._RTT, x10.rtt.Types.INT, x10.rtt.Types.INT), length, array);}}.apply(length))));
                {
                    
//#line 638
final int[] x10$lang$Runtime$RemoteCollectingFinish$this$counts$value2060 =
                      ((int[])counts.value);
                    
//#line 638
for (
//#line 638
int i =
                                        0;
                                      ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                      
//#line 638
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 638
x10$lang$Runtime$RemoteCollectingFinish$this$counts$value2060[i]=0;
                    }
                }
                
//#line 639
this.length = 1;
                
//#line 640
lock.unlock();
                
//#line 641
if ((!x10.rtt.Equality.equalsequals(null,e))) {
                    
//#line 642
final java.lang.Throwable t;
                    
//#line 643
if (((int) e.size()) ==
                                     ((int) 1)) {
                        
//#line 644
t = ((java.lang.Throwable)(e.peek$G()));
                    } else {
                        
//#line 646
t = ((java.lang.Throwable)(new x10.
                          lang.
                          MultipleExceptions(e)));
                    }
                    
//#line 648
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 648
(x10.
                                        lang.
                                        Runtime.
                                        RemoteCollectingFinish.<T>__$closure$apply$__2026(T,
                                                                                          ((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish cast(final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish) r)))))).notify2(((x10.core.ValRail)(m)),
                                                                                                                                  ((java.lang.Throwable)(t)));
                        
//#line 648
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 649
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 650
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                } else {
                    
//#line 652
sr.placeMerge();
                    
//#line 653
final T x =
                      ((T)(sr.result$G()));
                    
//#line 654
sr.reset();
                    
//#line 655
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 655
(x10.
                                        lang.
                                        Runtime.
                                        RemoteCollectingFinish.<T>__$closure$apply$__2027(T,
                                                                                          ((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish cast(final x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                                            lang.
                                                                                            Runtime.
                                                                                            RootCollectingFinish) r)))))).notify2(((x10.core.ValRail)(m)),
                                                                                                                                  ((T)(x)));
                        
//#line 655
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 656
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 657
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                }
                
//#line 659
x10.
                  lang.
                  Runtime.deallocObject(((java.lang.Object)(m)));
            }
        }
        
        
//#line 662
public void
                       accept(
                       final T t){
            
//#line 663
lock.lock();
            
//#line 664
sr.accept(((T)(t)));
            
//#line 665
lock.unlock();
        }
        
        
//#line 667
public void
                       accept(
                       final T t,
                       final int id){
            
//#line 668
sr.accept(((T)(t)),
                                   (int)(id));
        }
        
        final private static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2024(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__56__){
            
//#line 624
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__56__,null)) &&
                               !(x10.rtt.Equality.equalsequals(((x10.
                                   lang.
                                   Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__56__)))),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 624
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
            }
            
//#line 624
return __desugarer__var__56__;
        }
        
        final public static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2024$P(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__56__){
            return RemoteCollectingFinish.<T>__$closure$apply$__2024(T,
                                                                     ((x10.
                                                                       lang.
                                                                       Runtime.
                                                                       RootCollectingFinish)(__desugarer__var__56__)));
        }
        
        final private static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2025(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__57__){
            
//#line 631
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__57__,null)) &&
                               !(x10.rtt.Equality.equalsequals(((x10.
                                   lang.
                                   Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__57__)))),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 631
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
            }
            
//#line 631
return __desugarer__var__57__;
        }
        
        final public static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2025$P(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__57__){
            return RemoteCollectingFinish.<T>__$closure$apply$__2025(T,
                                                                     ((x10.
                                                                       lang.
                                                                       Runtime.
                                                                       RootCollectingFinish)(__desugarer__var__57__)));
        }
        
        final private static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2026(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__58__){
            
//#line 648
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__58__,null)) &&
                               !(x10.rtt.Equality.equalsequals(((x10.
                                   lang.
                                   Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__58__)))),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 648
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
            }
            
//#line 648
return __desugarer__var__58__;
        }
        
        final public static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2026$P(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__58__){
            return RemoteCollectingFinish.<T>__$closure$apply$__2026(T,
                                                                     ((x10.
                                                                       lang.
                                                                       Runtime.
                                                                       RootCollectingFinish)(__desugarer__var__58__)));
        }
        
        final private static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2027(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__59__){
            
//#line 655
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__59__,null)) &&
                               !(x10.rtt.Equality.equalsequals(((x10.
                                   lang.
                                   Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__59__)))),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 655
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
            }
            
//#line 655
return __desugarer__var__59__;
        }
        
        final public static <T> x10.
          lang.
          Runtime.
          RootCollectingFinish<T>
          __$closure$apply$__2027$P(
          final x10.rtt.Type T,
          final x10.
            lang.
            Runtime.
            RootCollectingFinish<T> __desugarer__var__59__){
            return RemoteCollectingFinish.<T>__$closure$apply$__2027(T,
                                                                     ((x10.
                                                                       lang.
                                                                       Runtime.
                                                                       RootCollectingFinish)(__desugarer__var__59__)));
        }
    
    }
    
    
//#line 673
public static class RemoteFinish
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<RemoteFinish> _RTT = new x10.rtt.RuntimeType<RemoteFinish>(
    /* base class */RemoteFinish.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 678
/**
         * The Exception Stack is used to collect exceptions
         * issued when activities associated with this finish state terminate abruptly.
         */public x10.
          util.
          Stack<java.lang.Throwable>
          exceptions;
        
//#line 683
/**
         * The monitor is used to serialize updates to the finish state.
         */final public x10.
          lang.
          Runtime.
          Lock
          lock;
        
//#line 688
/**
         * Keep track of the number of activities associated with this finish state.
         */final public x10.core.Rail<java.lang.Integer>
          counts;
        
//#line 690
final public x10.core.Rail<java.lang.Integer>
          message;
        
//#line 691
public int
          length;
        
//#line 693
public java.util.concurrent.atomic.AtomicInteger
          count;
        
        
//#line 695
public void
                       notifyActivityCreation(
                       ){
            
//#line 696
count.getAndIncrement();
        }
        
        
//#line 703
public void
                       notifySubActivitySpawn(
                       final x10.
                         lang.
                         Place place){
            
//#line 704
lock.lock();
            
//#line 705
if (((int) ((((int)(((int[])counts.value)[place.
                                                                     id] += 1))) - (((int)(1))))) ==
                             ((int) 0) &&
                             ((int) x10.
                                      lang.
                                      Runtime.here().
                                      id) !=
                             ((int) place.
                                      id)) {
                
//#line 706
((int[])message.value)[((x10.
                  lang.
                  Runtime.
                  RemoteFinish.__$closure$apply$__2028(((x10.
                                                         lang.
                                                         Runtime.
                                                         RemoteFinish)(this)),
                                                       (int)(1))) - (((int)(1))))] = place.
                                                                                       id;
            }
            
//#line 708
lock.unlock();
        }
        
        
//#line 714
public void
                       notifyActivityTermination(
                       final x10.
                         lang.
                         Runtime.
                         RootFinish r){
            
//#line 715
lock.lock();
            
//#line 716
((int[])counts.value)[x10.
                                                 lang.
                                                 Runtime.here().
                                                 id] -= 1;
            
//#line 717
if (((((int)(count.decrementAndGet()))) > (((int)(0))))) {
                
//#line 718
lock.unlock();
                
//#line 719
return;
            }
            
//#line 721
final x10.
              util.
              Stack<java.lang.Throwable> e =
              ((x10.
              util.
              Stack)(exceptions));
            
//#line 722
this.exceptions = null;
            
//#line 723
if (((((int)(((((int)(2))) * (((int)(length))))))) > (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))))) {
                
//#line 724
final x10.core.ValRail<java.lang.Integer> m =
                  ((x10.core.ValRail)(x10.core.RailFactory.<java.lang.Integer>makeValRailFromRail(x10.rtt.Types.INT, counts)));
                {
                    
//#line 725
final int[] x10$lang$Runtime$RemoteFinish$this$counts$value2061 =
                      ((int[])counts.value);
                    
//#line 725
for (
//#line 725
int i =
                                        0;
                                      ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                      
//#line 725
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 725
x10$lang$Runtime$RemoteFinish$this$counts$value2061[i]=0;
                    }
                }
                
//#line 726
this.length = 1;
                
//#line 727
lock.unlock();
                
//#line 728
if ((!x10.rtt.Equality.equalsequals(null,e))) {
                    
//#line 729
final java.lang.Throwable t;
                    
//#line 730
if (((int) e.size()) ==
                                     ((int) 1)) {
                        
//#line 731
t = ((java.lang.Throwable)(e.peek$G()));
                    } else {
                        
//#line 733
t = ((java.lang.Throwable)(new x10.
                          lang.
                          MultipleExceptions(e)));
                    }
                    
//#line 735
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 735
(x10.
                                        lang.
                                        Runtime.
                                        RemoteFinish.__$closure$apply$__2029(((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootFinish)(((x10.
                                                                                             lang.
                                                                                             Runtime.
                                                                                             RootFinish)
                                                                                             r))))).notify(((x10.core.ValRail)(m)),
                                                                                                           ((java.lang.Throwable)(t)));
                        
//#line 735
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 736
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 737
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                } else {
                    
//#line 739
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 739
(x10.
                                        lang.
                                        Runtime.
                                        RemoteFinish.__$closure$apply$__2030(((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootFinish)(((x10.
                                                                                             lang.
                                                                                             Runtime.
                                                                                             RootFinish)
                                                                                             r))))).notify(((x10.core.ValRail)(m)));
                        
//#line 739
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 740
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 741
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                }
                
//#line 743
x10.
                  lang.
                  Runtime.deallocObject(((java.lang.Object)(m)));
            } else {
                
//#line 745
final x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>> m =
                  ((x10.core.ValRail)((new java.lang.Object() {final x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>> apply(int length) {x10.
                  util.
                  Pair[] array = new x10.
                  util.
                  Pair[length];for (int i$ = 0; i$ < length; i$++) {final int i = i$;array[i] = new x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>(x10.rtt.Types.INT,
                                                             x10.rtt.Types.INT,
                                                             ((int[])message.value)[i],
                                                             ((int[])counts.value)[((int[])message.value)[i]]);}return new x10.core.ValRail<x10.
                  util.
                  Pair<java.lang.Integer, java.lang.Integer>>(new x10.rtt.ParameterizedType(x10.util.Pair._RTT, x10.rtt.Types.INT, x10.rtt.Types.INT), length, array);}}.apply(length))));
                {
                    
//#line 746
final int[] x10$lang$Runtime$RemoteFinish$this$counts$value2062 =
                      ((int[])counts.value);
                    
//#line 746
for (
//#line 746
int i =
                                        0;
                                      ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                      
//#line 746
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 746
x10$lang$Runtime$RemoteFinish$this$counts$value2062[i]=0;
                    }
                }
                
//#line 747
this.length = 1;
                
//#line 748
lock.unlock();
                
//#line 749
if ((!x10.rtt.Equality.equalsequals(null,e))) {
                    
//#line 750
final java.lang.Throwable t;
                    
//#line 751
if (((int) e.size()) ==
                                     ((int) 1)) {
                        
//#line 752
t = ((java.lang.Throwable)(e.peek$G()));
                    } else {
                        
//#line 754
t = ((java.lang.Throwable)(new x10.
                          lang.
                          MultipleExceptions(e)));
                    }
                    
//#line 756
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 756
(x10.
                                        lang.
                                        Runtime.
                                        RemoteFinish.__$closure$apply$__2031(((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootFinish)(((x10.
                                                                                             lang.
                                                                                             Runtime.
                                                                                             RootFinish)
                                                                                             r))))).notify2(((x10.core.ValRail)(m)),
                                                                                                            ((java.lang.Throwable)(t)));
                        
//#line 756
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 757
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 758
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                } else {
                    
//#line 760
final x10.core.fun.VoidFun_0_0 closure =
                      ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        
//#line 760
(x10.
                                        lang.
                                        Runtime.
                                        RemoteFinish.__$closure$apply$__2032(((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootFinish)(((x10.
                                                                                             lang.
                                                                                             Runtime.
                                                                                             RootFinish)
                                                                                             r))))).notify2(((x10.core.ValRail)(m)));
                        
//#line 760
x10.
                          lang.
                          Runtime.deallocObject(((java.lang.Object)(m)));
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                    
//#line 761
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(r)).
                                                                              id)), closure);
                    
//#line 762
x10.
                      lang.
                      Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
                }
                
//#line 764
x10.
                  lang.
                  Runtime.deallocObject(((java.lang.Object)(m)));
            }
        }
        
        
//#line 771
public void
                       pushException(
                       final java.lang.Throwable t){
            
//#line 772
lock.lock();
            
//#line 773
if (x10.rtt.Equality.equalsequals(null,exceptions)) {
                
//#line 773
this.exceptions = ((x10.
                  util.
                  Stack)(new x10.
                  util.
                  Stack<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class))));
            }
            
//#line 774
exceptions.push(((java.lang.Throwable)(t)));
            
//#line 775
lock.unlock();
        }
        
        
//#line 673
public RemoteFinish() {
            
//#line 673
super();
            
//#line 678
this.exceptions = null;
            
//#line 683
this.lock = ((x10.
              lang.
              Runtime.
              Lock)(new x10.
              lang.
              Runtime.
              Lock()));
            
//#line 688
this.counts = ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$40$ = 0; id$40$ < length; id$40$++) {final int id$40 = id$40$;array[id$40] = 0;}return new x10.core.Rail<java.lang.Integer>(x10.rtt.Types.INT, x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
            
//#line 690
this.message = ((x10.core.Rail)((new java.lang.Object() {final x10.core.Rail<java.lang.Integer> apply(int length) {int[] array = new int[length];for (int id$41$ = 0; id$41$ < length; id$41$++) {final int id$41 = id$41$;array[id$41] = x10.
                                                                                                                                                                                                                                                                     lang.
                                                                                                                                                                                                                                                                     Runtime.here().
                                                                                                                                                                                                                                                                     id;}return new x10.core.Rail<java.lang.Integer>(x10.rtt.Types.INT, x10.runtime.impl.java.Runtime.MAX_PLACES, array);}}.apply(x10.runtime.impl.java.Runtime.MAX_PLACES))));
            
//#line 691
this.length = 1;
            
//#line 693
this.count = ((java.util.concurrent.atomic.AtomicInteger)(new java.util.concurrent.atomic.AtomicInteger(0)));
        }
        
        final private static int
          __$closure$apply$__2028(
          final x10.
            lang.
            Runtime.
            RemoteFinish x,
          final int y){
            
//#line 706
return x.length = ((((int)(x.
                                                      length))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2028$P(
          final x10.
            lang.
            Runtime.
            RemoteFinish x,
          final int y){
            return RemoteFinish.__$closure$apply$__2028(((x10.
                                                          lang.
                                                          Runtime.
                                                          RemoteFinish)(x)),
                                                        (int)(y));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2029(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__60__){
            
//#line 735
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__60__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__60__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 735
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 735
return __desugarer__var__60__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2029$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__60__){
            return RemoteFinish.__$closure$apply$__2029(((x10.
                                                          lang.
                                                          Runtime.
                                                          RootFinish)(__desugarer__var__60__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2030(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__61__){
            
//#line 739
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__61__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__61__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 739
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 739
return __desugarer__var__61__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2030$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__61__){
            return RemoteFinish.__$closure$apply$__2030(((x10.
                                                          lang.
                                                          Runtime.
                                                          RootFinish)(__desugarer__var__61__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2031(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__62__){
            
//#line 756
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__62__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__62__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 756
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 756
return __desugarer__var__62__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2031$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__62__){
            return RemoteFinish.__$closure$apply$__2031(((x10.
                                                          lang.
                                                          Runtime.
                                                          RootFinish)(__desugarer__var__62__)));
        }
        
        final private static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2032(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__63__){
            
//#line 760
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__63__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__63__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 760
throw new java.lang.ClassCastException("x10.lang.Runtime.RootFinish{self.home==here}");
            }
            
//#line 760
return __desugarer__var__63__;
        }
        
        final public static x10.
          lang.
          Runtime.
          RootFinish
          __$closure$apply$__2032$P(
          final x10.
            lang.
            Runtime.
            RootFinish __desugarer__var__63__){
            return RemoteFinish.__$closure$apply$__2032(((x10.
                                                          lang.
                                                          Runtime.
                                                          RootFinish)(__desugarer__var__63__)));
        }
    
    }
    
    
//#line 781
final public static class Thread
                 extends x10.core.Ref
                 {public static final x10.rtt.RuntimeType<Thread> _RTT = new x10.rtt.RuntimeType<Thread>(
    /* base class */Thread.class
    , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 783
final public x10.
          runtime.
          impl.
          java.
          Thread
          __NATIVE_FIELD__;
        
        
//#line 783
private Thread(final x10.
                                      runtime.
                                      impl.
                                      java.
                                      Thread id0) {
            
//#line 783
super();
            
//#line 783
this.__NATIVE_FIELD__ = id0;
        }
        
        
//#line 788
public Thread(final x10.core.fun.VoidFun_0_0 body,
                                   final java.lang.String name) {
            
//#line 783
this(new x10.
                                runtime.
                                impl.
                                java.
                                Thread(body,
                                       name));
        }
        
        
//#line 790
public static x10.
                       lang.
                       Runtime.
                       Thread
                       currentThread(
                       ){
            
//#line 783
return new x10.
              lang.
              Runtime.
              Thread(x10.
                       runtime.
                       impl.
                       java.
                       Thread.currentThread());
        }
        
        
//#line 792
public void
                       start(
                       ){
            
//#line 783
this.
                           __NATIVE_FIELD__.start();
        }
        
        
//#line 794
public static void
                       sleep(
                       final long millis)
                           throws java.lang.InterruptedException{
            
//#line 783
x10.
              runtime.
              impl.
              java.
              Thread.sleep((long)(millis));
        }
        
        
//#line 796
public static void
                       sleep(
                       final long millis,
                       final int nanos)
                           throws java.lang.InterruptedException{
            
//#line 783
x10.
              runtime.
              impl.
              java.
              Thread.sleep((long)(millis),
                           (int)(nanos));
        }
        
        
//#line 798
public static void
                       park(
                       ){
            
//#line 783
x10.
              runtime.
              impl.
              java.
              Thread.park();
        }
        
        
//#line 800
public static void
                       parkNanos(
                       final long nanos){
            
//#line 783
x10.
              runtime.
              impl.
              java.
              Thread.parkNanos((long)(nanos));
        }
        
        
//#line 802
public void
                       unpark(
                       ){
            
//#line 783
this.
                           __NATIVE_FIELD__.unpark();
        }
        
        
//#line 804
public java.lang.Object
                       worker(
                       ){
            
//#line 783
return this.
                                  __NATIVE_FIELD__.worker();
        }
        
        
//#line 806
public void
                       worker(
                       final x10.
                         lang.
                         Runtime.
                         Worker worker){
            
//#line 783
this.
                           __NATIVE_FIELD__.worker(((x10.
                                                     lang.
                                                     Runtime.
                                                     Worker)(worker)));
        }
        
        
//#line 808
public java.lang.String
                       name(
                       ){
            
//#line 783
return this.
                                  __NATIVE_FIELD__.name();
        }
        
        
//#line 810
public void
                       name(
                       final java.lang.String name){
            
//#line 783
this.
                           __NATIVE_FIELD__.name(((java.lang.String)(name)));
        }
        
        
//#line 812
public int
                       locInt(
                       ){
            
//#line 783
return this.
                                  __NATIVE_FIELD__.locInt();
        }
        
        
//#line 814
public static long
                       getTid(
                       ){
            
//#line 783
return x10.
              runtime.
              impl.
              java.
              Thread.getTid();
        }
    
    }
    
    
//#line 818
final public static class Worker
                 extends x10.core.Ref
                   implements x10.core.fun.VoidFun_0_0
                 {public static final x10.rtt.RuntimeType<Worker> _RTT = new x10.rtt.RuntimeType<Worker>(
    /* base class */Worker.class
    , /* parents */ new x10.rtt.Type[] {x10.core.fun.VoidFun_0_0._RTT, x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 819
final public x10.
          lang.
          Runtime.
          Latch
          latch;
        
//#line 823
final public static int
          BOUND =
          100;
        
//#line 826
public x10.
          lang.
          Activity
          activity;
        
//#line 829
final public x10.
          lang.
          Runtime.
          Deque
          queue;
        
//#line 832
final public x10.
          util.
          Random
          random;
        
//#line 835
final public x10.core.GrowableRail<x10.
          lang.
          Activity>
          debug;
        
//#line 837
public long
          tid;
        
//#line 840
public int
          workerId;
        
        
//#line 841
public void
                       setWorkerId(
                       final int id){
            
//#line 842
this.workerId = id;
        }
        
        
//#line 845
public Worker(final x10.
                                     lang.
                                     Runtime.
                                     Latch latch,
                                   final int p) {
            super();
            
//#line 826
this.activity = null;
            
//#line 829
this.queue = ((x10.
              lang.
              Runtime.
              Deque)(new x10.
              lang.
              Runtime.
              Deque()));
            
//#line 835
this.debug = ((x10.core.GrowableRail)(new x10.core.GrowableRail<x10.
              lang.
              Activity>(x10.lang.Activity._RTT)));
            
//#line 837
this.tid = 0L;
            
//#line 840
this.workerId = 0;
            
//#line 846
this.latch = ((x10.
              lang.
              Runtime.
              Latch)(latch));
            
//#line 847
this.random = ((x10.
              util.
              Random)(new x10.
              util.
              Random(((long)(((int)(((((int)(((((int)(((((int)(p))) + (((int)((((((int)(p))) << (((int)(8)))))))))))) + (((int)((((((int)(p))) << (((int)(16)))))))))))) + (((int)((((((int)(p))) << (((int)(24))))))))))))))));
        }
        
        
//#line 853
public int
                       size(
                       ){
            
//#line 853
return queue.size();
        }
        
        
//#line 856
public x10.
                       lang.
                       Activity
                       activity(
                       ){
            
//#line 856
return activity;
        }
        
        
//#line 859
private x10.
                       lang.
                       Activity
                       poll(
                       ){
            
//#line 859
return (new java.lang.Object() {final x10.
              lang.
              Activity cast(final x10.
              lang.
              Activity self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Activity._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
              lang.
              Activity) queue.poll()));
        }
        
        public static x10.
          lang.
          Activity
          poll$P(
          final x10.
            lang.
            Runtime.
            Worker Worker){
            return Worker.poll();
        }
        
        
//#line 862
public x10.
                       lang.
                       Activity
                       steal(
                       ){
            
//#line 862
return (new java.lang.Object() {final x10.
              lang.
              Activity cast(final x10.
              lang.
              Activity self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Activity._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
              lang.
              Activity) queue.steal()));
        }
        
        
//#line 865
public void
                       push(
                       final x10.
                         lang.
                         Activity activity){
            {
                
//#line 865
queue.push(((java.lang.Object)(activity)));
                
//#line 865
return;
            }
        }
        
        
//#line 868
public void
                       apply(
                       ){
            
//#line 869
this.tid = x10.
              lang.
              Runtime.
              Thread.getTid();
            
//#line 870
try {{
                
//#line 871
while (this.loop(((x10.
                                                lang.
                                                Runtime.
                                                Latch)(latch)),
                                              (boolean)(true)))
                    
//#line 871
;
            }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
            if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
            final java.lang.Throwable t = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
            {
                
//#line 873
java.lang.System.err.println("Uncaught exception in worker thread");
                
//#line 874
t.printStackTrace();
            }
            }
            else {
            throw __$generated_wrappedex$__;
            }
            }catch (final java.lang.Throwable t) {
                
//#line 873
java.lang.System.err.println("Uncaught exception in worker thread");
                
//#line 874
t.printStackTrace();
            }finally {{
                 
//#line 876
x10.
                   lang.
                   Runtime.report();
             }}
            }
        
        
//#line 881
public void
                       join(
                       final x10.
                         lang.
                         Runtime.
                         Latch latch){
            
//#line 882
final x10.
              lang.
              Activity tmp =
              activity;
            
//#line 883
while (this.loop(((x10.
                                            lang.
                                            Runtime.
                                            Latch)(latch)),
                                          (boolean)(false)))
                
//#line 883
;
            
//#line 884
this.activity = tmp;
        }
        
        
//#line 888
private boolean
                       loop(
                       final x10.
                         lang.
                         Runtime.
                         Latch latch,
                       final boolean block){
            
//#line 889
for (
//#line 889
int i =
                                0;
                              ((((int)(i))) < (((int)(x10.
                                lang.
                                Runtime.
                                Worker.BOUND))));
                              
//#line 889
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 890
if (latch.apply()) {
                    
//#line 890
return false;
                }
                
//#line 891
this.activity = this.poll();
                
//#line 892
if (x10.rtt.Equality.equalsequals(activity,null)) {
                    
//#line 893
this.activity = x10.
                      lang.
                      Runtime.scan(((x10.
                                     util.
                                     Random)(random)),
                                   ((x10.
                                     lang.
                                     Runtime.
                                     Latch)(latch)),
                                   (boolean)(block));
                    
//#line 894
if (x10.rtt.Equality.equalsequals(activity,null)) {
                        
//#line 894
return false;
                    }
                }
                
//#line 896
(debug).add(activity);
                
//#line 897
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(activity)).
                                                                          id)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                    {
                        
//#line 897
(x10.
                                        lang.
                                        Runtime.
                                        Worker.__$closure$apply$__2033(((x10.
                                                                         lang.
                                                                         Activity)(((x10.
                                                                                     lang.
                                                                                     Activity)
                                                                                     activity))))).run();
                        
//#line 897
return;
                    }
                }}
                public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                }
                });
                
//#line 898
(debug).removeLast();
            }
            
//#line 900
return true;
        }
        
        public static boolean
          loop$P(
          final x10.
            lang.
            Runtime.
            Latch latch,
          final boolean block,
          final x10.
            lang.
            Runtime.
            Worker Worker){
            return Worker.loop(((x10.
                                 lang.
                                 Runtime.
                                 Latch)(latch)),
                               (boolean)(block));
        }
        
        
//#line 903
public void
                       probe(
                       ){
            
//#line 905
final x10.
              lang.
              Activity tmp =
              activity;
            
//#line 906
while (true) {
                
//#line 907
this.activity = this.poll();
                
//#line 908
if (x10.rtt.Equality.equalsequals(activity,null)) {
                    
//#line 909
this.activity = tmp;
                    
//#line 910
return;
                }
                
//#line 912
(debug).add(activity);
                
//#line 913
x10.runtime.impl.java.Runtime.runAt(((int)(x10.lang.Place.place(x10.core.Ref.home(activity)).
                                                                          id)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                    {
                        
//#line 913
(x10.
                                        lang.
                                        Runtime.
                                        Worker.__$closure$apply$__2034(((x10.
                                                                         lang.
                                                                         Activity)(((x10.
                                                                                     lang.
                                                                                     Activity)
                                                                                     activity))))).run();
                        
//#line 913
return;
                    }
                }}
                public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                }
                });
                
//#line 914
(debug).removeLast();
            }
        }
        
        
//#line 918
public void
                       dump(
                       final int id,
                       final x10.
                         lang.
                         Runtime.
                         Thread thread){
            
//#line 919
java.lang.System.err.printf("WORKER %d", ((java.lang.Integer)(id)));
            
//#line 920
java.lang.System.err.printf(" = THREAD %#lx\n", ((java.lang.Long)(tid)));
            
//#line 921
for (
//#line 921
int i =
                                ((((int)((debug).length()))) - (((int)(1))));
                              ((((int)(i))) >= (((int)(0))));
                              
//#line 921
i = ((((int)(i))) - (((int)(1))))) {
                
//#line 922
(debug).apply$G(((int)(i))).dump();
            }
            
//#line 924
java.lang.System.err.println();
        }
        
        final private static x10.
          lang.
          Activity
          __$closure$apply$__2033(
          final x10.
            lang.
            Activity __desugarer__var__64__){
            
//#line 897
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__64__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__64__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 897
throw new java.lang.ClassCastException("x10.lang.Activity{self.home==here}");
            }
            
//#line 897
return __desugarer__var__64__;
        }
        
        final public static x10.
          lang.
          Activity
          __$closure$apply$__2033$P(
          final x10.
            lang.
            Activity __desugarer__var__64__){
            return Worker.__$closure$apply$__2033(((x10.
                                                    lang.
                                                    Activity)(__desugarer__var__64__)));
        }
        
        final private static x10.
          lang.
          Activity
          __$closure$apply$__2034(
          final x10.
            lang.
            Activity __desugarer__var__65__){
            
//#line 913
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__65__,null)) &&
                               !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__65__)),x10.
                                   lang.
                                   Runtime.here()))) {
                
//#line 913
throw new java.lang.ClassCastException("x10.lang.Activity{self.home==here}");
            }
            
//#line 913
return __desugarer__var__65__;
        }
        
        final public static x10.
          lang.
          Activity
          __$closure$apply$__2034$P(
          final x10.
            lang.
            Activity __desugarer__var__65__){
            return Worker.__$closure$apply$__2034(((x10.
                                                    lang.
                                                    Activity)(__desugarer__var__65__)));
        }
        
        }
        
    
    
//#line 928
public static void
                   probe(
                   ){
        
//#line 929
x10.
          lang.
          Runtime.event_probe();
        
//#line 930
x10.
          lang.
          Runtime.worker().probe();
    }
    
    
//#line 933
public static class Pool
                 extends x10.core.Ref
                   implements x10.core.fun.VoidFun_0_0
                 {public static final x10.rtt.RuntimeType<Pool> _RTT = new x10.rtt.RuntimeType<Pool>(
    /* base class */Pool.class
    , /* parents */ new x10.rtt.Type[] {x10.core.fun.VoidFun_0_0._RTT, x10.rtt.Types.runtimeType(java.lang.Object.class)}
    );
    public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
    
    
    
        
//#line 934
final public x10.
          lang.
          Runtime.
          Latch
          latch;
        
//#line 935
public int
          size;
        
//#line 937
public int
          spares;
        
//#line 939
final public x10.
          lang.
          Runtime.
          Lock
          lock;
        
//#line 941
final public x10.
          lang.
          Runtime.
          Semaphore
          semaphore;
        
//#line 944
final public static int
          MAX =
          1000;
        
//#line 947
final public x10.core.Rail<x10.
          lang.
          Runtime.
          Worker>
          workers;
        
//#line 950
final public x10.core.Rail<x10.
          lang.
          Runtime.
          Thread>
          threads;
        
        
//#line 952
public Pool(final x10.
                                   lang.
                                   Runtime.
                                   Latch latch,
                                 final int size) {
            super();
            
//#line 935
this.size = 0;
            
//#line 937
this.spares = 0;
            
//#line 939
this.lock = ((x10.
              lang.
              Runtime.
              Lock)(new x10.
              lang.
              Runtime.
              Lock()));
            
//#line 941
this.semaphore = ((x10.
              lang.
              Runtime.
              Semaphore)(new x10.
              lang.
              Runtime.
              Semaphore(0)));
            
//#line 953
this.latch = ((x10.
              lang.
              Runtime.
              Latch)(latch));
            
//#line 954
this.size = size;
            
//#line 955
final x10.core.Rail<x10.
              lang.
              Runtime.
              Worker> workers =
              ((x10.core.Rail)(x10.core.RailFactory.<x10.
              lang.
              Runtime.
              Worker>makeVarRail(x10.lang.Runtime.Worker._RTT, ((int)(x10.
              lang.
              Runtime.
              Pool.MAX)))));
            
//#line 956
final x10.core.Rail<x10.
              lang.
              Runtime.
              Thread> threads =
              ((x10.core.Rail)(x10.core.RailFactory.<x10.
              lang.
              Runtime.
              Thread>makeVarRail(x10.lang.Runtime.Thread._RTT, ((int)(size)))));
            
//#line 959
final x10.
              lang.
              Runtime.
              Worker master =
              ((x10.
              lang.
              Runtime.
              Worker)(new x10.
              lang.
              Runtime.
              Worker(latch,
                     0)));
            
//#line 960
((x10.
              lang.
              Runtime.
              Worker[])workers.value)[0] = master;
            
//#line 961
((x10.
              lang.
              Runtime.
              Thread[])threads.value)[0] = x10.
              lang.
              Runtime.
              Thread.currentThread();
            
//#line 962
x10.
              lang.
              Runtime.
              Thread.currentThread().worker(((x10.
                                              lang.
                                              Runtime.
                                              Worker)(master)));
            
//#line 963
((x10.
              lang.
              Runtime.
              Worker)((x10.
              lang.
              Runtime.
              Worker[])workers.value)[0]).setWorkerId((int)(0));
            {
                
//#line 966
final x10.
                  lang.
                  Runtime.
                  Worker[] workers$value2063 =
                  ((x10.
                  lang.
                  Runtime.
                  Worker[])workers.value);
                
//#line 966
final x10.
                  lang.
                  Runtime.
                  Thread[] threads$value2064 =
                  ((x10.
                  lang.
                  Runtime.
                  Thread[])threads.value);
                
//#line 966
for (
//#line 966
int i =
                                    1;
                                  ((((int)(i))) < (((int)(size))));
                                  
//#line 966
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 967
final x10.
                      lang.
                      Runtime.
                      Worker worker =
                      ((x10.
                      lang.
                      Runtime.
                      Worker)(new x10.
                      lang.
                      Runtime.
                      Worker(latch,
                             i)));
                    
//#line 968
workers$value2063[i]=worker;
                    
//#line 969
threads$value2064[i]=new x10.
                      lang.
                      Runtime.
                      Thread(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                 {
                                     
//#line 969
worker.apply();
                                     
//#line 969
return;
                                 }
                             }}
                             public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                             }
                             },
                             (("thread-") + (((java.lang.Integer)(i)))));
                    
//#line 970
((x10.
                      lang.
                      Runtime.
                      Thread)threads$value2064[i]).worker(((x10.
                                                            lang.
                                                            Runtime.
                                                            Worker)(worker)));
                    
//#line 971
((x10.
                      lang.
                      Runtime.
                      Worker)workers$value2063[i]).setWorkerId((int)(i));
                }
            }
            
//#line 973
this.workers = ((x10.core.Rail)(workers));
            
//#line 974
this.threads = ((x10.core.Rail)(threads));
        }
        
        
//#line 977
public void
                       apply(
                       ){
            
//#line 978
final int s =
              size;
            {
                
//#line 979
final x10.
                  lang.
                  Runtime.
                  Thread[] x10$lang$Runtime$Pool$this$threads$value2065 =
                  ((x10.
                  lang.
                  Runtime.
                  Thread[])threads.value);
                
//#line 979
for (
//#line 979
int i =
                                    1;
                                  ((((int)(i))) < (((int)(s))));
                                  
//#line 979
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 980
((x10.
                      lang.
                      Runtime.
                      Thread)x10$lang$Runtime$Pool$this$threads$value2065[i]).start();
                }
            }
            
//#line 982
((x10.
              lang.
              Runtime.
              Worker)((x10.
              lang.
              Runtime.
              Worker[])workers.value)[0]).apply();
            
//#line 983
while (((((int)(size))) > (((int)(0)))))
                
//#line 983
x10.
                  lang.
                  Runtime.
                  Thread.park();
        }
        
        
//#line 989
public void
                       increase(
                       ){
            
//#line 990
lock.lock();
            
//#line 991
if (((((int)(spares))) > (((int)(0))))) {
                
//#line 993
x10.
                  lang.
                  Runtime.
                  Pool.__$closure$apply$__2035(((x10.
                                                 lang.
                                                 Runtime.
                                                 Pool)(this)),
                                               (int)(1));
                
//#line 994
lock.unlock();
                
//#line 995
semaphore.release();
            } else {
                
//#line 998
final int i =
                  ((x10.
                  lang.
                  Runtime.
                  Pool.__$closure$apply$__2036(((x10.
                                                 lang.
                                                 Runtime.
                                                 Pool)(this)),
                                               (int)(1))) - (((int)(1))));
                
//#line 999
lock.unlock();
                
//#line 1000
assert (((((int)(i))) < (((int)(x10.
                                        lang.
                                        Runtime.
                                        Pool.MAX)))));
                
//#line 1001
if (((((int)(i))) >= (((int)(x10.
                                    lang.
                                    Runtime.
                                    Pool.MAX))))) {
                    
//#line 1002
java.lang.System.err.println("TOO MANY THREADS... ABORTING");
                    
//#line 1003
java.lang.System.exit(((int)(1)));
                }
                
//#line 1005
final x10.
                  lang.
                  Runtime.
                  Worker worker =
                  ((x10.
                  lang.
                  Runtime.
                  Worker)(new x10.
                  lang.
                  Runtime.
                  Worker(latch,
                         i)));
                
//#line 1006
((x10.
                  lang.
                  Runtime.
                  Worker[])workers.value)[i] = worker;
                
//#line 1007
final x10.
                  lang.
                  Runtime.
                  Thread thread =
                  ((x10.
                  lang.
                  Runtime.
                  Thread)(new x10.
                  lang.
                  Runtime.
                  Thread(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                             {
                                 
//#line 1007
worker.apply();
                                 
//#line 1007
return;
                             }
                         }}
                         public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                         }
                         },
                         (("thread-") + (((java.lang.Integer)(i)))))));
                
//#line 1008
thread.worker(((x10.
                                              lang.
                                              Runtime.
                                              Worker)(worker)));
                
//#line 1009
thread.start();
            }
        }
        
        
//#line 1014
public void
                        decrease(
                        final int n){
            
//#line 1016
lock.lock();
            
//#line 1017
x10.
              lang.
              Runtime.
              Pool.__$closure$apply$__2037(((x10.
                                             lang.
                                             Runtime.
                                             Pool)(this)),
                                           (int)(n));
            
//#line 1018
lock.unlock();
            
//#line 1020
semaphore.reduce((int)(n));
        }
        
        
//#line 1024
public void
                        release(
                        ){
            
//#line 1025
semaphore.release();
            
//#line 1026
lock.lock();
            
//#line 1027
x10.
              lang.
              Runtime.
              Pool.__$closure$apply$__2038(((x10.
                                             lang.
                                             Runtime.
                                             Pool)(this)),
                                           (int)(1));
            
//#line 1028
if (((int) size) ==
                              ((int) 0)) {
                
//#line 1028
((x10.
                  lang.
                  Runtime.
                  Thread)((x10.
                  lang.
                  Runtime.
                  Thread[])threads.value)[0]).unpark();
            }
            
//#line 1029
lock.unlock();
        }
        
        
//#line 1033
public x10.
                        lang.
                        Activity
                        scan(
                        final x10.
                          util.
                          Random random,
                        final x10.
                          lang.
                          Runtime.
                          Latch latch,
                        final boolean block){
            
//#line 1034
x10.
              lang.
              Activity activity =
              null;
            
//#line 1035
int next =
              random.nextInt((int)(size));
            {
                
//#line 1036
final x10.
                  lang.
                  Runtime.
                  Worker[] x10$lang$Runtime$Pool$this$workers$value2066 =
                  ((x10.
                  lang.
                  Runtime.
                  Worker[])workers.value);
                
//#line 1036
for (;
                                   ;
                                   ) {
                    
//#line 1037
x10.
                      lang.
                      Runtime.event_probe();
                    
//#line 1038
if ((!x10.rtt.Equality.equalsequals(null,((x10.
                                        lang.
                                        Runtime.
                                        Worker)x10$lang$Runtime$Pool$this$workers$value2066[next])))) {
                        
//#line 1039
activity = ((x10.
                          lang.
                          Runtime.
                          Worker)x10$lang$Runtime$Pool$this$workers$value2066[next]).steal();
                    }
                    
//#line 1041
if ((!x10.rtt.Equality.equalsequals(null,activity)) ||
                                      latch.apply()) {
                        
//#line 1041
return activity;
                    }
                    
//#line 1042
if (((((int)(semaphore.available()))) < (((int)(0))))) {
                        
//#line 1043
if (block) {
                            
//#line 1044
semaphore.release();
                            
//#line 1045
semaphore.acquire();
                        } else {
                            
//#line 1047
return activity;
                        }
                    }
                    
//#line 1050
if (((int) (next = ((((int)(next))) + (((int)(1)))))) ==
                                      ((int) size)) {
                        
//#line 1050
next = 0;
                    }
                }
            }
        }
        
        
//#line 1054
public void
                        dump(
                        ){
            {
                
//#line 1055
final x10.
                  lang.
                  Runtime.
                  Worker[] x10$lang$Runtime$Pool$this$workers$value2067 =
                  ((x10.
                  lang.
                  Runtime.
                  Worker[])workers.value);
                
//#line 1055
final x10.
                  lang.
                  Runtime.
                  Thread[] x10$lang$Runtime$Pool$this$threads$value2068 =
                  ((x10.
                  lang.
                  Runtime.
                  Thread[])threads.value);
                
//#line 1055
for (
//#line 1055
int i =
                                     0;
                                   ((((int)(i))) < (((int)(size))));
                                   
//#line 1055
i = ((((int)(i))) + (((int)(1))))) {
                    
//#line 1056
((x10.
                      lang.
                      Runtime.
                      Worker)x10$lang$Runtime$Pool$this$workers$value2067[i]).dump((int)(i),
                                                                                   ((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     Thread)(((x10.
                                                                                     lang.
                                                                                     Runtime.
                                                                                     Thread)x10$lang$Runtime$Pool$this$threads$value2068[i]))));
                }
            }
        }
        
        final private static int
          __$closure$apply$__2035(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            
//#line 993
return x.spares = ((((int)(x.
                                                      spares))) - (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2035$P(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            return Pool.__$closure$apply$__2035(((x10.
                                                  lang.
                                                  Runtime.
                                                  Pool)(x)),
                                                (int)(y));
        }
        
        final private static int
          __$closure$apply$__2036(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            
//#line 998
return x.size = ((((int)(x.
                                                    size))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2036$P(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            return Pool.__$closure$apply$__2036(((x10.
                                                  lang.
                                                  Runtime.
                                                  Pool)(x)),
                                                (int)(y));
        }
        
        final private static int
          __$closure$apply$__2037(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            
//#line 1017
return x.spares = ((((int)(x.
                                                       spares))) + (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2037$P(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            return Pool.__$closure$apply$__2037(((x10.
                                                  lang.
                                                  Runtime.
                                                  Pool)(x)),
                                                (int)(y));
        }
        
        final private static int
          __$closure$apply$__2038(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            
//#line 1027
return x.size = ((((int)(x.
                                                     size))) - (((int)(y))));
        }
        
        final public static int
          __$closure$apply$__2038$P(
          final x10.
            lang.
            Runtime.
            Pool x,
          final int y){
            return Pool.__$closure$apply$__2038(((x10.
                                                  lang.
                                                  Runtime.
                                                  Pool)(x)),
                                                (int)(y));
        }
    
    }
    
    
//#line 1063
final public static boolean
      PRINT_STATS =
      false;
    
    
//#line 1065
public static void
                    dump(
                    ){
        
//#line 1066
x10.
                        lang.
                        Runtime.runtime.apply$G().
                        pool.dump();
    }
    
    
//#line 1072
final public x10.
      lang.
      Runtime.
      Pool
      pool;
    
//#line 1075
final public x10.
      lang.
      Runtime.
      Monitor
      monitor;
    
//#line 1076
final public x10.
      lang.
      Runtime.
      FinishStates
      finishStates;
    
    
//#line 1080
private Runtime(final x10.
                                    lang.
                                    Runtime.
                                    Pool pool) {
        super();
        
//#line 1075
this.monitor = ((x10.
          lang.
          Runtime.
          Monitor)(new x10.
          lang.
          Runtime.
          Monitor()));
        
//#line 1076
this.finishStates = ((x10.
          lang.
          Runtime.
          FinishStates)(new x10.
          lang.
          Runtime.
          FinishStates()));
        
//#line 1081
this.pool = ((x10.
          lang.
          Runtime.
          Pool)(pool));
    }
    
    
//#line 1087
/**
     * The runtime instance associated with each place
     */final public static x10.
      lang.
      PlaceLocalHandle<x10.
      lang.
      Runtime>
      runtime =
      new x10.
      lang.
      PlaceLocalHandle<x10.
      lang.
      Runtime>(x10.lang.Runtime._RTT);
    
    
//#line 1089
public static x10.
                    lang.
                    Runtime.
                    RemoteFinish
                    proxy(
                    final x10.
                      lang.
                      Runtime.
                      RootFinish rootFinish){
        
//#line 1089
return x10.
                               lang.
                               Runtime.runtime.apply$G().
                               finishStates.apply(((x10.
                                                    lang.
                                                    Runtime.
                                                    RootFinish)(rootFinish)));
    }
    
    
//#line 1094
private static x10.
                    lang.
                    Runtime.
                    Worker
                    worker(
                    ){
        
//#line 1095
return (new java.lang.Object() {final x10.
          lang.
          Runtime.
          Worker cast(final x10.
          lang.
          Runtime.
          Worker self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Runtime.Worker._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
          lang.
          Runtime.
          Worker) x10.
          lang.
          Runtime.
          Thread.currentThread().worker()));
    }
    
    public static x10.
      lang.
      Runtime.
      Worker
      worker$P(
      ){
        return Runtime.worker();
    }
    
    
//#line 1100
public static x10.
                    lang.
                    Activity
                    activity(
                    ){
        
//#line 1101
return new x10.core.fun.Fun_0_1<x10.
          lang.
          Activity, x10.
          lang.
          Activity>() {public final x10.
          lang.
          Activity apply$G(final x10.
          lang.
          Activity __desugarer__var__66__) { return apply(__desugarer__var__66__);}
        public final x10.
          lang.
          Activity apply(final x10.
          lang.
          Activity __desugarer__var__66__) { {
            
//#line 1101
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__66__,null)) &&
                                !(x10.rtt.Equality.equalsequals(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__66__)),x10.
                                    lang.
                                    Runtime.here()))) {
                
//#line 1101
throw new java.lang.ClassCastException("x10.lang.Activity{self.home==here}");
            }
            
//#line 1101
return __desugarer__var__66__;
        }}
        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return x10.lang.Activity._RTT;if (i ==1) return x10.lang.Activity._RTT;return null;
        }
        }.apply(((x10.
                  lang.
                  Activity)
                  x10.
                  lang.
                  Runtime.worker().activity()));
    }
    
    
//#line 1106
public static x10.
                    lang.
                    Place
                    here(
                    ){
        
//#line 1107
return x10.lang.Place.place(x10.core.Ref.home(x10.
          lang.
          Runtime.
          Thread.currentThread()));
    }
    
    
//#line 1112
public static int
                    hereInt(
                    ){
        
//#line 1113
return x10.
          lang.
          Runtime.
          Thread.currentThread().locInt();
    }
    
    
//#line 1120
public static int
                    surplusActivityCount(
                    ){
        
//#line 1120
return x10.
          lang.
          Runtime.worker().size();
    }
    
    
//#line 1125
public static void
                    start(
                    final x10.core.fun.VoidFun_0_0 init,
                    final x10.core.fun.VoidFun_0_0 body){
        
//#line 1126
final x10.
          lang.
          Runtime.
          RootFinish rootFinish =
          ((x10.
          lang.
          Runtime.
          RootFinish)(new x10.
          lang.
          Runtime.
          RootFinish()));
        
//#line 1127
final x10.
          lang.
          Runtime.
          Pool pool =
          ((x10.
          lang.
          Runtime.
          Pool)(new x10.
          lang.
          Runtime.
          Pool(rootFinish,
               x10.runtime.impl.java.Runtime.INIT_THREADS)));
        
//#line 1128
try {{
            
//#line 1129
for (
//#line 1129
int i =
                                 0;
                               ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                               
//#line 1129
i = ((((int)(i))) + (((int)(1))))) {
                
//#line 1130
if (x10.runtime.impl.java.Runtime.local(((int)(i)))) {
                    
//#line 1132
x10.runtime.impl.java.Runtime.runAt(((int)(i)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        {
                            
//#line 1132
x10.
                              lang.
                              Runtime.runtime.set(((x10.
                                                    lang.
                                                    Runtime)(new x10.
                                                    lang.
                                                    Runtime(pool))));
                            
//#line 1132
return;
                        }
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    });
                }
            }
            
//#line 1135
x10.
              lang.
              Runtime.registerHandlers();
            
//#line 1136
if (((int) x10.
                                lang.
                                Runtime.hereInt()) ==
                              ((int) 0)) {
                
//#line 1137
x10.
                  lang.
                  Runtime.execute(((x10.
                                    lang.
                                    Activity)(new x10.
                                    lang.
                                    Activity(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                                                 
//#line 1137
try {{
                                                     
//#line 1137
x10.
                                                       lang.
                                                       Runtime.startFinish();
                                                     {
                                                         
//#line 1137
init.apply();
                                                     }
                                                 }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
                                                 if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
                                                 java.lang.Throwable __desugarer__var__67__ = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
                                                 {
                                                     
//#line 1137
x10.
                                                       lang.
                                                       Runtime.pushException(((java.lang.Throwable)(__desugarer__var__67__)));
                                                     throw new java.lang.RuntimeException();
                                                 }
                                                 }
                                                 else {
                                                 throw __$generated_wrappedex$__;
                                                 }
                                                 }catch (java.lang.Throwable __desugarer__var__67__) {
                                                     
//#line 1137
x10.
                                                       lang.
                                                       Runtime.pushException(((java.lang.Throwable)(__desugarer__var__67__)));
                                                     throw new java.lang.RuntimeException();
                                                 }finally {{
                                                      
//#line 1137
x10.
                                                        lang.
                                                        Runtime.stopFinish();
                                                  }}
                                                 
//#line 1137
body.apply();
                                                 }}
                                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                 }
                                                 },
                                                 rootFinish,
                                                 true))));
                
//#line 1138
pool.apply();
                
//#line 1139
if ((!(((boolean)(x10.runtime.impl.java.Runtime.local(((int)(((((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))) - (((int)(1)))))))))))) {
                    
//#line 1140
for (
//#line 1140
int i =
                                         1;
                                       ((((int)(i))) < (((int)(x10.runtime.impl.java.Runtime.MAX_PLACES))));
                                       
//#line 1140
i = ((((int)(i))) + (((int)(1))))) {
                        
//#line 1141
x10.runtime.impl.java.Runtime.runAt(((int)(i)), new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            {
                                
//#line 1141
x10.
                                                lang.
                                                Runtime.worker().
                                                latch.release();
                                
//#line 1141
return;
                            }
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        });
                    }
                }
                
//#line 1144
rootFinish.waitForFinish((boolean)(false));
                } else {
                    
//#line 1146
pool.apply();
                }
            }}finally {{
                  
//#line 1149
if (x10.
                                      lang.
                                      Runtime.PRINT_STATS) {
                      
//#line 1150
java.lang.System.err.println((((((("ASYNC SENT AT PLACE ") + (((java.lang.Integer)(x10.
                                                                                                                         lang.
                                                                                                                         Runtime.here().
                                                                                                                         id))))) + (" = "))) + (((java.lang.Long)(x10.
                        lang.
                        Runtime.getAsyncsSent())))));
                      
//#line 1151
java.lang.System.err.println((((((("ASYNC RECV AT PLACE ") + (((java.lang.Integer)(x10.
                                                                                                                         lang.
                                                                                                                         Runtime.here().
                                                                                                                         id))))) + (" = "))) + (((java.lang.Long)(x10.
                        lang.
                        Runtime.getAsyncsReceived())))));
                  }
              }}
        }
        
        
//#line 1156
public static void
                        report(
                        ){
            
//#line 1157
x10.
                            lang.
                            Runtime.runtime.apply$G().
                            pool.release();
        }
        
        
//#line 1166
public static void
                        runAsync(
                        final x10.
                          lang.
                          Place place,
                        final x10.core.ValRail<x10.
                          lang.
                          Clock> clocks,
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1167
final x10.
              lang.
              Runtime.
              FinishState state =
              x10.
              lang.
              Runtime.currentState();
            
//#line 1168
final x10.core.ValRail<java.lang.Integer> phases =
              ((x10.core.ValRail)(x10.
              lang.
              Runtime.clockPhases().register(((x10.core.ValRail)(clocks)))));
            
//#line 1169
state.notifySubActivitySpawn(((x10.
                                                         lang.
                                                         Place)(place)));
            
//#line 1170
if (((int) place.
                                       id) ==
                              ((int) x10.
                                lang.
                                Runtime.hereInt())) {
                
//#line 1171
x10.
                  lang.
                  Runtime.execute(((x10.
                                    lang.
                                    Activity)(new x10.
                                    lang.
                                    Activity(body,
                                             state,
                                             clocks,
                                             phases))));
            } else {
                
//#line 1173
final x10.core.fun.VoidFun_0_0 c =
                  ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                    {
                        
//#line 1173
x10.
                          lang.
                          Runtime.execute(((x10.
                                            lang.
                                            Activity)(new x10.
                                            lang.
                                            Activity(body,
                                                     state,
                                                     clocks,
                                                     phases))));
                        
//#line 1173
return;
                    }
                }}
                public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                }
                }));
                
//#line 1174
x10.runtime.impl.java.Runtime.runAt(((int)(place.
                                                                           id)), c);
            }
        }
        
        
//#line 1178
public static void
                        runAsync(
                        final x10.
                          lang.
                          Place place,
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1179
final x10.
              lang.
              Runtime.
              FinishState state =
              x10.
              lang.
              Runtime.currentState();
            
//#line 1180
state.notifySubActivitySpawn(((x10.
                                                         lang.
                                                         Place)(place)));
            
//#line 1181
final boolean ok =
              x10.
              lang.
              Runtime.safe();
            
//#line 1182
if (((int) place.
                                       id) ==
                              ((int) x10.
                                lang.
                                Runtime.hereInt())) {
                
//#line 1183
x10.
                  lang.
                  Runtime.execute(((x10.
                                    lang.
                                    Activity)(new x10.
                                    lang.
                                    Activity(body,
                                             state,
                                             ok))));
            } else {
                
//#line 1185
x10.core.fun.VoidFun_0_0 closure;
                
//#line 1187
if (ok) {
                    
//#line 1188
closure = ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        {
                            
//#line 1188
x10.
                              lang.
                              Runtime.execute(((x10.
                                                lang.
                                                Activity)(new x10.
                                                lang.
                                                Activity(body,
                                                         state,
                                                         true))));
                            
//#line 1188
return;
                        }
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                } else {
                    
//#line 1190
closure = ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        {
                            
//#line 1190
x10.
                              lang.
                              Runtime.execute(((x10.
                                                lang.
                                                Activity)(new x10.
                                                lang.
                                                Activity(body,
                                                         state,
                                                         false))));
                            
//#line 1190
return;
                        }
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                }
                
//#line 1192
x10.runtime.impl.java.Runtime.runAt(((int)(place.
                                                                           id)), closure);
                
//#line 1193
x10.
                  lang.
                  Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
            }
        }
        
        
//#line 1197
public static void
                        runAsync(
                        final x10.core.ValRail<x10.
                          lang.
                          Clock> clocks,
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1198
final x10.
              lang.
              Runtime.
              FinishState state =
              x10.
              lang.
              Runtime.currentState();
            
//#line 1199
final x10.core.ValRail<java.lang.Integer> phases =
              ((x10.core.ValRail)(x10.
              lang.
              Runtime.clockPhases().register(((x10.core.ValRail)(clocks)))));
            
//#line 1200
state.notifySubActivitySpawn(((x10.
                                                         lang.
                                                         Place)(x10.
                                                         lang.
                                                         Runtime.here())));
            
//#line 1201
x10.
              lang.
              Runtime.execute(((x10.
                                lang.
                                Activity)(new x10.
                                lang.
                                Activity(body,
                                         state,
                                         clocks,
                                         phases))));
        }
        
        
//#line 1204
public static void
                        runAsync(
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1205
final x10.
              lang.
              Runtime.
              FinishState state =
              x10.
              lang.
              Runtime.currentState();
            
//#line 1206
state.notifySubActivitySpawn(((x10.
                                                         lang.
                                                         Place)(x10.
                                                         lang.
                                                         Runtime.here())));
            
//#line 1207
x10.
              lang.
              Runtime.execute(((x10.
                                lang.
                                Activity)(new x10.
                                lang.
                                Activity(body,
                                         state,
                                         x10.
                                           lang.
                                           Runtime.safe()))));
        }
        
        
//#line 1210
public static void
                        runUncountedAsync(
                        final x10.
                          lang.
                          Place place,
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1211
final boolean ok =
              x10.
              lang.
              Runtime.safe();
            
//#line 1212
if (((int) place.
                                       id) ==
                              ((int) x10.
                                lang.
                                Runtime.hereInt())) {
                
//#line 1213
x10.
                  lang.
                  Runtime.execute(((x10.
                                    lang.
                                    Activity)(new x10.
                                    lang.
                                    Activity(body,
                                             ok))));
            } else {
                
//#line 1215
x10.core.fun.VoidFun_0_0 closure;
                
//#line 1217
if (ok) {
                    
//#line 1218
closure = ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        {
                            
//#line 1218
x10.
                              lang.
                              Runtime.execute(((x10.
                                                lang.
                                                Activity)(new x10.
                                                lang.
                                                Activity(body,
                                                         true))));
                            
//#line 1218
return;
                        }
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                } else {
                    
//#line 1220
closure = ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                        {
                            
//#line 1220
x10.
                              lang.
                              Runtime.execute(((x10.
                                                lang.
                                                Activity)(new x10.
                                                lang.
                                                Activity(body,
                                                         false))));
                            
//#line 1220
return;
                        }
                    }}
                    public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                    }
                    }));
                }
                
//#line 1222
x10.runtime.impl.java.Runtime.runAt(((int)(place.
                                                                           id)), closure);
                
//#line 1223
x10.
                  lang.
                  Runtime.dealloc(((x10.core.fun.VoidFun_0_0)(closure)));
            }
        }
        
        
//#line 1227
public static void
                        runUncountedAsync(
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1228
x10.
              lang.
              Runtime.execute(((x10.
                                lang.
                                Activity)(new x10.
                                lang.
                                Activity(body,
                                         x10.
                                           lang.
                                           Runtime.safe()))));
        }
        
        
//#line 1234
public static class RemoteControl
                      extends x10.core.Ref
                      {public static final x10.rtt.RuntimeType<RemoteControl> _RTT = new x10.rtt.RuntimeType<RemoteControl>(
        /* base class */RemoteControl.class
        , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
        );
        public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
        
        
        
            
//#line 1235
public x10.
              util.
              Box<java.lang.Throwable>
              e;
            
//#line 1236
final public x10.
              lang.
              Runtime.
              Latch
              latch;
            
            
//#line 1234
public RemoteControl() {
                
//#line 1234
super();
                
//#line 1235
this.e = null;
                
//#line 1236
this.latch = ((x10.
                  lang.
                  Runtime.
                  Latch)(new x10.
                  lang.
                  Runtime.
                  Latch()));
            }
        
        }
        
        
        
//#line 1239
public static void
                        runAt(
                        final x10.
                          lang.
                          Place place,
                        final x10.core.fun.VoidFun_0_0 body){
            
//#line 1240
final x10.
              lang.
              Runtime.
              RemoteControl box =
              ((x10.
              lang.
              Runtime.
              RemoteControl)(new x10.
              lang.
              Runtime.
              RemoteControl()));
            
//#line 1241
x10.
              lang.
              Runtime.runAsync(((x10.
                                 lang.
                                 Place)(place)),
                               new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                   
//#line 1242
try {{
                                       
//#line 1243
body.apply();
                                       
//#line 1244
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1244
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
                                   if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
                                   final java.lang.Throwable e = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
                                   {
                                       
//#line 1246
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1247
box.e = new x10.
                                                                util.
                                                                Box<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class),
                                                                                         e);
                                                              
//#line 1248
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }
                                   }
                                   else {
                                   throw __$generated_wrappedex$__;
                                   }
                                   }catch (final java.lang.Throwable e) {
                                       
//#line 1246
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1247
box.e = new x10.
                                                                util.
                                                                Box<java.lang.Throwable>(x10.rtt.Types.runtimeType(java.lang.Throwable.class),
                                                                                         e);
                                                              
//#line 1248
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }
                               }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                               public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                               }
                               });
            
//#line 1252
if ((!(((boolean)(x10.runtime.impl.java.Runtime.NO_STEALS)))) &&
                              x10.
                                lang.
                                Runtime.safe()) {
                
//#line 1252
x10.
                  lang.
                  Runtime.worker().join(((x10.
                                          lang.
                                          Runtime.
                                          Latch)(box.
                                                   latch)));
            }
            
//#line 1253
box.
                            latch.await();
            
//#line 1254
if ((!x10.rtt.Equality.equalsequals(null,box.
                                                                     e))) {
                
//#line 1255
final java.lang.Throwable x =
                  ((java.lang.Throwable)(box.
                                           e.
                                           value));
                
//#line 1256
if (x10.rtt.Types.runtimeType(java.lang.Error.class).instanceof$(x)) {
                    
//#line 1257
throw (new java.lang.Object() {final java.lang.Error cast(final java.lang.Error self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.Error.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.Error) x));
                }
                
//#line 1258
if (x10.rtt.Types.runtimeType(java.lang.RuntimeException.class).instanceof$(x)) {
                    
//#line 1259
throw (new java.lang.Object() {final java.lang.RuntimeException cast(final java.lang.RuntimeException self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.RuntimeException.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.RuntimeException) x));
                }
            }
        }
        
        
//#line 1266
public static class Remote<T>
                      extends x10.core.Ref
                      {public static final x10.rtt.RuntimeType<Remote> _RTT = new x10.rtt.RuntimeType<Remote>(
        /* base class */Remote.class, 
        /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
        , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
        );
        public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
        
        public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
        
            private final x10.rtt.Type T;
            
            
//#line 1267
public x10.
              util.
              Box<T>
              t;
            
//#line 1268
public x10.
              util.
              Box<java.lang.Throwable>
              e;
            
//#line 1269
final public x10.
              lang.
              Runtime.
              Latch
              latch;
            
            
//#line 1266
public Remote(final x10.rtt.Type T) {
                                                                       
//#line 1266
super();
                                                                   this.T = T;
                                                                    {
                                                                       
//#line 1267
this.t = null;
                                                                       
//#line 1268
this.e = null;
                                                                       
//#line 1269
this.latch = ((x10.
                                                                         lang.
                                                                         Runtime.
                                                                         Latch)(new x10.
                                                                         lang.
                                                                         Runtime.
                                                                         Latch()));
                                                                   }}
        
        }
        
        
        
//#line 1272
public static <T> T
                        evalAt$G(
                        final x10.rtt.Type T,
                        final x10.
                          lang.
                          Place place,
                        final x10.core.fun.Fun_0_0<T> eval){
            
//#line 1273
final x10.
              lang.
              Runtime.
              Remote<T> box =
              ((x10.
              lang.
              Runtime.
              Remote)(new x10.
              lang.
              Runtime.
              Remote<T>(T)));
            
//#line 1274
x10.
              lang.
              Runtime.runAsync(((x10.
                                 lang.
                                 Place)(place)),
                               new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                   
//#line 1275
try {{
                                       
//#line 1276
final T result =
                                         ((T)(eval.apply$G()));
                                       
//#line 1277
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1278
box.t = ((x10.
                                                                util.
                                                                Box)(x10.
                                                                util.
                                                                Box.<T>$implicit_convert(T,
                                                                                         ((T)(result)))));
                                                              
//#line 1279
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }}catch (x10.runtime.impl.java.WrappedRuntimeException __$generated_wrappedex$__) {
                                   if (__$generated_wrappedex$__.getCause() instanceof java.lang.Throwable) {
                                   final java.lang.Throwable e = (java.lang.Throwable) __$generated_wrappedex$__.getCause();
                                   {
                                       
//#line 1282
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1283
box.e = ((x10.
                                                                util.
                                                                Box)(x10.
                                                                util.
                                                                Box.<java.lang.Throwable>$implicit_convert(x10.rtt.Types.runtimeType(java.lang.Throwable.class),
                                                                                                           ((java.lang.Throwable)(e)))));
                                                              
//#line 1284
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }
                                   }
                                   else {
                                   throw __$generated_wrappedex$__;
                                   }
                                   }catch (final java.lang.Throwable e) {
                                       
//#line 1282
x10.
                                         lang.
                                         Runtime.runAsync(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(box)))),
                                                          new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                              
//#line 1283
box.e = ((x10.
                                                                util.
                                                                Box)(x10.
                                                                util.
                                                                Box.<java.lang.Throwable>$implicit_convert(x10.rtt.Types.runtimeType(java.lang.Throwable.class),
                                                                                                           ((java.lang.Throwable)(e)))));
                                                              
//#line 1284
box.
                                                                              latch.release();
                                                          }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                          public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                          }
                                                          });
                                   }
                               }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                               public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                               }
                               });
            
//#line 1288
if ((!(((boolean)(x10.runtime.impl.java.Runtime.NO_STEALS)))) &&
                              x10.
                                lang.
                                Runtime.safe()) {
                
//#line 1288
x10.
                  lang.
                  Runtime.worker().join(((x10.
                                          lang.
                                          Runtime.
                                          Latch)(box.
                                                   latch)));
            }
            
//#line 1289
box.
                            latch.await();
            
//#line 1290
if ((!x10.rtt.Equality.equalsequals(null,box.
                                                                     e))) {
                
//#line 1291
final java.lang.Throwable x =
                  ((java.lang.Throwable)(box.
                                           e.
                                           value));
                
//#line 1292
if (x10.rtt.Types.runtimeType(java.lang.Error.class).instanceof$(x)) {
                    
//#line 1293
throw (new java.lang.Object() {final java.lang.Error cast(final java.lang.Error self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.Error.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.Error) x));
                }
                
//#line 1294
if (x10.rtt.Types.runtimeType(java.lang.RuntimeException.class).instanceof$(x)) {
                    
//#line 1295
throw (new java.lang.Object() {final java.lang.RuntimeException cast(final java.lang.RuntimeException self) {if (self==null) return null;x10.rtt.Type rtt = x10.rtt.Types.runtimeType(java.lang.RuntimeException.class);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((java.lang.RuntimeException) x));
                }
            }
            
//#line 1297
return box.
                                   t.
                                   value;
        }
        
        
//#line 1303
public static <T> x10.
                        lang.
                        Future<T>
                        evalFuture(
                        final x10.rtt.Type T,
                        final x10.
                          lang.
                          Place place,
                        final x10.core.fun.Fun_0_0<T> eval){
            
//#line 1304
final x10.
              lang.
              Future<T> f =
              ((x10.
              lang.
              Future)(x10.
              lang.
              Runtime.<x10.
              lang.
              Future<T>>evalAt$G(new x10.rtt.ParameterizedType(x10.lang.Future._RTT, T),
                                 ((x10.
                                   lang.
                                   Place)(place)),
                                 ((x10.core.fun.Fun_0_0)(new x10.core.fun.Fun_0_0<x10.
                                   lang.
                                   Future<T>>() {public final x10.
                                   lang.
                                   Future<T> apply$G() { return apply();}
                                 public final x10.
                                   lang.
                                   Future<T> apply() { {
                                     
//#line 1305
final x10.
                                       lang.
                                       Future<T> f1 =
                                       ((x10.
                                       lang.
                                       Future)(new x10.
                                       lang.
                                       Future<T>(T,
                                                 eval)));
                                     
//#line 1306
x10.
                                       lang.
                                       Runtime.runAsync(new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                                                            
//#line 1306
f1.run();
                                                        }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                                                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                                                        }
                                                        });
                                     
//#line 1307
return f1;
                                 }}
                                 public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.Future._RTT, T);return null;
                                 }
                                 })))));
            
//#line 1309
return f;
        }
        
        
//#line 1319
public static void
                        lock(
                        ){
            
//#line 1320
x10.
                            lang.
                            Runtime.runtime.apply$G().
                            monitor.lock();
        }
        
        
//#line 1327
public static void
                        await(
                        ){
            
//#line 1328
x10.
                            lang.
                            Runtime.runtime.apply$G().
                            monitor.await();
        }
        
        
//#line 1335
public static void
                        release(
                        ){
            
//#line 1336
x10.
                            lang.
                            Runtime.runtime.apply$G().
                            monitor.release();
        }
        
        
//#line 1345
public static x10.
                        lang.
                        Runtime.
                        ClockPhases
                        clockPhases(
                        ){
            
//#line 1346
final x10.
              lang.
              Activity a =
              ((x10.
              lang.
              Activity)(x10.
              lang.
              Runtime.activity()));
            
//#line 1347
if (x10.rtt.Equality.equalsequals(null,a.
                                                                   clockPhases)) {
                
//#line 1348
a.clockPhases = ((x10.
                  lang.
                  Runtime.
                  ClockPhases)(new x10.
                  lang.
                  Runtime.
                  ClockPhases()));
            }
            
//#line 1349
return a.
                                   clockPhases;
        }
        
        
//#line 1355
public static void
                        next(
                        ){
            {
                
//#line 1355
x10.
                  lang.
                  Runtime.clockPhases().next();
                
//#line 1355
return;
            }
        }
        
        
//#line 1363
private static x10.
                        lang.
                        Runtime.
                        FinishState
                        currentState(
                        ){
            
//#line 1364
final x10.
              lang.
              Activity a =
              ((x10.
              lang.
              Activity)(x10.
              lang.
              Runtime.activity()));
            
//#line 1365
if (x10.rtt.Equality.equalsequals(null,a.
                                                                   finishStack) ||
                              a.
                                finishStack.isEmpty()) {
                
//#line 1366
return a.
                                       finishState;
            }
            
//#line 1367
return a.
                                   finishStack.peek$G();
        }
        
        public static x10.
          lang.
          Runtime.
          FinishState
          currentState$P(
          ){
            return Runtime.currentState();
        }
        
        
//#line 1374
public static void
                        startFinish(
                        ){
            
//#line 1375
final x10.
              lang.
              Activity a =
              ((x10.
              lang.
              Activity)(x10.
              lang.
              Runtime.activity()));
            
//#line 1376
if (x10.rtt.Equality.equalsequals(null,a.
                                                                   finishStack)) {
                
//#line 1377
a.finishStack = ((x10.
                  util.
                  Stack)(new x10.
                  util.
                  Stack<x10.
                  lang.
                  Runtime.
                  FinishState>(x10.lang.Runtime.FinishState._RTT)));
            }
            
//#line 1378
a.
                            finishStack.push(((x10.
                                               lang.
                                               Runtime.
                                               FinishState)(new x10.
                                               lang.
                                               Runtime.
                                               RootFinish())));
        }
        
        
//#line 1387
public static void
                        stopFinish(
                        ){
            
//#line 1388
final x10.
              lang.
              Activity a =
              ((x10.
              lang.
              Activity)(x10.
              lang.
              Runtime.activity()));
            
//#line 1389
final x10.
              lang.
              Runtime.
              FinishState finishState =
              ((x10.
              lang.
              Runtime.
              FinishState)(a.
                             finishStack.pop$G()));
            
//#line 1390
finishState.notifyActivityTermination();
            
//#line 1391
finishState.waitForFinish((boolean)(x10.
                                                      lang.
                                                      Runtime.safe()));
        }
        
        
//#line 1398
public static void
                        pushException(
                        final java.lang.Throwable t){
            
//#line 1399
x10.
              lang.
              Runtime.currentState().pushException(((java.lang.Throwable)(t)));
        }
        
        
//#line 1402
private static boolean
                        safe(
                        ){
            
//#line 1403
final x10.
              lang.
              Activity a =
              ((x10.
              lang.
              Activity)(x10.
              lang.
              Runtime.activity()));
            
//#line 1404
return a.
                                   safe &&
            ((x10.rtt.Equality.equalsequals(null,a.
                                                   clockPhases)));
        }
        
        public static boolean
          safe$P(
          ){
            return Runtime.safe();
        }
        
        
//#line 1408
public static x10.
                        lang.
                        Activity
                        scan(
                        final x10.
                          util.
                          Random random,
                        final x10.
                          lang.
                          Runtime.
                          Latch latch,
                        final boolean block){
            
//#line 1409
return x10.
                                   lang.
                                   Runtime.runtime.apply$G().
                                   pool.scan(((x10.
                                               util.
                                               Random)(random)),
                                             ((x10.
                                               lang.
                                               Runtime.
                                               Latch)(latch)),
                                             (boolean)(block));
        }
        
        
//#line 1414
private static void
                        execute(
                        final x10.
                          lang.
                          Activity activity){
            
//#line 1415
x10.
              lang.
              Runtime.worker().push(((x10.
                                      lang.
                                      Activity)(activity)));
        }
        
        public static void
          execute$P(
          final x10.
            lang.
            Activity activity){
            Runtime.execute(((x10.
                              lang.
                              Activity)(activity)));
        }
        
        
//#line 1419
public static void
                        increaseParallelism(
                        ){
            
//#line 1420
if ((!(((boolean)(x10.runtime.impl.java.Runtime.STATIC_THREADS))))) {
                
//#line 1421
x10.
                                lang.
                                Runtime.runtime.apply$G().
                                pool.increase();
            }
        }
        
        
//#line 1426
public static void
                        decreaseParallelism(
                        final int n){
            
//#line 1427
if ((!(((boolean)(x10.runtime.impl.java.Runtime.STATIC_THREADS))))) {
                
//#line 1428
x10.
                                lang.
                                Runtime.runtime.apply$G().
                                pool.decrease((int)(n));
            }
        }
        
        
//#line 1433
public static void
                        park(
                        ){
            
//#line 1434
if ((!(((boolean)(x10.runtime.impl.java.Runtime.STATIC_THREADS))))) {
                
//#line 1435
x10.
                  lang.
                  Runtime.
                  Thread.park();
            } else {
                
//#line 1437
x10.
                  lang.
                  Runtime.event_probe();
            }
        }
        
        
//#line 1442
public static void
                        unpark(
                        final x10.
                          lang.
                          Runtime.
                          Thread thread){
            
//#line 1443
if ((!(((boolean)(x10.runtime.impl.java.Runtime.STATIC_THREADS))))) {
                
//#line 1444
thread.unpark();
            }
        }
        
        
//#line 1449
public static class CollectingFinish<T>
                      extends x10.core.Ref
                      {public static final x10.rtt.RuntimeType<CollectingFinish> _RTT = new x10.rtt.RuntimeType<CollectingFinish>(
        /* base class */CollectingFinish.class, 
        /* variances */ new x10.rtt.RuntimeType.Variance[] {x10.rtt.RuntimeType.Variance.INVARIANT}
        , /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
        );
        public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}
        
        public x10.rtt.Type<?> getParam(int i) {if (i ==0)return T;return null;}
        
            private final x10.rtt.Type T;
            
            
            
//#line 1452
public CollectingFinish(final x10.rtt.Type T,
                                                  final x10.
                                                    lang.
                                                    Reducible<T> r) {
                                                                             super();
                                                                         this.T = T;
                                                                          {
                                                                             
//#line 1453
final x10.
                                                                               lang.
                                                                               Activity a =
                                                                               ((x10.
                                                                               lang.
                                                                               Activity)(x10.
                                                                               lang.
                                                                               Runtime.activity()));
                                                                             
//#line 1454
if (x10.rtt.Equality.equalsequals(null,a.
                                                                                                                                    finishStack)) {
                                                                                 
//#line 1455
a.finishStack = ((x10.
                                                                                   util.
                                                                                   Stack)(new x10.
                                                                                   util.
                                                                                   Stack<x10.
                                                                                   lang.
                                                                                   Runtime.
                                                                                   FinishState>(x10.lang.Runtime.FinishState._RTT)));
                                                                             }
                                                                             
//#line 1456
a.
                                                                                             finishStack.push(((x10.
                                                                                                                lang.
                                                                                                                Runtime.
                                                                                                                FinishState)(new x10.
                                                                                                                lang.
                                                                                                                Runtime.
                                                                                                                RootCollectingFinish<T>(T,
                                                                                                                                        r))));
                                                                         }}
            
            
//#line 1460
public static <T> void
                            offer(
                            final x10.rtt.Type T,
                            final T t){
                
//#line 1461
final x10.
                  lang.
                  Runtime.
                  Worker thisWorker =
                  ((x10.
                  lang.
                  Runtime.
                  Worker)(x10.
                  lang.
                  Runtime.worker$P()));
                
//#line 1462
final int id =
                  thisWorker.
                    workerId;
                
//#line 1463
final x10.
                  lang.
                  Runtime.
                  FinishState state =
                  x10.
                  lang.
                  Runtime.currentState$P();
                
//#line 1465
if (x10.
                                    lang.
                                    Runtime.here().equals(((x10.
                                                            lang.
                                                            Place)(x10.lang.Place.place(x10.core.Ref.home(state)))))) {
                    
//#line 1466
(new x10.core.fun.Fun_0_1<x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T>, x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T>>() {public final x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T> apply$G(final x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T> __desugarer__var__68__) { return apply(__desugarer__var__68__);}
                                   public final x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T> apply(final x10.
                                     lang.
                                     Runtime.
                                     RootCollectingFinish<T> __desugarer__var__68__) { {
                                       
//#line 1466
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__68__,null)) &&
                                                           !(x10.rtt.Equality.equalsequals(((x10.
                                                               lang.
                                                               Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__68__)))),x10.
                                                               lang.
                                                               Runtime.here()))) {
                                           
//#line 1466
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
                                       }
                                       
//#line 1466
return __desugarer__var__68__;
                                   }}
                                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);return null;
                                   }
                                   }.apply((new java.lang.Object() {final x10.
                                             lang.
                                             Runtime.
                                             RootCollectingFinish cast(final x10.
                                             lang.
                                             Runtime.
                                             RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             lang.
                                             Runtime.
                                             RootCollectingFinish) state)))).accept(((T)(t)),
                                                                                    (int)(id));
                } else {
                    
//#line 1468
(new x10.core.fun.Fun_0_1<x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T>, x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T>>() {public final x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T> apply$G(final x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T> __desugarer__var__69__) { return apply(__desugarer__var__69__);}
                                   public final x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T> apply(final x10.
                                     lang.
                                     Runtime.
                                     RemoteCollectingFinish<T> __desugarer__var__69__) { {
                                       
//#line 1468
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__69__,null)) &&
                                                           !(x10.rtt.Equality.equalsequals(((x10.
                                                               lang.
                                                               Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__69__)))),x10.
                                                               lang.
                                                               Runtime.here()))) {
                                           
//#line 1468
throw new java.lang.ClassCastException("x10.lang.Runtime.RemoteCollectingFinish[T]{self.home==here}");
                                       }
                                       
//#line 1468
return __desugarer__var__69__;
                                   }}
                                   public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {if (i ==0) return new x10.rtt.ParameterizedType(x10.lang.Runtime.RemoteCollectingFinish._RTT, T);if (i ==1) return new x10.rtt.ParameterizedType(x10.lang.Runtime.RemoteCollectingFinish._RTT, T);return null;
                                   }
                                   }.apply((new java.lang.Object() {final x10.
                                             lang.
                                             Runtime.
                                             RemoteCollectingFinish cast(final x10.
                                             lang.
                                             Runtime.
                                             RemoteCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RemoteCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                             lang.
                                             Runtime.
                                             RemoteCollectingFinish) x10.
                                             lang.
                                             Runtime.proxy(((x10.
                                                             lang.
                                                             Runtime.
                                                             RootFinish)((new java.lang.Object() {final x10.
                                                             lang.
                                                             Runtime.
                                                             RootFinish cast(final x10.
                                                             lang.
                                                             Runtime.
                                                             RootFinish self) {if (self==null) return null;x10.rtt.Type rtt = x10.lang.Runtime.RootFinish._RTT;if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                             lang.
                                                             Runtime.
                                                             RootFinish) state))))))))).accept(((T)(t)),
                                                                                               (int)(id));
                }
            }
            
            
//#line 1471
public T
                            stopFinishExpr$G(
                            ){
                
//#line 1472
final x10.
                  lang.
                  Runtime.
                  Worker thisWorker =
                  ((x10.
                  lang.
                  Runtime.
                  Worker)(x10.
                  lang.
                  Runtime.worker$P()));
                
//#line 1473
final int id =
                  thisWorker.
                    workerId;
                
//#line 1474
final x10.
                  lang.
                  Runtime.
                  FinishState state =
                  x10.
                  lang.
                  Runtime.currentState$P();
                
//#line 1475
(x10.
                                 lang.
                                 Runtime.
                                 CollectingFinish.<T>__$closure$apply$__2039(T,
                                                                             ((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootCollectingFinish cast(final x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                               lang.
                                                                               Runtime.
                                                                               RootCollectingFinish) state)))))).notifyActivityTermination();
                
//#line 1476
assert x10.
                  lang.
                  Runtime.here().equals(((x10.
                                          lang.
                                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))));
                
//#line 1477
final T result =
                  ((T)((x10.
                          lang.
                          Runtime.
                          CollectingFinish.<T>__$closure$apply$__2040(T,
                                                                      ((x10.
                                                                        lang.
                                                                        Runtime.
                                                                        RootCollectingFinish)((new java.lang.Object() {final x10.
                                                                        lang.
                                                                        Runtime.
                                                                        RootCollectingFinish cast(final x10.
                                                                        lang.
                                                                        Runtime.
                                                                        RootCollectingFinish self) {if (self==null) return null;x10.rtt.Type rtt = new x10.rtt.ParameterizedType(x10.lang.Runtime.RootCollectingFinish._RTT, T);if (rtt != null && ! rtt.instanceof$(self)) throw new java.lang.ClassCastException();return self;}}.cast((x10.
                                                                        lang.
                                                                        Runtime.
                                                                        RootCollectingFinish) state)))))).waitForFinishExpr$G((boolean)(true))));
                
//#line 1478
final x10.
                  lang.
                  Activity a =
                  ((x10.
                  lang.
                  Activity)(x10.
                  lang.
                  Runtime.activity()));
                
//#line 1479
a.
                                finishStack.pop$G();
                
//#line 1480
return result;
            }
            
            final private static <T> x10.
              lang.
              Runtime.
              RootCollectingFinish<T>
              __$closure$apply$__2039(
              final x10.rtt.Type T,
              final x10.
                lang.
                Runtime.
                RootCollectingFinish<T> __desugarer__var__70__){
                
//#line 1475
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__70__,null)) &&
                                    !(x10.rtt.Equality.equalsequals(((x10.
                                        lang.
                                        Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__70__)))),x10.
                                        lang.
                                        Runtime.here()))) {
                    
//#line 1475
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
                }
                
//#line 1475
return __desugarer__var__70__;
            }
            
            final public static <T> x10.
              lang.
              Runtime.
              RootCollectingFinish<T>
              __$closure$apply$__2039$P(
              final x10.rtt.Type T,
              final x10.
                lang.
                Runtime.
                RootCollectingFinish<T> __desugarer__var__70__){
                return CollectingFinish.<T>__$closure$apply$__2039(T,
                                                                   ((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RootCollectingFinish)(__desugarer__var__70__)));
            }
            
            final private static <T> x10.
              lang.
              Runtime.
              RootCollectingFinish<T>
              __$closure$apply$__2040(
              final x10.rtt.Type T,
              final x10.
                lang.
                Runtime.
                RootCollectingFinish<T> __desugarer__var__71__){
                
//#line 1477
if ((!x10.rtt.Equality.equalsequals(__desugarer__var__71__,null)) &&
                                    !(x10.rtt.Equality.equalsequals(((x10.
                                        lang.
                                        Place)(x10.lang.Place.place(x10.core.Ref.home(__desugarer__var__71__)))),x10.
                                        lang.
                                        Runtime.here()))) {
                    
//#line 1477
throw new java.lang.ClassCastException("x10.lang.Runtime.RootCollectingFinish[T]{self.home==here}");
                }
                
//#line 1477
return __desugarer__var__71__;
            }
            
            final public static <T> x10.
              lang.
              Runtime.
              RootCollectingFinish<T>
              __$closure$apply$__2040$P(
              final x10.rtt.Type T,
              final x10.
                lang.
                Runtime.
                RootCollectingFinish<T> __desugarer__var__71__){
                return CollectingFinish.<T>__$closure$apply$__2040(T,
                                                                   ((x10.
                                                                     lang.
                                                                     Runtime.
                                                                     RootCollectingFinish)(__desugarer__var__71__)));
            }
        
        }
        
    
    }
    