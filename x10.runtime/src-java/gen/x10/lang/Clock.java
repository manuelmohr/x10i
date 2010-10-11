package x10.lang;

public class Clock
extends x10.core.Ref
{public static final x10.rtt.RuntimeType<Clock> _RTT = new x10.rtt.RuntimeType<Clock>(
/* base class */Clock.class
, /* parents */ new x10.rtt.Type[] {x10.rtt.Types.runtimeType(java.lang.Object.class)}
);
public x10.rtt.RuntimeType<?> getRTT() {return _RTT;}



    
//#line 17
final public java.lang.String
      name;
    
    
    
//#line 18
public static x10.
                  lang.
                  Clock
                  make(
                  ){
        
//#line 18
return x10.
          lang.
          Clock.make(((java.lang.String)("")));
    }
    
    
//#line 20
final public static int
      FIRST_PHASE =
      1;
    
    
//#line 22
public static x10.
                  lang.
                  Clock
                  make(
                  final java.lang.String name){
        
//#line 23
final x10.
          lang.
          Clock clock =
          ((x10.
          lang.
          Clock)(new x10.
          lang.
          Clock(name)));
        
//#line 24
x10.
          lang.
          Runtime.clockPhases().put(((x10.
                                      lang.
                                      Clock)(clock)),
                                    (java.lang.Integer)(x10.
                                      lang.
                                      Clock.FIRST_PHASE));
        
//#line 25
return clock;
    }
    
    
//#line 28
public int
      count;
    
//#line 29
public int
      alive;
    
//#line 30
public int
      phase;
    
    
//#line 32
private Clock(final java.lang.String name) {
        super();
        
//#line 28
this.count = 1;
        
//#line 29
this.alive = 1;
        
//#line 30
this.phase = x10.
          lang.
          Clock.FIRST_PHASE;
        
//#line 33
this.name = name;
    }
    
    
//#line 36
private int
                  get(
                  ){
        
//#line 36
return x10.
                             lang.
                             Runtime.clockPhases().get(((x10.
                                                         lang.
                                                         Clock)(this))).
                             value;
    }
    
    public static int
      get$P(
      final x10.
        lang.
        Clock Clock){
        return Clock.get();
    }
    
    
//#line 38
private x10.
                  util.
                  Box<java.lang.Integer>
                  put(
                  final int ph){
        
//#line 38
return x10.
          lang.
          Runtime.clockPhases().put(((x10.
                                      lang.
                                      Clock)(this)),
                                    (java.lang.Integer)(ph));
    }
    
    public static x10.
      util.
      Box<java.lang.Integer>
      put$P(
      final int ph,
      final x10.
        lang.
        Clock Clock){
        return Clock.put((int)(ph));
    }
    
    
//#line 40
private int
                  remove(
                  ){
        
//#line 40
return x10.
                             lang.
                             Runtime.clockPhases().remove(((x10.
                                                            lang.
                                                            Clock)(this))).
                             value;
    }
    
    public static int
      remove$P(
      final x10.
        lang.
        Clock Clock){
        return Clock.remove();
    }
    
    
//#line 42
private void
                  resumeLocal(
                  ){
        
//#line 42
try {{
            
//#line 42
x10.
              lang.
              Runtime.lock();
            {
                
//#line 43
if (x10.rtt.Equality.equalsequals(x10.
                                  lang.
                                  Clock.__$closure$apply$__2007(((x10.
                                                                  lang.
                                                                  Clock)(this)),
                                                                (int)(1)),0)) {
                    
//#line 44
this.alive = count;
                    
//#line 45
x10.
                      lang.
                      Clock.__$closure$apply$__2008(((x10.
                                                      lang.
                                                      Clock)(this)),
                                                    (int)(1));
                }
            }
        }}finally {{
              
//#line 42
x10.
                lang.
                Runtime.release();
          }}
        }
    
    public static void
      resumeLocal$P(
      final x10.
        lang.
        Clock Clock){
        Clock.resumeLocal();
    }
    
    
//#line 49
private void
                  dropLocal(
                  final int ph){
        
//#line 50
x10.
          lang.
          Clock.__$closure$apply$__2009(((x10.
                                          lang.
                                          Clock)(this)),
                                        (int)(1));
        
//#line 51
if (((int) (-(((int)(ph))))) !=
                        ((int) phase)) {
            
//#line 52
this.resumeLocal();
        }
    }
    
    public static void
      dropLocal$P(
      final int ph,
      final x10.
        lang.
        Clock Clock){
        Clock.dropLocal((int)(ph));
    }
    
    
//#line 55
public int
                  register(
                  ){
        
//#line 56
if (this.dropped()) {
            
//#line 56
throw new x10.
              lang.
              ClockUseException();
        }
        
//#line 57
final int ph =
          this.get();
        
//#line 58
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 58
try {{
                                
//#line 58
x10.
                                  lang.
                                  Runtime.lock();
                                {
                                    
//#line 59
x10.
                                      lang.
                                      Clock.__$closure$apply$__2010(((x10.
                                                                      lang.
                                                                      Clock)(x10.
                                                                      lang.
                                                                      Clock.this)),
                                                                    (int)(1));
                                    
//#line 60
if (((int) (-(((int)(ph))))) !=
                                                    ((int) phase)) {
                                        
//#line 60
x10.
                                          lang.
                                          Clock.__$closure$apply$__2011(((x10.
                                                                          lang.
                                                                          Clock)(x10.
                                                                          lang.
                                                                          Clock.this)),
                                                                        (int)(1));
                                    }
                                }
                            }}finally {{
                                  
//#line 58
x10.
                                    lang.
                                    Runtime.release();
                              }}
                            }}
                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                            }
                            })));
        
//#line 62
return ph;
        }
    
    
//#line 65
public void
                  resumeUnsafe(
                  ){
        
//#line 66
final int ph =
          this.get();
        
//#line 67
if (((((int)(ph))) < (((int)(0))))) {
            
//#line 67
return;
        }
        
//#line 68
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 68
x10.
                              lang.
                              Clock.this.resumeLocal();
                        }}
                        public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                        }
                        })));
        
//#line 69
this.put((int)((-(((int)(ph))))));
    }
    
    
//#line 72
public void
                  nextUnsafe(
                  ){
        
//#line 73
final int ph =
          this.get();
        
//#line 74
final int abs =
          x10.
          lang.
          Math.abs((int)(ph));
        
//#line 75
x10.
          lang.
          Runtime.runAt(((x10.
                          lang.
                          Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                        ((x10.core.fun.VoidFun_0_0)(new x10.core.fun.VoidFun_0_0() {public final void apply() { {
                            
//#line 76
if (((((int)(ph))) > (((int)(0))))) {
                                
//#line 76
x10.
                                  lang.
                                  Clock.this.resumeLocal();
                            }
                            
//#line 77
try {{
                                
//#line 77
x10.
                                  lang.
                                  Runtime.lock();
                                
//#line 77
while (!((((((int)(abs))) < (((int)(phase)))))))
                                    
//#line 77
x10.
                                      lang.
                                      Runtime.await();
                            }}finally {{
                                  
//#line 77
x10.
                                    lang.
                                    Runtime.release();
                              }}
                            }}
                            public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                            }
                            })));
        
//#line 79
this.put((int)(((((int)(abs))) + (((int)(1))))));
        }
    
    
//#line 82
public void
                  dropUnsafe(
                  ){
        
//#line 83
final int ph =
          this.remove();
        
//#line 84
x10.
          lang.
          Runtime.runAsync(((x10.
                             lang.
                             Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                           new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                               
//#line 84
x10.
                                 lang.
                                 Clock.this.dropLocal((int)(ph));
                           }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                           public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                           }
                           });
    }
    
    
//#line 87
public void
                  dropInternal(
                  ){
        
//#line 88
final int ph =
          this.get();
        
//#line 89
x10.
          lang.
          Runtime.runAsync(((x10.
                             lang.
                             Place)(x10.lang.Place.place(x10.core.Ref.home(this)))),
                           new x10.core.fun.VoidFun_0_0() {public final void apply() { try {{
                               
//#line 89
x10.
                                 lang.
                                 Clock.this.dropLocal((int)(ph));
                           }}catch (x10.runtime.impl.java.WrappedRuntimeException ex) {x10.lang.Runtime.pushException(ex.getCause());}}
                           public x10.rtt.RuntimeType<?> getRTT() { return _RTT;}public x10.rtt.Type<?> getParam(int i) {return null;
                           }
                           });
    }
    
    
//#line 92
public boolean
                  registered(
                  ){
        
//#line 92
return x10.
          lang.
          Runtime.clockPhases().containsKey(((x10.
                                              lang.
                                              Clock)(this)));
    }
    
    
//#line 94
public boolean
                  dropped(
                  ){
        
//#line 94
return (!(((boolean)(this.registered()))));
    }
    
    
//#line 96
public int
                  phase(
                  ){
        
//#line 97
if (this.dropped()) {
            
//#line 97
throw new x10.
              lang.
              ClockUseException();
        }
        
//#line 98
return x10.
          lang.
          Math.abs((int)(this.get()));
    }
    
    
//#line 101
public void
                   resume(
                   ){
        
//#line 102
if (this.dropped()) {
            
//#line 102
throw new x10.
              lang.
              ClockUseException();
        }
        
//#line 103
this.resumeUnsafe();
    }
    
    
//#line 106
public void
                   next(
                   ){
        
//#line 107
if (this.dropped()) {
            
//#line 107
throw new x10.
              lang.
              ClockUseException();
        }
        
//#line 108
this.nextUnsafe();
    }
    
    
//#line 111
public void
                   drop(
                   ){
        
//#line 112
if (this.dropped()) {
            
//#line 112
throw new x10.
              lang.
              ClockUseException();
        }
        
//#line 113
this.dropUnsafe();
    }
    
    
//#line 17
final public java.lang.String
                  name(
                  ){
        
//#line 17
return this.
                             name;
    }
    
    final private static int
      __$closure$apply$__2007(
      final x10.
        lang.
        Clock x,
      final int y){
        
//#line 43
return x.alive = ((((int)(x.
                                                alive))) - (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2007$P(
      final x10.
        lang.
        Clock x,
      final int y){
        return Clock.__$closure$apply$__2007(((x10.
                                               lang.
                                               Clock)(x)),
                                             (int)(y));
    }
    
    final private static int
      __$closure$apply$__2008(
      final x10.
        lang.
        Clock x,
      final int y){
        
//#line 45
return x.phase = ((((int)(x.
                                                phase))) + (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2008$P(
      final x10.
        lang.
        Clock x,
      final int y){
        return Clock.__$closure$apply$__2008(((x10.
                                               lang.
                                               Clock)(x)),
                                             (int)(y));
    }
    
    final private static int
      __$closure$apply$__2009(
      final x10.
        lang.
        Clock x,
      final int y){
        
//#line 50
return x.count = ((((int)(x.
                                                count))) - (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2009$P(
      final x10.
        lang.
        Clock x,
      final int y){
        return Clock.__$closure$apply$__2009(((x10.
                                               lang.
                                               Clock)(x)),
                                             (int)(y));
    }
    
    final private static int
      __$closure$apply$__2010(
      final x10.
        lang.
        Clock x,
      final int y){
        
//#line 59
return x.count = ((((int)(x.
                                                count))) + (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2010$P(
      final x10.
        lang.
        Clock x,
      final int y){
        return Clock.__$closure$apply$__2010(((x10.
                                               lang.
                                               Clock)(x)),
                                             (int)(y));
    }
    
    final private static int
      __$closure$apply$__2011(
      final x10.
        lang.
        Clock x,
      final int y){
        
//#line 60
return x.alive = ((((int)(x.
                                                alive))) + (((int)(y))));
    }
    
    final public static int
      __$closure$apply$__2011$P(
      final x10.
        lang.
        Clock x,
      final int y){
        return Clock.__$closure$apply$__2011(((x10.
                                               lang.
                                               Clock)(x)),
                                             (int)(y));
    }
    
    }
    